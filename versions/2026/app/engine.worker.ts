// Bounded compatibility bridge. The original modules are external, byte-exact JS.
// No authoritative image, RNG, ticks or retained locals are owned by the UI.
import type {SceneSnapshot,Boundary} from './protocol';
import {commands} from './protocol';
let memory:any,rng:any,options:any,objects:any,font:any,paintClock:any;
let lifecycle:any,gdi:any,resetSurface:any,menu:any,key:any;
let generation=0,frame=0,paused=true,failed=false,ready=false,delay=0,timer:ReturnType<typeof setTimeout>|undefined;
let front:OffscreenCanvas,back:OffscreenCanvas,frontContext:OffscreenCanvasRenderingContext2D,backContext:OffscreenCanvasRenderingContext2D;
const queue=new MessageChannel();let pending=false,scheduleToken=0;
queue.port1.onmessage=event=>{if(event.data!==scheduleToken)return;pending=false;if(ready&&!paused&&!failed)tick();};
const allowed=new Set<number>([...Object.values(commands),32872,32876,32909]);
const send=(type:string,data:unknown)=>self.postMessage({type,generation,data});
function fail(error:unknown){failed=true;paused=true;clearTimeout(timer);send('error',error instanceof Error?error.stack:String(error));}
function schedule(wait:number){
  if(paused||failed||pending)return;
  pending=true;const token=++scheduleToken;
  if(wait>0)timer=setTimeout(()=>{if(token!==scheduleToken)return;pending=false;if(!paused&&!failed)tick();},wait);
  else queue.port2.postMessage(token);
}
function paint(){
  delay=0;paintClock.beginPaint();const start=performance.now();
  const dc=gdi(frontContext,{objects,bitmapFont:font,messageBeep:()=>{},recordEvents:false});dc.canvas=front;
  const host={constructBufferedDC(){const buffered=gdi(backContext,{objects,bitmapFont:font,messageBeep:()=>{},recordEvents:false,cachePixelReads:true});buffered.canvas=back;buffered.context=backContext;return buffered;},
    getDeviceCaps(_dc:any,index:number){return index===12?24:index===8?1024:768;},applicationInstance(){return 1;},createBitmap(descriptor:any){return descriptor;},attachBitmap(){},createCompatibleDC(){return 1;},attachCompatibleDC(){},
    selectBitmap(buffered:any,bitmap:any){if(bitmap)resetSurface(buffered.canvas,buffered.context,bitmap.width,bitmap.height);return 0;},
    bitBlt(_front:any,buffered:any,descriptor:any){if(front.width!==descriptor.width||front.height!==descriptor.height){front.width=descriptor.width;front.height=descriptor.height;frontContext.font='13px Arial';}frontContext.drawImage(buffered.canvas,0,0);},deleteBitmap(){},invalidateRect(){},destroyBufferedDC(){}};
  lifecycle(memory,dc,rng,{...options,host,cursor:{x:0,y:0}});frame++;
  delay=Math.max(delay,paintClock.minimumDuration());
  return performance.now()-start;
}
function snapshot(workMs:number):SceneSnapshot {
  const i=(a:number)=>memory.readI32(a),d=(a:number)=>memory.readF64(a);
  const boats=Array.from({length:i(0x4da194)},(_,index)=>{const id=index+1;return{id,x:d(0x4f6af8+id*8),y:d(0x4f6c10+id*8),heading:i(0x535740+id*4),speed:i(0x4fdfe8+id*4)/10,leg:i(0x4f8538+id*4),finished:i(0x4fe638+id*4)};});
  return {generation,sequence:frame,time:d(0x5359f0),clock:i(0x4f8cd0),pace:i(0x4da174),windDirection:i(0x5362d4),windStrength:i(0x522ad0),boats,
    marks:[[0x5229d4,0x522ac8],[0x522acc,0x522ae0],[0x5229c8,0x522ac4],[0x536410,0x536414],[0x4fe094,0x4fe2a0]].map(([x,y])=>({x:i(x),y:i(y)})),results:i(0x5363f4)!==0,workMs,minimumDelayMs:delay,sentAt:performance.timeOrigin+performance.now()};
}
async function boundary():Promise<Boundary>{
  const digest=new Uint8Array(await crypto.subtle.digest('SHA-256',memory.bytes.slice()));
  return {frame,time:memory.readF64(0x5359f0),clock:memory.readI32(0x4f8cd0),rngState:rng.state,memorySha256:[...digest].map(v=>v.toString(16).padStart(2,'0')).join(''),shore:options.shoreStack.snapshot()};
}
function tick(){try{const duration=paint();send('snapshot',snapshot(duration));if(memory.readI32(0x5363f4)!==0){paused=true;send('paused',true);}else schedule(Math.max(0,delay-duration));}catch(error){fail(error);}}
async function initialize(data:any){
  if(ready||memory)throw new Error('Worker cannot initialize twice');
  generation=data.generation;
  const base=new URL(data.legacyBase),load=(path:string)=>import(/* @vite-ignore */new URL(path,base).href);
  const json=async(path:string)=>{const response=await fetch(new URL(path,base));if(!response.ok)throw new Error('Asset load failed: '+path);return response.json();};
  const edition='versions/2010-en/';
  const [original,clock,surface,float,integer,trig,bindings,application,keyboard,mouse,controller,renderer,paintModule,gdiModule,bitmap,tables,extended,stored,shore]=await Promise.all([
    load(edition+'src/runtime/original-data.js'),load(edition+'src/runtime/browser-clock.js'),load(edition+'src/runtime/canvas-surface.js'),load('src/runtime/float80.js'),load('src/engine/integer-core.js'),load(edition+'src/engine/native-trig.js'),load(edition+'src/engine/port.js'),load(edition+'src/engine/application.js'),load(edition+'src/engine/keyboard.js'),load(edition+'src/engine/mouse.js'),load(edition+'src/engine/menu-controller.js'),load(edition+'src/render/index.js'),load(edition+'src/render/paint-lifecycle.js'),load(edition+'src/render/gdi.js'),load('src/render/bitmap-font.js'),json(edition+'assets/data/trig-tables.json'),json(edition+'assets/data/x87-trig.json'),json(edition+'assets/data/x87-stored-trig.json'),json(edition+'assets/data/initial-shoreline-stack.json')]);
  memory=await original.fetchOriginalData();float.setX87ControlWord(0x027f);rng=new integer.PoseyRng();paintClock=clock.createPaintClock();
  font=await bitmap.fetchGdiBitmapFont({softwareAtlas:true,createSurface:(width:number,height:number)=>new OffscreenCanvas(width,height)});
  front=new OffscreenCanvas(1024,768);back=new OffscreenCanvas(1024,768);
  frontContext=front.getContext('2d')!;backContext=back.getContext('2d',{willReadFrequently:true})!;
  lifecycle=paintModule.paintLifecycle;gdi=gdiModule.createCanvasGdi;resetSurface=surface.resetBitmapSurface;menu=controller.handleMenuCommand;key=keyboard.handleKeyDown;
  const scenario=data.scenario;
  objects=application.initializeApplication(memory,rng,{preferences:null,timeSeed:scenario.seedTimeSeconds,screenHeight:768,integerTrig:tables});
  options={trig:trig.createCapturedTrig(extended,stored),...bindings.createEngineBindings(),...renderer.createOriginalRenderer({initialShoreStack:shore,smoothGraphics:true}),rng,
    playSound:()=>1,messageBeep:()=>{},beep:()=>{},dialogHandler:()=>{throw new Error('Original dialogs are unsupported in the worker spike');},getTickCount:paintClock.getTickCount,
    getCursorPos:()=>({x:0,y:0}),invalidateRect:()=>{},enforceMinimumPaintDuration:(duration:number)=>{delay=duration;},closeWindow:()=>{paused=true;},contextHelp:()=>{}};
  mouse.handleMouseMove(memory,0,0,0,options);
  paint();
  for(const id of scenario.setupCommands){await menu(memory,id,options);paint();}
  key(memory,32,options);
  for(let attempt=0;memory.readI32(0x5363b0)!==2&&attempt<4;attempt++)paint();
  if(memory.readI32(0x5363b0)!==2)throw new Error('Original race initialization failed');
  if([0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c].some(a=>memory.readI32(a)!==0)){key(memory,32,options);paint();}
  if(memory.readI32(0x4da1dc)!==0){await menu(memory,32984,options);paint();}
  for(const id of scenario.postSetupCommands)await menu(memory,id,options);
  const initial=await boundary(),expected=scenario.initialBoundary;
  if(initial.frame!==expected.frame||initial.memorySha256!==expected.memorySha256||initial.rngState!==expected.rngState||JSON.stringify(initial.shore)!==JSON.stringify(expected.shore))throw new Error('Worker initial state differs: '+JSON.stringify(initial));
  ready=true;send('ready',initial);send('snapshot',snapshot(0));paused=data.manual===true;
  if(!paused)schedule(0);
}
// Serialize commands, diagnostics and setup. Native callbacks never overlap.
let chain=Promise.resolve();
self.onmessage=(event:MessageEvent)=>{chain=chain.then(async()=>{
  const {type,data,id}=event.data;
  if(type==='init'){await initialize(data);return;}
  if(event.data.generation!==generation||!ready||failed)return;
  if(type==='pause'){paused=Boolean(data);if(paused){clearTimeout(timer);scheduleToken++;pending=false;}else schedule(0);send('paused',paused);}
  else if(type==='command'){if(!Number.isInteger(data)||!allowed.has(data))throw new Error('Unsupported native command');await menu(memory,data,options);send('accepted',{command:data,sequence:frame});}
  else if(type==='step'){if(!paused||!Number.isInteger(data)||data<1||data>200)throw new Error('Diagnostic steps require paused worker and 1..200 paints');let duration=0;for(let n=0;n<data;n++)duration=paint();send('snapshot',snapshot(duration));send('reply',{id,value:await boundary()});}
  else if(type==='boundary'){if(!paused)throw new Error('Boundary inspection requires pause');send('reply',{id,value:await boundary()});}
}).catch(fail);};
