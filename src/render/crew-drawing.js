import { add32, sub32, imul32, idiv32, irem32, i32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';

export const CREW_DRAWING_ROUTINES = Object.freeze({ drawCrew: 0x418b80 });
const indexed = (base, index) => add32(base, imul32(index, 4)) >>> 0;
const avg = (left, right) => idiv32(add32(left, right), 2);
const weighted = (first, second) => idiv32(add32(first, imul32(second, 2)), 3);
const abs32 = value => value < 0 ? sub32(0, value) : value;
const heightOffset = (memory, height, factor) => Float80.fromNumber(height).multiply(Float80.fromNumber(memory.readF64(factor))).truncI32();
function select(memory, dc, address) { const handle = memory.readU32(address); if (handle) dc.selectObject(handle); }

/** Complete 0x418b80: crew clothes, limbs, rigging, board grip and head. */
export function drawCrew(memory, dc, crewNumber, boat, height, screenY, pose, viewHeading) {
  [crewNumber, boat, screenY, pose, viewHeading] = [crewNumber, boat, screenY, pose, viewHeading].map(i32);
  const get = address => memory.readI32(address);
  if (screenY <= get(0x4ac13c) || get(0x491188) === 8 || (boat > get(0x491140) && get(0x4ac928) === 1)) return;
  const base = crewNumber === 1 ? 39 : crewNumber === 2 ? 45 : crewNumber === 3 ? 51 : boat;
  const x = index => get(indexed(0x4aa1a0, add32(base, index)));
  const y = index => get(indexed(0x4aa2a0, add32(base, index)));
  const board = get(0x4ac904) === 1;
  let heightPixels = board ? Float80.fromNumber(height).add(Float80.fromNumber(height)).truncI32() : heightOffset(memory, height, 0x484ff8);
  const footOffset = board ? idiv32(heightPixels, 3) : 0;
  let headOffset = board ? idiv32(imul32(heightPixels, 9), 10) : 0;
  const armY1 = sub32(y(1), idiv32(heightPixels, 2)), armY2 = sub32(y(2), idiv32(heightPixels, 2));
  const near = screenY > get(0x4a7354);
  const plain = get(0x4ac92c) === 1 || boat % 2 === 0 || get(0x4ac98c) === 1;
  let palette;
  if (crewNumber === 2) {
    if (plain) { select(memory, dc, near ? 0x4a3a04 : 0x4a403c); palette = 4; }
    else { select(memory, dc, near ? 0x4abf04 : 0x4a89bc); palette = 2; }
  } else {
    if (plain) { select(memory, dc, near ? 0x4a8a44 : 0x4abdbc); palette = 3; }
    else { select(memory, dc, near ? 0x4ab9e4 : 0x4abbfc); palette = 1; }
    if (get(0x4ac92c) === 0) {
      if ((irem32(boat, 3) === 0 && get(0x4ac98c) === 0 && get(0x4ac904) === 0)
          || (get(0x4ac904) === 1 && boat === 1)) {
        select(memory, dc, near ? 0x4a6794 : 0x4ab15c); palette = 5;
      }
    }
  }
  dc.moveTo(x(0), sub32(y(0), footOffset));
  dc.lineTo(x(1), sub32(y(1), heightPixels)); dc.lineTo(x(2), sub32(y(2), heightPixels));
  dc.lineTo(x(3), sub32(y(3), footOffset)); dc.moveTo(x(0), sub32(y(0), footOffset));
  if (near || boat === 1) {
    select(memory, dc, ({ 1: 0x4abbfc, 2: 0x4a89bc, 3: 0x4abdbc, 4: 0x4a403c, 5: 0x4ab15c })[palette]);
    const legOffset = crewNumber >= 2 && get(0x491188) === 7 && pose === 1 ? idiv32(imul32(heightPixels, 3), 2) : 0;
    dc.moveTo(x(0), sub32(y(0), footOffset)); dc.lineTo(x(4), add32(legOffset, y(4)));
    dc.moveTo(x(3), sub32(y(3), footOffset)); dc.lineTo(x(5), add32(legOffset, y(5)));
    if (!board && (crewNumber === 1 || get(0x491188) < 7)) {
      select(memory, dc, 0x4a4dec);
      const tack = get(indexed(0x4aa730, boat));
      const relative = abs32(sub32(imul32(tack, -90), viewHeading));
      if (relative < 50 || viewHeading < -150 || viewHeading > 150) {
        dc.moveTo(x(1), armY1); dc.lineTo(weighted(x(1), x(4)), weighted(armY1, y(4)));
      }
      if (relative < 90 || abs32(viewHeading) < (crewNumber === 1 ? 55 : 20)) {
        const endX = weighted(x(2), x(5)), endY = weighted(armY2, y(5));
        dc.moveTo(x(2), armY2); dc.lineTo(endX, endY);
        if (crewNumber === 1 && get(0x49114c) < 1 && get(0x4ac904) === 0) {
          dc.moveTo(get(0x4aa708), get(0x4abe68)); dc.lineTo(endX, endY);
        }
      }
    }
    if (board) {
      dc.moveTo(x(1), sub32(y(1), heightPixels));
      dc.lineTo(idiv32(add32(imul32(get(0x4a70f4), 4), imul32(get(0x4a70fc), 6)), 10),
        idiv32(add32(imul32(get(0x4a72c0), 4), imul32(get(0x4a72cc), 6)), 10));
      dc.moveTo(x(2), sub32(y(2), heightPixels));
      dc.lineTo(idiv32(add32(imul32(get(0x4a70f4), 6), imul32(get(0x4a70fc), 4)), 10),
        idiv32(add32(imul32(get(0x4a72cc), 4), imul32(get(0x4a72c0), 6)), 10));
    }
  }
  dc.selectStockObject(7);
  let radius = sub32(1, heightOffset(memory, height, 0x485060));
  if (radius < 3) radius = 3;
  if (get(0x491188) === 1) { radius = add32(radius, 1); if (get(0x4ac904) === 0) headOffset = sub32(headOffset, 1); }
  if (screenY < get(0x4a7354)) { radius = sub32(radius, 1); headOffset = sub32(headOffset, 1); }
  const headX = avg(x(2), x(1)), headY = avg(y(2), y(1));
  select(memory, dc, get(0x4ac92c) === 0 && get(0x4ac98c) === 0 ? 0x4ab17c : 0x4a3efc);
  dc.ellipse(sub32(headX, radius), sub32(sub32(headY, imul32(radius, 3)), headOffset),
    add32(radius, headX), sub32(sub32(headY, headOffset), radius));
}
