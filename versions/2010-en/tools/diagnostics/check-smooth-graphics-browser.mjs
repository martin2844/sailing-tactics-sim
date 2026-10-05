// Compare actual Canvas renders at the same original frame/control boundaries.
// Engine memory is observed only inside advanceFrame; drawing retains the
// original memory methods so its normal fast paths and pixel feedback run.
import assert from 'node:assert/strict';
import {createHash} from 'node:crypto';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {pathToFileURL} from 'node:url';
import {openBrowser} from '../../../../tools/browser-session.js';
import {paintMeasurementInstrumentation} from '../../../../tools/paint-measurements.js';
import {deterministicPaintSetupInstrumentation,runDeterministicPaintSetup} from '../../../../tools/deterministic-paint-setup.js';

const base=process.env.TACT_2010_URL??'http://127.0.0.1:8765/versions/2010-en/play.html';
const output=process.env.TACT_CANVAS_REPORT_DIR
  ?pathToFileURL(resolve(process.env.TACT_CANVAS_REPORT_DIR)+'/')
  :new URL('../../analysis/browser-performance/',import.meta.url);
await mkdir(output,{recursive:true});
const addresses={time:0x5359f0,dt:0x523378,speed:0x4da174,racing:0x5363b0,mode:0x4da16c,
  notice:0x53648c,divisor:0x4da178,clock:0x4f8cd0,autoSlow:0x4da1dc,
  overlays:[0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c]};
const installTrace=`(async()=>{
  const player=document.querySelector('script[type="module"][src]').src;
  const {advanceFrame}=await import(new URL('./engine/frame.js',player));
  const m=tact.state.memory,methods=new Map();
  const widths={U8:1,I8:1,U16:2,I16:2,U32:4,I32:4,F32:4,F64:8};
  let buffer=new Uint8Array(16384),length=0,operations=0;
  const record=(kind,address,width)=>{
    const required=length+12+width;
    if(required>buffer.length){const expanded=new Uint8Array(Math.max(required,buffer.length*2));expanded.set(buffer);buffer=expanded;}
    const header=new DataView(buffer.buffer,length,12);
    header.setUint32(0,kind,true);header.setUint32(4,address,true);header.setUint32(8,width,true);
    buffer.set(m.bytes.subarray(address-m.base,address-m.base+width),length+12);
    length=required;operations++;
  };
  let identifier=1;
  for(const [suffix,width] of Object.entries(widths))for(const prefix of ['read','write']){
    const key=prefix+suffix,original=m[key],kind=identifier++;
    methods.set(key,{descriptor:Object.getOwnPropertyDescriptor(m,key),wrapper:function(address,...args){
      const result=original.call(this,address,...args);record(kind,address,width);return result;
    }});
  }
  for(const key of ['readBytes','writeBytes','moveBytes']){
    const original=m[key],kind=identifier++;
    methods.set(key,{descriptor:Object.getOwnPropertyDescriptor(m,key),wrapper:function(address,...args){
      if(key==='moveBytes')record(kind,args[0],args[1]);
      const result=original.call(this,address,...args);
      const width=key==='readBytes'?args[0]:key==='writeBytes'?args[0].byteLength:args[1];
      record(kind,address,width);return result;
    }});
  }
  globalThis.engineTraces=[];
  tact.state.options.advanceFrame=(memory,rng,options)=>{
    if(memory!==m)throw new Error('Unexpected engine memory');
    length=0;operations=0;const frame=tact.state.frames+1,rngBefore=rng.state;
    for(const [key,{wrapper}] of methods)Object.defineProperty(m,key,{configurable:true,writable:true,value:wrapper});
    let result;
    try{result=advanceFrame(memory,rng,options);}
    finally{for(const [key,{descriptor}] of methods){if(descriptor)Object.defineProperty(m,key,descriptor);else delete m[key];}}
    const data=buffer.slice(0,length),metadata={frame,operations,bytes:length,rngBefore,rngAfter:rng.state};
    engineTraces.push(crypto.subtle.digest('SHA-256',data).then(digest=>({...metadata,
      sha256:[...new Uint8Array(digest)].map(v=>v.toString(16).padStart(2,'0')).join('')})));
    return result;
  };
})()`;

