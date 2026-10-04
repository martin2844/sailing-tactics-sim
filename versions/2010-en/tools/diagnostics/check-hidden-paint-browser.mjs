import assert from 'node:assert/strict';
import {readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {setTimeout as pause} from 'node:timers/promises';
import {openBrowser} from '../../../../tools/browser-session.js';

async function observe(url){
  const browser=await openBrowser(url);
  try{
    await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);
    assert.equal(await browser.evaluate('tact.state.error'),null);
    await browser.evaluate('tact.command(32909)');
    const key=async()=>{for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',
      {type,code:'Space',key:' ',windowsVirtualKeyCode:32,nativeVirtualKeyCode:32});};
    await key();await browser.waitFor('tact.state.memory.readI32(0x5363b0)===2||tact.state.error',60000);
    if(await browser.evaluate('[0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c].some(a=>tact.state.memory.readI32(a)!==0)'))await key();
    const initial=await browser.evaluate('tact.state.frames');
    await browser.waitFor(`tact.state.frames>${initial+3}||tact.state.error`,60000);
    const inspect=()=>browser.evaluate(`({visibility:document.visibilityState,frames:tact.state.frames,
      time:tact.state.memory.readF64(0x5359f0),pending:tact.state.pending,nextPaint:tact.state.nextPaint,
      dt:tact.state.memory.readF64(0x523378),error:tact.state.error})`);
    const own=(await browser.call('Target.getTargetInfo')).targetInfo.targetId;
    const other=await browser.call('Target.createTarget',{url:'about:blank'});
    await browser.call('Target.activateTarget',{targetId:other.targetId});
    await browser.waitFor('document.visibilityState==="hidden"');
    const hiddenStart=await inspect();await pause(750);const hiddenEnd=await inspect();
    await browser.call('Target.activateTarget',{targetId:own});
    await browser.waitFor(`document.visibilityState==='visible'&&tact.state.frames>${hiddenEnd.frames+3}||tact.state.error`,60000);
    const resumed=await inspect();
    const loaded=browser.events.filter(row=>row.method==='Network.responseReceived'&&row.params.response.url.endsWith('/src/play.js')).at(-1);
    const {body,base64Encoded}=await browser.call('Network.getResponseBody',{requestId:loaded.params.requestId});
    const playSourceSha256=createHash('sha256').update(Buffer.from(body,base64Encoded?'base64':'utf8')).digest('hex');
    return {url,playSourceSha256,hiddenStart,hiddenEnd,resumed,
      hiddenPaints:hiddenEnd.frames-hiddenStart.frames,hiddenSimulationDelta:hiddenEnd.time-hiddenStart.time,
      resumePaints:resumed.frames-hiddenEnd.frames,resumeSimulationDelta:resumed.time-hiddenEnd.time};
  }finally{await browser.close();}
}

const baseline=await observe(process.env.TACT_HIDDEN_BASELINE_URL??'http://127.0.0.1:8766/index.html');
const candidate=await observe(process.env.TACT_HIDDEN_URL??'http://127.0.0.1:8765/versions/2010-en/play.html');
assert.ok(baseline.hiddenPaints>0,'the prior immediate-task loop keeps computing in an actual background tab');
assert.equal(candidate.hiddenPaints,0);assert.equal(candidate.hiddenSimulationDelta,0);
assert.equal(candidate.hiddenEnd.pending,false);assert.equal(candidate.hiddenEnd.nextPaint,true);
assert.ok(candidate.resumePaints>=4);assert.equal(candidate.resumed.error,null);
const paths=['versions/2010-en/src/play.js','versions/2010-en/tests/paint-scheduler-review.test.js'];
const sourcePins=await Promise.all(paths.map(async path=>({path,sha256:createHash('sha256').update(await readFile(path)).digest('hex')})));
const report={checkedAt:new Date().toISOString(),scope:'Real Chrome tabs: original speed10 race, another tab brought to the foreground for750ms, then visible resume. No synthetic visibility property, lifecycle freeze or simulation-clock patch. This is hidden-work/resume evidence, not a throughput comparison.',sourcePins,baseline,candidate};
await writeFile('versions/2010-en/analysis/browser-performance/hidden-paint-review.json',JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify(report));
