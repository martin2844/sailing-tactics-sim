import test from 'node:test';
import assert from 'node:assert/strict';
import {summarizeRun,compareRuns,compareRunContexts} from '../tools/evaluation/metrics.js';

function raw(factor=1){
  const times=[2,2.1,2.2,2.3],starts=[10,20,60,70],durations=[2,3,8,4];
  const samples=starts.map((start,index)=>({frame:100+index,start:start*factor,duration:durations[index]*factor,
    time:times[index],dt:.1,speed:10,autoSlow:0,error:null}));
  const presentation=[[100,12,13,2],[100,14,16,2],[101,20,26,2.1],[103,70,76,2.3]]
    .map(([frame,timestamp,sampledAt,time])=>({frame,timestamp:timestamp*factor,sampledAt:sampledAt*factor,time}));
  return {samples,presentation,expected:{frames:4,speed:10,dt:.1,autoSlow:0},controlled:true};
}
const run=(factor=1,edition='2010',scenario='speed10')=>({edition,scenario,summary:summarizeRun(raw(factor))});

test('irregular cadence measures paint tails and changed-content rAF delivery, excluding held frames',()=>{
  const summary=summarizeRun(raw());
  assert.equal(summary.valid,true);
  assert.deepEqual(summary.paintDuration,{count:4,mean:4.25,p50:3,p95:8,p99:8,max:8});
  assert.deepEqual(summary.paintInterval,{count:3,mean:20,p50:10,p95:40,p99:40,max:40});
  assert.deepEqual(summary.contentInterval,{count:2,mean:31.5,p50:13,p95:50,p99:50,max:50});
  assert.ok(Math.abs(summary.simulationSecondsPerWallSecond-.3/.062)<1e-12);
  assert.ok(Math.abs(summary.sampledContentFramesPerSecond-2/.063)<1e-12);
  assert.equal(summary.presentation.heldContentObservations,1);
  assert.equal(summary.presentation.skippedPaintFrames,1);
  assert.equal(summary.presentation.physicalPresentationMeasured,false);
});

test('native slowdown remains visible while a controlled setting drift invalidates the run',()=>{
  const input=raw();input.samples[2].speed=1;input.samples[3].autoSlow=1;
  const controlled=summarizeRun(input);
  assert.equal(controlled.valid,false);
  assert.deepEqual(controlled.invariants.errors.filter(row=>row.code==='setting_drift').map(row=>row.field),['speed','autoSlow']);
  const native=summarizeRun({...input,controlled:false});
  assert.equal(native.valid,true);
  assert.deepEqual(native.settings.speed.distinctValues,[1,10]);
  assert.deepEqual(native.settings.autoSlow.distinctValues,[0,1]);
});

test('clock-quantized consecutive rAF observations may share sampledAt while timestamp advances',()=>{
  const input=raw();
  input.presentation.splice(2,0,{frame:100,timestamp:15,sampledAt:16,time:2});
  const summary=summarizeRun(input);
  assert.equal(summary.valid,true);
  assert.equal(summary.presentation.heldContentObservations,2);
  assert.deepEqual(summary.contentInterval,summarizeRun(raw()).contentInterval);
  input.presentation[2].sampledAt=15.5;
  assert.ok(summarizeRun(input).invariants.errors.some(row=>row.code==='content_clock_backwards'));
});

test('independently quantized rAF and observation clocks may have signed negative offsets',()=>{
  const input=raw();
  input.presentation.unshift({frame:99,timestamp:9.5,sampledAt:9.29999999702,time:1.9});
  input.presentation[1].timestamp=13.2;
  const summary=summarizeRun(input);
  assert.equal(summary.valid,true);
  assert.equal(summary.presentation.callbackClockOffset.count,5);
  assert.ok(summary.presentation.callbackClockOffset.min<-.2);
  assert.equal(summary.presentation.callbackDelay,undefined);
  assert.deepEqual(summary.contentInterval,summarizeRun(raw()).contentInterval);
  input.presentation[2].timestamp=13;
  assert.ok(summarizeRun(input).invariants.errors.some(row=>row.code==='raf_clock_backwards'));
  input.presentation[2].timestamp=14;
  input.presentation[2].sampledAt=12;
  assert.ok(summarizeRun(input).invariants.errors.some(row=>row.code==='content_clock_backwards'));
});

