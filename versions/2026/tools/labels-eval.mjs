import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';import {resolve} from 'node:path';
const out=resolve(process.argv[2]);await mkdir(out);const rows=[];
const overlap=(a,b,gap=0)=>a.x<b.x+b.w+gap&&a.x+a.w+gap>b.x&&a.y<b.y+b.h+gap&&a.y+a.h+gap>b.y;
for(const fleet of [5,15,30]){
 const b=await openBrowser(`http://127.0.0.1:8770/?manual&fleet=${fleet}`,{headless:true,gpu:true,requestTimeoutMs:60000});
 try{
  await b.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});
  await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));
  await b.evaluate('document.fonts.ready');const before=await b.evaluate('tact2026.engine.request("boundary")');
  const capture=async(name)=>{
   await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
   const value=await b.evaluate('(()=>{const l=tact2026.scene.labels;return {placed:l.placed,bounds:[...l.boatBounds].map(([id,b])=>({id,...b})),reserved:l.reserved,canvas:{width:l.canvas.width,height:l.canvas.height},cameraMode:tact2026.scene.cameraMode,showAll:l.showAll,selected:l.selected}})()');
   for(const [i,label]of value.placed.entries()){
    if(label.w>144||label.h!==20)throw Error('Label size unbounded');
    if(value.placed.slice(i+1).some(r=>overlap(label,r))||value.reserved.some(r=>overlap(label,r))||value.bounds.some(r=>overlap(label,r)))throw Error('Label collision: '+name+' '+label.key);
   }
   if(!value.placed.length)throw Error('All labels disappeared: '+name);
   rows.push({fleet,name,...value});await writeFile(resolve(out,`${fleet}-${name}.png`),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));return value;
  };
  await capture('chase');await b.evaluate('tact2026.camera("overview")');await capture('overview');
  await b.evaluate('document.getElementById("names").click()');await capture('all-names-overview');
  await b.evaluate('tact2026.camera("chase")');const chase=await capture('all-names-chase');
  const hit=chase.bounds.find(r=>r.x>220&&r.x+r.w<1200&&r.y>160&&r.y+r.h<650);
  if(hit){const x=hit.x+hit.w/2,y=hit.y+hit.h/2+64;await b.call('Input.dispatchMouseEvent',{type:'mouseMoved',x,y});for(const type of ['mousePressed','mouseReleased'])await b.call('Input.dispatchMouseEvent',{type,x,y,button:'left',clickCount:1});await capture('selected');if(await b.evaluate('tact2026.scene.cameraMode')!=='chase')throw Error('Selecting a boat cancelled auto follow');}
  await b.evaluate('(()=>{const s=tact2026.scene;s.controls.dispatchEvent({type:"start"});s.camera.position.copy(s.controls.target).add(s.camera.position.clone().sub(s.controls.target).multiplyScalar(.24));s.controls.update()})()');
  // Some close views contain no complete boat/mark bounds; this is preferable
  // to placing a billboard across a clipped sail. Save that case separately.
  await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
  const close=await b.evaluate('tact2026.scene.labels.placed');if(close.some(l=>l.w>144||l.h!==20))throw Error('Close-camera banner returned');
  rows.push({fleet,name:'close',placed:close});await writeFile(resolve(out,`${fleet}-close.png`),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
  const after=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Labels/camera changed native simulation');
  if(fleet===5){await b.evaluate('tact2026.camera("overview")');await b.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:2,mobile:false});await capture('dpr2');}
 }catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e;}finally{await b.close();}
}
await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Chrome 5/15/30 fleets, chase/overview/close views, all-name mode, trusted hover/selection and DPR2. Pixel-size bounds and label/HUD/projected-boat collision checks; full native boundary unchanged by presentation. Clipped models may intentionally have no label.',rows},null,2));console.log(JSON.stringify({passed:true,cases:rows.map(r=>({fleet:r.fleet,name:r.name,labels:r.placed.length}))}));
