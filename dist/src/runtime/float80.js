import {certifiedSqrtNumber} from './certified-sqrt.js';

/**
 * Finite x87 extended values with selectable arithmetic precision control,
 * round-to-nearest/ties-to-even. Loads and transcendental results retain m80.
 * Value = sign * mantissa * 2^exponent; normal mantissas have 64 bits.
 * This models values and rounding, not x87 exception/status flags or traps.
 */
const EXTENDED_MIN_UNIT = -16445;
const EXTENDED_MAX_TOP = 16383;
const INTEGER_BIT = 1n << 63n;
const DOUBLE_INTEGER_BIT = 1n << 52n;
const PRECISION_LIMITS = {24:1n << 24n,53:1n << 53n,64:1n << 64n};
const BINARY64_VALUE = Symbol('exact binary64 Float80');
const ROUNDED_EXTENDED_VALUE = Symbol('rounded extended Float80');
const MIN_NORMAL_BINARY64 = 2 ** -1022;
const SIGNED64_LIMIT = 2 ** 63;
const SMALL_INTEGER_LIMIT = 4096;
const UNIT_FIXED112_LIMIT=1n<<114n;
const smallIntegers = new Array(2 * SMALL_INTEGER_LIMIT + 1);
let negativeZeroValue;
// Only lazy m80 materialization uses this view. Arithmetic on binary64-backed
// values neither allocates a view nor extracts a BigInt significand.
const binary64View = new DataView(new ArrayBuffer(8));
let controlWord=0x037f;
let arithmeticPrecision=64;

export const getX87ControlWord=()=>controlWord;
export function setX87ControlWord(value){
  if(!Number.isInteger(value)||value<0||value>0xffff||(value&0xc00)!==0)throw new RangeError('Only nearest/even x87 rounding is supported');
  const bits=value&0x300;
  const precision=bits===0?24:bits===0x200?53:bits===0x300?64:undefined;
  if(!precision)throw new RangeError('Reserved x87 precision-control encoding');
  controlWord=value;arithmeticPrecision=precision;
}
/** Synchronous instruction scope; restore precision even when the call fails. */
export function withX87ControlWord(value,callback){
  const previous=controlWord;setX87ControlWord(value);
  try{const result=callback();if(result&&typeof result.then==='function')throw new TypeError('x87 instruction scope must be synchronous');return result;}
  finally{setX87ControlWord(previous);}
}

function bitLength(value) { return value === 0n ? 0 : value.toString(2).length; }

function roundRight(value, places, length) {
  if (places <= 0) return value << BigInt(-places);
  // A shift beyond all significant bits cannot reach a half-way case.
  length ??= bitLength(value);
  if (places > length) return 0n;
  const shift = BigInt(places);
  const quotient = value >> shift;
  const remainder = value - (quotient << shift);
  const halfway = 1n << (shift - 1n);
  return quotient + (remainder > halfway || (remainder === halfway && (quotient & 1n)) ? 1n : 0n);
}

function roundedParts(mantissa, exponent, precision, minimumUnit) {
  if (mantissa === 0n) return { mantissa: 0n, exponent: 0 };
  const length = bitLength(mantissa);
  const targetExponent = Math.max(exponent + length - precision, minimumUnit);
  let rounded = roundRight(mantissa, targetExponent - exponent, length);
  let roundedExponent = targetExponent;
  if (rounded >= PRECISION_LIMITS[precision]) {
    rounded >>= 1n;
    roundedExponent++;
  }
  return rounded === 0n ? { mantissa: 0n, exponent: 0 } : { mantissa: rounded, exponent: roundedExponent };
}

function normalized(mantissa, exponent) {
  const result = roundedParts(mantissa, exponent, 64, EXTENDED_MIN_UNIT);
  // roundedParts produces exactly 64 bits unless the result is a subnormal
  // at EXTENDED_MIN_UNIT. Those shorter significands cannot overflow.
  if (result.mantissa !== 0n && result.exponent > EXTENDED_MAX_TOP - 63) {
    throw new RangeError('Float80 overflow: infinite results are not supported');
  }
  return result;
}

