import { Float80,withX87ControlWord } from './float80.js';

// High precision mathematical atan2, rounded to extended precision once.
// FPATAN's vendor-specific final approximation can differ in the last m80 bit.
// Native instruction comparisons must establish the scope of each caller.
const PRECISION = 224;
const SCALE = 1n << BigInt(PRECISION);
const multiply = (left, right) => (left * right) / SCALE;

function series(value) {
  const squared = multiply(value, value);
  let power = value;
  let sum = value;
  for (let denominator = 3n, sign = -1n; ; denominator += 2n, sign = -sign) {
    power = multiply(power, squared);
    const term = power / denominator;
    if (term === 0n) return sum;
    sum += sign * term;
  }
}
const PI = 16n * series(SCALE / 5n) - 4n * series(SCALE / 239n);
export { PI as PI_FIXED, PRECISION as FIXED_PRECISION, SCALE as FIXED_SCALE };

function atanUnit(value) {
  if (value > SCALE / 2n) return PI / 4n + series(((value - SCALE) * SCALE) / (value + SCALE));
  return series(value);
}

/** Finite mathematical atan2(y,x) with 224-bit intermediate accuracy. */
export function atan2Extended(y, x) {
  if (!(y instanceof Float80) || !(x instanceof Float80)) throw new TypeError('Extended atan2 requires Float80 operands');
  if (y.mantissa === 0n) {
    if (x.sign > 0) return new Float80(y.sign, 0n, 0);
    return new Float80(y.sign, PI, -PRECISION);
  }
  if (x.mantissa === 0n) return new Float80(y.sign, PI / 2n, -PRECISION);
  let numerator = y.mantissa;
  let denominator = x.mantissa;
  const difference = y.exponent - x.exponent;
  if (difference >= 0) numerator <<= BigInt(difference);
  else denominator <<= BigInt(-difference);
  const inverted = numerator > denominator;
  const small = inverted ? denominator : numerator;
  const large = inverted ? numerator : denominator;
  // For sufficiently small ratios, cubic correction is below half a unit of
  // the 64-bit result. Retain its own exponent rather than fixed-point zero.
  if (!inverted && x.sign > 0 && (small << 100n) < large) {
    const positiveX = x.sign < 0 ? x.negate() : x;
    // FPATAN retains 64 significant bits regardless of arithmetic PC. This
    // shortcut approximates that instruction, rather than performing FDIV.
    return withX87ControlWord(0x037f,()=>y.divide(positiveX));
  }
  let magnitude = atanUnit((small * SCALE) / large);
  if (inverted) magnitude = PI / 2n - magnitude;
  if (x.sign < 0) magnitude = PI - magnitude;
  return new Float80(y.sign, magnitude, -PRECISION);
}

export function atanExtended(value) {
  return atan2Extended(value, Float80.fromInteger(1));
}
