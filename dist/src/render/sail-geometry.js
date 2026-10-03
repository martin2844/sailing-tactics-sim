import { Float80 } from '../runtime/float80.js';
import { i32, add32, sub32, imul32, idiv32, irem32 } from '../runtime/c-types.js';
import { wrapDegreesOnce } from '../engine/integer-core.js';
import { nativeTrig } from '../engine/native-trig.js';

const n = value => Float80.fromNumber(value);
const i = value => Float80.fromInteger(i32(value));
const f = (memory, address) => n(memory.readF64(address));
const stored = value => n(value.toNumber());
const at = (base, index, stride = 4) => add32(base, imul32(index, stride)) >>> 0;
const put = (memory, address, value) => memory.writeF64(address, value.toNumber());
const absolute = value => value < 0 ? sub32(0, value) : value;

/** Complete 0x414010: mainsail, jib and all twelve spinnaker points. */
export function initializeSailGeometry(memory, height, boat, baseIndex, curvature, viewHeading, widthScale, options = {}) {
  [boat, baseIndex, curvature, viewHeading] = [boat, baseIndex, curvature, viewHeading].map(i32);
  const r = address => memory.readI32(address);
  const rb = address => r(at(address, boat));
  const w = (address, value) => memory.writeI32(at(address, boat), value);
  const boatClass = r(0x491188);
  if (r(0x491140) < boat) {
    w(0x4a7768, 1); w(0x4a4ef8, 1);
    w(0x4a4170, boatClass === 10 || r(0x4ac90c) === 1 || r(0x4ac908) === 1 || boatClass === 8 ? 3 : 2);
    w(0x4ac5f0, 0);
  }
  let extensionCount = sub32(boatClass === 1 ? 5 : 4, rb(0x4a7768));
  if (r(0x4ac914) === 1) extensionCount = 1;
  if (r(0x4ac904) === 1) extensionCount = 6;
  const extentFactor = f(memory, absolute(viewHeading) < 11 ? 0x484f10 : 0x484d48);
  const scale = n(r(0x4ac900) === 1 ? 0.45 : 0.4);
  const width80 = n(widthScale);
  let bend = i(imul32(rb(0x4a6ec8), rb(0x4aa730))).multiply(width80).multiply(f(memory, 0x484f20));
  if (r(0x4ac904) === 1) bend = i(rb(0x4aa730)).multiply((bend.sign < 0 ? bend.negate() : bend).subtract(f(memory, 0x484f28))).multiply(width80).negate();
  bend = bend.multiply(scale);
  const bendStored = stored(bend);
  const step = stored(i(sub32(extensionCount, 1)).multiply(n(height)));
  let extent = extentFactor.multiply(step);
  const baseX = () => f(memory, at(0x4ac310, baseIndex, 8));
  const baseY = () => f(memory, at(0x4a3a38, baseIndex, 8));
  const sway = () => f(memory, 0x4a3ef0);
  const boardY = address => {
    if (r(0x4ac904) === 1) put(memory, address, f(memory, address).subtract(f(memory, address + (0x4a8710 - 0x4a3ac0)).multiply(i(2))));
  };
  const offset0 = bend.multiply(f(memory, 0x484e48));
  put(memory, 0x4a7a80, offset0);
  put(memory, 0x4ac398, f(memory, 0x4a7a80).add(baseX()));
  put(memory, 0x4a3ac0, baseY().subtract(extent.multiply(f(memory, 0x484d48))).add(scale.multiply(sway())));
  put(memory, 0x4a8710, scale);
  boardY(0x4a3ac0);
  const vertical1 = stored(scale.multiply(f(memory, 0x484eb8)));
  extent = extent.multiply(f(memory, 0x484da8));
  const offset1 = bend.multiply(f(memory, 0x484f30));
  put(memory, 0x4a7a88, offset1);
  put(memory, 0x4ac3a0, offset1.add(baseX()));
  put(memory, 0x4a3ac8, baseY().subtract(extent).add(sway().multiply(vertical1)));
  put(memory, 0x4a8718, vertical1);
  boardY(0x4a3ac8);
  const vertical2 = stored(scale.multiply(f(memory, 0x484ea8)));
  const offset2 = bend.multiply(f(memory, 0x484f38));
  put(memory, 0x4a7a90, offset2);
  put(memory, 0x4ac3a8, offset2.add(baseX()));
  put(memory, 0x4a3ad0, baseY().subtract(extent).add(sway().multiply(vertical2)));
  put(memory, 0x4a8720, vertical2);
  boardY(0x4a3ad0);
  const vertical3 = stored(scale.multiply(f(memory, 0x484f48)));
  const offset3 = bend.multiply(f(memory, 0x484f40));
  put(memory, 0x4a7a98, offset3);
  put(memory, 0x4ac3b0, offset3.add(baseX()));
  put(memory, 0x4a3ad8, sway().multiply(vertical3).add(baseY()));
  put(memory, 0x4a8728, vertical3);
  boardY(0x4a3ad8);
  const vertical4 = stored(scale.multiply(f(memory, 0x484f58)));
  const tip = bendStored.multiply(f(memory, 0x484f50));
  put(memory, 0x4a7aa0, tip);
  put(memory, 0x4ac3b8, tip.add(baseX()));
  put(memory, 0x4a3ae0, sway().multiply(vertical4).add(extentFactor.multiply(step)).add(baseY()));
  put(memory, 0x4a8730, vertical4);
  boardY(0x4a3ae0);
  if (r(0x4ac914) === 1) put(memory, 0x4a3ae0, f(memory, 0x4a3ae0).subtract(extentFactor.multiply(n(height)).multiply(f(memory, 0x484d60))));
  let angleOffset = add32(rb(0x4a77e8), 5);
  if (rb(0x4a8aa8) > 20) angleOffset = add32(rb(0x4a77e8), 15);
  if (rb(0x4a8aa8) > 70) angleOffset = 40;
  if (boat <= r(0x491140)) angleOffset = add32(add32(idiv32(rb(0x4a85d0), 5), 5), rb(0x4a77e8));
  if (angleOffset > 40) angleOffset = 40;
  if (r(0x4ac904) === 1) {
    angleOffset = idiv32(imul32(angleOffset, 2), 3);
    if (irem32(add32(f(memory, 0x4abef0).truncI32(), boat), 4) === 0) angleOffset = sub32(angleOffset, 2);
  }
  const angle0 = wrapDegreesOnce(add32(idiv32(curvature, 5), angleOffset));
  let radius = boatClass < 5 || r(0x4ac900) === 1 ? f(memory, 0x4a3a38) :
    f(memory, 0x4a3a40).subtract(f(memory, 0x4a3a38).multiply(f(memory, 0x484e80))).multiply(f(memory, 0x484f60));
  radius = radius.subtract(baseY());
  const radiusStored = stored(radius);
  const tableCos = angle => i(r(at(0x4a3450, angle)));
  const tableSin = angle => i(r(at(0x4a54a0, angle)));
  const nativeSin = angle => nativeTrig(angle, options).sine;
  const tack = () => i(rb(0x4aa730));
  const curvedPoints = [
    [angle0, radius, 0x4a7a80, 0x4a7ac0, 0x4ac3d8, 0x4a3b00, 0x4a8750, scale, null, 0x484e28, false],
    [wrapDegreesOnce(add32(idiv32(imul32(curvature, 2), 4), angleOffset)), radiusStored, 0x4a7a88, 0x4a7ab8, 0x4ac3d0, 0x4a3af8, 0x4a8748, vertical1, 0x484d70, 0x484f68, false],
    [wrapDegreesOnce(add32(idiv32(imul32(curvature, 3), 4), angleOffset)), radiusStored, 0x4a7a90, 0x4a7ab0, 0x4ac3c8, 0x4a3af0, 0x4a8740, vertical2, 0x484dc0, 0x484f70, true],
    [wrapDegreesOnce(add32(idiv32(imul32(curvature, 4), 5), angleOffset)), radiusStored, 0x4a7a98, 0x4a7aa8, 0x4ac3c0, 0x4a3ae8, 0x4a8738, vertical3, 0x484f78, 0x484f80, false],
  ];
  for (const [angle, distance, anchor, offsetAddress, xAddress, yAddress, verticalAddress, vertical, xFactor, yFactor, reloadOffset] of curvedPoints) {
    let horizontal = nativeSin(angle).multiply(distance).multiply(tack());
    if (xFactor) horizontal = horizontal.multiply(f(memory, xFactor));
    const offset = f(memory, anchor).subtract(horizontal);
    put(memory, offsetAddress, offset);
    put(memory, verticalAddress, vertical);
    put(memory, xAddress, (reloadOffset ? f(memory, offsetAddress) : offset).add(baseX()));
    put(memory, yAddress, baseY().subtract(tableCos(angle).multiply(distance).multiply(f(memory, yFactor))).add(vertical.multiply(sway())));
  }
  if (boatClass === 1) return;
  let jibAngle = idiv32(sub32(rb(0x4a7bc8), 30), 3);
  jibAngle = Math.min(24, Math.max(2, jibAngle));
  let span = stored(f(memory, at(0x4a3a30, baseIndex, 8)).add(baseY()).multiply(f(memory, 0x484da8)).subtract(f(memory, 0x4a3a60)));
  if (boatClass > 6 && r(0x4ac900) === 0) span = stored(f(memory, 0x484f58).divide(i(add32(rb(0x4a4ef8), 6))).multiply(span));
  if (r(0x4ac900) === 1) span = stored(span.multiply(f(memory, 0x484de8)));
  const sportJib = boatClass === 2 && rb(0x4abb70) === 1;
  const jibDirection = wrapDegreesOnce(sportJib ? 80 : add32(jibAngle, 11));
  put(memory, 0x4a3b08, f(memory, 0x4a3a60).subtract(tableCos(jibDirection).multiply(span).multiply(f(memory, 0x484e28))));
  put(memory, 0x4a7ac8, nativeSin(jibDirection).multiply(span).multiply(tack()).negate());
  if (sportJib) put(memory, 0x4a7ac8, f(memory, 0x4a7ac8).multiply(f(memory, 0x484f88)));
  put(memory, 0x4ac3e0, f(memory, 0x4a7ac8).add(f(memory, 0x4ac338)));
  if (rb(0x4abb70) < 1 || boatClass < 3) return;
  let spinAngle = Math.max(20, sub32(rb(0x4a7bc8), 112));
  if (boat === 1 && r(0x4a4174) === 3) spinAngle = 20;
  if (boat > 1 && boatClass === 8 && r(0x4aa390) < 12) spinAngle = 20;
  span = stored(baseY().subtract(f(memory, 0x4a3a60)));
  if (r(0x4ac900) === 1 || r(0x4ac908) === 1 || r(0x4ac90c) === 1) {
    span = stored(span.multiply(f(memory, 0x484f90))); spinAngle = 13;
  }
  if (boatClass === 3 && r(0x4ac90c) === 0) span = stored(span.multiply(f(memory, 0x484f90)));
  for (let group = 0; group < 3; group++) {
    const angle = wrapDegreesOnce(sub32(spinAngle, [0, 60, 130][group]));
    let distance = group === 2 ? baseY().subtract(f(memory, 0x4a3a60)) : span;
    if (group === 1) distance = stored(distance.multiply(f(memory, 0x484db8)));
    const horizontal = tableSin(angle).multiply(distance).multiply(tack());
    const vertical = tableCos(angle).multiply(distance);
    const horizontalStored = stored(horizontal), verticalStored = stored(vertical);
    const smallHorizontal = group === 0 ? horizontal.multiply(f(memory, 0x484e28)) : stored(horizontal.multiply(f(memory, 0x484e28)));
    const shortVertical = stored(vertical.multiply(f(memory, 0x484cc8)));
    for (let point = 0; point < 4; point++) {
      const offsetAddress = 0x4a7ad0 + group * 32 + point * 8;
      const xAddress = 0x4ac3e8 + group * 32 + point * 8;
      const yAddress = 0x4a3b10 + group * 32 + point * 8;
      let xDelta = smallHorizontal;
      if (point === 1 || point === 3) xDelta = (group === 2 ? horizontalStored : horizontal).multiply(f(memory, point === 1 ? 0x484fa0 : 0x484fb0));
      const offset = f(memory, 0x4a7a80 + point * 8).subtract(xDelta);
      put(memory, offsetAddress, offset);
      put(memory, xAddress, offset.add(baseX()));
      const yDelta = point === 0 || point === 2 ? shortVertical : (group === 2 ? verticalStored : vertical).multiply(f(memory, point === 1 ? 0x484fa8 : 0x484fb8));
      put(memory, yAddress, baseY().subtract(yDelta));
      if (group === 0 && point === 0 && r(0x4ac900) === 1) {
        put(memory, xAddress, baseX());
        put(memory, yAddress, f(memory, 0x4a3a60).subtract(f(memory, 0x4a3a60).subtract(baseY()).multiply(f(memory, 0x484f98))));
      }
    }
  }
}

export const SAIL_GEOMETRY_ROUTINES = Object.freeze({ initializeSailGeometry: 0x414010 });
