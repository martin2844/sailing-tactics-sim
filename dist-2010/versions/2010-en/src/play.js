import { fetchOriginalData } from './runtime/original-data.js';
import { createPaintClock } from './runtime/browser-clock.js';
import { resetBitmapSurface } from './runtime/canvas-surface.js';
import { setX87ControlWord } from '../../../src/runtime/float80.js';
import { PoseyRng } from '../../../src/engine/integer-core.js';
import { createCapturedTrig } from './engine/native-trig.js';
import { createEngineBindings } from './engine/port.js';
import { initializeApplication,saveApplicationPreferences,PREFERENCE_BYTES } from './engine/application.js';
import { handleKeyDown } from './engine/keyboard.js';
import { handleLeftButtonDown,handleRightButtonDown,handleMouseMove,handleMouseWheel } from './engine/mouse.js';
import { handleMenuCommand,menuCommandState } from './engine/menu-controller.js';
import { handleDialogControl,closeOriginalDialog } from './engine/dialogs.js';
import { paintLifecycle } from './render/paint-lifecycle.js';
import { createCanvasGdi } from './render/gdi.js';
import { fetchGdiBitmapFont } from '../../../src/render/bitmap-font.js';

const $=id=>document.getElementById(id);
const canvas=$('race'),context=canvas.getContext('2d');
// Reuse the backing surface. Selecting each original bitmap still resets its
// dimensions and drawing state, so no pixels or clipping survive a paint.
const bufferCanvas=document.createElement('canvas');
const bufferContext=bufferCanvas.getContext('2d',{willReadFrequently:true});
const state={memory:null,rng:null,objects:null,options:null,ready:false,closed:false,modal:false,pending:false,
  nextPaint:false,deferredPaintDue:null,delay:0,frames:0,error:null,cursor:{x:0,y:0},soundEnabled:false,activeSound:null,sounds:new Map(),menuHelp:null};
const assetUrl=path=>new URL(`../${path}`,import.meta.url);
const json=async path=>{const response=await fetch(assetUrl(path));if(!response.ok)throw new Error(`Could not load ${path}`);return response.json();};
const menuButtons=[];
const dimensions={width:1024,height:768,bitsPixel:24};
const paintClock=createPaintClock();
// Immediate paints still yield to the event loop without accumulating the
// browser's nested setTimeout minimum. Original positive delays use timers.
const paintQueue=typeof MessageChannel==='function'?new MessageChannel():null;
if(paintQueue)paintQueue.port1.onmessage=paint;

function fail(error){state.error=error.message;$('error').textContent=error.stack??error.message;$('error').hidden=false;$('status').textContent='Simulator stopped';console.error(error);}
function updateStatus(){
  if(!state.memory||state.closed||state.error)return;
  $('status').textContent=state.menuHelp??(state.memory.readI32(0x5363b0)===0?'Press Space to begin':state.memory.readI32(0x5363b4)===1?'Click to continue':'Sailing Tactics Simulator 2010');
}
function closeMenus(){document.querySelectorAll('.menu-popup').forEach(element=>element.hidden=true);document.querySelectorAll('[aria-expanded]').forEach(element=>element.setAttribute('aria-expanded','false'));state.menuHelp=null;updateStatus();}
function updateMenus(){
  if(!state.memory)return;
  for(const [button,id] of menuButtons){const value=menuCommandState(state.memory,id,{enabled:true,checked:0});button.disabled=!value.enabled;button.setAttribute('aria-checked',String(Boolean(value.checked)));}
}
async function command(id){
  closeMenus();if(!state.ready||state.closed||state.modal)return;
  try{await handleMenuCommand(state.memory,id,state.options);updateMenus();canvas.focus({preventScroll:true});}
  catch(error){fail(error);}
}
function buildMenus(resource){
  const build=(items,parent,root=false)=>{
    for(const item of items){
      if(item.separator){parent.append(document.createElement('hr'));continue;}
      const label=item.text.replace(/&/g,'');
      if(item.items){
        const holder=document.createElement('div');if(root)holder.className='menu-root';
        const button=document.createElement('button');button.type='button';button.textContent=label;button.className=root?'menu-toggle':'menu-submenu';button.setAttribute('aria-expanded','false');button.setAttribute('aria-haspopup','menu');
        const popup=document.createElement('div');popup.className='menu-popup';popup.hidden=true;popup.setAttribute('role','menu');
        button.addEventListener('click',event=>{event.stopPropagation();const wasOpen=!popup.hidden;if(root)closeMenus();updateMenus();popup.hidden=wasOpen;button.setAttribute('aria-expanded',String(!wasOpen));});
        holder.append(button,popup);parent.append(holder);build(item.items,popup);
      }else{
        const button=document.createElement('button');button.type='button';button.className='menu-command';button.textContent=label;button.dataset.command=String(item.command_id);button.setAttribute('role','menuitemcheckbox');
        const showHelp=()=>{state.menuHelp=state.strings[item.command_id]?.split('\n')[0]??'';updateStatus();};
        button.addEventListener('pointerenter',showHelp);button.addEventListener('focus',showHelp);
        button.addEventListener('click',()=>command(item.command_id));menuButtons.push([button,item.command_id]);parent.append(button);
      }
    }
  };build(resource.items,$('menus'),true);updateMenus();
}
document.addEventListener('click',event=>{if(!$('menus').contains(event.target))closeMenus();});

