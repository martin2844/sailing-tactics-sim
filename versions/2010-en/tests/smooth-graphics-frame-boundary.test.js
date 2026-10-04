import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../src/runtime/memory.js';
import {PoseyRng} from '../../../src/engine/integer-core.js';
import {withX87ControlWord} from '../../../src/runtime/float80.js';
import {sinCosX87Number} from '../../../src/runtime/transcendentals.js';
import {initializeApplication} from '../src/engine/application.js';
import {initializeBoatOptions} from '../src/engine/boat-options.js';
import {initializeRace} from '../src/engine/initialization.js';
import {createEngineBindings} from '../src/engine/port.js';
import {createCapturedTrig} from '../src/engine/native-trig.js';
import {handleMenuCommand} from '../src/engine/menu-controller.js';
import {handleKeyDown} from '../src/engine/keyboard.js';
import {configurePaintDimensions,drawSimulationFrame} from '../src/render/paint-lifecycle.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const tables=await json('../assets/data/trig-tables.json');
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'),await json('../assets/data/x87-stored-trig.json'));
const actualEngine=createEngineBindings();
const renderNames=['drawScene','drawChart','drawAdvice','drawSailingHud','drawCompactHud','drawPauseScreen'];

// This checks the actual frame/engine boundary with pure drawing callbacks.
// Real fast-render persistent stores and RNG need a separate complete-render
// comparison: the intentionally pure callbacks here cannot establish that.
function environment(smoothGraphics,tickStart){
  const memory=loadPE32(source),rng=new PoseyRng(),events=[],sounds=[],inputEvents=[];
  initializeApplication(memory,rng,{timeSeed:123456,screenHeight:768,integerTrig:tables});
  configurePaintDimensions(memory,{width:1024,height:768,bitsPixel:24,applicationInstance:1});
  const engine=Object.fromEntries(Object.entries(actualEngine).map(([name,routine])=>[name,(...args)=>{
    const options=args.at(-1);
    assert.equal(options.trig,trig,'every physics child retains the exact native captures');
    for(const provider of ['sinCos','atan2','atan2Extended'])assert.equal(provider in options,false,'no drawing provider replaces a physics provider');
    events.push({name,boat:['updateBoatWindAndAI','updateBoatDynamics','respawnWindPatch'].includes(name)?args[1]:null,
      phase:memory.readI32(0x5364e8),time:memory.readF64(0x5359f0),dt:memory.readF64(0x523378)});
    return routine(...args);
  }]));
  let tick=tickStart,cursorReads=0;
  const options={engine,trig,rng,smoothGraphics,cursor:{x:50,y:60},
    getTickCount:()=>tick++>>>0,getCursorPos:()=>{cursorReads++;return {...options.cursor};},
    playSound:event=>{sounds.push(event);return 1;},
    invalidateRect:event=>inputEvents.push(event),
  };
  initializeBoatOptions(memory,options);initializeRace(memory,rng,options);
  // Explicit race-screen configuration; only the original caller paint phase
  // and this declared pause state change directly in the frame tests below.
  memory.writeI32(0x5363b0,2);memory.writeI32(0x5233a8,0);memory.writeI32(0x536444,0);
  let throwDrawing=false,drawn=0;
  for(const name of renderNames)options[name]=(...args)=>{
    const drawingOptions=args.at(-1);
    assert.equal(drawingOptions.smoothGraphics,smoothGraphics);
    assert.equal(drawingOptions.trig,trig);
    events.push({name,phase:memory.readI32(0x5364e8)});drawn++;
    const angle=.213123+memory.readI32(0x5364e8)*.0001;
    const visibleSine=smoothGraphics?Math.sin(angle):sinCosX87Number(angle).sine.toNumber();
    assert.ok(Number.isFinite(visibleSine));
    if(throwDrawing)throw new Error('declared drawing failure');
  };
  return {memory,rng,events,sounds,inputEvents,options,
    setDrawingFailure(value){throwDrawing=value;},cursorReads:()=>cursorReads,drawn:()=>drawn};
}

function identical(left,right){
  assert.deepEqual(right.memory.bytes,left.memory.bytes,'complete original image remains exact');
  assert.equal(right.rng.state,left.rng.state,'exact original RNG cadence');
  assert.deepEqual(right.events,left.events,'physics/drawing order and pre-child dt remain identical');
  assert.deepEqual(right.sounds,left.sounds);assert.deepEqual(right.inputEvents,left.inputEvents);
  assert.equal(right.cursorReads(),left.cursorReads());assert.equal(right.drawn(),left.drawn());
  assert.equal(left.memory.readI32(0x4da16c),0);assert.equal(right.memory.readI32(0x4da16c),0);
}

