import { u32 } from '../../../../src/runtime/c-types.js';

/**
 * Declared unit-tick Windows host, shared by every original child in a paint.
 * The original tick loops finish synchronously; the browser scheduler supplies
 * their physical delay using minimumDuration(), minus time already rendering.
 */
export function createPaintClock(start = 0) {
  if (!Number.isSafeInteger(start)) throw new TypeError('Paint clock start must be an integer');
  let tick = u32(start);
  let reads = 0;
  return Object.freeze({
    beginPaint() { reads = 0; },
    getTickCount() {
      if (reads >= 100_000) throw new RangeError('Original paint timer exceeded its native host bound');
      reads++;
      const result = tick;
      tick = u32(result + 1);
      return result;
    },
    minimumDuration() { return Math.max(0, reads - 1); },
  });
}
