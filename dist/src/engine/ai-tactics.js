import { add32, sub32, imul32, idiv32, i32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom, wrapDegreesOnce } from './integer-core.js';
import { distanceToBoat } from './movement-helpers.js';
import { aheadAstern, projectionLow32 } from './encounter-geometry.js';

export const AI_TACTICS_ADDRESSES = Object.freeze({
  chooseDownwindHeading: 0x425600, scoreDownwindTurn: 0x425910,
  rivalCover: 0x4ac9b8, heading: 0x4ac018, tack: 0x4aa730,
  trueWindDirection: 0x4aa5b0, targetAngle: 0x4abc00,
  overlap: 0x4a6010, trueWindAngle: 0x4a7bc8, priorTargetAngle: 0x4aba68,
  downwindLimit: 0x4a5f10, sailAngle: 0x4a5e90, boatCount: 0x49118c,
  turnFlag: 0x4a4398, turnStarted: 0x4a7970, time: 0x4a5b80,
  secondBoatDelay: 0x491168, turning: 0x4aa660, legStarted: 0x4a41f0,
  metric: 0x4a7f28, priorMetric: 0x4a4510,
  matchMode: 0x4ac9ac, rivalDecision: 0x491198, rivalDecisionTime: 0x49119c,
  islandFlag: 0x4a5a4c, weather: 0x4a4958, targetDistance: 0x4a5268,
  course: 0x491194, interference: 0x4a7868, starboardObstruction: 0x4aada0,
  forceTurn: 0x4a6804, score: 0x4a681c, startPointX: 0x4aa294, startPointY: 0x4aa388,
  shortenedCourse: 0x491160, reverseCourse: 0x4ac9a8, difficulty: 0x491190,
  randomScore: 0x4a67f4, angleScore: 0x4a67f8, interferenceScore: 0x4a67d4,
  clearScore: 0x4a67d8, windLossScore: 0x4a67dc, metricScore: 0x4a67e0,
  favoredShiftScore: 0x4a67e4, adverseShiftScore: 0x4a67e8,
  adverseDriftScore: 0x4a67ec, favoredDriftScore: 0x4a67f0,
  rivalInterferenceScore: 0x4a6808, rivalClearScore: 0x4a680c,
  windTactics: 0x4ac9b0, windStrength: 0x4aa390, boatWindStrength: 0x4a6338,
  baseWindDirection: 0x4a4f8c, windShiftType: 0x4a71a4, driftRate: 0x4abc7c,
  oscillationFlag: 0x4a5a48, aheadScore: 0x4a67fc, favoredSideScore: 0x4a6800,
  downwindRandomRange: 0x4911b4, dt: 0x4aa948,
});
const a = AI_TACTICS_ADDRESSES;
const at = (base, boat, stride = 4) => add32(base, imul32(boat, stride)) >>> 0;
const abs = value => value < 0 ? sub32(0, value) : value;
const constant = (memory, address) => Float80.fromNumber(memory.readF64(address));

