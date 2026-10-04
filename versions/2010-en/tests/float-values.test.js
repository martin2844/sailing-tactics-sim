import test from 'node:test';
import assert from 'node:assert/strict';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import * as fp from '../src/render/float-values.js';
import {cF64} from '../src/render/typed-c.js';

const hex=value=>Buffer.from(fp.fpBox(value).toBytes()).toString('hex');
const outcome=callback=>{try{return {bits:hex(callback())};}catch(error){return {name:error.name,message:error.message};}};

test('typed floating Number arithmetic keeps exact m80 under every supported precision',()=>{
  const boundary=[0,-0,Number.MIN_VALUE,-Number.MIN_VALUE,2**-1022, -(2**-1022),1,-1,0.1,-0.1,1+2**-52,2**-53,2**-54,2**53,2**63,Number.MAX_VALUE,-Number.MAX_VALUE];
  let seed=0x117dac98;
  const random=()=>{seed^=seed<<13;seed^=seed>>>17;seed^=seed<<5;return seed>>>0;};
  const pairs=boundary.flatMap(left=>boundary.map(right=>[left,right]));
  for(let index=0;index<1600;index++){
    const number=()=>{const bytes=Buffer.alloc(8);bytes.writeUInt32LE(random());bytes.writeUInt32LE(((random()&0x800fffff)|((random()%2047)<<20))>>>0,4);return bytes.readDoubleLE();};
    pairs.push([number(),number()]);
  }
  for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
    for(const [a,b]of pairs)for(const [helper,method]of [['fpAdd','add'],['fpSub','subtract'],['fpMul','multiply'],['fpDiv','divide']]){
      assert.deepEqual(outcome(()=>fp[helper](a,b)),outcome(()=>Float80.fromNumber(a)[method](Float80.fromNumber(b))),`${word}/${method}/${a}/${b}`);
    }
    for(const a of boundary)for(const extended of [new Float80(1,0x8000000000000001n,-63),new Float80(-1,1n,2000),new Float80(1,1n,-16445)]){
      for(const [helper,method]of [['fpAdd','add'],['fpSub','subtract'],['fpMul','multiply'],['fpDiv','divide']]){
        assert.deepEqual(outcome(()=>fp[helper](a,extended)),outcome(()=>Float80.fromNumber(a)[method](extended)));
        assert.deepEqual(outcome(()=>fp[helper](extended,a)),outcome(()=>extended[method](Float80.fromNumber(a))));
      }
    }
  });
});

test('typed loads, integer conversions, binary64 spills and forwarding retain signed zero and failures',()=>{
  assert.ok(Object.is(fp.fpLoad(-0),-0));
  assert.ok(Object.is(fp.fpFromInteger(-0),0));
  assert.ok(Object.is(fp.fpNeg(0),-0));
  assert.ok(Object.is(fp.fpAbs(-0),0));
  assert.ok(Object.is(fp.fpStoreF64(Float80.fromNumber(-0)),-0));
  assert.equal(fp.fpArgument(undefined),undefined);
  assert.equal(fp.fpLoad(2**63),2**63,'binary64 load is independent of signed integer range');
  const tiny=new Float80(-1,1n,-16445),huge=new Float80(1,1n,2000);
  assert.ok(Object.is(fp.fpStoreF64(tiny),-0));
  assert.equal(fp.fpToNumber(huge),Infinity,'global F64 store may write infinity');
  assert.throws(()=>fp.fpStoreF64(huge),/NaN or infinite/,'cast spill reload rejects infinity');
  for(const value of [NaN,Infinity,-Infinity])assert.throws(()=>fp.fpLoad(value),RangeError);
  for(const value of [0,-0,1.5,-1.5,2**53,-(2**63),2**63,Number.MIN_VALUE,Number.MAX_VALUE]){
    for(const unsigned of [false,true]){
      const capture=callback=>{try{return {value:String(callback())};}catch(error){return {name:error.name,message:error.message};}};
      const floating=Float80.fromNumber(value);
      assert.deepEqual(capture(()=>fp.fpI32(value,unsigned)),capture(()=>unsigned?floating.truncI32()>>>0:floating.truncI32()));
      assert.deepEqual(capture(()=>fp.fpI64(value,unsigned)),capture(()=>unsigned?BigInt.asUintN(64,floating.truncI64()):floating.truncI64()));
    }
    assert.equal(fp.fpTruth(value),floatingTruth(value));
  }
  function floatingTruth(value){return Float80.fromNumber(value).compare(Float80.fromInteger(0))!==0;}
});

