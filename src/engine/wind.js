import { add32, i32, idiv32, imul32, sub32 } from '../runtime/index.js';
import { Float80,getX87ControlWord } from '../runtime/float80.js';
import { wrapDegreesOnce, scaledRandom } from './integer-core.js';
import { bearingFromVector } from './angles.js';
import { scheduleWindShift } from './helpers.js';
import { nativeTrig } from './native-trig.js';

export const WIND_ADDRESSES = Object.freeze({
  routine: 0x0041b5d0,
  hour: 0x004a4be4,
  dailyMinimum: 0x004a609c,
  dailyMaximum: 0x004a7758,
  thermalGain: 0x004a79ec,
  weather: 0x004a4958,
  shore: 0x004aa804,
  reversal: 0x004a4378,
  baseDirection: 0x004a4430,
  baseStrength: 0x004a70dc,
  driftRate: 0x004abc7c,
  forceCondition: 0x004a5b9c,
  mode: 0x004ac9ac,
  time: 0x004a5b80,
  resetTime: 0x004a4168,
  tidePhaseHour: 0x004a8020,
  tideAmplitude: 0x004ac1dc,
  target: 0x004ac9e8,
  nextTime: 0x004abae4,
  range: 0x004aa590,
  period: 0x004aa978,
  targetIndex: 0x004911c4,
  timeIndex: 0x004911c8,
  randomTable: 0x004a9450,
  cosine: 0x004a3450,
  sine: 0x004a54a0,
  driftClock: 0x004ab8b8,
  smoothDirection: 0x004aa6f0,
  dt: 0x004aa948,
  thermal: 0x004ac568,
  strength: 0x004aa390,
  peakStrength: 0x004a70f0,
  condition1: 0x004a71a4,
  condition2: 0x004a888c,
  meanDirection: 0x004a4f8c,
  direction: 0x004ac840,
  tide: 0x004aa298,
});

/**
 * Original FSIN m80 values captured on local x87 hardware with control word 0x037f.
 * Inputs are FILD angle; FMUL original binary64 constant at 0x00484d40; FSIN.
 * These finite hardware results do not establish parity with every historical CPU.
 */
