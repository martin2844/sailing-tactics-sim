import { add32, i32, imul32, sub32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { wrapDegreesOnce } from './integer-core.js';
import { bearingFromVector } from './angles.js';
import { aheadAstern, projectionLow32 } from './encounter-geometry.js';
import { collisionPenalty } from './penalties.js';

export const INTERFERENCE_ADDRESSES = Object.freeze({
  updateInterference: 0x00429f40,
  boatCount: 0x0049118c,
  humanBoatCount: 0x00491140,
  boardFlag: 0x004ac904,
  catamaranFlag: 0x004ac900,
  viewportWidth: 0x004a763c,
  previousInterference: 0x004aa830,
  interference: 0x004a7868,
  windInterference: 0x004a40d0,
  leader: 0x004a6010,
  overlap: 0x004aada0,
  positionX: 0x004a49e8,
  positionY: 0x004a4ae0,
  heading: 0x004ac018,
  tack: 0x004aa730,
  trueWindDirection: 0x004aa5b0,
  trueWindKnots: 0x004a6338,
  angleToWind: 0x004a7bc8,
});

const a = INTERFERENCE_ADDRESSES;
const indexed = (base, boat, stride = 4) => add32(base, imul32(boat, stride)) >>> 0;
const absolute32 = value => value < 0 ? sub32(0, value) : value;
const folded = value => value > 180 ? sub32(360, value) : value;

/** Complete 0x429f40 descending encounter scan and connected collision rules. */
export function updateInterference(memory, boat, rng, options = {}) {
  boat = i32(boat);
  const count = memory.readI32(a.boatCount);
  const read = (field, index = boat) => memory.readI32(indexed(a[field], index));
  const write = (field, value) => memory.writeI32(indexed(a[field], boat), value);
  const position = (field, index) => Float80.fromNumber(memory.readF64(indexed(a[field], index, 8))).truncI32();
  if (count === 2 && read('tack') !== 1 && read('tack') !== -1) throw new RangeError('Original two-boat interference requires tack ±1; other tacks read an uninitialized threshold');
  if (boat === 1) memory.writeI32(a.previousInterference, read('interference'));
  for (const field of ['interference', 'windInterference', 'leader', 'overlap']) write(field, 0);
  const proximity = count === 2 ? 75 : 60;
  for (let other = count; other > 0; other = sub32(other, 1)) {
    if (other === boat) continue;
    // Positions are reread for each boat: a preceding collision can move us.
    const dx = sub32(position('positionX', other), position('positionX', boat));
    const dy = sub32(position('positionY', boat), position('positionY', other));
    const distance = add32(absolute32(dx), absolute32(dy));
    if (distance < 30 && read('tack') === read('tack', other)) write('overlap', 1);
    if (distance >= proximity) continue;
    const bearing = bearingFromVector(dx, dy);
    const windDiff = folded(absolute32(sub32(read('trueWindDirection'), bearing)));
    const headingDiff = folded(wrapDegreesOnce(absolute32(sub32(read('heading'), bearing))));
    const near = read('trueWindKnots') < 11 ? 30 : 20;
    const humans = memory.readI32(a.humanBoatCount);
    if (headingDiff < 40 && distance < near && boat > humans) write('windInterference', 1);
    const board = memory.readI32(a.boardFlag);
    if (headingDiff < 25 && distance < near && board === 0 && boat <= humans) write('windInterference', 1);
    if (headingDiff < 30 && distance < near && board === 1 && boat <= humans) write('windInterference', 1);
    let tack = read('tack');
    if (tack !== read('tack', other)) write('windInterference', 0);
    let leaderRadius;
    if (memory.readI32(a.boatCount) === 2) {
      if (tack === 1) leaderRadius = absolute32(projectionLow32(aheadAstern(memory, boat, other, options))) > 9 ? 65 : 75;
      tack = read('tack');
      if (tack === -1) leaderRadius = 50;
    } else leaderRadius = tack === 1 ? 40 : 30;
    if (distance < leaderRadius && headingDiff > 100 && tack === read('tack', other) && windDiff < 120 && tack === 1) write('leader', other);
    if (windDiff < 25) write('interference', tack === read('tack', other) ? 2 : 12);
    if (headingDiff < 23 && tack === read('tack', other) && read('angleToWind') < 60 && read('angleToWind', other) < 90) write('interference', 3);
    let threshold = 6;
    if (tack !== read('tack', other)) {
      const headingDelta = sub32(read('heading'), read('heading', other));
      if (wrapDegreesOnce(headingDelta) >= 30 && wrapDegreesOnce(add32(headingDelta, 180)) >= 30) threshold = 8;
    }
    if (memory.readI32(a.catamaranFlag) === 1) threshold = 8;
    if (memory.readI32(a.viewportWidth) > 900) threshold = sub32(threshold, 1);
    if (distance < threshold) collisionPenalty(memory, other, boat, distance, rng, options);
  }
}

export const FUN_00429f40 = updateInterference;
