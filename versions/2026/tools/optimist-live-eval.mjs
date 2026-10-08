import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {setTimeout as delay} from 'node:timers/promises';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});
const browser=await openBrowser('http://127.0.0.1:8771/',{headless:false,gpu:true,requestTimeoutMs:60000});
try{
 await browser.call('Emulation.setFocusEmulationEnabled',{enabled:true});
 await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:900,deviceScaleFactor:1,mobile:false});
 await browser.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 console.log('Ready; checking geometry');
 if(await browser.evaluate('tact2026.error'))throw Error(await browser.evaluate('tact2026.error'));
 const geometry=await browser.evaluate(`(async()=>{
  const {OptimistStudy}=await import('/app/models/optimist-study.ts');
  const {OptimistBoatMesh}=await import('/app/models/optimist-boat-mesh.ts');
  const {boatSample}=await import('/app/starter-samples.ts');
  const reference=new OptimistStudy(),live=new OptimistStudy(),rows=[];
  for(const trim of [-85,-30,0,12,80])for(const penalty of [false,true]){
   const pose={trim,heel:0,luff:.8,time:.25,penalty,crew:true};reference.update(pose);live.animate(pose);
   const a=reference.rig.geometry.attributes.position.array,b=live.rig.geometry.attributes.position.array;
   // First 70 triangles are the sail panels (the window is its own mesh).
   let clothError=0;for(let i=0;i<70*9;i++)clothError=Math.max(clothError,Math.abs(a[i]-b[i]));
   if(clothError>1e-5)throw Error('Live cloth differs from reviewed study '+clothError);
   for(const mesh of [live.hull,live.rig,live.sailor,live.window])for(const key of ['position','normal'])if(!Array.from(mesh.geometry.attributes[key].array).every(Number.isFinite))throw Error('Non-finite live geometry');
   const color=live.rig.geometry.attributes.color;if(penalty&&color.getX(0)>.05)throw Error('Penalty not applied');
   rows.push({trim,penalty,clothError});
  }
  const boat=new OptimistBoatMesh(),p=boatSample(1);boat.update(p,p.boats[1],p.boats[2]);
  const state={id:1,heading:0,windFrom:0,luff:90};boat.interpolate(1,state,1);
  const before=Array.from(boat.model.rig.geometry.attributes.position.array);boat.interpolate(1,state,1);
  const frozen=before.every((v,i)=>v===boat.model.rig.geometry.attributes.position.array[i]);
  boat.interpolate(1,state,1.2);const flutter=before.some((v,i)=>v!==boat.model.rig.geometry.attributes.position.array[i]);
  if(!frozen||!flutter)throw Error('Pause or headwind animation failed');
  boat.interpolate(1,state,.1);const crew=Array.from(boat.model.sailor.geometry.attributes.position.array);
  boat.interpolate(1,state,1.5);const crewStableInHeadwind=crew.every((v,i)=>v===boat.model.sailor.geometry.attributes.position.array[i]);
  if(!crewStableInHeadwind)throw Error('Crew crossed the boat with visual sail flutter');
  boat.dispose();live.dispose();reference.dispose();return {rows,frozen,flutter,crewStableInHeadwind};
 })()`);
 console.log('Geometry passed; setting up fleet');
 await browser.evaluate(`(()=>{for(const [id,value]of [['race-boat','1'],['race-fleet','30'],['race-speed','clock:32']]){const field=document.getElementById(id);field.value=value;field.dispatchEvent(new Event('change',{bubbles:true}));}})()`);
 await browser.waitFor("document.getElementById('boat-preview').dataset.boat==='1'&&document.getElementById('boat-preview').dataset.state==='ready'",30000);
 await writeFile(resolve(output,'starter.png'),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 await browser.evaluate('document.getElementById("race-form").requestSubmit()');
 await browser.waitFor('(tact2026.ready&&document.getElementById("starter").hidden&&tact2026.latest.configuration.selector===1&&tact2026.latest.boats.length===30&&tact2026.scene.models.size===30)||tact2026.error',60000);
 if(await browser.evaluate('tact2026.error'))throw Error(await browser.evaluate('tact2026.error'));
 console.log('Fleet ready; sampling frames');
 const timing=await browser.evaluate(`new Promise(resolve=>{const times=[];let last=performance.now();function sample(now){times.push(now-last);last=now;if(times.length<300)requestAnimationFrame(sample);else resolve(times);}requestAnimationFrame(sample);})`);
 console.log('Frames sampled');
 const live=await browser.evaluate(`({error:tact2026.error,rate:tact2026.latest.playback.actualRate,selected:tact2026.latest.playback.selected.rate,boats:tact2026.scene.models.size,newModels:[...tact2026.scene.models.values()].every(m=>!!m.model?.sailor),gpu:tact2026.scene.adapterInfo})`);
 if(live.error||!live.newModels||live.selected!==32)throw Error('Live Optimist fleet failed '+JSON.stringify(live));
 await browser.evaluate('tact2026.engine.send("pause",true)');await browser.waitFor('tact2026.paused');
 const boundaryBefore=await browser.evaluate('tact2026.engine.request("boundary")');
 console.log('Paused; checking source fixtures');
 const cases=[];
 for(const kind of ['normal','trim','oppositeTack','penalty','luff']){
  cases.push(await browser.evaluate(`(async()=>{const {OptimistBoatMesh}=await import('/app/models/optimist-boat-mesh.ts');const model=new OptimistBoatMesh(),v=await tact2026.engine.request('modelcase','${kind}'),p=v.packet;model.update(p,p.boats[1],p.boats[2]);const row={kind:'${kind}',...model.current};if('${kind}'==='penalty'&&!row.penalty)throw Error('Engine penalty lost');model.dispose();return row;})()`));
 }
 const boundaryAfter=await browser.evaluate('tact2026.engine.request("boundary")');
 if(JSON.stringify(boundaryBefore)!==JSON.stringify(boundaryAfter))throw Error('Renderer fixtures changed the engine');
 if(cases[0].trim===cases[1].trim||Math.sign(cases[0].trim)===Math.sign(cases[2].trim))throw Error('Engine trim/tack not connected');
 await browser.evaluate(`(()=>{const scene=tact2026.scene;scene.mode='orbit';scene.controls.target.set(0,7,0);scene.camera.position.set(30,22,32);scene.controls.update();scene.cameraDirty=true;})()`);
 await delay(200);
 await writeFile(resolve(output,'race-close.png'),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 timing.sort((a,b)=>a-b);
 const result={passed:true,geometry,live,cases,frames:{medianMs:timing[150],p95Ms:timing[285],over50ms:timing.filter(v=>v>50).length,total:timing.length},boundaryUnchanged:true};
 await writeFile(resolve(output,'verification.json'),JSON.stringify(result,null,2));console.log(JSON.stringify(result));
}finally{await browser.close();}
