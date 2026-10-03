import { add32, sub32, imul32, idiv32, i32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { formatInteger, readAnsiString } from '../engine/hud-state.js';
import { wrapDegreesOnce } from '../engine/integer-core.js';
import { drawBoat } from './boat.js';
import { drawSceneMark, sortSceneDepths } from './scene-objects.js';
import { selectBoatTextColor } from './tutorial-controls.js';

export const SCREEN_ROUTINES = Object.freeze({
  drawStartScreen: 0x40f4a0, drawDemoNotice: 0x410090, drawResultsScreen: 0x41c940,
  drawForecastScreen: 0x41d890, drawAdvice: 0x4063e0,
  drawTackingAdvice: 0x406c90, drawJibingAdvice: 0x4064d0,
});
const f = (memory, address) => Float80.fromNumber(memory.readF64(address));
const at = (address, index, stride = 4) => add32(address, imul32(index, stride)) >>> 0;

/** Complete original 0x410090 information screen; no demo gates are altered. */
export function drawDemoNotice(memory, dc) {
  const r = address => memory.readI32(address), text = address => readAnsiString(memory, address);
  const width = r(0x4a763c), line = width < 700 ? 14 : width < 900 ? 18 : 19;
  const x = width < 700 ? 3 : 20, gap = width < 700 ? 21 : width < 900 ? 27 : 30;
  let y = 2;
  const color = value => { if (r(0x4ac92c) === 0) dc.setTextColor(value); };
  const output = (address, outputY = y, outputX = x) => dc.textOut(outputX, outputY, text(address));
  color(0x7f0000);
  if (r(0x4ac93c) === 0) {
    output(0x492fb4); output(0x492f58, add32(line, 2)); y = add32(add32(line, 2), line);
    if ([1, 3, 4, 2].includes(r(0x491164))) output(0x492f18);
    if (r(0x491164) === 12) output(0x492f00);
    y = add32(y, gap); color(0x7f00); output(0x492ea8);
    if ([1, 3, 4].includes(r(0x491164))) { y = add32(y, line); output(0x492e54); }
    if (r(0x491164) === 2) { y = add32(y, line); output(0x492e30); }
    color(0xff0000); output(0x492ddc, add32(y, gap)); y = add32(add32(y, gap), line);
    output(0x492d7c); y = add32(y, line); output(0x492d20); y = add32(y, line); output(0x492cd4);
    y = add32(y, gap); color(0x7f0000); output(0x492c80); y = add32(y, line); output(0x492c28);
    y = add32(y, gap); color(0x7f); output(0x492bf0); y = add32(y, line); color(0x7f7f00); output(0x492b94);
    y = add32(y, gap);
  }
  if (r(0x4ac93c) === 1) {
    color(0x7f0000); output(0x492b64, add32(y, line)); y = add32(add32(y, line), gap);
    output(0x492b10); y = add32(y, gap);
    if ([1, 4, 2].includes(r(0x491164))) {
      const sessions = r(0x4ac95c);
      dc.textOut(x, y, text(0x492aec) + formatInteger(sessions) + text(sessions < 2 && sessions !== 0 ? 0x492ae0 : 0x492ad4));
    }
    y = add32(y, imul32(gap, 6));
  }
  if (r(0x4ac93c) === 10) { output(0x492a84, add32(y, gap)); y = add32(add32(imul32(gap, 9), y), gap); }
  color(0x7f0000);
  if (r(0x491164) === 1) {
    color(0x7f0000); output(0x492a30); output(0x4929f0, add32(y, line)); y = add32(add32(y, line), line);
    output(0x4929b0); y = add32(y, gap); color(0xff0000); output(0x492950); y = add32(y, line);
    output(0x4928f4); y = add32(y, line); color(0x7f); output(0x4928d4);
    color(0x7f007f); output(0x4928b4, y, sub32(idiv32(r(0x4a763c), 2), 10)); y = add32(y, line);
    color(0xff0000); output(0x492894); color(0x7f00); output(0x492870, y, sub32(idiv32(r(0x4a763c), 2), 10));
    color(0x7f7f00); output(0x492810, add32(y, gap)); y = add32(add32(y, gap), line); output(0x4927b0);
  }
  if (r(0x491164) === 2 || r(0x491164) === 4) {
    y = add32(y, idiv32(line, 2)); output(0x492790); y = add32(y, line); output(0x492750);
    y = add32(y, line); output(0x492700);
    if (r(0x491164) === 4) {
      color(0x7f7f00); output(0x4926c4, add32(y, gap)); y = add32(add32(y, gap), line);
      output(0x492674); y = add32(y, line); output(0x492654);
    }
    color(0xff0000); output(0x49262c, add32(y, gap)); y = add32(add32(y, gap), line);
    output(0x4925e0); y = add32(y, line); output(0x4925bc);
  }
  if (r(0x491164) === 3) {
    y = add32(y, idiv32(line, 2)); output(0x492790); y = add32(y, line); output(0x492750);
    color(0xff0000); y = add32(add32(y, line), idiv32(imul32(line, 3), 2)); output(0x492594);
    y = add32(y, line); output(0x492578); y = add32(y, line); output(0x49253c); output(0x492510, add32(y, line));
  }
  if (r(0x4ac92c) === 0) { dc.setTextColor(0xff); dc.setBkColor(0); }
  const promptY = () => Float80.fromInteger(r(0x4a72d0)).multiply(f(memory, 0x484dc8)).truncI32();
  if (r(0x4ac93c) === 0) output(0x4924f0, promptY());
  if (r(0x4ac93c) > 0 && r(0x4ac93c) < 10) output(0x4924ac, promptY());
  if (r(0x4ac93c) === 10) output(0x492484, promptY());
  dc.setBkColor(0xffffff);
}

/** Complete original startup screen 0x40f4a0, retaining the demo notice gate. */
export function drawStartScreen(memory, dc, rng, options = {}) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const text = address => readAnsiString(memory, address), width = () => r(0x4a763c), height = () => r(0x4a72d0);
  memory.writeF64(0x4aa810, width()); memory.writeF64(0x4aa7d8, height());
  const titleX = idiv32(width(), 10), offset = width() < 700 ? -10 : 0;
  dc.selectStockObject(7); dc.selectStockObject(0); dc.rectangle(0, 0, width(), height());
  if (r(0x491164) > 0 && r(0x4ac9cc) === 0) { drawDemoNotice(memory, dc); return; }
  dc.setTextColor(r(0x4ac92c) === 0 ? 0xff : 0);
  dc.textOut(5, 1, text(0x492438));
  const titleY = add32(offset, r(0x4ac9ac) === 0 ? 60 : 40);
  if (r(0x4ac92c) === 0) dc.setTextColor(0x7f0000);
  const menuHeight = i32(options.getSystemMetrics?.(15) ?? options.menuHeight ?? 20);
  w(0x4a5264, menuHeight); dc.textOut(titleX, titleY, text(0x492418));
  if (width() === 900) throw new RangeError('Original startup screen leaves its registered-symbol X uninitialized at width 900');
  const symbolX = add32(titleX, width() < 700 || menuHeight < 21 ? 230 : 290);
  dc.textOut(add32(symbolX, 2), sub32(titleY, idiv32(height(), 100)), text(0x492414));
  dc.setTextColor(0);
  if (r(0x4ac9ac) === 1) {
    dc.textOut(10, add32(titleY, 20), text(0x4923c0));
    if (r(0x4ac9ac) === 1) dc.textOut(10, add32(titleY, 40), text(0x492364));
  }
  if (r(0x4ac92c) === 0) dc.setTextColor(0x7f0000);
  dc.textOut(titleX, add32(titleY, 20), text(r(0x491164) === 0 ? 0x492358 : 0x492348));
  if (r(0x4ac92c) === 0) dc.setTextColor(0xff0000);
  dc.textOut(idiv32(imul32(width(), 6), 11), titleY, text(0x49231c)); dc.setTextColor(0);
  if (r(0x491140) === 2) {
    for (const [value, address] of [[-7, 0x492308], [-4, 0x4922ec], [-2, 0x4922d4], [0, 0x4922b8], [7, 0x4922a4], [4, 0x492288], [2, 0x492270]]) {
      if (r(0x4ac948) === value) dc.textOut(20, idiv32(imul32(height(), 3), 4), text(address));
    }
  }
  if (r(0x491188) > 5 && r(0x491188) < 9 && r(0x4ac908) === 0) {
    const y = idiv32(imul32(height(), 4), 5);
    dc.textOut(10, y, text(0x492264) + formatInteger(r(0x4a5ba4)));
    if (r(0x4a4eec) === 11) dc.textOut(idiv32(width(), 4), y, text(0x492250));
    if (r(0x4a4eec) === 10) dc.textOut(idiv32(width(), 4), y, text(0x492238));
    if (r(0x4a4eec) === 9) dc.textOut(idiv32(width(), 4), y, text(0x492224));
    if (r(0x4a4eec) < 9) dc.textOut(idiv32(width(), 4), y, text(0x492208));
    const sailX = add32(idiv32(imul32(width(), 2), 4), 10);
    if (r(0x4a5b90) < 10) dc.textOut(sailX, y, text(0x4921f0));
    const average = r(0x4a5b90) === 10;
    if (average) dc.textOut(sailX, y, text(0x4921dc));
    if (!average && r(0x4a5b90) > 9) dc.textOut(sailX, y, text(0x4921c4));
    dc.textOut(add32(idiv32(imul32(width(), 3), 4), 10), y, text(r(0x491150) < 100 ? 0x4921b4 : 0x4921a4));
  }
  // dVar3 is explicitly spilled to binary64 before the subsequent __ftol.
  const cornerOffset = Float80.fromNumber(f(memory, 0x4a8670).multiply(f(memory, 0x484d88)).toNumber()).truncI32();
  const brush = memory.readU32(r(0x4ac92c) === 0 ? 0x4a6dac : 0x4aa7f4);
  if (brush) dc.selectObject(brush);
  dc.roundRect(idiv32(width(), 10), idiv32(height(), 5), idiv32(imul32(width(), 9), 10), sub32(idiv32(imul32(height(), 3), 4), cornerOffset), 80, 80);
  w(0x4ac994, 1); const priorView = r(0x4a4e8c); w(0x4a4e8c, 2); w(0x4a6834, 0);
  const scaled = (global, factor) => f(memory, global).multiply(f(memory, factor)).truncI32();
  (options.drawSceneMark ?? drawSceneMark)(memory, dc, scaled(0x4aa810, 0x484d98), scaled(0x4aa7d8, 0x484d90), 4, 1);
  for (const boat of [1, 2, 3]) {
    if (boat === 3 && r(0x49118c) <= 2) break;
    for (const [base, value] of [[0x4a77e8, 2], [0x4aa730, boat === 2 ? -1 : 1], [0x4a6ec8, 15],
      [0x4a7060, 60], [0x4a6338, 15], [0x4ac018, boat === 2 ? 45 : 315], [0x4a7bc8, 45],
      [0x4abb70, 0], [0x4abf18, -1000]]) w(at(base, boat), value);
    const xFactor = [0, 0x484da8, 0x484db0, 0x484dc0][boat], yFactor = boat === 3 ? 0x484db8 : 0x484da0;
    (options.drawBoat ?? drawBoat)(memory, dc, scaled(0x4aa810, xFactor), scaled(0x4aa7d8, yFactor), boat, 1, height(), 0, rng, options);
  }
  w(0x4ac994, 0); w(0x4a4e8c, priorView); options.enforceMinimumPaintDuration?.(80);
}

