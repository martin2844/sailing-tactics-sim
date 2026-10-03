import { add32, i32, idiv32, imul32, sub32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom, wrapDegreesOnce } from './integer-core.js';
import { bearingFromVector } from './angles.js';
import { sampleShorelineMetric, sampleSpatialMetric } from './current.js';
import { projectPoint } from './race-targets.js';

export const COURSE_ADDRESSES = Object.freeze({
  initializeCourse: 0x004201a0,
  baseWindDirection: 0x004a4f8c, courseHeading: 0x004abc80,
  courseLength: 0x004ab184, difficulty: 0x00491190,
  boatCount: 0x0049118c, optimistFlag: 0x004ac914,
  catamaranFlag: 0x004ac900, skiffFlag: 0x004ac90c,
  speedLevel: 0x0049116c, course: 0x00491194, islandFlag: 0x004a5a4c,
  shortenedCourse: 0x00491160, lengthReduction: 0x004ac954,
  startWidth: 0x004aa998, startAX: 0x004aa594, startAY: 0x004aa59c,
  startBX: 0x004a70f8, startBY: 0x004a72c8,
  markCX: 0x004aa294, markCY: 0x004aa388,
  markDX: 0x004aa38c, markDY: 0x004aa588,
  markEX: 0x004aa288, markEY: 0x004aa384,
  pointX: 0x004a70e8, pointY: 0x004aa81c,
  reversal: 0x004a4378, reverseCourse: 0x004ac9a8,
  spatialVariant: 0x004a864c, weather: 0x004a4958,
  legHeading: 0x004a6440, legLength: 0x004a6458,
  spawnX: 0x004a4be0, spawnY: 0x004a4f84,
  targetX: 0x004a8a50, targetY: 0x004a8a80,
  renderX: 0x004a52f8, renderY: 0x004a60b8,
  metricThreshold: 0x004850c8,
});

const a = COURSE_ADDRESSES;
const integer = value => Float80.fromInteger(value);

