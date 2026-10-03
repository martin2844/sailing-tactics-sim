import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { scoreDownwindTurn, chooseDownwindHeading } from '../src/engine/ai-tactics.js';

const original = await readFile(new URL('../original/Tact02Demo.exe',import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-ai-tactics.json',import.meta.url),'utf8'));
const tables = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json',import.meta.url),'utf8'));
const trig = createCapturedTrig(JSON.parse(await readFile(new URL('../assets/data/x87-trig.json',import.meta.url),'utf8')));
const memory = loadPE32(original);
for (let i=0;i<tables.sine.length;i++) {
  memory.writeI32(0x4a3450+i*4,tables.cosine[i]); memory.writeI32(0x4a54a0+i*4,tables.sine[i]);
}
const baseline = Buffer.from(memory.bytes);
for (const [name,routine] of Object.entries({scoreDownwindTurn,chooseDownwindHeading})) {
  test(`${name} preserves every original image byte, RNG and integer result`, () => {
    for (const [index,row] of fixtures.groups[name].cases.entries()) {
      memory.bytes.set(baseline);
      for (const {address,bits} of row.inputs) memory.bytes.set(Buffer.from(bits,'hex'),address-memory.base);
      const expected = Buffer.from(memory.bytes);
      for (const {address,bits} of row.expected.stores) expected.set(Buffer.from(bits,'hex'),address-memory.base);
      const rng = new PoseyRng(row.seed);
      const result = routine(memory,...row.arguments,rng,{trig});
      assert.equal(result,row.expected.returnValue,`${name} ${index} result`);
      assert.equal(rng.state,row.expected.rngState,`${name} ${index} RNG`);
      if (!Buffer.from(memory.bytes).equals(expected)) {
        const changes=[];
        for(let offset=0;offset<expected.length;offset++)if(memory.bytes[offset]!==expected[offset])changes.push((memory.base+offset).toString(16));
        assert.fail(`${name} ${index}: changed bytes ${changes.slice(0,20).join(', ')}`);
      }
    }
  });
}
