import { Float80, float80Key, getX87ControlWord, withX87ControlWord } from './float80.js';
import {dd,ddAdd,ddSub,ddMul,ddDiv,ddFromFixed,ddToFixed} from './double-double.js';

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
const atanKeys=new Array(ATAN_CACHE_LIMIT);
let nextAtanKey=0;
const FAST_PRECISION = 112;
const FAST_SHIFT = BigInt(FAST_PRECISION);
const FAST_SCALE = 1n << FAST_SHIFT;
const FAST_ERROR = 1024n;
const QUICK_SHIFT = 80n;
const QUICK_SCALE = 1n << QUICK_SHIFT;

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
const QUICK_PI = PI >> (PRECISION_SHIFT - QUICK_SHIFT);

/**
 * Certify the original 224-bit result, rather than assuming fewer bits suffice.
 * Callers prove it lies within ±1024 units of their 112-bit integer. Monotonic
 * nearest/even m80 rounding makes identical endpoint results authoritative;
 * ambiguity, including an enclosure crossing zero, requires the 224-bit path.
 */
export function certifyFixed112(value) {
  return Float80.certifyInterval(value - FAST_ERROR, value + FAST_ERROR, -FAST_PRECISION);
}

const fastScaleDown = (value,shift=FAST_SHIFT) => value < 0n ? -((-value) >> shift) : value >> shift;
function fastSeries(value,scale=FAST_SCALE,shift=FAST_SHIFT) {
  if (value < -scale / 2n || value > scale / 2n) return null;
  const squared = fastScaleDown(value * value,shift);
  let power = value, sum = value;
  // For |value/scale|≤1/2, each power decreases by at least 1/4. Both the
  // 112-bit candidate and original 224-bit series terminate within 113 steps.
  for (let denominator = 3n, sign = -1n, iteration = 0; iteration < 113; denominator += 2n, sign = -sign, iteration++) {
    power = fastScaleDown(power * squared,shift);
    const term = power / denominator;
    if (term === 0n) return sum;
    sum += sign * term;
  }
  return null;
}

function fastAtanUnit(value,scale=FAST_SCALE,shift=FAST_SHIFT,pi=FAST_PI) {
  if (value > scale / 2n) {
    const result = fastSeries(((value - scale) * scale) / (value + scale),scale,shift);
    return result === null ? null : pi / 4n + result;
  }
  return fastSeries(value,scale,shift);
}

function atanUnit(value) {
  if (value > SCALE / 2n) return PI / 4n + series(((value - SCALE) * SCALE) / (value + SCALE));
  return series(value);
}

// Exact dyadic anchors, evaluated with the original 224-bit algorithm once.
// Nearest-anchor reduction leaves |r|<=1/128, so the 80-bit series needs at
// most seven terms. Its input ratio is formed as one exact integer quotient:
// (v/S-k/64)/(1+(v/S)*k/64), avoiding any rounded denominator product.
const ORIGINAL_ANCHORS=Array.from({length:65},(_,index)=>atanUnit(BigInt(index)*SCALE/64n));
const QUICK_ANCHORS=ORIGINAL_ANCHORS.map(value=>value>>(PRECISION_SHIFT-QUICK_SHIFT));
const DD_ANCHORS=ORIGINAL_ANCHORS.map(value=>ddFromFixed(value,PRECISION));
const DD_PI=ddFromFixed(PI,PRECISION);
const DD_HALF_PI=ddMul(DD_PI,dd(.5));
const DD_ATAN_COEFFICIENTS=Array.from({length:8},(_,index)=>ddFromFixed((index&1?-1n:1n)*SCALE/BigInt(index*2+1),PRECISION));
const DD_ERROR=1n<<24n;
function doubleAtan(small,large,inverted,negativeX,sign,numberRatio){
  const value=numberRatio??ddFromFixed((small*FAST_SCALE)/large,FAST_PRECISION);
  const index=Math.round(value[0]*64);
  if(index<0||index>64)return null;
  const anchor=dd(index/64);
  const residual=ddDiv(ddSub(value,anchor),ddAdd(dd(1),ddMul(value,anchor)));
  if(Math.abs(residual[0])>.008)return null;
  const squared=ddMul(residual,residual);
  let polynomial=DD_ATAN_COEFFICIENTS[7];
  for(let index=6;index>=0;index--)polynomial=ddAdd(DD_ATAN_COEFFICIENTS[index],ddMul(polynomial,squared));
  let result=ddAdd(DD_ANCHORS[index],ddMul(polynomial,residual));
  if(inverted)result=ddSub(DD_HALF_PI,result);
  if(negativeX)result=ddSub(DD_PI,result);
  const fixed=BigInt(sign)*ddToFixed(result,112);
  return Float80.certifyInterval(fixed-DD_ERROR,fixed+DD_ERROR,-112);
}
function quickAtanUnit(value) {
  const index=Number(((value<<6n)+(QUICK_SCALE>>1n))>>QUICK_SHIFT);
  if(index<0||index>64)return null;
  const anchor=BigInt(index);
  const residual=((value*64n-anchor*QUICK_SCALE)*QUICK_SCALE)/(QUICK_SCALE*64n+value*anchor);
  if(residual < -QUICK_SCALE/128n || residual > QUICK_SCALE/128n)return null;
  const correction=fastSeries(residual,QUICK_SCALE,QUICK_SHIFT);
  return correction===null?null:QUICK_ANCHORS[index]+correction;
}
const FAST_LEVELS=[[QUICK_SCALE,QUICK_SHIFT,QUICK_PI],[FAST_SCALE,FAST_SHIFT,FAST_PI]];

