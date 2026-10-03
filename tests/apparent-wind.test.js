import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { apparentWind, APPARENT_WIND_ADDRESSES as a } from '../src/engine/apparent-wind.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-apparent-wind.json', import.meta.url), 'utf8'));
const tables = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json', import.meta.url), 'utf8'));

function initializedMemory() {
  const memory = loadPE32(original);
  for (let index = 0; index < tables.sine.length; index++) {
    memory.writeI32(a.sine + index * 4, tables.sine[index]);
    memory.writeI32(a.cosine + index * 4, tables.cosine[index]);
  }
  return memory;
}

function runCase(memory, fixture) {
  memory.writeI32(a.angleToTrueWind + fixture.boat * 4, fixture.angle);
  memory.writeI32(a.trueWindKnots + fixture.boat * 4, fixture.trueWind);
  const pressure = apparentWind(memory, fixture.speedTenths, fixture.boat);
  const bits = Buffer.alloc(8);
  bits.writeDoubleLE(pressure);
  return {
    pressureBits: bits.toString('hex'),
    apparentWindKnots: memory.readI32(a.apparentWindKnots + fixture.boat * 4),
    apparentWindAngle: memory.readI32(a.apparentWindAngle + fixture.boat * 4),
  };
}

test('wind and trigonometric fixtures identify the original binary and x87 setup', () => {
  const hash = createHash('sha256').update(original).digest('hex');
  assert.equal(fixtures.provenance.sha256, hash);
  assert.equal(tables.provenance.sha256, hash);
  assert.equal(fixtures.provenance.engine, 'Unicorn');
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.equal(tables.generator, '0x415a60');
  assert.equal(tables.sine.length, 362);
  assert.equal(tables.cosine.length, 362);
  assert.ok(fixtures.cases.length >= 1960);
  const angles = new Set(fixtures.cases.map(fixture => fixture.angle));
  for (let angle = 0; angle <= 361; angle++) assert.ok(angles.has(angle), `native angle ${angle}`);
});

test('all apparent-wind fields and exact returned binary64 bits match original instructions', () => {
  const memory = initializedMemory();
  for (const [index, fixture] of fixtures.cases.entries()) {
    const actual = runCase(memory, fixture);
    const { pressureBits, apparentWindKnots, apparentWindAngle } = fixture.expected;
    assert.deepEqual(actual, { pressureBits, apparentWindKnots, apparentWindAngle },
      `native case ${index}: speed ${fixture.speedTenths}, boat ${fixture.boat}, angle ${fixture.angle}, wind ${fixture.trueWind}`);
  }
});

test('native zero-vector and angle-361 cases preserve their early-return direction', () => {
  const zeroVector = fixtures.cases.find(fixture => fixture.angle === 0 && fixture.speedTenths === 0 && fixture.trueWind === 0);
  const beyondHalfTurn = fixtures.cases.find(fixture => fixture.angle > 179 && fixture.speedTenths === 0 && fixture.trueWind === 0);
  const angle361 = fixtures.cases.find(fixture => fixture.angle === 361 && fixture.expected.apparentWindAngle === 179);
  assert.ok(zeroVector);
  assert.ok(beyondHalfTurn);
  assert.ok(angle361);
  const memory = initializedMemory();
  assert.equal(runCase(memory, zeroVector).apparentWindAngle, 90);
  assert.equal(runCase(memory, beyondHalfTurn).apparentWindAngle, 90);
  assert.equal(runCase(memory, angle361).apparentWindAngle, 179);
});

test('apparent-wind calculation only changes its selected boat output fields', () => {
  const memory = initializedMemory();
  const fixture = fixtures.cases.find(value => value.boat === 30 && value.trueWind > 0);
  assert.ok(fixture);
  memory.writeI32(a.angleToTrueWind + fixture.boat * 4, fixture.angle);
  memory.writeI32(a.trueWindKnots + fixture.boat * 4, fixture.trueWind);
  const expectedBytes = memory.bytes.slice();
  const expectedMemory = new DataView(expectedBytes.buffer);
  expectedMemory.setInt32(a.apparentWindKnots + fixture.boat * 4 - memory.base, fixture.expected.apparentWindKnots, true);
  expectedMemory.setInt32(a.apparentWindAngle + fixture.boat * 4 - memory.base, fixture.expected.apparentWindAngle, true);
  apparentWind(memory, fixture.speedTenths, fixture.boat);
  assert.deepEqual(memory.bytes, expectedBytes);
});
