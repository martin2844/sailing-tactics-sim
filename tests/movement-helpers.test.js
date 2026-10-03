import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import {
  MOVEMENT_HELPER_ADDRESSES as a, distanceToBoat, prestartSpeedPercent,
} from '../src/engine/movement-helpers.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-movement-helpers.json', import.meta.url), 'utf8'));
const fromBits = bits => Buffer.from(bits, 'hex').readDoubleLE();
const doubleBits = value => { const bytes = Buffer.alloc(8); bytes.writeDoubleLE(value); return bytes.toString('hex'); };
const imageBytes = memory => Buffer.from(memory.bytes.buffer, memory.bytes.byteOffset, memory.bytes.byteLength);

function preparePrestart(memory, fixture) {
  for (const [field, value] of Object.entries(fixture.inputs)) memory.writeI32(fixtures.inputs[field], value);
  for (const [field, bits] of Object.entries(fixture.doubleInputBits)) memory.writeF64(fixtures.doubleInputs[field], fromBits(bits));
  for (const [field, value] of Object.entries(fixture.indexedInputs)) {
    const { address, stride, type } = fixtures.indexed[field];
    if (type === 'F64') memory.writeF64(address + fixture.boat * stride, fromBits(fixture.indexedInputBits[field]));
    else memory.writeI32(address + fixture.boat * stride, value);
  }
}

test('movement fixtures identify unchanged original instructions, typed globals and finite scope', () => {
  assert.equal(fixtures.provenance.sha256, createHash('sha256').update(original).digest('hex'));
  assert.equal(fixtures.provenance.engine, 'Unicorn');
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.equal(fixtures.provenance.tls_accessor_stub, '0x459ed0');
  assert.match(fixtures.provenance.note, /not a complete movement or full-game parity proof/);
  assert.equal(fixtures.distanceToBoat.address, a.distanceToBoat);
  assert.equal(fixtures.prestartSpeedPercent.address, a.prestartSpeedPercent);
  for (const [field, address] of Object.entries({ ...fixtures.inputs, ...fixtures.doubleInputs })) assert.equal(address, a[field]);
  for (const [field, spec] of Object.entries(fixtures.indexed)) {
    assert.equal(spec.address, a[field]);
    assert.equal(spec.stride, spec.type === 'F64' ? 8 : 4);
  }
  assert.ok(fixtures.provenance.floating_spills.distanceToBoat[0].includes('0x428ace'));
  assert.ok(fixtures.provenance.floating_spills.prestartSpeedPercent[1].includes('0x42a423'));
});

test('all captured distances match exact original ST0, binary64 store and unchanged image', () => {
  const memory = loadPE32(original);
  for (const [index, fixture] of fixtures.distanceToBoat.cases.entries()) {
    for (const field of ['positionX', 'positionY']) memory.writeF64(a[field] + fixture.boat * 8, fromBits(fixture.inputBits[field]));
    const before = Buffer.from(imageBytes(memory));
    const result = distanceToBoat(memory, fixture.boat, fromBits(fixture.inputBits.x), fromBits(fixture.inputBits.y));
    const context = `native distance ${index}: boat ${fixture.boat}`;
    assert.equal(Buffer.from(result.toBytes()).toString('hex'), fixture.expected.returnExtendedBits, `${context} ST0 bits`);
    assert.equal(doubleBits(result.toNumber()), fixture.expected.returnBits, `${context} store bits`);
    assert.equal(result.toNumber(), fixture.expected.returnValue, `${context} value`);
    assert.equal(fixture.expected.imageUnchanged, true);
    assert.equal(imageBytes(memory).equals(before), true, `${context} no mapped image writes`);
    assert.match(fixture.nativeSpills.deltaXStoredBits, /^[0-9a-f]{16}$/);
  }
});

test('all captured prestart percentages match original EAX, RNG state and unchanged image', () => {
  const memory = loadPE32(original);
  for (const [index, fixture] of fixtures.prestartSpeedPercent.cases.entries()) {
    preparePrestart(memory, fixture);
    const before = Buffer.from(imageBytes(memory));
    const rng = new PoseyRng(fixture.seed);
    const result = prestartSpeedPercent(memory, fixture.boat, rng);
    const context = `native prestart ${index}: boat ${fixture.boat}, count ${fixture.inputs.boatCount}, difficulty ${fixture.inputs.difficulty}`;
    assert.equal(result, fixture.expected.returnValue, `${context} EAX`);
    assert.equal(rng.state, fixture.expected.rngState, `${context} RNG state`);
    assert.equal(fixture.expected.imageUnchanged, true);
    assert.equal(imageBytes(memory).equals(before), true, `${context} no mapped image writes`);
    const early = fixture.inputs.boatCount === 2 && fixture.boat === 2 && fixture.inputs.time < fixture.inputs.secondBoatDelay;
    assert.equal(Object.keys(fixture.nativeSpills).length, early ? 0 : 2, `${context} native spill capture`);
  }
});

test('reference coverage includes delayed starts, RNG despite interference, unclamped negatives and precision boundaries', () => {
  const cases = fixtures.prestartSpeedPercent.cases;
  for (const count of [1, 2, 3, 4]) assert.ok(cases.some(row => row.inputs.boatCount === count));
  for (const time of [19, 20, 21]) assert.ok(cases.some(row => row.inputs.boatCount === 2 && row.boat === 2 && row.inputs.time === time));
  for (const difficulty of [-2147483648, 1, 2, 12, 13, 2147483647]) assert.ok(cases.some(row => row.inputs.difficulty === difficulty));
  assert.ok(cases.some(row => row.inputs.course === 8 && row.inputs.islandFlag === 0 && row.inputs.difficulty === 1));
  for (const coefficient of [59, 60, 61, 100]) assert.ok(cases.some(row => row.indexedInputs.rateCoefficient === coefficient));
  for (const interference of [0, 1, 2]) assert.ok(cases.some(row => row.indexedInputs.interference === interference));
  assert.ok(cases.some(row => row.inputs.boatCount > 2 && row.indexedInputs.interference > 0 && row.expected.returnValue === 100 && row.expected.rngState !== row.seed));
  assert.ok(cases.some(row => row.expected.returnValue < 0));
  for (const sign of [-1, 1]) assert.ok(cases.some(row => Math.sign(row.doubleInputs.raceTime) === sign));
  assert.ok(cases.some(row => row.indexedInputs.positionX === 2 ** 53));
  assert.ok(fixtures.distanceToBoat.cases.some(row => row.inputBits.x === '0000000000000080'));
  assert.ok(fixtures.distanceToBoat.cases.some(row => row.expected.returnBits === '0000000000000000'));
  assert.ok(fixtures.distanceToBoat.cases.some(row => Math.abs(row.positionX) >= 1e150));
});
