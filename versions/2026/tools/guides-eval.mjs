import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const out=resolve(process.argv[2]);await mkdir(out);const rows=[];
for(const fleet of [5,30]){
 const b=await openBrowser(`http://127.0.0.1:8770/?manual&fleet=${fleet}`,{headless:true,gpu:true,requestTimeoutMs:60000});
 try{
  await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
  if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));
  const originalCases=await b.evaluate('tact2026.engine.request("guidecase")');
  if(JSON.stringify(originalCases.before)!==JSON.stringify(originalCases.after))throw Error('Guide extraction changed the master image/RNG');
  const initial=await b.evaluate('({course:tact2026.latest.course,heading:tact2026.latest.boats[0].heading,mode:tact2026.latest.configuration.mode})');
  if(initial.mode!==0||initial.course.guides.length)throw Error('Demo or prestart rays');
  await b.evaluate('tact2026.engine.send("key",76)');await b.waitFor('tact2026.latest.course.showLaylines');
  await b.waitFor('document.getElementById("heading").textContent===tact2026.latest.course.headingReference+"°"');
  await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
  const L=await b.evaluate('({course:tact2026.latest.course,reference:document.getElementById("heading").textContent})');
  if(L.course.guides.length||L.reference!==L.course.headingReference+'°'||L.course.headingReference===initial.heading)throw Error('L did not restore the native heading reference');
  await b.evaluate('tact2026.camera("overview");new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
  await writeFile(resolve(out,`prestart-${fleet}.png`),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
  rows.push({fleet,initial,L,originalCases});
 }catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e;}finally{await b.close();}
}
await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Original full-chart GDI oracle against isolated guide extraction; 15 private conditions per fleet (5/30), real L input and prestart state. Entire authoritative memory/RNG/frame/clock/shore unchanged by extraction.',rows},null,2));
console.log(JSON.stringify({passed:true,fleets:rows.map(r=>({fleet:r.fleet,cases:r.originalCases.cases.length}))}));
