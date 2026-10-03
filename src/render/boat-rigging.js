import { add32, sub32, imul32, idiv32, i32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { nativeTrig } from '../engine/native-trig.js';
import { selectBoatColor } from './boat-primitives.js';
import { drawTelltale } from './boat-panels.js';

export const BOAT_RIGGING_ROUTINES = Object.freeze({ drawBalancePanels: 0x418120, drawMastRigging: 0x416d10 });
const indexed = (base, index) => add32(base, imul32(index, 4)) >>> 0;
const px = (m, index) => m.readI32(indexed(0x4aa1a0, index));
const py = (m, index) => m.readI32(indexed(0x4aa2a0, index));
const rb = (m, base, boat) => m.readI32(indexed(base, boat));
const avg = (a, b) => idiv32(add32(a, b), 2);
const weighted = (a, b, factor = 2, divisor = 3) => idiv32(add32(a, imul32(b, factor)), divisor);
const constant = (m, address) => Float80.fromNumber(m.readF64(address));
const product = (m, value, address) => Float80.fromNumber(value).multiply(constant(m, address));
const offset = (m, value, address) => product(m, value, address).truncI32();
function select(m, dc, address) { const handle = m.readU32(address); if (handle) dc.selectObject(handle); }
function polygon(m, dc, values) {
  for (const [index, [x, y]] of values.entries()) { m.writeI32(0x4a4ca8 + index * 8, x); m.writeI32(0x4a4cac + index * 8, y); }
  dc.polygon(values.map(([x, y]) => ({ x, y })));
}

/** Complete 0x418120: catamaran lower hulls and the original crew-balance triangles. */
export function drawBalancePanels(memory, dc, height, boat, viewHeading, options = {}) {
  boat = i32(boat); viewHeading = i32(viewHeading);
  dc.selectStockObject(7); selectBoatColor(memory, dc, boat);
  const lower = offset(memory, height, 0x485050), depth = offset(memory, height, 0x484d90);
  const rightX = avg(px(memory, 16), px(memory, 15)), rightY = add32(avg(py(memory, 16), py(memory, 15)), depth);
  const leftX = avg(px(memory, 7), px(memory, 6)), leftY = add32(avg(py(memory, 6), py(memory, 7)), depth);
  polygon(memory, dc, [[px(memory, 16), py(memory, 16)], [px(memory, 15), py(memory, 15)],
    [px(memory, 15), add32(py(memory, 15), lower)], [rightX, rightY], [px(memory, 16), add32(py(memory, 16), lower)]]);
  polygon(memory, dc, [[px(memory, 7), py(memory, 7)], [px(memory, 6), py(memory, 6)],
    [px(memory, 6), add32(py(memory, 6), lower)], [leftX, leftY], [px(memory, 7), add32(py(memory, 7), lower)]]);
  if (boat >= 2) return;
  select(memory, dc, 0x4a4dec); dc.selectStockObject(4);
  // The first FSIN is spilled to binary64; the rudder FSIN below remains extended.
  const phase = Float80.fromNumber(nativeTrig(viewHeading, options).sine.toNumber());
  const centerX = avg(px(memory, 15), px(memory, 16)), centerY = avg(py(memory, 16), py(memory, 15));
  const dx = sub32(rightX, centerX), dy = sub32(rightY, centerY);
  for (let side = 1; side < 3; side++) {
    const cx = side === 1 ? centerX : avg(px(memory, 6), px(memory, 7));
    const cy = side === 1 ? centerY : avg(py(memory, 7), py(memory, 6));
    let x = side === 1 ? rightX : leftX, y = side === 1 ? rightY : leftY;
    let scale = constant(memory, 0x484d50);
    if (rb(memory, 0x4aa730, boat) === (side === 1 ? -1 : 1)) {
      const crew = rb(memory, 0x4a6ec8, boat);
      if (crew >= 7) { x = add32(x, dx); y = add32(y, dy); }
      else if (crew > 0) { x = add32(x, idiv32(imul32(dx, crew), 6)); y = add32(y, idiv32(imul32(dy, crew), 6)); }
      scale = Float80.fromInteger(idiv32(crew, 6)).subtract(constant(memory, 0x484e78)).multiply(constant(memory, 0x484d50));
    }
    if (scale.compare(constant(memory, 0x485058)) > 0) scale = constant(memory, 0x485058);
    const rudder = nativeTrig(memory.readI32(0x4a7044), options).sine;
    const first = rudder.multiply(scale).multiply(Float80.fromNumber(height)).truncI32();
    const second = scale.multiply(Float80.fromNumber(height)).multiply(phase).truncI32();
    polygon(memory, dc, [[cx, cy], [x, y], [add32(sub32(first, second), x), y]]);
  }
}

/** Complete 0x416d10, including mast, telltales and crew trapeze state writes. */
export function drawMastRigging(memory, dc, boat, height, mastIndex, curvature, screenY, widthScale, viewHeading, colorSelector, side, rng) {
  [boat, mastIndex, curvature, screenY, viewHeading, colorSelector, side] = [boat, mastIndex, curvature, screenY, viewHeading, colorSelector, side].map(i32);
  const get = address => memory.readI32(address), set = (address, value) => memory.writeI32(address, value);
  let effective = product(memory, height, 0x484fc0).toNumber();
  if (get(0x491188) === 8) effective = product(memory, effective, 0x484fc8).toNumber();
  if (get(0x4ac900) === 1) effective = product(memory, effective, 0x484fd0).toNumber();
  if (get(0x4ac914) === 1) effective = product(memory, effective, 0x484dc0).toNumber();
  let curveDepth = idiv32(Float80.fromInteger(curvature).multiply(Float80.fromNumber(widthScale)).truncI32(), 3);
  if (get(0x4ac904) === 1) curveDepth = add32(curveDepth, offset(memory, effective, 0x484dd8));
  const telltale = () => drawTelltale(memory, dc, px(memory, 21), sub32(py(memory, 21), offset(memory, effective, 0x484fe0)), boat, viewHeading, screenY, colorSelector, rng);
  if (boat === 1 || get(0x4ac98c) === 1 || get(0x4ac994) > 0) telltale();
  if (boat === 2) {
    if (get(0x491140) === 2 && get(0x4ac98c) === 0) telltale();
    if (get(0x491140) === 1 && get(0x4ac98c) === 0 && get(0x49118c) === 2) telltale();
  }
  if (screenY > get(0x4a7354)) select(memory, dc, 0x4a4dec); else dc.selectStockObject(7);
  dc.moveTo(px(memory, mastIndex), py(memory, mastIndex));
  const lower = offset(memory, effective, 0x484e00), middle = offset(memory, effective, 0x484d90), upper = offset(memory, effective, 0x484da8);
  dc.lineTo(px(memory, 17), sub32(py(memory, 17), lower));
  dc.lineTo(px(memory, 18), sub32(py(memory, 18), middle));
  dc.lineTo(px(memory, 19), sub32(py(memory, 19), upper));
  dc.lineTo(px(memory, 20), sub32(py(memory, 20), offset(memory, effective, 0x484ec8)));
  if (get(0x4ac914) === 1) dc.selectStockObject(6);
  const top = offset(memory, effective, 0x484fe0);
  dc.lineTo(px(memory, 21), sub32(py(memory, 21), top));
  select(memory, dc, 0x4a4dec);
  if (screenY < get(0x4ac13c)) return;
  if (get(0x4ac914) === 1 && ((rb(memory, 0x4aa730, boat) === 1 && side === 1) || (rb(memory, 0x4aa730, boat) === -1 && side === 0))) {
    dc.moveTo(px(memory, 19), sub32(py(memory, 19), upper)); dc.lineTo(px(memory, 21), sub32(py(memory, 21), top));
  }
  set(0x4a70fc, px(memory, 17)); set(0x4a72cc, sub32(py(memory, 17), lower));
  if (get(0x4ac904) === 1) { set(0x4a70fc, px(memory, 18)); set(0x4a72cc, sub32(py(memory, 18), middle)); }
  set(0x4a70f4, px(memory, 25)); set(0x4a72c0, sub32(sub32(py(memory, 25), curveDepth), lower));
  dc.moveTo(get(0x4a70fc), get(0x4a72cc)); dc.lineTo(get(0x4a70f4), get(0x4a72c0));
  if (!(screenY > get(0x4a7354) && boat < 2 && get(0x4ac904) !== 1)) return;
  dc.selectStockObject(7);
  set(0x4ac1d8, rb(memory, 0x4a7bc8, boat) < 60 ? 2 : 4);
  if (get(0x4ac900) === 1 && rb(memory, 0x4a7bc8, boat) > 90) set(0x4ac1d8, 3);
  const catamaran = get(0x4ac900), boatClass = get(0x491188), factor = get(0x4ac1d8);
  let boomX, boomY;
  if (catamaran === 0 && boatClass < 6) { boomX = get(0x4a70f4); boomY = get(0x4a72c0); }
  else if (catamaran === 0) { boomX = weighted(get(0x4a70fc), get(0x4a70f4)); boomY = weighted(get(0x4a72cc), get(0x4a72c0)); }
  else { boomX = weighted(get(0x4a70fc), get(0x4a70f4), 3, 4); boomY = weighted(get(0x4a72cc), get(0x4a72c0), 3, 4); }
  let gripX = boat, gripY = boat;
  const tack = rb(memory, 0x4aa730, boat);
  if (catamaran === 0) {
    const left = boatClass < 6 ? 6 : 7, right = boatClass < 6 ? 16 : 15, reference = boatClass < 6 ? 0 : 1;
    const ax = weighted(px(memory, left), px(memory, reference), 6, 7), ay = weighted(py(memory, left), py(memory, reference), 6, 7);
    const bx = weighted(px(memory, right), px(memory, reference), 6, 7), by = weighted(py(memory, right), py(memory, reference), 6, 7);
    if (tack === 1) { gripX = add32(ax, idiv32(imul32(sub32(bx, px(memory, left)), factor), 8)); gripY = add32(ay, idiv32(imul32(sub32(by, py(memory, left)), factor), 8)); }
    else { gripX = add32(bx, idiv32(imul32(sub32(ax, px(memory, right)), factor), 8)); gripY = add32(by, idiv32(imul32(sub32(ay, py(memory, right)), factor), 8)); }
  }
  if (catamaran === 1) {
    const mx = avg(get(0x4a4880), get(0x4a4950)), my = avg(get(0x4a4884), get(0x4a4df0));
    if (tack === 1) { gripX = add32(mx, idiv32(imul32(sub32(get(0x4a4950), mx), factor), 4)); gripY = add32(my, idiv32(imul32(sub32(get(0x4a4884), my), factor), 4)); }
    if (tack === -1) { gripX = add32(mx, idiv32(imul32(sub32(get(0x4a4880), mx), factor), 4)); gripY = add32(my, idiv32(imul32(sub32(get(0x4a4df0), my), factor), 4)); }
  }
  dc.selectStockObject(4); dc.moveTo(boomX, boomY); dc.lineTo(gripX, gripY);
  if (boatClass < 7) {
    dc.moveTo(avg(get(0x4a70f4), get(0x4a70fc)), avg(get(0x4a72cc), get(0x4a72c0)));
    dc.lineTo(avg(px(memory, 1), px(memory, 2)), avg(py(memory, 2), py(memory, 1)));
  }
  if (catamaran === 0) {
    dc.moveTo(weighted(get(0x4a70f4), get(0x4a70fc)), weighted(get(0x4a72c0), get(0x4a72cc)));
    dc.lineTo(px(memory, mastIndex), py(memory, mastIndex));
  }
}
