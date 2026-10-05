import {createHash,randomUUID} from 'node:crypto';
import {mkdir,writeFile} from 'node:fs/promises';
import {join,resolve} from 'node:path';
import {cpus,loadavg} from 'node:os';
import {openBrowser} from '../browser-session.js';
import {paintMeasurementInstrumentation} from '../paint-measurements.js';
import {presentationMeasurementInstrumentation} from '../presentation-measurements.js';
import {deterministicPaintSetupInstrumentation,deterministicSetupSnapshotExpression,
  deterministicFinalPaintSnapshotInstrumentation,disableOriginalAutomaticSlowdown} from '../deterministic-paint-setup.js';
import {getScenario} from './scenarios.js';
import {evaluationWindowVisibility} from './window-visibility.js';

export const editionAddresses=Object.freeze({
  '2010':Object.freeze({time:0x5359f0,dt:0x523378,speed:0x4da174,paused:0x536444,racing:0x5363b0,
    fleet:0x4da194,mode:0x4da16c,notice:0x53648c,divisor:0x4da178,difficulty:0x4da198,selector:0x4da144,length:0x4faa48,
    timeFactor:0x523d48,courseLength:0x525a9c,clock:0x4f8cd0,autoSlow:0x4da1dc,
    area:0x4da19c,venue:0x4da1f8,course:0x4da188,results:0x5363f4,leg:0x4da1cc,
    overlays:Object.freeze([0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c])}),
  '2002':Object.freeze({time:0x4ac1f8,dt:0x4aa948,speed:0x49116c,paused:0x4ac980,racing:0x4ac8f8,
    fleet:0x49118c,mode:0x491164,notice:0x4ac9cc,divisor:0x491170,difficulty:0x491190,selector:0x491144,length:0x4a5ba4,
    timeFactor:0x4ab0c0,courseLength:0x4ab184,clock:0x4a5b80,autoSlow:0x4911d0,
    area:0x491194,venue:null,course:0x491180,results:0x4ac93c,leg:0x4911c0,
    overlays:Object.freeze([0x4ac980,0x4ac938,0x4aa980,0x4ac970,0x4ac974])}),
});

const hostSample=()=>{
  const processors=cpus();
  return {logicalProcessors:processors.length,loadAverage:loadavg(),
    idle:processors.reduce((sum,cpu)=>sum+cpu.times.idle,0),
    total:processors.reduce((sum,cpu)=>sum+Object.values(cpu.times).reduce((a,b)=>a+b,0),0)};
};
const actualExpression=a=>`(()=>{const s=tact.state,m=s.memory,c=document.getElementById('race'),r=c.getBoundingClientRect();return {
  frame:s.frames,rngState:s.rng.state,error:s.error,errorStack:document.getElementById('error')?.textContent,
  speed:m.readI32(${a.speed}),dt:m.readF64(${a.dt}),autoSlow:m.readI32(${a.autoSlow}),
  time:m.readF64(${a.time}),clock:m.readI32(${a.clock}),racing:m.readI32(${a.racing}),mode:m.readI32(${a.mode}),
  fleet:m.readI32(${a.fleet}),boatSelector:m.readI32(${a.selector}),boatLength:m.readI32(${a.length}),
  area:m.readI32(${a.area}),venue:${a.venue===null?'null':`m.readI32(${a.venue})`},course:m.readI32(${a.course}),
  divisor:m.readI32(${a.divisor}),difficulty:m.readI32(${a.difficulty}),timeFactor:m.readF64(${a.timeFactor}),
  courseLength:m.readI32(${a.courseLength}),results:m.readI32(${a.results}),leg:m.readI32(${a.leg}),
  notice:m.readI32(${a.notice}),overlays:${JSON.stringify(a.overlays)}.map(address=>m.readI32(address)),
  canvas:{width:c.width,height:c.height,cssWidth:r.width,cssHeight:r.height},dimensions:tact.dimensions,
  visibility:document.visibilityState,graphics:new URLSearchParams(location.search).get('graphics')??'default'};})()`;

