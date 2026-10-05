import {readFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {openBrowser} from '../../../tools/browser-session.js';
import {paintMeasurementInstrumentation} from '../../../tools/paint-measurements.js';
import {deterministicPaintSetupInstrumentation,runDeterministicPaintSetup,deterministicSetupSnapshotExpression} from '../../../tools/deterministic-paint-setup.js';
export const addresses={time:0x5359f0,clock:0x4f8cd0,speed:0x4da174,divisor:0x4da178,racing:0x5363b0,mode:0x4da16c,notice:0x53648c,autoSlow:0x4da1dc,overlays:[0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c]};
let server;
export async function referenceSession({fleet=5,record='',before='',setup=true}={}){
  if(![5,15].includes(fleet))throw new Error('Unsupported candidate fleet');
  if(!server){process.env.TACT_PORT='0';process.env.TACT_HOST='127.0.0.1';({server}=await import('../../../tools/serve.js'));if(!server.listening)await new Promise((r,j)=>{server.once('listening',r);server.once('error',j);});}
  const browser=await openBrowser(`http://127.0.0.1:${server.address().port}/versions/2010-en/play.html`,{headless:false,gpu:true,width:1280,height:1051,requestTimeoutMs:60000});
  try{
    await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});
    const instrumentation=paintMeasurementInstrumentation(record,{setupGate:true});
    if(!instrumentation.includes('const start=performance.now();callback(...args);'))throw new Error('Unknown paint instrument contract');
    await browser.call('Page.addScriptToEvaluateOnNewDocument',{source:deterministicPaintSetupInstrumentation()+instrumentation.replace('const start=performance.now();callback(...args);',`const start=performance.now();${before};callback(...args);`)});
    await browser.call('Page.reload');await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);
    // Declared deterministic host input, outside the native helm region.
    // No cursor/game-memory assignment; original callers use their host callback.
    await browser.evaluate(`(async()=>{
      for(const type of ['pointermove','pointerdown','wheel','keydown'])document.addEventListener(type,event=>event.stopImmediatePropagation(),true);
      tact.state.options.getCursorPos=()=>({x:0,y:0});
      const {handleMouseMove}=await import('./src/engine/mouse.js');
      handleMouseMove(tact.state.memory,0,0,0,tact.state.options);
    })()`);
    const healthy=async()=>{const error=await browser.evaluate('tact.state.error');if(error)throw new Error(error);};
    const held=async()=>{await browser.waitFor('paintSetupGate.queued===1||tact.state.error',60000);await healthy();};
    const step=async label=>{await held();await browser.evaluate(`paintSetupGate.step(${JSON.stringify(label)})`);await healthy();};
    const command=async id=>{await browser.evaluate(`tact.command(${id})`);await browser.evaluate('tact.requestPaint()');await healthy();};
    const key=async(code,key,keyCode)=>{if(!Number.isSafeInteger(keyCode))throw new Error('Invalid original key');await browser.evaluate(`(async()=>{const {handleKeyDown}=await import('./src/engine/keyboard.js');handleKeyDown(tact.state.memory,${keyCode},tact.state.options);})()`);};
    const initialSetup=setup?await runDeterministicPaintSetup(browser,{addresses,commands:[32799,32816,32789,fleet===5?32806:32808,32909],key,noAutoSlow:true}):null;
    return {browser,setup:initialSetup,step,command,key,held,snapshot:()=>browser.evaluate(deterministicSetupSnapshotExpression(addresses)),
      async modules(){const pin=JSON.parse(await readFile(new URL('../analysis/baseline/reference.json',import.meta.url)));const loaded=new Map(browser.events.filter(e=>e.method==='Network.responseReceived'&&/\.js(?:\?|$)/.test(e.params.response.url)).map(e=>[e.params.response.url,e.params.requestId]));const rows=[];for(const [url,requestId]of loaded){const {body,base64Encoded}=await browser.call('Network.getResponseBody',{requestId});const bytes=Buffer.from(body,base64Encoded?'base64':'utf8'),path=new URL(url).pathname.slice(1),sha256=createHash('sha256').update(bytes).digest('hex'),expected=pin.files.find(f=>f.path===path);rows.push({path,sha256,bytes:bytes.length,matched:sha256===expected?.sha256&&bytes.length===expected?.bytes});}if(!rows.length||rows.some(r=>!r.matched))throw new Error('Loaded module differs from frozen reference');return rows;},
      close:()=>browser.close()};
  }catch(error){await browser.close();throw error;}
}
export async function closeReferenceServer(){if(server){await new Promise(r=>server.close(r));server=null;}}
