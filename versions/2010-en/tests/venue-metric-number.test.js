import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {sinCosX87} from '../../../src/runtime/transcendentals.js';
import {sampleVenueMetric} from '../src/engine/spatial-metrics.js';
import {numberVenueMetricEnabled} from '../src/engine/venue-metric-number.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const fixture=JSON.parse(await readFile(new URL('fixtures/original-sampleVenueMetric.json',import.meta.url),'utf8'));
const baseline=Buffer.from(fixture.mutableBaseline,'hex');

test('venue numeric loop requires PC53 and leaves custom trig providers on the original path',()=>{
  for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
    assert.equal(numberVenueMetricEnabled({}),word===0x027f);
    assert.equal(numberVenueMetricEnabled({sinCosX87:undefined}),false);
    assert.equal(numberVenueMetricEnabled(Object.create({sinCosX87})),false);
    assert.equal(numberVenueMetricEnabled(null),false);
  });
});

test('venue point loop preserves exact returns, failures and ordered reads at floating boundaries',()=>{
  const memory=loadPE32(source),reads=[];
  const nativeRead32=memory.readI32.bind(memory),nativeRead64=memory.readF64.bind(memory);
  memory.readI32=address=>{reads.push(['I32',address]);return nativeRead32(address);};
  memory.readF64=address=>{reads.push(['F64',address]);return nativeRead64(address);};
  const run=(args,options)=>{
    reads.length=0;
    try{
      const returned=sampleVenueMetric(memory,...args,options);
      assert.ok(returned instanceof Float80);
      return {bits:Buffer.from(returned.toBytes()).toString('hex'),reads:reads.slice()};
    }catch(error){return {error:{name:error.name,message:error.message},reads:reads.slice()};}
  };
  const restore=row=>{
    memory.writeBytes(fixture.mutableBlock.address,baseline);
    for(const [field,value] of Object.entries(row.inputs??{}))memory.writeI32(fixture.integerInputs[field],value);
    for(const [field,value] of Object.entries(row.doubleInputs??{}))memory.writeF64(fixture.doubleInputs[field],value);
    for(const patch of row.patches??[])memory.writeBytes(patch.address,Buffer.from(patch.bytes,'hex'));
  };
  const values=[0,-0,Number.MIN_VALUE,2**-1022,2**-500,2**-100,0.1,1,Math.PI,2**100,2**500,Number.MAX_VALUE,Infinity,NaN];
  const addresses=[0x4fafa8+8,0x4fb5e0+8,0x4cc658,0x4cc468,0x4cccc8,0x4cccc0,0x4cc920,0x4cc650];
  let cases=0;
  withX87ControlWord(0x027f,()=>{
    for(const index of [0,29,51,113,221,447,691,1001]){
      const row=fixture.cases[index];
      for(const address of addresses)for(const value of values){
        restore(row);memory.writeF64(address,value);
        const before=memory.readBytes(memory.base,memory.size);
        const optimized=run(row.arguments,{});
        const original=run(row.arguments,{sinCosX87});
        assert.deepEqual(optimized,original,`case${index} address${address.toString(16)} value${String(value)}`);
        assert.deepEqual(memory.readBytes(memory.base,memory.size),before,'metric is read-only');
        cases++;
      }
    }
  });
  assert.equal(cases,896);
});

test('custom venue trig callback retains Float80 arguments and its original call order',()=>{
  const memory=loadPE32(source),row=fixture.cases[0];
  memory.writeBytes(fixture.mutableBlock.address,baseline);
  for(const [field,value] of Object.entries(row.inputs??{}))memory.writeI32(fixture.integerInputs[field],value);
  for(const patch of row.patches??[])memory.writeBytes(patch.address,Buffer.from(patch.bytes,'hex'));
  let calls=0;
  withX87ControlWord(0x027f,()=>sampleVenueMetric(memory,...row.arguments,{
    sinCosX87(angle){assert.ok(angle instanceof Float80);calls++;return sinCosX87(angle);},
  }));
  assert.ok(calls>0);
});
