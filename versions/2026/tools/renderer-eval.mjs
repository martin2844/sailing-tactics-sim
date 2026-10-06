import {mkdir,writeFile,readFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {setTimeout as pause} from 'node:timers/promises';
import{execFile}from'node:child_process';import{promisify}from'node:util';const executeFile=promisify(execFile);
async function focus(b){await b.call('Page.bringToFront');if(process.env.HYPRLAND_INSTANCE_SIGNATURE){const clients=JSON.parse((await executeFile('hyprctl',['-j','clients'])).stdout),pids=new Set([b.metadata.processId,b.metadata.browserProcessId]),owned=clients.filter(c=>pids.has(c.pid)&&c.mapped!==false);if(owned.length!==1||!/^0x[0-9a-f]+$/i.test(owned[0].address))throw Error('Owned renderer window not uniquely identified');const address=owned[0].address,expression='hl.dsp.focus({window="address:'+address+'"})';const result=await executeFile('hyprctl',['dispatch',expression]);if(result.stdout.trim()!=='ok')throw Error('Owned compositor focus failed: '+result.stdout);const active=JSON.parse((await executeFile('hyprctl',['-j','activewindow'])).stdout);if(active.address!==address)throw Error('Owned renderer window is not active');}}

import {openBrowser} from '../../../tools/browser-session.js';
const out=resolve(process.argv[2]??'');if(process.argv.length<3)throw new Error('Usage: renderer-eval.mjs NEW_DIRECTORY [REPEATS=5]');await mkdir(out);
const repetitions=Number(process.argv[3]??5),runs=[];
const acceptance=JSON.parse(await readFile(new URL('../config/acceptance.json',import.meta.url),'utf8')).desktop;
const percentile=(a,p)=>{const sorted=a.filter(v=>Number.isFinite(v)).sort((a,b)=>a-b);return sorted.length?sorted[Math.min(sorted.length-1,Math.floor(sorted.length*p))]:null;};
function stats(a){return{samples:a.length,median:percentile(a,.5),p95:percentile(a,.95),p99:percentile(a,.99),max:a.length?Math.max(...a):null};}
async function sizedBrowser(url,backend,repetition){
 if(!process.env.HYPRLAND_INSTANCE_SIGNATURE)return openBrowser(url,{headless:false,gpu:true,width:1280,height:1051,requestTimeoutMs:60000});
 // Fractional/off-screen origins can produce an outward-rounded extra pixel.
 // Position only our window at integer coordinates and require settled bounds.
 const b=await openBrowser(url,{headless:false,gpu:true,width:1280,height:1051,ensureWindowSize:false,requestTimeoutMs:60000});
 const sizing=b.metadata.windowSizing={requested:{width:1280,height:1051},before:b.metadata.window?.bounds,actions:[],status:'pending',compositor:'Hyprland',syntax:'lua'};
 try{
  if(!b.metadata.window?.windowId)throw Error('Chrome owned window ID unavailable');
  const info=await b.browserCall('SystemInfo.getProcessInfo'),pid=info.processInfo.find(p=>p.type==='browser')?.id;
  if(!Number.isSafeInteger(pid)||pid<=0)throw Error('Browser PID unavailable for owned sizing');b.metadata.browserProcessId=pid;
  const own=async()=>{const clients=JSON.parse((await executeFile('hyprctl',['-j','clients'],{timeout:2000})).stdout),found=clients.filter(c=>[pid,b.metadata.processId].includes(c.pid)&&c.mapped!==false);if(found.length!==1||!/^0x[0-9a-f]+$/i.test(found[0].address))throw Error('Owned Chrome window ambiguous');return found[0];};
  const initial=await own(),address=initial.address;
  const monitors=JSON.parse((await executeFile('hyprctl',['-j','monitors'],{timeout:2000})).stdout),monitor=monitors.find(m=>m.id===initial.monitor);
  if(!monitor||monitor.width/monitor.scale<1280||monitor.height/monitor.scale<1051)throw Error('Owned monitor cannot fit reference window');
  const x=Math.trunc(monitor.x+(monitor.width/monitor.scale-1280)/2),y=Math.trunc(monitor.y+(monitor.height/monitor.scale-1051)/2);
  const dispatch=async(operation)=>{if((await own()).address!==address)throw Error('Owned window changed during sizing');const expression=`hl.dsp.window.${operation.slice(0,-2)},window="address:${address}"})`;const result=await executeFile('hyprctl',['dispatch',expression],{timeout:2000});if(result.stdout.trim()!=='ok')throw Error('Owned sizing failed: '+result.stdout);sizing.actions.push({expression,address,processId:pid});};
  await dispatch('float({action="set"})');await dispatch('fullscreen_state({action="set",internal=0,client=0})');
  await dispatch(`resize({x=1280,y=1051,relative=false})`);await dispatch(`move({x=${x},y=${y},relative=false})`);
  await pause(500);
  let matched=0;
  for(let attempt=0;attempt<12;attempt++){
   const {bounds}=await b.browserCall('Browser.getWindowBounds',{windowId:b.metadata.window.windowId});sizing.after=bounds;b.metadata.window.bounds=bounds;
   if(bounds.width===1280&&bounds.height===1051){if(++matched===2){const client=await own();if(client.at[0]<monitor.x||client.at[1]<monitor.y||client.at[0]+client.size[0]>monitor.x+monitor.width/monitor.scale||client.at[1]+client.size[1]>monitor.y+monitor.height/monitor.scale)throw Error('Owned reference window outside monitor');sizing.ownedClient={address,pid,at:client.at,size:client.size,monitor:client.monitor};sizing.status='matched';b.metadata.viewport=await b.evaluate('({width:innerWidth,height:innerHeight,outerWidth,outerHeight,devicePixelRatio,visibilityState:document.visibilityState,focused:document.hasFocus()})');return b;}}
   else{
    matched=0;const client=await own(),width=Math.round(client.size[0]+1280-bounds.width),height=Math.round(client.size[1]+1051-bounds.height);
    if(width<1||height<1||width>16384||height>16384)throw Error('Owned size correction outside bounds');
    await dispatch(`resize({x=${width},y=${height},relative=false})`);
    await dispatch(`move({x=${x},y=${y},relative=false})`);
   }
   await pause(500);
  }
  throw Error('Owned Chrome did not settle at 1280x1051: '+JSON.stringify(sizing.after));
 }catch(error){sizing.status='failed';await writeFile(resolve(out,`${backend}-${repetition}-startup.json`),JSON.stringify({scope:'Failed before measurement; own browser cleaned',message:error.message,browser:b.metadata},null,2));await b.close();throw error;}
}
async function click(b,id){const p=await b.evaluate(`(()=>{const r=document.getElementById(${JSON.stringify(id)}).getBoundingClientRect();return {x:r.x+r.width/2,y:r.y+r.height/2};})()`);await b.call('Input.dispatchMouseEvent',{type:'mouseMoved',...p});await b.call('Input.dispatchMouseEvent',{type:'mousePressed',button:'left',clickCount:1,...p});await b.call('Input.dispatchMouseEvent',{type:'mouseReleased',button:'left',clickCount:1,...p});}
try{
 for(const backend of(process.env.TACT_RENDERER_BACKENDS?process.env.TACT_RENDERER_BACKENDS.split(','):['webgl2','webgpu']))for(let repetition=0;repetition<repetitions;repetition++){
  const b=await sizedBrowser(`http://127.0.0.1:8770/${process.env.TACT_RENDERER_STARTER==='1'?'':'spike/'}?fleet=15&backend=${backend}`,backend,repetition);
  try{
   await b.call('Page.addScriptToEvaluateOnNewDocument',{source:"globalThis.visibilityLog=[];document.addEventListener('visibilitychange',()=>visibilityLog.push({state:document.visibilityState,time:performance.now()}));"});await b.call('Page.reload');
   await b.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});
   await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);const err=await b.evaluate('tact2026.error');if(err)throw new Error(err);
   if(process.env.TACT_RENDERER_STARTER==='1'){await click(b,'start-race');await b.waitFor('!tact2026.paused&&document.getElementById("starter").hidden',10000);}
   if(process.env.TACT_RENDERER_ISLAND==='1'){
    await b.evaluate('document.getElementById("race-area").value="32801";document.getElementById("race-boat").value="1";document.getElementById("race-course").value="3";document.getElementById("race-wind").dispatchEvent(new Event("change"))');
    await b.waitFor('tact2026.ready&&tact2026.latest.configuration.selector===1||tact2026.error',60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));
    await b.evaluate('(()=>{for(let n=0;n<6;n++)tact2026.engine.send("key",33);tact2026.engine.send("pause",true);return tact2026.engine.request("boundary")})()');
   }
   await focus(b);
   await b.evaluate('document.title="Tact automated evaluation · temporary 15-boat window";document.getElementById("fleet").disabled=true;document.getElementById("restart").disabled=true;');
   await b.evaluate('globalThis.benchmarkBlockedKeys=0;document.addEventListener("keydown",event=>{benchmarkBlockedKeys++;event.preventDefault();event.stopImmediatePropagation();},true);');
   let raceWarmup;
   if(process.env.TACT_RENDERER_LIVE_RACE==='1'){
    await b.evaluate('tact2026.engine.send("pause",true)');await b.waitFor('tact2026.paused');
    raceWarmup=[];
    const warmClock=process.env.TACT_RENDERER_ISLAND==='1'?1600:5;
    while(await b.evaluate('tact2026.latest.clock<'+warmClock)){
     if(raceWarmup.length>=12)throw Error('Native countdown did not progress');
     raceWarmup.push(await b.evaluate('tact2026.engine.request("step",200)'));
    }
    await b.waitFor('tact2026.scene.modelSequence>=tact2026.latest.sequence||tact2026.error',60000);
    const target=await b.evaluate('({clock:tact2026.latest.clock,point:tact2026.latest.course.navigationTarget?.point,guides:tact2026.latest.course.guides.length})');
    if(target.clock<0||target.point!==3||!target.guides)throw Error('Live native race target/guides unavailable');
    if(process.env.TACT_RENDERER_ISLAND==='1')await b.evaluate('tact2026.engine.send("command",32909);tact2026.engine.request("boundary")');
    await b.evaluate('tact2026.engine.send("pause",false)');await b.waitFor('!tact2026.paused');
   }
   let guideFixture;
   if(process.env.TACT_RENDERER_GUIDE_FIXTURE==='1'){
    await b.evaluate('tact2026.engine.send("pause",true)');await b.waitFor('tact2026.paused');
    const cases=await b.evaluate('tact2026.engine.request("guidecase")');
    if(JSON.stringify(cases.before)!==JSON.stringify(cases.after))throw Error('Guide fixture extraction changed native state');
    guideFixture=cases.cases.find(c=>c.fixture.name==='upwind').candidate;
    await b.evaluate(`(()=>{const scene=tact2026.scene,receive=scene.receive.bind(scene),guides=${JSON.stringify(guideFixture)};scene.receive=state=>receive({...state,clock:20,course:{...state.course,guides,target:state.course.marks[0],navigationTarget:{...state.course.marks[0],point:3,finish:false}}});scene.receive(tact2026.latest);scene.labels.showAll=true;document.getElementById('names').setAttribute('aria-pressed','true');})()`);
    await b.evaluate('tact2026.engine.send("pause",false)');await b.waitFor('!tact2026.paused');
   }
   // Warm up original numeric/drawing code and material compilation, then reset.
   await b.waitFor('tact2026.latest.sequence>=60||tact2026.error',30000);
   await focus(b);
   const scenario=()=>b.evaluate('({generation:tact2026.latest.generation,configuration:tact2026.latest.configuration,fleet:tact2026.latest.boats.length,pace:tact2026.latest.pace,names:tact2026.scene.labels.showAll,markLines:tact2026.latest.course.showMarkLines,headingReference:tact2026.latest.course.showLaylines})');
   const scenarioStart=await scenario();if(scenarioStart.fleet!==15)throw Error('Evaluation requires the fifteen-boat reference');
   const start=await b.evaluate('({time:tact2026.latest.time,clock:tact2026.latest.clock,now:performance.now(),sequence:tact2026.latest.sequence})');
   await b.evaluate('tact2026.resetMetrics()');
   await b.waitFor('tact2026.scene.samples.length>=360||tact2026.error',30000);
   const end=await b.evaluate('({time:tact2026.latest.time,clock:tact2026.latest.clock,now:performance.now(),sequence:tact2026.latest.sequence,error:tact2026.error})');if(end.error)throw new Error(end.error);
   const scenarioEnd=await scenario();if(JSON.stringify(scenarioStart)!==JSON.stringify(scenarioEnd))throw Error('Evaluation scenario changed during measurement: '+JSON.stringify({scenarioStart,scenarioEnd}));
   const metrics=await b.evaluate('tact2026.metrics');
   const surface=await b.evaluate('(()=>{const c=document.getElementById("scene"),r=c.getBoundingClientRect();return {cssWidth:r.width,cssHeight:r.height,bufferWidth:c.width,bufferHeight:c.height,devicePixelRatio};})()');
   const visibility=await b.evaluate('({current:document.visibilityState,log:visibilityLog})');
   // Keep response checks outside cadence measurement; real trusted clicks.
   for(let n=0;n<6;n++){await click(b,n%2?'chase':'overview');await b.waitFor(`tact2026.responses.length>=${n+1}`,10000);}
   const responses=await b.evaluate('tact2026.responses');
   await click(b,'pause');await b.waitFor('tact2026.paused',10000);
   const before=await b.evaluate('tact2026.engine.request("boundary")');
   await click(b,'overview');await b.waitFor('tact2026.responses.length>=7',10000);const after=await b.evaluate('tact2026.engine.request("boundary")');
   if(JSON.stringify(before)!==JSON.stringify(after))throw new Error('Camera changed paused authoritative state');
   await writeFile(resolve(out,`${backend}-${repetition}.png`),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
   // Original steering handler through the modern button, followed by one real paint.
   const oldTarget=await b.evaluate('(async()=>{const bytes=await tact2026.engine.request("image");return new DataView(bytes.buffer,bytes.byteOffset,bytes.byteLength).getFloat64(0x4fe938-0x400000,true);})()');
   await b.evaluate('globalThis.trustedPortAccepted=false;tact2026.engine.worker.addEventListener("message",event=>{if(event.data.type==="accepted"&&event.data.data.command===32842)trustedPortAccepted=true;})');
   await click(b,'pause');await b.waitFor('!tact2026.paused',10000);
   const oldHeading=await b.evaluate('tact2026.latest.boats[0].heading');await click(b,'port');
   await click(b,'pause');await b.waitFor('tact2026.paused',10000);let helmPaints=0,newHeading=await b.evaluate('tact2026.latest.boats[0].heading');
   // Native rudder updates have class/paint eligibility; keep that separate
   // from completed-frame cadence and host camera-response measurements.
   while(newHeading===oldHeading&&helmPaints<4){await b.evaluate('tact2026.engine.request("step",1)');helmPaints++;newHeading=await b.evaluate('tact2026.latest.boats[0].heading');}
   const newTarget=await b.evaluate('(async()=>{const bytes=await tact2026.engine.request("image");return new DataView(bytes.buffer,bytes.byteOffset,bytes.byteLength).getFloat64(0x4fe938-0x400000,true);})()');
   if(!await b.evaluate('trustedPortAccepted')||oldTarget===newTarget)throw new Error('Trusted Port button did not reach original helm target');
   const badRequests=b.events.filter(e=>e.method==='Network.requestWillBeSent'&&/\.(exe|zip|cpuprofile)(\?|$)|\/analysis\/|\/fixtures\/|\/decompiled\//.test(e.params.request.url));if(badRequests.length)throw new Error('Runtime fetched evidence or executable');
   const completed=metrics.samples.filter(s=>s.intervalMs>0);let changedGap=0;const changed=[];for(const sample of completed){changedGap+=sample.intervalMs;if(sample.changed){changed.push(changedGap);changedGap=0;}}
   const summary={scenario:process.env.TACT_RENDERER_ISLAND==='1'?'Fifteen Optimists on the corrected island, native Page Up warm-up then Sailing pace for measurement, live racing near second mark; modern shore routing and coastal props':guideFixture?'Source-checked upwind guide presentation fixture plus all names; real native worker in prestart':raceWarmup?'Real native countdown-to-race; original AI, physical target and guides':'Real native prestart course and automatic nearby names',raceWarmup,startedFromModernSetup:process.env.TACT_RENDERER_STARTER==='1',minimapEnabled:await b.evaluate('document.getElementById("minimap-toggle").getAttribute("aria-pressed")==="true"'),guideCount:guideFixture?.length??await b.evaluate('tact2026.latest.course.guides.length'),requestedBackend:backend,actualBackend:metrics.backend,repetition,browser:b.metadata,adapter:metrics.adapterInfo,readyMs:metrics.readyMs,visibility,
    completedCadenceMs:stats(completed.map(s=>s.intervalMs)),changedCadenceMs:stats(changed),poseChangedFrames:metrics.samples.filter(s=>s.poseChanged).length,changedFrames:changed.length,blockedExternalKeyCount:await b.evaluate('benchmarkBlockedKeys'),
    cpuSubmitMs:stats(metrics.samples.map(s=>s.cpuMs)),gpuMs:metrics.gpuMs.length?stats(metrics.gpuMs):'unavailable',workerPaintMs:stats(metrics.workerCosts),snapshotMaxBytes:Math.max(...metrics.snapshotBytes),
    modelExtractionMs:stats(metrics.modelCosts),modelBuildMs:stats(metrics.modelBuildCosts),modelMaxBytes:Math.max(...metrics.modelBytes),combinedPresentationMaxBytes:Math.max(...metrics.snapshotBytes)+Math.max(...metrics.modelBytes),surface,scenarioStart,scenarioEnd,
    drawCallsMax:Math.max(...metrics.samples.map(s=>s.calls)),trianglesMax:Math.max(...metrics.samples.map(s=>s.triangles)),simulation:{start,end,simSecondsPerWallSecond:(end.time-start.time)/((end.now-start.now)/1000)},trustedCameraResponseMs:stats(responses.filter(s=>s.trusted).map(s=>s.ms)),pausedCameraStateUnchanged:true,trustedPort:{oldHeading,newHeading,oldTarget,newTarget,helmPaints,constrained:oldHeading===newHeading},prohibitedRequests:badRequests.length};
   summary.checks={changedCadence:summary.changedCadenceMs.median<=acceptance.cadenceMs.medianMax&&summary.changedCadenceMs.p95<=acceptance.cadenceMs.p95Max&&summary.changedCadenceMs.p99<=acceptance.cadenceMs.p99Max,
    trustedCamera:summary.trustedCameraResponseMs.samples===6&&summary.trustedCameraResponseMs.p95<acceptance.cameraHudResponseMs.p95StrictlyBelow,
    presentation:summary.modelExtractionMs.samples>0&&summary.combinedPresentationMaxBytes<=acceptance.snapshotBytesMax,
    geometry:summary.drawCallsMax<=acceptance.workingGeometryBudgets.drawCallsMax&&summary.trianglesMax<=acceptance.workingGeometryBudgets.visibleTrianglesMax,
    visible:visibility.current==='visible',physicsProgress:end.sequence>start.sequence&&end.time>start.time};
   await writeFile(resolve(out,`${backend}-${repetition}.json`),JSON.stringify({summary,metrics,responses,paused:{before,after}},null,2));runs.push(summary);console.log(JSON.stringify({backend:summary.actualBackend,repetition,cadence:summary.changedCadenceMs,camera:summary.trustedCameraResponseMs,drawCalls:summary.drawCallsMax,worker:summary.workerPaintMs,models:summary.modelExtractionMs,modelBuild:summary.modelBuildMs,presentationBytes:summary.combinedPresentationMaxBytes,gpu:summary.gpuMs,checks:summary.checks}));
   if(Object.values(summary.checks).some(passed=>!passed))throw new Error('Bounded renderer budget failed; see retained summary checks');
  }catch(error){await writeFile(resolve(out,`${backend}-${repetition}-failure.json`),JSON.stringify({message:error.stack,state:await b.evaluate('({ready:globalThis.tact2026?.ready,error:globalThis.tact2026?.error,paused:globalThis.tact2026?.paused,latest:globalThis.tact2026?.latest,metrics:globalThis.tact2026?.metrics,visible:document.visibilityState,focused:document.hasFocus(),visibility:globalThis.visibilityLog})').catch(e=>String(e))},null,2));throw error;}finally{await b.close();}
 }
 await writeFile(resolve(out,'verification.json'),JSON.stringify({format:1,passed:true,scope:'Bounded desktop Chrome renderer/backend/worker coexistence evaluation, not complete MVP or physical touch acceptance',runs},null,2));
}catch(error){await writeFile(resolve(out,'failure.txt'),error.stack);throw error;}
