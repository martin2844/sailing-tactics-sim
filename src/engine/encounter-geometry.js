import { add32, i32, imul32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { nativeTrig } from './native-trig.js';
import { distanceToBoat } from './movement-helpers.js';

export const ENCOUNTER_GEOMETRY_ADDRESSES = Object.freeze({
  relativeProjection: 0x00428af0,
  aheadAstern: 0x0044da90,
  positionX: 0x004a49e8,
  positionY: 0x004a4ae0,
  heading: 0x004ac018,
  tack: 0x004aa730,
  trueWindDirection: 0x004aa5b0,
  projectionX: 0x00485188,
  projectionY: 0x00485190,
  percentage: 0x00485020,
  aheadX: 0x004853f0,
  aheadY: 0x004853f8,
  zero: 0x00484e18,
});

const a = ENCOUNTER_GEOMETRY_ADDRESSES;
const indexed = (base, boat, stride = 4) => add32(base, imul32(boat, stride)) >>> 0;
const extended = (memory, address) => Float80.fromNumber(memory.readF64(address));
const spill = value => Float80.fromNumber(value.toNumber());

/** Complete 0x428af0 signed64 __ftol return; ordinary callers use its low32. */
export function relativeProjection(memory, boat1, selector, boat2, options = {}) {
  boat1 = i32(boat1); selector = i32(selector); boat2 = i32(boat2);
  const x = extended(memory, indexed(a.positionX, boat1, 8));
  const y = extended(memory, indexed(a.positionY, boat1, 8));
  const angle = memory.readI32(indexed(selector === 1 ? a.heading : a.trueWindDirection, boat1));
  const { sine, cosine } = nativeTrig(angle, options);
  let px, py;
  if (selector === 1) {
    const tack = Float80.fromInteger(memory.readI32(indexed(a.tack, boat1)));
    const scale = extended(memory, a.projectionX);
    px = x.subtract(cosine.multiply(tack).multiply(scale));
    py = y.subtract(sine.multiply(tack).multiply(scale));
  } else {
    px = x.subtract(sine.multiply(extended(memory, a.projectionX)));
    py = y.subtract(cosine.multiply(extended(memory, a.projectionY)));
  }
  const dx = px.subtract(x), dy = py.subtract(y);
  const selfSquared = dy.multiply(dy).add(dx.multiply(spill(dx)));
  const zero = extended(memory, a.zero);
  const selfDistance = selfSquared.compare(zero) > 0 ? spill(selfSquared.sqrt()) : Float80.fromInteger(100);
  const otherDx = px.subtract(extended(memory, indexed(a.positionX, boat2, 8)));
  const otherDy = py.subtract(extended(memory, indexed(a.positionY, boat2, 8)));
  const otherSquared = otherDy.multiply(spill(otherDy)).add(otherDx.multiply(spill(otherDx)));
  return selfDistance.subtract(otherSquared.compare(zero) > 0 ? otherSquared.sqrt() : extended(memory, a.percentage)).truncI64();
}

/** Complete 0x44da90, preserving projected coordinate and first-distance spills. */
export function aheadAstern(memory, boat1, boat2, options = {}) {
  boat1 = i32(boat1); boat2 = i32(boat2);
  const { sine, cosine } = nativeTrig(memory.readI32(indexed(a.trueWindDirection, boat1)), options);
  const x = extended(memory, indexed(a.positionX, boat1, 8)).subtract(sine.multiply(extended(memory, a.aheadX))).toNumber();
  const y = extended(memory, indexed(a.positionY, boat1, 8)).subtract(cosine.multiply(extended(memory, a.aheadY))).toNumber();
  const first = spill(distanceToBoat(memory, boat2, x, y));
  return first.subtract(distanceToBoat(memory, boat1, x, y)).truncI64();
}

export const projectionLow32 = value => Number(BigInt.asIntN(32, value));
export const FUN_00428af0 = relativeProjection;
export const FUN_0044da90 = aheadAstern;
