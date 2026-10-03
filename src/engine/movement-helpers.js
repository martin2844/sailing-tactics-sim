import { add32, i32, imul32, sub32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom } from './integer-core.js';

export const MOVEMENT_HELPER_ADDRESSES = Object.freeze({
  distanceToBoat: 0x00428ab0,
  prestartSpeedPercent: 0x0042a3b0,
  boatCount: 0x0049118c,
  secondBoatDelay: 0x00491168,
  time: 0x004a5b80,
  difficulty: 0x00491190,
  course: 0x00491194,
  islandFlag: 0x004a5a4c,
  positionX: 0x004a49e8,
  positionY: 0x004a4ae0,
  targetX: 0x004a4888,
  targetY: 0x004a6f48,
  rateCoefficient: 0x004a6e48,
  interference: 0x004a7868,
  raceTime: 0x004ac1f8,
  timeFactor: 0x004ab0c0,
  zero: 0x00484e18,
  rateScale: 0x00484dd8,
  minimumRate: 0x00484eb8,
  interferenceRate: 0x00484da8,
  percentage: 0x00485020,
});

const a = MOVEMENT_HELPER_ADDRESSES;
const indexed = (base, boat, stride = 4) => add32(base, imul32(boat, stride)) >>> 0;
const extended = (memory, address) => Float80.fromNumber(memory.readF64(address));

/**
 * Complete 0x428ab0 distance return in unrounded ST0. Native X is spilled once
 * to binary64 before multiplying by its retained extended copy; Y is unspilled.
 */
export function distanceToBoat(memory, boat, x, y) {
  boat = i32(boat);
  const deltaX = extended(memory, indexed(a.positionX, boat, 8)).subtract(Float80.fromNumber(x));
  const deltaY = extended(memory, indexed(a.positionY, boat, 8)).subtract(Float80.fromNumber(y));
  return deltaX.multiply(Float80.fromNumber(deltaX.toNumber())).add(deltaY.multiply(deltaY)).sqrt();
}

/**
 * Complete 0x42a3b0 prestart AI speed percentage. The original may return values
 * below zero; it does not clamp percentages. One CRT random draw is consumed
 * when boatCount > 2, including calls later overridden by interference flags.
 */
export function prestartSpeedPercent(memory, boat, rng) {
  boat = i32(boat);
  const read = field => memory.readI32(a[field]);
  const count = read('boatCount');
  if (count === 2 && boat === 2 && read('time') < read('secondBoatDelay')) return 100;
  const deltaX = Float80.fromInteger(memory.readI32(indexed(a.targetX, boat)))
    .subtract(extended(memory, indexed(a.positionX, boat, 8)));
  const deltaY = Float80.fromInteger(memory.readI32(indexed(a.targetY, boat)))
    .subtract(extended(memory, indexed(a.positionY, boat, 8)));
  // 0x42a411 spills X; 0x42a423 spills the sum before the later FSQRT.
  const squared = Float80.fromNumber(deltaX.multiply(Float80.fromNumber(deltaX.toNumber()))
    .add(deltaY.multiply(deltaY)).toNumber());
  const difficulty = read('difficulty');
  let skill = difficulty <= 12 ? difficulty : 12;
  if (read('course') === 8 && read('islandFlag') === 0) skill = 0;
  if (difficulty === 2) skill = -5;
  if (difficulty === 1) skill = -10;
  const randomOffset = count > 2 ? Float80.fromInteger(scaledRandom(17, rng)) : extended(memory, a.zero);
  const zero = extended(memory, a.zero);
  const distance = squared.compare(zero) > 0
    ? squared.sqrt().subtract(Float80.fromInteger(imul32(sub32(15, skill), 4))).subtract(randomOffset)
    : zero;
  let rate = Float80.fromInteger(memory.readI32(indexed(a.rateCoefficient, boat))).multiply(extended(memory, a.rateScale));
  const minimum = extended(memory, a.minimumRate);
  if (rate.compare(minimum) <= 0) rate = minimum;
  const interference = memory.readI32(indexed(a.interference, boat));
  if (interference > 0) rate = extended(memory, a.interferenceRate);
  rate = rate.multiply(extended(memory, a.raceTime)).divide(extended(memory, a.timeFactor)).negate();
  const percent = rate.compare(zero) <= 0 || rate.compare(distance) <= 0
    ? 100 : distance.multiply(extended(memory, a.percentage)).divide(rate).truncI32();
  return interference > 0 ? 100 : percent;
}

export const FUN_00428ab0 = distanceToBoat;
export const FUN_0042a3b0 = prestartSpeedPercent;
