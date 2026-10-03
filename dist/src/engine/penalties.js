import { add32, i32, idiv32, imul32, sub32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom, wrapDegreesOnce } from './integer-core.js';
import { nativeTrig } from './native-trig.js';
import { distanceToBoat } from './movement-helpers.js';
import { projectionLow32, relativeProjection } from './encounter-geometry.js';

export const PENALTY_ADDRESSES = Object.freeze({
  resetBoat: 0x00421c40,
  signedStartDistance: 0x00426f50,
  respawnNearStart: 0x0042a8a0,
  shiftPenaltyPosition: 0x0042a950,
  checkNearRaceMarks: 0x0042abb0,
  collisionPenalty: 0x0042a530,
  updateMarkStartPenalties: 0x0042a2d0,
  boatCount: 0x0049118c,
  humanBoatCount: 0x00491140,
  startMode: 0x004911cc,
  time: 0x004a5b80,
  endpointAX: 0x004aa594,
  endpointAY: 0x004aa59c,
  endpointBX: 0x004a70f8,
  endpointBY: 0x004a72c8,
  endpointCX: 0x004aa294,
  endpointCY: 0x004aa388,
  endpointDX: 0x004aa38c,
  endpointDY: 0x004aa588,
  endpointEX: 0x004aa288,
  endpointEY: 0x004aa384,
  relocationSpan: 0x004aa998,
  spawnX: 0x004a4be0,
  spawnY: 0x004a4f84,
  soundDisabled: 0x004ac9c0,
  moduleHandle: 0x004ac1d4,
  course: 0x00491194,
  reversePenaltyFlag: 0x004ac9a8,
  closehauledAngle: 0x004a4eb0,
  raceStage: 0x004a5420,
  targetX: 0x004a4888,
  targetY: 0x004a6f48,
  heading: 0x004ac018,
  tack: 0x004aa730,
  trueWindDirection: 0x004aa5b0,
  angleToWind: 0x004a7bc8,
  downwindLimit: 0x004a5f10,
  positionX: 0x004a49e8,
  positionY: 0x004a4ae0,
  penaltyShift: 0x00485200,
  zero: 0x00484e18,
  playSoundImport: 0x004b1c18,
  viewportWidth: 0x004a763c,
  twoPlayerMode: 0x004ac9ac,
  catamaranFlag: 0x004ac900,
  penaltyCode: 0x004a89c0,
  penaltyTime: 0x004abf18,
  windInterference: 0x004a40d0,
  turnMode: 0x004a4df8,
  lastTurnTime: 0x004a41f0,
  nearStartRadius: 0x004850c8,
});

const a = PENALTY_ADDRESSES;
const indexed = (base, boat, stride = 4) => add32(base, imul32(boat, stride)) >>> 0;
const extended = (memory, address) => Float80.fromNumber(memory.readF64(address));
const integer = (memory, address) => Float80.fromInteger(memory.readI32(address));
const spill = value => Float80.fromNumber(value.toNumber());
const absolute32 = value => value < 0 ? sub32(0, value) : value;

function penaltySound(memory, boat, options) {
  if (boat <= memory.readI32(a.humanBoatCount) && memory.readI32(a.soundDisabled) === 0 && memory.readI32(a.time) > -168) {
    options.playSound?.({ resourceId: 137, moduleHandle: memory.readU32(a.moduleHandle), flags: 0x40005 });
  }
}

/** Complete 0x421c40. EAX becomes 2 unless the final midpoint override runs. */
export function resetBoat(memory, boat) {
  boat = i32(boat);
  const count = memory.readI32(a.boatCount);
  const countPlus = add32(count, 1);
  const mode = memory.readI32(a.startMode);
  const humans = memory.readI32(a.humanBoatCount);
  const bx = memory.readI32(a.endpointBX), by = memory.readI32(a.endpointBY);
  const ax = memory.readI32(a.endpointAX), ay = memory.readI32(a.endpointAY);
  memory.writeI32(indexed(a.raceStage, boat), 0);
  const interpolate = (from, to) => idiv32(add32(imul32(from, sub32(countPlus, boat)), imul32(boat, to)), countPlus);
  const targets = (x, y) => {
    memory.writeI32(indexed(a.targetX, boat), x);
    memory.writeI32(indexed(a.targetY, boat), y);
  };
  if (mode === 2) targets(interpolate(ax, bx), interpolate(ay, by));
  if (mode === 1) targets(interpolate(bx, ax), interpolate(by, ay));
  if (boat > humans && mode > 2) targets(interpolate(ax, bx), interpolate(ay, by));
  if (mode > 2 && (boat <= humans || count === 2 || memory.readI32(a.time) > -30)) {
    const y = idiv32(add32(by, ay), 2);
    targets(idiv32(add32(ax, bx), 2), y);
    return y;
  }
  return 2;
}