function measurementInjection(a){
  return deterministicPaintSetupInstrumentation()+`
    globalThis.evaluationSamples=[];globalThis.evaluationEndQueue=[];globalThis.evaluationErrors=[];
    globalThis.evaluationFinalReached=false;globalThis.evaluationMeasuring=false;
    globalThis.evaluationPresentationFinished=false;
    const originalGateAccept=paintSetupGate.accept;
    paintSetupGate.accept=callback=>{
      if(evaluationFinalReached)evaluationEndQueue.push(callback);else originalGateAccept(callback);
    };
    globalThis.releaseEvaluationEndFence=()=>{
      evaluationFinalReached=false;const queued=evaluationEndQueue.splice(0);
      for(const callback of queued)callback();
    };
    addEventListener('error',event=>evaluationErrors.push({kind:'error',message:event.message,stack:event.error?.stack}));
    addEventListener('unhandledrejection',event=>evaluationErrors.push({kind:'unhandledrejection',message:String(event.reason),stack:event.reason?.stack}));
  `+paintMeasurementInstrumentation(`
    const s=globalThis.tact?.state,m=s?.memory;
    const row={frame:s?.frames,start,duration:performance.now()-start,time:m?.readF64(${a.time}),dt:m?.readF64(${a.dt}),
      speed:m?.readI32(${a.speed}),autoSlow:m?.readI32(${a.autoSlow}),error:s?.error??null,
      clock:m?.readI32(${a.clock}),racing:m?.readI32(${a.racing}),results:m?.readI32(${a.results}),leg:m?.readI32(${a.leg}),
      visible:document.visibilityState!=='hidden'};
    if(evaluationMeasuring)evaluationSamples.push(row);
    if(s?.error)evaluationErrors.push({kind:'simulator',frame:s.frames,message:s.error});
    if(evaluationMeasuring&&(row.frame===paintMeasurementFinalFrame||row.error)){
      ${deterministicFinalPaintSnapshotInstrumentation(a)}
      globalThis.evaluationEndActual=${actualExpression(a)};
      evaluationMeasuring=false;evaluationFinalReached=true;
    }
  `,{setupGate:true})+presentationMeasurementInstrumentation(a.time)+`
    globalThis.startEvaluationWindow=lastFrame=>{
      paintMeasurementFinalFrame=lastFrame;paintMeasurementFinalSnapshot=null;
      evaluationMeasuring=true;evaluationPresentationFinished=false;
      startPresentationMeasurements();
      // The observer is registered first at every rAF, so the final completed
      // canvas frame is sampled before this fence stops both observation loops.
      const fence=()=>{
        if(evaluationFinalReached){stopPresentationMeasurements();evaluationPresentationFinished=true;return;}
        requestAnimationFrame(fence);
      };
      requestAnimationFrame(fence);
    };
  `;
}

async function stageTiming(browser,edition){
  return browser.evaluate(`(async()=>{
    const options=tact.state.options,player=document.querySelector('script[type="module"][src]').src;
    const {advanceFrame}=await import(new URL('./engine/frame.js',player));
    const {drawChart}=await import(new URL('./render/chart.js',player));
    const {drawSailingHud}=await import(new URL('./render/hud.js',player));
    globalThis.evaluationStages=[];
    const wrap=(name,original)=>function(...args){const start=performance.now();try{return original.apply(this,args);}
      finally{evaluationStages.push({name,frame:tact.state.frames+1,start,duration:performance.now()-start});}};
    const bindings={advanceFrame:options.advanceFrame??advanceFrame,drawScene:options.drawScene,
      drawChart:options.drawChart??drawChart,drawSailingHud:options.drawSailingHud??drawSailingHud};
    const engineChildren=${edition==='2010'}?['updateGlobalWind','respawnWindPatch','updateBoatWindAndAI',
      'updatePlayer1Steering','updatePlayer2Steering','updateBoatDynamics','integratePositions']:[];
    for(const name of engineChildren)if(typeof options[name]==='function')bindings[name]=options[name];
    const installed=[];
    for(const [name,original] of Object.entries(bindings))if(typeof original==='function'){
      options[name]=wrap(name,original);installed.push(name);
    }
    return {installed,scope:'Diagnostic option callbacks preserve receiver, arguments, returns and exceptions. Nested stage durations overlap. 2002 internal engine children have no option callback boundary; only aggregate advanceFrame is timed.'};
  })()`);
}

