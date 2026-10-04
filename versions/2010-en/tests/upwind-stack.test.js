import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { assertNativeProvenance, createNativeHarness } from './native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { updateUpwindTactics } from '../src/engine/ai.js';
import { createLocalFrame, framePointer, readLocal } from '../src/render/typed-c.js';

const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const source = await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe', import.meta.url));
const fixture = await json('fixtures/original-upwind-stack.json');
const translation = await json('../analysis/ai-translation-sources.json');
const trig = createCapturedTrig(await json('../assets/data/x87-trig.json'));

test('the elided dead stack read is pinned to unchanged original instructions and its precise guard', () => {
  assertNativeProvenance(source, fixture);
  const original = loadPE32(source);
  const [correction] = translation.semanticCorrections;
  assert.equal(translation.semanticCorrections.length, 1);
  assert.equal(correction.address, 0x437e60);
  assert.equal(correction.original, '(0 < local_1c) && (iVar4 == 2)');
  assert.equal(correction.translated, '(iVar4 == 2) && (0 < local_1c)');
  for (const field of ['originalLoad', 'originalFleetGuard']) {
    const { address, bytes } = correction[field];
    assert.equal(Buffer.from(original.readBytes(address, bytes.length / 2)).toString('hex'), bytes);
  }
  assert.equal(fixture.cases.length, 279);
  assert.deepEqual([...new Set(fixture.cases.map(row => row.branchInputs.fleet))], [2, 3, 5, 10, 15, 20, 25, 30]);
  assert.deepEqual([...new Set(fixture.cases.map(row => row.branchInputs.aiLevel))], [1, 10]);
  assert.deepEqual([...new Set(fixture.cases.map(row => row.branchInputs.distance))], [100, 101, 500]);
  // The generic byte-frame contract remains strict: no fabricated zero cells.
  assert.throws(() => readLocal(framePointer(createLocalFrame(292), 264), 4, 'int'),
    /Original C reads an undefined retained local byte/);
});

test('engaged upwind tactics preserve every native mutable byte, RNG and sound across all fleet sizes', () => {
  const harness = createNativeHarness(source, fixture);
  const twoBoatOutputs = new Set();
  for (const [index, row] of fixture.cases.entries()) {
    const sounds = [];
    try {
      harness.check(row, index, (memory, rng, args) => updateUpwindTactics(memory, ...args, rng,
        { trig, playSound: event => { sounds.push(event); return 1; } }));
      assert.deepEqual(sounds, row.expected.sounds, `case${index}: ordered original sounds`);
      if (row.branchInputs.fleet === 2 && row.branchInputs.distance > 100) {
        twoBoatOutputs.add(row.expected.integers.specialTacticalFlag);
      }
      if (row.branchInputs.fleet > 2 && row.branchInputs.distance > 100) {
        assert.equal(row.expected.integers.specialTacticalFlag, 0, 'fleet guard makes the retained stack value irrelevant');
      }
    } catch (error) { error.message = `${row.label}: ${error.message}`; throw error; }
  }
  assert.deepEqual([...twoBoatOutputs].sort(), [0, 1], 'initialized two-boat local still controls both native outcomes');
});
