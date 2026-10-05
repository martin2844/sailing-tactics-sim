import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {openBrowser} from '../../../tools/browser-session.js';
import {referenceSession,closeReferenceServer} from './reference-session.mjs';
const out=resolve(process.argv[2]??''),fleet=Number(process.argv[3]??5);if(process.argv.length<3||![5,15].includes(fleet))throw new Error('Usage: hotkeys-eval.mjs NEW_DIRECTORY [FLEET=5]');await mkdir(out);
const entries=[['Comma',',',188],['Period','.',190],['Quote',"'",222],['Enter','Enter',13],...['C','T','H','J','D','S','A','I','O','E','P','G','U'].map(v=>['Key'+v,v.toLowerCase(),v.charCodeAt(0)]),['Escape','Escape',27],['Backquote','`',192],...Array.from({length:5},(_,n)=>['F'+(n+1),'F'+(n+1),112+n]),['ArrowLeft','ArrowLeft',37],['ArrowRight','ArrowRight',39],['ArrowUp','ArrowUp',38],['ArrowDown','ArrowDown',40],['Home','Home',36],['Numpad5','Clear',12],...Array.from({length:10},(_,n)=>['Digit'+n,String(n),48+n]),...['V','X','Z','L','F'].map(v=>['Key'+v,v.toLowerCase(),v.charCodeAt(0)]),['KeyF','f',70],['Space',' ',32],['Space',' ',32],['PageUp','PageUp',33],['PageDown','PageDown',34],['Backslash','\\',220],['CapsLock','CapsLock',20],['Semicolon',';',186],['Backspace','Backspace',8],['KeyW','w',87],['Space',' ',32],['KeyR','r',82],['Space',' ',32],['BracketLeft','[',219],['Space',' ',32],['BracketRight',']',221],['Equal','=',187],['Minus','-',189],['Space',' ',32],['Slash','?',191],['Space',' ',32],['KeyY','y',89],['Space',' ',32],['F12','F12',123],['KeyN','n',78],...['B','P','L','M','S','Z','C'].map(v=>['Key'+v,v.toLowerCase(),v.charCodeAt(0)]),['Space',' ',32],['Space',' ',32]];
let candidate,reference;const checks=[];
try{
 reference=await referenceSession({fleet,headless:true});await reference.command(32850);
 candidate=await openBrowser('http://127.0.0.1:8770/?manual&fleet='+fleet,{headless:true,gpu:true,width:1280,height:1051,requestTimeoutMs:60000});
 await candidate.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});
 await candidate.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 async function compare(label){const original={...await reference.snapshot(),shore:await reference.browser.evaluate('tact.state.options.shoreStack.snapshot()')},actual=await candidate.evaluate('tact2026.engine.request("boundary")');for(const k of ['frame','time','clock','rngState','memorySha256','shore'])if(JSON.stringify(original[k])!==JSON.stringify(actual[k]))throw new Error('Native key mismatch '+label+' '+k);return actual;}
 await compare('initial');
 for(let n=0;n<entries.length;n++){
   const [code,key,vk]=entries[n];await candidate.evaluate('document.getElementById("scene").focus()');
   await reference.key(code,key,vk);
   await candidate.call('Input.dispatchKeyEvent',{type:'keyDown',code,key,windowsVirtualKeyCode:vk,nativeVirtualKeyCode:vk});
   await candidate.call('Input.dispatchKeyEvent',{type:'keyUp',code,key,windowsVirtualKeyCode:vk,nativeVirtualKeyCode:vk});
   const boundary=await compare('key '+code+' '+n);
   // The frozen port crashes rendering CapsLock's true-wind label. Its key
   // handler is still compared exactly, then toggled off before paired paints.
   // The candidate's assembly-grounded label repair is checked separately.
   if(vk===20){await reference.key(code,key,vk);await candidate.evaluate('tact2026.engine.send("key",20)');}
   await reference.step('hotkey '+n);await candidate.evaluate('tact2026.engine.request("step",1)');
   await candidate.waitFor('tact2026.error||tact2026.scene.modelSequence===tact2026.latest.sequence',60000);
   const error=await candidate.evaluate('tact2026.error');if(error)throw new Error(error);
   const painted=await compare('paint '+code+' '+n),state=await candidate.evaluate('({view:tact2026.latest.view,panel:tact2026.latest.panel,sheet:tact2026.latest.sheet,shape:tact2026.latest.sailShape,pace:tact2026.latest.pace,frozen:tact2026.latest.frozen})');
   if(state.panel){await candidate.waitFor('document.getElementById("native-screen").getContext("2d").getImageData(0,0,1,1).data[3]>0',10000);await writeFile(resolve(out,n+'-'+code+'.png'),Buffer.from((await candidate.call('Page.captureScreenshot',{format:'png'})).data,'base64'));}
   checks.push({code,key,vk,boundary,painted,state});console.log(JSON.stringify({n,code,vk,panel:state.panel,matched:true}));
 }
 // Text entry and browser navigation must not reach the simulation.
 const before=await candidate.evaluate('tact2026.engine.request("boundary")');
 await candidate.evaluate('(()=>{const i=document.createElement("input");i.id="key-test";document.body.append(i);i.focus();})()');
 await candidate.call('Input.dispatchKeyEvent',{type:'keyDown',code:'KeyT',key:'t',windowsVirtualKeyCode:84});
 await candidate.call('Input.dispatchKeyEvent',{type:'keyUp',code:'KeyT',key:'t',windowsVirtualKeyCode:84});
 const after=await candidate.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw new Error('Typing leaked to native controls');
 await candidate.evaluate('tact2026.restart()');await candidate.waitFor('tact2026.ready||tact2026.error',60000);
 await candidate.evaluate('tact2026.engine.send("key",20)');await candidate.evaluate('tact2026.engine.request("step",1)');
 const windError=await candidate.evaluate('tact2026.error');if(windError)throw new Error('Repaired native true-wind paint failed: '+windError);
 const label=await candidate.evaluate(`(async()=>{const {fetchOriginalData}=await import('/legacy/versions/2010-en/src/runtime/original-data.js'),{GdiTrace}=await import('/legacy/src/render/gdi.js'),{originalDrawing0048b7e0}=await import('/legacy/versions/2010-en/src/render/drawing-functions.js');const memory=await fetchOriginalData(),dc=new GdiTrace();memory.writeI32(0x4fe2a8,723);memory.writeI32(0x51158c,17);const bytes=memory.bytes.slice();originalDrawing0048b7e0(memory,dc,null,{},dc);return {events:dc.events,unchanged:bytes.every((v,i)=>v===memory.bytes[i])};})()`);
 if(!label.unchanged||label.events.length!==2||label.events[0].op!=='setTextColor'||label.events[0].color!==0||label.events[1].op!=='textOut'||label.events[1].x!==10||label.events[1].y!==64||!label.events[1].text.endsWith('17'))throw new Error('Wind label differs from reviewed native instructions');
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,fleet,scope:'Trusted native hotkeys: exact whole-image/RNG/shore state after each key and paired paint. CapsLock key is compared, then disabled before paired paint because the frozen port crashes its label; candidate repaired paint and native GDI call contract checked separately.',checks,textEntry:{before,after},nativeLabelRepair:label,referenceModules:await reference.modules()},null,2));
}catch(error){await writeFile(resolve(out,'failure.txt'),error.stack);await writeFile(resolve(out,'partial.json'),JSON.stringify(checks,null,2));if(reference)await writeFile(resolve(out,'reference-errors.json'),JSON.stringify(reference.browser.events.filter(v=>v.method==='Runtime.consoleAPICalled'||v.method==='Runtime.exceptionThrown'),null,2));if(candidate)await writeFile(resolve(out,'failure.png'),Buffer.from((await candidate.call('Page.captureScreenshot',{format:'png'})).data,'base64'));throw error;}finally{await candidate?.close();await reference?.close();await closeReferenceServer();}
