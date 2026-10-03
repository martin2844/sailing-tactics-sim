import { add32, sub32, imul32, idiv32, i32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom } from '../engine/integer-core.js';
import { drawInteriorPanel, drawSailCurve } from './boat-primitives.js';

export const BOAT_DETAIL_ROUTINES = Object.freeze({
  drawHullOutline: 0x412810, drawBoardSurfaces: 0x419db0,
  drawSailRigging: 0x4156f0, drawMainsail: 0x414d00,
});
const X = 0x4aa1a0, Y = 0x4aa2a0, POLYGON = 0x4a4ca8;
const indexed = (base, index) => add32(base, imul32(index, 4)) >>> 0;
const px = (m, index) => m.readI32(indexed(X, index));
const py = (m, index) => m.readI32(indexed(Y, index));
const rb = (m, base, boat) => m.readI32(indexed(base, boat));
const avg = (left, right) => idiv32(add32(left, right), 2);
const weighted = (first, second, factor = 2, divisor = 3) => idiv32(add32(first, imul32(second, factor)), divisor);
const constant = (memory, address) => Float80.fromNumber(memory.readF64(address));
const heightProduct = (memory, height, factor) => Float80.fromNumber(height).multiply(constant(memory, factor));
const heightOffset = (memory, height, factor) => heightProduct(memory, height, factor).truncI32();
const abs32 = value => value < 0 ? sub32(0, value) : value;
function select(memory, dc, address) { const handle = memory.readU32(address); if (handle) dc.selectObject(handle); }
function storePolygon(memory, values) {
  values.forEach(([x, y], index) => { memory.writeI32(POLYGON + index * 8, x); memory.writeI32(POLYGON + index * 8 + 4, y); });
}
function drawPolygon(memory, dc, values, stock) {
  storePolygon(memory, values);
  if (stock !== undefined) dc.selectStockObject(stock);
  dc.polygon(values.map(([x, y]) => ({ x, y })));
}

