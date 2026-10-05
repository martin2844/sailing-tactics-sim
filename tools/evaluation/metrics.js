/** Pure evaluation of browser observations. All timing values are milliseconds.
 * Quantiles use the nearest-rank order statistic. Content observations describe
 * callback delivery through requestAnimationFrame, never physical presentation.
 */
const finite=value=>typeof value==='number'&&Number.isFinite(value);
const integer=value=>Number.isSafeInteger(value)&&value>=0;
const settings=['speed','dt','autoSlow'];
const metricPaths=['paintDuration.p95','paintDuration.p99','paintInterval.p95',
  'paintInterval.p99','contentInterval.p95','contentInterval.p99'];
const error=(code,message,details={})=>({code,message,...details});
const median=values=>{
  const ordered=values.slice().sort((a,b)=>a-b),middle=Math.floor(ordered.length/2);
  return ordered.length%2?ordered[middle]:ordered[middle-1]+(ordered[middle]-ordered[middle-1])/2;
};
function statistics(values){
  if(!values.length)return {count:0,mean:null,p50:null,p95:null,p99:null,max:null};
  const ordered=values.slice().sort((a,b)=>a-b);
  const quantile=rank=>ordered[Math.max(0,Math.ceil(rank*ordered.length)-1)];
  // Incremental mean avoids overflowing a sum of otherwise finite samples.
  let mean=0;for(const [index,value]of values.entries())mean+=(value-mean)/(index+1);
  return {count:values.length,mean,p50:quantile(.5),p95:quantile(.95),p99:quantile(.99),max:ordered.at(-1)};
}
function settingRange(rows,field){
  const values=rows.map(row=>row[field]);
  return {first:values[0],last:values.at(-1),min:values.reduce((a,b)=>Math.min(a,b)),max:values.reduce((a,b)=>Math.max(a,b)),
    distinctValues:[...new Set(values)].sort((a,b)=>a-b)};
}

/** Paint samples record simulation state at paint completion. The simulation
 * rate uses completion-to-completion wall time, matching those state snapshots.
 * A native automatic setting change is reported; a controlled run requires
 * each setting to retain its expected value (or its first observed value).
 */
