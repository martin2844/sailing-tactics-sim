import { add32, i32, idiv32, imul32, sub32 } from '../runtime/index.js';
import { Float80,getX87ControlWord } from '../runtime/float80.js';
import { wrapDegreesOnce } from './integer-core.js';
import { bearingFromVector } from './angles.js';
import { nativeTrig } from './native-trig.js';

export const CURRENT_ADDRESSES = Object.freeze({
  sampleShorelineMetric: 0x00420b70,
  sampleSpatialMetric: 0x00420c40,
  sampleBoundaryMetric: 0x00420d10,
  sampleCurrent: 0x00421560,
  updateShoreDirections: 0x00421ae0,
  sampleUpstreamDistance: 0x00421b80,
  refreshFlag: 0x004a60a0,
  resetTime: 0x004a4168,
  time: 0x004a5b80,
  spatialVariant: 0x004a864c,
  tidePhaseHour: 0x004a8020,
  tideOffsetHours: 0x004ac94c,
  hour: 0x004a4be4,
  tideAmplitude: 0x004ac1dc,
  islandFlag: 0x004a5a4c,
  centerX: 0x004ac284,
  centerY: 0x004a3a08,
  weather: 0x004a4958,
  currentBaseDirection: 0x004aae1c,
  course: 0x00491194,
  shore: 0x004aa804,
  shoreY: 0x004aa290,
  placementMode: 0x004ac85c,
  branchDirection1: 0x004a67bc,
  branchDirection2: 0x004a67c4,
  centerDirection: 0x004a67c0,
  tideCycleFlag: 0x00491158,
  reversal: 0x004a4378,
  radius: 0x004abae8,
  windDirection: 0x004ac840,
  globalTide: 0x004aa298,
  axisScaleX: 0x004a6470,
  axisScaleY: 0x004abe60,
  cachedMetric: 0x004a7f28,
  shorelineX: 0x004a6490,
  shorelineY: 0x004a68c8,
  boundaryRadius: 0x004a8028,
  currentStrength: 0x004ac208,
  previousStrength: 0x004a4778,
  rawCurrent: 0x004aa800,
  currentEffect: 0x004aa720,
  currentDirection: 0x004aa960,
  shoreDirection: 0x004aa284,
  oppositeShoreDirection: 0x004a71a8,
  sine: 0x004a54a0,
  cosine: 0x004a3450,
  interpolateScale: 0x004850d0,
  shorelineScale: 0x00485058,
  zero: 0x00484e18,
  spatialScale: 0x004850d8,
  boundaryBase: 0x00484e88,
  one: 0x00484e10,
  boundaryScale: 0x004850e0,
  half: 0x00484da8,
});

