import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance, createNativeHarness } from './native-state.js';
import * as geometry from '../src/engine/ai-geometry.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';

const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const source = await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe', import.meta.url));
const trig = createCapturedTrig(await json('../assets/data/x87-trig.json'));
for (const [name, address] of Object.entries(geometry.AI_GEOMETRY_ROUTINES)) {
  const fixture = await json(`fixtures/original-${name}.json`);
  test(`${name}: preserved English routine, packed ABI and startup precision authority`, () => {
    assertNativeProvenance(source, fixture);
    assert.equal(fixture.routine.address, address);
    assert.ok(fixture.cases.length > 100);
  });
  test(`${name}: exact whole mutable state, extended returns, integer registers and RNG`, () => {
    const harness = createNativeHarness(source, fixture);
    for (const [index, row] of fixture.cases.entries()) harness.check(row, index, (memory, rng, args) => {
      const result = name === 'signedDegrees' ? geometry[name](...args) : geometry[name](memory, ...args, { trig, rng });
      if (fixture.routine.returnType === 'I64') {
        assert.equal(typeof result, 'bigint');
        assert.equal(Number(BigInt.asUintN(32, result)), row.expected.eax, `case${index}: native EAX`);
        assert.equal(Number(BigInt.asUintN(32, result >> 32n)), row.expected.edx, `case${index}: native EDX`);
      }
      return result;
    });
  });
}
