import {openBrowser} from '../../../../tools/browser-session.js';
import {boatChoices,areaChoices,gateCourses} from '../../app/native-catalog.ts';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const output=resolve(process.argv[2]);await mkdir(output);
const browser=await openBrowser('http://127.0.0.1:8770/?manual&fleet=5',{headless:true,gpu:true,requestTimeoutMs:60000});
const checks=[];
async function evaluateCase(settings,fleet=5,geometry=true){
 return browser.evaluate(`(async()=>{
  let client,blob;const NativeWorker=globalThis.Worker;
  // Enforce the architectural boundary at execution time in the actual worker.
  globalThis.Worker=class extends NativeWorker {
   constructor(url,options){if(String(url).includes('engine.worker')){
    const source='const NativeURL=globalThis.URL;globalThis.URL=class extends NativeURL{constructor(input,base){super(input,typeof base==="string"&&base.startsWith("blob:")?'+JSON.stringify(String(url))+':base);}};const queued=[];self.onmessage=e=>queued.push(e);globalThis.OffscreenCanvas=class{constructor(){throw Error("Forbidden authoritative Canvas allocation");}};globalThis.createImageBitmap=()=>{throw Error("Forbidden authoritative bitmap");};await import('+JSON.stringify(String(url))+');const handler=self.onmessage;for(const e of queued)handler(e);';
    blob=URL.createObjectURL(new Blob([source],{type:'text/javascript'}));super(blob,options);
   }else super(url,options);}
  };
  try{
   let state;
   await new Promise((resolve,reject)=>{client=new tact2026.engine.constructor(8241,${fleet},true,{ready:resolve,snapshot:s=>state=s,models:()=>{},paused:()=>{},error:reject},${JSON.stringify(settings)});});
   globalThis.Worker=NativeWorker;
   const before=await client.request('boundary');
   const configuration=state.configuration;
   const packet=await client.request('geometry');
   if(!packet.positions.length||packet.boats.length!==${fleet}*3)throw Error('Missing boat geometry');
   if(!state.boats.every(b=>Number.isFinite(b.depth)&&Number.isFinite(b.speed)&&b.trueWind>0))throw Error('Invalid initial conditions');
   const after=await client.request('boundary');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Geometry mutated master');
   await client.request('step',30);const advanced=await client.request('boundary');
   if(advanced.time<=before.time)throw Error('Simulation did not advance');
   return {configuration,before,advanced,vertices:packet.positions.length/3,records:packet.records.length,contacts:state.contacts};
  }finally{globalThis.Worker=NativeWorker;client?.dispose();if(blob)URL.revokeObjectURL(blob);}
 })()`);
}
try{
 await browser.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 if(await browser.evaluate('tact2026.error'))throw Error(await browser.evaluate('tact2026.error'));
 const cases=[];
 for(const boat of boatChoices)cases.push({label:'boat-'+boat.value,settings:{boat:boat.value,area:32799,course:1,wind:2}});
 for(const area of areaChoices)cases.push({label:'venue-'+area.command,settings:{boat:area.area===8||area.venue===5?14:12,area:area.command,course:[32964,33018].includes(area.command)?3:1,wind:2}});
 for(let course=1;course<=7;course++)for(let direction=0;direction<360;direction+=45)cases.push({label:'island-'+course+'-'+direction,settings:{boat:1,area:32801,course,wind:2,windDirection:direction}});
 for(let course=1;course<=7;course++)cases.push({label:'short-'+course,settings:{boat:12,area:32799,course,wind:2,short:true}});
 for(const course of gateCourses)for(const short of[false,true])cases.push({label:'gate-'+course+'-'+short,fleet:20,settings:{boat:12,area:32799,course,wind:2,gate:true,short}});
 for(const c of cases){
  const result=await evaluateCase(c.settings,c.fleet??5),configuration=result.configuration,area=areaChoices.find(a=>a.command===c.settings.area);
  if(configuration.selector!==c.settings.boat||configuration.area!==area.area||configuration.venue!==area.venue||configuration.course!==c.settings.course||configuration.wind!==c.settings.wind||configuration.short!==!!c.settings.short||configuration.gate!==!!c.settings.gate)throw Error('Selection mismatch '+c.label+' '+JSON.stringify(configuration));
  checks.push({...c,result});await writeFile(resolve(output,'progress.json'),JSON.stringify({checks},null,2));console.log(JSON.stringify({passed:true,label:c.label}));
 }
 const held=await browser.evaluate('tact2026.engine.request("boundary")');
 await browser.evaluate('tact2026.engine.send("key",78);tact2026.engine.send("key",32);tact2026.engine.request("step",10)');
 if(await browser.evaluate('tact2026.latest.panel==="Race setup"||tact2026.latest.time===tact2026.initial.time'))throw Error('N/Space restart remained in setup');
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,checks,held,scope:'Actual Chrome worker with Canvas/bitmap allocation guards: every27boat class, every33venue,56islandcourse/wind combinations,7shortcourses and8gatedcases; canonical geometry validity, configuration readback,30real simulation steps and private-geometry purity percase; public N/Space restart. Bounded startup coverage, not complete races in every combination.'},null,2));
}catch(error){await writeFile(resolve(output,'failure.json'),JSON.stringify({error:error.stack,checks},null,2));throw error;}finally{await browser.close();}
