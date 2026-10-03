import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import {
  BOAT_OPTION_ADDRESSES as a, BOAT_SELECTORS, BOAT_TIME_FACTORS, initializeBoatOptions,
} from '../src/engine/boat-options.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-boat-options.json', import.meta.url), 'utf8'));
const calibration = JSON.parse(await readFile(new URL('../assets/data/boat-calibration.json', import.meta.url), 'utf8'));

function prepare(memory, fixture) {
  for (const [field, value] of Object.entries(fixture.inputs)) memory.writeI32(fixtures.inputs[field], value);
}

function output(memory, returnValue) {
  const actual = { returnValue };
  for (const [field, address] of Object.entries(fixtures.outputs)) actual[field] = memory.readI32(address);
  actual.timeFactor = memory.readF64(a.timeFactor);
  actual.timeFactorBits = Buffer.from(memory.readBytes(a.timeFactor, 8)).toString('hex');
  return actual;
}

test('boat fixture hashes, original addresses, and selector coverage are confirmed', () => {
  const hash = createHash('sha256').update(original).digest('hex');
  assert.equal(fixtures.provenance.sha256, hash);
  assert.equal(calibration.provenance.sha256, hash);
  assert.equal(fixtures.provenance.engine, 'Unicorn');
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.equal(calibration.routine, '0x417790');
  for (const [field, address] of Object.entries({ ...fixtures.inputs, ...fixtures.outputs })) {
    assert.equal(a[field], address, `original field ${field}`);
  }
  const selectors = new Set(fixtures.cases.map(fixture => fixture.inputs.selector));
  for (let selector = 1; selector <= 15; selector++) {
    assert.ok(selectors.has(selector), `selector ${selector}`);
    assert.ok(BOAT_SELECTORS[selector]);
  }
  for (const invalid of [-1, 0, 16]) assert.ok(selectors.has(invalid));
});

test('every boat option field, exact time-factor bits, and residual EAX match original instructions', () => {
  const memory = loadPE32(original);
  for (const [index, fixture] of fixtures.cases.entries()) {
    prepare(memory, fixture);
    const returnValue = initializeBoatOptions(memory);
    assert.deepEqual(output(memory, returnValue), fixture.expected,
      `native boat options case ${index}, selector ${fixture.inputs.selector}, prior class ${fixture.inputs.boatClass}`);
  }
});

test('all 38 captured length factors match native stored bits and actual initialization', () => {
  assert.equal(Object.keys(calibration.lengths).length, 38);
  assert.deepEqual(Object.keys(BOAT_TIME_FACTORS).sort(), Object.keys(calibration.lengths).sort());
  const memory = loadPE32(original);
  for (const [length, { value, bits }] of Object.entries(calibration.lengths)) {
    const stored = Buffer.alloc(8);
    stored.writeDoubleLE(BOAT_TIME_FACTORS[length]);
    assert.equal(stored.toString('hex'), bits, `captured factor length ${length}`);
    assert.equal(BOAT_TIME_FACTORS[length], value);
    // Invalid selector/class 0 preserve the supplied length; the original factor
    // formula is unchanged, allowing every calibrated length to be exercised.
    memory.writeI32(a.selector, 0);
    memory.writeI32(a.boatClass, 0);
    memory.writeI32(a.length, Number(length));
    initializeBoatOptions(memory);
    assert.equal(Buffer.from(memory.readBytes(a.timeFactor, 8)).toString('hex'), bits,
      `initialized factor length ${length}`);
  }
});

test('class 7 retains its rig and course state and option initialization has no other memory writes', () => {
  const cases = [
    fixtures.cases.find(fixture => fixture.inputs.selector === 14 && fixture.inputs.course === 8),
    fixtures.cases.find(fixture => fixture.inputs.selector === 3),
    fixtures.cases.find(fixture => fixture.inputs.selector === 0 && fixture.inputs.boatClass === 11),
  ];
  for (const fixture of cases) {
    assert.ok(fixture);
    const memory = loadPE32(original);
    prepare(memory, fixture);
    for (const flag of ['catamaranFlag', 'boardFlag', 'sportBoatFlag', 'skiffFlag', 'jy15Flag', 'optimistFlag']) {
      memory.writeI32(a[flag], -999);
    }
    const expectedBytes = memory.bytes.slice();
    const view = new DataView(expectedBytes.buffer);
    for (const [field, address] of Object.entries(fixtures.outputs)) {
      view.setInt32(address - memory.base, fixture.expected[field], true);
    }
    view.setFloat64(a.timeFactor - memory.base, fixture.expected.timeFactor, true);
    initializeBoatOptions(memory);
    assert.deepEqual(memory.bytes, expectedBytes, `writes for selector ${fixture.inputs.selector}`);
  }
});
