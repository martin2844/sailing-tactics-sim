import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';
import {PoseyRng} from '../../../../src/engine/integer-core.js';
import {targetRelativeBearing} from '../../../2010-en/src/engine/ai-geometry.js';
import {callDrawingDependency,callNumberDrawingDependencyOwned} from '../../../2010-en/src/render/dependencies.js';
import '../../../2010-en/src/render/drawing-functions.js';
import {updateCompatibilityCamera} from '../../app/engine/view/camera-state.ts';
import {createCameraStatePort} from '../../app/engine/compatibility/camera-state-port.ts';
const source=await readFile(new URL('../../../2010-en/runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const low32 = value=>Number(BigInt.asIntN(32,value.truncI64()));
function ports(memory){return createCameraStatePort(memory,{
  coordinateLow32:value=>low32(Float80.fromNumber(value)),
  bearingToOtherBoat:boat=>{
    const other=3-boat;
    const angle=targetRelativeBearing(memory,memory.readF64(0x4f6af8+other*8),memory.readF64(0x4f6c10+other*8),0,boat);
    return low32(angle.multiply(Float80.fromNumber(memory.readF64(0x4cc3e8))));
  },
});}
function image(boat,players,automatic,clock,mode,offset,target){
  const m=loadPE32(source);m.writeI32(0x4da140,players);m.writeI32(0x5363e8,0);m.writeI32(0x4f8cd0,clock);
  for(const id of[1,2]){
    for(const[base,value]of[[0x523a58,automatic],[0x535740,237],[0x522ff0,-1],[0x512d60,mode],[0x522b90,280],[0x4f49a0,offset]])m.writeI32(base+id*4,value);
    m.writeF64(0x4f6af8+id*8,id===boat?200:target[0]);m.writeF64(0x4f6c10+id*8,id===boat?300:target[1]);
  }
  m.writeI32(0x5229d4,200);m.writeI32(0x522ac8,300); // Cover near-mark auto view.
  return m;
}

test('both camera kernels match full image/RNG across modes, time gates, player ownership and projection extremes',()=>withX87ControlWord(0x027f,()=>{
  for(const boat of[1,2])for(const players of[1,2])for(const auto of[0,1])for(const clock of[-31,-30,-29,14,15,29,30,100])for(const mode of[-1,0,1,100])for(const offset of[0,180,181,-181]){
    const target=clock===100?[1e10,-1e10]:[400,-200];
    for(const numeric of[false,true]){
      const a=image(boat,players,auto,clock,mode,offset,target),b=image(boat,players,auto,clock,mode,offset,target),ra=new PoseyRng(12),rb=new PoseyRng(12);
      const address=boat===1?0x41e0a0:0x41e220;
      if(numeric)callNumberDrawingDependencyOwned(a,undefined,address,[],0,ra,{smoothGraphics:false,numberRendering:true});
      else callDrawingDependency(a,undefined,address,[],ra,{smoothGraphics:false,numberRendering:false});
      updateCompatibilityCamera(ports(b),boat);
      assert.deepEqual(b.bytes,a.bytes,JSON.stringify({boat,players,auto,clock,mode,offset,numeric}));assert.equal(rb.state,ra.state);
    }
  }
}));

test('automatic viewpoint boundaries are preserved away from marks',()=>withX87ControlWord(0x027f,()=>{
  for(const[clock,expected]of[[-31,2],[-30,2],[-29,3],[14,3],[15,1],[29,1],[30,2]])for(const boat of[1,2]){
    const a=image(boat,2,1,clock,0,0,[400,-200]),b=image(boat,2,1,clock,0,0,[400,-200]);
    for(const m of[a,b])for(const address of[0x5229d4,0x522ac8,0x522acc,0x522ae0,0x5229c8,0x522ac4])m.writeI32(address,-10000);
    callDrawingDependency(a,undefined,boat===1?0x41e0a0:0x41e220,[],new PoseyRng(12),{});
    updateCompatibilityCamera(ports(b),boat);
    assert.deepEqual(b.bytes,a.bytes);assert.equal(b.readI32(0x4f71c0+boat*4),expected);
  }
}));