/** Complete original current-race results 0x41c940, including scoring quirks. */
export function drawResultsScreen(memory, dc, _rng, _options = {}) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const text = address => readAnsiString(memory, address), width = () => r(0x4a763c), height = () => r(0x4a72d0);
  let y = width() < 700 ? 35 : 50, line = width() < 700 ? 15 : 17;
  if (width() > 900) { line = 20; y = 65; }
  const initialY = y;
  dc.selectStockObject(0); dc.selectStockObject(6); dc.rectangle(0, 0, width(), height());
  if (r(0x491164) >= 1 && r(0x4ac93c) >= 1) { drawDemoNotice(memory, dc); return; }
  w(0x49116c, r(0x4aa6f8)); w(0x491170, r(0x4ac858)); let offset = 0;
  if (r(0x4ac92c) === 0) { dc.setTextColor(0x7f0000); dc.setBkColor(0xffffff); }
  dc.textOut(idiv32(width(), 5), 1, text(0x493198));
  dc.textOut(idiv32(imul32(width(), 3), 5), 1, text(0x493184) + formatInteger(r(0x491190)));
  if (r(0x4ac960) === 1) {
    for (let boat = 1; boat <= r(0x491140); boat++) {
      const finish = r(at(0x4a764c, boat - 1));
      if (r(0x491140) === 2) { dc.textOut(10, y, text(0x49317c) + formatInteger(boat) + text(0x493170) + formatInteger(finish)); y = add32(y, line); }
      else dc.textOut(10, y, text(0x493158) + formatInteger(finish));
    }
  }
  const columns = [1, 2, 3, 4].map(multiplier => sub32(idiv32(imul32(width(), multiplier), 10), 10));
  if (r(0x4ac960) === 0) {
    const totals = new Int32Array(31);
    for (let boat = 1; boat <= r(0x49118c); boat++) {
      const scoreAddress = at(add32(0x4a6bc0, imul32(r(0x4ac944), 4)), boat - 1, 16);
      const score = imul32(r(at(0x4a764c, boat - 1)), 101); w(scoreAddress, score === 101 ? 100 : score);
      const point = at(0x4a6bc4, boat - 1, 16), race = r(0x4ac944);
      if (r(point) === 0 && race > 1) w(point, 3100);
      if (r(point + 4) === 0 && race > 2) w(point + 4, 3100);
      if (r(point + 8) === 0 && race === 3) w(point, 3100);
      const total = add32(add32(r(point + 8), r(point + 4)), r(point));
      totals[boat] = total; w(at(0x4a6db4, boat - 1), total);
    }
    sortSceneDepths(memory, 1);
    const headingY = sub32(y, line);
    const headings = [0x4930ac, 0x4930a4, 0x49309c, 0x493150, 0x49308c];
    const headingXs = [5, add32(columns[0], idiv32(width(), 30)), add32(columns[1], idiv32(width(), 50)), columns[2], sub32(columns[3], idiv32(width(), 50))];
    headings.forEach((address, index) => dc.textOut(headingXs[index], headingY, text(address)));
    if (r(0x49118c) > 15) {
      const secondColumn = sub32(idiv32(width(), 2), 10);
      headings.forEach((address, index) => dc.textOut(add32(secondColumn, headingXs[index]), headingY, text(address)));
    }
    const rightAlign = idiv32(width(), 18);
    for (let rank = 1; rank <= r(0x49118c); rank++) {
      const boat = r(at(0x4a4438, rank)); selectBoatTextColor(memory, dc, boat); w(at(0x4ac0c0, boat), rank);
      dc.textOut(add32(offset, 5), y, formatInteger(rank) + text(0x493080) + formatInteger(boat) + text(0x491d20));
      const point = at(0x4a6bb4, boat, 16);
      dc.textOut(add32(add32(columns[0], rightAlign), offset), y, formatInteger(idiv32(r(point), 100)));
      if (r(point + 4) > 0) dc.textOut(add32(add32(columns[1], rightAlign), offset), y, formatInteger(idiv32(r(point + 4), 100)));
      if (r(point + 8) > 0) dc.textOut(add32(add32(columns[2], rightAlign), offset), y, formatInteger(idiv32(r(point + 8), 100)));
      dc.textOut(add32(add32(columns[3], rightAlign), offset), y, formatInteger(idiv32(totals[boat], 100)));
      y = add32(y, line);
      if (rank === 15) { offset = sub32(idiv32(width(), 2), 10); y = initialY; }
    }
    if (r(0x4ac960) === 0 && r(0x4ac944) === 3 && r(0x491140) === 1) {
      dc.setTextColor(0);
      const skill = idiv32(imul32(add32(r(0x49118c), sub32(1, r(0x4ac0c4))), r(0x491190)), 30);
      const skillY = add32(add32(idiv32(line, 2), imul32(line, -9)), idiv32(imul32(height(), 6), 7));
      if (skill > 0) dc.textOut(10, skillY, text(0x493130) + formatInteger(skill));
    }
  }
  y = add32(add32(add32(idiv32(line, 2), imul32(line, -8)), idiv32(imul32(height(), 6), 7)), 10);
  if (r(0x4ac92c) === 0) dc.setTextColor(0xff);
  dc.textOut(10, y, text(0x4930e4)); y = add32(y, imul32(line, 2));
  if (r(0x4ac9bc) === 1) {
    const handle = memory.readU32(0x4a6dac); if (handle) dc.selectObject(handle);
    dc.rectangle(0, sub32(y, 4), width(), height()); dc.setBkColor(0x7f7f00); dc.setTextColor(0);
    dc.textOut(10, y, text(0x49306c)); y = add32(y, line);
    for (const [index, address, color] of [[0, 0x49305c, 0xffff], [1, 0x49304c, 0xff00], [2, 0x493038, 0xffffff], [3, 0x493024, 0x7f7f7f], [4, 0x493010, 0xff0000]]) {
      dc.setTextColor(color); dc.textOut(add32(idiv32(imul32(width(), index), 5), 10), y, text(address));
    }
    dc.setBkColor(0xffffff);
  }
}