/** Complete 0x4201a0, including its recursive course shortening and RNG order. */
export function initializeCourse(memory, length, rng, options = {}) {
  length = i32(length);
  const read = key => memory.readI32(a[key]);
  const write = (key, value) => memory.writeI32(a[key], value);
  const point = (x, y, distance, heading) => projectPoint(memory, x, y, distance, heading, options);
  const pointInto = (xKey, yKey, x, y, distance, heading) => {
    point(x, y, distance, heading);
    write(xKey, read('pointX'));
    write(yKey, read('pointY'));
  };
  const metric = (x, y) => read('spatialVariant') === 1
    ? sampleShorelineMetric(memory, x, y, 0) : sampleSpatialMetric(memory, x, y, 0);
  const tooClose = (x, y) => metric(x, y).compare(Float80.fromNumber(memory.readF64(a.metricThreshold))) < 0;
  const canShorten = () => read('islandFlag') === 0 && read('course') !== 8 && read('weather') < 2;
  const shorten = () => {
    length = sub32(length, 1);
    initializeCourse(memory, length, rng, options);
  };
  write('courseHeading', read('baseWindDirection'));
  write('courseLength', imul32(length, 100));
  let roundingRadius = read('difficulty') >= 7 ? 53 : 65;
  if (read('boatCount') === 2) roundingRadius = 40;
  if (read('optimistFlag') === 1) roundingRadius = add32(roundingRadius, 2);
  if (read('catamaranFlag') === 1 || read('skiffFlag') === 1) roundingRadius = add32(roundingRadius, 5);
  if (read('speedLevel') < 13 && read('boatCount') > 2) roundingRadius = sub32(roundingRadius, 4);
  if (read('speedLevel') < 11 && read('boatCount') > 2) roundingRadius = sub32(roundingRadius, 4);
  if (read('course') === 8 && read('islandFlag') === 0) {
    write('courseHeading', 90);
    write('courseLength', 3300);
    write('shortenedCourse', 1);
  }
  if (read('course') === 8) {
    if (read('islandFlag') === 1) write('courseLength', 2200);
    roundingRadius = add32(roundingRadius, 10);
  }
  if (read('lengthReduction') === 1) write('courseLength', imul32(idiv32(read('courseLength'), 10), 7));
  write('startWidth', imul32(add32(read('boatCount'), 10), 10));
  if (read('boatCount') === 2) write('startWidth', 125);
  write('startAX', 0);
  write('startAY', 0);
  if (read('course') === 1) write('startAY', 350);
  if (read('course') === 2) write('startAX', -250);
  if (read('course') === 3) write('startAY', -350);
  if (read('course') === 4) write('startAX', 250);
  if (read('reversal') === 1) write('startAX', 500);
  if (read('course') === 9) { write('startAX', 0); write('startAY', -400); }
  if (read('course') === 10) { write('startAX', 0); write('startAY', 400); }
  let lateralLength = read('islandFlag') === 1 ? read('courseLength') : idiv32(imul32(read('courseLength'), 3), 4);
  if (read('course') === 10) lateralLength = idiv32(read('courseLength'), 3);
  if (read('shortenedCourse') === 1) lateralLength = read('boatCount') < 15 ? 1 : read('courseLength');
  const handedness = read('reverseCourse') === 1 && read('islandFlag') === 0 ? -1 : 1;
  const quarterTurn = imul32(handedness, 90);
  pointInto('startBX', 'startBY', read('startAX'), read('startAY'), read('startWidth'), add32(read('courseHeading'), quarterTurn));
  memory.writeI32(a.legHeading, wrapDegreesOnce(add32(read('courseHeading'), quarterTurn)));
  memory.writeI32(a.legLength, read('startWidth'));
  pointInto('markCX', 'markCY', idiv32(add32(read('startAX'), read('startBX')), 2),
    idiv32(add32(read('startBY'), read('startAY')), 2), read('courseLength'), read('courseHeading'));
  const deltaX = sub32(read('markCX'), read('startAX'));
  const deltaY = sub32(read('startAY'), read('markCY'));
  memory.writeI32(a.legHeading + 4, bearingFromVector(deltaX, deltaY));
  memory.writeI32(a.legLength + 4, integer(deltaX).multiply(integer(deltaX)).add(integer(deltaY).multiply(integer(deltaY))).sqrt().truncI32());
  if (tooClose(read('markCX'), read('markCY')) && canShorten()) shorten();
  let lateralHeading = read('islandFlag') === 1 || read('course') === 9
    ? sub32(read('courseHeading'), quarterTurn)
    : add32(imul32(sub32(scaledRandom(60, rng), 120), handedness), read('courseHeading'));
  if (read('course') === 10) lateralHeading = sub32(read('courseHeading'), imul32(handedness, 110));
  if (read('shortenedCourse') === 1 && read('boatCount') > 14) {
    lateralHeading = sub32(read('courseHeading'), imul32(handedness, 5));
    lateralLength = read('courseLength');
  }
  pointInto('markDX', 'markDY', read('startAX'), read('startAY'), lateralLength, lateralHeading);
  memory.writeI32(a.legHeading + 8, wrapDegreesOnce(lateralHeading));
  memory.writeI32(a.legLength + 8, lateralLength);
  const lateralTooClose = tooClose(read('markDX'), read('markDY'));
  if (lateralTooClose && canShorten()) shorten();
  const finalOffset = read('islandFlag') === 0 ? 180 : 200;
  const finalHeading = sub32(read('courseHeading'), imul32(handedness, finalOffset));
  pointInto('markEX', 'markEY', read('startAX'), read('startAY'), read('courseLength'), finalHeading);
  memory.writeI32(a.legHeading + 12, wrapDegreesOnce(finalHeading));
  memory.writeI32(a.legLength + 12, read('courseLength'));
  if (tooClose(read('markEX'), read('markEY')) && canShorten()) shorten();
  const divisor = read('course') === 8 ? 21 : 8;
  const weight = read('course') === 8 ? 20 : 7;
  write('spawnX', idiv32(add32(imul32(read('startBX'), weight), read('markEX')), divisor));
  write('spawnY', idiv32(add32(imul32(read('startBY'), weight), read('markEY')), divisor));
  const target = (index, x, y, distance, heading) => {
    point(x, y, distance, heading);
    memory.writeI32(a.targetX + index * 4, read('pointX'));
    memory.writeI32(a.targetY + index * 4, read('pointY'));
  };
  target(1, read('markCX'), read('markCY'), roundingRadius, add32(read('courseHeading'), quarterTurn));
  target(2, read('markCX'), read('markCY'), idiv32(imul32(roundingRadius, 2), 3), read('courseHeading'));
  target(3, read('markCX'), read('markCY'), roundingRadius, sub32(read('courseHeading'), imul32(handedness, 60)));
  target(4, read('markDX'), read('markDY'), roundingRadius, sub32(read('courseHeading'), imul32(handedness, 55)));
  target(5, read('markDX'), read('markDY'), roundingRadius, sub32(read('courseHeading'), imul32(handedness, 135)));
  target(6, read('markEX'), read('markEY'), roundingRadius, sub32(read('courseHeading'), imul32(handedness, 115)));
  target(7, read('markEX'), read('markEY'), roundingRadius, add32(read('courseHeading'), imul32(handedness, 135)));
  if (read('shortenedCourse') === 1 && read('boatCount') < 15) {
    write('markDX', read('markEX'));
    write('markDY', read('markEY'));
    for (const index of [4, 5]) {
      memory.writeI32(a.targetX + index * 4, memory.readI32(a.targetX + 24));
      memory.writeI32(a.targetY + index * 4, memory.readI32(a.targetY + 24));
    }
    memory.writeI32(a.legHeading + 8, memory.readI32(a.legHeading + 12));
    memory.writeI32(a.legLength + 8, memory.readI32(a.legLength + 12));
  }
  const pairs = [['startAX', 'startAY'], ['startBX', 'startBY'], ['markCX', 'markCY'], ['markDX', 'markDY'], ['markEX', 'markEY']];
  pairs.forEach(([x, y], index) => {
    memory.writeF64(a.renderX + index * 8, read(x));
    memory.writeF64(a.renderY + index * 8, read(y));
  });
  memory.writeI32(a.targetX + 36, memory.readI32(a.targetX + 4));
  memory.writeI32(a.targetY + 36, memory.readI32(a.targetY + 4));
  memory.writeI32(a.targetX + 32, idiv32(add32(read('startAX'), read('startBX')), 2));
  const midpointY = idiv32(add32(read('startBY'), read('startAY')), 2);
  memory.writeI32(a.targetY + 32, midpointY);
  return midpointY;
}

export const FUN_004201a0 = initializeCourse;
