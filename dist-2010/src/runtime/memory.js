import { i8, u8, i16, u16, i32, u32 } from './c-types.js';

export const POSEY_IMAGE_BASE = 0x00400000;

function integerRange(value, minimum, maximum, description) {
  if (!Number.isSafeInteger(value) || value < minimum || value > maximum) {
    throw new RangeError(`Invalid ${description}: ${value}`);
  }
  return value;
}

function asBytes(value) {
  if (value instanceof Uint8Array) return value;
  if (value instanceof ArrayBuffer) return new Uint8Array(value);
  throw new TypeError('Expected a Uint8Array or ArrayBuffer');
}

/** Byte-addressable memory indexed by original absolute x86 addresses. */
export class AddressSpaceMemory {
  constructor(size, base = POSEY_IMAGE_BASE) {
    integerRange(base, 0, 0xffffffff, 'memory base');
    integerRange(size, 1, 0x100000000 - base, 'memory size');
    this.base = base;
    this.size = size;
    this.bytes = new Uint8Array(size);
    this.view = new DataView(this.bytes.buffer);
  }

  offset(address, width = 1) {
    integerRange(address, 0, 0xffffffff, 'address');
    integerRange(width, 0, this.size, 'access width');
    const offset = address - this.base;
    if (offset < 0 || offset + width > this.size) {
      throw new RangeError(`Memory access outside image at 0x${address.toString(16)} (${width} bytes)`);
    }
    return offset;
  }

  readU8(address) { return this.view.getUint8(this.offset(address)); }
  readI8(address) { return this.view.getInt8(this.offset(address)); }
  readU16(address) { return this.view.getUint16(this.offset(address, 2), true); }
  readI16(address) { return this.view.getInt16(this.offset(address, 2), true); }
  readU32(address) { return this.view.getUint32(this.offset(address, 4), true); }
  readI32(address) { return this.view.getInt32(this.offset(address, 4), true); }
  readF32(address) { return this.view.getFloat32(this.offset(address, 4), true); }
  readF64(address) { return this.view.getFloat64(this.offset(address, 8), true); }

  writeU8(address, value) { this.view.setUint8(this.offset(address), u8(value)); }
  writeI8(address, value) { this.view.setInt8(this.offset(address), i8(value)); }
  writeU16(address, value) { this.view.setUint16(this.offset(address, 2), u16(value), true); }
  writeI16(address, value) { this.view.setInt16(this.offset(address, 2), i16(value), true); }
  writeU32(address, value) { this.view.setUint32(this.offset(address, 4), u32(value), true); }
  writeI32(address, value) { this.view.setInt32(this.offset(address, 4), i32(value), true); }
  writeF32(address, value) { this.view.setFloat32(this.offset(address, 4), value, true); }
  writeF64(address, value) { this.view.setFloat64(this.offset(address, 8), value, true); }

  readBytes(address, length) {
    const offset = this.offset(address, length);
    return this.bytes.slice(offset, offset + length);
  }

  writeBytes(address, source) {
    const bytes = asBytes(source);
    this.bytes.set(bytes, this.offset(address, bytes.length));
  }

  /** Overlap-safe copying, matching memmove. */
  moveBytes(destination, source, length) {
    const from = this.offset(source, length);
    const to = this.offset(destination, length);
    this.bytes.copyWithin(to, from, from + length);
  }
}

/** Read the PE32 preferred image layout without invoking Windows or Node APIs. */
export function parsePE32(source) {
  const bytes = asBytes(source);
  const view = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
  const requireBytes = (offset, width) => {
    if (!Number.isSafeInteger(offset) || offset < 0 || offset + width > bytes.length) {
      throw new RangeError('Truncated PE32 file');
    }
  };
  requireBytes(0, 0x40);
  if (view.getUint16(0, true) !== 0x5a4d) throw new TypeError('Missing DOS MZ signature');
  const peOffset = view.getUint32(0x3c, true);
  requireBytes(peOffset, 24);
  if (view.getUint32(peOffset, true) !== 0x00004550) throw new TypeError('Missing PE signature');
  const machine = view.getUint16(peOffset + 4, true);
  if (machine !== 0x14c) throw new TypeError('Runtime supports x86 PE32 images only');
  const numberOfSections = view.getUint16(peOffset + 6, true);
  const optionalSize = view.getUint16(peOffset + 20, true);
  const optionalOffset = peOffset + 24;
  requireBytes(optionalOffset, optionalSize);
  if (optionalSize < 96 || view.getUint16(optionalOffset, true) !== 0x10b) {
    throw new TypeError('Missing PE32 optional header');
  }
  const imageBase = view.getUint32(optionalOffset + 28, true);
  const sizeOfImage = view.getUint32(optionalOffset + 56, true);
  const sizeOfHeaders = view.getUint32(optionalOffset + 60, true);
  if (!sizeOfImage || imageBase + sizeOfImage > 0x100000000) throw new RangeError('Invalid PE image extent');
  if (sizeOfHeaders > sizeOfImage) throw new RangeError('PE headers exceed image');
  requireBytes(0, sizeOfHeaders);
  const sectionTable = optionalOffset + optionalSize;
  requireBytes(sectionTable, numberOfSections * 40);
  const sections = [];
  for (let index = 0; index < numberOfSections; index++) {
    const offset = sectionTable + index * 40;
    let name = '';
    for (let i = 0; i < 8 && bytes[offset + i] !== 0; i++) name += String.fromCharCode(bytes[offset + i]);
    const virtualSize = view.getUint32(offset + 8, true);
    const rva = view.getUint32(offset + 12, true);
    const rawSize = view.getUint32(offset + 16, true);
    const fileOffset = view.getUint32(offset + 20, true);
    const mappedSize = Math.max(virtualSize, rawSize);
    if (rva + mappedSize > sizeOfImage) throw new RangeError(`Section ${name} exceeds PE image`);
    if (rawSize) requireBytes(fileOffset, rawSize);
    sections.push(Object.freeze({
      name, rva, address: imageBase + rva, virtualSize, rawSize, fileOffset,
      mappedSize, characteristics: view.getUint32(offset + 36, true),
    }));
  }
  return Object.freeze({
    machine, imageBase, sizeOfImage, sizeOfHeaders,
    entryPoint: imageBase + view.getUint32(optionalOffset + 16, true),
    sectionAlignment: view.getUint32(optionalOffset + 32, true),
    fileAlignment: view.getUint32(optionalOffset + 36, true),
    sections: Object.freeze(sections),
  });
}

/**
 * Map headers and section bytes at their preferred addresses. Raw padding is
 * retained; virtual tails and image gaps start as zero, including Posey's BSS.
 * This does not execute code or resolve the Windows import address table.
 */
export function loadPE32(source, { maxImageSize = 256 * 1024 * 1024 } = {}) {
  const bytes = asBytes(source);
  const pe = parsePE32(bytes);
  integerRange(maxImageSize, 1, 0x100000000, 'maximum image size');
  if (pe.sizeOfImage > maxImageSize) throw new RangeError('PE image exceeds configured size limit');
  const memory = new AddressSpaceMemory(pe.sizeOfImage, pe.imageBase);
  memory.writeBytes(pe.imageBase, bytes.subarray(0, pe.sizeOfHeaders));
  for (const section of pe.sections) {
    if (section.rawSize) {
      memory.writeBytes(section.address, bytes.subarray(section.fileOffset, section.fileOffset + section.rawSize));
    }
  }
  Object.defineProperty(memory, 'pe', { value: pe, enumerable: true });
  return memory;
}
