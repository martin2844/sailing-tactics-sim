import {test} from 'node:test';
import assert from 'node:assert/strict';
import {executeSimulationStep} from '../../app/engine/simulation-step.ts';
import {AddressSpaceMemory} from '../../../../src/runtime/memory.js';
import {drawSimulationFrame} from '../../public/legacy/versions/2010-en/src/render/paint-lifecycle.js';

function run(pace,start,modern,clock=true){
  const memory=new AddressSpaceMemory(0x21c000),events=[];
  for(const[a,v]of[[0x4da174,pace],[0x4da140,0],[0x4f7124,3],[0x4f7128,4]])memory.writeI32(a,v);
  let tick=start;
  const advance=()=>{events.push('advance');return start;};
  const readTick=()=>{events.push('tick');return (tick++)>>>0;};
  const wait=(duration,began)=>events.push(['wait',duration,began]);
  let result;
  if(modern)result=executeSimulationStep({advance,pace:()=>pace,updateWorldState:()=>{},readTick:clock?readTick:undefined,
    enforceMinimumDuration:wait,clearFrameWarnings:()=>{memory.writeI32(0x4f7124,0);memory.writeI32(0x4f7128,0);}});
  else result=drawSimulationFrame(memory,{}, {}, {advanceFrame:advance,getTickCount:clock?readTick:undefined,enforceMinimumPaintDuration:wait});
  return {bytes:memory.bytes,result,events};
}

test('step order, native pace timing and unsigned clock wrap match original driver',()=>{
  for(const pace of[1,4,5,6,7,10,15])for(const start of[0,0xfffffffe])for(const clock of[false,true]){
    const a=run(pace,start,false,clock),b=run(pace,start,true,clock);
    assert.deepEqual(b,a,JSON.stringify({pace,start,clock}));
  }
});

test('world failure propagates without clearing frame warnings',()=>{
  const error=new Error('world failure'),events=[];
  assert.throws(()=>executeSimulationStep({advance:()=>0,updateWorldState:()=>{throw error;},pace:()=>1,
    clearFrameWarnings:()=>events.push('cleared')}),e=>e===error);
  assert.deepEqual(events,[]);
});

test('nonadvancing clock is bounded and does not run successful-frame cleanup',()=>{
  let cleared=false;
  assert.throws(()=>executeSimulationStep({advance:()=>0,updateWorldState:()=>{},pace:()=>1,readTick:()=>0,
    clearFrameWarnings:()=>{cleared=true;}}),/tick host did not advance/);
  assert.equal(cleared,false);
});
