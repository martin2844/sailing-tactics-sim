import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { Float80, float80Key, getX87ControlWord, withX87ControlWord } from '../src/runtime/float80.js';
import { atan2Extended, certifyFixed112, FIXED_PRECISION, FIXED_SCALE, PI_FIXED } from '../src/runtime/atan.js';
import { sinCosExtended, sinCosX87 } from '../src/runtime/transcendentals.js';

const from = bits => Float80.fromBytes(Buffer.from(bits, 'hex'));
const hex = value => Buffer.from(value.toBytes()).toString('hex');
// Uncached pre-optimization m80 results, including adjacent values that all
// store to the same binary64 Number. These exercise cache-key precision.
const adjacent = [
  ['0000000000000080ff3f', '2170674878a46ad7fe3f', '925c34a87d40518afe3f', '35c26821a2da0fc9fe3f'],
  ['0100000000000080ff3f', '2270674878a46ad7fe3f', '905c34a87d40518afe3f', '36c26821a2da0fc9fe3f'],
  ['0200000000000080ff3f', '2370674878a46ad7fe3f', '8e5c34a87d40518afe3f', '37c26821a2da0fc9fe3f'],
  ['0100000000000080ffbf', '2270674878a46ad7febf', '905c34a87d40518afe3f', '36c26821a2da0fc9febf'],
];

test('cold and warm transcendental caches retain every m80 input bit under PC24/53/64', () => {
  assert.equal(from(adjacent[0][0]).toNumber(), from(adjacent[1][0]).toNumber());
  for (const controlWord of [0x007f, 0x027f, 0x037f]) withX87ControlWord(controlWord, () => {
    for (let repeat = 0; repeat < 3; repeat++) for (const [input, sine, cosine, atan] of adjacent) {
      const value = from(input), pair = sinCosX87(value);
      assert.equal(hex(pair.sine), sine);
      assert.equal(hex(pair.cosine), cosine);
      assert.equal(hex(atan2Extended(value, Float80.fromInteger(1))), atan);
      assert.equal(getX87ControlWord(), controlWord);
    }
  });
});

test('sin/cos returns fresh mutable wrappers without exposing the cached pair', () => {
  const value = from(adjacent[1][0]);
  const first = sinCosX87(value), second = sinCosX87(value);
  assert.notEqual(first, second);
  assert.equal(Object.isFrozen(first), false);
  assert.equal(Object.isFrozen(second), false);
  assert.equal(Object.isFrozen(first.sine), true);
  first.sine = Float80.fromInteger(0);
  delete first.cosine;
  second.cosine = Float80.fromInteger(0);
  const third = sinCosX87(from(adjacent[1][0]));
  assert.equal(hex(third.sine), adjacent[1][1]);
  assert.equal(hex(third.cosine), adjacent[1][2]);
});

test('sin/cos preserves signed-zero and tiny-input identity on repeated calls', () => {
  for (const controlWord of [0x007f, 0x027f, 0x037f]) withX87ControlWord(controlWord, () => {
    for (const sign of [1, -1]) for (const mantissa of [0n, 1n, 0x8000000000000001n]) {
      const first = new Float80(sign, mantissa, -16445);
      const second = new Float80(sign, mantissa, -16445);
      assert.equal(sinCosX87(first).sine, first);
      assert.equal(sinCosX87(second).sine, second);
      assert.equal(hex(sinCosX87(first).cosine), '0000000000000080ff3f');
    }
  });
});

test('atan cache preserves all signed-zero quadrants and PC64 tiny-ratio instruction scope', () => {
  for (const controlWord of [0x007f, 0x027f, 0x037f]) withX87ControlWord(controlWord, () => {
    for (let repeat = 0; repeat < 2; repeat++) for (const sign of [1, -1]) {
      const zero = new Float80(sign, 0n, 0);
      const positive = Float80.fromInteger(1), negative = Float80.fromInteger(-1);
      assert.equal(hex(atan2Extended(zero, positive)), sign > 0 ? '00000000000000000000' : '00000000000000000080');
      assert.equal(hex(atan2Extended(zero, new Float80(1, 0n, 0))), hex(zero));
      const pi = sign > 0 ? '35c26821a2da0fc90040' : '35c26821a2da0fc900c0';
      assert.equal(hex(atan2Extended(zero, negative)), pi);
      assert.equal(hex(atan2Extended(zero, new Float80(-1, 0n, 0))), pi);
      const tiny = new Float80(sign, 0x8000000000000001n, -200);
      assert.equal(hex(atan2Extended(tiny, positive)), hex(tiny));
      assert.equal(getX87ControlWord(), controlWord);
    }
  });
});

test('cached calls still reject invalid operands and out-of-range sin/cos inputs', () => {
  const one = Float80.fromInteger(1);
  sinCosX87(one); atan2Extended(one, one);
  for (const value of [1, null, {}, Object.create(null)]) {
    assert.throws(() => sinCosX87(value), TypeError);
    assert.throws(() => atan2Extended(value, one), TypeError);
    assert.throws(() => atan2Extended(one, value), TypeError);
  }
  for (const sign of [1, -1]) {
    assert.throws(() => sinCosX87(new Float80(sign, 1n, 63)), RangeError);
    assert.throws(() => sinCosX87(new Float80(sign, 1n, 16383)), RangeError);
  }
});

