import { Float80 } from '../runtime/float80.js';
import { i32, add32, sub32, imul32, idiv32, irem32 } from '../runtime/c-types.js';

const f = (memory, address) => Float80.fromNumber(memory.readF64(address));
const n = value => Float80.fromNumber(value);
const i = value => Float80.fromInteger(i32(value));
const stored = value => n(value.toNumber());
const at = (base, index, stride = 4) => add32(base, imul32(index, stride)) >>> 0;
const put = (memory, address, value) => memory.writeF64(address, value.toNumber());

/** Complete 0x4139d0 for its five initialized selector values. */
export function crewPositionFactor(memory, selector) {
  selector = i32(selector);
  const address = ({ '-2': 0x484eb8, '-1': 0x484e10, 0: 0x484e18, 1: 0x484eb0, 2: 0x484ea8 })[selector];
  if (address === undefined) throw new RangeError('Original crew factor is uninitialized outside selectors -2 through 2');
  return f(memory, address);
}

/** Complete 0x413a20, retaining the operands of each original non-popping FST. */
export function writeCrewGeometry(memory, x, y, height, width, index, boat, crewNumber, screenY, pose) {
  [index, boat, crewNumber, screenY, pose] = [index, boat, crewNumber, screenY, pose].map(i32);
  const boatClass = memory.readI32(0x491188);
  const boardFlag = memory.readI32(0x4ac904);
  const coefficient = n(boatClass === 1 ? 1.3 : boatClass === 5 || boatClass === 7 ? 0.6 : 1);
  const originalTack = memory.readI32(at(0x4aa730, boat));
  const tack = pose < 0 ? sub32(0, originalTack) : originalTack;
  const x80 = n(x), y80 = n(y), width80 = n(width);
  const scaledHeight = stored(coefficient.multiply(n(height)));
  const lowerY = y80.subtract(scaledHeight);
  const lowerYStored = stored(lowerY);
  const offset = imul32(index, 8);
  const dest = base => add32(base, offset) >>> 0;
  put(memory, dest(0x4ac310), x80);
  const firstRelative = x80.subtract(f(memory, 0x4ac310));
  put(memory, dest(0x4a3a38), lowerY);
  put(memory, dest(0x4a79f8), firstRelative);
  const sideScale = n(boardFlag === 1 && memory.readI32(at(0x4a8aa8, boat)) < 80 ? 1 : 0.2);
  // The original overwrites the height argument with binary64 signed tack.
  const tackStored = stored(i(tack));
  const pointX = sideScale.multiply(coefficient).multiply(width80).multiply(tackStored).add(x80);
  const pointXStored = stored(pointX);
  const upperY = y80.add(scaledHeight);
  const upperYStored = stored(upperY);
  put(memory, dest(0x4ac318), pointX);
  const sideRelative1 = pointXStored.subtract(f(memory, 0x4ac310));
  put(memory, dest(0x4ac320), pointXStored);
  const sideRelative2 = pointXStored.subtract(f(memory, 0x4ac310));
  put(memory, dest(0x4ac328), x80);
  const otherRelative = x80.subtract(f(memory, 0x4ac310));
  put(memory, dest(0x4a3a40), lowerYStored);
  put(memory, dest(0x4a7a00), sideRelative1);
  put(memory, dest(0x4a3a48), upperY);
  put(memory, dest(0x4a7a08), sideRelative2);
  put(memory, dest(0x4a3a50), upperYStored);
  put(memory, dest(0x4a7a10), otherRelative);
  let tailOffset = coefficient.multiply(width80).multiply(tackStored)
    .multiply(f(memory, crewNumber > 1 && boatClass === 7 ? 0x484ec0 : 0x484da8));
  if (screenY <= memory.readI32(0x4a7354) && boat > 1) return;
  if (boardFlag === 1 && memory.readI32(at(0x4a8aa8, boat)) < 80 &&
      irem32(add32(boat, f(memory, 0x4abef0).truncI32()), 4) === 0) {
    tailOffset = tailOffset.multiply(f(memory, originalTack === -1 ? 0x484ec8 : 0x484ed0));
  }
  const tailX = x80.subtract(tailOffset);
  put(memory, dest(0x4a3a58), lowerYStored);
  put(memory, dest(0x4ac330), tailX);
  const tailRelative1 = tailX.subtract(f(memory, 0x4ac310));
  put(memory, dest(0x4ac338), tailX);
  const tailRelative2 = tailX.subtract(f(memory, 0x4ac310));
  put(memory, dest(0x4a3a60), upperYStored);
  put(memory, dest(0x4a7a18), tailRelative1);
  put(memory, dest(0x4a7a20), tailRelative2);
}