test('invariants fail closed on missing, short, nonfinite, backwards and gapped observations',()=>{
  assert.equal(summarizeRun().valid,false);
  assert.equal(summarizeRun(null).valid,false);
  for(const [code,mutate]of [
    ['short_sample',input=>input.samples.pop()],
    ['nonfinite_sample',input=>{input.samples[1].duration=NaN;}],
    ['simulation_time_backwards',input=>{input.samples[1].time=1;}],
    ['frame_gap',input=>{input.samples[2].frame=105;}],
    ['runtime_error',input=>{input.samples[1].error='stopped';}],
    ['short_content_sample',input=>{input.presentation=input.presentation.slice(0,2);}]
  ]){
    const input=raw();mutate(input);const summary=summarizeRun(input);
    assert.equal(summary.valid,false,code);
    assert.ok(summary.invariants.errors.some(row=>row.code===code),code);
  }
});

test('repeat comparisons allow different editions, report missing latency and reject invalid or incomplete evidence',()=>{
  const baseline=[run(1,'2002'),run(1.01,'2002')],candidate=[run(1.05),run(1.06)];
  const comparison=compareRuns(baseline,candidate);
  assert.equal(comparison.verdict,'met');assert.equal(comparison.provisional,false);
  assert.equal(comparison.groups[0].baselineEdition,'2002');
  assert.equal(comparison.groups[0].candidateEdition,'2010');
  assert.equal(comparison.groups[0].latency.availability,'unavailable');
  assert.equal(comparison.groups[0].metrics.length,6);
  assert.equal(compareRuns(baseline,[run(1.3),run(1.31)]).verdict,'not_met');
  assert.equal(compareRuns([],candidate).verdict,'invalid');
  assert.equal(compareRuns(baseline,candidate,null).verdict,'invalid');
  assert.equal(compareRuns(baseline,candidate,{maxRatio:null}).verdict,'invalid');
  assert.equal(compareRuns([baseline[0]],candidate).verdict,'invalid');
  assert.equal(compareRuns(baseline,[run(1,'2010','other'),run(1,'2010','other')]).verdict,'invalid');
  const bad=run();bad.summary.paintInterval.p95=Infinity;
  assert.equal(compareRuns(baseline,[bad,run()]).verdict,'invalid');
  const noisy=compareRuns([run(1,'2002'),run(1,'2002'),run(1,'2002')],[run(),run(),run(2)]);
  assert.equal(noisy.verdict,'met');assert.equal(noisy.provisional,true);
  assert.equal(noisy.groups[0].metrics[0].conservativeRatio,2);
});

function contextual(edition='2010',sha='b'.repeat(64)){
  return {...run(1,edition),metadata:{headless:false,gpu:true,
    gpuValidation:{passed:true},layoutViewportOverride:{width:1280,height:1050,deviceScaleFactor:1,mobile:false},
    environment:{devicePixelRatio:1,viewport:{width:1280,height:1050,outerWidth:1280,outerHeight:1050}},
    launch:{requested:{headless:false,gpu:true,width:1280,height:1050},
      version:{product:'Chrome/140',revision:'abc',jsVersion:'14',protocolVersion:'1.3'},
      systemInfo:{gpu:{devices:[{vendorId:4098,deviceId:123,driverVersion:'24',vendorString:'AMD'}],
        auxAttributes:{glRenderer:'ANGLE AMD',glVendor:'AMD',glVersion:'4.6'},
        featureStatus:{'2d_canvas':'enabled','gpu_compositing':'enabled','rasterization':'enabled'}}},
      window:{windowId:1,bounds:{width:1280,height:1050}}}},
    actual:{canvas:{width:1024,height:768,cssWidth:1024,cssHeight:768},dimensions:{width:1024,height:768,bitsPixel:24}},
    moduleSources:[{url:`http://127.0.0.1:8765/${edition}/play.js`,bytes:100,sha256:sha}]};
}

test('actual context validation ignores ephemeral IDs and allows candidate source changes across arms',()=>{
  const baseline=[contextual('2010','a'.repeat(64)),contextual('2010','a'.repeat(64))];
  const candidate=[contextual(),contextual()];
  candidate[1].metadata.launch.window.windowId=99;
  candidate[1].metadata.launch.processId=400;
  candidate[1].moduleSources[0].url='http://localhost:9000/2010/play.js';
  assert.equal(compareRunContexts(baseline,candidate).valid,true);
  assert.equal(compareRunContexts([contextual('2002'),contextual('2002')],candidate).valid,true);
});

