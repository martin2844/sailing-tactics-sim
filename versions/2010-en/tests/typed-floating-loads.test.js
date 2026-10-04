import test from 'node:test';
import assert from 'node:assert/strict';
import {Float80} from '../../../src/runtime/float80.js';
import {createLocalFrame,framePointer,pointerAdd,localPointer,readPointer,readPointerFloatNumber,
  readLocalFloatWordsNumber,writeLocal,wordsAsF64Number,cRawWord} from '../src/render/typed-c.js';

const outcome=call=>{try{const value=call();return {value:value instanceof Float80?value.toNumber():value};}
  catch(error){return {error:{name:error.name,message:error.message}};}};
const originalWords=(memory,pointer)=>wordsAsF64Number(cRawWord(readPointer(memory,pointerAdd(pointer,4),4)),cRawWord(readPointer(memory,pointer,4)));

test('raw floating pointer loads preserve binary64 images and all other pointer dispatch',()=>{
  const view=new DataView(new ArrayBuffer(8));let bits=0xa127cc13;
  const memory={readF64(address){assert.equal(address,0xfffffffc);return view.getFloat64(0,true);}};
  for(let index=0;index<4000;index++){
    bits=(Math.imul(bits,1664525)+1013904223)>>>0;view.setUint32(0,bits,true);
    bits=(Math.imul(bits,1664525)+1013904223)>>>0;view.setUint32(4,bits,true);
    assert.deepEqual(outcome(()=>readPointerFloatNumber(memory,-4)),outcome(()=>readPointer(memory,-4,8)));
  }
  const frame=createLocalFrame(40),stored={events:[]};
  for(const value of [-0,Number.MIN_VALUE,2**63,undefined,stored]){
    writeLocal(framePointer(frame,4),value instanceof Object||value===undefined?value:Float80.fromNumber(value),8,'float');
    assert.deepEqual(outcome(()=>readPointerFloatNumber(undefined,framePointer(frame,4))),outcome(()=>readPointer(undefined,framePointer(frame,4),8)));
  }
  for(const pointer of [localPointer([-0],8),localPointer([Float80.fromNumber(1.25)],8),localPointer([undefined],8),
    {dc:stored,offset:0,kind:'object'},{dc:stored,offset:4,kind:'object'},stored,
    {frame,offset:4,events:[]},{frame,offset:4,dc:stored,kind:'object'}]){
    assert.deepEqual(outcome(()=>readPointerFloatNumber(undefined,pointer)),outcome(()=>readPointer(undefined,pointer,8)));
  }
  for(const pointer of [2**63,NaN,Infinity,undefined]){
    assert.deepEqual(outcome(()=>readPointerFloatNumber(memory,pointer)),outcome(()=>readPointer(memory,pointer,8)));
  }
});

test('fused local DWORD floating loads retain every finite/nonfinite image in packed and public byte frames',()=>{
  const view=new DataView(new ArrayBuffer(8));let bits=0x52cab419;
  for(let index=0;index<4000;index++){
    bits=(Math.imul(bits,1664525)+1013904223)>>>0;view.setUint32(0,bits,true);
    bits=(Math.imul(bits,1664525)+1013904223)>>>0;view.setUint32(4,bits,true);
    for(const materialized of [false,true]){
      const frame=createLocalFrame(48),offset=materialized?index%9:4*(index%10),pointer=framePointer(frame,offset);
      if(materialized){frame.bytes.set(new Uint8Array(view.buffer),offset);frame.valid.fill(1,offset,offset+8);}
      else{writeLocal(pointer,view.getInt32(0,true),4,'int');writeLocal(pointerAdd(pointer,4),view.getInt32(4,true),4,'int');}
      assert.deepEqual(outcome(()=>readLocalFloatWordsNumber(undefined,pointer)),outcome(()=>originalWords(undefined,pointer)));
    }
  }
});

test('fused local floating loads preserve high-word-first failures, semantic words and wraparound',()=>{
  for(const offset of [-0x80000000,-4,-1,0,1,4,28,32,36,40,0x7fffffff]){
    for(const known of [[],[0],[4],[0,4],[28],[32],[28,32]]){
      const frame=createLocalFrame(40);for(const at of known)writeLocal(framePointer(frame,at),0,4,'int');
      const pointer=framePointer(frame,offset);
      assert.deepEqual(outcome(()=>readLocalFloatWordsNumber(undefined,pointer)),outcome(()=>originalWords(undefined,pointer)));
    }
  }
  for(const semanticSize of [4,8])for(const at of [0,4]){
    const frame=createLocalFrame(16),pointer=framePointer(frame,0),semantic={events:[]};
    writeLocal(pointer,0,4,'int');writeLocal(pointerAdd(pointer,4),0,4,'int');
    writeLocal(framePointer(frame,at),semantic,semanticSize,semanticSize===8?'float':'int');
    assert.deepEqual(outcome(()=>readLocalFloatWordsNumber(undefined,pointer)),outcome(()=>originalWords(undefined,pointer)));
  }
  const array=localPointer([0,0]);
  assert.deepEqual(outcome(()=>readLocalFloatWordsNumber(undefined,array)),outcome(()=>originalWords(undefined,array)));
  const frame=createLocalFrame(16);writeLocal(framePointer(frame,0),0,4,'int');writeLocal(framePointer(frame,4),0,4,'int');
  for(const pointer of [{frame,offset:0,events:[]},{frame,offset:0,dc:{events:[]},kind:'object'}]){
    assert.deepEqual(outcome(()=>readLocalFloatWordsNumber(undefined,pointer)),outcome(()=>originalWords(undefined,pointer)));
  }
});

test('raw floating pointer loads keep inherited numeric events and their getter order',()=>{
  const descriptor=Object.getOwnPropertyDescriptor(Number.prototype,'events');
  try{
    for(const provided of [true,false]){
      let reads=0;
      Object.defineProperty(Number.prototype,'events',{configurable:true,get(){reads++;return provided?[]:undefined;}});
      const memory={readF64:()=>1.25};
      const actual=outcome(()=>readPointerFloatNumber(memory,12)),actualReads=reads;reads=0;
      const expected=outcome(()=>readPointer(memory,12,8));
      assert.deepEqual(actual,expected);assert.equal(actualReads,reads);
    }
  }finally{if(descriptor)Object.defineProperty(Number.prototype,'events',descriptor);else delete Number.prototype.events;}
});
