import { add32, imul32, sub32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';

export const TRAIL_ADDRESSES = Object.freeze({
  recordTrails: 0x004313a0,
  boatCount: 0x0049118c,
  humanBoatCount: 0x00491140,
  trailCount: 0x004ab9d8,
  positionX: 0x004a49e8,
  positionY: 0x004a4ae0,
  trailX: 0x004a9a0c,
  trailY: 0x004ab1a4,
  trailBoatStride: 0x25c,
});

/** Complete native trail-history insertion and backwards shift at 0x4313a0. */
export function recordTrails(memory) {
  const a = TRAIL_ADDRESSES;
  const boats = memory.readI32(a.boatCount) === 2 ? 2 : memory.readI32(a.humanBoatCount);
  const count = memory.readI32(a.trailCount);
  if (boats < 1) return boats;
  for (let boat = 1; boat <= boats; boat++) {
    const baseX = add32(a.trailX, imul32(boat, a.trailBoatStride)) >>> 0;
    const baseY = add32(a.trailY, imul32(boat, a.trailBoatStride)) >>> 0;
    memory.writeI32(baseX, Float80.fromNumber(memory.readF64(a.positionX + boat * 8)).truncI32());
    memory.writeI32(baseY, Float80.fromNumber(memory.readF64(a.positionY + boat * 8)).truncI32());
    // The original stores index zero before shifting count-1 entries. This
    // retains its first-sample duplication rather than rewriting the ordering.
    for (let index = sub32(count, 1); index >= 1; index = sub32(index, 1)) {
      const offset = imul32(index, 4);
      memory.writeI32(add32(baseX, offset) >>> 0, memory.readI32(add32(baseX, sub32(offset, 4)) >>> 0));
      memory.writeI32(add32(baseY, offset) >>> 0, memory.readI32(add32(baseY, sub32(offset, 4)) >>> 0));
    }
  }
  return 0;
}

export const FUN_004313a0 = recordTrails;
