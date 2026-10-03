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
const fixtureBytes = await bytes('tests/fixtures/original-initialized-island-chart.json');
const fixture = JSON.parse(fixtureBytes);

test('island chart authority is fresh unchanged original initialization with both original panels', () => {
  assert.equal(sha(fixtureBytes), '6f9b3d86ad9c34b9cbb027d0ae5288771952893de60fd8091a7c15c955dee166');
  assert.equal(fixture.sourceSha256, sha(source));
  assert.equal(fixture.provenance.loadedOriginalTextUnchanged, true);
  assert.equal(fixture.provenance.originalFileUnchanged, true);
  assert.equal(fixture.provenance.x87ControlWord, '0x027f');
  assert.deepEqual(fixture.cases.map(row => row.routine.address), [0x420c00, 0x41be70, 0x407ff0, 0x407ff0]);
  assert.equal(fixture.cases[0].preparation.customCourseEditor, 0);
  assert.equal(fixture.cases.reduce((sum, row) => sum + (row.expected.drawingCommands?.length ?? 0), 0), 103);
  assert.ok(fixture.cases.slice(1).every(row => row.continue && !('seed' in row)));
  for (const row of fixture.cases.slice(1)) {
    assert.equal(row.expected.integers.island, 1);
    assert.equal(row.expected.integers.course, 7);
    assert.equal(row.expected.integers.calibratedHeight, 723);
  }
});

async function replayCharts(fixture) {
  const harness = createNativeHarness(source, fixture);
  const trig = createCapturedTrig(await json('assets/data/x87-trig.json'), await json('assets/data/x87-stored-trig.json'));
  const engine = createEngineBindings(), render = createOriginalRenderer();
  let objects = new Map();
  for (const [index, row] of fixture.cases.entries()) {
    const sounds = []; let ticks = 0;
    const dc = new GdiTrace({ objects });
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
      assert.equal(row.routine.address, 0x407ff0);
      return render.drawChart(memory, dc, ...row.arguments.slice(1), options);
    });
    assert.deepEqual(sounds, row.expected.sounds ?? [], `case${index}: original ordered sounds`);
    assert.deepEqual(dc.events, row.expected.drawingCommands ?? [], `case${index}: original ordered GDI`);
  }
}

test('both retained island charts match all native bytes, names, RNG, sounds and GDI', async () => {
  await replayCharts(fixture);
});

test('explicit clock-zero inputs exercise the original chart body with exact native state and GDI', async () => {
  const startedBytes = await bytes('tests/fixtures/original-initialized-island-chart-started.json');
  assert.equal(sha(startedBytes), '1afffe79b281a01ec2835c79c96012e922f89dcbe3c40908ac9177147648c29e');
  const started = JSON.parse(startedBytes);
  assert.deepEqual(started.cases[2].patches, [
    { address: 0x4f8cd0, bytes: '00000000' }, { address: 0x5359f0, bytes: '0000000000000000' },
  ]);
  assert.equal(started.cases.reduce((sum, row) => sum + (row.expected.drawingCommands?.length ?? 0), 0), 124);
  await replayCharts(started);
});
