import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createNativeHarness, assertNativeProvenance } from './native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createEngineBindings } from '../src/engine/port.js';
import { initializeGdiObjects } from '../src/engine/application.js';
import { initializeBoatOptions } from '../src/engine/boat-options.js';
import { initializeRace } from '../src/engine/initialization.js';
import { handleKeyDown } from '../src/engine/keyboard.js';
import { handleMenuCommand } from '../src/engine/menu-controller.js';
import { createOriginalRenderer } from '../src/render/index.js';
import { drawSimulationFrame } from '../src/render/paint-lifecycle.js';
import { GdiTrace } from '../src/render/gdi.js';

const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const source = await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe', import.meta.url));
const fixture = await json('fixtures/original-retained-board-frames.json');
const trig = createCapturedTrig(await json('../assets/data/x87-trig.json'), await json('../assets/data/x87-stored-trig.json'));

test('native Board preset/start prefix retains all actual state before its declared finite turn boundary', () => {
  assertNativeProvenance(source, fixture);
  assert.equal(fixture.cases.length, 9);
  assert.equal(fixture.cases[1].identifier, 32881);
  const initialized = fixture.cases.find(row => row.phase === 'start-initialize');
  assert.equal(initialized.expected.integers.selector, 3);
  assert.equal(initialized.expected.integers.boardFlag, 1);
  assert.equal(initialized.expected.integers.boatClass, 1);
  assert.equal(fixture.inputEvidence.constructorObjectCount, 90);
  const frames = fixture.cases.filter(row => row.phase === 'frame');
  assert.equal(frames.length, 3);
  assert.equal(frames[0].expected.integers.turn2, 0);
  assert.equal(frames[0].expected.integers.turn3, 0);
  for (const row of fixture.cases.slice(1)) { assert.equal(row.continue, true); assert.equal(row.seed, undefined); }
  for (const row of frames.slice(1)) assert.deepEqual(row.patches.map(patch => patch.address), [0x5364e8]);
});

test('three retained full board frames are exact for image, RNG, strings, ordered GDI/sounds/UI', () => {
  const harness = createNativeHarness(source, fixture), engine = createEngineBindings(), render = createOriginalRenderer();
  let objects = new Map();
  for (const [index, row] of fixture.cases.entries()) {
    const sounds = [], events = []; let ticks = 0, pixels = 0;
    const dc = new GdiTrace({ objects, readPixel: () => {
      if (pixels >= row.host.pixels.length) throw new RangeError('Original pixel budget exceeded');
      return row.host.pixels[pixels++];
    } });
    try {
      harness.check(row, index, (memory, rng) => {
        const options = { engine, render, trig, rng, windowHandle: 0x20000001,
          invalidateRect: event => events.push({ type: 'invalidateRect', ...event }),
          defaultKeyHandler: ({ key, repeat, flags }) => { events.push({ type: 'default', message: 0x100,
            wparam: key >>> 0, lparam: ((repeat & 0xffff) | (flags << 16)) >>> 0, result: 1 }); return 1; },
          playSound: event => { sounds.push(event); return 1; }, messageBeep: type => { dc.emit({ op: 'messageBeep', type }); return 1; },
          ...(row.host ? { menuHeight: row.host.menuHeight, getCursorPos: () => ({ x: row.host.cursor[0], y: row.host.cursor[1] }),
            getTickCount: () => (row.host.tickStart + ticks++) >>> 0 } : {}) };
        if (row.phase === 'initialize') { objects = initializeGdiObjects(memory); assert.equal(objects.size, 90); return initializeRace(memory, rng, options); }
        if (row.phase === 'start-options') return initializeBoatOptions(memory);
        if (row.phase === 'start-initialize') return initializeRace(memory, rng, options);
        if (row.phase === 'frame') return drawSimulationFrame(memory, dc, rng, options);
        if (row.kind === 2) { assert.equal(handleMenuCommand(memory, row.identifier, options), true); return; }
        if (row.kind === 1) return handleKeyDown(memory, row.arguments[0], { ...options, repeat: row.arguments[1], flags: row.arguments[2] });
        throw new Error('Unexpected native board continuation phase');
      });
      assert.deepEqual(events, row.expected.events ?? []);
      assert.deepEqual(sounds, row.expected.sounds ?? []);
      assert.deepEqual(dc.events, row.expected.drawingCommands ?? []);
      assert.equal(pixels, (row.expected.drawingCommands ?? []).filter(event => event.op === 'getPixel').length);
    } catch (error) { error.message = `case${index} ${row.label}: ${error.message}`; throw error; }
  }
});
