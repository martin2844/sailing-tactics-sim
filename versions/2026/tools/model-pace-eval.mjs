import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const out=resolve(process.argv[2]);await mkdir(out,{recursive:true});
const browser=await openBrowser('http://127.0.0.1:8770/?manual&fleet=30',{headless:true,gpu:true,requestTimeoutMs:60000}),checks=[];
try{
 await browser.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});
 await browser.waitFor('globalThis.tact2026?.ready',60000);
 await browser.evaluate('tact2026.engine.send("playback",{mode:"clock",rate:32})');await browser.waitFor('tact2026.latest.pace===15');
 for(let n=0;n<2;n++)await browser.evaluate('tact2026.engine.request("step",200)');
 const base=await browser.evaluate(`(async()=>{globalThis.referenceModel=await tact2026.engine.request('geometry');return{clock:tact2026.latest.clock,boats:referenceModel.boats.length/3}})()`);
 for(const rate of[1,2,4,8,16,24,28,32]){
  await browser.evaluate(`tact2026.engine.send('playback',{mode:'clock',rate:${rate}})`);await browser.waitFor(`tact2026.latest.playback.active.rate===${rate}`);
  const result=await browser.evaluate(`(async()=>{const before=await tact2026.engine.request('boundary'),p=await tact2026.engine.request('geometry'),after=await tact2026.engine.request('boundary');return{unchanged:JSON.stringify(before)===JSON.stringify(after),exact:['positions','records','colors','boats'].every(k=>p[k].length===referenceModel[k].length&&p[k].every((v,i)=>v===referenceModel[k][i])),pace:tact2026.latest.pace,time:after.time}})()`);
  if(!result.unchanged||!result.exact)throw Error('Playback leaks into boat models '+JSON.stringify({rate,result}));checks.push({rate,...result});
 }
 await browser.evaluate('tact2026.engine.send("toggle-pace")');await browser.waitFor('tact2026.latest.pace===6');
 const space=await browser.evaluate(`(async()=>{const p=await tact2026.engine.request('geometry');return{selected:tact2026.latest.playback.selected.rate,exact:['positions','records','colors','boats'].every(k=>p[k].length===referenceModel[k].length&&p[k].every((v,i)=>v===referenceModel[k][i]))}})()`);
 if(!space.exact||space.selected!==32)throw Error('Precision toggle changes boat geometry');
 await browser.evaluate(`{const s=tact2026.scene,player=tact2026.latest.boats[0],boat=tact2026.latest.boats[1],x=boat.x-player.x,z=boat.y-player.y;s.mode='orbit';s.camera.position.set(x+58,36,z+52);s.controls.target.set(x,17,z);s.controls.update();s.receiveModels({generation:tact2026.latest.generation,sequence:tact2026.latest.sequence,packet:referenceModel});}`);
 for(const [name,offset]of[['starboard',58],['port',-58]]){
  await browser.evaluate(`{const s=tact2026.scene,t=s.controls.target;s.camera.position.set(t.x+${offset},36,t.z+52);s.controls.update();}new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))`);
  await writeFile(resolve(out,name+'.png'),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 }
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,base,checks,space,scope:'Exact packet equality across all eight modern multipliers and Space, on the same post-start30-boat physical state. Each extraction retains the whole master image/RNG boundary. Actual Three renderer inspected from both sides. The diagnostic normalizes only the disposable drawing copy.'},null,2));console.log(JSON.stringify({passed:true,checks:checks.length,space}));
}finally{await browser.close()}
