import{openBrowser}from'../../../tools/browser-session.js';import{mkdir,writeFile}from'node:fs/promises';import{resolve}from'node:path';
const out=resolve(process.argv[2]);await mkdir(out);const b=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true});const rows=[];
try{await b.waitFor('globalThis.tact2026?.ready',60000);for(let boat=1;boat<=27;boat++){
 try{await b.evaluate(`document.getElementById('race-boat').value='${boat}';document.getElementById('race-boat').dispatchEvent(new Event('change'))`);await b.waitFor('tact2026.ready||tact2026.error',60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));
 const actual=await b.evaluate(`(async()=>{const captures=await tact2026.engine.request('lift',1),parts={};for(const p of captures[0].primitives){const key=p.part?.toString(16)??'none';parts[key]??={};parts[key][p.op]=(parts[key][p.op]??0)+1;}return {configuration:tact2026.latest.configuration,parts,positions:tact2026.scene.modelPacket.positions.length,records:tact2026.scene.modelPacket.records.length,models:tact2026.scene.models.size,rigs:Array.from(tact2026.scene.models).map(([id,m])=>({id,hasRig:m.hasRig,sailHeight:m.sailHeight}))}})()`);rows.push({boat,...actual});console.log(JSON.stringify(rows.at(-1)));await writeFile(resolve(out,'progress.json'),JSON.stringify(rows,null,2));
 }catch(e){rows.push({boat,error:String(e)});console.log(JSON.stringify(rows.at(-1)));await writeFile(resolve(out,'progress.json'),JSON.stringify(rows,null,2));}
 }
 await writeFile(resolve(out,'verification.json'),JSON.stringify({rows,scope:'Diagnostic native geometry-family probe, not acceptance'},null,2));
}catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e}finally{await b.close()}
