import { add32, i32, idiv32, sub32, u32, umul32 } from '../runtime/index.js';

/** Addresses identify the original instructions behind each translation. */
export const ORIGINAL_ADDRESSES = Object.freeze({
  wrapDegreesOnce: 0x00413cb0,
  updateSpeedDivisor: 0x0044e380,
  srand: 0x00456ed0,
  rand: 0x00456ee0,
  scaledRandom: 0x00415a20,
  initializeThreadData: 0x00459eb0,
  speedLevel: 0x0049116c,
  speedDivisor: 0x00491170,
  threadSeedOffset: 0x14,
});

/**
 * FUN_00413cb0: adjust by one revolution at most. Inputs outside [-360, 719]
 * need not finish in [0, 359]; replacing this with modulo changes behavior.
 */
export function wrapDegreesOnce(input) {
  let angle = i32(input);
  if (angle >= 360) angle = sub32(angle, 360);
  if (angle < 0) angle = add32(angle, 360);
  return angle;
}

// Immediate values written by FUN_0044e380; index is the original speed level.
const SPEED_DIVISORS = Object.freeze([0, 2919, 1946, 1297, 865, 577, 384, 256, 171, 114, 76, 51, 34, 23, 15, 10]);

/** Pure value equivalent of the speed-global update; invalid levels retain it. */
export function speedDivisor(level, previous) {
  level = i32(level);
  return level >= 1 && level <= 15 ? SPEED_DIVISORS[level] : i32(previous);
}

/** FUN_0044e380: invalid levels do not write DAT_00491170. */
export function updateSpeedDivisor(memory) {
  const level = memory.readI32(ORIGINAL_ADDRESSES.speedLevel);
  if (level >= 1 && level <= 15) {
    memory.writeI32(ORIGINAL_ADDRESSES.speedDivisor, SPEED_DIVISORS[level]);
  }
  // EAX retains the original level at the RET instruction.
  return level;
}

/**
 * Abstract one original CRT thread's seed field at threadData + 0x14.
 * Separate instances represent separate original TLS states. Default 1 is
 * written by the original thread-data initializer at 0x00459ebb.
 */
export class PoseyRng {
  #state;

  constructor(seed = 1) { this.srand(seed); }
  get state() { return this.#state; }
  set state(seed) { this.#state = u32(seed); }

  /** Original srand at 0x00456ed0 stores the low 32 seed bits. */
  srand(seed) { this.#state = u32(seed); }

  /** Original rand at 0x00456ee0: overflow is modulo 2^32 at every step. */
  rand() {
    this.#state = u32(umul32(this.#state, 214013) + 2531011);
    return (this.#state >>> 16) & 0x7fff;
  }
}

/**
 * FUN_00415a20's scaled random helper, including its unusual negative inputs.
 * The absolute value is used ONLY in the <2 check. Larger negative inputs keep
 * their sign for 32000 / range; the resulting negative divisor clamps to one.
 * INT_MIN's overflowing absolute value is negative, so it selects range two.
 * Every call consumes exactly one original rand() result.
 */
export function scaledRandom(input, rng) {
  let range = i32(input);
  const absolute = range < 0 ? i32(-range) : range;
  if (absolute < 2) range = 2;
  let divisor = idiv32(32000, range);
  if (divisor < 1) divisor = 1;
  return idiv32(rng.rand(), divisor);
}

export const FUN_00413cb0 = wrapDegreesOnce;
export const FUN_0044e380 = updateSpeedDivisor;
export const FUN_00415a20 = scaledRandom;
