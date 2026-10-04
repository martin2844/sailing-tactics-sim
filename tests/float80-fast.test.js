import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { Float80, float80Key, withX87ControlWord } from '../src/runtime/float80.js';

const precision = JSON.parse(await readFile(new URL('./fixtures/native-precision.json', import.meta.url), 'utf8'));
const fromBits = bits => Float80.fromBytes(Buffer.from(bits, 'hex'));
const hex = value => Buffer.from(value.toBytes()).toString('hex');
const doubleBits = value => { const bytes = Buffer.alloc(8); bytes.writeDoubleLE(value); return bytes.toString('hex'); };

test('binary64 carriers match captured native PC24/53/64 arithmetic and stored bits', () => {
  const checked = new Map();
  for (const [index, row] of precision.cases.entries()) {
    const left = fromBits(row.leftBits), right = fromBits(row.rightBits);
    const leftNumber = left.toNumber(), rightNumber = right.toNumber();
    if (!Number.isFinite(leftNumber) || !Number.isFinite(rightNumber)) continue;
    const carriedLeft = Float80.fromNumber(leftNumber), carriedRight = Float80.fromNumber(rightNumber);
    if (hex(carriedLeft) !== hex(left) || hex(carriedRight) !== hex(right)) continue;
    const result = withX87ControlWord(row.controlWord, () => row.operation === 'sqrt'
      ? carriedLeft.sqrt() : carriedLeft[row.operation](carriedRight));
    assert.equal(hex(result), row.expected.extendedBits, `native carried m80 ${index}`);
    assert.equal(doubleBits(result.toNumber()), row.expected.storedDoubleBits, `native carried binary64 ${index}`);
    checked.set(row.controlWord, (checked.get(row.controlWord) ?? 0) + 1);
  }
  for (const word of [0x007f, 0x027f, 0x037f]) assert.ok(checked.get(word) >= 20, `native cases for CW ${word.toString(16)}`);
});

test('PC53 arithmetic retains the x87 exponent range at binary64 overflow and underflow', () => {
  withX87ControlWord(0x027f, () => {
    const overflow = Float80.fromNumber(Number.MAX_VALUE).multiply(Float80.fromInteger(2));
    assert.equal(overflow.toNumber(), Infinity);
    assert.equal(overflow.compare(new Float80(1, (1n << 53n) - 1n, 972)), 0);
    const subnormal = Float80.fromNumber(2 ** -1022).divide(Float80.fromInteger(2));
    assert.equal(subnormal.compare(new Float80(1, 1n, -1023)), 0);
    const underflow = Float80.fromNumber(Number.MIN_VALUE).multiply(Float80.fromNumber(Number.MIN_VALUE));
    assert.equal(underflow.toNumber(), 0);
    assert.equal(underflow.compare(new Float80(1, 1n, -2148)), 0);
    const extendedInput = new Float80(1, (1n << 63n) + 1n, -63);
    const residual = extendedInput.subtract(Float80.fromInteger(1));
    assert.equal(residual.compare(new Float80(1, 1n, -63)), 0);
    assert.notEqual(float80Key(extendedInput), float80Key(Float80.fromInteger(1)));
  });
});

