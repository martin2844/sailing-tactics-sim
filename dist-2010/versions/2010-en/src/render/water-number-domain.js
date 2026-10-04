import {originalAddressSpaceMemoryState,addressSpaceMemoryIntrinsics} from '../../../../src/runtime/memory.js';
import {getX87ControlWord} from '../../../../src/runtime/float80.js';

const own=Object.getOwnPropertyDescriptor,prototypeOf=Object.getPrototypeOf;
const dataViewPrototype=DataView.prototype;
const byteLength=own(dataViewPrototype,'byteLength').get;
const buffer=own(dataViewPrototype,'buffer').get;
const arrayBufferByteLength=own(ArrayBuffer.prototype,'byteLength').get;
const getFloat64=own(dataViewPrototype,'getFloat64').value;
const {prototype:memoryPrototype,readF64,offset}=addressSpaceMemoryIntrinsics;
const data=(object,key)=>{
  const descriptor=own(object,key);
  return descriptor&&'value' in descriptor?descriptor:undefined;
};
const method=(object,key,expected)=>{
  const descriptor=own(object,key)??own(prototypeOf(object),key);
  return descriptor&&'value' in descriptor&&descriptor.value===expected;
};

// The brand check comes before every descriptor/prototype query. A Proxy,
// duck-typed host or subclass cannot make guard queries observable. Native
// DataView branding likewise precedes every query of the stored view object.
export function waterNumberMemoryEnabled(memory){
  const original=originalAddressSpaceMemoryState(memory);
  if(!original||getX87ControlWord()!==0x027f)return false;
  if(prototypeOf(memory)!==memoryPrototype||!method(memory,'readF64',readF64)
    ||!method(memory,'offset',offset))return false;
  const base=data(memory,'base'),size=data(memory,'size'),bytes=data(memory,'bytes'),view=data(memory,'view');
  if(!base||!size||!bytes||!view||base.value!==original.base||size.value!==original.size
    ||bytes.value!==original.bytes||view.value!==original.view
    ||!Number.isSafeInteger(base.value)||!Number.isSafeInteger(size.value)
    ||base.value<0||size.value<=0||base.value+size.value>0x100000000
    ||base.value>0x4cc5c8||base.value+size.value<0x4cc7b8)return false;
  let length;
  try{
    length=byteLength.call(view.value);
    // A subclass may have supplied a different buffer during the original
    // constructor's this.bytes.buffer read. Constructor identity alone does
    // not establish that the stored DataView is unshared.
    arrayBufferByteLength.call(buffer.call(view.value));
  }catch{return false;}
  if(length<size.value||prototypeOf(view.value)!==dataViewPrototype
    ||!method(view.value,'getFloat64',getFloat64))return false;
  return true;
}
