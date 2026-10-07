import {openBrowser} from '../../../tools/browser-session.js';import {mkdir,writeFile} from 'node:fs/promises';import {resolve} from 'node:path';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});const rows=[];
for(const fleet of[5,15,30]){
 const b=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true,requestTimeoutMs:60000});
 try{
  await b.waitFor('globalThis.tact2026?.ready',60000);
  await b.evaluate(`document.getElementById('race-fleet').value='${fleet}';document.getElementById('race-fleet').dispatchEvent(new Event('change'));document.getElementById('race-form').requestSubmit()`);
  await b.waitFor(`tact2026.ready&&document.getElementById('starter').hidden&&tact2026.latest.boats.length===${fleet}`,60000);
  await b.evaluate('tact2026.engine.send("pause",true)');await b.waitFor('tact2026.paused');
  await b.evaluate('tact2026.engine.request("step",30)');
  const report=await b.evaluate('tact2026.engine.request("profile-steps",200)');rows.push({fleet,report});console.log(JSON.stringify({fleet,...report}));
 }finally{await b.close()}
}
await writeFile(resolve(output,'phases.json'),JSON.stringify({scope:'200 paused diagnostic numerical steps in each actual Chrome worker; per-phase timer wrappers add overhead but no display frames are used for scheduling.',rows},null,2));
