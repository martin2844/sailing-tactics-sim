import test from 'node:test';
import assert from 'node:assert/strict';
import { Float80, getX87ControlWord, withX87ControlWord } from '../src/runtime/float80.js';

const hex = value => Buffer.from(value.toBytes()).toString('hex');
const endpoint = (value, exponent) => new Float80(value < 0n ? -1 : 1, value < 0n ? -value : value, exponent);

test('interval certification preserves exact m80 ties, signs, underflow and exponent limits at every PC', () => {
  const precisionBefore = getX87ControlWord();
  const boundary = (1n << 64n) + 1n;
  const cases = [
    [1n << 112n, (1n << 112n) + 1024n, -112],
    [-(1n << 112n) - 1024n, -(1n << 112n), -112],
    [boundary - 1n, boundary, 0], // even tie agrees with the lower endpoint
    [boundary, boundary + 1n, 0], // opposite sides of the rounding boundary
    [boundary + 2n, boundary + 3n, 0], // odd tie rounds toward the next even result
    [0n, 0n, 0],
    [0n, 1n, -16447],
    [-2n, -1n, -16448],
    [-1n, 0n, -16447],
    [1n, 1n, -16445],
    [1n << 63n, 1n << 63n, -16445],
    [(1n << 64n) - 1n, (1n << 64n) - 1n, 16320],
    [1n, 2n, -Number.MAX_SAFE_INTEGER],
  ];
  for (const controlWord of [0x007f, 0x027f, 0x037f]) withX87ControlWord(controlWord, () => {
    for (const [lower, upper, exponent] of cases) {
      const low = endpoint(lower, exponent), high = endpoint(upper, exponent);
      const certified = Float80.certifyInterval(lower, upper, exponent);
      if (hex(low) !== hex(high)) assert.equal(certified, null);
      else {
        assert.equal(hex(certified), hex(low));
        assert.ok(Object.isFrozen(certified));
        assert.ok(Object.is(certified.toNumber(), low.toNumber()));
        assert.equal(hex(certified.negate()), hex(low.negate()));
      }
      assert.equal(getX87ControlWord(), controlWord, 'certification does not change arithmetic PC');
    }
    assert.throws(() => Float80.certifyInterval(1n << 64n, 1n << 64n, 16320), /overflow/);
  });
  assert.equal(getX87ControlWord(), precisionBefore);
  assert.throws(() => Float80.certifyInterval(1, 2n, 0), /ordered BigInt/);
  assert.throws(() => Float80.certifyInterval(2n, 1n, 0), /ordered BigInt/);
  assert.throws(() => Float80.certifyInterval(1n, 2n, Infinity), /safe integer/);
  assert.throws(() => Float80.certifyInterval(1n, 2n, Number.MAX_SAFE_INTEGER), /safe integer/);
});

test('safe BigInt integer loads retain identical m80 images, integer returns and arithmetic precision', () => {
  const integers = [0n, -1n, 1n, -4097n, -4096n, 4096n, 4097n,
    -(1n << 24n) - 1n, (1n << 24n) + 1n, -(1n << 53n) + 1n, (1n << 53n) - 1n,
    -(1n << 53n), 1n << 53n, -(1n << 53n) - 1n, (1n << 53n) + 1n];
  for (const controlWord of [0x007f, 0x027f, 0x037f]) withX87ControlWord(controlWord, () => {
    for (const integer of integers) {
      const expected = endpoint(integer, 0), loaded = Float80.fromInteger(integer);
      assert.equal(hex(loaded), hex(expected));
      assert.equal(loaded.truncI64(), integer);
      assert.equal(hex(loaded.add(Float80.fromInteger(1))), hex(expected.add(Float80.fromInteger(1))));
      assert.equal(hex(loaded.divide(Float80.fromInteger(3))), hex(expected.divide(Float80.fromInteger(3))));
      assert.equal(getX87ControlWord(), controlWord);
    }
  });
});
