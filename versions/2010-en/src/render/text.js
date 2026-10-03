import { i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';

export const TEXT_ROUTINES = Object.freeze({ formatInteger: 0x41bc70, formatDecimal: 0x41bd00 });
const decoder = new TextDecoder('windows-1252');
const globalStrings = new WeakMap();
export const ORIGINAL_CSTRING_ADDRESSES=Object.freeze([0x4fdfd4,...Array.from({length:35},(_,index)=>0x4fec30+index*4)]);
const stringAddresses=new Set(ORIGINAL_CSTRING_ADDRESSES);
export const isOriginalCStringAddress=address=>stringAddresses.has(address>>>0);
export function resetOriginalCStringContents(memory){globalStrings.delete(memory);}

/** Original CString contents; allocator pointer identity is owned host metadata. */
export function readCString(memory,address){
  address>>>=0;
  if(!stringAddresses.has(address))throw new RangeError('Unknown original 2010 global CString cell');
  return globalStrings.get(memory)?.get(address)??'';
}
export function writeCString(memory,address,value){
  address>>>=0;
  if(!stringAddresses.has(address))throw new RangeError('Unknown original 2010 global CString cell');
  let values=globalStrings.get(memory);
  if(!values){values=new Map();globalStrings.set(memory,values);}
  values.set(address,String(value));
  return String(value);
}
export function cStringData(memory,value){
  return typeof value==='number' && stringAddresses.has(value>>>0) ? readCString(memory,value) : value;
}
export function originalCStringContents(memory){
  return ORIGINAL_CSTRING_ADDRESSES.map(address=>({address,text:readCString(memory,address)}));
}

/** Read the actual localized target bytes; leading NUL keeps the native empty string. */
export function readAnsiString(memory, address, maximum = 65536) {
  address >>>= 0;
  const bytes = [];
  for (let offset = 0; offset < maximum; offset++) {
    const byte = memory.readU8((address + offset) >>> 0);
    if (byte === 0) return decoder.decode(new Uint8Array(bytes));
    bytes.push(byte);
  }
  throw new RangeError('Original 2010 ANSI string exceeds the bounded read');
}

/** TextOutA accepts an explicit byte count, independently of strlen/CString. */
export function readAnsiBytes(memory, address, count) {
  address >>>= 0; count = i32(count);
  if (count < 0 || count > 65536) throw new RangeError('Original 2010 text byte count exceeds the bound');
  return decoder.decode(Uint8Array.from({ length: count }, (_, offset) => memory.readU8((address + offset) >>> 0)));
}

export const formatInteger = value => String(i32(value));

/** Original two FTOL truncations; fractional digits have no padding or sign repair. */
export function formatDecimal(memory, value) {
  const original = Float80.fromNumber(value);
  const integer = original.truncI32();
  const decimal = original.subtract(Float80.fromInteger(integer))
    .multiply(Float80.fromNumber(memory.readF64(0x4cc580))).truncI32();
  return `${integer}${readAnsiString(memory, 0x4dd054)}${decimal}`;
}
