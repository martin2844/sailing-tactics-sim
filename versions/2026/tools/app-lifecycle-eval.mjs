import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const output=resolve(process.argv[2]??'');if(process.argv.length!==3)throw new Error('Usage: app-lifecycle-eval.mjs NEW_DIRECTORY');await mkdir(output);
const b=await openBrowser('http://127.0.0.1:8770/?manual&fleet=5',{headless:false,gpu:true,width:1280,height:1051,requestTimeoutMs:60000});
const checks=[];
const healthy=async()=>{await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);const error=await b.evaluate('tact2026.error');if(error)throw new Error(error);};
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});await healthy();
 checks.push({name:'five boat initial hash',initial:await b.evaluate('tact2026.initial')});
 // Actual rendered RGBA hashes, gathered synchronously after completed renders.
 // Deliberate readback is isolated from all cadence/latency measurements.
 await b.evaluate('tact2026.engine.send("pause",false)');await b.waitFor('tact2026.latest.sequence>=70',30000);
 const pixels=await b.evaluate(`new Promise((resolve,reject)=>{const scene=tact2026.scene,original=scene.render.bind(scene),canvas=document.getElementById('scene'),copy=new OffscreenCanvas(canvas.width,canvas.height),ctx=copy.getContext('2d',{willReadFrequently:true}),images=[];let last;
 scene.render=now=>{try{original(now);const sample=scene.samples.at(-1);if(sample&&sample!==last&&sample.changed){last=sample;ctx.drawImage(canvas,0,0);const bytes=ctx.getImageData(0,0,copy.width,copy.height).data;images.push({sequence:sample.sequence,alpha:sample.alpha,bytes:bytes.slice()});if(images.length===8){scene.render=original;Promise.all(images.map(async image=>({sequence:image.sequence,alpha:image.alpha,sha256:[...new Uint8Array(await crypto.subtle.digest('SHA-256',image.bytes))].map(v=>v.toString(16).padStart(2,'0')).join('')}))).then(resolve,reject);}}}catch(e){scene.render=original;reject(e);}};})`);
 if(new Set(pixels.map(p=>p.sha256)).size<6)throw new Error('Rendered moving frames did not change pixels');checks.push({name:'actual rendered RGBA changes',pixels});
 await b.evaluate('tact2026.engine.send("pause",true)');await b.waitFor('tact2026.paused',10000);
 const before=await b.evaluate('tact2026.engine.request("boundary")');await b.evaluate('tact2026.camera("overview")');await b.waitFor('tact2026.responses.length>=1',10000);const after=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw new Error('Paused camera mutated native state');checks.push({name:'paused camera image/RNG/shore unchanged',before,after});
 // Resume and pause the host scheduler repeatedly; stale queued messages must not
 // advance a subsequently paused worker. This uses real native paints.
 for(let i=0;i<3;i++){await b.evaluate('tact2026.engine.send("pause",false)');await b.waitFor('!tact2026.paused',10000);await b.evaluate('tact2026.engine.send("pause",true)');await b.waitFor('tact2026.paused',10000);const a=await b.evaluate('tact2026.engine.request("boundary")');await b.evaluate('tact2026.camera("chase")');const z=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(a)!==JSON.stringify(z))throw new Error('Paused scheduler advanced');checks.push({name:'pause cycle '+i,boundary:z});}
 await b.evaluate('(()=>{const select=document.getElementById("fleet");select.value="15";select.dispatchEvent(new Event("change"));})()');await healthy();await b.waitFor('tact2026.latest.boats.length===15',10000);checks.push({name:'fleet restart fifteen',initial:await b.evaluate('tact2026.initial')});
 await b.evaluate('document.getElementById("names").click()');if(!(await b.evaluate('tact2026.scene.labels.showAll')))throw Error('All names did not enable');
 await b.evaluate('tact2026.scene.renderer.getContext().getExtension("WEBGL_lose_context").loseContext()');await b.waitFor('tact2026.error',10000);
 if(!(await b.evaluate('document.getElementById("port").disabled')))throw new Error('Context loss left helm enabled');checks.push({name:'context loss stopped worker and disabled controls',error:await b.evaluate('tact2026.error')});
 await b.evaluate('document.getElementById("restart").click()');await healthy();checks.push({name:'context loss restart recovered',initial:await b.evaluate('tact2026.initial')});
 if(!(await b.evaluate('tact2026.scene.labels.showAll&&document.getElementById("names").getAttribute("aria-pressed")==="true"&&document.querySelectorAll(".world-labels").length===1')))throw Error('Label toggle or canvas ownership lost during context recovery');checks.push({name:'all-names toggle and single annotation canvas survive context recovery'});
 await b.evaluate('tact2026.engine.request("step",8)');await writeFile(resolve(output,'scene.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,browser:b.metadata,checks},null,2));console.log(JSON.stringify(checks.map(c=>c.name)));
}catch(error){await writeFile(resolve(output,'failure.txt'),error.stack);await writeFile(resolve(output,'failure-checks.json'),JSON.stringify({checks,state:await b.evaluate('({ready:tact2026.ready,error:tact2026.error,paused:tact2026.paused,hidden:document.hidden,sequence:tact2026.latest?.sequence,samples:tact2026.scene.samples.length,last:tact2026.scene.samples.at(-1)})').catch(e=>({inspectionError:String(e)}))},null,2));throw error;}finally{await b.close();}