function originalDialog(resourceId){
  const resource=state.dialogs.find(row=>row.resource_id===resourceId);if(!resource)throw new Error(`Missing original dialog ${resourceId}`);
  state.modal=true;closeMenus();const dialog=$('original-dialog'),content=$('dialog-controls');content.replaceChildren();$('dialog-title').textContent=resource.title;
  const unitX=2,unitY=2,rect=resource.rect_dialog_units;content.style.width=`${rect[2]*unitX}px`;content.style.height=`${rect[3]*unitY}px`;
  let radioGroup=0;
  return new Promise(resolve=>{
    let done=false;
    const finish=accepted=>{if(done)return;done=true;const result=closeOriginalDialog(state.memory,resourceId,accepted,{...state.options,endDialog:()=>dialog.close()});state.modal=false;resolve(result);if(state.nextPaint)requestPaint();};
    dialog.oncancel=event=>{event.preventDefault();finish(false);};
    for(const control of resource.controls){
      const [x,y,width,height]=control.rect_dialog_units;const type=control.style&15;let element;
      if(control.class_name==='button'&&type===7){
        radioGroup++;element=document.createElement('fieldset');element.className='dialog-group';const legend=document.createElement('legend');legend.textContent=control.title;element.append(legend);
      }else if(control.class_name==='button'&&type===9){
        element=document.createElement('label');element.className='dialog-radio';const input=document.createElement('input');input.type='radio';input.name=`radio-${resourceId}-${radioGroup}`;input.value=String(control.id);
        input.addEventListener('change',()=>handleDialogControl(state.memory,resourceId,control.id,state.options));element.append(input,document.createTextNode(control.title));
      }else if(control.class_name==='button'){
        element=document.createElement('button');element.type='button';element.textContent=control.title;element.addEventListener('click',()=>finish(control.id===1));
      }else if(typeof control.title==='object'){
        element=document.createElement('img');element.src=assetUrl('assets/images/icon-1-1033.png');element.alt='';element.className='dialog-icon';
      }else{element=document.createElement('span');element.textContent=control.title;element.className='dialog-static';}
      element.classList.add('dialog-control');Object.assign(element.style,{left:`${x*unitX}px`,top:`${y*unitY}px`,width:`${width*unitX}px`,height:`${height*unitY}px`});content.append(element);
    }
    dialog.showModal();dialog.scrollLeft=0;
  });
}

function playSound({resourceId,flags}){
  if(resourceId===0){state.activeSound?.pause();state.activeSound=null;return 1;}
  const template=state.sounds.get(resourceId);if(!template)return 0;
  if(!state.soundEnabled)return 1;
  if((flags&16)&&state.activeSound&&!state.activeSound.paused)return 0;
  state.activeSound?.pause();const sound=template.cloneNode();sound.loop=Boolean(flags&8);state.activeSound=sound;sound.play().catch(()=>{});return 1;
}
function messageBeep(){
  if(!state.soundEnabled)return;
  const AudioContext=globalThis.AudioContext??globalThis.webkitAudioContext;if(!AudioContext)return;
  state.audioContext??=new AudioContext();state.audioContext.resume();const oscillator=state.audioContext.createOscillator(),gain=state.audioContext.createGain();
  oscillator.frequency.value=880;gain.gain.value=.035;oscillator.connect(gain);gain.connect(state.audioContext.destination);oscillator.start();oscillator.stop(state.audioContext.currentTime+.12);
}
$('sound').addEventListener('click',()=>{state.soundEnabled=!state.soundEnabled;$('sound').textContent=state.soundEnabled?'Sound on':'Sound off';$('sound').setAttribute('aria-pressed',String(state.soundEnabled));if(!state.soundEnabled)state.activeSound?.pause();});
$('fullscreen').addEventListener('click',()=>{if(document.fullscreenElement)document.exitFullscreen();else document.querySelector('.simulator').requestFullscreen().catch(fail);});