/** Complete 0x42a8a0; consumes two CRT draws and returns the final integer Y. */
export function respawnNearStart(memory, boat, rng, options = {}) {
  boat = i32(boat);
  const range = idiv32(memory.readI32(a.relocationSpan), 6);
  penaltySound(memory, boat, options);
  resetBoat(memory, boat);
  const halfRange = idiv32(range, 2);
  const x = add32(scaledRandom(range, rng), sub32(memory.readI32(a.spawnX), halfRange));
  memory.writeF64(indexed(a.positionX, boat, 8), x);
  const y = add32(scaledRandom(range, rng), sub32(memory.readI32(a.spawnY), halfRange));
  memory.writeF64(indexed(a.positionY, boat, 8), y);
  return y;
}

/** Complete 0x42a950 for valid tacks ±1; other tacks use an uninitialized native local. */
export function shiftPenaltyPosition(memory, boat, options = {}) {
  boat = i32(boat);
  const read = field => memory.readI32(indexed(a[field], boat));
  const tack = read('tack');
  if (tack !== 1 && tack !== -1) throw new RangeError('Original penalty shift requires tack +1 or -1; other tacks read an uninitialized stack value');
  penaltySound(memory, boat, options);
  let base = read('heading');
  const stage = read('raceStage');
  if (memory.readI32(a.course) !== 8 && (stage < 4 || stage === 8)) base = sub32(read('trueWindDirection'), imul32(tack, memory.readI32(a.closehauledAngle)));
  const below = read('angleToWind') < sub32(160, read('downwindLimit'));
  const reverse = memory.readI32(a.reversePenaltyFlag) === 1;
  const offset = reverse
    ? (tack === 1 ? (below ? 180 : -160) : (below ? -160 : 180))
    : (tack === 1 ? (below ? 160 : 180) : (below ? 170 : 160));
  const angle = wrapDegreesOnce(add32(base, offset));
  const { sine, cosine } = nativeTrig(angle, options);
  const shift = extended(memory, a.penaltyShift);
  const x = sine.multiply(shift).add(extended(memory, indexed(a.positionX, boat, 8)));
  const y = extended(memory, indexed(a.positionY, boat, 8)).subtract(cosine.multiply(shift));
  memory.writeF64(indexed(a.positionX, boat, 8), x.toNumber());
  memory.writeF64(indexed(a.positionY, boat, 8), y.toNumber());
  return angle;
}

/** Complete 0x42abb0 Manhattan proximity check, including the asymmetric final radius. */
export function checkNearRaceMarks(memory, radius, boat) {
  radius = i32(radius); boat = i32(boat);
  const x = extended(memory, indexed(a.positionX, boat, 8)).truncI32();
  const y = extended(memory, indexed(a.positionY, boat, 8)).truncI32();
  const distance = letter => add32(absolute32(sub32(memory.readI32(a[`endpoint${letter}X`]), x)), absolute32(sub32(memory.readI32(a[`endpoint${letter}Y`]), y)));
  let da = distance('A'), db = distance('B');
  const dc = distance('C'), dd = distance('D'), de = distance('E');
  if (sub32(170, memory.readI32(indexed(a.downwindLimit, boat))) < memory.readI32(indexed(a.angleToWind, boat)) && memory.readI32(a.time) > 30) da = db = 1000;
  return radius < da && radius < dc && radius < dd && radius < de && add32(radius, 2) < db ? 0 : 1;
}

/** Complete 0x426f50; return retained ST0, including all four binary64 spills. */
export function signedStartDistance(memory, boat) {
  boat = i32(boat);
  const dx = spill(extended(memory, indexed(a.positionX, boat, 8)).subtract(integer(memory, a.endpointCX)));
  const dy = extended(memory, indexed(a.positionY, boat, 8)).subtract(integer(memory, a.endpointCY));
  const midx = idiv32(add32(memory.readI32(a.endpointAX), memory.readI32(a.endpointBX)), 2);
  const midy = idiv32(add32(memory.readI32(a.endpointAY), memory.readI32(a.endpointBY)), 2);
  const refdx = spill(Float80.fromInteger(midx).subtract(integer(memory, a.endpointCX)));
  const refdy = Float80.fromInteger(midy).subtract(integer(memory, a.endpointCY));
  const positionDistance = spill(dx.multiply(dx).add(dy.multiply(spill(dy))).sqrt());
  return positionDistance.subtract(refdx.multiply(refdx).add(refdy.multiply(refdy)).sqrt());
}

function applyPenaltyMovement(memory, boat, rng, options) {
  if (memory.readI32(a.time) < 20) {
    // The caller resets once and 0x42a8a0 resets again; preserve both calls.
    resetBoat(memory, boat);
    respawnNearStart(memory, boat, rng, options);
  } else shiftPenaltyPosition(memory, boat, options);
}

