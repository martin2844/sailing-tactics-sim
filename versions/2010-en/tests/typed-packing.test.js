import test from 'node:test';
import assert from 'node:assert/strict';
import {Float80} from '../../../src/runtime/float80.js';
import {bitsAsF64,cConcat,cRawWord,wordsAsF64Number} from '../src/render/typed-c.js';
import {fpI32} from '../src/render/float-values.js';
import {cI32,cI64} from '../src/render/typed-c.js';

const outcome=call=>{try{return {value:call()};}catch(error){return {error:{name:error.name,message:error.message}};}};

test('direct DWORD-to-binary64 loads match complete original CONCAT44 decoding, including signed zero and nonfinite failures',()=>{
  let state=0x214fd345;
  const next=()=>{state=(Math.imul(state,1664525)+1013904223)>>>0;return state;};
  const words=[[0,0],[0x80000000,0],[0,1],[0x80000000,1],[0x7fefffff,0xffffffff],
    [0x00100000,0],[0x000fffff,0xffffffff],[0x7ff00000,0],[0xfff00000,0],[0x7ff80000,1]];
  for(let i=0;i<4000;i++)words.push([next(),next()]);
  for(const [high,low] of words)for(const signed of [false,true]){
    const h=signed?high|0:high,l=signed?low|0:low;
    assert.deepEqual(outcome(()=>wordsAsF64Number(h,l)),outcome(()=>bitsAsF64(cConcat(h,l,4,4)).toNumber()));
  }
});

test('unusual DWORD arguments retain the complete original coercion and failure path',()=>{
  for(const high of [1n,-1n,true,false,0x1ffffffff,1.5,undefined,NaN,Float80.fromNumber(1.75)]){
    for(const low of [0,3n,-1,1.5,undefined,Float80.fromNumber(-1.75)]){
      assert.deepEqual(outcome(()=>wordsAsF64Number(high,low)),outcome(()=>bitsAsF64(cConcat(high,low,4,4)).toNumber()));
    }
  }
  const outer={ [Symbol.toPrimitive](){assert.equal(bitsAsF64(0x8000000000000000n).sign,-1);return 0x3ff8000000000000n;} };
  assert.equal(bitsAsF64(outer).toNumber(),1.5,'reentrant coercion precedes the outer scratch write');
  assert.equal(cRawWord(Float80.fromNumber(-0)),0);
  assert.equal(bitsAsF64(0x8000000000000000n).sign,-1);
});

test('fused floating FTOL64 and low-DWORD casts preserve the existing signed and unsigned results and overflow checks',()=>{
  const values=[0,-0,1.75,-1.75,2**31,-(2**31),2**32+1,-(2**32)-1,2**53+2,
    2**63-1024,-(2**63),2**63,-(2**63)-2048,Number.MIN_VALUE,-Number.MIN_VALUE,
    Float80.fromInteger((1n<<63n)-1n),Float80.fromInteger(-(1n<<63n)-1n)];
  for(const value of values)for(const unsigned of [false,true]){
    const floating=value instanceof Float80?value:Float80.fromNumber(value);
    assert.deepEqual(outcome(()=>fpI32(value,unsigned)),outcome(()=>cI32(cI64(floating),unsigned)));
  }
});
