import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { initializeWindRandomTable } from '../src/engine/wind-initialization.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixture = JSON.parse(await readFile(new URL('./fixtures/original-startup-random.json', import.meta.url), 'utf8'));
const hash = value => createHash('sha256').update(value).digest('hex');

test('startup random table follows all 68 original sequences and modifies only its 301 integers', () => {
  assert.equal(fixture.provenance.sha256, hash(original));
  assert.equal(fixture.provenance.routine, '0042e080');
  assert.equal(fixture.cases.length, 68);
  let observedOver99 = false;
  for (const row of fixture.cases) {
    const memory = loadPE32(original), rng = new PoseyRng(row.seed);
    const result = initializeWindRandomTable(memory, rng);
    const table = Array.from({ length: 301 }, (_, index) => memory.readI32(0x4a9450 + index * 4));
    assert.deepEqual(table, row.expected.table, `seed ${row.seed}`);
    assert.equal(rng.state, row.expected.rngState);
    assert.equal(result, row.expected.residualEAX);
    assert.equal(hash(memory.readBytes(0x400000, 0x111000)), row.expected.imageHash);
    observedOver99 ||= table.some(value => value > 99);
  }
  assert.ok(observedOver99, 'Original scaledRandom(100) can return 100..102; no clamp');
});
