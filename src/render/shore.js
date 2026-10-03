import { add32, sub32, imul32, idiv32, i32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { atan2Extended } from '../runtime/atan.js';
import { wrapDegreesOnce } from '../engine/integer-core.js';
import { targetRelativeBearing } from '../engine/target-bearing.js';
import { sampleCurrent } from '../engine/current.js';
import { displayedTargetMark, formatInteger, readAnsiString } from '../engine/hud-state.js';
import { projectScenePoint } from './projection.js';
import { drawAlternateShore } from './chart-terrain.js';
import { drawEllipseMarker } from './boat-panels.js';

export const SHORE_ROUTINES = Object.freeze({
  drawProjectedShoreline: 0x42d120, drawShoreSegment: 0x42d8a0,
  drawShoreMarker: 0x42e190, drawHarborHouse: 0x42e550,
  drawHarborBuilding: 0x42e750, drawShoreBuilding: 0x42e870,
  drawShoreHouse: 0x42e970, drawLighthouse: 0x42eb40,
  drawHeadingIndicator: 0x42ede0, drawSceneLayline: 0x42f0d0,
});
const integer = value => Float80.fromInteger(value);
const f = (memory, address) => Float80.fromNumber(memory.readF64(address));
const indexed = (base, index, stride = 4) => add32(base, imul32(index, stride)) >>> 0;
const abs32 = value => value < 0 ? sub32(0, value) : value;
function select(memory, dc, address) { const handle = memory.readU32(address); if (handle) dc.selectObject(handle); }
function polygon(memory, dc, points) {
  for (const [index, [x, y]] of points.entries()) {
    memory.writeI32(0x4a4ca8 + index * 8, x); memory.writeI32(0x4a4cac + index * 8, y);
  }
  dc.polygon(points.map(([x, y]) => ({ x, y })));
}
function stackInteger(options, field) {
  const value = options.shorelineStack?.[field];
  if (!Number.isInteger(value)) throw new RangeError(`Original shoreline requires captured retained stack value ${field}`);
  return i32(value);
}

/** Complete 0x42d8a0. GetPixel inputs are observations supplied by the DC. */
export function drawShoreSegment(memory, dc, x1, y1, x2, y2, fillBottom, endpointIndex,
  left, _top, right, bottom, waterLine, centerProjectedY, options = {}) {
  [x1, y1, x2, y2, fillBottom, endpointIndex, left, _top, right, bottom, waterLine] =
    [x1, y1, x2, y2, fillBottom, endpointIndex, left, _top, right, bottom, waterLine].map(i32);
  const get = address => memory.readI32(address), island = get(0x4a5a4c);
  let angle = y1;
  if (get(0x4a864c) === 1) angle = wrapDegreesOnce(sub32(imul32(get(0x4aa804), 90), 90));
  if (get(0x4a864c) === 0) {
    angle = wrapDegreesOnce((options.atan2 ?? atan2Extended)(
      integer(sub32(get(indexed(0x4a6490, endpointIndex)), get(0x4ac284))),
      integer(sub32(get(0x4a3a08), get(indexed(0x4a68c8, endpointIndex)))))
      .multiply(f(memory, 0x484d78)).truncI32());
    if (island === 1) angle = wrapDegreesOnce(wrapDegreesOnce(add32(angle, 180)));
  }
  const relative = wrapDegreesOnce(sub32(get(0x4ac840), angle));
  let grade = relative < 90 || relative > 270 ? 1 : 0;
  if (relative < 75 || relative > 285) grade = 2;
  if (relative < 60 || relative > 300) grade = 3;
  if (island === 1) {
    if (!Number.isInteger(centerProjectedY)) throw new RangeError('Original shoreline centerProjectedY stack input is required');
    centerProjectedY = i32(centerProjectedY);
    if (y1 < centerProjectedY && y2 < centerProjectedY) return;
  }
  if ((x1 < left && x2 < left) || (right < x1 && right < x2) || (y1 <= waterLine && y2 <= waterLine)) return;
  const course = get(0x491194);
  if (course === 2 && endpointIndex > 17) return;
  if (course === 4 && endpointIndex < 19) return;
  if (course === 11 && (endpointIndex > 35 || endpointIndex < 2 || (endpointIndex > 13 && endpointIndex < 20))) return;
  if (get(0x4a5b9c) === 1 && ((endpointIndex > 6 && endpointIndex < 12) || (endpointIndex > 24 && endpointIndex < 30))) return;
  if (bottom < y1 && bottom < y2) return;
  if (dc.getPixel(x1, add32(y1, 2)) === 0x8000 || dc.getPixel(x2, add32(y2, 2)) === 0x8000
    || dc.getPixel(x1, add32(y1, 1)) === 0x8000 || dc.getPixel(x2, add32(y2, 1)) === 0x8000) return;
  const denominator = imul32(sub32(bottom, waterLine), sub32(3, get(0x4ac1e0)));
  const h1 = add32(idiv32(imul32(get(indexed(0x4a9450, endpointIndex)), sub32(y1, waterLine)), denominator), 1);
  const h2 = add32(idiv32(imul32(get(indexed(0x4a9454, endpointIndex)), sub32(y2, waterLine)), denominator), 1);
  if (island === 0) {
    if (get(0x4ac92c) === 0 && get(0x4ac98c) === 0) { dc.selectStockObject(8); select(memory, dc, 0x4a621c); }
    else { select(memory, dc, 0x4a71bc); select(memory, dc, 0x4a70e4); }
    if (get(0x4ac98c) === 1) { dc.selectStockObject(8); select(memory, dc, 0x4aa7f4); }
    polygon(memory, dc, [[x1, sub32(y1, h1)], [x1, fillBottom], [x2, fillBottom], [x2, sub32(y2, h2)]]);
    if (get(0x4ac928) === 0 && get(0x49116c) < 13) {
      const small = add32(idiv32(get(0x4a72d0), 150), waterLine), big = add32(idiv32(get(0x4a72d0), 80), waterLine);
      select(memory, dc, 0x4a4dec);
      if (small < y1 && small < y2) {
        const dx = integer(sub32(x2, x1)).toNumber();
        // With the original masked x87 control word, dx=0 stores infinity or
        // NaN as the slope. The next 0*slope is NaN; __ftol's signed-I64
        // indefinite value has low I32 bits zero. No finite approximation is
        // used: the original low-word result is zero for this exact branch.
        const slope = dx === 0 ? undefined : integer(sub32(sub32(y2, h2), sub32(y1, h1))).divide(Float80.fromNumber(dx)).toNumber();
        for (let pointer = 0x4a9458; pointer < 0x4a946c; pointer += 4) {
          const x = sub32(x1, integer(get(pointer - 4)).multiply(Float80.fromNumber(dx)).multiply(f(memory, 0x484e28)).truncI32());
          const y = add32(dx === 0 ? 0 : integer(sub32(x, x1)).multiply(Float80.fromNumber(slope)).truncI32(), sub32(y1, h1));
          const treeY = sub32(y, integer(sub32(add32(idiv32(get(0x4a72d0), 100), y), waterLine))
            .multiply(integer(get(pointer))).multiply(f(memory, 0x484cc8)).truncI32());
          if (small < treeY && treeY < big && treeY < y) { dc.moveTo(x, treeY); dc.lineTo(x, sub32(treeY, 1)); }
          if (big <= treeY && treeY < y) { dc.moveTo(sub32(x, 1), treeY); dc.lineTo(x, sub32(treeY, 2)); dc.lineTo(add32(x, 1), treeY); }
        }
      }
    }
  }
  dc.selectStockObject(8);
  select(memory, dc, get(0x4ac1e0) === 1 || get(0x4ac92c) === 1 || get(0x4ac98c) === 1 ? 0x4a70e4 : 0x4a4f7c);
  if (get(0x4ac92c) === 1) select(memory, dc, 0x4a3efc);
  polygon(memory, dc, [[x1, y1], [x1, sub32(y1, h1)], [x2, sub32(y2, h2)], [x2, y2]]);
  if (grade === 0 || get(0x4ac98c) !== 0) {
    dc.selectStockObject(6); dc.moveTo(x1, add32(y1, 1)); dc.lineTo(x2, add32(y2, 1)); return;
  }
  dc.selectStockObject(8); select(memory, dc, get(0x4ac92c) === 0 ? 0x4a8e04 : 0x4a70e4);
  polygon(memory, dc, [[x1, y1], [x1, add32(y1, idiv32(imul32(imul32(grade, h1), 2), 3))],
    [x2, add32(y2, idiv32(imul32(imul32(grade, h2), 2), 3))], [x2, y2]]);
}

/** Complete 0x42d120. Undefined native local data is explicit when consumed. */
export function drawProjectedShoreline(memory, dc, horizon, first, last, camera, left, top, right, bottom, waterLine, options = {}) {
  [horizon, first, last, camera, left, top, right, bottom, waterLine] = [horizon, first, last, camera, left, top, right, bottom, waterLine].map(i32);
  if (first < 0 || last > 180) throw new RangeError('Original shoreline local arrays support indices 0 through 180');
  const get = address => memory.readI32(address), xs = [], ys = [], treeXs = [], treeYs = [];
  let centerY;
  if (get(0x4a864c) === 0) {
    projectScenePoint(memory, 0, get(0x4ac284), get(0x4a3a08), camera, 0, options);
    centerY = get(0x4a7c48) < right && left < get(0x4a7c48) ? get(0x4aaa48) : 0;
    if (options.shorelineStack) options.shorelineStack.centerProjectedY = centerY;
  }
  for (let index = first; index <= last; index++) {
    projectScenePoint(memory, index, get(indexed(0x4a6490, index)), get(indexed(0x4a68c8, index)), camera, 5, options);
    xs[index] = get(indexed(0x4a7c48, index)); ys[index] = Math.max(get(indexed(0x4aaa48, index)), horizon);
    memory.writeI32(indexed(0x4a3c10, index), get(0x4ac66c));
  }
  // X[180] and the first predecessor-Y share the original frame address.
  // Preserve that store for a later invocation using the same caller frame.
  if (xs[180] !== undefined && options.shorelineStack) options.shorelineStack.previousTreeY = xs[180];
  for (let index = add32(first, 1), counter = imul32(index, 2); index <= last; index++, counter = add32(counter, 2)) {
    const kind = get(0x4a4958);
    if (kind === 4 && (abs32(sub32(counter, get(0x4a67bc))) <= 6 || abs32(sub32(counter, get(0x4a67c0))) <= 5 || abs32(sub32(counter, get(0x4a67c4))) <= 5)) continue;
    if (kind === 5 && (abs32(sub32(counter, get(0x4a67bc))) <= 9 || abs32(sub32(counter, get(0x4a67c0))) <= 9)) continue;
    if (kind === 6 && !((counter < 91 || counter > 269) && counter > 3 && counter < 357)) continue;
    if (kind === 7 && !(counter > 89 && counter < 271 && (counter < 186 || counter > 194))) continue;
    if (![xs[index - 1], xs[index], ys[index - 1], ys[index]].every(value => abs32(value) < 31000)) continue;
    if (abs32(get(indexed(0x4a3c10, index - 1))) >= 160 || abs32(get(indexed(0x4a3c10, index))) >= 160) continue;
    if (centerY === undefined && get(0x4a5a4c) === 1) centerY = stackInteger(options, 'centerProjectedY');
    drawShoreSegment(memory, dc, xs[index - 1], ys[index - 1], xs[index], ys[index], waterLine, index,
      left, top, right, bottom, waterLine, centerY, options);
  }
  if (get(0x4a4958) >= 2 || get(0x4a5a4c) !== 1) return;
  let treeX = imul32(sub32(bottom, waterLine), sub32(3, get(0x4ac1e0))), treeY = treeX;
  for (let index = first; index <= last; index++) {
    treeXs[index] = xs[index]; memory.writeI32(indexed(0x4a4f90, index), xs[index]);
    treeYs[index] = sub32(sub32(ys[index], idiv32(imul32(sub32(ys[index], waterLine), get(indexed(0x4a9454, index))), treeX)), 1);
    memory.writeI32(indexed(0x4a5bb0, index), treeYs[index]);
  }
  if (get(0x4ac92c) === 0 && get(0x4ac98c) === 0) { dc.selectStockObject(8); select(memory, dc, 0x4a621c); }
  else { select(memory, dc, 0x4a71bc); select(memory, dc, 0x4a70e4); }
  dc.selectStockObject(7);
  if (get(0x4ac98c) === 1) { dc.selectStockObject(7); select(memory, dc, 0x4aa7f4); }
  drawAlternateShore(memory, dc);
  if (get(0x4ac928) !== 0 || get(0x49116c) >= 13) return;
  projectScenePoint(memory, 0, get(0x4ac284), get(0x4a3a08), camera, 0, options);
  const cx = get(0x4a7c48), cy = get(0x4aaa48);
  // The original local arrays share one stack frame. Its predecessor Y at
  // first=0 aliases projected X[180]; MoveTo's large-tree prior POINT can
  // overwrite the predecessor X at frame+0x30 during the two tree draws.
  let retainedPreviousX;
  const prior = (values, index, field) => {
    if (values[index - 1] !== undefined) return values[index - 1];
    if (field === 'previousTreeY' && first === 0 && xs[180] !== undefined) return xs[180];
    if (field === 'previousX' && retainedPreviousX !== undefined) return retainedPreviousX;
    return stackInteger(options, field);
  };
  for (let index = first; index <= last; index++) {
    select(memory, dc, 0x4a4dec);
    const nextHeight = get(indexed(0x4a9458, index));
    for (let offset = 0; offset < 2; offset++) {
      const height = get(indexed(0x4a9454 + offset * 4, index));
      if (height < 26) {
        treeX = idiv32(add32(add32(prior(treeXs, index, 'previousX'), imul32(treeXs[index], 3)), cx), 5);
        treeY = idiv32(add32(add32(prior(treeYs, index, 'previousTreeY'), imul32(treeYs[index], 3)), cy), 5);
      } else if (nextHeight < 51) {
        treeX = idiv32(add32(add32(prior(treeXs, index, 'previousX'), cx), treeXs[index]), 3);
        treeY = idiv32(add32(add32(prior(treeYs, index, 'previousTreeY'), cy), treeYs[index]), 3);
      }
      if (height > 50 && nextHeight < 75) {
        treeX = idiv32(add32(add32(prior(treeXs, index, 'previousX'), imul32(cx, 2)), treeXs[index]), 4);
        treeY = idiv32(add32(add32(prior(treeYs, index, 'previousTreeY'), imul32(cy, 2)), treeYs[index]), 4);
      }
      if (height > 74) {
        treeX = idiv32(add32(add32(cx, imul32(prior(treeXs, index, 'previousX'), 3)), treeXs[index]), 5);
        treeY = idiv32(add32(add32(cy, imul32(prior(treeYs, index, 'previousTreeY'), 3)), treeYs[index]), 5);
      }
      if (treeX === treeY) continue;
      if (add32(waterLine, idiv32(get(0x4a72d0), 100)) < treeY && treeY < idiv32(get(0x4a72d0), 12)) { dc.moveTo(treeX, treeY); dc.lineTo(treeX, sub32(treeY, 1)); }
      if (idiv32(get(0x4a72d0), 12) <= treeY) {
        const previous = dc.moveTo(sub32(treeX, 1), treeY);
        if (first === 0) {
          retainedPreviousX = previous.y;
          if (options.shorelineStack) options.shorelineStack.previousX = previous.y;
        }
        dc.lineTo(treeX, sub32(treeY, 2)); dc.lineTo(add32(treeX, 1), treeY);
      }
    }
  }
  // The same frame+0x18 slot that held the earlier center Y becomes the
  // vegetation height pointer. Each point advances it twice by four bytes.
  if (first <= last && options.shorelineStack) options.shorelineStack.centerProjectedY = indexed(0x4a945c, last);
}

/** Complete original0x42e190. The scene caller explicitly supplies selector0 or1. */
export function drawShoreMarker(memory, dc, x, y, selector) {
  [x, y] = [x, y].map(i32); const get = address => memory.readI32(address);
  if (y < add32(get(0x491148), 1)) return;
  if (!Number.isInteger(selector)) throw new RangeError('Original shore marker requires its integer selector');
  selector = i32(selector); dc.selectStockObject(7);
  const factor = f(memory, 0x484dd8).subtract(integer(sub32(y, 30)).multiply(f(memory, 0x485280))
    .divide(integer(sub32(idiv32(get(0x4a72d0), 2), 30))));
  let size = factor.multiply(f(memory, get(0x4a5a4c) === 1 ? 0x485288 : 0x485290)).truncI32();
  if (selector === 1) size = factor.multiply(f(memory, 0x485298)).truncI32();
  if (get(0x4a5a4c) === 0) {
    select(memory, dc, 0x4a70e4); const width = idiv32(imul32(size, 3), 10);
    dc.ellipse(sub32(x, width), y, add32(x, width), add32(y, idiv32(size, 10)));
  }
  let upper = y;
  if (get(0x4a5a4c) === 1) {
    dc.selectStockObject(8); select(memory, dc, get(0x4ac98c) === 0 && get(0x4ac92c) === 0 ? 0x4a621c : 0x4a70e4);
    if (get(0x4ac98c) === 1) select(memory, dc, 0x4aa7f4);
    upper = sub32(y, idiv32(size, 2));
    polygon(memory, dc, [[sub32(x, imul32(size, 3)), y], [x, upper], [add32(x, imul32(size, 3)), y]]);
    dc.selectStockObject(7); dc.moveTo(sub32(x, imul32(size, 3)), y); dc.lineTo(x, upper); dc.lineTo(add32(x, imul32(size, 3)), y);
  }
  if (get(0x4ac98c) === 0) dc.selectStockObject(0); else select(memory, dc, 0x4a70e4);
  const width = idiv32(imul32(size, selector === 1 ? 4 : 2), 30), side = idiv32(size, 7);
  const height = idiv32(size, add32(selector, 1));
  polygon(memory, dc, [[sub32(x, side), upper], [sub32(x, width), sub32(upper, height)],
    [add32(x, width), sub32(upper, height)], [add32(x, side), upper]]);
  dc.selectStockObject(4);
  if (get(0x4ac92c) === 0) { select(memory, dc, 0x4a3a14); select(memory, dc, 0x4a676c); }
  else { dc.selectStockObject(0); dc.selectStockObject(6); }
  dc.rectangle(add32(sub32(x, width), 1), sub32(sub32(upper, height), idiv32(size, 10)), add32(add32(x, width), 1), sub32(upper, height));
}

const buildingVisible = (memory, y) => y >= add32(memory.readI32(0x491148), 1) || memory.readI32(0x4a5a4c) !== 0;
const buildingSize = (memory, y, offset) => Math.min(1000, add32(idiv32(imul32(sub32(y, memory.readI32(0x491148)), 9), 4), offset));

export function drawHarborHouse(memory, dc, x, y) {
  [x, y] = [x, y].map(i32); if (!buildingVisible(memory, y)) return;
  const get = address => memory.readI32(address);
  const size = Math.min(1000, idiv32(add32(imul32(idiv32(imul32(sub32(y, get(0x491148)), 9), 4), 4), 80), 5));
  dc.selectStockObject(7); select(memory, dc, 0x4a3efc);
  const upper = sub32(y, idiv32(size, 2));
  polygon(memory, dc, [[sub32(x, idiv32(size, 10)), y], [sub32(x, idiv32(size, 20)), upper],
    [add32(x, idiv32(size, 20)), upper], [add32(x, idiv32(size, 10)), y]]);
  if (get(0x4ac92c) === 0) select(memory, dc, get(0x4a5b9c) === 1 || get(0x4a4958) === 1 ? 0x4a8e04 : 0x4a6484);
  else dc.selectStockObject(0);
  if (get(0x4ac98c) === 1) select(memory, dc, 0x4a70e4);
  dc.ellipse(sub32(x, idiv32(size, 4)), sub32(upper, idiv32(size, 6)), add32(x, idiv32(size, 4)), add32(upper, idiv32(size, 6)));
}

export function drawHarborBuilding(memory, dc, x, y) {
  [x, y] = [x, y].map(i32); if (!buildingVisible(memory, y)) return;
  const size = buildingSize(memory, y, 20), width = idiv32(size, 4);
  dc.selectStockObject(7); select(memory, dc, memory.readI32(0x4ac98c) === 1 || memory.readI32(0x4ac92c) === 1 ? 0x4a70e4 : 0x4a4f7c);
  dc.ellipse(sub32(x, width), sub32(y, idiv32(size, 2)), add32(x, width), y);
  select(memory, dc, 0x4a3efc); dc.rectangle(sub32(x, width), sub32(y, width), add32(x, width), y);
}

export function drawShoreBuilding(memory, dc, x, y) {
  [x, y] = [x, y].map(i32); if (!buildingVisible(memory, y)) return;
  const size = buildingSize(memory, y, 20), upper = sub32(y, idiv32(size, 4));
  select(memory, dc, 0x4a70e4); dc.selectStockObject(7); dc.rectangle(sub32(x, size), upper, add32(x, size), y);
  select(memory, dc, 0x4a3efc); dc.rectangle(sub32(x, size), upper, add32(x, size), sub32(y, idiv32(size, 9)));
}

export function drawShoreHouse(memory, dc, x, y, selector) {
  [x, y, selector] = [x, y, selector].map(i32); if (!buildingVisible(memory, y)) return;
  const get = address => memory.readI32(address), size = Math.min(1000, add32(imul32(sub32(y, get(0x491148)), 2), 27));
  const upper = sub32(y, idiv32(imul32(size, 2), 3));
  const phase = add32(f(memory, 0x4abef0).divide(f(memory, get(0x491194) === 8 ? 0x4852a0 : 0x4852a8)).truncI32(), selector);
  if ((phase & 1) === 0) {
    if (get(0x4ac92c) === 0) { select(memory, dc, 0x4a3a14); select(memory, dc, 0x4a676c); }
    else { dc.selectStockObject(0); dc.selectStockObject(6); }
    drawEllipseMarker(memory, dc, 1, add32(x, 1), sub32(upper, 1));
  }
  select(memory, dc, 0x4a71bc); dc.moveTo(sub32(x, idiv32(size, 6)), y);
  dc.lineTo(sub32(x, 1), upper); dc.lineTo(add32(x, 1), upper); dc.lineTo(add32(x, idiv32(size, 6)), y);
  for (const offset of [0, -1, 1]) { dc.moveTo(add32(x, offset), y); dc.lineTo(x, upper); }
}

export function drawLighthouse(memory, dc, x, y, selector) {
  [x, y, selector] = [x, y, selector].map(i32); const get = address => memory.readI32(address);
  if (y < add32(get(0x491148), 1)) return;
  if (get(0x491194) === 8 && get(0x4a5a4c) === 1) y = get(0x491148);
  const depth = get(0x4a4378) === 1 ? 6 : 0;
  if (selector === 1) { memory.writeI32(0x4aca10, x); memory.writeI32(0x4aca14, y); }
  if (selector === 2) {
    select(memory, dc, get(0x4a4378) === 0 ? 0x4a4ee4 : 0x4aa634);
    if (get(0x4aca10) > 10 && get(0x4aca10) < sub32(get(0x4a763c), 10)) { dc.moveTo(get(0x4aca10), sub32(get(0x4aca14), depth)); dc.lineTo(x, sub32(y, depth)); }
    if (get(0x4a4378) === 1) {
      const dx = sub32(x, get(0x4aca10)), dy = sub32(y, get(0x4aca14));
      dc.moveTo(x, sub32(y, depth)); dc.lineTo(add32(x, imul32(dx, 2)), add32(y, imul32(dy, 2)));
      dc.moveTo(get(0x4aca10), sub32(get(0x4aca14), depth)); dc.lineTo(sub32(get(0x4aca10), imul32(dx, 2)), sub32(get(0x4aca14), imul32(dy, 2)));
    }
  }
  const size = buildingSize(memory, y, 30);
  if (get(0x4ac98c) === 0 && get(0x4a4378) === 0) dc.selectStockObject(0); else select(memory, dc, 0x4a70e4);
  dc.selectStockObject(7); const upper = sub32(y, idiv32(size, 2)), lower = add32(y, idiv32(size, 40));
  polygon(memory, dc, [[sub32(x, idiv32(size, 20)), lower], [sub32(x, idiv32(size, 30)), upper],
    [add32(x, idiv32(size, 30)), upper], [add32(x, idiv32(size, 20)), lower]]);
}

/** Complete 0x42ede0: compass heading, with integer-table rays and original text. */
export function drawHeadingIndicator(memory, dc, boat, right, sceneTop) {
  [boat, right, sceneTop] = [boat, right, sceneTop].map(i32);
  const get = address => memory.readI32(address);
  if (get(0x4ac904) === 1) return;
  dc.setBkMode(1); const x = sub32(right, 30), y = get(indexed(0x4a4e88, boat)) === 3 ? 31 : sub32(sceneTop, 10);
  if (get(0x4ac92c) === 0) { dc.setBkColor(0x7f7f00); dc.setTextColor(0xffff); }
  if (get(0x4ac98c) === 1) dc.setBkColor(0x7f7f7f);
  let heading = get(indexed(0x4ac018, boat)); const textX = sub32(right, heading < 100 ? 40 : 45);
  if (get(0x4ac9d0) === 1) { heading = wrapDegreesOnce(sub32(heading, imul32(get(indexed(0x4aa730, boat)), 45))); dc.setTextColor(0xff); }
  dc.textOut(textX, sub32(y, 26), formatInteger(heading));
  const angle = wrapDegreesOnce(get(indexed(0x4ac018, boat))), sine = get(indexed(0x4a54a0, angle)), cosine = get(indexed(0x4a3450, angle));
  const points = [[sub32(x, idiv32(imul32(sine, 26), 100)), sub32(y, idiv32(imul32(cosine, 26), 300))],
    [add32(x, idiv32(imul32(cosine, 13), 100)), sub32(y, idiv32(imul32(sine, 13), 300))],
    [add32(x, idiv32(imul32(sine, 13), 100)), add32(y, idiv32(imul32(cosine, 13), 300))],
    [sub32(x, idiv32(imul32(cosine, 13), 100)), add32(y, idiv32(imul32(sine, 13), 300))]];
  dc.selectStockObject(4); dc.selectStockObject(7); dc.ellipse(sub32(right, 56), sub32(y, 8), sub32(right, 4), add32(y, 8));
  select(memory, dc, 0x4a4ee4); for (const [px, py] of points) { dc.moveTo(x, y); dc.lineTo(px, py); }
  dc.selectStockObject(7); dc.setBkMode(2);
}

/** Complete 0x42f0d0: apparent/true wind, mark and current direction indicators. */
export function drawSceneLayline(memory, dc, selector, camera, left, sceneTop, right, options = {}) {
  [selector, camera, left, sceneTop, right] = [selector, camera, left, sceneTop, right].map(i32);
  const get = address => memory.readI32(address), offset = f(memory, 0x4aa810).multiply(f(memory, 0x485058)).truncI32();
  if (selector === -1 && ((get(0x4a4958) > 0 && get(0x4a4958) < 4) || (get(0x491158) === 0 && get(0x4a4958) !== 4))) return;
  dc.setBkMode(1);
  const variant = !(get(0x4ac980) < 1 || get(0x4ac980) === 2 || get(0x4ac980) === 300);
  let x = add32(add32(left, 30), imul32(selector, 70));
  let y = get(indexed(0x4a4e88, camera)) === 3 ? 31 : sub32(sceneTop, 10), angle = selector, strength;
  if (selector === -1) x = 210;
  if (variant) y = add32(sceneTop, 31);
  if (selector === 1) {
    x = sub32(right, offset); memory.writeI32(0x4aa7e0, displayedTargetMark(memory, camera));
    const target = get(0x4aa7e0);
    angle = sub32(186, targetRelativeBearing(memory, memory.readF64(indexed(0x4a52f0, target, 8)),
      memory.readF64(indexed(0x4a60b0, target, 8)), -1, camera).multiply(f(memory, 0x484d78)).truncI32());
  }
  if (selector === 0) {
    x = add32(left, 27);
    const second = get(0x4ac9d8) === 0 ? get(0x4a4800) : get(0x4a7bd0);
    angle = sub32(0, camera === 1
      ? add32(imul32(get(get(0x4ac9d8) === 0 ? 0x4a47fc : 0x4a7bcc), get(0x4aa734)), get(0x4a475c))
      : add32(imul32(second, get(0x4aa738)), get(0x4a4770)));
    if (variant) { x = sub32(get(0x4a763c), 40); angle = get(0x4ac840); }
  }
  if (selector === -1) {
    x = add32(add32(offset, 2), left);
    strength = sampleCurrent(memory, f(memory, indexed(0x4a49e8, camera, 8)).truncI32(), f(memory, indexed(0x4a4ae0, camera, 8)).truncI32(), camera, options);
    angle = wrapDegreesOnce(sub32(sub32(get(camera === 1 ? 0x4ac01c : 0x4ac020), get(0x4aa960)), get(camera === 1 ? 0x4a475c : 0x4a4770)));
  }
  const intermediate = wrapDegreesOnce(wrapDegreesOnce(angle)); angle = wrapDegreesOnce(intermediate);
  if (intermediate < 0 || intermediate >= 361) return;
  const ray = (a, length) => [sub32(x, idiv32(imul32(get(indexed(0x4a54a0, a)), length), 100)),
    sub32(y, idiv32(imul32(get(indexed(0x4a3450, a)), length), 300))];
  const points = [ray(intermediate, 26), ray(wrapDegreesOnce(wrapDegreesOnce(add32(angle, 40))), 13), ray(wrapDegreesOnce(wrapDegreesOnce(sub32(angle, 40))), 13)];
  if (get(0x4ac92c) === 0) select(memory, dc, 0x4a621c); else dc.selectStockObject(4);
  if (get(0x4ac92c) === 0 && selector === 1) {
    const target = get(0x4aa7e0); if (target === 3 || target === 5) select(memory, dc, 0x4a6484);
    if (target === 4) select(memory, dc, 0x4ab17c); if (target === 2) select(memory, dc, 0x4a70e4);
  }
  if (get(0x4ac92c) === 0 && selector === -1) select(memory, dc, 0x4aa714);
  dc.selectStockObject(7); dc.ellipse(sub32(x, 26), sub32(y, 8), add32(x, 26), add32(y, 8));
  select(memory, dc, 0x4a4ee4); for (const [px, py] of points) { dc.moveTo(x, y); dc.lineTo(px, py); }
  const textY = sub32(y, get(0x4a763c) > 900 ? 27 : 26);
  if (get(0x4ac92c) === 0) { dc.setBkColor(0x7f7f00); dc.setTextColor(0xffff); }
  if (get(0x4ac98c) === 1) dc.setBkColor(0x7f7f7f);
  if (selector === 0 && !variant) {
    const text = readAnsiString(memory, get(0x4ac9d8) === 0 ? 0x493478 : 0x493470)
      + formatInteger(get(indexed(get(0x4ac9d8) === 0 ? 0x4ab9e8 : 0x4a6338, camera)));
    dc.textOut(sub32(x, 24), textY, text);
  }
  if (variant) dc.textOut(sub32(x, 12), textY, readAnsiString(memory, 0x493468));
  if (selector === 1) dc.textOut(sub32(x, 15), textY, readAnsiString(memory, 0x493460));
  if (selector === -1) {
    let label = '';
    if (get(0x4a4958) !== 4) label = readAnsiString(memory, 0x493458);
    if (get(0x4a4958) === 4 && get(0x4a763c) > 700) label = readAnsiString(memory, 0x49344c);
    if (get(0x4a4958) === 4 && get(0x4a763c) < 701) label = readAnsiString(memory, 0x493444);
    const magnitude = abs32(strength);
    dc.textOut(sub32(x, 25), textY, `${label}${formatInteger(idiv32(magnitude, 10))}${readAnsiString(memory, 0x49300c)}${formatInteger(magnitude % 10)}`);
  }
  dc.setBkMode(2); dc.setBkColor(0xffffff); dc.setTextColor(0);
}
