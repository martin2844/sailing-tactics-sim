import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {sinCosX87} from '../../../src/runtime/transcendentals.js';
import {originalDrawing0043ec20} from '../src/render/drawing-functions.js';
import {tryProjectChartPointOutputFast} from '../src/render/chart-output-fast.js';
import '../src/render/index.js';

const executable=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const originalOptions={numberRendering:false,retainedDrawingStack:{[0x43ec20]:[]}};
const number=Float80.fromNumber;
// The original byte-translated bearing routine plus the unchanged 468440 C
// coordinate arithmetic provides an independent reference for these windows.
function originalPoint(memory,x,y,selector,camera,scale,centerX,centerY,clampDistance){
  const angle=originalDrawing0043ec20(memory,null,null,originalOptions,number(x),number(y),selector,camera);
  if(clampDistance&&memory.readF64(0x4ccd88)<memory.readF64(0x4fbb88)){
    memory.writeI32(0x4fbb88,0);memory.writeI32(0x4fbb8c,0x40d86a00);
  }
  const distance=number(memory.readF64(0x4fbb88)),trig=sinCosX87(angle);
  let column=trig.sine.multiply(number(scale)).multiply(distance).add(Float80.fromInteger(centerX));
  let row=Float80.fromInteger(centerY).subtract(trig.cosine.multiply(number(scale)).multiply(distance));
  let storedColumn=column.toNumber();
  const upper=number(memory.readF64(0x4ccd78)),lower=number(memory.readF64(0x4ccd80));
  if(upper.compare(column)<0)storedColumn=10000;
  if(storedColumn<lower.toNumber())storedColumn=-10000;
  if(upper.compare(row)<0)row=upper;
  if(row.compare(lower)<0)row=lower;
  return {x:number(storedColumn).truncI32(),y:row.truncI32()};
}
const outputs=memory=>[Buffer.from(memory.readBytes(0x4fbb88,8)).toString('hex'),memory.readI32(0x4f4b40)];
const patch=(memories,fields)=>{for(const memory of memories)for(const [kind,address,value] of fields)memory[`write${kind}`](address,value);};

test('certified chart coordinates match original bearing, clamps, and m80 trigonometry',()=>withX87ControlWord(0x027f,()=>{
  const memories=[loadPE32(executable),loadPE32(executable)];
  let state=0x468440,accepted=0;
  const random=()=>{state=(Math.imul(state,1664525)+1013904223)>>>0;return state;};
  for(let index=0;index<2000;index++){
    const camera=index%30+1,selector=[-3,-1,0,1,2,3,4][index%7];
    patch(memories,[['F64',0x4f6af8+camera*8,(random()%200001-100000)/16],
      ['F64',0x4f6c10+camera*8,(random()%200001-100000)/16],
      ['I32',0x536410,random()%20001-10000],['I32',0x536414,random()%20001-10000],
      ['I32',0x4fbb90+camera*4,random()%360],['I32',0x535740+camera*4,random()%360],
      ['I32',0x522b90+camera*4,random()%360],['I32',0x525a78+camera*4,index%4]]);
    const x=(random()%2000001-1000000)/16,y=(random()%2000001-1000000)/16;
    const args=[x,y,selector,camera,[.0137,.2575,-.4189,1.03125,0][index%5],
      random()%2001-1000,random()%2001-1000,index%2===0];
    const before=outputs(memories[0]),actual=tryProjectChartPointOutputFast(memories[0],...args);
    if(actual===undefined){assert.deepEqual(outputs(memories[0]),before);continue;}
    accepted++;
    assert.deepEqual(actual,originalPoint(memories[1],...args),`chart point ${index}`);
    assert.deepEqual(outputs(memories[0]),outputs(memories[1]),`chart stores ${index}`);
  }
  assert.ok(accepted>1200,`${accepted}/2000 chart windows accepted`);
}));

test('axis constants, mutated ordered clamps, signed zeros and literal distance clamp retain original store order',()=>withX87ControlWord(0x027f,()=>{
  const memories=[loadPE32(executable),loadPE32(executable)];
  const writes=[[],[]];
  for(const [index,memory] of memories.entries())for(const kind of ['F64','I32']){
    const write=memory[`write${kind}`].bind(memory);
    memory[`write${kind}`]=(address,value)=>{writes[index].push([kind,address,value]);write(address,value);};
  }
  patch(memories,[['F64',0x4f6b00,0],['F64',0x4f6c18,0],['I32',0x4fbb94,0],['I32',0x525a7c,0]]);
  let accepted=0;
  for(const [upper,lower] of [[10000,-10000],[1234,-2345],[-10,20]]){
    patch(memories,[['F64',0x4ccd78,upper],['F64',0x4ccd80,lower],['F64',0x4ccd88,100]]);
    for(const [x,y] of [[0,0],[-0,-0],[0,1000],[0,-1000],[123.125,-45789.25],[0.125,0.25]]){
      const args=[x,y,-1,1,.1237,333,277,true];
      writes.forEach(row=>row.length=0);
      const actual=tryProjectChartPointOutputFast(memories[0],...args);
      if(actual===undefined){assert.deepEqual(writes[0],[]);continue;}
      accepted++;
      assert.deepEqual(actual,originalPoint(memories[1],...args));
      assert.deepEqual(writes[0],writes[1]);
    }
  }
  assert.ok(accepted>=12);
}));

test('unsupported chart output windows decline without stores or provider getter calls',()=>{
  const memory=loadPE32(executable),before=outputs(memory);
  for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
    for(const args of [[Infinity,1,0,1,1,0,0,false],[1,2,0,31,1,0,0,false],
      [1,2,0,1,1e20,0,0,false],[1,2,0,1,1,.5,0,false]]){
      assert.equal(tryProjectChartPointOutputFast(memory,...args),undefined);
    }
    for(const field of ['sinCos','atan2','drawingDependencies','retainedDrawingStack']){
      const options=Object.defineProperty({},field,{get(){throw new Error('Unexpected provider getter');}});
      assert.equal(tryProjectChartPointOutputFast(memory,1,2,0,1,1,0,0,false,options),undefined);
    }
    if(word!==0x027f)assert.equal(tryProjectChartPointOutputFast(memory,1,2,0,1,1,0,0,false),undefined);
    assert.deepEqual(outputs(memory),before);
  });
});
