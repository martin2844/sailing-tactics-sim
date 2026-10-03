import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { Float80 } from '../src/runtime/float80.js';

const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-x87.json', import.meta.url), 'utf8'));
const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const probe = await readFile(new URL('../tools/capture_x87_native.c', import.meta.url));
const calibration = JSON.parse(await readFile(new URL('../assets/data/boat-calibration.json', import.meta.url), 'utf8'));
const bytes = hex => Uint8Array.from(Buffer.from(hex, 'hex'));
const hex = value => Buffer.from(value).toString('hex');
const doubleBits = value => { const buffer = Buffer.alloc(8); buffer.writeDoubleLE(value); return buffer.toString('hex'); };

test('x87 fixtures identify source, precision64 rounding mode and native probes', () => {
  assert.equal(fixtures.provenance.sha256, createHash('sha256').update(original).digest('hex'));
  assert.equal(fixtures.provenance.engine, 'Unicorn');
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.equal(fixtures.provenance.authoritative_engine, 'native-x87');
  assert.equal(fixtures.provenance.native_verification.probe_sha256, createHash('sha256').update(probe).digest('hex'));
  for (const row of [...fixtures.arithmetic, ...fixtures.truncation]) assert.equal(row.referenceEngine, 'native-x87');
  assert.ok(fixtures.arithmetic.length >= 989);
  assert.ok(fixtures.truncation.length >= 110);
});

test('all captured native boat factors match extended division then sqrt and binary64 store', () => {
  assert.equal(calibration.provenance.authoritative_engine, 'native-x87');
  for (const [length, reference] of Object.entries(calibration.lengths)) {
    const factor = Float80.fromInteger(15).divide(Float80.fromInteger(Number(length))).sqrt();
    assert.equal(hex(factor.toBytes()), reference.extendedBits, `native extended factor length ${length}`);
    assert.equal(doubleBits(factor.toNumber()), reference.bits, `native stored factor length ${length}`);
  }
});

test('every finite arithmetic result matches native m80 and binary64 stored bits', () => {
  for (const [index, fixture] of fixtures.arithmetic.entries()) {
    const left = Float80.fromBytes(bytes(fixture.leftBits));
    const right = fixture.rightBits ? Float80.fromBytes(bytes(fixture.rightBits)) : undefined;
    const result = fixture.operation === 'sqrt' ? left.sqrt() : left[fixture.operation](right);
    assert.equal(hex(result.toBytes()), fixture.expected.extendedBits, `${fixture.operation} extended bits, native case ${index}`);
    assert.equal(doubleBits(result.toNumber()), fixture.expected.storedDoubleBits, `${fixture.operation} stored bits, native case ${index}`);
  }
});

test('every native CRT __ftol truncation matches signed64 and low signed32', () => {
  for (const [index, fixture] of fixtures.truncation.entries()) {
    const value = Float80.fromBytes(bytes(fixture.inputBits));
    assert.equal(value.truncI64().toString(), fixture.expected.integer64, `native ftol int64 case ${index}`);
    assert.equal(value.truncI32(), fixture.expected.integer32, `native ftol int32 case ${index}`);
  }
});

test('binary64 loading is exact for signedzero, subnormals and boundary values', () => {
  for (const number of [0, -0, Number.MIN_VALUE, -Number.MIN_VALUE, 2 ** -1022, Number.MAX_VALUE, -Number.MAX_VALUE, Math.PI, 1, -1]) {
    assert.equal(doubleBits(Float80.fromNumber(number).toNumber()), doubleBits(number));
  }
  const one = Float80.fromInteger(1);
  const tiny = new Float80(1, 1n, -60);
  assert.equal(one.add(tiny).subtract(one).compare(tiny), 0);
  assert.equal(one.add(tiny).toNumber(), 1);
});

test('canonical m80 loading and byte copies retain finite values and signs', () => {
  const pseudo = bytes('00000000000000800000');
  const normal = Float80.fromBytes(pseudo);
  assert.equal(hex(normal.toBytes()), '00000000000000800100');
  const padded = new Uint8Array(20);
  padded.set(normal.toBytes(), 4);
  assert.equal(hex(Float80.fromBytes(padded.subarray(4, 14)).toBytes()), hex(normal.toBytes()));
  const smallest = Float80.fromBytes(bytes('01000000000000000000'));
  assert.equal(smallest.mantissa, 1n);
  assert.equal(smallest.exponent, -16445);
  assert.equal(hex(smallest.toBytes()), '01000000000000000000');
  const output = normal.toBytes();
  output[0] = 255;
  assert.equal(hex(normal.toBytes()), '00000000000000800100');
  assert.ok(Object.isFrozen(normal));
  assert.throws(() => { normal.sign = -1; }, TypeError);
});

test('signedzero, exact cancellation, ordering and underflow are preserved', () => {
  const negativeZero = Float80.fromNumber(-0), zero = Float80.fromNumber(0);
  assert.ok(Object.is(negativeZero.add(negativeZero).toNumber(), -0));
  assert.ok(Object.is(negativeZero.add(zero).toNumber(), 0));
  assert.ok(Object.is(negativeZero.multiply(Float80.fromInteger(2)).toNumber(), -0));
  assert.ok(Object.is(negativeZero.sqrt().toNumber(), -0));
  assert.equal(negativeZero.compare(zero), 0);
  assert.equal(Float80.fromInteger(-2).compare(Float80.fromInteger(-1)), -1);
  assert.equal(Float80.fromInteger(2).compare(Float80.fromInteger(-1)), 1);
  assert.ok(Object.is(Float80.fromInteger(-1).add(Float80.fromInteger(1)).toNumber(), 0));
  assert.equal(new Float80(1, 1n, -16446).mantissa, 0n); // Half-way to the least subnormal, even zero.
  assert.equal(new Float80(1, 3n, -16446).mantissa, 2n); // Half-way between odd/even subnormal significands.
  assert.equal(new Float80(1, 1n, 1024).toNumber(), Infinity);
  assert.equal(new Float80(-1, 1n, 1024).toNumber(), -Infinity);
});

test('unsupported nonfinite encodings, exceptions and invalid conversions throw', () => {
  for (const value of [NaN, Infinity, -Infinity]) assert.throws(() => Float80.fromNumber(value), /does not support/);
  assert.throws(() => Float80.fromBytes(bytes('0000000000000080ff7f')), /does not support/);
  assert.throws(() => Float80.fromBytes(bytes('01000000000000000100')), /unnormal/);
  assert.throws(() => Float80.fromInteger(Number.MAX_SAFE_INTEGER + 1), /safe integer/);
  assert.throws(() => Float80.fromInteger(1).divide(Float80.fromInteger(0)), /division by zero/);
  assert.throws(() => Float80.fromInteger(-1).sqrt(), /negative square root/);
  assert.throws(() => new Float80(1, 1n, 16384), /overflow/);
  assert.throws(() => Float80.fromInteger(1n << 63n).truncI32(), /signed int64/);
  assert.equal(Float80.fromInteger(-(1n << 63n)).truncI64(), -(1n << 63n));
});