export function summarizeRun(input){
  const {samples,presentation,expected,controlled}=input&&typeof input==='object'?input:{};
  const errors=[];
  const result={format:1,valid:false,controlled,expected:expected?{...expected}:null,
    invariants:{passed:false,errors},sampleCount:Array.isArray(samples)?samples.length:0,
    paintDuration:null,paintInterval:null,contentInterval:null,
    simulationSecondsPerWallSecond:null,sampledContentFramesPerSecond:null,
    observation:null,settings:null,presentation:{kind:'requestAnimationFrame content observer proxy',
      physicalPresentationMeasured:false,sampleCount:Array.isArray(presentation)?presentation.length:0}};
  if(!expected||!integer(expected.frames)||expected.frames<2)
    errors.push(error('invalid_expected_frames','Expected frame count must be an integer of at least two.'));
  if(typeof controlled!=='boolean')errors.push(error('invalid_control_regime','Controlled must explicitly be true or false.'));
  for(const field of settings){
    if(expected?.[field]!==undefined&&(!finite(expected[field])||expected[field]<0))
      errors.push(error('invalid_expected_setting','Expected settings must be finite nonnegative numbers.',{field}));
  }
  if(!Array.isArray(samples)||samples.length<2)
    errors.push(error('missing_paint_samples','At least two paint samples are required.'));
  else if(integer(expected?.frames)&&samples.length!==expected.frames)
    errors.push(error(samples.length<expected.frames?'short_sample':'unexpected_sample_count',
      'Paint sample count differs from the requested frame count.',{expected:expected.frames,actual:samples.length}));
  if(!Array.isArray(presentation)||presentation.length<2)
    errors.push(error('missing_content_samples','At least two content observations are required.'));
  if(!Array.isArray(samples)||!Array.isArray(presentation))return result;

  for(const [index,row]of samples.entries()){
    if(!row||typeof row!=='object'){errors.push(error('invalid_paint_sample','Paint sample must be an object.',{index}));continue;}
    if(!integer(row.frame))errors.push(error('invalid_frame','Paint frame must be a nonnegative safe integer.',{index}));
    for(const field of ['start','duration','time',...settings]){
      if(!finite(row[field]))errors.push(error('nonfinite_sample','Sample field must be a finite number.',{index,field}));
      else if(field!=='time'&&row[field]<0)errors.push(error('negative_sample','Timing and setting fields must be nonnegative.',{index,field}));
    }
    if(row.error!==null&&row.error!==undefined&&row.error!==false)
      errors.push(error('runtime_error','A paint reported a runtime error.',{index,detail:String(row.error)}));
    const previous=samples[index-1];
    if(previous){
      if(integer(row.frame)&&integer(previous.frame)&&row.frame!==previous.frame+1)
        errors.push(error('frame_gap','Paint frames must be contiguous and ordered.',{index,previous:previous.frame,actual:row.frame}));
      if(finite(row.start)&&finite(previous.start)&&row.start<=previous.start)
        errors.push(error('paint_clock_backwards','Paint starts must advance strictly.',{index}));
      if(finite(row.time)&&finite(previous.time)&&row.time<previous.time)
        errors.push(error('simulation_time_backwards','Simulation time decreased.',{index}));
    }
    if(controlled===true){
      for(const field of settings){
        const target=expected?.[field]??samples[0]?.[field];
        if(finite(row[field])&&finite(target)&&row[field]!==target)
          errors.push(error('setting_drift','A controlled setting differs from its expected value.',{index,field,expected:target,actual:row[field]}));
      }
    }
  }
  const paintByFrame=new Map(samples.filter(row=>row&&integer(row.frame)).map(row=>[row.frame,row]));
  for(const [index,row]of presentation.entries()){
    if(!row||typeof row!=='object'){errors.push(error('invalid_content_sample','Content observation must be an object.',{index}));continue;}
    if(!integer(row.frame))errors.push(error('invalid_content_frame','Observed frame must be a nonnegative safe integer.',{index}));
    for(const field of ['timestamp','sampledAt','time']){
      if(!finite(row[field]))errors.push(error('nonfinite_content_sample','Content field must be a finite number.',{index,field}));
      else if(field!=='time'&&row[field]<0)errors.push(error('negative_content_clock','Content timestamps must be nonnegative.',{index,field}));
    }
    // These clocks are provided independently and can be quantized differently.
    // Validate each sequence, without inferring an order between the clocks.
    const previous=presentation[index-1];
    if(previous){
      if(finite(row.sampledAt)&&finite(previous.sampledAt)&&row.sampledAt<previous.sampledAt)
        errors.push(error('content_clock_backwards','Content callback observation time must not decrease.',{index}));
      // Chrome can repeat its animation timestamp while callback delivery and
      // completed content advance. Cadence uses sampledAt, not this timestamp.
      if(finite(row.timestamp)&&finite(previous.timestamp)&&row.timestamp<previous.timestamp)
        errors.push(error('raf_clock_backwards','rAF timestamps must not decrease.',{index}));
      if(integer(row.frame)&&integer(previous.frame)&&row.frame<previous.frame)
        errors.push(error('content_frame_backwards','Observed content frame decreased.',{index}));
      if(finite(row.time)&&finite(previous.time)&&row.time<previous.time)
        errors.push(error('content_time_backwards','Observed simulation time decreased.',{index}));
    }
    const paint=paintByFrame.get(row.frame);
    if(paint&&finite(row.time)&&finite(paint.time)&&row.time!==paint.time)
      errors.push(error('content_time_mismatch','Content state does not match the corresponding completed paint.',{index,frame:row.frame}));
  }
  if(errors.length)return result;

  const first=samples[0],last=samples.at(-1),firstEnd=first.start+first.duration,lastEnd=last.start+last.duration;
  const completionWall=lastEnd-firstEnd;
  if(!finite(firstEnd)||!finite(lastEnd)||completionWall<=0){
    errors.push(error('invalid_wall_interval','Paint completion boundaries must have positive finite elapsed time.'));return result;
  }
  const content=[];
  for(const row of presentation){
    if(row.frame<first.frame||row.frame>last.frame)continue;
    if(content.at(-1)?.frame!==row.frame)content.push(row);
  }
  if(content.length<2){errors.push(error('short_content_sample','At least two distinct content frames inside the paint sample are required.'));return result;}
  const paintIntervals=samples.slice(1).map((row,index)=>row.start-samples[index].start);
  const contentIntervals=content.slice(1).map((row,index)=>row.sampledAt-content[index].sampledAt);
  const simulationElapsed=last.time-first.time,contentWall=content.at(-1).sampledAt-content[0].sampledAt;
  const simulationRate=simulationElapsed/(completionWall/1000),contentRate=(content.length-1)/(contentWall/1000);
  if(!finite(simulationElapsed)||!finite(simulationRate)||!finite(contentRate)){
    errors.push(error('nonfinite_derived_metric','Derived rates must remain finite.'));return result;
  }
  result.paintDuration=statistics(samples.map(row=>row.duration));
  result.paintInterval=statistics(paintIntervals);
  result.contentInterval=statistics(contentIntervals);
  result.simulationSecondsPerWallSecond=simulationRate;
  result.sampledContentFramesPerSecond=contentRate;
  result.settings=Object.fromEntries(settings.map(field=>[field,settingRange(samples,field)]));
  result.observation={paintFrames:samples.length,firstFrame:first.frame,lastFrame:last.frame,
    wallMilliseconds:lastEnd-first.start,completionWallMilliseconds:completionWall,
    simulationSeconds:simulationElapsed,observedContentFrames:content.length,contentWallMilliseconds:contentWall};
  result.presentation={...result.presentation,distinctContentFrames:content.length,
    heldContentObservations:presentation.filter(row=>row.frame>=first.frame&&row.frame<=last.frame).length-content.length,
    skippedPaintFrames:content.slice(1).reduce((sum,row,index)=>sum+row.frame-content[index].frame-1,0),
    intervalClock:'sampledAt: actual callback delivery time',
    callbackClockOffset:{...statistics(presentation.map(row=>row.sampledAt-row.timestamp)),
      min:presentation.reduce((minimum,row)=>Math.min(minimum,row.sampledAt-row.timestamp),Infinity),
      definition:'Signed sampledAt minus rAF timestamp; diagnostic only, not a delay or ordering assertion.'}};
  result.valid=true;result.invariants.passed=true;return result;
}

