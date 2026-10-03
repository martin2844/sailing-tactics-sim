import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { GdiTrace } from '../src/render/gdi.js';
import * as basics from '../src/render/tutorial-basics.js';
import { readRoutineFixture } from './read-routine-fixture.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixture = await readRoutineFixture(new URL('./fixtures/original-tutorials.json', import.meta.url), Object.keys(basics.TUTORIAL_BASIC_ROUTINES));
const tables = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json', import.meta.url), 'utf8'));
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
const bytes = bits => Uint8Array.from(Buffer.from(bits, 'hex'));

test('tutorial1–8 identify original unchanged routines and complete state evidence', () => {
  assert.equal(fixture.provenance.sha256, hash(original));
  assert.equal(fixture.provenance.x87_control_word, '0x037f');
  for (const [name, address] of Object.entries(basics.TUTORIAL_BASIC_ROUTINES)) {
    assert.equal(fixture.routines[name].address, address);
    assert.equal(fixture.routines[name].cases.length, 128);
  }
});

for (const name of Object.keys(basics.TUTORIAL_BASIC_ROUTINES)) test(`${name}: exact original text, colors, coordinates and complete image (${fixture.routines[name].cases.length} calls)`, () => {
  const memory = loadPE32(original);
  for (const [address, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine]]) values.forEach((value, index) => memory.writeI32(address + index * 4, value));
  const baseline = memory.bytes.slice(), { address, size } = fixture.mutableBlock;
  for (const [index, row] of fixture.routines[name].cases.entries()) {
    memory.bytes.set(baseline);
    for (const patch of row.imageInputs) memory.writeBytes(patch.address, bytes(patch.bits));
    const before = memory.readBytes(address, size), expected = memory.bytes.slice();
    for (const change of row.expected.imageChanges) {
      assert.equal(Buffer.from(before.slice(change.address - address, change.address - address + change.before.length / 2)).toString('hex'), change.before);
      expected.set(bytes(change.after), change.address - memory.base);
    }
    assert.equal(hash(expected.slice(address - memory.base, address - memory.base + size)), row.expected.mutableBlockHash);
    const dc = new GdiTrace();
    basics[name](memory, dc);
    assert.deepEqual(dc.events, row.expected.drawingCommands, `${name} case${index}: ordered text/color requests`);
    assert.deepEqual(memory.bytes, expected, `${name} case${index}: every mapped original image byte`);
    assert.deepEqual(row.expected.sounds, []);
    assert.equal(row.expected.rngState, row.seedAtCall);
    assert.deepEqual(row.imageWrites, []);
  }
});
