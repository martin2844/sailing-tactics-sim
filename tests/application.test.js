import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/memory.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { initializeApplication,PREFERENCE_FIELDS,serializePreferences } from '../src/engine/application.js';
import { withX87ControlWord } from '../src/runtime/float80.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const [original,fixture64,tables64,pc53Fixture,pc53Tables]=await Promise.all([
  readFile(new URL('../original/Tact02Demo.exe',import.meta.url)),json('./fixtures/original-application.json'),json('../assets/data/trig-tables.json'),
  json('./fixtures/original-application-pc53.json'),json('../assets/data/pc53/trig-tables.json'),
]);
for(const [fixture,tables] of [[fixture64,tables64],[pc53Fixture,pc53Tables]])test(`complete original constructor: archive order, sanitization, RNG, graphics and state (64,${fixture.provenance.x87_control_word})`,()=>withX87ControlWord(Number(fixture.provenance.x87_control_word),()=>{
  assert.equal(createHash('sha256').update(original).digest('hex'),fixture.provenance.sha256);
  assert.deepEqual(PREFERENCE_FIELDS,fixture.preferenceFields);
  const memory=loadPE32(original),baseline=memory.bytes.slice(),block=fixture.mutableBlock;
  for(const [index,row] of fixture.routines.initializeApplication.cases.entries()){
    memory.bytes.set(baseline);
    const expected=memory.readBytes(block.address,block.size);
    for(const change of row.expected.imageChanges)expected.set(Buffer.from(change.after,'hex'),change.address-block.address);
    assert.equal(createHash('sha256').update(expected).digest('hex'),row.expected.mutableBlockHash);
    const rng=new PoseyRng(row.seedAtCall),preferences=row.preferences===null?null:Uint8Array.from(Buffer.from(row.preferences,'hex'));
    const objects=initializeApplication(memory,rng,{preferences,timeSeed:row.timeSeed,screenHeight:row.screenHeight,integerTrig:tables});
    assert.deepEqual(memory.readBytes(block.address,block.size),expected,`constructor original case ${index}`);
    assert.equal(rng.state,row.expected.rngState,`constructor RNG ${index}`);
    assert.deepEqual([...objects.values()],row.expected.graphicsDefinitions,`constructor graphics ${index}`);
    const serialized=serializePreferences(memory),view=new DataView(serialized.buffer);
    assert.deepEqual(PREFERENCE_FIELDS.map((address,n)=>view.getInt32(n*4,true)),PREFERENCE_FIELDS.map(address=>memory.readI32(address)));
  }
}));