function arithmeticResult(sign,mantissa,exponent){
  const parts=roundedParts(mantissa,exponent,arithmeticPrecision,EXTENDED_MIN_UNIT+64-arithmeticPrecision);
  return roundedArithmeticValue(sign,parts.mantissa,parts.exponent);
}

function roundedArithmeticValue(sign,mantissa,exponent){
  if(mantissa===0n)return binary64Value(sign<0?-0:0);
  // Callers have already rounded to the selected precision. At PC53 the
  // significand is at most 53 bits (or an exact 2^53 carry), so normal binary64
  // values need no second normalization or BigInt-backed construction.
  if(arithmeticPrecision===53&&exponent>=-1074&&exponent<=971){
    const value=sign*Number(mantissa)*2**exponent;
    if(normalBinary64(value))return binary64Value(value);
  }
  return new Float80(sign,mantissa,exponent);
}

function integer(value) {
  if (typeof value === 'bigint') return value;
  if (typeof value !== 'number' || !Number.isSafeInteger(value)) {
    throw new TypeError('Float80 integer input must be a BigInt or safe integer Number');
  }
  return BigInt(value);
}

function operand(value) {
  if (!(value instanceof Float80)) throw new TypeError('Float80 arithmetic requires a Float80 operand');
  return value;
}

/** Exact value key; signed zero and all retained m80 significand bits matter. */
export function float80Key(value) {
  operand(value);
  return value.exactKey();
}

function normalBinary64(value) {
  return Number.isFinite(value) && Math.abs(value) >= MIN_NORMAL_BINARY64;
}

// PC53 mixed products need the retained eleven m80 bits too. Splitting at
// bit11 gives an exact binary64 high component and an exact eleven-bit tail.
// TwoProd retains the complete high product. Tail/correction roundings have
// error <256u^2*product; certify strictly inside the candidate's IEEE cell.
// Bounds keep every split/product normal. Uncertain midpoints use BigInt.
// These private normalized parts belong to immutable Float80 values. Cache
// their factor-independent dyadic split; unlike product memoization this adds
// only one small record per retained input and does not keep dead inputs alive.
const mixedSplitCache=new WeakMap();
function mixedBinary64Product(parts,value){
  if(parts.exponent<-163||parts.exponent>36||Math.abs(value)<2**-100||Math.abs(value)>2**100)return NaN;
  let split=mixedSplitCache.get(parts);
  if(!split){
    const high=Number(parts.mantissa>>11n)*2**(parts.exponent+11);
    const tail=Number(parts.mantissa&2047n)*2**parts.exponent;
    const splitHigh=134217729*high,ah=splitHigh-(splitHigh-high),al=high-ah;
    split={high,tail,ah,al};mixedSplitCache.set(parts,split);
  }
  const {high,tail,ah,al}=split;
  const factor=Math.abs(value),product=high*factor;
  const splitFactor=134217729*factor,bh=splitFactor-(splitFactor-factor),bl=factor-bh;
  const error=((ah*bh-product)+ah*bl+al*bh)+al*bl;
  const correction=error+tail*factor,candidate=product+correction;
  const distance=(product-candidate)+correction;
  const margin=product*2**-97;
  binary64View.setFloat64(0,candidate,true);
  const upper=binary64View.getUint32(4,true),lower=binary64View.getUint32(0,true);
  const gap=2**(((upper>>>20)&0x7ff)-1023-52);
  const halfBelow=(lower===0&&(upper&0xfffff)===0)?gap/4:gap/2;
  // Two margins also cover rounding these boundary subtractions. An exact
  // tie is deliberately ambiguous, including the asymmetric power-of-two cell.
  return distance>-halfBelow+margin&&distance<gap/2-margin?candidate:NaN;
}

