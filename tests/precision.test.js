import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { Float80,withX87ControlWord,getX87ControlWord } from '../src/runtime/float80.js';
import { atan2Extended } from '../src/runtime/atan.js';
const fixture=JSON.parse(await readFile(new URL('./fixtures/native-precision.json',import.meta.url),'utf8'));
const f=bits=>Float80.fromBytes(Uint8Array.from(Buffer.from(bits,'hex'))),hex=value=>Buffer.from(value.toBytes()).toString('hex');
const storedHex=value=>{const bytes=Buffer.alloc(8);bytes.writeDoubleLE(value.toNumber());return bytes.toString('hex');};
test('24/53/64-bit x87 arithmetic matches independent native instruction results',async()=>{
  const source=await readFile(new URL('../tools/capture_precision_native.c',import.meta.url));assert.equal(createHash('sha256').update(source).digest('hex'),fixture.provenance.probeSha256);
  const failures=[];
  for(const [index,row] of fixture.cases.entries()){
    try{
      const actual=withX87ControlWord(row.controlWord,()=>row.operation==='sqrt'?f(row.leftBits).sqrt():f(row.leftBits)[row.operation](f(row.rightBits)));
      if(hex(actual)!==row.expected.extendedBits)failures.push({index,controlWord:row.controlWord,operation:row.operation,actual:hex(actual),expected:row.expected.extendedBits});
      if(storedHex(actual)!==row.expected.storedDoubleBits)failures.push({index,store:storedHex(actual),expected:row.expected.storedDoubleBits});
    }catch(error){failures.push({index,error:error.message});}
  }
  assert.equal(failures.length,0,JSON.stringify(failures.slice(0,15)));assert.equal(getX87ControlWord(),0x037f);
});

test('FPATAN small-ratio results retain native m80 precision under PC24/53/64 (108)',async()=>{
  const capture=JSON.parse(await readFile(new URL('./fixtures/native-atan-precision.json',import.meta.url),'utf8'));
  const source=await readFile(new URL('../tools/capture_atan_precision_native.c',import.meta.url));
  assert.equal(createHash('sha256').update(source).digest('hex'),capture.provenance.probeSha256);
  for(const [index,row] of capture.cases.entries()){
    const actual=withX87ControlWord(row.controlWord,()=>atan2Extended(f(row.yBits),f(row.xBits)));
    assert.equal(hex(actual),row.expected.extendedBits,`native FPATAN m80 ${index}`);
    assert.equal(storedHex(actual),row.expected.bits,`native FPATAN F64 ${index}`);
  }
  assert.equal(getX87ControlWord(),0x037f);
});
