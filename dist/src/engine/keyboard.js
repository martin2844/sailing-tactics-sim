import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { updateSpeedDivisor, wrapDegreesOnce } from './integer-core.js';

/**
 * Complete original WM_KEYDOWN handler 0x4517c0. The original MFC signature
 * consumes key, repeat-count and flags; only key affects Posey's state.
 * InvalidateRect and the final MFC default-window call are explicit callbacks.
 * Demo/menu gates are preserved as reads of the original globals.
 */
export function handleKeyDown(memory, key, options = {}) {
  const r = address => memory.readI32(address);
  const w = (address, value) => memory.writeI32(address, value);
  const current = () => r(0x4a60a4);
  const invalidate = erase => options.invalidateRect?.({ windowHandle: options.windowHandle ?? 0, rectangle: null, erase });
  const redraw = (erase = 0) => { w(0x4ac8fc, 0); invalidate(erase); };
  const cycle = (address, limit = 1, reset = 0) => {
    w(address, add32(r(address), 1));
    if (r(address) > limit) w(address, reset);
  };
  const clear = (...addresses) => addresses.forEach(address => w(address, 0));
  key = i32(key); w(0x4a60a4, key);
  if (key === 0xdc) { cycle(0x4911d0); w(0x4a60a4, -1); }
  if (current() === 8) w(0x4ac9ec, add32(r(0x4ac9ec), 1));
  if (r(0x4ac9ec) > 1) w(0x4ac9ec, 0);
  if (current() === 0x21 || current() === 0x22) {
    if (current() === 0x21 && r(0x49116c) < 15) w(0x49116c, add32(r(0x49116c), 1));
    if (current() === 0x22 && r(0x49116c) > 1) w(0x49116c, sub32(r(0x49116c), 1));
    updateSpeedDivisor(memory);
    w(0x491178, r(0x49116c)); w(0x491174, r(0x491170)); redraw();
  }
  if (current() === 0x7b && r(0x4ac980) === 0 && r(0x491140) === 1 && r(0x491164) === 0) {
    cycle(0x4ac9b4); w(0x4ac9c8, 0);
    if (r(0x49118c) > 2) w(0x4ac9b4, 0);
    redraw(); w(0x4a60a4, -1);
  }
  if (current() === 0xba) { cycle(0x4ac9c4); redraw(); }
  if (current() === 0x20) {
    if (r(0x4ac980) > 0) { clear(0x4ac980, 0x4ac984); redraw(); w(0x4a60a4, -1); }
    if (current() === 0x20) {
      if (r(0x4ac8f8) === 0 && r(0x491164) > 0 && r(0x4ac9cc) === 0) {
        w(0x4ac9cc, 1); w(0x4a60a4, -1); redraw();
      }
      if (current() === 0x20 && r(0x4ac8f8) === 0) { w(0x4ac8f8, 1); redraw(); w(0x4a60a4, -1); }
    }
  }
  if (current() === 0x1b) w(0x4ac95c, 0);
  if (current() === 0xbf) { w(0x4ac8fc, 1); w(0x4ac980, 6); w(0x4ac984, 6); invalidate(0); w(0x4a6774, 0); }
  if (current() === 0x20 && r(0x4ac8f8) > 0) {
    if ([0x4ac938, 0x4aa980, 0x4ac970, 0x4ac974, 0x4ac988, 0x4ac980].every(address => r(address) === 0)) {
      if (r(0x49116c) === 1) {
        w(0x491170, r(0x491174)); w(0x49116c, r(0x491178));
        if (r(0x4911d0) === 1) { w(0x4911d0, 2); w(0x4911d4, r(0x4a5b80)); }
      } else { w(0x491178, r(0x49116c)); w(0x491174, r(0x491170)); w(0x491170, 0xb67); w(0x49116c, 1); }
    } else { clear(0x4ac938, 0x4ac974, 0x4ac970, 0x4ac94c, 0x4aa980, 0x4ac980, 0x4ac984, 0x4ac988, 0x4ac968); redraw(); }
  }
  if (current() === 0x4e) {
    clear(0x4ac8f8, 0x4ac97c, 0x4ac93c, 0x4ac980, 0x4ac9cc);
    if (r(0x4ac944) > 2) w(0x4ac944, 0);
    w(0x4ac8fc, 0); w(0x4a5b80, r(0x4a4168)); invalidate(1);
  }
  if (current() === 0x46) { cycle(0x4ac968); if (r(0x4ac968) === 0) redraw(); else w(0x4ac8fc, 1); }
  if (current() === 0x52) {
    const next = add32(r(0x4aa980), 1); w(0x4aa980, next);
    if (next > 1) w(0x4aa980, 0);
    w(0x4ac8fc, next === 1 ? 1 : 0); invalidate(0);
    clear(0x4ac94c, 0x4ac970, 0x4ac974, 0x4ac938);
  }
  if (current() === 0x57) { cycle(0x4ac938); redraw(1); clear(0x4ac94c, 0x4aa980, 0x4ac980); w(0x4a60a8, 1); }
  if (current() === 0x59 && r(0x491140) === 1) {
    if (r(0x4ac984) === 300) clear(0x4ac980, 0x4ac984);
    else { w(0x4ac980, 300); w(0x4ac984, 300); w(0x4ac938, 0); }
    redraw();
  }
  if (current() === 0xdb || current() === 0xdd) {
    const selected = current() === 0xdb ? 0x4ac970 : 0x4ac974;
    cycle(selected); redraw(); clear(selected === 0x4ac970 ? 0x4ac974 : 0x4ac970, 0x4aa980, 0x4ac938, 0x4ac94c, 0x4ac980);
  }
  let active = current(), boat = r(0x491140);
  const at = base => add32(base, imul32(boat, 4)) >>> 0;
  const rb = base => r(at(base));
  const wb = (base, value) => w(at(base), value);
  const clearBoat = (...bases) => bases.forEach(base => wb(base, 0));
  const zoomLimit = r(0x4a4958) < 2 ? 128 : 64;
  w(0x4a775c, zoomLimit);
  if (active === 0x58) { const next = imul32(rb(0x4a8660), 2); wb(0x4a8660, next); if (next !== zoomLimit && next >= zoomLimit) wb(0x4a8660, zoomLimit); }
  if (active === 0x5a) { const next = idiv32(rb(0x4a8660), 2); wb(0x4a8660, next < 2 ? 2 : next); }
  if (active === 0x42) cycle(at(0x4ab160), 2);
  if (active === 0x56) { wb(0x4aae20, 0); cycle(at(0x4a4e88), 3, 1); }
  if (active === 0x55) cycle(at(0x4a40c0));
  if (active === 0xc0) cycle(0x4ac958);
  if (active === 0xbc || active === 0xbe) {
    if (boat === 1) {
      const value = Float80.fromNumber(memory.readF64(0x4a78e8)).subtract(Float80.fromNumber(memory.readF64(active === 0xbc ? 0x484d58 : 0x484d60)));
      memory.writeF64(0x4a78e8, value.toNumber());
    } else {
      w(0x4ac020, wrapDegreesOnce(add32(r(0x4ac020), active === 0xbc ? -10 : 10)));
      boat = r(0x491140); active = current();
    }
    clearBoat(0x4a8910, 0x4a4968, 0x4a6848, 0x4a4df8, 0x4abf98);
  }
  if (active === 0x43) { wb(0x4a4df8, -1); clearBoat(0x4ac1e8, 0x4a8910, 0x4a4968, 0x4abf98); }
  if (active === 0x54) { wb(0x4a4df8, 1); clearBoat(0x4a8910, 0x4a6848, 0x4a4968); wb(0x4a41f0, r(0x4a5b80)); wb(0x4a46a8, 1); wb(0x4abf98, 0); }
  if (active === 0x4a) { wb(0x4abf98, 1); clearBoat(0x4a8910, 0x4a6848, 0x4a4968, 0x4a4df8); }
  if (active === 0x48) { wb(0x4a6848, rb(0x4a7bc8) < 90 ? 2 : 3); clearBoat(0x4a8910, 0x4a4968, 0x4a4df8, 0x4abf98); }
  if (active === 0x44 && r(0x4ac8f8) > 0) { wb(0x4a6848, 1); clearBoat(0x4a8910, 0x4a4968, 0x4a4df8, 0x4abf98); }
  let view = r(0x4ac980);
  const reload = () => { view = r(0x4ac980); boat = r(0x491140); active = current(); };
  const autopilot = value => { wb(0x4ac1e8, value); wb(0x4a8910, 1); clearBoat(0x4a4968, 0x4a4df8, 0x4abf98); };
  if (active === 0xbb && view === 0) {
    if (r(0x4ac974) === 1) { w(0x4ac8fc, 0); w(0x4ac94c, add32(r(0x4ac94c), 1)); invalidate(0); reload(); }
    else if (rb(0x4a8910) > 0) autopilot(5);
  }
  const menuStep = step => { w(0x4a6774, 0); w(0x4ac980, add32(r(0x4ac980), step)); invalidate(0); reload(); };
  if (active === 0xbb && view > 100 && view < 110 && (r(0x491164) === 0 || view < 102)) menuStep(1);
  if (active === 0xbd && view > 101 && view < 111) menuStep(-1);
  if (active === 0xbb && view > 500 && view < 514 && (r(0x491164) === 0 || view < 502)) menuStep(1);
  if (active === 0xbd && view > 501 && view < 515) menuStep(-1);
  if (active === 0xbb && view > 600 && view < 604) menuStep(1);
  if (active === 0xbd) {
    if (view > 601 && view < 605) menuStep(-1);
    if (active === 0xbd && view === 0 && rb(0x4a8910) > 0) autopilot(-5);
  }
  if (active === 0x53) { if (r(0x4ac8f8) > 0) wb(0x4a85d0, 90); if (r(0x4ac8f8) === 0) w(0x4ac9a4, add32(r(0x4ac9a4), 1)); }
  if (r(0x4ac9a4) > 1) w(0x4ac9a4, 0);
  if (active === 0x41) {
    if (view === 0) wb(0x4a85d0, -1);
    if (view > 0) { w(0x4a6774, add32(r(0x4a6774), 1)); if (r(0x4a6774) > r(0x491184)) w(0x4a6774, 0); invalidate(0); w(0x4ac8fc, 1); boat = r(0x491140); active = current(); }
  }
  if (active === 0x49) { const next = sub32(rb(0x4a85d0), 20); wb(0x4a85d0, next < 0 ? -1 : next); }
  if (active === 0x4f) { const next = add32(rb(0x4a85d0), 20); wb(0x4a85d0, next > 90 ? 90 : next); }
  if (active === 0x45) cycle(at(0x4a7768), 3, 1);
  if (active >= 0x70 && active <= 0x72) wb(0x4a7768, active - 0x6f);
  if (active === 0x50 && (boat === 1 || boat === 2) && r(0x491188) > 1 && r(0x491188) !== 9) cycle(boat === 1 ? 0x4a4388 : 0x4a438c);
  if (active === 0x4c) cycle(0x4ac9d0);
  if (active === 0x30) cycle(at(0x4aae20));
  if (active >= 0x31 && active <= 0x33) { wb(0x4a4e88, active - 0x30); wb(0x4aae20, 0); }
  if (active === 0x34 && boat === 1 && r(0x4ac9b4) === 0) { cycle(0x4ac9c8); redraw(); boat = r(0x491140); active = current(); }
  if (active === 0x37 || active === 0x24) { wb(0x4a9440, -1); wb(0x4a4608, 0); }
  if (active === 0x35 || active === 0xc) { wb(0x4a9440, 1); wb(0x4a4608, 0); }
  if (active === 0x39) { wb(0x4a9440, 100); w(0x4aa97c, 0); wb(0x4a4608, 0); }
  if (active === 0x26) { wb(0x4a4608, 0); wb(0x4a9440, 0); }
  if (active === 0x28) { wb(0x4a4608, 180); wb(0x4a9440, 0); }
  if (active === 0x27) { const next = sub32(rb(0x4a4608), 30); wb(0x4a4608, next < -360 ? 0 : next); wb(0x4a9440, 0); }
  if (active === 0x25) { const next = add32(rb(0x4a4608), 30); wb(0x4a4608, next > 360 ? 0 : next); wb(0x4a9440, 0); }
  options.defaultKeyHandler?.();
}

export const KEYBOARD_ROUTINES = Object.freeze({ handleKeyDown: 0x4517c0 });
