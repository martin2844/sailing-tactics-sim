// Bounded compatibility bridge. Frozen source is verified before preparation;
// one generated drawing adapter observes boats and supports private 3D extraction.
// No authoritative image, RNG, ticks or retained locals are owned by the UI.
import type {SceneSnapshot,Boundary,CourseLine} from './protocol';
import {commands} from './protocol';
import {createNativeVisualObserver,packNativeVisuals} from './native-visuals';
import {createModelExtractor} from './native-models';
import {validateRaceSettings,raceSetupCommands,isAuditedPreset} from './race-settings';
import {evaluateEnvironmentCases} from './environment-cases';
import {readNativeTerrain} from './native-environment';
import {areaChoices,fleetChoices} from './native-catalog';
let memory:any,rng:any,options:any,objects:any,font:any,paintClock:any;
let lifecycle:any,gdi:any,resetSurface:any,menu:any,key:any,readCString:any;
let advanceTarget:any,drawResults:any,copyStrings:any,updateDynamics:any,sampleCurrent:any,sampleVenueCurrent:any;
let modelDraw:any,ModelMemory:any,ModelRng:any,TraceDc:any;
let modelExtractor:ReturnType<typeof createModelExtractor>;
let modelWorker:Worker,modelReady=false,modelBusy=false,modelSequence=-1,modelWidth=0;
let modelMutableBase=0,modelMutableSize=0;
let modelDirty=false,panelBusy=false;
let startingLine:CourseLine|undefined;
let resultsReady=false;
let generation=0,frame=0,paused=true,failed=false,ready=false,delay=0,timer:ReturnType<typeof setTimeout>|undefined;
let front:OffscreenCanvas,back:OffscreenCanvas,frontContext:OffscreenCanvasRenderingContext2D,backContext:OffscreenCanvasRenderingContext2D;
const queue=new MessageChannel();let pending=false,scheduleToken=0;
queue.port1.onmessage=event=>{if(event.data!==scheduleToken)return;pending=false;if(ready&&!paused&&!failed)tick();};
const visuals=createNativeVisualObserver();Object.assign(globalThis,{tactNativeVisuals:visuals});
function observeDc(dc:any){const emit=dc.emit;dc.emit=function(event:any){visuals.observe(event,this);return emit.call(this,event);};return dc;}
const allowed=new Set<number>([...Object.values(commands),32872,32876,32909,32918]);
const send=(type:string,data:any)=>{if(type==='snapshot'){const native=(data as SceneSnapshot).nativeVisuals;self.postMessage({type,generation,data},{transfer:[native.styles.buffer,native.geometry.buffer,native.boats.buffer]});}else if(type==='models'){const p=data.packet;self.postMessage({type,generation,data},{transfer:[p.positions.buffer,p.records.buffer,p.colors.buffer,p.boats.buffer]});}else self.postMessage({type,generation,data});};
function requestModels(){
  if(!ready||!modelReady||modelBusy||failed||!modelDirty&&modelSequence===frame)return;
  const calibration=visuals.frame(1024,361).boats.find(b=>b.id===1)?.calibration;if(calibration)modelWidth=calibration.width;
  if(!modelWidth)throw new Error('Missing native model calibration');
  const image=memory.readBytes(modelMutableBase,modelMutableSize).buffer;modelBusy=true;modelDirty=false;modelSequence=frame;
  modelWorker.postMessage({type:'frame',data:{generation,sequence:frame,image,rngState:rng.state,width:modelWidth,ids:Array.from({length:memory.readI32(0x4da194)},(_,i)=>i+1)}},{transfer:[image]});
}
function fail(error:unknown){failed=true;paused=true;clearTimeout(timer);send('error',error instanceof Error?error.stack:String(error));}
function schedule(wait:number){
  if(paused||failed||pending)return;
  pending=true;const token=++scheduleToken;
  if(wait>0)timer=setTimeout(()=>{if(token!==scheduleToken)return;pending=false;if(!paused&&!failed)tick();},wait);
  else queue.port2.postMessage(token);
}
function paint(){
  delay=0;visuals.clear();paintClock.beginPaint();const start=performance.now();
  const phase=memory.readI32(0x5363b0);
  const drawingResults=memory.readI32(0x5363f4)>0&&memory.readI32(0x5233a8)===0;
  const dc=observeDc(gdi(frontContext,{objects,bitmapFont:font,messageBeep:()=>{},recordEvents:false}));dc.canvas=front;
  const host={constructBufferedDC(){const buffered=observeDc(gdi(backContext,{objects,bitmapFont:font,messageBeep:()=>{},recordEvents:false,cachePixelReads:true}));buffered.canvas=back;buffered.context=backContext;return buffered;},
    getDeviceCaps(_dc:any,index:number){return index===12?24:index===8?1024:768;},applicationInstance(){return 1;},createBitmap(descriptor:any){return descriptor;},attachBitmap(){},createCompatibleDC(){return 1;},attachCompatibleDC(){},
    selectBitmap(buffered:any,bitmap:any){if(bitmap)resetSurface(buffered.canvas,buffered.context,bitmap.width,bitmap.height);return 0;},
    bitBlt(_front:any,buffered:any,descriptor:any){if(front.width!==descriptor.width||front.height!==descriptor.height){front.width=descriptor.width;front.height=descriptor.height;frontContext.font='13px Arial';}frontContext.drawImage(buffered.canvas,0,0);},deleteBitmap(){},invalidateRect(){},destroyBufferedDC(){}};
  lifecycle(memory,dc,rng,{...options,host,cursor:{x:0,y:0}});frame++;
  if(drawingResults)resultsReady=true;
  if(phase!==2&&memory.readI32(0x5363b0)===2)startingLine=courseLine();
  delay=Math.max(delay,paintClock.minimumDuration());
  return performance.now()-start;
}
function courseLine():CourseLine{return {a:{x:memory.readI32(0x536410),y:memory.readI32(0x536414)},b:{x:memory.readI32(0x4fe094),y:memory.readI32(0x4fe2a0)}};}
function snapshot(workMs:number):SceneSnapshot {
  const i=(a:number)=>memory.readI32(a),d=(a:number)=>memory.readF64(a);
  const boats=Array.from({length:i(0x4da194)},(_,index)=>{const id=index+1;return{id,name:readCString(memory,0x4fec30+id*4),x:d(0x4f6af8+id*8),y:d(0x4f6c10+id*8),heading:i(0x535740+id*4),speed:i(0x4fdfe8+id*4)/10,leg:i(0x4f8538+id*4),finished:i(0x4fe638+id*4),status:i(0x5116e0+id*4),finishTime:i(id===1?0x534d64:0x4f4350+id*4),points:[0,1,2].map(n=>i(0x4fbf24+id*16+n*4)),windFrom:i(0x522b90+id*4),windAngle:i(0x4fecc8+id*4),luff:i(0x512278+id*4),boomAngle:i(0x4fe818+id*4),tack:i(0x522ff0+id*4),depth:d(0x4ffcb8+id*8),trueWind:i(0x4fb380+id*4),currentSpeed:i(0x535a08+id*4)/10,currentDirection:i(0x522d30+id*4),grounded:i(0x5116e0+id*4)===10};});
  const owner=i(0x4da140),panel=panelTitle();
  const marks=[[0x5229d4,0x522ac8],[0x522acc,0x522ae0],[0x5229c8,0x522ac4],[0x536410,0x536414],[0x4fe094,0x4fe2a0]].map(([x,y])=>({x:i(x),y:i(y)})),finish=courseLine();
  return {environment:{waves:i(0x535e44),currentEffect:i(0x522fd8),gusts:Array.from({length:5},(_,index)=>{const n=index+1;return {x:d(0x535460+n*8),y:d(0x4f4b08+n*8),width:i(0x4f7ea0+n*4),strength:i(0x4f71d8+n*4)}})},generation,sequence:frame,time:d(0x5359f0),clock:i(0x4f8cd0),pace:i(0x4da174),windDirection:i(0x5362d4),windStrength:i(0x522ad0),boats,
    configuration:{course:i(0x4da188),wind:i(0x4da154),fleet:i(0x4da194),selector:i(0x4da144),area:i(0x4da19c),venue:i(0x4da1f8),mode:i(0x4da16c),gate:i(0x4da1e8)!==0,short:i(0x53640c)!==0},
    view:{lookDegrees:i(0x4f49a0+owner*4),lookMode:i(0x512d60+owner*4),viewpoint:i(0x4f71c0+owner*4),automatic:i(0x523a58+owner*4)!==0,otherBoat:i(0x5233a4),tacticalZoom:i(0x50f6d0+owner*4),tacticalOrientation:i(0x525a78+owner*4)},
    panel,sheet:i(0x500380+owner*4),sailShape:i(0x4fe778+owner*4),spinnaker:i(0x4f451c+owner*4)!==0,frozen:i(0x53642c)!==0,
    nativeVisuals:packNativeVisuals(visuals.frame(memory.readI32(0x4fe624),Math.trunc(memory.readI32(0x4fe2a8)/2))),marks,
    course:{marks:marks.slice(0,3),gate:i(0x4da1e8)?[{x:i(0x4f4a68),y:i(0x4f6d34)},{x:i(0x523248),y:i(0x52359c)}]:[],start:startingLine??finish,finish,committee:{...finish.a,heading:i(0x4f7f94)},target:{x:i(0x4f4d78+owner*4),y:i(0x4fc350+owner*4)},closeAngle:i(0x4f7200)+i(0x5359e0+owner*4),downwindAngle:i(0x4fae60+owner*4),showLaylines:i(0x536490)!==0,showMarkLines:i(0x4da184)!==0,length:i(0x525a9c)},
    results:i(0x5363f4)!==0,resultsReady,completedRaces:i(0x5363fc),seriesScoring:i(0x536424)===0,workMs,minimumDelayMs:delay,sentAt:performance.timeOrigin+performance.now()};
}
function panelTitle():string|null{
  const i=(a:number)=>memory.readI32(a);
  if(i(0x5363b0)<2)return 'Race setup';
  if(i(0x536444))return i(0x536444)===6?'Keyboard controls':i(0x536444)===300?'Coach':'Sailing guide';
  if(i(0x5363f0))return 'Weather forecast';
  if(i(0x5233a8))return 'Race course';
  if(i(0x536434))return 'Wind history';
  if(i(0x536438))return 'Current history';
  if(i(0x53644c))return 'Race results';
  return null;
}
function publishPanel(){
  const title=panelTitle();if(!title||panelBusy)return;
  panelBusy=true;const sequence=frame;
  // Copy rather than transferToImageBitmap: never clear the canonical surface.
  createImageBitmap(front).then(bitmap=>{if(!failed)self.postMessage({type:'panel',generation,data:{sequence,title,bitmap}},{transfer:[bitmap]});else bitmap.close();}).catch(fail).finally(()=>{panelBusy=false;});
}
async function boundary():Promise<Boundary>{
  const digest=new Uint8Array(await crypto.subtle.digest('SHA-256',memory.bytes.slice()));
  return {frame,time:memory.readF64(0x5359f0),clock:memory.readI32(0x4f8cd0),rngState:rng.state,memorySha256:[...digest].map(v=>v.toString(16).padStart(2,'0')).join(''),shore:options.shoreStack.snapshot()};
}
function tick(){try{let duration=paint();if(memory.readI32(0x5363f4)!==0&&!resultsReady)duration+=paint();send('snapshot',snapshot(duration));publishPanel();requestModels();if(memory.readI32(0x5363f4)!==0){paused=true;send('paused',true);}else schedule(Math.max(0,delay-duration));}catch(error){fail(error);}}
async function initialize(data:any){
  if(ready||memory)throw new Error('Worker cannot initialize twice');
  generation=data.generation;
  visuals.setRecording(data.manual===true);
  const base=new URL(data.legacyBase),load=(path:string)=>import(/* @vite-ignore */new URL(path,base).href);
  const json=async(path:string)=>{const response=await fetch(new URL(path,base));if(!response.ok)throw new Error('Asset load failed: '+path);return response.json();};
  const edition='versions/2010-en/';
  const text=await load(edition+'src/render/text.js');readCString=text.readCString;
  copyStrings=(source:any,target:any)=>{for(const {address,text:content}of text.originalCStringContents(source))text.writeCString(target,address,content);};
  updateDynamics=(await load(edition+'src/engine/boat-dynamics.js')).updateBoatDynamics;({sampleCurrent,sampleVenueCurrent}=await load(edition+'src/engine/current.js'));
  advanceTarget=(await load(edition+'src/engine/race-targets.js')).advanceRaceTarget;
  drawResults=(await load(edition+'src/render/screens.js')).drawResultsScreen;
  const [original,clock,surface,float,integer,trig,bindings,application,keyboard,mouse,controller,renderer,paintModule,gdiModule,bitmap,tables,extended,stored,shore]=await Promise.all([
    load(edition+'src/runtime/original-data.js'),load(edition+'src/runtime/browser-clock.js'),load(edition+'src/runtime/canvas-surface.js'),load('src/runtime/float80.js'),load('src/engine/integer-core.js'),load(edition+'src/engine/native-trig.js'),load(edition+'src/engine/port.js'),load(edition+'src/engine/application.js'),load(edition+'src/engine/keyboard.js'),load(edition+'src/engine/mouse.js'),load(edition+'src/engine/menu-controller.js'),load(edition+'src/render/index.js'),load(edition+'src/render/paint-lifecycle.js'),load(edition+'src/render/gdi.js'),load('src/render/bitmap-font.js'),json(edition+'assets/data/trig-tables.json'),json(edition+'assets/data/x87-trig.json'),json(edition+'assets/data/x87-stored-trig.json'),json(edition+'assets/data/initial-shoreline-stack.json')]);
  memory=await original.fetchOriginalData();float.setX87ControlWord(0x027f);rng=new integer.PoseyRng();paintClock=clock.createPaintClock();
  modelMutableBase=original.MUTABLE_BASE;modelMutableSize=original.MUTABLE_SIZE;
  const [modelModule,memoryModule]=await Promise.all([load(edition+'src/render/drawing-functions.js'),load('src/runtime/memory.js')]);
  modelDraw=modelModule.nativeModelDrawBoatNumber;ModelMemory=memoryModule.AddressSpaceMemory;ModelRng=integer.PoseyRng;TraceDc=gdiModule.GdiTrace;
  font=await bitmap.fetchGdiBitmapFont({softwareAtlas:true,createSurface:(width:number,height:number)=>new OffscreenCanvas(width,height)});
  front=new OffscreenCanvas(1024,768);back=new OffscreenCanvas(1024,768);
  frontContext=front.getContext('2d')!;backContext=back.getContext('2d',{willReadFrequently:true})!;
  lifecycle=paintModule.paintLifecycle;gdi=gdiModule.createCanvasGdi;resetSurface=surface.resetBitmapSurface;menu=controller.handleMenuCommand;key=keyboard.handleKeyDown;
  const scenario=data.scenario,settings=validateRaceSettings(data.settings);
  const fleet=data.fleet??scenario.configuration.fleet;if(!fleetChoices.some(f=>f.value===fleet))throw Error('Unsupported native fleet');
  if(settings.gate&&fleet<20)throw Error('Native gate requires at least 20 boats');
  objects=application.initializeApplication(memory,rng,{preferences:null,timeSeed:scenario.seedTimeSeconds,screenHeight:768,integerTrig:tables});
  options={trig:trig.createCapturedTrig(extended,stored),...bindings.createEngineBindings(),...renderer.createOriginalRenderer({initialShoreStack:shore,smoothGraphics:true}),rng,
    playSound:()=>1,messageBeep:()=>{},beep:()=>{},dialogHandler:()=>{throw new Error('Original dialogs are unsupported in the worker spike');},getTickCount:paintClock.getTickCount,
    getCursorPos:()=>({x:0,y:0}),invalidateRect:()=>{},enforceMinimumPaintDuration:(duration:number)=>{delay=duration;},closeWindow:()=>{paused=true;},contextHelp:()=>{}};
  // The Block Island chart's recovered overlap needs an exact drawing profile.
  // Preserve the native geometry scratch values while its DWORD store repair
  // replaces the fictitious upper-word read. Modern 3D remains independent.
  if([33017,33018,33029,33031,33032].includes(settings.area??0)){options.numberRendering=false;options.smoothGraphics=false;}
  modelExtractor=createModelExtractor({memory,rng,options,objects,ModelMemory,ModelRng,TraceDc,modelDraw});
  modelWorker=new Worker(new URL('./models.worker.ts',import.meta.url),{type:'module'});
  modelWorker.onerror=event=>fail(event.message);
  modelWorker.onmessage=event=>{if(event.data.type==='error'){fail(event.data.data);return;}if(event.data.type==='ready')modelReady=true;else if(event.data.type==='models'){modelBusy=false;send('models',event.data.data);}try{requestModels();}catch(error){fail(error);}};
  modelWorker.postMessage({type:'init',data:{legacyBase:data.legacyBase,objects:[...objects]}});
  mouse.handleMouseMove(memory,0,0,0,options);
  paint();
  for(const id of raceSetupCommands(scenario.setupCommands,settings,fleet)){await menu(memory,id,options);paint();}
  if(settings.gate!==undefined&&Boolean(memory.readI32(0x4da1e8))!==settings.gate){await menu(memory,32994,options);paint();}
  key(memory,32,options);
  for(let attempt=0;memory.readI32(0x5363b0)!==2&&attempt<4;attempt++)paint();
  if(memory.readI32(0x5363b0)!==2)throw new Error('Original race initialization failed');
  if([0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c].some(a=>memory.readI32(a)!==0)){key(memory,32,options);paint();}
  if(memory.readI32(0x4da1dc)!==0){await menu(memory,32984,options);paint();}
  for(const id of scenario.postSetupCommands)await menu(memory,id,options);
  const initial=await boundary(),expected=scenario.initialBoundary;
  if(isAuditedPreset(settings,fleet)&&(initial.frame!==expected.frame||initial.memorySha256!==expected.memorySha256||initial.rngState!==expected.rngState||JSON.stringify(initial.shore)!==JSON.stringify(expected.shore)))throw new Error('Worker initial state differs: '+JSON.stringify(initial));
  const area=areaChoices.find(a=>a.command===(settings.area??32799))!;
  if(memory.readI32(0x4da154)!==settings.wind||memory.readI32(0x4da194)!==fleet||memory.readI32(0x4da144)!==(settings.boat??12)||memory.readI32(0x4da1f8)!==area.venue||memory.readI32(0x4da19c)!==area.area||memory.readI32(0x4da188)!==settings.course||memory.readI32(0x4da16c)!==0)throw new Error('Native race configuration differs from selection');
  if(settings.scoring&&memory.readI32(0x536424)!==(settings.scoring==='single'?1:0))throw new Error('Native scoring mode differs');
  ready=true;send('terrain',readNativeTerrain(memory));send('ready',initial);send('snapshot',snapshot(0));paused=data.manual===true;requestModels();
  if(!paused)schedule(0);
}
// Serialize commands, diagnostics and setup. Native callbacks never overlap.
let chain=Promise.resolve();
self.onmessage=(event:MessageEvent)=>{chain=chain.then(async()=>{
  const {type,data,id}=event.data;
  if(type==='init'){await initialize(data);return;}
  if(event.data.generation!==generation||!ready||failed)return;
  if(type==='pause'){paused=Boolean(data);if(paused){clearTimeout(timer);scheduleToken++;pending=false;}else schedule(0);send('paused',paused);}
  else if(type==='command'){if(!Number.isInteger(data)||!allowed.has(data))throw new Error('Unsupported native command');await menu(memory,data,options);send('snapshot',snapshot(0));send('accepted',{command:data,sequence:frame});}
  else if(type==='key'){
    if(!Number.isInteger(data)||data<0||data>255)throw new Error('Invalid native virtual key');
    key(memory,data,options);if(memory.readI32(0x5363f4)===0)resultsReady=false;modelDirty=true;send('snapshot',snapshot(0));send('accepted',{key:data,sequence:frame});requestModels();
  }
  else if(type==='step'){if(!paused||!Number.isInteger(data)||data<1||data>200)throw new Error('Diagnostic steps require paused worker and 1..200 paints');let duration=0;for(let n=0;n<data;n++)duration=paint();send('snapshot',snapshot(duration));publishPanel();requestModels();send('reply',{id,value:await boundary()});}
  else if(type==='model'){send('reply',{id,value:visuals.frame(memory.readI32(0x4fe624),Math.trunc(memory.readI32(0x4fe2a8)/2))});}
  else if(type==='lift'){if(!paused)throw new Error('Model diagnostics require pause');const width=visuals.frame(1024,361).boats.find(b=>b.id===1)?.calibration?.width;if(!width)throw new Error('Missing model calibration');send('reply',{id,value:[0,1,2].map(shear=>modelExtractor.capture(data??1,width,35,shear))});}
  else if(type==='boundary'){if(!paused)throw new Error('Boundary inspection requires pause');send('reply',{id,value:await boundary()});}
  else if(type==='image'){if(!paused)throw Error('Image diagnostics require pause');const bytes=memory.bytes.slice();self.postMessage({type:'reply',generation,data:{id,value:bytes}},{transfer:[bytes.buffer]});}
  else if(type==='next-race'){
    if(!paused||!resultsReady||memory.readI32(0x5363f4)===0)throw new Error('Next race requires completed native results');
    clearTimeout(timer);scheduleToken++;pending=false;startingLine=undefined;resultsReady=false;
    key(memory,78,options);paint();key(memory,32,options);paint();
    for(let attempt=0;attempt<4&&[0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c].some(a=>memory.readI32(a)!==0);attempt++){key(memory,32,options);paint();}
    // Results draw freezes the native simulator. N retains that flag; dismissing
    // its series notice consumes Space before the ordinary thaw branch runs.
    if(memory.readI32(0x53642c)!==0)key(memory,70,options);
    if(memory.readI32(0x5363b0)!==2||memory.readI32(0x5363f4)!==0||memory.readI32(0x53642c)!==0)throw new Error('Native next race initialization failed');
    modelDirty=true;send('terrain',readNativeTerrain(memory));send('snapshot',snapshot(0));send('paused',true);requestModels();send('reply',{id,value:await boundary()});
  }
  else if(type==='finishcase'){
    if(!paused)throw new Error('Finish diagnostics require pause');
    const before=await boundary(),m=new ModelMemory(memory.size,memory.base),random=new ModelRng(rng.state);m.bytes.set(memory.bytes);copyStrings(memory,m);
    const count=m.readI32(0x4da194);m.writeI32(0x4f6d64,0);m.writeI32(0x4f6a58,0);m.writeI32(0x5363fc,0);m.writeI32(0x4f8cd0,600);m.writeI32(0x536424,0);
    for(let b=1;b<=count;b++){m.writeI32(0x4fe638+b*4,0);for(let n=0;n<3;n++)m.writeI32(0x4fbf24+b*16+n*4,0);}
    const order=Array.from({length:count},(_,i)=>count-i);
    for(const b of order){m.writeI32(0x4f8538+b*4,m.readI32(0x4da1e4));advanceTarget(m,b,{...options,rng:random});}
    const surface=new OffscreenCanvas(1024,768),dc=gdi(surface.getContext('2d')!,{objects:new Map(objects),bitmapFont:font,recordEvents:false});dc.canvas=surface;
    drawResults(m,dc,random,{...options,rng:random});
    const boats=Array.from({length:count},(_,n)=>{const b=n+1;return{id:b,name:readCString(m,0x4fec30+b*4),finished:m.readI32(0x4fe638+b*4),points:[0,1,2].map(n=>m.readI32(0x4fbf24+b*16+n*4))};});
    const after=await boundary();if(JSON.stringify(before)!==JSON.stringify(after))throw new Error('Private finish case mutated the master');
    send('reply',{id,value:{before,after,boats,order,results:m.readI32(0x5363f4)!==0,completedRaces:m.readI32(0x5363fc),scope:'Isolated native finish-target transition and original results draw, not a naturally sailed race'}});
  }
  else if(type==='environmentcase'){
    if(!paused)throw Error('Environment diagnostics require pause');const before=await boundary(),cases=await evaluateEnvironmentCases(memory,rng,options,ModelMemory,ModelRng,updateDynamics,sampleCurrent,sampleVenueCurrent),after=await boundary();if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Environment diagnostic changed master');send('reply',{id,value:{before,after,cases,terrain:readNativeTerrain(memory),scope:'Private controlled depths with original current/dynamics; not naturally sailed grounding'}});
  }
  else if(type==='modelcase'){
    if(!paused)throw new Error('Model diagnostics require pause');
    const privateMemory=new ModelMemory(memory.size,memory.base);privateMemory.bytes.set(memory.bytes);const privateRng=new ModelRng(rng.state);
    const cases:{[key:string]:()=>void}={
      normal:()=>{},
      penalty:()=>{privateMemory.writeI32(0x5116e4,1);privateMemory.writeI32(0x535624,privateMemory.readI32(0x4f8cd0));},
      trim:()=>{privateMemory.writeI32(0x4fe81c,35);privateMemory.writeI32(0x500384,80);},
      luff:()=>{privateMemory.writeI32(0x51227c,85);privateMemory.writeI32(0x500384,100);},
      oppositeTack:()=>{privateMemory.writeI32(0x522ff4,-privateMemory.readI32(0x522ff4));},
      luffNext:()=>{privateMemory.writeI32(0x51227c,85);privateMemory.writeI32(0x500384,100);privateRng.rand();},
      spinnaker:()=>{privateMemory.writeI32(0x5350dc,1);},
    };
    if(typeof data!=='string'||!Object.hasOwn(cases,data))throw new Error('Unknown isolated model case');cases[data]();
    const calibration=visuals.frame(1024,361).boats.find(b=>b.id===1)?.calibration;if(!calibration)throw new Error('Missing model calibration');
    const extractor=createModelExtractor({memory:privateMemory,rng:privateRng,options,objects,ModelMemory,ModelRng,TraceDc,modelDraw});
    send('reply',{id,value:{kind:data,packet:extractor.extract([1],calibration.width),projections:[0,1,2].map(shear=>extractor.capture(1,calibration.width,35,shear)),unscaled:extractor.capture(1,calibration.width,35,0,1)}});
  }
  else if(type==='geometry'){if(!paused)throw new Error('Model diagnostics require pause');const calibration=visuals.frame(1024,361).boats.find(b=>b.id===1)?.calibration;if(!calibration)throw new Error('Missing native calibration');send('reply',{id,value:modelExtractor.extract(Array.from({length:memory.readI32(0x4da194)},(_,i)=>i+1),calibration.width)});}
}).catch(fail);};
