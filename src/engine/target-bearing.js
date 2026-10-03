import { i32, add32, imul32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { atan2Extended } from '../runtime/atan.js';

export const TARGET_BEARING_ADDRESSES = Object.freeze({
  routine: 0x42c400, positionX: 0x4a49e8, positionY: 0x4a4ae0,
  startAX: 0x4aa594, startAY: 0x4aa59c, distance: 0x4a6828,
  bearingDegrees: 0x4a4758, priorBearing: 0x4a6830, mode: 0x4ab160,
  heading: 0x4ac018, windDirection: 0x4aa5b0,
});
const a = TARGET_BEARING_ADDRESSES;
const at = (address, boat, stride = 4) => add32(address, imul32(boat, stride)) >>> 0;
const floating = (memory, address) => Float80.fromNumber(memory.readF64(address));

/** Original target distance/bearing and relative-angle selectors, 0x42c400. */
export function targetRelativeBearing(memory, targetX, targetY, selector, boat) {
  selector = i32(selector); boat = i32(boat);
  const target = Float80.fromNumber(targetX);
  let x = target;
  let y = target;
  if (selector < 2) {
    x = floating(memory, at(a.positionX, boat, 8));
    y = floating(memory, at(a.positionY, boat, 8));
  } else {
    x = Float80.fromInteger(memory.readI32(a.startAX));
    y = Float80.fromInteger(memory.readI32(a.startAY));
  }
  const dy = y.subtract(Float80.fromNumber(targetY));
  const dxExtended = target.subtract(x);
  const dx = Float80.fromNumber(dxExtended.toNumber());
  memory.writeF64(a.distance, dy.multiply(dy).add(dxExtended.multiply(dx)).sqrt().toNumber());
  const zero = floating(memory, 0x484e18);
  const angle = dx.compare(zero) === 0
    ? (dy.compare(zero) <= 0 ? floating(memory, 0x484ed8) : zero)
    : atan2Extended(dx, dy);
  memory.writeI32(a.bearingDegrees, angle.multiply(floating(memory, 0x484d78)).truncI32());
  let result = dx;
  const relative = address => Float80.fromNumber(angle.subtract(Float80.fromInteger(memory.readI32(at(address, boat)))
    .multiply(floating(memory, 0x484d40))).toNumber());
  if (selector === -1) result = relative(a.priorBearing);
  if (selector === 1 || selector === 2) {
    const mode = memory.readI32(at(a.mode, boat));
    if (mode === 0) result = relative(a.priorBearing);
    if (mode === 1) result = relative(a.heading);
    if (mode === 2) result = relative(a.windDirection);
  }
  return selector !== 0 && selector < 3 ? result : Float80.fromNumber(angle.toNumber());
}