/** Complete 0x412810, including sport-boat and skiff geometry state writes. */
export function drawHullOutline(memory, dc, height, boat, screenY) {
  boat = i32(boat); screenY = i32(screenY);
  const get = address => memory.readI32(address);
  const boatClass = get(0x491188);
  const values = [5, 10, 9, 8, 7, 6, 16, 15, 14, 13, 12].map(index => [px(memory, index), py(memory, index)]);
  storePolygon(memory, values);
  if (get(0x4ac92c) === 0 && get(0x4ac910) === 0) select(memory, dc, 0x4a4f7c);
  else dc.selectStockObject(0);
  if (boat > get(0x491140)) select(memory, dc, 0x4a3efc);
  if (get(0x4ac98c) === 1) select(memory, dc, 0x4a3efc);
  dc.selectStockObject(7);
  if (get(0x4ac92c) === 0 && get(0x4ac910) === 1 && boat === 1) select(memory, dc, 0x4ac854);
  dc.polygon(values.map(([x, y]) => ({ x, y })));
  if (boatClass !== 4 && get(0x4ac90c) !== 1 && get(0x4ac914) !== 1 && screenY > get(0x4ac13c)) drawInteriorPanel(memory, dc, boat);
  if (boat === 0) return;
  if (boatClass < 7 && boatClass !== 4 && screenY > get(0x4a7354) && boat > 0 && boatClass !== 3 && boatClass > 1) {
    select(memory, dc, 0x4aa634);
    dc.moveTo(weighted(px(memory, 3), px(memory, 13)), weighted(py(memory, 3), py(memory, 13)));
    dc.lineTo(avg(px(memory, 4), px(memory, 3)), avg(py(memory, 4), py(memory, 3)));
    dc.lineTo(weighted(px(memory, 3), px(memory, 9)), weighted(py(memory, 3), py(memory, 9)));
  }
  if (boatClass === 4 || get(0x4ac90c) === 1) {
    select(memory, dc, 0x4aa634);
    dc.moveTo(px(memory, 9), py(memory, 9)); dc.lineTo(px(memory, 13), py(memory, 13));
  }
  if (get(0x4ac908) === 1 || get(0x4ac90c) === 1) {
    select(memory, dc, 0x4a4dec);
    const dx = sub32(px(memory, 5), px(memory, 3)), dy = sub32(py(memory, 5), py(memory, 3));
    if (get(0x4ac908) === 1) {
      if (rb(memory, 0x4abb70, boat) === 1) {
        memory.writeI32(0x4aaeb0, add32(idiv32(dx, 2), px(memory, 5)));
        memory.writeI32(0x4ab8c0, add32(sub32(idiv32(dy, 2), heightOffset(memory, height, 0x484d48)), py(memory, 5)));
      }
      if (rb(memory, 0x4abb70, boat) === 0) {
        memory.writeI32(0x4aaeb0, add32(idiv32(dx, 5), px(memory, 5)));
        memory.writeI32(0x4ab8c0, add32(idiv32(dy, 5), py(memory, 5)));
      }
    }
    if (get(0x4ac90c) === 1) {
      memory.writeI32(0x4aaeb0, add32(idiv32(dx, 2), px(memory, 5)));
      memory.writeI32(0x4ab8c0, add32(sub32(idiv32(dy, 2), heightOffset(memory, height, 0x484d48)), py(memory, 5)));
    }
    dc.moveTo(px(memory, 5), py(memory, 5)); dc.lineTo(get(0x4aaeb0), get(0x4ab8c0));
  }
  if (get(0x4ac90c) === 1) {
    const offset = heightOffset(memory, height, 0x484d48);
    for (const [first, second] of [[9, 7], [13, 15]]) {
      const x1 = add32(idiv32(imul32(sub32(px(memory, first), px(memory, 3)), 4), 5), px(memory, first));
      const y1 = add32(sub32(idiv32(imul32(sub32(py(memory, first), py(memory, 3)), 4), 5), offset), py(memory, first));
      const x2 = add32(idiv32(imul32(sub32(px(memory, second), px(memory, 1)), 4), 5), px(memory, second));
      const y2 = add32(sub32(idiv32(imul32(sub32(py(memory, second), py(memory, 1)), 4), 5), offset), py(memory, second));
      dc.moveTo(px(memory, first), py(memory, first)); dc.lineTo(x1, y1); dc.lineTo(x2, y2); dc.lineTo(px(memory, second), py(memory, second));
    }
    select(memory, dc, 0x4aa634);
    dc.moveTo(px(memory, 15), py(memory, 15)); dc.lineTo(px(memory, 7), py(memory, 7));
  }
}