function binary64Value(value) {
  // Common integer operands use bounded direct slots. Continuously changing
  // geometry avoids a Map lookup/insertion/eviction on every arithmetic step.
  // Every shared value is immutable, including its lazy parts.
  if (Number.isInteger(value)) {
    if (Object.is(value, -0)) return negativeZeroValue ??= new Float80(BINARY64_VALUE, value);
    if (value >= -SMALL_INTEGER_LIMIT && value <= SMALL_INTEGER_LIMIT) {
      const index = value + SMALL_INTEGER_LIMIT;
      return smallIntegers[index] ??= new Float80(BINARY64_VALUE, value);
    }
  }
  return new Float80(BINARY64_VALUE, value);
}

function binary64Parts(value) {
  if (value === 0) return { mantissa: 0n, exponent: 0 };
  binary64View.setFloat64(0, value, true);
  const low = binary64View.getUint32(0, true);
  const high = binary64View.getUint32(4, true);
  const biasedExponent = (high >>> 20) & 0x7ff;
  const fraction = (BigInt(high & 0xfffff) << 32n) | BigInt(low);
  if (biasedExponent !== 0) {
    return { mantissa: (DOUBLE_INTEGER_BIT | fraction) << 11n, exponent: biasedExponent - 1023 - 63 };
  }
  const shift = 64 - bitLength(fraction);
  return { mantissa: fraction << BigInt(shift), exponent: -1074 - shift };
}

function exactBinary64Number(sign, parts) {
  if (parts.mantissa === 0n) return sign < 0 ? -0 : 0;
  // Normalized m80 values have 64 significand bits. Requiring the low eleven
  // bits to be zero proves that no precision is lost. Keep subnormal stores
  // and the extended exponent range on the exact arithmetic path.
  if (parts.exponent >= -1085 && parts.exponent <= 960 && (parts.mantissa & 2047n) === 0n) {
    return sign * Number(parts.mantissa >> 11n) * 2 ** (parts.exponent + 11);
  }
  return NaN;
}

function floorLogRatio(numerator, denominator) {
  let power = bitLength(numerator) - bitLength(denominator);
  if (power >= 0 ? numerator < (denominator << BigInt(power)) : (numerator << BigInt(-power)) < denominator) power--;
  return power;
}

function roundQuotient(numerator, denominator) {
  const quotient = numerator / denominator;
  const remainder = numerator % denominator;
  const twice = remainder * 2n;
  return quotient + (twice > denominator || (twice === denominator && (quotient & 1n)) ? 1n : 0n);
}

function integerSqrt(value) {
  if (value < 2n) return value;
  let current = 1n << BigInt(Math.ceil(bitLength(value) / 2));
  for (;;) {
    const next = (current + value / current) >> 1n;
    if (next >= current) return current;
    current = next;
  }
}

export class Float80 {
  #number;
  #parts;

  /** Construct from an exact finite sign/magnitude binary value, rounding once. */
  constructor(sign, mantissa, exponent) {
    if (sign === ROUNDED_EXTENDED_VALUE) {
      this.sign = mantissa.sign;
      this.#parts = mantissa.parts;
      this.#number = exactBinary64Number(this.sign, this.#parts);
      Object.freeze(this);
      return;
    }
    if (sign === BINARY64_VALUE) {
      this.sign = mantissa < 0 || Object.is(mantissa, -0) ? -1 : 1;
      this.#number = mantissa;
      this.#parts = null;
      Object.freeze(this);
      return;
    }
    if (sign !== 1 && sign !== -1) throw new TypeError('Float80 sign must be +1 or -1');
    if (typeof mantissa !== 'bigint' || mantissa < 0n) throw new TypeError('Float80 mantissa must be a nonnegative BigInt');
    if (!Number.isSafeInteger(exponent) || !Number.isSafeInteger(exponent + bitLength(mantissa))) {
      throw new RangeError('Float80 exponent must be a safe integer');
    }
    const parts = normalized(mantissa, exponent);
    this.sign = sign;
    this.#number = exactBinary64Number(sign, parts);
    this.#parts = parts;
    Object.freeze(this);
  }

