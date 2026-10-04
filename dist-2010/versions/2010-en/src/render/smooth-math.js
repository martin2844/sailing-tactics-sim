import {Float80,getX87ControlWord} from '../../../../src/runtime/float80.js';

// Opt-in drawing-only math. Callers keep their existing exact path when
// these helpers decline. A Number result deliberately stays a Number through
// the typed renderer; it is not an m80 result or an engine arithmetic helper.
const maximumTrigAngle=2**20;
const floatPrototype=Float80.prototype;
const exactNumber=Float80.prototype.exactNumber,toNumber=Float80.prototype.toNumber;
const ordinaryNumber=value=>{
  if(typeof value==='number')return value;
  let exact;
  // The private-field read brands the operand before any prototype query;
  // a Proxy or duck value cannot turn that check into a host callback.
  try{exact=exactNumber.call(value);}catch{return undefined;}
  if(Object.getPrototypeOf(value)!==floatPrototype)return undefined;
  if(Number.isFinite(exact))return exact;
  const number=toNumber.call(value);
  // A nonzero m80 value that spills to zero is unsafe for atan's direction.
  return Number.isFinite(number)&&number!==0?number:undefined;
};
const enabled=options=>{
  if(options===null||(typeof options!=='object'&&typeof options!=='function')
    ||getX87ControlWord()!==0x027f)return false;
  const mode=Object.getOwnPropertyDescriptor(options,'smoothGraphics');
  if(!mode||!('value' in mode)||mode.value!==true)return false;
  return !('sinCos' in options||'atan2' in options||'retainedDrawingStack' in options
    ||'drawingDependencies' in options);
};

export function trySmoothSinCosNumber(value,options){
  value=ordinaryNumber(value);
  if(!Number.isFinite(value)||Math.abs(value)>maximumTrigAngle||!enabled(options))return undefined;
  return {sine:Math.sin(value),cosine:Math.cos(value)};
}

export function trySmoothAtanNumber(y,x,options){
  y=ordinaryNumber(y);x=ordinaryNumber(x);
  if(!Number.isFinite(y)||!Number.isFinite(x)||!enabled(options))return undefined;
  return Math.atan2(y,x);
}
