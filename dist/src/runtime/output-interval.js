import {atan2ExtendedNumeric,PI_FIXED,FIXED_PRECISION} from './atan.js';

// Bounds for private drawing intermediates. These operations model RN53
// arithmetic in the normal binary64 range; callers guard the original PC53
// context. Only certified final integers may escape this representation.
const minimumNormal=2**-1022;
const angleError=2**-40;
const pi=Number(PI_FIXED)/2**FIXED_PRECISION,halfPi=pi/2;
const atanAnchors=Array.from({length:65},(_,index)=>atan2ExtendedNumeric(index/64,1).toNumber());
const image=new DataView(new ArrayBuffer(8));
const valid=value=>value&&Number.isFinite(value[0])&&Number.isFinite(value[1])&&value[0]<=value[1];
const normal=value=>Number.isFinite(value)&&Math.abs(value)>=minimumNormal;

function adjacent(value,up){
  if(value===0)return up?Number.MIN_VALUE:-Number.MIN_VALUE;
  image.setFloat64(0,value,true);
  let low=image.getUint32(0,true),high=image.getUint32(4,true);
  if((value>0)===up){low=(low+1)>>>0;if(low===0)high++;}
  else{if(low===0)high--;low=(low-1)>>>0;}
  image.setUint32(0,low,true);image.setUint32(4,high,true);
  return image.getFloat64(0,true);
}
const enclose=(center,radius)=>[adjacent(center-radius,false),adjacent(center+radius,true)];
const add=(a,b)=>{const value=a+b;return normal(value)||(value===0&&a===-b)?value:undefined;};
const sub=(a,b)=>{const value=a-b;return normal(value)||(value===0&&a===b)?value:undefined;};
const mul=(a,b)=>{const value=a*b;return normal(value)||(value===0&&(a===0||b===0))?value:undefined;};
const div=(a,b)=>{const value=a/b;return normal(value)||(value===0&&a===0&&b!==0)?value:undefined;};

// RN53 is monotone. Applying the same correctly rounded operation to enclosing
// endpoints bounds the original result, including exact singleton arithmetic.
// A rounded zero from underflow or a subnormal endpoint requires the old path.
export function intervalAdd(a,b){
  if(!valid(a)||!valid(b))return undefined;
  const low=add(a[0],b[0]),high=add(a[1],b[1]);
  return low===undefined||high===undefined?undefined:[low,high];
}
export function intervalSub(a,b){
  if(!valid(a)||!valid(b))return undefined;
  const low=sub(a[0],b[1]),high=sub(a[1],b[0]);
  return low===undefined||high===undefined?undefined:[low,high];
}
export function intervalMul(a,b){
  if(!valid(a)||!valid(b))return undefined;
  const aSingleton=Object.is(a[0],a[1]),bSingleton=Object.is(b[0],b[1]);
  if(aSingleton||bSingleton){
    const p=mul(a[0],b[0]);
    if(p===undefined)return undefined;
    if(aSingleton&&bSingleton)return [p,p];
    const q=aSingleton?mul(a[0],b[1]):mul(a[1],b[0]);
    return q===undefined?undefined:[Math.min(p,q),Math.max(p,q)];
  }
  const p=mul(a[0],b[0]),q=mul(a[0],b[1]),r=mul(a[1],b[0]),s=mul(a[1],b[1]);
  return p===undefined||q===undefined||r===undefined||s===undefined?undefined:[Math.min(p,q,r,s),Math.max(p,q,r,s)];
}
export function intervalDiv(a,b){
  if(!valid(a)||!valid(b)||(b[0]<=0&&b[1]>=0))return undefined;
  const aSingleton=Object.is(a[0],a[1]),bSingleton=Object.is(b[0],b[1]);
  if(aSingleton||bSingleton){
    const p=div(a[0],b[0]);
    if(p===undefined)return undefined;
    if(aSingleton&&bSingleton)return [p,p];
    const q=aSingleton?div(a[0],b[1]):div(a[1],b[0]);
    return q===undefined?undefined:[Math.min(p,q),Math.max(p,q)];
  }
  const p=div(a[0],b[0]),q=div(a[0],b[1]),r=div(a[1],b[0]),s=div(a[1],b[1]);
  return p===undefined||q===undefined||r===undefined||s===undefined?undefined:[Math.min(p,q,r,s),Math.max(p,q,r,s)];
}
export function intervalTruncI32(value){
  if(!valid(value)||value[0]<-(2**63)||value[1]>=2**63)return undefined;
  const low=Math.trunc(value[0]),high=Math.trunc(value[1]);
  // Compare complete signed-I64 integers before taking the low DWORD. Equal
  // wrapped endpoints alone could hide any number of intervening 2^32 turns.
  return low===high?low|0:undefined;
}

