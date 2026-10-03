/** x86 integer storage conversions; use BigInt when a value exceeds Number precision. */
function integer(value) {
  if (typeof value === 'bigint') return value;
  if (typeof value !== 'number' || !Number.isSafeInteger(value)) {
    throw new TypeError('Integer conversion requires a safe integer Number or a BigInt');
  }
  return value;
}

function cast(value, bits, signed) {
  value = integer(value);
  if (typeof value === 'bigint') {
    return Number(signed ? BigInt.asIntN(bits, value) : BigInt.asUintN(bits, value));
  }
  if (bits === 32) return signed ? value | 0 : value >>> 0;
  const mask = (1 << bits) - 1;
  const narrowed = value & mask;
  return signed ? (narrowed << (32 - bits)) >> (32 - bits) : narrowed;
}

export const i8 = value => cast(value, 8, true);
export const u8 = value => cast(value, 8, false);
export const i16 = value => cast(value, 16, true);
export const u16 = value => cast(value, 16, false);
export const i32 = value => cast(value, 32, true);
export const u32 = value => cast(value, 32, false);

/** IEEE-754 binary32 storage rounding, default round-to-nearest/ties-to-even. */
export const f32 = Math.fround;
/** JavaScript binary64 value. This is not an x87 extended-precision operation. */
export const f64 = Number;

/** C-style truncation for a representable signed 32-bit floating-point conversion. */
export function truncFloatToI32(value) {
  if (typeof value !== 'number' || !Number.isFinite(value)) {
    throw new RangeError('Nonfinite float-to-int conversion requires an explicit x87 model');
  }
  const truncated = Math.trunc(value);
  if (truncated < -0x80000000 || truncated > 0x7fffffff) {
    throw new RangeError('Out-of-range float-to-int conversion requires an explicit x87 model');
  }
  return truncated === 0 ? 0 : truncated;
}

function signedDivisionOperands(dividend, divisor) {
  const a = i32(dividend), b = i32(divisor);
  if (b === 0) throw new RangeError('x86 integer division by zero');
  if (a === -0x80000000 && b === -1) throw new RangeError('x86 signed division overflow');
  return [a, b];
}

/** Signed C/x86 quotient truncates toward zero. Invalid IDIV inputs throw. */
export function idiv32(dividend, divisor) {
  const [a, b] = signedDivisionOperands(dividend, divisor);
  const result = Math.trunc(a / b);
  return result === 0 ? 0 : result;
}

/** Signed remainder has the dividend's sign (with integer zero normalized). */
export function irem32(dividend, divisor) {
  const [a, b] = signedDivisionOperands(dividend, divisor);
  const result = a % b;
  return result === 0 ? 0 : result;
}

export function udiv32(dividend, divisor) {
  const a = u32(dividend), b = u32(divisor);
  if (b === 0) throw new RangeError('x86 integer division by zero');
  return Math.floor(a / b);
}

export function urem32(dividend, divisor) {
  const a = u32(dividend), b = u32(divisor);
  if (b === 0) throw new RangeError('x86 integer division by zero');
  return a % b;
}

/** Low 32 product bits, avoiding the precision loss of JavaScript a * b. */
export const imul32 = (a, b) => Math.imul(i32(a), i32(b));
export const umul32 = (a, b) => Math.imul(u32(a), u32(b)) >>> 0;
export const add32 = (a, b) => (i32(a) + i32(b)) | 0;
export const sub32 = (a, b) => (i32(a) - i32(b)) | 0;
