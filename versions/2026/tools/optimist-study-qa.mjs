import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';import {resolve} from 'node:path';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});
const browser=await openBrowser('http://127.0.0.1:8771/tools/optimist-study.html',{headless:true,gpu:true,requestTimeoutMs:60000});
const rows=[];
const input=async(id,value)=>browser.evaluate(`(()=>{const e=document.getElementById('${id}');if(e.type==='checkbox'){if(e.checked!==${JSON.stringify(value)})e.click();}else{e.value=${JSON.stringify(value)};e.dispatchEvent(new Event('input',{bubbles:true}));}})()`);
async function frame(){
 const {model,camera}=optimistStudy,canvas=document.getElementById('view').getBoundingClientRect();
 model.group.updateMatrixWorld(true);camera.updateMatrixWorld(true);
 const V=camera.position.constructor;let maxX=0,maxY=0;
 for(const mesh of [model.hull,model.rig,model.sailor,model.window]){
  if(!mesh.visible)continue;const p=mesh.geometry.getAttribute('position');
  for(let i=0;i<p.count;i++){const v=new V().fromBufferAttribute(p,i).applyMatrix4(mesh.matrixWorld).project(camera);if(![v.x,v.y,v.z].every(Number.isFinite)||v.z< -1||v.z>1)throw Error('Invalid projected vertex');maxX=Math.max(maxX,Math.abs(v.x));maxY=Math.max(maxY,Math.abs(v.y));}
 }
 if(maxX>.901||maxY>.901||canvas.bottom>innerHeight+1)throw Error('Clipped canvas/model '+JSON.stringify({maxX,maxY,bottom:canvas.bottom,height:innerHeight}));
 return {maxX,maxY,canvas:{width:canvas.width,height:canvas.height,bottom:canvas.bottom}};
}
try{
 await browser.waitFor('globalThis.studyReady',30000);
 const result=await browser.evaluate(`(()=>{
  const {model}=optimistStudy;
  model.update({trim:25,luff:0,heel:0});const a=model.rig.geometry.getAttribute('position').array.slice(0,210*3);
  model.update({trim:-25});const b=model.rig.geometry.getAttribute('position').array;
  let mirrorError=0;for(let i=0;i<a.length;i+=3)mirrorError=Math.max(mirrorError,Math.abs(a[i]+b[i]),Math.abs(a[i+1]-b[i+1]),Math.abs(a[i+2]-b[i+2]));
  if(mirrorError>1e-6)throw Error('Camber does not mirror on tack '+mirrorError);
  const sailor=Array.from(model.sailor.geometry.getAttribute('position').array);model.update({trim:0});
  if(sailor.some((v,i)=>v!==model.sailor.geometry.getAttribute('position').array[i]))throw Error('Crew swapped sides at zero trim');
  model.update({trim:12});const attribute=model.rig.geometry.getAttribute('position'),version=attribute.version;
  model.update({heel:25,crew:false});
  if(model.sailor.visible||!model.rig.visible||model.rig.geometry.getAttribute('position').version!==version)throw Error('Crew/heel rebuilt or hid hardware');
  let extension=false;for(let i=0;i<attribute.count;i++)if(Math.hypot(attribute.getX(i)+.275,attribute.getY(i)-.46,attribute.getZ(i)-.55)<1e-5)extension=true;
  if(!extension)throw Error('Tiller extension disappeared with hidden sailor');
  model.update({heel:0,crew:true,luff:1,time:0});const cloth=model.rig.geometry.getAttribute('position').array.slice(0,210*3);model.update({time:.4});
  const displacement=Math.max(...cloth.map((v,i)=>Math.abs(v-model.rig.geometry.getAttribute('position').array[i])));
  if(displacement<.001)throw Error('Luffing did not move cloth');model.update({luff:0,time:0});
  return {mirrorError,zeroTrimRetainsCrew:true,hiddenCrewRetainsTiller:true,heelDoesNotRebuildRig:true,luffDisplacement:displacement};
 })()`);
 for(const [width,height]of [[1280,1000],[1000,700],[1920,1080]]){
  await browser.call('Emulation.setDeviceMetricsOverride',{width,height,deviceScaleFactor:1,mobile:false});await browser.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
  for(const view of ['quarter','side','bow','stern','top']){
   await browser.evaluate(`document.querySelector('[data-view="${view}"]').click()`);
   if(!await browser.evaluate(`document.querySelector('[data-view="${view}"]').getAttribute('aria-pressed')==='true'`))throw Error('Preset not selected');
   rows.push({width,height,view,...await browser.evaluate('('+frame.toString()+')()')});
  }
 }
 await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1000,deviceScaleFactor:1,mobile:false});
 for(const [name,trim,heel]of [['port',-85,-25],['starboard',85,25],['neutral',12,0]]){
  await input('trim',trim);await input('heel',heel);
  await browser.evaluate('optimistStudy.setView("quarter")');
  rows.push({name,trim,heel,...await browser.evaluate('('+frame.toString()+')()')});
  await writeFile(resolve(output,name+'.png'),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 }
 await input('crew',false);if(!await browser.evaluate('!optimistStudy.model.sailor.visible'))throw Error('Crew control failed');
 await input('crew',true);await input('penalty',true);
 if(!await browser.evaluate('optimistStudy.model.rig.geometry.getAttribute("color").getX(0)<.05'))throw Error('Penalty control failed');
 await input('penalty',false);await input('luff',true);
 await browser.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');await input('luff',false);
 const frozen=await browser.evaluate('optimistStudy.model.rig.geometry.getAttribute("position").version');
 await browser.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
 if(frozen!==await browser.evaluate('optimistStudy.model.rig.geometry.getAttribute("position").version'))throw Error('Cloth continues changing with luffing off');
 for(const link of await browser.evaluate('Array.from(document.querySelectorAll(".refs a"),a=>a.href)'))if(!await browser.evaluate(`fetch(${JSON.stringify(link)}).then(r=>r.ok)`))throw Error('Broken reference link');
 await browser.evaluate('optimistStudy.setView("quarter")');
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,result,frames:rows},null,2));console.log(JSON.stringify({passed:true,result,frameChecks:rows.length}));
}catch(error){await writeFile(resolve(output,'failure.json'),JSON.stringify({error:String(error),rows},null,2));throw error;}finally{await browser.close();}
