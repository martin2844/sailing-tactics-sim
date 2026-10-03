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
import { createLocalFrame, framePointer, writeLocalPoint, readLocal } from '../src/render/typed-c.js';
import { createShoreStack, restoreShoreStackFrame, saveShoreStackFrame, SHORE_STACK_LAYOUT } from '../src/render/shore-stack.js';

const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const edition = new URL('../', import.meta.url);
const bytes = path => readFile(new URL(path, edition));
const json = async path => JSON.parse(await bytes(path));
const source = await bytes('runtime/Tactics2010EnglishPreserved.exe');
const originalBaseline = Buffer.from((await json('tests/fixtures/original-boat-options.json')).mutableBaseline, 'hex');
const trig = createCapturedTrig(await json('assets/data/x87-trig.json'), await json('assets/data/x87-stored-trig.json'));
const engine = createEngineBindings();
const observationPublication = await json('analysis/island-shore-context-observation-publication.json');
const fixtureHashes = {
  'original-island-shore-context': '7be3b5f096ebdcf199baa73c79650799cf9af599b6d30555cacb4710175aea22',
  'original-island-shore-context-repeat': '0acb56eef8189db5308daa5a4ae632d7e5f851b5b1b6f94172f04a63bd4f5820',
};

test('shore model seeds only the observed caller slots and retains the real POINT alias', () => {
  assert.throws(() => createShoreStack(), /explicit caller reference/);
  assert.throws(() => createShoreStack({ previousX: 1 }), /explicit signed I32/);
  const model = createShoreStack({ previousX: 604045502, previousTreeY: 0 });
  const frame = createLocalFrame(3180);
  restoreShoreStackFrame(frame, model);
  assert.deepEqual(Array.from(frame.valid.entries()).filter(([, valid]) => valid).map(([index]) => index),
    [280, 281, 282, 283, 1004, 1005, 1006, 1007]);
  assert.throws(() => readLocal(framePointer(frame, 1000), 4), /undefined retained local byte/);
  // Original iStack_b58 POINT at276 has its Y word exactly at X0 offset280.
  writeLocalPoint(framePointer(frame, 276), { x: -123, y: 1200 });
  saveShoreStackFrame(frame, model);
  assert.deepEqual(model.snapshot(), { previousX: 1200, previousTreeY: 0, completedCalls: 1 });
  const next = createLocalFrame(3180);
  restoreShoreStackFrame(next, model);
  assert.equal(readLocal(framePointer(next, SHORE_STACK_LAYOUT.previousX), 4), 1200);
  assert.equal(readLocal(framePointer(next, SHORE_STACK_LAYOUT.previousTreeY), 4), 0);
});

test('production initial reference is pinned to two actual normal UI caller observations', async () => {
  const assetBytes = await bytes('assets/data/initial-shoreline-stack.json');
  assert.equal(sha(assetBytes), '4834efd3d4f08f8535828888fd8e3515cd90662acacb6571a6ad0e4c087865fb');
  const asset = JSON.parse(assetBytes);
  assert.equal(asset.sourceSha256, sha(source));
  assert.deepEqual(asset.initialStack, { previousX: 604045502, previousTreeY: 0 });
  const reportBytes = await bytes(asset.evidence.report);
  assert.equal(sha(reportBytes), asset.evidence.reportSha256);
  const report = JSON.parse(reportBytes);
  assert.equal(report.targetGameMemoryWrites, 0);
  assert.equal(report.loadedOriginalTextUnchanged, true);
  assert.equal(report.launches.length, 2);
  for (const launch of report.launches) {
    assert.equal(sha(await bytes(launch.log)), launch.logSha256);
    assert.equal(launch.samples.length, 3);
    assert.deepEqual(Object.fromEntries(launch.samples[0].reads.map(row => [row.field, row.value])), asset.initialStack);
    for (let index = 1; index < launch.samples.length; index++) {
      assert.equal(launch.samples[index].entry.previousX, launch.samples[index - 1].exit.previousX);
      assert.equal(launch.samples[index].entry.previousTreeY, launch.samples[index - 1].exit.previousTreeY);
    }
  }
});

