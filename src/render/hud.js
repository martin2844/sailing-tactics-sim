import { i32, add32, sub32, imul32, idiv32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { signedDegreesOnce, displayedTargetMark, formatInteger, formatDecimal, readAnsiString } from '../engine/hud-state.js';
import { targetRelativeBearing } from '../engine/target-bearing.js';
import { wrapDegreesOnce } from '../engine/integer-core.js';

export const HUD_ROUTINES = Object.freeze({ drawCompactHud: 0x40e9a0, drawSailingHud: 0x40c3b0,
  drawSteeringPanel: 0x409760, drawSecondPlayerControls: 0x40b990, drawTacticalPanel: 0x40db30 });
const at = (address, boat, stride = 4) => add32(address, imul32(boat, stride)) >>> 0;
const abs32 = value => value < 0 ? sub32(0, value) : value;
const f = (memory, address) => Float80.fromNumber(memory.readF64(address));
const integer = value => Float80.fromInteger(value);
const hudStrings = new WeakMap();
export const getHudText = memory => hudStrings.get(memory) ?? '';
function setHudText(memory, text) { hudStrings.set(memory, String(text)); }

/** Original button fill/outline selector, 0x44d990. */
export function drawHudButton(memory, dc, left, top, right, bottom, fill, orientation) {
  left = i32(left); top = i32(top); right = i32(right); bottom = i32(bottom);
  fill = i32(fill); orientation = i32(orientation);
  if (fill === 1) {
    const brush = memory.readU32(0x4a70e4);
    if (brush !== 0) dc.selectObject(brush);
  } else dc.selectStockObject(5);
  dc.selectStockObject(7);
  if (memory.readI32(0x4a763c) < 750) {
    dc.roundRect(left, top, right, bottom, 5, 5);
    return;
  }
  if (orientation === 1) dc.roundRect(add32(left, 2), add32(top, 1), add32(right, 3), bottom, 12, 12);
  if (orientation === 0) dc.roundRect(sub32(left, 2), add32(top, 1), sub32(right, 3), bottom, 12, 12);
  if (orientation === -1) dc.roundRect(left, top, right, bottom, 12, 12);
}

/** Complete compact instrument panel, original 0x40e9a0. */
export function drawCompactHud(memory, dc, left, top, right, bottom, boat, options = {}) {
  left = i32(left); top = i32(top); right = i32(right); bottom = i32(bottom); boat = i32(boat);
  const r = address => memory.readI32(address);
  const b = address => r(at(address, boat));
  const text = address => readAnsiString(memory, address);
  const lineHeight = idiv32(r(0x4a72d0), 31);
  dc.pushClipRect(left, top, right, bottom);
  const mark = displayedTargetMark(memory, boat);
  memory.writeI32(0x4aa7e0, mark);
  const bearing = targetRelativeBearing(memory, memory.readF64(at(0x4a52f0, mark, 8)),
    memory.readF64(at(0x4a60b0, mark, 8)), 0, boat);
  memory.writeI32(at(0x4aa6e0, boat), f(memory, 0x4a6828).multiply(f(memory, 0x484d70)).truncI32());
  memory.writeI32(0x4ac66c, signedDegreesOnce(sub32(bearing.multiply(f(memory, 0x484d78)).truncI32(), b(0x4ac018))));
  const distance = f(memory, 0x4a6828).truncI32();
  dc.selectStockObject(7); dc.selectStockObject(0); dc.rectangle(left, top, right, bottom);
  dc.setBkColor(0xffffff);
  if (r(0x4ac92c) === 0) {
    dc.setTextColor(0xff);
    if (r(0x4ac92c) === 0) dc.setTextColor(0x7f0000);
  }
  let value = formatDecimal(memory, f(memory, at(0x4a71c8, boat, 8)).multiply(f(memory, 0x484d48)).toNumber());
  const x = add32(left, 1);
  let y = add32(top, 1);
  dc.textOut(x, y, text(0x491e80));
  y = add32(y, lineHeight); dc.textOut(x, y, text(0x4911f0) + value);
  y = add32(y, lineHeight);
  const depth = f(memory, at(0x4a7f28, boat, 8));
  const depthThreshold = f(memory, 0x484d80);
  if (depth.compare(depthThreshold) <= 0) {
    if (r(0x4ac92c) === 0) dc.setTextColor(0xff);
    dc.textOut(x, y, text(0x491e1c) + formatInteger(depth.truncI32()));
    if (depth.compare(depthThreshold) < 0 && depthThreshold.compare(f(memory, at(0x4a4510, boat, 8))) < 0
      && r(0x4ac9c0) === 0) options.messageBeep?.(0);
  } else {
    if (r(0x4ac92c) === 0) dc.setTextColor(0xff0000);
    dc.textOut(x, y, text(0x49219c)); y = add32(y, lineHeight);
    if (b(0x4a7768) === 1) dc.textOut(x, y, text(0x492194));
    if (b(0x4a7768) === 2) dc.textOut(x, y, text(0x49218c));
    if (b(0x4a7768) === 3) dc.textOut(x, y, text(0x492184));
  }
  if (r(0x4ac92c) === 0) dc.setTextColor(0x7f0000);
  value = formatInteger(b(0x4a8aa8));
  dc.textOut(x, add32(y, lineHeight), text(0x492178));
  y = add32(add32(y, lineHeight), lineHeight);
  dc.textOut(x, y, text(0x4911f0) + value + text(0x491e4c));
  y = add32(y, lineHeight);
  if (r(0x4ac92c) === 0) dc.setTextColor(0x7f00);
  if (b(0x4a7868) === 0) dc.textOut(x, y, text(0x492170));
  else if (r(0x4ac92c) === 0) dc.setTextColor(0xff);
  if (b(0x4a7868) === 2 || b(0x4a7868) === 12) dc.textOut(x, y, text(0x492168));
  if (b(0x4a7868) === 3) dc.textOut(x, y, text(0x492160));
  y = add32(y, lineHeight);
  if (r(0x4ac92c) === 0) dc.setTextColor(0x7f0000);
  const windDifference = signedDegreesOnce(sub32(b(0x4aa5b0), r(0x4a4f8c)));
  const absoluteWindDifference = abs32(windDifference);
  memory.writeI32(0x4ac964, Number(absoluteWindDifference > 40));
  if (r(0x4ac978) === 0 && r(0x4ac964) === 0) {
    if (imul32(windDifference, b(0x4aa730)) > 0) dc.textOut(x, y, text(0x492158) + formatInteger(absoluteWindDifference));
    if (windDifference === 0) dc.textOut(x, y, text(0x492150));
    if (imul32(windDifference, b(0x4aa730)) < 0) {
      if (r(0x4ac978) === 0) dc.textOut(x, y, text(0x492148) + formatInteger(absoluteWindDifference));
      if (r(0x4a7bcc) < 55 && abs32(r(0x4ac66c)) > 45 && absoluteWindDifference > 10 && distance > 300 && boat === 1) {
        memory.writeI32(0x4a620c, 1);
      }
    }
  }
  y = add32(add32(y, 2), lineHeight); dc.setTextColor(0xff0000);
  if (b(0x4a8910) === 1 && b(0x4ac1e8) === 0) dc.textOut(x, y, text(0x49213c));
  if (b(0x4a8910) === 1 && b(0x4ac1e8) === 5) dc.textOut(x, y, text(0x492134));
  if (b(0x4a8910) === 1 && b(0x4ac1e8) === -5) dc.textOut(x, y, text(0x492128));
  if (b(0x4a4968) === 1) dc.textOut(x, y, text(0x492120));
  y = add32(y, lineHeight);
  if (r(0x4a5b80) > 0) {
    if (r(0x4ac92c) === 0) {
      dc.setTextColor(r(0x4aa7e0) === 3 || r(0x4aa7e0) === 5 ? 0x7f : 0x7f7f);
      if (r(0x4aa7e0) === 2) dc.setTextColor(0x7f7f);
    }
    const angle = r(0x4ac66c);
    if (angle > 0) dc.textOut(x, y, text(0x492118) + formatInteger(angle) + text(0x492110));
    if (angle < 0) dc.textOut(x, y, text(0x492118) + formatInteger(abs32(angle)) + text(0x492108));
    if (angle === 0) dc.textOut(x, y, text(0x4920fc));
  }
  if (boat === 1) drawSteeringPanel(memory, dc, left, top, right, bottom, 1, lineHeight, options);
  else drawSecondPlayerControls(memory, dc, left, top, right, bottom, boat, lineHeight, options);
  dc.setTextColor(0);
  dc.popClipRect();
}

function drawArrow(memory, dc, x, y, angle, divisor) {
  for (const [direction, scale] of [[angle, divisor], [sub32(angle, 30), imul32(divisor, 2)], [add32(angle, 30), imul32(divisor, 2)]]) {
    const wrapped = wrapDegreesOnce(direction);
    const sine = memory.readI32(at(0x4a54a0, wrapped)), cosine = memory.readI32(at(0x4a3450, wrapped));
    dc.moveTo(x, y); dc.lineTo(add32(x, idiv32(sine, scale)), sub32(y, idiv32(cosine, scale)));
  }
}

function cameraEyes(memory, dc, right, top, lineHeight, width, secondPlayer) {
  const mode = memory.readI32(secondPlayer ? 0x4a9448 : 0x4a9444);
  const offset = memory.readI32(secondPlayer ? 0x4a4610 : 0x4a460c);
  const y = add32(top, idiv32(lineHeight, 2));
  for (let eye = 1; eye <= 2; eye++) {
    let x = idiv32(eye === 1 ? add32(imul32(right, 4), imul32(width, -3)) : sub32(imul32(right, 4), width), 4);
    if (!secondPlayer) x = sub32(x, 2);
    const radius = idiv32(lineHeight, mode === 1 ? 4 : 3);
    const product = imul32(radius, 3);
    const mid = add32(product, (product >> 31) & 3) >> 2;
    const inner = sub32(mid, add32(product, (product >> 31) & 3) >> 31) >> 1;
    let pupilX = x;
    if (offset > 0 && mode === 0) pupilX = sub32(x, idiv32(lineHeight, 3));
    if (offset < 0 && mode === 0) pupilX = add32(pupilX, idiv32(lineHeight, 3));
    dc.selectStockObject(0);
    const outerX = imul32(radius, mode === 1 ? (secondPlayer ? 4 : 3) : 2);
    dc.ellipse(sub32(x, outerX), sub32(y, radius), add32(x, outerX), add32(y, radius));
    if (memory.readI32(0x4ac92c) === 0) {
      const brush = memory.readU32(0x4a469c);
      if (brush !== 0) dc.selectObject(brush);
    } else dc.selectStockObject(4);
    dc.ellipse(sub32(pupilX, mid), sub32(y, mid), add32(pupilX, mid), add32(y, mid));
    dc.selectStockObject(4);
    dc.ellipse(sub32(pupilX, inner), sub32(y, inner), add32(pupilX, inner), add32(y, inner));
  }
}

function cameraButton(memory, dc, borderLeft, textLeft, right, top, bottom, label, extraBottomLine = false) {
  drawHudButton(memory, dc, borderLeft, top, right, bottom, 1, 0);
  dc.textOut(textLeft, top, readAnsiString(memory, label));
  dc.selectStockObject(6); dc.moveTo(textLeft, top); dc.lineTo(sub32(right, 2), top);
  if (extraBottomLine) { dc.moveTo(textLeft, add32(bottom, 1)); dc.lineTo(sub32(right, 2), add32(bottom, 1)); }
  drawHudButton(memory, dc, borderLeft, top, right, bottom, 0, 0);
}

/** Original primary camera controls including their click/hover state, 409760. */
export function drawSteeringPanel(memory, dc, left, top, right, bottom, boat, lineHeight, options = {}) {
  left = i32(left); top = i32(top); right = i32(right); bottom = i32(bottom); boat = i32(boat); lineHeight = i32(lineHeight);
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  dc.setBkMode(1);
  const short = r(0x4a763c) < 700 || (r(0x4a763c) < 900 && r(0x4a5264) > 0);
  const width = integer(r(0x4a763c)).multiply(f(memory, 0x484d50)).truncI32();
  const textLeft = sub32(right, width), borderLeft = sub32(textLeft, 2);
  let y = add32(top, lineHeight);
  dc.setBkColor(0x7f7f7f); dc.setTextColor(0);
  drawHudButton(memory, dc, borderLeft, top, right, y, 1, 0); dc.selectStockObject(7);
  cameraEyes(memory, dc, right, top, lineHeight, width, false);
  const inside = (xAddress, yAddress, upper, lower) => textLeft < r(xAddress) && r(xAddress) < right && upper < r(yAddress) && r(yAddress) < lower;
  const tooltip = address => { setHudText(memory, readAnsiString(memory, address)); w(0x4ac9dc, 1); };
  const buttons = [
    { label: 0x491c18, selected: () => r(0x4a460c) === 0 && r(0x4a9444) === 0, tip: short ? 0x491bcc : 0x491bf0, click: () => { w(0x4a460c, 0); w(0x4a9444, 0); w(0x4aa97c, 0); } },
    { label: 0x491bc4, selected: () => r(0x4a460c) >= 1 && r(0x4a460c) !== 180 && r(0x4a9444) === 0, tip: short ? 0x491b74 : 0x491b98, click: () => { w(0x4a460c, add32(r(0x4a460c), 30)); w(0x4a9444, 0); w(0x4aa97c, 0); } },
    { label: 0x491b6c, selected: () => r(0x4a460c) < 0 && r(0x4a9444) === 0, tip: short ? 0x491b24 : 0x491b44, click: () => { w(0x4a460c, sub32(r(0x4a460c), 30)); w(0x4a9444, 0); w(0x4aa97c, 0); } },
    { label: 0x491b1c, selected: () => r(0x4a460c) === 180 && r(0x4a9444) === 0, tip: short ? 0x491ad4 : 0x491af4, click: () => { w(0x4a460c, 180); w(0x4a9444, 0); w(0x4aa97c, 0); } },
    { label: 0x491acc, selected: () => r(0x4a9444) === 1, tip: 0x491aac, color: 0xffff, click: () => { w(0x4a9444, 1); w(0x4aa97c, 0); w(0x4a460c, 0); } },
    { label: 0x491aa4, selected: () => r(0x4a9444) === -1, tip: 0x491a80, color: 0xffff, click: () => { w(0x4a9444, -1); w(0x4aa97c, 0); w(0x4a460c, 0); } },
  ];
  for (const button of buttons) {
    const lower = add32(y, lineHeight);
    dc.setTextColor(button.selected() ? 0 : r(0x4ac92c) === 0 ? button.color ?? 0xffff00 : 0xffffff);
    cameraButton(memory, dc, borderLeft, textLeft, right, y, lower, button.label);
    if (inside(0x4ac9e0, 0x4ac9e4, y, lower)) tooltip(button.tip);
    if (inside(0x4a774c, 0x4aa97c, sub32(lower, lineHeight), lower)) button.click();
    y = lower;
  }
  if (r(0x491140) === 2 || r(0x49118c) === 2) {
    const lower = add32(y, lineHeight);
    dc.setTextColor(r(0x4a9444) === 100 ? 0 : r(0x4ac92c) === 0 ? 0xffff00 : 0xffffff);
    cameraButton(memory, dc, borderLeft, textLeft, right, y, lower, 0x491a78, true);
    if (inside(0x4ac9e0, 0x4ac9e4, y, lower)) tooltip(0x491a54);
    if (inside(0x4a774c, 0x4aa97c, sub32(lower, lineHeight), lower)) { w(0x4a9444, 100); w(0x4aa97c, 0); w(0x4a460c, 0); }
    y = lower;
  }
  if (r(0x491140) === 2) drawPlayer1Controls(memory, dc, left, sub32(y, lineHeight), right, bottom, boat, lineHeight, options);
}

/** Original second-player camera column, 40b990. Its buttons have no mouse writes. */
export function drawSecondPlayerControls(memory, dc, left, top, right, bottom, boat, _lineHeight, options = {}) {
  left = i32(left); top = i32(top); right = i32(right); bottom = i32(bottom); boat = i32(boat);
  const r = address => memory.readI32(address), lineHeight = idiv32(r(0x4a72d0), 31);
  dc.setBkMode(1);
  const width = sub32(2, integer(r(0x4a763c)).multiply(f(memory, 0x484d68)).truncI32());
  const textLeft = sub32(right, width), borderLeft = sub32(textLeft, 2);
  let y = add32(top, lineHeight);
  drawHudButton(memory, dc, borderLeft, top, right, y, 1, 0);
  dc.setBkColor(0x7f7f7f); dc.setTextColor(0); dc.selectStockObject(7);
  cameraEyes(memory, dc, right, top, lineHeight, width, true);
  const selected = [() => r(0x4a4610) === 0 && r(0x4a9448) === 0,
    () => r(0x4a4610) >= 1 && r(0x4a4610) !== 180 && r(0x4a9448) === 0,
    () => r(0x4a4610) < 0 && r(0x4a9448) === 0, () => r(0x4a4610) === 180 && r(0x4a9448) === 0,
    () => r(0x4a9448) === 1, () => r(0x4a9448) === -1, () => r(0x4a9448) === 100];
  for (const [index, label] of [0x491c18, 0x491bc4, 0x491b6c, 0x491b1c, 0x491cfc, 0x491cf4, 0x491ce8].entries()) {
    const lower = add32(y, lineHeight);
    dc.setTextColor(selected[index]() ? 0 : r(0x4ac92c) === 0 ? index === 4 || index === 5 ? 0xffff : 0xffff00 : 0xffffff);
    cameraButton(memory, dc, borderLeft, textLeft, right, y, lower, label, index === 6);
    if (index < 4) {
      const pen = memory.readU32(0x4a4dec); if (pen !== 0) dc.selectObject(pen);
      if (index === 0) drawArrow(memory, dc, sub32(sub32(right, idiv32(r(0x4a763c), 130)), 2), add32(y, 2), 180, 10);
      if (index === 1) drawArrow(memory, dc, sub32(sub32(right, idiv32(r(0x4a763c), 50)), 2), add32(idiv32(lineHeight, 2), y), 90, 10);
      if (index === 2) drawArrow(memory, dc, sub32(right, 3), add32(idiv32(lineHeight, 2), y), 270, 10);
      if (index === 3) drawArrow(memory, dc, sub32(sub32(right, idiv32(r(0x4a763c), 130)), 2), sub32(lower, 1), 0, 10);
      dc.selectStockObject(7);
    }
    y = lower;
  }
  drawPlayer2Controls(memory, dc, left, sub32(y, lineHeight), right, bottom, boat, lineHeight, options);
}

function lowerControlLayout(memory, left, top, right, lineHeight) {
  const first = sub32(idiv32(add32(right, imul32(left, 2)), 3), idiv32(memory.readI32(0x4a763c), 200));
  const second = idiv32(add32(left, imul32(right, 2)), 3);
  return { first, second, y: add32(sub32(top, 2), idiv32(imul32(lineHeight, 7), 2)) };
}
function lowerButton(memory, dc, left, top, right, bottom, x, label) {
  drawHudButton(memory, dc, left, top, right, bottom, 1, -1);
  dc.textOut(x, top, readAnsiString(memory, label));
  drawHudButton(memory, dc, left, top, right, bottom, 0, -1);
}
function lowerSeam(dc, left, right, y) { dc.selectStockObject(6); dc.moveTo(add32(left, 1), y); dc.lineTo(sub32(right, 1), y); }

/** Original keyboard-labelled second-player control strip, 40b130. */
export function drawPlayer2Controls(memory, dc, left, top, right, _bottom, _boat, lineHeight) {
  left = i32(left); top = i32(top); right = i32(right); lineHeight = i32(lineHeight);
  const r = address => memory.readI32(address), color = value => r(0x4ac92c) === 0 ? value : 0xffffff;
  const { first, second, y: initialY } = lowerControlLayout(memory, left, top, right, lineHeight);
  let y = initialY, lower = add32(y, lineHeight);
  const brush = memory.readU32(0x4a70e4); if (brush !== 0) dc.selectObject(brush);
  dc.setTextColor(color(0xffff)); lowerButton(memory, dc, left, y, first, lower, add32(left, 1), 0x491ce0);
  dc.setTextColor(color(0xffff)); lowerButton(memory, dc, first, y, second, lower, add32(first, 1), 0x491cd8);
  dc.setTextColor(r(0x4a8918) === 1 || r(0x4a4e00) === -1 ? 0 : color(0xffff));
  lowerButton(memory, dc, second, y, right, lower, add32(second, 1), 0x491cd0);
  lowerSeam(dc, left, right, lower);
  y = add32(lower, 1); lower = add32(y, lineHeight);
  drawHudButton(memory, dc, left, y, first, lower, 1, -1);
  if (r(0x4a4e00) === 1 || r(0x4abfa0) === 1) dc.setTextColor(0);
  else {
    dc.setTextColor(color(r(0x4a7bd0) < 90 ? 0xffff00 : 0xffffff));
    if (r(0x4ac92c) === 0 && r(0x4a7bd0) > 89) dc.setTextColor(0xff00);
  }
  dc.textOut(add32(left, 1), y, readAnsiString(memory, r(0x4a7bd0) < 90 ? 0x491cc8 : 0x491cc0));
  drawHudButton(memory, dc, left, y, first, lower, 0, -1);
  drawHudButton(memory, dc, first, y, second, lower, 1, -1);
  dc.setTextColor(r(0x4a6850) < 2 ? color(0xffff00) : 0);
  dc.textOut(add32(first, 1), y, readAnsiString(memory, 0x491cb8));
  drawHudButton(memory, dc, first, y, second, lower, 0, -1);
  drawHudButton(memory, dc, second, y, right, lower, 1, -1);
  dc.setTextColor(r(0x4a6850) === 1 || r(0x4a4970) === 1 ? 0 : color(0xffff00));
  dc.textOut(add32(second, 1), y, readAnsiString(memory, 0x491cb0));
  drawHudButton(memory, dc, second, y, right, lower, 0, -1);
  lowerSeam(dc, left, right, lower);
  y = add32(lower, 1); lower = add32(y, lineHeight);
  if (r(0x4ac92c) === 0) dc.setTextColor(0xffff);
  drawHudButton(memory, dc, left, y, first, lower, 1, -1);
  if ((r(0x4a438c) <= 0 && r(0x4a7bd0) <= 90) || r(0x4a5b80) < 1) {
    if (r(0x4a85d8) < 50) { dc.setTextColor(color(0x7f)); dc.textOut(add32(left, 1), y, readAnsiString(memory, 0x491c98)); }
    else { dc.setTextColor(color(0xff00)); dc.textOut(r(0x4a763c) < 701 ? left : add32(left, 1), y, readAnsiString(memory, 0x491c90)); }
  } else {
    dc.setTextColor(color(0xffff)); if (r(0x4abb78) > 0) dc.setTextColor(0);
    if (r(0x491188) > 2) dc.textOut(add32(left, 1), y, readAnsiString(memory, 0x491ca8));
    if (r(0x491188) === 2) dc.textOut(add32(left, 1), y, readAnsiString(memory, 0x491ca0));
  }
  drawHudButton(memory, dc, left, y, first, lower, 0, -1);
  drawHudButton(memory, dc, first, y, second, lower, 1, -1);
  if (r(0x4ac92c) === 0) dc.setTextColor(0xffffff);
  dc.textOut(add32(first, 1), y, readAnsiString(memory, 0x491c88));
  drawHudButton(memory, dc, first, y, second, lower, 0, -1);
  drawHudButton(memory, dc, second, y, right, lower, 1, -1);
  if (r(0x4ac92c) === 0) dc.setTextColor(0xffff00);
  dc.textOut(add32(second, 1), y, readAnsiString(memory, 0x491c80));
  drawHudButton(memory, dc, second, y, right, lower, 0, -1);
  lowerSeam(dc, left, right, lower);
}

/** Original mouse-enabled primary lower control strip, 40a360. */
export function drawPlayer1Controls(memory, dc, left, top, right, _bottom, _boat, lineHeight) {
  left = i32(left); top = i32(top); right = i32(right); lineHeight = i32(lineHeight);
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const color = value => r(0x4ac92c) === 0 ? value : 0xffffff;
  const { first, second, y: initialY } = lowerControlLayout(memory, left, top, right, lineHeight);
  let y = initialY, lower = add32(y, lineHeight);
  const clicked = (a, b) => a < r(0x4a774c) && r(0x4a774c) < b && y < r(0x4aa97c) && r(0x4aa97c) < lower;
  const redraw = (x, label, selectedColor = 0) => { dc.setTextColor(selectedColor); dc.textOut(x, y, readAnsiString(memory, label)); };
  const clearSteering = () => { for (const address of [0x4a8914, 0x4a774c, 0x4aa97c, 0x4a4dfc, 0x4abf9c, 0x4a496c, 0x4a684c]) w(address, 0); };
  const brush = memory.readU32(0x4a70e4); if (brush !== 0) dc.selectObject(brush);
  dc.setTextColor(color(0xffff)); lowerButton(memory, dc, left, y, first, lower, add32(left, 3), 0x491c78);
  if (clicked(left, first)) { memory.writeF64(0x4a78e8, f(memory, 0x4a78e8).subtract(f(memory, 0x484d58)).toNumber()); clearSteering(); redraw(add32(left, 3), 0x491c78); }
  dc.setTextColor(color(0xffff)); lowerButton(memory, dc, first, y, second, lower, add32(first, 3), 0x491c70);
  if (clicked(first, second)) { memory.writeF64(0x4a78e8, f(memory, 0x4a78e8).subtract(f(memory, 0x484d60)).toNumber()); clearSteering(); redraw(add32(first, 3), 0x491c70); }
  dc.setTextColor(r(0x4a8914) === 1 || r(0x4a4dfc) === -1 ? 0 : color(0xffff));
  lowerButton(memory, dc, second, y, right, lower, add32(second, 3), 0x491c68);
  if (clicked(second, right)) { w(0x4a4dfc, -1); for (const address of [0x4abf9c, 0x4ac1ec, 0x4a8914, 0x4a496c, 0x4a684c]) w(address, 0); }
  lowerSeam(dc, left, right, lower);
  y = add32(lower, 1); lower = add32(y, lineHeight);
  if (r(0x4a4dfc) === 1 || r(0x4abf9c) === 1) dc.setTextColor(0);
  else { dc.setTextColor(color(r(0x4a7bcc) < 90 ? 0xffff00 : 0xffffff)); if (r(0x4ac92c) === 0 && r(0x4a7bcc) > 89) dc.setTextColor(0xff00); }
  lowerButton(memory, dc, left, y, first, lower, add32(left, 3), r(0x4a7bcc) < 90 ? 0x491c60 : 0x491c58);
  if (clicked(left, first)) {
    if (r(0x4a7bcc) < 90) { w(0x4a4dfc, 1); w(0x4a46ac, 1); w(0x4a41f4, r(0x4a5b80)); w(0x4abf9c, 0); }
    else { w(0x4abf9c, 1); w(0x4a4dfc, 0); }
    for (const address of [0x4a8914, 0x4a496c, 0x4a684c]) w(address, 0);
  }
  dc.setTextColor(r(0x4a684c) < 2 ? color(0xffff00) : 0);
  drawHudButton(memory, dc, first, y, second, lower, 1, -1); dc.textOut(add32(first, 2), y, readAnsiString(memory, 0x491c50));
  if (clicked(first, second)) { w(0x4a684c, Number(r(0x4a7bcc) > 89) + 2); for (const address of [0x4a8914, 0x4a496c, 0x4a4dfc, 0x4abf9c]) w(address, 0); }
  drawHudButton(memory, dc, first, y, second, lower, 0, -1);
  drawHudButton(memory, dc, second, y, right, lower, 1, -1); dc.setTextColor(r(0x4a684c) === 1 || r(0x4a496c) === 1 ? 0 : color(0xffff00));
  dc.textOut(add32(second, 3), y, readAnsiString(memory, 0x491c4c)); drawHudButton(memory, dc, second, y, right, lower, 0, -1);
  if (clicked(second, right)) { w(0x4a684c, 1); for (const address of [0x4a8914, 0x4a496c, 0x4a4dfc, 0x4abf9c]) w(address, 0); }
  lowerSeam(dc, left, right, lower);
  y = add32(lower, 1); lower = add32(y, lineHeight);
  if (r(0x4ac92c) === 0) dc.setTextColor(0xffff);
  drawHudButton(memory, dc, left, y, first, lower, 1, -1);
  if ((r(0x4a4388) > 0 || r(0x4a7bcc) > 90) && r(0x4a5b80) > 0) {
    dc.setTextColor(color(0xffff)); if (r(0x4abb74) > 0) dc.setTextColor(0);
    if (r(0x491188) > 2) dc.textOut(add32(left, 3), y, readAnsiString(memory, 0x491c44));
    if (r(0x491188) === 2) dc.textOut(add32(left, 3), y, readAnsiString(memory, 0x491c3c));
    if (clicked(left, first) && r(0x491188) > 1) {
      w(0x4a4388, add32(r(0x4a4388), 1)); if (r(0x4a4388) > 1) w(0x4a4388, 0);
      dc.setTextColor(0);
      if (r(0x491188) > 2) dc.textOut(add32(left, 3), y, readAnsiString(memory, 0x491c44));
      if (r(0x491188) === 2) dc.textOut(add32(left, 3), y, readAnsiString(memory, 0x491c3c));
    }
  } else if (r(0x4a85d4) < 50) {
    dc.setTextColor(color(0x7f)); dc.textOut(add32(left, 3), y, readAnsiString(memory, 0x491c34));
    if (clicked(left, first)) { w(0x4a85d4, 90); redraw(add32(left, 3), 0x491c34, 0xffffff); }
  } else {
    dc.setTextColor(color(0xff00)); dc.textOut(add32(left, 1), y, readAnsiString(memory, 0x491c30));
    if (clicked(left, first)) { w(0x4a85d4, -1); redraw(add32(left, 1), 0x491c30, 0xffffff); }
  }
  drawHudButton(memory, dc, left, y, first, lower, 0, -1);
  drawHudButton(memory, dc, first, y, second, lower, 1, -1); dc.setTextColor(0xffffff); dc.textOut(add32(first, 2), y, readAnsiString(memory, 0x491c28));
  if (clicked(first, second)) { w(0x4a776c, add32(r(0x4a776c), 1)); if (r(0x4a776c) > 3) w(0x4a776c, 1); redraw(add32(first, 2), 0x491c28); }
  drawHudButton(memory, dc, first, y, second, lower, 0, -1);
  drawHudButton(memory, dc, second, y, right, lower, 1, -1); dc.setTextColor(color(0xffff00)); dc.textOut(add32(second, 3), y, readAnsiString(memory, 0x491c20));
  drawHudButton(memory, dc, second, y, right, lower, 0, -1);
  if (clicked(second, right)) { w(0x4a4e8c, add32(r(0x4a4e8c), 1)); if (r(0x4a4e8c) > 3) w(0x4a4e8c, 1); w(0x4aae24, 0); redraw(add32(second, 3), 0x491c20); }
  lowerSeam(dc, left, right, lower); w(0x4aa97c, 0);
}

/** Complete original tactical control column, 0x40db30. */
export function drawTacticalPanel(memory, dc, left, top, right, columnRight, boat, lineHeight) {
  left = i32(left); top = i32(top); right = i32(right); columnRight = i32(columnRight); boat = i32(boat); lineHeight = i32(lineHeight);
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const color = value => r(0x4ac92c) === 0 ? value : 0xffffff;
  const short = r(0x4a763c) < 700 || (r(0x4a763c) < 900 && r(0x4a5264) > 0);
  if (r(0x4ac9c8) === 1 && r(at(0x4a4e88, boat)) < 3) columnRight = idiv32(add32(right, imul32(left, 6)), 7);
  let y = add32(top, 1), lower = add32(y, lineHeight);
  const inside = (xAddress, yAddress) => left < r(xAddress) && r(xAddress) < columnRight && y < r(yAddress) && r(yAddress) < lower;
  const clicked = () => inside(0x4a774c, 0x4aa97c), hovered = () => inside(0x4ac9e0, 0x4ac9e4);
  const tip = address => { setHudText(memory, readAnsiString(memory, address)); w(0x4ac9dc, 1); };
  const label = (address, offset = 4) => dc.textOut(add32(left, offset), y, readAnsiString(memory, address));
  const fill = () => drawHudButton(memory, dc, left, y, columnRight, lower, 1, 1);
  const outline = () => { dc.selectStockObject(6); dc.moveTo(add32(left, 1), y); dc.lineTo(columnRight, y); drawHudButton(memory, dc, left, y, columnRight, lower, 0, 1); };
  const next = () => { y = lower; lower = add32(y, lineHeight); };
  const clear = () => { for (const address of [0x4a8914, 0x4a496c, 0x4a4dfc, 0x4abf9c]) w(address, 0); };
  dc.setBkColor(0x7f7f7f);
  dc.setTextColor(r(0x4a8914) === 1 || r(0x4a4dfc) === -1 ? 0 : color(0xffff));
  fill(); label(0x491c68); outline();
  if (clicked()) { w(0x4a4dfc, -1); for (const address of [0x4abf9c, 0x4ac1ec, 0x4a8914, 0x4a496c, 0x4a684c]) w(address, 0); }
  if (hovered()) tip(short ? 0x4920c0 : 0x4920d4);
  next();
  if (r(0x4a4dfc) === 1 || r(0x4abf9c) === 1) dc.setTextColor(0);
  else {
    dc.setTextColor(color(r(0x4a7bcc) < 90 ? 0xffff : 0xffffff));
    if (r(0x4ac92c) === 0 && r(0x4a7bcc) > 89) dc.setTextColor(0xff00);
  }
  fill(); label(r(0x4a7bcc) < 90 ? 0x491c60 : 0x491c58);
  if (clicked()) {
    if (r(0x4a7bcc) < 90) {
      w(0x4a4dfc, 1); w(0x4abf9c, 0); w(0x4a46ac, 1); w(0x4a41f4, r(0x4a5b80));
    } else { w(0x4abf9c, 1); w(0x4a4dfc, 0); }
    for (const address of [0x4a8914, 0x4a496c, 0x4a684c]) w(address, 0);
  }
  if (hovered()) tip(r(0x4a7bcc) < 90 ? (short ? 0x49207c : 0x492098) : (short ? 0x492034 : 0x492054));
  outline(); next();
  dc.setTextColor(r(0x4a684c) < 2 ? color(0xffff00) : 0);
  fill(); label(0x491c50); outline();
  if (clicked()) { w(0x4a684c, Number(r(0x4a7bcc) > 89) + 2); clear(); }
  if (hovered()) tip(0x49201c);
  next();
  dc.setTextColor(r(0x4a684c) === 1 || r(0x4a496c) === 1 ? 0 : color(0xffff00));
  fill(); label(0x491c4c); outline();
  if (clicked()) { w(0x4a684c, 1); clear(); }
  if (hovered()) tip(short ? 0x491fe4 : 0x492000);
  next(); fill();
  if ((r(0x4a4388) <= 0 && r(0x4a7bcc) <= 90) || r(0x4a5b80) < 1) {
    if (r(0x4a85d4) < 50) {
      dc.setTextColor(color(0x7f)); label(0x491c34);
      if (clicked()) { w(0x4a85d4, 90); dc.setTextColor(0); label(0x491c34); }
      if (hovered()) tip(0x491f90);
    } else {
      dc.setTextColor(color(0xff00)); label(0x491c30, 1);
      if (clicked()) { w(0x4a85d4, -1); dc.setTextColor(0); label(0x491c30, 1); }
      if (hovered()) tip(short ? 0x491f54 : 0x491f70);
    }
  } else {
    dc.setTextColor(r(0x4abb74) === 1 ? 0 : color(0xffff));
    if (r(0x491188) > 2) label(0x491c44);
    if (r(0x491188) === 2) label(0x491c3c);
    if (clicked() && r(0x491188) > 1) { w(0x4a4388, add32(r(0x4a4388), 1)); if (r(0x4a4388) > 1) w(0x4a4388, 0); }
    if (hovered()) {
      if (r(0x491188) > 2 && r(0x491188) !== 9) tip(r(0x4abb74) === 0 ? 0x491fd4 : 0x491fc4);
      if (r(0x491188) === 2 || r(0x491188) === 9) tip(r(0x4abb74) === 0 ? 0x491fb8 : 0x491fac);
    }
  }
  if (r(0x4ac92c) === 0) dc.setTextColor(0xffffff);
  outline(); next(); fill(); label(0x491c28); outline();
  if (clicked()) {
    w(0x4a776c, add32(r(0x4a776c), 1)); if (r(0x4a776c) > 3) w(0x4a776c, 1);
    dc.setTextColor(0); label(0x491c28);
  }
  if (hovered()) {
    if (r(0x4a776c) === 1) setHudText(memory, readAnsiString(memory, 0x491f3c));
    if (r(0x4a776c) === 2) setHudText(memory, readAnsiString(memory, 0x491f24));
    if (r(0x4a776c) === 3) setHudText(memory, readAnsiString(memory, 0x491f0c));
    w(0x4ac9dc, 1);
  }
  next(); if (r(0x4ac92c) === 0) dc.setTextColor(0xffff00);
  fill(); label(0x491c20); outline();
  if (clicked()) {
    w(0x4a4e8c, add32(r(0x4a4e8c), 1)); if (r(0x4a4e8c) > 3) w(0x4a4e8c, 1); w(0x4aae24, 0);
    dc.setTextColor(0); label(0x491c20);
  }
  if (hovered()) {
    if (r(0x4a4e8c) === 1) setHudText(memory, readAnsiString(memory, 0x491ef4));
    if (r(0x4a4e8c) === 2) setHudText(memory, readAnsiString(memory, 0x491edc));
    if (r(0x4a4e8c) === 3) setHudText(memory, readAnsiString(memory, 0x491ec0));
    w(0x4ac9dc, 1);
  }
  w(0x4aa97c, 0);
}

/** Original explanation strip, 44db20: CDC plus lineHeight, left and textX. */
export function drawHudExplanation(memory, dc, lineHeight, left, textX) {
  if (memory.readI32(0x4911a4) === 0) return;
  dc.setTextColor(memory.readI32(0x4ac92c) === 0 ? 0x7f7f00 : 0);
  if (memory.readI32(0x4a763c) < 700) textX = add32(left, 1);
  dc.setBkMode(2); dc.setBkColor(0xffffff);
  dc.textOut(textX, sub32(sub32(memory.readI32(0x4aa824), idiv32(memory.readI32(0x4a72d0), 50)), lineHeight), getHudText(memory));
  dc.setBkMode(1);
}

/** Complete original primary instrument display and steering zone, 0x40c3b0. */
export function drawSailingHud(memory, dc, left, top, right, bottom, boat, options = {}) {
  left = i32(left); top = i32(top); right = i32(right); bottom = i32(bottom); boat = i32(boat);
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const b = address => r(at(address, boat));
  const text = address => readAnsiString(memory, address);
  const lineHeight = idiv32(r(0x4a72d0), 30);
  dc.pushClipRect(left, top, right, bottom);
  setHudText(memory, text(0x4aca50)); w(0x4ac9dc, 0);
  w(0x4a70ec, idiv32(add32(right, left), 2));
  w(0x4aa824, idiv32(add32(top, imul32(bottom, 4)), 5));
  const columnRight = r(0x4ac9c8) === 1 && b(0x4a4e88) < 3
    ? idiv32(add32(right, imul32(left, 3)), 4)
    : idiv32(add32(right, imul32(left, 4)), 5);
  const x = add32(columnRight, r(0x4ac9c8) === 1 && b(0x4a4e88) < 3 ? 10 : 5);
  dc.selectStockObject(7);
  const pen = memory.readU32(0x4a4dec); if (pen !== 0) dc.selectObject(pen);
  dc.selectStockObject(0); dc.rectangle(left, top, right, bottom);
  drawSteeringPanel(memory, dc, left, top, right, bottom, boat, lineHeight, options);
  drawTacticalPanel(memory, dc, left, top, right, columnRight, boat, lineHeight);
  let y = add32(top, 1), distance;
  dc.setBkColor(0xffffff); dc.setTextColor(r(0x4ac92c) === 0 ? 0xff : 0);
  if (r(0x4a5b80) < 1) {
    dc.textOut(x, y, formatInteger(abs32(r(0x4a5e84))) + text(0x491eb8) + formatInteger(abs32(r(0x4a6778))) + text(0x491eb0));
    y = add32(y, imul32(lineHeight, 2));
  }
  if (r(0x4a5b80) > 0) {
    const mark = displayedTargetMark(memory, boat); w(0x4aa7e0, mark);
    const bearing = targetRelativeBearing(memory, memory.readF64(at(0x4a52f0, mark, 8)), memory.readF64(at(0x4a60b0, mark, 8)), 0, boat);
    w(0x4aa6e4, f(memory, 0x4a6828).multiply(f(memory, 0x484d70)).truncI32());
    w(0x4ac66c, signedDegreesOnce(sub32(bearing.multiply(f(memory, 0x484d78)).truncI32(), b(0x4ac018))));
    distance = f(memory, 0x4a6828).truncI32();
    if (r(0x4ac92c) === 0) {
      dc.setTextColor(mark === 3 || mark === 5 ? 0x7f : 0x7f7f);
      if (mark === 2) dc.setTextColor(0x7f7f7f);
    }
    dc.textOut(x, y, text(0x491ea8)); y = add32(y, lineHeight); w(0x4a6770, r(0x4ac66c));
    if (r(0x4ac66c) > 0) dc.textOut(add32(x, 10), y, formatInteger(r(0x4ac66c)) + text(0x491e98));
    if (r(0x4ac66c) < 0) dc.textOut(add32(x, 10), y, formatInteger(abs32(r(0x4ac66c))) + text(0x491e88));
    if (r(0x4ac66c) === 0) dc.textOut(add32(x, 10), y, text(0x491c18));
    y = add32(y, lineHeight);
  }
  if (r(0x4ac92c) === 0) dc.setTextColor(0x7f0000);
  dc.textOut(x, y, text(0x491e80) + formatDecimal(memory, f(memory, at(0x4a71c8, boat, 8)).multiply(f(memory, 0x484d48)).toNumber()));
  y = add32(y, lineHeight);
  if (r(0x4ac92c) === 0) dc.setTextColor(0x7f00);
  if (b(0x4a7868) === 0) dc.textOut(x, y, text(0x491e74));
  else if (r(0x4ac92c) === 0) dc.setTextColor(0xff);
  if (b(0x4a7868) === 2 || b(0x4a7868) === 12) dc.textOut(x, y, text(0x491e68));
  if (b(0x4a7868) === 3) dc.textOut(x, y, text(0x491e5c));
  y = add32(y, lineHeight);
  if (r(0x4ac92c) === 0) dc.setTextColor(0x7f0000);
  dc.textOut(x, y, text(0x491e50) + formatInteger(b(0x4a8aa8)) + text(0x491e4c));
  y = add32(y, lineHeight);
  const depth = f(memory, at(0x4a7f28, boat, 8)), threshold = f(memory, 0x484d80);
  if (depth.compare(threshold) <= 0) {
    if (r(0x4ac92c) === 0) dc.setTextColor(0xff);
    dc.textOut(x, y, text(0x491e1c) + formatInteger(depth.truncI32()));
    if (depth.compare(threshold) < 0 && threshold.compare(f(memory, at(0x4a4510, boat, 8))) < 0 && r(0x4ac9c0) === 0) options.messageBeep?.(0);
  } else {
    if (r(0x4ac92c) === 0) dc.setTextColor(0xff0000);
    if (b(0x4a7768) === 1) dc.textOut(x, y, text(0x491e40));
    if (b(0x4a7768) === 2) dc.textOut(x, y, text(0x491e30));
    if (b(0x4a7768) === 3) dc.textOut(x, y, text(0x491e24));
  }
  y = add32(y, lineHeight);
  if (r(0x4ac92c) === 0) dc.setTextColor(0x7f);
  const difference = signedDegreesOnce(sub32(b(0x4aa5b0), r(0x4a4f8c))), absoluteDifference = abs32(difference);
  w(0x4ac964, Number(absoluteDifference > 70));
  if (r(0x4ac978) === 0 && r(0x4ac964) === 0) {
    if (imul32(difference, b(0x4aa730)) > 0) dc.textOut(x, y, text(0x491e14) + formatInteger(absoluteDifference));
    if (difference === 0) dc.textOut(x, y, text(0x491e04));
    if (imul32(difference, b(0x4aa730)) < 0) {
      if (r(0x4ac978) === 0) dc.textOut(x, y, text(0x491dfc) + formatInteger(absoluteDifference));
      if (r(0x4a7bcc) < 55 && abs32(r(0x4ac66c)) > 45 && absoluteDifference > 10 && distance > 300 && boat === 1 && r(0x4a5b80) > 0) w(0x4a620c, 1);
    }
    // The original rechecks this flag after writing zero at the enclosing gate.
    if (r(0x4ac964) === 1) { if (r(0x4ac92c) === 0) dc.setTextColor(0x7f0000); dc.textOut(x, y, text(0x491de8)); }
    y = add32(y, lineHeight);
  }
  const statusX = r(0x4ac9c8) === 0 || b(0x4a4e88) === 3 ? add32(left, 10) : x;
  if (r(0x4ac964) === 1) dc.textOut(x, y, text(0x491de8));
  const verticalUnit = idiv32(r(0x4a72d0), 50), statusY = sub32(r(0x4aa824), verticalUnit);
  if (r(0x491188) === 7 || r(0x491188) === 8) {
    if (r(0x4ac92c) === 0) dc.setTextColor(0x7f00);
    dc.textOut(statusX, sub32(statusY, imul32(lineHeight, 4)), text(0x491ddc) + formatInteger(b(0x4a6338)) + text(0x491dd4) + formatInteger(b(0x4aa5b0)) + text(0x49198c));
  }
  if (boat === 1 && r(0x4a5b80) > 0) {
    if (r(0x4a7bcc) < 55) {
      if (imul32(difference, r(0x4aa734)) >= 0) w(0x4a4bd8, add32(r(0x4a4bd8), 1));
      if (r(0x4a7bcc) < 55) w(0x4ab9c4, add32(r(0x4ab9c4), 1));
    }
    w(0x4ab9d4, add32(r(0x4ab9d4), 1));
    if (r(0x4a786c) > 0) { w(0x4a61f8, 1); w(0x4a7754, add32(r(0x4a7754), 1)); }
    if (r(0x4a7bcc) < 55 && abs32(r(0x4ac66c)) > 75 && distance > 700) w(0x4a620c, 2);
    if (r(0x4a7bcc) < 55 && abs32(r(0x4ac66c)) > 90 && r(0x4a5424) > 0 && r(0x4a5b80) > 10) w(0x4a620c, 3);
  }
  if (boat === 1 && imul32(difference, r(0x4aa734)) > 0 && r(0x4a5b80) > 0 && sub32(170, r(0x4a5f14)) <= r(0x4a7bcc)) {
    if (distance > 300 && r(0x4a5f14) < abs32(r(0x4ac66c))) w(0x4a620c, -1);
    if (sub32(170, r(0x4a5f14)) <= r(0x4a7bcc)) {
      if (distance > 700 && idiv32(imul32(r(0x4a5f14), 9), 5) < abs32(r(0x4ac66c))) w(0x4a620c, -2);
      if (sub32(170, r(0x4a5f14)) <= r(0x4a7bcc) && distance > 700 && imul32(r(0x4a5f14), 2) < abs32(r(0x4ac66c))) w(0x4a620c, -3);
    }
  }
  dc.setTextColor(0x7f7f7f);
  if (r(0x4911a4) === 1) {
    if (r(0x4ac9dc) === 0) dc.textOut(r(0x4a763c) < 700 ? add32(left, 1) : statusX, sub32(statusY, lineHeight), text(0x491db4));
    else drawHudExplanation(memory, dc, lineHeight, left, statusX);
  }
  dc.setTextColor(r(0x4ac92c) === 0 ? 0x7f : 0);
  if (b(0x4a8910) === 1 && b(0x4ac1e8) === 0) dc.textOut(statusX, sub32(statusY, imul32(lineHeight, 3)), text(0x491d98));
  if (b(0x4a8910) === 1 && b(0x4ac1e8) === 5) dc.textOut(statusX, sub32(statusY, imul32(lineHeight, 3)), text(0x491d80));
  if (b(0x4a8910) === 1 && b(0x4ac1e8) === -5) dc.textOut(statusX, sub32(statusY, imul32(lineHeight, 3)), text(0x491d68));
  if (b(0x4a4968) === 1) dc.textOut(statusX, sub32(statusY, imul32(lineHeight, 3)), text(0x491d54));
  if (r(0x4ac92c) === 0) dc.setTextColor(0x7f0000);
  if (r(0x4ac8fc) === 0) {
    if (r(0x49116c) === 1 && r(0x4ac92c) === 0) dc.setTextColor(0xff);
    dc.textOut(add32(left, 10), sub32(statusY, imul32(lineHeight, 2)), text(0x491d40) + formatInteger(r(0x49116c)));
  } else {
    if (r(0x4ac92c) === 0) dc.setTextColor(0xff);
    dc.textOut(add32(left, 10), sub32(statusY, imul32(lineHeight, 2)), text(0x491d2c));
  }
  if (r(0x4ac92c) === 0) dc.setTextColor(0x7f7f00);
  if (r(0x4a5b80) > 0) dc.textOut(sub32(idiv32(add32(left, imul32(right, 2)), 3), 3), sub32(statusY, imul32(lineHeight, 2)), text(0x491d24) + formatInteger(r(0x4a4be4)) + text(0x491d20) + formatInteger(r(0x4a5e84)));
  dc.setTextColor(0); dc.popClipRect();
  const zoneBottom = add32(r(0x4aa824), imul32(verticalUnit, 10));
  if (sub32(r(0x4a5ba0), idiv32(r(0x4a3f04), 15)) <= statusY || r(0x4a4f80) <= sub32(r(0x4aa808), 20) || add32(r(0x4ab150), 20) <= r(0x4a4f80)) {
    const brush = memory.readU32(0x4a70e4); if (brush !== 0) dc.selectObject(brush);
    dc.rectangle(left, statusY, right, zoneBottom); dc.setBkColor(0x7f7f7f);
    const offset = r(0x4a763c) < 901 ? 12 : r(0x4a5264) < 21 ? 30 : 16;
    const quarterX = sub32(left, idiv32(sub32(left, right), 4)), thirdX = sub32(left, idiv32(sub32(left, right), 3));
    const shift = r(0x4a763c) < 700 ? -1 : offset;
    dc.textOut(add32(r(0x4ac9c8) === 0 || b(0x4a4e88) === 3 ? quarterX : thirdX, shift), add32(statusY, 2), text(0x491d10));
    dc.setBkColor(0xffffff);
  } else {
    const brush = memory.readU32(r(0x4ac92c) === 0 ? 0x4a469c : 0x4aa7f4); if (brush !== 0) dc.selectObject(brush);
    dc.rectangle(left, statusY, right, zoneBottom);
  }
  dc.selectStockObject(7); dc.moveTo(r(0x4a70ec), statusY); dc.lineTo(r(0x4a70ec), zoneBottom);
  if (r(0x4ac9c4) > 0) {
    let nearest, nearestDistance = 3000;
    for (let other = 2; other <= r(0x49118c); other = add32(other, 1)) {
      targetRelativeBearing(memory, memory.readF64(at(0x4a49e8, other, 8)), memory.readF64(at(0x4a4ae0, other, 8)), 1, 1);
      const otherDistance = f(memory, 0x4a6828).truncI32();
      if (otherDistance < nearestDistance) { nearest = other; nearestDistance = otherDistance; }
    }
    if (nearest === undefined) throw new RangeError('Original nearest-boat HUD uses an uninitialized boat index when no boat is within 3000 units');
    const value = formatDecimal(memory, f(memory, at(0x4a71c8, nearest, 8)).multiply(f(memory, 0x484d48)).toNumber());
    dc.setBkColor(0x7f7f7f);
    dc.textOut(sub32(left, idiv32(sub32(left, right), 4)), add32(statusY, add32(lineHeight, 2)), text(0x491d04) + value);
  }
  dc.setBkColor(0xffffff);
}
