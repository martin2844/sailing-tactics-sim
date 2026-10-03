import { add32, sub32, imul32, idiv32, i32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { projectScenePoint } from './projection.js';
import { drawLaylines } from './chart-details.js';
import { drawBoat } from './boat.js';

export const SCENE_OBJECT_ROUTINES = Object.freeze({
  selectNearestSceneObject: 0x42cd00, sortSceneDepths: 0x42cca0,
  prepareStartBuoy: 0x42cf50, drawSceneMark: 0x42cd40,
  drawSceneStartLine: 0x42c550, drawSceneObjects: 0x42c7b0,
});
const indexed = (base, index, stride = 4) => add32(base, imul32(index, stride)) >>> 0;
const rb = (memory, base, index) => memory.readI32(indexed(base, index));
const f = (memory, address) => Float80.fromNumber(memory.readF64(address));
const integer = value => Float80.fromInteger(value);
function select(memory, dc, address) { const handle = memory.readU32(address); if (handle) dc.selectObject(handle); }

/** Complete 0x42cd00. A scan with no value below the threshold retains its prior output slot. */
export function selectNearestSceneObject(memory, rank, count, threshold) {
  [rank, count, threshold] = [rank, count, threshold].map(i32);
  for (let object = 1; object <= count; object++) {
    const depth = rb(memory, 0x4a6db0, object);
    if (depth < threshold) { memory.writeI32(indexed(0x4a4438, rank), object); threshold = depth; }
  }
}

/** Complete 0x42cca0, including the destructive 20000 sentinel writes. */
export function sortSceneDepths(memory, selector) {
  selector = i32(selector);
  let count = memory.readI32(0x49118c);
  if (selector === 0) count = add32(count, 5);
  for (let rank = 1; rank <= count; rank++) {
    selectNearestSceneObject(memory, rank, count, 19000);
    memory.writeI32(indexed(0x4a6db0, rb(memory, 0x4a4438, rank)), 20000);
  }
}

/** Complete 0x42cf50: the start buoy borrows player one's local wind heading. */
export function prepareStartBuoy(memory) {
  memory.writeI32(0x4a6ec8, 0); memory.writeI32(0x4ac018, memory.readI32(0x4aa5b4)); memory.writeI32(0x4aa730, 1);
}

/** Complete 0x42cd40, with unspilled x87 sizing before the I32 conversion. */
export function drawSceneMark(memory, dc, x, y, mark, camera) {
  [x, y, mark, camera] = [x, y, mark, camera].map(i32);
  const get = address => memory.readI32(address), horizon = get(0x491148);
  if (get(0x491194) === 8 && y < idiv32(imul32(horizon, 3), 2)) return;
  if (get(0x4ac98c) === 1 && y < imul32(horizon, 2)) return;
  const view = rb(memory, 0x4a4e88, camera);
  let size = f(memory, 0x484eb8);
  if (view < 3) size = integer(sub32(y, horizon)).multiply(f(memory, view === 2 ? 0x484f48 : 0x485270))
    .divide(integer(sub32(get(0x4a72d0), horizon))).subtract(f(memory, 0x485278));
  const radius = size.truncI32();
  if (get(0x4ac92c) === 1) { dc.selectStockObject(6); dc.selectStockObject(0); }
  else if (mark === 3 || mark === 5) { select(memory, dc, 0x4a3a14); select(memory, dc, 0x4a676c); }
  else { select(memory, dc, 0x4a6234); select(memory, dc, 0x4a67ac); }
  if (get(0x4ac98c) === 1) { dc.selectStockObject(4); select(memory, dc, 0x4a4dec); }
  const half = idiv32(radius, 2);
  const values = [[sub32(x, radius), y], [x, sub32(y, imul32(view !== 3 ? 2 : 1, radius))],
    [add32(x, radius), y], [add32(x, half), add32(y, half)], [sub32(x, half), add32(y, half)]];
  for (const [index, [px, py]] of values.entries()) { memory.writeI32(0x4a4ca8 + index*8, px); memory.writeI32(0x4a4cac + index*8, py); }
  dc.polygon(values.map(([x, y]) => ({ x, y })));
}

/** Complete 0x42c550: projected ten-part start line, with the native visibility tests. */
export function drawSceneStartLine(memory, dc, left, right, bottom, camera, options = {}) {
  [left, right, bottom, camera] = [left, right, bottom, camera].map(i32);
  const get = address => memory.readI32(address);
  dc.selectStockObject(7);
  const reverse = get(0x4aaa50) < get(0x4aaa4c);
  dc.moveTo(get(reverse ? 0x4a7c50 : 0x4a7c4c), get(reverse ? 0x4aaa50 : 0x4aaa4c));
  const limit = sub32(bottom, idiv32(bottom, 20));
  const xa = reverse ? 0x4aa594 : 0x4a70f8, xb = reverse ? 0x4a70f8 : 0x4aa594;
  const ya = reverse ? 0x4aa59c : 0x4a72c8, yb = reverse ? 0x4a72c8 : 0x4aa59c;
  for (let first = 1, second = 9; second >= 0; first++, second--) {
    const x = integer(get(xa)).multiply(integer(first)).add(integer(get(xb)).multiply(integer(second))).multiply(f(memory, 0x484d48)).toNumber();
    const y = integer(get(ya)).multiply(integer(first)).add(integer(get(yb)).multiply(integer(second))).multiply(f(memory, 0x484d48)).toNumber();
    projectScenePoint(memory, 0, x, y, camera, 0, options);
    if (get(0x4aaa48) < limit && left < get(0x4a7c48) && get(0x4a7c48) < right) dc.lineTo(get(0x4a7c48), get(0x4aaa48));
  }
  const finalX = reverse ? 0x4a7c4c : 0x4a7c50, finalY = reverse ? 0x4aaa4c : 0x4aaa50;
  if (get(finalY) < limit && left < get(finalX) && get(finalX) < right) dc.lineTo(get(finalX), get(finalY));
}

/** Complete 0x42c7b0: projection, depth order, laylines and explicit GetPixel occlusion. */
export function drawSceneObjects(memory, dc, camera, left, _top, right, bottom, sceneTop, rng, options = {}) {
  [camera, left, _top, right, bottom, sceneTop] = [camera, left, _top, right, bottom, sceneTop].map(i32);
  const get = address => memory.readI32(address);
  for (let object = 1; object <= add32(get(0x49118c), 5); object++) {
    projectScenePoint(memory, object, memory.readF64(indexed(0x4a52f0, object, 8)), memory.readF64(indexed(0x4a60b0, object, 8)), camera, 0, options);
    memory.writeI32(indexed(0x4a6db0, object), rb(memory, 0x4aaa48, object));
  }
  sortSceneDepths(memory, 0);
  if (get(0x4a5b80) < 1) drawSceneStartLine(memory, dc, left, right, bottom, camera, options);
  select(memory, dc, 0x4a71bc);
  dc.moveTo(get(camera === 1 ? 0x4a7c60 : 0x4a7c64), get(camera === 1 ? 0x4aaa60 : 0x4aaa64));
  dc.lineTo(rb(memory, 0x4a7c48, get(0x4aa7e0)), rb(memory, 0x4aaa48, get(0x4aa7e0)));
  for (let rank = 1; rank <= add32(get(0x49118c), 5); rank++) {
    const object = rb(memory, 0x4a4438, rank);
    const x = rb(memory, 0x4a7c48, object), y = rb(memory, 0x4aaa48, object);
    if (dc.getPixel(x, add32(y, 1)) === 0x8000 || dc.getPixel(x, add32(y, 2)) === 0x8000) continue;
    if (get(0x49117c) === 1) {
      const leg = rb(memory, 0x4a6ba0, camera), angle = rb(memory, 0x4a7bc8, camera), gybe = rb(memory, 0x4a5f10, camera);
      const layline = selector => drawLaylines(memory, dc, x, y, selector, camera, 0, object, options);
      if (object === 3 && leg === 1) { if (angle < add32(get(0x4a4eb0), 10)) layline(1); if (sub32(165, gybe) < angle && get(0x491194) === 8) layline(2); }
      if (object === 4 && leg === 2) { if (angle < add32(get(0x4a4eb0), 10)) layline(1); if (sub32(165, gybe) < angle) layline(2); }
      if (object === 5 && leg === 3 && get(0x491160) === 0) { if (angle < add32(get(0x4a4eb0), 10)) layline(1); if (sub32(165, gybe) < angle) layline(2); }
      if (object === 5 && leg === 3 && get(0x491160) === 1 && get(0x49118c) > 14) { if (angle < get(0x4a4eb0)) layline(1); if (sub32(165, gybe) < angle) layline(2); }
      if (object === 2 && leg === 0 && angle < 90) layline(get(0x4ac9a8) === 1 ? 5 : 4);
      if (object === 1 && leg === 0 && angle < 90) layline(get(0x4ac9a8) === 1 ? 4 : 5);
    }
    if (!(x < right && left < x && y <= bottom)) continue;
    if (object < 6) {
      if (object === 2) { prepareStartBuoy(memory); drawBoat(memory, dc, x, y, 0, camera, bottom, sceneTop, rng, options); }
      else drawSceneMark(memory, dc, x, y, object, camera);
    } else drawBoat(memory, dc, x, y, sub32(object, 5), camera, bottom, sceneTop, rng, options);
  }
}