export const WIND_SINE_BITS = Object.freeze({
  "0": "00000000000000000000",
  "15": "fc3f06157e618484fd3f",
  "30": "d63de6e380670080fe3f",
  "45": "180ac1ccf77105b5fe3f",
  "60": "46e00d6bc64eb4ddfe3f",
  "75": "a20c2bb58e3747f7fe3f",
  "90": "a3eae904fffffffffe3f",
  "105": "9db4fd0df57d46f7fe3f",
  "120": "77c2382d39e8b2ddfe3f",
  "135": "8104956ce67603b5fe3f",
  "150": "c8d410d4f3f4fbfffd3f",
  "165": "049aa65e2af87e84fd3f",
  "180": "1eb799faf20d46b3f0bf",
  "195": "c5159cbbcdca8984fdbf",
  "210": "b38f68f183d40280febf",
  "225": "286d8da0036d07b5febf",
  "240": "39b44bdd4cb5b5ddfebf",
  "255": "d52217c820f147f7febf",
  "270": "c43f392cf7fffffffebf",
  "285": "15cb94d253c445f7febf",
  "300": "2758d723a581b1ddfebf",
  "315": "11e71880cf7b01b5febf",
  "330": "6f3cc407de1af7fffdbf",
  "345": "c299a798d28e7984fdbf",
  "360": "7e1c453bf00d46b3f13f",
  "375": "9ba53d5219348f84fd3f",
  "390": "3e577c1283410580fe3f",
  "405": "30a3eae7096809b5fe3f",
  "420": "2c41e783cc1bb7ddfe3f",
  "435": "2647bc46abaa48f7fe3f",
  "450": "45ead77ae7fffffffe3f",
  "465": "9100f602ab0a45f7fe3f",
  "480": "e89ef44e0a1bb0ddfe3f",
  "495": "a43c5c07b380ffb4fe3f",
  "510": "96c40c63c040f2fffd3f",
  "525": "3ab533c376257484fd3f",
  "540": "20144abd708a7486f2bf",
  "555": "d779c0d8609d9484fdbf",
  "570": "d98b0e477eae0780febf",
  "585": "d721c9a20a630bb5febf",
  "600": "2b8ad55e4582b8ddfebf",
  "615": "bdc914312e6449f7febf",
  "630": "a0eac5f0cffffffffebf",
  "645": "d605279ffa5044f7febf",
  "660": "7f949bae68b4aeddfebf",
  "675": "3d906e029185fdb4febf",
  "690": "6e7f10e69a66edfffdbf",
  "705": "906275de16bc6e84fdbf",
  "720": "3cb2f23de50d46b3f23f",
  "-720": "3cb2f23de50d46b3f2bf",
  "-705": "906275de16bc6e84fd3f",
  "-690": "6e7f10e69a66edfffd3f",
  "-675": "3d906e029185fdb4fe3f",
  "-660": "7f949bae68b4aeddfe3f",
  "-645": "d605279ffa5044f7fe3f",
  "-630": "a0eac5f0cffffffffe3f",
  "-615": "bdc914312e6449f7fe3f",
  "-600": "2b8ad55e4582b8ddfe3f",
  "-585": "d721c9a20a630bb5fe3f",
  "-570": "d98b0e477eae0780fe3f",
  "-555": "d779c0d8609d9484fd3f",
  "-540": "20144abd708a7486f23f",
  "-525": "3ab533c376257484fdbf",
  "-510": "96c40c63c040f2fffdbf",
  "-495": "a43c5c07b380ffb4febf",
  "-480": "e89ef44e0a1bb0ddfebf",
  "-465": "9100f602ab0a45f7febf",
  "-450": "45ead77ae7fffffffebf",
  "-435": "2647bc46abaa48f7febf",
  "-420": "2c41e783cc1bb7ddfebf",
  "-405": "30a3eae7096809b5febf",
  "-390": "3e577c1283410580febf",
  "-375": "9ba53d5219348f84fdbf",
  "-360": "7e1c453bf00d46b3f1bf",
  "-345": "c299a798d28e7984fd3f",
  "-330": "6f3cc407de1af7fffd3f",
  "-315": "11e71880cf7b01b5fe3f",
  "-300": "2758d723a581b1ddfe3f",
  "-285": "15cb94d253c445f7fe3f",
  "-270": "c43f392cf7fffffffe3f",
  "-255": "d52217c820f147f7fe3f",
  "-240": "39b44bdd4cb5b5ddfe3f",
  "-225": "286d8da0036d07b5fe3f",
  "-210": "b38f68f183d40280fe3f",
  "-195": "c5159cbbcdca8984fd3f",
  "-180": "1eb799faf20d46b3f03f",
  "-165": "049aa65e2af87e84fdbf",
  "-150": "c8d410d4f3f4fbfffdbf",
  "-135": "8104956ce67603b5febf",
  "-120": "77c2382d39e8b2ddfebf",
  "-105": "9db4fd0df57d46f7febf",
  "-90": "a3eae904fffffffffebf",
  "-75": "a20c2bb58e3747f7febf",
  "-60": "46e00d6bc64eb4ddfebf",
  "-45": "180ac1ccf77105b5febf",
  "-30": "d63de6e380670080febf",
  "-15": "fc3f06157e618484fdbf"
});

const windSines = new Map(Object.entries(WIND_SINE_BITS).map(([angle, bits]) => [
  Number(angle), Float80.fromBytes(Uint8Array.from(bits.match(/../g), byte => parseInt(byte, 16))),
]));
const ninety = Float80.fromInteger(90);
const negativeNinety = Float80.fromInteger(-90);
const revolution = Float80.fromInteger(360);
const negativeRevolution = Float80.fromInteger(-360);
const smoothingRate = Float80.fromNumber(-0.05);

function capturedWindSine(angle,options) {
  if((getX87ControlWord()&0x300)!==0x300||options.trig)return nativeTrig(angle,options).sine;
  const value = windSines.get(angle);
  if (!value) throw new RangeError(`Original wind FSIN angle ${angle} is outside the captured -720..720 domain`);
  return value;
}

function indexed(base, index) {
  return (base + Math.imul(i32(index), 4)) >>> 0;
}

/**
 * Full control flow of original global environmental wind update.
 * Requires original integer trig/random tables and the same per-thread RNG state.
 * Arithmetic retains precision64 x87 intermediates until the original spills.
 * Wind/tide FSIN is limited to captured multiples of 15 in [-720, 720]; unsupported
 * angles and invalid/nonfinite x87 arithmetic throw instead of approximating.
 */
