import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { updateUpwindTactics } from '../src/engine/upwind-tactics.js';
const original = await readFile(new URL('../original/Tact02Demo.exe',import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-upwind-tactics.json',import.meta.url),'utf8'));
const tables = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json',import.meta.url),'utf8'));
const trig = createCapturedTrig(JSON.parse(await readFile(new URL('../assets/data/x87-trig.json',import.meta.url),'utf8')));
const memory = loadPE32(original);
for (let index=0;index<tables.sine.length;index++) {
  memory.writeI32(0x4a3450+index*4,tables.cosine[index]);memory.writeI32(0x4a54a0+index*4,tables.sine[index]);
}
const baseline = Buffer.from(memory.bytes);
test('complete upwind scoring matches original global writes and RNG', () => {
  for(const [index,row] of fixtures.groups.updateUpwindTactics.cases.entries()) {
    memory.bytes.set(baseline);
    for(const {address,bits} of row.inputs)memory.bytes.set(Buffer.from(bits,'hex'),address-memory.base);
    const expected=Buffer.from(memory.bytes);
    for(const {address,bits} of row.expected.stores)expected.set(Buffer.from(bits,'hex'),address-memory.base);
    const rng=new PoseyRng(row.seed);
    updateUpwindTactics(memory,...row.arguments,rng,{trig});
    assert.equal(rng.state,row.expected.rngState,`case ${index} RNG`);
    if(!Buffer.from(memory.bytes).equals(expected)) {
      const changes=[];
      for(let offset=0;offset<expected.length;offset++)if(memory.bytes[offset]!==expected[offset])changes.push((memory.base+offset).toString(16));
      assert.fail(`case ${index} writes: ${changes.slice(0,20).join(', ')}`);
    }
  }
});
