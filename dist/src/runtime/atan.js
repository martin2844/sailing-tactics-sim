import { Float80, float80Key, getX87ControlWord, withX87ControlWord } from './float80.js';

// High precision mathematical atan2, rounded to extended precision once.
// FPATAN's vendor-specific final approximation can differ in the last m80 bit.
// Native instruction comparisons must establish the scope of each caller.
const PRECISION = 224;
const SCALE = 1n << BigInt(PRECISION);
const PRECISION_SHIFT = BigInt(PRECISION);
// BigInt division truncates toward zero; arithmetic right shift rounds down
// for negatives. Shift the magnitude so the fixed-point operation is exact.
const multiply = (left, right) => {
  const product = left * right;
  return product < 0n ? -((-product) >> PRECISION_SHIFT) : product >> PRECISION_SHIFT;
};
const ATAN_CACHE_LIMIT = 2048;
const atanCache = new Map();
const FAST_PRECISION = 112;
const FAST_SHIFT = BigInt(FAST_PRECISION);
const FAST_SCALE = 1n << FAST_SHIFT;
const FAST_ERROR = 1024n;

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
const FAST_PI = PI >> (PRECISION_SHIFT - FAST_SHIFT);

/**
 * Certify the original 224-bit result, rather than assuming fewer bits suffice.
 * Callers prove it lies within ±1024 units of their 112-bit integer. Monotonic
 * nearest/even m80 rounding makes identical endpoint results authoritative;
 * ambiguity, including an enclosure crossing zero, requires the 224-bit path.
 */
export function certifyFixed112(value) {
  const extended = integer => new Float80(integer < 0n ? -1 : 1, integer < 0n ? -integer : integer, -FAST_PRECISION);
  const lower = extended(value - FAST_ERROR), upper = extended(value + FAST_ERROR);
  return lower.sign === upper.sign && lower.mantissa === upper.mantissa && lower.exponent === upper.exponent ? lower : null;
}

const fastScaleDown = value => value < 0n ? -((-value) >> FAST_SHIFT) : value >> FAST_SHIFT;
function fastSeries(value) {
  if (value < -FAST_SCALE / 2n || value > FAST_SCALE / 2n) return null;
  const squared = fastScaleDown(value * value);
  let power = value, sum = value;
  // For |value/scale|≤1/2, each power decreases by at least 1/4. Both the
  // 112-bit candidate and original 224-bit series terminate within 113 steps.
  for (let denominator = 3n, sign = -1n, iteration = 0; iteration < 113; denominator += 2n, sign = -sign, iteration++) {
    power = fastScaleDown(power * squared);
    const term = power / denominator;
    if (term === 0n) return sum;
    sum += sign * term;
  }
  return null;
}

function fastAtanUnit(value) {
  if (value > FAST_SCALE / 2n) {
    const result = fastSeries(((value - FAST_SCALE) * FAST_SCALE) / (value + FAST_SCALE));
    return result === null ? null : FAST_PI / 4n + result;
  }
  return fastSeries(value);
}

function atanUnit(value) {
  if (value > SCALE / 2n) return PI / 4n + series(((value - SCALE) * SCALE) / (value + SCALE));
  return series(value);
}

/** Finite mathematical atan2(y,x) with 224-bit intermediate accuracy. */
export function atan2Extended(y, x) {
  if (!(y instanceof Float80) || !(x instanceof Float80)) throw new TypeError('Extended atan2 requires Float80 operands');
  const key = `${getX87ControlWord()}/${float80Key(y)}/${float80Key(x)}`;
  const cached = atanCache.get(key);
  if (cached) return cached;
  const result = calculateAtan2(y, x);
  if (atanCache.size >= ATAN_CACHE_LIMIT) atanCache.delete(atanCache.keys().next().value);
  atanCache.set(key, result);
  return result;
}

// Cache immutable m80 results only after successful evaluation. Exceptions and
// the temporary PC64 instruction scope of the small-ratio path still propagate.
function calculateAtan2(y, x) {
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
  /*
   * The bound covers the ORIGINAL fixed-point algorithm as well as the fast
   * one. For |series input|≤1/2, squared-input truncation and each power
   * truncation give a power error <2 scale units (contraction≤1/4). Each
   * divided term then differs by <2 units. At most 113 terms plus the first
   * omitted alternating term give <229 units. Ratio quantization and the
   * atan transform contribute <3 more; all atan derivatives here are ≤1.
   * The original Machin PI has error <20*(229+1)=4600 ORIGINAL scale units.
   * FAST_PI truncation adds <1 fast unit; PI divisions/quadrants add <6.
   * Thus the candidate-to-original difference is <240 fast units plus
   * 10000 original units (10000/2^112<1 fast unit), safely below 1024.
   * A guard failure or ambiguous m80 rounding always retains the old path.
   */
  let approximate = fastAtanUnit((small * FAST_SCALE) / large);
  if (approximate !== null) {
    if (inverted) approximate = FAST_PI / 2n - approximate;
    if (x.sign < 0) approximate = FAST_PI - approximate;
    const certified = certifyFixed112(BigInt(y.sign) * approximate);
    if (certified) return certified;
  }
  let magnitude = atanUnit((small * SCALE) / large);
  if (inverted) magnitude = PI / 2n - magnitude;
  if (x.sign < 0) magnitude = PI - magnitude;
  return new Float80(y.sign, magnitude, -PRECISION);
}

export function atanExtended(value) {
  return atan2Extended(value, Float80.fromInteger(1));
}
