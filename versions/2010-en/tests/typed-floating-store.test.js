import test from 'node:test';
import assert from 'node:assert/strict';
import {Float80} from '../../../src/runtime/float80.js';
import {createLocalFrame,framePointer,readLocal,writeLocal,writeLocalFloatNumber} from '../src/render/typed-c.js';
import {fpArgument} from '../src/render/float-values.js';

const result=callback=>{try{callback();return null;}catch(error){return [error.name,error.message];}};
test('floating Number stores preserve binary64 images and alias validity across packed and public frames',()=>{
  let seed=0x44abc921;
  const random=()=>{seed^=seed<<13;seed^=seed>>>17;seed^=seed<<5;return seed>>>0;};
  const values=[0,-0,Number.MIN_VALUE,-Number.MIN_VALUE,2**-1022,1,2**53,2**63,Number.MAX_VALUE];
  for(let index=0;index<128;index++){
    const bytes=Buffer.alloc(8);bytes.writeUInt32LE(random());bytes.writeUInt32LE(((random()&0x800fffff)|((random()%2047)<<20))>>>0,4);values.push(bytes.readDoubleLE());
  }
  for(const size of [96,688,4096])for(const offset of [0,4,28,32,60,size-8])for(const publicFrame of [false,true]){
    const actual=createLocalFrame(size),expected=createLocalFrame(size);
    if(publicFrame){actual.bytes;expected.bytes;}
    for(const value of values){
      writeLocalFloatNumber(framePointer(actual,offset),value);
      writeLocal(framePointer(expected,offset),fpArgument(value),8,'float');
      assert.deepEqual(readLocal(framePointer(actual,offset),8,'float').toBytes(),readLocal(framePointer(expected,offset),8,'float').toBytes());
    }
    // A partial DWORD overwrite remains visible through the floating view.
    writeLocal(framePointer(actual,offset+4),0,4);writeLocal(framePointer(expected,offset+4),0,4);
    assert.deepEqual(actual.bytes,expected.bytes);assert.deepEqual(actual.valid,expected.valid);
    writeLocalFloatNumber(framePointer(actual,offset),undefined);
    writeLocal(framePointer(expected,offset),undefined,8,'float');
    assert.deepEqual(actual.valid,expected.valid);
    assert.deepEqual(result(()=>readLocal(framePointer(actual,offset),4)),result(()=>readLocal(framePointer(expected,offset),4)));
  }
});

test('floating stores keep conversion failures, deferred infinity reads and signed-zero origins',()=>{
  for(const value of [undefined,true,NaN,Infinity,-Infinity,'semantic text',()=>{}, {frame:{},offset:0},
    Float80.fromNumber(-0),new Float80(-1,1n,-16445),new Float80(1,1n,2000)])for(const offset of [0,28,96]){
    const actual=createLocalFrame(96),expected=createLocalFrame(96);
    assert.deepEqual(result(()=>writeLocalFloatNumber(framePointer(actual,offset),value)),
      result(()=>writeLocal(framePointer(expected,offset),fpArgument(value),8,'float')));
    assert.deepEqual(actual.bytes,expected.bytes);assert.deepEqual(actual.valid,expected.valid);
    assert.deepEqual(result(()=>readLocal(framePointer(actual,offset),8,'float')),result(()=>readLocal(framePointer(expected,offset),8,'float')));
  }
  const frame=createLocalFrame(16);
  writeLocal(framePointer(frame,0),-0,8,'float');assert.ok(Object.is(readLocal(framePointer(frame,0),8,'float').toNumber(),0));
  writeLocalFloatNumber(framePointer(frame,0),-0);assert.ok(Object.is(readLocal(framePointer(frame,0),8,'float').toNumber(),-0));
});