/** Hardware-captured FSIN m80 for each supported current phase angle. */
export const CURRENT_SINE_BITS = Object.freeze({
  "0": "00000000000000000000",
  "30": "d63de6e380670080fe3f",
  "60": "46e00d6bc64eb4ddfe3f",
  "90": "a3eae904fffffffffe3f",
  "120": "77c2382d39e8b2ddfe3f",
  "150": "c8d410d4f3f4fbfffd3f",
  "180": "1eb799faf20d46b3f0bf",
  "210": "b38f68f183d40280febf",
  "240": "39b44bdd4cb5b5ddfebf",
  "270": "c43f392cf7fffffffebf",
  "300": "2758d723a581b1ddfebf",
  "330": "6f3cc407de1af7fffdbf",
  "360": "7e1c453bf00d46b3f13f",
  "390": "3e577c1283410580fe3f",
  "420": "2c41e783cc1bb7ddfe3f",
  "450": "45ead77ae7fffffffe3f",
  "480": "e89ef44e0a1bb0ddfe3f",
  "510": "96c40c63c040f2fffd3f",
  "540": "20144abd708a7486f2bf",
  "570": "d98b0e477eae0780febf",
  "600": "2b8ad55e4582b8ddfebf",
  "630": "a0eac5f0cffffffffebf",
  "660": "7f949bae68b4aeddfebf",
  "690": "6e7f10e69a66edfffdbf",
  "720": "3cb2f23de50d46b3f23f",
  "750": "06250c8f751b0a80fe3f",
  "780": "7e920b6eb7e8b9ddfe3f",
  "810": "8e41038eb0fffffffe3f",
  "840": "e836d742c04dadddfe3f",
  "870": "677ff5906d8ce8fffd3f",
  "900": "831bf23f549117e0f2bf",
  "930": "631a62ea68880c80febf",
  "960": "9d5d7eb1224fbbddfebf",
  "990": "05f08f5289fffffffebf",
  "1020": "5384b20b11e7abddfebf",
  "1050": "2ed7e16338b2e3fffdbf",
  "1080": "8801cf315e8a7486f33f",
  "-1080": "8801cf315e8a7486f3bf",
  "-1050": "2ed7e16338b2e3fffd3f",
  "-1020": "5384b20b11e7abddfe3f",
  "-990": "05f08f5289fffffffe3f",
  "-960": "9d5d7eb1224fbbddfe3f",
  "-930": "631a62ea68880c80fe3f",
  "-900": "831bf23f549117e0f23f",
  "-870": "677ff5906d8ce8fffdbf",
  "-840": "e836d742c04dadddfebf",
  "-810": "8e41038eb0fffffffebf",
  "-780": "7e920b6eb7e8b9ddfebf",
  "-750": "06250c8f751b0a80febf",
  "-720": "3cb2f23de50d46b3f2bf",
  "-690": "6e7f10e69a66edfffd3f",
  "-660": "7f949bae68b4aeddfe3f",
  "-630": "a0eac5f0cffffffffe3f",
  "-600": "2b8ad55e4582b8ddfe3f",
  "-570": "d98b0e477eae0780fe3f",
  "-540": "20144abd708a7486f23f",
  "-510": "96c40c63c040f2fffdbf",
  "-480": "e89ef44e0a1bb0ddfebf",
  "-450": "45ead77ae7fffffffebf",
  "-420": "2c41e783cc1bb7ddfebf",
  "-390": "3e577c1283410580febf",
  "-360": "7e1c453bf00d46b3f1bf",
  "-330": "6f3cc407de1af7fffd3f",
  "-300": "2758d723a581b1ddfe3f",
  "-270": "c43f392cf7fffffffe3f",
  "-240": "39b44bdd4cb5b5ddfe3f",
  "-210": "b38f68f183d40280fe3f",
  "-180": "1eb799faf20d46b3f03f",
  "-150": "c8d410d4f3f4fbfffdbf",
  "-120": "77c2382d39e8b2ddfebf",
  "-90": "a3eae904fffffffffebf",
  "-60": "46e00d6bc64eb4ddfebf",
  "-30": "d63de6e380670080febf"
});

const a = CURRENT_ADDRESSES;
const sineValues = new Map(Object.entries(CURRENT_SINE_BITS).map(([angle, bits]) => [
  Number(angle), Float80.fromBytes(Uint8Array.from(bits.match(/../g), byte => parseInt(byte, 16))),
]));
const indexed = (base, index, stride = 4) => add32(base, imul32(index, stride)) >>> 0;
const absolute32 = value => value < 0 ? sub32(0, value) : value;
const readExtended = (memory, address) => Float80.fromNumber(memory.readF64(address));

function storeMetric(memory, boat, result) {
  if (boat > 0) memory.writeF64(indexed(a.cachedMetric, boat, 8), result.toNumber());
  // The original FST does not pop: callers consume this unrounded ST0 value.
  return result;
}

