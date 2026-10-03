import { i32, u32, add32, sub32, idiv32 } from '../../../../src/runtime/c-types.js';
import { scaledRandom } from '../../../../src/engine/integer-core.js';

// Original 0x41e000 retains a negative divisor after the absolute-value guard.
export { scaledRandom };

export const APPLICATION_ROUTINES = Object.freeze({
  initializeApplication: 0x402440, saveApplicationPreferences: 0x4036a0,
  updateSpeedDivisor: 0x464940, initializeIntegerTrig: 0x41e040,
  initializeWindRandomTable: 0x4413e0, scaledRandom: 0x41e000,
  wrapDegreesOnce: 0x41bc20, rand: 0x49b7b0, srand: 0x49b7a0,
});

// Original CArchive order, including repeated fields and the unaligned F64.
const beforeFloat = [
  0x4da19c,0x4da144,0x4da174,0x4da194,0x4da198,0x536484,0x536468,0x4da14c,
  0x4da154,0x4da140,0x536400,0x4da188,0x4f8b78,0x53646c,0x536424,0x53640c,
  0x4da158,0x536498,0x53643c,0x536454,0x53645c,0x523a5c,0x523a60,0x536480,
  0x5363e4,0x5363fc,0x4da1a8,0x536420,0x4da1ac,0x4da1d8,0x4da1a8,0x5363e0,
  0x536484,0x525a7c,0x525a80,0x4da1dc,0x4da1e8,0x5363dc,0x4da1f8,0x5363d0,
  0x5363d4,0x5363d8,0x5363dc,
];
const afterFloat = [
  ...Array.from({length:30},(_,index)=>0x4fbf34+index*16),
  ...Array.from({length:30},(_,index)=>0x4fbf38+index*16),
  ...Array.from({length:30},(_,index)=>0x4f49bc+index*4),
  0x4da238,0x4da23c,0x4da240,0x4da244,0x4da248,0x4da24c,0x4da250,0x4da254,
  0x4da258,0x4da25c,0x536504,0x522f08,0x536508,0x4da264,0x536500,0x4da260,
  0x4da268,0x53650c,0x536510,0x536514,0x536518,0x4da26c,0x536524,0x53641c,
];
export const PREFERENCE_FIELDS = Object.freeze([
  ...beforeFloat.map(address=>Object.freeze({address,type:'I32',bytes:4})),
  Object.freeze({address:0x4da230,type:'F64',bytes:8}),
  ...afterFloat.map(address=>Object.freeze({address,type:'I32',bytes:4})),
]);
export const PREFERENCE_BYTES = 636;

export function loadPreferences(memory, bytes) {
  if (!(bytes instanceof Uint8Array) || bytes.length !== PREFERENCE_BYTES) {
    throw new RangeError('The 2010 preference archive must contain exactly 636 bytes');
  }
  let offset = 0;
  for (const field of PREFERENCE_FIELDS) {
    memory.writeBytes(field.address, bytes.subarray(offset, offset + field.bytes));
    offset += field.bytes;
  }
}

export function serializePreferences(memory) {
  const bytes = new Uint8Array(PREFERENCE_BYTES);
  let offset = 0;
  for (const field of PREFERENCE_FIELDS) {
    bytes.set(memory.readBytes(field.address, field.bytes), offset);
    offset += field.bytes;
  }
  return bytes;
}

/** Original destructor's session store precedes every preference archive write. */
export function saveApplicationPreferences(memory) {
  if (memory.readI32(0x4da16c) === 1 && memory.readI32(0x536420) < 12) {
    memory.writeI32(0x536420, add32(memory.readI32(0x536420), 1));
  }
  return serializePreferences(memory);
}

export function wrapDegreesOnce(value) {
  value = i32(value);
  if (value >= 360) value = sub32(value, 360);
  if (value < 0) value = add32(value, 360);
  return value;
}

