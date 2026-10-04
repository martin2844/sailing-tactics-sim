import { Float80, float80Key, getX87ControlWord } from './float80.js';
import { PI_FIXED as PI, FIXED_PRECISION as PRECISION, FIXED_SCALE as SCALE, certifyFixed112 } from './atan.js';
import {dd,ddAdd,ddSub,ddNeg,ddMul,ddFromFixed,ddToFixed} from './double-double.js';

const SIN_COS_CACHE_LIMIT = 2048;
const sinCosCache = new Map();
const sinCosKeys=new Array(SIN_COS_CACHE_LIMIT);
let nextSinCosKey=0;
const numberSinCosCache=new Map(),numberSinCosKeys=new Array(SIN_COS_CACHE_LIMIT);
let numberSinCosWord,nextNumberSinCosKey=0;
const PRECISION_SHIFT = BigInt(PRECISION);
// Preserve the truncation toward zero of division by the positive 2^224 scale.
const scaleDown = value => value < 0n ? -((-value) >> PRECISION_SHIFT) : value >> PRECISION_SHIFT;
const FAST_SHIFT = 112n;
const FAST_SCALE = 1n << FAST_SHIFT;
const QUICK_SHIFT = 80n;
const QUICK_SCALE = 1n << QUICK_SHIFT;
const fastScaleDown = (value,shift=FAST_SHIFT) => value < 0n ? -((-value) >> shift) : value >> shift;
const sineDivisors=Array.from({length:64},(_,index)=>BigInt((index+1)*2*((index+1)*2+1)));
const cosineDivisors=Array.from({length:64},(_,index)=>BigInt(((index+1)*2-1)*(index+1)*2));
const factorials=[1n];
for(let index=1;index<28;index++)factorials.push(factorials[index-1]*BigInt(index));
const quickSineCoefficients=Array.from({length:12},(_,index)=>(index&1?-1n:1n)*(QUICK_SCALE/factorials[index*2+1]));
const quickCosineCoefficients=Array.from({length:12},(_,index)=>(index&1?-1n:1n)*(QUICK_SCALE/factorials[index*2]));
const ddSineCoefficients=Array.from({length:6},(_,index)=>ddFromFixed((index&1?-1n:1n)*(SCALE/factorials[index*2+1]),PRECISION));
const ddCosineCoefficients=Array.from({length:6},(_,index)=>ddFromFixed((index&1?-1n:1n)*(SCALE/factorials[index*2]),PRECISION));
const ddSinCosAnchors=Array.from({length:53},(_,index)=>{
  const angle=BigInt(index)*SCALE/64n,squared=angle*angle/SCALE;
  let sine=angle,cosine=SCALE,sineTerm=angle,cosineTerm=SCALE;
  for(let index=0;index<64;index++){
    sineTerm=-sineTerm*squared/SCALE/sineDivisors[index];
    cosineTerm=-cosineTerm*squared/SCALE/cosineDivisors[index];
    sine+=sineTerm;cosine+=cosineTerm;
    if(sineTerm===0n&&cosineTerm===0n)return{ sine:ddFromFixed(sine,PRECISION),cosine:ddFromFixed(cosine,PRECISION) };
  }
  throw new Error('Bounded sine/cosine anchor series did not terminate');
});
const DD_ERROR=1n<<24n;

function doubleSinCos(reduced,quadrant){
  return doubleSinCosAngle(ddFromFixed(reduced,PRECISION),quadrant);
}

