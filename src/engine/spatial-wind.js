import { add32, sub32, imul32, idiv32, i32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { wrapDegreesOnce } from './integer-core.js';
import { bearingFromVector } from './angles.js';
import { sampleUpstreamDistance, sampleShorelineMetric, sampleSpatialMetric, updateShoreDirections } from './current.js';

export const SPATIAL_WIND_ADDRESSES = Object.freeze({
  routine: 0x426150, windDirection: 0x4ac840, strength: 0x4aa390,
  boatWindDirection: 0x4aa5b0, metric: 0x4a7f28, upstreamDistance: 0x4a8678,
  thermalBoost: 0x4a5f0c, player1Patch: 0x4aa62c, player2Patch: 0x4aa638,
  player1Shore: 0x4a4ee8, course: 0x491194, dailyMinimum: 0x4a609c,
  thermal: 0x4ac568, shelterMode: 0x4ac1e0, patchActive: 0x4a5b94,
  patchX: 0x4abd90, patchY: 0x4a4730, patchRadius: 0x4a4ec4,
  patchStrength: 0x4a4e9c, patchDirection: 0x4ac0a0, spatialVariant: 0x4a864c,
  shoreEffect: 0x4a4390, weather: 0x4a4958, shoreDirection: 0x4aa284,
  oppositeShoreDirection: 0x4a71a8, direction: 0x4aaeac, reversal: 0x4ac998,
  islandFlag: 0x4a5a4c, localShift: 0x4abd84, sectorCount: 0x4ac9f4,
  sectorDirection: 0x4a67bc, sectorLeft: 0x4a7184, sectorRight: 0x4a5a54,
  gust: 0x4ac4d8, player1Lull: 0x4a61fc,
});
const a = SPATIAL_WIND_ADDRESSES;
const abs32 = value => value < 0 ? sub32(0, value) : value;
const at = (base, index, stride = 4) => add32(base, imul32(index, stride)) >>> 0;

/** Original 0x426150: spatial wind strength, patch priority and directional smoothing. */
export function sampleSpatialWind(memory, x, y, boat) {
  x = i32(x); y = i32(y); boat = i32(boat);
  const read = name => memory.readI32(a[name]);
  const write = (name, value) => memory.writeI32(a[name], value);
  const previous = boat > 0 ? memory.readI32(at(a.boatWindDirection, boat)) : 0;
  write('thermalBoost', 0);
  if (boat === 1) { write('player1Patch', 0); write('player1Shore', 0); }
  if (boat === 2) write('player2Patch', 0);
  let distance = boat < 1 || memory.readF64(at(a.metric, boat, 8)) <= memory.readF64(0x4850e8)
    ? sampleUpstreamDistance(memory, 1, x, y) : 900;
  const wind = read('windDirection');
  if (read('course') === 9 && wind > 120 && wind < 240) distance = 900;
  if (read('course') === 10 && (wind > 330 || wind < 30)) distance = 900;
  if (boat < 3) memory.writeI32(at(a.upstreamDistance, boat), distance);
  let strength = read('strength');
  if (distance < 900) {
    const half = idiv32(strength, 2);
    strength = add32(Float80.fromInteger(distance).multiply(Float80.fromNumber(memory.readF64(0x485168)))
      .multiply(Float80.fromInteger(half)).truncI32(), half);
  }
  if (read('dailyMinimum') < sub32(read('thermal'), 10) && distance < 900) {
    write('thermalBoost', 1);
    strength = idiv32(imul32(strength, 13), 10);
  }
  if (read('shelterMode') === 1 && distance < 300) strength = idiv32(imul32(strength, 9), 10);
  write('direction', wind);
  write('patchActive', 0);
  let lastPatch = 0;
  for (let patch = 0; patch < 5; patch++) {
    const dx = Float80.fromInteger(x).subtract(Float80.fromNumber(memory.readF64(at(a.patchX, patch, 8))));
    const dy = Float80.fromInteger(y).subtract(Float80.fromNumber(memory.readF64(at(a.patchY, patch, 8))));
    // Original FST binary64 without pop, then xExt*xStored + yExt*yExt.
    const radius = dx.multiply(Float80.fromNumber(dx.toNumber())).add(dy.multiply(dy)).sqrt().truncI32();
    if (radius < memory.readI32(at(a.patchRadius, patch))) {
      write('patchActive', 1);
      strength = add32(strength, memory.readI32(at(a.patchStrength, patch)));
      lastPatch = patch + 1;
      if (boat === 1) write('player1Patch', 1);
      if (boat === 2) write('player2Patch', 1);
    }
  }
  write('shoreEffect', 0);
  const metric = read('spatialVariant') === 1 ? sampleShorelineMetric(memory, x, y, 0) : sampleSpatialMetric(memory, x, y, 0);
  if (metric.truncI32() < (read('weather') < 2 ? 99 : 40)) {
    if (read('course') > 4 && read('course') < 9) updateShoreDirections(memory, x, y);
    const direction = read('windDirection') < 60 ? add32(read('windDirection'), 360) : read('windDirection');
    if (abs32(sub32(direction, read('shoreDirection'))) < 30) {
      strength = idiv32(imul32(strength, 12), 10); write('shoreEffect', 1);
    }
    if (abs32(sub32(direction, read('oppositeShoreDirection'))) < 30) {
      strength = idiv32(imul32(strength, 8), 10); write('shoreEffect', -1);
    }
    if (boat === 1 && read('shoreEffect') !== 0) write('player1Shore', 1);
  }
  let direction;
  if (read('patchActive') === 1) direction = memory.readI32(at(a.patchDirection, lastPatch));
  else direction = add32(read('windDirection'), imul32(read('reversal') === 0
    ? sub32(strength, read('strength')) : sub32(read('strength'), strength), 3));
  if (read('islandFlag') === 1 && direction < 125) direction = 125;
  direction = wrapDegreesOnce(direction);
  write('direction', direction); write('localShift', 0);
  if (read('weather') > 1 && read('weather') !== 5) {
    const radius = Float80.fromInteger(add32(imul32(x, x), imul32(y, y))).sqrt().toNumber();
    const bearing = bearingFromVector(x, sub32(0, y));
    const relative = abs32(sub32(bearing, read('windDirection')));
    const side = relative > 270 ? 2 : (relative < 90 ? 1 : 0);
    const inSector = sector => bearing > add32(imul32(memory.readI32(at(a.sectorLeft, sector)), 2), 5)
      && bearing < sub32(imul32(memory.readI32(at(a.sectorRight, sector)), 2), 5);
    for (let sector = 0; sector < read('sectorCount'); sector++) {
      const heading = memory.readI32(at(a.sectorDirection, sector));
      const difference = abs32(sub32(read('windDirection'), heading));
      if ((difference < 30 || difference > 330) && side !== 0 && radius > memory.readF64(0x485170) && inSector(sector)) {
        direction = heading; write('direction', direction); write('localShift', 1);
      }
    }
    for (let sector = 0; sector < read('sectorCount'); sector++) {
      const heading = wrapDegreesOnce(sub32(memory.readI32(at(a.sectorDirection, sector)), 180));
      const difference = abs32(sub32(read('windDirection'), heading));
      if ((difference < 30 || difference > 330) && side === 0 && radius > memory.readF64(0x485178) && inSector(sector)) {
        direction = heading; write('direction', direction); write('localShift', 1);
      }
    }
    if (read('weather') === 6) {
      if ((wind < 20 || wind > 320) && x < 650 && x > -650 && y < -500) {
        direction = 350; write('direction', direction); write('localShift', 1);
      } else write('localShift', 0);
      if (wind > 140 && wind < 200 && x < 650 && x > -900 && y < -800) {
        direction = 170; write('direction', direction); write('localShift', 1);
      }
    }
    if (read('weather') === 7) {
      if (wind < 225 && wind > 165 && x < 500 && x > -900 && y > 500) {
        direction = 195; write('direction', direction); write('localShift', 1);
      } else write('localShift', 0);
      if (wind >= 0 && wind < 30 && x < 500 && x > -900 && y > 800) {
        direction = 15; write('direction', direction); write('localShift', 1);
      }
    }
  }
  if (strength < 6) strength = 6;
  let gust = add32(idiv32(strength, 10), 1);
  if (distance < 900) gust = idiv32(imul32(distance, gust), 900);
  write('gust', gust);
  if (boat === 1 && strength < sub32(read('strength'), 1)) write('player1Lull', boat);
  if (boat > 0) {
    if (abs32(sub32(previous, direction)) < 180) {
      write('direction', idiv32(add32(direction, imul32(previous, 2)), 3));
      return strength;
    }
    if (previous > 270 && direction < 90) {
      direction = wrapDegreesOnce(idiv32(add32(sub32(direction, 720), imul32(previous, 2)), 3));
      write('direction', direction);
    }
    if (previous < 90 && direction < 270) {
      direction = wrapDegreesOnce(idiv32(add32(sub32(direction, 360), imul32(previous, 2)), 3));
      write('direction', direction);
    }
  }
  return strength;
}
