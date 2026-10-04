import test from 'node:test';
import assert from 'node:assert/strict';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {trySmoothSinCosNumber,trySmoothAtanNumber} from '../src/render/smooth-math.js';
import {fpTrig,fpAtan} from '../src/render/float-values.js';
import {originalTrig,originalAtan} from '../src/render/typed-c.js';
import {sinCosX87Number} from '../../../src/runtime/transcendentals.js';

// Exercise the installed hooks, with an independent retained exact reference.
const candidateTrig=fpTrig,candidateAtan=fpAtan;
const exactTrig=(value,options={})=>{
  if('sinCos' in options)return originalTrig(value,options);
  if(value instanceof Float80&&!Number.isNaN(value.exactNumber()))value=value.exactNumber();
  return typeof value==='number'?sinCosX87Number(value):originalTrig(value,options);
};
const exactAtan=(y,x,options={})=>originalAtan(
  y===undefined?undefined:y instanceof Float80?y:typeof y==='number'?Float80.fromNumber(y):y,
  x===undefined?undefined:x instanceof Float80?x:typeof x==='number'?Float80.fromNumber(x):x,options);
const image=value=>value instanceof Float80?{m80:Buffer.from(value.toBytes()).toString('hex')}
  :value&&typeof value==='object'?Object.fromEntries(Object.entries(value).map(([key,item])=>[key,image(item)]))
  :{value};
const outcome=callback=>{
  try{return {returned:image(callback())};}
  catch(error){return {error:{name:error.name,message:error.message}};}
};

test('opted-in finite drawing trig returns Number results with signed zeros and a fresh pair',()=>withX87ControlWord(0x027f,()=>{
  const options={smoothGraphics:true};
  for(const value of [0,-0,Number.MIN_VALUE,-Number.MIN_VALUE,.1,-.1,Math.PI/2,Math.PI,-Math.PI,2**20,-(2**20)]){
    const pair=trySmoothSinCosNumber(value,options);
    assert.equal(typeof pair.sine,'number');assert.equal(typeof pair.cosine,'number');
    assert.ok(Object.is(pair.sine,Math.sin(value)));assert.ok(Object.is(pair.cosine,Math.cos(value)));
    const installed=fpTrig(value,options);
    assert.equal(typeof installed.sine,'number');assert.equal(typeof installed.cosine,'number');
    assert.ok(Object.is(installed.sine,pair.sine));assert.ok(Object.is(installed.cosine,pair.cosine));
  }
  const a=trySmoothSinCosNumber(.25,options),b=trySmoothSinCosNumber(.25,options);
  assert.notEqual(a,b);a.sine=99;assert.equal(b.sine,Math.sin(.25));
}));

test('opted-in atan handles every signed axis and extreme finite ratio without m80 carriers',()=>withX87ControlWord(0x027f,()=>{
  const options={smoothGraphics:true},values=[0,-0,Number.MIN_VALUE,-Number.MIN_VALUE,1,-1,Number.MAX_VALUE,-Number.MAX_VALUE];
  for(const y of values)for(const x of values){
    const result=trySmoothAtanNumber(y,x,options);
    assert.equal(typeof result,'number');assert.ok(Object.is(result,Math.atan2(y,x)));
    assert.ok(Object.is(candidateAtan(y,x,options),result),'zero is accepted, not treated as a decline');
  }
}));

test('absent, false, inherited or accessor flags and unsupported precision retain the exact path',()=>{
  const getter=Object.defineProperty({},'smoothGraphics',{get(){throw new Error('Unexpected flag getter');}});
  const options=[undefined,null,1,'x',{}, {smoothGraphics:false},{smoothGraphics:1},Object.create({smoothGraphics:true}),getter];
  for(const option of options)withX87ControlWord(0x027f,()=>{
    assert.equal(trySmoothSinCosNumber(.2,option),undefined);assert.equal(trySmoothAtanNumber(.2,.3,option),undefined);
    assert.deepEqual(outcome(()=>candidateTrig(.2,option)),outcome(()=>exactTrig(.2,option)));
    assert.deepEqual(outcome(()=>candidateAtan(.2,.3,option)),outcome(()=>exactAtan(.2,.3,option)));
  });
  for(const word of [0x007f,0x037f])withX87ControlWord(word,()=>{
    assert.equal(trySmoothSinCosNumber(.2,{smoothGraphics:true}),undefined);
    assert.equal(trySmoothAtanNumber(.2,.3,{smoothGraphics:true}),undefined);
    assert.deepEqual(outcome(()=>fpTrig(.2,{smoothGraphics:true})),outcome(()=>exactTrig(.2)));
    assert.deepEqual(outcome(()=>fpAtan(.2,.3,{smoothGraphics:true})),outcome(()=>exactAtan(.2,.3)));
  });
});

