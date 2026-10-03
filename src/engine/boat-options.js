import { Float80,getX87ControlWord } from '../runtime/float80.js';

/** Global addresses used by original FUN_00417790. */
export const BOAT_OPTION_ADDRESSES = Object.freeze({
  routine: 0x00417790,
  selector: 0x00491144,
  boatClass: 0x00491188,
  lengthOverride: 0x004ac918,
  displacementOverride: 0x004ac91c,
  sailAreaOverride: 0x004ac920,
  sailPercentOverride: 0x004ac924,
  length: 0x004a5ba4,
  displacement: 0x004a4eec,
  sailArea: 0x004a5b90,
  sailPercent: 0x00491150,
  rig: 0x0049114c,
  course: 0x00491194,
  offshoreCourseFlag: 0x004ac990,
  catamaranFlag: 0x004ac900,
  boardFlag: 0x004ac904,
  sportBoatFlag: 0x004ac908,
  skiffFlag: 0x004ac90c,
  jy15Flag: 0x004ac910,
  optimistFlag: 0x004ac914,
  timeFactor: 0x004ab0c0,
});

/** Original menu selection values, linked through MFC command-map entries. */
export const BOAT_SELECTORS = Object.freeze({
  1: 'Optimist', 2: 'Laser', 3: 'Board', 4: 'Snipe', 5: 'JY15',
  6: '505', 7: 'Skiff', 8: 'Thistle', 9: 'Lightning',
  10: 'Tornado Catamaran', 11: 'Spinnaker Catamaran', 12: 'Keelboat',
  13: 'Sport Boat', 14: 'Offshore Racer', 15: "America's Cup",
});

/**
 * Original x87-generated binary64 factors, from assets/data/boat-calibration.json.
 * All possible ordinary preset/custom lengths are covered. The original divides
 * in extended precision before FSQRT; binary64 division+Math.sqrt differs by one
 * ULP for lengths 29 and 35. Keeping all captured values also avoids depending on
 * browser libm for the verified domain.
 */
export const BOAT_TIME_FACTORS = Object.freeze({
  11: 1.1677484162422844,
  14: 1.0350983390135313,
  15: 1,
  16: 0.9682458365518543,
  17: 0.9393364366277243,
  18: 0.9128709291752769,
  20: 0.8660254037844386,
  21: 0.8451542547285166,
  22: 0.8257228238447705,
  23: 0.8075728530872482,
  24: 0.7905694150420949,
  25: 0.7745966692414834,
  26: 0.7595545253127499,
  27: 0.7453559924999299,
  28: 0.7319250547113999,
  29: 0.7191949522280762,
  30: 0.7071067811865476,
  31: 0.6956083436402524,
  32: 0.6846531968814576,
  33: 0.674199862463242,
  34: 0.6642111641550714,
  35: 0.6546536707079772,
  36: 0.6454972243679028,
  37: 0.6367145399670133,
  38: 0.6282808624375432,
  39: 0.6201736729460423,
  40: 0.6123724356957945,
  41: 0.6048583789091339,
  42: 0.5976143046671968,
  43: 0.5906244232186183,
  44: 0.5838742081211422,
  45: 0.5773502691896257,
  46: 0.5710402407201608,
  47: 0.564932682866032,
  48: 0.5590169943749475,
  49: 0.5532833351724882,
  50: 0.5477225575051661,
  61: 0.4958847036804647,
});

/**
 * Reconstruct original boat option initialization against image memory.
 * Invalid selectors preserve the previous class but clear all six type flags.
 * Class 7 retains its prior rig, course, and offshore-course flag. Overrides are
 * checked before fixed class presets; several presets intentionally replace them.
 * Valid length factors use captured original binary64 values. Other finite
 * positive lengths use precision64 Float80 division and square root before the
 * binary64 store. Nonpositive retained lengths need unsupported native
 * nonfinite/exception semantics and throw explicitly.
 * Returns residual native EAX; native callers use this routine for memory writes.
 */
