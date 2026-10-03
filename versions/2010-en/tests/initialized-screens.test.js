import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance, createNativeHarness } from './native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createEngineBindings } from '../src/engine/port.js';
import { initializeBoatOptions } from '../src/engine/boat-options.js';
import { initializeRace } from '../src/engine/initialization.js';
import { initializeGdiObjects } from '../src/engine/application.js';
import { createOriginalRenderer } from '../src/render/index.js';
import { drawStartScreen, drawResultsScreen, drawForecastScreen } from '../src/render/screens.js';
import { GdiTrace } from '../src/render/gdi.js';

const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const source = await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe', import.meta.url));
const fixture = await json('fixtures/original-initialized-screens.json');
const trig = createCapturedTrig(await json('../assets/data/x87-trig.json'),
  await json('../assets/data/x87-stored-trig.json'));
const engine = createEngineBindings(), render = createOriginalRenderer();
const screens = { drawStartScreen, drawResultsScreen, drawForecastScreen };

test('initialized screens retain original code, caller state, names and constructor GDI evidence', () => {
  assertNativeProvenance(source, fixture);
  assert.deepEqual(fixture.profiles.map(profile => profile.selector), [1, 7, 12, 17, 26, 27]);
  assert.equal(fixture.cases.length, 30);
  assert.equal(fixture.inputEvidence.constructorObjectCount, 90);
  assert.equal(new Set(fixture.inputEvidence.constructorObjects.map(object => object.handleAddress)).size, 90);
  for (const profile of fixture.profiles) {
    const rows = fixture.cases.filter(row => row.profile === profile.name);
    assert.deepEqual(rows.map(row => row.routine.address), [0x420c00, 0x41be70, 0x413bc0, 0x428b70, 0x4298f0]);
    assert.equal(rows[0].continue, undefined);
    assert.equal(rows[0].preparation.customCourseEditor, 0);
    for (const row of rows.slice(1)) {
      assert.equal(row.continue, true);
      assert.equal(row.seed, undefined, 'native RNG remains retained between actual routines');
      assert.deepEqual(row.patches ?? [], [], 'no gameplay or final-state substitutions between original calls');
      assert.deepEqual(row.strings ?? [], [], 'all boat names come from actual original initialization');
      assert.equal(row.expected.globalStrings.length, 36);
      const names = row.expected.globalStrings.filter(string => string.address >= 0x4fec30);
      assert.equal(names.length, 35);
      assert.equal(names.filter(string => string.bytes).length, 30);
      for (let boat = 1; boat <= profile.boats; boat++) assert.ok(names[boat].bytes.length > 0);
      assert.equal(row.expected.integers.venue, 0);
      assert.equal(row.expected.integers.calibratedWidth, 1024);
      assert.equal(row.expected.integers.calibratedHeight, 723);
    }
  }
});

for (const profile of fixture.profiles) test(`${profile.name}: public screens match retained native state, names, RNG, sound and drawing order`, () => {
  const harness = createNativeHarness(source, fixture);
  const rows = fixture.cases.filter(row => row.profile === profile.name);
  let objects = new Map();
  for (const [index, row] of rows.entries()) {
    const sounds = [];
    let pixels = 0, ticks = 0;
    const dc = new GdiTrace({ objects, readPixel() {
      if (pixels >= row.host.pixels.length) throw new RangeError('Screen exceeded its declared native pixel inputs');
      return row.host.pixels[pixels++];
    } });
    harness.check(row, index, (memory, rng) => {
      const options = { engine, render, trig, rng,
        playSound: event => { sounds.push(event); return 1; },
        messageBeep: type => { dc.emit({ op: 'messageBeep', type }); return 1; },
        ...(row.host ? { menuHeight: row.host.menuHeight,
          getCursorPos: () => ({ x: row.host.cursor[0], y: row.host.cursor[1] }),
          getTickCount: () => (row.host.tickStart + ticks++) >>> 0 } : {}),
      };
      if (row.phase === 'boat-options') {
        objects = initializeGdiObjects(memory);
        assert.equal(objects.size, 90);
        return initializeBoatOptions(memory);
      }
      if (row.phase === 'race-initialization') return initializeRace(memory, rng, options);
      const screen = screens[row.phase];
      if (!screen) throw new Error('Unknown complete original screen routine');
      return screen(memory, dc, rng, options);
    });
    assert.deepEqual(sounds, row.expected.sounds ?? [], `row ${index}: original ordered sound requests`);
    assert.deepEqual(dc.events, row.expected.drawingCommands ?? [], `row ${index}: original ordered drawing requests`);
    assert.equal(pixels, (row.expected.drawingCommands ?? []).filter(event => event.op === 'getPixel').length);
  }
});
