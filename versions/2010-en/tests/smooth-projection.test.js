import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../src/runtime/memory.js';
import {withX87ControlWord} from '../../../src/runtime/float80.js';
import {originalDrawing0043e730} from '../src/render/drawing-functions.js';
import {tryProjectScenePointOutputFast} from '../src/render/projection-output-fast.js';
import '../src/render/index.js';
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const exact={numberRendering:false,retainedDrawingStack:{[0x43e730]:[],[0x43ea10]:[],[0x43eb00]:[]}};
const options={smoothGraphics:true};
const pair=[loadPE32(source),loadPE32(source)];
function setup(heading,mode=1){
  for(const m of pair){
    for(const [address,value] of [[0x4f71c4,mode],[0x4fbb94,heading],[0x4da148,200],[0x4f4b48,240],[0x4fe2a8,734],[0x4f40a8,512],[0x5364c8,0]])m.writeI32(address,value);
    for(const [address,value] of [[0x4f6b00,0],[0x4f6c18,0],[0x5259d0,1]])m.writeF64(address,value);
  }
}
function compare(x,y,selector,label){
  originalDrawing0043e730(pair[0],null,null,exact,0,x,y,1,selector);
  originalDrawing0043e730(pair[1],null,null,options,0,x,y,1,selector);
  assert.deepEqual(pair[1].readBytes(0x4fbb88,8),pair[0].readBytes(0x4fbb88,8),label+' exact distance');
  for(const address of [0x523660,0x4fed58])assert.ok(Math.abs(pair[1].readI32(address)-pair[0].readI32(address))<=1,
    `${label} at${address.toString(16)}: exact${pair[0].readI32(address)},smooth${pair[1].readI32(address)}`);
}
test('smooth perspective pixels stay within one pixel of original byte-frame drawing in ordinary views',()=>withX87ControlWord(0x027f,()=>{
  let state=0x435e730;const random=()=>state=(Math.imul(state,1664525)+1013904223)>>>0;
  for(let i=0;i<600;i++){
    const heading=random()%360;setup(heading,i%2+1);
    const radians=(heading+(random()%22001-11000)/100)*Math.PI/180,distance=50+random()%20000;
    compare(Math.sin(radians)*distance,-Math.cos(radians)*distance,i%3===0?5:0,'point'+i);
  }
}));
test('view cutoff and selector5 degree boundaries do not turn rounding into large pixel jumps',()=>withX87ControlWord(0x027f,()=>{
  for(const mode of [1,2])for(const degrees of [-130,-90,-80,-70,0,70,80,90,130])for(const offset of [-1e-12,0,1e-12]){
    setup(0,mode);const angle=(degrees+offset)/pair[0].readF64(0x4cc3e8);
    const originY=-pair[0].readF64(0x4ccb20);
    for(const selector of [0,5])compare(Math.sin(angle)*1000,originY-Math.cos(angle)*1000,selector,`boundary${degrees}+${offset},mode${mode},selector${selector}`);
  }
}));
test('smooth projection retains no-store declines for unsupported controls and malformed coefficients',()=>withX87ControlWord(0x027f,()=>{
  setup(0);const m=pair[1];
  for(const args of [[31,1,2,1,0],[0,Infinity,2,1,0],[0,1,2,31,0],[0,1,2,1,99]]){
    const before=m.bytes.slice();assert.equal(tryProjectScenePointOutputFast(m,...args,options),undefined);assert.deepEqual(m.bytes,before);
  }
  for(const address of [0x4cc580,0x4cc4f0,0x4ccb68]){
    const original=m.readF64(address);m.writeF64(address,NaN);const before=m.bytes.slice();
    assert.equal(tryProjectScenePointOutputFast(m,0,100,-1000,1,5,options),undefined);assert.deepEqual(m.bytes,before);m.writeF64(address,original);
  }
}));