async function readModules(browser){
  const loaded=new Map(browser.events.filter(event=>event.method==='Network.responseReceived'&&
    /\.(?:js|mjs)(?:\?|$)/.test(event.params.response.url)).map(event=>[event.params.response.url,event.params.requestId]));
  const rows=[];
  for(const [url,requestId] of loaded){
    try{
      const {body,base64Encoded}=await browser.call('Network.getResponseBody',{requestId});
      const bytes=Buffer.from(body,base64Encoded?'base64':'utf8');
      rows.push({url,bytes:bytes.length,sha256:createHash('sha256').update(bytes).digest('hex')});
    }catch(error){rows.push({url,error:error.message});}
  }
  return rows;
}

/** Actual original commands and callbacks; never writes game memory or RNG. */
async function setUp(browser,a,scenario,warmup){
  const history=[];
  const live=()=>browser.evaluate(actualExpression(a));
  const healthy=async()=>{const state=await live();if(state.error)throw new Error(state.error);return state;};
  const held=async()=>{
    await browser.waitFor('paintSetupGate.queued===1||tact.state.error',60000);
    if(await browser.evaluate('paintSetupGate.queued!==1||!paintSetupGate.holding'))throw new Error('Setup lost the single original scheduled paint');
    return healthy();
  };
  const paint=async label=>{
    await held();await browser.evaluate(`paintSetupGate.step(${JSON.stringify(label)})`);
    const state=await healthy();history.push({kind:'paint',label,...state});return state;
  };
  const command=async id=>{
    const label=await browser.evaluate(`(()=>{const button=document.querySelector('[data-command="${id}"]');
      if(!button||button.disabled)throw new Error('Original menu${id} is unavailable');
      const label=button.textContent;button.click();return label;})()`);
    await browser.evaluate('tact.requestPaint()');
    const state=await healthy();history.push({kind:'command',id,label,...state});
    const speedCommands=new Map([[32872,1],[32909,10],[32973,15]]);
    if(speedCommands.has(id)&&state.speed!==speedCommands.get(id))throw new Error(`Original menu${id} did not select requested speed`);
    return state;
  };
  const space=async label=>{
    await browser.evaluate('document.getElementById("race").focus({preventScroll:true})');
    for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code:'Space',key:' ',windowsVirtualKeyCode:32});
    const state=await healthy();history.push({kind:'key',code:'Space',label,...state});return state;
  };
  let initial,entry,automaticSlowdown;
  try{
    await held();initial=await browser.evaluate(deterministicSetupSnapshotExpression(a));
    const initialSettings=await live();
    await paint('initial start screen');
    for(const id of scenario.commands){await command(id);await paint(`menu${id}`);}
    let state=await space('begin');
    if(state.racing===0&&state.mode>0&&state.notice===1)state=await space('acknowledge original demo notice');
    for(let attempts=0;state.racing!==2&&attempts<4;attempts++)state=await paint('initialize race');
    if(state.racing!==2)throw new Error('Original start handler did not initialize racing');
    for(let attempts=0;state.overlays.some(value=>value!==0)&&attempts<4;attempts++){
      await space('dismiss original overlay');state=await paint('unobstructed racing');
    }
    if(state.overlays.some(value=>value!==0))throw new Error('Original overlay remains active');
    if(scenario.settings.automaticSlowdown==='off'){
      automaticSlowdown=await disableOriginalAutomaticSlowdown(
        ()=>browser.evaluate(`tact.state.memory.readI32(${a.autoSlow})`),command,paint);
    }else automaticSlowdown={before:state.autoSlow,after:state.autoSlow,intervention:null};
    if(scenario.phase==='race'){
      state=await command(32973);
      for(let attempts=0;state.clock<scenario.clock&&attempts<2000;attempts++){
        if(state.speed!==15)throw new Error(`Original fast-forward changed speed to ${state.speed} at clock ${state.clock}`);
        state=await paint('original speed15 race advance');
      }
      if(state.clock<scenario.clock)throw new Error('Bounded original fast-forward did not reach requested race clock');
      await command(scenario.settings.speed===1?32872:32909);
    }
    await paint('settle requested speed through original integration');
    // Same callback bodies warm the JIT; the gate retains precise setup boundaries.
    for(let index=0;index<warmup;index++)await paint('warmup');
    await held();entry=await browser.evaluate(deterministicSetupSnapshotExpression(a));
    const actual=await live();
    const requested=scenario.settings;
    for(const key of ['fleet','boatSelector','area','venue','course','speed']){
      if(key==='speed'&&!scenario.controlled)continue;
      if(requested[key]!==undefined&&!(key==='venue'&&a.venue===null)&&actual[key]!==requested[key]){
        throw new Error(`Requested ${key}=${requested[key]}, observed ${actual[key]}`);
      }
    }
    if(!Number.isFinite(actual.dt)||actual.dt<=0||!Number.isInteger(actual.courseLength)||actual.courseLength<=0)throw new Error('Original timestep or course length is invalid');
    if(actual.visibility!=='visible'||actual.racing!==2||actual.overlays.some(value=>value!==0))throw new Error('Measurement requires visible unobstructed original racing');
    return {initial,initialSettings,entry,history,automaticSlowdown,actual,
      scope:'Original DOM menu handlers and trusted Space input between actual scheduled paint callbacks. Fixed Date.now seed before initialization; no game memory, RNG, timestep or finish-flag writes. Warmup uses the same original callbacks; measurement releases the natural scheduler.'};
  }catch(error){error.setup={initial,entry,history,automaticSlowdown};throw error;}
}

