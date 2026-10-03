import assert from 'node:assert/strict';
import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { createNativeHarness } from './native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createEngineBindings } from '../src/engine/port.js';
import { initializeBoatOptions } from '../src/engine/boat-options.js';
import { initializeRace } from '../src/engine/initialization.js';
import { initializeGdiObjects } from '../src/engine/application.js';
import { createOriginalRenderer } from '../src/render/index.js';
import { GdiTrace } from '../src/render/gdi.js';

const edition = new URL('../', import.meta.url);
const bytes = path => readFile(new URL(path, edition));
const json = async path => JSON.parse(await bytes(path));
const sha = value => createHash('sha256').update(value).digest('hex');
const source = await bytes('runtime/Tactics2010EnglishPreserved.exe');
const fixtureBytes = await bytes('tests/fixtures/original-initialized-venue-render.json');
const fixture = JSON.parse(fixtureBytes);
const trig = createCapturedTrig(await json('assets/data/x87-trig.json'), await json('assets/data/x87-stored-trig.json'));
const engine = createEngineBindings();

test('initialized venue evidence preserves original startup inputs and exercised CDC aliases', () => {
  assert.equal(sha(fixtureBytes), 'a7d3dd559ee55fd6642c499cc352e12751c9939076cbb6a04208d2f3b5c64b2c');
  assert.equal(fixture.sourceSha256, sha(source));
  assert.equal(fixture.provenance.loadedOriginalTextUnchanged, true);
  assert.equal(fixture.provenance.originalFileUnchanged, true);
  assert.equal(fixture.provenance.x87ControlWord, '0x027f');
  assert.equal(fixture.cases.length, 16);
  assert.equal(fixture.cases.reduce((sum, row) => sum + (row.expected.drawingCommands?.length ?? 0), 0), 12712);
  assert.deepEqual(fixture.profiles.map(profile => profile.venue), [2, 6, 9, 106]);
  for (const venue of [6, 106]) {
    const row = fixture.cases.find(row => row.phase === 'drawScene' && row.profile.includes(`venue${venue}-`));
    for (const returnAddress of [0x482f84, 0x483084]) {
      assert.ok(row.expected.callObservations.some(event => event.returnAddress === returnAddress
        && event.service === 0x1002c && event.stackArgumentBytes === 4));
    }
  }
});

for (const profile of fixture.profiles) {
  test(`venue${profile.venue}: retained native options/race/scene/chart state and ordered GDI`, () => {
    const harness = createNativeHarness(source, fixture), render = createOriginalRenderer();
    let objects = new Map();
    const rows = fixture.cases.map((row, index) => ({ row, index })).filter(({ row }) => row.profile === profile.name);
    assert.equal(rows.length, 4);
    for (const { row, index } of rows) {
      const sounds = []; let ticks = 0, pixels = 0;
      const dc = new GdiTrace({ objects, readPixel() {
        if (pixels >= row.host.pixels.length) throw new RangeError('Original venue pixel input exhausted');
        return row.host.pixels[pixels++];
      } });
      harness.check(row, index, (memory, rng) => {
        const options = { engine, render, trig, rng,
          playSound: event => { sounds.push(event); return 1; },
          messageBeep: type => { dc.emit({ op: 'messageBeep', type }); return 1; },
          ...(row.host ? { menuHeight: row.host.menuHeight,
            getCursorPos: () => ({ x: row.host.cursor[0], y: row.host.cursor[1] }),
            getTickCount: () => (row.host.tickStart + ticks++) >>> 0 } : {}) };
        if (row.phase === 'boat-options') {
          objects = initializeGdiObjects(memory);
          assert.equal(objects.size, 90);
          return initializeBoatOptions(memory);
        }
        if (row.phase === 'race-initialization') return initializeRace(memory, rng, options);
        if (row.phase === 'drawScene') return render.drawScene(memory, dc, ...row.arguments.slice(1), options);
        assert.equal(row.phase, 'drawChart');
        return render.drawChart(memory, dc, ...row.arguments.slice(1), options);
      });
      assert.deepEqual(sounds, row.expected.sounds ?? [], `case${index}: original ordered sounds`);
      assert.deepEqual(dc.events, row.expected.drawingCommands ?? [], `case${index}: original ordered GDI`);
      assert.equal(pixels, (row.expected.drawingCommands ?? []).filter(event => event.op === 'getPixel').length);
    }
  });
}
