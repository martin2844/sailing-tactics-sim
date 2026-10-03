import { add32, sub32, imul32, idiv32, i32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom, wrapDegreesOnce } from '../engine/integer-core.js';
import { selectBoatColor, drawWakePoint } from './boat-primitives.js';

export const BOAT_PANEL_ROUTINES = Object.freeze({
  drawEllipseMarker: 0x423640,
  drawHullPortSide: 0x415de0, drawHullStarboardSide: 0x416070,
  drawHullStern: 0x416300,
  drawWakeSegment: 0x417eb0,
  drawStarboardInnerPanel: 0x417d30, drawStarboardOuterPanel: 0x417fb0,
  drawPortInnerPanel: 0x418890, drawPortOuterPanel: 0x418a10,
  drawCatamaranCrossbar: 0x418580,
  drawWakeBurst: 0x419ca0, drawSideSpray: 0x419b40,
  drawRudder: 0x4194b0, drawCatamaranRudders: 0x419640,
  drawSteeringArc: 0x4198f0, drawTelltale: 0x417570,
});

const X = 0x4aa1a0, Y = 0x4aa2a0, POLYGON = 0x4a4ca8;
const indexed = (base, index) => add32(base, imul32(index, 4)) >>> 0;
const px = (memory, index) => memory.readI32(indexed(X, index));
const py = (memory, index) => memory.readI32(indexed(Y, index));
const rb = (memory, address, boat) => memory.readI32(indexed(address, boat));
const abs32 = value => value < 0 ? sub32(0, value) : value;
const scaledHeight = (memory, height, factor) => Float80.fromNumber(height).multiply(Float80.fromNumber(memory.readF64(factor))).truncI32();
const weighted = (first, second, factor = 2, divisor = 3) => idiv32(add32(first, imul32(second, factor)), divisor);
function select(memory, dc, address) {
  const handle = memory.readU32(address);
  if (handle !== 0) dc.selectObject(handle);
}
function polygon(memory, dc, values) {
  values.forEach((point, index) => {
    memory.writeI32(POLYGON + index * 8, point[0]);
    memory.writeI32(POLYGON + index * 8 + 4, point[1]);
  });
  dc.polygon(values.map(point => ({ x: point[0], y: point[1] })));
}

/** Complete 0x423640. */
export function drawEllipseMarker(_memory, dc, radius, x, y) {
  radius = i32(radius); x = i32(x); y = i32(y);
  dc.ellipse(sub32(x, radius), sub32(y, radius), add32(x, radius), add32(y, radius));
}

function hullSide(memory, dc, height, style, boat, port) {
  style = i32(style); boat = i32(boat);
  dc.selectStockObject(8);
  selectBoatColor(memory, dc, boat);
  let depth = scaledHeight(memory, height, 0x484da8);
  if (style === 1) depth = idiv32(imul32(depth, 3), 2);
  const inner = port ? 8 : 14, outer = port ? 9 : 13;
  const x1 = weighted(px(memory, 2), px(memory, inner));
  const y1 = add32(weighted(py(memory, 2), py(memory, inner)), depth);
  const x2 = weighted(px(memory, 3), px(memory, outer));
  const y2 = add32(weighted(py(memory, 3), py(memory, outer)), depth);
  polygon(memory, dc, [[px(memory, port ? 6 : 16), py(memory, port ? 6 : 16)],
    [px(memory, port ? 7 : 15), py(memory, port ? 7 : 15)],
    [px(memory, inner), py(memory, inner)], [x1, y1],
    [memory.readI32(port ? 0x4a4380 : 0x4a4384), memory.readI32(port ? 0x4a6784 : 0x4a6788)]]);
  polygon(memory, dc, [[px(memory, inner), py(memory, inner)],
    [px(memory, outer), py(memory, outer)], [x2, y2], [x1, y1]]);
  polygon(memory, dc, [[px(memory, outer), py(memory, outer)],
    [px(memory, port ? 10 : 12), py(memory, port ? 10 : 12)],
    [px(memory, 5), py(memory, 5)], [memory.readI32(0x4ac838), memory.readI32(0x4a3f88)], [x2, y2]]);
  if (memory.readI32(0x4ac98c) === 1 && boat > 0 && memory.readI32(0x4ac92c) === 0) {
    select(memory, dc, port ? 0x4aa98c : 0x4a3a14);
    select(memory, dc, port ? 0x4a39fc : 0x4a676c);
    drawEllipseMarker(memory, dc, 2, px(memory, 5), py(memory, 5));
  }
}

