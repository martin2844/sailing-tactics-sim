import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import {
  CURRENT_ADDRESSES as a, CURRENT_SINE_BITS, sampleCurrent, sampleShorelineMetric,
  sampleSpatialMetric, sampleBoundaryMetric, updateShoreDirections, sampleUpstreamDistance,
} from '../src/engine/current.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-current.json', import.meta.url), 'utf8'));
const trig = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json', import.meta.url), 'utf8'));
const extendedTrig = JSON.parse(await readFile(new URL('../assets/data/x87-trig.json', import.meta.url), 'utf8'));
const geometryFields = { shorelineX: 'shorelineX', shorelineY: 'shorelineY', radialBoundary: 'boundaryRadius' };
const helpers = {
  shorelineMetric: { field: 'sampleShorelineMetric', run: sampleShorelineMetric, floating: true },
  ellipticalMetric: { field: 'sampleSpatialMetric', run: sampleSpatialMetric, floating: true },
  radialMetric: { field: 'sampleBoundaryMetric', run: sampleBoundaryMetric, floating: true },
  shoreDirections: { field: 'updateShoreDirections', run: updateShoreDirections },
  attenuationDistance: { field: 'sampleUpstreamDistance', run: sampleUpstreamDistance },
};
const doubleBits = value => { const bytes = Buffer.alloc(8); bytes.writeDoubleLE(value); return bytes.toString('hex'); };

function originalMemory() {
  const memory = loadPE32(original);
  for (const table of ['sine', 'cosine']) {
    for (const [index, value] of trig[table].entries()) memory.writeI32(a[table] + index * 4, value);
  }
  for (const [field, { address, values }] of Object.entries(fixtures.geometry)) {
    const floating = field === 'radialBoundary';
    for (const [index, value] of values.entries()) {
      if (floating) memory.writeF64(address + index * 8, value);
      else memory.writeI32(address + index * 4, value);
    }
  }
  return memory;
}

function prepare(memory, fixture) {
  for (const [field, value] of Object.entries(fixture.inputs)) memory.writeI32(fixtures.inputs[field], value);
  for (const [field, value] of Object.entries(fixture.doubleInputs)) memory.writeF64(fixtures.doubleInputs[field], value);
  memory.writeF64(a.cachedMetric + fixture.boat * 8, fixture.cachedMetric);
  memory.writeI32(a.currentStrength + fixture.boat * 4, fixture.currentStrength);
  memory.writeI32(a.previousStrength + fixture.boat * 4, fixture.previousStrength);
}

function state(memory, boat) {
  const actual = {};
  for (const [field, address] of Object.entries(fixtures.outputs)) actual[field] = memory.readI32(address);
  actual.currentStrength = memory.readI32(a.currentStrength + boat * 4);
  actual.previousStrength = memory.readI32(a.previousStrength + boat * 4);
  actual.cachedMetric = memory.readF64(a.cachedMetric + boat * 8);
  actual.cachedMetricBits = Buffer.from(memory.readBytes(a.cachedMetric + boat * 8, 8)).toString('hex');
  return actual;
}

function invoke(helper, memory, fixture) {
  return helper === helpers.attenuationDistance
    ? helper.run(memory, fixture.selector, fixture.x, fixture.y)
    : helper.run(memory, fixture.x, fixture.y, fixture.boat);
}

test('current fixtures identify original instructions, every address, and synthetic geometry', () => {
  const hash = createHash('sha256').update(original).digest('hex');
  for (const capture of [fixtures, trig, extendedTrig]) assert.equal(capture.provenance.sha256, hash);
  assert.equal(fixtures.provenance.engine, 'Unicorn');
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.match(fixtures.provenance.note, /synthetic/);
  assert.equal(a.sampleCurrent, 0x00421560);
  for (const [field, address] of Object.entries({ ...fixtures.inputs, ...fixtures.doubleInputs, ...fixtures.outputs, ...fixtures.indexed })) {
    assert.equal(a[field], address, `original field ${field}`);
  }
  for (const [field, record] of Object.entries(fixtures.geometry)) assert.equal(a[geometryFields[field]], record.address);
  for (const [name, helper] of Object.entries(helpers)) assert.equal(a[helper.field], fixtures.helpers[name].address);
  assert.equal(fixtures.cases.length, 2510);
  assert.equal(Object.values(fixtures.helpers).reduce((count, helper) => count + helper.cases.length, 0), 1280);
  for (let weather = -1; weather <= 7; weather++) assert.ok(fixtures.cases.some(fixture => fixture.inputs.weather === weather));
});

