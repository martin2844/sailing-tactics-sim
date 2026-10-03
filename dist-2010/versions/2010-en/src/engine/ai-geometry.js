import { add32, sub32, imul32, idiv32, i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { atan2Extended } from '../../../../src/runtime/atan.js';
import { wrapDegreesOnce } from './application.js';
import { distanceToBoat } from './movement.js';

export const AI_GEOMETRY_ROUTINES = Object.freeze({
  signedDegrees: 0x41e3a0, updateTack: 0x435f90, setClosehauledHeading: 0x437520,
  signedStartDistance: 0x437d40, relativeProjection: 0x439ec0,
  targetRelativeBearing: 0x43ec20, aheadAstern: 0x464050,
});
const at = (base, boat, stride = 4) => add32(base, imul32(boat, stride)) >>> 0;
const number = Float80.fromInteger;
const floating = (memory, address) => Float80.fromNumber(memory.readF64(address));
const spill = value => Float80.fromNumber(value.toNumber());
const trig = (options, angle) => {
  if (typeof options.trig?.extended !== 'function') throw new TypeError('Native 2010 integer-angle reference required');
  return options.trig.extended(angle);
};

/** Original 0x41e3a0: one degree wrap, then signed representation. */
export function signedDegrees(value) {
  value = wrapDegreesOnce(i32(value));
  return value > 180 ? sub32(value, 360) : value;
}

/** Original 0x435f90; the subtraction intentionally precedes any angle wrap. */
export function updateTack(memory, boat) {
  boat = i32(boat);
  const difference = sub32(memory.readI32(at(0x535740, boat)), memory.readI32(at(0x522b90, boat)));
  memory.writeI32(at(0x522ff0, boat), (difference > 0 && difference < 180) || difference < -180 ? -1 : 1);
}

/** Original 0x437520, including the first boat's signed integer HUD field. */
export function setClosehauledHeading(memory, boat) {
  boat = i32(boat);
  const limit = add32(memory.readI32(0x4f7200), memory.readI32(at(0x5359e0, boat)));
  if (boat === 1) memory.writeI32(0x4f8390, limit);
  const heading = sub32(memory.readI32(at(0x522b90, boat)), imul32(memory.readI32(at(0x522ff0, boat)), limit));
  memory.writeI32(at(0x535740, boat), wrapDegreesOnce(heading));
}

/** Complete 0x437d40; retained ST0, explicit binary64 spills and venue-five factor. */
export function signedStartDistance(memory, boat) {
  boat = i32(boat);
  const cx = number(memory.readI32(0x5229d4)), cy = number(memory.readI32(0x522ac8));
  const dx = spill(floating(memory, at(0x4f6af8, boat, 8)).subtract(cx));
  const dy = floating(memory, at(0x4f6c10, boat, 8)).subtract(cy);
  const midpointX = idiv32(add32(memory.readI32(0x536410), memory.readI32(0x4fe094)), 2);
  const midpointY = idiv32(add32(memory.readI32(0x536414), memory.readI32(0x4fe2a0)), 2);
  const referenceX = spill(number(midpointX).subtract(cx));
  const referenceY = number(midpointY).subtract(cy);
  // The native literal is binary64 0x3ff00c49ba5e353f, loaded only for this venue/time branch.
  const factor = Float80.fromNumber(memory.readI32(0x4da1f8) === 5 && memory.readI32(0x4f8cd0) < 10 ? 1.003 : 1);
  const positionDistance = spill(dx.multiply(dx).add(dy.multiply(spill(dy))).sqrt().multiply(factor));
  return positionDistance.subtract(referenceX.multiply(referenceX).add(referenceY.multiply(referenceY)).sqrt());
}

/** Complete 0x439ec0. Original __ftol returns signed64; callers usually use low32. */
export function relativeProjection(memory, boat1, selector, boat2, options = {}) {
  boat1 = i32(boat1); selector = i32(selector); boat2 = i32(boat2);
  const x = floating(memory, at(0x4f6af8, boat1, 8));
  const y = floating(memory, at(0x4f6c10, boat1, 8));
  const { sine, cosine } = trig(options, memory.readI32(at(selector === 1 ? 0x535740 : 0x522b90, boat1)));
  let px, py;
  if (selector === 1) {
    const tack = number(memory.readI32(at(0x522ff0, boat1))), scale = floating(memory, 0x4cca10);
    px = x.subtract(cosine.multiply(tack).multiply(scale));
    py = y.subtract(sine.multiply(tack).multiply(scale));
  } else {
    px = x.subtract(sine.multiply(floating(memory, 0x4cca10)));
    py = y.subtract(cosine.multiply(floating(memory, 0x4cca18)));
  }
  const dx = px.subtract(x), dy = py.subtract(y);
  const selfSquared = dy.multiply(dy).add(dx.multiply(spill(dx)));
  const zero = floating(memory, 0x4cc658);
  const selfDistance = selfSquared.compare(zero) > 0 ? spill(selfSquared.sqrt()) : number(100);
  const otherX = px.subtract(floating(memory, at(0x4f6af8, boat2, 8)));
  const otherY = py.subtract(floating(memory, at(0x4f6c10, boat2, 8)));
  const otherSquared = otherY.multiply(spill(otherY)).add(otherX.multiply(spill(otherX)));
  return selfDistance.subtract(otherSquared.compare(zero) > 0 ? otherSquared.sqrt() : floating(memory, 0x4cc488)).truncI64();
}

/** Original 0x43ec20 cdecl(F64,F64,I32,I32)->ST0, including unhandled-selector behavior. */
export function targetRelativeBearing(memory, targetX, targetY, selector, boat) {
  selector = i32(selector); boat = i32(boat);
  const x = selector < 2 ? floating(memory, at(0x4f6af8, boat, 8)) : number(memory.readI32(0x536410));
  const y = selector < 2 ? floating(memory, at(0x4f6c10, boat, 8)) : number(memory.readI32(0x536414));
  const dy = y.subtract(Float80.fromNumber(targetY));
  const retainedX = Float80.fromNumber(targetX).subtract(x), storedX = spill(retainedX);
  memory.writeF64(0x4fbb88, dy.multiply(dy).add(retainedX.multiply(storedX)).sqrt().toNumber());
  const zero = floating(memory, 0x4cc658);
  const angle = storedX.compare(zero) === 0
    ? (dy.compare(zero) <= 0 ? floating(memory, 0x4cc740) : zero)
    : atan2Extended(storedX, dy);
  memory.writeI32(0x4f4b40, angle.multiply(floating(memory, 0x4cc3e8)).truncI32());
  let result = storedX;
  const relative = address => spill(angle.subtract(number(memory.readI32(at(address, boat))).multiply(floating(memory, 0x4cc568))));
  if (selector === -1) result = relative(0x4fbb90);
  if (selector === 1 || selector === 2) {
    const mode = memory.readI32(at(0x525a78, boat));
    if (mode === 0) result = relative(0x4fbb90);
    if (mode === 1) result = relative(0x535740);
    if (mode === 2) result = relative(0x522b90);
  }
  return selector !== 0 && selector < 3 ? result : spill(angle);
}

/** Original 0x464050, preserving projected coordinates and first distance stores. */
export function aheadAstern(memory, boat1, boat2, options = {}) {
  boat1 = i32(boat1); boat2 = i32(boat2);
  const { sine, cosine } = trig(options, memory.readI32(at(0x522b90, boat1)));
  const x = floating(memory, at(0x4f6af8, boat1, 8)).subtract(sine.multiply(floating(memory, 0x4ccc98))).toNumber();
  const y = floating(memory, at(0x4f6c10, boat1, 8)).subtract(cosine.multiply(floating(memory, 0x4ccca0))).toNumber();
  return spill(distanceToBoat(memory, boat2, x, y)).subtract(distanceToBoat(memory, boat1, x, y)).truncI64();
}

export const projectionLow32 = value => Number(BigInt.asIntN(32, value));