/** Complete 0x415de0. */
export function drawHullPortSide(memory, dc, height, style, boat) { hullSide(memory, dc, height, style, boat, true); }
/** Complete 0x416070. */
export function drawHullStarboardSide(memory, dc, height, style, boat) { hullSide(memory, dc, height, style, boat, false); }

/** Complete 0x416300; the height argument is intentionally unused. */
export function drawHullStern(memory, dc, _height, boat, style, screenY) {
  boat = i32(boat); style = i32(style); screenY = i32(screenY);
  selectBoatColor(memory, dc, boat);
  polygon(memory, { polygon: () => {} }, [[px(memory, 16), py(memory, 16)], [px(memory, 6), py(memory, 6)],
    [memory.readI32(0x4a4380), memory.readI32(0x4a6784)],
    [memory.readI32(0x4a437c), memory.readI32(0x4a678c)],
    [memory.readI32(0x4a4384), memory.readI32(0x4a6788)]]);
  dc.selectStockObject(7);
  dc.polygon(Array.from({ length: 5 }, (_, index) => ({ x: memory.readI32(POLYGON + index * 8), y: memory.readI32(POLYGON + index * 8 + 4) })));
  if (memory.readI32(0x491188) < 6 && screenY > memory.readI32(0x4ac13c) && style === 0 && memory.readI32(0x4ac904) === 0) {
    select(memory, dc, 0x4a4dec);
    dc.moveTo(px(memory, 0), py(memory, 0));
    dc.lineTo(memory.readI32(0x4a437c), memory.readI32(0x4a678c));
  }
}

/** Complete 0x417eb0: one RNG draw and the original weighted endpoint. */
export function drawWakeSegment(memory, dc, height, x, y, pixelIndex, screenY, rng) {
  [x, y, pixelIndex, screenY] = [x, y, pixelIndex, screenY].map(i32);
  const offset = scaledHeight(memory, height, 0x484e30);
  let endX, endY;
  if (scaledRandom(10, rng) < 5) {
    endX = idiv32(add32(px(memory, pixelIndex), x), 2);
    endY = idiv32(add32(add32(py(memory, pixelIndex), offset), y), 2);
  } else {
    endX = weighted(px(memory, pixelIndex), x);
    endY = idiv32(add32(add32(py(memory, pixelIndex), imul32(y, 2)), offset), 3);
  }
  select(memory, dc, screenY > memory.readI32(0x4a7354) ? 0x4a46a4 : 0x4a4ee4);
  dc.moveTo(x, y); dc.lineTo(endX, endY); dc.selectStockObject(7);
}

function raisedPanel(memory, dc, height, boat, screenY, rng, { center, neighbor1, neighbor2, tip, wakeIndex, tack }) {
  boat = i32(boat); screenY = i32(screenY);
  dc.selectStockObject(8); selectBoatColor(memory, dc, boat);
  const x = idiv32(add32(add32(px(memory, neighbor1), imul32(px(memory, center), 12)), px(memory, neighbor2)), 14);
  const y = sub32(idiv32(add32(add32(py(memory, neighbor1), imul32(py(memory, center), 12)), py(memory, neighbor2)), 14), scaledHeight(memory, height, 0x485038));
  polygon(memory, dc, [[px(memory, center), py(memory, center)], [x, y],
    [px(memory, wakeIndex), sub32(py(memory, wakeIndex), scaledHeight(memory, height, 0x485040))],
    [px(memory, tip), sub32(py(memory, tip), scaledHeight(memory, height, 0x485048))],
    [px(memory, tip), py(memory, tip)], [px(memory, wakeIndex), py(memory, wakeIndex)]]);
  if ((rb(memory, 0x4aa730, boat) !== tack || rb(memory, 0x4a6ec8, boat) < 8) && rb(memory, 0x4a7060, boat) > 40) {
    drawWakeSegment(memory, dc, height, x, y, wakeIndex, screenY, rng);
  }
}

