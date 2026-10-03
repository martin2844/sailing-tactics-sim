import { add32, sub32, idiv32, i32 } from '../runtime/c-types.js';
import { readAnsiString } from '../engine/hud-state.js';

export const TUTORIAL_CONTROL_ROUTINES = Object.freeze({
  selectBoatTextColor: 0x416990, drawTutorialAdvanceButton: 0x44d6d0, drawTutorialAdvanceHint: 0x44d830,
});

/** Complete original 0x416990; invalid negative boat numbers retain text color. */
export function selectBoatTextColor(memory, dc, boat) {
  boat = i32(boat);
  if (memory.readI32(0x4ac92c) !== 0) { dc.setTextColor(0); return; }
  if (boat === 1) dc.setTextColor(0xff);
  if (boat === 2) dc.setTextColor(0xff00);
  for (const [boats, color] of [
    [[3, 12, 21], 0x7f7f], [[0, 4, 13, 22], 0x7f7f7f], [[5, 14, 23], 0x7f7f],
    [[6, 15, 24], 0xff00ff], [[7, 16, 25], 0], [[8, 17, 26], 0x7f],
    [[9, 18, 27], 0x7f00], [[10, 19, 28], 0x7f007f],
  ]) if (boats.includes(boat)) dc.setTextColor(color);
  if (boat === 11 || boat === 20 || boat > 28) dc.setTextColor(0xffff00);
}

/** Complete original 0x44d6d0, including the original CDC color restoration. */
export function drawTutorialAdvanceButton(memory, dc, height) {
  height = i32(height); const get = address => memory.readI32(address), top = get(0x4a600c);
  const handle = memory.readU32(0x4a70e4); if (handle) dc.selectObject(handle);
  dc.selectStockObject(7);
  dc.rectangle(0, top, add32(idiv32(get(0x4a763c), 3), 4), add32(add32(top, 3), height));
  dc.setBkColor(0x7f7f7f); dc.setTextColor(0);
  const restore = get(0x4a6774) === get(0x491184);
  if (get(0x4ac92c) === 0) dc.setTextColor(restore ? 0xffff00 : 0xffff);
  dc.textOut(2, add32(top, 2), readAnsiString(memory, restore ? 0x49f16c : 0x49f148));
  dc.setBkColor(0xffffff); dc.setTextColor(0);
}

/** Complete original 0x44d830; the second argument is intentionally unused. */
export function drawTutorialAdvanceHint(memory, dc, _unused, lineHeight) {
  lineHeight = i32(lineHeight); const get = address => memory.readI32(address), y = sub32(get(0x4a600c), lineHeight);
  if (get(0x4a6774) < get(0x491184)) {
    if (get(0x4ac92c) === 0) dc.setTextColor(0);
    dc.textOut(3, y, readAnsiString(memory, 0x49f21c));
    if (get(0x4ac92c) === 0) dc.setTextColor(0xff);
    dc.textOut(3, y, readAnsiString(memory, 0x49f1f8));
  } else {
    if (get(0x4ac92c) === 0) dc.setTextColor(0xff);
    dc.textOut(3, y, readAnsiString(memory, 0x49f190));
  }
}