// Load isolated production modules and expose their private maps only to this
// test. This verifies retention limits without adding browser diagnostics APIs.
async function inspectableModule(name, exports) {
  const location = new URL(`../src/runtime/${name}.js`, import.meta.url);
  const source = (await readFile(location, 'utf8')).replace(/from '(\.\/[^']+)'/g,
    (_match, specifier) => `from ${JSON.stringify(new URL(specifier, location).href)}`);
  return import(`data:text/javascript;base64,${Buffer.from(`${source}\nexport { ${exports} };`).toString('base64')}`);
}

test('fixed-point shifts preserve signed truncation around zero and every scale boundary', async () => {
  assert.equal(FIXED_PRECISION, 224);
  assert.equal(FIXED_SCALE, 1n << 224n);
  assert.equal(PI_FIXED, 0x3243f6a8885a308d313198a2e03707344a4093822299f31d0082efa94n);
  const trig = await inspectableModule('transcendentals', 'scaleDown');
  const atan = await inspectableModule('atan', 'multiply');
  for (const magnitude of [0n, 1n, FIXED_SCALE - 1n, FIXED_SCALE, FIXED_SCALE + 1n, 3n * FIXED_SCALE - 1n, 3n * FIXED_SCALE + 1n]) {
    for (const sign of [1n, -1n]) {
      const value = sign * magnitude;
      assert.equal(trig.scaleDown(value), value / FIXED_SCALE);
      assert.equal(atan.multiply(value, 1n), value / FIXED_SCALE);
      assert.equal(atan.multiply(value, -1n), -value / FIXED_SCALE);
    }
  }
  // Exercise the series at its tiny-input cutoff with both signs. A direct
  // negative shift would turn a sub-scale negative correction into -1n.
  for (const exponent of [-99, -100, -101]) for (const sign of [1, -1]) {
    const value = new Float80(sign, 0x8000000000000001n, exponent - 63);
    for (const routine of [sinCosExtended, sinCosX87]) {
      const pair = routine(value);
      assert.equal(hex(pair.sine), hex(value));
      assert.equal(hex(pair.cosine), '0000000000000080ff3f');
    }
    assert.equal(hex(atan2Extended(value, Float80.fromInteger(1))), hex(value));
  }
});

test('enclosure certification rejects ambiguous m80 rounding and near-zero results', () => {
  const half = 1n << 111n, halfUlp = 1n << 47n;
  assert.equal(hex(certifyFixed112(half)), hex(Float80.fromNumber(0.5)));
  assert.equal(hex(certifyFixed112(-half)), hex(Float80.fromNumber(-0.5)));
  for (const sign of [1n, -1n]) {
    assert.equal(certifyFixed112(sign * (half + halfUlp)), null);
    for (const value of [0n, 1n, 1024n]) assert.equal(certifyFixed112(sign * value), null);
  }
});

test('certified series enforce their domains and preserve the original fallback near quadrant zero', async () => {
  const trig = await inspectableModule('transcendentals', 'fastSinCos');
  const atan = await inspectableModule('atan', 'fastSeries');
  assert.equal(trig.fastSinCos(FIXED_SCALE, 0n), null);
  assert.equal(trig.fastSinCos(-FIXED_SCALE, 0n), null);
  assert.equal(trig.fastSinCos(0n, 0n), null, 'zero sine requires the exact original result');
  assert.equal(atan.fastSeries((1n << 111n) + 1n), null);
  assert.equal(atan.fastSeries(-(1n << 111n) - 1n), null);
  for (const sign of [1, -1]) {
    const value = new Float80(sign, 0x8000000000000001n, -133);
    assert.equal(hex(atan2Extended(value, Float80.fromInteger(1))), hex(value), 'ambiguous small atan uses all original m80 bits');
  }
});

test('both caches evict oldest entries and remain bounded across changing inputs and control words', async () => {
  const trig = await inspectableModule('transcendentals', 'sinCosCache as cache, SIN_COS_CACHE_LIMIT as cacheLimit');
  const atan = await inspectableModule('atan', 'atanCache as cache, ATAN_CACHE_LIMIT as cacheLimit');
  const one = Float80.fromInteger(1), key = `${getX87ControlWord()}/${float80Key(one)}`;
  const pair = trig.sinCosX87(one), angle = atan.atan2Extended(one, one);
  for (let index = 1; index <= Math.max(trig.cacheLimit, atan.cacheLimit) + 32; index++) {
    const value = new Float80(1, 0x8000000000000000n + BigInt(index), -63);
    trig.sinCosX87(value); atan.atan2Extended(value, one);
    assert.ok(trig.cache.size <= trig.cacheLimit);
    assert.ok(atan.cache.size <= atan.cacheLimit);
  }
  assert.equal(trig.cache.size, trig.cacheLimit);
  assert.equal(atan.cache.size, atan.cacheLimit);
  assert.equal(trig.cache.has(key), false);
  assert.equal(atan.cache.has(`${key}/${float80Key(one)}`), false);
  const recomputed = trig.sinCosX87(one);
  assert.equal(hex(recomputed.sine), hex(pair.sine));
  assert.equal(hex(recomputed.cosine), hex(pair.cosine));
  assert.equal(hex(atan.atan2Extended(one, one)), hex(angle));
  for (const controlWord of [0x007f, 0x027f, 0x037f]) withX87ControlWord(controlWord, () => {
    trig.sinCosX87(one); atan.atan2Extended(one, one);
    assert.ok(trig.cache.has(`${controlWord}/${float80Key(one)}`));
    assert.ok(atan.cache.has(`${controlWord}/${float80Key(one)}/${float80Key(one)}`));
    assert.ok(trig.cache.size <= trig.cacheLimit);
    assert.ok(atan.cache.size <= atan.cacheLimit);
  });
});
