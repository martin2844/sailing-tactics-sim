import { createHash } from 'node:crypto';
import { writeFile } from 'node:fs/promises';
import { setTimeout as pause } from 'node:timers/promises';
import { cpus,loadavg } from 'node:os';
import { openBrowser } from '../browser-session.js';
import { paintMeasurementInstrumentation } from '../paint-measurements.js';

const edition=process.env.TACT_PACE_EDITION??'2010';
if(!['2002','2010'].includes(edition))throw new Error('Unknown pace edition');
const url=process.env.TACT_2010_URL??(edition==='2010'?'http://127.0.0.1:8765/versions/2010-en/play.html':'http://127.0.0.1:8765/play.html');
const addresses=edition==='2010'?{time:0x5359f0,dt:0x523378,speed:0x4da174,paused:0x536444,racing:0x5363b0,
  fleet:0x4da194,mode:0x4da16c,notice:0x53648c,divisor:0x4da178,difficulty:0x4da198,selector:0x4da144,length:0x4faa48,
  timeFactor:0x523d48,courseLength:0x525a9c,dtScaleNormal:0x4cc5a8,dtScaleShort:0x4ccaf0,dtScalePractice:0x4cc5d0,clock:0x4f8cd0,
  overlays:[0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c]}:{time:0x4ac1f8,dt:0x4aa948,speed:0x49116c,paused:0x4ac980,racing:0x4ac8f8,
  fleet:0x49118c,mode:0x491164,notice:0x4ac9cc,divisor:0x491170,difficulty:0x491190,selector:0x491144,length:0x4a5ba4,
  timeFactor:0x4ab0c0,courseLength:0x4ab184,dtScaleNormal:0x484d88,dtScaleShort:0x484d88,dtScalePractice:0x484d88,clock:0x4a5b80,
  overlays:[0x4ac980,0x4ac938,0x4aa980,0x4ac970,0x4ac974]};