const relativeRatio=(value,reference)=>{
  const ratio=reference===0?(value===0?1:null):value/reference;
  return finite(ratio)?ratio:null;
};
const aggregate=values=>({runCount:values.length,median:median(values),min:Math.min(...values),max:Math.max(...values),values:values.slice()});
function validStats(stats){
  return stats&&integer(stats.count)&&stats.count>0&&['mean','p50','p95','p99','max'].every(field=>finite(stats[field])&&stats[field]>=0)
    &&stats.p50<=stats.p95&&stats.p95<=stats.p99&&stats.p99<=stats.max&&stats.mean<=stats.max;
}
function measuredSummary(summary){
  return summary?.valid===true&&summary.invariants?.passed===true&&Array.isArray(summary.invariants.errors)&&summary.invariants.errors.length===0
    &&['paintDuration','paintInterval','contentInterval'].every(field=>validStats(summary[field]))
    &&finite(summary.simulationSecondsPerWallSecond)&&summary.simulationSecondsPerWallSecond>=0
    &&finite(summary.sampledContentFramesPerSecond)&&summary.sampledContentFramesPerSecond>0
    &&integer(summary.expected?.frames)&&summary.expected.frames>=2&&typeof summary.controlled==='boolean'
    &&summary.sampleCount===summary.expected.frames&&summary.paintDuration.count===summary.expected.frames
    &&summary.paintInterval.count===summary.expected.frames-1
    &&settings.every(field=>summary.expected[field]===undefined||(finite(summary.expected[field])&&summary.expected[field]>=0));
}
function repeatedMetric(path,baseline,candidate,maxRatio){
  const read=row=>path.split('.').reduce((value,key)=>value?.[key],row);
  const reference=aggregate(baseline.map(read)),actual=aggregate(candidate.map(read));
  const ratio=relativeRatio(actual.median,reference.median),conservative=relativeRatio(actual.max,reference.min);
  const spread=value=>value.median===0?(value.max===0?0:null):relativeRatio(value.max-value.min,value.median);
  const referenceSpread=spread(reference),candidateSpread=spread(actual);
  const provisional=referenceSpread===null||candidateSpread===null||referenceSpread>.2||candidateSpread>.2;
  const relativeVerdict=actual.median<=reference.median*maxRatio?'met':'not_met';
  const absoluteThresholdMs=path==='inputLatency.p95'?100:null;
  const absoluteVerdict=absoluteThresholdMs===null?null:actual.median<absoluteThresholdMs?'met':'not_met';
  return {metric:path,unit:'milliseconds',baseline:reference,candidate:actual,ratio,
    conservativeRatio:conservative,observedRatioRange:{min:relativeRatio(actual.min,reference.max),max:conservative},
    repeatSpread:{baseline:referenceSpread,candidate:candidateSpread},maxRatio,
    relativeVerdict,absoluteThresholdMs,absoluteVerdict,
    verdict:relativeVerdict==='not_met'||absoluteVerdict==='not_met'?'not_met':'met',provisional};
}

