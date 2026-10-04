import {cI32,cFloat} from './typed-c.js';
const nonfiniteF64=Symbol('stored nonfinite binary64');

// The generator proves that these slots never overlap and their addresses never
// escape. Keep the same undefined-byte failure and stored semantic pointer /
// callback / CString identities as writeLocal/readLocal on a complete frame.
const semantic=value=>value?.frame||value?.array||value?.dc||value?.events||
  value&&typeof value==='object'&&('clipRect' in value||'restoreClip' in value||'stockObject' in value)||
  typeof value==='function'||typeof value==='string';

export function scalarRead(value){
  if(value===undefined)throw new RangeError('Original C reads an undefined retained local byte');
  if(value===nonfiniteF64)throw new RangeError('Float80 does not support NaN or infinite inputs');
  return value;
}
export const scalarReadArgument=value=>value===undefined?undefined:scalarRead(value);
// DataView's integer store applies ToNumber after the C conversion. A host-like
// object with a false pointer field can survive cI32 without being semantic.
export const scalarStoreI32=value=>value===undefined||semantic(value)?value:(+cI32(value))|0;
export function scalarStoreF64(value){
  if(value===undefined||semantic(value))return value;
  const floating=cFloat(value);
  // A finite m80 value may spill to infinity. The original byte store permits
  // this; only its later floating load fails, and an overwrite may avoid it.
  return Number.isFinite(floating.toNumber())?floating.storeBinary64():nonfiniteF64;
}