test('all 73 supported current phase sines match authoritative hardware m80 captures', () => {
  assert.equal(extendedTrig.provenance.authoritative_engine, 'native-x87');
  assert.equal(extendedTrig.provenance.native_verification.control_word, '0x037f');
  assert.equal(Object.keys(CURRENT_SINE_BITS).length, 73);
  for (let angle = -1080; angle <= 1080; angle += 30) {
    assert.equal(CURRENT_SINE_BITS[angle], extendedTrig.angles[angle].sineBits, `native FSIN angle ${angle}`);
  }
});

test('2510 complete current samplings match all native state fields, cache bits, and EAX', () => {
  const memory = originalMemory();
  for (const [index, fixture] of fixtures.cases.entries()) {
    prepare(memory, fixture);
    const returnValue = sampleCurrent(memory, fixture.x, fixture.y, fixture.boat);
    assert.deepEqual({ ...state(memory, fixture.boat), returnValue }, fixture.expected,
      `native current case ${index}: weather ${fixture.inputs.weather}, x ${fixture.x}, y ${fixture.y}, boat ${fixture.boat}`);
  }
});

for (const [name, helper] of Object.entries(helpers)) {
  test(`${name}: all 256 native helper states and exact returns match`, () => {
    const memory = originalMemory();
    for (const [index, fixture] of fixtures.helpers[name].cases.entries()) {
      prepare(memory, fixture);
      const result = invoke(helper, memory, fixture);
      const actual = state(memory, fixture.boat);
      if (helper.floating) {
        actual.returnValue = result.toNumber();
        actual.returnBits = doubleBits(result.toNumber());
        actual.returnExtendedBits = Buffer.from(result.toBytes()).toString('hex');
      } else {
        actual.returnValue = result;
      }
      assert.deepEqual(actual, fixture.expected,
        `native ${name} case ${index}: x ${fixture.x}, y ${fixture.y}, boat ${fixture.boat}`);
    }
  });
}

test('current and helper calls only write their original globals and indexed boat fields', () => {
  const calls = [];
  for (const weather of [-1, 0, 1, 2, 3, 4, 5, 6, 7]) {
    calls.push({ fixture: fixtures.cases.find(row => row.inputs.weather === weather && row.boat === 1), run: sampleCurrent });
  }
  for (const [name, helper] of Object.entries(helpers)) {
    calls.push({ fixture: fixtures.helpers[name].cases.find(row => row.boat > 0), helper });
  }
  for (const { fixture, run, helper } of calls) {
    assert.ok(fixture);
    const memory = originalMemory();
    prepare(memory, fixture);
    const expectedBytes = memory.bytes.slice();
    const view = new DataView(expectedBytes.buffer);
    for (const [field, address] of Object.entries(fixtures.outputs)) view.setInt32(address - memory.base, fixture.expected[field], true);
    for (const field of ['currentStrength', 'previousStrength']) {
      view.setInt32(a[field] + fixture.boat * 4 - memory.base, fixture.expected[field], true);
    }
    view.setFloat64(a.cachedMetric + fixture.boat * 8 - memory.base, fixture.expected.cachedMetric, true);
    if (helper) invoke(helper, memory, fixture);
    else run(memory, fixture.x, fixture.y, fixture.boat);
    assert.deepEqual(memory.bytes, expectedBytes, `original writes for ${helper?.field ?? 'sampleCurrent'}, weather ${fixture.inputs.weather}`);
  }
});

test('uncaptured current FSIN phases throw instead of silently reducing or approximating', () => {
  const fixture = fixtures.cases.find(row => row.boat === 1 && row.inputs.time > row.inputs.resetTime + 10);
  assert.ok(fixture);
  const memory = originalMemory();
  prepare(memory, fixture);
  memory.writeI32(a.tideOffsetHours, 100);
  assert.throws(() => sampleCurrent(memory, fixture.x, fixture.y, fixture.boat),
    /FSIN angle.*outside the captured -1080\.\.1080 domain/);
});