/** Complete 0x419db0, for its initialized native class/selector domain. */
export function drawBoardSurfaces(memory, dc, boat, height, selector, viewHeading, screenY) {
  [boat, selector, viewHeading, screenY] = [boat, selector, viewHeading, screenY].map(i32);
  const get = address => memory.readI32(address);
  if ((boat > get(0x491140) && get(0x4ac928) === 1) || screenY < get(0x4ac13c) || (get(0x491188) !== 7 && selector === 0)) return;
  let depth, sideDepth;
  dc.selectStockObject(7);
  if (get(0x491188) === 7) { depth = heightOffset(memory, height, 0x484d48); sideDepth = idiv32(depth, 2); }
  if (selector === 1 || selector === 2) { depth = heightOffset(memory, height, 0x484f10); sideDepth = heightOffset(memory, height, 0x484d90); }
  const flat = get(0x4ac930) === 1;
  if (flat) { depth = 0; sideDepth = 0; }
  if (depth === undefined) throw new RangeError('Original board-surface depth is uninitialized for this class/selector');
  const leftX = idiv32(add32(imul32(px(memory, 13), 7), imul32(px(memory, 9), 3)), 10);
  const leftY = idiv32(add32(imul32(py(memory, 13), 7), imul32(py(memory, 9), 3)), 10);
  const rightX = idiv32(add32(imul32(px(memory, 9), 7), imul32(px(memory, 13), 3)), 10);
  const rightY = idiv32(add32(imul32(py(memory, 9), 7), imul32(py(memory, 13), 3)), 10);
  const nearX = weighted(px(memory, 14), px(memory, 8), 3, 4), nearY = weighted(py(memory, 14), py(memory, 8), 3, 4);
  const farX = weighted(px(memory, 8), px(memory, 14), 3, 4), farY = weighted(py(memory, 8), py(memory, 14), 3, 4);
  const leftLow = sub32(leftY, sideDepth), rightLow = sub32(rightY, sideDepth);
  const nearLow = sub32(nearY, depth), farLow = sub32(farY, depth);
  // Original common tail always draws this upper surface, even for flat views.
  const finish = () => drawPolygon(memory, dc, [[farX, farLow], [nearX, nearLow], [rightX, rightLow], [leftX, leftLow]], 0);
  if (viewHeading > -20) {
    if (flat) { finish(); return; }
    drawPolygon(memory, dc, [[nearX, nearY], [rightX, rightY], [rightX, rightLow], [nearX, nearLow]], 0);
    if (selector < 5) {
      const midNear = avg(nearLow, nearY), midRight = avg(rightLow, rightY);
      select(memory, dc, 0x4a4dec);
      dc.moveTo(weighted(rightX, nearX), weighted(midRight, midNear));
      dc.lineTo(weighted(nearX, rightX), weighted(midNear, midRight));
    }
    dc.selectStockObject(7);
  }
  if (!flat) {
    if (viewHeading < 20 || viewHeading > 160) {
      drawPolygon(memory, dc, [[farX, farY], [leftX, leftY], [leftX, leftLow], [farX, farLow]], 0);
      if (selector < 5) {
        const midFar = avg(farY, farLow), midLeft = avg(leftY, leftLow);
        select(memory, dc, 0x4a4dec);
        dc.moveTo(weighted(leftX, farX), weighted(midLeft, midFar));
        dc.lineTo(weighted(farX, leftX), weighted(midFar, midLeft));
      }
      dc.selectStockObject(7);
    }
    if (abs32(viewHeading) < 90) {
      drawPolygon(memory, dc, [[farX, farY], [farX, farLow], [nearX, nearLow], [nearX, nearY]], 0);
      if (selector !== 0) { finish(); return; }
      const x1 = weighted(nearX, farX), x2 = weighted(farX, nearX);
      drawPolygon(memory, dc, [[x1, weighted(nearY, farY)], [x1, weighted(nearLow, farLow)],
        [x2, weighted(farLow, nearLow)], [x2, weighted(farY, nearY)]], 4);
    } else drawPolygon(memory, dc, [[leftX, leftY], [leftX, leftLow], [rightX, rightLow], [rightX, rightY]], 0);
  }
  finish();
}

/** Complete 0x4156f0. Continuous x87 intermediates are truncated directly. */
export function drawSailRigging(memory, dc, x, y, otherX, otherY, height) {
  [x, y, otherX, otherY] = [x, y, otherX, otherY].map(i32);
  const get = address => memory.readI32(address);
  const combination = (first, firstFactor, second, secondFactor) => Float80.fromInteger(first).multiply(constant(memory, firstFactor))
    .subtract(Float80.fromInteger(second).multiply(constant(memory, secondFactor))).truncI32();
  const pen = () => select(memory, dc, get(0x4ac92c) === 1 ? 0x4a4ee4 : 0x4a4dec);
  dc.selectStockObject(get(0x4ac92c) === 1 ? 6 : 7);
  if (get(0x491150) < 100) {
    const tipY = sub32(py(memory, 18), heightOffset(memory, height, 0x484d90));
    const bendX = combination(x, 0x484fe8, otherX, 0x484ff0), bendY = combination(y, 0x484fe8, otherY, 0x484ff0);
    dc.moveTo(get(0x4a7640), get(0x4a7750)); dc.lineTo(bendX, bendY); dc.lineTo(x, y);
    pen(); dc.moveTo(px(memory, 18), tipY);
    if (get(0x491188) !== 4 && get(0x4ac900) === 0) dc.lineTo(bendX, bendY);
  }
  if (get(0x491150) === 100) {
    const bendX1 = combination(otherX, 0x485000, x, 0x485008), bendY1 = combination(otherY, 0x485000, y, 0x485008);
    const bendX2 = combination(otherX, 0x485010, x, 0x485018), bendY2 = combination(otherY, 0x485010, y, 0x485018);
    dc.moveTo(get(0x4a7640), get(0x4a7750)); dc.lineTo(bendX2, bendY2); dc.lineTo(bendX1, bendY1); dc.lineTo(x, y);
    pen();
    dc.moveTo(weighted(px(memory, 17), px(memory, 18)), sub32(weighted(py(memory, 17), py(memory, 18)), heightOffset(memory, height, 0x484ff8)));
    dc.lineTo(bendX1, bendY1);
    dc.moveTo(px(memory, 19), sub32(py(memory, 19), heightOffset(memory, height, 0x484da8))); dc.lineTo(bendX2, bendY2);
  }
  dc.selectStockObject(7);
}

