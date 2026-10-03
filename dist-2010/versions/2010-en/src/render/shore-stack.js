import { framePointer, readLocal, writeLocal } from './typed-c.js';

export const SHORE_STACK_LAYOUT = Object.freeze({
  routine: 0x440400,
  previousX: 280,       // entryESP - 0xb54; POINT at276 aliases its Y here.
  previousTreeY: 1004,  // entryESP - 0x880; predecessor of the first tree row.
});

const sourceSha256 = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
const states = new WeakMap();
const signedWord = (value, field) => {
  if (!Number.isInteger(value) || value < -0x80000000 || value > 0x7fffffff) {
    throw new TypeError(`Original shoreline ${field} requires an explicit signed I32 caller value`);
  }
  return value;
};
const stateFor = model => {
  const state = states.get(model);
  if (!state) throw new TypeError('Original shoreline requires a model created from an explicit caller reference');
  return state;
};

/**
 * Retain the two observed original caller slots. Initial values belong to the
 * supplied caller context: intact UI and bounded reference hosts differ.
 * This does not seed other locals or derive coordinates from drawing outputs.
 */
export function createShoreStack(reference) {
  if (!reference || typeof reference !== 'object') {
    throw new TypeError('Original shoreline requires an explicit caller reference');
  }
  if (reference.sourceSha256 !== undefined && reference.sourceSha256 !== sourceSha256) {
    throw new TypeError('Original shoreline reference belongs to another executable');
  }
  const initial = reference.initialStack ?? reference;
  const state = {
    previousX: signedWord(initial.previousX, 'previousX'),
    previousTreeY: signedWord(initial.previousTreeY, 'previousTreeY'),
    completedCalls: 0,
    activeFrames: new WeakSet(),
  };
  const model = Object.freeze({
    snapshot: () => Object.freeze({
      previousX: state.previousX,
      previousTreeY: state.previousTreeY,
      completedCalls: state.completedCalls,
    }),
  });
  states.set(model, state);
  return model;
}

/** Called only for original440400, immediately after its local frame exists. */
export function restoreShoreStackFrame(frame, model) {
  if (model === undefined) return;
  const state = stateFor(model);
  if (state.activeFrames.has(frame)) throw new TypeError('Original shoreline frame was already restored');
  writeLocal(framePointer(frame, SHORE_STACK_LAYOUT.previousX), state.previousX, 4);
  writeLocal(framePointer(frame, SHORE_STACK_LAYOUT.previousTreeY), state.previousTreeY, 4);
  state.activeFrames.add(frame);
}

/**
 * Called at normal original returns. Read actual local bytes after every real
 * POINT/array write; POINT.y at276 therefore updates previousX automatically.
 */
export function saveShoreStackFrame(frame, model) {
  if (model === undefined) return;
  const state = stateFor(model);
  if (!state.activeFrames.has(frame)) throw new TypeError('Original shoreline frame was not restored');
  const previousX = readLocal(framePointer(frame, SHORE_STACK_LAYOUT.previousX), 4);
  const previousTreeY = readLocal(framePointer(frame, SHORE_STACK_LAYOUT.previousTreeY), 4);
  state.previousX = previousX;
  state.previousTreeY = previousTreeY;
  state.completedCalls++;
  state.activeFrames.delete(frame);
}
