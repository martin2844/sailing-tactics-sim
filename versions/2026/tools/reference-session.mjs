import {readFile} from 'node:fs/promises';
import {createHash,randomUUID} from 'node:crypto';
import {openBrowser} from '../../../tools/browser-session.js';
import {paintMeasurementInstrumentation} from '../../../tools/paint-measurements.js';
import {deterministicPaintSetupInstrumentation,runDeterministicPaintSetup,deterministicSetupSnapshotExpression} from '../../../tools/deterministic-paint-setup.js';
export const addresses={time:0x5359f0,clock:0x4f8cd0,speed:0x4da174,divisor:0x4da178,racing:0x5363b0,mode:0x4da16c,notice:0x53648c,autoSlow:0x4da1dc,overlays:[0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c]};
let server;
export async function referenceSession({fleet=5,record='',before='',setup=true,headless=false,setupCommands,chartPointerRepair=false}={}){
  if(![5,15].includes(fleet))throw new Error('Unsupported candidate fleet');
  if(!server){process.env.TACT_PORT='0';process.env.TACT_HOST='127.0.0.1';({server}=await import('../../../tools/serve.js'));if(!server.listening)await new Promise((r,j)=>{server.once('listening',r);server.once('error',j);});}
  const browser=await openBrowser(`http://127.0.0.1:${server.address().port}/versions/2010-en/play.html`,{headless,gpu:true,width:1280,height:1051,requestTimeoutMs:60000});
  let interception,interceptionError,chartBody;const handled=new Set();
  try{
    if(chartPointerRepair){
      // Edgartown cannot run in the frozen translation: a native DWORD function
      // pointer was incorrectly concatenated into a double. This declared
      // two-expression response adapter does not edit the preserved source.
      const source=await readFile(new URL('../../2010-en/src/render/drawing-functions.js',import.meta.url),'utf8');
      let corrected=source;for(const store of [
        'writeLocal(framePointer(localFrame,260),bitsAsF64(cConcat(cRawWord(readPointer(memory,pointerAdd(framePointer(localFrame,260),4),4)),cRawWord(dcMethod(dc,100,memory)),4,4)),8,"float")',
        'writeLocalFloatNumber(framePointer(localFrame,260),wordsAsF64Number(cRawWord(readPointer(memory,pointerAdd(framePointer(localFrame,260),4),4)),cRawWord(dcMethod(dc,100,memory))))',
      ]){if(corrected.split(store).length!==2)throw Error('Original pointer repair source changed');corrected=corrected.replace(store,'writeLocal(framePointer(localFrame,260),dcMethod(dc,100,memory),4,"int")');}
      chartBody={bytes:Buffer.byteLength(corrected),sha256:createHash('sha256').update(corrected).digest('hex')};
      await browser.call('Network.setCacheDisabled',{cacheDisabled:true});await browser.call('Fetch.enable',{patterns:[{urlPattern:'*drawing-functions.js',requestStage:'Request'}]});
      interception=setInterval(()=>{for(const e of browser.events){if(e.method!=='Fetch.requestPaused'||handled.has(e.params.requestId))continue;handled.add(e.params.requestId);browser.call('Fetch.fulfillRequest',{requestId:e.params.requestId,responseCode:200,responseHeaders:[{name:'Content-Type',value:'application/javascript'}],body:Buffer.from(corrected).toString('base64')}).catch(error=>{if(!String(error).includes('Invalid InterceptionId'))interceptionError=error;});}},20);
    }
    await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});
    const instrumentation=paintMeasurementInstrumentation(record,{setupGate:true});
    if(!instrumentation.includes('const start=performance.now();callback(...args);'))throw new Error('Unknown paint instrument contract');
    const documentToken=randomUUID();
    await browser.call('Page.addScriptToEvaluateOnNewDocument',{source:`globalThis.referenceEvaluationDocumentToken=${JSON.stringify(documentToken)};`+deterministicPaintSetupInstrumentation()+instrumentation.replace('const start=performance.now();callback(...args);',`const start=performance.now();${before};callback(...args);`)});
    await browser.call('Page.reload');await browser.waitFor(`globalThis.referenceEvaluationDocumentToken===${JSON.stringify(documentToken)}&&(globalThis.tact?.state.ready||globalThis.tact?.state.error)`,60000);const initializationError=await browser.evaluate('tact.state.error');if(initializationError)throw Error(initializationError);
    // Declared deterministic host input, outside the native helm region.
    // No cursor/game-memory assignment; original callers use their host callback.
    await browser.evaluate(`(async()=>{
      for(const type of ['pointermove','pointerdown','wheel','keydown'])document.addEventListener(type,event=>event.stopImmediatePropagation(),true);
      tact.state.options.getCursorPos=()=>({x:0,y:0});
      const {handleMouseMove}=await import('./src/engine/mouse.js');
      handleMouseMove(tact.state.memory,0,0,0,tact.state.options);
    })()`);
    const healthy=async()=>{if(interceptionError)throw interceptionError;const error=await browser.evaluate('tact.state.error');if(error)throw new Error(error);};
    const held=async()=>{await browser.waitFor('paintSetupGate.queued===1||tact.state.error',60000);await healthy();};
    const step=async label=>{await held();await browser.evaluate(`paintSetupGate.step(${JSON.stringify(label)})`);await healthy();};
    const command=async id=>{await browser.evaluate(`tact.command(${id})`);await browser.evaluate('tact.requestPaint()');await healthy();};
    const key=async(code,key,keyCode)=>{if(!Number.isSafeInteger(keyCode))throw new Error('Invalid original key');await browser.evaluate(`(async()=>{const {handleKeyDown}=await import('./src/engine/keyboard.js');handleKeyDown(tact.state.memory,${keyCode},tact.state.options);})()`);};
    // Declared oracle compatibility: the original recovered Float80 rejects
    // masked x87 invalid operations. Only native 0x465e90 immediately converts
    // this negative FSQRT to __ftol's integer-indefinite (low DWORD zero).
    // Corroborated by executable instructions and an actual x87 FISTP probe.
    await browser.evaluate(`(async()=>{const {Float80}=await import('/src/runtime/float80.js');const sqrt=Float80.prototype.sqrt;Float80.prototype.sqrt=function(){if(this.sign<0&&new Error().stack.includes('originalDrawing00465e90'))return Float80.fromNumber(-9223372036854775808);return sqrt.call(this);};})()`);
    const initialSetup=setup?await runDeterministicPaintSetup(browser,{addresses,commands:setupCommands??[32799,32816,32789,fleet===5?32806:32808,32909],key,noAutoSlow:true}):null;
    return {browser,setup:initialSetup,step,command,key,held,snapshot:()=>browser.evaluate(deterministicSetupSnapshotExpression(addresses)),
      async modules(){const pin=JSON.parse(await readFile(new URL('../analysis/baseline/reference.json',import.meta.url)));const loaded=new Map(browser.events.filter(e=>e.method==='Network.responseReceived'&&/\.js(?:\?|$)/.test(e.params.response.url)).map(e=>[e.params.response.url,e.params.requestId]));const rows=[];for(const [url,requestId]of loaded){const {body,base64Encoded}=await browser.call('Network.getResponseBody',{requestId});const bytes=Buffer.from(body,base64Encoded?'base64':'utf8'),path=new URL(url).pathname.slice(1),sha256=createHash('sha256').update(bytes).digest('hex'),expected=pin.files.find(f=>f.path===path);const originalMatched=sha256===expected?.sha256&&bytes.length===expected?.bytes,declaredChartRepair=path==='versions/2010-en/src/render/drawing-functions.js'&&sha256===chartBody?.sha256&&bytes.length===chartBody?.bytes;rows.push({path,sha256,bytes:bytes.length,matched:originalMatched||declaredChartRepair,originalMatched,...(declaredChartRepair?{adapter:'Declared native Edgartown DWORD pointer-store response repair',sourceSha256:expected.sha256}:{})});}if(!rows.length||rows.some(r=>!r.matched))throw new Error('Loaded module differs from frozen reference');return rows;},
      close:()=>{clearInterval(interception);return browser.close()}};
  }catch(error){clearInterval(interception);const originalStack=await browser.evaluate('document.getElementById("error")?.textContent').catch(()=>null);if(originalStack)error.message+='\nOriginal stack: '+originalStack;await browser.close();throw error;}
}
export async function closeReferenceServer(){if(server){await new Promise(r=>server.close(r));server=null;}}
