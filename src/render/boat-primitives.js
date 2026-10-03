import { add32, sub32, imul32, idiv32, i32 } from '../runtime/c-types.js';

export const BOAT_PRIMITIVE_ADDRESSES = Object.freeze({
  selectBoatColor: 0x416420, drawCatamaranPanels: 0x417be0,
  drawInteriorPanel: 0x41a450, selectSailColor: 0x41af70,
  drawWakePoint: 0x419d50, drawSailCurve: 0x415590,
  monochromeFlag: 0x4ac92c, playerColorFlag: 0x4ac910,
  alternateColorFlag: 0x4ac98c, humanBoatCount: 0x491140,
  boatClass: 0x491188, simplifiedBoatFlag: 0x4ac928, boardFlag: 0x4ac904,
  player1Warning: 0x4a40c4, player2Warning: 0x4a40c8,
  pixelX: 0x4aa1a0, pixelY: 0x4aa2a0, polygonPoints: 0x4a4ca8,
});
const A = BOAT_PRIMITIVE_ADDRESSES;
function select(memory, dc, address) {
  const handle = memory.readU32(address);
  if (handle !== 0) dc.selectObject(handle);
}
function points(memory, count) {
  return Array.from({ length: count }, (_, index) => ({
    x: memory.readI32(A.polygonPoints + index * 8),
    y: memory.readI32(A.polygonPoints + index * 8 + 4),
  }));
}

/** Complete 0x416420, including all successive color overrides. */
export function selectBoatColor(memory, dc, boat) {
  boat = i32(boat);
  const monochrome = memory.readI32(A.monochromeFlag);
  if (monochrome === 0) {
    if (boat === 0) dc.selectStockObject(0);
    if (boat === 1) select(memory, dc, 0x4a3a14);
    if (boat === 2) select(memory, dc, 0x4aa98c);
    const groups = [
      [[3, 12, 21], 0x4a6234], [[4, 13, 22], 0x4a70e4],
      [[5, 14, 23], 0x4a4f7c], [[6, 15, 24], 0x4a7f24],
      [[8, 17, 26], 0x4a6484], [[9, 18, 27], 0x4a621c],
      [[10, 19, 28], 0x4a487c],
    ];
    for (const [boats, address] of groups) if (boats.includes(boat)) select(memory, dc, address);
    if ([7, 16, 25].includes(boat)) dc.selectStockObject(4);
    if (boat === 11 || boat === 20 || boat > 28) select(memory, dc, 0x4a8e04);
    if (memory.readI32(A.playerColorFlag) === 1) {
      if (boat === 1) dc.selectStockObject(0);
      else select(memory, dc, 0x4a3efc);
    }
  }
  if (memory.readI32(A.alternateColorFlag) === 1) {
    select(memory, dc, boat === 1 ? 0x4a6484 : 0x4a70e4);
    if (boat === 2 && memory.readI32(A.humanBoatCount) === 2) select(memory, dc, 0x4a621c);
  }
  if (monochrome === 1) {
    if (boat === 1) select(memory, dc, 0x4a70e4);
    if (boat > 1) dc.selectStockObject(4);
  }
}

/** Complete 0x417be0. The shared polygon block is part of original state. */
export function drawCatamaranPanels(memory, dc) {
  const firstStores = [
    [0x4a4ca8, 0x4aa1c8], [0x4a4cac, 0x4aa2c8], [0x4a4cb4, 0x4aa2c4],
    [0x4a4cb0, 0x4aa1c4], [0x4a4cc0, 0x4aa1b8], [0x4a4cb8, 0x4aa1bc],
    [0x4a4ccc, 0x4aa2c0], [0x4a4cbc, 0x4aa2bc], [0x4a4cc4, 0x4aa2b8],
    [0x4a4cc8, 0x4aa1c0],
  ];
  for (const [destination, source] of firstStores) memory.writeI32(destination, memory.readI32(source));
  if (memory.readI32(A.monochromeFlag) === 0) select(memory, dc, 0x4a4f7c);
  else dc.selectStockObject(0);
  dc.selectStockObject(7);
  dc.polygon(points(memory, 5));
  const secondStores = [
    [0x4a4ca8, 0x4aa1d0], [0x4a4cac, 0x4aa2d0], [0x4a4cb0, 0x4aa1d8],
    [0x4a4cb4, 0x4aa2d8], [0x4a4cb8, 0x4aa1e0], [0x4a4cbc, 0x4aa2e0],
    [0x4a4cc0, 0x4aa1dc], [0x4a4cc4, 0x4aa2dc], [0x4a4cc8, 0x4aa1d4],
    [0x4a4ccc, 0x4aa2d4],
  ];
  for (const [destination, source] of secondStores) memory.writeI32(destination, memory.readI32(source));
  dc.polygon(points(memory, 5));
}

