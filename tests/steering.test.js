import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import {
  STEERING_ADDRESSES as a, updatePlayer1Rudder, updatePlayer1Steering, updatePlayer2Steering,
} from '../src/engine/steering.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-steering.json', import.meta.url), 'utf8'));
const routines = { updatePlayer1Rudder, updatePlayer1Steering, updatePlayer2Steering };

function prepare(memory, fixture) {
  for (const [field, value] of Object.entries(fixture.inputs ?? {})) memory.writeI32(fixtures.inputs[field], value);
  for (const [field, value] of Object.entries(fixture.doubleInputs ?? {})) memory.writeF64(fixtures.doubleInputs[field], value);
}

function output(memory, returnValue, sounds) {
  const actual = {};
  for (const [field, address] of Object.entries(fixtures.outputs)) actual[field] = memory.readI32(address);
  actual.smoothHeading = memory.readF64(a.smoothHeading);
  actual.smoothHeadingBits = Buffer.from(memory.readBytes(a.smoothHeading, 8)).toString('hex');
  actual.returnValue = returnValue;
  actual.sounds = sounds;
  return actual;
}

function invoke(memory, run) {
  const sounds = [];
  const returnValue = run(memory, { playSound: request => sounds.push(request) });
  return output(memory, returnValue, sounds);
}

test('steering provenance identifies original routines and the observational sound stub', () => {
  assert.equal(fixtures.provenance.sha256, createHash('sha256').update(original).digest('hex'));
  assert.equal(fixtures.provenance.engine, 'Unicorn');
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.equal(parseInt(fixtures.provenance.sound_import_stub, 16), a.playSoundImport);
  assert.equal(fixtures.provenance.sound_return, 1);
  assert.match(fixtures.provenance.note, /PlaySoundA stub records ordered arguments/);
  for (const [field, address] of Object.entries({ ...fixtures.inputs, ...fixtures.doubleInputs, ...fixtures.outputs })) {
    assert.equal(a[field], address, `original steering field ${field}`);
  }
  assert.equal(Object.keys(fixtures.outputs).length, 19);
  assert.equal(Object.values(fixtures.routines).reduce((count, routine) => count + routine.cases.length, 0), 5346);
  assert.equal(fixtures.chains.reduce((count, chain) => count + chain.steps.length, 0), 144);
  for (const [name, fixture] of Object.entries(fixtures.routines)) assert.equal(a[name], fixture.address);
});

for (const [name, run] of Object.entries(routines)) {
  test(`${name}: 1782 complete original states, exact heading bits, EAX, and ordered sounds match`, () => {
    const memory = loadPE32(original);
    for (const [index, fixture] of fixtures.routines[name].cases.entries()) {
      prepare(memory, fixture);
      assert.deepEqual(invoke(memory, run), fixture.expected,
        `native steering ${name} case ${index}: turn ${fixture.inputs.turnMode1}/${fixture.inputs.turnMode2}, sailing ${fixture.inputs.sailingMode1}/${fixture.inputs.sailingMode2}`);
    }
  });
}

test('all 144 chained controls preserve exact native heading and control state', () => {
  for (const chain of fixtures.chains) {
    const memory = loadPE32(original);
    prepare(memory, chain);
    for (const [index, step] of chain.steps.entries()) {
      prepare(memory, step);
      assert.deepEqual(invoke(memory, routines[chain.routine]), step.expected,
        `native steering ${chain.routine} chained step ${index}`);
    }
  }
});

test('every sound request matches the exact Windows resource, module, and flag arguments', () => {
  let count = 0;
  for (const [name, routine] of Object.entries(fixtures.routines)) {
    for (const fixture of routine.cases.filter(row => row.expected.sounds.length > 0)) {
      const memory = loadPE32(original);
      prepare(memory, fixture);
      const actual = invoke(memory, routines[name]);
      assert.deepEqual(actual.sounds, fixture.expected.sounds);
      for (const sound of actual.sounds) {
        assert.equal(sound.resourceId, 134);
        assert.equal(sound.moduleHandle, fixture.inputs.moduleHandle >>> 0);
        assert.equal(sound.flags, 0x40005);
        count++;
      }
    }
  }
  assert.ok(count > 0);
});

test('steering writes only its original mutable globals and binary64 heading', () => {
  for (const [name, routine] of Object.entries(fixtures.routines)) {
    const selected = [routine.cases[0], routine.cases.find(row => row.expected.sounds.length > 0),
      routine.cases.find(row => row.inputs.sailingMode1 === 2 && row.inputs.angle1 > 90),
      routine.cases.find(row => row.inputs.sailingMode2 === 3 && row.inputs.angle2 < 90)];
    for (const fixture of selected) {
      assert.ok(fixture);
      const memory = loadPE32(original);
      prepare(memory, fixture);
      const expectedBytes = memory.bytes.slice();
      const view = new DataView(expectedBytes.buffer);
      for (const [field, address] of Object.entries(fixtures.outputs)) view.setInt32(address - memory.base, fixture.expected[field], true);
      view.setFloat64(a.smoothHeading - memory.base, fixture.expected.smoothHeading, true);
      invoke(memory, routines[name]);
      assert.deepEqual(memory.bytes, expectedBytes, `original writes for steering ${name}`);
    }
  }
});
