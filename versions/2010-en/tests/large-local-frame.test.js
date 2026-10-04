import test from 'node:test';
import assert from 'node:assert/strict';
import { Float80 } from '../../../src/runtime/float80.js';
import { createLocalFrame, framePointer, readLocal, readLocalFloatNumber, readLocalArgument, writeLocal } from '../src/render/typed-c.js';

test('large retained frames preserve byte images and validity across every 32-byte boundary', () => {
  for (const size of [96, 292, 688, 4096, 65536]) {
    const frame = createLocalFrame(size), bytes = new Uint8Array(size), valid = new Uint8Array(size);
    const expected = new DataView(bytes.buffer);
    const last = Math.floor((size - 8) / 4) * 4;
    for (const offset of new Set([0, 28, 60, 64, 88, last])) {
      if (offset + 8 > size) continue;
      const value = offset === 28 ? -0 : -123.456 - offset;
      writeLocal(framePointer(frame, offset), Float80.fromNumber(value), 8, 'float');
      expected.setFloat64(offset, value, true); valid.fill(1, offset, offset + 8);
      assert.ok(Object.is(readLocal(framePointer(frame, offset), 8, 'float').toNumber(), value));
    }
    // An undefined write straddles bit31/block1 and keeps the physical bytes.
    writeLocal(framePointer(frame, 31), undefined, 7); valid.fill(0, 31, 38);
    assert.equal(readLocalArgument(framePointer(frame, 28), 8, 'float'), undefined);
    assert.throws(() => readLocal(framePointer(frame, 28), 8, 'float'), /undefined retained local byte/);
    // A wider invalidation spans three distinct validity blocks.
    writeLocal(framePointer(frame, 17), undefined, 75); valid.fill(0, 17, 92);
    writeLocal(framePointer(frame, 64), 0x89abcdef, 4);
    expected.setInt32(64, 0x89abcdef, true); valid.fill(1, 64, 68);
    assert.equal(readLocal(framePointer(frame, 64), 4), 0x89abcdef | 0);
    assert.deepEqual(frame.bytes, bytes, `frame${size}: exact physical image`);
    assert.deepEqual(frame.valid, valid, `frame${size}: all per-byte validity`);
  }
});

test('large frame semantics, partial overwrites and public storage changes stay visible to escaped pointers', () => {
  const frame = createLocalFrame(688), escaped = framePointer(frame, 284);
  writeLocal(escaped, 'retained camera', 8, 'float');
  assert.equal(readLocal(escaped, 8, 'float'), 'retained camera');
  writeLocal(framePointer(frame, 288), 0x12345678, 4);
  assert.equal(frame.semantic.has(284), false);
  const image = Buffer.alloc(8); image.writeInt32LE(0x12345678, 4);
  assert.deepEqual(Buffer.from(frame.bytes.subarray(284, 292)), image);
  const replacementBuffer = new Uint8Array(720), replacement = replacementBuffer.subarray(16, 704);
  const view = new DataView(replacement.buffer, replacement.byteOffset, replacement.byteLength);
  frame.bytes = replacement;
  view.setFloat64(284, 12.5, true);
  assert.equal(readLocal(escaped, 8, 'float').toNumber(), 12.5);
  frame.valid[287] = 0;
  assert.equal(readLocalArgument(escaped, 8, 'float'), undefined);
  assert.throws(() => readLocal(escaped, 8, 'float'), /undefined retained local byte/);
  frame.valid[287] = 1;
  writeLocal(escaped, Float80.fromNumber(-9.25), 8, 'float');
  assert.equal(view.getFloat64(284, true), -9.25);
});

test('high aligned writes retain exact bounds, undefined inputs and failing host coercions', () => {
  const frame = createLocalFrame(292), at = framePointer(frame, 288);
  assert.equal(readLocalArgument(at, 4), undefined);
  writeLocal(at, 0x12345678, 4);
  const invalid = { frame: null, valueOf() { throw new RangeError('retained coercion failed'); } };
  assert.throws(() => writeLocal(at, invalid, 4), { name: 'RangeError', message: 'retained coercion failed' });
  assert.equal(readLocal(at, 4), 0x12345678);
  for (const operation of [() => readLocal(at, 8, 'float'), () => writeLocal(at, 1, 8, 'float'),
    () => readLocalArgument(framePointer(frame, 290), 4)]) assert.throws(operation, /memory access exceeds frame/);
  writeLocal(at, undefined, 4);
  assert.throws(() => readLocal(at, 4), /undefined retained local byte/);
  assert.equal(readLocalArgument(at, 4), undefined);
  const view = new DataView(frame.bytes.buffer);
  assert.equal(view.getInt32(288, true), 0x12345678, 'invalidating a local never fabricates or clears its bytes');
});

