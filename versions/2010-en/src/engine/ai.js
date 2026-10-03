import { i32 } from '../../../../src/runtime/c-types.js';
import {
  originalUpdateBoatWindAndAI, originalChooseDownwindHeading, originalScoreDownwindTurn,
  originalSampleSpatialWind, originalUpdateUpwindTactics, originalUpdateCollisionAvoidance,
  originalAvoidAiCollision, originalWarnHumanRightOfWay, originalRequestRightOfWaySound,
  originalSampleVenueWind,
} from './ai-functions.js';

export const AI_ROUTINES = Object.freeze({
  updateBoatWindAndAI: 0x434f70, chooseDownwindHeading: 0x435fe0,
  scoreDownwindTurn: 0x436400, sampleSpatialWind: 0x436ba0,
  updateUpwindTactics: 0x437e60, updateCollisionAvoidance: 0x439100,
  avoidAiCollision: 0x4391f0, warnHumanRightOfWay: 0x439a30,
  requestRightOfWaySound: 0x439df0, sampleVenueWind: 0x488d70,
});
const context = (rng, options) => ({ ...options, rng });
const requireRng = rng => {
  if (typeof rng?.rand !== 'function') throw new TypeError('Original 2010 AI requires its retained CRT RNG');
  return rng;
};

/** Complete original 0x434f70, with every original numeric child executed. */
export function updateBoatWindAndAI(memory, boat, rng, options = {}) {
  return originalUpdateBoatWindAndAI(memory, requireRng(rng), context(rng, options), i32(boat));
}
export function chooseDownwindHeading(memory, desiredHeading, closehauled, boat, rng, options = {}) {
  return originalChooseDownwindHeading(memory, requireRng(rng), context(rng, options), i32(desiredHeading), i32(closehauled), i32(boat));
}
export function scoreDownwindTurn(memory, targetAngle, desiredHeading, boat, rng, options = {}) {
  return originalScoreDownwindTurn(memory, requireRng(rng), context(rng, options), i32(targetAngle), i32(desiredHeading), i32(boat));
}
export function sampleSpatialWind(memory, x, y, boat, options = {}) {
  return originalSampleSpatialWind(memory, options.rng, options, i32(x), i32(y), i32(boat));
}
export function sampleVenueWind(memory, x, y, boat, options = {}) {
  return originalSampleVenueWind(memory, options.rng, options, i32(x), i32(y), i32(boat));
}
export function updateUpwindTactics(memory, desiredHeading, boat, rng, options = {}) {
  return originalUpdateUpwindTactics(memory, requireRng(rng), context(rng, options), i32(desiredHeading), i32(boat));
}
export function updateCollisionAvoidance(memory, boat, options = {}) {
  return originalUpdateCollisionAvoidance(memory, options.rng, options, i32(boat));
}
export function avoidAiCollision(memory, distance, otherBoat, boat, tack, options = {}) {
  return originalAvoidAiCollision(memory, options.rng, options, i32(distance), i32(otherBoat), i32(boat), i32(tack));
}
export function warnHumanRightOfWay(memory, distance, otherBoat, boat, options = {}) {
  return originalWarnHumanRightOfWay(memory, options.rng, options, i32(distance), i32(otherBoat), i32(boat));
}
export function requestRightOfWaySound(memory, boat, options = {}) {
  return originalRequestRightOfWaySound(memory, options.rng, options, i32(boat));
}
