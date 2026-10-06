import{openBrowser}from'../../../tools/browser-session.js';
import{mkdir,writeFile}from'node:fs/promises';import{resolve}from'node:path';import{setTimeout as delay}from'node:timers/promises';
import{depthWarning}from'../app/depth-warning.ts';
const out=resolve(process.argv[2]);await mkdir(out);const checks=[];
for(const [depth,grounded,expected]of[[30,false,'clear'],[13,false,'caution'],[10,false,'danger'],[8,false,'danger'],[7,false,'danger'],[30,true,'grounded'],[undefined,false,'unknown']]){const actual=depthWarning({depth,grounded,groundingDepth:8});if(actual.level!==expected)throw Error('Depth warning '+depth);checks.push({depth,grounded,expected,actual});}
const b=await openBrowser('http://127.0.0.1:8770/?manual&fleet=5',{headless:true,gpu:true,requestTimeoutMs:60000});
async function click(id){const p=await b.evaluate(`(()=>{const r=document.getElementById('${id}').getBoundingClientRect();return {x:r.x+r.width/2,y:r.y+r.height/2};})()`);for(const type of['mousePressed','mouseReleased'])await b.call('Input.dispatchMouseEvent',{type,...p,button:'left',clickCount:1});}
async function key(code,value,windowsVirtualKeyCode){for(const type of['keyDown','keyUp'])await b.call('Input.dispatchKeyEvent',{type,code,key:value,windowsVirtualKeyCode});}
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));
 const initial=await b.evaluate('tact2026.engine.request("boundary")'),pace=await b.evaluate('tact2026.latest.pace');
 for(const id of['chase','overview','mark-lines','names']){
  await click(id);if(await b.evaluate('document.activeElement.id')!==id)throw Error('Trusted click did not focus '+id);
  const start=await b.evaluate('tact2026.latest.sequence');await key('Space',' ',32);await b.waitFor('!tact2026.paused&&tact2026.latest.sequence>'+start,10000);
  await key('Space',' ',32);await b.waitFor('tact2026.paused',10000);const before=await b.evaluate('tact2026.engine.request("boundary")');await delay(350);const after=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Space pause advanced state');checks.push({name:'Space after '+id,before,after});
 }
 await click('pause');await b.waitFor('!tact2026.paused');await key('KeyF','f',70);await b.waitFor('tact2026.paused&&!tact2026.latest.frozen&&document.getElementById("pause").textContent==="Resume"');
 const frozen=await b.evaluate('tact2026.latest.sequence');await click('pause');await b.waitFor('!tact2026.paused&&tact2026.latest.sequence>'+frozen,10000);await click('pause');await b.waitFor('tact2026.paused');checks.push({name:'F uses the same stable host pause as Space and the button'});
 const held=await b.evaluate('({boundary:null,state:{boat:tact2026.latest.boats[0],sheet:tact2026.latest.sheet,sailShape:tact2026.latest.sailShape,spinnaker:tact2026.latest.spinnaker}})');held.boundary=await b.evaluate('tact2026.engine.request("boundary")');
 for(const[code,value,vk]of[['KeyT','t',84],['KeyJ','j',74],['KeyI','i',73],['KeyO','o',79],['KeyP','p',80],['Comma',',',188],['Period','.',190],['F1','F1',112]])await key(code,value,vk);
 await click('port');await click('tack');
 await b.evaluate('tact2026.engine.send("control",84);tact2026.engine.send("control-command",32842);tact2026.engine.request("boundary")');
 const heldAfter=await b.evaluate('tact2026.engine.request("boundary")'),stateAfter=await b.evaluate('({boat:tact2026.latest.boats[0],sheet:tact2026.latest.sheet,sailShape:tact2026.latest.sailShape,spinnaker:tact2026.latest.spinnaker})');
 if(JSON.stringify(held.boundary)!==JSON.stringify(heldAfter)||JSON.stringify(held.state)!==JSON.stringify(stateAfter))throw Error('Paused sailing inputs changed held state');
 if(!await b.evaluate('document.getElementById("port").disabled&&document.getElementById("tack").disabled'))throw Error('Paused helm still enabled');checks.push({name:'Paused helm/sail input ignored at UI and worker; telemetry retained',held,heldAfter,stateAfter});
 await click('keyboard');await b.waitFor('tact2026.latest.panel');await key('Space',' ',32);await b.waitFor('!tact2026.latest.panel');if(!await b.evaluate('tact2026.paused'))throw Error('Panel dismissal changed host pause');if(await b.evaluate('tact2026.latest.pace')!==pace)throw Error('Space changed native pace');
 checks.push({name:'Space dismisses panel without changing pace/pause'});
 const beforeDepth=await b.evaluate('tact2026.engine.request("boundary")'),saved=await b.evaluate('({...tact2026.latest.boats[0]})'),depthCases=[];
 for(const depth of[30,13,10,7]){
  await b.evaluate(`Object.assign(tact2026.latest.boats[0],{depth:${depth},groundingDepth:8,grounded:false})`);await b.waitFor(`document.getElementById('depth').textContent==='${depth.toFixed(1)} ft'`);
  const result=await b.evaluate('({level:document.getElementById("depth").parentElement.dataset.level,text:document.getElementById("depth-warning").textContent,color:getComputedStyle(document.getElementById("depth")).color})');if(result.level!==depthWarning({depth,groundingDepth:8,grounded:false}).level)throw Error('HUD depth mismatch');if(depth<=10&&result.color!=='rgb(179, 37, 36)')throw Error('Danger depth not red');depthCases.push({depth,...result});
 }
 await writeFile(resolve(out,'shallow-depth.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));await b.evaluate(`Object.assign(tact2026.latest.boats[0],${JSON.stringify(saved)})`);const afterDepth=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(beforeDepth)!==JSON.stringify(afterDepth))throw Error('Depth presentation mutated master');
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Trusted Chrome toolbar clicks followed by Space, actual pause/freeze/resume/panel controls, exact paused native state, isolated red-depth HUD fixtures; no naturally sailed grounding claim.',initial,checks,depthCases,beforeDepth,afterDepth},null,2));console.log(JSON.stringify({passed:true,checks:checks.length,depthCases}));
}catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e;}finally{await b.close();}
