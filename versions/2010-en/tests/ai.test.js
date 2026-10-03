import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { assertNativeProvenance, createNativeHarness } from './native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import * as ai from '../src/engine/ai.js';

const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const source = await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe', import.meta.url));
const trig = createCapturedTrig(await json('../assets/data/x87-trig.json'));
const randomRoutines = new Set(['updateBoatWindAndAI', 'chooseDownwindHeading', 'scoreDownwindTurn', 'updateUpwindTactics']);
const translation = await json('../analysis/ai-translation-sources.json');
test('complete static AI is generated from the exact corrected English C bodies', async () => {
  assert.equal(translation.sourceSha256, sha(source));
  assert.equal(translation.routines.length, 10);
  for (const routine of translation.routines) {
    const bytes = await readFile(new URL(`../${routine.source}`, import.meta.url));
    assert.equal(sha(bytes), routine.sha256, `original source ${routine.address.toString(16)}`);
    const dependencies = [...new Set([...bytes.toString('utf8').matchAll(/\bFUN_([0-9a-f]{8})\s*\(/g)]
      .map(match => Number.parseInt(match[1], 16)).filter(address => address !== routine.address))].sort((a, b) => a - b);
    assert.deepEqual(routine.dependencies, dependencies, `original calls ${routine.address.toString(16)}`);
  }
});
for (const [name, address] of Object.entries(ai.AI_ROUTINES)) {
  const fixture = await json(`fixtures/original-${name}.json`);
  test(`${name}: unchanged original instructions, explicit initialized inputs and startup precision`, () => {
    assertNativeProvenance(source, fixture);
    assert.equal(fixture.routine.address, address);
    assert.equal(fixture.inputEvidence.nativeInitializedFixture, 'tests/fixtures/original-initializeRace.json');
    assert.equal(fixture.inputEvidence.nativeAdvancedGeometryFixture, 'tests/fixtures/original-advanced-terrain.json');
    assert.match(fixture.inputEvidence.sha256, /^[0-9a-f]{64}$/);
    assert.ok(fixture.cases.length >= 190);
  });
  test(`${name}: whole mutable bytes, actual return, retained RNG and ordered original sounds`, () => {
    const harness = createNativeHarness(source, fixture);
    for (const [index, row] of fixture.cases.entries()) {
      const sounds = [];
      harness.check(row, index, (memory, rng, args) => {
        const options = { trig, rng, playSound: event => { sounds.push(event); return 1; } };
        return randomRoutines.has(name) ? ai[name](memory, ...args, rng, options) : ai[name](memory, ...args, options);
      });
      assert.deepEqual(sounds, row.expected.sounds, `case${index}: ordered PlaySoundA arguments`);
    }
  });
}
