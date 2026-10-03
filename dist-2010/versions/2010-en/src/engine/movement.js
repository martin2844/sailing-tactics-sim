import { Float80 } from '../../../../src/runtime/float80.js';
import { i32 } from '../../../../src/runtime/c-types.js';

export const MOVEMENT_ADDRESSES = Object.freeze({
  distanceToBoat: 0x439e80, positionX: 0x4f6af8, positionY: 0x4f6c10,
  integratePositions: 0x43cf60,
});

/** Complete original 0x439e80, including the second x-difference F64 spill. */
export function distanceToBoat(memory, boat, x, y) {
  boat = i32(boat);
  const offset = Math.imul(boat, 8);
  const positionX = Float80.fromNumber(memory.readF64((0x4f6af8 + offset) >>> 0));
  const positionY = Float80.fromNumber(memory.readF64((0x4f6c10 + offset) >>> 0));
  const dx = positionX.subtract(Float80.fromNumber(x));
  const dy = positionY.subtract(Float80.fromNumber(y));
  return dy.multiply(dy).add(dx.multiply(Float80.fromNumber(dx.toNumber()))).sqrt();
}
