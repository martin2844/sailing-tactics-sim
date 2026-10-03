import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { createShorelineStack } from '../src/render/shore-stack.js';

const reference=JSON.parse(await readFile(new URL('../assets/data/pc53/initial-shoreline-stack.json',import.meta.url),'utf8'));
test('production shoreline inputs are grounded in unchanged live original consumed reads',async()=>{
  const original=await readFile(new URL('../original/Tact02Demo.exe',import.meta.url));
  assert.equal(createHash('sha256').update(original).digest('hex'),reference.source_sha256);
  assert.equal(reference.x87_control_word,'0x027f');
  assert.equal(reference.observations.length,reference.sampleCount);
  for(const observation of reference.observations){
    const raw=await readFile(new URL(`../${observation.log}`,import.meta.url));
    assert.equal(createHash('sha256').update(raw).digest('hex'),observation.sha256);
    const events=raw.toString('utf8').trim().split(/\r?\n/).map(line=>JSON.parse(line));
    const entry={...events.find(event=>event.event==='shore-entry')};
    // The earlier probe labeled its read of 4ac948 as "variant". Keep that
    // raw log intact and verify the reference's corrected descriptive label.
    if('unrelatedFlag4ac948' in observation.entry){entry.unrelatedFlag4ac948=entry.variant;delete entry.variant;}
    assert.deepEqual(entry,observation.entry);
    assert.deepEqual(events.filter(event=>event.event==='consumed-retained-input'),observation.consumedReads);
  }
  const selected=reference.observations[reference.selectedSample];
  assert.equal(selected.entry.textUnchanged,true);
  assert.equal(selected.entry.controlWord,'027f');
  assert.equal(reference.variantFlagAddress,0x4a864c);
  for(const [field,value] of Object.entries(reference.context))assert.equal(selected.entry[field],value);
  assert.deepEqual(createShorelineStack(reference),Object.fromEntries(
    ['centerProjectedY','previousX','previousTreeY'].map(field=>[field,selected.entry[field]])));
  for(const [field,instruction,offset] of [['previousX',0x42d668,-0xb54],['previousTreeY',0x42d67d,-0x2d8]]){
    const read=selected.consumedReads.find(event=>event.field===field);
    assert.equal(read.instruction,instruction);
    assert.equal(read.index,selected.entry.first);
    assert.equal(read.address,selected.entry.entryEsp+offset+read.index*4);
    assert.equal(read.value,reference.initialStack[field]);
  }
  assert.notEqual(reference.observations[0].entry.previousX,selected.entry.previousX,'native retained values vary with caller history');
});
