import test from 'node:test';
import assert from 'node:assert/strict';
import{readFile}from'node:fs/promises';
import{createHash}from'node:crypto';
import{loadPE32}from'../src/runtime/memory.js';
import*as mouse from'../src/engine/mouse.js';
const fixture=JSON.parse(await readFile(new URL('./fixtures/original-mouse.json',import.meta.url),'utf8'));
const original=await readFile(new URL('../original/Tact02Demo.exe',import.meta.url));
const tables=JSON.parse(await readFile(new URL('../assets/data/trig-tables.json',import.meta.url),'utf8'));
for(const[name,routine]of Object.entries(fixture.routines))test(`${name}: original full state and ordered invalidations/default calls (${routine.cases.length})`,()=>{
  assert.equal(createHash('sha256').update(original).digest('hex'),fixture.provenance.sha256);
  const memory=loadPE32(original),block=fixture.mutableBlock;
  for(let angle=0;angle<362;angle++){
    memory.writeI32(0x4a54a0+angle*4,tables.sine[angle]);
    memory.writeI32(0x4a3450+angle*4,tables.cosine[angle]);
  }
  const baseline=memory.bytes.slice();
  for(const[index,row]of routine.cases.entries()){
    memory.bytes.set(baseline);for(const input of row.imageInputs)memory.writeBytes(input.address,Uint8Array.from(Buffer.from(input.bits,'hex')));
    const expected=memory.readBytes(block.address,block.size);for(const change of row.expected.imageChanges)expected.set(Buffer.from(change.after,'hex'),change.address-block.address);
    const events=[];mouse[name](memory,...row.arguments,{windowHandle:fixture.windowHandle,invalidateRect:event=>events.push({op:'invalidateRect',...event}),defaultMouseHandler:()=>events.push({op:'defaultMouseHandler'})});
    const actual=memory.readBytes(block.address,block.size);
    assert.deepEqual(actual,expected,`${name} original case${index}`);
    assert.equal(createHash('sha256').update(actual).digest('hex'),row.expected.mutableBlockHash,`${name} original full-state hash${index}`);
    assert.deepEqual(events,row.expected.hostEvents,`${name} host order${index}`);
  }
});
