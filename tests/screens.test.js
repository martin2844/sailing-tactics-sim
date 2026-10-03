import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { GdiTrace } from '../src/render/gdi.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createHullTrig } from '../src/engine/hull-geometry.js';
import * as screens from '../src/render/screens.js';
import { assertNativeAuthority } from './native-authority.js';

const readJson = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const [fixture, tables, trigCapture, hullCapture] = await Promise.all([
  readJson('./fixtures/original-screens.json'), readJson('../assets/data/trig-tables.json'),
  readJson('../assets/data/x87-trig.json'), readJson('../assets/data/x87-hull-trig.json'),
]);
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
const bytes = bits => Uint8Array.from(Buffer.from(bits, 'hex'));
const initial = loadPE32(original);
for (const [address, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine]]) values.forEach((value, index) => initial.writeI32(address + index * 4, value));
const { address, size } = fixture.mutableBlock, baseline = initial.readBytes(address, size);
const trig = createCapturedTrig(trigCapture), hullTrig = createHullTrig(hullCapture);

test('all screen reference bytes have strict unchanged-original native authority', async () => {
  await assertNativeAuthority('original-screens.json', 'screens-native-reference-comparison.json', fixture);
});

test('screen fixtures identify unchanged original code and owned Windows inputs', () => {
  assert.equal(fixture.provenance.sha256, hash(original));
  assert.equal(fixture.provenance.x87_control_word, '0x037f');
  assert.match(fixture.provenance.note, /GetTickCount/);
  assert.match(fixture.provenance.note, /GetSystemMetrics/);
});

for (const [name, implementation] of Object.entries(screens)) {
  const group = fixture.routines[name]; if (!group) continue;
  test(`${name}: original text, ordered drawing, complete state and RNG (${group.cases.length} calls)`, () => {
    const failures = [];
    for (const [index, row] of group.cases.entries()) {
      const memory = loadPE32(original); memory.writeBytes(address, baseline);
      for (const input of row.imageInputs) memory.writeBytes(input.address, bytes(input.bits));
      const before = memory.readBytes(address, size), expected = before.slice();
      for (const change of row.expected.imageChanges) {
        assert.equal(Buffer.from(before.slice(change.address - address, change.address - address + change.before.length / 2)).toString('hex'), change.before);
        expected.set(bytes(change.after), change.address - address);
      }
      assert.equal(hash(expected), row.expected.mutableBlockHash);
      const dc = new GdiTrace(), rng = new PoseyRng(row.seedAtCall); let delay = 0;
      const options = { trig, hullTrig, menuHeight: row.menuHeight, enforceMinimumPaintDuration: value => { delay = value; } };
      try {
        if (['drawStartScreen', 'drawResultsScreen', 'drawForecastScreen'].includes(name)) implementation(memory, dc, rng, options);
        else implementation(memory, dc, ...row.arguments);
      } catch (error) { failures.push({ index, error: error.message }); continue; }
      const actual = memory.readBytes(address, size), offset = actual.findIndex((value, at) => value !== expected[at]);
      if (offset >= 0) failures.push({ index, address: `0x${(address + offset).toString(16)}`, actual: Buffer.from(actual.slice(offset, offset + 16)).toString('hex'), expected: Buffer.from(expected.slice(offset, offset + 16)).toString('hex') });
      if (JSON.stringify(dc.events) !== JSON.stringify(row.expected.drawingCommands)) {
        const event = dc.events.findIndex((value, at) => JSON.stringify(value) !== JSON.stringify(row.expected.drawingCommands[at]));
        failures.push({ index, event, actualEvent: dc.events[event], expectedEvent: row.expected.drawingCommands[event] });
      }
      if (rng.state !== row.expected.rngState) failures.push({ index, actualRng: rng.state, expectedRng: row.expected.rngState });
      if (name === 'drawStartScreen' && delay !== row.expected.elapsedPaintTicks) failures.push({ index, delay, expectedDelay: row.expected.elapsedPaintTicks });
    }
    assert.equal(failures.length, 0, `${failures.length} differences; first ${JSON.stringify(failures.slice(0, 8))}`);
  });
}
