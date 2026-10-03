import { add32, sub32, imul32, idiv32, i32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom } from '../engine/integer-core.js';
import { selectSailColor } from './boat-primitives.js';

export const HEADSAIL_ROUTINES = Object.freeze({ drawJib: 0x416ad0, drawSpinnaker: 0x41a5d0 });
const indexed = (base, index) => add32(base, imul32(index, 4)) >>> 0;
const px = (m, index) => m.readI32(indexed(0x4aa1a0, index));
const py = (m, index) => m.readI32(indexed(0x4aa2a0, index));
const rb = (m, base, boat) => m.readI32(indexed(base, boat));
const avg = (left, right) => idiv32(add32(left, right), 2);
const constant = (m, address) => Float80.fromNumber(m.readF64(address));
const product = (m, value, factor) => value.multiply(constant(m, factor));
const offset = (m, value, factor) => product(m, value, factor).truncI32();
function select(memory, dc, address) { const handle = memory.readU32(address); if (handle) dc.selectObject(handle); }
function drawPolygon(memory, dc, points) {
  points.forEach(([x, y], index) => {
    memory.writeI32(0x4a4ca8 + index*8, x); memory.writeI32(0x4a4cac + index*8, y);
  });
  dc.polygon(points.map(([x, y]) => ({ x, y })));
}

/** Complete 0x416ad0; all sail-height scaling remains extended precision. */
export function drawJib(memory, dc, height, boat, _screenY, side) {
  boat = i32(boat); side = i32(side);
  const get = address => memory.readI32(address);
  let effective = product(memory, Float80.fromNumber(height), 0x484fc0);
  if (get(0x491188) === 8) effective = product(memory, effective, 0x484fc8);
  if (get(0x4ac900) === 1) effective = product(memory, effective, 0x484fd0);
  const topIndex = get(0x491150) === 100 ? 21 : 20;
  const topY = sub32(py(memory, topIndex), offset(memory, effective, topIndex === 21 ? 0x484fe0 : 0x484ec8));
  const frontY = sub32(py(memory, 26), offset(memory, effective, 0x485028));
  let curvature = offset(memory, effective, 0x485030);
  if (side === 1) curvature = sub32(0, curvature);
  if (rb(memory, 0x4abb70, boat) === 1 && get(0x491188) === 2 && boat <= get(0x491140) && rb(memory, 0x4a7bc8, boat) < 132) curvature = idiv32(imul32(curvature, -3), 2);
  const curveX = avg(px(memory, 26), px(memory, 5)), curveY = add32(avg(frontY, py(memory, 5)), curvature);
  const catamaranOffset = get(0x4ac900) === 1 ? offset(memory, Float80.fromNumber(height), 0x484db0) : 0;
  const points = [[px(memory, 5), sub32(py(memory, 5), catamaranOffset)],
    [px(memory, topIndex), sub32(topY, catamaranOffset)], [px(memory, 26), frontY], [curveX, curveY]];
  // The original selects objects after preparing the full shared point block.
  points.forEach(([x, y], index) => { memory.writeI32(0x4a4ca8+index*8, x); memory.writeI32(0x4a4cac+index*8, y); });
  dc.selectStockObject(7);
  if (get(0x491188) < 7 || get(0x4ac92c) !== 0 || get(0x491188) > 8) dc.selectStockObject(0);
  else select(memory, dc, 0x4ab17c);
  if (get(0x4ac98c) === 1) select(memory, dc, 0x4a70e4);
  if (boat === 1 && get(0x4a40c4) === 1) dc.selectStockObject(5);
  if (boat === 2 && get(0x4a40c8) === 1 && get(0x491140) === 2) dc.selectStockObject(5);
  dc.polygon(points.map(([x, y]) => ({ x, y })));
}

