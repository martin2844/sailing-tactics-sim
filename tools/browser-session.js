import { spawn,execFile } from 'node:child_process';
import { mkdtemp,rm } from 'node:fs/promises';
import { tmpdir } from 'node:os';
import { join } from 'node:path';
import { setTimeout as pause } from 'node:timers/promises';
import {promisify} from 'node:util';

const executeFile=promisify(execFile);

const positiveDuration=(value,name)=>{
  if(!Number.isSafeInteger(value)||value<1||value>2147483647)throw new TypeError(`${name} must be a finite positive integer`);
  return value;
};
function launchConfiguration(url,options){
  if(typeof url!=='string'||!url)throw new TypeError('Browser URL must be a nonempty string');
  if(options===null||typeof options!=='object')throw new TypeError('Browser options must be an object');
  const {headless=true,gpu=false,width,height,ensureWindowSize=true,requestTimeoutMs=30000,startupTimeoutMs=20000}=options;
  if(typeof headless!=='boolean'||typeof gpu!=='boolean'||typeof ensureWindowSize!=='boolean')throw new TypeError('headless, gpu and ensureWindowSize must be booleans');
  if((width===undefined)!==(height===undefined))throw new TypeError('Both browser window dimensions must be supplied');
  for(const [name,value]of [['width',width],['height',height]])if(value!==undefined
    &&(!Number.isSafeInteger(value)||value<1||value>16384))throw new TypeError(`${name} must be an integer from 1 to 16384`);
  return {url,headless,gpu,ensureWindowSize,width:width??null,height:height??null,
    requestTimeoutMs:positiveDuration(requestTimeoutMs,'requestTimeoutMs'),
    startupTimeoutMs:positiveDuration(startupTimeoutMs,'startupTimeoutMs'),
    executable:process.env.TACT_CHROME??'/etc/profiles/per-user/martin/bin/google-chrome'};
}

async function sizeOwnedWindow(browserCall,metadata){
  const requested=metadata.requested;
  if(requested.headless||requested.width===null||!requested.ensureWindowSize)return;
  const sizing=metadata.windowSizing={requested:{width:requested.width,height:requested.height},
    before:metadata.window?.bounds,actions:[],status:'pending'};
  if(!metadata.window?.windowId)throw new Error('Chrome did not expose its owned window for sizing');
  const windowId=metadata.window.windowId,ownedPids=new Set([metadata.processId]);
  const hyprland=Boolean(process.env.HYPRLAND_INSTANCE_SIGNATURE);
  const clients=async()=>JSON.parse((await executeFile('hyprctl',['-j','clients'],{timeout:2000,maxBuffer:1024*1024})).stdout);
  const ownClient=async()=>{
    const found=(await clients()).filter(client=>ownedPids.has(client.pid)&&client.mapped!==false&&/^0x[0-9a-f]+$/i.test(client.address));
    if(found.length>1)throw new Error('Owned Chrome exposes multiple compositor windows; refusing ambiguous resize');
    return found[0];
  };
  const dispatch=async(command,args,client)=>{
    const current=await ownClient();
    if(!current||current.address!==client.address||current.pid!==client.pid)throw new Error('Owned Chrome window changed before compositor resize');
    // Hyprland 0.55 uses a Lua dispatcher expression. The window selector is
    // always the validated address belonging to this session's browser PID.
    const window=`"address:${client.address}"`;
    const dimensions=args.match(/^exact ([0-9]+) ([0-9]+),address:0x[0-9a-f]+$/i);
    const expression=command==='setfloating'?`hl.dsp.window.float({action="on",window=${window}})`
      :command==='fullscreenstate'?`hl.dsp.window.fullscreen_state({action="set",internal=0,client=0,window=${window}})`
      :command==='resizewindowpixel'&&dimensions?`hl.dsp.window.resize({x=${dimensions[1]},y=${dimensions[2]},window=${window}})`
      :undefined;
    if(!expression)throw new Error('Unsupported owned Chrome compositor operation');
    let output;
    if(command!=='fullscreenstate'&&sizing.syntax!=='lua'){
      try{output=await executeFile('hyprctl',['dispatch',command,args],{timeout:2000,maxBuffer:16384});}
      catch(error){if(!/hl\.dispatch|expected near|syntax/i.test(String(error.stdout??error.message)))throw error;output={stdout:error.stdout??''};}
      if(output.stdout.trim()==='ok')sizing.syntax='legacy';
      else if(/hl\.dispatch|expected near|syntax/i.test(output.stdout)){sizing.syntax='lua';output=undefined;}
      else throw new Error(`Owned Chrome compositor ${command} failed: ${output.stdout.trim()}`);
    }
    if(!output)output=await executeFile('hyprctl',['dispatch',expression],{timeout:2000,maxBuffer:16384});
    if(output.stdout.trim()!=='ok')throw new Error(`Owned Chrome compositor ${command} failed: ${output.stdout.trim()}`);
    sizing.actions.push({method:'hyprctl',command,args,expression,address:client.address,processId:client.pid});
  };
  try{
    let client;
    if(hyprland){
      const processInfo=await browserCall('SystemInfo.getProcessInfo');
      const actualPid=processInfo.processInfo?.find(row=>row.type==='browser')?.id;
      if(Number.isSafeInteger(actualPid)&&actualPid>0){ownedPids.add(actualPid);metadata.browserProcessId=actualPid;}
      for(let attempt=0;attempt<20&&!client;attempt++){client=await ownClient();if(!client)await pause(50);}
      if(!client)throw new Error('Hyprland did not expose a window belonging to the owned Chrome process');
      sizing.compositor='Hyprland';
      if(!client.floating)await dispatch('setfloating',`address:${client.address}`,client);
      if(sizing.syntax==='lua')await dispatch('fullscreenstate',`0 0,address:${client.address}`,client);
    }else{
      await browserCall('Browser.setWindowBounds',{windowId,bounds:{windowState:'normal'}});
      await browserCall('Browser.setWindowBounds',{windowId,bounds:{width:requested.width,height:requested.height}});
      sizing.actions.push({method:'Browser.setWindowBounds',windowId,width:requested.width,height:requested.height});
    }
    for(let attempt=0;attempt<4;attempt++){
      await pause(100);
      const {bounds}=await browserCall('Browser.getWindowBounds',{windowId});
      metadata.window={windowId,bounds};sizing.after=bounds;
      if(bounds.width===requested.width&&bounds.height===requested.height){sizing.status='matched';return;}
      if(hyprland&&attempt<3){
        client=await ownClient();
        if(!client||!Array.isArray(client.size))throw new Error('Owned Chrome compositor dimensions are unavailable');
        const width=client.size[0]+requested.width-bounds.width,height=client.size[1]+requested.height-bounds.height;
        if(!Number.isSafeInteger(width)||!Number.isSafeInteger(height)||width<1||height<1||width>16384||height>16384)throw new Error('Owned Chrome compositor size adjustment is outside bounds');
        await dispatch('resizewindowpixel',`exact ${width} ${height},address:${client.address}`,client);
      }
    }
    throw new Error(`Chrome window dimensions do not match: requested ${requested.width}x${requested.height}, observed ${sizing.after?.width}x${sizing.after?.height}`);
  }catch(error){sizing.status='failed';sizing.error=String(error);error.browserMetadata=metadata;throw error;}
}
const waitForExit=(child,timeout)=>new Promise(resolve=>{
  if(child.pid===undefined||child.exitCode!==null||child.signalCode!==null){resolve(true);return;}
  const finish=value=>{clearTimeout(timer);child.removeListener('exit',exited);resolve(value);};
  const exited=()=>finish(true),timer=setTimeout(()=>finish(false),timeout);
  child.once('exit',exited);
});

