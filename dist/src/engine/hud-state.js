import { add32, sub32, imul32, i32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { wrapDegreesOnce } from './integer-core.js';
import { targetRelativeBearing } from './target-bearing.js';

export const HUD_STATE_ROUTINES = Object.freeze({
  updateDisplayedLeg: 0x42cf70, displayedTargetMark: 0x42d0c0,
  signedDegreesOnce: 0x415dc0, formatInteger: 0x413d00, formatDecimal: 0x413d90,
});
const at = (address, boat, stride = 4) => add32(address, imul32(boat, stride)) >>> 0;
const abs32 = value => value < 0 ? sub32(0, value) : value;

/** Original one-revolution wrap followed by the signed bearing selector. */
export function signedDegreesOnce(value) {
  const angle = wrapDegreesOnce(value);
  return angle > 180 ? sub32(angle, 360) : angle;
}

/** Original HUD/chart progress observer; this is separate from race-stage AI. */
export function updateDisplayedLeg(memory, boat) {
  boat = i32(boat);
  const legAddress = at(0x4a6ba0, boat);
  const time = memory.readI32(0x4a5b80);
  if (time < 0) {
    memory.writeI32(legAddress, 0);
    return;
  }
  if (time < 30) memory.writeI32(legAddress, 1);
  targetRelativeBearing(memory, memory.readI32(0x4aa594), memory.readI32(0x4aa59c), 0, boat);
  for (let offset = 0, leg = 1; offset < 9; offset += 4, leg++) {
    const bearing = wrapDegreesOnce(add32(memory.readI32(0x4a4758), 180));
    const courseBearing = wrapDegreesOnce(memory.readI32(0x4a6444 + offset));
    const difference = abs32(sub32(bearing, courseBearing));
    const sameDirection = bearing === courseBearing || difference === 360 || difference === 359
      || bearing === sub32(courseBearing, 1) || bearing === add32(courseBearing, 1);
    if (leg === memory.readI32(legAddress) && sameDirection
      && sub32(memory.readI32(0x4a645c + offset), 20) <= Float80.fromNumber(memory.readF64(0x4a6828)).truncI32()) {
      memory.writeI32(legAddress, add32(memory.readI32(legAddress), 1));
    }
  }
  if (memory.readI32(legAddress) === 4) {
    if (memory.readI32(0x4ac950) === 1 && memory.readI32(at(0x4a72d8, boat)) === 1) {
      memory.writeI32(legAddress, 1);
    }
    if (memory.readI32(legAddress) === 4) memory.writeI32(legAddress, 0);
  }
}

/** Invalid displayed-leg values preserve the prior global target selector. */
export function displayedTargetMark(memory, boat) {
  updateDisplayedLeg(memory, boat);
  const leg = memory.readI32(at(0x4a6ba0, i32(boat)));
  if (leg === 1) memory.writeI32(0x4aa7e0, 3);
  if (leg === 2) memory.writeI32(0x4aa7e0, 4);
  if (leg === 3) memory.writeI32(0x4aa7e0, 5);
  if (leg === 0) memory.writeI32(0x4aa7e0, 2);
  return memory.readI32(0x4aa7e0);
}

export const formatInteger = value => String(i32(value));

/** Original CString formatter: two signed truncations, with no zero padding. */
export function formatDecimal(memory, value) {
  const original = Float80.fromNumber(value);
  const integer = original.truncI32();
  const decimal = original.subtract(Float80.fromInteger(integer))
    .multiply(Float80.fromNumber(memory.readF64(0x484d58))).truncI32();
  return `${integer}${readAnsiString(memory, 0x49300c)}${decimal}`;
}

/** Original null-terminated ANSI bytes; decoder preserves Windows-1252 text. */
export function readAnsiString(memory, address, maximum = 65536) {
  const bytes = [];
  for (let offset = 0; offset < maximum; offset++) {
    const byte = memory.readU8((address + offset) >>> 0);
    if (byte === 0) return new TextDecoder('windows-1252').decode(new Uint8Array(bytes));
    bytes.push(byte);
  }
  throw new RangeError('Original ANSI string exceeds bounded read');
}