async function run(exact){
  const url=new URL(base);if(exact)url.searchParams.set('graphics','exact');else url.searchParams.delete('graphics');
  const browser=await openBrowser(url.href);
  try{
    await browser.call('Page.addScriptToEvaluateOnNewDocument',{source:deterministicPaintSetupInstrumentation()+paintMeasurementInstrumentation(`
      const s=tact.state,m=s.memory;
      paintMeasurements.push({frame:s.frames,rng:m?s.rng.state:null,time:m?.readF64(${addresses.time}),
        dt:m?.readF64(${addresses.dt}),speed:m?.readI32(${addresses.speed}),mode:m?.readI32(${addresses.mode}),error:s.error});
      if(s.frames===globalThis.traceFinalFrame)s.modal=true;
    `,{setupGate:true})});
    await browser.call('Page.reload');
    await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);
    await browser.waitFor('paintSetupGate.queued===1||tact.state.error',60000);
    assert.equal(await browser.evaluate('tact.state.error'),null);
    await browser.evaluate(installTrace);
    const key=async(code,key,keyCode)=>{
      await browser.evaluate('document.getElementById("race").focus()');
      for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code,key,windowsVirtualKeyCode:keyCode});
    };
    const setup=await runDeterministicPaintSetup(browser,{addresses,commands:[32909],key,afterFastForward:true,fastForwardClock:100,noAutoSlow:true});
    const finalFrame=setup.entry.frame+240;
    await browser.evaluate(`traceFinalFrame=${finalFrame};paintSetupGate.release()`);
    await browser.waitFor(`tact.state.frames>=${finalFrame}||tact.state.error`,180000);
    assert.equal(await browser.evaluate('tact.state.error'),null);
    const rows=await browser.evaluate(`Promise.all(engineTraces).then(rows=>rows.filter(row=>row.frame<=${finalFrame}))`);
    const paints=await browser.evaluate(`paintMeasurements.filter((row,index,rows)=>row.frame<=${finalFrame}&&(index===0||row.frame!==rows[index-1].frame))`);
    assert.equal(paints.length,finalFrame,'Every completed paint is represented once');
    const screenshot=await browser.call('Page.captureScreenshot',{format:'png'});
    const imageName=`smooth-graphics-canvas-${exact?'exact':'smooth'}.png`;
    await writeFile(new URL(imageName,output),Buffer.from(screenshot.data,'base64'));
    const modules=[];
    const loaded=new Map(browser.events.filter(e=>e.method==='Network.responseReceived'&&/\.js(?:\?|$)/.test(e.params.response.url)).map(e=>[e.params.response.url,e.params.requestId]));
    for(const [moduleUrl,requestId] of loaded){
      const {body,base64Encoded}=await browser.call('Network.getResponseBody',{requestId});
      const bytes=Buffer.from(body,base64Encoded?'base64':'utf8');
      modules.push({url:moduleUrl,sha256:createHash('sha256').update(bytes).digest('hex')});
    }
    const exceptions=browser.events.filter(e=>e.method==='Runtime.exceptionThrown').map(e=>e.params.exceptionDetails);
    assert.deepEqual(exceptions,[]);
    return {url:url.href,setup,finalFrame,rows,paints,imageName,modules,exceptions};
  }finally{await browser.close();}
}
const exact=await run(true),smooth=await run(false);
const differences=[];
for(const key of ['rows','paints']){
  const a=exact[key],b=smooth[key];
  if(a.length!==b.length)differences.push({kind:key,exactCount:a.length,smoothCount:b.length});
  for(let i=0;i<Math.min(a.length,b.length);i++)if(JSON.stringify(a[i])!==JSON.stringify(b[i]))differences.push({kind:key,index:i,exact:a[i],smooth:b[i]});
}
if(JSON.stringify(exact.setup.history)!==JSON.stringify(smooth.setup.history))differences.push({kind:'controlHistory'});
const report={format:1,checkedAt:new Date().toISOString(),scope:'Two sequential real Canvas browser runs through identical original controls and420paint boundaries. Each engine prefix hashes every ordered memory access and returned/stored bytes with SHA256; exact memory methods are restored before drawing, so native pixel feedback and drawing fast paths remain active. End-of-paint RNG/time/dt/speed/fullmode are compared for every frame. Correctness instrumentation timings are not performance evidence. This is finite default-scenario coverage, not exhaustive state proof.',
  equal:differences.length===0,differences,exact,smooth};
await writeFile(new URL('smooth-graphics-canvas-coupling.json',output),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({equal:report.equal,engineFrames:exact.rows.length,paints:exact.paints.length,differences:differences.slice(0,3)}));
assert.deepEqual(differences,[],'Smooth Canvas rendering changed an engine trace or original paint state');
