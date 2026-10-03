import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { loadPE32 } from '../src/runtime/index.js';
import { sampleSpatialWind } from '../src/engine/spatial-wind.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-spatial-wind.json', import.meta.url), 'utf8'));
const tables = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json', import.meta.url), 'utf8'));
const memory = loadPE32(original);
for (const [address,values] of [[0x4a3450,tables.cosine], [0x4a54a0,tables.sine]]) {
  for (let index = 0; index < values.length; index++) memory.writeI32(address + index * 4,values[index]);
}
for (const {address,bits} of fixtures.baseline) memory.bytes.set(Buffer.from(bits,'hex'),address - memory.base);
const baseline = Buffer.from(memory.bytes);

test('spatial wind matches every original return and complete image state', () => {
  for (const [index,row] of fixtures.cases.entries()) {
    memory.bytes.set(baseline);
    for (const [name,value] of Object.entries(row.inputs)) memory.writeI32(fixtures.inputs[name],value);
    memory.writeI32(0x4aa5b0 + row.boat * 4,row.previousDirection);
    memory.writeF64(0x4a7f28 + row.boat * 8,row.cachedMetric);
    const expected = Buffer.from(memory.bytes);
    for (const {address,bits} of row.expected.stores) expected.set(Buffer.from(bits,'hex'),address - memory.base);
    assert.equal(sampleSpatialWind(memory,row.x,row.y,row.boat),row.expected.returnValue,`case ${index} return`);
    if (!Buffer.from(memory.bytes).equals(expected)) {
      const changes = [];
      for (let offset = 0; offset < expected.length; offset++) if (memory.bytes[offset] !== expected[offset]) changes.push((offset + memory.base).toString(16));
      assert.fail(`case ${index}: ${changes.slice(0,20).join(', ')} differs from original`);
    }
  }
});

test('spatial fixtures exercise all weather, overlaps and both players', () => {
  for (let weather = 0; weather < 8; weather++) assert.ok(fixtures.cases.some(row => row.inputs.weather === weather));
  for (let boat = 0; boat < 4; boat++) assert.ok(fixtures.cases.some(row => row.boat === boat));
  assert.ok(fixtures.cases.some(row => row.expected.stores.some(store => store.address === 0x4a5b94 && store.bits === '01000000')));
});
