import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {setTimeout as delay} from 'node:timers/promises';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});
const b=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true,requestTimeoutMs:60000}),checks=[];
async function key(code,value,vk,repeat=false){for(const type of ['keyDown','keyUp'])await b.call('Input.dispatchKeyEvent',{type,code,key:value,windowsVirtualKeyCode:vk,...(type==='keyDown'?{autoRepeat:repeat,...(value.length===1?{text:value}:code==='Enter'?{text:'\r'}:{})}:{})});}
async function click(id){const point=await b.evaluate(`(()=>{const r=document.getElementById('${id}').getBoundingClientRect();return{x:r.x+r.width/2,y:r.y+r.height/2};})()`);for(const type of ['mousePressed','mouseReleased'])await b.call('Input.dispatchMouseEvent',{type,...point,button:'left',clickCount:1});}
async function focus(id){await b.evaluate(`(()=>{if('${id}'==='hitboxes')document.getElementById('evaluation').open=true;document.getElementById('${id}').focus()})()`);await b.waitFor(`document.activeElement.id==='${id}'`);}
async function select(rate){await b.evaluate(`document.getElementById('pace').value='clock:${rate}';document.getElementById('pace').dispatchEvent(new Event('change'))`);await b.waitFor(`tact2026.latest.playback.selected.rate===${rate}&&tact2026.latest.playback.active.rate===${rate}`);}
async function active(rate){await b.waitFor(`tact2026.latest.playback.active.rate===${rate}&&document.activeElement.id==='scene'`);}
const state=()=>b.evaluate('({playback:tact2026.latest.playback,paused:tact2026.paused,focus:document.activeElement.id,checkbox:document.getElementById("hitboxes").checked,open:document.getElementById("pace").matches(":open"),scroll:scrollY,overview:tact2026.scene.cameraMode})');
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});
 await b.waitFor('globalThis.tact2026?.ready',60000);
 await b.evaluate('globalThis.sentKeys=[];{const client=tact2026.engine;globalThis.originalHotkeySends??=new WeakMap();const send=originalHotkeySends.get(client)??client.send.bind(client);originalHotkeySends.set(client,send);client.send=(type,data)=>{sentKeys.push({type,data});send(type,data)};};document.getElementById("race-speed").value="clock:8";document.getElementById("race-speed").dispatchEvent(new Event("change"))');
 await b.waitFor('tact2026.latest.playback.selected.rate===8');
 await focus('start-race');await key('Space',' ',32);await active(1);
 if(!await b.evaluate('!document.getElementById("starter").hidden'))throw Error('Space activated Start race');
 await focus('start-race');await key('Space',' ',32);await active(8);checks.push({name:'Space on Start button toggles pace and never clicks Start'});
 await focus('race-name');for(const [code,value,vk]of [['KeyT','t',84],['Space',' ',32],['KeyJ','j',74]])await key(code,value,vk);
 if(!await b.evaluate('document.getElementById("race-name").value==="t j"&&tact2026.latest.playback.active.rate===8'))throw Error('Name typing leaked gameplay keys');checks.push({name:'Boat-name typing remains isolated from gameplay shortcuts'});
 await click('start-race');await b.waitFor('tact2026.ready&&document.getElementById("starter").hidden&&!tact2026.paused',60000);
 await key('KeyF','f',70);await b.waitFor('tact2026.paused');await select(8);
 // The runtime may have been replaced while applying setup. Observe the actual
 // replacement client, rather than using a stale transport spy.
 await b.evaluate('globalThis.sentKeys=[];const client=tact2026.engine;globalThis.originalHotkeySends??=new WeakMap();const send=originalHotkeySends.get(client)??client.send.bind(client);originalHotkeySends.set(client,send);client.send=(type,data)=>{sentKeys.push({type,data});send(type,data)}');
 const before=await b.evaluate('tact2026.engine.request("boundary")');
 for(const id of ['overview','pause','hitboxes','pace']){
  await focus(id);const first=await state();await key('Space',' ',32);await active(1);
  await key('Space',' ',32,true);await active(1);
  await focus(id);await key('Space',' ',32);await active(8);const after=await state();
  if(after.checkbox!==first.checkbox||after.overview!==first.overview||after.paused!==first.paused||after.scroll!==first.scroll||after.open||after.playback.selected.rate!==8)throw Error('Space triggered a browser/control default '+JSON.stringify({id,first,after}));
  checks.push({name:'Focused '+id+': Space1×/8×, held-key repeat ignored, native defaults suppressed',first,after});
 }
 await click('pace');await b.waitFor('document.getElementById("pace").matches(":open")');await key('Space',' ',32);await active(1);
 if(await b.evaluate('document.getElementById("pace").matches(":open")'))throw Error('Picker remained open after Space transferred focus');await key('Space',' ',32);await active(8);if(!await b.evaluate('document.getElementById("pace").querySelector("selectedcontent .option-label").textContent==="8×"&&document.getElementById("pace").closest(".select-control").querySelector(".select-icon [data-needle]").dataset.needle==="-17"'))throw Error('Picker dismissal changed the selected label/gauge');checks.push({name:'Space captures an open native picker, closes it, retains label/gauge and toggles pace'});
 const after=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Paused pace/focus keys mutated authoritative state');checks.push({name:'Every paused focus/Space path retains the exact numerical boundary',before,after});
 await focus('pace');await key('PageUp','PageUp',33);await active(16);await focus('hitboxes');await key('PageDown','PageDown',34);await active(8);checks.push({name:'Page keys override focused select/checkbox defaults and transfer focus'});
 await click('overview');await b.waitFor('tact2026.scene.cameraMode==="overview"');await focus('pace');await key('KeyQ','q',81);await b.waitFor('tact2026.scene.cameraMode==="chase"&&document.activeElement.id==="scene"');checks.push({name:'Q follows the boat from a focused select'});
 await focus('overview');await key('KeyF','f',70);await b.waitFor('!tact2026.paused');
 for(const [id,code,value,vk]of [['pace','KeyT','t',84],['hitboxes','KeyJ','j',74],['overview','KeyI','i',73],['pause','KeyO','o',79],['overview','Enter','Enter',13]]){
  await focus(id);const count=await b.evaluate('sentKeys.length');await key(code,value,vk);await b.waitFor('document.activeElement.id==="scene"');
  const dispatched=await b.evaluate(`sentKeys.slice(${count})`);if(dispatched.filter(e=>e.type==='control'&&e.data===vk).length!==1)throw Error('Hotkey not sent exactly once '+JSON.stringify({id,code,dispatched}));
  if(await b.evaluate('tact2026.paused||tact2026.scene.cameraMode!=="chase"||document.getElementById("hitboxes").checked'))throw Error('Hotkey also activated the focused UI control');
  checks.push({name:code+' executes through the actual game transport from '+id,dispatched});
 }
 await key('KeyR','r',82);await b.waitFor('tact2026.latest.panel==="Race course"');await focus('panel-close');await key('Space',' ',32);await active(1);
 if(!await b.evaluate('tact2026.latest.panel==="Race course"'))throw Error('Space clicked Return to sailing');await key('Space',' ',32);await active(8);
 await focus('panel-close');await key('KeyT','t',84);await b.waitFor('!tact2026.latest.panel&&document.activeElement.id==="scene"');checks.push({name:'Space changes pace on held chart; a sailing hotkey returns to the game and executes'});
 await key('KeyY','y',89);await b.waitFor('tact2026.paused&&document.getElementById("information-panel").dataset.state==="ready"');await focus('information-close');await key('Space',' ',32);await active(1);
 if(!await b.evaluate('tact2026.paused&&!document.getElementById("information-panel").hidden'))throw Error('Space closed coach or resumed the game');await key('Space',' ',32);await active(8);await key('KeyT','t',84);await b.waitFor('!tact2026.paused&&document.getElementById("information-panel").hidden&&document.activeElement.id==="scene"');checks.push({name:'Space toggles pace while coach holds; T returns to sailing and executes'});
 await key('KeyF','f',70);await b.waitFor('tact2026.paused');
 // Negative control for the scheduler change: the previous direct timer chain
 // incurs Chrome's nested-timer clamp; message tasks reset the nesting level.
 const scheduling=await b.evaluate(`new Promise((resolve,reject)=>{
  const source=\`onmessage=async()=>{const runs=[];for(const messages of [false,true]){const channel=new MessageChannel();let count=0,start=performance.now();await new Promise(done=>{const tick=()=>{if(++count===100){runs.push({messages,ms:performance.now()-start});done();return;}setTimeout(messages?()=>channel.port2.postMessage(0):tick,1);};channel.port1.onmessage=tick;tick();});channel.port1.close();channel.port2.close();}postMessage(runs)}\`;
  const url=URL.createObjectURL(new Blob([source],{type:'text/javascript'})),worker=new Worker(url);worker.onmessage=e=>{worker.terminate();URL.revokeObjectURL(url);resolve(e.data)};worker.onerror=e=>{worker.terminate();URL.revokeObjectURL(url);reject(Error(e.message))};worker.postMessage(0);
 })`);
 if(scheduling[1].ms>=scheduling[0].ms*.8)throw Error('Message scheduling did not avoid timer clamp '+JSON.stringify(scheduling));checks.push({name:'Chrome negative control proves direct nested timers are throttled and message-mediated timers avoid the clamp',scheduling});
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,checks,scope:'Actual Chrome trusted key events over buttons, checkbox, closed/open customizable selects, starter and coach/course panels. Real EngineClient dispatch is observed and still executed; paused whole-image/RNG boundary remains exact. A separate worker compares old nested timers with message-mediated timers. Text editing and held-key repeat are tested.'},null,2));console.log(JSON.stringify({passed:true,checks:checks.length,scheduling}));
}catch(error){await writeFile(resolve(output,'failure.json'),JSON.stringify({error:error.stack,checks,state:await state().catch(String)},null,2));throw error;}finally{await b.close();}