/** Enclose the original m80 atan2 for finite, bounded exact binary64 loads. */
export function atan2Interval(y,x){
  if(typeof y!=='number'||typeof x!=='number'||!Number.isFinite(y)||!Number.isFinite(x))return undefined;
  const absY=Math.abs(y),absX=Math.abs(x);
  if((absY!==0&&(absY<2**-100||absY>2**100))||(absX!==0&&(absX<2**-100||absX>2**100)))return undefined;
  const negativeY=y<0||Object.is(y,-0),negativeX=x<0||Object.is(x,-0);
  if(y===0)return negativeX?enclose(negativeY?-pi:pi,angleError):[y,y];
  if(x===0)return enclose(negativeY?-halfPi:halfPi,angleError);
  const inverted=absY>absX,ratio=(inverted?absX:absY)/(inverted?absY:absX);
  const index=Math.round(ratio*64),anchor=index/64;
  const residual=(ratio-anchor)/(1+ratio*anchor);
  if(index<0||index>64||Math.abs(residual)>.008)return undefined;
  const squared=residual*residual;
  let result=atanAnchors[index]+residual*(1+squared*(-1/3+squared*(1/5-squared/7)));
  if(inverted)result=halfPi-result;
  if(negativeX)result=pi-result;
  if(negativeY)result=-result;
  // Ratio/reduction rounding, the degree7 polynomial, anchor conversion and
  // quadrant corrections contribute <32u (u=2^-53) absolutely. Its residual
  // remainder is <.008^9/9. Original224/m80 rounding is inside that budget.
  // The deliberately wider 2^-40 radius is rounded outward at both ends.
  return enclose(result,angleError);
}

/** Enclose FSIN/FCOS-style cosine, including uncertainty in its input angle. */
function trigX87Interval(angle,sineOutput){
  if(!valid(angle)||angle[0]<-16||angle[1]>16||angle[1]-angle[0]>2**-10)return undefined;
  if(angle[0]===0&&angle[1]===0)return sineOutput?[angle[0],angle[1]]:[1,1];
  const center=angle[0]+(angle[1]-angle[0])/2;
  const inputRadius=Math.max(center-angle[0],angle[1]-center);
  const quadrant=Math.round(center/halfPi),reduced=center-quadrant*halfPi;
  if(Math.abs(quadrant)>11||Math.abs(reduced)>.8)return undefined;
  const squared=reduced*reduced;
  const cosine=1+squared*(-1/2+squared*(1/24+squared*(-1/720+squared*(1/40320+squared*(-1/3628800+squared*(1/479001600-squared/87178291200))))));
  const sine=reduced*(1+squared*(-1/6+squared*(1/120+squared*(-1/5040+squared*(1/362880+squared*(-1/39916800+squared*(1/6227020800-squared/1307674368000)))))));
  const wrapped=(quadrant%4+4)%4;
  const result=sineOutput?(wrapped===0?sine:wrapped===1?cosine:wrapped===2?-sine:-cosine)
    :(wrapped===0?cosine:wrapped===1?-sine:wrapped===2?-cosine:sine);
  // For |quadrant|<=11, reduction using binary64 half-pi differs from the
  // retained66-bit reduction by <37u. Horner rounding and the degree14/15
  // remainders keep the total below64u. Sine and cosine are1-Lipschitz, so adding the
  // complete input radius encloses every angle before original m80 rounding.
  return enclose(result,adjacent(inputRadius+angleError,true));
}

export const cosX87Interval=angle=>trigX87Interval(angle,false);
export const sinX87Interval=angle=>trigX87Interval(angle,true);