test('smooth drawing flag and different host clock epochs preserve real dt, AI cadence, inputs and full mode',()=>withX87ControlWord(0x027f,()=>{
  const exact=environment(false,13),smooth=environment(true,0xfffffff0);
  identical(exact,smooth);
  let frame=0;
  for(const [command,speed,duration] of [[32872,1,80],[32876,5,60],[32877,6,30],[32878,7,0],[32909,10,0],[32973,15,0]]){
    for(const host of [exact,smooth])handleMenuCommand(host.memory,command,host.options);
    assert.equal(exact.memory.readI32(0x4da174),speed);identical(exact,smooth);
    for(let step=0;step<6;step++){
      frame++;
      // Actual native keyboard events run between completed frames; cursor is
      // sampled once before the wind/AI/steering/dynamics prefix.
      for(const host of [exact,smooth]){
        if(step===2)handleKeyDown(host.memory,37,host.options);
        if(step===4)handleKeyDown(host.memory,39,host.options);
        host.options.cursor={x:50+frame,y:60-frame};
        host.memory.writeI32(0x5364e8,frame);
      }
      identical(exact,smooth);
      const counts=exact.events.length,before=exact.memory.readF64(0x5359f0);
      for(const host of [exact,smooth])assert.equal(drawSimulationFrame(host.memory,null,host.rng,host.options),duration);
      identical(exact,smooth);
      const current=exact.events.slice(counts),fleet=exact.memory.readI32(0x4da194);
      assert.equal(current.filter(event=>event.name==='updateGlobalWind').length,1);
      assert.deepEqual(current.filter(event=>event.name==='updateBoatWindAndAI').map(event=>event.boat),Array.from({length:fleet},(_,index)=>index+1));
      assert.deepEqual(current.filter(event=>event.name==='updateBoatDynamics').map(event=>event.boat),Array.from({length:fleet},(_,index)=>index+1));
      assert.equal(current.filter(event=>event.name==='integratePositions').length,1);
      assert.ok(current.findIndex(event=>event.name==='drawScene')>current.findIndex(event=>event.name==='integratePositions'));
      assert.ok(exact.memory.readF64(0x5359f0)>before);
      if(speed===10)assert.equal(exact.memory.readF64(0x523378),0.20384122874775878);
      assert.equal(exact.cursorReads(),frame);
      assert.equal(exact.memory.readI32(0x4f7f78),50+frame);
      assert.equal(exact.memory.readI32(0x4f8ee4),60-frame);
    }
  }
}));

test('pause and a failing drawing suffix keep the original single physics prefix and finish ordering',()=>withX87ControlWord(0x027f,()=>{
  const exact=environment(false,10),smooth=environment(true,0xfffffff0);
  for(const host of [exact,smooth])handleMenuCommand(host.memory,32909,host.options);
  for(const [index,pause] of [0,2,300,0].entries()){
    for(const host of [exact,smooth]){host.memory.writeI32(0x536444,pause);host.memory.writeI32(0x5364e8,index+1);}
    const before=exact.memory.readF64(0x5359f0),count=exact.events.length;
    for(const host of [exact,smooth])drawSimulationFrame(host.memory,null,host.rng,host.options);
    identical(exact,smooth);
    const calls=exact.events.slice(count);
    assert.equal(calls.filter(event=>event.name==='updateGlobalWind').length,1);
    assert.equal(calls.filter(event=>event.name==='integratePositions').length,pause===0?1:0);
    if(pause!==0)assert.equal(exact.memory.readF64(0x5359f0),before);
  }
  for(const host of [exact,smooth]){
    host.memory.writeI32(0x5364e8,5);host.memory.writeI32(0x4f7124,23);host.memory.writeI32(0x4f7128,29);
    host.setDrawingFailure(true);
  }
  const count=exact.events.length,before=exact.memory.readF64(0x5359f0);
  for(const host of [exact,smooth])assert.throws(()=>drawSimulationFrame(host.memory,null,host.rng,host.options),/declared drawing failure/);
  identical(exact,smooth);
  assert.equal(exact.events.slice(count).filter(event=>event.name==='integratePositions').length,1);
  assert.ok(exact.memory.readF64(0x5359f0)>before,'failed drawing follows one completed integration, without retry');
  assert.equal(exact.memory.readI32(0x4f7124),23,'finishFrame does not clear input globals after an error');
  assert.equal(exact.memory.readI32(0x4f7128),29);
}));