/** Complete 0x417d30. */
export function drawStarboardInnerPanel(memory, dc, height, boat, screenY, rng) {
  raisedPanel(memory, dc, height, boat, screenY, rng, { center: 12, neighbor1: 13, neighbor2: 14, tip: 15, wakeIndex: 13, tack: -1 });
}
/** Complete 0x417fb0. */
export function drawStarboardOuterPanel(memory, dc, height, boat, screenY, rng) {
  raisedPanel(memory, dc, height, boat, screenY, rng, { center: 12, neighbor1: 13, neighbor2: 14, tip: 16, wakeIndex: 14, tack: -1 });
}
/** Complete 0x418890. */
export function drawPortInnerPanel(memory, dc, height, boat, screenY, rng) {
  raisedPanel(memory, dc, height, boat, screenY, rng, { center: 10, neighbor1: 8, neighbor2: 9, tip: 6, wakeIndex: 8, tack: 1 });
}
/** Complete 0x418a10. */
export function drawPortOuterPanel(memory, dc, height, boat, screenY, rng) {
  raisedPanel(memory, dc, height, boat, screenY, rng, { center: 10, neighbor1: 8, neighbor2: 9, tip: 7, wakeIndex: 9, tack: 1 });
}

/** Complete 0x418580, including scratch geometry written for the later sail. */
export function drawCatamaranCrossbar(memory, dc, height, perspective) {
  const pair = (first, second) => [weighted(px(memory, first), px(memory, second)), weighted(py(memory, first), py(memory, second))];
  polygon(memory, { polygon: () => {} }, [[px(memory, 13), py(memory, 13)], [px(memory, 8), py(memory, 8)], pair(8, 6), pair(13, 15)]);
  const [x1, y1] = pair(9, 7), [x2, y2] = pair(14, 16);
  select(memory, dc, 0x4a3efc);
  dc.polygon(Array.from({ length: 4 }, (_, index) => ({ x: memory.readI32(POLYGON + index * 8), y: memory.readI32(POLYGON + index * 8 + 4) })));
  select(memory, dc, perspective <= memory.readF64(0x484ec8) ? 0x4a71bc : 0x4aa634);
  dc.moveTo(px(memory, 9), py(memory, 9)); dc.lineTo(px(memory, 14), py(memory, 14));
  dc.moveTo(x1, y1); dc.lineTo(x2, y2);
  memory.writeI32(0x4a4880, x1); memory.writeI32(0x4a4884, y2);
  memory.writeI32(0x4a4950, x2); memory.writeI32(0x4a4df0, y1);
  dc.selectStockObject(7);
  dc.moveTo(px(memory, 12), py(memory, 12));
  dc.lineTo(px(memory, 5), sub32(py(memory, 5), scaledHeight(memory, height, 0x484d48)));
  dc.lineTo(px(memory, 10), py(memory, 10));
  if (memory.readI32(0x491188) === 10) {
    const offset = scaledHeight(memory, height, 0x484db0);
    const x = add32(idiv32(sub32(px(memory, 5), px(memory, 3)), 3), px(memory, 5));
    const y = add32(sub32(idiv32(sub32(sub32(py(memory, 5), offset), py(memory, 3)), 3), offset), py(memory, 5));
    memory.writeI32(0x4aaeb0, x); memory.writeI32(0x4ab8c0, y);
    dc.moveTo(px(memory, 3), py(memory, 3)); dc.lineTo(x, y);
  }
}

/** Complete 0x419ca0. Each pixel consumes X then Y draws. */
export function drawWakeBurst(memory, dc, boat, height, x, y, rng) {
  [boat, x, y] = [boat, x, y].map(i32);
  select(memory, dc, 0x4a4ee4);
  const range = scaledHeight(memory, height, 0x484f10);
  for (let index = 1; index < idiv32(rb(memory, 0x4a7060, boat), 8); index = add32(index, 1)) {
    const dx = scaledRandom(range, rng), dy = scaledRandom(range, rng);
    drawWakePoint(memory, dc, add32(dx, sub32(x, idiv32(range, 2))), add32(dy, y), 0);
  }
}

