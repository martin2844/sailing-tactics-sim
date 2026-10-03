import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/memory.js';
import { withX87ControlWord } from '../src/runtime/float80.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createHullTrig } from '../src/engine/hull-geometry.js';
import { createRawTrig } from '../src/engine/terrain.js';
import { GdiTrace } from '../src/render/gdi.js';
import { drawScene } from '../src/render/scene.js';
import { getHudText } from '../src/render/hud.js';
import { drawSimulationFrame } from '../src/render/paint-lifecycle.js';
import { assertNativeAuthority } from './native-authority.js';

const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const [original, fixture, extended, stored, force, hull, raw] = await Promise.all([
  readFile(new URL('../original/Tact02Demo.exe', import.meta.url)), json('./fixtures/original-connected-frames-p53.json'),
  json('../assets/data/pc53/x87-trig.json'), json('../assets/data/pc53/x87-stored-trig.json'),
  json('../assets/data/pc53/x87-force-trig.json'), json('../assets/data/pc53/x87-hull-trig.json'),
  json('../assets/data/pc53/x87-raw-trig.json'),
]);
const hash = value => createHash('sha256').update(value).digest('hex');
const bytes = value => Uint8Array.from(Buffer.from(value, 'hex'));
const reference = { trig: createCapturedTrig(extended, stored, force), hullTrig: createHullTrig(hull), rawTrig: createRawTrig(raw) };
const originalMemory = loadPE32(original);
for (const patch of fixture.baseline.patches) originalMemory.writeBytes(patch.address, bytes(patch.bits));
const baseline = originalMemory.bytes.slice(), block = fixture.mutableBlock;

test('complete precision53 frame references have strict unchanged-original native authority for these exact bytes', async () => {
  await assertNativeAuthority('original-connected-frames-p53.json', 'connected-frames-p53-native-reference-comparison.json', fixture);
});

test('complete-frame evidence keeps measured application precision separate from isolated precision64 captures', () => {
  assert.equal(fixture.provenance.sha256, hash(original));
  assert.equal(fixture.provenance.x87_control_word, '0x027f');
  assert.match(fixture.provenance.note, /Every game child executes/);
  assert.equal(fixture.routines.drawSimulationFrame.address, 0x404020);
  for (const capture of [extended, stored, force, hull, raw]) {
    assert.equal(capture.provenance.sha256, fixture.provenance.sha256);
    assert.equal(capture.provenance.authoritative_engine, 'native-x87');
    assert.equal(capture.provenance.x87_control_word, '0x027f');
  }
  const cases = fixture.routines.drawSimulationFrame.cases;
  assert.equal(cases.length, 180);
  assert.equal(new Set(cases.map(row => row.profileIndex)).size, 60);
  assert.deepEqual([...new Set(cases.map(row => row.configuration.course))], [1, 2, 4, 6, 8]);
  assert.deepEqual([...new Set(cases.map(row => row.configuration.humans))], [1, 2]);
  assert.ok(cases.some(row => row.shorelineStackObservations.length === 2));
});

test('complete original404020 frame: all mutable bytes, RNG, ordered drawing, sounds, HUD and explicit OS inputs', () => {
  const failures = [];
  for (const [index, row] of fixture.routines.drawSimulationFrame.cases.entries()) {
    const memory = loadPE32(original); memory.bytes.set(baseline);
    for (const input of row.imageInputs) memory.writeBytes(input.address, bytes(input.bits));
    const before = memory.readBytes(block.address, block.size), expected = before.slice();
    for (const change of row.expected.imageChanges) {
      assert.equal(Buffer.from(before.slice(change.address - block.address, change.address - block.address + change.before.length / 2)).toString('hex'), change.before);
      expected.set(bytes(change.after), change.address - block.address);
    }
    assert.equal(hash(expected), row.expected.mutableBlockHash);
    const rng = new PoseyRng(row.seedAtCall), sounds = [];
    let pixel = 0, scene = 0, duration = 0;
    const dc = new GdiTrace({ readPixel: () => {
      if (pixel >= row.pixelReadValues.length) throw new RangeError('Original GetPixel input bound exceeded');
      return row.pixelReadValues[pixel++];
    } });
    const options = { ...reference, cursor: row.cursor,
      messageBeep: type => dc.emit({ op: 'messageBeep', type }),
      playSound: request => { sounds.push(request); return 1; },
      enforceMinimumPaintDuration: value => { duration = value; },
      drawScene: (sceneMemory, sceneDc, ...argumentsAndOptions) => {
        const sceneOptions = argumentsAndOptions.pop();
        const observed = row.shorelineStackObservations[scene++];
        if (!observed) throw new RangeError('Original retained shoreline input bound exceeded');
        drawScene(sceneMemory, sceneDc, ...argumentsAndOptions, { ...sceneOptions, shorelineStack: { ...observed, ...observed.consumed } });
      },
    };
    try { withX87ControlWord(0x027f, () => drawSimulationFrame(memory, dc, rng, options)); }
    catch (error) { failures.push({ index, configuration: row.configuration, error: error.message }); continue; }
    const actual = memory.readBytes(block.address, block.size), offset = actual.findIndex((value, at) => value !== expected[at]);
    if (offset >= 0) failures.push({ index, address: `0x${(block.address + offset).toString(16)}`, actual: Buffer.from(actual.slice(offset, offset + 16)).toString('hex'), expected: Buffer.from(expected.slice(offset, offset + 16)).toString('hex') });
    const event = dc.events.findIndex((value, at) => JSON.stringify(value) !== JSON.stringify(row.expected.drawingCommands[at]));
    if (event >= 0 || dc.events.length !== row.expected.drawingCommands.length) failures.push({ index, event, eventCount: dc.events.length, expectedEventCount: row.expected.drawingCommands.length, actual: dc.events.slice(Math.max(event, 0), Math.max(event, 0) + 2), expected: row.expected.drawingCommands.slice(Math.max(event, 0), Math.max(event, 0) + 2) });
    if (rng.state !== row.expected.rngState) failures.push({ index, rng: rng.state, expectedRng: row.expected.rngState });
    if (JSON.stringify(sounds) !== JSON.stringify(row.expected.sounds)) failures.push({ index, sounds, expectedSounds: row.expected.sounds });
    if (getHudText(memory) !== row.expected.hudText) failures.push({ index, hudText: getHudText(memory), expectedHudText: row.expected.hudText });
    if (duration !== row.expected.elapsedPaintTicks) failures.push({ index, duration, expectedDuration: row.expected.elapsedPaintTicks });
    if (pixel !== row.pixelReadValues.length || scene !== row.shorelineStackObservations.length) failures.push({ index, pixelInputs: [pixel, row.pixelReadValues.length], sceneInputs: [scene, row.shorelineStackObservations.length] });
  }
  assert.equal(failures.length, 0, `${failures.length} differences; first ${JSON.stringify(failures.slice(0, 18))}`);
});