export function initializeBoatOptions(memory) {
  const a = BOAT_OPTION_ADDRESSES;
  const selector = memory.readI32(a.selector);
  const read = key => memory.readI32(a[key]);
  const write = (key, value) => memory.writeI32(a[key], value);
  for (const flag of ['jy15Flag', 'catamaranFlag', 'boardFlag', 'sportBoatFlag', 'skiffFlag', 'optimistFlag']) write(flag, 0);

  switch (selector) {
    case 1: write('boatClass', 1); write('optimistFlag', 1); break;
    case 2: write('boatClass', 1); break;
    case 3: write('boatClass', 1); write('boardFlag', 1); break;
    case 4: write('boatClass', 2); break;
    case 5: write('boatClass', 2); write('jy15Flag', 1); break;
    case 6: write('boatClass', 3); break;
    case 7: write('boatClass', 3); write('skiffFlag', 1); break;
    case 8: write('boatClass', 4); break;
    case 9: write('boatClass', 5); break;
    case 10: write('catamaranFlag', 1); write('boatClass', 9); break;
    case 11: write('catamaranFlag', 1); write('boatClass', 10); break;
    case 12: write('boatClass', 6); break;
    case 13: write('sportBoatFlag', 1); write('boatClass', 7); break;
    case 14: write('boatClass', 7); break;
    case 15: write('boatClass', 8); break;
  }

  const boatClass = read('boatClass');
  const displacement = read('displacementOverride');
  write('displacement', displacement >= 8 && displacement <= 11 ? displacement : 10);
  const area = read('sailAreaOverride');
  write('sailArea', area >= 8 && area <= 11 ? area : 10);
  write('sailPercent', boatClass === 7 && read('sportBoatFlag') === 0 ? 100 : 80);
  const sailPercent = read('sailPercentOverride');
  if (sailPercent > 0) write('sailPercent', sailPercent);
  if (boatClass < 6) {
    write('sailPercent', 80);
    write('displacement', 10);
    write('sailArea', 10);
  }
  if (boatClass === 1) {
    write('displacement', 6);
    write('length', selector === 3 ? 40 : 14);
    if (selector === 3) write('sailArea', 10);
  }
  if (boatClass === 1 && selector === 1) {
    write('length', 11);
    write('displacement', 10);
    write('sailArea', 10);
  }
  if (boatClass === 2) {
    write('length', selector === 5 ? 14 : 15);
    write('displacement', selector === 5 ? 6 : 7);
  }
  if (boatClass === 3) {
    write('displacement', 5);
    write('length', selector === 7 ? 30 : 18);
    write('sailArea', selector === 7 ? 11 : 10);
  }
  if (boatClass === 4) { write('displacement', 6); write('length', 16); }
  if (boatClass === 5) { write('displacement', 7); write('length', 17); }
  const length = read('lengthOverride');
  if (boatClass === 6) write('length', length >= 20 && length <= 50 ? length : 25);
  if (boatClass === 7 && read('sportBoatFlag') === 0) write('length', length >= 20 && length <= 50 ? length : 40);
  if (read('sportBoatFlag') === 1) {
    write('length', 25);
    write('displacement', 7);
    write('sailArea', 11);
  }
  if (boatClass < 7 || boatClass > 8) write('rig', -1);
  if (boatClass === 8) {
    write('displacement', 10);
    write('length', 61);
    write('sailArea', 12);
    write('sailPercent', 80);
    write('rig', 1);
  }
  if (boatClass === 9 || boatClass === 10) {
    write('displacement', 6);
    write('length', 37);
    write('sailArea', 10);
    write('sailPercent', 80);
  }
  const resultingLength = read('length');
  memory.writeF64(a.timeFactor, (getX87ControlWord()&0x300)===0x300&&Object.hasOwn(BOAT_TIME_FACTORS, resultingLength)
    ? BOAT_TIME_FACTORS[resultingLength]
    : Float80.fromInteger(15).divide(Float80.fromInteger(resultingLength)).sqrt().toNumber());
  let returnValue = boatClass;
  if (boatClass !== 7) {
    returnValue = read('course');
    write('offshoreCourseFlag', 0);
    if (returnValue === 8) write('course', 1);
  }
  return returnValue;
}

export const FUN_00417790 = initializeBoatOptions;
