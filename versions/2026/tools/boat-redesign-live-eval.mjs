import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';

const output=resolve(process.argv[2]??'');
if(process.argv.length!==3)throw Error('Usage: boat-redesign-live-eval.mjs NEW_DIRECTORY');
await mkdir(output,{recursive:true});
const rows=[];
for(const [name,id] of [['optimist',1],['laser',2],['keelboat',12]]){
 const browser=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true,requestTimeoutMs:60000});
 try{
  await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:900,deviceScaleFactor:1,mobile:false});
  await browser.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
  if(await browser.evaluate('tact2026.error'))throw Error(await browser.evaluate('tact2026.error'));
  await browser.evaluate(`(()=>{const field=document.getElementById('race-boat');field.value='${id}';field.dispatchEvent(new Event('change',{bubbles:true}));})()`);
  await browser.waitFor(`document.getElementById('boat-preview').dataset.boat==='${id}'&&document.getElementById('boat-preview').dataset.state==='ready'`,30000);
  await browser.evaluate('document.getElementById("race-form").requestSubmit()');
  await browser.waitFor(`globalThis.tact2026?.latest?.configuration?.selector===${id}&&tact2026.scene.hasModels&&document.getElementById('starter').hidden||globalThis.tact2026?.error`,60000);
  if(await browser.evaluate('tact2026.error'))throw Error(await browser.evaluate('tact2026.error'));
  const row=await browser.evaluate(`(()=>{const model=tact2026.scene.models.get(1);return {classId:tact2026.latest.configuration.selector,modelTriangles:model.geometry.getAttribute('position').count/3,modelSequence:tact2026.scene.modelSequence,boats:tact2026.latest.boats.length,renderer:tact2026.scene.actualBackend}})()`);
  if(row.classId!==id||row.modelTriangles<100||row.boats<2)throw Error('Incomplete live model '+JSON.stringify(row));
  await writeFile(resolve(output,`${name}-live.png`),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
  rows.push({name,...row});
 }finally{await browser.close();}
}
await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,rows},null,2));
console.log(JSON.stringify({passed:true,rows}));