for (const [name, pinnedHash] of Object.entries(fixtureHashes)) {
  const fixtureBytes = await bytes(`tests/fixtures/${name}.json`);
  const fixture = JSON.parse(fixtureBytes);
  test(`${name}: ten retained original calls match all bytes, names, RNG, sounds and GDI`, async () => {
    assert.equal(sha(fixtureBytes), pinnedHash);
    assert.equal(fixture.sourceSha256, sha(source));
    assert.equal(fixture.provenance.sha256, sha(source));
    assert.equal(fixture.provenance.engine, 'Original fixed x86 code under Wine, observed at four hardware execution points');
    assert.equal(fixture.provenance.x87ControlWord, '0x027f');
    assert.equal(fixture.provenance.loadedOriginalTextUnchanged, true);
    assert.equal(fixture.provenance.originalFileUnchanged, true);
    assert.equal(fixture.provenance.targetGameMemoryWritesByObserver, 0);
    assert.equal(fixture.provenance.stackInputsSupplied, false);
    assert.deepEqual(Buffer.from(fixture.mutableBaseline, 'hex'), originalBaseline);
    assert.equal(fixture.cases.length, 10);
    assert.equal(fixture.cases.reduce((count, row) => count + row.shoreReads.length, 0), 16);
    assert.equal(observationPublication.sourceSha256, sha(source));
    const publication = observationPublication.copies.find(row => row.fixture === `tests/fixtures/${name}.json`);
    assert.ok(publication, 'Measured observation publication is available in a fresh checkout');
    assert.equal(publication.fixtureSha256, pinnedHash);
    assert.equal(publication.originalPath, fixture.provenance.rawObservations);
    const observationBytes = await bytes(publication.publicationPath);
    assert.equal(observationBytes.length, publication.bytes);
    assert.equal(sha(observationBytes), publication.sha256);
    const observed = observationBytes.toString('utf8').trim().split(/\r?\n/).map(JSON.parse);
    assert.deepEqual(observed, fixture.cases.flatMap(row => row.shoreReads));
    for (const read of observed) {
      assert.equal(read.controlWord, 0x027f);
      assert.equal(read.first, 0);
      assert.equal(read.last, 36);
      assert.equal(read.camera, 1);
      assert.equal(read.address, read.entryEsp - 0x880);
      assert.equal(read.xAddress, read.entryEsp - 0xb54);
    }
    // Adapt only the provenance label/baseline digest to the established strict
    // harness after independently checking this hardware-observer contract.
    // All captured cases, deltas, hashes, names and expectations stay identical.
    const harness = createNativeHarness(source, { ...fixture, provenance: { ...fixture.provenance,
      engine: 'Original x86 code under Wine; no text edits', mutableBaselineSha256: sha(originalBaseline) } });
    const firstRead = observed[0];
    const shoreStack = createShoreStack({ sourceSha256: fixture.sourceSha256,
      initialStack: { previousX: firstRead.previousXAtYRead, previousTreeY: firstRead.previousTreeY } });
    const render = createOriginalRenderer({ shoreStack });
    let objects = new Map(), scenes = 0;
    for (const [index, row] of fixture.cases.entries()) {
      const sounds = []; let pixels = 0, ticks = 0;
      const dc = new GdiTrace({ objects, readPixel() {
        if (pixels >= row.host.pixels.length) throw new RangeError('Native shoreline pixel budget exceeded');
        return row.host.pixels[pixels++];
      } });
      if (row.shoreReads.length) {
        assert.equal(shoreStack.snapshot().previousX, row.shoreReads[0].previousXAtYRead,
          `case${index}: actual previous-call POINT alias becomes the next observed X read`);
        assert.equal(shoreStack.snapshot().previousTreeY, row.shoreReads[0].previousTreeY);
      }
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
        assert.equal(row.phase, 'drawScene');
        scenes++;
        return render.drawScene(memory, dc, ...row.arguments.slice(1), options);
      });
      assert.deepEqual(sounds, row.expected.sounds ?? [], `case${index}: original ordered sounds`);
      assert.deepEqual(dc.events, row.expected.drawingCommands ?? [], `case${index}: original ordered GDI`);
      assert.equal(pixels, (row.expected.drawingCommands ?? []).filter(event => event.op === 'getPixel').length);
      assert.equal(shoreStack.snapshot().completedCalls, scenes);
    }
    assert.equal(scenes, 8);
  });
}
