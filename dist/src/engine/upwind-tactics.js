import { add32, sub32, imul32, idiv32, i32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom, wrapDegreesOnce } from './integer-core.js';
import { bearingFromVector } from './angles.js';
import { aheadAstern, projectionLow32 } from './encounter-geometry.js';

export const UPWIND_TACTICS_ADDRESSES = Object.freeze({
  routine: 0x427030, heading: 0x4ac018, targetAngle: 0x4aba68,
  debug: 0x4a4bf0, rivalCover: 0x4ac9b8, matchMode: 0x4ac9ac,
  metric: 0x4a7f28, priorMetric: 0x4a4510, boatCount: 0x49118c,
  targetX: 0x4a4888, targetY: 0x4a6f48, positionX: 0x4a49e8, positionY: 0x4a4ae0,
  trueWindAngle: 0x4a7bc8, overlap: 0x4a6010, tack: 0x4aa730,
  weather: 0x4a4958, interference: 0x4a7868, targetDistance: 0x4a5268,
  reverseCourse: 0x4ac9a8, time: 0x4a5b80, legStarted: 0x4a41f0,
  matchTurnDelay: 0x4911b8, secondBoatDelay: 0x491168, penaltyFlag: 0x4a76d0,
  course: 0x491194, leg: 0x4a5420, closehauled: 0x4a4eb0,
  trueWindDirection: 0x4aa5b0, baseWindDirection: 0x4a4f8c, difficulty: 0x491190,
  windTactics: 0x4ac9b0, boatWindStrength: 0x4a6338, windStrength: 0x4aa390,
  player1Shore: 0x4a4ee8, rateCoefficient: 0x4a6e48, speed: 0x4a7060,
  previousCurrent: 0x4a4778, current: 0x4ac208, globalTide: 0x4aa298,
  driftRate: 0x4abc7c, oscillationFlag: 0x4a5a48, recentLegDelay: 0x4911bc,
  boatClass: 0x491188, kiteFlag: 0x4ac904, collisionFlag: 0x4a40d0,
  islandFlag: 0x4a5a4c, windShiftType: 0x4a71a4, apparentInterference: 0x4aa82c,
  catamaranFlag: 0x4ac900, skiffFlag: 0x4ac90c, randomRange: 0x4911b0,
  dt: 0x4aa948, score: 0x4a4c8c, turning: 0x4aa660, smoothSpeed: 0x4a71c8,
  penaltyAmount: 0x4a6ec8, rivalDecision: 0x491198, rivalDecisionTime: 0x49119c,
});
const a = UPWIND_TACTICS_ADDRESSES;
const at = (base, boat, stride = 4) => add32(base, imul32(boat, stride)) >>> 0;
const abs = value => value < 0 ? sub32(0, value) : value;
const floating = (memory, address) => Float80.fromNumber(memory.readF64(address));
const signedAngle = angle => { const result = wrapDegreesOnce(angle); return result > 180 ? sub32(result, 360) : result; };