async function connect(endpoint,timeout,label){
  const socket=new WebSocket(endpoint),pending=new Map(),events=[];
  let id=0,closed=false;
  const rejectPending=error=>{
    for(const job of pending.values()){clearTimeout(job.timer);job.reject(error);}
    pending.clear();
  };
  socket.addEventListener('message',event=>{
    let message;
    try{message=JSON.parse(event.data);}catch(error){rejectPending(error);return;}
    if(message.method)events.push(message);
    if(message.id){
      const job=pending.get(message.id);if(!job)return;
      pending.delete(message.id);clearTimeout(job.timer);
      if(message.error)job.reject(new Error(JSON.stringify(message.error)));else job.resolve(message.result);
    }
  });
  socket.addEventListener('close',()=>{closed=true;rejectPending(new Error(`${label} DevTools connection closed`));});
  socket.addEventListener('error',()=>rejectPending(new Error(`${label} DevTools connection failed`)));
  try{
    await new Promise((resolve,reject)=>{
      const finish=error=>{clearTimeout(timer);socket.removeEventListener('open',opened);socket.removeEventListener('error',failed);socket.removeEventListener('close',failed);error?reject(error):resolve();};
      const opened=()=>finish(),failed=()=>finish(new Error(`${label} DevTools connection failed`));
      const timer=setTimeout(()=>finish(new Error(`${label} DevTools connection timed out`)),timeout);
      socket.addEventListener('open',opened,{once:true});socket.addEventListener('error',failed,{once:true});socket.addEventListener('close',failed,{once:true});
    });
  }catch(error){socket.close();throw error;}
  const call=(method,params={}, {timeoutMs=timeout}={})=>new Promise((resolve,reject)=>{
    positiveDuration(timeoutMs,'timeoutMs');
    if(closed||socket.readyState!==WebSocket.OPEN){reject(new Error(`${label} DevTools connection closed`));return;}
    const current=++id,timer=setTimeout(()=>{
      pending.delete(current);reject(new Error(`${label} CDP request timed out after ${timeoutMs} ms: ${method}`));
    },timeoutMs);
    pending.set(current,{resolve,reject,timer});
    try{socket.send(JSON.stringify({id:current,method,params}));}
    catch(error){pending.delete(current);clearTimeout(timer);reject(error);}
  });
  const close=()=>{closed=true;rejectPending(new Error(`${label} DevTools connection closed`));socket.close();};
  return {call,events,close};
}

