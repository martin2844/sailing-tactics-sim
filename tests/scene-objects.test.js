import test from 'node:test';
import { assertNativeAuthority } from './native-authority.js';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import * as scene from '../src/render/scene-objects.js';
import { createHullTrig } from '../src/engine/hull-geometry.js';
import { GdiTrace } from '../src/render/gdi.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const readJson = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const [fixtures, tables, trigCapture, hullCapture] = await Promise.all([
  readJson('./fixtures/original-scene-objects.json'),
  readJson('../assets/data/trig-tables.json'), readJson('../assets/data/x87-trig.json'), readJson('../assets/data/x87-hull-trig.json'),
]);
const trig = createCapturedTrig(trigCapture);
const routines = scene;
const addresses = scene.SCENE_OBJECT_ROUTINES;
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
const bytes = bits => Uint8Array.from(Buffer.from(bits, 'hex'));
function mergedRanges(writes) {
  const ranges = [];
  for (const [address, size] of writes.sort((left, right) => left[0] - right[0] || left[1] - right[1])) {
    const previous = ranges.at(-1);
    if (previous && address <= previous.address + previous.size) previous.size = Math.max(previous.address + previous.size, address + size) - previous.address;
    else ranges.push({ address, size });
  }
  return ranges;
}

test('complete scene-object fixtures identify unchanged original code and complete mutable-state contracts', () => {
  assert.equal(fixtures.provenance.sha256, hash(original));
  assert.match(fixtures.provenance.engine, /Unicorn/);
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.equal(fixtures.mutableBlock.address, 0x491000);
  assert.equal(fixtures.mutableBlock.size, 0x1d000);
  assert.equal(fixtures.baseline.integerTrigRoutine, 0x415a60);
  assert.equal(Object.values(fixtures.routines).reduce((count, routine) => count + routine.cases.length, 0), 2464);
  for (const [name, routine] of Object.entries(fixtures.routines)) {
    assert.equal(routine.address, addresses[name]);
    assert.equal(routine.returnType, 'void');
  }
  for (const capture of [tables, trigCapture]) assert.equal(capture.provenance.sha256, fixtures.provenance.sha256);
});

for (const [name, routine] of Object.entries(fixtures.routines)) test(`${name} matches complete original drawing order, complete state, store ranges and RNG (${routine.cases.length} calls)`, () => {
  const memory = loadPE32(original);
  for (const [address, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine]]) values.forEach((value, index) => memory.writeI32(address + index * 4, value));
  const baseline = memory.bytes.slice();
  const block = fixtures.mutableBlock;
  const originalMethods = Object.fromEntries(['writeI32', 'writeU32', 'writeF64', 'writeBytes'].map(method => [method, memory[method].bind(memory)]));
  let writes;
  for (const [method, originalMethod] of Object.entries(originalMethods)) memory[method] = (address, value) => {
    if (writes) writes.push([address, method === 'writeF64' ? 8 : method === 'writeBytes' ? value.length : 4]);
    return originalMethod(address, value);
  };
  const failures = [];
  for (const [index, row] of routine.cases.entries()) {
    memory.bytes.set(baseline);
    for (const input of row.imageInputs) memory.writeBytes(input.address, bytes(input.bits));
    const before = memory.readBytes(block.address, block.size);
    const expected = before.slice();
    const expectedImage = memory.bytes.slice();
    for (const change of row.expected.imageChanges) {
      const offset = change.address - block.address;
      assert.equal(Buffer.from(before.slice(offset, offset + change.before.length / 2)).toString('hex'), change.before, `${name} case ${index}: recorded input bytes`);
      expected.set(bytes(change.after), offset);
      expectedImage.set(bytes(change.after), change.address - memory.base);
    }
    assert.equal(hash(expected), row.expected.mutableBlockHash, `${name} case ${index}: fixture image hash`);
    const rng = new PoseyRng(row.seedAtCall);
    let readIndex = 0;
    const dc = new GdiTrace({ readPixel: () => { assert.ok(readIndex < row.pixelReadValues.length, 'Recorded pixel-input bound'); return row.pixelReadValues[readIndex++]; } });
    writes = [];
    try { routine.argumentTypes[0] === 'CDC' ? (name === 'drawSceneObjects' ? routines[name](memory, dc, ...row.arguments, rng, { trig, hullTrig: createHullTrig(hullCapture) }) : routines[name](memory, dc, ...row.arguments, { trig })) : routines[name](memory, ...row.arguments); }
    catch (error) { failures.push({ index, error: error.message }); writes = undefined; continue; }
    const actualWrites = mergedRanges(writes);
    writes = undefined;
    const equal = Buffer.from(memory.bytes).equals(Buffer.from(expectedImage));
    const mismatch = equal ? -1 : memory.bytes.findIndex((value, offset) => value !== expectedImage[offset]);
    if (mismatch !== -1) failures.push({ index, address: `0x${(memory.base + mismatch).toString(16)}`,
      expected: Buffer.from(expectedImage.slice(mismatch, mismatch + 16)).toString('hex'),
      actual: Buffer.from(memory.bytes.slice(mismatch, mismatch + 16)).toString('hex') });
    if (rng.state !== row.expected.rngState) failures.push({ index, rng: rng.state, expectedRng: row.expected.rngState });
    if (routine.argumentTypes[0] === 'CDC' && JSON.stringify(dc.events) !== JSON.stringify(row.expected.drawingCommands)) {
      const command = dc.events.findIndex((event, i) => JSON.stringify(event) !== JSON.stringify(row.expected.drawingCommands[i]));
      failures.push({ index, command, actual: dc.events.slice(Math.max(0, command), Math.max(0, command)+3), expected: row.expected.drawingCommands.slice(Math.max(0, command), Math.max(0, command)+3) });
    }
    if (JSON.stringify(actualWrites) !== JSON.stringify(row.imageWrites)) failures.push({ index, stores: actualWrites, expectedStores: row.imageWrites });
  }
  assert.equal(failures.length, 0, `${name}: ${failures.length} exact mismatches; first: ${JSON.stringify(failures.slice(0, 12))}`);
});

test('scene observations and complete mutable states have unchanged native original authority', async () => {
  await assertNativeAuthority('original-scene-objects.json', 'scene-objects-native-reference-comparison.json', fixtures);
  assert.equal(fixtures.provenance.pixelReadContract,
    'case.pixelReadValues is the exact consumed ordered U32 return list; GetPixel coordinates and values remain in ordered drawingCommands.');
  for (const row of fixtures.routines.drawSceneObjects.cases) assert.equal(
    row.expected.drawingCommands.filter(event => event.op === 'getPixel').length, row.pixelReadValues.length);
});