/** Complete original tactical text wrapper; both unused arguments are retained. */
export function drawAdvice(memory, dc, left, top, right, bottom, _boat, _mode) {
  [left, top, right, bottom] = [left, top, right, bottom].map(i32);
  const line = memory.readI32(0x4a763c) < 700 ? 16 : 20;
  dc.pushClipRect(left, top, right, bottom); dc.selectStockObject(7); dc.selectStockObject(0);
  dc.rectangle(left, top, right, bottom); dc.setTextColor(0x7f0000);
  if (memory.readI32(0x4a7bd0) < sub32(170, memory.readI32(0x4a5f18))) drawTackingAdvice(memory, dc, top, left, line);
  else drawJibingAdvice(memory, dc, top, left, line);
  dc.popClipRect();
}

/** Complete 0x4064d0; rendering also clears all 20 original jibe counters. */
export function drawJibingAdvice(memory, dc, top, left, lineHeight) {
  [top, left, lineHeight] = [top, left, lineHeight].map(i32);
  const r = address => memory.readI32(address), text = address => readAnsiString(memory, address), x = add32(left, 5);
  let y = add32(top, lineHeight); dc.textOut(x, y, text(0x49147c)); y = add32(y, idiv32(lineHeight, 2));
  const factor = (global, label, positiveOnly = false) => {
    const value = r(global); if (positiveOnly ? value <= 0 : value === 0) return;
    y = add32(y, lineHeight); dc.textOut(x, y, text(label) + formatInteger(value));
  };
  for (const [global, label] of [[0x4a67d4, 0x491464], [0x4a67d8, 0x491448], [0x4a67dc, 0x491430],
    [0x4a67e0, 0x49141c], [0x4a67e4, 0x491404], [0x4a67e8, 0x4913ec], [0x4a67ec, 0x4913d0],
    [0x4a67f0, 0x4913d0], [0x4a67f4, 0x4913b4], [0x4a67f8, 0x49139c], [0x4a67fc, 0x49137c], [0x4a6800, 0x491360]]) factor(global, label);
  if (r(0x4a6804) === 1) { y = add32(y, lineHeight); dc.textOut(x, y, text(0x491348)); }
  factor(0x4a6808, 0x491334, true); factor(0x4a680c, 0x491324, true);
  if (r(0x4ac9ac) === 1) { factor(0x4a6810, 0x491308); factor(0x4a6814, 0x4912f0); }
  dc.textOut(x, idiv32(imul32(r(0x4a72d0), 6), 7), text(0x4912d4) + formatInteger(r(0x4a681c)));
  for (let global = 0x4a67d0; global < 0x4a6820; global += 4) memory.writeI32(global, 0);
}

