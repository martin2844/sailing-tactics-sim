import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance, createNativeHarness } from './native-state.js';
import { updateWaveMotion } from '../src/engine/wave-motion.js';

const source = await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe', import.meta.url));
const fixture = JSON.parse(await readFile(new URL('fixtures/original-updateWaveMotion.json', import.meta.url), 'utf8'));
test('wave motion executes the entire unchanged original no-argument body at startup precision', () => {
  assertNativeProvenance(source, fixture);
  assert.equal(fixture.routine.address, 0x4432b0);
  assert.deepEqual(fixture.routine.argumentTypes, []);
  assert.equal(fixture.cases.length, 2610);
  assert.ok(fixture.cases.some(row => row.inputs?.counter === -2147483648));
  assert.ok(fixture.cases.some(row => row.inputs?.counter === 2147483647));
  assert.equal(fixture.cases.filter(row => row.continue).length, 80);
});
test('wave motion matches every native byte, retained RNG, raw F64 spill and ordered sound request', () => {
  const harness = createNativeHarness(source, fixture);
  for (const [index, row] of fixture.cases.entries()) {
    const sounds = [];
    harness.check(row, index, memory => updateWaveMotion(memory, { playSound: event => { sounds.push(event); return 1; } }));
    assert.deepEqual(sounds, row.expected.sounds, `case${index}: original ordered sound requests`);
  }
});
