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
import { handleMenuCommand, menuCommandState } from '../src/engine/menu-controller.js';
import { createOriginalRenderer } from '../src/render/index.js';
import { createShoreStack } from '../src/render/shore-stack.js';
import { drawSimulationFrame } from '../src/render/paint-lifecycle.js';
import { GdiTrace } from '../src/render/gdi.js';

const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const source = await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe', import.meta.url));
const fixtures = [await json('fixtures/original-retained-controller-start-frames.json'),
  await json('fixtures/original-retained-island-controller-shore-frames.json')];
const unobservedIsland = await json('fixtures/original-retained-island-controller-start-frames.json');
const trig = createCapturedTrig(await json('../assets/data/x87-trig.json'), await json('../assets/data/x87-stored-trig.json'));
const engine = createEngineBindings();

for (const fixture of fixtures) {
  const profile = fixture.profiles[0];
  test(`${profile.name}: original start prefix, real controller calls and explicit paint-caller stores`, () => {
    assertNativeProvenance(source, fixture);
    assert.equal(fixture.inputEvidence.constructorObjectCount, 90);
    assert.deepEqual(fixture.cases.slice(0, 1).map(row => row.routine.address), [0x41be70]);
    const start = fixture.cases.filter(row => row.phase.startsWith('start-'));
    assert.deepEqual(start.map(row => row.routine.address), [0x420c00, 0x41be70]);
    const frames = fixture.cases.filter(row => row.phase === 'frame');
    assert.equal(frames.length, profile.transition ? 10 : 25);
    for (const [index, row] of fixture.cases.entries()) if (index) {
      assert.equal(row.continue, true);
      assert.equal(row.seed, undefined, 'native RNG is never replaced between calls');
      assert.deepEqual(row.inputs ?? {}, {});
      assert.deepEqual(row.doubleInputs ?? {}, {});
      if (row.phase !== 'frame') assert.deepEqual(row.patches, []);
    }
    for (const [frame, row] of frames.entries()) {
      assert.deepEqual(row.patches.map(patch => patch.address), frame === 0 ? [0x5363b0, 0x5364e8] : [0x5364e8]);
      assert.equal(Buffer.from(row.patches.at(-1).bytes, 'hex').readInt32LE(), frame + 1);
      assert.equal(row.callerInput.routine, 0x404510);
      assert.equal(row.host.pixels.length, 1024);
      assert.ok(row.host.pixels.every(value => value === 0xffffff));
    }
    const kinds = new Set(fixture.cases.filter(row => row.kind).map(row => row.kind));
    assert.deepEqual([...kinds].sort(), [1, 2, 3]);
    for (const row of fixture.cases.filter(row => row.kind)) {
      assert.equal(row.expected.globalStrings.length, 36, 'actual original CString contents stay live through controllers');
      for (const binding of row.expected.runtimeBindings) assert.equal(binding.retained, binding.bound);
    }
    if (profile.transition) {
      assert.equal(fixture.provenance.shoreObserver.targetGameMemoryWrites, 0);
      assert.equal(fixture.provenance.shoreObserver.stackInputsSupplied, false);
      assert.equal(fixture.provenance.shoreObserver.consumedPairs, 20);
      assert.equal(fixture.cases.reduce((count, row) => count + row.shoreReads.length, 0), 20);
      for (const row of frames) for (const read of row.shoreReads) {
        assert.equal(read.first, 0); assert.equal(read.last, 36); assert.equal(read.camera, 1);
        assert.equal(read.controlWord, 0x027f);
      }
      assertNativeProvenance(source, unobservedIsland);
      assert.equal(fixture.cases.length, unobservedIsland.cases.length);
      for (const [index, row] of fixture.cases.entries()) {
        const original = unobservedIsland.cases[index];
        assert.deepEqual(row.patches, original.patches);
        for (const field of ['mutableSha256', 'imageChanges', 'rngState', 'integers', 'doubles', 'drawingCommands', 'sounds', 'events']) {
          assert.deepEqual(row.expected[field], original.expected[field],
            `case${index}: read-only hardware observation preserves original ${field}`);
        }
        // Actual allocator/window pointers belong to each owned oracle process.
        // Keep that raw evidence, and compare original semantic CString bytes.
        const text = value => value.globalStrings?.map(({ address, bytes }) => ({ address, bytes }));
        assert.deepEqual(text(row.expected), text(original.expected));
      }
    }
  });

  test(`${profile.name}: retained state, CString/RNG, sound, GDI and ordered UI callbacks are native exact`, () => {
    const harness = createNativeHarness(source, fixture);
    const firstShoreRead = fixture.cases.flatMap(row => row.shoreReads ?? [])[0];
    const shoreStack = firstShoreRead ? createShoreStack({ sourceSha256: fixture.sourceSha256,
      initialStack: { previousX: firstShoreRead.previousX, previousTreeY: firstShoreRead.previousTreeY } }) : undefined;
    const render = createOriginalRenderer({ ...(shoreStack ? { shoreStack } : {}) });
    let objects = new Map(), frames = 0, controllerCalls = 0;
    for (const [index, row] of fixture.cases.entries()) {
      const sounds = [], events = [];
      let ticks = 0, pixels = 0;
      const dc = new GdiTrace({ objects, readPixel() {
        if (pixels >= row.host.pixels.length) throw new RangeError('Original frame exceeded its declared pixel input budget');
        return row.host.pixels[pixels++];
      } });
      const context = `${profile.name}: case${index} ${row.label}`;
      if (row.shoreReads?.length) {
        assert.equal(shoreStack.snapshot().previousX, row.shoreReads[0].previousX, `${context}: actual first consumed X caller byte`);
        assert.equal(shoreStack.snapshot().previousTreeY, row.shoreReads[0].previousTreeY, `${context}: actual first consumed Y caller byte`);
      }
      try { harness.check(row, index, (memory, rng) => {
        const options = { engine, render, trig, rng, windowHandle: 0x20000001,
          invalidateRect: event => events.push({ type: 'invalidateRect', ...event }),
          defaultKeyHandler: ({ key, repeat, flags }) => {
            events.push({ type: 'default', message: 0x100, wparam: key >>> 0,
              lparam: ((repeat & 0xffff) | (flags << 16)) >>> 0, result: 1 });
            return 1;
          },
          playSound: event => { sounds.push(event); return 1; },
          messageBeep: type => { dc.emit({ op: 'messageBeep', type }); return 1; },
          ...(row.host ? { menuHeight: row.host.menuHeight,
            getCursorPos: () => ({ x: row.host.cursor[0], y: row.host.cursor[1] }),
            getTickCount: () => (row.host.tickStart + ticks++) >>> 0 } : {}),
        };
        if (row.phase === 'initialize') {
          objects = initializeGdiObjects(memory);
          assert.equal(objects.size, 90);
          return initializeRace(memory, rng, options);
        }
        if (row.phase === 'start-options') return initializeBoatOptions(memory);
        if (row.phase === 'start-initialize') return initializeRace(memory, rng, options);
        if (row.phase === 'frame') {
          assert.equal(memory.readI32(0x5363b0), 2, 'the original start prefix has entered the race');
          assert.equal(memory.readI32(0x53642c), 0, 'a frame is never forced while the original caller is frozen');
          frames++;
          return drawSimulationFrame(memory, dc, rng, options);
        }
        controllerCalls++;
        if (row.kind === 1) return handleKeyDown(memory, row.arguments[0], { ...options,
          repeat: row.arguments[1], flags: row.arguments[2] });
        if (row.kind === 2) { assert.equal(handleMenuCommand(memory, row.identifier, options), true); return; }
        if (row.kind === 3) { events.push(...menuCommandState(memory, row.identifier).events); return; }
        throw new Error('Unrecognized retained controller kind');
      }); } catch (error) { error.message = `${context}: ${error.message}`; throw error; }
      assert.deepEqual(events, row.expected.events ?? [], `${context}: ordered original UI callbacks`);
      assert.deepEqual(sounds, row.expected.sounds ?? [], `${context}: ordered original sound requests`);
      const drawing = row.expected.drawingCommands ?? [];
      assert.equal(dc.events.length, drawing.length, `${context}: drawing request count`);
      for (let event = 0; event < drawing.length; event++) assert.deepEqual(dc.events[event], drawing[event], `${context}: drawing request${event}`);
      assert.equal(pixels, drawing.filter(event => event.op === 'getPixel').length, `${context}: consumed pixel sequence`);
      if (row.phase === 'start-initialize' && profile.transition) {
        assert.equal(row.expected.integers.course, 7, 'the actual original course is Round the Island');
        assert.equal(row.expected.integers.boatClass, 6, 'actual physical boat class at4da190');
        assert.equal(row.expected.integers.configurationControl4da188, 3, 'original configuration control at4da188');
        assert.equal(row.expected.integers.island, 1);
        assert.equal(row.expected.integers.shorelineVariant, 0);
      }
    }
    assert.equal(frames, profile.transition ? 10 : 25);
    assert.equal(controllerCalls, profile.transition ? 8 : 14);
  });
}