/** Complete 0x406c90, preserving all stop reasons and factor presentation order. */
export function drawTackingAdvice(memory, dc, top, left, lineHeight) {
  [top, left, lineHeight] = [top, left, lineHeight].map(i32);
  const r = address => memory.readI32(address), text = address => readAnsiString(memory, address), x = add32(left, 5);
  let y = add32(top, lineHeight); dc.textOut(x, y, text(0x49187c)); y = add32(y, idiv32(lineHeight, 2));
  if (r(0x4aa668) > 0) { y = add32(y, lineHeight); dc.textOut(x, y, text(0x49186c)); }
  if (add32(r(0x4a4eb0), 5) < r(0x4a7bd0)) { dc.textOut(x, add32(y, lineHeight), text(0x491854)); return; }
  if (r(0x4a4bf0) > 0) y = add32(y, lineHeight);
  for (const [reason, label] of [[1, 0x491838], [2, 0x491814], [3, 0x4917f4], [4, 0x4917d0],
    [5, 0x4917ac], [6, 0x49178c], [7, 0x491768], [8, 0x49174c], [9, 0x491734]]) {
    if (r(0x4a4bf0) === reason) dc.textOut(x, y, text(label));
  }
  if (r(0x4a4bf0) > 0) return;
  const factor = (global, label) => {
    const value = r(global); if (value === 0) return;
    y = add32(y, lineHeight); dc.textOut(x, y, text(label) + formatInteger(value));
  };
  for (const [global, label] of [[0x4a4bf4, 0x491720], [0x4a4c64, 0x49170c], [0x4a4bf8, 0x4916e8],
    [0x4a4bfc, 0x4916d4], [0x4a4c00, 0x4916b8], [0x4a4c04, 0x49169c], [0x4a4c08, 0x491688],
    [0x4a4c0c, 0x491688], [0x4a4c10, 0x491688], [0x4a4c14, 0x491688], [0x4a4c18, 0x491678], [0x4a4c1c, 0x491678]]) factor(global, label);
  factor(0x4a4c20, r(0x4abc7c) < 1 ? 0x491650 : 0x491664);
  for (const [global, label] of [[0x4a4c24, 0x491630], [0x4a4c28, 0x491610], [0x4a4c2c, 0x4915f0],
    [0x4a4c30, 0x4915d0], [0x4a4c34, 0x4915bc], [0x4a4c38, 0x4915a4]]) factor(global, label);
  factor(0x4a4c3c, r(0x4a4c3c) < 1 ? 0x491574 : 0x49158c);
  for (const [global, label] of [[0x4a4c50, 0x491560], [0x4a4c54, 0x491560], [0x4a4c48, 0x491548],
    [0x4a4c4c, 0x491524], [0x4a4c58, 0x491510], [0x4a4c5c, 0x4914fc], [0x4a4c60, 0x4914e0],
    [0x4a4c68, 0x4914bc], [0x4a4c6c, 0x4914a0]]) factor(global, label);
  dc.textOut(x, idiv32(imul32(r(0x4a72d0), 6), 7), text(0x4912d4) + formatInteger(r(0x4a4c8c)));
}

