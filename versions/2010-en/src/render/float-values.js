import { Float80, getX87ControlWord } from '../../../../src/runtime/float80.js';
import { cFloat,cF64,cI32,cI64,originalTrig,originalAtan } from './typed-c.js';
import {sinCosX87Number} from '../../../../src/runtime/transcendentals.js';
import {atan2ExtendedNumeric} from '../../../../src/runtime/atan.js';
import {scalarRead,scalarReadArgument,scalarStoreF64} from './scalar-stack.js';
import {trySmoothSinCosNumber,trySmoothAtanNumber} from './smooth-math.js';

// These helpers are used only at C expressions statically proved floating by
// the source translator. A Number here represents an exact binary64 x87 load;
// integer expressions continue to use the existing wrapping C helpers.
const minimumNormal=2**-1022;
const normal=value=>Number.isFinite(value)&&Math.abs(value)>=minimumNormal;
const nearest53=()=>getX87ControlWord()===0x027f;
const operand=value=>value instanceof Float80?value:typeof value==='number'?Float80.fromNumber(value):cFloat(value);
const unbox=value=>value instanceof Float80&&!Number.isNaN(value.exactNumber())?value.exactNumber():value;
const nonfiniteScalar=Symbol('stored nonfinite Number drawing scalar');

export function fpDrawingEnabled(options={}){
  if(options===null||(typeof options!=='object'&&typeof options!=='function')||!nearest53()
    ||'retainedDrawingStack' in options||'sinCos' in options||'atan2' in options||'drawingDependencies' in options)return false;
  const mode=Object.getOwnPropertyDescriptor(options,'numberRendering');
  return mode?'value' in mode&&mode.value!==false:!('numberRendering' in options);
}
export function fpLoad(value){
  if(typeof value!=='number'||!Number.isFinite(value))return Float80.fromNumber(value).toNumber();
  return value;
}
export const fpBox=value=>value===undefined?undefined:operand(value);
export const fpArgument=fpBox;
export function fpFromInteger(value){
  if(typeof value==='number'&&Number.isSafeInteger(value))return value===0?0:value;
  if(typeof value==='boolean')return Number(value);
  if(typeof value==='bigint'&&value>=-9007199254740991n&&value<=9007199254740991n)return Number(value);
  return cFloat(value);
}
export const fpToNumber=value=>value instanceof Float80?value.toNumber():fpLoad(value);
export const fpStoreF64=value=>fpLoad(fpToNumber(value));
export const fpFormalF64=(value,alreadyFloatingImage=false)=>value===undefined?undefined:alreadyFloatingImage?fpStoreF64(value):cF64(value).toNumber();
export const fpTrig=(value,options={})=>{
  if('sinCos' in options)return originalTrig(value,options);
  const smooth=trySmoothSinCosNumber(value,options);
  if(smooth!==undefined)return smooth;
  value=unbox(value);
  return typeof value==='number'?sinCosX87Number(value):originalTrig(value,options);
};
export function fpAtan(y,x,options={}){
  const smooth=trySmoothAtanNumber(y,x,options);
  if(smooth!==undefined)return smooth;
  if(typeof y==='number'&&typeof x==='number'){
    const absY=Math.abs(y),absX=Math.abs(x);
    if(absY>=2**-100&&absY<=2**100&&absX>=2**-100&&absX<=2**100){
      if(options===null||(typeof options!=='object'&&typeof options!=='function')||'atan2' in options){
        return originalAtan(fpArgument(y),fpArgument(x),options);
      }
      // Both original argument boxes are successful in this domain. Read the
      // provider once at the original selection point, preserving its getter
      // and callback argument representation when present.
      const provider=options.atan2;
      return provider==null?atan2ExtendedNumeric(y,x)
        :originalAtan(fpArgument(y),fpArgument(x),{atan2:provider});
    }
  }
  return originalAtan(fpArgument(y),fpArgument(x),options);
}
export function fpScalarStoreF64(value){
  if(typeof value==='number')return fpLoad(value);
  if(value instanceof Float80){const number=value.toNumber();return Number.isFinite(number)?number:nonfiniteScalar;}
  // Undefined and original semantic pointer/callback slots retain the exact
  // existing store contract. Only declared floating values use Number storage.
  return scalarStoreF64(value);
}
export function fpScalarRead(value){
  if(value===nonfiniteScalar)throw new RangeError('Float80 does not support NaN or infinite inputs');
  return scalarRead(value);
}
export function fpScalarReadArgument(value){
  return value===undefined?scalarReadArgument(value):fpScalarRead(value);
}

export function fpAdd(a,b){
  a=unbox(a);b=unbox(b);
  if(typeof a==='number'&&typeof b==='number'&&nearest53()){
    const value=a+b;
    if(normal(value)||(value===0&&a===-b))return value;
  }
  return unbox(operand(a).add(operand(b)));
}
export function fpSub(a,b){
  a=unbox(a);b=unbox(b);
  if(typeof a==='number'&&typeof b==='number'&&nearest53()){
    const value=a-b;
    if(normal(value)||(value===0&&a===b))return value;
  }
  return unbox(operand(a).subtract(operand(b)));
}
export function fpMul(a,b){
  a=unbox(a);b=unbox(b);
  if(typeof a==='number'&&typeof b==='number'&&nearest53()){
    const value=a*b;
    if(normal(value)||(value===0&&(a===0||b===0)))return value;
  }
  if(a instanceof Float80&&typeof b==='number')return unbox(Object.getPrototypeOf(a)===Float80.prototype?a.multiplyNumberUnboxed(b):a.multiplyNumber(b));
  if(b instanceof Float80&&typeof a==='number')return unbox(Object.getPrototypeOf(b)===Float80.prototype?b.multiplyNumberUnboxed(a):b.multiplyNumber(a));
  return unbox(operand(a).multiply(operand(b)));
}
export function fpDiv(a,b){
  a=unbox(a);b=unbox(b);
  if(typeof a==='number'&&typeof b==='number'&&nearest53()){
    const value=a/b;
    if(normal(value)||(value===0&&a===0&&Number.isFinite(b)&&b!==0))return value;
  }
  return unbox(operand(a).divide(operand(b)));
}
export const fpNeg=value=>typeof value==='number'?-fpLoad(value):operand(value).negate();
export const fpAbs=value=>typeof value==='number'?Math.abs(fpLoad(value)):(value=operand(value),value.sign<0?value.negate():value);
export function fpCompare(a,b,operator){
  let comparison;
  if(typeof a==='number'&&typeof b==='number'&&Number.isFinite(a)&&Number.isFinite(b))comparison=a<b?-1:a>b?1:0;
  else comparison=operand(a).compare(operand(b));
  return operator==='<'?comparison<0:operator==='>'?comparison>0:operator==='<='?comparison<=0:operator==='>='?comparison>=0:operator==='=='?comparison===0:comparison!==0;
}
export function fpTruth(value){
  return typeof value==='number'?fpLoad(value)!==0:operand(value).compare(Float80.fromInteger(0))!==0;
}
export function fpI32(value,unsigned=false){
  if(typeof value==='number'&&Number.isFinite(value)&&value>=-(2**63)&&value<2**63)return unsigned?value>>>0:value|0;
  return cI32(operand(value),unsigned);
}
export function fpI64(value,unsigned=false){
  if(typeof value==='number'&&Number.isFinite(value)&&value>=-(2**63)&&value<2**63){
    const exact=BigInt(Math.trunc(value));
    return unsigned?BigInt.asUintN(64,exact):exact;
  }
  return cI64(operand(value),unsigned);
}
