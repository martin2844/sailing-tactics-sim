import { add32, i32, idiv32, imul32, sub32 } from '../runtime/index.js';
import { wrapDegreesOnce } from './integer-core.js';

export const SAILING_HELPER_ADDRESSES = Object.freeze({
  updateTack: 0x004255b0,
  spinnakerAnglePenalty: 0x0042a280,
  scheduleWindShift: 0x0041ba60,
  setClosehauledHeading: 0x004269d0,
  heading: 0x004ac018,
  trueWindDirection: 0x004aa5b0,
  trueWindKnots: 0x004a6338,
  angleToTrueWind: 0x004a7bc8,
  tack: 0x004aa730,
  spinnakerThreshold: 0x004ab180,
  spinnakerPenalty: 0x004ac5f0,
  windRandomTable: 0x004a9450,
  targetRandomIndex: 0x004911c4,
  timeRandomIndex: 0x004911c8,
  integerSeconds: 0x004a5b80,
  nextWindTime: 0x004abae4,
  nextWindTarget: 0x004ac9e8,
  boatClass: 0x00491188,
  catamaranFlag: 0x004ac900,
  boardFlag: 0x004ac904,
  sportBoatFlag: 0x004ac908,
  closehauledOffset: 0x004ac1e8,
  player1ClosehauledAngle: 0x004a52e8,
});

function indexed(base, index) {
  return (base + Math.imul(i32(index), 4)) >>> 0;
}

/**
 * Set original tack sign from heading minus wind direction.
 * Neither difference nor endpoints are normalized: exactly 0/+180/-180 retain
 * +1. Returns the original residual EAX (difference), while the tack is written
 * to image memory; the native caller treats this routine as void.
 */
export function updateTack(memory, boat) {
  const a = SAILING_HELPER_ADDRESSES;
  const difference = sub32(memory.readI32(indexed(a.heading, boat)),
    memory.readI32(indexed(a.trueWindDirection, boat)));
  memory.writeI32(indexed(a.tack, boat),
    (difference > 0 && difference < 180) || difference < -180 ? -1 : 1);
  return difference;
}

/** Set original spinnaker angle penalty; return residual EAX (input angle). */
export function spinnakerAnglePenalty(memory, boat) {
  const a = SAILING_HELPER_ADDRESSES;
  const threshold = memory.readI32(a.spinnakerThreshold);
  const angle = memory.readI32(indexed(a.angleToTrueWind, boat));
  const lower = sub32(threshold, 8);
  let penalty = 0;
  if (angle < threshold && angle >= lower) penalty = 30;
  if (angle < lower) penalty = 100;
  memory.writeI32(indexed(a.spinnakerPenalty, boat), penalty);
  return angle;
}

/**
 * Schedule wind using the original precomputed random table and two independent
 * cyclic cursors. Products wrap before signed division. Index 300 is read before
 * its cursor wraps to 1; index 0 is not specially normalized.
 */
export function scheduleWindShift(memory, center, range, period) {
  const a = SAILING_HELPER_ADDRESSES;
  const targetIndex = memory.readI32(a.targetRandomIndex);
  const timeIndex = memory.readI32(a.timeRandomIndex);
  const timeRandom = memory.readI32(indexed(a.windRandomTable, timeIndex));
  const nextTime = add32(add32(idiv32(imul32(timeRandom, 7), 10), period),
    memory.readI32(a.integerSeconds));
  memory.writeI32(a.nextWindTime, nextTime);
  const targetRandom = memory.readI32(indexed(a.windRandomTable, targetIndex));
  const target = add32(sub32(idiv32(imul32(targetRandom, range), 100),
    idiv32(range, 2)), center);
  memory.writeI32(a.nextWindTarget, target);
  const nextTargetIndex = add32(targetIndex, 1);
  const nextTimeIndex = add32(timeIndex, 1);
  memory.writeI32(a.targetRandomIndex, nextTargetIndex > 300 ? 1 : nextTargetIndex);
  memory.writeI32(a.timeRandomIndex, nextTimeIndex > 300 ? 1 : nextTimeIndex);
  return target;
}

/**
 * Choose the original closehauled heading by boat class, wind, and tack.
 * Option branches deliberately distinguish nonzero catamaran from exactly 1,
 * as the original instructions do. The final heading correction is a single
 * wrap. Returns the original EAX (new heading).
 */
export function setClosehauledHeading(memory, boat) {
  const a = SAILING_HELPER_ADDRESSES;
  boat = i32(boat);
  const boatClass = memory.readI32(a.boatClass);
  const catamaran = memory.readI32(a.catamaranFlag);
  const wind = memory.readI32(indexed(a.trueWindKnots, boat));
  const offset = memory.readI32(indexed(a.closehauledOffset, boat));
  let angle = catamaran === 0
    ? add32(add32(sub32(idiv32(wind, -3), idiv32(boatClass, 6)), 45), offset)
    : add32(sub32(offset, idiv32(wind, 8)), 46);
  if (boatClass === 3) angle = add32(angle, 3);
  if (boatClass === 7) angle = sub32(angle, 2);
  if (boatClass === 8) angle = sub32(angle, 6);
  if (memory.readI32(a.boardFlag) === 1) angle = add32(offset, 55);
  if (boatClass < 7 || catamaran === 1 || memory.readI32(a.sportBoatFlag) === 1) {
    if (wind < 11) angle = add32(angle, 3);
    if (wind < 8) angle = add32(angle, 3);
  }
  if (boat === 1) memory.writeI32(a.player1ClosehauledAngle, angle);
  const heading = wrapDegreesOnce(sub32(memory.readI32(indexed(a.trueWindDirection, boat)),
    imul32(memory.readI32(indexed(a.tack, boat)), angle)));
  memory.writeI32(indexed(a.heading, boat), heading);
  return heading;
}

export const FUN_004255b0 = updateTack;
export const FUN_0042a280 = spinnakerAnglePenalty;
export const FUN_0041ba60 = scheduleWindShift;
export const FUN_004269d0 = setClosehauledHeading;
