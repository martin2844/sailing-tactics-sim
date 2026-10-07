import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const output=resolve(process.argv[2]);await mkdir(output);
const browser=await openBrowser('http://127.0.0.1:8770/?manual&fleet=5',{headless:true,gpu:true,requestTimeoutMs:60000});
const checks=[];
async function key(code,value,vk){for(const type of['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code,key:value,windowsVirtualKeyCode:vk});}
const state=()=>browser.evaluate(`(async()=>{const image=await tact2026.engine.request('image'),d=new DataView(image.buffer,image.byteOffset,image.byteLength);return {boat:tact2026.latest.boats[0],turn:d.getInt32(0x4f7094-0x400000,true),jibe:d.getInt32(0x5356b4-0x400000,true),auto:d.getInt32(0x511624-0x400000,true)};})()`);
async function maneuver(code,value,vk,field){
 const before=await state();await key('KeyF','f',70);await browser.waitFor('!tact2026.paused');
 await key(code,value,vk);await key('KeyF','f',70);await browser.waitFor('tact2026.paused');
 const armed=await state();if(armed[field]!==1)throw Error('Trusted maneuver was not retained: '+code);
 const path=[];
 for(let n=0;n<60;n++){await browser.evaluate('tact2026.engine.request("step",2)');const s=await state();path.push(s);if(s[field]===0&&s.boat.tack===-before.boat.tack)break;}
 const after=path.at(-1);if(after[field]!==0||after.boat.tack!==-before.boat.tack)throw Error('Maneuver failed: '+code);
 if(field==='turn'&&!after.auto)throw Error('Tack did not restore close-haul steering');
 await browser.waitFor('tact2026.scene.modelSequence===tact2026.latest.sequence||tact2026.error',60000);
 if(await browser.evaluate('tact2026.error'))throw Error(await browser.evaluate('tact2026.error'));
 checks.push({code,before,armed,after,path});await browser.evaluate('tact2026.engine.request("step",60)');
}
try{
 await browser.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 if(await browser.evaluate('tact2026.error'))throw Error(await browser.evaluate('tact2026.error'));
 await browser.evaluate('tact2026.engine.request("step",100)');
 await maneuver('KeyT','t',84,'turn');await maneuver('KeyT','t',84,'turn');
 await browser.evaluate('tact2026.engine.send("command",32848);tact2026.engine.request("step",200)');
 for(let n=0;n<5&&await browser.evaluate('tact2026.latest.boats[0].windAngle<130');n++)await browser.evaluate('tact2026.engine.request("step",50)');
 await maneuver('KeyJ','j',74,'jibe');await maneuver('KeyJ','j',74,'jibe');
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,checks,scope:'Trusted Chrome T/J/F keys, default Keelboat/5fleet; both tacks and both jibes arm, cross the correct wind side and complete through real numerical steps. Tack restores close-haul mode; model worker reaches every resulting state without error. Diagnostic stepping isolates turning from host wall-time pacing.'},null,2));
 console.log(JSON.stringify({passed:true,maneuvers:checks.length}));
}catch(error){await writeFile(resolve(output,'failure.json'),JSON.stringify({error:error.stack,checks},null,2));throw error;}finally{await browser.close();}