/** Complete 0x41a450. Weighted coordinates wrap before signed division. */
export function drawInteriorPanel(memory, dc, boat) {
  boat = i32(boat);
  if (memory.readI32(A.simplifiedBoatFlag) === 1 && memory.readI32(A.humanBoatCount) < boat) return;
  if (memory.readI32(A.boardFlag) === 1) return;
  const weighted = (address, other) => idiv32(add32(memory.readI32(address), imul32(memory.readI32(other), 2)), 3);
  const sources = [[0x4aa1c4, 0x4aa1d4], [0x4aa2c4, 0x4aa2d4],
    [0x4aa1d4, 0x4aa1c4], [0x4aa2d4, 0x4aa2c4],
    [0x4aa1dc, 0x4aa1bc], [0x4aa2dc, 0x4aa2bc],
    [0x4aa1bc, 0x4aa1dc], [0x4aa2bc, 0x4aa2dc]];
  for (const [index, [address, other]] of sources.entries()) memory.writeI32(A.polygonPoints + index * 4, weighted(address, other));
  dc.selectStockObject(7);
  select(memory, dc, memory.readI32(A.playerColorFlag) === 1 ? 0x4a3efc : 0x4aa7f4);
  dc.polygon(points(memory, 4));
}

/** Complete 0x41af70, preserving every later sail-color override. */
export function selectSailColor(memory, dc, boat) {
  boat = i32(boat);
  const boatClass = memory.readI32(A.boatClass);
  if (boatClass === 2 || boatClass === 9) { dc.selectStockObject(0); return; }
  select(memory, dc, boat % 2 === 0 ? 0x4aa98c : 0x4aa714);
  if (boat === 1) select(memory, dc, 0x4a3a14);
  if (boat === 2) select(memory, dc, 0x4a6234);
  if ([4, 9, 12].includes(boat)) select(memory, dc, 0x4a6484);
  if ([5, 13].includes(boat)) select(memory, dc, 0x4a621c);
  if ([6, 11].includes(boat)) select(memory, dc, 0x4a7f24);
  if ([3, 10].includes(boat)) select(memory, dc, 0x4a3a14);
  if (memory.readI32(A.monochromeFlag) === 1) {
    select(memory, dc, 0x4a3efc);
    if (boat === 2 && memory.readI32(A.humanBoatCount) === 2) dc.selectStockObject(0);
  }
  if (memory.readI32(A.alternateColorFlag) === 1) select(memory, dc, 0x4a70e4);
  if (boat === 1 && memory.readI32(A.player1Warning) === 1) dc.selectStockObject(5);
  if (boat === 2 && memory.readI32(A.player2Warning) === 1 && memory.readI32(A.humanBoatCount) === 2) dc.selectStockObject(5);
}

/** Complete 0x419d50. */
export function drawWakePoint(_memory, dc, x, y, selector) {
  x = i32(x); y = i32(y);
  if (i32(selector) === 0) dc.setPixel(x, y, 0xffffff);
  else { dc.moveTo(x, y); dc.lineTo(sub32(x, 1), y); }
}

/** Complete 0x415590: the original four-segment sail curve. */
export function drawSailCurve(_memory, dc, horizontalFactor, verticalFactor, side, width, x1, y1, x2, y2, angle, flutter) {
  [horizontalFactor, verticalFactor, side, width, x1, y1, x2, y2, angle, flutter] =
    [horizontalFactor, verticalFactor, side, width, x1, y1, x2, y2, angle, flutter].map(i32);
  const midpointX = idiv32(add32(x2, x1), 2);
  const midpointY = idiv32(add32(y1, y2), 2);
  if (side === 0) width = sub32(0, width);
  const x = [idiv32(add32(midpointX, x1), 2), midpointX, idiv32(add32(midpointX, x2), 2), x2];
  const y = [
    sub32(idiv32(add32(midpointY, y1), 2), idiv32(imul32(imul32(add32(add32(idiv32(angle, 2), 3), imul32(flutter, 2)), width), horizontalFactor), 300)),
    sub32(midpointY, idiv32(imul32(imul32(add32(add32(flutter, 7), angle), width), verticalFactor), 300)),
    sub32(idiv32(add32(midpointY, y2), 2), idiv32(imul32(add32(sub32(idiv32(angle, 2), flutter), 11), width), 30)),
    y2,
  ];
  dc.moveTo(x1, y1);
  for (let index = 0; index < 4; index++) dc.lineTo(x[index], y[index]);
}

export const FUN_00416420 = selectBoatColor;
export const FUN_00417be0 = drawCatamaranPanels;
export const FUN_0041a450 = drawInteriorPanel;
export const FUN_0041af70 = selectSailColor;
export const FUN_00419d50 = drawWakePoint;
export const FUN_00415590 = drawSailCurve;