/** Each run is {edition,scenario,summary,inputLatency?}. Flattened summaries
 * with edition/scenario are also accepted. Different editions may be compared
 * for the same scenario; native dt is recorded and preserved independently.
 * The verdict covers measured tail timings only. Missing input latency remains
 * unavailable and cannot certify a latency goal. Repeat range is empirical,
 * not a confidence interval; a spread above20% makes acceptance provisional.
 */
export function compareRuns(baselineRuns,candidateRuns,options){
  const maxRatio=options===undefined?1.1:options&&typeof options==='object'
    ?options.maxRatio===undefined?1.1:options.maxRatio:NaN;
  const errors=[],groups=[];
  const result={format:1,verdict:'invalid',provisional:false,maxRatio,
    scope:'Measured comparable p95/p99 timing metrics only; no complete-goal or physical-presentation claim.',
    aggregation:'Median of per-run quantiles; empirical repeat range is not a confidence interval.',
    physicalPresentationMeasured:false,errors,groups};
  if(!finite(maxRatio)||maxRatio<=0)errors.push(error('invalid_max_ratio','Maximum ratio must be a positive finite number.'));
  const arms={baseline:new Map(),candidate:new Map()};
  for(const [arm,runs]of [['baseline',baselineRuns],['candidate',candidateRuns]]){
    if(!Array.isArray(runs)||runs.length===0){errors.push(error('missing_runs','Both arms require measured runs.',{arm}));continue;}
    for(const [index,run]of runs.entries()){
      if(!run||typeof run.edition!=='string'||!run.edition||typeof run.scenario!=='string'||!run.scenario){
        errors.push(error('missing_run_identity','Each run requires edition and scenario.',{arm,index}));continue;
      }
      const summary=run.summary??run;
      if(!measuredSummary(summary)){errors.push(error('invalid_run_summary','A run has missing or invalid timing/invariant evidence.',{arm,index,scenario:run.scenario}));continue;}
      const latency=run.inputLatency??summary.inputLatency;
      if(latency!==undefined&&latency!==null&&(!validStats(latency.stats??latency)||typeof latency.kind!=='string'||!latency.kind)){
        errors.push(error('invalid_input_latency','Provided input latency requires finite measured statistics and a measurement kind.',{arm,index}));continue;
      }
      if(!arms[arm].has(run.scenario))arms[arm].set(run.scenario,[]);
      arms[arm].get(run.scenario).push({edition:run.edition,summary,latency});
    }
  }
  for(const scenario of new Set([...arms.baseline.keys(),...arms.candidate.keys()])){
    const baseline=arms.baseline.get(scenario)??[],candidate=arms.candidate.get(scenario)??[];
    const issues=[];
    if(baseline.length<2||candidate.length<2)issues.push(error('insufficient_repeats','Each scenario needs at least two runs in each arm.'));
    for(const [arm,rows]of [['baseline',baseline],['candidate',candidate]]){
      if(new Set(rows.map(row=>row.edition)).size>1)issues.push(error('mixed_editions','An arm mixes editions for one scenario.',{arm}));
    }
    const all=[...baseline,...candidate];
    for(const field of ['frames','speed','autoSlow']){
      if(new Set(all.map(row=>row.summary.expected[field])).size>1)
        issues.push(error('incomparable_setting','Requested settings differ between runs.',{field}));
    }
    if(new Set(all.map(row=>row.summary.controlled)).size>1)issues.push(error('incomparable_control_regime','Native and controlled runs cannot share one comparison.'));
    if(all[0]?.summary.controlled===true){
      for(const [arm,rows]of [['baseline',baseline],['candidate',candidate]]){
        if(new Set(rows.map(row=>row.summary.expected.dt)).size>1)
          issues.push(error('incomparable_dt','Controlled dt differs within an edition arm.',{arm}));
      }
      if(baseline[0]?.edition===candidate[0]?.edition&&baseline[0]?.summary.expected.dt!==candidate[0]?.summary.expected.dt)
        issues.push(error('incomparable_dt','Controlled dt differs for the same edition.'));
    }
    const group={scenario,baselineEdition:baseline[0]?.edition??null,candidateEdition:candidate[0]?.edition??null,
      verdict:'invalid',provisional:false,errors:issues,metrics:[],latency:{availability:'unavailable',reason:'Not measured in every run.',physicalPresentationMeasured:false}};
    groups.push(group);
    if(issues.length)continue;
    group.nativeDt={baseline:baseline[0].summary.expected.dt??null,candidate:candidate[0].summary.expected.dt??null,
      baselinePerRun:baseline.map(row=>row.summary.expected.dt??null),candidatePerRun:candidate.map(row=>row.summary.expected.dt??null)};
    const reference=baseline.map(row=>row.summary),actual=candidate.map(row=>row.summary);
    group.metrics=metricPaths.map(path=>repeatedMetric(path,reference,actual,maxRatio));
    const latencies=all.map(row=>row.latency);
    if(latencies.every(Boolean)){
      const kinds=new Set(latencies.map(value=>value.kind));
      if(kinds.size===1){
        group.latency={availability:'available',kind:latencies[0].kind,physicalPresentationMeasured:false};
        const referenceLatency=baseline.map(row=>({inputLatency:row.latency.stats??row.latency}));
        const actualLatency=candidate.map(row=>({inputLatency:row.latency.stats??row.latency}));
        group.metrics.push(...['inputLatency.p95','inputLatency.p99'].map(path=>repeatedMetric(path,referenceLatency,actualLatency,maxRatio)));
      }else group.latency.reason='Measurement kinds differ between runs.';
    }
    group.verdict=group.metrics.some(row=>row.verdict==='not_met')?'not_met':'met';
    group.provisional=group.metrics.some(row=>row.provisional);
  }
  if(errors.length||!groups.length||groups.some(group=>group.verdict==='invalid'))return result;
  result.verdict=groups.some(group=>group.verdict==='not_met')?'not_met':'met';
  result.provisional=groups.some(group=>group.provisional);return result;
}