/** Complete 0x414d00, including right-of-way throttle and UI state writes. */
export function drawMainsail(memory, dc, height, boat, widthScale, screenY, viewHeading, side, rng) {
  [boat, screenY, viewHeading, side] = [boat, screenY, viewHeading, side].map(i32);
  const get = address => memory.readI32(address), set = (address, value) => memory.writeI32(address, value);
  let effective = heightProduct(memory, height, 0x484fc0).toNumber();
  if (get(0x491188) === 8) effective = heightProduct(memory, effective, 0x484fc8).toNumber();
  if (get(0x4ac900) === 1) effective = heightProduct(memory, effective, 0x484fd0).toNumber();
  if (get(0x4ac914) === 1) effective = heightProduct(memory, effective, 0x484dc0).toNumber();
  const curveDepth = idiv32(heightOffset(memory, widthScale, 0x484fd8), 3);
  const interactive = () => boat <= get(0x491140) && get(0x491188) > 1 && get(0x4ac930) === 0;
  const rigging = left => drawSailRigging(memory, dc, get(left ? 0x4aa598 : 0x4a67a0), get(left ? 0x4aba64 : 0x4aa6fc), get(0x4a76c4), get(0x4a7760), effective);
  if (interactive()) {
    set(0x4a76c4, px(memory, 21)); set(0x4a7760, sub32(py(memory, 21), heightOffset(memory, effective, 0x484fe0)));
    if (get(0x4ac900) === 0) {
      set(0x4aa598, weighted(px(memory, 8), px(memory, 9), 3, 4));
      set(0x4aba64, weighted(py(memory, 8), py(memory, 9), 3, 4));
      set(0x4a67a0, weighted(px(memory, 14), px(memory, 13), 3, 4));
      set(0x4aa6fc, weighted(py(memory, 14), py(memory, 13), 3, 4));
    }
    if (get(0x4ac900) === 1) {
      set(0x4aa598, weighted(px(memory, 7), px(memory, 9), 5, 6));
      set(0x4aba64, weighted(py(memory, 7), py(memory, 9), 5, 6));
      set(0x4a67a0, weighted(px(memory, 16), px(memory, 14), 5, 6));
      set(0x4aa6fc, weighted(py(memory, 16), py(memory, 14), 5, 6));
    }
    if (get(0x491150) === 100) { set(0x4a7640, px(memory, 21)); set(0x4a7750, get(0x4a7760)); }
    else { set(0x4a7640, px(memory, 20)); set(0x4a7750, sub32(py(memory, 20), heightOffset(memory, effective, 0x484ec8))); }
    rigging(get(0x4aa734) !== 1);
  }
  const offsets = [0x484e00, 0x484d90, 0x484da8, 0x484ec8, 0x484fe0].map(factor => heightOffset(memory, effective, factor));
  const values = Array.from({ length: 5 }, (_, index) => [px(memory, 17+index), sub32(py(memory, 17+index), offsets[index])]);
  values.push([px(memory, 22), sub32(sub32(py(memory, 22), curveDepth), offsets[3])],
    [px(memory, 23), sub32(sub32(py(memory, 23), curveDepth), offsets[2])],
    [px(memory, 24), sub32(sub32(py(memory, 24), curveDepth), offsets[1])],
    [px(memory, 25), sub32(sub32(py(memory, 25), curveDepth), offsets[0])]);
  storePolygon(memory, values);
  dc.selectStockObject(7);
  if (get(0x4ac98c) === 0) dc.selectStockObject(0);
  else select(memory, dc, 0x4a70e4);
  if (get(0x4ac92c) === 1) set(0x4ac9bc, 0);
  if (get(0x4ac98c) === 0 && get(0x4ac9bc) === 1) {
    if (boat === 1) select(memory, dc, 0x4a4f7c);
    if (boat === 2) select(memory, dc, 0x4aa98c);
    if (boat >= 11 && boat < 21) select(memory, dc, 0x4a3efc);
    if (boat >= 21) select(memory, dc, 0x4a5afc);
  }
  const humans = get(0x491140);
  if (get(0x4911d0) === 2 && add32(get(0x4911d4), 4) < get(0x4a5b80)) set(0x4911d0, 1);
  const throttleMode = get(0x4911d0);
  const warning = rb(memory, 0x4a4e78, boat), warningAddress = indexed(0x4a6090, boat);
  if (warning === 0 && boat <= humans) set(warningAddress, 0);
  if (warning > 0 && boat <= humans) {
    if (throttleMode === 1 && get(warningAddress) === 0) {
      if (get(0x49116c) > 1) { set(0x491178, get(0x49116c)); set(0x491174, get(0x491170)); }
      set(0x491170, 0xb67); set(0x49116c, 1);
    }
    select(memory, dc, 0x4a3a14); select(memory, dc, 0x4a676c); set(warningAddress, warning);
  }
  if (get(0x4a5b80) < add32(rb(memory, 0x4abf18, boat), get(0x4a7644)) && rb(memory, 0x4a89c0, boat) < 11) dc.selectStockObject(4);
  if (boat === 1 && get(0x4a40c4) === 1) dc.selectStockObject(5);
  if (boat === 2 && get(0x4a40c8) === 1 && get(0x491140) === 2) dc.selectStockObject(5);
  dc.polygon(values.map(([x, y]) => ({ x, y }))); dc.selectStockObject(7);
  if (interactive()) {
    const angle = rb(memory, 0x4a77e8, boat), tack = rb(memory, 0x4aa730, boat);
    if (tack === 1 && sub32(0, add32(angle, 10)) < viewHeading) rigging(true);
    if (tack === -1 && viewHeading < add32(angle, 10)) rigging(false);
    if (tack === -1 && viewHeading === 180) rigging(false);
  }
  if (screenY >= get(0x4a7358) && (boat <= get(0x491140) || get(0x4ac928) !== 1)) {
    dc.selectStockObject(7);
    const random = scaledRandom(10, rng);
    let horizontal = 10, vertical = 10;
    if (rb(memory, 0x4a8aa8, boat) > 10) horizontal = add32(random, 1);
    if (rb(memory, 0x4a8aa8, boat) > 35) { horizontal = sub32(random, 6); vertical = random; }
    for (const [classFactor, first, second, offset] of [[30, 18, 24, offsets[1]], [25, 19, 23, offsets[2]], [20, 20, 22, offsets[3]]]) {
      if (classFactor === 20 && get(0x4ac914) !== 0) continue;
      const width = Float80.fromInteger(sub32(classFactor, get(0x491188))).multiply(Float80.fromNumber(widthScale)).truncI32();
      drawSailCurve(memory, dc, horizontal, vertical, side, width, px(memory, first), sub32(py(memory, first), offset),
        px(memory, second), sub32(sub32(py(memory, second), curveDepth), offset), 6, 2);
    }
  }
}
