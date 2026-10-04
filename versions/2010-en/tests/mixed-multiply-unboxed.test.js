import test from 'node:test';
import assert from 'node:assert/strict';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {fpMul} from '../src/render/float-values.js';

const capture=call=>{
  try{return {value:call()};}catch(error){return {error:{name:error.name,message:error.message}};}
};
const image=value=>{
  const boxed=typeof value==='number'?Float80.fromNumber(value):value;
  return {sign:boxed.sign,mantissa:boxed.mantissa,exponent:boxed.exponent};
};
const assertEqual=(actual,expected,label)=>{
  if(expected.error){assert.deepEqual(actual,expected,label);return;}
  assert.ok(!actual.error,label);
  assert.deepEqual(image(actual.value),image(expected.value),label);
  if(typeof actual.value==='number')assert.ok(Object.is(actual.value,expected.value.exactNumber()),label);
};

test('unboxed mixed products preserve boundary images and fallback errors at every precision',()=>{
  const significands=[1n<<63n,(1n<<63n)+1n,(1n<<63n)+1023n,(1n<<63n)+1024n,(1n<<63n)+2047n,(1n<<64n)-1n];
  const values=[0,-0,Number.MIN_VALUE,-Number.MIN_VALUE,2**-1022,-(2**-1022),2**-101,2**-100,
    0.1,-0.1,0.5,-0.5,1,-1,2,-2,2**100,2**101,Number.MAX_VALUE,-Number.MAX_VALUE];
  const inputs=[Float80.fromNumber(0),Float80.fromNumber(-0),Float80.fromNumber(1),Float80.fromNumber(-1),
    Float80.fromNumber(Number.MIN_VALUE),Float80.fromNumber(Number.MAX_VALUE)];
  for(const exponent of [-16445,-1086,-164,-163,-64,-63,35,36,37,16319]){
    for(const sign of [1,-1])for(const mantissa of significands)inputs.push(new Float80(sign,mantissa,exponent));
  }
  let cases=0,unboxed=0;
  for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
    for(const input of inputs)for(const value of values){
      const label=`word${word.toString(16)} ${input.exactKey()} x ${Object.is(value,-0)?'-0':value}`;
      const expected=capture(()=>input.multiplyNumber(value));
      const actual=capture(()=>input.multiplyNumberUnboxed(value));
      assertEqual(actual,expected,label);
      if(typeof actual.value==='number')unboxed++;
      else if(!actual.error)assert.ok(actual.value instanceof Float80,label);
      cases++;
    }
    for(const value of [undefined,null,1n,'1',{},NaN,Infinity,-Infinity]){
      assertEqual(capture(()=>inputs[2].multiplyNumberUnboxed(value)),capture(()=>inputs[2].multiplyNumber(value)),`bad input ${String(value)}`);
      cases++;
    }
  });
  assert.equal(cases,7584);
  assert.ok(unboxed>500,'the intended PC53 carrier-free branch is exercised');
});

test('unboxed mixed products and fpMul match the previous method on retained random m80 values',()=>{
  let state=0x1341ab77;
  const random=()=>{state^=state<<13;state^=state>>>17;state^=state<<5;return state>>>0;};
  let cases=0;
  for(let index=0;index<2048;index++){
    const mantissa=(1n<<63n)|(BigInt(random())<<31n)|BigInt(random());
    const input=new Float80(random()&1?-1:1,mantissa,-163+random()%201);
    const value=(random()&1?-1:1)*(1+random()/2**32)*2**(-100+random()%201);
    for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
      const expected=capture(()=>input.multiplyNumber(value));
      assertEqual(capture(()=>input.multiplyNumberUnboxed(value)),expected,`direct${index}/${word}`);
      assertEqual(capture(()=>fpMul(input,value)),expected,`left${index}/${word}`);
      assertEqual(capture(()=>fpMul(value,input)),expected,`right${index}/${word}`);
      cases+=3;
    });
  }
  assert.equal(cases,18432);
});

test('fpMul preserves the existing dynamic multiplyNumber contract for Float80 subclasses',()=>{
  const calls=[];
  class CustomFloat extends Float80{
    multiplyNumber(value){
      calls.push({receiver:this,value});
      if(value<0)throw new TypeError('custom mixed multiplication');
      return Float80.fromInteger(7);
    }
  }
  const input=new CustomFloat(1,(1n<<63n)+1n,-63);
  withX87ControlWord(0x027f,()=>{
    assert.equal(fpMul(input,2),7);
    assert.equal(fpMul(3,input),7);
    assert.throws(()=>fpMul(input,-2),{name:'TypeError',message:'custom mixed multiplication'});
    assert.throws(()=>fpMul(-3,input),{name:'TypeError',message:'custom mixed multiplication'});
  });
  assert.deepEqual(calls.map(row=>row.value),[2,3,-2,-3]);
  assert.ok(calls.every(row=>row.receiver===input));
});