const frames=Number(process.env.TACT_PACE_FRAMES??120);
const fleet=Number(process.env.TACT_PACE_FLEET??20);
const defaultSetup=process.env.TACT_PACE_DEFAULT==='1';
const afterFastForward=process.env.TACT_PACE_STARTED==='1';
const fastForwardClock=Number(process.env.TACT_PACE_CLOCK??100);
const label=process.argv[2]??'speed-ten-current';
const fleets=new Map([[2,32805],[5,32806],[10,32807],[15,32808],[20,32809],[25,32810],[30,32811]]);
if(!fleets.has(fleet)||!Number.isSafeInteger(frames)||frames<20||!Number.isSafeInteger(fastForwardClock)||fastForwardClock<0||!/^[-a-z0-9]+$/.test(label))throw new Error('Invalid pace setup');
const browser=await openBrowser(url);
const hostSample=()=>{
  const processors=cpus();
  return {logicalProcessors:processors.length,loadAverage:loadavg(),
    idle:processors.reduce((sum,cpu)=>sum+cpu.times.idle,0),
    total:processors.reduce((sum,cpu)=>sum+Object.values(cpu.times).reduce((a,b)=>a+b,0),0)};
};
try{
  await browser.call('Page.addScriptToEvaluateOnNewDocument',{source:paintMeasurementInstrumentation(`
        const memory=globalThis.tact?.state.memory;
        paintMeasurements.push({start,duration:performance.now()-start,frame:globalThis.tact?.state.frames,
          time:memory?.readF64(${addresses.time}),dt:memory?.readF64(${addresses.dt}),speed:memory?.readI32(${addresses.speed}),
          paused:memory?.readI32(${addresses.paused}),racing:memory?.readI32(${addresses.racing})===2,error:globalThis.tact?.state.error});
  `)});
  await browser.call('Page.reload');
  await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);
  await browser.waitFor('tact.state.frames>0||tact.state.error',60000);
  const healthy=async()=>{const error=await browser.evaluate('tact.state.error');if(error)throw new Error(error);};
  const key=async(code,key,keyCode)=>{
    await browser.evaluate('document.getElementById("race").focus()');
    await browser.call('Input.dispatchKeyEvent',{type:'keyDown',code,key,windowsVirtualKeyCode:keyCode});
    await browser.call('Input.dispatchKeyEvent',{type:'keyUp',code,key,windowsVirtualKeyCode:keyCode});
  };
  for(const command of defaultSetup?[32909]:[32799,32816,32789,fleets.get(fleet),32909]){
    await browser.evaluate(`tact.command(${command})`);
    await browser.evaluate('tact.requestPaint()');await pause(150);await healthy();
  }
  await key('Space',' ',32);
  if(await browser.evaluate(`tact.state.memory.readI32(${addresses.racing})===0&&tact.state.memory.readI32(${addresses.mode})>0&&tact.state.memory.readI32(${addresses.notice})===1`))await key('Space',' ',32);
  await browser.waitFor(`tact.state.memory.readI32(${addresses.racing})===2||tact.state.error`,60000);
  if(await browser.evaluate(`${JSON.stringify(addresses.overlays)}.some(a=>tact.state.memory.readI32(a)!==0)`))await key('Space',' ',32);
  await healthy();
  if(afterFastForward){
    await browser.evaluate('tact.command(32973)');
    await browser.waitFor(`tact.state.memory.readI32(${addresses.clock})>=${fastForwardClock}||tact.state.error`,180000);
    await healthy();
    await browser.evaluate('tact.command(32909)');
  }
  const first=await browser.evaluate('tact.state.frames');
  const hostBefore=hostSample();
  await browser.waitFor(`tact.state.frames>=${first+frames}||tact.state.error`,180000);
  const hostAfter=hostSample();
  const paints=await browser.evaluate(`paintMeasurements.filter(row=>row.racing&&row.frame>${first}).slice(0,${frames})`);
  const live=await browser.evaluate(`({frames:tact.state.frames,mode:tact.state.memory.readI32(${addresses.mode}),
    fleet:tact.state.memory.readI32(${addresses.fleet}),speed:tact.state.memory.readI32(${addresses.speed}),
    divisor:tact.state.memory.readI32(${addresses.divisor}),difficulty:tact.state.memory.readI32(${addresses.difficulty}),
    selector:tact.state.memory.readI32(${addresses.selector}),length:tact.state.memory.readI32(${addresses.length}),
    timeFactor:tact.state.memory.readF64(${addresses.timeFactor}),courseLength:tact.state.memory.readI32(${addresses.courseLength}),
    dtScaleNormal:tact.state.memory.readF64(${addresses.dtScaleNormal}),dtScaleShort:tact.state.memory.readF64(${addresses.dtScaleShort}),
    dtScalePractice:tact.state.memory.readF64(${addresses.dtScalePractice}),dt:tact.state.memory.readF64(${addresses.dt}),
    simulationTime:tact.state.memory.readF64(${addresses.time}),clock:tact.state.memory.readI32(${addresses.clock}),
    error:tact.state.error,errorStack:document.getElementById('error').textContent})`);
  const moduleSources=[];
  const loaded=new Map(browser.events.filter(event=>event.method==='Network.responseReceived'&&/\.js(?:\?|$)/.test(event.params.response.url)).map(event=>[event.params.response.url,event.params.requestId]));
  for(const [moduleUrl,requestId] of loaded){
    const {body,base64Encoded}=await browser.call('Network.getResponseBody',{requestId});
    const bytes=Buffer.from(body,base64Encoded?'base64':'utf8');
    moduleSources.push({url:moduleUrl,bytes:bytes.length,sha256:createHash('sha256').update(bytes).digest('hex')});
  }
  const firstPaint=paints[0],lastPaint=paints.at(-1);
  const wallSeconds=paints.length>1?(lastPaint.start-firstPaint.start)/1000:0;
  const simulationSeconds=paints.length>1?lastPaint.time-firstPaint.time:0;
  const sorted=paints.map(row=>row.duration).sort((a,b)=>a-b);
  const report={format:1,label,url,edition,checkedAt:new Date().toISOString(),seedTimeSeconds:1546300800,
    scope:`Headless Chrome, ${defaultSetup?'unchanged original default boat/venue/fleet and original speed10 menu':`original Round Lake/Keelboat/Windward/${fleet}-boat/speed10 menus`}; ${frames} requested genuine continuous paints.${afterFastForward?` Original speed15 menu first advances the actual simulation past ${fastForwardClock} seconds, then the original speed10 handler selects the measured pace.`:''} Actual physics and drawing; no profiler overhead.`,
    live,host:{logicalProcessors:hostBefore.logicalProcessors,loadAverageBefore:hostBefore.loadAverage,
      loadAverageAfter:hostAfter.loadAverage,
      cpuBusyFraction:1-(hostAfter.idle-hostBefore.idle)/(hostAfter.total-hostBefore.total)},
    requestedFrames:frames,observedFrames:paints.length,wallSeconds,simulationSeconds,
    simulationSecondsPerWallSecond:wallSeconds?simulationSeconds/wallSeconds:null,
    framesPerSecond:wallSeconds?(paints.length-1)/wallSeconds:null,
    paintDuration:{meanMs:sorted.reduce((a,b)=>a+b,0)/sorted.length,medianMs:sorted[Math.floor(sorted.length/2)],maxMs:sorted.at(-1)},
    paints,moduleSources,exceptions:browser.events.filter(event=>event.method==='Runtime.exceptionThrown').map(event=>event.params.exceptionDetails)};
  await writeFile(new URL(`../../versions/2010-en/analysis/browser-performance/${label}.json`,import.meta.url),JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({...report,moduleSources:moduleSources.length,paints:paints.length,exceptions:report.exceptions.length}));
  if(live.error||report.exceptions.length||paints.length!==frames){
    console.error(`Incomplete or failed pace run: ${paints.length}/${frames} paints, ${report.exceptions.length} browser exceptions.`);
    process.exitCode=1;
  }
}catch(error){
  const failureState=await browser.evaluate(`(()=>{const s=globalThis.tact?.state,m=s?.memory;return {
    frames:s?.frames,pending:s?.pending,nextPaint:s?.nextPaint,modal:s?.modal,error:s?.error,
    clock:m?.readI32(${addresses.clock}),time:m?.readF64(${addresses.time}),
    speed:m?.readI32(${addresses.speed}),racing:m?.readI32(${addresses.racing}),
    overlays:${JSON.stringify(addresses.overlays)}.map(a=>({address:a,value:m?.readI32(a)}))};})()`)
    .catch(problem=>({inspectionError:String(problem)}));
  console.error(JSON.stringify({label,failure:String(error),failureState}));
  throw error;
}finally{await browser.close();}