test('carried values preserve frozen public fields, signed zeros and integer boundaries', () => {
  for (const number of [0, -0, Number.MIN_VALUE, 2 ** -1022, 1, Math.PI, Number.MAX_VALUE]) {
    const value = Float80.fromNumber(number);
    assert.equal(typeof value.mantissa, 'bigint');
    assert.equal(typeof value.exponent, 'number');
    assert.ok(Object.isFrozen(value));
    assert.throws(() => { value.mantissa = 3n; }, TypeError);
    assert.throws(() => { value.exponent = 0; }, TypeError);
    const key = float80Key(value);
    assert.equal(doubleBits(value.toNumber()), doubleBits(number));
    assert.equal(hex(Float80.fromBytes(value.toBytes())), hex(value));
    assert.equal(float80Key(value), key);
  }
  assert.notEqual(float80Key(Float80.fromNumber(-0)), float80Key(Float80.fromNumber(0)));
  withX87ControlWord(0x027f, () => {
    const positive = Float80.fromNumber(0), negative = Float80.fromNumber(-0);
    assert.ok(Object.is(negative.add(negative).toNumber(), -0));
    assert.ok(Object.is(negative.subtract(positive).toNumber(), -0));
    assert.ok(Object.is(negative.multiply(Float80.fromNumber(-1)).toNumber(), 0));
    assert.ok(Object.is(positive.divide(Float80.fromNumber(-1)).toNumber(), -0));
    assert.ok(Object.is(Float80.fromInteger(-1).add(Float80.fromInteger(1)).toNumber(), 0));
    assert.throws(() => positive.divide(negative), /division by zero/);
  });
  for (const number of [-(2 ** 63), -(2 ** 53), -4294967297.75, -0, 0, 4294967297.75, 2 ** 53, 2 ** 63 - 1024]) {
    const value = Float80.fromNumber(number), expected = BigInt(Math.trunc(number));
    assert.equal(value.truncI64(), expected);
    assert.equal(value.truncI32(), Number(BigInt.asIntN(32, expected)));
  }
  for (const number of [2 ** 63, -(2 ** 63) - 2048]) {
    assert.throws(() => Float80.fromNumber(number).truncI64(), /signed int64/);
    assert.throws(() => Float80.fromNumber(number).truncI32(), /signed int64/);
  }
  assert.ok(Object.is(Float80.fromInteger(-0).toNumber(), 0));
});

test('shared immutable integer carriers retain exact values across other loads', () => {
  const original = Float80.fromNumber(17);
  const expected = hex(original);
  assert.equal(Float80.fromNumber(17), original);
  const negativeZero = Float80.fromNumber(-0);
  assert.notEqual(negativeZero, Float80.fromNumber(0));
  for (let index = 0; index < 9000; index++) Float80.fromNumber(index + .125);
  assert.equal(hex(original), expected);
  assert.equal(hex(Float80.fromNumber(17)), expected);
  assert.ok(Object.is(negativeZero.toNumber(), -0));
  assert.ok(Object.is(Float80.fromNumber(-0).toNumber(), -0));
});

test('PC53 square root uses only an exactly certified candidate and falls back on bad candidates', () => {
  const squareRoot = Math.sqrt;
  try {
    withX87ControlWord(0x027f, () => {
      for (const faulty of [() => 0, () => NaN, () => Infinity, () => 1, () => 3, () => -2, () => 2n,
        () => { throw new Error('bad square-root candidate'); }, value => squareRoot(value) + 1]) {
        Math.sqrt = faulty;
        assert.equal(hex(Float80.fromNumber(2).sqrt()), '0068def933f304b5ff3f');
        assert.equal(Float80.fromNumber(4).sqrt().toNumber(), 2);
        assert.equal(Float80.fromNumber(Number.MIN_VALUE).sqrt().compare(new Float80(1, 1n, -537)), 0);
      }
      Math.sqrt = () => { throw new Error('candidate must not be used'); };
      assert.ok(Object.is(Float80.fromNumber(-0).sqrt().toNumber(), -0));
      assert.throws(() => Float80.fromInteger(-1).sqrt(), /negative square root/);
    });
    for (const word of [0x007f, 0x037f]) withX87ControlWord(word, () => {
      Math.sqrt = () => { throw new Error('candidate must not be used'); };
      assert.equal(Float80.fromNumber(4).sqrt().toNumber(), 2);
    });
  } finally {
    Math.sqrt = squareRoot;
  }
});

test('PC53 exact identities retain every operand bit, including binary64 subnormals', () => {
  withX87ControlWord(0x027f, () => {
    const zero = Float80.fromNumber(0), negativeZero = Float80.fromNumber(-0), one = Float80.fromInteger(1);
    for (const number of [Number.MIN_VALUE, -Number.MIN_VALUE, 2 ** -1022, Math.PI, -1, Number.MAX_VALUE]) {
      const value = Float80.fromNumber(number), expected = hex(value);
      for (const result of [value.add(zero), zero.add(value), value.add(negativeZero), value.subtract(zero),
        value.subtract(negativeZero), value.multiply(one), one.multiply(value), value.divide(one)]) {
        assert.equal(hex(result), expected);
        assert.ok(Object.isFrozen(result));
      }
    }
    for (const integer of [1, 2, 3, 64, 65535, 2 ** 26]) {
      assert.equal(Float80.fromNumber(integer * integer).sqrt().toNumber(), integer);
    }
  });
});