/** Complete original downwind tactical scoring, 0x425910. */
export function scoreDownwindTurn(memory, targetAngle, bearing, boat, rng, options = {}) {
  targetAngle = i32(targetAngle); bearing = i32(bearing); boat = i32(boat);
  const r = key => memory.readI32(a[key]);
  const w = (key, value) => memory.writeI32(a[key], value);
  const b = key => memory.readI32(at(a[key], boat));
  const B = (key, value) => memory.writeI32(at(a[key], boat), value);
  const f = key => memory.readF64(at(a[key], boat, 8));
  const threshold = r('course') === 8 ? 200 : 100;
  if (b('targetDistance') < threshold) return 0;
  const beyondLimit = targetAngle > sub32(180, b('downwindLimit'));
  let response = beyondLimit ? -1 : b('sailAngle');
  if (!beyondLimit && targetAngle > sub32(sub32(180, b('downwindLimit')), response)) response = idiv32(response, 2);
  let result = response;
  if ((r('boatCount') === 2 || scaledRandom(100, rng) < 50)
      && (b('starboardObstruction') === 1 || b('interference') === 2)) {
    if (b('targetDistance') > 200 && add32(b('turnStarted'), 3) < r('time')) {
      response = add32(response, 10); B('turnStarted', r('time'));
    }
    if (beyondLimit && b('targetDistance') > threshold) response = -10;
    const rivalStarboard = r('boatCount') === 2 && memory.readI32(a.tack + 8) === 1;
    w('forceTurn', 1); w('score', 0);
    if (b('interference') !== 2 || scaledRandom(100, rng) > 29 || !beyondLimit
      || r('time') <= add32(b('turnStarted'), 3) || rivalStarboard) return response;
    result = -1; w('forceTurn', 0);
  }
  const startDistance = distanceToBoat(memory, boat, r('startPointX'), r('startPointY'));
  if (startDistance.compare(Float80.fromInteger(imul32(r('boatCount'), 7))) < 0
    && r('shortenedCourse') === 1 && r('boatCount') < 15) {
    B('tack', r('reverseCourse') === 1 ? -1 : 1); return -1;
  }
  w('randomScore', r('boatCount') < 3 || r('difficulty') > 6 ? 0 : scaledRandom(50, rng));
  let difference = abs(sub32(bearing, b('heading')));
  if (difference > 180) difference = sub32(360, difference);
  const limit = b('downwindLimit');
  if (difference < idiv32(limit, 3)) w('randomScore', sub32(r('randomScore'), 50));
  let score = r('randomScore');
  if (difference > limit) score = add32(score, 40);
  if (difference > idiv32(imul32(limit, 6), 5)) score = add32(score, b('tack') === -1 ? 250 : 100);
  const half = idiv32(limit, 2);
  if (difference > half && r('course') === 8) score = add32(score, imul32(sub32(difference, half), 10));
  const lower = idiv32(imul32(limit, r('boatCount') === 2 ? 8 : 7), 5);
  const upper = idiv32(imul32(limit, r('boatCount') === 2 ? 9 : 8), 5);
  if (difference > lower && difference <= upper) score = add32(score, b('tack') === -1 ? 50 : 30);
  if (difference > upper) score = add32(score, b('tack') === -1 ? 1200 : 250);
  w('angleScore', sub32(score, r('randomScore')));
  let next = score;
  if (b('interference') === 2) { next = add32(next, 600); w('interferenceScore', sub32(next, score)); }
  else w('interferenceScore', 0);
  if (b('interference') === 12) { next = sub32(next, 600); w('clearScore', sub32(next, score)); }
  else w('clearScore', 0);
  if (r('boatCount') === 2) {
    if (memory.readI32(a.interference + 4) === 2 && difference < imul32(limit, 2)) {
      const previous = next; next = sub32(next, 300); w('rivalInterferenceScore', sub32(next, previous));
    }
    if (memory.readI32(a.interference + 4) === 12 && memory.readI32(a.trueWindAngle + 4) > 90 && difference < imul32(limit, 2)) {
      const previous = next; next = add32(next, 20000); w('rivalClearScore', sub32(next, previous));
    }
  }
  score = next;
  if (r('windTactics') === 1 || r('matchMode') === 0) {
    const losing = b('boatWindStrength') < r('windStrength') && f('metric') < f('priorMetric');
    if (losing && difference > half) score = add32(score, 200);
    w('windLossScore', sub32(score, next));
    if (losing && difference < idiv32(imul32(limit, 7), 5)) score = sub32(score, 200);
    w('metricScore', sub32(score, next));
  }
  let shift = wrapDegreesOnce(sub32(b('trueWindDirection'), r('baseWindDirection')));
  if (shift > 180) shift = sub32(shift, 360);
  if (difference > idiv32(limit, 2) && difference < idiv32(imul32(limit, 3), 2)) {
    const correction = imul32(imul32(abs(shift), add32(idiv32(r('difficulty'), 2), 4)), add32(r('windShiftType'), 1));
    next = imul32(shift, b('tack')) < 0 ? sub32(score, correction) : add32(score, correction);
    w(imul32(shift, b('tack')) < 0 ? 'adverseShiftScore' : 'favoredShiftScore', sub32(next, score));
    score = next;
    const drift = imul32(imul32(abs(r('driftRate')), add32(r('oscillationFlag'), 1)), 3);
    if (imul32(r('driftRate'), b('tack')) < 0 && b('targetDistance') > 400) {
      score = add32(score, drift); w('adverseDriftScore', sub32(score, next));
    }
    if (imul32(r('driftRate'), b('tack')) > 0 && b('targetDistance') > 400) {
      score = sub32(score, drift); w('favoredDriftScore', sub32(score, next));
    }
  }
  let residual = r('weather') < 2 ? 50 : 20;
  if (f('metric') < f('priorMetric') && f('metric') < residual) score = add32(score, 1000);
  if (r('boatCount') === 2 && memory.readI32(a.trueWindAngle + 8) > 55) {
    residual = sub32(0, projectionLow32(aheadAstern(memory, 2, 1, options)));
    next = score;
    if (residual !== 40 && residual > 39 && difference > limit && b('targetDistance') > 200) next = add32(score, 100);
    w('aheadScore', sub32(next, score)); score = next;
  }
  next = score;
  if (b('targetDistance') < 800 && r('boatCount') === 2
    && difference > idiv32(b('downwindLimit'), 4) && difference < idiv32(imul32(b('downwindLimit'), 3), 2) && abs(residual) < 20) {
    if (r('reverseCourse') === 0 && b('tack') === 1) next = add32(next, 100);
    if (r('reverseCourse') === 1 && b('tack') === -1) next = add32(next, 100);
    w('favoredSideScore', sub32(next, score));
  }
  w('score', next);
  let random = scaledRandom(r('downwindRandomRange'), rng);
  if (r('time') > 0 && r('course') === 8) random = imul32(random, 7);
  const probability = constant(memory, a.dt).multiply(constant(memory, 0x485160))
    .multiply(Float80.fromInteger(idiv32(next, 10))).truncI32();
  if (beyondLimit && random < probability && add32(b('turnStarted'), 10) < r('time')
    && imul32(b('starboardObstruction'), b('tack')) !== 1) {
    B('turnStarted', r('time')); B('tack', sub32(0, b('tack')));
    memory.writeBytes(at(a.priorMetric, boat, 8), memory.readBytes(at(a.metric, boat, 8), 8));
    B('turnFlag', 1);
    if (r('matchMode') === 1 && boat === 2) { w('rivalDecision', -6); w('rivalDecisionTime', r('time')); }
  }
  return result;
}

