import test from 'node:test';
import assert from 'node:assert/strict';
import {Float80,withX87ControlWord} from '../src/runtime/float80.js';
import {certifiedSqrtNumber} from '../src/runtime/certified-sqrt.js';

const image=new DataView(new ArrayBuffer(8));
function next(value,up){
  image.setFloat64(0,value,true);
  image.setBigUint64(0,image.getBigUint64(0,true)+(up?1n:-1n),true);
  return image.getFloat64(0,true);
}

test('certified roots match exact x87 midpoint comparisons across exponents and square boundaries',()=>withX87ControlWord(0x027f,()=>{
  const values=[];
  for(let exponent=-100;exponent<=100;exponent++){
    const power=2**exponent;
    values.push(power,next(power,false),next(power,true));
  }
  let state=0x43ea10;
  const random=()=>{state=(Math.imul(state,1664525)+1013904223)>>>0;return state;};
  for(let index=0;index<20000;index++)values.push((1+random()/2**32)*2**(random()%200-100));
  for(const root of [1,3,7,100,123.125,1023,2**26]){
    const square=root*root;
    values.push(next(square,false),square,next(square,true));
  }
  // Disable every hardware candidate for the reference calculation: this
  // forces the retained exact integer square-root algorithm even when the
  // production Float80 implementation also uses this certificate.
  const originalSqrt=Math.sqrt;
  let expected;
  try{
    Math.sqrt=()=>NaN;
    expected=values.map(value=>Float80.fromNumber(value).sqrt().toNumber());
  }finally{Math.sqrt=originalSqrt;}
  let accepted=0;
  for(const [index,value] of values.entries()){
    const actual=certifiedSqrtNumber(value);
    if(actual===undefined)continue;
    accepted++;
    assert.equal(actual,expected[index],`square root of ${value}`);
  }
  assert.ok(accepted>values.length*.99,`${accepted}/${values.length} roots certified`);
}));

test('root certification preserves zero signs and declines unsupported or incorrect candidates',()=>{
  assert.ok(Object.is(certifiedSqrtNumber(-0),-0));
  assert.ok(Object.is(certifiedSqrtNumber(0),0));
  for(const value of [undefined,NaN,Infinity,-Infinity,-1,Number.MIN_VALUE,2**-101,2**101]){
    assert.equal(certifiedSqrtNumber(value),undefined);
  }
  const original=Math.sqrt;
  try{
    for(const candidate of [next(1,true),next(1,false),2,Infinity,NaN,0,-1]){
      Math.sqrt=()=>candidate;
      assert.equal(certifiedSqrtNumber(1),undefined,`incorrect candidate ${candidate}`);
    }
    Math.sqrt=()=>{throw new Error('candidate unavailable');};
    assert.equal(certifiedSqrtNumber(1),undefined);
  }finally{Math.sqrt=original;}
});
