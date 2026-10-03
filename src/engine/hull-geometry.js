import { Float80 } from '../runtime/float80.js';

const fromHex = bits => Float80.fromBytes(Uint8Array.from(bits.match(/../g), byte => parseInt(byte, 16)));

/** Decoder for measured native FSIN outputs using the original hull scale order. */
export function createHullTrig(capture) {
  if (capture?.provenance?.authoritative_engine !== 'native-x87') throw new TypeError('Native hull trig capture required');
  return (angle, { optimist = false } = {}) => {
    const row = capture.variants?.[optimist ? 'optimist' : 'standard']?.[angle];
    if (!row) throw new RangeError(`Uncaptured native hull angle ${angle}`);
    return Object.freeze({ sine: fromHex(row.sineBits), cosine: fromHex(row.cosineBits) });
  };
}

const f = (memory, address) => Float80.fromNumber(memory.readF64(address));
const i = value => Float80.fromInteger(value);
function centers(memory, step) {
  for (let index = 0; index < 6; index++) {
    memory.writeBytes(0x4ac310 + index * 8, memory.readBytes(0x4ac320, 8));
    memory.writeF64(0x4a3a38 + index * 8, f(memory, 0x4a3a48).subtract(i(index - 2).multiply(step)).toNumber());
  }
}

/** Complete 0x412f60. Width-offset storage does not round the retained sum operand. */
export function initializeCurvedHull(memory, length, width, options = {}) {
  if (!options.hullTrig) throw new Error('Native hull FSIN reference is required');
  const optimist = memory.readI32(0x4ac914) === 1;
  const step = Float80.fromNumber(length).multiply(f(memory, 0x484d48));
  const width80 = Float80.fromNumber(width);
  centers(memory, step);
  memory.writeF64(0x4a3a90, f(memory, 0x4a3a38).subtract(step.multiply(f(memory, 0x484e48))).toNumber());
  memory.writeBytes(0x4ac368, memory.readBytes(0x4ac310, 8));
  for (let index = 0; index < 5; index++) {
    const baseline = f(memory, 0x4ac338);
    const offset = options.hullTrig((index + 1) * 29, { optimist }).sine.multiply(width80).multiply(f(memory, 0x484e50));
    memory.writeF64(0x4a3a88 - index * 8, i(index + 1).multiply(step).add(f(memory, 0x4a3a60)).toNumber());
    memory.writeF64(0x4a7a48 - index * 8, offset.toNumber());
    memory.writeF64(0x4ac360 - index * 8, baseline.add(offset).toNumber());
  }
  for (let index = 0; index < 5; index++) {
    const baseline = f(memory, 0x4ac338);
    const offset = options.hullTrig((index + 1) * 29, { optimist }).sine.multiply(width80).multiply(f(memory, 0x484e58));
    memory.writeF64(0x4a3a98 + index * 8, i(index + 1).multiply(step).add(f(memory, 0x4a3a60)).toNumber());
    memory.writeF64(0x4a7a58 + index * 8, offset.toNumber());
    memory.writeF64(0x4ac370 + index * 8, baseline.add(offset).toNumber());
  }
  if (optimist) memory.writeBytes(0x4a3a60, memory.readBytes(0x4a3a58, 8));
}

/** Complete 0x413100: original rectangular hull with its binary64 spill points. */
export function initializeFlatHull(memory, length, width) {
  const stepExact = Float80.fromNumber(length).multiply(f(memory, 0x484d48));
  const stepStored = Float80.fromNumber(stepExact.toNumber());
  centers(memory, stepExact);
  const width80 = Float80.fromNumber(width);
  memory.writeF64(0x4a7a40, width80.multiply(f(memory, 0x484e60)).toNumber());
  memory.writeF64(0x4a7a38, width80.multiply(f(memory, 0x484e50)).toNumber());
  memory.writeF64(0x4a7a68, width80.multiply(f(memory, 0x484e68)).toNumber());
  memory.writeF64(0x4a7a60, width80.multiply(f(memory, 0x484e58)).toNumber());
  for (const [target, source] of [[0x4a7a30, 0x4a7a40], [0x4a7a28, 0x4a7a38], [0x4a7a78, 0x4a7a68]]) memory.writeBytes(target, memory.readBytes(source, 8));
  memory.writeF64(0x4a7a58, width80.negate().toNumber());
  memory.writeF64(0x4ac360, width80.add(f(memory, 0x4ac338)).toNumber());
  memory.writeF64(0x4a3a90, f(memory, 0x4a3a38).subtract(stepStored.multiply(f(memory, 0x484e48))).toNumber());
  for (const [target, source] of [[0x4ac358, 0x4a7a40], [0x4ac350, 0x4a7a38], [0x4ac348, 0x4a7a30], [0x4ac340, 0x4a7a28], [0x4ac370, 0x4a7a58], [0x4ac380, 0x4a7a68], [0x4ac378, 0x4a7a60], [0x4ac390, 0x4a7a78], [0x4ac388, 0x4a7a60]]) memory.writeF64(target, f(memory, source).add(f(memory, 0x4ac338)).toNumber());
  for (const [target, source] of [[0x4ac368, 0x4ac310], [0x4a3a88, 0x4a3a60], [0x4a3a80, 0x4a3a50], [0x4a3a78, 0x4a3a50], [0x4a3a70, 0x4a3a38], [0x4a3a68, 0x4a3a38], [0x4a3a98, 0x4a3a60], [0x4a3aa8, 0x4a3a50], [0x4a3aa0, 0x4a3a50], [0x4a3ab8, 0x4a3a38], [0x4a3ab0, 0x4a3a38], [0x4a7a70, 0x4a7a60]]) memory.writeBytes(target, memory.readBytes(source, 8));
  memory.writeF64(0x4a7a48, width80.toNumber());
}

export const HULL_GEOMETRY_ROUTINES = Object.freeze({ initializeCurvedHull: 0x412f60, initializeFlatHull: 0x413100 });
