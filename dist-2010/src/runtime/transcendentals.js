import { Float80, float80Key, getX87ControlWord } from './float80.js';
import { PI_FIXED as PI, FIXED_PRECISION as PRECISION, FIXED_SCALE as SCALE, certifyFixed112 } from './atan.js';

const SIN_COS_CACHE_LIMIT = 2048;
const sinCosCache = new Map();
const PRECISION_SHIFT = BigInt(PRECISION);
// Preserve the truncation toward zero of division by the positive 2^224 scale.
const scaleDown = value => value < 0n ? -((-value) >> PRECISION_SHIFT) : value >> PRECISION_SHIFT;
const FAST_SHIFT = 112n;
const FAST_SCALE = 1n << FAST_SHIFT;
const fastScaleDown = value => value < 0n ? -((-value) >> FAST_SHIFT) : value >> FAST_SHIFT;

function fastSinCos(reduced, quadrant) {
  const shift = PRECISION_SHIFT - FAST_SHIFT;
  const angle = reduced < 0n ? -((-reduced) >> shift) : reduced >> shift;
  if (angle <= -FAST_SCALE || angle >= FAST_SCALE) return null;
  const squared = (angle * angle) >> FAST_SHIFT;
  let sine = angle, cosine = FAST_SCALE, sineTerm = angle, cosineTerm = FAST_SCALE;
  /*
   * Exact 224-bit x87 reduction precedes this candidate. |angle/scale|<1:
   * each Taylor term is bounded by scale/(2n)! and vanishes before n=64
   * at BOTH precisions (128!>2^224). Squared-input and successive term
   * truncations add <2 units per step, with contraction≤1/2, so each term
   * differs from the mathematical term by <4 units. Summation plus the
   * first omitted alternating term is <4*64+4=260 units. Truncating the
   * reduced angle contributes <1 fast unit because |sin'|,|cos'|≤1.
   * The original 224-bit series has the same <260-unit bound at its own
   * scale. Hence the original integer lies within 262 fast units, below
   * the conservative ±1024-unit enclosure. Certify both m80 endpoints;
   * failed iteration/range/rounding certification uses the original series.
   */
  for (let index = 1n; index <= 64n; index++) {
    const even = index * 2n;
    sineTerm = -fastScaleDown(sineTerm * squared) / (even * (even + 1n));
    cosineTerm = -fastScaleDown(cosineTerm * squared) / ((even - 1n) * even);
    sine += sineTerm; cosine += cosineTerm;
    if (sineTerm === 0n && cosineTerm === 0n) {
      const wrapped = Number((quadrant % 4n + 4n) % 4n);
      const pairs = [[sine, cosine], [cosine, -sine], [-sine, -cosine], [-cosine, sine]];
      const certifiedSine = certifyFixed112(pairs[wrapped][0]);
      const certifiedCosine = certifyFixed112(pairs[wrapped][1]);
      return certifiedSine && certifiedCosine ? { sine: certifiedSine, cosine: certifiedCosine } : null;
    }
  }
  return null;
}

function rememberSinCos(key, result) {
  if (sinCosCache.size >= SIN_COS_CACHE_LIMIT) sinCosCache.delete(sinCosCache.keys().next().value);
  // Float80 components are immutable; only this private wrapper is frozen.
  // Public callers always receive a fresh mutable pair.
  sinCosCache.set(key, Object.freeze({ ...result }));
  return result;
}

/**
 * Mathematical sin/cos with 224-bit intermediates and one m80 rounding.
 * The x87 vendor's polynomial/range-reduction error is not reproduced here.
 * Captured exact native tables remain authoritative for discrete game angles;
 * continuous rendering phases require exact original integer drawing traces.
 */