export function updateSpeedDivisor(memory) {
  const level = memory.readI32(0x4da174);
  const divisors = [2919,1946,1297,865,577,384,256,171,114,76,51,34,23,15,10];
  if (level >= 1 && level <= 15) memory.writeI32(0x4da178, divisors[level - 1]);
}

/** Complete 0x4413e0: 449 values, one original CRT RNG call per value. */
export function initializeWindRandomTable(memory, rng) {
  for (let address = 0x512d70; address < 0x513474; address += 4) {
    memory.writeI32(address, scaledRandom(100, rng));
  }
}

export function initializeIntegerTrig(memory, integerTrig) {
  if (!integerTrig || integerTrig.sine?.length !== 362 || integerTrig.cosine?.length !== 362) {
    throw new TypeError('Native 2010 integer sine and cosine reference tables are required');
  }
  for (let index = 0; index < 362; index++) {
    memory.writeI32(0x4f85c8 + index * 4, integerTrig.sine[index]);
    memory.writeI32(0x4f1740 + index * 4, integerTrig.cosine[index]);
  }
}

// All 56 pens and 34 brushes, in their original constructor request order.
export const ORIGINAL_GDI_DEFINITIONS = Object.freeze([
  Object.freeze({handleAddress:0x522d24,kind:'pen',style:0,widthDivisor:200,color:0x7f7900}),
  Object.freeze({handleAddress:0x523384,kind:'pen',style:0,widthDivisor:200,color:0x7f6e00}),
  Object.freeze({handleAddress:0x4fb254,kind:'pen',style:0,widthDivisor:150,color:0x7f7900}),
  Object.freeze({handleAddress:0x4f46a4,kind:'pen',style:0,widthDivisor:150,color:0x7f6e00}),
  Object.freeze({handleAddress:0x523654,kind:'pen',style:0,widthDivisor:150,color:0xa07800}),
  Object.freeze({handleAddress:0x535c64,kind:'pen',style:0,width:2,color:0xffff00}),
  Object.freeze({handleAddress:0x53560c,kind:'pen',style:0,widthDivisor:80,color:0xff00}),
  Object.freeze({handleAddress:0x5116dc,kind:'pen',style:0,widthDivisor:130,color:0xff00}),
  Object.freeze({handleAddress:0x4fb9e4,kind:'pen',style:0,widthDivisor:80,color:0xff}),
  Object.freeze({handleAddress:0x525a74,kind:'pen',style:0,widthDivisor:130,color:0xff}),
  Object.freeze({handleAddress:0x511774,kind:'pen',style:0,widthDivisor:80,color:0x7f7f7f}),
  Object.freeze({handleAddress:0x535494,kind:'pen',style:0,widthDivisor:130,color:0x7f7f7f}),
  Object.freeze({handleAddress:0x512d5c,kind:'pen',style:0,width:3,color:0x7f7f7f}),
  Object.freeze({handleAddress:0x4f1cf4,kind:'pen',style:0,widthDivisor:80,color:0x0}),
  Object.freeze({handleAddress:0x4f4154,kind:'pen',style:0,widthDivisor:130,color:0x0}),
  Object.freeze({handleAddress:0x534eb4,kind:'pen',style:0,widthDivisor:80,color:0xff0000}),
  Object.freeze({handleAddress:0x535174,kind:'pen',style:0,widthDivisor:130,color:0xff0000}),
  Object.freeze({handleAddress:0x4f4a64,kind:'pen',style:0,widthDivisor:130,color:0xffffff}),
  Object.freeze({handleAddress:0x4faa54,kind:'pen',style:0,width:3,color:0xffffff}),
  Object.freeze({handleAddress:0x4f7084,kind:'pen',style:0,width:2,color:0x0}),
  Object.freeze({handleAddress:0x535214,kind:'pen',style:0,width:3,color:0x0}),
  Object.freeze({handleAddress:0x522d14,kind:'pen',style:0,width:2,color:0x7f7f7f}),
  Object.freeze({handleAddress:0x5362fc,kind:'pen',style:0,width:2,color:0x3f3f3f}),
  Object.freeze({handleAddress:0x4fe174,kind:'pen',style:0,width:1,color:0x7f7f7f}),
  Object.freeze({handleAddress:0x4fb994,kind:'pen',style:0,width:2,color:0xff}),
  Object.freeze({handleAddress:0x522f1c,kind:'pen',style:0,width:2,color:0x7fff}),
  Object.freeze({handleAddress:0x4fdfdc,kind:'pen',style:0,width:2,color:0x7f}),
  Object.freeze({handleAddress:0x4fdfe4,kind:'pen',style:0,width:1,color:0x7f}),
  Object.freeze({handleAddress:0x4f40a4,kind:'pen',style:0,width:2,color:0x7fffff}),
  Object.freeze({handleAddress:0x5230c4,kind:'pen',style:0,width:2,color:0x7f}),
  Object.freeze({handleAddress:0x4f1cec,kind:'pen',style:0,width:2,color:0xff00}),
  Object.freeze({handleAddress:0x4f450c,kind:'pen',style:0,width:3,color:0xff0000}),
  Object.freeze({handleAddress:0x534e9c,kind:'pen',style:0,width:2,color:0x7f0000}),
  Object.freeze({handleAddress:0x522fbc,kind:'pen',style:0,width:1,color:0x7f0000}),
  Object.freeze({handleAddress:0x4f3a2c,kind:'pen',style:0,width:2,color:0x7f00}),
  Object.freeze({handleAddress:0x4f4a4c,kind:'pen',style:0,width:2,color:0x6e00}),
  Object.freeze({handleAddress:0x5362e4,kind:'pen',style:0,width:1,color:0x7f00}),
  Object.freeze({handleAddress:0x53516c,kind:'pen',style:0,width:2,color:0xff00ff}),
  Object.freeze({handleAddress:0x5230ac,kind:'pen',style:0,width:2,color:0x7f007f}),
  Object.freeze({handleAddress:0x4f7ec4,kind:'pen',style:0,width:2,color:0xffffff}),
  Object.freeze({handleAddress:0x5359c4,kind:'pen',style:0,width:3,color:0xffffff}),
  Object.freeze({handleAddress:0x4f3c0c,kind:'pen',style:0,width:1,color:0xff00}),
  Object.freeze({handleAddress:0x5362ec,kind:'pen',style:0,width:1,color:0xff}),
  Object.freeze({handleAddress:0x4fba14,kind:'pen',style:0,width:2,color:0xffff}),
  Object.freeze({handleAddress:0x52339c,kind:'pen',style:0,width:1,color:0xff00ff}),
  Object.freeze({handleAddress:0x4f4e4c,kind:'pen',style:0,width:1,color:0x7f007f}),
  Object.freeze({handleAddress:0x5125e4,kind:'pen',style:0,width:2,color:0xff00ff}),
  Object.freeze({handleAddress:0x5125ec,kind:'pen',style:0,width:4,color:0xff0000}),
  Object.freeze({handleAddress:0x4f49b4,kind:'pen',style:0,width:4,color:0xffff}),
  Object.freeze({handleAddress:0x4f408c,kind:'pen',style:0,width:4,color:0xff}),
  Object.freeze({handleAddress:0x4fe14c,kind:'pen',style:0,width:4,color:0x696900}),
  Object.freeze({handleAddress:0x4faf9c,kind:'pen',style:0,width:2,color:0x696900}),
  Object.freeze({handleAddress:0x4f468c,kind:'pen',style:0,widthDivisor:130,color:0xffffff}),
  Object.freeze({handleAddress:0x4f4474,kind:'pen',style:0,widthDivisor:200,color:0xffffff}),
  Object.freeze({handleAddress:0x4fb9a4,kind:'pen',style:0,width:4,color:0xa07800}),
  Object.freeze({handleAddress:0x4fe80c,kind:'pen',style:0,width:4,color:0x646400}),
  Object.freeze({handleAddress:0x4f4a5c,kind:'brush',color:0xffc87f}),
  Object.freeze({handleAddress:0x4f8c3c,kind:'brush',color:0xffff7f}),
  Object.freeze({handleAddress:0x4f7ed4,kind:'brush',color:0xb48c00}),
  Object.freeze({handleAddress:0x4f71d4,kind:'brush',color:0xd2aa00}),
  Object.freeze({handleAddress:0x5354a4,kind:'brush',color:0xa07800}),
  Object.freeze({handleAddress:0x5125f4,kind:'brush',color:0xff7f00}),
  Object.freeze({handleAddress:0x4f71b4,kind:'brush',color:0x969600}),
  Object.freeze({handleAddress:0x4fc15c,kind:'brush',color:0x7f7f00}),
  Object.freeze({handleAddress:0x523194,kind:'brush',color:0x696900}),
  Object.freeze({handleAddress:0x500414,kind:'brush',color:0xfa7f00}),
  Object.freeze({handleAddress:0x5359b4,kind:'brush',color:0x7f7900}),
  Object.freeze({handleAddress:0x5231a4,kind:'brush',color:0x7f7e00}),
  Object.freeze({handleAddress:0x4f8d6c,kind:'brush',color:0xe60000}),
  Object.freeze({handleAddress:0x4f3864,kind:'brush',color:0xff}),
  Object.freeze({handleAddress:0x525aac,kind:'brush',color:0x7f7f}),
  Object.freeze({handleAddress:0x4fb6ac,kind:'brush',color:0x7f}),
  Object.freeze({handleAddress:0x5359fc,kind:'brush',color:0xbe}),
  Object.freeze({handleAddress:0x4fb244,kind:'brush',color:0x7800}),
  Object.freeze({handleAddress:0x5363a4,kind:'brush',color:0x6400}),
  Object.freeze({handleAddress:0x4f6a54,kind:'brush',color:0x2000}),
  Object.freeze({handleAddress:0x5233b4,kind:'brush',color:0xff00}),
  Object.freeze({handleAddress:0x522fcc,kind:'brush',color:0xff0000}),
  Object.freeze({handleAddress:0x4fe16c,kind:'brush',color:0x7f0000}),
  Object.freeze({handleAddress:0x4f41ec,kind:'brush',color:0x7fff}),
  Object.freeze({handleAddress:0x4fb25c,kind:'brush',color:0xffff}),
  Object.freeze({handleAddress:0x525a94,kind:'brush',color:0x7f7f}),
  Object.freeze({handleAddress:0x4ff034,kind:'brush',color:0xff00ff}),
  Object.freeze({handleAddress:0x4f4d6c,kind:'brush',color:0x7f007f}),
  Object.freeze({handleAddress:0x4f7f74,kind:'brush',color:0x7fffff}),
  Object.freeze({handleAddress:0x4fe07c,kind:'brush',color:0x7f7f7f}),
  Object.freeze({handleAddress:0x5230cc,kind:'brush',color:0x3f3f3f}),
  Object.freeze({handleAddress:0x4fecc4,kind:'brush',color:0x303030}),
  Object.freeze({handleAddress:0x5363ac,kind:'brush',color:0x202020}),
  Object.freeze({handleAddress:0x4f3f5c,kind:'brush',color:0xbfbfbf}),
]);

