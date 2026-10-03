import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import {
  AddressSpaceMemory, parsePE32, loadPE32,
  i8, u8, i16, u16, i32, u32, f32, truncFloatToI32,
  idiv32, irem32, udiv32, urem32, imul32, umul32, add32, sub32,
} from '../src/runtime/index.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));

test('original PE preferred addresses and virtual data extent match the executable', () => {
  const pe = parsePE32(original);
  assert.equal(pe.imageBase, 0x400000);
  assert.equal(pe.entryPoint, 0x457190);
  assert.equal(pe.sizeOfImage, 0x111000);
  assert.equal(pe.sizeOfHeaders, 0x400);
  assert.deepEqual(pe.sections.map(s => [s.name, s.address, s.virtualSize, s.rawSize, s.fileOffset]), [
    ['.text', 0x401000, 0x80716, 0x80800, 0x400],
    ['.rdata', 0x482000, 0xe550, 0xe600, 0x80c00],
    ['.data', 0x491000, 0x1fa48, 0x12400, 0x8f200],
    ['.idata', 0x4b1000, 0x23dc, 0x2400, 0xa1600],
    ['.rsrc', 0x4b4000, 0x5c73c, 0x5c800, 0xa3a00],
  ]);
});

test('all section bytes map exactly and uninitialized .data bytes are zero', () => {
  const memory = loadPE32(original);
  assert.deepEqual(memory.readBytes(0x400000, 0x400), new Uint8Array(original.subarray(0, 0x400)));
  for (const section of memory.pe.sections) {
    assert.deepEqual(memory.readBytes(section.address, section.rawSize),
      new Uint8Array(original.subarray(section.fileOffset, section.fileOffset + section.rawSize)));
  }
  assert.deepEqual(memory.readBytes(0x4a3400, 0xd648), new Uint8Array(0xd648));
  assert.deepEqual(memory.readBytes(0x400400, 0xc00), new Uint8Array(0xc00));
  assert.equal(memory.readU32(0x482000), 0x485538); // Real .rdata pointer, not an offset.
  assert.equal(memory.readU32(0x491004), 0x47b5d5); // Real initialized .data pointer.
  memory.writeI32(0x4a3400, -17);
  assert.equal(memory.readI32(0x4a3400), -17);
  assert.deepEqual(original.subarray(0x8f200, 0x8f204), Buffer.alloc(4));
});

test('loader supports a byte view with an offset and rejects truncated inputs', () => {
  const padded = new Uint8Array(original.length + 11);
  padded.set(original, 7);
  assert.equal(loadPE32(padded.subarray(7, 7 + original.length)).readU32(0x482000), 0x485538);
  assert.throws(() => parsePE32(original.subarray(0, 100)), /Truncated/);
  assert.throws(() => loadPE32(original, { maxImageSize: 1024 }), /size limit/);
  const bad = Uint8Array.from(original);
  bad[0] = 0;
  assert.throws(() => parsePE32(bad), /MZ/);
});

test('memory reads and writes are little-endian, unaligned, and alias correctly', () => {
  const memory = new AddressSpaceMemory(32, 0x400000);
  memory.writeU32(0x400001, 0x89abcdef);
  assert.deepEqual(memory.readBytes(0x400001, 4), Uint8Array.of(0xef, 0xcd, 0xab, 0x89));
  assert.equal(memory.readI32(0x400001), -1985229329);
  assert.equal(memory.readU16(0x400002), 0xabcd);
  assert.equal(memory.readI8(0x400001), -17);
  memory.writeI16(0x400002, -2);
  assert.equal(memory.readU32(0x400001), 0x89fffeef);
  memory.moveBytes(0x400002, 0x400001, 4);
  assert.deepEqual(memory.readBytes(0x400002, 4), Uint8Array.of(0xef, 0xfe, 0xff, 0x89));
  assert.throws(() => memory.readU32(0x40001d), /outside image/);
  assert.throws(() => memory.readU8(0x3fffff), /outside image/);
  assert.throws(() => memory.readU8(0x400000 + 0.5), /Invalid address/);
});

test('integer conversions preserve exact two\'s-complement wrapping', () => {
  assert.equal(i8(0x180), -128);
  assert.equal(u8(-1), 255);
  assert.equal(i16(0x18000), -32768);
  assert.equal(u16(-65537), 65535);
  assert.equal(i32(0x80000000), -2147483648);
  assert.equal(u32(-1), 4294967295);
  assert.equal(i32(0x1ffffffffn), -1);
  assert.equal(u32(0x123456789abcdefn), 0x89abcdef);
  assert.throws(() => i32(Number.MAX_SAFE_INTEGER + 1), /safe integer/);
  assert.throws(() => i32(3.5), /safe integer/);
  assert.equal(imul32(0x7fffffff, 0x7fffffff), 1);
  assert.equal(umul32(0xffffffff, 0xffffffff), 1);
  assert.equal(add32(0x7fffffff, 1), -2147483648);
  assert.equal(sub32(-2147483648, 1), 2147483647);
});

test('C integer quotient truncates toward zero and signed remainder follows dividend', () => {
  for (const [a, b, quotient, remainder] of [[7, 3, 2, 1], [-7, 3, -2, -1], [7, -3, -2, 1], [-7, -3, 2, -1]]) {
    assert.equal(idiv32(a, b), quotient);
    assert.equal(irem32(a, b), remainder);
    assert.equal(quotient * b + remainder, a);
  }
  assert.equal(idiv32(-1, 3), 0);
  assert.equal(irem32(-6, 3), 0);
  assert.equal(udiv32(0xffffffff, 2), 2147483647);
  assert.equal(urem32(0xffffffff, 2), 1);
  for (const operation of [idiv32, irem32, udiv32, urem32]) assert.throws(() => operation(1, 0), /zero/);
  assert.throws(() => idiv32(-2147483648, -1), /overflow/);
  assert.throws(() => irem32(-2147483648, -1), /overflow/);
});

test('binary32 stores round once at storage; binary64 and signed zero preserve bits', () => {
  const memory = new AddressSpaceMemory(32);
  assert.equal(f32(1 + 2 ** -24), 1); // Halfway, even significand.
  assert.equal(f32(1 + 3 * 2 ** -24), 1 + 2 ** -22);
  memory.writeF32(0x400000, 1 + 2 ** -24);
  assert.equal(memory.readU32(0x400000), 0x3f800000);
  memory.writeF64(0x400004, Math.PI);
  assert.equal(memory.readF64(0x400004), Math.PI);
  assert.equal(memory.readU32(0x400004), 0x54442d18);
  assert.equal(memory.readU32(0x400008), 0x400921fb);
  memory.writeF32(0x40000c, -0);
  assert.equal(memory.readU32(0x40000c), 0x80000000);
  assert.ok(Object.is(memory.readF32(0x40000c), -0));
  assert.equal(truncFloatToI32(-3.9), -3);
  assert.equal(truncFloatToI32(-0.1), 0);
  assert.throws(() => truncFloatToI32(Infinity), /explicit x87 model/);
  assert.throws(() => truncFloatToI32(2147483648), /explicit x87 model/);
});
