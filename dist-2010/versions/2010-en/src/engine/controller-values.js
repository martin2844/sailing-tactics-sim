import { i32, u32, add32, sub32, imul32, idiv32, irem32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';

// Typed C expressions used by the statically translated original controllers.
// The finite arithmetic precision is supplied by the shared x87 context.
const integer=value=>typeof value==='boolean' ? Number(value) : value;
export const cI32 = (value, unsigned = false) => (unsigned ? u32 : i32)(value instanceof Float80 ? value.truncI32() : integer(value));
export const cFloat = value => value instanceof Float80 ? value : Float80.fromInteger(integer(value));
export const cAdd = (a,b) => a instanceof Float80 || b instanceof Float80 ? cFloat(a).add(cFloat(b)) : add32(integer(a),integer(b));
export const cSub = (a,b) => a instanceof Float80 || b instanceof Float80 ? cFloat(a).subtract(cFloat(b)) : sub32(integer(a),integer(b));
export const cMul = (a,b) => a instanceof Float80 || b instanceof Float80 ? cFloat(a).multiply(cFloat(b)) : imul32(integer(a),integer(b));
export const cDiv = (a,b) => a instanceof Float80 || b instanceof Float80 ? cFloat(a).divide(cFloat(b)) : idiv32(integer(a),integer(b));
export const cRem = (a,b) => irem32(integer(a),integer(b));
export const cNeg = value => value instanceof Float80 ? value.negate() : sub32(0,integer(value));
export const cBits = (a,b,operator) => operator === '&' ? a&b : operator === '|' ? a|b : operator === '^' ? a^b : operator === '<<' ? a<<b : operator === '>>' ? a>>b : ~a;
export function cCompare(a,b,operator) {
  const comparison = a instanceof Float80 || b instanceof Float80 ? cFloat(a).compare(cFloat(b)) : a<b ? -1 : a>b ? 1 : 0;
  return operator === '<' ? comparison<0 : operator === '>' ? comparison>0 : operator === '<=' ? comparison<=0 : operator === '>=' ? comparison>=0 : operator === '==' ? comparison===0 : comparison!==0;
}
export function cTruth(value) {
  if (value===undefined) throw new RangeError('Original controller reads an undefined retained local');
  return value instanceof Float80 ? value.compare(Float80.fromInteger(0))!==0 : value!==0 && value!==false && value!==null;
}

export function controllerMemory(memory) {
  return {
    r32: address => memory.readI32(u32(address)),
    r64: address => Float80.fromNumber(memory.readF64(u32(address))),
    w32: (address,value) => { value=cI32(value);memory.writeI32(u32(address),value);return value; },
    w64: (address,value) => { value=cFloat(value).toNumber();memory.writeF64(u32(address),value);return Float80.fromNumber(value); },
  };
}
