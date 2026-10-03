import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { updateBoatDynamics, BOAT_DYNAMICS_ADDRESSES } from '../src/engine/boat-dynamics.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const readJson = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const [fixtures, tables, trigCapture, forceCapture] = await Promise.all([
  readJson('./fixtures/original-boat-dynamics.json'), readJson('../assets/data/trig-tables.json'),
  readJson('../assets/data/x87-trig.json'), readJson('../assets/data/x87-force-trig.json'),
]);
const trig = createCapturedTrig(trigCapture, undefined, forceCapture);
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

test('boat dynamics references cover the complete original routine and measured native corrections', () => {
  assert.equal(fixtures.provenance.sha256, hash(original));
  assert.equal(fixtures.provenance.engine, 'Unicorn with documented native original-code corrections');
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.equal(fixtures.provenance.sound_import_stub, '004b1c18');
  assert.equal(fixtures.provenance.tls_accessor_stub, '00459ed0');
  const correction = fixtures.provenance.native_corrections;
  assert.equal(correction.original_sha256, fixtures.provenance.sha256);
  assert.equal(correction.corrected_cases, 94);
  assert.match(correction.reason, /host x87 under Wine/);
  assert.match(correction.reason, /No tolerance or original executable edits/);
  assert.equal(fixtures.mutableBlock.address, 0x491000);
  assert.equal(fixtures.mutableBlock.size, 0x1d000);
  assert.equal(fixtures.baseline.integerTrigRoutine, 0x415a60);
  const routine = fixtures.routines.updateBoatDynamics;
  assert.equal(routine.address, BOAT_DYNAMICS_ADDRESSES.updateBoatDynamics);
  assert.equal(routine.returnType, 'void');
  assert.equal(routine.cases.length, 4098);
  const counts = {};
  for (const row of routine.cases) counts[row.branch] = (counts[row.branch] ?? 0) + 1;
  assert.deepEqual(counts, { 'all-sailing-angles': 2715, 'trim-depower': 630, heel: 255, 'time-stage': 198, 'random-connected-state': 300 });
  for (let selector = 1; selector <= 15; selector++) assert.equal(routine.cases.filter(row => row.selector === selector && row.branch === 'all-sailing-angles').length, 181);
  for (const capture of [tables, trigCapture, forceCapture]) assert.equal(capture.provenance.sha256, fixtures.provenance.sha256);
  assert.equal(forceCapture.provenance.authoritative_engine, 'native-x87');
});

test('complete 0x428c60 matches all mapped image bytes, store ranges, RNG and ordered sounds in 4,098 native calls', () => {
  const memory = loadPE32(original);
  for (const [address, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine]]) values.forEach((value, index) => memory.writeI32(address + index * 4, value));
  const baseline = memory.bytes.slice();
  const block = fixtures.mutableBlock;
  const originals = Object.fromEntries(['writeI32', 'writeU32', 'writeF64', 'writeBytes'].map(method => [method, memory[method].bind(memory)]));
  let writes;
  for (const [method, originalMethod] of Object.entries(originals)) memory[method] = (address, value) => {
    if (writes) writes.push([address, method === 'writeF64' ? 8 : method === 'writeBytes' ? value.length : 4]);
    return originalMethod(address, value);
  };
  const failures = [];
  for (const [index, row] of fixtures.routines.updateBoatDynamics.cases.entries()) {
    memory.bytes.set(baseline);
    for (const input of row.imageInputs) memory.writeBytes(input.address, bytes(input.bits));
    const before = memory.readBytes(block.address, block.size);
    const expectedImage = memory.bytes.slice();
    for (const change of row.expected.imageChanges) {
      const offset = change.address - block.address;
      assert.equal(Buffer.from(before.slice(offset, offset + change.before.length / 2)).toString('hex'), change.before, `native boat case ${index}: recorded input`);
      expectedImage.set(bytes(change.after), change.address - memory.base);
    }
    assert.equal(hash(expectedImage.slice(block.address - memory.base, block.address - memory.base + block.size)), row.expected.mutableBlockHash, `native boat case ${index}: fixture hash`);
    const rng = new PoseyRng(row.seedAtCall);
    const sounds = [];
    writes = [];
    try { updateBoatDynamics(memory, row.arguments[0], rng, { trig, playSound: event => sounds.push(event) }); }
    catch (error) { failures.push({ index, branch: row.branch, selector: row.selector, error: error.message }); writes = undefined; continue; }
    const actualWrites = mergedRanges(writes);
    writes = undefined;
    if (!Buffer.from(memory.bytes).equals(Buffer.from(expectedImage))) {
      const mismatch = memory.bytes.findIndex((value, offset) => value !== expectedImage[offset]);
      failures.push({ index, branch: row.branch, selector: row.selector, address: `0x${(memory.base + mismatch).toString(16)}`,
        expected: Buffer.from(expectedImage.slice(mismatch, mismatch + 16)).toString('hex'),
        actual: Buffer.from(memory.bytes.slice(mismatch, mismatch + 16)).toString('hex') });
    }
    if (rng.state !== row.expected.rngState) failures.push({ index, rng: rng.state, expectedRng: row.expected.rngState });
    if (JSON.stringify(sounds) !== JSON.stringify(row.expected.sounds)) failures.push({ index, sounds, expectedSounds: row.expected.sounds });
    if (JSON.stringify(actualWrites) !== JSON.stringify(row.imageWrites)) failures.push({ index, stores: actualWrites, expectedStores: row.imageWrites });
  }
  assert.equal(failures.length, 0, `${failures.length} exact boat-dynamics mismatches; first: ${JSON.stringify(failures.slice(0, 16))}`);
});
