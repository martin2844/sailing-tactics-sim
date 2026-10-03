import { add32, imul32, idiv32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { sinCosX87 } from '../../../../src/runtime/transcendentals.js';
import { nearestWaypointDistance } from './waypoints.js';

export const WAVE_MOTION_ROUTINES = Object.freeze({ updateWaveMotion: 0x4432b0 });

/** Complete original wave/heave update. The inferred fastcall argument is dead. */
export function updateWaveMotion(memory, options = {}) {
  const r = address => memory.readI32(address);
  const w = (address, value) => memory.writeI32(address, value);
  const f = address => Float80.fromNumber(memory.readF64(address));
  const sound = (resourceId, flags) => options.playSound?.({ resourceId, moduleHandle: memory.readU32(0x5359c8), flags });
  const audible = () => r(0x536484) === 0 && r(0x4f7124) === 0 && r(0x4f7128) === 0;
  w(0x536430, add32(r(0x536430), 1));
  w(0x4f4b38, 0); w(0x4f4b3c, 0);
  const nearWave = (boat, previous, distance, countdown, flag) => {
    memory.writeBytes(previous, memory.readBytes(distance, 8));
    const nearest = nearestWaypointDistance(memory, memory.readF64(0x4f6af8 + boat * 8), memory.readF64(0x4f6c10 + boat * 8), -1);
    memory.writeF64(distance, nearest.toNumber());
    const remaining = f(countdown).subtract(f(0x4cc650));
    memory.writeF64(countdown, remaining.toNumber());
    // FST retains the unrounded register for this comparison; later tests reload.
    if (remaining.compare(f(0x4cc658)) < 0) memory.writeF64(countdown, 0);
    if (f(distance).compare(f(0x4cc710)) < 0 && f(distance).compare(f(previous)) < 0
        && f(countdown).compare(f(0x4cc658)) === 0 && r(0x535e40 + boat * 4) > 1) {
      if (boat === 1) w(0x536430, idiv32(r(0x4da178), 5));
      memory.writeF64(countdown, 20);
      if (audible()) sound(0x99, 0x40045);
      w(flag, 1);
    }
  };
  if (r(0x4feccc) < 80 && r(0x535e44) > 1) nearWave(1, 0x536550, 0x536558, 0x536560, 0x4f4b38);
  if (r(0x4fecd0) < 80 && r(0x535e48) > 1 && r(0x4da140) === 2) nearWave(2, 0x536568, 0x536570, 0x536578, 0x4f4b3c);
  if (r(0x536430) === 1 && r(0x4feccc) <= 90 && audible()) sound(0x97, 0x40015);
  if (r(0x536430) > idiv32(r(0x4da178), 3)) w(0x536430, 0);
  const angle = r(0x4feccc);
  let amplitude;
  if (angle < 90) amplitude = add32(r(0x535e44), 2);
  if (angle < 60) amplitude = add32(imul32(r(0x535e44), 2), 2);
  if (angle >= 90) amplitude = r(0x4fb384) > 12 ? 2 : 1;
  const phase = Float80.fromInteger(r(0x536430)).multiply(f(0x4ccbb0)).divide(Float80.fromInteger(r(0x4da178)));
  const sine = (options.sinCos ?? sinCosX87)(phase).sine;
  w(0x4f8ccc, Float80.fromInteger(amplitude).multiply(sine).truncI32());
}
