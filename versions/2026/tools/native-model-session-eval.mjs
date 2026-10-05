import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const out=resolve(process.argv[2]??'');
if(process.argv.length!==3)throw new Error('Usage: native-model-session-eval.mjs NEW_DIRECTORY');
await mkdir(out);const runs=[];
try{
 for(const fleet of [5,15]){
  const browser=await openBrowser(`http://127.0.0.1:8770/?manual&fleet=${fleet}`,{headless:true,gpu:true,requestTimeoutMs:60000});
  try{
   await browser.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
   const initial=await browser.evaluate('tact2026.initial'),checkpoints=[];
   for(const steps of [200,200,200,200,200,100]){
    const boundary=await browser.evaluate(`tact2026.engine.request('step',${steps})`);
    await browser.waitFor('tact2026.error||tact2026.scene.modelSequence===tact2026.latest.sequence',60000);
    const checkpoint=await browser.evaluate(`(async()=>{
      if(tact2026.error)throw new Error(tact2026.error);
      const scene=tact2026.scene,a=scene.modelPacket,b=await tact2026.engine.request('geometry');
      const matches=['positions','records','colors','boats'].every(k=>a[k].length===b[k].length&&a[k].every((v,i)=>v===b[k][i]));
      return {sequence:tact2026.latest.sequence,clock:tact2026.latest.clock,time:tact2026.latest.time,boats:a.boats.length/3,matches,
        modelBytes:a.positions.byteLength+a.records.byteLength+a.colors.byteLength+a.boats.byteLength,after:await tact2026.engine.request('boundary')};
    })()`);
    if(!checkpoint.matches||checkpoint.boats!==fleet||JSON.stringify(boundary)!==JSON.stringify(checkpoint.after))throw new Error('Post-start geometry/private-state isolation failed');
    checkpoints.push({boundary,...checkpoint});console.log(JSON.stringify({fleet,sequence:checkpoint.sequence,clock:checkpoint.clock,models:checkpoint.boats,matched:checkpoint.matches}));
   }
   if(checkpoints.at(-1).clock<=0)throw new Error('Natural native race start was not reached');
   await writeFile(resolve(out,`fleet-${fleet}.png`),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
   runs.push({fleet,initial,checkpoints});
  }finally{await browser.close();}
 }
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'1100 real native paints per fleet through a natural race start; private graphics transport agrees with full-image extraction at six boundaries; diagnostic pacing, not wall-time performance or complete races',runs},null,2));
}catch(error){await writeFile(resolve(out,'failure.txt'),error.stack);throw error;}