export function updateGlobalWind(memory, rng, options={}) {
  const a = WIND_ADDRESSES;
  const read = key => memory.readI32(a[key]);
  const write = (key, value) => memory.writeI32(a[key], value);
  const hour = read('hour');
  const minimum = read('dailyMinimum');
  const maximum = read('dailyMaximum');
  const thermalSine = capturedWindSine(imul32(sub32(hour, 8), 15),options);
  const tideSine = capturedWindSine(imul32(sub32(hour, read('tidePhaseHour')), 30),options);
  let thermal = add32(thermalSine.multiply(Float80.fromInteger(sub32(maximum, minimum))).truncI32(), minimum);
  if (thermal < minimum) thermal = minimum;
  write('thermal', thermal);
  let thermalWind = idiv32(imul32(thermal, read('thermalGain')), maximum);
  const weather = read('weather');
  if (thermalWind < 0 || (weather > 0 && weather < 5)) thermalWind = 0;
  if (hour > 22 || hour < 9) thermalWind = 0;

  const shore = read('shore');
  const reversal = read('reversal');
  let thermalDirection = imul32(add32(shore, 1), 90);
  if (reversal === 1) thermalDirection = add32(thermalDirection, 90);
  thermalDirection = wrapDegreesOnce(thermalDirection);
  const baseDirection = wrapDegreesOnce(read('baseDirection'));
  const baseStrength = read('baseStrength');
  const component = (table, angle, value) => idiv32(imul32(memory.readI32(indexed(a[table], angle)), value), 100);
  const x = add32(component('cosine', baseDirection, baseStrength), component('cosine', thermalDirection, thermalWind));
  const y = add32(component('sine', baseDirection, baseStrength), component('sine', thermalDirection, thermalWind));
  const squared = add32(imul32(x, x), imul32(y, y));
  let strength = squared === 0 ? baseStrength : Float80.fromInteger(squared).sqrt().truncI32();
  if (strength > 22) strength = 22;
  if (strength < 8) strength = 8;
  write('peakStrength', strength);
  if ((strength > 9 && hour > 16) || hour < 11) strength = sub32(strength, 2);
  write('strength', strength);

  const driftTime = Float80.fromNumber(memory.readF64(a.driftClock)).truncI32();
  const drift = idiv32(imul32(driftTime, read('driftRate')), 60);
  const bearing = wrapDegreesOnce(add32(drift, bearingFromVector(y, x)));
  const relative = add32(sub32(bearing, imul32(shore, 90)), 90);
  const absolute = relative < 0 ? sub32(0, relative) : relative;
  const condition = absolute < 90 || weather > 0 || read('forceCondition') === 1 || reversal === 1;
  write('condition1', condition ? 1 : 0);
  write('condition2', condition ? 1 : 0);

  const mode = read('mode');
  const time = read('time');
  if (mode === 0 || mode === 1) {
    const reset = mode === 0 ? time < add32(read('resetTime'), 10) : time < 10;
    if (reset) {
      memory.writeF64(a.smoothDirection, bearing);
      write('meanDirection', bearing);
      write('direction', bearing);
      if (mode === 0) write('target', bearing);
    } else {
      write('range', add32(scaledRandom(condition ? 30 : 20, rng), condition ? 30 : 20));
      const periodBase = mode === 0 ? (condition ? 15 : 30) : (condition ? 20 : 40);
      write('period', add32(scaledRandom(condition ? 10 : 20, rng), periodBase));
      if (read('nextTime') < time) scheduleWindShift(memory, bearing, read('range'), read('period'));
      const current = Float80.fromNumber(memory.readF64(a.smoothDirection));
      let difference = Float80.fromInteger(read('target')).subtract(current);
      // The original uses two sequential 90-degree tests; the second branch can
      // undo the first correction. A shortest-turn/modulo formula changes it.
      if (difference.compare(ninety) > 0) difference = difference.subtract(revolution);
      if (difference.compare(negativeNinety) < 0) difference = difference.subtract(negativeRevolution);
      const delta = difference.multiply(Float80.fromNumber(memory.readF64(a.dt))).multiply(smoothingRate);
      const result = current.subtract(delta);
      memory.writeF64(a.smoothDirection, result.toNumber());
      // Original FST stores binary64 without popping; __ftol consumes the
      // unrounded extended value below this boundary in the native routine.
      write('direction', wrapDegreesOnce(result.truncI32()));
    }
  }

  const tide = tideSine.multiply(Float80.fromInteger(read('tideAmplitude'))).truncI32();
  write('tide', tide);
  return tide;
}

export const FUN_0041b5d0 = updateGlobalWind;