/** 0x420b70: interpolated shoreline metric; return retains original ST0 precision. */
export function sampleShorelineMetric(memory, x, y, boat) {
  x = i32(x); y = i32(y); boat = i32(boat);
  let index = add32(idiv32(sub32(x, memory.readI32(a.shorelineX + 8)), 250), 2);
  if (index < 2) index = 2;
  const startX = memory.readI32(indexed(a.shorelineX, index));
  const startY = memory.readI32(indexed(a.shorelineY, index));
  const nextY = memory.readI32(indexed(a.shorelineY, add32(index, 1)));
  const interpolated = Float80.fromInteger(sub32(x, startX))
    .multiply(readExtended(memory, a.interpolateScale))
    .multiply(Float80.fromInteger(sub32(nextY, startY))).truncI32();
  let shoreline = add32(interpolated, startY);
  if (index < 3) shoreline = memory.readI32(a.shorelineY + 8);
  let result = Float80.fromInteger(absolute32(sub32(shoreline, y))).multiply(readExtended(memory, a.shorelineScale));
  const shore = memory.readI32(a.shore);
  if ((shore === 1 && y < shoreline) || (shore === 3 && y > shoreline)) result = readExtended(memory, a.zero);
  return storeMetric(memory, boat, result);
}

/** 0x420d10: radial boundary metric for weather/course variants above one. */
export function sampleBoundaryMetric(memory, x, y, boat) {
  x = i32(x); y = i32(y); boat = i32(boat);
  const bearing = bearingFromVector(x, sub32(0, y));
  let index = idiv32(bearing, 2);
  if (index < 0 || index > 180) index = 0;
  let boundary = readExtended(memory, indexed(a.boundaryRadius, index, 8));
  if ((absolute32(bearing) & 1) !== 0 && index <= 178) {
    boundary = boundary.add(readExtended(memory, indexed(a.boundaryRadius, add32(index, 1), 8)))
      .multiply(readExtended(memory, a.half));
  }
  const squared = add32(imul32(x, x), imul32(y, y));
  const fraction = Float80.fromInteger(squared).sqrt().divide(boundary);
  let result = readExtended(memory, a.boundaryBase).subtract(
    readExtended(memory, a.one).subtract(fraction).multiply(readExtended(memory, a.boundaryScale)),
  );
  const zero = readExtended(memory, a.zero);
  if (result.compare(zero) < 0) result = zero;
  return storeMetric(memory, boat, result);
}

/** 0x420c40: normalized radial metric, or its weather-specific boundary variant. */
export function sampleSpatialMetric(memory, x, y, boat) {
  x = i32(x); y = i32(y); boat = i32(boat);
  if (memory.readI32(a.weather) > 1) return sampleBoundaryMetric(memory, x, y, boat);
  const normalizedX = Float80.fromInteger(sub32(x, memory.readI32(a.centerX)))
    .divide(readExtended(memory, a.axisScaleX));
  const normalizedY = Float80.fromInteger(sub32(y, memory.readI32(a.centerY)))
    .divide(readExtended(memory, a.axisScaleY));
  // 0x420cb6 FST spills X to binary64, then multiplies its extended original
  // by that rounded copy. Y has no spill before its square.
  const squareX = normalizedX.multiply(Float80.fromNumber(normalizedX.toNumber()));
  const squareY = normalizedY.multiply(normalizedY);
  const fraction = squareX.add(squareY).sqrt().divide(Float80.fromInteger(memory.readI32(a.radius)));
  const scale = readExtended(memory, a.spatialScale);
  let result = scale.subtract(fraction.multiply(scale));
  result = memory.readI32(a.islandFlag) === 0 ? result.add(result) : result.negate();
  if (memory.readI32(a.reversal) === 1) result = result.add(result);
  return storeMetric(memory, boat, result);
}