function requestPaint(delay=0){
  if(!state.ready||state.closed||state.error)return;
  state.nextPaint=true;if(state.modal||state.pending)return;
  if(document.visibilityState==='hidden'){
    state.deferredPaintDue??=performance.now()+Math.max(0,delay);
    return;
  }
  if(state.deferredPaintDue!==null){
    delay=Math.max(delay,state.deferredPaintDue-performance.now());
    state.deferredPaintDue=null;
  }
  state.pending=true;
  if(delay<=0&&paintQueue)paintQueue.port2.postMessage(0);
  else setTimeout(paint,Math.max(0,delay));
}
function paint(){
  state.pending=false;if(state.modal||state.closed||state.error)return;
  if(document.visibilityState==='hidden'){state.nextPaint=true;return;}
  state.deferredPaintDue=null;
  state.nextPaint=false;state.delay=0;paintClock.beginPaint();const start=performance.now();
  try{
    const front=createCanvasGdi(context,{objects:state.objects,bitmapFont:state.bitmapFont,messageBeep,recordEvents:false});front.canvas=canvas;
    const host={
      constructBufferedDC(){const dc=createCanvasGdi(bufferContext,{objects:state.objects,bitmapFont:state.bitmapFont,messageBeep,recordEvents:false,cachePixelReads:true});dc.canvas=bufferCanvas;dc.context=bufferContext;return dc;},
      getDeviceCaps(_dc,index){return index===12?dimensions.bitsPixel:index===8?dimensions.width:dimensions.height;},
      applicationInstance(){return 1;},createBitmap(descriptor){return descriptor;},attachBitmap(){},
      createCompatibleDC(){return 1;},attachCompatibleDC(){},
      selectBitmap(dc,bitmap){if(bitmap)resetBitmapSurface(dc.canvas,dc.context,bitmap.width,bitmap.height);return 0;},
      bitBlt(_front,buffer,descriptor){
        if(canvas.width!==descriptor.width||canvas.height!==descriptor.height){canvas.width=descriptor.width;canvas.height=descriptor.height;context.font='13px Arial';}
        context.drawImage(buffer.canvas,0,0);
      },deleteBitmap(){},invalidateRect(){state.nextPaint=true;},destroyBufferedDC(){},
    };
    paintLifecycle(state.memory,front,state.rng,{...state.options,host,cursor:state.cursor});state.frames++;
    state.delay=Math.max(state.delay,paintClock.minimumDuration());
    updateStatus();
    if(state.nextPaint)requestPaint(Math.max(0,state.delay-(performance.now()-start)));
  }catch(error){fail(error);}
}
document.addEventListener('visibilitychange',()=>{
  if(document.visibilityState!=='hidden'&&state.nextPaint)requestPaint();
});

const virtualKeys={Space:32,Enter:13,Escape:27,Backspace:8,PageUp:33,PageDown:34,Home:36,End:35,ArrowLeft:37,ArrowUp:38,ArrowRight:39,ArrowDown:40,
  Backslash:220,Semicolon:186,Slash:191,BracketLeft:219,BracketRight:221,Backquote:192,Comma:188,Period:190,Equal:187,Minus:189};
