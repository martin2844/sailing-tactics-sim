import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance, createNativeHarness } from './native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { updateBoatWindAndAI } from '../src/engine/ai.js';

const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const source = await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe', import.meta.url));
const fixture = await json('fixtures/original-board-turn.json');
const trig = createCapturedTrig(await json('../assets/data/x87-trig.json'));

test('board turn matrix covers original speed stride and the exact completion gates', () => {
  assertNativeProvenance(source, fixture);
  assert.equal(fixture.routine.address, 0x434f70);
  assert.equal(fixture.cases.length, 384);
  assert.deepEqual([...new Set(fixture.cases.map(row => row.branchInputs.boat))], [1, 2, 3, 12]);
  for (const field of ['boardFlag', 'speed', 'turnMode', 'elapsed']) {
    assert.deepEqual([...new Set(fixture.cases.map(row => row.branchInputs[field]))],
      { boardFlag: [0, 1], speed: [9, 10], turnMode: [-1, 0, 1], elapsed: [0, 1, 2, 3, 4, 5, 6, 10] }[field]);
  }
  assert.equal(fixture.inputEvidence.originalInstruction.bytes, '8b04b580b34f00');
});

test('complete board AI matches every native mutable byte, retained RNG and ordered sound', () => {
  const harness = createNativeHarness(source, fixture);
  for (const [index, row] of fixture.cases.entries()) {
    const sounds = [];
    try {
      harness.check(row, index, (memory, rng, args) => updateBoatWindAndAI(memory, ...args, rng,
        { trig, rng, playSound: event => { sounds.push(event); return 1; } }));
      assert.deepEqual(sounds, row.expected.sounds, `case${index}: ordered original sounds`);
      const { boat, boardFlag, speed, turnMode, elapsed, humans } = row.branchInputs;
      if (turnMode !== 0 && boat > humans && elapsed > 5) {
        assert.equal(row.expected.integers[`speed${boat}`], speed, 'speed input survives the non-resampling phase');
        assert.equal(row.expected.integers[`turnMode${boat}`], 0, 'original turn completes');
        let expectedHeading = row.expected.integers[`windDirection${boat}`]
          + turnMode * (row.expected.integers.closehauledAngle + (boardFlag === 1 && speed < 10 ? 5 : 0));
        if (expectedHeading >= 360) expectedHeading -= 360;
        if (expectedHeading < 0) expectedHeading += 360;
        assert.equal(row.expected.integers[`heading${boat}`], expectedHeading, 'original completed-turn heading');
      }
    } catch (error) { error.message = `${row.label}: ${error.message}`; throw error; }
  }
});