/** Handle identity is supplied by the browser/GDI host, separate from game data. */
export function initializeGdiObjects(memory, options = {}) {
  const width = memory.readI32(0x4fe624), objects = new Map();
  for (const definition of ORIGINAL_GDI_DEFINITIONS) {
    const object = {kind:definition.kind,color:definition.color};
    if (object.kind === 'pen') {
      object.style = definition.style;
      object.width = definition.widthDivisor === undefined ? definition.width : idiv32(width, definition.widthDivisor);
    }
    const handle = u32(options.createGdiObject?.({...object,handleAddress:definition.handleAddress}) ?? definition.handleAddress);
    memory.writeU32(definition.handleAddress, handle);
    objects.set(handle, Object.freeze(object));
    options.attachGdiObject?.({objectAddress:definition.handleAddress-4,handle});
  }
  return objects;
}

/** Complete constructor game defaults, archive fields, sanitization and setup. */
export function initializeApplication(memory, rng, options = {}) {
  const {preferences=null,timeSeed,screenHeight,integerTrig} = options;
  if (!Number.isInteger(timeSeed) || !Number.isInteger(screenHeight)) {
    throw new TypeError('Original startup requires explicit time and screen-height inputs');
  }
  const r = address => memory.readI32(address), w = (address,value) => memory.writeI32(address,value);
  if (preferences === null) {
    for (const [address,value] of [[0x4da144,12],[0x4da190,6],[0x5363c0,0],[0x5363b8,0],[0x4da1f8,3],[0x4da19c,0],[0x4da174,7]]) w(address,value);
  } else loadPreferences(memory, preferences);
  if (r(0x4da16c) === 1) w(0x4da154,3);
  w(0x536450, Number(r(0x536454) === 1));
  if ([3,4,6].includes(r(0x4da188)) || r(0x4da19c) === 8) w(0x4da1e8,0);
  if (r(0x4da194) < 15) w(0x4da1e8,0);
  if (r(0x4da1dc) > 1 || r(0x4da1dc) < 0) w(0x4da1dc,0);
  for (const address of [0x525a7c,0x525a80]) if (r(address) < 0 || r(address) > 2) w(address,1);
  if (r(0x4da1d8) < 1 || r(0x4da1d8) > 10) w(0x4da1d8,5);
  if (r(0x4da194) === 2 && r(0x4da1d8) > 5) w(0x4da1d8,5);
  if (r(0x5363fc) > 2) w(0x5363fc,0);
  if (r(0x4da188) === 1) { w(0x4da168,1);w(0x5363f8,0); }
  if (r(0x4da188) === 2) { w(0x4da168,1);w(0x5363f8,0); }
  w(0x536408, Number(r(0x4da188) === 2));
  if (r(0x4da188) === 3) { w(0x4da168,0);w(0x5363f8,0); }
  if (r(0x4da188) === 4) { w(0x4da168,0);w(0x5363f8,0);w(0x536408,1); }
  if (r(0x4da188) === 6) { w(0x4da168,1);w(0x5363f8,0); }
  w(0x53527c, Number(r(0x4da188) === 6));
  if (r(0x4da188) === 7) { w(0x4da168,1);w(0x5363f8,0);w(0x53527c,1);w(0x536408,1); }
  if (r(0x4da188) === 5) { w(0x4da168,0);w(0x5363f8,1);w(0x536408,1); }
  if (r(0x4da19c) === 8) {
    for (const address of [0x5363f8,0x536408,0x53640c]) w(address,0);
    w(0x4da188,1);w(0x4da1e8,0);w(0x53527c,0);
  }
  if (r(0x4da19c) === 7) {
    for (const address of [0x4da168,0x5363f8,0x536408,0x53640c,0x4da1e8,0x53527c]) w(address,0);
    if (r(0x4da188) < 3 || r(0x4da188) > 4) w(0x4da188,3);
  }
  updateSpeedDivisor(memory);w(0x4da180,r(0x4da174));w(0x4da17c,r(0x4da178));
  w(0x4fe624,i32(screenHeight));
  initializeIntegerTrig(memory,integerTrig);
  rng.srand(u32(timeSeed));initializeWindRandomTable(memory,rng);
  return initializeGdiObjects(memory,options);
}