/** 0x421ae0: update both shore directions, retaining the residual original EAX. */
export function updateShoreDirections(memory, x, y) {
  x = i32(x); y = i32(y);
  if (memory.readI32(a.weather) === 5) {
    if (y <= 0) {
      memory.writeI32(a.oppositeShoreDirection, 270);
      memory.writeI32(a.shoreDirection, 90);
    } else {
      memory.writeI32(a.shoreDirection, 270);
      memory.writeI32(a.oppositeShoreDirection, 90);
    }
    return y;
  }
  let bearing = bearingFromVector(sub32(memory.readI32(a.centerX), x), sub32(y, memory.readI32(a.centerY)));
  if (memory.readI32(a.islandFlag) === 0) bearing = add32(bearing, 180);
  memory.writeI32(a.shoreDirection, wrapDegreesOnce(add32(bearing, 90)));
  const opposite = wrapDegreesOnce(sub32(bearing, 90));
  memory.writeI32(a.oppositeShoreDirection, opposite);
  return opposite;
}

/** 0x421b80: discrete upstream shore distance, including its repeated zero step. */
export function sampleUpstreamDistance(memory, mode, x, y) {
  mode = i32(mode); x = i32(x); y = i32(y);
  let direction = memory.readI32(mode === 1 ? a.windDirection : a.currentBaseDirection);
  if (mode !== 1 && memory.readI32(a.globalTide) < 0) direction = add32(direction, 180);
  direction = wrapDegreesOnce(direction);
  for (let distance = 300; distance <= 3300; distance = add32(distance, 300)) {
    const step = idiv32(distance, 400);
    const sampleX = add32(x, imul32(step, memory.readI32(indexed(a.sine, direction))));
    const sampleY = sub32(y, imul32(step, memory.readI32(indexed(a.cosine, direction))));
    const metric = memory.readI32(a.spatialVariant) === 1
      ? sampleShorelineMetric(memory, sampleX, sampleY, 0)
      : sampleSpatialMetric(memory, sampleX, sampleY, 0);
    if (metric.truncI32() < 5) return imul32(step, 100);
  }
  return 900;
}

/**
 * Complete 0x421560 current sampler. All integers wrap at original instructions;
 * called spatial samplers retain extended results through the native __ftol.
 * FSIN uses hardware-captured values for multiples of 30 in [-1080,1080].
 * Unsupported angles/nonfinite arithmetic throw; x87 status flags are unmodeled.
 */