/** Complete original 0x41d890 forecast, including its wind-history observer. */
export function drawForecastScreen(memory, dc, _rng, _options = {}) {
  const r = address => memory.readI32(address), text = address => readAnsiString(memory, address);
  const format = (address, ...values) => {
    let index = 0; return text(address).replace(/%d/g, () => formatInteger(values[index++]));
  };
  const compass = selector => {
    const north = text(0x49343c), south = text(0x49342c), east = text(0x493434), west = text(0x493424);
    return ['', north, north + east, east, south + east, south, south + west, west, north + west][selector] ?? '';
  };
  const color = value => { if (r(0x4ac92c) === 0) dc.setTextColor(value); };
  let line = 15, historyLine = 17;
  dc.selectStockObject(6); dc.selectStockObject(0); dc.rectangle(0, 0, r(0x4a763c), r(0x4a72d0));
  if (r(0x4a763c) > 700) { historyLine = 19; line = 17; }
  if (r(0x4a763c) > 900) { historyLine = 22; line = 20; }
  color(0x7f0000); dc.textOut(20, 25, text(0x493410));
  const weather = r(0x4a5b98), humidity = r(0x4a8a78);
  if (weather < 1 || humidity < 1) throw new RangeError('Original forecast leaves its weather text uninitialized for nonpositive selectors');
  const weatherAddress = weather === 1 ? 0x493404 : weather === 2 ? 0x4933f4 : 0x4933e8;
  const humidityAddress = humidity === 1 ? 0x4933d8 : humidity === 2 ? 0x4933c4 : 0x4933b4;
  dc.textOut(20, 60, text(weatherAddress) + text(humidityAddress));
  let y = add32(60, line), doubleLine = imul32(line, 2);
  dc.textOut(20, y, format(0x493398, r(0x4a7758))); y = add32(y, doubleLine);
  const pressure = text(r(0x4aa8bc) === 1 ? 0x493390 : 0x493388) + text(0x493374) + compass(r(0x4a8990)) + text(0x49300c);
  if (r(0x4ac998) === 0) dc.textOut(20, y, pressure);
  y = add32(y, line);
  dc.textOut(20, y, text(0x493364) + compass(r(0x4a5e88)) + format(0x49334c, sub32(r(0x4a70dc), 2), add32(r(0x4a70dc), 3)));
  y = add32(y, doubleLine); dc.textOut(20, y, format(0x493330, r(0x4a609c))); y = add32(y, line);
  if (r(0x4a79ec) > 4) dc.textOut(20, y, text(0x49331c));
  color(0x7f); y = add32(y, doubleLine); dc.textOut(20, y, text(0x49330c) + format(0x4932f8, r(0x4a4be4), r(0x4a5e84)));
  color(0x7f00); y = add32(y, line); dc.textOut(20, y, text(0x4932d4) + format(0x4932c8, r(0x4aa390)));
  y = add32(y, doubleLine);
  if (r(0x4ac1e0) === 1) { color(0x7f7f7f); dc.textOut(20, y, text(0x4932b8)); }
  else { color(0x7f7f); dc.textOut(20, y, text(0x4932a8)); }
  color(0x7f0000);
  if (r(0x4ac1dc) > 0) {
    y = add32(y, doubleLine);
    const high = r(0x4a796c), highNext = add32(high, 12) > 23 ? sub32(high, 12) : add32(high, 12);
    dc.textOut(20, y, text(0x493298) + format(0x493284, high, highNext)); y = add32(y, line);
    const low = r(0x4a8020), lowNext = add32(low, 12) > 23 ? sub32(low, 12) : add32(low, 12);
    dc.textOut(20, y, text(0x493274) + format(0x493284, low, lowNext)); y = add32(y, line);
    let tideDirection = '';
    for (const [selector, address] of [[4, 0x49324c], [1, 0x493244], [2, 0x49323c], [3, 0x493234]]) if (r(0x4aa804) === selector) tideDirection += text(address);
    dc.textOut(20, y, text(0x493254) + tideDirection); y = add32(y, line);
    dc.textOut(20, y, text(0x493220) + format(0x493210, idiv32(r(0x4ac1dc), 10), r(0x4ac1dc) % 10));
  }
  color(0xff); dc.textOut(20, add32(y, imul32(line, 3)), text(0x4918bc));
  color(0xff0000); dc.textOut(380, 25, text(0x4931ec));
  let tableY = add32(imul32(historyLine, 2), 40), offset = 0;
  for (let index = 0, hourFraction = 2, minute = 10; index < 10; index++, hourFraction++, minute = add32(minute, 5)) {
    const shift = sub32(r(0x4abc7c), idiv32(imul32(hourFraction, r(0x4abc7c)), 12));
    let direction = add32(sub32(sub32(idiv32(imul32(r(0x4aa590), r(0x4a9458 + index * 4)), 400), idiv32(r(0x4aa590), 8)), shift), r(0x4a4f8c));
    let speed = r(0x4a70f0);
    if (hourFraction % 3 === 0) {
      speed = add32(r(0x4a70f0), r(0x4a4e9c + offset)); direction = sub32(r(0x4ac0a4 + offset), shift); offset += 4;
    }
    dc.textOut(380, tableY, format(0x4931d8, sub32(r(0x4a5bac), 1), minute, speed));
    dc.textOut(510, tableY, format(0x4931d0, wrapDegreesOnce(direction))); tableY = add32(tableY, historyLine);
  }
  const variable = r(0x4a888c) === 1 ? 0 : 1;
  dc.textOut(380, add32(imul32(historyLine, 13), 40), text(0x4931b8) + formatInteger(imul32(variable + 1, r(0x49115c)))
    + text(0x4931b0) + formatInteger(imul32(variable + 3, r(0x49115c))) + text(0x4931a8));
  memory.writeI32(0x4aa838, sub32(r(0x4ac0a4), r(0x4a4f8c)));
}