export function sinCosExtended(value) {
  if (!(value instanceof Float80)) throw new TypeError('Extended sine/cosine requires a Float80 operand');
  if (value.mantissa === 0n) return { sine: value, cosine: Float80.fromInteger(1) };
  const top = value.exponent + value.mantissa.toString(2).length - 1;
  if (top >= 63) throw new RangeError('Original x87 FSIN/FCOS input is outside its reduction range');
  if (top < -100) return { sine: value, cosine: Float80.fromInteger(1) };
  const shift = value.exponent + PRECISION;
  let angle = BigInt(value.sign) * (shift >= 0 ? value.mantissa << BigInt(shift) : value.mantissa >> BigInt(-shift));
  const revolution = PI * 2n;
  angle %= revolution;
  if (angle > PI) angle -= revolution;
  if (angle < -PI) angle += revolution;
  const squared = (angle * angle) >> PRECISION_SHIFT;
  let sine = angle;
  let cosine = SCALE;
  let sineTerm = angle;
  let cosineTerm = SCALE;
  for (let index = 1n; ; index++) {
    const even = index * 2n;
    sineTerm = -scaleDown(sineTerm * squared) / (even * (even + 1n));
    cosineTerm = -scaleDown(cosineTerm * squared) / ((even - 1n) * even);
    sine += sineTerm; cosine += cosineTerm;
    if (sineTerm === 0n && cosineTerm === 0n) break;
  }
  const extended = integer => new Float80(integer < 0n ? -1 : 1, integer < 0n ? -integer : integer, -PRECISION);
  return { sine: extended(sine), cosine: extended(cosine) };
}

export const sineExtended = value => sinCosExtended(value).sine;
export const cosineExtended = value => sinCosExtended(value).cosine;

// Intel SDM vol.1 §8.3.8, f=C90FDAA2 2168C234 C (66 significant bits):
// pi=0.f*2^2. The polynomial error after reduction is still vendor-specific.
const X87_PI = 0x3243f6a8885a308d3n << BigInt(PRECISION - 64);

/** Continuous x87-style 66-bit-pi reduction, with mathematical reduced series. */
export function sinCosX87(value) {
  if (!(value instanceof Float80)) throw new TypeError('Extended sine/cosine requires a Float80 operand');
  // Repeated game angles reuse the exact extended result. Keep every input bit
  // and control-word context; binary64 angle rounding would merge m80 values.
  const key = `${getX87ControlWord()}/${float80Key(value)}`;
  const cached = sinCosCache.get(key);
  if (cached) return { sine: cached.sine, cosine: cached.cosine };
  if (value.mantissa === 0n) return { sine: value, cosine: Float80.fromInteger(1) };
  const top = value.exponent + value.mantissa.toString(2).length - 1;
  if (top >= 63) throw new RangeError('Original x87 FSIN/FCOS input is outside its reduction range');
  if (top < -100) return { sine: value, cosine: Float80.fromInteger(1) };
  const shift = value.exponent + PRECISION;
  const input = BigInt(value.sign) * (shift >= 0 ? value.mantissa << BigInt(shift) : value.mantissa >> BigInt(-shift));
  const half = X87_PI / 2n;
  const quarter = X87_PI / 4n;
  const quadrant = input >= 0n ? (input + quarter) / half : (input - quarter) / half;
  const reduced = input - quadrant * half;
  const certified = fastSinCos(reduced, quadrant);
  if (certified) return rememberSinCos(key, certified);
  const squared = (reduced * reduced) >> PRECISION_SHIFT;
  let sine = reduced, cosine = SCALE, sineTerm = reduced, cosineTerm = SCALE;
  for (let index = 1n; ; index++) {
    const even = index * 2n;
    sineTerm = -scaleDown(sineTerm * squared) / (even * (even + 1n));
    cosineTerm = -scaleDown(cosineTerm * squared) / ((even - 1n) * even);
    sine += sineTerm; cosine += cosineTerm;
    if (sineTerm === 0n && cosineTerm === 0n) break;
  }
  const wrapped = Number((quadrant % 4n + 4n) % 4n);
  const pairs = [[sine, cosine], [cosine, -sine], [-sine, -cosine], [-cosine, sine]];
  const extended = integer => new Float80(integer < 0n ? -1 : 1, integer < 0n ? -integer : integer, -PRECISION);
  const result = { sine: extended(pairs[wrapped][0]), cosine: extended(pairs[wrapped][1]) };
  return rememberSinCos(key, result);
}