/** Complete 0x419b40. Original order is Y RNG draw followed by X. */
export function drawSideSpray(memory, dc, boat, height, tackSelector, screenY, viewHeading, rng) {
  [boat, tackSelector, screenY, viewHeading] = [boat, tackSelector, screenY, viewHeading].map(i32);
  if (screenY <= memory.readI32(0x4a7354) && boat > 1) return;
  if (imul32(boat, memory.readI32(0x4ac928)) > 1) return;
  const point = tackSelector === 1 ? 13 : 9;
  select(memory, dc, screenY > memory.readI32(0x4a7354) ? 0x4a46a4 : 0x4a4ee4);
  let range = scaledHeight(memory, height, abs32(viewHeading) < 15 ? 0x485070 : 0x484db0);
  let count;
  if (memory.readI32(0x4a5b7c) < 1) count = 5;
  else { count = 2; range = idiv32(range, 2); }
  const heightOffset = scaledHeight(memory, height, 0x485078);
  for (; count !== 0; count--) {
    dc.moveTo(memory.readI32(0x4ac838), sub32(memory.readI32(0x4a3f88), 1));
    const y = add32(scaledRandom(range, rng), sub32(sub32(py(memory, point), idiv32(range, 2)), heightOffset));
    const x = add32(scaledRandom(range, rng), sub32(px(memory, point), idiv32(range, 2)));
    dc.lineTo(x, y);
  }
}

/** Complete 0x419640. */
export function drawCatamaranRudders(memory, dc, _height, boat) {
  boat = i32(boat);
  const rudder = memory.readI32(0x4a7044);
  const strength = boat < 2 ? abs32(idiv32(rudder, 2)) : 0;
  const ends = [];
  for (let side = 1; side < 3; side++) {
    const first = side === 1 ? 6 : 16, second = side === 1 ? 7 : 15;
    const third = side === 1 ? 9 : 13, fourth = side === 1 ? 8 : 14;
    const x1 = weighted(px(memory, third), px(memory, second), 3, 4);
    const y1 = weighted(py(memory, third), py(memory, second), 3, 4);
    const x2 = weighted(px(memory, fourth), px(memory, first), 3, 4);
    const y2 = weighted(py(memory, fourth), py(memory, first), 3, 4);
    const centerX = idiv32(add32(x2, x1), 2), centerY = idiv32(add32(y2, y1), 2);
    const x = idiv32(add32(imul32(rudder < 1 ? x1 : x2, strength), centerX), add32(strength, 1));
    const y = idiv32(add32(imul32(rudder < 1 ? y1 : y2, strength), centerY), add32(strength, 1));
    ends.push([x, y]);
    select(memory, dc, 0x4a4dec);
    dc.moveTo(idiv32(add32(px(memory, first), px(memory, second)), 2), idiv32(add32(py(memory, first), py(memory, second)), 2));
    dc.lineTo(x, y);
  }
  dc.moveTo(...ends[0]); dc.lineTo(...ends[1]);
  memory.writeI32(0x4aa708, idiv32(add32(ends[0][0], ends[1][0]), 2));
  memory.writeI32(0x4abe68, idiv32(add32(ends[0][1], ends[1][1]), 2));
  dc.selectStockObject(7);
}

/** Complete 0x4194b0, including the catamaran subcall. */
export function drawRudder(memory, dc, height, boat, screenY) {
  boat = i32(boat); screenY = i32(screenY);
  if (memory.readI32(0x4ac904) === 1 || screenY <= memory.readI32(0x4ac13c) || imul32(boat, memory.readI32(0x4ac928)) >= 2) return;
  if (memory.readI32(0x4ac900) === 1) { drawCatamaranRudders(memory, dc, height, boat); return; }
  const rudder = memory.readI32(0x4a7044);
  const strength = boat < 2 ? abs32(idiv32(rudder, 2)) : 0;
  const point = rudder < 1 ? 7 : 15;
  const x = idiv32(add32(imul32(idiv32(add32(px(memory, point), px(memory, 1)), 2), strength), px(memory, 1)), add32(strength, 1));
  const y = idiv32(add32(imul32(idiv32(add32(py(memory, point), py(memory, 1)), 2), strength), py(memory, 1)), add32(strength, 1));
  memory.writeI32(0x4aa708, x); memory.writeI32(0x4abe68, y);
  select(memory, dc, 0x4a4dec);
  dc.moveTo(px(memory, 0), py(memory, 0)); dc.lineTo(x, y); dc.selectStockObject(7);
}

