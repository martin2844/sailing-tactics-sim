import test from 'node:test';
import assert from 'node:assert/strict';
import vm from 'node:vm';
import {readFile} from 'node:fs/promises';

const source=await readFile(new URL('../src/play.js',import.meta.url),'utf8');
const graphicsSetup=source.slice(source.indexOf('  const smoothGraphics='),source.indexOf('  buildMenus(',source.indexOf('  const smoothGraphics=')));
const queue=source.match(/^const paintQueue=typeof MessageChannel[^\n]*\nif\(paintQueue\)[^\n]*$/m)?.[0];
const paintFunctions=source.slice(source.indexOf('function requestPaint(delay=0){'),source.indexOf("document.addEventListener('visibilitychange'"));
assert.ok(graphicsSetup.startsWith('  const smoothGraphics='));
assert.ok(queue&&paintFunctions.startsWith('function requestPaint(delay=0){'));

test('the actual graphics query installs only renderer shared options and preserves engine providers',()=>{
  for(const [search,smooth] of [['',true],['?graphics=exact',false],['?graphics=smooth',true]]){
    const trig=Object.freeze({extended:()=>0,stored:()=>0}),engineRoutine=()=>1;
    const getTickCount=()=>0,rendererCalls=[],state={rng:{state:123}},initialShoreStack={original:true};
    const context=vm.createContext({state,location:{search},URLSearchParams,trig,initialShoreStack,
      createEngineBindings:()=>({engineRoutine}),
      renderer:{createOriginalRenderer(options){rendererCalls.push(options);return {drawScene:()=>options.smoothGraphics};}},
      playSound:()=>1,messageBeep:()=>1,originalDialog:()=>1,paintClock:{getTickCount},requestPaint:()=>1,
      $:()=>({textContent:'',hidden:false}),
    });
    vm.runInContext(graphicsSetup,context);
    assert.equal(rendererCalls.length,1);assert.equal(rendererCalls[0].smoothGraphics,smooth);
    assert.equal(rendererCalls[0].initialShoreStack,initialShoreStack);
    assert.equal(state.options.drawScene(),smooth);
    assert.equal(state.options.engineRoutine,engineRoutine);assert.equal(state.options.trig,trig);
    assert.equal(state.options.getTickCount,getTickCount);assert.equal(state.options.rng,state.rng);
    for(const key of ['smoothGraphics','sinCos','atan2','atan2Extended'])assert.equal(key in state.options,false,`${key} cannot leak from drawing sharedOptions into physics`);
    assert.equal(state.rng.state,123);
  }
});

function scheduler(renderDuration,nativeDuration){
  let now=10;
  const messages=[],timers=[],events=[];
  class Channel{
    constructor(){this.port1={onmessage:null};this.port2={postMessage:()=>messages.push(()=>this.port1.onmessage())};}
  }
  const state={ready:true,closed:false,error:null,modal:false,pending:false,nextPaint:false,deferredPaintDue:null,
    delay:0,frames:0,memory:{},rng:{},objects:{},options:{},cursor:{x:12,y:34}};
  const canvas={width:1024,height:722},bufferCanvas={};
  const context=vm.createContext({state,canvas,bufferCanvas,context:{},bufferContext:{},
    dimensions:{width:1024,height:768,bitsPixel:24},document:{visibilityState:'visible'},
    performance:{now:()=>now},Math,MessageChannel:Channel,
    setTimeout(callback,delay){timers.push({callback,delay});},
    paintClock:{beginPaint(){events.push(['begin']);},minimumDuration:()=>0},
    createCanvasGdi:()=>({}),messageBeep:()=>1,resetBitmapSurface:()=>1,
    paintLifecycle(_memory,_front,_rng,options){
      events.push(['physics',state.frames,options.cursor.x,options.cursor.y]);
      options.enforceMinimumPaintDuration?.(nativeDuration);
      state.delay=nativeDuration;options.host.invalidateRect();now+=renderDuration;
    },
    updateStatus:()=>events.push(['status']),fail:error=>{throw error;},
  });
  vm.runInContext(queue+'\n'+paintFunctions+'\nglobalThis.schedule=requestPaint;',context);
  return {state,context,messages,timers,events};
}

test('faster drawing keeps one simulation callback per original paint and yields to queued input',()=>{
  for(const renderDuration of [1,40]){
    const host=scheduler(renderDuration,0);
    host.context.schedule();host.context.schedule();
    assert.equal(host.messages.length,1);assert.equal(host.state.frames,0);
    for(let index=0;index<12;index++){
      host.state.cursor={x:12+index,y:34-index};
      assert.equal(host.messages.length,1);host.messages.shift()();
      assert.equal(host.state.frames,index+1);
      assert.equal(host.messages.length,1,'the next simulation always waits in a separate task');
      assert.equal(host.timers.length,0);
    }
    assert.deepEqual(host.events.filter(event=>event[0]==='physics'),Array.from({length:12},(_,index)=>['physics',index,12+index,34-index]));
  }
  for(const nativeDuration of [30,60,80])for(const renderDuration of [1,40]){
    const host=scheduler(renderDuration,nativeDuration);
    host.context.schedule();host.messages.shift()();
    assert.equal(host.state.frames,1);
    const remainder=Math.max(0,nativeDuration-renderDuration);
    if(remainder===0){assert.equal(host.messages.length,1);assert.equal(host.timers.length,0);}
    else{assert.equal(host.messages.length,0);assert.equal(host.timers.length,1);assert.equal(host.timers[0].delay,remainder);}
  }
});
