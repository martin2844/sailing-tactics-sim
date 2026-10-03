import { Float80 } from '../../../../src/runtime/float80.js';
import { i32, add32, sub32, imul32, idiv32, irem32 } from '../../../../src/runtime/c-types.js';
import { wrapDegreesOnce } from '../../../../src/engine/integer-core.js';

const n = value => Float80.fromNumber(value instanceof Float80 ? value.toNumber() : value);
const i = value => Float80.fromInteger(i32(value));
const f = (memory, address) => n(memory.readF64(address));
const stored = value => n(value.toNumber());
const at = (base, index, stride = 4) => add32(base, imul32(index, stride)) >>> 0;
const put = (memory, address, value) => memory.writeF64(address, value.toNumber());
const absolute = value => value < 0 ? sub32(0, value) : value;

/** Complete original 2010 0x41bfb0: mainsail, jib and all twelve spinnaker points. */
export function initializeSailGeometry(memory, height, boat, baseIndex, curvature, viewHeading, widthScale, options = {}) {
  [boat, baseIndex, curvature, viewHeading] = [boat, baseIndex, curvature, viewHeading].map(i32);
  const r = address => memory.readI32(address);
  const rb = address => r(at(address, boat));
  const w = (address, value) => memory.writeI32(at(address, boat), value);
  const boatClass = r(0x4da190);
  if (r(0x4da140) < boat) {
    w(0x4fe778, 1); w(0x4f7ee0, 1);
    w(0x4f42c0, boatClass === 10 || r(0x5363c4) === 1 || r(0x5363c0) > 0 || boatClass === 8 || r(0x53652c) === 1 ? 3 : 2);
    w(0x535f68, 0);
  }
  let extensionCount = sub32(boatClass === 1 ? 5 : 4, rb(0x4fe778));
  if (r(0x5363cc) === 1) extensionCount = 1;
  if (r(0x5363bc) === 1) extensionCount = 6;
  const extentFactor = f(memory, absolute(viewHeading) < 11 ? 0x4cc770 : 0x4cc570);
  const scale = n(r(0x5363b8) === 1 || r(0x536528) === 1 || r(0x53652c) === 1 ? 0.45 : 0.4);
  const width80 = n(widthScale);
  let bend = i(imul32(rb(0x4fc2c0), rb(0x522ff0))).multiply(width80).multiply(f(memory, 0x4cc538));
  if (r(0x5363bc) === 1) bend = i(rb(0x522ff0)).multiply((bend.sign < 0 ? bend.negate() : bend).subtract(f(memory, 0x4cc780))).multiply(width80).negate();
  bend = bend.multiply(scale);
  const bendStored = stored(bend);
  const step = stored(i(sub32(extensionCount, 1)).multiply(n(height)));
  let extent = extentFactor.multiply(step);
  const baseX = () => f(memory, at(0x535c68, baseIndex, 8));
  const baseY = () => f(memory, at(0x4f3a38, baseIndex, 8));
  const sway = () => f(memory, 0x4f3f50);
  const boardY = address => {
    if (r(0x5363bc) === 1) put(memory, address, f(memory, address).subtract(f(memory, address + (0x511410 - 0x4f3ac0)).multiply(i(2))));
  };
  const offset0 = bend.multiply(f(memory, 0x4cc6b8));
  put(memory, 0x4feaf0, offset0);
  put(memory, 0x535cf0, f(memory, 0x4feaf0).add(baseX()));
  put(memory, 0x4f3ac0, baseY().subtract(extent.multiply(f(memory, 0x4cc570))).add(scale.multiply(sway())));
  put(memory, 0x511410, scale);
  boardY(0x4f3ac0);
  const vertical1 = stored(scale.multiply(f(memory, 0x4cc730)));
  extent = extent.multiply(f(memory, 0x4cc4f8));
  const offset1 = bend.multiply(f(memory, 0x4cc788));
  put(memory, 0x4feaf8, offset1);
  put(memory, 0x535cf8, offset1.add(baseX()));
  put(memory, 0x4f3ac8, baseY().subtract(extent).add(sway().multiply(vertical1)));
  put(memory, 0x511418, vertical1);
  boardY(0x4f3ac8);
  const vertical2 = stored(scale.multiply(f(memory, 0x4cc728)));
  const offset2 = bend.multiply(f(memory, 0x4cc790));
  put(memory, 0x4feb00, offset2);
  put(memory, 0x535d00, offset2.add(baseX()));
  put(memory, 0x4f3ad0, baseY().subtract(extent).add(sway().multiply(vertical2)));
  put(memory, 0x511420, vertical2);
  boardY(0x4f3ad0);
  const vertical3 = stored(scale.multiply(f(memory, 0x4cc7a0)));
  const offset3 = bend.multiply(f(memory, 0x4cc798));
  put(memory, 0x4feb08, offset3);
  put(memory, 0x535d08, offset3.add(baseX()));
  put(memory, 0x4f3ad8, sway().multiply(vertical3).add(baseY()));
  put(memory, 0x511428, vertical3);
  boardY(0x4f3ad8);
  const vertical4 = stored(scale.multiply(f(memory, 0x4cc418)));
  const tip = bendStored.multiply(f(memory, 0x4cc7a8));
  put(memory, 0x4feb10, tip);
  put(memory, 0x535d10, tip.add(baseX()));
  put(memory, 0x4f3ae0, sway().multiply(vertical4).add(extentFactor.multiply(step)).add(baseY()));
  put(memory, 0x511430, vertical4);
  boardY(0x4f3ae0);
  if (r(0x5363cc) === 1) put(memory, 0x4f3ae0, f(memory, 0x4f3ae0).subtract(extentFactor.multiply(n(height)).multiply(f(memory, 0x4cc588))));
  let angleOffset = add32(rb(0x4fe818), 5);
  if (rb(0x512278) > 20) angleOffset = add32(rb(0x4fe818), 15);
  if (rb(0x512278) > 70) angleOffset = 40;
  if (boat <= r(0x4da140)) angleOffset = add32(add32(idiv32(rb(0x500380), 5), 5), rb(0x4fe818));
  if (angleOffset > 40) angleOffset = 40;
  if (r(0x5363bc) === 1) {
    angleOffset = idiv32(imul32(angleOffset, 2), 3);
    if (irem32(add32(f(memory, 0x5355f8).truncI32(), boat), 4) === 0) angleOffset = sub32(angleOffset, 2);
  }
  if (r(0x5363b8) === 1) angleOffset = idiv32(angleOffset, r(0x5364c0) === 1 ? 5 : 2);
  if (r(0x5363c4) === 1 && rb(0x5350d8) === 1) angleOffset = idiv32(angleOffset, 2);
  if ((boatClass === 8 || r(0x5363c0) > 0) && rb(0x5350d8) === 1) angleOffset = idiv32(angleOffset, 2);
  const angle0 = wrapDegreesOnce(add32(idiv32(curvature, 5), angleOffset));
  let radius = f(memory,0x4f3a38);
  if (boatClass > 4) radius = f(memory,0x4f3a40).subtract(f(memory,0x4f3a38).multiply(f(memory,0x4cc5c8))).multiply(f(memory,0x4cc7b0));
  radius = stored(radius.subtract(baseY()));
  if (r(0x5364bc) === 1) radius = stored(f(memory,0x4f3a40).subtract(f(memory,0x4f3a58)));
  if (r(0x53652c) === 1 || r(0x536530) === 1) radius = stored(f(memory,0x4f3a38).subtract(baseY()));
  if (boatClass === 8 || r(0x5363b8) === 1) radius = stored(f(memory,0x4f3a40).add(f(memory,0x4f3a38)).multiply(f(memory,0x4cc4f8)).subtract(baseY()));
  if (r(0x536528) === 1) {
    const sum = f(memory,0x4f3a40).add(f(memory,0x4f3a38));
    radius = stored(sum.add(sum).multiply(f(memory,0x4cc518)).subtract(baseY()));
  }
  if (r(0x5363bc) === 1) radius = stored(f(memory,0x4f3a38).subtract(f(memory,0x4f3a50)));
  const radiusStored = stored(radius);
  const tableCos = angle => i(r(at(0x4f1740, angle)));
  const tableSin = angle => i(r(at(0x4f85c8, angle)));
  const nativeSin = angle => options.trig.extended(angle).sine;
  const tack = () => i(rb(0x522ff0));
  const curvedPoints = [
    [angle0, radius, 0x4feaf0, 0x4feb30, 0x535d30, 0x4f3b00, 0x511450, scale, null, 0x4cc678, false],
    [wrapDegreesOnce(add32(idiv32(imul32(curvature, 2), 4), angleOffset)), radiusStored, 0x4feaf8, 0x4feb28, 0x535d28, 0x4f3af8, 0x511448, vertical1, 0x4cc7b8, 0x4cc7c0, false],
    [wrapDegreesOnce(add32(idiv32(imul32(curvature, 3), 4), angleOffset)), radiusStored, 0x4feb00, 0x4feb20, 0x535d20, 0x4f3af0, 0x511440, vertical2, 0x4cc600, 0x4cc7c8, true],
    [wrapDegreesOnce(add32(idiv32(imul32(curvature, 4), 5), angleOffset)), radiusStored, 0x4feb08, 0x4feb18, 0x535d18, 0x4f3ae8, 0x511438, vertical3, 0x4cc7d0, 0x4cc7d8, false],
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
  let jibAngle = idiv32(sub32(rb(0x4fecc8), 30), 3);
  if ((r(0x5364c0) === 1 || r(0x5363c4) === 1) && rb(0x5350d8) === 1) jibAngle = idiv32(jibAngle,2);
  jibAngle = Math.min(24, Math.max(2, jibAngle));
  let span = stored(f(memory, at(0x4f3a30, baseIndex, 8)).add(baseY()).multiply(f(memory, 0x4cc4f8)).subtract(f(memory, 0x4f3a60)));
  if (boatClass > 6 && r(0x5363b8) === 0) span = stored(f(memory, 0x4cc418).divide(i(add32(rb(0x4f7ee0), 6))).multiply(span));
  if (r(0x5363b8) === 1 || r(0x5364c8) === 1) span = stored(span.multiply(f(memory,0x4cc508)));
  if (boatClass === 8 || r(0x5364c4) === 1) span = stored(span.multiply(f(memory,0x4cc6b0)));
  if (r(0x4fb410) === 1) span = stored(span.multiply(f(memory,0x4cc7e0)));
  if (r(0x5364bc) === 1 || r(0x53652c) === 1) span = stored(span.multiply(f(memory,0x4cc7e0)));
  if (r(0x536528) === 1) span = stored(span.multiply(f(memory,0x4cc600)));
  if (r(0x536530) === 1) span = stored(span.multiply(f(memory,0x4cc600)));
  const sportJib = (boatClass === 2 || r(0x5364c4) === 1 || r(0x5364c8) === 1) && rb(0x5350d8) === 1;
  const jibDirection = wrapDegreesOnce(sportJib ? 80 : add32(jibAngle, 11));
  put(memory, 0x4f3b08, f(memory, 0x4f3a60).subtract(tableCos(jibDirection).multiply(span).multiply(f(memory, 0x4cc678))));
  put(memory, 0x4feb38, nativeSin(jibDirection).multiply(span).multiply(tack()).negate());
  if (sportJib) put(memory, 0x4feb38, f(memory, 0x4feb38).multiply(f(memory, 0x4cc7e8)));
  put(memory, 0x535d38, f(memory, 0x4feb38).add(f(memory, 0x535c90)));
  if (rb(0x5350d8) < 1 || boatClass < 3) return;
  let spinAngle = Math.max(20, sub32(rb(0x4fecc8), 112));
  if (boat === 1 && r(0x4f42c4) === 3) spinAngle = 20;
  if (boat > 1 && boatClass === 8) spinAngle = 20;
  span = stored(baseY().subtract(f(memory, 0x4f3a60)));
  if (r(0x5363b8) === 1 || r(0x5363c0) > 0 || r(0x5363c4) === 1 || r(0x53652c) === 1) {
    span = stored(span.multiply(f(memory, 0x4cc7f0))); spinAngle = 13;
  }
  if (boatClass === 3 && r(0x5363c4) === 0) span = stored(span.multiply(f(memory, 0x4cc7f0)));
  for (let group = 0; group < 3; group++) {
    const angle = wrapDegreesOnce(sub32(spinAngle, [0, 60, 130][group]));
    let distance = group === 2 ? baseY().subtract(f(memory, 0x4f3a60)) : span;
    if (group === 1) distance = stored(distance.multiply(f(memory, 0x4cc820)));
    const horizontal = tableSin(angle).multiply(distance).multiply(tack());
    const vertical = tableCos(angle).multiply(distance);
    const horizontalStored = stored(horizontal), verticalStored = stored(vertical);
    const smallHorizontal = group === 0 ? horizontal.multiply(f(memory, 0x4cc678)) : stored(horizontal.multiply(f(memory, 0x4cc678)));
    const shortVertical = stored(vertical.multiply(f(memory, 0x4cc3f0)));
    for (let point = 0; point < 4; point++) {
      const offsetAddress = 0x4feb40 + group * 32 + point * 8;
      const xAddress = 0x535d40 + group * 32 + point * 8;
      const yAddress = 0x4f3b10 + group * 32 + point * 8;
      let xDelta = smallHorizontal;
      if (point === 1 || point === 3) xDelta = (group === 2 ? horizontalStored : horizontal).multiply(f(memory, point === 1 ? 0x4cc800 : 0x4cc810));
      const offset = f(memory, 0x4feaf0 + point * 8).subtract(xDelta);
      put(memory, offsetAddress, offset);
      put(memory, xAddress, offset.add(baseX()));
      const yDelta = point === 0 || point === 2 ? shortVertical : (group === 2 ? verticalStored : vertical).multiply(f(memory, point === 1 ? 0x4cc808 : 0x4cc818));
      put(memory, yAddress, baseY().subtract(yDelta));
      if (group === 0 && point === 0 && r(0x5363b8) === 1) {
        put(memory, xAddress, baseX());
        put(memory, yAddress, f(memory, 0x4f3a60).subtract(f(memory, 0x4f3a60).subtract(baseY()).multiply(f(memory, 0x4cc7f8))));
      }
    }
  }
}

export const SAIL_GEOMETRY_ROUTINES = Object.freeze({ initializeSailGeometry: 0x41bfb0 });