const canonical=value=>JSON.stringify(value,(_key,item)=>item&&typeof item==='object'&&!Array.isArray(item)
  ?Object.fromEntries(Object.keys(item).sort().map(key=>[key,item[key]])):item);
function contextOf(run){
  const metadata=run.metadata,launch=metadata?.launch,gpu=launch?.systemInfo?.gpu;
  const version=launch?.version,bounds=launch?.window?.bounds,viewport=metadata?.environment?.viewport;
  const canvas=run.actual?.canvas,dimensions=run.actual?.dimensions;
  const positive=value=>finite(value)&&value>0;
  if(metadata?.headless!==false||metadata.gpu!==true||launch?.requested?.headless!==false||launch.requested.gpu!==true
    ||metadata.gpuValidation?.passed!==true)return {error:'Headed GPU-enabled launch evidence is missing or failed.'};
  if(!version||!['product','revision','jsVersion','protocolVersion'].every(field=>typeof version[field]==='string'&&version[field]))
    return {error:'Actual browser version evidence is incomplete.'};
  if(!gpu||!Array.isArray(gpu.devices)||!gpu.devices.length||!gpu.featureStatus||!gpu.auxAttributes
    ||typeof gpu.auxAttributes.glRenderer!=='string'||!gpu.auxAttributes.glRenderer
    ||!['2d_canvas','gpu_compositing','rasterization'].every(field=>/^enabled(?:_|$)/.test(gpu.featureStatus[field]??'')))
    return {error:'Actual GPU device, renderer, or enabled feature evidence is incomplete.'};
  if(!bounds||!['width','height'].every(field=>integer(bounds[field])&&bounds[field]>0)
    ||bounds.width!==launch.requested.width||bounds.height!==launch.requested.height)
    return {error:'Actual window bounds do not retain the requested dimensions.'};
  if(!viewport||!['width','height','outerWidth','outerHeight'].every(field=>positive(viewport[field]))
    ||!positive(metadata.environment.devicePixelRatio)||!metadata.layoutViewportOverride
    ||viewport.width!==metadata.layoutViewportOverride.width||viewport.height!==metadata.layoutViewportOverride.height
    ||metadata.environment.devicePixelRatio!==metadata.layoutViewportOverride.deviceScaleFactor)
    return {error:'Actual layout viewport or pixel ratio evidence is incomplete or differs from the requested override.'};
  if(!canvas||!['width','height'].every(field=>integer(canvas[field])&&canvas[field]>0)
    ||!['cssWidth','cssHeight'].every(field=>positive(canvas[field]))
    ||!dimensions||!['width','height','bitsPixel'].every(field=>integer(dimensions[field])&&dimensions[field]>0))
    return {error:'Actual canvas backing/CSS dimensions or simulator surface evidence is incomplete.'};
  if(run.profile||metadata.timingScope?.startsWith('CPU/stage-profile'))return {error:'Profiled runs are ineligible for timing comparisons.'};
  const auxiliaryFields=['glRenderer','glVendor','glVersion','glImplementationParts','displayType',
    'inProcessGpu','passthroughCmdDecoder','softwareRendering'];
  return {value:{browser:Object.fromEntries(['product','revision','jsVersion','protocolVersion'].map(field=>[field,version[field]])),
    gpu:{devices:gpu.devices,featureStatus:gpu.featureStatus,
      auxiliary:Object.fromEntries(auxiliaryFields.filter(field=>field in gpu.auxAttributes).map(field=>[field,gpu.auxAttributes[field]]))},
    window:{width:bounds.width,height:bounds.height},viewport:{...viewport,devicePixelRatio:metadata.environment.devicePixelRatio},
    canvas:{width:canvas.width,height:canvas.height,cssWidth:canvas.cssWidth,cssHeight:canvas.cssHeight},
    dimensions:{width:dimensions.width,height:dimensions.height,bitsPixel:dimensions.bitsPixel}}};
}
function moduleSetOf(run){
  if(!Array.isArray(run.moduleSources)||!run.moduleSources.length)return {error:'Loaded module source hashes are missing.'};
  const seen=new Set(),modules=[];
  for(const row of run.moduleSources){
    if(row?.error||typeof row?.url!=='string'||typeof row.sha256!=='string'||!/^[0-9a-f]{64}$/.test(row.sha256)
      ||!integer(row.bytes)||row.bytes===0)return {error:'A loaded module source record is missing or invalid.'};
    let identity;try{const url=new URL(row.url);identity=url.pathname+url.search;}catch{return {error:'A loaded module URL is invalid.'};}
    if(seen.has(identity))return {error:'Duplicate loaded module identity.'};
    seen.add(identity);modules.push({path:identity,bytes:row.bytes,sha256:row.sha256});
  }
  return {value:modules.sort((a,b)=>a.path<b.path?-1:a.path>b.path?1:0)};
}

