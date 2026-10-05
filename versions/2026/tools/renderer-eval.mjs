import {mkdir,writeFile,readFile} from 'node:fs/promises';
import {resolve} from 'node:path';
async function focus(b){await b.call("Page.bringToFront");}
import {openBrowser} from '../../../tools/browser-session.js';
const out=resolve(process.argv[2]??'');if(process.argv.length<3)throw new Error('Usage: renderer-eval.mjs NEW_DIRECTORY [REPEATS=5]');await mkdir(out);
const repetitions=Number(process.argv[3]??5),runs=[];
const acceptance=JSON.parse(await readFile(new URL('../config/acceptance.json',import.meta.url),'utf8')).desktop;
const percentile=(a,p)=>{const sorted=a.filter(v=>Number.isFinite(v)).sort((a,b)=>a-b);return sorted.length?sorted[Math.min(sorted.length-1,Math.floor(sorted.length*p))]:null;};
function stats(a){return{samples:a.length,median:percentile(a,.5),p95:percentile(a,.95),p99:percentile(a,.99),max:a.length?Math.max(...a):null};}
async function click(b,id){const p=await b.evaluate(`(()=>{const r=document.getElementById(${JSON.stringify(id)}).getBoundingClientRect();return {x:r.x+r.width/2,y:r.y+r.height/2};})()`);await b.call('Input.dispatchMouseEvent',{type:'mouseMoved',...p});await b.call('Input.dispatchMouseEvent',{type:'mousePressed',button:'left',clickCount:1,...p});await b.call('Input.dispatchMouseEvent',{type:'mouseReleased',button:'left',clickCount:1,...p});}
try{
 for(const backend of ['webgl2','webgpu'])for(let repetition=0;repetition<repetitions;repetition++){
  const b=await openBrowser(`http://127.0.0.1:8770/spike/?fleet=15&backend=${backend}`,{headless:false,gpu:true,width:1280,height:1051,requestTimeoutMs:60000});
  try{
   await b.call('Page.addScriptToEvaluateOnNewDocument',{source:"globalThis.visibilityLog=[];document.addEventListener('visibilitychange',()=>visibilityLog.push({state:document.visibilityState,time:performance.now()}));"});await b.call('Page.reload');
   await b.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});
   await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);const err=await b.evaluate('tact2026.error');if(err)throw new Error(err);
   await focus(b);
   // Warm up original numeric/drawing code and material compilation, then reset.
   await b.waitFor('tact2026.latest.sequence>=60||tact2026.error',30000);
   await focus(b);
   const start=await b.evaluate('({time:tact2026.latest.time,clock:tact2026.latest.clock,now:performance.now(),sequence:tact2026.latest.sequence})');
   await b.evaluate('tact2026.resetMetrics()');
   await b.waitFor('tact2026.scene.samples.length>=360||tact2026.error',30000);
   const end=await b.evaluate('({time:tact2026.latest.time,clock:tact2026.latest.clock,now:performance.now(),sequence:tact2026.latest.sequence,error:tact2026.error})');if(end.error)throw new Error(end.error);
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
   const oldHeading=await b.evaluate('tact2026.latest.boats[0].heading');await click(b,'port');await b.evaluate('tact2026.engine.request("step",1)');
   const newHeading=await b.evaluate('tact2026.latest.boats[0].heading');
   if(oldHeading===newHeading)throw new Error('Trusted Port button did not change original heading');
   const badRequests=b.events.filter(e=>e.method==='Network.requestWillBeSent'&&/\.(exe|zip|cpuprofile)(\?|$)|\/analysis\/|\/fixtures\/|\/decompiled\//.test(e.params.request.url));if(badRequests.length)throw new Error('Runtime fetched evidence or executable');
   const completed=metrics.samples.filter(s=>s.intervalMs>0);let changedGap=0;const changed=[];for(const sample of completed){changedGap+=sample.intervalMs;if(sample.changed){changed.push(changedGap);changedGap=0;}}
   const summary={requestedBackend:backend,actualBackend:metrics.backend,repetition,browser:b.metadata,adapter:metrics.adapterInfo,readyMs:metrics.readyMs,visibility,
    completedCadenceMs:stats(completed.map(s=>s.intervalMs)),changedCadenceMs:stats(changed),poseChangedFrames:metrics.samples.filter(s=>s.poseChanged).length,changedFrames:changed.length,
    cpuSubmitMs:stats(metrics.samples.map(s=>s.cpuMs)),gpuMs:metrics.gpuMs.length?stats(metrics.gpuMs):'unavailable',workerPaintMs:stats(metrics.workerCosts),snapshotMaxBytes:Math.max(...metrics.snapshotBytes),
    modelExtractionMs:stats(metrics.modelCosts),modelBuildMs:stats(metrics.modelBuildCosts),modelMaxBytes:Math.max(...metrics.modelBytes),combinedPresentationMaxBytes:Math.max(...metrics.snapshotBytes)+Math.max(...metrics.modelBytes),surface,
    drawCallsMax:Math.max(...metrics.samples.map(s=>s.calls)),trianglesMax:Math.max(...metrics.samples.map(s=>s.triangles)),simulation:{start,end,simSecondsPerWallSecond:(end.time-start.time)/((end.now-start.now)/1000)},trustedCameraResponseMs:stats(responses.filter(s=>s.trusted).map(s=>s.ms)),pausedCameraStateUnchanged:true,trustedPort:{oldHeading,newHeading},prohibitedRequests:badRequests.length};
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
