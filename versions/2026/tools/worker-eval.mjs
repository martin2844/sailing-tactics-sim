import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {openBrowser} from '../../../tools/browser-session.js';
import {referenceSession,closeReferenceServer} from './reference-session.mjs';
const out=resolve(process.argv[2]??'');if(process.argv.length!==3)throw new Error('Usage: worker-eval.mjs NEW_DIRECTORY (preview :8770)');await mkdir(out);
const runs=[];
try{
 for(const fleet of [5,15]){
  const ref=await referenceSession({fleet,headless:process.env.TACT_HEADLESS==='1'});let candidate;
  try{
   await ref.command(32850);
   candidate=await openBrowser(`http://127.0.0.1:8770/spike/?manual&fleet=${fleet}`,{headless:process.env.TACT_HEADLESS==='1',gpu:true,width:1280,height:1051,requestTimeoutMs:60000});
   await candidate.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});
   await candidate.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
   const error=await candidate.evaluate('tact2026.error');if(error)throw new Error(error);
   const boundaries=[],costs=[];
   async function compare(label){const original={...await ref.snapshot(),shore:await ref.browser.evaluate('tact.state.options.shoreStack.snapshot()')};const worker=await candidate.evaluate('tact2026.engine.request("boundary")');for(const k of ['frame','time','clock','rngState','memorySha256','shore'])if(JSON.stringify(original[k])!==JSON.stringify(worker[k]))throw new Error(`Mismatch fleet ${fleet}, ${label}, ${k}`);boundaries.push({label,original,worker,matched:true});}
   await compare('initial');
   for(let n=0;n<32;n++){
    const command=({8:32842,16:32841,24:32846})[n];
    if(command){await ref.command(command);await candidate.evaluate(`tact2026.engine.send('command',${command})`);}
    await ref.step('worker pairing '+n);
    await candidate.evaluate('tact2026.engine.request("step",1)');
    const snapshot=await candidate.evaluate('(()=>{const {nativeVisuals,...state}=tact2026.latest;return {workMs:state.workMs,bytes:new TextEncoder().encode(JSON.stringify(state)).byteLength+nativeVisuals.geometry.byteLength+nativeVisuals.styles.byteLength+nativeVisuals.boats.byteLength};})()');costs.push(snapshot);
    if((n+1)%8===0)await compare('step '+(n+1));
   }
   runs.push({fleet,browser:candidate.metadata,boundaries,costs,referenceModules:await ref.modules()});
  }finally{await candidate?.close();await ref.close();}
 }
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'32 real paints per 5/15 boats; initial + four exact whole-image/RNG/shore boundaries; native port/starboard/tack commands; worker host Canvas retained',runs},null,2));
 console.log(JSON.stringify(runs.map(r=>({fleet:r.fleet,matched:r.boundaries.length,maxWorkMs:Math.max(...r.costs.map(c=>c.workMs)),maxSnapshotBytes:Math.max(...r.costs.map(c=>c.bytes))}))));
}finally{await closeReferenceServer();}
