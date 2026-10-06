import{readFile,mkdir,writeFile}from'node:fs/promises';import{resolve}from'node:path';import assert from'node:assert/strict';
import{separation,area}from'../app/contact-geometry.ts';import{openBrowser}from'../../../tools/browser-session.js';
const out=resolve(process.argv[2]);await mkdir(out);const catalog=JSON.parse(await readFile(new URL('../app/generated/contact-shapes.json',import.meta.url),'utf8')),rows=[];
for(const[id,parts]of Object.entries(catalog.boats)){assert.ok(parts.length);for(const p of parts){assert.ok(area(p.points)>.01);assert.ok(p.points.every(v=>Number.isFinite(v.x)&&Number.isFinite(v.y)));}if([10,11,17,23].includes(Number(id)))assert.ok(parts.length>1);}
const b=await openBrowser('http://127.0.0.1:8770/?manual&fleet=5&hitboxes',{headless:true,gpu:true,requestTimeoutMs:60000});
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 for(let selector=1;selector<=27;selector++){
  await b.evaluate(`document.getElementById('race-boat').value='${selector}';document.getElementById('race-boat').dispatchEvent(new Event('change'))`);
  await b.waitFor(`tact2026.ready&&tact2026.latest.configuration.selector===${selector}||tact2026.error`,60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));
  const before=await b.evaluate('tact2026.engine.request("boundary")');
  const live=await b.evaluate(`(()=>{const p=tact2026.scene.modelPacket,v=[];for(let at=p.boats[1];at<p.boats[2];){const op=p.records[at],part=p.records[at+1],count=p.records[at+6];if(op===1&&part===1)for(const i of p.records.slice(at+7,at+7+count))v.push({x:p.positions[i*3]/2048*4,y:p.positions[i*3+2]/2048*4});at+=7+count+(op===3?2:0);}return {points:v,scale:tact2026.scene.models.get(1).group.scale.x,overlay:tact2026.scene.contactOverlay.group.visible};})()`);
  let outside=0;for(const p of live.points)outside=Math.max(outside,separation({key:'hull',parts:catalog.boats[selector],pose:{x:0,y:0,heading:0},radius:50},{key:'point',parts:[{kind:'circle',radius:0}],pose:{...p,heading:0},radius:0}).gap);
  if(outside>.1)throw Error('Live hull outside contact catalogue '+selector+': '+outside);assert.equal(live.scale,catalog.scale);assert.ok(live.overlay);
  const after=await b.evaluate('tact2026.engine.request("boundary")');assert.deepEqual(after,before);rows.push({selector,points:live.points.length,outside,components:catalog.boats[selector].length});
  if([1,11,12,15].includes(selector)){await b.evaluate('tact2026.camera("overview")');await writeFile(resolve(out,'shape-'+selector+'.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));}
  console.log(JSON.stringify(rows.at(-1)));
 }
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,rows,scope:'All 27 live initial native hull model packets against contact catalogue, compound catamarans, actual renderer scale and overlay; entire held image/RNG/shore boundary unchanged. Not contact physics acceptance.'},null,2));
}catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e;}finally{await b.close();}
