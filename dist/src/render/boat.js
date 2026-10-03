import { add32, sub32, imul32, idiv32, i32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { atan2Extended } from '../runtime/atan.js';
import { sinCosX87 } from '../runtime/transcendentals.js';
import { wrapDegreesOnce } from '../engine/integer-core.js';
import { nativeTrig } from '../engine/native-trig.js';
import { initializeCurvedHull, initializeFlatHull } from '../engine/hull-geometry.js';
import { updateBoatSway } from '../engine/boat-sway.js';
import { initializeSailGeometry } from './sail-geometry.js';
import { initializeCrewGeometry } from './crew-geometry.js';
import { drawCatamaranPanels } from './boat-primitives.js';
import { drawHullPortSide, drawHullStarboardSide, drawHullStern, drawWakeBurst, drawSideSpray,
  drawStarboardInnerPanel, drawStarboardOuterPanel, drawPortInnerPanel, drawPortOuterPanel,
  drawCatamaranCrossbar, drawRudder, drawSteeringArc, drawTelltale } from './boat-panels.js';
import { drawHullOutline, drawBoardSurfaces, drawMainsail } from './boat-details.js';
import { drawBalancePanels, drawMastRigging } from './boat-rigging.js';
import { drawJib, drawSpinnaker } from './headsails.js';
import { drawCrew } from './crew-drawing.js';

export const BOAT_RENDERER_ROUTINE = 0x411000;
const index = (base, number, stride = 4) => add32(base, imul32(number, stride)) >>> 0;
const rb = (m, base, boat) => m.readI32(index(base, boat));
const px = (m, number) => rb(m, 0x4aa1a0, number), py = (m, number) => rb(m, 0x4aa2a0, number);
const f = (m, address) => Float80.fromNumber(m.readF64(address));
const n = value => Float80.fromNumber(value), integer = value => Float80.fromInteger(value);
const avg = (a, b) => idiv32(add32(a, b), 2);
const weighted = (a, b, factor = 2, divisor = 3) => idiv32(add32(a, imul32(b, factor)), divisor);
const abs = value => value < 0 ? sub32(0, value) : value;
function select(m, dc, address) { const handle = m.readU32(address); if (handle) dc.selectObject(handle); }

// 0x413cd0 returns its x87 operand without an additional binary64 spill.
function wrappedRadians(m, input) {
  let value = n(input);
  if (value.compare(f(m, 0x484ed8)) > 0) value = value.subtract(f(m, 0x484ee0));
  if (value.compare(f(m, 0x484ee8)) < 0) value = value.subtract(f(m, 0x484ef0));
  return value;
}

/** Complete 0x411000. Continuous x87 phases are checked at committed geometry and drawing requests. */
export function drawBoat(memory, dc, screenX, screenY, boat, viewer, bottom, top, rng, options = {}) {
  [screenX, screenY, boat, viewer, bottom, top] = [screenX, screenY, boat, viewer, bottom, top].map(i32);
  const get = address => memory.readI32(address), set = (address, value) => memory.writeI32(address, value);
  const sinCos = options.sinCos ?? sinCosX87, atan = options.atan2 ?? atan2Extended;
  if (get(0x4ac98c) === 1 && screenY < imul32(get(0x491148), 2)) return;
  const marker = boat === 0 ? 1 : 0;
  if (viewer === 1 && boat === 1) { set(0x4a67b0, screenX); set(0x4a6840, screenY); }
  if (viewer === 2 && boat === 2) { set(0x4a67b4, screenX); set(0x4a6844, screenY); }
  const mastIndex = get(0x491188) === 1 && get(0x4ac904) === 0 ? 4 : 3;
  const view = rb(memory, 0x4a4e88, viewer);
  const numerator = integer(sub32(screenY, top)), denominator = integer(sub32(bottom, top));
  let perspective = f(memory, 0x484dd8).subtract(numerator.multiply(f(memory, 0x484dd0)).divide(denominator)).toNumber();
  if (view === 2 && get(0x4ac994) !== 1) perspective = n(perspective).multiply(f(memory, 0x484de0)).toNumber();
  if (get(0x4ac980) > 500) perspective = n(perspective).multiply(f(memory, 0x484de8)).toNumber();
  if (view === 3) {
    perspective = f(memory, 0x484db0).subtract(numerator.multiply(f(memory, 0x484df0)).divide(denominator)).toNumber();
    if (get(0x4ac980) > 0) perspective = n(perspective).multiply(f(memory, 0x484cd8)).toNumber();
  }
  if (marker === 1 && get(0x4ac980) !== 109) perspective = n(perspective).multiply(f(memory, 0x484dc0)).toNumber();
  const nearThreshold = weighted(bottom, top);
  if (view === 1 || view === 2) {
    set(0x4ac930, 0); set(0x4a7354, nearThreshold); set(0x4a7358, view === 1 ? nearThreshold : avg(top, bottom)); set(0x4ac13c, nearThreshold);
  }
  if (view === 3) { set(0x4a7358, 0); set(0x4ac13c, 0); set(0x4a7354, 0); set(0x4ac930, 1); }
  if (boat === 1) updateBoatSway(memory, { sinCos });
  let sway = get(0x4a5b7c);
  if (boat & 1) sway = sub32(0, sway);
  if (screenY < get(0x4ac13c)) sway = idiv32(sway, 2);
  memory.writeF64(0x4a3ef0, idiv32(sway, 2));
  const boatClass = get(0x491188);
  let count;
  if (boatClass === 1) count = 44;
  if ([2, 3, 9].includes(boatClass)) count = 50;
  if (boatClass === 10 || (boatClass > 3 && boatClass < 8)) count = 56;
  if (boatClass === 8 || screenY <= get(0x4ac13c)) count = 38;
  if (count === undefined) throw new RangeError('Original boat renderer point count is uninitialized for this boat class');
  if (screenY <= get(0x4a7354) && boatClass !== 8 && boat > 1) count = sub32(count, 2);
  if (screenY <= get(0x4ac13c) && rb(memory, 0x4abb70, boat) < 1) count = 26;
  if (boat !== 1 && get(0x4ac928) === 1) count = rb(memory, 0x4abb70, boat) < 1 ? 26 : 38;
  if (marker === 1) count = 16;
  const heightUnrounded = integer(get(0x4a72d0)).multiply(n(perspective));
  let height = heightUnrounded.multiply(f(memory, boatClass < 8 || marker === 1 ? 0x484d50 : 0x484df8)).toNumber();
  if (get(0x4ac904) === 1) height = heightUnrounded.multiply(f(memory, 0x484df8)).toNumber();
  if (get(0x4ac900) === 1) height = heightUnrounded.multiply(f(memory, 0x484e00)).toNumber();
  let headingDifference = sub32(rb(memory, 0x4ac018, boat), rb(memory, 0x4a6830, viewer));
  // The first original wrap call discards EAX; its input register is retained.
  if (rb(memory, 0x4a4608, viewer) === 0 && rb(memory, 0x4a4e88, viewer) < 3 && boat !== viewer) {
    const scaled = integer(sub32(screenX, idiv32(get(0x4a763c), 2))).multiply(f(memory, 0x4ab0c8)).truncI32();
    // Signed high-half IMUL sequence at 0x4113be is division by -60.
    const high = Number(BigInt.asIntN(32, (BigInt(scaled) * 0x77777777n) >> 32n));
    const raw = sub32(high, scaled) >> 5;
    headingDifference = add32(headingDifference, add32(raw, raw < 0 ? 1 : 0));
  }
  let heading = wrapDegreesOnce(headingDifference);
  if (heading > 180) heading = sub32(heading, 360);
  if (viewer === 1 && boat === 1) set(0x4a475c, heading);
  if (viewer === 2 && boat === 2) set(0x4a4770, heading);
  let trim = add32(rb(memory, 0x4a77e8, boat), 5);
  const length = f(memory, 0x484e10).subtract(heightUnrounded.multiply(f(memory, 0x484e08))).toNumber();
  if (trim > 40) trim = 40;
  const trimPlus = add32(trim, 2), tack = rb(memory, 0x4aa730, boat);
  let front = 0;
  if (tack === 1) {
    if (heading < sub32(180, trimPlus) && heading >= 0) front = 1;
    if (sub32(0, trimPlus) < heading && heading < 0) front = 1;
  }
  if (tack === -1) {
    if (heading >= 0 && heading < trimPlus) front = 1;
    if (heading < 0 && sub32(trim, 178) < heading) front = 1;
  }
  memory.writeF64(0x4a3a48, screenY); memory.writeF64(0x4ac320, screenX);
  if (get(0x4ac900) === 1 && marker === 0) initializeFlatHull(memory, length, height);
  else initializeCurvedHull(memory, length, height, options);
  if (marker === 0) initializeSailGeometry(memory, height, boat, mastIndex, 15, heading, perspective, options);
  if (screenY > get(0x4ac13c) && marker === 0) initializeCrewGeometry(memory, height, boat, screenY);

  const metrics = new Map();
  function measure(first, number, yTarget) {
    for (let point = first; point < first + number; point++) {
      const dx = f(memory, index(0x4ac310, point, 8)).subtract(f(memory, 0x4ac320));
      const negativeY = f(memory, index(0x4a3a38, point, 8)).subtract(f(memory, 0x4a3a48)).negate();
      const dxStored = n(dx.toNumber());
      const angle = atan(dx, negativeY);
      memory.writeF64(yTarget + (point-first)*8, negativeY.toNumber());
      const total = negativeY.multiply(negativeY).add(dxStored.multiply(dxStored));
      metrics.set(point, total.compare(f(memory, 0x484e18)) <= 0 ? { radius: 0, angle: 0 } :
        { radius: n(total.toNumber()).sqrt().toNumber(), angle: angle.toNumber() });
    }
  }
  const hullCount = Math.min(count, 26);
  if (hullCount >= 0) measure(0, hullCount + 1, 0x4a8688);
  if (rb(memory, 0x4abb70, boat) === 1) measure(27, 12, 0x4a8760);
  if (screenY > get(0x4ac13c) && count > 38) measure(39, count-38, 0x4a87c0);
  const flatten = rb(memory, 0x4a4e88, viewer) > 2 ? 0.6 : 0.3;
  let crewAngle = wrapDegreesOnce(rb(memory, 0x4a6ec8, boat));
  if (get(0x4ac904) === 1) crewAngle = 0;
  const headingRadians = integer(heading).multiply(f(memory, 0x484e20)).toNumber();
  const crewSine = n(nativeTrig(crewAngle, options).sine.toNumber());
  function project(first, number, lateralBase, yBase) {
    for (let point = first; point < first + number; point++) {
      const { radius, angle } = metrics.get(point);
      const lateral = f(memory, lateralBase + (point-first)*8).multiply(crewSine).multiply(integer(rb(memory, 0x4aa730, boat))).multiply(f(memory, 0x484dc0));
      const vertical = lateral.subtract(f(memory, yBase + (point-first)*8).multiply(integer(sway)).multiply(f(memory, 0x484e28))).toNumber();
      const phase = wrappedRadians(memory, n(angle).subtract(n(headingRadians)).toNumber());
      const trig = sinCos(phase);
      set(index(0x4aa1a0, point), add32(trig.sine.multiply(n(radius)).truncI32(), screenX));
      set(index(0x4aa2a0, point), sub32(screenY, trig.cosine.multiply(n(flatten)).multiply(n(radius)).add(n(vertical)).truncI32()));
    }
  }
  if (hullCount >= 0) project(0, hullCount+1, 0x4a79f8, 0x4a8688);
  if (rb(memory, 0x4abb70, boat) === 1) project(27, 12, 0x4a7ad0, 0x4a8760);
  if (screenY > get(0x4ac13c) && count > 38) project(39, count-38, 0x4a7b30, 0x4a87c0);
  let depth = n(height).multiply(f(memory, 0x484e30)).truncI32();
  if (marker === 1) depth = idiv32(imul32(depth, 3), 2);
  if (get(0x4ac904) === 1) depth = idiv32(depth, 2);
  set(0x4a437c, px(memory, 0)); set(0x4a678c, add32(depth, py(memory, 0)));
  let rightX = avg(px(memory, 16), px(memory, 0)), rightY = avg(py(memory, 16), py(memory, 0));
  let leftX = avg(px(memory, 0), px(memory, 6)), leftY = avg(py(memory, 0), py(memory, 6));
  if (get(0x4ac914) === 1) {
    rightX = weighted(px(memory, 0), px(memory, 16), 3, 4); rightY = weighted(py(memory, 0), py(memory, 16), 3, 4);
    leftX = weighted(px(memory, 0), px(memory, 6), 3, 4); leftY = weighted(py(memory, 0), py(memory, 6), 3, 4);
  }
  set(0x4a4384, rightX); set(0x4a4380, leftX); set(0x4a6788, add32(rightY, depth)); set(0x4a6784, add32(leftY, depth));
  depth = n(height).multiply(f(memory, 0x484e38)).truncI32();
  if (marker === 1) depth = idiv32(imul32(depth, 3), 2);
  let sternX = px(memory, 5), sternY = py(memory, 5);
  if (boatClass !== 4 && boatClass !== 8 && boat !== 0) { sternX = weighted(px(memory, 4), px(memory, 5)); sternY = weighted(py(memory, 4), py(memory, 5)); }
  if (get(0x4ac904) === 1) { sternX = px(memory, 4); sternY = py(memory, 4); }
  set(0x4ac838, sternX); set(0x4a3f88, add32(sternY, depth));
  const wake = (x, y) => drawWakeBurst(memory, dc, boat, height, x, y, rng);
  if (boat <= get(0x491140) && rb(memory, 0x4a7060, boat) > 26 && boat > 0 && get(0x4ac900) === 0) wake(px(memory, 11), py(memory, 11));
  if (get(0x4ac994) > 0) wake(px(memory, 11), py(memory, 11));
  if ((boat <= get(0x491140) || get(0x4ac994) > 0) && rb(memory, 0x4a7060, boat) > 30 && boat > 0 && get(0x4ac900) === 1 && marker === 0) {
    const rise = n(height).multiply(f(memory, 0x484e40)).truncI32();
    const xLeft = avg(px(memory, 6), px(memory, 7)), yLeft = sub32(avg(py(memory, 6), py(memory, 7)), rise);
    const xRight = avg(px(memory, 16), px(memory, 15)), yRight = sub32(avg(py(memory, 16), py(memory, 15)), rise);
    if (rb(memory, 0x4aa730, boat) === 1) { wake(xRight, yRight); if (rb(memory, 0x4a6ec8, boat) < 8) wake(xLeft, yLeft); }
    if (rb(memory, 0x4aa730, boat) === -1) { if (rb(memory, 0x4a6ec8, boat) < 8) wake(xRight, yRight); wake(xLeft, yLeft); }
  }
  if (get(0x4ac900) === 0 || marker === 1) {
    if (heading > 0 || heading < -169) drawHullPortSide(memory, dc, height, marker, boat);
    if (heading < 0 || heading > 169) drawHullStarboardSide(memory, dc, height, marker, boat);
    if (heading > -90 && heading < 90) drawHullStern(memory, dc, height, boat, marker, screenY);
  }
  if (get(0x4ac900) === 1 && marker === 0) {
    if (heading > 0 || heading < -169) { drawStarboardInnerPanel(memory, dc, height, boat, screenY, rng); drawPortOuterPanel(memory, dc, height, boat, screenY, rng); }
    if (heading < 0 || heading > 169) { drawPortInnerPanel(memory, dc, height, boat, screenY, rng); drawStarboardOuterPanel(memory, dc, height, boat, screenY, rng); }
    if (heading > -91 && heading < 91) drawBalancePanels(memory, dc, height, boat, heading, options);
  }
  if (rb(memory, 0x4a7060, boat) > 30 && marker === 0 && get(0x4ac900) === 0) {
    if (heading < 15 || heading > 170) drawSideSpray(memory, dc, boat, height, 1, screenY, heading, rng);
    if (heading > -15 || heading < -170) drawSideSpray(memory, dc, boat, height, 0, screenY, heading, rng);
  }
  if (get(0x4ac900) === 1 && marker === 0) { drawCatamaranPanels(memory, dc); drawCatamaranCrossbar(memory, dc, height, perspective); }
  else drawHullOutline(memory, dc, height, boat, screenY);
  if (boatClass === 7 && marker === 0 && abs(heading) < 91) drawBoardSurfaces(memory, dc, boat, height, heading, 0, screenY);
  if (marker === 1 || boat === 0) {
    if (abs(heading) < 91) drawBoardSurfaces(memory, dc, boat, height, 1, heading, screenY);
    set(0x4a7bc8, 0);
    const truncatedHeight = n(height).truncI32();
    drawTelltale(memory, dc, px(memory, 2), add32(py(memory, 2), imul32(truncatedHeight, -3)), 0, heading, screenY, marker, rng);
    drawTelltale(memory, dc, px(memory, 2), add32(py(memory, 2), imul32(truncatedHeight, -2)), 0, heading, screenY, 2, rng);
    select(memory, dc, 0x4a4dec); dc.moveTo(px(memory, 2), py(memory, 2)); dc.lineTo(px(memory, 2), add32(py(memory, 2), imul32(truncatedHeight, -3)));
    if (abs(heading) > 90) drawBoardSurfaces(memory, dc, boat, height, 1, heading, screenY);
    return;
  }
  if (boatClass === 7 && abs(heading) > 90) drawBoardSurfaces(memory, dc, boat, height, heading, marker, screenY);
  if (get(0x49114c) < 1) drawRudder(memory, dc, height, boat, screenY);
  const mast = pose => drawMastRigging(memory, dc, boat, height, mastIndex, 15, screenY, perspective, heading, marker, pose, rng);
  const mainsail = () => drawMainsail(memory, dc, height, boat, perspective, screenY, heading, front, rng);
  const headsails = () => {
    if (rb(memory, 0x4abb70, boat) === 1 && boatClass > 2 && boatClass !== 9) drawSpinnaker(memory, dc, height, boat, screenY, front, rng);
    if (rb(memory, 0x4abb70, boat) === 1 && boatClass === 2) drawJib(memory, dc, height, boat, screenY, front);
    if (rb(memory, 0x4abb70, boat) < 1 && boatClass > 1) drawJib(memory, dc, height, boat, screenY, front);
  };
  const arcs = () => {
    if (boatClass === 8) { drawSteeringArc(memory, dc, height, boat, 1, heading, screenY); drawSteeringArc(memory, dc, height, boat, -1, heading, screenY); }
  };
  const crew = () => {
    const near = heading < 90 && heading > -90;
    const draw = number => drawCrew(memory, dc, number, boat, height, screenY, front, heading);
    const steering = () => { if (get(0x49114c) === 1 && boatClass < 8) drawSteeringArc(memory, dc, height, boat, 0, heading, screenY); };
    if (near) { if (boatClass > 3 && boatClass < 9) draw(3); if (boatClass > 1) draw(2); draw(1); steering(); }
    else { steering(); draw(1); if (boatClass > 1) draw(2); if (boatClass > 3 && boatClass < 9) draw(3); }
  };
  if (get(0x4ac904) === 1) mast(front);
  if (front === 1) { headsails(); mainsail(); mast(1); arcs(); crew(); }
  else { arcs(); crew(); mainsail(); mast(front); headsails(); }
}