export function sampleCurrent(memory, x, y, boat, options={}) {
  x = i32(x); y = i32(y); boat = i32(boat);
  const read = key => memory.readI32(a[key]);
  const write = (key, value) => memory.writeI32(a[key], value);
  if (read('refreshFlag') === 1) {
    memory.writeI32(indexed(a.previousStrength, boat), memory.readI32(indexed(a.currentStrength, boat)));
  }
  if (boat === 1) write('currentEffect', 0);
  const metric = read('time') > add32(read('resetTime'), 10) && boat > 0
    ? readExtended(memory, indexed(a.cachedMetric, boat, 8))
    : read('spatialVariant') === 1 ? sampleShorelineMetric(memory, x, y, 0) : sampleSpatialMetric(memory, x, y, 0);
  const depth = metric.truncI32();
  const phase = add32(add32(sub32(depth >= 30 ? 0 : -1, read('tidePhaseHour')), read('tideOffsetHours')), read('hour'));
  const angle = imul32(phase, 30);
  const sine = (getX87ControlWord()&0x300)===0x300&&!options.trig?sineValues.get(angle):nativeTrig(angle,options).sine;
  if (!sine) throw new RangeError(`Original current FSIN angle ${angle} is outside the captured -1080..1080 domain`);
  let strength = sine.multiply(Float80.fromInteger(read('tideAmplitude'))).truncI32();
  write('rawCurrent', strength);
  const island = read('islandFlag');
  const weather = read('weather');
  if (island === 1 && absolute32(sub32(x, read('centerX'))) < 200) {
    strength = idiv32(imul32(strength, 14), 10);
    if (boat === 1) write('currentEffect', -1);
  }
  if (depth < 70 && weather !== 4) {
    strength = idiv32(imul32(strength, depth), 70);
    if (boat === 1) write('currentEffect', 1);
  }
  const baseDirection = read('currentBaseDirection');
  let direction = wrapDegreesOnce(strength < 0 ? add32(baseDirection, 180) : baseDirection);
  const course = read('course');
  if ((course === 2 || course === 4) && depth < 70) {
    updateShoreDirections(memory, x, y);
    direction = read('shoreDirection');
    if (strength < 0) direction = wrapDegreesOnce(add32(direction, 180));
  }
  if (depth < 90 && island === 1) {
    const quadrant = imul32(idiv32(sub32(x, read('centerX')), 100), idiv32(sub32(y, read('centerY')), 100)) < 1 ? -1 : 1;
    const baseSign = baseDirection <= 180 ? 1 : -1;
    direction = add32(direction, imul32(imul32(quadrant, baseSign), -45));
  }
  if (read('spatialVariant') === 1 && idiv32(imul32(absolute32(read('shoreY')), 8), 10) < absolute32(y)) {
    if (y < 0 && read('shore') === 1) direction = add32(direction, 90);
    if (y > 0 && read('shore') === 3) direction = sub32(direction, 90);
  }
  direction = wrapDegreesOnce(direction);

  const placement = read('placementMode');
  const cycle = read('tideCycleFlag');
  if (weather === 4) {
    let branch = y;
    let attenuation = 1;
    if (placement === 1) {
      branch = read('centerDirection');
      if (y < -400) {
        if (x < 0) {
          attenuation = 2;
          branch = wrapDegreesOnce(sub32(read('branchDirection2'), 180));
        } else {
          branch = wrapDegreesOnce(sub32(read('branchDirection1'), 180));
        }
      }
    }
    if (placement === 2) {
      if (x <= -600) {
        if (y < 0) attenuation = 2;
        branch = wrapDegreesOnce(sub32(read(y < 0 ? 'branchDirection1' : 'branchDirection2'), 180));
      } else if (x < -150) {
        branch = wrapDegreesOnce(idiv32(add32(sub32(read(y < 0 ? 'branchDirection1' : 'branchDirection2'), 180), read('centerDirection')), 2));
      }
      // x == -150 intentionally retains the preceding branch value.
      if (x > -150) branch = read('centerDirection');
    }
    if (cycle === 0) strength = read('tideAmplitude');
    if (depth < 50) strength = idiv32(imul32(strength, depth), 100);
    if (attenuation === 2) strength = idiv32(imul32(strength, 3), 4);
    if (strength < 0 || cycle === 0) branch = add32(branch, 180);
    direction = wrapDegreesOnce(branch);
  }
  if (weather === 5) {
    direction = placement === 1 ? (x <= 0 ? 75 : 90) : (x <= 0 ? 105 : 90);
    if (strength < 0 || cycle === 0) direction = add32(direction, 180);
    direction = wrapDegreesOnce(direction);
  }
  if (weather === 6) {
    direction = y <= -1000 ? 180 : (x <= 0 ? 155 : 135);
    if (y >= -600) direction = 90;
    if (strength < 0 || cycle === 0) direction = add32(direction, 180);
    direction = wrapDegreesOnce(direction);
  }
  if (weather === 7) {
    direction = y <= 1000 ? (x <= 0 ? 285 : 270) : 10;
    if (y > 600 && y <= 1000) direction = x <= 0 ? 330 : 310;
    if (strength < 0 || cycle === 0) direction = add32(direction, 180);
    direction = wrapDegreesOnce(direction);
  }
  const distance = depth < 81 ? sampleUpstreamDistance(memory, 0, x, y) : 900;
  if (distance < 900) {
    strength = idiv32(imul32(strength, distance), 900);
    if (boat === 1) write('currentEffect', 2);
  }
  write('currentDirection', direction);
  memory.writeI32(indexed(a.currentStrength, boat), strength);
  return strength;
}

export const FUN_00420b70 = sampleShorelineMetric;
export const FUN_00420c40 = sampleSpatialMetric;
export const FUN_00420d10 = sampleBoundaryMetric;
export const FUN_00421560 = sampleCurrent;
export const FUN_00421ae0 = updateShoreDirections;
export const FUN_00421b80 = sampleUpstreamDistance;
