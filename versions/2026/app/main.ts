import '@fontsource/ibm-plex-sans/latin-400.css';
import '@fontsource/ibm-plex-sans/latin-600.css';
import './style.css';
import {EngineClient} from './engine-client';
import {SailingScene,type RenderSample} from './scene';
import {commands,type Boundary,type SceneSnapshot} from './protocol';
const app=document.querySelector<HTMLDivElement>('#app')!;
app.innerHTML=`<header><strong>Tact <span>2026</span></strong><div class="setup"><span>Round Lake</span><label>Fleet <select id="fleet"><option value="5">5 keelboats</option><option value="15">15 keelboats</option></select></label></div><button id="restart">Restart race</button></header>
<section class="sailing" aria-label="Sailing scene"><canvas id="scene" tabindex="0" aria-label="Drag to look around the sailing scene"></canvas>
<canvas id="boats" aria-hidden="true"></canvas>
<div class="instruments" aria-label="Boat instruments"><div><span id="clock-label">Prestart</span><strong id="clock">—</strong></div><dl><div><dt>Heading</dt><dd id="heading">—</dd></div><div><dt>Speed</dt><dd id="speed">—</dd></div><div><dt>Wind</dt><dd id="wind">—</dd></div></dl><span class="your-boat"><i></i>Your boat</span></div>
<nav class="cameras" aria-label="Camera"><button id="chase" aria-pressed="true">Follow boat</button><button id="overview" aria-pressed="false">Overview</button></nav>
<div id="notice" role="status">Preparing the fleet…</div></section>
<footer><button id="pause" disabled>Pause</button><div class="helm" role="group" aria-label="Helm"><button id="port" disabled>Port ↶</button><button id="tack" disabled>Tack</button><button id="starboard" disabled>Starboard ↷</button><button id="close" disabled>Close hauled</button><button id="run" disabled>Run</button></div><label>Pace <select id="pace" disabled><option value="32909">Sailing</option><option value="32876">Study</option><option value="32872">Precision</option></select></label></footer>
<div class="preview-note">Development preview <span>Original boat geometry. Arrow keys to steer; T to tack; Space to pause.</span><a href="${location.pathname.includes('/spike')?'../':'./'}spike/?backend=webgpu">Compare renderer</a></div>
<details id="evaluation"><summary>Renderer evaluation</summary><pre id="diagnostics"></pre></details>`;
const $=<T extends HTMLElement=HTMLElement>(id:string)=>document.getElementById(id) as T;
const query=new URLSearchParams(location.search),manual=query.has('manual');let fleet=query.get('fleet')==='15'?15:5,generation=0,engine:EngineClient;
let latest:SceneSnapshot|undefined,initial:Boundary|undefined,error:string|undefined,ready=false,paused=manual,hiddenPaused=false,wasPlaying=false,animation=0,lastHud=0;
let sceneReady=false,readyMs=0;const workerCosts:number[]=[],snapshotBytes:number[]=[],responses:{kind:string;ms:number;trusted:boolean}[]=[];let pendingResponse:{kind:string;start:number;trusted:boolean}|undefined;
$('fleet').setAttribute('aria-label','Fleet size');($('fleet') as HTMLSelectElement).value=String(fleet);
const notice=$('notice');let canvas=$<HTMLCanvasElement>('scene'),scene:SailingScene,graphicsFailed=false;
function initializeScene(){
 const candidate=new SailingScene(canvas,$<HTMLCanvasElement>('boats'),sample=>{if(sample.changed&&pendingResponse){responses.push({kind:pendingResponse.kind,ms:performance.now()-pendingResponse.start,trusted:pendingResponse.trusted});pendingResponse=undefined;}},message=>{if(scene===candidate){graphicsFailed=true;fail(message);}});
 scene=candidate;sceneReady=false;
 candidate.initialize(query.get('backend')==='webgpu'?'webgpu':'webgl2').then(()=>{if(scene!==candidate)return;sceneReady=true;refreshReady();}).catch(e=>{if(scene===candidate){graphicsFailed=true;fail(String(e));}});
}
function enable(enabled:boolean){for(const id of ['pause','port','tack','starboard','close','run','pace'])($<HTMLButtonElement>(id)).disabled=!enabled;}
function refreshReady(){const complete=ready&&sceneReady&&scene.hasModels&&!error;enable(complete);if(complete)notice.hidden=true;}
function fail(message:string){error=message;ready=false;enable(false);engine?.send('pause',true);notice.hidden=false;notice.textContent='The scene stopped. Restart the race to try again.';$('diagnostics').textContent=message;console.error(message);}
function setPaused(value:boolean){paused=value;scene.setPaused(value);$('pause').textContent=value?'Resume':'Pause';$('pause').setAttribute('aria-pressed',String(value));}
function restart(){engine?.dispose();generation++;ready=false;error=undefined;if(graphicsFailed){scene.dispose();const replacement=canvas.cloneNode(false) as HTMLCanvasElement;canvas.replaceWith(replacement);canvas=replacement;graphicsFailed=false;initializeScene();}initial=undefined;latest=undefined;workerCosts.length=0;snapshotBytes.length=0;enable(false);scene.reset();($<HTMLSelectElement>('pace')).value='32909';setPaused(manual);notice.hidden=false;notice.textContent='Preparing the fleet…';
 const current=generation,initiallyHidden=document.hidden;hiddenPaused=initiallyHidden;wasPlaying=initiallyHidden&&!manual;
 engine=new EngineClient(current,fleet,manual||initiallyHidden,{ready:value=>{if(current!==generation||error)return;if(initiallyHidden&&!document.hidden&&!manual)engine.send('pause',false);initial=value;ready=true;readyMs=performance.now();refreshReady();},models:value=>{if(current!==generation||error)return;if(!scene.hasModels)readyMs=performance.now();scene.receiveModels(value);refreshReady();},snapshot:value=>{if(current!==generation||error)return;latest=value;scene.receive(value);if(workerCosts.length<4000){workerCosts.push(value.workMs);const {nativeVisuals,...state}=value;snapshotBytes.push(new TextEncoder().encode(JSON.stringify(state)).byteLength+nativeVisuals.geometry.byteLength+nativeVisuals.styles.byteLength+nativeVisuals.boats.byteLength);}},error:fail,paused:value=>{if(current===generation)setPaused(value);}});
}
function camera(mode:'chase'|'overview',event?:Event){scene.setCamera(mode);$('chase').setAttribute('aria-pressed',String(mode==='chase'));$('overview').setAttribute('aria-pressed',String(mode==='overview'));pendingResponse={kind:'camera',start:performance.now(),trusted:event?.isTrusted??false};}
function command(id:number){if(ready&&!error)engine.send('command',id);}
$('restart').addEventListener('click',restart);$('fleet').addEventListener('change',()=>{fleet=Number($<HTMLSelectElement>('fleet').value);restart();});
$('chase').addEventListener('click',e=>camera('chase',e));$('overview').addEventListener('click',e=>camera('overview',e));
for(const name of ['port','starboard','tack','close','run'] as const)$(name).addEventListener('click',()=>command(commands[name]));
$('pace').addEventListener('change',()=>command(Number($<HTMLSelectElement>('pace').value)));
$('pause').addEventListener('click',()=>{if(ready){engine.send('pause',!paused);}});
document.addEventListener('keydown',event=>{if(!ready||event.ctrlKey||event.metaKey||event.altKey||(event.target as HTMLElement).closest('button,select,input'))return;const id=event.code==='ArrowLeft'?commands.port:event.code==='ArrowRight'?commands.starboard:event.code==='KeyT'?commands.tack:null;if(id){event.preventDefault();command(id);}else if(event.code==='Space'){event.preventDefault();engine.send('pause',!paused);}});
document.addEventListener('visibilitychange',()=>{if(!ready)return;if(document.hidden){hiddenPaused=true;wasPlaying=!paused;engine.send('pause',true);}else if(hiddenPaused){hiddenPaused=false;if(wasPlaying)engine.send('pause',false);}});
function hud(){if(!latest)return;const player=latest.boats[0];const seconds=Math.abs(latest.clock);$('clock').textContent=`${Math.floor(seconds/60)}:${String(seconds%60).padStart(2,'0')}`;$('clock-label').textContent=latest.results?'Finished':latest.clock<0?'Prestart':'Race time';$('heading').textContent=player.heading+'°';$('speed').textContent=player.speed.toFixed(1)+' kn';$('wind').textContent=latest.windStrength+' / '+latest.windDirection+'°';}
function loop(now:number){if(error){animation=requestAnimationFrame(loop);return;}if(sceneReady&&ready&&scene.hasModels&&!document.hidden){try{scene.render(now);if(now-lastHud>100){hud();lastHud=now;}if(($('evaluation') as HTMLDetailsElement).open)$('diagnostics').textContent=`${scene.actualBackend}\n${latest?.boats.length} boats; ${scene.samples.at(-1)?.calls} draw calls; ${scene.samples.at(-1)?.triangles} triangles\nFrame ${latest?.sequence}; original clock ${latest?.clock}\n${JSON.stringify(scene.adapterInfo)}`;}catch(e){graphicsFailed=true;fail(e instanceof Error?e.message:String(e));}}animation=requestAnimationFrame(loop);}
initializeScene();
restart();animation=requestAnimationFrame(loop);
Object.assign(globalThis,{tact2026:{get ready(){return ready&&sceneReady&&scene.hasModels;},get initial(){return initial;},get latest(){return latest;},get error(){return error;},get paused(){return paused;},get engine(){return engine;},get scene(){return scene;},camera,restart,get readyMs(){return readyMs;},workerCosts,snapshotBytes,responses,resetMetrics(){scene.resetMetrics();workerCosts.length=0;snapshotBytes.length=0;responses.length=0;},get metrics(){return {samples:scene.samples,gpuMs:scene.gpuMs,backend:scene.actualBackend,adapterInfo:scene.adapterInfo,workerCosts,snapshotBytes,modelCosts:scene.modelCosts,modelBytes:scene.modelBytes,modelSequence:scene.modelSequence,modelBuildCosts:scene.modelBuildCosts,responses,readyMs};}}});
window.addEventListener('pagehide',()=>{cancelAnimationFrame(animation);engine.dispose();scene.dispose();});
