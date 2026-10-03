import { add32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { sinCosX87 } from '../runtime/transcendentals.js';

export const BOAT_SWAY_ROUTINE = 0x4304d0;

/** Complete 0x4304d0. The sine approximation is checked at the original I32 store. */
export function updateBoatSway(memory, options = {}) {
  let counter = add32(memory.readI32(0x4ac96c), 1);
  const divisor = memory.readI32(0x491170);
  if (counter > idiv32(divisor, 3)) counter = 0;
  memory.writeI32(0x4ac96c, counter);
  const angle = memory.readI32(0x4a7bcc), crew = memory.readI32(0x4ac4ec);
  let amplitude;
  if (angle < 90) amplitude = add32(crew, 2);
  if (angle < 60) amplitude = add32(imul32(crew, 2), 2);
  if (angle >= 90) amplitude = memory.readI32(0x4a633c) > 12 ? 2 : 1;
  const phase = Float80.fromInteger(counter).multiply(Float80.fromNumber(memory.readF64(0x4852c8))).divide(Float80.fromInteger(divisor));
  const sine = (options.sinCos ?? sinCosX87)(phase).sine;
  memory.writeI32(0x4a5b7c, Float80.fromInteger(amplitude).multiply(sine).truncI32());
}
