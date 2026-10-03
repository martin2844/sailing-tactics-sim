import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import {
  ORIGINAL_ADDRESSES, wrapDegreesOnce, speedDivisor, updateSpeedDivisor,
  PoseyRng, scaledRandom,
} from '../src/engine/integer-core.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-core.json', import.meta.url), 'utf8'));

test('machine-code fixtures identify the exact original executable', () => {
  assert.equal(fixtures.provenance.sha256, createHash('sha256').update(original).digest('hex'));
  assert.equal(fixtures.provenance.engine, 'Unicorn');
  assert.ok(fixtures.wrapDegreesOnce.length > 0);
  assert.ok(fixtures.speedDivisor.length > 0);
  assert.ok(fixtures.rng.length > 0);
  assert.ok(fixtures.scaledRandom.length > 0);
});

test('all angle cases match execution of original x86 instructions', () => {
  for (const { input, expected } of fixtures.wrapDegreesOnce) {
    assert.equal(wrapDegreesOnce(input), expected, `angle input ${input}`);
  }
});

test('all speed-global outputs and return registers match original instructions', () => {
  const memory = loadPE32(original);
  for (const { level, previous, expected, return_value } of fixtures.speedDivisor) {
    assert.equal(speedDivisor(level, previous), expected, `speed value level ${level}, prior ${previous}`);
    memory.writeI32(ORIGINAL_ADDRESSES.speedLevel, level);
    memory.writeI32(ORIGINAL_ADDRESSES.speedDivisor, previous);
    assert.equal(updateSpeedDivisor(memory), return_value, `speed EAX level ${level}`);
    assert.equal(memory.readI32(ORIGINAL_ADDRESSES.speedDivisor), expected,
      `speed global level ${level}, prior ${previous}`);
    assert.equal(memory.readI32(ORIGINAL_ADDRESSES.speedLevel), level);
  }
});

test('every RNG output and intermediate seed match chained original executions', () => {
  for (const { seed, sequence } of fixtures.rng) {
    const rng = new PoseyRng(seed);
    assert.ok(sequence.length > 0);
    for (const [index, { output, state }] of sequence.entries()) {
      assert.equal(rng.rand(), output, `rand seed ${seed}, call ${index + 1}`);
      assert.equal(rng.state, state, `rand state seed ${seed}, call ${index + 1}`);
    }
    rng.srand(seed);
    assert.equal(rng.rand(), sequence[0].output, `srand restores seed ${seed}`);
  }
});

test('scaled random outputs and resulting seeds match original instructions', () => {
  for (const { seed, range, expected, state } of fixtures.scaledRandom) {
    const rng = new PoseyRng(seed);
    assert.equal(scaledRandom(range, rng), expected, `scaled random seed ${seed}, range ${range}`);
    assert.equal(rng.state, state, `scaled random state seed ${seed}, range ${range}`);
  }
});

test('single-step angle adjustment preserves out-of-range behavior', () => {
  assert.equal(wrapDegreesOnce(360), 0);
  assert.equal(wrapDegreesOnce(-1), 359);
  assert.equal(wrapDegreesOnce(720), 360);
  assert.equal(wrapDegreesOnce(-721), -361);
  assert.equal(wrapDegreesOnce(0xffffffff), 359);
});

test('speed update writes the original global and retains it for invalid levels', async () => {
  const bytes = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
  const memory = loadPE32(bytes);
  memory.writeI32(ORIGINAL_ADDRESSES.speedLevel, 7);
  updateSpeedDivisor(memory);
  assert.equal(memory.readI32(ORIGINAL_ADDRESSES.speedDivisor), 256);
  memory.writeI32(ORIGINAL_ADDRESSES.speedLevel, -1);
  updateSpeedDivisor(memory);
  assert.equal(memory.readI32(ORIGINAL_ADDRESSES.speedDivisor), 256);
  assert.equal(speedDivisor(16, -19), -19);
});

test('each RNG instance retains an independent original thread seed', () => {
  const first = new PoseyRng();
  const second = new PoseyRng();
  first.rand();
  assert.equal(second.state, 1);
  first.srand(0xffffffffn);
  assert.equal(first.state, 0xffffffff);
  assert.equal(second.state, 1);
});

test('scaled random consumes one seed step including clamped and negative inputs', () => {
  const referenceRng = new PoseyRng(19);
  referenceRng.rand();
  for (const range of [-2147483648, -100, -2, -1, 0, 1, 2, 100, 32001]) {
    const rng = new PoseyRng(19);
    scaledRandom(range, rng);
    assert.equal(rng.state, referenceRng.state);
  }
});
