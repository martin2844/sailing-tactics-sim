import assert from 'node:assert/strict';
import { readFile,mkdir,writeFile } from 'node:fs/promises';
import { setTimeout as pause } from 'node:timers/promises';
import { openBrowser } from './browser-session.js';

const output=new URL('../analysis/play-breadth-browser-check/',import.meta.url);
await mkdir(output,{recursive:true});
const source=await readFile(new URL('../src/engine/menu-controller.js',import.meta.url),'utf8');
const pauseSource=await readFile(new URL('../src/render/tutorials.js',import.meta.url),'utf8');
const menu=JSON.parse(await readFile(new URL('../assets/ui/menus.json',import.meta.url),'utf8')).find(row=>row.resource_id===128);
const dialogs=JSON.parse(await readFile(new URL('../assets/ui/dialogs.json',import.meta.url),'utf8'));
const labels=new Map();
function collect(items,path=[]){for(const item of items){if(item.items)collect(item.items,[...path,item.text.replace(/&/g,'')]);else if(item.command_id)labels.set(item.command_id,[...path,item.text.replace(/&/g,'')].join(' / '));}}
collect(menu.items);
const order=pauseSource.match(/const order = \[([^\]]+)\]/)[1].split(',').map(Number);
const handlers=[...source.matchAll(/\[(\d+), \(memory, options, r, w, f, invalidate\) => \{([\s\S]*?)\n  \}\]/g)].map(match=>({command:Number(match[1]),body:match[2]}));
const literal=(body,address)=>[...body.matchAll(new RegExp(`w\\(${address}, i32\\((0x[0-9a-f]+|[0-9]+)\\)\\)`,'g'))].map(match=>Number(match[1]));
const tutorials=handlers.flatMap(row=>literal(row.body,'0x4ac980').filter(value=>order.includes(value)).slice(0,1).map(selector=>({...row,selector,label:labels.get(row.command)})));
const boats=handlers.flatMap(row=>literal(row.body,'0x491144').filter(value=>value>=1&&value<=15).slice(0,1).map(selector=>({...row,selector,label:labels.get(row.command)})));
assert.equal(new Set(tutorials.map(row=>row.selector)).size,36);
assert.deepEqual([...new Set(boats.map(row=>row.selector))].sort((a,b)=>a-b),Array.from({length:15},(_,index)=>index+1));
const base=process.env.TACT_URL??'http://127.0.0.1:8765';
const supplement=process.argv.includes('--supplement');
const previous=supplement?JSON.parse(await readFile(new URL('report.json',output),'utf8')):null;
const browser=await openBrowser(`${base}/play.html`),checks=previous?.checks??[],failures=previous?.failures??[],gates=(previous?.gates??[]).filter(row=>!row.name.startsWith('mobile tutorial'));
let navigation=0;
const inspect=()=>browser.evaluate(`({ready:tact.state.ready,frames:tact.state.frames,error:tact.state.error,application:tact.state.memory.readI32(0x4ac8f8),tutorial:tact.state.memory.readI32(0x4ac980),selector:tact.state.memory.readI32(0x491144),boatClass:tact.state.memory.readI32(0x491188),course:tact.state.memory.readI32(0x491194),weather:tact.state.memory.readI32(0x4a4958),humans:tact.state.memory.readI32(0x491140),view:tact.state.memory.readI32(0x4a4e8c),time:tact.state.memory.readF64(0x4ac1f8),modal:tact.state.modal})`);
const screenshot=async name=>{const result=await browser.call('Page.captureScreenshot',{format:'png',captureBeyondViewport:true});await writeFile(new URL(name,output),Buffer.from(result.data,'base64'));};
const key=async(code,key,keyCode)=>{await browser.evaluate('document.getElementById("race").focus()');for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code,key,windowsVirtualKeyCode:keyCode,nativeVirtualKeyCode:keyCode});};
const wait=async expression=>{await browser.waitFor(`tact.state.error||(${expression})`);assert.equal(await browser.evaluate('tact.state.error'),null);};
async function clickCommand(command){
  if(!await browser.evaluate(`Boolean(document.querySelector('[data-command="${command}"]:not(:disabled)'))`)){
    const error=new Error(`Original command${command} is disabled for this preserved demo/state`);error.originalGate=true;error.command=command;throw error;
  }
  await browser.evaluate(`document.querySelector('[data-command="${command}"]').click()`);
  assert.equal(await browser.evaluate('tact.state.error'),null);
}
async function fresh(){
  await browser.call('Page.navigate',{url:`${base}/play.html?breadth=${++navigation}`});
  await browser.waitFor(`location.search==='?breadth=${navigation}'&&globalThis.tact?.state.ready`);
  await wait('tact.state.frames>0');
  const row=await inspect();assert.equal(row.application,0);return row;
}
async function startRace(){
  await key('Space',' ',32);await wait('tact.state.memory.readI32(0x4ac9cc)===1');
  await key('Space',' ',32);await wait('tact.state.memory.readI32(0x4ac8f8)===2');
  await key('Space',' ',32);await wait('tact.state.memory.readI32(0x4aa980)===0');
  const frames=await browser.evaluate('tact.state.frames');await wait(`tact.state.frames>${frames}`);
}
async function check(name,operation){
  const old=checks.findIndex(row=>row.name===name);if(old>=0)checks.splice(old,1);
  const oldGate=gates.findIndex(row=>row.name===name);if(oldGate>=0)gates.splice(oldGate,1);
  try{const result=await operation();assert.equal(await browser.evaluate('tact.state.error'),null);checks.push({name,...result});console.log(`PASS ${name}`);}
  catch(error){const state=await inspect().catch(()=>null);if(error.originalGate){gates.push({name,command:error.command,reason:error.message,state});console.log(`GATE ${name}`);return;}failures.push({name,error:error.message,state});console.log(`FAIL ${name}: ${error.message}`);if(state?.error)await screenshot(`failure-${failures.length}.png`).catch(()=>{});}
}
try{
  await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});
  await browser.call('Page.addScriptToEvaluateOnNewDocument',{source:`localStorage.removeItem('tact-2002-preferences');`});
  const glossary=tutorials.find(row=>row.selector===601);
  if(!supplement){
  for(const row of tutorials)await check(`tutorial${row.selector}: ${row.label}`,async()=>{
    await fresh();await startRace();const frames=await browser.evaluate('tact.state.frames');await clickCommand(row.command);
    await wait(`tact.state.frames>${frames}&&tact.state.memory.readI32(0x4ac980)===${row.selector}`);
    await screenshot(`tutorial-${row.selector}.png`);return{command:row.command,selector:row.selector,state:await inspect()};
  });
  await check('glossary pages602–604 via original + keyboard navigation',async()=>{
    await fresh();await startRace();await clickCommand(glossary.command);await wait('tact.state.memory.readI32(0x4ac980)===601');
    const pages=[];
    for(const selector of [602,603,604]){const frames=await browser.evaluate('tact.state.frames');await key('Equal','+',187);await wait(`tact.state.frames>${frames}&&tact.state.memory.readI32(0x4ac980)===${selector}`);await screenshot(`tutorial-${selector}.png`);pages.push(await inspect());}
    return{command:glossary.command,key:'+',selectors:[602,603,604],pages};
  });
  for(const row of boats)await check(`boat preset${row.selector}: ${row.label}`,async()=>{
    await fresh();const before=await browser.evaluate('tact.state.frames');await clickCommand(row.command);await wait(`tact.state.frames>${before}&&tact.state.memory.readI32(0x491144)===${row.selector}`);
    await startRace();await screenshot(`boat-${row.selector}.png`);return{command:row.command,selector:row.selector,state:await inspect()};
  });
  const controls=[...labels].filter(([,label])=>/^(3D view|Top view) \/ /.test(label));
  await fresh();await startRace();
  for(const [command,label] of controls)await check(`view/chart: ${label}`,async()=>{
    await clickCommand(command);const frames=await browser.evaluate('tact.state.frames');await wait(`tact.state.frames>${frames}`);return{command,state:await inspect()};
  });
  await screenshot('chart-last.png');
  await check('weather forecast toggles through the original menu',async()=>{
    await fresh();await startRace();const row=[...labels].find(([,label])=>label.includes('Weather Forecast'));
    await clickCommand(row[0]);await wait('tact.state.memory.readI32(0x4ac938)===1');await screenshot('forecast.png');const shown=await inspect();await clickCommand(row[0]);await wait('tact.state.memory.readI32(0x4ac938)===0');return{command:row[0],shown,restored:await inspect()};
  });
  await check('coach advice uses the original live race menu',async()=>{
    await fresh();await startRace();const row=tutorials.find(row=>row.selector===300);await clickCommand(row.command);await wait('tact.state.memory.readI32(0x4ac980)===300');await screenshot('advice.png');return{command:row.command,state:await inspect()};
  });
  for(const resourceId of [131,132])await check(`original modal${resourceId}: every radio, immediate stores and deferred tail`,async()=>{
    await fresh();const command=resourceId===131?32779:32823;
    await clickCommand(command);await wait('tact.state.modal');
    const resource=dialogs.find(row=>row.resource_id===resourceId),controls=resource.controls.filter(row=>row.class_name==='button'&&(row.style&15)===9);
    const storeMap=await browser.evaluate(`import('./src/engine/dialogs.js').then(module=>module.DIALOG_CONTROLS[${resourceId}])`);
    const tested=[];
    for(const control of controls){await browser.evaluate(`document.querySelector('#original-dialog input[value="${control.id}"]').click()`);const row=storeMap[control.id];assert.ok(row);assert.equal(await browser.evaluate(`tact.state.memory.readI32(${row[1]})`),row[2]);tested.push({control:control.id,address:row[1],value:row[2]});}
    await screenshot(`dialog-${resourceId}.png`);
    const before=await inspect();await pause(150);assert.equal((await inspect()).frames,before.frames,'original modal pauses game painting');
    await browser.evaluate(`Array.from(document.querySelectorAll('#original-dialog button')).find(button=>button.textContent==='OK').click()`);
    await wait('!tact.state.modal');await wait(`tact.state.frames>${before.frames}`);
    if(resourceId===131)assert.equal(await browser.evaluate('tact.state.memory.readI32(0x491140)'),2);
    await startRace();return{command,radioCount:tested.length,tested,state:await inspect()};
  });
  }
  await check('Look at Other Boat is enabled in the original two-player context',async()=>{
    await fresh();await clickCommand(32779);await wait('tact.state.modal');
    await browser.evaluate(`Array.from(document.querySelectorAll('#original-dialog button')).find(button=>button.textContent==='OK').click()`);await wait('!tact.state.modal');
    await startRace();await clickCommand(32834);const frames=await browser.evaluate('tact.state.frames');await wait(`tact.state.frames>${frames}`);
    assert.equal(await browser.evaluate('tact.state.memory.readI32(0x491140)'),2);
    await screenshot('two-player-other-boat.png');return{command:32834,state:await inspect()};
  });
  await check('mobile tutorial and original setup dialog remain usable',async()=>{
    await browser.call('Emulation.setDeviceMetricsOverride',{width:390,height:844,deviceScaleFactor:1,mobile:true});
    await fresh();await clickCommand(32823);await wait('tact.state.modal');
    const layout=await browser.evaluate(`(()=>{const dialog=document.getElementById('original-dialog'),title=document.getElementById('dialog-title'),length=document.querySelector('#original-dialog input[value="1008"]');const bounds=dialog.getBoundingClientRect(),titleBounds=title.getBoundingClientRect(),lengthBounds=length.getBoundingClientRect();return{scrollLeft:dialog.scrollLeft,title:title.textContent,dialogLeft:bounds.left,titleLeft:titleBounds.left,lengthLeft:lengthBounds.left,viewportWidth:innerWidth};})()`);
    assert.equal(layout.scrollLeft,0,'mobile original dialog initially shows its left edge');
    assert.equal(layout.title,'Design Options');assert.ok(layout.titleLeft>=layout.dialogLeft&&layout.titleLeft<layout.viewportWidth,'original dialog title is visible');
    assert.ok(layout.lengthLeft>=layout.dialogLeft&&layout.lengthLeft<layout.viewportWidth,'original length controls are visible');
    await screenshot('mobile-dialog.png');await browser.evaluate(`Array.from(document.querySelectorAll('#original-dialog button')).find(button=>button.textContent==='OK').click()`);await wait('!tact.state.modal');
    await startRace();const enabled=tutorials.find(row=>row.selector===6);await clickCommand(enabled.command);await wait('tact.state.memory.readI32(0x4ac980)===6');await screenshot('mobile-tutorial.png');return{viewport:{width:390,height:844},selector:6,dialogLayout:layout};
  });
  const exceptions=[...(previous?.exceptions??[]),...browser.events.filter(row=>row.method==='Runtime.exceptionThrown').map(row=>row.params.exceptionDetails)];
  const requests=browser.events.filter(row=>row.method==='Network.requestWillBeSent').map(row=>row.params.request.url);
  assert.deepEqual(requests.filter(url=>/\/original\/|\/tests\/fixtures\/|\.exe(?:$|\?)/.test(url)),[]);
  const result={url:base+'/play.html',checkedAt:new Date().toISOString(),scope:'Actual production menu buttons, original keyboard progression and dialog controls. No game-state writes or test fixtures supplied. Fresh preferences per profile preserve original demo gates.',
    tutorialSelectors:[...new Set(tutorials.map(row=>row.selector).concat([602,603,604]))].sort((a,b)=>a-b),
    renderedTutorialSelectors:[...new Set(checks.filter(row=>row.name.startsWith('tutorial')||row.name.startsWith('glossary')).flatMap(row=>row.pages?row.pages.map(page=>page.tutorial):[row.selector]))].sort((a,b)=>a-b),
    disabledTutorialSelectors:[...new Set(gates.map(row=>tutorials.find(item=>item.command===row.command)?.selector).filter(value=>value!==undefined))].sort((a,b)=>a-b),
    boatSelectors:boats.map(row=>row.selector).sort((a,b)=>a-b),checks,gates,failures,exceptions,requests:(previous?.requests??0)+requests.length};
  await writeFile(new URL('report.json',output),JSON.stringify(result,null,2)+'\n');
  console.log(`${checks.length} production breadth checks passed; ${gates.length} original restrictions preserved; ${failures.length} failures.`);
  if(failures.length||exceptions.length)process.exitCode=1;
}finally{await browser.close();}
