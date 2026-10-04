import test from 'node:test';
import assert from 'node:assert/strict';
import {cI32,cAdd,cSub,cMul,cTruth} from '../src/render/typed-c.js';

test('primitive integer arithmetic keeps DWORD wrapping and strict conversions',()=>{
 assert.equal(cI32(0xffffffff),-1);
 assert.equal(cI32(-1,true),0xffffffff);
 assert.equal(cAdd(0x7fffffff,1),-0x80000000);
 assert.equal(cSub(-0x80000000,1),0x7fffffff);
 assert.equal(cMul(0x7fffffff,0x7fffffff),1);
 for(const value of [.5,NaN,Infinity,2**53]){
  assert.throws(()=>cI32(value),TypeError);
  assert.throws(()=>cAdd(value,1),TypeError);
  assert.throws(()=>cSub(1,value),TypeError);
  assert.throws(()=>cMul(value,1),TypeError);
 }
 assert.throws(()=>cAdd(NaN,undefined),/undefined retained local/);
 assert.equal(cTruth(-0),false);
 assert.equal(cTruth(NaN),true);
});

test('integer dispatch preserves semantic events on Number prototypes',()=>{
 const original=Object.getOwnPropertyDescriptor(Number.prototype,'events');
 let reads=0;
 try{
  Object.defineProperty(Number.prototype,'events',{configurable:true,get(){reads++;return true;}});
  assert.equal(cI32(0xffffffff),0xffffffff);
  assert.equal(reads,1);
  reads=0;
  assert.deepEqual(cAdd(3,4),{dc:3,offset:4,kind:'object'});
  assert.equal(reads,3);
  reads=0;
  assert.deepEqual(cSub(3,4),{dc:3,offset:-4,kind:'object'});
  assert.equal(reads,3);
 }finally{
  if(original)Object.defineProperty(Number.prototype,'events',original);
  else delete Number.prototype.events;
 }
});