/** Local Chrome session for native JS rendering and input comparisons. */
export async function openBrowser(url,options={}){
  const requested=launchConfiguration(url,options);
  const profile=await mkdtemp(join(tmpdir(),'tact-browser-'));
  const args=[...(requested.headless?['--headless=new']:[]),...(requested.gpu?[]:['--disable-gpu']),
    '--no-sandbox','--remote-debugging-port=0','--no-first-run',`--user-data-dir=${profile}`,
    ...(requested.width===null?[]:[`--window-size=${requested.width},${requested.height}`]),'about:blank'];
  const chrome=spawn(requested.executable,args,{stdio:['ignore','ignore','pipe']});
  let stderr='',pageConnection,browserConnection,closing;
  const close=()=>closing??=(async()=>{
    pageConnection?.close();browserConnection?.close();
    chrome.kill();
    if(!await waitForExit(chrome,3000)){chrome.kill('SIGKILL');await waitForExit(chrome,1000);}
    await rm(profile,{recursive:true,force:true}).catch(()=>{});
  })();
  try{
    const endpoint=await new Promise((resolve,reject)=>{
      const finish=(error,endpoint)=>{clearTimeout(timer);chrome.removeListener('error',failed);chrome.removeListener('exit',exited);error?reject(error):resolve(endpoint);};
      const failed=error=>finish(error),exited=code=>finish(new Error(`Chrome exited ${code}: ${stderr.slice(-500)}`));
      const timer=setTimeout(()=>finish(new Error(`Chrome did not start DevTools: ${stderr.slice(-500)}`)),requested.startupTimeoutMs);
      chrome.once('error',failed);chrome.once('exit',exited);
      chrome.stderr.on('data',chunk=>{stderr=(stderr+chunk).slice(-16000);const match=stderr.match(/DevTools listening on (ws:\/\/\S+)/);if(match)finish(null,match[1]);});
    });
    const host=new URL(endpoint).host;
    const response=await fetch(`http://${host}/json/list`,{signal:AbortSignal.timeout(requested.startupTimeoutMs)});
    if(!response.ok)throw new Error(`Chrome target listing failed: ${response.status}`);
    const pages=await response.json(),page=pages.find(row=>row.type==='page');
    if(!page?.webSocketDebuggerUrl)throw new Error('Chrome did not expose a page target');
    browserConnection=await connect(endpoint,requested.requestTimeoutMs,'Browser');
    pageConnection=await connect(page.webSocketDebuggerUrl,requested.requestTimeoutMs,'Page');
    const {call,events}=pageConnection,browserCall=browserConnection.call;
    const metadata={requested:{...requested,args,profile},processId:chrome.pid,errors:{}};
    const values=await Promise.allSettled([browserCall('Browser.getVersion'),browserCall('SystemInfo.getInfo'),browserCall('Browser.getWindowForTarget',{targetId:page.id})]);
    for(const [index,name]of ['version','systemInfo','window'].entries()){
      const value=values[index];if(value.status==='fulfilled')metadata[name]=value.value;else metadata.errors[name]=String(value.reason);
    }
    await sizeOwnedWindow(browserCall,metadata);
    const evaluate=async(expression,{awaitPromise=true,timeoutMs=requested.requestTimeoutMs}={})=>{const result=await call('Runtime.evaluate',{expression,returnByValue:true,awaitPromise},{timeoutMs});if(result.exceptionDetails)throw new Error(JSON.stringify(result.exceptionDetails));return result.result.value;};
    const waitFor=async(expression,timeout=20000)=>{const end=Date.now()+positiveDuration(timeout,'waitFor timeout');while(Date.now()<end){if(await evaluate(expression,{timeoutMs:Math.max(1,Math.min(requested.requestTimeoutMs,end-Date.now()))}))return;await pause(Math.min(100,Math.max(0,end-Date.now())));}throw new Error(`Browser condition timed out: ${expression}`);};
    await call('Runtime.enable');await call('Page.enable');await call('Network.enable');
    await call('Page.navigate',{url});
    await waitFor(`location.href===${JSON.stringify(url)}&&document.readyState!=='loading'`);
    if(!requested.headless)await call('Page.bringToFront');
    metadata.viewport=await evaluate('({width:innerWidth,height:innerHeight,outerWidth,outerHeight,devicePixelRatio,visibilityState:document.visibilityState,focused:document.hasFocus()})');
    return{call,browserCall,evaluate,waitFor,events,metadata,close};
  }catch(error){await close();throw error;}
}
