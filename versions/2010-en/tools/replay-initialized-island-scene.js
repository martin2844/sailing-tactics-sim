import assert from 'node:assert/strict';
import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { createNativeHarness } from '../tests/native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createEngineBindings } from '../src/engine/port.js';
import { initializeBoatOptions } from '../src/engine/boat-options.js';
import { initializeRace } from '../src/engine/initialization.js';
import { initializeGdiObjects } from '../src/engine/application.js';
import { createOriginalRenderer } from '../src/render/index.js';
import { drawScene } from '../src/render/scene.js';
import { GdiTrace } from '../src/render/gdi.js';

// A fresh bounded observation. This never supplies retained local/stack values,
// edits renderer source, or rewrites original-native fixture expectations.
const edition = new URL('../', import.meta.url);
const json = async path => JSON.parse(await readFile(new URL(path, edition), 'utf8'));
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const fixtureBytes = await readFile(new URL('tests/fixtures/original-initialized-island-scene.json', edition));
const fixture = JSON.parse(fixtureBytes);
const source = await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition));
const harness = createNativeHarness(source, fixture);
const trig = createCapturedTrig(await json('assets/data/x87-trig.json'), await json('assets/data/x87-stored-trig.json'));
const engine = createEngineBindings(), render = createOriginalRenderer();
let objects = new Map();
const rows = [];
for (const [index, row] of fixture.cases.entries()) {
  let expected, error, pixels = 0, ticks = 0;
  const sounds = [];
  const dc = new GdiTrace({ objects, readPixel() {
    if (pixels >= row.host.pixels.length) throw new RangeError('Native island pixel budget exceeded');
    return row.host.pixels[pixels++];
  } });
  const started = performance.now();
  try {
    harness.check(row, index, (memory, rng) => {
      expected = memory.readBytes(fixture.mutableBlock.address, fixture.mutableBlock.size);
      for (const change of row.expected.imageChanges) {
        expected.set(Buffer.from(change.after, 'hex'), change.address - fixture.mutableBlock.address);
      }
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
      if (row.phase !== 'drawScene') throw new Error('Unknown bounded original routine');
      return drawScene(memory, dc, ...row.arguments.slice(1), options);
    });
    assert.deepEqual(sounds, row.expected.sounds ?? [], 'Original ordered sound requests');
    assert.deepEqual(dc.events, row.expected.drawingCommands ?? [], 'Original ordered drawing requests');
    assert.equal(pixels, (row.expected.drawingCommands ?? []).filter(event => event.op === 'getPixel').length);
  } catch (caught) {
    error = { name: caught.constructor.name, message: caught.message, stack: caught.stack };
  }
  const actual = harness.memory.readBytes(fixture.mutableBlock.address, fixture.mutableBlock.size);
  const differences = [];
  if (expected) for (let offset = 0; offset < actual.length; offset += 4) {
    const a = Buffer.from(actual.subarray(offset, offset + 4)), e = Buffer.from(expected.subarray(offset, offset + 4));
    if (!a.equals(e)) differences.push({ address: `0x${(fixture.mutableBlock.address + offset).toString(16)}`,
      actualBits: a.toString('hex'), expectedBits: e.toString('hex'), actualI32: a.readInt32LE(), expectedI32: e.readInt32LE() });
  }
  const eventDifferences = [];
  const nativeEvents = row.expected.drawingCommands ?? [];
  for (let eventIndex = 0; eventIndex < Math.max(nativeEvents.length, dc.events.length); eventIndex++) {
    if (JSON.stringify(nativeEvents[eventIndex]) !== JSON.stringify(dc.events[eventIndex])) {
      eventDifferences.push({ index: eventIndex, actual: dc.events[eventIndex], expected: nativeEvents[eventIndex] });
      if (eventDifferences.length === 20) break;
    }
  }
  rows.push({ index, phase: row.phase, routine: row.routine, elapsedMs: performance.now() - started,
    nativeIntegers: row.expected.integers, actualIntegers: Object.fromEntries(Object.entries(fixture.integerOutputs)
      .map(([name, address]) => [name, harness.memory.readI32(address)])),
    rng: { actual: harness.rng.state, expected: row.expected.rngState },
    sounds: { actual: sounds, expected: row.expected.sounds ?? [] },
    drawingCounts: { actual: dc.events.length, expected: nativeEvents.length },
    pixels, eventDifferences, differingWords: differences.length, firstWordDifferences: differences.slice(0, 24), error,
    exact: !error && differences.length === 0 && eventDifferences.length === 0 });
  if (error) break;
}
const report = { sourceSha256: sha(source), fixtureSha256: sha(fixtureBytes), fixture: 'tests/fixtures/original-initialized-island-scene.json',
  nativeCapturedCalls: fixture.cases.length, nativeOriginalTextUnchanged: fixture.provenance.loadedOriginalTextUnchanged,
  nativeOriginalFileUnchanged: fixture.provenance.originalFileUnchanged, x87ControlWord: fixture.provenance.x87ControlWord,
  profile: fixture.profiles[0], rows, exact: rows.length === fixture.cases.length && rows.every(row => row.exact),
  scope: 'Genuine original boat-options → race-initialization → island scene. Strict public JavaScript replay uses no retained local/stack injections and unchanged native expectations. GetPixel inputs are declared synthetic host observations, not raster identity.',
  sourceHashes: Object.fromEntries(await Promise.all(['src/render/drawing-functions.js', 'src/render/scene.js', 'src/render/host.js']
    .map(async path => [path, sha(await readFile(new URL(path, edition)))]))) };
await writeFile(new URL('analysis/initialized-island-scene-native-replay.json', edition), JSON.stringify(report, null, 2) + '\n');
console.log(JSON.stringify({ exact: report.exact, phases: rows.map(({ phase, exact, error, differingWords, drawingCounts }) =>
  ({ phase, exact, error: error?.message, differingWords, drawingCounts })) }, null, 2));
process.exitCode = report.exact ? 0 : 1;
