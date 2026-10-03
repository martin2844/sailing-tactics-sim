import { add32, i32, imul32, idiv32, sub32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { wrapDegreesOnce } from './integer-core.js';
import { distanceToBoat } from './movement-helpers.js';
import { aheadAstern, relativeProjection, projectionLow32 } from './encounter-geometry.js';
import { PENALTY_ADDRESSES } from './penalties.js';
import { BOAT_OPTION_ADDRESSES } from './boat-options.js';

export const AVOIDANCE_ADDRESSES = Object.freeze({
  ...PENALTY_ADDRESSES, ...BOAT_OPTION_ADDRESSES,
  updateCollisionAvoidance: 0x00427fd0,
  avoidAiCollision: 0x004280c0,
  warnHumanRightOfWay: 0x004286e0,
  requestRightOfWaySound: 0x00428a30,
  feedbackCode: 0x00491198,
  feedbackTime: 0x0049119c,
  feedbackDistance: 0x004a4c6c,
  closehauledOverride: 0x004ac9b0,
  lastRightOfWaySound: 0x004aca08,
  resetTime: 0x004a4168,
  collisionTime: 0x004a7970,
  collisionX: 0x004a9988,
  collisionY: 0x004a9908,
  startDistance: 0x004a5268,
  relativeTargetAngle: 0x004aba68,
  avoidanceTurnState: 0x004aa660,
  rightOfWayWarning: 0x004a4e78,
  spinnakerHoldFlag: 0x004a76d0,
  speedOverride: 0x004a5f90,
  speedTenths: 0x004a7060,
  tackSlowFlag: 0x004a46a8,
});

const a = AVOIDANCE_ADDRESSES;
const indexed = (base, boat, stride = 4) => add32(base, imul32(boat, stride)) >>> 0;
const absolute32 = value => value < 0 ? sub32(0, value) : value;
const spill = value => Float80.fromNumber(value.toNumber());
const projection = (memory, otherBoat, selector, boat, options) => projectionLow32(relativeProjection(memory, otherBoat, selector, boat, options));

/** Complete 0x428a30. Sound precedes the last-sound timestamp store. */
export function requestRightOfWaySound(memory, selector, options = {}) {
  selector = i32(selector);
  if (memory.readI32(a.soundDisabled) > 0 || memory.readI32(a.time) < add32(memory.readI32(a.resetTime), 10)) return;
  if (selector === 1 || selector === 2) {
    options.playSound?.({ resourceId: selector === 1 ? 141 : 135, moduleHandle: memory.readU32(a.moduleHandle), flags: 0x40015 });
    memory.writeI32(a.lastRightOfWaySound, memory.readI32(a.time));
  }
}

function geometry(memory, otherBoat, boat, options) {
  const ahead = projectionLow32(aheadAstern(memory, boat, otherBoat, options));
  const to = letter => distanceToBoat(memory, boat, memory.readI32(a[`endpoint${letter}X`]), memory.readI32(a[`endpoint${letter}Y`]));
  const radius = Float80.fromInteger(memory.readI32(a.boatCount) === 2 ? 50 : 75);
  const near = to('D').compare(radius) < 0 || to('E').compare(radius) < 0;
  return { ahead, to, near };
}

/** Complete 0x4280c0 automatic right-of-way steering and feedback. */
export function avoidAiCollision(memory, distance, otherBoat, boat, turnMultiplier, options = {}) {
  distance = i32(distance); otherBoat = i32(otherBoat); boat = i32(boat); turnMultiplier = i32(turnMultiplier);
  const read = field => memory.readI32(a[field]);
  const write = (field, value) => memory.writeI32(a[field], value);
  const rb = (field, index = boat) => memory.readI32(indexed(a[field], index));
  const wb = (field, value) => memory.writeI32(indexed(a[field], boat), value);
  const time = read('time');
  if ((read('twoPlayerMode') > 0 && time < 3) || (time < 3 && read('startMode') < 3) || time < add32(rb('collisionTime'), 3)) return;
  const reverse = read('reversePenaltyFlag') === 1;
  if (rb('windInterference') === 1 && rb('tack') === rb('tack', otherBoat)) {
    wb('speedOverride', absolute32(idiv32(rb('speedTenths', otherBoat), 2)));
    if (read('twoPlayerMode') === 1 && boat === 2) write('feedbackCode', -8);
    return;
  }
  const { ahead, to, near } = geometry(memory, otherBoat, boat, options);
  if (near) {
    const first = spill(to('B'));
    const second = distanceToBoat(memory, otherBoat, read('endpointBX'), read('endpointBY'));
    if (first.compare(second) <= 0 || distance > 21 || time < 31 || ahead < -5) return;
    wb('collisionTime', time);
    wb('heading', add32(rb('heading', otherBoat), imul32(imul32(reverse ? -1 : 1, turnMultiplier), 7)));
    if (read('twoPlayerMode') === 1 && boat === 2) { write('feedbackCode', -3); write('feedbackTime', time); }
    return;
  }
  let threshold = read('boardFlag') === 1 || read('catamaranFlag') === 1 || read('skiffFlag') === 1 ? -2 : -5;
  if (rb('startDistance') < 200) threshold = add32(threshold, 2);
  threshold = time < 1 ? -5 : add32(threshold, absolute32(rb('relativeTargetAngle')) < 15 ? 15 : 5);
  if (rb('tack') === -1 && rb('tack', otherBoat) === 1 && threshold <= projection(memory, otherBoat, 0, boat, options) && rb('angleToWind') < 56 && add32(rb('lastTurnTime'), 10) < time && rb('spinnakerHoldFlag') === 0) {
    wb('tack', 1);
    wb('heading', sub32(rb('trueWindDirection'), read('twoPlayerMode') === 0 || read('closehauledOverride') === 1 ? 15 : read('closehauledAngle')));
    wb('collisionTime', time);
    wb('avoidanceTurnState', 0);
    wb('lastTurnTime', sub32(time, 5));
    wb('tackSlowFlag', 1);
    if (read('twoPlayerMode') === 1 && boat === 2 && otherBoat === 1) { write('feedbackCode', -7); write('feedbackTime', time); write('feedbackDistance', 1000); }
    return;
  }
  if (rb('tack') === -1) {
    let delta;
    if (rb('tack', otherBoat) === 1 && projection(memory, otherBoat, 0, boat, options) < threshold && sub32(threshold, 3) <= projection(memory, otherBoat, 0, boat, options) && rb('angleToWind') < 56) delta = 85;
    else if (rb('tack') === -1 && rb('tack', otherBoat) === 1 && projection(memory, otherBoat, 0, boat, options) < sub32(threshold, 3) && rb('angleToWind') < 56) delta = 55;
    if (delta !== undefined) {
      wb('heading', add32(rb('heading'), delta));
      wb('collisionTime', time);
      wb('avoidanceTurnState', 0);
      wb('spinnakerHoldFlag', 1);
      if (read('twoPlayerMode') === 1 && boat === 2) { write('feedbackCode', -2); write('feedbackTime', time); }
      return;
    }
  }
  const overlap = projection(memory, otherBoat, 1, boat, options);
  const overlapRadius = read('course') === 8 && time < 100 ? 10 : 15;
  const tack = rb('tack');
  if (tack === rb('tack', otherBoat) && overlap > 0 && rb('angleToWind', otherBoat) <= rb('angleToWind') && distance < overlapRadius) {
    wb('heading', add32(time < 30 ? rb('heading') : rb('heading', otherBoat), imul32(tack, 10)));
    wb('collisionTime', time);
    if (read('twoPlayerMode') === 1 && boat === 2) { write('feedbackCode', -4); write('feedbackTime', time); }
  } else if (rb('angleToWind') > 55 && tack === -1 && rb('tack', otherBoat) === 1) {
    const side = projectionLow32(aheadAstern(memory, boat, otherBoat, options));
    if (rb('angleToWind', otherBoat) < 91 || side > 0) {
      write('feedbackCode', -4);
      wb('heading', add32(rb('heading'), imul32(rb('tack'), 40)));
      wb('collisionTime', time);
      return;
    }
    wb('heading', wrapDegreesOnce(add32(add32(rb('downwindLimit'), 180), rb('trueWindDirection'))));
    write('feedbackCode', -16);
    wb('collisionTime', time);
  }
}

/** Complete 0x4286e0 human-boat warnings, including original repeated projections. */
export function warnHumanRightOfWay(memory, distance, otherBoat, boat, options = {}) {
  distance = i32(distance); otherBoat = i32(otherBoat); boat = i32(boat);
  const read = field => memory.readI32(a[field]);
  const rb = (field, index = boat) => memory.readI32(indexed(a[field], index));
  const warn = selector => {
    memory.writeI32(indexed(a.rightOfWayWarning, boat), 1);
    if (selector) requestRightOfWaySound(memory, selector, options);
  };
  if (read('time') <= add32(read('resetTime'), 1)) return;
  if (rb('windInterference') === 1 && rb('tack') === rb('tack', otherBoat)) { warn(); return; }
  const { ahead, to, near } = geometry(memory, otherBoat, boat, options);
  if (near) {
    const first = spill(to('B'));
    const second = distanceToBoat(memory, otherBoat, read('endpointBX'), read('endpointBY'));
    if (first.compare(second) <= 0 || distance > 21 || read('time') < 31 || ahead < -5) return;
    warn();
    return;
  }
  let threshold = read('boardFlag') === 1 || read('catamaranFlag') === 1 ? -3 : -5;
  if (rb('startDistance') < 200) threshold = add32(threshold, 2);
  threshold = read('time') < 1 ? -5 : add32(threshold, absolute32(rb('relativeTargetAngle')) < 15 ? 15 : 5);
  const opposed = () => rb('tack') === -1 && rb('tack', otherBoat) === 1;
  if (opposed()) {
    let portRisk = threshold <= projection(memory, otherBoat, 0, boat, options) && rb('angleToWind') < 56 && add32(rb('lastTurnTime'), 10) < read('time') && rb('spinnakerHoldFlag') === 0;
    if (!portRisk && opposed()) {
      portRisk = opposed() && projection(memory, otherBoat, 0, boat, options) < threshold && sub32(threshold, 3) <= projection(memory, otherBoat, 0, boat, options) && rb('angleToWind') < 56;
      if (!portRisk) portRisk = opposed() && projection(memory, otherBoat, 0, boat, options) < sub32(threshold, 3) && rb('angleToWind') < 56;
    }
    if (portRisk) { warn(1); return; }
  }
  const overlap = projection(memory, otherBoat, 1, boat, options);
  const tack = rb('tack'), otherTack = rb('tack', otherBoat);
  if (tack === otherTack && overlap > 0 && ((rb('angleToWind', otherBoat) <= rb('angleToWind') && distance < 5) || rb('angleToWind', otherBoat) < rb('angleToWind'))) { warn(2); return; }
  if (rb('angleToWind') < 56 || tack !== -1 || otherTack !== 1) return;
  aheadAstern(memory, boat, otherBoat, options);
  warn(1);
}

/** Complete 0x427fd0 ascending nearby-boat scan over projected integer positions. */
export function updateCollisionAvoidance(memory, boat, options = {}) {
  boat = i32(boat);
  const rb = (field, index = boat) => memory.readI32(indexed(a[field], index));
  if (add32(rb('collisionTime'), 5) <= memory.readI32(a.time)) memory.writeI32(indexed(a.spinnakerHoldFlag, boat), 0);
  for (let other = 1; other <= memory.readI32(a.boatCount); other = add32(other, 1)) {
    if (other === boat) continue;
    const dx = Float80.fromInteger(sub32(rb('collisionX'), rb('collisionX', other)));
    const dy = Float80.fromInteger(sub32(rb('collisionY'), rb('collisionY', other)));
    const distance = dy.multiply(spill(dy)).add(dx.multiply(dx)).sqrt().truncI32();
    if (distance < 9) {
      if (boat > memory.readI32(a.humanBoatCount)) avoidAiCollision(memory, distance, other, boat, 2, options);
      else warnHumanRightOfWay(memory, distance, other, boat, options);
      memory.writeI32(indexed(a.heading, boat), wrapDegreesOnce(rb('heading')));
    }
  }
}

export const FUN_00427fd0 = updateCollisionAvoidance;
export const FUN_004280c0 = avoidAiCollision;
export const FUN_004286e0 = warnHumanRightOfWay;
export const FUN_00428a30 = requestRightOfWaySound;
