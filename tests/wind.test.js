import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { WIND_ADDRESSES as a, WIND_SINE_BITS, updateGlobalWind } from '../src/engine/wind.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-global-wind.json', import.meta.url), 'utf8'));
const trig = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json', import.meta.url), 'utf8'));
const extendedTrig = JSON.parse(await readFile(new URL('../assets/data/x87-trig.json', import.meta.url), 'utf8'));

function originalMemory() {
  const memory = loadPE32(original);
  for (const [table, values] of Object.entries({ sine: trig.sine, cosine: trig.cosine, randomTable: fixtures.randomTable })) {
    for (const [index, value] of values.entries()) memory.writeI32(a[table] + index * 4, value);
  }
  return memory;
}

function prepare(memory, fixture) {
  for (const [field, value] of Object.entries(fixture.inputs ?? {})) memory.writeI32(fixtures.inputs[field], value);
  for (const [field, value] of Object.entries(fixture.doubleInputs ?? {})) memory.writeF64(fixtures.doubleInputs[field], value);
}

function output(memory, rng, returnValue) {
  const actual = {};
  for (const [field, address] of Object.entries(fixtures.outputs)) actual[field] = memory.readI32(address);
  actual.smoothDirection = memory.readF64(a.smoothDirection);
  actual.smoothDirectionBits = Buffer.from(memory.readBytes(a.smoothDirection, 8)).toString('hex');
  actual.rngState = rng.state;
  actual.returnValue = returnValue;
  return actual;
}

test('global wind provenance and every original state address are confirmed', () => {
  const hash = createHash('sha256').update(original).digest('hex');
  for (const capture of [fixtures, trig, extendedTrig]) assert.equal(capture.provenance.sha256, hash);
  assert.equal(fixtures.provenance.engine, 'Unicorn');
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.equal(a.routine, 0x0041b5d0);
  for (const [field, address] of Object.entries({ ...fixtures.inputs, ...fixtures.doubleInputs, ...fixtures.outputs })) {
    assert.equal(a[field], address, `original field ${field}`);
  }
  assert.equal(a.randomTable, fixtures.randomTableAddress);
  assert.equal(fixtures.randomTable.length, 302);
  assert.equal(Object.keys(fixtures.outputs).length, 14);
  assert.equal(fixtures.cases.length, 824);
  assert.equal(fixtures.chains.reduce((count, chain) => count + chain.steps.length, 0), 128);
});

test('every supported wind sine matches native extended bits and the original input constant', () => {
  assert.equal(extendedTrig.provenance.engine, 'Unicorn');
  assert.equal(extendedTrig.provenance.x87_control_word, '0x037f');
  assert.equal(extendedTrig.provenance.authoritative_engine, 'native-x87');
  assert.equal(extendedTrig.provenance.native_verification.control_word, '0x037f');
  assert.equal(extendedTrig.degreeFactorAddress, 0x00484d40);
  const memory = loadPE32(original);
  assert.equal(Buffer.from(memory.readBytes(extendedTrig.degreeFactorAddress, 8)).toString('hex'),
    extendedTrig.degreeFactorBits);
  assert.match(extendedTrig.inputOrdering, /FILD.*FMUL.*FSIN/);
  assert.equal(Object.keys(WIND_SINE_BITS).length, 97);
  for (let angle = -720; angle <= 720; angle += 15) {
    assert.equal(WIND_SINE_BITS[angle], extendedTrig.angles[angle].sineBits, `FSIN angle ${angle}`);
  }
});

test('all 824 full wind states match native fields, binary64 bits, RNG, and residual EAX', () => {
  const memory = originalMemory();
  const rng = new PoseyRng();
  for (const [index, fixture] of fixtures.cases.entries()) {
    prepare(memory, fixture);
    rng.state = fixture.seed;
    const returnValue = updateGlobalWind(memory, rng);
    assert.deepEqual(output(memory, rng, returnValue), fixture.expected,
      `native wind case ${index}: mode ${fixture.inputs.mode}, hour ${fixture.inputs.hour}, time ${fixture.inputs.time}`);
  }
});

test('128 chained wind updates retain exact smoothing, scheduling, and random state', () => {
  for (const [chainIndex, chain] of fixtures.chains.entries()) {
    const memory = originalMemory();
    const rng = new PoseyRng(chain.seed);
    prepare(memory, chain);
    for (const [stepIndex, step] of chain.steps.entries()) {
      prepare(memory, step);
      const returnValue = updateGlobalWind(memory, rng);
      assert.deepEqual(output(memory, rng, returnValue), step.expected,
        `native wind chain ${chainIndex}, step ${stepIndex}`);
    }
  }
});

test('wind truncates the unrounded extended value after storing binary64 with FST', () => {
  const fixture = fixtures.cases[311];
  assert.equal(fixture.inputs.target, 0);
  assert.equal(fixture.doubleInputs.smoothDirection, 1);
  assert.equal(fixture.doubleInputs.dt, 1e-15);
  const memory = originalMemory();
  const rng = new PoseyRng(fixture.seed);
  prepare(memory, fixture);
  updateGlobalWind(memory, rng);
  assert.equal(memory.readF64(a.smoothDirection), 1);
  assert.equal(memory.readI32(a.direction), 0);
  assert.equal(Buffer.from(memory.readBytes(a.smoothDirection, 8)).toString('hex'), fixture.expected.smoothDirectionBits);
});

test('wind writes only its original output globals in reset, smoothing, scheduling, and inactive modes', () => {
  const selected = [
    fixtures.cases.find(fixture => fixture.inputs.mode === 0 && fixture.inputs.time < fixture.inputs.resetTime + 10),
    fixtures.cases.find(fixture => fixture.inputs.mode === 1 && fixture.inputs.time < 10),
    fixtures.cases.find(fixture => fixture.inputs.mode === 0 && fixture.inputs.nextTime < fixture.inputs.time),
    fixtures.cases.find(fixture => fixture.inputs.mode === 1 && fixture.inputs.nextTime < fixture.inputs.time),
    fixtures.cases.find(fixture => fixture.inputs.mode === 0 && fixture.inputs.nextTime === fixture.inputs.time),
    fixtures.cases.find(fixture => fixture.inputs.mode !== 0 && fixture.inputs.mode !== 1),
  ];
  for (const fixture of selected) {
    assert.ok(fixture);
    const memory = originalMemory();
    const rng = new PoseyRng(fixture.seed);
    prepare(memory, fixture);
    const expectedBytes = memory.bytes.slice();
    const view = new DataView(expectedBytes.buffer);
    for (const [field, address] of Object.entries(fixtures.outputs)) {
      view.setInt32(address - memory.base, fixture.expected[field], true);
    }
    view.setFloat64(a.smoothDirection - memory.base, fixture.expected.smoothDirection, true);
    updateGlobalWind(memory, rng);
    assert.deepEqual(memory.bytes, expectedBytes, `writes for mode ${fixture.inputs.mode}, time ${fixture.inputs.time}`);
  }
});

test('wind rejects uncaptured thermal or tide sine angles before mutating state', () => {
  for (const changes of [{ hour: 57 }, { hour: 12, tidePhaseHour: -13 }]) {
    const fixture = fixtures.cases[0];
    const memory = originalMemory();
    const rng = new PoseyRng(fixture.seed);
    prepare(memory, fixture);
    prepare(memory, { inputs: changes });
    const before = memory.bytes.slice();
    assert.throws(() => updateGlobalWind(memory, rng), /FSIN angle.*outside the captured -720\.\.720 domain/);
    assert.deepEqual(memory.bytes, before);
    assert.equal(rng.state, fixture.seed);
  }
});