function keyCode(event){if(virtualKeys[event.code]!==undefined)return virtualKeys[event.code];if(/^Key[A-Z]$/.test(event.code))return event.code.charCodeAt(3);if(/^Digit[0-9]$/.test(event.code))return event.code.charCodeAt(5);const fn=/^F(\d+)$/.exec(event.code);return fn?111+Number(fn[1]):event.keyCode;}
document.addEventListener('keydown',event=>{
  if(!state.ready||state.modal||state.closed||event.ctrlKey||event.metaKey||event.altKey)return;
  if(event.target.closest('button,input,dialog'))return;
  event.preventDefault();closeMenus();try{handleKeyDown(state.memory,keyCode(event),state.options);updateMenus();}catch(error){fail(error);}
});
const point=event=>{const rect=canvas.getBoundingClientRect();return{x:Math.trunc((event.clientX-rect.left)*canvas.width/rect.width),y:Math.trunc((event.clientY-rect.top)*canvas.height/rect.height)};};
canvas.addEventListener('pointermove',event=>{if(!state.ready||state.modal||state.closed||state.error)return;const p=point(event);state.cursor={x:p.x,y:p.y+Math.trunc(dimensions.height/17)};try{handleMouseMove(state.memory,event.buttons,p.x,p.y,state.options);}catch(error){fail(error);}});
canvas.addEventListener('pointerdown',event=>{if(!state.ready||state.modal)return;event.preventDefault();canvas.focus({preventScroll:true});const p=point(event);try{(event.button===2?handleRightButtonDown:handleLeftButtonDown)(state.memory,event.buttons,p.x,p.y,state.options);}catch(error){fail(error);}});
canvas.addEventListener('wheel',event=>{
  if(!state.ready||state.modal||state.closed)return;
  event.preventDefault();const p=point(event);
  const delta=event.deltaY===0?0:event.deltaY<0?120:-120;
  try{handleMouseWheel(state.memory,event.buttons??0,delta,p.x,p.y,state.options);}catch(error){fail(error);}
},{passive:false});
canvas.addEventListener('contextmenu',event=>event.preventDefault());
window.addEventListener('pagehide',()=>{
  if(!state.memory)return;
  try{localStorage.setItem('tact-2010-en-preferences',JSON.stringify([...saveApplicationPreferences(state.memory)]));}catch{}
});

async function start(){
  const [memory,tables,extended,stored,menus,dialogs,manifest,renderer,bitmapFont,strings,initialShoreStack]=await Promise.all([
    fetchOriginalData(),json('assets/data/trig-tables.json'),json('assets/data/x87-trig.json'),json('assets/data/x87-stored-trig.json'),
    json('assets/ui/menus.json'),json('assets/ui/dialogs.json'),json('assets/manifest.json'),
    import('./render/index.js'),fetchGdiBitmapFont({softwareAtlas:true}),json('assets/ui/strings.json'),
    json('assets/data/initial-shoreline-stack.json'),
  ]);
  setX87ControlWord(0x027f);
  state.memory=memory;state.rng=new PoseyRng();state.dialogs=dialogs;state.bitmapFont=bitmapFont;state.strings=strings;
  let preferences=null;
  try{
    const saved=localStorage.getItem('tact-2010-en-preferences');
    if(saved){
      const value=JSON.parse(saved);
      if(!Array.isArray(value)||value.length!==PREFERENCE_BYTES||value.some(byte=>!Number.isInteger(byte)||byte<0||byte>255))throw new Error('Saved2010 preferences are invalid');
      preferences=Uint8Array.from(value);
    }
  }catch{try{localStorage.removeItem('tact-2010-en-preferences');}catch{}}
  const trig=createCapturedTrig(extended,stored);
  state.objects=initializeApplication(memory,state.rng,{preferences,timeSeed:Math.floor(Date.now()/1000),screenHeight:dimensions.height,integerTrig:tables});
  for(const row of manifest.resources.filter(row=>row.type==='WAVE')){const audio=new Audio(assetUrl(`assets/${row.wav_path}`));audio.preload='auto';state.sounds.set(row.id,audio);}
  // Graphics may use browser math; engine bindings retain their original math.
  // The exact renderer remains available for preservation comparisons.
  const smoothGraphics=new URLSearchParams(location.search).get('graphics')!=='exact';
  state.options={trig,...createEngineBindings(),...renderer.createOriginalRenderer({initialShoreStack,smoothGraphics}),rng:state.rng,
    playSound,messageBeep,beep:messageBeep,dialogHandler:originalDialog,getTickCount:paintClock.getTickCount,
    invalidateRect:()=>requestPaint(),enforceMinimumPaintDuration:duration=>state.delay=duration,
    closeWindow:()=>{state.closed=true;$('status').textContent='Simulator closed';},
    contextHelp:()=>{$('status').hidden=!$('status').hidden;},
  };
  buildMenus(menus.find(row=>row.resource_id===128));state.ready=true;$('status').textContent='Press Space to begin';canvas.focus({preventScroll:true});requestPaint();
}

// Exposes live state for local preservation comparisons and browser regression
// checks; the game itself does not load test fixtures or execute x86 code.
globalThis.tact={state,command,requestPaint,paint,dimensions};
start().catch(fail);