test('direct Number loads preserve the exact binary64 images, signed zeros and extended-load failures', () => {
  const bits = new DataView(new ArrayBuffer(8));
  const values = [0, -0, Number.MIN_VALUE, -Number.MIN_VALUE, Number.MAX_VALUE, -Number.MAX_VALUE,
    2 ** -1022, -(2 ** -1022), Math.PI, -123.456];
  let seed = 0x137aba51;
  const next = () => seed = (Math.imul(seed, 1664525) + 1013904223) >>> 0;
  for (let index = 0; index < 500; index++) {
    bits.setUint32(0, next(), true); bits.setUint32(4, next(), true);
    const value = bits.getFloat64(0, true);
    if (Number.isFinite(value)) values.push(value);
  }
  for (const value of values) for (const offset of [0, 28, 64, 284, 680]) {
    const frame = createLocalFrame(688), at = framePointer(frame, offset);
    bits.setFloat64(0, value, true);
    writeLocal(at, bits.getInt32(0, true), 4);
    writeLocal(framePointer(frame, offset + 4), bits.getInt32(4, true), 4);
    assert.ok(Object.is(readLocalFloatNumber(at), value), `${offset}: exact binary64 Number image`);
    assert.ok(Object.is(readLocalFloatNumber(at), readLocal(at, 8, 'float').toNumber()));
  }
  for (const value of [Infinity, -Infinity, NaN]) {
    const frame = createLocalFrame(688), at = framePointer(frame, 284);
    bits.setFloat64(0, value, true);
    writeLocal(at, bits.getInt32(0, true), 4);
    writeLocal(framePointer(frame, 288), bits.getInt32(4, true), 4);
    let originalError;
    try { readLocal(at, 8, 'float'); } catch (error) { originalError = error; }
    assert.throws(() => readLocalFloatNumber(at), { name: originalError.name, message: originalError.message });
  }
});

test('direct Number loads preserve semantic slots, array replacements and strict unknown/bounds errors', () => {
  const frame = createLocalFrame(688), at = framePointer(frame, 284), semantic = { frame: { retained: true }, offset: 0 };
  writeLocal(at, semantic, 8, 'float');
  assert.equal(readLocalFloatNumber(at), semantic);
  writeLocal(at, negativeZero(), 8, 'float');
  const buffer = new Uint8Array(720), replacement = buffer.subarray(16, 704);
  const view = new DataView(replacement.buffer, replacement.byteOffset, replacement.byteLength);
  replacement.set(frame.bytes); frame.bytes = replacement;
  view.setFloat64(284, -Number.MIN_VALUE, true);
  assert.ok(Object.is(readLocalFloatNumber(at), -Number.MIN_VALUE));
  frame.valid[287] = 0;
  for (const pointer of [at, framePointer(frame, -1), framePointer(frame, 684), framePointer(frame, 688)]) {
    let originalError;
    try { readLocal(pointer, 8, 'float'); } catch (error) { originalError = error; }
    assert.throws(() => readLocalFloatNumber(pointer), { name: originalError.name, message: originalError.message });
  }
  frame.valid[287] = 1;
  for (const offset of [284.5, '284', '0x11c', NaN, undefined]) {
    const pointer = framePointer(frame, offset);
    let original, originalError;
    try { original = readLocal(pointer, 8, 'float'); } catch (error) { originalError = error; }
    if (originalError) assert.throws(() => readLocalFloatNumber(pointer), { name: originalError.name, message: originalError.message });
    else assert.ok(Object.is(readLocalFloatNumber(pointer), original.toNumber()));
  }
});

function negativeZero() { return Float80.fromNumber(-0); }