/** Context equality excludes ephemeral process, websocket and window IDs.
 * Edition-specific native canvas geometry is recorded separately. It must
 * remain stable across repeats and same-edition comparisons, while shared
 * browser/device/window/viewport and simulator dimensions remain identical.
 * Runtime hashes must match within an edition/scenario arm across repeats;
 * baseline and candidate module sets may differ for legitimate code changes.
 * The caller combines this validity result with compareRuns, so missing old
 * context evidence cannot silently certify a comparison.
 */
export function compareRunContexts(baselineRuns,candidateRuns){
  const errors=[],contexts=new Map(),surfaces=new Map(),moduleSets=new Map();
  for(const [arm,runs]of [['baseline',baselineRuns],['candidate',candidateRuns]]){
    if(!Array.isArray(runs)||runs.length===0){errors.push(error('missing_context_runs','Both comparison arms require context evidence.',{arm}));continue;}
    for(const [index,run]of runs.entries()){
      if(!run||typeof run.edition!=='string'||!run.edition||typeof run.scenario!=='string'||!run.scenario){
        errors.push(error('missing_context_identity','Context requires edition and scenario.',{arm,index}));continue;
      }
      const context=contextOf(run),modules=moduleSetOf(run);
      if(context.error)errors.push(error('invalid_context',context.error,{arm,index,scenario:run.scenario}));
      else{
        const {canvas,...commonContext}=context.value;
        const previous=contexts.get(run.scenario);
        if(previous&&canonical(previous)!==canonical(commonContext))errors.push(error('context_mismatch',
          'Actual browser, GPU, window, viewport or simulator dimensions differ.',{arm,index,scenario:run.scenario}));
        else if(!previous)contexts.set(run.scenario,commonContext);
        const surfaceKey=canonical([run.edition,run.scenario]),previousSurface=surfaces.get(surfaceKey);
        if(previousSurface&&canonical(previousSurface.canvas)!==canonical(canvas))errors.push(error('surface_mismatch',
          'Native canvas backing/CSS dimensions changed within an edition/scenario.',{arm,index,edition:run.edition,scenario:run.scenario}));
        else if(!previousSurface)surfaces.set(surfaceKey,{edition:run.edition,scenario:run.scenario,canvas,arms:new Set([arm])});
        if(previousSurface)previousSurface.arms.add(arm);
      }
      if(modules.error)errors.push(error('invalid_module_sources',modules.error,{arm,index,scenario:run.scenario}));
      else{
        const key=canonical([arm,run.edition,run.scenario]),previous=moduleSets.get(key);
        if(previous&&canonical(previous)!==canonical(modules.value))errors.push(error('module_sources_changed',
          'Loaded runtime source hashes changed within an edition arm across repetitions.',{arm,index,edition:run.edition,scenario:run.scenario}));
        else if(!previous)moduleSets.set(key,modules.value);
      }
    }
  }
  const surfaceDifferences=[];
  for(const baseline of surfaces.values())for(const candidate of surfaces.values()){
    if(!baseline.arms.has('baseline')||!candidate.arms.has('candidate')||baseline.scenario!==candidate.scenario
      ||baseline.edition===candidate.edition||canonical(baseline.canvas)===canonical(candidate.canvas))continue;
    surfaceDifferences.push({scenario:baseline.scenario,
      baseline:{edition:baseline.edition,canvas:baseline.canvas},candidate:{edition:candidate.edition,canvas:candidate.canvas},
      differences:Object.keys(baseline.canvas).filter(field=>baseline.canvas[field]!==candidate.canvas[field])
        .map(field=>({field,baseline:baseline.canvas[field],candidate:candidate.canvas[field]})),
      interpretation:'Native edition-specific canvas geometry; workloads may differ despite matched simulator settings.'});
  }
  return {valid:errors.length===0,errors,contexts:[...contexts].map(([scenario,context])=>({scenario,...context})),
    surfaces:[...surfaces.values()].map(({arms,...surface})=>({...surface,arms:[...arms]})),surfaceDifferences,
    moduleSets:[...moduleSets].map(([key,modules])=>{const [arm,edition,scenario]=JSON.parse(key);return {arm,edition,scenario,modules};})};
}
