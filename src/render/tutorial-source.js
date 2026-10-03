import { i32, u32, add32, sub32, imul32, idiv32, irem32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { readAnsiString } from '../engine/hud-state.js';

// Typed operations used by the static tutorial translation. Pointer values here
// address original data or local C arrays; no executable bytes are interpreted.
const integer = value => {
  if (value === undefined) throw new RangeError('Original tutorial reads an undefined retained local');
  return typeof value === 'boolean' ? Number(value) : value;
};
const pointer = value => value && typeof value === 'object' && 'array' in value;
const table = value => value && typeof value === 'object' && 'dc' in value;
export function cI32(value, unsigned = false) {
  if (value instanceof Float80) value = value.truncI32();
  if (pointer(value) || table(value) || typeof value === 'function' || typeof value === 'string' || value?.events) return value;
  return (unsigned ? u32 : i32)(integer(value));
}
export function cI64(value, unsigned = false) {
  if (value instanceof Float80) value = value.truncI64();
  if (pointer(value) || table(value) || value?.events) return value;
  return (unsigned ? BigInt.asUintN : BigInt.asIntN)(64, BigInt(integer(value)));
}
export function cFloat(value) {
  if (value instanceof Float80) return value;
  return Float80.fromInteger(integer(value));
}
export function pointerAdd(value, offset) {
  offset = cI32(offset);
  if (pointer(value)) return { array: value.array, offset: add32(value.offset, offset) };
  if (table(value)) return { dc: value.dc, offset: add32(value.offset, offset) };
  if (value?.events) return { dc: value, offset };
  return add32(value, offset);
}
export function localPointer(array) { return { array, offset: 0 }; }
export function cAdd(a, b) {
  if (pointer(a) || table(a) || a?.events) return pointerAdd(a, b);
  if (a instanceof Float80 || b instanceof Float80) return cFloat(a).add(cFloat(b));
  if (typeof a === 'bigint' || typeof b === 'bigint') return BigInt.asIntN(64,BigInt(integer(a))+BigInt(integer(b)));
  return add32(integer(a),integer(b));
}
export function cSub(a, b) {
  if (pointer(a) || table(a) || a?.events) return pointerAdd(a,cNeg(b));
  if (a instanceof Float80 || b instanceof Float80) return cFloat(a).subtract(cFloat(b));
  if (typeof a === 'bigint' || typeof b === 'bigint') return BigInt.asIntN(64,BigInt(integer(a))-BigInt(integer(b)));
  return sub32(integer(a),integer(b));
}
export function cMul(a, b) {
  if (a instanceof Float80 || b instanceof Float80) return cFloat(a).multiply(cFloat(b));
  if (typeof a === 'bigint' || typeof b === 'bigint') return BigInt.asIntN(64,BigInt(integer(a))*BigInt(integer(b)));
  return imul32(integer(a),integer(b));
}
export function cDiv(a, b) {
  if (a instanceof Float80 || b instanceof Float80) return cFloat(a).divide(cFloat(b));
  if (typeof a === 'bigint' || typeof b === 'bigint') return BigInt(integer(a))/BigInt(integer(b));
  return idiv32(integer(a),integer(b));
}
export function cRem(a, b) {
  if (typeof a === 'bigint' || typeof b === 'bigint') return BigInt(integer(a))%BigInt(integer(b));
  return irem32(integer(a),integer(b));
}
export function cNeg(value) {
  if (value instanceof Float80) return value.negate();
  if (typeof value === 'bigint') return BigInt.asIntN(64,-value);
  return sub32(0,integer(value));
}
export function cBits(a, b, operator) {
  if (typeof a === 'bigint' || typeof b === 'bigint') {
    a=BigInt(integer(a)); b=BigInt(integer(b));
    const result = operator === '&' ? a&b : operator === '|' ? a|b : operator === '^' ? a^b : operator === '<<' ? a<<b : operator === '>>' ? a>>b : ~a;
    return BigInt.asIntN(64,result);
  }
  a=integer(a); b=integer(b);
  return operator === '&' ? a&b : operator === '|' ? a|b : operator === '^' ? a^b : operator === '<<' ? a<<b : operator === '>>' ? a>>b : ~a;
}
export function cCompare(a,b,operator) {
  let comparison;
  if (a instanceof Float80 || b instanceof Float80) comparison=cFloat(a).compare(cFloat(b));
  else { a=integer(a);b=integer(b);comparison=a<b?-1:a>b?1:0; }
  return operator==='<' ? comparison<0 : operator==='>' ? comparison>0 : operator==='<=' ? comparison<=0 : operator==='>=' ? comparison>=0 : operator==='==' ? comparison===0 : comparison!==0;
}
export function cTruth(value) {
  if (value instanceof Float80) return value.compare(Float80.fromInteger(0)) !== 0;
  if (value === undefined) throw new RangeError('Original tutorial reads an undefined retained local');
  return value !== 0 && value !== 0n && value !== false && value !== null;
}
export function cString(memory,value) { return typeof value === 'string' ? value : readAnsiString(memory,cI32(value)>>>0); }
export function readPointer(memory,value,size) {
  if (value?.events) return value;
  if (table(value)) return dcMethod(value.dc,value.offset);
  if (pointer(value)) {
    if (value.offset%4 !== 0) throw new RangeError('Unaligned tutorial local-array read');
    const result=value.array[value.offset/4];
    if (result===undefined) throw new RangeError('Original tutorial reads an undefined retained array slot');
    return result;
  }
  const address=cI32(value)>>>0;
  return size===8 ? Float80.fromNumber(memory.readF64(address)) : memory.readI32(address);
}
export function writePointer(memory,value,data,size) {
  if (pointer(value)) { value.array[value.offset/4]=cI32(data); return data; }
  const address=cI32(value)>>>0;
  if (size===8) memory.writeF64(address,cFloat(data).toNumber());
  else memory.writeI32(address,cI32(data));
  return data;
}
export function writeLocalPoint(destination,point) {
  if (pointer(destination)) { destination.array[destination.offset/4]=point.x;destination.array[destination.offset/4+1]=point.y; }
  return point;
}
export const stockObject = index => ({ stockObject: cI32(index) });
export function originalPoints(memory,address,count) {
  address=cI32(address)>>>0; count=cI32(count);
  if (count<0 || count>256) throw new RangeError('Original tutorial polygon count');
  return Array.from({length:count},(_,index)=>({x:memory.readI32(address+index*8),y:memory.readI32(address+index*8+4)}));
}
export function selectGdiObject(dc,value) {
  if (value && typeof value==='object' && 'stockObject' in value) return dc.selectStockObject(value.stockObject);
  return dc.selectObject(cI32(value)>>>0);
}
export function dcMethod(dc,offset) {
  const name={44:'selectStockObject',52:'setBkColor',56:'setTextColor',100:'textOut'}[offset];
  if (!name) throw new RangeError(`Unsupported tutorial CDC offset ${offset}`);
  return dc[name].bind(dc);
}
