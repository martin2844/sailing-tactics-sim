import { writeFile,mkdir } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { setTimeout as pause } from 'node:timers/promises';
import { openBrowser } from './browser-session.js';
import { paintMeasurementInstrumentation } from './paint-measurements.js';
import { installProjectionOutputDiagnostics } from './projection-output-diagnostics.js';

const url=process.env.TACT_2010_URL??'http://127.0.0.1:8765/versions/2010-en/play.html';
const label=process.argv[2]??'current';
if(!/^[a-z0-9-]+$/.test(label))throw new Error('Profile label must be a simple filename');
const fleet=Number(process.env.TACT_PROFILE_FLEET??20);
const warmup=Number(process.env.TACT_PROFILE_WARMUP??0);
const measuredFrames=Number(process.env.TACT_PROFILE_FRAMES??20);
const speedTen=process.env.TACT_PROFILE_SPEED_TEN==='1';
const defaultSetup=process.env.TACT_PROFILE_DEFAULT==='1';
const started=process.env.TACT_PROFILE_STARTED==='1';
const fastForwardClock=Number(process.env.TACT_PROFILE_CLOCK??100);
const instrumentProjection=process.env.TACT_PROFILE_PROJECTION==='1';
if(!Number.isSafeInteger(warmup)||warmup<0||!Number.isSafeInteger(measuredFrames)||measuredFrames<20||!Number.isSafeInteger(fastForwardClock)||fastForwardClock<0)throw new Error('Invalid profile frame counts or clock');
const fleetCommands=new Map([[2,32805],[5,32806],[10,32807],[15,32808],[20,32809],[25,32810],[30,32811]]);
if(!fleetCommands.has(fleet))throw new Error('Profile fleet must be an original menu choice');
const output=new URL('../versions/2010-en/analysis/browser-performance/',import.meta.url);
await mkdir(output,{recursive:true});
const browser=await openBrowser(url);
let report;
let projectionDiagnostics;
try{
  if(instrumentProjection)projectionDiagnostics=await installProjectionOutputDiagnostics(browser);
  await browser.call('Page.addScriptToEvaluateOnNewDocument',{source:paintMeasurementInstrumentation(`
        paintMeasurements.push({start,duration:performance.now()-start,frame:globalThis.tact?.state.frames,
          racing:globalThis.tact?.state.memory?.readI32(0x5363b0)===2});
  `)});
  await browser.call('Page.reload');
  await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);
  await browser.waitFor('tact.state.frames>0||tact.state.error',60000);
  const healthy=async()=>{const error=await browser.evaluate('tact.state.error');if(error)throw new Error(error);};
  await healthy();
  const key=async(code,key,keyCode)=>{
    await browser.evaluate('document.getElementById("race").focus()');
    await browser.call('Input.dispatchKeyEvent',{type:'keyDown',code,key,windowsVirtualKeyCode:keyCode});
    await browser.call('Input.dispatchKeyEvent',{type:'keyUp',code,key,windowsVirtualKeyCode:keyCode});
  };
  // Real setup commands; exact original scene and physics remain enabled.
  for(const command of [...(defaultSetup?[]:[32799,32816,32789,fleetCommands.get(fleet)]),...(speedTen?[32909]:[])]){
    await browser.evaluate(`tact.command(${command})`);
    await browser.evaluate('tact.requestPaint()');
    await pause(150);await healthy();
  }
  await key('Space',' ',32);
  await browser.waitFor('tact.state.memory.readI32(0x5363b0)===2||tact.state.error',60000);
  const overlay=await browser.evaluate(`[0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c].some(a=>tact.state.memory.readI32(a)!==0)`);
  if(overlay)await key('Space',' ',32);
  await healthy();
  if(started){
    await browser.evaluate('tact.command(32973)');
    await browser.waitFor(`tact.state.memory.readI32(0x4f8cd0)>=${fastForwardClock}||tact.state.error`,180000);
    await healthy();
    await browser.evaluate('tact.command(32909)');
  }
  if(warmup){
    const start=await browser.evaluate('tact.state.frames');
    await browser.waitFor(`tact.state.frames>=${start+warmup}||tact.state.error`,180000);
    await healthy();
  }
  if(projectionDiagnostics)await projectionDiagnostics.reset();
  await browser.call('Profiler.enable');await browser.call('Profiler.setSamplingInterval',{interval:1000});
  await browser.call('Profiler.start');
  const first=await browser.evaluate('tact.state.frames');
  await browser.waitFor(`tact.state.frames>=${first+measuredFrames}||tact.state.error`,180000);
  await healthy();
  const {profile}=await browser.call('Profiler.stop');
  const projectionOutputDiagnostics=projectionDiagnostics?await projectionDiagnostics.read():undefined;
  await writeFile(new URL(`${label}.cpuprofile`,output),JSON.stringify(profile));
  const paints=await browser.evaluate(`paintMeasurements.filter(row=>row.racing&&row.frame>${first}).slice(0,${measuredFrames})`);
  const inputTimes=[];
  for(let n=0;n<5;n++){
    const start=performance.now();await key('KeyF','f',70);inputTimes.push(performance.now()-start);
    await pause(100);
  }
  const summarize=values=>{const sorted=values.toSorted((a,b)=>a-b);return {samples:values.length,
    meanMs:values.reduce((a,b)=>a+b,0)/values.length,medianMs:sorted[Math.floor(sorted.length/2)],maxMs:sorted.at(-1)};};
  const interval=paints.slice(1).map((row,index)=>row.start-paints[index].start);
  const live=await browser.evaluate(`({frames:tact.state.frames,mode:tact.state.memory.readI32(0x4da16c),
    fleet:tact.state.memory.readI32(0x4da194),selector:tact.state.memory.readI32(0x4da144),
    simulationTime:tact.state.memory.readF64(0x5359f0),error:tact.state.error})`);
  const source=await browser.evaluate(`Promise.all([...document.querySelectorAll('script[type="module"][src]')].map(async element=>{
    const response=await fetch(element.src);const bytes=await response.arrayBuffer();
    const hash=await crypto.subtle.digest('SHA-256',bytes);return{url:element.src,sha256:[...new Uint8Array(hash)].map(v=>v.toString(16).padStart(2,'0')).join('')};}))`);
  const loadedModules=new Map();
  for(const event of browser.events){
    if(event.method==='Network.responseReceived'&&/\.js(?:\?|$)/.test(event.params.response.url))
      loadedModules.set(event.params.response.url,event.params.requestId);
  }
  const moduleSources=[];
  for(const [moduleUrl,requestId] of loadedModules){
    const {body,base64Encoded}=await browser.call('Network.getResponseBody',{requestId});
    const bytes=Buffer.from(body,base64Encoded?'base64':'utf8');
    moduleSources.push({url:moduleUrl,bytes:bytes.length,sha256:createHash('sha256').update(bytes).digest('hex')});
  }
  if(live.mode!==0||live.fleet!==fleet||live.selector!==12||live.error)throw new Error('Benchmark did not retain the full original Keelboat setup');
  report={format:1,label,url,checkedAt:new Date().toISOString(),seedTimeSeconds:1546300800,
    scope:`Headless Chrome, ${defaultSetup?'unchanged original default setup':`original Round Lake/Keelboat/Windward course/${fleet}-boat menus`}${speedTen?', original speed10 menu':''}, ${warmup} warmup frames and ${measuredFrames} genuine continuous profiled paints.${started?` Original speed15 advances the actual simulation past ${fastForwardClock} seconds before the measured original speed10 segment.`:''} Timing includes actual drawing and physics. No scene/physics reductions.`,
    live,source,moduleSources,projectionOutputDiagnostics,paintDuration:summarize(paints.map(row=>row.duration)),paintInterval:summarize(interval),
    framesPerSecond:1000/(interval.reduce((a,b)=>a+b,0)/interval.length),physicalKeyDispatch:summarize(inputTimes),paints,
    exceptions:browser.events.filter(row=>row.method==='Runtime.exceptionThrown').map(row=>row.params.exceptionDetails)};
  await writeFile(new URL(`${label}.json`,output),JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({label,...report.paintDuration,framesPerSecond:report.framesPerSecond,mode:live.mode}));
}finally{try{await projectionDiagnostics?.close();}finally{await browser.close();}}