test('retained/provider paths keep existing getter, argument and callback behavior',()=>withX87ControlWord(0x027f,()=>{
  for(const field of ['sinCos','atan2','retainedDrawingStack','drawingDependencies']){
    let gets=0;
    const option=Object.defineProperty({smoothGraphics:true},field,{get(){gets++;throw new Error('Original getter');}});
    assert.equal(trySmoothSinCosNumber(.2,option),undefined);assert.equal(trySmoothAtanNumber(.2,.3,option),undefined);
    assert.equal(gets,0);
  }
  const run=(trig,atan)=>{
    const events=[];
    const options={smoothGraphics:true,
      get sinCos(){events.push('sinCos:get');return radians=>{events.push(['sinCos',image(radians)]);return {sine:radians,cosine:radians};};},
      get atan2(){events.push('atan2:get');return (y,x)=>{events.push(['atan2',image(y),image(x)]);return y;};}};
    return {trig:outcome(()=>trig(-0,options)),atan:outcome(()=>atan(.2,.3,options)),events};
  };
  assert.deepEqual(run(candidateTrig,candidateAtan),run(exactTrig,exactAtan));
}));

test('unknown/nonfinite/extended operands and large angles keep original failures and values',()=>withX87ControlWord(0x027f,()=>{
  class CustomFloat extends Float80{}
  const options={smoothGraphics:true},values=[undefined,null,'x',1n,NaN,Infinity,-Infinity,
    new Float80(1,1n,2000),new Float80(-1,1n,-16445),new CustomFloat(1,1n,0)];
  for(const value of values){
    assert.equal(trySmoothSinCosNumber(value,options),undefined);
    assert.deepEqual(outcome(()=>candidateTrig(value,options)),outcome(()=>exactTrig(value,options)));
    for(const [y,x] of [[value,.3],[.3,value]]){
      assert.equal(trySmoothAtanNumber(y,x,options),undefined);
      assert.deepEqual(outcome(()=>candidateAtan(y,x,options)),outcome(()=>exactAtan(y,x,options)));
    }
  }
  for(const value of [2**21,-(2**21),2**63,-(2**63),Number.MAX_VALUE]){
    assert.equal(trySmoothSinCosNumber(value,options),undefined);
    assert.deepEqual(outcome(()=>candidateTrig(value,options)),outcome(()=>exactTrig(value,options)));
  }
}));

test('ordinary m80 drawing values may round to Number while underflowed directions decline',()=>withX87ControlWord(0x027f,()=>{
  const options={smoothGraphics:true};
  for(const value of [Float80.fromNumber(-0),Float80.fromNumber(.2),new Float80(1,0x8000000000000001n,-63)]){
    const number=value.toNumber(),pair=trySmoothSinCosNumber(value,options);
    assert.ok(Object.is(pair.sine,Math.sin(number)));assert.ok(Object.is(pair.cosine,Math.cos(number)));
    assert.ok(Object.is(trySmoothAtanNumber(value,Float80.fromNumber(.3),options),Math.atan2(number,.3)));
    const installed=fpTrig(value,options);
    assert.ok(Object.is(installed.sine,pair.sine));assert.ok(Object.is(installed.cosine,pair.cosine));
    assert.ok(Object.is(fpAtan(value,Float80.fromNumber(.3),options),Math.atan2(number,.3)));
  }
  const tiny=new Float80(1,1n,-16445);
  assert.equal(trySmoothAtanNumber(tiny,tiny,options),undefined);
}));

test('ordinary display-angle differences from x87 remain small while the exact helper stays unchanged',()=>withX87ControlWord(0x027f,()=>{
  for(let index=-80;index<=80;index++){
    const angle=index*Math.PI/20,actual=trySmoothSinCosNumber(angle,{smoothGraphics:true}),exact=fpTrig(angle,{});
    assert.ok(Math.abs(actual.sine-exact.sine.toNumber())<=4e-15);
    assert.ok(Math.abs(actual.cosine-exact.cosine.toNumber())<=4e-15);
    const numeric=trySmoothAtanNumber(Math.sin(angle),Math.cos(angle),{smoothGraphics:true});
    const extended=fpAtan(Math.sin(angle),Math.cos(angle),{});
    assert.ok(Math.abs(numeric-extended.toNumber())<=4e-15);
  }
}));