  #materialized() {
    return this.#parts ??= binary64Parts(this.#number);
  }

  get mantissa() { return this.#materialized().mantissa; }
  get exponent() { return this.#materialized().exponent; }

  /** Avoid materializing exact binary64-backed values just to identify them. */
  exactKey() {
    return Number.isNaN(this.#number)
      ? `e:${this.sign}/${this.mantissa}/${this.exponent}`
      : `n:${this.sign}/${this.#number}`;
  }

  /** Exact binary64 carrier, or NaN when a store would change this m80 value. */
  exactNumber() { return this.#number; }

  /** Load an exact IEEE binary64 value; NaN and infinities are unsupported. */
  static fromNumber(value) {
    if (typeof value !== 'number') throw new TypeError('Float80 Number input must be a Number');
    if (!Number.isFinite(value)) throw new RangeError('Float80 does not support NaN or infinite inputs');
    return binary64Value(value);
  }

  static fromInteger(value) {
    if (typeof value === 'number') {
      if (!Number.isSafeInteger(value)) throw new TypeError('Float80 integer input must be a BigInt or safe integer Number');
      return binary64Value(value === 0 ? 0 : value);
    }
    const exact = integer(value);
    if (exact >= -9007199254740991n && exact <= 9007199254740991n) return binary64Value(Number(exact));
    return new Float80(exact < 0n ? -1 : 1, exact < 0n ? -exact : exact, 0);
  }

  /** Return the common m80 rounding of a finite signed fixed-point interval. */
  static certifyInterval(lower, upper, exponent) {
    if (typeof lower !== 'bigint' || typeof upper !== 'bigint' || lower > upper) throw new TypeError('Float80 interval requires ordered BigInt endpoints');
    if (!Number.isSafeInteger(exponent)) throw new RangeError('Float80 exponent must be a safe integer');
    const lowerSign = lower < 0n ? -1 : 1, upperSign = upper < 0n ? -1 : 1;
    // Crossing zero cannot certify a common signed result.
    if (lowerSign !== upperSign) return null;
    const lowMagnitude = lower < 0n ? -lower : lower, highMagnitude = upper < 0n ? -upper : upper;
    if(exponent===-112&&lowMagnitude<UNIT_FIXED112_LIMIT&&highMagnitude<UNIT_FIXED112_LIMIT){
      // Bounded transcendental enclosures are normal m80 values. Round their
      // smaller magnitude once, then compare the larger magnitude with the
      // exact upper midpoint of that rounding cell, including ties-to-even.
      const minimum=lowMagnitude<highMagnitude?lowMagnitude:highMagnitude;
      const maximum=lowMagnitude<highMagnitude?highMagnitude:lowMagnitude;
      if(minimum===0n)return maximum===0n?new Float80(ROUNDED_EXTENDED_VALUE,{sign:lowerSign,parts:{mantissa:0n,exponent:0}}):null;
      const parts=normalized(minimum,exponent);
      const midpoint=parts.mantissa*2n+1n,shift=parts.exponent-1-exponent;
      const bound=shift>=0?midpoint<<BigInt(shift):midpoint;
      const value=shift>=0?maximum:maximum<<BigInt(-shift);
      if(value>bound||(value===bound&&(parts.mantissa&1n)!==0n))return null;
      return new Float80(ROUNDED_EXTENDED_VALUE,{sign:lowerSign,parts});
    }
    if (!Number.isSafeInteger(exponent + bitLength(lowMagnitude)) || !Number.isSafeInteger(exponent + bitLength(highMagnitude))) throw new RangeError('Float80 exponent must be a safe integer');
    const low = normalized(lowMagnitude, exponent), high = normalized(highMagnitude, exponent);
    if (low.mantissa !== high.mantissa || low.exponent !== high.exponent) return null;
    // Both endpoints have already passed exactly the public constructor's
    // rounding and range checks. Avoid normalizing and allocating them again.
    return new Float80(ROUNDED_EXTENDED_VALUE, {sign:lowerSign,parts:low});
  }

  /**
   * Load an m80real image (10 little-endian bytes). Pseudo-denormals are
   * accepted and canonicalized to the equivalent normal VALUE. This does not
   * preserve a pseudo-denormal input's noncanonical storage representation.
   * Unnormal/NaN/infinite encodings
   * require unsupported x87 invalid-operation semantics and throw explicitly.
   */
  static fromBytes(bytes) {
    if (!(bytes instanceof Uint8Array) || bytes.byteLength !== 10) throw new TypeError('Float80 m80 input must be a 10-byte Uint8Array');
    const view = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
    const mantissa = view.getBigUint64(0, true);
    const signExponent = view.getUint16(8, true);
    const sign = signExponent & 0x8000 ? -1 : 1;
    const biasedExponent = signExponent & 0x7fff;
    if (biasedExponent === 0x7fff) throw new RangeError('Float80 does not support NaN or infinite m80 inputs');
    if (biasedExponent !== 0 && !(mantissa & INTEGER_BIT)) throw new RangeError('Float80 does not support unnormal m80 encodings');
    return new Float80(sign, mantissa, (biasedExponent || 1) - 16383 - 63);
  }

  toBytes() {
    const bytes = new Uint8Array(10);
    const view = new DataView(bytes.buffer);
    view.setBigUint64(0, this.mantissa, true);
    const biasedExponent = this.mantissa < INTEGER_BIT ? 0 : this.exponent + 63 + 16383;
    view.setUint16(8, biasedExponent | (this.sign < 0 ? 0x8000 : 0), true);
    return bytes;
  }

  /** One binary64 store conversion, without an intermediate Number rounding. */
  toNumber() {
    if (!Number.isNaN(this.#number)) return this.#number;
    const parts = roundedParts(this.mantissa, this.exponent, 53, -1074);
    if(parts.mantissa===0n)return this.sign<0?-0:0;
    // The store has already rounded to <=53 bits and a unit >=2^-1074.
    // Its integer significand and power of two are exact binary64 values;
    // their product is the final image (or the required infinity). No bits
    // need to be packed into a temporary buffer.
    return this.sign*Number(parts.mantissa)*2**parts.exponent;
  }

  /** One binary64 spill/reload; an already exact binary64 value is unchanged. */
  storeBinary64() {
    return Number.isNaN(this.#number) ? Float80.fromNumber(this.toNumber()) : this;
  }

  negate() {
    return Number.isNaN(this.#number)
      ? new Float80(-this.sign, this.mantissa, this.exponent)
      : binary64Value(-this.#number);
  }

  add(other) {
    operand(other);
    if (arithmeticPrecision === 53 && !Number.isNaN(this.#number) && !Number.isNaN(other.#number)) {
      if (other.#number === 0 && this.#number !== 0) return this;
      if (this.#number === 0 && other.#number !== 0) return other;
      const sum = this.#number + other.#number;
      if (normalBinary64(sum) || (sum === 0 && this.#number === -other.#number)) return binary64Value(sum);
    }
    if (this.mantissa === 0n && other.mantissa === 0n) {
      return new Float80(this.sign < 0 && other.sign < 0 ? -1 : 1, 0n, 0);
    }
    const exponent = Math.min(this.exponent, other.exponent);
    const left = BigInt(this.sign) * (this.mantissa << BigInt(this.exponent - exponent));
    const right = BigInt(other.sign) * (other.mantissa << BigInt(other.exponent - exponent));
    const sum = left + right;
    return arithmeticResult(sum < 0n ? -1 : 1, sum < 0n ? -sum : sum, exponent);
  }

  subtract(other) {
    operand(other);
    if (arithmeticPrecision === 53 && !Number.isNaN(this.#number) && !Number.isNaN(other.#number)) {
      if (other.#number === 0 && this.#number !== 0) return this;
      const difference = this.#number - other.#number;
      if (normalBinary64(difference) || (difference === 0 && this.#number === other.#number)) return binary64Value(difference);
    }
    return this.add(other.negate());
  }

  multiply(other) {
    operand(other);
    if (arithmeticPrecision === 53 && !Number.isNaN(this.#number) && !Number.isNaN(other.#number)) {
      if (other.#number === 1) return this;
      if (this.#number === 1) return other;
      const product = this.#number * other.#number;
      if (normalBinary64(product) || this.#number === 0 || other.#number === 0) return binary64Value(product);
    }
    if(arithmeticPrecision===53){
      const leftNumber=!Number.isNaN(this.#number),rightNumber=!Number.isNaN(other.#number);
      if(leftNumber!==rightNumber){
        const extended=leftNumber?other:this,value=leftNumber?this.#number:other.#number;
        const product=mixedBinary64Product(extended.#parts,value);
        if(!Number.isNaN(product))return binary64Value(this.sign*other.sign*product);
      }
    }
    return arithmeticResult(this.sign * other.sign, this.mantissa * other.mantissa, this.exponent + other.exponent);
  }

  /** Multiply an exact binary64 load without allocating its operand carrier. */
  multiplyNumber(value){
    if(typeof value!=='number'||!Number.isFinite(value))return this.multiply(Float80.fromNumber(value));
    if(arithmeticPrecision===53){
      if(!Number.isNaN(this.#number)){
        const product=this.#number*value;
        if(normalBinary64(product)||this.#number===0||value===0)return binary64Value(product);
      }else{
        const product=mixedBinary64Product(this.#parts,value);
        if(!Number.isNaN(product))return binary64Value(this.sign*(value<0?-product:product));
      }
    }
    return this.multiply(Float80.fromNumber(value));
  }

  /** Internal floating evaluator result: exact binary64 Number or Float80.
   * Reuse the public mixed-product certificate without allocating a carrier
   * that the evaluator would immediately unbox. Extended fallback is unchanged.
   */
  multiplyNumberUnboxed(value){
    if(typeof value!=='number'||!Number.isFinite(value))return this.multiply(Float80.fromNumber(value));
    if(arithmeticPrecision===53){
      if(!Number.isNaN(this.#number)){
        const product=this.#number*value;
        if(normalBinary64(product)||this.#number===0||value===0)return product;
      }else{
        const product=mixedBinary64Product(this.#parts,value);
        if(!Number.isNaN(product))return this.sign*(value<0?-product:product);
      }
    }
    return this.multiply(Float80.fromNumber(value));
  }

  divide(other) {
    operand(other);
    if (arithmeticPrecision === 53 && !Number.isNaN(this.#number) && !Number.isNaN(other.#number)) {
      if (other.#number === 0) throw new RangeError('Float80 division by zero requires unsupported x87 exception semantics');
      if (other.#number === 1) return this;
      const quotient = this.#number / other.#number;
      if (normalBinary64(quotient) || this.#number === 0) return binary64Value(quotient);
    }
    if (other.mantissa === 0n) throw new RangeError('Float80 division by zero requires unsupported x87 exception semantics');
    if (this.mantissa === 0n) return new Float80(this.sign * other.sign, 0n, 0);
    const baseExponent = this.exponent - other.exponent;
    const top = baseExponent + floorLogRatio(this.mantissa, other.mantissa);
    const outputExponent = Math.max(top - arithmeticPrecision+1, EXTENDED_MIN_UNIT+64-arithmeticPrecision);
    const shift = baseExponent - outputExponent;
    const numerator = shift >= 0 ? this.mantissa << BigInt(shift) : this.mantissa;
    const denominator = shift < 0 ? other.mantissa << BigInt(-shift) : other.mantissa;
    return roundedArithmeticValue(this.sign * other.sign, roundQuotient(numerator, denominator), outputExponent);
  }

  sqrt() {
    if (this.#number === 0) return this;
    if (this.sign < 0) throw new RangeError('Float80 negative square root requires unsupported x87 exception semantics');
    const binary64Input = !Number.isNaN(this.#number);
    let candidate;
    if (arithmeticPrecision === 53 && binary64Input) {
      const certified=certifiedSqrtNumber(this.#number);
      if(certified!==undefined)return binary64Value(certified);
      try { candidate = Math.sqrt(this.#number); } catch { /* Use exact integer sqrt below. */ }
      // Integer products through 2^52 are exact binary64 operations, so an
      // integer root no larger than 2^26 can be certified before m80 decoding.
      if (Number.isInteger(candidate) && candidate > 0 && candidate <= 2 ** 26
          && candidate * candidate === this.#number) return binary64Value(candidate);
    }
    const top = this.exponent + (binary64Input ? 63 : bitLength(this.mantissa) - 1);
    const outputExponent = Math.max(Math.floor(top / 2) - arithmeticPrecision+1, EXTENDED_MIN_UNIT+64-arithmeticPrecision);
    const shift = this.exponent - 2 * outputExponent;
    const numerator = shift >= 0 ? this.mantissa << BigInt(shift) : this.mantissa;
    const denominator = shift < 0 ? 1n << BigInt(-shift) : 1n;
    if (arithmeticPrecision === 53 && binary64Input) {
      // Math.sqrt supplies a candidate only. Exact squared midpoint comparisons
      // certify the same nearest/even root as the integer algorithm below.
      // For finite binary64 input the m80 significand has 64 bits and shift is
      // 41 or 42, so there is no denominator or extended underflow here.
      const candidateUnits = normalBinary64(candidate) ? candidate / 2 ** outputExponent : NaN;
      if (Number.isInteger(candidateUnits) && candidateUnits >= 2 ** 52 && candidateUnits <= 2 ** 53) {
        const root = BigInt(candidateUnits);
        const center = (root * root) << 2n;
        const delta = root << 2n;
        const lower = center - delta + 1n, upper = center + delta + 1n;
        const exact = numerator << 2n;
        if ((exact > lower && exact < upper)
            || ((exact === lower || exact === upper) && (root & 1n) === 0n)) {
          return binary64Value(candidate);
        }
      }
    }
    let root = integerSqrt(numerator / denominator);
    const left = 4n * numerator;
    const halfway = denominator * (4n * root * root + 4n * root + 1n);
    if (left > halfway || (left === halfway && (root & 1n))) root++;
    return roundedArithmeticValue(1, root, outputExponent);
  }

  /** Numeric ordering; positive and negative zero compare equal. */
  compare(other) {
    operand(other);
    if (!Number.isNaN(this.#number) && !Number.isNaN(other.#number)) {
      return this.#number === other.#number ? 0 : this.#number < other.#number ? -1 : 1;
    }
    if (this.mantissa === 0n && other.mantissa === 0n) return 0;
    if (this.sign !== other.sign) return this.sign < other.sign ? -1 : 1;
    const exponent = Math.min(this.exponent, other.exponent);
    const left = this.mantissa << BigInt(this.exponent - exponent);
    const right = other.mantissa << BigInt(other.exponent - exponent);
    return left === right ? 0 : (left < right ? -1 : 1) * this.sign;
  }

  /** Signed-64 truncation used by the original CRT __ftol helper. */
  truncI64() {
    if (!Number.isNaN(this.#number)) {
      const result = Math.trunc(this.#number);
      if (result < -SIGNED64_LIMIT || result >= SIGNED64_LIMIT) throw new RangeError('Float80 truncation is outside representable signed int64');
      return BigInt(result);
    }
    const magnitude = this.exponent >= 0
      ? this.mantissa << BigInt(this.exponent) : this.mantissa >> BigInt(-this.exponent);
    const result = this.sign < 0 ? -magnitude : magnitude;
    if (result < -(1n << 63n) || result > (1n << 63n) - 1n) throw new RangeError('Float80 truncation is outside representable signed int64');
    return result;
  }

  /** Original __ftol returns low 32 bits after signed-64 truncation. */
  truncI32() {
    if (!Number.isNaN(this.#number)) {
      const result = Math.trunc(this.#number);
      if (result < -SIGNED64_LIMIT || result >= SIGNED64_LIMIT) throw new RangeError('Float80 truncation is outside representable signed int64');
      return result | 0;
    }
    return Number(BigInt.asIntN(32, this.truncI64()));
  }
}
