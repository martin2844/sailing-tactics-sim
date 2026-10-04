import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createNativeHarness,assertNativeProvenance } from './native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createEngineBindings } from '../src/engine/port.js';
import { initializeGdiObjects } from '../src/engine/application.js';
import { initializeRace } from '../src/engine/initialization.js';
import { handleMenuCommand,MENU_COMMAND_ROUTINES } from '../src/engine/menu-controller.js';
import { createOriginalRenderer } from '../src/render/index.js';
import { drawSimulationFrame } from '../src/render/paint-lifecycle.js';
import { GdiTrace } from '../src/render/gdi.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const fixtures=[await json('fixtures/original-retained-speed-ten-frames.json'),await json('fixtures/original-retained-speed-ten-long-frames.json')];
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'),await json('../assets/data/x87-stored-trig.json'));
const engine=createEngineBindings(),render=createOriginalRenderer();

for(const fixture of fixtures)for(const profile of fixture.profiles)for(const mode of fixture===fixtures[0]?['numeric','original']:['numeric'])test(`${profile.name} (${mode} arithmetic): complete native state, RNG, text, GDI, sounds and actual speed selection remain exact`,()=>{
  assertNativeProvenance(source,fixture);
  const harness=createNativeHarness(source,fixture),rows=fixture.cases.filter(row=>row.profile===profile.name);
  let objects=new Map(),initialTime,menuTime,speedTenFrames=0;
  for(const [index,row] of rows.entries()){
    const sounds=[],callbacks=[];let ticks=0,pixels=0;
    const dc=new GdiTrace({objects,readPixel(){
      if(pixels>=row.host.pixels.length)throw new RangeError('Retained speed10 frame exceeded declared native pixel inputs');
      return row.host.pixels[pixels++];
    }});
    harness.check(row,index,(memory,rng)=>{
      const options={engine,render,trig,rng,...(mode==='original'?{numberRendering:false}:{}),
        playSound:event=>{sounds.push(event);return 1;},messageBeep:type=>{dc.emit({op:'messageBeep',type});return 1;},
        ...(row.host?{menuHeight:row.host.menuHeight,getCursorPos:()=>({x:row.host.cursor[0],y:row.host.cursor[1]}),
          getTickCount:()=>(row.host.tickStart+ticks++)>>>0}:{}),
      };
      if(row.phase==='initialize'){
        objects=initializeGdiObjects(memory);assert.equal(objects.size,90);
        return initializeRace(memory,rng,options);
      }
      if(row.phase==='select-speed-ten'){
        assert.equal(row.kind,2);assert.equal(row.identifier,32909);
        assert.equal(row.routine.address,MENU_COMMAND_ROUTINES[32909]);
        assert.deepEqual(row.patches,[],'the native menu handler owns every gameplay speed store');
        menuTime=memory.readF64(0x5359f0);assert.ok(menuTime>100,'actual native full-frame integration reaches the later race phase');
        return handleMenuCommand(memory,row.identifier,{...options,windowHandle:row.windowHandle,
          invalidateRect:event=>callbacks.push({type:'invalidateRect',...event})});
      }
      assert.equal(row.patches.length,1,'only the exact paint-caller phase changes between complete retained frames');
      assert.equal(row.patches[0].address,0x5364e8);
      assert.equal(row.callerInput.value,row.frame%60+1);
      if(memory.readI32(0x4da174)===10){assert.equal(memory.readI32(0x4da178),76);speedTenFrames++;}
      return drawSimulationFrame(memory,dc,rng,options);
    });
    if(row.phase==='initialize'){
      initialTime=harness.memory.readF64(0x5359f0);
      for(const [name,required] of Object.entries(profile.required))assert.equal(row.expected.integers[name],required,`actual native initialized ${name}`);
      assert.equal(harness.memory.readI32(0x4da16c),0,'native full edition remains unrestricted');
    }else if(row.phase==='select-speed-ten'){
      assert.deepEqual(callbacks,row.expected.events,'original menu invalidation callback and order');
      assert.equal(harness.memory.readI32(0x4da174),10);assert.equal(harness.memory.readI32(0x4da178),76);
    }else{
      assert.deepEqual(sounds,row.expected.sounds,`frame ${row.frame}: native ordered sound requests`);
      assert.deepEqual(dc.events,row.expected.drawingCommands,`frame ${row.frame}: native ordered GDI commands`);
      assert.equal(pixels,row.expected.drawingCommands.filter(event=>event.op==='getPixel').length);
      assert.ok(ticks>0,'each native full frame consumes the declared original tick host');
    }
  }
  assert.equal(speedTenFrames,profile.speedTenFrames??profile.frames);
  assert.ok(harness.memory.readF64(0x5359f0)>initialTime,'retained native precise race time advances');
  if(menuTime!==undefined)assert.ok(harness.memory.readF64(0x5359f0)>menuTime,'speed10 advances beyond the native later-race menu transition');
});
