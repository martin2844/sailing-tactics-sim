import { add32, sub32, imul32, idiv32, i32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { wrapDegreesOnce } from './integer-core.js';
import { bearingFromVector } from './angles.js';
import { updateTack, setClosehauledHeading } from './helpers.js';
import { sampleSpatialWind } from './spatial-wind.js';
import { aheadAstern } from './encounter-geometry.js';
import { advanceRaceTarget } from './race-targets.js';
import { signedStartDistance } from './penalties.js';
import { targetRelativeBearing } from './target-bearing.js';
import { chooseDownwindHeading } from './ai-tactics.js';
import { updateUpwindTactics } from './upwind-tactics.js';
import { updateCollisionAvoidance } from './avoidance.js';

export const AI_ADDRESSES = Object.freeze({
  routine: 0x4249a0, matchMode: 0x4ac9ac, rivalDecision: 0x491198,
  rivalDecisionTime: 0x49119c, time: 0x4a5b80, heading: 0x4ac018,
  boatCount: 0x49118c, boatClass: 0x491188, boatWindStrength: 0x4a6338,
  downwindLimit: 0x4a5f10, skiffFlag: 0x4ac90c, catamaranFlag: 0x4ac900,
  sportBoatFlag: 0x4ac908, kiteFlag: 0x4ac904, advanceDistance: 0x4aa834,
  refreshFlag: 0x4a60a0, resetTime: 0x4a4168, positionX: 0x4a49e8,
  positionY: 0x4a4ae0, windDirection: 0x4aa5b0, gust: 0x4ac4e8,
  autopilot1: 0x4a8914, autopilot2: 0x4a8918, smoothHeading: 0x4a78e8,
  humanBoatCount: 0x491140, player2Downwind: 0x4a4970, priorTack: 0x4abe70,
  tack: 0x4aa730, turnFlag: 0x4a4398, closehauled: 0x4a4eb0,
  lesson: 0x491164, maximumHeel: 0x4ac95c, raceComplete: 0x4ac93c,
  targetX: 0x4a4888, targetY: 0x4a6f48, targetDistance: 0x4a5268,
  leg: 0x4a5420, startAX: 0x4aa594, startAY: 0x4aa59c,
  startBX: 0x4a70f8, startBY: 0x4a72c8, startWidth: 0x4aa998,
  finishMode: 0x4a495c, lastFinishTime: 0x4ab8b4, warningMode: 0x4911a0,
  turning: 0x4aa660, penaltyFlag: 0x4a76d0, rivalCover: 0x4ac9b8,
  debug: 0x4a4bf0, secondBoatDelay: 0x491168, initialRivalHeading: 0x4a414c,
  downwindFlag: 0x4aada8, turnStarted: 0x4a7970, reverseCourse: 0x4ac9a8,
  legStarted: 0x4a41f0, tackSlowFlag: 0x4a46a8, smoothSpeed: 0x4a71c8,
});
const a = AI_ADDRESSES;
const at = (base, boat, stride = 4) => add32(base, imul32(boat, stride)) >>> 0;
const abs = value => value < 0 ? sub32(0, value) : value;
const floating = (memory, address) => Float80.fromNumber(memory.readF64(address));

/** Full 0x4249a0 frame coordinator for boat wind, targets and AI steering. */
export function updateBoatWindAndAI(memory, boat, rng, options = {}) {
  boat = i32(boat);
  const r = key => memory.readI32(a[key]);
  const w = (key, value) => memory.writeI32(a[key], value);
  const b = key => memory.readI32(at(a[key], boat));
  const B = (key, value) => memory.writeI32(at(a[key], boat), value);
  const f = key => floating(memory, at(a[key], boat, 8));
  if (add32(r('rivalDecisionTime'), 7) < r('time') && r('matchMode') === 1 && boat === 2) w('rivalDecision', 1000);
  const oldHeading = b('heading');
  if (r('boatCount') === 2 && boat === 2) aheadAstern(memory, 2, 1, options);
  let boatClass = r('boatClass');
  const wind = b('boatWindStrength');
  let limit = wind < 12 && boatClass > 2 ? 33 : 20;
  if (boatClass === 1) limit = 5;
  if (boatClass === 2) limit = 12;
  if (boatClass === 3 && r('skiffFlag') === 0) limit = wind > 11 ? 25 : 42;
  if (boatClass === 4 || boatClass === 5) limit = wind > 13 ? 8 : 15;
  if (boatClass === 6) limit = wind > 13 ? 10 : 20;
  if (r('catamaranFlag') === 1 || r('skiffFlag') === 1) {
    limit = wind < 10 || wind > 13 ? 36 : 41;
    if (boatClass === 10) limit = add32(limit, 1);
  }
  if (boatClass === 7 && r('sportBoatFlag') === 0) limit = sub32(limit, wind < 12 ? 3 : 5);
  if (wind > 16) limit = sub32(limit, 3);
  if (boatClass === 8) limit = wind > 13 ? 33 : 38;
  if (r('sportBoatFlag') === 1) limit = wind > 13 ? 31 : 40;
  if (r('kiteFlag') === 1) {
    limit = wind > 10 ? 50 : 40;
    if (wind < 8) limit = 35;
    if (wind > 13) limit = 40;
    if (wind > 18) limit = 35;
  }
  if (r('matchMode') === 1 && boatClass === 7) limit = wind < 9 ? 37 : wind < 11 ? 34 : wind < 14 ? 22 : 10;
  B('downwindLimit', limit);
  w('advanceDistance', r('time') > 0 ? 40 : 300);
  if (r('refreshFlag') === 1 || r('time') < add32(r('resetTime'), 20) || r('matchMode') === 1) {
    B('boatWindStrength', sampleSpatialWind(memory, f('positionX').truncI32(), f('positionY').truncI32(), boat));
    B('windDirection', memory.readI32(0x4aaeac)); B('gust', memory.readI32(0x4ac4d8));
  }
  if (r('autopilot1') === 1 && boat === 1) {
    setClosehauledHeading(memory, 1); memory.writeF64(a.smoothHeading, memory.readI32(a.heading + 4));
  }
  if (r('autopilot2') === 1 && boat === 2 && r('humanBoatCount') === 2) setClosehauledHeading(memory, 2);
  if (boat === 2 && r('player2Downwind') === 1 && r('humanBoatCount') === 2) {
    memory.writeI32(a.heading + 8, wrapDegreesOnce(sub32(memory.readI32(a.windDirection + 8), imul32(sub32(180, memory.readI32(a.downwindLimit + 8)), memory.readI32(a.tack + 8)))));
  }
  if (boat <= r('humanBoatCount')) { B('priorTack', b('tack')); updateTack(memory, boat); }
  boatClass = r('boatClass');
  const boatWind = b('boatWindStrength');
  B('turnFlag', 0);
  let closehauled;
  if (r('catamaranFlag') === 0) {
    const high = Number(BigInt.asIntN(32, (BigInt(boatWind) * 0x55555555n) >> 32n));
    const residual = sub32(high, boatWind);
    closehauled = add32(sub32(sub32(residual >> 1, residual >> 31), idiv32(boatClass, 6)), 45);
  } else closehauled = sub32(46, idiv32(boatWind, 8));
  if (boatClass === 3) closehauled = add32(closehauled, 2);
  if (boatClass === 7) closehauled = sub32(closehauled, 2);
  if (boatClass === 8) closehauled = sub32(closehauled, 6);
  if (r('kiteFlag') === 1) closehauled = 55;
  if (boatClass < 7 || r('catamaranFlag') === 1 || r('sportBoatFlag') === 1) {
    if (boatWind < 11) closehauled = add32(closehauled, 3);
    if (boatWind < 8) closehauled = add32(closehauled, 3);
  }
  w('closehauled', closehauled);
  if ([1,2,4].includes(r('lesson')) && r('maximumHeel') > 10) w('raceComplete', 10);
  if (r('lesson') > 0 && r('time') > 260) w('raceComplete', 1);
  B('targetDistance', add32(abs(sub32(b('targetX'), f('positionX').truncI32())), abs(sub32(b('targetY'), f('positionY').truncI32()))));
  const threshold = boat <= r('humanBoatCount') || r('time') < 1 ? 300 : r('advanceDistance');
  if (r('time') < 31 && r('time') > -4 && b('leg') === 0 && r('matchMode') === 0) {
    targetRelativeBearing(memory, idiv32(add32(r('startBX'), r('startAX')), 2), idiv32(add32(r('startAY'), r('startBY')), 2), 0, boat);
    if (b('targetDistance') < threshold && floating(memory, 0x4a6828).truncI32() < idiv32(r('startWidth'), 2)) {
      w('finishMode', 0); advanceRaceTarget(memory, boat, options);
    }
  }
  if (r('time') >= 31 && b('targetDistance') < threshold && b('leg') < 8) { w('finishMode', 0); advanceRaceTarget(memory, boat, options); }
  if (b('leg') === 8 && b('targetDistance') < idiv32(imul32(r('startWidth'), 3), 4)
    && signedStartDistance(memory, boat, options).compare(floating(memory, 0x484ea8)) <= 0) {
    w('finishMode', 0); advanceRaceTarget(memory, boat, options);
  }
  if (idiv32(r('time'), 5) < sub32(r('time'), r('lastFinishTime')) && b('leg') < 9) {
    B('leg', 8); w('finishMode', 1); advanceRaceTarget(memory, boat, options);
  }
  if (r('warningMode') > 0 && boat <= r('humanBoatCount')) updateCollisionAvoidance(memory, boat, options);
  if (boat <= r('humanBoatCount')) return;
  const bearing = bearingFromVector(sub32(b('targetX'), f('positionX').truncI32()), sub32(f('positionY').truncI32(), b('targetY')));
  let targetAngle = oldHeading;
  if (b('turning') === 0 && b('penaltyFlag') === 0) targetAngle = chooseDownwindHeading(memory, bearing, r('closehauled'), boat, rng, options);
  if (r('closehauled') < targetAngle || b('turning') !== 0 || b('penaltyFlag') !== 0) {
    if (boat === 2 && r('boatCount') === 2) { w('rivalCover', 0); for (let index = 0; index < 40; index++) memory.writeI32(a.debug + index * 4, 0); }
  } else {
    B('heading', sub32(b('windDirection'), imul32(b('tack'), r('closehauled'))));
    if (r('matchMode') === 1 && boat === 2 && add32(r('rivalDecisionTime'), 7) < r('time')) w('rivalDecision', -10);
    if (add32(r('resetTime'), 10) < r('time')) updateUpwindTactics(memory, bearing, boat, rng, options);
  }
  if (boat === 2 && r('rivalCover') === 1 && r('boatCount') === 2) {
    B('heading', sub32(b('windDirection'), imul32(sub32(r('closehauled'), 5), b('tack')))); w('rivalDecision', -9);
  }
  if (r('humanBoatCount') === 1 && r('time') < r('secondBoatDelay') && r('boatCount') === 2 && boat === 2) {
    if (r('time') < add32(r('resetTime'), 10)) { B('heading', r('initialRivalHeading')); return; }
    if (b('tack') === 1 && idiv32(add32(add32(r('resetTime'), 10), r('secondBoatDelay')), 2) < r('time')) {
      if (r('downwindFlag') === 0) { B('heading', wrapDegreesOnce(add32(b('windDirection'), 145))); B('tack', -1); }
      else { B('heading', wrapDegreesOnce(sub32(b('windDirection'), r('closehauled')))); B('tack', 1); }
    }
    if (r('time') < sub32(r('secondBoatDelay'), 5)) B('heading', wrapDegreesOnce(add32(b('windDirection'), imul32(b('tack'), -145))));
    if (sub32(r('secondBoatDelay'), 5) <= r('time')) B('heading', wrapDegreesOnce(add32(b('windDirection'), imul32(b('tack'), -50))));
  }
  if (r('time') < add32(b('turnStarted'), 3) && b('turnFlag') === 0 && b('turning') === 0 && add32(r('resetTime'), 10) < r('time')) B('heading', oldHeading);
  if (b('turning') === 0 && b('turnFlag') === 0 && b('penaltyFlag') === 0 && [1,4,8].includes(b('leg'))) {
    if (wrapDegreesOnce(add32(oldHeading, 30)) < wrapDegreesOnce(b('heading'))
      && wrapDegreesOnce(b('heading')) < wrapDegreesOnce(add32(oldHeading, 180)) && r('reverseCourse') === 1) B('heading', wrapDegreesOnce(add32(oldHeading, 30)));
    if (wrapDegreesOnce(b('heading')) < wrapDegreesOnce(sub32(oldHeading, 30))
      && wrapDegreesOnce(sub32(oldHeading, 180)) < wrapDegreesOnce(b('heading')) && r('reverseCourse') === 0) B('heading', wrapDegreesOnce(sub32(oldHeading, 30)));
  }
  B('turnFlag', 0); updateCollisionAvoidance(memory, boat, options);
  const kiteOffset = r('kiteFlag') === 1 && b('boatWindStrength') <= 9 ? 5 : 0;
  const turning = b('turning');
  if (turning !== 0) {
    const started = b('legStarted');
    if (r('time') === started) B('heading', sub32(b('windDirection'), imul32(r('closehauled'), turning)));
    if (r('time') === add32(started, 1)) B('heading', add32(b('windDirection'), imul32(turning, -30)));
    if (r('time') === add32(started, 2)) { B('tackSlowFlag', 1); B('heading', add32(b('windDirection'), imul32(turning, -15))); }
    if (r('time') === add32(started, 3)) B('heading', add32(b('windDirection'), imul32(turning, 15)));
    if (r('time') === add32(started, 4)) B('heading', add32(b('windDirection'), imul32(turning, 30)));
    if (add32(started, 5) < r('time')) {
      memory.writeF64(at(a.smoothSpeed, boat, 8), 0); B('tack', sub32(0, turning));
      B('heading', sub32(b('windDirection'), imul32(add32(kiteOffset, r('closehauled')), sub32(0, turning)))); B('turning', 0);
    }
  }
  B('heading', wrapDegreesOnce(b('heading'))); updateTack(memory, boat);
  if (r('matchMode') === 1 && boat === 2 && add32(r('rivalDecisionTime'), 7) < r('time') && r('rivalDecision') !== -10 && r('rivalDecision') !== -9) w('rivalDecision', b('heading'));
}