test('native canvas differences across editions are recorded; repeat and same-edition geometry drift still fail',()=>{
  const baseline=[contextual('2002'),contextual('2002')],candidate=[contextual(),contextual()];
  for(const row of baseline)row.actual.canvas={width:1024,height:730,cssWidth:1028,cssHeight:732.84375};
  for(const row of candidate)row.actual.canvas={width:1024,height:723,cssWidth:1028,cssHeight:725.8125};
  const context=compareRunContexts(baseline,candidate);
  assert.equal(context.valid,true);
  assert.equal(context.surfaceDifferences.length,1);
  assert.deepEqual(context.surfaceDifferences[0].differences,[
    {field:'height',baseline:730,candidate:723},{field:'cssHeight',baseline:732.84375,candidate:725.8125}]);
  assert.deepEqual(context.contexts[0].dimensions,{width:1024,height:768,bitsPixel:24});
  assert.equal(context.surfaces.length,2);
  const drift=structuredClone(candidate);drift[1].actual.canvas.cssHeight+=1;
  assert.ok(compareRunContexts(baseline,drift).errors.some(row=>row.code==='surface_mismatch'));
  const sameEdition=structuredClone(baseline);for(const row of sameEdition)row.edition='2010';
  assert.ok(compareRunContexts(sameEdition,candidate).errors.some(row=>row.code==='surface_mismatch'));
  const wrongSimulator=structuredClone(candidate);for(const row of wrongSimulator)row.actual.dimensions.height=723;
  assert.ok(compareRunContexts(baseline,wrongSimulator).errors.some(row=>row.code==='context_mismatch'));
});

test('actual browser/GPU/surface mismatches and inconsistent module hashes fail closed',()=>{
  for(const mutate of [
    row=>{row.metadata.launch.version.product='Chrome/141';},
    row=>{row.metadata.launch.systemInfo.gpu.devices[0].driverVersion='25';},
    row=>{row.metadata.launch.systemInfo.gpu.auxAttributes.glRenderer='other renderer';},
    row=>{row.metadata.launch.systemInfo.gpu.featureStatus.rasterization='disabled_software';},
    row=>{row.metadata.launch.window.bounds.width=1279;},
    row=>{row.actual.canvas.cssWidth=900;},
    row=>{row.actual.canvas.height=700;},
    row=>{row.moduleSources[0].sha256='c'.repeat(64);},
    row=>{delete row.moduleSources;},
    row=>{delete row.metadata.launch;},
    row=>{row.profile={nodes:[]};},
  ]){
    const baseline=[contextual('2002'),contextual('2002')],candidate=[contextual(),contextual()];
    mutate(candidate[1]);assert.equal(compareRunContexts(baseline,candidate).valid,false);
  }
  assert.equal(compareRunContexts([],[]).valid,false);
});

test('measured input latency requires both reference parity and strict p95 below 100 ms',()=>{
  const latency=value=>({kind:'trusted input to changed completed canvas observed at rAF',
    count:12,mean:value,p50:value,p95:value,p99:value,max:value});
  const withLatency=value=>[run(),run()].map(row=>({...row,inputLatency:latency(value)}));
  const overAbsolute=compareRuns(withLatency(150),withLatency(110));
  assert.equal(overAbsolute.verdict,'not_met');
  const metric=overAbsolute.groups[0].metrics.find(row=>row.metric==='inputLatency.p95');
  assert.equal(metric.relativeVerdict,'met');assert.equal(metric.absoluteThresholdMs,100);
  assert.equal(metric.absoluteVerdict,'not_met');
  assert.equal(compareRuns(withLatency(100),withLatency(100)).verdict,'not_met');
  assert.equal(compareRuns(withLatency(90),withLatency(99)).verdict,'met');
  assert.equal(compareRuns(withLatency(80),withLatency(95)).verdict,'not_met');
  const incomplete=withLatency(80);delete incomplete[1].inputLatency;
  const unavailable=compareRuns(withLatency(80),incomplete);
  assert.equal(unavailable.groups[0].latency.availability,'unavailable');
  assert.ok(!unavailable.groups[0].metrics.some(row=>row.metric==='inputLatency.p95'));
  const malformed=withLatency(80);malformed[0].inputLatency.p95=NaN;
  assert.equal(compareRuns(withLatency(80),malformed).verdict,'invalid');
});

test('native dt changes across repeats are observations; controlled dt changes invalidate comparability',()=>{
  const native=dt=>{
    const input=raw();input.controlled=false;input.expected.dt=dt;
    for(const sample of input.samples)sample.dt=dt;
    return {edition:'2010',scenario:'native',summary:summarizeRun(input)};
  };
  const comparison=compareRuns([native(.1),native(.2)],[native(.3),native(.4)]);
  assert.equal(comparison.verdict,'met');assert.equal(comparison.provisional,false);
  assert.deepEqual(comparison.groups[0].nativeDt.baselinePerRun,[.1,.2]);
  const changed=run();changed.summary.expected.dt=.2;
  assert.equal(compareRuns([run(),run()],[run(),changed]).verdict,'invalid');
});