/** Complete 0x427030 tactical tack scoring, including match-race diagnostics. */
export function updateUpwindTactics(memory, bearing, boat, rng, options = {}) {
  bearing = i32(bearing); boat = i32(boat);
  const r = key => memory.readI32(a[key]);
  const w = (key, value) => memory.writeI32(a[key], value);
  const b = key => memory.readI32(at(a[key], boat));
  const B = (key, value) => memory.writeI32(at(a[key], boat), value);
  const f = key => memory.readF64(at(a[key], boat, 8));
  const debug = (offset, value) => memory.writeI32(a.debug + offset, value);
  if (r('matchMode') === 1) { memory.writeF64(a.metric + 16, 100); memory.writeF64(a.priorMetric + 16, 100); }
  const oldHeading = b('heading');
  w('rivalCover', 0);
  for (let index = 0; index < 40; index++) debug(index * 4, 0);
  let angle = abs(sub32(bearing, oldHeading));
  if (angle > 180) angle = sub32(360, angle);
  B('targetAngle', angle);
  let localShift = 0;
  let rivalBearing = 0;
  let ahead = 0;
  if (r('boatCount') === 2) {
    rivalBearing = bearingFromVector(sub32(memory.readI32(a.targetX + 4), floating(memory, a.positionX + 8).truncI32()),
      sub32(floating(memory, a.positionY + 8).truncI32(), memory.readI32(a.targetY + 4)));
    ahead = memory.readI32(a.trueWindAngle + 4) < 90 ? projectionLow32(aheadAstern(memory, 2, 1, options)) : 200;
    localShift = memory.readI32(a.overlap + 4) > 0 && memory.readI32(a.tack + 8) === 1 ? 1 : 0;
  }
  if (f('metric') > (r('weather') < 2 ? 40 : 15) || r('matchMode') === 1) {
    const exit = value => { debug(0, value); };
    if (b('interference') === 12) { exit(8); return; }
    if (angle > 45 && b('targetDistance') < 201 && ((b('tack') === 1 && r('reverseCourse') === 1) || (b('tack') === -1 && r('reverseCourse') === 0))) { exit(9); return; }
    if (r('boatCount') > 2 && r('time') < add32(b('legStarted'), 37)) { exit(1); return; }
    if (r('boatCount') === 2) {
      if (r('time') < add32(r('matchTurnDelay'), b('legStarted')) && r('time') > 0) { exit(1); return; }
      if (r('time') < add32(b('legStarted'), 4) && r('time') < 1) { exit(1); return; }
      if (r('time') < r('secondBoatDelay')) { exit(2); return; }
      if (localShift !== 0) { exit(7); return; }
    }
    if (b('penaltyFlag') === 1) { exit(3); return; }
    if (b('overlap') > 0 && b('targetDistance') > 200) {
      exit(4); if (ahead >= 1 && r('boatCount') === 2) w('rivalCover', 1); return;
    }
  }
  if ((angle < 26 && b('tack') === -1 && r('boatCount') > 2) || (angle < 11 && b('tack') === -1 && r('boatCount') === 2)) { debug(0, 5); return; }
  if (angle < 4 && b('tack') === 1) { debug(0, 6); return; }
  let score = angle < 10 ? -200 : 0;
  let storedScore = score;
  if (angle < 10) debug(4, -200);
  const initial = score;
  if (angle > 55 && b('tack') === 1 && localShift === 0) { score = add32(score, imul32(sub32(angle, 55), 20)); storedScore = score; debug(8, sub32(score, initial)); }
  if (angle > 55 && b('tack') === 1 && b('targetDistance') < 300 && localShift === 0) { score = add32(score, 1000); storedScore = score; debug(8, sub32(score, initial)); }
  if (angle > 65 && b('tack') === 1 && localShift === 0) { score = add32(score, imul32(sub32(angle, 55), 40)); storedScore = score; debug(8, sub32(score, initial)); }
  if (angle > 45 && r('course') === 8) { score = add32(score, imul32(sub32(angle, 45), 80)); storedScore = score; debug(8, sub32(score, initial)); }
  if (angle > 55 && b('tack') === 1 && b('leg') === 1 && localShift === 0) { score = add32(score, imul32(sub32(angle, 55), 40)); storedScore = score; debug(8, sub32(score, initial)); }
  if (angle > 70 && b('tack') === 1 && localShift === 0) { score = add32(score, 4000); storedScore = score; debug(8, sub32(score, initial)); }
  if (angle > idiv32(imul32(r('closehauled'), 9), 5) && b('tack') === -1) { score = add32(score, 600); storedScore = score; debug(116, sub32(score, initial)); }
  let prior = score;
  if (angle > 65) {
    if (b('tack') === 1 && b('targetDistance') > 200 && localShift === 0) { score = add32(score, imul32(sub32(65, angle), 3)); storedScore = score; debug(12, sub32(score, prior)); }
    if (b('tack') === -1 && b('targetDistance') > 400) { score = add32(score, imul32(sub32(angle, 65), add32(imul32(r('reverseCourse'), 18), 3))); storedScore = score; debug(12, sub32(score, prior)); }
  }
  if (angle < 65 || b('targetDistance') < 201) debug(12, 0);
  if (angle < 66 && b('targetDistance') > 200) {
    localShift = signedAngle(sub32(b('trueWindDirection'), r('baseWindDirection')));
    const shiftOnTack = imul32(localShift, b('tack'));
    if (shiftOnTack < 0) {
      prior = score; score = add32(score, abs(localShift)); storedScore = score; debug(16, sub32(score, prior));
      if (r('difficulty') > 9) { prior = score; score = add32(score, imul32(abs(localShift), 6)); storedScore = score; debug(16, sub32(score, prior)); }
    }
    if (shiftOnTack > 0 && r('difficulty') > 9) { prior = score; score = sub32(score, imul32(abs(localShift), 6)); storedScore = score; debug(20, sub32(score, prior)); }
    if (r('matchMode') === 0 || r('windTactics') === 1) {
      if (f('metric') < f('priorMetric') && b('boatWindStrength') < r('windStrength') && r('difficulty') > 7 && b('targetDistance') > 150 && r('player1Shore') === 1 && angle > 15) {
        prior = score; score = add32(score, 100); storedScore = score; debug(24, sub32(score, prior));
      }
      if (f('priorMetric') < f('metric') && b('boatWindStrength') < r('windStrength') && r('difficulty') > 7 && b('targetDistance') > 150 && r('player1Shore') === 1 && angle > 15) {
        prior = score; score = sub32(score, 100); storedScore = score; debug(28, sub32(score, prior));
      }
      const rate = b('rateCoefficient'), speed = b('speed');
      const difference = abs(sub32(rate, speed));
      if (rate < speed) {
        if (b('previousCurrent') < b('current') && r('difficulty') > 8 && difference > 3 && b('targetDistance') > 500) {
          prior = score; score = add32(score, imul32(difference, 20)); storedScore = score; debug(52, sub32(score, prior));
        }
        if (b('current') < b('previousCurrent') && r('difficulty') > 8 && abs(r('globalTide')) > 3 && b('targetDistance') > 500) {
          prior = score; score = sub32(score, imul32(abs(r('globalTide')), 10)); storedScore = score; debug(56, sub32(score, prior));
        }
      }
      if (speed < rate) {
        if (b('current') < b('previousCurrent') && r('difficulty') > 8 && difference > 3 && b('targetDistance') > 500) {
          prior = score; score = add32(score, imul32(difference, 10)); storedScore = score; debug(60, sub32(score, prior));
        }
        if (b('previousCurrent') < b('current') && r('difficulty') > 8 && abs(r('globalTide')) > 3 && b('targetDistance') > 500) {
          prior = score; score = sub32(score, imul32(abs(r('globalTide')), 10)); storedScore = score; debug(64, sub32(score, prior));
        }
      }
    }
    if (imul32(r('driftRate'), b('tack')) > 0 && r('difficulty') > 7 && b('targetDistance') > 300 && angle < 70) {
      prior = score; score = add32(score, imul32(abs(r('driftRate')), r('oscillationFlag') === 1 ? 15 : 5)); storedScore = score; debug(48, sub32(score, prior));
    }
    if (imul32(r('driftRate'), b('tack')) < 0 && r('difficulty') > 7 && b('targetDistance') > 300 && angle < 70) {
      prior = score; score = sub32(score, imul32(abs(r('driftRate')), r('oscillationFlag') === 1 ? 15 : 5)); storedScore = score; debug(48, sub32(score, prior));
    }
    if (r('time') < add32(b('legStarted'), r('recentLegDelay'))) {
      prior = score; if (r('boatClass') > 5 || r('kiteFlag') === 1) { score = sub32(score, 40); storedScore = score; }
      debug(68, sub32(score, prior));
    }
    if (r('difficulty') < 8) { score = add32(score, scaledRandom(50, rng)); storedScore = score; }
  }
  prior = score;
  if (b('collisionFlag') === 1 && r('difficulty') > 5) { score = add32(score, 500); storedScore = score; debug(72, sub32(score, prior)); }
  if (r('difficulty') > 3 && r('boatCount') > 2) {
    if (b('interference') === 2 || b('interference') === 3) { score = add32(score, 500); storedScore = score; }
    debug(72, sub32(score, prior));
  }
  const shallow = r('weather') < 2 ? 50 : 20;
  if (f('metric') < shallow && r('matchMode') === 0 && r('islandFlag') === 0) {
    if (f('metric') < f('priorMetric')) { score = 5000; storedScore = score; }
    if (f('priorMetric') < f('metric')) { score = sub32(score, 500); storedScore = score; }
  }
  if (f('metric') < shallow && r('matchMode') === 0 && r('islandFlag') === 1) {
    score = add32(score, b('tack') === 1 ? 500 : -500); storedScore = score;
  }
  if (r('boatCount') === 2 && boat === 2) {
    prior = score;
    if (b('interference') === 2 || b('interference') === 3) { score = add32(score, 5000); storedScore = score; debug(72, sub32(score, prior)); }
    if (ahead < 0 && r('windShiftType') === 1) {
      prior = score;
      if (imul32(localShift, memory.readI32(a.tack + 8)) < 0 && r('difficulty') > 9) { score = add32(score, imul32(abs(localShift), 2)); storedScore = score; debug(76, sub32(score, prior)); }
      if (imul32(localShift, memory.readI32(a.tack + 8)) > 10 && r('difficulty') > 9) { score = sub32(score, imul32(abs(localShift), 2)); storedScore = score; debug(76, sub32(score, prior)); }
      const difference = sub32(score, prior);
      if (difference > 0) debug(80, difference);
      if (difference < 0) debug(84, difference);
    }
    prior = score;
    const playerTack = memory.readI32(a.tack + 4), rivalTack = memory.readI32(a.tack + 8);
    const rivalDistance = memory.readI32(a.targetDistance + 8);
    if (rivalDistance > 200 && playerTack !== rivalTack && angle < 75 && score < 200 && ahead > 0 && (memory.readI32(a.interference + 4) === 12 || memory.readI32(a.apparentInterference + 4) === 12)) {
      score = add32(score, 20000); storedScore = score; debug(96, sub32(score, prior));
    }
    prior = score;
    if (rivalDistance > 200 && playerTack === rivalTack && angle < 75 && memory.readI32(a.interference + 4) === 2) {
      score = sub32(score, 500); storedScore = score; debug(100, sub32(score, prior));
    }
    const difference = signedAngle(sub32(bearing, rivalBearing));
    if (add32(memory.readI32(a.debug + 96), memory.readI32(a.debug + 100)) === 0) {
      if (ahead > 10 && rivalDistance > 200 && playerTack !== rivalTack) {
        prior = score;
        if (abs(difference) < 4) { score = add32(score, 300); storedScore = score; debug(88, sub32(score, prior)); }
        else {
          if (playerTack === 1 && difference > 3 && difference < 90 && ahead > 15) { prior = score; score = sub32(score, 125); storedScore = score; debug(92, sub32(score, prior)); }
          if (playerTack === -1) {
            if (difference > 3 && difference < 90) { prior = score; score = add32(score, 125); storedScore = score; debug(88, sub32(score, prior)); }
            if (difference < -3 && difference > -90) { prior = score; score = sub32(score, 125); storedScore = score; debug(92, sub32(score, prior)); }
          }
          if (playerTack === 1 && difference <= -4 && difference >= -89) { prior = score; score = add32(score, 125); storedScore = score; debug(88, sub32(score, prior)); }
        }
      }
      if (ahead > 7 && rivalDistance > 200 && playerTack === rivalTack) {
        if (abs(difference) < 4) { prior = score; score = sub32(score, 300); storedScore = score; debug(104, sub32(score, prior)); }
        else {
          if (playerTack === 1 && difference > 3 && difference < 90 && ahead > 20) { prior = score; score = add32(score, 125); storedScore = score; debug(108, sub32(score, prior)); }
          if (playerTack === -1 && difference < -3 && difference > -90 && ahead > 15) { prior = score; score = add32(score, 125); storedScore = score; debug(108, sub32(score, prior)); }
        }
      }
    }
    debug(120, 0);
    let secondBranch = true;
    let staleAngle = angle;
    if (ahead < 21 && rivalDistance > 300 && difference > 2 && difference < 90 && playerTack === 1) {
      prior = score;
      if (rivalTack === 1) { score = sub32(score, 125); storedScore = score; debug(120, sub32(score, prior)); }
      staleAngle = score;
      if (rivalTack === -1) {
        if (ahead < 16) { prior = score; score = add32(score, 125); storedScore = score; debug(120, sub32(score, prior)); }
        else secondBranch = false;
      }
    }
    if (secondBranch) {
      staleAngle = score;
      if (ahead < 16 && rivalDistance > 300 && difference < -2 && difference > -90 && playerTack === -1) {
        prior = score;
        if (rivalTack === -1) { score = sub32(score, 125); storedScore = score; debug(120, sub32(score, prior)); }
        if (rivalTack === 1) { const before = score; score = add32(score, 125); storedScore = score; debug(120, sub32(score, before)); }
        staleAngle = score;
      }
    }
    score = staleAngle;
    if (ahead < -20) {
      prior = score;
      if (rivalDistance > 200 && playerTack === rivalTack && abs(difference) < 3) { score = add32(score, 70); storedScore = score; debug(112, sub32(score, prior)); }
      if (rivalDistance > 200 && playerTack !== rivalTack && abs(difference) < 3) { score = sub32(score, 70); storedScore = score; debug(112, sub32(score, prior)); }
    }
  }
  if (r('catamaranFlag') === 0 && r('kiteFlag') === 0 && r('skiffFlag') === 0) w('randomRange', idiv32(imul32(r('randomRange'), 4), 5));
  if (r('time') > 0 && r('course') === 8) w('randomRange', imul32(r('randomRange'), 4));
  const chance = floating(memory, a.dt).multiply(floating(memory, 0x485160))
    .multiply(Float80.fromInteger(storedScore)).multiply(floating(memory, 0x484d48));
  // Original 0x427f22 passes the unspilled ST0 product directly to __ftol.
  const probability = chance.truncI32();
  w('score', score);
  if (scaledRandom(r('randomRange'), rng) < probability) {
    B('legStarted', r('time')); B('turning', b('tack'));
    B('previousCurrent', b('current'));
    memory.writeBytes(at(a.priorMetric, boat, 8), memory.readBytes(at(a.metric, boat, 8), 8));
    memory.writeF64(at(a.smoothSpeed, boat, 8), floating(memory, at(a.smoothSpeed, boat, 8)).multiply(floating(memory, 0x484ec8)).toNumber());
    B('penaltyAmount', 0);
    if (r('matchMode') === 1 && boat === 2) { w('rivalDecision', -1); w('rivalDecisionTime', r('time')); }
  }
}
