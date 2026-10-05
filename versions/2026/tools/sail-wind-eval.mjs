import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
if(process.argv.length!==3)throw new Error('Usage: sail-wind-eval.mjs NEW_DIRECTORY');
const out=resolve(process.argv[2]);await mkdir(out);
const b=await openBrowser('http://127.0.0.1:8770/?manual',{headless:true,gpu:true});
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});await b.waitFor('globalThis.tact2026?.ready',60000);
 const before=await b.evaluate('tact2026.engine.request("boundary")');
 const result=await b.evaluate(`(()=>{
 const scene=tact2026.scene,model=scene.models.get(1),boat=tact2026.latest.boats[0],p=model.geometry.getAttribute('position'),c=model.geometry.getAttribute('color');
 const wind={...boat,heading:boat.windFrom,luff:90};model.interpolate(1,wind,0);const a=Array.from(p.array);model.interpolate(1,wind,.8);const z=Array.from(p.array);
 let moved=0,coloredMovement=0,mastMovement=0;for(let i=0;i<p.count;i++){const distance=Math.hypot(...[0,1,2].map(k=>z[i*3+k]-a[i*3+k]));moved=Math.max(moved,distance);
 const rgb=[c.getX(i),c.getY(i),c.getZ(i)],black=rgb.every(v=>v<.001),white=rgb.every(v=>v>.99);if(!black&&!white)coloredMovement=Math.max(coloredMovement,distance);
 const v=a.slice(i*3,i*3+3).map((v,k)=>v-model.pivot.getComponent(k)),dot=v.reduce((sum,v,k)=>sum+v*model.mast.getComponent(k),0),radial=Math.hypot(...v.map((v,k)=>v-dot*model.mast.getComponent(k)));if(radial<.02)mastMovement=Math.max(mastMovement,distance);}
 const loaded={...boat,windFrom:boat.heading+60,luff:0};model.interpolate(1,loaded,0);const l=Array.from(p.array);model.interpolate(1,loaded,.8);const loadedChanged=l.some((v,i)=>v!==p.array[i]);
 return {moved,coloredMovement,mastMovement,loadedChanged,boat};})()`);
 if(result.moved<.03||result.coloredMovement>1e-6||result.mastMovement>1e-6||result.loadedChanged)throw Error('Sail motion/isolation failed '+JSON.stringify(result));
 for(const time of [0,.4,.8]){
  await b.evaluate(`(()=>{const scene=tact2026.scene,value={...tact2026.latest,time:${time},boats:tact2026.latest.boats.map(b=>b.id===1?{...b,heading:b.windFrom,luff:90}:b)};scene.latest=value;scene.previous=value;scene.setPaused(true);for(const [id,m]of scene.models)m.group.visible=id===1;scene.camera.position.set(48,32,42);scene.controls.target.set(0,15,0);scene.controls.update()})()`);
  await b.evaluate('new Promise(resolve=>requestAnimationFrame(()=>requestAnimationFrame(resolve)))');await writeFile(resolve(out,'headwind-'+time+'.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 }
 const after=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Presentation wind animation mutated simulation');
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Actual native mesh at isolated headwind display fixtures; loaded shape fixed, colored hull/crew and mast anchored, complete native boundary unchanged; not a new physical sail model',result,before,after},null,2));console.log(JSON.stringify(result));
}catch(error){await writeFile(resolve(out,'failure.txt'),error.stack);throw error;}finally{await b.close()}