/** Complete 0x41a5d0, retaining both RNG draws when luff exceeds 30. */
export function drawSpinnaker(memory, dc, height, boat, screenY, side, rng) {
  [boat, screenY, side] = [boat, screenY, side].map(i32);
  const get = address => memory.readI32(address);
  const hasJib = () => get(0x491188) === 3 || get(0x4ac908) === 1 || get(0x4ac900) === 1;
  if (hasJib() && side !== 1) drawJib(memory, dc, height, boat, screenY, side);
  let flutter = 0;
  if (boat <= get(0x491140)) {
    if (rb(memory, 0x4ac5f0, boat) > 10) flutter = add32(scaledRandom(12, rng), 6);
    if (rb(memory, 0x4ac5f0, boat) > 30) flutter = add32(scaledRandom(24, rng), 17);
  }
  let effective, topX, topY;
  const originalHeight = Float80.fromNumber(height);
  if (get(0x491150) === 100 || get(0x491188) === 8 || get(0x4ac908) === 1 || get(0x4ac90c) === 1) {
    effective = product(memory, originalHeight, 0x484fc0);
    topX = px(memory, 21);
    if (get(0x491188) === 8) effective = product(memory, effective, 0x484fc8);
    topY = sub32(py(memory, 21), offset(memory, effective, 0x484fe0));
  } else {
    effective = product(memory, originalHeight, 0x484f58);
    topX = px(memory, 20); topY = sub32(py(memory, 20), offset(memory, originalHeight, 0x485080));
  }
  if (get(0x4ac900) === 1) {
    effective = product(memory, effective, 0x484fd0);
    topY = sub32(py(memory, 20), offset(memory, effective, 0x484fe0));
  }
  const front = get(0x4ac900) === 1 || get(0x4ac908) === 1 || get(0x4ac90c) === 1
    ? [get(0x4aaeb0), get(0x4ab8c0)] : [px(memory, 27), sub32(py(memory, 27), offset(memory, effective, 0x484d48))];
  const halfFlutter = idiv32(flutter, 2);
  const offsets = Object.fromEntries([0x484d90, 0x484da8, 0x484ec8, 0x484d48, 0x485070, 0x484f78].map(factor => [factor, offset(memory, effective, factor)]));
  const p28 = [px(memory, 28), sub32(add32(py(memory, 28), halfFlutter), offsets[0x484d90])];
  const p29 = [px(memory, 29), sub32(add32(flutter, py(memory, 29)), offsets[0x484da8])];
  const p30 = [px(memory, 30), add32(py(memory, 30), sub32(flutter, offsets[0x484ec8]))];
  const p31 = [px(memory, 31), sub32(add32(py(memory, 31), halfFlutter), offsets[0x484d48])];
  const p32 = [px(memory, 32), add32(sub32(py(memory, 32), offsets[0x485070]), halfFlutter)];
  const p33 = [px(memory, 33), add32(sub32(flutter, offsets[0x484f78]), py(memory, 33))];
  const p34 = [px(memory, 34), add32(py(memory, 34), sub32(flutter, offsets[0x484ec8]))];
  const p35 = [px(memory, 35), sub32(py(memory, 35), offsets[0x484d48])];
  const p36 = [px(memory, 36), sub32(py(memory, 36), offsets[0x484d90])];
  const p37 = [px(memory, 37), sub32(py(memory, 37), offsets[0x484da8])];
  const p38 = [px(memory, 38), sub32(py(memory, 38), offsets[0x484ec8])];
  let curve = offset(memory, effective, 0x485030);
  if (side === 0) curve = idiv32(curve, 2);
  const curveLeft = [avg(p33[0], p29[0]), sub32(avg(p29[1], p33[1]), curve)];
  const curveRight = [avg(p37[0], p33[0]), sub32(avg(p37[1], p33[1]), curve)];
  if (get(0x4ac900) === 0 && get(0x4ac908) === 0 && get(0x4ac90c) === 0) {
    if (screenY > get(0x4ac13c)) select(memory, dc, 0x4a4dec);
    else dc.selectStockObject(7);
    dc.moveTo(px(memory, 17), sub32(py(memory, 17), offset(memory, originalHeight, 0x485088))); dc.lineTo(...front);
  }
  selectSailColor(memory, dc, boat); dc.selectStockObject(7);
  const left = [front, p28, p29, p30, [topX, topY], p34, p33, p32, p31];
  const right = [p31, p32, p33, p34, [topX, topY], p38, p37, p36, p35];
  const line = (start, bend) => { select(memory, dc, 0x4a4dec); dc.moveTo(...start); dc.lineTo(...bend); dc.lineTo(...p33); dc.selectStockObject(7); };
  if (side === 1) {
    drawPolygon(memory, dc, right); line(p37, curveRight);
    drawPolygon(memory, dc, left); line(p29, curveLeft);
  } else {
    dc.selectStockObject(7); drawPolygon(memory, dc, left); line(p29, curveLeft);
    drawPolygon(memory, dc, right); line(p37, curveRight);
  }
  if (hasJib()) {
    if (side === 1) drawJib(memory, dc, height, boat, screenY, 1);
    if (get(0x491188) === 3 && get(0x4ac90c) === 0 && side === 1) {
      if (screenY > get(0x4ac13c)) select(memory, dc, 0x4a4dec);
      else dc.selectStockObject(7);
      dc.moveTo(px(memory, 17), sub32(py(memory, 17), offset(memory, originalHeight, 0x485088))); dc.lineTo(...front);
    }
  }
}
