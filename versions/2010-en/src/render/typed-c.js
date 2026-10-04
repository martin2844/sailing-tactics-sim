import { i32, u32, add32, sub32, imul32, idiv32, irem32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { readAnsiString, readAnsiBytes,isOriginalCStringAddress,readCString } from './text.js';
import { sinCosX87 } from '../../../../src/runtime/transcendentals.js';
import { atan2Extended } from '../../../../src/runtime/atan.js';

// Typed operations used by the static 2010 drawing translation. Pointer values here
// address original data or local C arrays; no executable bytes are interpreted.
const integer = value => {
  if (value === undefined) throw new RangeError('Original 2010 drawing reads an undefined retained local');
  return typeof value === 'boolean' ? Number(value) : value;
};
const pointer = value => value && typeof value === 'object' && ('array' in value || 'frame' in value);
const table = value => value && typeof value === 'object' && 'dc' in value;
const hostObject = value => value && typeof value==='object' && ('clipRect' in value || 'restoreClip' in value || 'stockObject' in value);
export function cI32(value, unsigned = false) {
  if (value instanceof Float80) value = value.truncI32();
  if (pointer(value) || table(value) || hostObject(value) || typeof value === 'function' || typeof value === 'string' || value?.events) return value;
  return (unsigned ? u32 : i32)(integer(value));
}
export function cI64(value, unsigned = false) {
  if (value instanceof Float80) value = value.truncI64();
  if (pointer(value) || table(value) || value?.events) return value;
  return (unsigned ? BigInt.asUintN : BigInt.asIntN)(64, BigInt(integer(value)));
}
export function cFloat(value) {
  if (value instanceof Float80) return value;
  value=integer(value);
  return typeof value==='number' && !Number.isInteger(value) ? Float80.fromNumber(value) : Float80.fromInteger(value);
}
export const cF64=value=>cFloat(value).storeBinary64();
export const cAbs=value=>{value=cFloat(value);return value.sign<0?value.negate():value;};
export function pointerAdd(value, offset) {
  offset = cI32(offset);
  if (value?.frame) return {frame:value.frame,offset:add32(value.offset,offset)};
  if (pointer(value)) return { array: value.array, offset: add32(value.offset, offset),elementSize:value.elementSize??4 };
  if (table(value)) return { dc: value.dc, offset: add32(value.offset, offset),kind:value.kind };
  if (value?.events) return { dc: value, offset,kind:'object' };
  return add32(value, offset);
}
export function localPointer(array,elementSize=4) { return { array, offset: 0,elementSize }; }
// The common aligned argument slots fit in the first 32 bytes. Keep their exact
// DWORD images and byte-validity mask until a caller needs public byte arrays or
// an access outside that range. Each frame owns its storage for its full lifetime.
const localScalarView=new DataView(new ArrayBuffer(8));
class LocalFrame {
 constructor(size){this._size=size;this._words=[];this._validBits=0;this._bytes=null;this._valid=null;this._view=null;this._semantic=null;}
 materialize(){
  if(this._words===null)return;
  this._bytes=new Uint8Array(this._size);this._valid=new Uint8Array(this._size);this._view=new DataView(this._bytes.buffer);
  for(let index=0;index<this._words.length;index++)this._view.setUint32(index*4,this._words[index]??0,true);
  for(let index=0;index<Math.min(32,this._size);index++)this._valid[index]=(this._validBits>>>index)&1;
  this._words=null;
 }
 get bytes(){this.materialize();return this._bytes;}
 set bytes(value){this.materialize();this._bytes=value;this._view=null;}
 get valid(){this.materialize();return this._valid;}
 set valid(value){this.materialize();this._valid=value;}
 get view(){this.materialize();return this._view??=new DataView(this._bytes.buffer,this._bytes.byteOffset,this._bytes.byteLength);}
 set view(value){this.materialize();this._view=value;}
 get semantic(){return this._semantic??=new Map();}
 set semantic(value){this._semantic=value;}
}
export function createLocalFrame(size,initial=[]){
 if(!Number.isInteger(size)||size<0||size>65536)throw new RangeError('Original C local frame exceeds bound');
 const frame=new LocalFrame(size);
 for(const row of initial){
  const bytes=Uint8Array.from(row.bytes.match(/../g)??[],pair=>Number.parseInt(pair,16));
  if(row.offset<0||row.offset+bytes.length>size)throw new RangeError('Declared retained local exceeds frame');
  frame.bytes.set(bytes,row.offset);frame.valid.fill(1,row.offset,row.offset+bytes.length);
 }
 return frame;
}
export const framePointer=(frame,offset)=>({frame,offset});
const packedRange=(frame,offset,size)=>frame._words!==null&&frame._bytes===null&&Number.isInteger(offset)&&Number.isInteger(size)&&offset>=0&&size>=0&&offset+size<=32;
const byteMask=(offset,size)=>size===0?0:((0xffffffff>>>(32-size))<<offset);
function checkLocal(pointer,size,writing=false){
 const {frame,offset}=pointer;
 const length=packedRange(frame,offset,size)?frame._size:frame.bytes.length;
 if(offset<0||offset+size>length)throw new RangeError('Original C local memory access exceeds frame');
 if(!writing&&!localBytesValid(frame,offset,size))throw new RangeError('Original C reads an undefined retained local byte');
}
function localBytesValid(frame,offset,size){
 if(packedRange(frame,offset,size)){const mask=byteMask(offset,size);return (frame._validBits&mask)===mask;}
 if(size<0||!Number.isInteger(offset)||!Number.isInteger(size))return frame.valid.subarray(offset,offset+size).every(Boolean);
 for(let at=offset,end=offset+size;at<end;at++)if(!frame.valid[at])return false;
 return true;
}
export function readLocal(pointer,size,kind='int'){
 checkLocal(pointer,size);
 const {frame,offset}=pointer,semantic=frame._semantic?.get(offset);
 if(semantic&&semantic.size===size)return semantic.value;
 if(packedRange(frame,offset,size)&&(offset&3)===0){
  if(size===4&&kind!=='float')return frame._words[offset>>>2]??0;
  if(size===8&&kind==='float'){
   localScalarView.setUint32(0,frame._words[offset>>>2]??0,true);localScalarView.setUint32(4,frame._words[(offset>>>2)+1]??0,true);
   return Float80.fromNumber(localScalarView.getFloat64(0,true));
  }
 }
 const width=kind==='float'||size===8?8:size===1?1:size===2?2:size===3?3:4;
 const cached=size>=width&&Number.isInteger(size)&&Number.isInteger(offset);
 const view=cached?frame.view:new DataView(frame.bytes.buffer,frame.bytes.byteOffset+offset,size),at=cached?offset:0;
 if(kind==='float')return Float80.fromNumber(view.getFloat64(at,true));
 return size===8?view.getBigInt64(at,true):size===1?view.getUint8(at):size===2?view.getUint16(at,true):size===3?view.getUint16(at,true)|(view.getUint8(at+2)<<16):view.getInt32(at,true);
}
export function readLocalArgument(pointer,size,kind='int'){
 checkLocal(pointer,size,true);
 if(!localBytesValid(pointer.frame,pointer.offset,size))return undefined;
 return readLocal(pointer,size,kind);
}
export const cWordArgument=(value,unsigned=false)=>value===undefined?undefined:cI32(value,unsigned);
export function writeLocal(pointer,value,size,kind='int'){
 checkLocal(pointer,size,true);
 const {frame,offset}=pointer;
 if(frame._semantic)for(const [at,row]of frame._semantic)if(at<offset+size&&offset<at+row.size)frame._semantic.delete(at);
 const packed=packedRange(frame,offset,size)&&(offset&3)===0&&(size===4&&kind!=='float'||size===8&&(kind==='float'||value instanceof Float80));
 if(value===undefined){
  if(packedRange(frame,offset,size))frame._validBits&=~byteMask(offset,size);
  else frame.valid.fill(0,offset,offset+size);
  return value;
 }
 const semantic=pointer?.frame&&(value?.frame||value?.array||value?.dc||value?.events||hostObject(value)||typeof value==='function'||typeof value==='string');
 if(packed){
  if(semantic){frame.semantic.set(offset,{size,value});frame._words[offset>>>2]=0;if(size===8)frame._words[(offset>>>2)+1]=0;}
  else if(size===8){localScalarView.setFloat64(0,cFloat(value).toNumber(),true);frame._words[offset>>>2]=localScalarView.getInt32(0,true);frame._words[(offset>>>2)+1]=localScalarView.getInt32(4,true);}
  else frame._words[offset>>>2]=(+cI32(value))|0;
  frame._validBits|=byteMask(offset,size);return value;
 }
 const width=kind==='float'||size===8?8:size===1?1:size===2?2:size===3?3:4;
 const cached=size>=width&&Number.isInteger(size)&&Number.isInteger(offset);
 const view=cached?frame.view:new DataView(frame.bytes.buffer,frame.bytes.byteOffset+offset,size),at=cached?offset:0;
 if(semantic){frame.semantic.set(offset,{size,value});frame.bytes.fill(0,offset,offset+size);}
 else if(kind==='float'||value instanceof Float80&&size===8)view.setFloat64(at,cFloat(value).toNumber(),true);
 else if(size===8)view.setBigInt64(at,BigInt.asIntN(64,BigInt(integer(value))),true);
 else if(size===1)view.setUint8(at,cI32(value));else if(size===2)view.setUint16(at,cI32(value),true);else if(size===3){view.setUint16(at,cI32(value),true);view.setUint8(at+2,cI32(value)>>>16);}else view.setInt32(at,cI32(value),true);
 frame.valid.fill(1,offset,offset+size);return value;
}
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
export function signedBorrow32(a,b) {
  a=cI32(a);b=cI32(b);const result=sub32(a,b);
  return ((a^b)&(a^result))<0;
}
export function cCompare(a,b,operator) {
  let comparison;
  if (a instanceof Float80 || b instanceof Float80) comparison=cFloat(a).compare(cFloat(b));
  else { a=integer(a);b=integer(b);comparison=a<b?-1:a>b?1:0; }
  return operator==='<' ? comparison<0 : operator==='>' ? comparison>0 : operator==='<=' ? comparison<=0 : operator==='>=' ? comparison>=0 : operator==='==' ? comparison===0 : comparison!==0;
}
export function cTruth(value) {
  if (value instanceof Float80) return value.compare(Float80.fromInteger(0)) !== 0;
  if (value === undefined) throw new RangeError('Original 2010 drawing reads an undefined retained local');
  return value !== 0 && value !== 0n && value !== false && value !== null;
}
export function cString(memory,value) {
  if (typeof value==='string') return value;
  if (typeof value==='number' && isOriginalCStringAddress(value))return readCString(memory,value);
  if (value?.frame) {
    const bytes=[];
    for(let index=value.offset;index<value.frame.bytes.length;index++) {
      const byte=readLocal(framePointer(value.frame,index),1);
      if(byte===0)return new TextDecoder('windows-1252').decode(Uint8Array.from(bytes));
      bytes.push(byte);
    }
    throw new RangeError('Original local ANSI string is not NUL terminated');
  }
  if (pointer(value)) {
    const bytes=[];
    for(let index=value.offset;index<value.array.length;index++) {
      const byte=value.array[index];
      if(byte===undefined)throw new RangeError('Original local ANSI string reads an undefined byte');
      if(byte===0)return new TextDecoder('windows-1252').decode(Uint8Array.from(bytes));
      bytes.push(byte&255);
    }
    throw new RangeError('Original local ANSI string is not NUL terminated');
  }
  return readAnsiString(memory,cI32(value)>>>0);
}
export function readPointer(memory,value,size) {
  // A semantic CString stands for the original object and its data payload.
  // Its allocator address is excluded from game-state comparisons, while the
  // exact byte string remains observable in TextOut and the global cells.
  if(size===4 && typeof value==='string')return value;
  if(size===4 && typeof value==='number' && isOriginalCStringAddress(value))return readCString(memory,value);
  if (value?.events) return {dc:value,offset:0,kind:'vtable'};
  if (table(value)) {
    if(value.kind==='vtable')return dcMethod(value.dc,value.offset,memory);
    if(value.offset===0)return {dc:value.dc,offset:0,kind:'vtable'};
    if(value.offset===4)return value.dc;
    if(value.offset===8)return 0;
    throw new RangeError('Unsupported original CDC object member');
  }
  if(value?.frame)return readLocal(value,size,size===8?'float':'int');
  if (pointer(value)) {
    const elementSize=value.elementSize??4;
    if (value.offset%elementSize !== 0) throw new RangeError('Unaligned 2010 drawing local-array read');
    const result=value.array[value.offset/elementSize];
    if (result===undefined) throw new RangeError('Original 2010 drawing reads an undefined retained array slot');
    return result;
  }
  const address=cI32(value)>>>0;
  return size===8 ? Float80.fromNumber(memory.readF64(address)) : size===1?memory.readU8(address):size===2?memory.readU16(address):size===3?memory.readU16(address)|(memory.readU8(address+2)<<16):memory.readI32(address);
}
export function writePointer(memory,value,data,size) {
  if(value?.frame)return writeLocal(value,data,size,size===8?'float':'int');
  if (pointer(value)) { value.array[value.offset/(value.elementSize??4)]=size===8?cF64(data):cI32(data); return data; }
  const address=cI32(value)>>>0;
  if (size===8) memory.writeF64(address,cFloat(data).toNumber());
  else if(size===1)memory.writeU8(address,cI32(data));else if(size===2)memory.writeU16(address,cI32(data));else if(size===3){memory.writeU16(address,cI32(data));memory.writeU8(address+2,cI32(data)>>>16);}else memory.writeI32(address,cI32(data));
  return data;
}
export function writeLocalPoint(destination,point) {
  if(destination?.frame){writeLocal(destination,point.x,4);writeLocal(pointerAdd(destination,4),point.y,4);return point;}
  if (pointer(destination)) { destination.array[destination.offset/4]=point.x;destination.array[destination.offset/4+1]=point.y; }
  return point;
}
export const stockObject = index => ({ stockObject: cI32(index) });
export function originalPoints(memory,address,count) {
  count=cI32(count);
  if (count<0 || count>4096) throw new RangeError('Original 2010 drawing polygon count');
  if (pointer(address)) return Array.from({length:count},(_,index)=>({
    x:cI32(readPointer(memory,pointerAdd(address,index*8),4)),
    y:cI32(readPointer(memory,pointerAdd(address,index*8+4),4)),
  }));
  address=cI32(address)>>>0;
  return Array.from({length:count},(_,index)=>({x:memory.readI32(address+index*8),y:memory.readI32(address+index*8+4)}));
}
export function selectGdiObject(dc,value) {
  if (value?.clipRect) { dc.pushClipRect(...value.clipRect); return { restoreClip: true }; }
  if (value?.restoreClip) { dc.popClipRect(); return 0; }
  if (value && typeof value==='object' && 'stockObject' in value) return dc.selectStockObject(value.stockObject);
  return dc.selectObject(cI32(value)>>>0);
}
// CDC::SelectObject receives a CGdiObject*, whose +4 member is the HGDIOBJ.
// The original drawing callers covered here discard its framework-object return.
export function selectOriginalGdiObject(dc,memory,value) {
  const address=cI32(value)>>>0;
  return dc.selectObject(address===0 ? 0 : memory.readU32(address+4));
}
export function importDrawingMethod(dc,memory,name) {
  if(name==='Ellipse')return dc.ellipse.bind(dc);
  if(name==='Polygon')return (points,count)=>dc.polygon(originalPoints(memory,points,count));
  if(name==='SelectObject')return handle=>selectGdiObject(dc,handle);
  if(name==='TextOutA')return (x,y,text,count)=>textOutCount(dc,memory,x,y,text,count);
  throw new RangeError('Unreviewed original GDI function-pointer alias');
}
export function invokeDrawingPointer(method,dc,args){
  if(typeof method!=='function')throw new TypeError('Original drawing function pointer is not bound');
  return method(...(args[0]===dc?args.slice(1):args));
}
export const clipRegion = (left,top,right,bottom) => ({clipRect:[left,top,right,bottom].map(value=>cI32(value))});
export function textOutCount(dc,memory,x,y,text,count) {
  count=cI32(count);
  if (count<0 || count>65536) throw new RangeError('Original 2010 text byte count exceeds the bounded contract');
  if(pointer(text))return dc.textOut(x,y,readAnsiBytes({readU8:offset=>readPointer(memory,pointerAdd(text,offset),1)},0,count));
  return dc.textOut(x,y,typeof text==='string' ? text.slice(0,count) : readAnsiBytes(memory,cI32(text)>>>0,count));
}
export function cStringHeaderLength(memory,value) {
  return typeof value==='string' ? value.length : memory.readI32((cI32(value)>>>0)-8);
}
export function originalTrig(value,options={}) {
  const radians=cFloat(value);
  return options.sinCos ? options.sinCos(radians) : sinCosX87(radians);
}
export function dcMethod(dc,offset,memory) {
  if (offset===48) return value=>selectOriginalGdiObject(dc,memory,value);
  const name={44:'selectStockObject',52:'setBkColor',56:'setTextColor',100:'textOut'}[offset];
  if (!name) throw new RangeError(`Unsupported 2010 drawing CDC offset ${offset}`);
  if (offset===100) return (x,y,text,count)=>textOutCount(dc,memory,x,y,text,count);
  return dc[name].bind(dc);
}
export const originalAtan=(y,x,options={})=>(options.atan2??atan2Extended)(cFloat(y),cFloat(x));
export function cConcat(high,low,highBytes,lowBytes){
  const width=BigInt(lowBytes*8),mask=(1n<<width)-1n;
  return BigInt.asUintN((highBytes+lowBytes)*8,(BigInt(cI64(high))<<width)|(BigInt(cI64(low))&mask));
}
export function bitsAsF64(value){
  const data=new DataView(new ArrayBuffer(8));data.setBigUint64(0,BigInt.asUintN(64,BigInt(value)),true);
  return Float80.fromNumber(data.getFloat64(0,true));
}
export function cRawWord(value){
  if(!(value instanceof Float80))return cI32(value);
  const data=new DataView(new ArrayBuffer(8));data.setFloat64(0,value.toNumber(),true);
  return data.getInt32(0,true);
}
export function cRawSlice(value,offset,size,kind='float'){
  const bytes=new Uint8Array(kind==='extended'?10:8),view=new DataView(bytes.buffer);
  if(kind==='extended')bytes.set(cFloat(value).toBytes());
  else if(kind==='integer')view.setBigInt64(0,BigInt.asIntN(64,BigInt(value)),true);
  else view.setFloat64(0,cFloat(value).toNumber(),true);
  if(offset<0||offset+size>bytes.length)throw new RangeError('Original scalar raw-word access exceeds width');
  if(size===1)return view.getUint8(offset);
  if(size===2)return view.getUint16(offset,true);
  if(size===4)return view.getInt32(offset,true);
  if(size===8)return view.getBigInt64(offset,true);
  throw new RangeError('Unsupported original scalar raw-word width');
}
