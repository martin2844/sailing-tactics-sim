import assert from 'node:assert/strict';
import { mkdir, writeFile } from 'node:fs/promises';
import { openBrowser } from './browser-session.js';

const output=new URL('../analysis/island-browser-check/',import.meta.url);
await mkdir(output,{recursive:true});
const browser=await openBrowser(`${process.env.TACT_URL??'http://127.0.0.1:8765'}/play.html`);
try{
  await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error');
  assert.equal(await browser.evaluate('tact.state.error'),null);
  await browser.waitFor('tact.state.frames>0');
  const inspect=()=>browser.evaluate(`({frames:tact.state.frames,error:tact.state.error,course:tact.state.memory.readI32(0x491194),island:tact.state.memory.readI32(0x4a5a4c),app:tact.state.memory.readI32(0x4ac8f8),shoreKind:tact.state.memory.readI32(0x4a4958),stack:{...tact.state.options.shorelineStack}})`);
  const initial=await inspect();
  await browser.evaluate('globalThis.checkedShorelineStack=tact.state.options.shorelineStack;true');
  const key=async(code,key,keyCode)=>{
    for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code,key,windowsVirtualKeyCode:keyCode,nativeVirtualKeyCode:keyCode});
  };
  const menu=async id=>{
    assert.equal(await browser.evaluate(`document.querySelector('[data-command="${id}"]').disabled`),false);
    await browser.evaluate(`document.querySelector('[data-command="${id}"]').click()`);
  };
  await key('KeyN','n',78);
  await browser.waitFor('tact.state.memory.readI32(0x4ac8f8)===0');
  await menu(32801);
  await browser.waitFor('tact.state.memory.readI32(0x491194)===7');
  await menu(32771);
  await browser.waitFor('tact.state.memory.readI32(0x4ac8f8)===2||tact.state.error');
  await key('Space',' ',32);
  await browser.waitFor(`tact.state.frames>${initial.frames+3}||tact.state.error`);
  const island=await inspect();
  assert.equal(island.error,null);assert.equal(island.course,7);assert.equal(island.island,1);assert.equal(island.app,2);
  assert.equal(island.stack.previousTreeY,initial.stack.previousTreeY);
  assert.equal(island.stack.centerProjectedY,0x4a94ec);
  assert.equal(await browser.evaluate('checkedShorelineStack===tact.state.options.shorelineStack'),true);
  const exceptions=browser.events.filter(event=>event.method==='Runtime.exceptionThrown');
  assert.deepEqual(exceptions,[]);
  const result=await browser.call('Page.captureScreenshot',{format:'png',captureBeyondViewport:true});
  await writeFile(new URL('round-island.png',output),Buffer.from(result.data,'base64'));
  await writeFile(new URL('report.json',output),JSON.stringify({initial,island,exceptions,
    scope:'Normal original menu/key handlers and native JavaScript production assets; functional Canvas check, separate from exact native drawing-request authority.'},null,2)+'\n');
  console.log('Round-the-Island browser path and persistent observed shoreline frame passed.');
}finally{await browser.close();}
