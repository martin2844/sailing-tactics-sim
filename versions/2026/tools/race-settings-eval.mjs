import {openBrowser} from '../../../tools/browser-session.js';
import {referenceSession,closeReferenceServer} from './reference-session.mjs';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
if(process.argv.length!==3)throw Error('Usage: race-settings-eval.mjs NEW_DIRECTORY');const out=resolve(process.argv[2]);await mkdir(out);const checks=[];let candidate;
try{
 candidate=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true,requestTimeoutMs:60000});
 await candidate.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 // Independent menu IDs from the preserved controller, not the UI helper.
 for(const fleet of [5,15])for(const [course,courseCommand]of [[1,32816],[3,32818],[5,32820]])for(const [wind,windCommand]of [[1,32812],[2,32813],[3,32814]]){
  const commands=[32799,courseCommand,32789,fleet===5?32806:32808,32909];if(wind!==2)commands.push(windCommand);
  const ref=await referenceSession({fleet,headless:true,setupCommands:commands});
  try{
   await ref.command(32850);
   await candidate.evaluate(`(()=>{document.getElementById('race-fleet').value='${fleet}';document.getElementById('race-course').value='${course}';document.getElementById('race-wind').value='${wind}';document.getElementById('race-wind').dispatchEvent(new Event('change'));})()`);
   await candidate.waitFor('tact2026.ready||tact2026.error',60000);const error=await candidate.evaluate('tact2026.error');if(error)throw Error(error);
   const snapshots=[];
   async function compare(label){const original={...await ref.snapshot(),shore:await ref.browser.evaluate('tact.state.options.shoreStack.snapshot()')},worker=await candidate.evaluate('tact2026.engine.request("boundary")');for(const key of ['frame','time','clock','rngState','memorySha256','shore'])if(JSON.stringify(original[key])!==JSON.stringify(worker[key]))throw Error(`Mismatch ${fleet}/${course}/${wind} ${label}: ${key}`);snapshots.push({label,original,worker});}
   await compare('initial');for(let n=0;n<8;n++){await ref.step('selected race '+n);await candidate.evaluate('tact2026.engine.request("step",1)');}await compare('eight real paints');
   const configuration=await candidate.evaluate('tact2026.latest.configuration');if(configuration.fleet!==fleet||configuration.course!==course||configuration.wind!==wind)throw Error('Configuration readback differs');
   checks.push({fleet,course,wind,commands,configuration,snapshots});console.log(JSON.stringify({passed:true,fleet,course,wind}));
  }finally{await ref.close()}
 }
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'All 18 supported 5/15 fleet, three-course, three-wind combinations; initial and eight-paint whole native image/time/RNG/shore matches against original menu handlers',checks},null,2));
}catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e}finally{await candidate?.close();await closeReferenceServer()}
