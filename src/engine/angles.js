import { i32, truncFloatToI32 } from '../runtime/index.js';
import { wrapDegreesOnce } from './integer-core.js';

export const ANGLE_ADDRESSES = Object.freeze({
  wrapRadiansOnce: 0x00413cd0,
  bearingFromVector: 0x0041bb10,
});

/**
 * Original single-step radian correction. These stored decimal constants are
 * intentional; replacing them with Math.PI or using modulo changes boundaries.
 * Uses binary64 arithmetic at the JS return boundary; x87 flags are not modeled.
 */
export function wrapRadiansOnce(input) {
  if (typeof input !== 'number') throw new TypeError('Radian input must be a Number');
  let angle = input;
  if (angle > 3.1416) angle -= 6.2832;
  if (angle < -3.1416) angle -= -6.2832;
  return angle;
}

/**
 * Original signed integer vector bearing and its asymmetric +0.5/trunc rounding.
 * Math.atan2 uses browser binary64 libm; fixture parity does not prove complete
 * x87 FPATAN equivalence for every possible signed-32-bit input pair.
 */
export function bearingFromVector(param1, param2) {
  const angle = 0.5 - Math.atan2(i32(param1), i32(param2)) * -57.295;
  return wrapDegreesOnce(truncFloatToI32(angle));
}

export const FUN_00413cd0 = wrapRadiansOnce;
export const FUN_0041bb10 = bearingFromVector;