function doubleSinCosAngle(angle,quadrant){
  if(Math.abs(angle[0])<2**-24||Math.abs(angle[0])>.8)return null;
  const index=Math.round(Math.abs(angle[0])*64),negative=angle[0]<0;
  const residual=ddSub(angle,dd((negative?-index:index)/64));
  if(Math.abs(residual[0])>.008)return null;
  const squared=ddMul(residual,residual);
  let sine=ddSineCoefficients[5],cosine=ddCosineCoefficients[5];
  for(let index=4;index>=0;index--){
    sine=ddAdd(ddSineCoefficients[index],ddMul(sine,squared));
    cosine=ddAdd(ddCosineCoefficients[index],ddMul(cosine,squared));
  }
  sine=ddMul(sine,residual);
  const anchor=ddSinCosAnchors[index],anchorSine=negative?ddNeg(anchor.sine):anchor.sine;
  const combinedSine=ddAdd(ddMul(anchorSine,cosine),ddMul(anchor.cosine,sine));
  cosine=ddSub(ddMul(anchor.cosine,cosine),ddMul(anchorSine,sine));
  sine=combinedSine;
  // Exact224-bit dyadic anchors leave a residual <=.008. The degree10
  // cosine and degree11 sine remainders are below 2^-112. The
  // conservative candidate enclosure includes both truncation and arithmetic.
  // Certification, not the double-double approximation, decides acceptance.
  const wrapped=typeof quadrant==='number'?(quadrant%4+4)%4:Number((quadrant%4n+4n)%4n);
  let s=ddToFixed(sine,112),c=ddToFixed(cosine,112);
  if(wrapped===1)[s,c]=[c,-s];
  else if(wrapped===2){s=-s;c=-c;}
  else if(wrapped===3)[s,c]=[-c,s];
  const certifiedSine=Float80.certifyInterval(s-DD_ERROR,s+DD_ERROR,-112);
  const certifiedCosine=Float80.certifyInterval(c-DD_ERROR,c+DD_ERROR,-112);
  return certifiedSine&&certifiedCosine?{sine:certifiedSine,cosine:certifiedCosine}:null;
}

function quickSinCos(reduced,quadrant){
  const shift=PRECISION_SHIFT-QUICK_SHIFT;
  const angle=reduced<0n?-((-reduced)>>shift):reduced>>shift;
  if(angle<=-QUICK_SCALE||angle>=QUICK_SCALE)return null;
  const squared=(angle*angle)>>QUICK_SHIFT;
  let sine=quickSineCoefficients[11],cosine=quickCosineCoefficients[11];
  // For |angle|<1 the degree-23/22 Taylor remainders are <S/25!<1
  // and <S/24!<2 units at S=2^80. Each coefficient loses <1 unit.
  // A Horner intermediate has magnitude <2S, so the squared-input error
  // contributes <2 units per step; coefficient and product truncation add
  // <2 more. Eleven steps plus the final sine product and angle truncation
  // stay below 50 units. The original 224-bit error adds <1 fast unit.
  // The same conservative 1024-unit interval therefore certifies m80.
  for(let index=10;index>=0;index--){
    sine=quickSineCoefficients[index]+fastScaleDown(sine*squared,QUICK_SHIFT);
    cosine=quickCosineCoefficients[index]+fastScaleDown(cosine*squared,QUICK_SHIFT);
  }
  sine=fastScaleDown(sine*angle,QUICK_SHIFT);
  const wrapped=Number((quadrant%4n+4n)%4n);
  if(wrapped===1)[sine,cosine]=[cosine,-sine];
  else if(wrapped===2){sine=-sine;cosine=-cosine;}
  else if(wrapped===3)[sine,cosine]=[-cosine,sine];
  const certifiedSine=Float80.certifyInterval(sine-1024n,sine+1024n,-80);
  const certifiedCosine=Float80.certifyInterval(cosine-1024n,cosine+1024n,-80);
  return certifiedSine&&certifiedCosine?{sine:certifiedSine,cosine:certifiedCosine}:null;
}

function fastSinCos(reduced, quadrant,precision=FAST_SHIFT,scale=FAST_SCALE) {
  const shift = PRECISION_SHIFT - precision;
  const angle = reduced < 0n ? -((-reduced) >> shift) : reduced >> shift;
  if (angle <= -scale || angle >= scale) return null;
  const squared = (angle * angle) >> precision;
  let sine = angle, cosine = scale, sineTerm = angle, cosineTerm = scale;
  /*
   * Exact 224-bit x87 reduction precedes this candidate. |angle/scale|<1:
   * each Taylor term is bounded by scale/(2n)! and vanishes before n=64
   * at all three precisions (80/112/224; 128!>2^224). Squared-input and successive term
   * truncations add <2 units per step, with contraction≤1/2, so each term
   * differs from the mathematical term by <4 units. Summation plus the
   * first omitted alternating term is <4*64+4=260 units. Truncating the
   * reduced angle contributes <1 fast unit because |sin'|,|cos'|≤1.
   * The original 224-bit series has the same <260-unit bound at its own
   * scale. Hence the original integer lies within 262 fast units, below
   * the conservative ±1024-unit enclosure. Certify both m80 endpoints;
   * failed 80-bit certification retries at 112 bits, then the original series.
   */
  for (let index = 0; index < 64; index++) {
    sineTerm = -fastScaleDown(sineTerm * squared,precision) / sineDivisors[index];
    cosineTerm = -fastScaleDown(cosineTerm * squared,precision) / cosineDivisors[index];
    sine += sineTerm; cosine += cosineTerm;
    if (sineTerm === 0n && cosineTerm === 0n) {
      const wrapped = Number((quadrant % 4n + 4n) % 4n);
      const pairs = [[sine, cosine], [cosine, -sine], [-sine, -cosine], [-cosine, sine]];
      const certify = integer => precision===FAST_SHIFT?certifyFixed112(integer):Float80.certifyInterval(integer-1024n,integer+1024n,-Number(precision));
      const certifiedSine = certify(pairs[wrapped][0]);
      const certifiedCosine = certify(pairs[wrapped][1]);
      return certifiedSine && certifiedCosine ? { sine: certifiedSine, cosine: certifiedCosine } : null;
    }
  }
  return null;
}

