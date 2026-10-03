import { Float80 } from './float80.js';
import { PI_FIXED as PI, FIXED_PRECISION as PRECISION, FIXED_SCALE as SCALE } from './atan.js';

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
  const squared = (angle * angle) / SCALE;
  let sine = angle;
  let cosine = SCALE;
  let sineTerm = angle;
  let cosineTerm = SCALE;
  for (let index = 1n; ; index++) {
    const even = index * 2n;
    sineTerm = -((sineTerm * squared) / SCALE) / (even * (even + 1n));
    cosineTerm = -((cosineTerm * squared) / SCALE) / ((even - 1n) * even);
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
  const squared = (reduced * reduced) / SCALE;
  let sine = reduced, cosine = SCALE, sineTerm = reduced, cosineTerm = SCALE;
  for (let index = 1n; ; index++) {
    const even = index * 2n;
    sineTerm = -((sineTerm * squared) / SCALE) / (even * (even + 1n));
    cosineTerm = -((cosineTerm * squared) / SCALE) / ((even - 1n) * even);
    sine += sineTerm; cosine += cosineTerm;
    if (sineTerm === 0n && cosineTerm === 0n) break;
  }
  const wrapped = Number((quadrant % 4n + 4n) % 4n);
  const pairs = [[sine, cosine], [cosine, -sine], [-sine, -cosine], [-cosine, sine]];
  const extended = integer => new Float80(integer < 0n ? -1 : 1, integer < 0n ? -integer : integer, -PRECISION);
  return { sine: extended(pairs[wrapped][0]), cosine: extended(pairs[wrapped][1]) };
}
