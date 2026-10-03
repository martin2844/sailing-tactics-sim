import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { withX87ControlWord } from '../../../src/runtime/float80.js';
import { BOAT_OPTION_ADDRESSES as addresses,BOAT_SELECTORS,initializeBoatOptions } from '../src/engine/boat-options.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const fixture=JSON.parse(await readFile(new URL('fixtures/original-boat-options.json',import.meta.url),'utf8'));
const hash=bytes=>createHash('sha256').update(bytes).digest('hex');
const baseline=Buffer.from(fixture.mutableBaseline,'hex');
const base=fixture.mutableBlock.address;

test('2010 boat evidence executes unchanged original code in the observed precision',()=>{
  assert.equal(fixture.sourceSha256,hash(source));
  assert.equal(fixture.provenance.sha256,hash(source));
  assert.equal(fixture.provenance.engine,'Original x86 code under Wine; no text edits');
  assert.equal(fixture.provenance.x87ControlWord,'0x027f');
  assert.equal(fixture.provenance.loadedOriginalTextUnchanged,true);
  assert.equal(fixture.provenance.originalFileUnchanged,true);
  assert.equal(hash(baseline),fixture.provenance.mutableBaselineSha256);
  for(const [field,address]of Object.entries({...fixture.integerInputs,...fixture.integerOutputs,...fixture.doubleOutputs}))assert.equal(addresses[field],address,field);
  const selectors=new Set(fixture.cases.map(row=>row.inputs.selector));
  assert.equal(Object.keys(BOAT_SELECTORS).length,27);
  for(let selector=1;selector<=27;selector++)assert.ok(selectors.has(selector),`selector${selector}`);
  for(const invalid of [-0x80000000,-1,0,28,0x7fffffff])assert.ok(selectors.has(invalid));
});

test('all 1677 full boat-option states, floating bits and residual EAX match native original code',()=>{
  const memory=loadPE32(source);
  for(const [index,row]of fixture.cases.entries()){
    memory.writeBytes(base,baseline);
    for(const [field,value]of Object.entries(row.inputs))memory.writeI32(fixture.integerInputs[field],value);
    const before=memory.readBytes(base,baseline.length),expected=before.slice();
    for(const change of row.expected.imageChanges){
      const offset=change.address-base;
      assert.equal(Buffer.from(before.subarray(offset,offset+change.before.length/2)).toString('hex'),change.before,`case${index}:native before bytes`);
      expected.set(Buffer.from(change.after,'hex'),offset);
    }
    const prefix=memory.readBytes(memory.base,base-memory.base);
    const suffix=memory.readBytes(base+baseline.length,memory.size-(base-memory.base)-baseline.length);
    const returned=withX87ControlWord(0x027f,()=>initializeBoatOptions(memory));
    assert.equal(returned>>>0,row.expected.eax,`case${index}:residual EAX`);
    assert.equal(row.expected.rngState,row.seed>>>0,`case${index}:no RNG calls`);
    for(const [field,address]of Object.entries(fixture.integerOutputs))assert.equal(memory.readI32(address),row.expected.integers[field],`case${index}: ${field}`);
    for(const [field,address]of Object.entries(fixture.doubleOutputs))assert.equal(Buffer.from(memory.readBytes(address,8)).toString('hex'),row.expected.doubles[field],`case${index}: ${field} bits`);
    const actual=memory.readBytes(base,baseline.length);
    assert.equal(hash(actual),row.expected.mutableSha256,`case${index}:full native mutable SHA256`);
    assert.deepEqual(actual,expected,`case${index}:all mutable bytes`);
    assert.deepEqual(memory.readBytes(memory.base,prefix.length),prefix,`case${index}:outside mutable prefix`);
    assert.deepEqual(memory.readBytes(base+baseline.length,suffix.length),suffix,`case${index}:outside mutable suffix`);
  }
});
