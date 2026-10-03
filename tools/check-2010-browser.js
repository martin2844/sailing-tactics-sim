import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';
import {setTimeout as pause} from 'node:timers/promises';
import {openBrowser} from './browser-session.js';

const output=new URL('../versions/2010-en/analysis/browser-check/',import.meta.url);
await mkdir(output,{recursive:true});
const url=process.env.TACT_2010_URL??`${process.env.TACT_URL??'http://127.0.0.1:8765'}/versions/2010-en/play.html`;
const reportName=new URL(url).pathname.endsWith('/index.html')?'standalone-browser-verification.json':'browser-verification.json';
const browser=await openBrowser(url),checks=[];
let failure=null;
try{
  await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});
  await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);
  const healthy=async()=>{
    const error=await browser.evaluate('tact.state.error');
    assert.equal(error,null,error?await browser.evaluate('document.getElementById("error").textContent'):undefined);
  };
  const rendered=async before=>{
    await browser.waitFor(`tact.state.frames>${before}||tact.state.error`,60000);await healthy();
  };
  const inspect=()=>browser.evaluate(`({ready:tact.state.ready,frames:tact.state.frames,error:tact.state.error,
    app:tact.state.memory.readI32(0x5363b0),view:tact.state.memory.readI32(0x4f71c4),
    paused:tact.state.memory.readI32(0x536444),mode:tact.state.memory.readI32(0x4da16c),
    notice:tact.state.memory.readI32(0x53648c),forecast:tact.state.memory.readI32(0x5363f0),
    chart:tact.state.memory.readI32(0x5233a8),current:tact.state.memory.readI32(0x536434),
    tide:tact.state.memory.readI32(0x536438),otherOverlay:tact.state.memory.readI32(0x53644c),
    time:tact.state.memory.readF64(0x5359f0),clock:tact.state.memory.readI32(0x4f8cd0),
    selector:tact.state.memory.readI32(0x4da144),humans:tact.state.memory.readI32(0x4da140)})`);
  const key=async(code,key,keyCode)=>{
    await browser.evaluate('document.getElementById("race").focus()');
    await browser.call('Input.dispatchKeyEvent',{type:'keyDown',code,key,windowsVirtualKeyCode:keyCode,nativeVirtualKeyCode:keyCode});
    await browser.call('Input.dispatchKeyEvent',{type:'keyUp',code,key,windowsVirtualKeyCode:keyCode,nativeVirtualKeyCode:keyCode});
  };
  const screenshot=async name=>{
    const result=await browser.call('Page.captureScreenshot',{format:'png',captureBeyondViewport:true});
    await writeFile(new URL(name,output),Buffer.from(result.data,'base64'));
  };
  const click=async id=>{
    const before=await browser.evaluate('tact.state.frames');
    const enabled=await browser.evaluate(`(()=>{const button=document.querySelector('[data-command="${id}"]');
      if(!button||button.disabled)return false;button.click();return true;})()`);
    assert.equal(enabled,true,`Original command ${id} is enabled in this context`);
    const idle=await browser.evaluate(`tact.state.frames===${before}&&!tact.state.pending&&!tact.state.modal`);
    if(idle){
      // Some original setup handlers change selections without invalidating
      // the native window. Supply a separate host paint for their render check.
      checks.push({name:`original command ${id} leaves painting idle`,passed:true});
      await browser.evaluate('tact.requestPaint()');
    }
    await rendered(before);
  };
  await healthy();await rendered(0);
  assert.equal((await inspect()).app,0);
  assert.equal(await browser.evaluate('document.querySelectorAll(".menu-command").length'),312);
  assert.equal(await browser.evaluate(`import(new URL('../../../src/runtime/float80.js',document.querySelector('script[type="module"]').src)).then(module=>module.getX87ControlWord())`),0x027f);
  checks.push({name:'2010 constructor, 312 original commands and observed x87 precision',...(await inspect())});
  await screenshot('01-start.png');
  await key('Space',' ',32);
  await browser.waitFor('tact.state.memory.readI32(0x5363b0)>0||tact.state.memory.readI32(0x53648c)===1||tact.state.error',60000);await healthy();
  const firstSpace=await inspect();
  if(firstSpace.app===0&&firstSpace.mode>0&&firstSpace.notice===1)await key('Space',' ',32);
  await browser.waitFor('tact.state.memory.readI32(0x5363b0)===2||tact.state.error',60000);await healthy();
  const started=await inspect();
  // Original Space clears active chart/forecast/tutorial screens. Pressing it
  // again when those flags are already clear instead toggles simulation speed.
  if(started.paused>0||started.forecast||started.chart||started.current||started.tide||started.otherOverlay){
    await key('Space',' ',32);
    await browser.waitFor('!tact.state.memory.readI32(0x536444)&&!tact.state.memory.readI32(0x5363f0)&&!tact.state.memory.readI32(0x5233a8)&&!tact.state.memory.readI32(0x536434)&&!tact.state.memory.readI32(0x536438)&&!tact.state.memory.readI32(0x53644c)||tact.state.error',60000);await healthy();
    checks.push({name:'Space dismisses the active original startup overlay',before:started,after:await inspect()});
  }
  const race=await inspect();await browser.waitFor(`tact.state.memory.readI32(0x4f8cd0)>${race.clock}||tact.state.error`,60000);await healthy();
  checks.push({name:'original Space starts a continuously advancing race',...(await inspect())});await screenshot('02-race.png');
  await key('Slash','/',191);await browser.waitFor('tact.state.memory.readI32(0x536444)===6||tact.state.error');await healthy();
  await pause(200);checks.push({name:'keyboard controls tutorial',...(await inspect())});await screenshot('03-controls.png');
  await key('Space',' ',32);await browser.waitFor('tact.state.memory.readI32(0x536444)===0||tact.state.error');await healthy();
  await key('KeyF','f',70);await pause(500);const frozen=await inspect();await pause(250);assert.equal((await inspect()).frames,frozen.frames);
  checks.push({name:'F freezes continuous invalidation',passed:true});
  const sheetBefore=await browser.evaluate('tact.state.memory.readI32(0x500384)');
  const point=await browser.evaluate('(()=>{const r=document.getElementById("race").getBoundingClientRect();return{x:r.x+r.width/2,y:r.y+r.height/2};})()');
  const deltaY=sheetBefore>=90?120:-120;
  await browser.call('Input.dispatchMouseEvent',{type:'mouseWheel',...point,deltaX:0,deltaY});
  const sheetAfter=await browser.evaluate('tact.state.memory.readI32(0x500384)');
  assert.equal(sheetAfter,deltaY<0?Math.min(90,sheetBefore+5):Math.max(0,sheetBefore-5));
  checks.push({name:'physical wheel event follows original sheet control',before:sheetBefore,after:sheetAfter});
  await key('KeyF','f',70);await rendered(frozen.frames);
  const beforeDialog=await inspect();
  await browser.evaluate(`document.querySelector('[data-command="57664"]').click()`);
  await browser.waitFor('tact.state.modal');await pause(250);const modal=await inspect();await pause(250);assert.equal((await inspect()).frames,modal.frames);
  await screenshot('04-about.png');
  await browser.evaluate('document.querySelector("#original-dialog button").click()');await browser.waitFor('!tact.state.modal');await rendered(modal.frames);
  checks.push({name:'original About dialog pauses and resumes the active race',before:beforeDialog.clock,after:(await inspect()).clock});
  await key('KeyN','n',78);await browser.waitFor('tact.state.memory.readI32(0x5363b0)===0||tact.state.error');await healthy();
  for(const [id,selector] of [[33104,25],[33105,26],[33106,27],[33098,23],[33099,24],[33100,21],[33101,22]]){
    await click(id);assert.equal((await inspect()).selector,selector);
    checks.push({name:`original boat command ${id} renders selector ${selector}`,passed:true});
  }
  await screenshot('05-flying-scot.png');
  const groups=await browser.evaluate(`(()=>{
    const all=[...document.querySelectorAll('.menu-submenu')];
    const group=name=>[...all.find(button=>button.textContent===name).nextElementSibling.querySelectorAll('.menu-command')].map(button=>({id:Number(button.dataset.command),label:button.textContent}));
    return{boats:group('Boat Type'),venues:group('Real Racing Areas'),imaginary:group('Imaginary  Racing Areas'),courses:group('Race Course')};
  })()`);
  for(const [group,commands] of Object.entries(groups)){
    if(group==='courses'){await click(32799);await click(32809);}
    for(const row of commands){
      await click(row.id);checks.push({name:`setup ${group}: ${row.label}`,command:row.id,passed:true});
    }
  }
  await click(32799);await click(32816);await click(32881);await click(32807);
  await key('Space',' ',32);
  await browser.waitFor('tact.state.memory.readI32(0x5363b0)===2||tact.state.error',60000);await healthy();
  assert.equal(await browser.evaluate('tact.state.memory.readI32(0x5363bc)'),1);
  const boardStarted=await inspect();
  if(boardStarted.paused||boardStarted.forecast||boardStarted.chart||boardStarted.current||boardStarted.tide||boardStarted.otherOverlay)
    await key('Space',' ',32);
  const boardBefore=await inspect();
  await browser.waitFor(`tact.state.frames>=${boardBefore.frames+3}||tact.state.error`,60000);await healthy();
  const boardAfter=await inspect();assert.ok(boardAfter.time>boardBefore.time);
  checks.push({name:'original Board selection starts and advances a live sailboard fleet',
    beforeTime:boardBefore.time,afterTime:boardAfter.time,passed:true});
  await key('KeyN','n',78);await browser.waitFor('tact.state.memory.readI32(0x5363b0)===0||tact.state.error');await healthy();
  // Restore a normal setup before exercising every tutorial branch.
  await click(32799);await click(32816);await click(32789);await click(32807);
  const modalSelection=async(commandId,controlId,accept)=>{
    const enabled=await browser.evaluate(`(()=>{const button=document.querySelector('[data-command="${commandId}"]');
      if(button.disabled)return false;button.click();return true;})()`);
    assert.equal(enabled,true);await browser.waitFor('tact.state.modal');
    await browser.evaluate(`document.querySelector('#original-dialog input[value="${controlId}"]').click()`);
    const label=JSON.stringify(accept?'OK':'Cancel');
    await browser.evaluate(`[...document.querySelectorAll('#original-dialog button')].find(button=>button.textContent===${label}).click()`);
    await browser.waitFor('!tact.state.modal');await pause(100);await healthy();
  };
  await modalSelection(32823,1013,false);
  assert.equal(await browser.evaluate('tact.state.memory.readI32(0x5363d0)'),50);
  checks.push({name:'Design Options Cancel retains the original immediate length selection',passed:true});
  await modalSelection(32823,1009,true);
  assert.equal(await browser.evaluate('tact.state.memory.readI32(0x5363d0)'),25);
  checks.push({name:'Design Options OK follows the original selection and close tail',passed:true});
  await modalSelection(32779,1001,false);
  assert.equal(await browser.evaluate('tact.state.memory.readI32(0x536400)'),4);
  assert.equal((await inspect()).humans,2);
  checks.push({name:'Helm Cancel retains the original speed selection and two-player close tail',passed:true});
  await click(32778);
  const tutorials=await browser.evaluate(`(()=>{
    const ids=[32862,32868,33102,32926,32956];
    const all=[...document.querySelectorAll('.menu-submenu')];
    for(const name of ['Rules Tutorial','Tactics + Strategy Tutorial'])
      for(const button of all.find(button=>button.textContent===name).nextElementSibling.querySelectorAll('.menu-command'))ids.push(Number(button.dataset.command));
    return ids;
  })()`);
  for(const id of tutorials){await click(id);checks.push({name:`original tutorial command ${id}`,view:(await inspect()).view,passed:true});}
  await key('Space',' ',32);await healthy();
  // The results menu requires a recorded finisher. Its native state/render
  // comparison covers actual finish data; this browser check explicitly sets
  // the one-finisher input to reach the same menu and screen host path.
  await browser.evaluate(`tact.state.memory.writeI32(0x5363fc,1);document.querySelector('.menu-toggle').click()`);
  await click(32939);
  assert.equal((await inspect()).paused,400);
  await screenshot('06-results.png');checks.push({name:'prepared one-finisher input: original Show Race Results menu and screen',passed:true});
  // Save through the actual pagehide handler, then load the original archive on reload.
  const selected=await browser.evaluate('tact.state.memory.readI32(0x4da144)');
  await browser.call('Page.reload');await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);await healthy();await rendered(0);
  assert.equal((await inspect()).selector,selected);
  assert.equal(await browser.evaluate('JSON.parse(localStorage.getItem("tact-2010-en-preferences")).length'),636);
  checks.push({name:'636-byte native preference archive survives reload',passed:true});
  const exceptions=browser.events.filter(row=>row.method==='Runtime.exceptionThrown').map(row=>row.params.exceptionDetails);
  assert.deepEqual(exceptions,[]);
  const requests=browser.events.filter(row=>row.method==='Network.requestWillBeSent').map(row=>row.params.request.url);
  assert.deepEqual(requests.filter(url=>/\/tests\/fixtures\/|\.exe(?:$|\?)/.test(url)),[]);
  checks.push({name:'production uses browser JavaScript and data with no EXE or proof fixture requests',requests:requests.length,passed:true});
}catch(error){failure=error.stack??String(error);throw error;}
finally{
  const report={url,checkedAt:new Date().toISOString(),passed:failure===null,checks,failure,
    exceptions:browser.events.filter(row=>row.method==='Runtime.exceptionThrown').map(row=>row.params.exceptionDetails)};
  await writeFile(new URL('report.json',output),JSON.stringify(report,null,2)+'\n');
  if(failure===null)await writeFile(new URL('../'+reportName,output),JSON.stringify(report,null,2)+'\n');
  await browser.close();
}
console.log(`${checks.length} 2010 browser checks passed.`);