test('Number drawing dispatch preserves retained/custom host paths without reading callback getters',()=>withX87ControlWord(0x027f,()=>{
  assert.equal(fp.fpDrawingEnabled({}),true);
  for(const key of ['retainedDrawingStack','sinCos','atan2','drawingDependencies']){
    const options=Object.defineProperty({},key,{get(){throw new Error('Guard evaluated original host getter');}});
    assert.equal(fp.fpDrawingEnabled(options),false);
    assert.equal(fp.fpDrawingEnabled(Object.create(options)),false);
  }
  for(const options of [null,1,'x',Object.freeze({numberRendering:false})])assert.equal(fp.fpDrawingEnabled(options),false);
  const flag=Object.defineProperty({},'numberRendering',{get(){throw new Error('Extra debug getter ran');}});
  assert.equal(fp.fpDrawingEnabled(flag),false);
  assert.equal(fp.fpDrawingEnabled(Object.create(flag)),false);
  withX87ControlWord(0x037f,()=>assert.equal(fp.fpDrawingEnabled({}),false));
}));

test('Number scalar storage preserves deferred nonfinite errors, unknown arguments and semantic values',()=>{
  const minusZero=fp.fpScalarStoreF64(-0);
  assert.ok(Object.is(fp.fpScalarRead(minusZero),-0));
  assert.equal(fp.fpScalarReadArgument(undefined),undefined);
  assert.throws(()=>fp.fpScalarRead(undefined),/undefined retained local byte/);
  const stored=fp.fpScalarStoreF64(new Float80(1,1n,2000));
  assert.throws(()=>fp.fpScalarRead(stored),/NaN or infinite/);
  assert.throws(()=>fp.fpScalarReadArgument(stored),/NaN or infinite/);
  assert.equal(fp.fpScalarRead(fp.fpScalarStoreF64(3)),3,'overwriting an unread infinity succeeds');
  assert.throws(()=>fp.fpScalarStoreF64(Infinity),/NaN or infinite/);
  for(const semantic of ['original text',()=>{}, {frame:{},offset:0},{clipRect:[]}]){
    assert.equal(fp.fpScalarStoreF64(semantic),semantic);
    assert.equal(fp.fpScalarRead(semantic),semantic);
  }
});

test('numeric F64 formals distinguish exact floating images from original integer arguments',()=>{
  const capture=callback=>{try{return {value:callback()};}catch(error){return {name:error.name,message:error.message};}};
  const values=[undefined,0,-0,1,-1,0.1,2**53,2**63,Number.MIN_VALUE,NaN,Infinity,1n,9007199254740993n,
    Float80.fromNumber(-0),new Float80(1,0x8000000000000001n,-63),new Float80(-1,1n,-16445),new Float80(1,1n,2000)];
  for(const value of values){
    assert.deepEqual(capture(()=>fp.fpFormalF64(value)),capture(()=>value===undefined?undefined:cF64(value).toNumber()));
    if(typeof value==='number'||value instanceof Float80||value===undefined){
      assert.deepEqual(capture(()=>fp.fpFormalF64(value,true)),capture(()=>value===undefined?undefined:cF64(fp.fpBox(value)).toNumber()));
    }
  }
  assert.ok(Object.is(fp.fpFormalF64(-0),0));
  assert.ok(Object.is(fp.fpFormalF64(-0,true),-0));
  assert.equal(fp.fpFormalF64(2**63,true),2**63);
});