function validate(report){
  const failures=[];
  if(report.samples.length!==report.requested.frames)failures.push(`Expected ${report.requested.frames} paints; recorded ${report.samples.length}`);
  for(let index=0;index<report.samples.length;index++){
    const row=report.samples[index];
    if(row.error)failures.push(`Frame${row.frame}: ${row.error}`);
    if(row.frame!==report.setup.entry.frame+index+1)failures.push(`Nonconsecutive paint at sample${index}`);
    if(!row.visible)failures.push(`Frame${row.frame} ran while hidden`);
    if(report.scenario.controlled){
      for(const field of ['speed','dt','autoSlow'])if(!Object.is(row[field],report.expected[field]))failures.push(`Controlled ${field} drift at frame${row.frame}: ${row[field]}`);
    }
  }
  if(report.exceptions.length||report.observedErrors.length)failures.push('Browser or simulator reported an exception');
  if(report.moduleSources.some(row=>row.error))failures.push('One or more loaded module bodies could not be hashed');
  if(!report.end)failures.push('Exact final-paint snapshot is missing');
  return {passed:failures.length===0,failures};
}

/** A fresh headed, GPU-enabled browser per run. Profiled samples are diagnostic only. */
export async function runScenario({edition,scenario,frames=240,warmup=60,baseUrl,outputDir,profile=false,afterMeasurement,diagnostic,windowHeight=1051}={}){
  edition=String(edition);const a=editionAddresses[edition];
  scenario=typeof scenario==='string'?getScenario(scenario):scenario;
  if(!a||!scenario?.editions.includes(edition))throw new RangeError('Scenario does not support this edition');
  if(!Number.isSafeInteger(frames)||frames<1||!Number.isSafeInteger(warmup)||warmup<0)throw new RangeError('Invalid evaluation frame counts');
  if(diagnostic&&(!diagnostic.label||typeof diagnostic.script!=='string'))throw new TypeError('Diagnostic needs a label and a startup script');
  const supplied=new URL(baseUrl??'http://127.0.0.1:8765/');
  const playerPath=edition==='2010'?'/versions/2010-en/play.html':'/play.html';
  const playerUrl=supplied.pathname.endsWith('.html')?supplied:new URL(playerPath,supplied);
  if(!supplied.pathname.endsWith('.html'))playerUrl.search=supplied.search;
  const url=playerUrl.href;
  const destination=resolve(outputDir??'analysis/evaluation');await mkdir(destination,{recursive:true});
  const id=`${edition}-${scenario.id}-${profile?'profile':'timing'}-${randomUUID()}`;
  const report={format:1,id,edition,scenario,url,checkedAt:new Date().toISOString(),
    requested:{frames,warmup,settings:scenario.settings},samples:[],presentation:[],moduleSources:[],exceptions:[],observedErrors:[],
    metadata:{headless:false,gpu:true,width:1280,height:windowHeight,seedTimeSeconds:1546300800,
      timingScope:profile||diagnostic?'CPU/stage-profile or Canvas diagnostic; these timings are ineligible for performance acceptance':'Headed GPU-enabled continuous original scheduler, without CPU/stage profiling',
      presentationScope:'requestAnimationFrame samples are a canvas-content availability proxy, not proof of physical display presentation',
      comparisonScope:scenario.comparisonScope??'Native edition defaults/features are retained; cross-edition full-state equality is not assumed'},
    validation:{passed:false,failures:[]}};
  if(diagnostic)report.diagnostic={label:diagnostic.label,scriptSha256:createHash('sha256').update(diagnostic.script).digest('hex')};
  let browser,profiling=false,hostBefore,hostAfter,runError;
  try{
    // Install the fixed initialization seed/gate before the game is loaded once.
    browser=await openBrowser('about:blank',{headless:false,gpu:true,width:1280,height:windowHeight});
    report.metadata.launch=browser.metadata;
    if(browser.metadata?.window?.bounds?.width!==1280||browser.metadata?.window?.bounds?.height!==windowHeight)throw new Error('Requested real browser window bounds were not retained');
    await browser.call('Network.enable',{maxTotalBufferSize:100_000_000,maxResourceBufferSize:30_000_000});
    await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});
    await browser.call('Page.addScriptToEvaluateOnNewDocument',{source:measurementInjection(a)});
    if(diagnostic)await browser.call('Page.addScriptToEvaluateOnNewDocument',{source:diagnostic.script});
    await browser.call('Page.navigate',{url});
    await browser.call('Page.bringToFront');
    report.metadata.compositorBefore=await evaluationWindowVisibility(browser.metadata,{focus:true});
    await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);
    if(await browser.evaluate('tact.state.error'))throw new Error(await browser.evaluate('tact.state.error'));
    report.setup=await setUp(browser,a,scenario,warmup);
    report.actual=report.setup.actual;
    report.expected={frames,speed:scenario.settings.speed,dt:report.actual.dt,autoSlow:scenario.controlled?0:undefined};
    report.metadata.launch=browser.metadata;
    const features=browser.metadata?.systemInfo?.gpu?.featureStatus;
    const requiredGpuFeatures=['2d_canvas','gpu_compositing','rasterization'];
    report.metadata.gpuValidation={passed:requiredGpuFeatures.every(key=>/^enabled(?:_|$)/.test(features?.[key]??'')),
      required:requiredGpuFeatures,actual:features??null};
    if(!report.metadata.gpuValidation.passed)throw new Error('Required Canvas, compositing and rasterization GPU features are not enabled');
    report.metadata.layoutViewportOverride={width:1280,height:1050,deviceScaleFactor:1,mobile:false};
    report.metadata.environment=await browser.evaluate(`({userAgent:navigator.userAgent,devicePixelRatio,
      viewport:{width:innerWidth,height:innerHeight,outerWidth,outerHeight},screen:{width:screen.width,height:screen.height},
      graphics:new URLSearchParams(location.search).get('graphics')??'default'})`);
    if(report.metadata.environment.viewport.width!==1280||report.metadata.environment.viewport.height!==1050)throw new Error('Requested layout viewport was not retained');
    if(profile){
      report.profile={stageCoverage:await stageTiming(browser,edition)};
      await browser.call('Profiler.enable');await browser.call('Profiler.setSamplingInterval',{interval:1000});
      await browser.call('Profiler.start');profiling=true;
    }
    await browser.evaluate(`startEvaluationWindow(${report.setup.entry.frame+frames})`);
    hostBefore=hostSample();
    await browser.evaluate('paintSetupGate.release()');
    await browser.waitFor(diagnostic?'evaluationFinalReached||tact.state.error':'evaluationPresentationFinished||tact.state.error',Math.max(180000,frames*200));
    if(diagnostic)report.diagnostic.presentationFence='Paint completion only. Partial animation-frame observations do not establish content cadence.';
    hostAfter=hostSample();
    report.metadata.compositorAfter=await evaluationWindowVisibility(browser.metadata);
    if(profiling){
      const result=await browser.call('Profiler.stop');profiling=false;
      report.profile.path=join(destination,`${id}.cpuprofile`);
      await writeFile(report.profile.path,JSON.stringify(result.profile));
      report.profile.stages=await browser.evaluate('evaluationStages');
    }
    report.presentation=await browser.evaluate('presentationMeasurements');
    report.samples=await browser.evaluate('evaluationSamples');
    report.end=await browser.evaluate('paintMeasurementFinalSnapshot');
    report.endActual=await browser.evaluate('evaluationEndActual');
    report.observedErrors=await browser.evaluate('evaluationErrors');
    if(diagnostic)report.diagnostic.observations=await browser.evaluate('globalThis.canvasDiagnostics');
    report.exceptions=browser.events.filter(event=>event.method==='Runtime.exceptionThrown').map(event=>event.params.exceptionDetails);
    report.moduleSources=await readModules(browser);
    report.host={logicalProcessors:hostBefore.logicalProcessors,loadAverageBefore:hostBefore.loadAverage,loadAverageAfter:hostAfter.loadAverage,
      cpuBusyFraction:1-(hostAfter.idle-hostBefore.idle)/(hostAfter.total-hostBefore.total)};
    report.milestones={startingGun:report.setup.entry.clock>=0||report.samples.some(row=>row.clock>=0),
      raceLeg:report.setup.actual.leg>0||report.samples.some(row=>row.leg>0),
      resultsObserved:report.samples.some(row=>row.results>0),
      scope:'Read-only native clock, race stage and results observations; a bounded run without results is not a full-race proof'};
    report.validation=validate(report);
    if(!report.validation.passed)throw new Error(report.validation.failures.join('; '));
    if(afterMeasurement&&!profile){
      // Performance data and final image are already fixed; restore natural paints for input probes.
      await browser.evaluate('releaseEvaluationEndFence()');
      report.inputLatency=await afterMeasurement(browser,{edition,addresses:a,scenario});
      report.metadata.compositorAfterInput=await evaluationWindowVisibility(browser.metadata);
    }
  }catch(error){
    runError=error;report.failure={message:error.message,stack:error.stack};
    if(error.browserMetadata)report.metadata.launch=error.browserMetadata;
    report.setup??=error.setup;
    report.validation={passed:false,failures:[...report.validation.failures,error.message]};
    if(browser){
      for(const [key,expression] of [['samples','evaluationSamples'],['presentation','presentationMeasurements'],['observedErrors','evaluationErrors']]){
        try{report[key]=await browser.evaluate(expression)??report[key];}catch{}
      }
      try{report.failure.actual=await browser.evaluate(actualExpression(a));}catch{}
      try{
        const screenshot=await browser.call('Page.captureScreenshot',{format:'png'});
        report.failure.screenshotPath=join(destination,`${id}-failure.png`);
        await writeFile(report.failure.screenshotPath,Buffer.from(screenshot.data,'base64'));
      }catch(screenshotError){report.failure.screenshotError=screenshotError.message;}
      report.exceptions=browser.events.filter(event=>event.method==='Runtime.exceptionThrown').map(event=>event.params.exceptionDetails);
      if(!report.moduleSources.length)try{report.moduleSources=await readModules(browser);}catch{}
    }
  }finally{
    if(profiling&&browser)try{await browser.call('Profiler.stop');}catch{}
    if(browser)await browser.close();
    report.reportPath=join(destination,`${id}.json`);
    await writeFile(report.reportPath,JSON.stringify(report,null,2)+'\n');
  }
  if(runError){Object.defineProperty(runError,'report',{value:report});throw runError;}
  return report;
}