function rememberSinCos(key, result) {
  if (sinCosCache.size >= SIN_COS_CACHE_LIMIT) sinCosCache.delete(sinCosKeys[nextSinCosKey]);
  sinCosKeys[nextSinCosKey]=key;nextSinCosKey=(nextSinCosKey+1)%SIN_COS_CACHE_LIMIT;
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
const x87HalfDD=ddFromFixed(0x3243f6a8885a308d3n,65);
const x87QuarterDD=[x87HalfDD[0]/2,x87HalfDD[1]/2];
const ddSign=value=>value[0]<0?-1:value[0]>0?1:value[1]<0?-1:value[1]>0?1:0;

function reduceNumberAngle(value){
  // A binary64 input in this range and the 66-bit half-pi constant have
  // dyadic support within [-66,21]. The quotient is at most20bits; its
  // product with the13-bit low component is exact binary64. Error-free
  // transforms therefore retain the whole reduction in two doubles.
  if(!Number.isFinite(value)||Math.abs(value)<.5||Math.abs(value)>2**20)return null;
  let quadrant=Math.round(value/x87HalfDD[0]);
  let reduced=ddSub(dd(value),ddMul(dd(quadrant),x87HalfDD));
  const below=ddSign(ddAdd(reduced,x87QuarterDD));
  const above=ddSign(ddSub(reduced,x87QuarterDD));
  // Match the original signed integer division at half-quadrant ties.
  if(below<0||(below===0&&value<0)){
    quadrant--;reduced=ddAdd(reduced,x87HalfDD);
  }else if(above>0||(above===0&&value>0)){
    quadrant++;reduced=ddSub(reduced,x87HalfDD);
  }
  if(ddSign(ddAdd(reduced,x87QuarterDD))<0||ddSign(ddSub(reduced,x87QuarterDD))>0)return null;
  return{angle:reduced,quadrant};
}

function directNumberSinCos(value){
  const reduced=reduceNumberAngle(value);
  return reduced?doubleSinCosAngle(reduced.angle,reduced.quadrant):null;
}

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
  const certified = doubleSinCos(reduced,quadrant) ?? quickSinCos(reduced, quadrant) ?? fastSinCos(reduced, quadrant);
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

/** Immutable internal pair for an exact binary64 load; no decimal cache key. */
export function sinCosX87Number(value){
  if(typeof value!=='number'||!Number.isFinite(value))return sinCosX87(Float80.fromNumber(value));
  // A Number Map merges signed zeros; neither zero is retained in this cache.
  if(value===0)return Object.freeze({sine:Float80.fromNumber(value),cosine:Float80.fromInteger(1)});
  const word=getX87ControlWord();
  if(numberSinCosWord!==word){numberSinCosCache.clear();numberSinCosKeys.fill(undefined);nextNumberSinCosKey=0;numberSinCosWord=word;}
  const cached=numberSinCosCache.get(value);
  if(cached)return cached;
  const pair=Object.freeze(directNumberSinCos(value)??sinCosX87(Float80.fromNumber(value)));
  if(numberSinCosCache.size>=SIN_COS_CACHE_LIMIT)numberSinCosCache.delete(numberSinCosKeys[nextNumberSinCosKey]);
  numberSinCosKeys[nextNumberSinCosKey]=value;nextNumberSinCosKey=(nextNumberSinCosKey+1)%SIN_COS_CACHE_LIMIT;
  numberSinCosCache.set(value,pair);
  return pair;
}