/** Complete 0x413370: all original crew positions, poses, and timestamp writes. */
export function initializeCrewGeometry(memory, width, boat, screenY) {
  boat = i32(boat); screenY = i32(screenY);
  const r = address => memory.readI32(address);
  const rb = address => r(at(address, boat));
  const w = (address, value) => memory.writeI32(at(address, boat), value);
  if (r(0x491140) < boat && r(0x4ac928) === 1) return;
  const height = stored(f(memory, 0x4a3a38).subtract(f(memory, 0x4a3a40)).multiply(f(memory, 0x484e70)));
  let poseThreshold = r(0x491188) >= 6 && r(0x491188) <= 8 ? 22 : 15;
  if (r(0x4ac900) === 1) poseThreshold = 10;
  const normalPose = () => r(0x491140) < boat || r(0x491188) > 6 ||
    r(0x4a5b80) < rb(0x4a3a18) || add32(rb(0x4a41f0), r(0x4ac9d4)) <= r(0x4a5b80);
  const canTurn = () => boat <= r(0x491140) && r(0x491188) < 7 &&
    r(0x4a5b80) < add32(rb(0x4a41f0), r(0x4ac9d4));
  let pose;
  if (normalPose()) {
    pose = idiv32(poseThreshold, 3) < rb(0x4a6ec8) ? 2 : 1;
    if (canTurn() || r(0x4ac90c) === 1) pose = 2;
    if (r(0x491188) === 1 && boat <= r(0x491140)) w(0x4a3a18, 20000);
  } else pose = -1;
  let factor = crewPositionFactor(memory, pose);
  if (r(0x49114c) === 1 && r(0x491188) === 7) factor = f(memory, 0x484e10);
  const tack = rb(0x4aa730);
  let centerX, centerY;
  if (r(0x4ac900) === 0) {
    const side = f(memory, imul32(pose, tack) > 0 ? 0x4ac348 : 0x4ac388);
    centerX = stored(factor.multiply(side).add(f(memory, 0x4ac318)).divide(factor.subtract(f(memory, 0x484e78))));
    if (r(0x4ac90c) === 1) centerX = stored(centerX.subtract(i(tack).multiply(height).multiply(f(memory, 0x484d60))));
    if (r(0x4ac904) === 1 && rb(0x4a8aa8) < 80 && irem32(add32(f(memory, 0x4abef0).truncI32(), boat), 4) === 0)
      centerX = stored(centerX.subtract(f(memory, 0x484e80)));
    centerY = stored(f(memory, 0x4a3a40).subtract(height));
    if (r(0x491188) === 1) centerY = stored(centerY.subtract(height.multiply(f(memory, 0x484e88))));
  } else if (r(0x4ac900) === 1) {
    const side = f(memory, imul32(pose, tack) > 0 ? 0x4ac348 : 0x4ac390);
    centerX = stored(factor.multiply(side).add(f(memory, 0x4ac318)).divide(factor.subtract(f(memory, 0x484e78))));
    if (pose === 2 && [9, 10].includes(r(0x491188))) centerX = stored(centerX.subtract(i(tack).multiply(height).multiply(f(memory, r(0x491188) === 10 ? 0x484e90 : 0x484e80))));
    centerY = stored(f(memory, 0x4a3a40).add(f(memory, 0x4a3a48)).multiply(f(memory, 0x484da8)).subtract(height));
  } else throw new RangeError('Original crew geometry leaves centers uninitialized for this catamaran flag');
  writeCrewGeometry(memory, centerX.toNumber(), centerY.toNumber(), height.toNumber(), width, 39, boat, 1, screenY, pose);
  if (r(0x491188) < 2) return;
  if (normalPose()) {
    if (r(0x491188) > 1 && r(0x491188) < 4 && boat <= r(0x491140)) w(0x4a3a18, 20000);
    pose = idiv32(poseThreshold, 3) < rb(0x4a6ec8) ? 2 : 1;
    if (canTurn()) pose = 2;
    if (rb(0x4a6ec8) < 5) pose = r(0x491188) === 7 ? 1 : 0;
    if (rb(0x4a6ec8) < 5 && r(0x491188) === 9 && rb(0x4a7bc8) > 120) pose = -2;
  } else pose = -1;
  factor = crewPositionFactor(memory, pose);
  if (r(0x4ac900) === 0) {
    const side = f(memory, imul32(pose, tack) > 0 ? 0x4ac350 : 0x4ac380);
    centerX = stored(factor.multiply(side).add(f(memory, 0x4ac320)).divide(factor.subtract(f(memory, 0x484e78))));
    if (pose === 2) {
      if (r(0x491188) === 3) centerX = stored(centerX.subtract(i(tack).multiply(height).multiply(f(memory, 0x484e98))));
      if (r(0x4ac90c) === 1) centerX = stored(centerX.subtract(i(tack).multiply(height).multiply(f(memory, 0x484e90))));
    }
    centerY = stored(f(memory, 0x4a3a48).subtract(height.multiply(f(memory, 0x484e78))));
  } else {
    const side = f(memory, imul32(pose, tack) > 0 ? 0x4ac358 : 0x4ac380);
    centerX = stored(factor.multiply(side).add(f(memory, 0x4ac328)).divide(factor.subtract(f(memory, 0x484e78))));
    if (pose === 2) centerX = stored(centerX.subtract(i(tack).multiply(height).multiply(f(memory, 0x484e90))));
    centerY = stored(height.subtract(f(memory, 0x4a3a48).add(f(memory, 0x4a3a50)).multiply(f(memory, 0x484ea0))));
  }
  writeCrewGeometry(memory, centerX.toNumber(), centerY.toNumber(), height.toNumber(), width, 45, boat, 2, screenY, pose);
  if (r(0x491188) < 4 || r(0x4ac900) === 1) return;
  if (boat <= r(0x491140) && r(0x491188) < 7 && rb(0x4a3a18) <= r(0x4a5b80) &&
      r(0x4a5b80) < add32(rb(0x4a41f0), r(0x4ac9d4))) pose = -1;
  else {
    if (r(0x491188) < 7 && boat <= r(0x491140)) w(0x4a3a18, 20000);
    pose = idiv32(poseThreshold, 3) < rb(0x4a6ec8) ? 2 : 1;
    if (canTurn()) pose = 2;
    if (rb(0x4a6ec8) < 7 && r(0x491188) !== 7) pose = 0;
  }
  factor = crewPositionFactor(memory, pose);
  const side = f(memory, imul32(pose, rb(0x4aa730)) > 0 ? 0x4ac358 : 0x4ac378);
  centerX = stored(factor.multiply(side).add(f(memory, 0x4ac328)).divide(factor.subtract(f(memory, 0x484e78))));
  centerY = stored(f(memory, 0x4a3a50).subtract(height.multiply(f(memory, 0x484e98))));
  writeCrewGeometry(memory, centerX.toNumber(), centerY.toNumber(), height.toNumber(), width, 51, boat, 3, screenY, pose);
}

export const CREW_GEOMETRY_ROUTINES = Object.freeze({ crewPositionFactor: 0x4139d0, writeCrewGeometry: 0x413a20, initializeCrewGeometry: 0x413370 });
