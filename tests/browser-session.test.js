import test,{after} from 'node:test';
import assert from 'node:assert/strict';
import {createServer} from 'node:http';
import {mkdtemp,writeFile,readFile,chmod,access,rm} from 'node:fs/promises';
import {tmpdir} from 'node:os';
import {join} from 'node:path';
import {openBrowser} from '../tools/browser-session.js';

// Real disposable child process, with a tiny fake CDP peer: no Chrome, display,
// external server, or graphics driver is needed for transport regressions.
const temporary=await mkdtemp(join(tmpdir(),'tact-browser-session-test-'));
const executable=join(temporary,'chrome.mjs'),argumentsPath=join(temporary,'arguments.json');
const server=createServer((_request,response)=>{
  response.setHeader('Content-Type','application/json');
  response.end(JSON.stringify([{id:'page',type:'page',webSocketDebuggerUrl:'ws://fixture/page'}]));
});
await new Promise(resolve=>server.listen(0,'127.0.0.1',resolve));
const saved={chrome:process.env.TACT_CHROME,endpoint:process.env.TACT_BROWSER_SESSION_ENDPOINT,
  arguments:process.env.TACT_BROWSER_SESSION_ARGUMENTS,WebSocket:globalThis.WebSocket};
process.env.TACT_CHROME=executable;
process.env.TACT_BROWSER_SESSION_ENDPOINT=`ws://127.0.0.1:${server.address().port}/browser/fixture`;
process.env.TACT_BROWSER_SESSION_ARGUMENTS=argumentsPath;
await writeFile(executable,`#!/usr/bin/env node
import {writeFileSync} from 'node:fs';
writeFileSync(process.env.TACT_BROWSER_SESSION_ARGUMENTS,JSON.stringify(process.argv.slice(2)));
process.stderr.write('DevTools listening on '+process.env.TACT_BROWSER_SESSION_ENDPOINT+'\\n');
setInterval(()=>{},1000);
`);
await chmod(executable,0o755);

class FakeSocket extends EventTarget{
  static OPEN=1;
  constructor(url){super();this.browser=url.includes('/browser/');this.readyState=0;
    queueMicrotask(()=>{this.readyState=1;this.dispatchEvent(new Event('open'));});}
  send(encoded){
    const {id,method}=JSON.parse(encoded);let result,error;
    if(method==='Test.neverReply')return;
    if(method.startsWith('Browser.')||method==='SystemInfo.getInfo'){
      assert.equal(this.browser,true,'browser-only methods use the browser websocket');
      if(method==='Browser.getVersion')result={product:'FixtureChrome/1'};
      else if(method==='SystemInfo.getInfo')result={gpu:{featureStatus:{gpu_compositing:'disabled_software'}}};
      else result={windowId:7,bounds:{width:500,height:400}};
    }else{
      assert.equal(this.browser,false,'page methods use the page websocket');
      if(method==='Runtime.evaluate')result={result:{value:true}};
      else if(method==='Test.error')error={message:'fixture protocol failure'};
      else result={};
    }
    queueMicrotask(()=>this.dispatchEvent(new MessageEvent('message',{data:JSON.stringify({id,result,error})})));
  }
  close(){if(this.readyState===3)return;this.readyState=3;this.dispatchEvent(new Event('close'));}
}
globalThis.WebSocket=FakeSocket;
after(async()=>{
  for(const [field,old]of [['TACT_CHROME',saved.chrome],['TACT_BROWSER_SESSION_ENDPOINT',saved.endpoint],
    ['TACT_BROWSER_SESSION_ARGUMENTS',saved.arguments]])if(old===undefined)delete process.env[field];else process.env[field]=old;
  globalThis.WebSocket=saved.WebSocket;
  await new Promise(resolve=>server.close(resolve));await rm(temporary,{recursive:true,force:true});
});

test('default launch stays headless/GPU-disabled and reports actual browser-scoped metadata',async()=>{
  const browser=await openBrowser('http://fixture/');
  try{
    const args=JSON.parse(await readFile(argumentsPath,'utf8'));
    assert.ok(args.includes('--headless=new'));assert.ok(args.includes('--disable-gpu'));
    assert.deepEqual(browser.metadata.requested.args,args);
    assert.equal(browser.metadata.version.product,'FixtureChrome/1');
    assert.equal(browser.metadata.systemInfo.gpu.featureStatus.gpu_compositing,'disabled_software');
    assert.ok(Number.isInteger(browser.metadata.processId));
    assert.equal((await browser.browserCall('Browser.getVersion')).product,'FixtureChrome/1');
    await assert.rejects(browser.call('Test.error'),/fixture protocol failure/);
    await assert.rejects(browser.call('Test.neverReply',{}, {timeoutMs:10}),/CDP request timed out.*Test.neverReply/);
    assert.equal(await browser.evaluate('true'),true,'a timed-out request does not poison later calls');
  }finally{await browser.close();}
  await assert.rejects(access(browser.metadata.requested.profile),{code:'ENOENT'});
});

test('headed GPU request records flags without assuming hardware, and close rejects pending calls',async()=>{
  const browser=await openBrowser('http://fixture/',{headless:false,gpu:true,width:1280,height:1050,ensureWindowSize:false});
  const args=JSON.parse(await readFile(argumentsPath,'utf8'));
  assert.ok(!args.includes('--headless=new'));assert.ok(!args.includes('--disable-gpu'));
  assert.ok(args.includes('--window-size=1280,1050'));
  assert.equal(browser.metadata.requested.gpu,true);
  assert.equal(browser.metadata.systemInfo.gpu.featureStatus.gpu_compositing,'disabled_software');
  const pending=assert.rejects(browser.call('Test.neverReply'),/DevTools connection closed/);
  await Promise.all([browser.close(),browser.close(),pending]);
  await assert.rejects(browser.browserCall('Browser.getVersion'),/DevTools connection closed/);
  await assert.rejects(access(browser.metadata.requested.profile),{code:'ENOENT'});
});

test('invalid dimensions and timeouts reject before launching a child',async()=>{
  for(const options of [null,{headless:1},{gpu:1},{width:1280},{width:NaN,height:1050},
    {width:1280,height:0},{requestTimeoutMs:Infinity},{startupTimeoutMs:0}]){
    await assert.rejects(openBrowser('about:blank',options),TypeError);
  }
  const previous=process.env.TACT_CHROME;
  try{
    process.env.TACT_CHROME=join(temporary,'missing-chrome');
    await assert.rejects(openBrowser('about:blank'),{code:'ENOENT'});
  }finally{process.env.TACT_CHROME=previous;}
});
