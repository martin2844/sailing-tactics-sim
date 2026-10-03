import { add32, sub32, imul32, idiv32, i32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { initializeBoatOptions } from '../engine/boat-options.js';
import { initializeRace } from '../engine/initialization.js';
import { advanceFrame, finishFrame, minimumFrameDuration } from '../engine/frame.js';
import { drawChart } from './chart.js';
import { drawCompactHud, drawSailingHud } from './hud.js';
import { drawCircle } from './chart-symbols.js';
import { drawAdvice, drawStartScreen, drawResultsScreen, drawForecastScreen } from './screens.js';
import { drawPauseScreen } from './tutorials.js';

export const PAINT_ROUTINES = Object.freeze({ paintLifecycle: 0x403bb0, drawSimulationFrame: 0x404020 });
const required = (options, name) => {
  if (typeof options[name] !== 'function') throw new Error(`Original paint branch requires ${name}`);
  return options[name];
};

/** Original display-cap calibration stores at the start of 403bb0. */
export function configurePaintDimensions(memory, { width, height, bitsPixel, applicationInstance }) {
  width = i32(width); height = i32(height); bitsPixel = i32(bitsPixel);
  if (width > 1040) width = 1040;
  if (height > 768) height = 768;
  memory.writeI32(0x4aaa1c, bitsPixel);
  memory.writeU32(0x4ac1d4, applicationInstance >>> 0);
  memory.writeI32(0x4a3f84, width); memory.writeI32(0x4a763c, width);
  memory.writeI32(0x4a3f04, height);
  return calibratePaintScale(memory);
}
function calibratePaintScale(memory) {
  const width = memory.readI32(0x4a763c), height = memory.readI32(0x4a3f04), bitsPixel = memory.readI32(0x4aaa1c);
  const clientHeight = width < 801 ? sub32(height, 30) : sub32(height, idiv32(height, 20));
  memory.writeI32(0x4a72d0, clientHeight);
  memory.writeF64(0x4a8670, Float80.fromInteger(height).multiply(Float80.fromNumber(memory.readF64(0x484cb0))).toNumber());
  memory.writeF64(0x4ab0c8, Float80.fromInteger(width).multiply(Float80.fromNumber(memory.readF64(0x484cb8))).toNumber());
  return { width, height: clientHeight, bitsPixel };
}

/** Complete rendering suffix of 404020; its numerical prefix is advanceFrame. */
export function composeRaceFrame(memory, dc, rng, options = {}) {
  options = { ...options, rng };
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const width = () => r(0x4a763c), height = () => r(0x4a72d0);
  const scene = (...args) => required(options, 'drawScene')(memory, dc, ...args, { ...options, rng });
  const chart = (...args) => (options.drawChart ?? drawChart)(memory, dc, ...args, options);
  const pause = () => (options.drawPauseScreen ?? drawPauseScreen)(memory, dc, rng, options);
  const advice = (...args) => (options.drawAdvice ?? drawAdvice)(memory, dc, ...args, options);
  const sailing = (...args) => (options.drawSailingHud ?? drawSailingHud)(memory, dc, ...args, options);
  const compact = (...args) => (options.drawCompactHud ?? drawCompactHud)(memory, dc, ...args, options);
  const showPause = () => r(0x4ac980) === 2 || r(0x4ac980) === 300;
  if (r(0x491140) === 1 && r(0x4a4e8c) < 3) {
    scene(0, 0, width(), idiv32(height(), 2), 1);
    if (showPause()) pause();
    if (r(0x4ac9c8) === 0) {
      if (r(0x4ac9b4) === 0) chart(0, idiv32(height(), 2), idiv32(width(), 3), height(), 1, 2);
      else advice(0, idiv32(height(), 2), idiv32(width(), 3), height(), 1, 2);
    }
    const left = r(0x4ac9c8) === 1 ? 0 : idiv32(width(), 3);
    const right = r(0x4ac9c8) === 1 ? idiv32(width(), 2) : idiv32(imul32(width(), 2), 3);
    chart(right, idiv32(height(), 2), width(), height(), 1, 1);
    sailing(left, idiv32(height(), 2), right, height(), 1);
    w(0x4aa808, left); w(0x4ab150, right);
  }
  if (r(0x491140) === 1 && r(0x4a4e8c) === 3) {
    scene(idiv32(width(), 3), 0, width(), height(), 1);
    if (showPause()) pause();
    chart(0, 0, idiv32(width(), 3), idiv32(height(), 2), 1, 1);
    if (showPause()) pause();
    sailing(0, idiv32(height(), 2), idiv32(width(), 3), height(), 1);
    w(0x4ab150, idiv32(width(), 3)); w(0x4aa808, 0);
  }
  if (r(0x491140) === 2) {
    scene(0, 0, idiv32(width(), 2), idiv32(height(), 2), 2);
    if (showPause()) pause();
    scene(idiv32(width(), 2), 0, width(), idiv32(height(), 2), 1);
    if (showPause()) pause();
    const inset = idiv32(width(), 30);
    chart(0, idiv32(height(), 2), sub32(idiv32(width(), 3), inset), height(), 2, 1);
    compact(sub32(idiv32(width(), 3), inset), idiv32(height(), 2), idiv32(width(), 2), height(), 2);
    chart(idiv32(width(), 2), idiv32(height(), 2), sub32(idiv32(imul32(width(), 5), 6), idiv32(inset, 2)), height(), 1, 1);
    compact(sub32(idiv32(imul32(width(), 5), 6), idiv32(inset, 2)), idiv32(height(), 2), width(), height(), 1);
  }
}

/** Complete original 404020 call order. Browser host schedules the returned delay. */
export function drawSimulationFrame(memory, dc, rng, options = {}) {
  options = { ...options, rng };
  const frameOptions = options.beep || !options.messageBeep ? options : { ...options, beep: () => options.messageBeep(0) };
  (options.advanceFrame ?? advanceFrame)(memory, rng, frameOptions);
  composeRaceFrame(memory, dc, rng, options);
  const duration = minimumFrameDuration(memory);
  options.enforceMinimumPaintDuration?.(duration);
  finishFrame(memory);
  return duration;
}

/** Original screen dispatch, preserving sequential re-reads after every child call. */
export function drawPaintContent(memory, dc, rng, options = {}) {
  options = { ...options, rng };
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const width = () => r(0x4a763c), height = () => r(0x4a72d0);
  const pause = () => (options.drawPauseScreen ?? drawPauseScreen)(memory, dc, rng, options);
  if (r(0x4ac8f8) === 0) {
    (options.initializeBoatOptions ?? initializeBoatOptions)(memory);
    (options.drawStartScreen ?? drawStartScreen)(memory, dc, rng, options);
  }
  if (r(0x4ac8f8) === 1) {
    (options.initializeBoatOptions ?? initializeBoatOptions)(memory);
    (options.initializeRace ?? initializeRace)(memory, rng, options); w(0x4ac8f8, 2);
  }
  if (r(0x4ac93c) > 0) {
    (options.drawResultsScreen ?? drawResultsScreen)(memory, dc, rng, options); w(0x4ac97c, 1);
    if (r(0x4ac980) === 300) pause();
  }
  if (r(0x4ac93c) !== 0) return;
  if (r(0x4ac938) === 1 && r(0x4ac8f8) === 2 && r(0x4aa980) === 0) (options.drawForecastScreen ?? drawForecastScreen)(memory, dc, rng, options);
  if ([0, 2, 300].includes(r(0x4ac980)) && r(0x4ac8f8) > 1 && r(0x4ac938) === 0 && r(0x4aa980) === 0 && r(0x4ac970) === 0 && r(0x4ac974) === 0) {
    (options.drawSimulationFrame ?? drawSimulationFrame)(memory, dc, rng, options);
  }
  const chart = mode => (options.drawChart ?? drawChart)(memory, dc, 0, 0, width(), height(), 0, mode, options);
  if (r(0x4ac8f8) > 0 && r(0x4ac938) === 0 && r(0x4aa980) === 1) chart(3);
  if (r(0x4ac8f8) > 0 && r(0x4ac938) === 0 && r(0x4ac970) === 1 && r(0x4ac980) === 0) chart(4);
  if (r(0x4ac8f8) >= 1 && r(0x4ac938) === 0 && r(0x4ac974) === 1 && r(0x4ac980) === 0) chart(5);
  if (r(0x4ac980) !== 0 && r(0x4ac980) >= 0) pause();
}

/**
 * Complete 403bb0 game lifecycle with explicit owned host surfaces/OS callbacks.
 * Surface allocation and blitting preserve request order; Canvas raster/handle
 * identity is a host concern. No original Windows entrypoint is executed.
 */
export function paintLifecycle(memory, frontDc, rng, options = {}) {
  const host = options.host;
  if (!host) throw new Error('Original paint lifecycle requires an explicit surface host');
  const buffer = host.constructBufferedDC();
  memory.writeI32(0x4aaa1c, host.getDeviceCaps(frontDc, 12));
  memory.writeU32(0x4ac1d4, host.applicationInstance() >>> 0);
  let width = i32(host.getDeviceCaps(frontDc, 8));
  memory.writeI32(0x4a3f84, width);
  if (width > 1040) { width = 1040; memory.writeI32(0x4a3f84, width); }
  memory.writeI32(0x4a763c, width);
  let height = i32(host.getDeviceCaps(frontDc, 10));
  memory.writeI32(0x4a3f04, height);
  if (height > 768) { height = 768; memory.writeI32(0x4a3f04, height); }
  const dimensions = calibratePaintScale(memory);
  const bitmap = host.createBitmap({ ...dimensions, planes: 1, pixels: null });
  host.attachBitmap(bitmap);
  host.attachCompatibleDC(buffer, host.createCompatibleDC(frontDc));
  const previous = host.selectBitmap(buffer, bitmap);
  drawPaintContent(memory, buffer, rng, options);
  host.bitBlt(frontDc, buffer, { x: 0, y: 0, width: memory.readI32(0x4a763c), height: dimensions.height, sourceX: 0, sourceY: 0, rasterOperation: 0xcc0020 });
  host.selectBitmap(buffer, previous === 0 ? null : previous);
  host.deleteBitmap(bitmap);
  const rectangle = { left: 0, top: 0, right: memory.readI32(0x4a763c), bottom: memory.readI32(0x4a72d0) };
  if (memory.readI32(0x4ac8fc) === 0 && memory.readI32(0x4ac8f8) > 0 && memory.readI32(0x4ac938) === 0 && memory.readI32(0x4ac97c) === 0) {
    host.invalidateRect({ windowHandle: options.windowHandle ?? 0, rectangle, erase: 0 });
  }
  if (memory.readI32(0x4ac9a4) === 1 && memory.readI32(0x4ac8f8) > 0) {
    const y = sub32(memory.readI32(0x4a5ba0), idiv32(memory.readI32(0x4a3f04), 20));
    frontDc.selectStockObject(4);
    (options.drawCircle ?? drawCircle)(memory, frontDc, 3, memory.readI32(0x4a4f80), y);
  }
  host.destroyBufferedDC(buffer);
}