/** Complete 0x4198f0, with the original startup integer trig lookup. */
export function drawSteeringArc(memory, dc, height, boat, side, viewHeading, screenY) {
  [boat, side, viewHeading, screenY] = [boat, side, viewHeading, screenY].map(i32);
  if (screenY <= memory.readI32(0x4ac13c) || imul32(boat, memory.readI32(0x4ac928)) >= 2) return;
  const heading = wrapDegreesOnce(viewHeading);
  if (screenY > memory.readI32(0x4a7354)) select(memory, dc, 0x4a4dec);
  else dc.selectStockObject(7);
  const radius = sub32(1, scaledHeight(memory, height, 0x485068));
  let x = side, y = side;
  if (side === 0) { x = px(memory, 1); y = sub32(py(memory, 1), idiv32(radius, 2)); }
  if (side === 1) { x = idiv32(add32(px(memory, 1), px(memory, 15)), 2); y = sub32(idiv32(add32(py(memory, 15), py(memory, 1)), 2), idiv32(radius, 2)); }
  if (side === -1) { x = idiv32(add32(px(memory, 7), px(memory, 1)), 2); y = sub32(idiv32(add32(py(memory, 1), py(memory, 7)), 2), idiv32(radius, 2)); }
  const cosine = rb(memory, 0x4a3450, heading);
  const horizontalRadius = idiv32(imul32(radius, cosine), 100);
  const startX = sub32(x, radius), startY = sub32(y, radius);
  dc.arc(sub32(x, horizontalRadius), startY, add32(x, horizontalRadius), add32(y, radius), startX, startY, startX, startY);
  let angle;
  if (boat === 1) angle = sub32(imul32(memory.readI32(0x4a7044), -2), idiv32(imul32(memory.readI32(0x4a6ecc), memory.readI32(0x4aa734)), 2));
  else angle = sub32(0, idiv32(imul32(rb(memory, 0x4aa730, boat), rb(memory, 0x4a6ec8, boat)), 2));
  angle = wrapDegreesOnce(angle);
  const endX = add32(idiv32(imul32(abs32(cosine), idiv32(imul32(rb(memory, 0x4a54a0, angle), radius), 100)), 100), x);
  const endY = sub32(y, idiv32(imul32(rb(memory, 0x4a3450, angle), radius), 100));
  dc.moveTo(x, y); dc.lineTo(endX, endY); dc.selectStockObject(7);
}

/** Complete 0x417570; alternate colors use the original ellipse instead. */
export function drawTelltale(memory, dc, x, y, boat, viewHeading, screenY, colorSelector, rng) {
  [x, y, boat, viewHeading, screenY, colorSelector] = [x, y, boat, viewHeading, screenY, colorSelector].map(i32);
  if (memory.readI32(0x4ac98c) === 1) {
    dc.selectStockObject(6); dc.selectStockObject(0);
    drawEllipseMarker(memory, dc, 2, x, sub32(y, 1));
    return;
  }
  if (memory.readI32(0x4ac92c) !== 0) select(memory, dc, 0x4a4ee4);
  else {
    select(memory, dc, boat % 2 === 0 ? 0x4a39fc : 0x4a676c);
    if (colorSelector === 1) select(memory, dc, 0x4a4374);
    if (colorSelector === 2) select(memory, dc, 0x4a676c);
  }
  const tackAngle = idiv32(imul32(imul32(rb(memory, 0x4aa730, boat), rb(memory, 0x4a7bc8, boat)), 2), 3);
  const random = scaledRandom(20, rng);
  const angle = wrapDegreesOnce(wrapDegreesOnce(add32(sub32(sub32(sub32(0, tackAngle), viewHeading), 10), random)));
  let length = idiv32(screenY, 15);
  if (rb(memory, 0x4a4e88, boat) === 3 || memory.readI32(0x4ac980) > 500) length = idiv32(imul32(length, 2), 3);
  dc.moveTo(x, y);
  dc.lineTo(add32(idiv32(imul32(length, rb(memory, 0x4a54a0, angle)), 100), x),
    add32(idiv32(imul32(length, rb(memory, 0x4a3450, angle)), 300), y));
}
