import{openBrowser}from'../../../tools/browser-session.js';
import{mkdir,writeFile}from'node:fs/promises';import{resolve}from'node:path';
import{createHash}from'node:crypto';
const out=resolve(process.argv[2]);await mkdir(out);const rows=[];
for(const fleet of[5,15]){
 const url=`http://127.0.0.1:8770/?manual&fleet=${fleet}`,control=await openBrowser(url,{headless:true,gpu:true});let candidate;
 try{
  candidate=await openBrowser(url,{headless:true,gpu:true});
  for(const b of[control,candidate]){await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));}
  const initial=await control.evaluate('tact2026.engine.request("boundary")'),before=await candidate.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(initial)!==JSON.stringify(before))throw Error('Initial mismatch');
  const visualHash=async()=>createHash('sha256').update(JSON.stringify(await candidate.evaluate('tact2026.engine.request("model")'))).digest('hex');
  const visualsBefore=await visualHash();
  const cases=await candidate.evaluate('tact2026.engine.request("guidecase")');if(JSON.stringify(cases.before)!==JSON.stringify(cases.after))throw Error('Diagnostic mutated master');const boundaries=[];
  const visualsAfter=await visualHash();if(visualsBefore!==visualsAfter)throw Error('Private oracle polluted the native graphics observer');
  for(const steps of[1,7,24,200]){
   const [a,b]=await Promise.all([control.evaluate(`tact2026.engine.request('step',${steps})`),candidate.evaluate(`tact2026.engine.request('step',${steps})`)]);
   if(JSON.stringify(a)!==JSON.stringify(b))throw Error('Diagnostic changed future master paints: '+JSON.stringify({fleet,steps,a,b}));boundaries.push({steps,control:a,afterDiagnostic:b,matched:true});
  }
  rows.push({fleet,before,visualsBefore,visualsAfter,boundaries});
 }catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e;}finally{await candidate?.close();await control.close();}
}
await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Private original guide oracle leaves future simulation untouched: exact whole memory/RNG/frame/clock/shore against a second untouched worker after 1,8,32,232 real paints for 5/15 boats. No complete-race claim.',rows},null,2));console.log(JSON.stringify({passed:true,fleets:rows.length,boundaries:rows.reduce((n,r)=>n+r.boundaries.length,0)}));
