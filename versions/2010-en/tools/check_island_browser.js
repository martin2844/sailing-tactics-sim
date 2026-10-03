import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';
import {openBrowser} from '../../../tools/browser-session.js';

const output=new URL('../analysis/island-browser-check/',import.meta.url);
await mkdir(output,{recursive:true});
const url=process.env.TACT_2010_URL??`${process.env.TACT_URL??'http://127.0.0.1:8765'}/versions/2010-en/play.html`;
const browser=await openBrowser(url);
try{
  await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});
  await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);
  assert.equal(await browser.evaluate('tact.state.error'),null);
  await browser.waitFor('tact.state.frames>0');
  const inspect=()=>browser.evaluate(`({frames:tact.state.frames,error:tact.state.error,
    course:tact.state.memory.readI32(0x4da19c),island:tact.state.memory.readI32(0x4f8b78),
    app:tact.state.memory.readI32(0x5363b0),variant:tact.state.memory.readI32(0x50040c),
    display:tact.state.memory.readI32(0x4da174),stack:tact.state.options.shoreStack.snapshot()})`);
  const initial=await inspect();
  await browser.evaluate('globalThis.checkedShoreStack=tact.state.options.shoreStack;true');
  const key=async(code,key,keyCode)=>{
    await browser.evaluate('document.getElementById("race").focus()');
    for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code,key,windowsVirtualKeyCode:keyCode,nativeVirtualKeyCode:keyCode});
  };
  const menu=async id=>{
    assert.equal(await browser.evaluate(`document.querySelector('[data-command="${id}"]').disabled`),false);
    await browser.evaluate(`document.querySelector('[data-command="${id}"]').click()`);
  };
  await menu(32801);
  await browser.waitFor('tact.state.memory.readI32(0x4da19c)===7');
  await menu(32771);
  await browser.waitFor('tact.state.memory.readI32(0x5363b0)===2||tact.state.error',60000);
  await key('Space',' ',32);
  await menu(32970);
  await browser.waitFor('tact.state.options.shoreStack.snapshot().completedCalls>=3||tact.state.error',60000);
  const island=await inspect();
  if(island.error){
    const error=await browser.evaluate('document.getElementById("error").textContent');
    await writeFile(new URL('failure.json',output),JSON.stringify({initial,island,error},null,2)+'\n');
    assert.fail(error);
  }
  assert.equal(island.course,7);assert.equal(island.island,1);assert.equal(island.app,2);
  assert.equal(island.variant,0);assert.equal(island.display,12);
  assert.equal(island.stack.previousTreeY,initial.stack.previousTreeY);
  assert.ok(island.stack.completedCalls>=3);
  assert.equal(await browser.evaluate('checkedShoreStack===tact.state.options.shoreStack'),true);
  const exceptions=browser.events.filter(event=>event.method==='Runtime.exceptionThrown');
  assert.deepEqual(exceptions,[]);
  const screenshot=await browser.call('Page.captureScreenshot',{format:'png',captureBeyondViewport:true});
  await writeFile(new URL('round-island.png',output),Buffer.from(screenshot.data,'base64'));
  await writeFile(new URL('report.json',output),JSON.stringify({url,initial,island,exceptions,
    scope:'Normal original menu and keyboard handlers in the native JavaScript browser. Persistent caller-scoped shoreline inputs use the intact original reference. Functional Canvas proof is separate from native drawing-request equality.'},null,2)+'\n');
  console.log('2010 Round the Island browser path preserves the observed retained slots.');
}finally{await browser.close();}