/** Finite mathematical atan2(y,x) with 224-bit intermediate accuracy. */
export function atan2Extended(y, x) {
  if (!(y instanceof Float80) || !(x instanceof Float80)) throw new TypeError('Extended atan2 requires Float80 operands');
  const key = `${getX87ControlWord()}/${float80Key(y)}/${float80Key(x)}`;
  const cached = atanCache.get(key);
  if (cached) return cached;
  const result = calculateAtan2(y, x);
  if (atanCache.size >= ATAN_CACHE_LIMIT) atanCache.delete(atanKeys[nextAtanKey]);
  atanKeys[nextAtanKey]=key;nextAtanKey=(nextAtanKey+1)%ATAN_CACHE_LIMIT;
  atanCache.set(key, result);
  return result;
}

/** Same exact calculation without retention for continuously changing points. */
export function atan2ExtendedUncached(y,x){
  if(!(y instanceof Float80)||!(x instanceof Float80))throw new TypeError('Extended atan2 requires Float80 operands');
  return calculateAtan2(y,x);
}

/** Exact binary64 inputs without temporary Float80 operands or cache keys. */
export function atan2ExtendedNumeric(y,x){
  if(typeof y==='number'&&typeof x==='number'){
    const absY=Math.abs(y),absX=Math.abs(x);
    if(absY>=2**-100&&absY<=2**100&&absX>=2**-100&&absX<=2**100){
      const inverted=absY>absX;
      const ratio=ddDiv(dd(inverted?absX:absY),dd(inverted?absY:absX));
      const certified=doubleAtan(0n,1n,inverted,x<0,y<0?-1:1,ratio);
      if(certified)return certified;
    }
  }
  // Preserve the left-to-right finite binary64 load failures and the original
  // zero, extreme-ratio and ambiguous-certificate calculations.
  return atan2ExtendedUncached(Float80.fromNumber(y),Float80.fromNumber(x));
}

// Cache immutable m80 results only after successful evaluation. Exceptions and
// the temporary PC64 instruction scope of the small-ratio path still propagate.
function calculateAtan2(y, x) {
  const numericY=y.exactNumber(),numericX=x.exactNumber();
  const absY=Math.abs(numericY),absX=Math.abs(numericX);
  // Exact binary64 loads already form double-double operands. Avoid extracting
  // and dividing BigInt significands for ordinary geometry; all split products
  // and quotient corrections remain normal in this bounded domain.
  if(absY>=2**-100&&absY<=2**100&&absX>=2**-100&&absX<=2**100){
    const inverted=absY>absX;
    const ratio=ddDiv(dd(inverted?absX:absY),dd(inverted?absY:absX));
    const certified=doubleAtan(0n,1n,inverted,x.sign<0,y.sign,ratio);
    if(certified)return certified;
  }
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
  const doubleResult=doubleAtan(small,large,inverted,x.sign<0,y.sign);
  if(doubleResult)return doubleResult;
  /*
   * The bound covers the ORIGINAL fixed-point algorithm as well as both fast
   * one. For |series input|≤1/2, squared-input truncation and each power
   * truncation give a power error <2 scale units (contraction≤1/4). Each
   * divided term then differs by <2 units. At most 113 terms plus the first
   * omitted alternating term give <229 units. Ratio quantization and the
   * atan transform contribute <3 more; all atan derivatives here are ≤1.
   * The original Machin PI has error <20*(229+1)=4600 ORIGINAL scale units.
   * Truncating PI to either 80 or 112 bits adds <1 fast unit; divisions add <6.
   * Thus the candidate-to-original difference is <240 fast units plus
   * 10000 original units (<1 unit at either fast scale), safely below 1024.
   * The 80-bit nearest dyadic anchor adds <1 unit for its stored table value
   * plus <1 unit for the exact residual quotient; the anchor's original
   * 224-bit error is <10000 original units. atan addition has derivative<=1.
   * These additional <3 fast units remain inside the 1024-unit bound.
   * Ambiguous 80-bit rounding retries at 112 bits, then retains the old path.
   */
  for (const [scale,shift,pi] of FAST_LEVELS) {
    const ratio=(small*scale)/large;
    let approximate = shift===QUICK_SHIFT?quickAtanUnit(ratio):fastAtanUnit(ratio,scale,shift,pi);
    if (approximate !== null) {
      if (inverted) approximate = pi / 2n - approximate;
      if (x.sign < 0) approximate = pi - approximate;
      const signed = BigInt(y.sign) * approximate;
      const certified = Float80.certifyInterval(signed-FAST_ERROR,signed+FAST_ERROR,-Number(shift));
      if (certified) return certified;
    }
  }
  let magnitude = atanUnit((small * SCALE) / large);
  if (inverted) magnitude = PI / 2n - magnitude;
  if (x.sign < 0) magnitude = PI - magnitude;
  return new Float80(y.sign, magnitude, -PRECISION);
}

export function atanExtended(value) {
  return atan2Extended(value, Float80.fromInteger(1));
}
