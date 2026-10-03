import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance, createNativeHarness } from './native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createEngineBindings } from '../src/engine/port.js';
import { initializeGdiObjects } from '../src/engine/application.js';
import { initializeRace } from '../src/engine/initialization.js';
import { createOriginalRenderer } from '../src/render/index.js';
import { drawSimulationFrame } from '../src/render/paint-lifecycle.js';
import { GdiTrace } from '../src/render/gdi.js';

const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const source = await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe', import.meta.url));
const fixtures = [await json('fixtures/original-retained-frames.json'), await json('fixtures/original-retained-graphics-frames.json')];
const trig = createCapturedTrig(await json('../assets/data/x87-trig.json'), await json('../assets/data/x87-stored-trig.json'));
const engine = createEngineBindings();
const render = createOriginalRenderer();

for (const fixture of fixtures) {
test(`retained full frames (${fixture.profiles.length} profiles): original initialization and all actual children, declared caller cadence only`, () => {
  assertNativeProvenance(source, fixture);
  assert.equal(fixture.cases.length, fixture.profiles.length * 101);
  assert.ok(fixture.profiles.length === 3 || fixture.profiles.length === 1);
  if (fixture.profiles.length === 1) {
    assert.equal(fixture.profiles[0].constructorGraphics, true);
    assert.equal(fixture.inputEvidence.constructorObjectCount, 90);
  }
  for (const profile of fixture.profiles) {
    const rows = fixture.cases.filter(row => row.profile === profile.name);
    assert.equal(rows.length, 101);
    assert.equal(rows[0].routine.address, 0x41be70);
    assert.equal(rows[0].continue, undefined);
    for (const [index, row] of rows.slice(1).entries()) {
      assert.equal(row.routine.address, 0x4049f0);
      assert.equal(row.continue, true);
      assert.equal(row.seed, undefined, 'retained original RNG must not be reseeded');
      assert.deepEqual(row.inputs ?? {}, {});
      assert.deepEqual(row.doubleInputs ?? {}, {});
      assert.equal(row.patches.length, 1, 'only the original caller paint counter may change');
      assert.equal(row.patches[0].address, 0x5364e8);
      assert.equal(Buffer.from(row.patches[0].bytes, 'hex').readInt32LE(), index % 60 + 1);
      assert.equal(row.callerInput.routine, 0x404510);
      assert.equal(row.host.pixels.length, 1024);
      assert.ok(row.host.pixels.every(color => color === 0xffffff));
      assert.ok(row.expected.drawingCommands.length > 0);
    }
  }
});

for (const profile of fixture.profiles) test(`${profile.name}: 100 continuous full frames match native state, text, RNG, sounds and drawing order`, () => {
  const harness = createNativeHarness(source, fixture);
  const rows = fixture.cases.filter(row => row.profile === profile.name);
  let initialTime;
  let objects = new Map();
  for (const [index, row] of rows.entries()) {
    const sounds = [];
    let pixels = 0, ticks = 0;
    const dc = new GdiTrace({ objects, readPixel() {
      if (pixels >= row.host.pixels.length) throw new RangeError('Full frame exceeded the declared original pixel input budget');
      return row.host.pixels[pixels++];
    } });
    try { harness.check(row, index, (memory, rng) => {
      const options = { engine, render, trig, rng,
        playSound: event => { sounds.push(event); return 1; },
        messageBeep: type => { dc.emit({ op: 'messageBeep', type }); return 1; },
        ...(row.host ? { menuHeight: row.host.menuHeight,
          getCursorPos: () => ({ x: row.host.cursor[0], y: row.host.cursor[1] }),
          getTickCount: () => (row.host.tickStart + ticks++) >>> 0 } : {}),
      };
      if (row.phase === 'initialize') {
        if (profile.constructorGraphics) {
          objects = initializeGdiObjects(memory);
          assert.equal(objects.size, 90, 'all exact original constructor pen and brush objects');
        }
        return initializeRace(memory, rng, options);
      }
      return drawSimulationFrame(memory, dc, rng, options);
    }); } catch (error) {
      error.message = `${profile.name}, ${row.phase}, frame ${row.frame ?? 'initialization'}, case ${index}: ${error.message}`;
      throw error;
    }
    assert.deepEqual(sounds, row.expected.sounds, `row${index}: original ordered sound requests`);
    const nativeDrawing = row.expected.drawingCommands ?? [];
    const context = `${profile.name}, ${row.phase}, frame ${row.frame ?? 'initialization'}, case ${index}`;
    assert.equal(dc.events.length, nativeDrawing.length, `${context}: original drawing request count`);
    for (let event = 0; event < nativeDrawing.length; event++) {
      assert.deepEqual(dc.events[event], nativeDrawing[event], `${context}: original ordered drawing request${event}`);
    }
    assert.equal(pixels, (row.expected.drawingCommands ?? []).filter(event => event.op === 'getPixel').length);
    if (row.phase === 'initialize') {
      initialTime = harness.memory.readF64(0x5359f0);
      for (const [name, required] of Object.entries(profile.required)) assert.equal(row.expected.integers[name], required, `actual original initialized ${name}`);
    } else assert.ok(ticks > 0, 'original full frame reads the declared host tick counter');
  }
  assert.ok(harness.memory.readF64(0x5359f0) > initialTime, 'original precise race time advances continuously');
  assert.equal(harness.memory.readI32(0x5364e8), 40, 'original 60-paint cadence wraps');
});
}
