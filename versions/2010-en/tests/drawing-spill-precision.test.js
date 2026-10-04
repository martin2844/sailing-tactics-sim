import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {cFloat,cF64} from '../src/render/typed-c.js';

const oldSpill=value=>Float80.fromNumber(cFloat(value).toNumber());
const capture=(spill,value)=>{
 try{return {bits:Buffer.from(spill(value).toBytes()).toString('hex')};}
 catch(error){return {name:error.constructor.name,message:error.message};}
};
const inputs=[-0,0,-1,1,1.5,Number.MIN_VALUE,-Number.MIN_VALUE,Number.MAX_VALUE,-Number.MAX_VALUE,1e20,NaN,Infinity,-Infinity,undefined,null,false,true,'1',1n,1n<<100n];
for(const value of [-0,0,-1,1,1.5,Number.MIN_VALUE,-Number.MIN_VALUE,Number.MAX_VALUE,-Number.MAX_VALUE])inputs.push(Float80.fromNumber(value));
for(const sign of [-1,1])for(const exponent of [-16445,-1138,-1137,-1136,-1086,-1085,-1084,-1074,-1073,-63,-1,0,960,961,962,16320]){
 for(const mantissa of [0n,1n,1n<<52n,1n<<63n,(1n<<63n)+1n,(1n<<63n)+1023n,(1n<<63n)+1024n,(1n<<63n)+1025n,(1n<<63n)+3072n,(1n<<64n)-1n]){
  inputs.push(new Float80(sign,mantissa,exponent));
 }
}
for(const cw of [0x007f,0x027f,0x037f])test(`drawing F64 spill preserves m80 bits, signed zero and failures under CW${cw.toString(16)}`,()=>{
 withX87ControlWord(cw,()=>{
  for(const [index,value] of inputs.entries())assert.deepEqual(capture(cF64,value),capture(oldSpill,value),`input ${index}`);
  const arithmetic=[
   Float80.fromNumber(1).divide(Float80.fromNumber(3)),
   Float80.fromNumber(Number.MIN_VALUE).multiply(Float80.fromNumber(.5)),
   Float80.fromNumber(Number.MAX_VALUE).multiply(Float80.fromNumber(2)),
   Float80.fromNumber(-0).multiply(Float80.fromNumber(1)),
  ];
  for(const [index,value] of arithmetic.entries())assert.deepEqual(capture(cF64,value),capture(oldSpill,value),`arithmetic ${index}`);
 });
});

for(const construction of ['extended','stored']){
 const fixture=JSON.parse(await readFile(new URL(`../assets/data/x87-${construction==='extended'?'':'stored-'}trig.json`,import.meta.url)));
 test(`drawing F64 spills preserve every captured native ${construction} sine/cosine`,()=>{
  withX87ControlWord(0x027f,()=>{
   for(const [angle,pair] of Object.entries(fixture.angles))for(const key of ['sineBits','cosineBits']){
    const value=Float80.fromBytes(Buffer.from(pair[key],'hex'));
    assert.deepEqual(capture(cF64,value),capture(oldSpill,value),`${construction} ${angle} ${key}`);
   }
  });
 });
}

test('exact binary64 drawing operands reuse their immutable Float80 value',()=>{
 for(const value of [-0,0,-1,1,1.5,Number.MIN_VALUE,Number.MAX_VALUE]){
  const operand=Float80.fromNumber(value);
  assert.equal(cF64(operand),operand);
 }
});
