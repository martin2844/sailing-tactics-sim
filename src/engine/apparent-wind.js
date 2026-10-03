import { add32, sub32, i32, idiv32, imul32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { atanExtended } from '../runtime/atan.js';

/** Original FUN_00429df0 and the parallel arrays it reads and writes. */
export const APPARENT_WIND_ADDRESSES = Object.freeze({
  routine: 0x00429df0,
  angleToTrueWind: 0x004a7bc8,
  trueWindKnots: 0x004a6338,
  cosine: 0x004a3450,
  sine: 0x004a54a0,
  apparentWindKnots: 0x004ab9e8,
  apparentWindAngle: 0x004a47f8,
});

// Original x86 addressing wraps the scaled integer index to 32 bits.
function indexed(base, index) {
  return (base + Math.imul(i32(index), 4)) >>> 0;
}

/**
 * Translate the original apparent-wind vector routine against image memory.
 * speedTenths is the integer speed argument; boat selects original global arrays.
 * Tables must contain the original 362 integer sine/cosine values.
 *
 * Integer operations preserve x86 wrapping and truncation. Pressure, square
 * root, division and degree conversion preserve the original extended
 * intermediates. Mathematical atan uses 224-bit intermediates; the final
 * vendor-specific FPATAN approximation is not modeled bit for bit.
 *
 * Returns pressure (the original x87 ST0 result), and writes the two original
 * apparent-wind globals. This routine has no random-number side effects.
 */
export function apparentWindExtended(memory, speedTenths, boat) {
  const a = APPARENT_WIND_ADDRESSES;
  const angle = memory.readI32(indexed(a.angleToTrueWind, boat));
  const wind = memory.readI32(indexed(a.trueWindKnots, boat));
  const cosine = memory.readI32(indexed(a.cosine, angle));
  const sine = memory.readI32(indexed(a.sine, angle));

  const x = add32(idiv32(imul32(cosine, wind), 10), speedTenths);
  const y = idiv32(imul32(sine, wind), 10);
  const xExtended = Float80.fromInteger(x);
  const yExtended = Float80.fromInteger(y);
  const pressure = xExtended.multiply(xExtended).add(yExtended.multiply(yExtended))
    .multiply(Float80.fromNumber(memory.readF64(0x4851e0)));
  memory.writeI32(indexed(a.apparentWindKnots, boat),
    pressure.multiply(Float80.fromNumber(memory.readF64(0x4851e8))).sqrt().truncI32());

  let apparentAngle;
  if (x === 0) {
    // The original returns here before its final true-wind-angle clamp.
    memory.writeI32(indexed(a.apparentWindAngle, boat), 90);
    return pressure;
  }
  if (y === 0 && angle < 5) {
    memory.writeI32(indexed(a.apparentWindAngle, boat), 0);
    return pressure;
  }
  if (y === 0 && angle >= 0) {
    apparentAngle = 179;
  } else if (x > 0) {
    apparentAngle = atanExtended(yExtended.divide(xExtended))
      .multiply(Float80.fromNumber(memory.readF64(0x484d78))).truncI32();
  } else {
    apparentAngle = sub32(90, atanExtended(xExtended.divide(yExtended).negate())
      .multiply(Float80.fromNumber(memory.readF64(0x4850b8))).truncI32());
  }
  if (angle > 179) apparentAngle = 179;
  memory.writeI32(indexed(a.apparentWindAngle, boat), apparentAngle);
  return pressure;
}

/** Public binary64 store boundary used by original dynamics at 0x428d63. */
export function apparentWind(memory, speedTenths, boat) {
  return apparentWindExtended(memory, speedTenths, boat).toNumber();
}

export const FUN_00429df0 = apparentWind;
