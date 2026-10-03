import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import {
  SAILING_HELPER_ADDRESSES as a, updateTack, spinnakerAnglePenalty,
  scheduleWindShift, setClosehauledHeading,
} from '../src/engine/helpers.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-sailing-helpers.json', import.meta.url), 'utf8'));

const routines = {
  updateTack: {
    prepare(memory, fixture) {
      memory.writeI32(a.heading + fixture.boat * 4, fixture.heading);
      memory.writeI32(a.trueWindDirection + fixture.boat * 4, fixture.windDirection);
    },
    run: (memory, fixture) => updateTack(memory, fixture.boat),
    fields: fixture => ({ tack: a.tack + fixture.boat * 4 }),
  },
  spinnakerAnglePenalty: {
    prepare(memory, fixture) {
      memory.writeI32(a.angleToTrueWind + fixture.boat * 4, fixture.angle);
      memory.writeI32(a.spinnakerThreshold, fixture.threshold);
    },
    run: (memory, fixture) => spinnakerAnglePenalty(memory, fixture.boat),
    fields: fixture => ({ penalty: a.spinnakerPenalty + fixture.boat * 4 }),
  },
  scheduleWindShift: {
    prepare(memory, fixture) {
      memory.writeI32(a.targetRandomIndex, fixture.targetIndex);
      memory.writeI32(a.timeRandomIndex, fixture.timeIndex);
      memory.writeI32(a.windRandomTable + fixture.targetIndex * 4, fixture.targetRandom);
      memory.writeI32(a.windRandomTable + fixture.timeIndex * 4, fixture.timeRandom);
      memory.writeI32(a.integerSeconds, fixture.time);
    },
    run: (memory, fixture) => scheduleWindShift(memory, fixture.center, fixture.range, fixture.period),
    fields: () => ({
      target: a.nextWindTarget, nextTime: a.nextWindTime,
      targetIndex: a.targetRandomIndex, timeIndex: a.timeRandomIndex,
    }),
  },
  setClosehauledHeading: {
    prepare(memory, fixture) {
      memory.writeI32(a.boatClass, fixture.boatClass);
      memory.writeI32(a.catamaranFlag, fixture.twinHullFlag);
      memory.writeI32(a.boardFlag, fixture.boardFlag);
      memory.writeI32(a.sportBoatFlag, fixture.planingFlag);
      memory.writeI32(a.player1ClosehauledAngle, fixture.previousAngle);
      memory.writeI32(a.trueWindKnots + fixture.boat * 4, fixture.wind);
      memory.writeI32(a.closehauledOffset + fixture.boat * 4, fixture.offset);
      memory.writeI32(a.trueWindDirection + fixture.boat * 4, fixture.windDirection);
      memory.writeI32(a.tack + fixture.boat * 4, fixture.tack);
    },
    run: (memory, fixture) => setClosehauledHeading(memory, fixture.boat),
    fields: fixture => ({ heading: a.heading + fixture.boat * 4, angle: a.player1ClosehauledAngle }),
  },
};

test('sailing helper fixtures identify the original binary and instruction emulator', () => {
  assert.equal(fixtures.provenance.sha256, createHash('sha256').update(original).digest('hex'));
  assert.equal(fixtures.provenance.engine, 'Unicorn');
  for (const name of Object.keys(routines)) assert.ok(fixtures[name].length > 0, name);
});

for (const [name, routine] of Object.entries(routines)) {
  test(`${name}: every output and residual EAX matches original x86 instructions`, () => {
    const memory = loadPE32(original);
    for (const [index, fixture] of fixtures[name].entries()) {
      routine.prepare(memory, fixture);
      const returnValue = routine.run(memory, fixture);
      const actual = { returnValue };
      for (const [field, address] of Object.entries(routine.fields(fixture))) actual[field] = memory.readI32(address);
      assert.deepEqual(actual, fixture.expected, `${name} native case ${index}`);
    }
  });

  test(`${name}: only documented original global fields change`, () => {
    const fixture = fixtures[name].find(value => value.boat === 1) ?? fixtures[name][0];
    const memory = loadPE32(original);
    routine.prepare(memory, fixture);
    const expectedBytes = memory.bytes.slice();
    const view = new DataView(expectedBytes.buffer);
    for (const [field, address] of Object.entries(routine.fields(fixture))) {
      view.setInt32(address - memory.base, fixture.expected[field], true);
    }
    routine.run(memory, fixture);
    assert.deepEqual(memory.bytes, expectedBytes);
  });
}
