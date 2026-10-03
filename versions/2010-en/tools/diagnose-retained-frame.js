import { readFile, writeFile } from 'node:fs/promises';
import { createNativeHarness } from '../tests/native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createEngineBindings } from '../src/engine/port.js';
import { initializeGdiObjects } from '../src/engine/application.js';
import { initializeRace } from '../src/engine/initialization.js';
import { createOriginalRenderer } from '../src/render/index.js';
import { drawSimulationFrame } from '../src/render/paint-lifecycle.js';
import { GdiTrace } from '../src/render/gdi.js';

// Diagnostic only: retain the strict native fixture and report differences.
// Expected bytes always come from recorded original native deltas.
const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const name = process.argv[2] ?? 'coastal-venue5-two-human-started';
const frame = Number(process.argv[3] ?? 0);
if (!Number.isInteger(frame) || frame < 0 || frame >= 100) throw new Error('Frame must be an original captured index0..99');
const graphics = name.includes('constructor-graphics');
const fixture = await json(`../tests/fixtures/original-retained-${graphics ? 'graphics-' : ''}frames.json`);
const source = await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe', import.meta.url));
const profile = fixture.profiles.find(row => row.name === name);
if (!profile) throw new Error('Profile is not in the original native fixture');
const rows = fixture.cases.filter(row => row.profile === name);
const harness = createNativeHarness(source, fixture);
const trig = createCapturedTrig(await json('../assets/data/x87-trig.json'), await json('../assets/data/x87-stored-trig.json'));
const engine = createEngineBindings(), render = createOriginalRenderer();
let objects = new Map();
harness.check(rows[0], 0, (memory, rng) => {
  if (profile.constructorGraphics) objects = initializeGdiObjects(memory);
  return initializeRace(memory, rng, { engine, render, trig, rng });
});
const invoke = (row, dc, sounds, clock) => (memory, rng) => drawSimulationFrame(memory, dc, rng, {
  engine, render, trig, rng, menuHeight: row.host.menuHeight,
  getCursorPos: () => ({ x: row.host.cursor[0], y: row.host.cursor[1] }),
  getTickCount: () => (row.host.tickStart + clock.ticks++) >>> 0,
  playSound: event => { sounds.push(event); return 1; },
  messageBeep: type => { dc.emit({ op: 'messageBeep', type }); return 1; },
});
for (let prior = 0; prior < frame; prior++) {
  const row = rows[prior + 1], sounds = [], clock = { ticks: 0, pixels: 0 };
  const dc = new GdiTrace({ objects, readPixel: () => row.host.pixels[clock.pixels++] });
  harness.check(row, prior + 1, invoke(row, dc, sounds, clock));
  if (JSON.stringify(dc.events) !== JSON.stringify(row.expected.drawingCommands) || JSON.stringify(sounds) !== JSON.stringify(row.expected.sounds)) {
    throw new Error(`Prior native frame${prior} differs; cannot diagnose a later retained frame without correcting the earlier source`);
  }
}
const row = rows[frame + 1], base = fixture.mutableBlock.address;
for (const patch of row.patches) harness.memory.writeBytes(patch.address, Buffer.from(patch.bytes, 'hex'));
const expected = harness.memory.readBytes(base, fixture.mutableBlock.size);
for (const change of row.expected.imageChanges) expected.set(Buffer.from(change.after, 'hex'), change.address - base);
const clock = { ticks: 0, pixels: 0 };
let error;
const sounds = [];
const dc = new GdiTrace({ objects, readPixel() {
  if (clock.pixels >= row.host.pixels.length) throw new RangeError('Declared native pixel budget exceeded');
  return row.host.pixels[clock.pixels++];
} });
const started = performance.now();
try {
  harness.check(row, frame + 1, invoke(row, dc, sounds, clock));
} catch (caught) { error = { message: caught.message, stack: caught.stack }; }
const elapsedMs = performance.now() - started;
const actual = harness.memory.readBytes(base, expected.length);
const wordDifferences = [];
for (let offset = 0; offset < expected.length; offset += 4) {
  const a = Buffer.from(actual.subarray(offset, offset + 4)), e = Buffer.from(expected.subarray(offset, offset + 4));
  if (!a.equals(e)) wordDifferences.push({ address: `0x${(base + offset).toString(16)}`,
    actual: a.toString('hex'), expected: e.toString('hex'), actualI32: a.readInt32LE(), expectedI32: e.readInt32LE() });
}
const nativeEvents = row.expected.drawingCommands;
const eventDifferences = [];
for (let index = 0; index < Math.max(nativeEvents.length, dc.events.length); index++) {
  if (JSON.stringify(nativeEvents[index]) !== JSON.stringify(dc.events[index])) {
    eventDifferences.push({ index, actual: dc.events[index], expected: nativeEvents[index] });
    if (eventDifferences.length === 25) break;
  }
}
const report = { sourceSha256: fixture.sourceSha256, profile: name, nativeFrame: frame, elapsedMs, error,
  rng: { actual: harness.rng.state, expected: row.expected.rngState },
  sounds: { actual: sounds, expected: row.expected.sounds },
  ticks: clock.ticks, pixels: clock.pixels, differingWords: wordDifferences.length, wordDifferences,
  drawingCounts: { actual: dc.events.length, expected: nativeEvents.length }, eventDifferences,
  scope: 'Retained full original frame after the native-verified initializer and strictly matched prior frames. Expected state/drawing requests are unchanged original hardware observations; this tool reports failures and does not update fixtures.' };
const destination = new URL(`../analysis/retained-frame-diagnostic-${name}${frame ? `-frame${frame}` : ''}.json`, import.meta.url);
await writeFile(destination, JSON.stringify(report, null, 2) + '\n');
console.log(JSON.stringify({ profile: name, elapsedMs, differingWords: wordDifferences.length,
  drawingCounts: report.drawingCounts, firstDifferences: wordDifferences.slice(0, 20),
  firstEventDifference: eventDifferences[0], error: error?.message }, null, 2));
process.exitCode = error || wordDifferences.length || eventDifferences.length ? 1 : 0;