/** Complete 0x425600: target steering and staged gybe decisions. */
export function chooseDownwindHeading(memory, bearing, closehauled, boat, rng, options = {}) {
  bearing = i32(bearing); closehauled = i32(closehauled); boat = i32(boat);
  const r = key => memory.readI32(a[key]);
  const w = (key, value) => memory.writeI32(a[key], value);
  const b = key => memory.readI32(at(a[key], boat));
  const B = (key, value) => memory.writeI32(at(a[key], boat), value);
  const f = key => memory.readF64(at(a[key], boat, 8));
  w('rivalCover', 0);
  const previousTack = b('tack');
  const previousHeading = b('heading');
  let angle = wrapDegreesOnce(wrapDegreesOnce(abs(sub32(b('trueWindDirection'), bearing))));
  if (angle > 180) angle = sub32(360, angle);
  B('targetAngle', angle);
  if (b('overlap') > 0 && b('tack') === 1 && b('trueWindAngle') < add32(closehauled, 5) && abs(b('priorTargetAngle')) > 60) {
    B('heading', previousHeading); return angle;
  }
  if (angle < 71 || r('time') < 10) {
    if (closehauled < angle) B('heading', bearing);
  } else {
    const turn = scoreDownwindTurn(memory, angle, bearing, boat, rng, options);
    if (turn < 0) {
      const limit = b('downwindLimit');
      let offset = limit < 20 ? idiv32(b('sailAngle'), 2) : sub32(idiv32(b('sailAngle'), 4), 3);
      offset = add32(offset, limit);
      if (r('boatCount') === 2) offset = limit;
      if (offset < 2) offset = 1;
      if (turn === -10) offset = add32(offset, 10);
      if (b('turnFlag') === 1) offset = 3;
      B('heading', wrapDegreesOnce(add32(add32(imul32(offset, b('tack')), 180), b('trueWindDirection'))));
    } else B('heading', add32(imul32(turn, b('tack')), bearing));
  }
  B('heading', wrapDegreesOnce(b('heading')));
  if (r('secondBoatDelay') < r('time') || r('boatCount') !== 2) {
    const currentAngle = b('trueWindAngle');
    const change = abs(sub32(b('heading'), previousHeading));
    if (currentAngle < 70 && change > 65 && change < 180 && b('turning') === 0 && add32(b('legStarted'), 8) < r('time')) {
      B('turning', b('tack'));
      memory.writeBytes(at(a.priorMetric, boat, 8), memory.readBytes(at(a.metric, boat, 8), 8));
      B('tack', previousTack); B('legStarted', r('time')); B('heading', previousHeading);
      if (r('matchMode') === 1 && boat === 2) { w('rivalDecision', -1); w('rivalDecisionTime', r('time')); }
    }
    const side = r('islandFlag') === 1 ? 1 : -1;
    const threshold = r('weather') < 2 ? 40 : 15;
    if (f('metric') < threshold && currentAngle > add32(closehauled, 5)) {
      B('heading', add32(b('heading'), imul32(imul32(Float80.fromInteger(threshold).subtract(Float80.fromNumber(f('metric'))).truncI32(), side), 2)));
    }
    if (f('priorMetric') < threshold && currentAngle > add32(closehauled, 5)) {
      B('heading', add32(b('heading'), imul32(imul32(Float80.fromInteger(threshold).subtract(Float80.fromNumber(f('priorMetric'))).truncI32(), side), 2)));
    }
  }
  return angle;
}
