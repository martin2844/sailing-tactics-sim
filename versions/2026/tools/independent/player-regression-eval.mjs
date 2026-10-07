import {openBrowser} from '../../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {simulatorSpeeds} from '../../app/engine/speed.ts';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});
const browser=await openBrowser('http://127.0.0.1:8770/?manual&fleet=5',{headless:true,gpu:true,requestTimeoutMs:60000});
const checks=[];
async function key(code,value,vk){for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code,key:value,windowsVirtualKeyCode:vk});}
async function select(id,value){await browser.evaluate(`(()=>{const e=document.getElementById(${JSON.stringify(id)});e.focus();e.value=${JSON.stringify(String(value))};e.dispatchEvent(new Event('change'));if(document.activeElement.id!=='scene')throw Error('Pace selector retained shortcut focus');})()`);}
try{
 await browser.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 if(await browser.evaluate('tact2026.error'))throw Error(await browser.evaluate('tact2026.error'));
 for(const {level,command} of simulatorSpeeds){
  await select('pace',command);await browser.waitFor(`tact2026.latest.configuration.speed===${level}&&tact2026.latest.pace===${level}`);
  await key('Space',' ',32);await browser.waitFor(`tact2026.latest.pace===1&&tact2026.latest.configuration.speed===${level}`);
  await key('Space',' ',32);await browser.waitFor(`tact2026.latest.pace===${level}`);
  if(!await browser.evaluate(`tact2026.paused&&document.getElementById('race-speed').value==='${level}'&&localStorage.getItem('tact2026.simulatorSpeed')==='${level}'`))throw Error('Selection/freeze drift at '+level);
  checks.push({name:'selected speed '+level+' with trusted Space twice while held'});
 }
 await select('pace',32876);await key('PageUp','PageUp',33);await browser.waitFor('tact2026.latest.configuration.speed===6&&document.getElementById("race-speed").value==="6"');
 await key('Space',' ',32);await browser.waitFor('tact2026.latest.pace===1');await key('Space',' ',32);await browser.waitFor('tact2026.latest.pace===6');
 await browser.call('Page.reload',{});await browser.waitFor('globalThis.tact2026?.ready&&tact2026.latest.configuration.speed===6',60000);
 checks.push({name:'Page Up updates selected pace, setup, Space restore and reload preference'});
 // Both helm buttons go through the public UI/control-command route. Native
 // commands change the retained rudder; no physical motion is synthesized.
 const readRudder=()=>browser.evaluate(`(async()=>{const bytes=await tact2026.engine.request('image');return new DataView(bytes.buffer).getFloat64(0x4fe938-0x400000,true);})()`);
 const helm={before:await readRudder()};
 for(const direction of ['starboard','port']){
  await key('KeyF','f',70);await browser.waitFor('!tact2026.paused');
  await browser.evaluate(`document.getElementById('${direction}').click();tact2026.engine.send('pause',true)`);await browser.waitFor('tact2026.paused');helm[direction]=await readRudder();
 }
 if(!(helm.starboard>helm.before&&helm.port<helm.starboard))throw Error('Port/starboard helm direction '+JSON.stringify(helm));
 checks.push({name:'Both helm directions available',helm});
 for(const boat of [12,11,1])for(const fleet of [5,15,30]){
  const result=await browser.evaluate(`(async()=>{let client,state;try{
   await new Promise((resolve,reject)=>{client=new tact2026.engine.constructor(7382,${fleet},true,{ready:resolve,snapshot:s=>state=s,models:()=>{},paused:()=>{},error:reject},{boat:${boat},area:32799,course:1,wind:2,speed:10});});
   await client.request('boundary');const positions=state.boats.map(b=>({id:b.id,x:b.x,y:b.y}));
   if(new Set(positions.map(b=>b.x+','+b.y)).size!==${fleet})throw Error('Duplicate spawn');
   const samples=[];
   for(const count of [0,4]){if(count)await client.request('step',count);const bytes=await client.request('image'),d=new DataView(bytes.buffer);const penalty=d.getInt32(0x535624-0x400000,true),status=d.getInt32(0x5116e4-0x400000,true),packet=await client.request('geometry');let polygons=0;
    const begin=packet.boats[1],end=packet.boats[2];for(let i=begin;i<end;){const [op,part,fill,,flags,,vertices]=packet.records.slice(i,i+7);if(op===1&&part===5&&!(flags&2)){polygons++;if(packet.colors[fill]===0)throw Error('Black mainsail at startup');}i+=7+vertices+(op===3?2:op===4?4:0);}
    if(!polygons||penalty!==-2000||status===4)throw Error('Startup foul '+JSON.stringify({penalty,status,polygons}));samples.push({sequence:state.sequence,penalty,status,polygons});
   }
   return {positions,samples};
  }finally{client?.dispose();}})()`);
  checks.push({name:'White clear spawn',boat,fleet,result});
 }
 await browser.evaluate('tact2026.engine.send("control",8);tact2026.engine.request("boundary")');
 await browser.waitFor('tact2026.latest.frozen&&tact2026.paused');checks.push({name:'Public replay accepted while host paused'});
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,checks,scope:'Actual Chrome public UI selection and trusted Space/F/PageUp keys; selected speed persistence, both helm directions, nine actual workers and private mainsail mesh colors at boot/four live steps, public paused replay. Bounded startup proof; sailing collisions remain enabled.'},null,2));console.log(JSON.stringify({passed:true,checks:checks.length}));
}catch(error){await writeFile(resolve(output,'failure.json'),JSON.stringify({error:error.stack,checks},null,2));throw error;}finally{await browser.close();}
