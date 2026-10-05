import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile,readFile} from 'node:fs/promises';
import {resolve} from 'node:path';
if(process.argv.length!==3)throw Error('Usage: starter-eval.mjs NEW_DIRECTORY');const out=resolve(process.argv[2]);await mkdir(out);
const b=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true});const checks=[];
const healthy=async()=>{await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);const error=await b.evaluate('tact2026.error');if(error)throw Error(error)};
async function click(id){const p=await b.evaluate(`(()=>{const r=document.getElementById(${JSON.stringify(id)}).getBoundingClientRect();return {x:r.x+r.width/2,y:r.y+r.height/2}})()`);for(const type of ['mousePressed','mouseReleased'])await b.call('Input.dispatchMouseEvent',{type,...p,button:'left',clickCount:1});}
async function key(key,code,windowsVirtualKeyCode){for(const type of ['keyDown','keyUp'])await b.call('Input.dispatchKeyEvent',{type,key,code,windowsVirtualKeyCode});}
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});await healthy();
 const initial=await b.evaluate('tact2026.engine.request("boundary")');if(initial.memorySha256!=='391afc440f591035e003f724a8eb7a24b4d57ee893b6f41fad9991baefe8baf5')throw Error('Default preset changed');
 if(!(await b.evaluate('tact2026.paused&&!document.getElementById("starter").hidden&&document.getElementById("port").disabled&&!document.getElementById("start-race").disabled')))throw Error('Starter ownership failed');
 await b.evaluate('new Promise(r=>setTimeout(r,600))');const held=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(initial)!==JSON.stringify(held))throw Error('Countdown advanced on starter');
 await writeFile(resolve(out,'starter.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));checks.push({name:'default starter holds audited entire initial boundary',initial,held});
 await b.evaluate('document.getElementById("scene").focus()');await key('t','KeyT',84);const blocked=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(held)!==JSON.stringify(blocked))throw Error('Sailing input leaked into starter');checks.push({name:'helm input blocked during setup'});
 await click('start-race');await b.waitFor('!tact2026.paused&&tact2026.latest.sequence>=15',10000);if(!(await b.evaluate('document.getElementById("starter").hidden&&!document.getElementById("port").disabled')))throw Error('Start did not enable helm');checks.push({name:'trusted Start resumes native countdown',sequence:await b.evaluate('tact2026.latest.sequence')});
 await click('restart');await healthy();if(!(await b.evaluate('tact2026.paused&&!document.getElementById("starter").hidden')))throw Error('Restart skipped starter');checks.push({name:'restart returns to held starter'});
 await b.evaluate('globalThis.retiredWorkerError=tact2026.engine.worker.onerror');
 // Real browser select input, not a hand-authored game-memory configuration.
 for(const id of ['race-fleet','race-course','race-wind']){await b.evaluate(`document.getElementById('${id}').focus()`);await key('ArrowDown','ArrowDown',40);await key('Enter','Enter',13);await healthy();}
 await b.waitFor('tact2026.latest.configuration.fleet===15&&tact2026.latest.configuration.course===3&&tact2026.latest.configuration.wind===3',10000);
 const selected=await b.evaluate('({configuration:tact2026.latest.configuration,boats:tact2026.latest.boats.length,paused:tact2026.paused,models:tact2026.scene.models.size})');if(!selected.paused||selected.models!==15)throw Error('Selected fleet/model readiness mismatch');checks.push({name:'trusted native fifteen/Triangle/Strong selection',selected});
 await b.evaluate('retiredWorkerError({message:"Isolated retired-worker error fixture"})');if(await b.evaluate('Boolean(tact2026.error)||!tact2026.ready'))throw Error('Retired worker error stopped selected race');checks.push({name:'retired worker error callback cannot stop newer generation',scope:'Isolated callback fixture, not an actual worker crash'});
 await click('start-race');await b.waitFor('!tact2026.paused&&tact2026.latest.sequence>=16',10000);await b.evaluate('document.getElementById("scene").focus()');await key('n','KeyN',78);await healthy();await b.waitFor('tact2026.paused&&!document.getElementById("starter").hidden',10000);checks.push({name:'native N request returns to modern starter'});
 // Simulated visibility event through the same listener: it must not resume a
 // setup preview. This is event-path evidence, not an OS background-tab claim.
 const visibility=await b.evaluate(`(async()=>{const before=await tact2026.engine.request('boundary');Object.defineProperty(document,'hidden',{configurable:true,value:true});document.dispatchEvent(new Event('visibilitychange'));Object.defineProperty(document,'hidden',{configurable:true,value:false});document.dispatchEvent(new Event('visibilitychange'));delete document.hidden;await new Promise(r=>setTimeout(r,100));return {before,after:await tact2026.engine.request('boundary')}})()`);if(JSON.stringify(visibility.before)!==JSON.stringify(visibility.after))throw Error('Visibility resumed starter');checks.push({name:'visibility listener keeps setup paused',visibility});
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,checks,browser:b.metadata},null,2));console.log(JSON.stringify(checks.map(c=>c.name)));
}catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e}finally{await b.close()}