/** Complete 0x42a530 collision rules, including the other boat's cooldown. */
export function collisionPenalty(memory, otherBoat, boat, distance, rng, options = {}) {
  otherBoat = i32(otherBoat); boat = i32(boat); distance = i32(distance);
  const read = (field, index = boat) => memory.readI32(indexed(a[field], index));
  const write = (field, value) => memory.writeI32(indexed(a[field], boat), value);
  const time = () => memory.readI32(a.time);
  const humans = () => memory.readI32(a.humanBoatCount);
  const distanceTo = letter => distanceToBoat(memory, boat, memory.readI32(a[`endpoint${letter}X`]), memory.readI32(a[`endpoint${letter}Y`]));
  if (read('raceStage') > 8 || time() < add32(read('penaltyTime', otherBoat), 50)) return;
  const radius = Float80.fromInteger(memory.readI32(a.boatCount) === 2 ? 30 : 40);
  if (distanceTo('D').compare(radius) < 0 || distanceTo('E').compare(radius) < 0) {
    const first = spill(distanceTo('B'));
    const second = distanceToBoat(memory, otherBoat, memory.readI32(a.endpointBX), memory.readI32(a.endpointBY));
    if (first.compare(second) <= 0 || add32(read('raceStage', otherBoat), read('raceStage')) > 15 || read('angleToWind') < 56) return;
    write('penaltyTime', time());
    if (boat <= humans()) write('penaltyCode', 3);
    shiftPenaltyPosition(memory, boat, options);
    return;
  }
  const tack = read('tack');
  if (tack === -1 && read('tack', otherBoat) === 1) {
    write('penaltyTime', time());
    if (boat <= humans()) write('penaltyCode', 4);
    applyPenaltyMovement(memory, boat, rng, options);
    return;
  }
  const blocked = read('windInterference') === 1;
  const sameTack = tack === read('tack', otherBoat);
  if (blocked && sameTack && absolute32(sub32(read('raceStage'), read('raceStage', otherBoat))) < 2) {
    write('penaltyCode', 6);
    write('penaltyTime', time());
    applyPenaltyMovement(memory, boat, rng, options);
    return;
  }
  let checkProjection = true;
  if (blocked && boat > humans()) {
    if (sameTack) {
      if (time() < 4) {
        write('penaltyTime', time());
        resetBoat(memory, boat);
        respawnNearStart(memory, boat, rng, options);
        return;
      }
    } else checkProjection = false;
  }
  if (checkProjection && sameTack && projectionLow32(relativeProjection(memory, otherBoat, 1, boat, options)) >= 0 && distance <= add32(memory.readI32(a.catamaranFlag), 5)) {
    write('penaltyTime', time());
    if (boat <= humans()) write('penaltyCode', 5);
    applyPenaltyMovement(memory, boat, rng, options);
    return;
  }
  if (boat > humans()) return;
  if (read('turnMode') === 1 && read('angleToWind') < 55) {
    write('penaltyTime', time());
    write('penaltyCode', 7);
    applyPenaltyMovement(memory, boat, rng, options);
    return;
  }
  if (distanceTo('C').compare(extended(memory, a.nearStartRadius)) >= 0 || sub32(time(), read('lastTurnTime')) > 5 || read('angleToWind') > 54) return;
  write('penaltyTime', time());
  write('penaltyCode', 7);
  shiftPenaltyPosition(memory, boat, options);
}

/** Complete 0x42a2d0 mark contact and premature start routing. */
export function updateMarkStartPenalties(memory, boat, rng, options = {}) {
  boat = i32(boat);
  if (checkNearRaceMarks(memory, (memory.readI32(a.viewportWidth) < 901 ? 1 : 0) + 1, boat) === 1) {
    if (boat <= memory.readI32(a.humanBoatCount)) memory.writeI32(indexed(a.penaltyCode, boat), 1);
    applyPenaltyMovement(memory, boat, rng, options);
    memory.writeI32(indexed(a.penaltyTime, boat), memory.readI32(a.time));
  }
  if (memory.readI32(a.time) < 51 && memory.readI32(a.twoPlayerMode) !== 1) {
    if (signedStartDistance(memory, boat).compare(extended(memory, a.zero)) <= 0 && memory.readI32(a.time) > -3 && memory.readI32(a.time) < 1 && memory.readI32(a.startMode) > 2) {
      if (boat <= memory.readI32(a.humanBoatCount)) memory.writeI32(indexed(a.penaltyCode, boat), 2);
      resetBoat(memory, boat);
      respawnNearStart(memory, boat, rng, options);
      memory.writeI32(indexed(a.penaltyTime, boat), memory.readI32(a.time));
    }
  }
}

export const FUN_00421c40 = resetBoat;
export const FUN_00426f50 = signedStartDistance;
export const FUN_0042a8a0 = respawnNearStart;
export const FUN_0042a950 = shiftPenaltyPosition;
export const FUN_0042abb0 = checkNearRaceMarks;
export const FUN_0042a530 = collisionPenalty;
export const FUN_0042a2d0 = updateMarkStartPenalties;
