import {i32,u32} from '../../../../src/runtime/c-types.js';
import {cString,writeLocal,pointerAdd} from './typed-c.js';

export function createDrawingHost(options={}) {
  return {...options,drawingHost:{tick:u32(options.tickStart??0),reads:0}};
}
export function drawingTick(options) {
  if(typeof options.getTickCount==='function')return u32(options.getTickCount());
  const host=options.drawingHost??(options.drawingHost={tick:u32(options.tickStart??0),reads:0});
  if(++host.reads>1_000_000)throw new RangeError('Original drawing tick loop exceeded its bound');
  const result=host.tick;host.tick=u32(result+1);return result;
}
export function drawingSystemMetric(index,options={}) {
  if(index!==15)throw new RangeError('Unbound original drawing system metric');
  const height=i32(options.menuHeight??20);
  if(height<0 || height>128)throw new RangeError('Original menu height exceeds its host contract');
  return height;
}
export function drawingSound(options,resource,moduleHandle,flags){
  const request={resourceId:u32(resource),moduleHandle:u32(moduleHandle),flags:u32(flags)};
  if(typeof options.playSound!=='function')throw new TypeError('Original drawing sound requires an explicit host callback');
  options.playSound(request);return 1;
}
export function drawingCursor(options){
  const value=typeof options.getCursorPos==='function'?options.getCursorPos():options.cursor;
  if(!value||!Number.isInteger(value.x)||!Number.isInteger(value.y))throw new TypeError('Original drawing requires explicit cursor coordinates');
  return {x:i32(value.x),y:i32(value.y)};
}
const decode=new TextDecoder('windows-1252');
const ansi=new Map(Array.from({length:256},(_,byte)=>[decode.decode(Uint8Array.of(byte)),byte]));
/** Original game uses only %d/%% here; output is an ANSI local buffer. */
export function drawingPrintf(memory,destination,format,...values) {
  format=cString(memory,format);let argument=0;
  const text=format.replace(/%(?:%|d)/g,token=>token==='%%'?'%':String(i32(values[argument++])));
  if(/%(?!%|d)/.test(format.replace(/%%|%d/g,'')) || argument!==values.length)throw new RangeError('Unsupported original drawing printf contract');
  const bytes=Array.from(text,char=>{
    const value=ansi.get(char);if(value===undefined)throw new RangeError('Original printf text exceeds ANSI');return value;
  });
  if(destination?.frame){
    if(destination.offset<0||destination.offset+bytes.length>=destination.frame.bytes.length)throw new RangeError('Original printf local buffer exceeds its bound');
    bytes.push(0);for(let index=0;index<bytes.length;index++)writeLocal(pointerAdd(destination,index),bytes[index],1);
    return bytes.length-1;
  }
  if(!destination?.array || destination.offset<0 || destination.offset+bytes.length>=destination.array.length)throw new RangeError('Original printf local buffer exceeds its bound');
  bytes.push(0);for(let index=0;index<bytes.length;index++)destination.array[destination.offset+index]=bytes[index];
  return bytes.length-1;
}
