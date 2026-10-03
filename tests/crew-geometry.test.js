import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { crewPositionFactor, writeCrewGeometry, initializeCrewGeometry, CREW_GEOMETRY_ROUTINES } from '../src/render/crew-geometry.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-crew-geometry.json', import.meta.url), 'utf8'));
const tables = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json', import.meta.url), 'utf8'));
const routines = { crewPositionFactor, writeCrewGeometry, initializeCrewGeometry };
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
const bytes = bits => Uint8Array.from(Buffer.from(bits, 'hex'));
const bits = value => { const buffer = Buffer.alloc(8); buffer.writeDoubleLE(value); return buffer.toString('hex'); };
function mergedRanges(writes) {
  const ranges = [];
  for (const [address, size] of writes.sort((left, right) => left[0] - right[0] || left[1] - right[1])) {
    const previous = ranges.at(-1);
    if (previous && address <= previous.address + previous.size) previous.size = Math.max(previous.address + previous.size, address + size) - previous.address;
    else ranges.push({ address, size });
  }
  return ranges;
}

test('crew references identify original code, initialized selectors and complete state scope', () => {
  assert.equal(fixtures.provenance.sha256, hash(original));
  assert.match(fixtures.provenance.engine, /Unicorn/);
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.equal(fixtures.baseline.integerTrigRoutine, 0x415a60);
  assert.equal(fixtures.mutableBlock.address, 0x491000);
  assert.equal(fixtures.mutableBlock.size, 0x1d000);
  assert.equal(Object.values(fixtures.routines).reduce((sum, row) => sum + row.cases.length, 0), 725);
  for (const [name, routine] of Object.entries(fixtures.routines)) assert.equal(routine.address, CREW_GEOMETRY_ROUTINES[name]);
});

for (const [name, routine] of Object.entries(fixtures.routines)) test(`${name}: exact complete image, stores and extended return (${routine.cases.length} cases)`, () => {
  const memory = loadPE32(original);
  for (const [address, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine]]) values.forEach((value, index) => memory.writeI32(address + index * 4, value));
  const baseline = memory.bytes.slice();
  const originals = Object.fromEntries(['writeI32', 'writeF64'].map(method => [method, memory[method].bind(memory)]));
  let writes;
  for (const [method, originalMethod] of Object.entries(originals)) memory[method] = (address, value) => {
    if (writes) writes.push([address, method === 'writeF64' ? 8 : 4]);
    return originalMethod(address, value);
  };
  const failures = [];
  for (const [index, row] of routine.cases.entries()) {
    memory.bytes.set(baseline);
    for (const input of row.imageInputs) memory.writeBytes(input.address, bytes(input.bits));
    const before = memory.readBytes(fixtures.mutableBlock.address, fixtures.mutableBlock.size);
    const expectedImage = memory.bytes.slice();
    for (const change of row.expected.imageChanges) {
      const offset = change.address - fixtures.mutableBlock.address;
      assert.equal(Buffer.from(before.slice(offset, offset + change.before.length / 2)).toString('hex'), change.before, `${name} case ${index}: original input`);
      expectedImage.set(bytes(change.after), change.address - memory.base);
    }
    assert.equal(hash(expectedImage.slice(fixtures.mutableBlock.address - memory.base, fixtures.mutableBlock.address - memory.base + fixtures.mutableBlock.size)), row.expected.mutableBlockHash, `${name} case ${index}: original final-image hash`);
    writes = [];
    let returned;
    try { returned = routines[name](memory, ...row.arguments); }
    catch (error) { failures.push({ index, error: error.message }); writes = undefined; continue; }
    const actualWrites = mergedRanges(writes);
    writes = undefined;
    if (!Buffer.from(memory.bytes).equals(Buffer.from(expectedImage))) {
      const mismatch = memory.bytes.findIndex((value, offset) => value !== expectedImage[offset]);
      failures.push({ index, address: `0x${(memory.base + mismatch).toString(16)}`,
        expected: Buffer.from(expectedImage.slice(mismatch, mismatch + 16)).toString('hex'),
        actual: Buffer.from(memory.bytes.slice(mismatch, mismatch + 16)).toString('hex') });
    }
    if (JSON.stringify(actualWrites) !== JSON.stringify(row.imageWrites)) failures.push({ index, stores: actualWrites, expectedStores: row.imageWrites });
    if (routine.returnType === 'Float80') {
      assert.equal(Buffer.from(returned.toBytes()).toString('hex'), row.expected.returnExtendedBits, `${name} case ${index}: ST0`);
      assert.equal(bits(returned.toNumber()), row.expected.returnBits, `${name} case ${index}: binary64`);
    }
  }
  assert.equal(failures.length, 0, `${name}: ${failures.length} exact mismatches; first: ${JSON.stringify(failures.slice(0, 12))}`);
});

test('uninitialized original crew factor selectors are rejected explicitly', () => {
  const memory = loadPE32(original);
  for (const selector of [-3, 3, -0x80000000, 0x7fffffff]) assert.throws(() => crewPositionFactor(memory, selector), /uninitialized/);
});
