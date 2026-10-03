import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { GdiTrace } from '../src/render/gdi.js';
import { paintLifecycle, drawSimulationFrame } from '../src/render/paint-lifecycle.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixture = JSON.parse(await readFile(new URL('./fixtures/original-paint-lifecycle.json', import.meta.url), 'utf8'));
const tables = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json', import.meta.url), 'utf8'));
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
const raw = bits => Uint8Array.from(Buffer.from(bits, 'hex'));
const initial = loadPE32(original);
for (const [address, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine]]) values.forEach((value, index) => initial.writeI32(address + index * 4, value));
const { address, size } = fixture.mutableBlock;
const baseline = initial.readBytes(address, size);

test('paint caller evidence declares independent child and host bindings', () => {
  assert.equal(fixture.provenance.sha256, hash(original));
  assert.match(fixture.provenance.scope, /Explicit child routines/);
  assert.equal(fixture.routines.paintLifecycle.cases.length, 225);
  assert.equal(fixture.routines.drawSimulationFrame.cases.length, 144);
});

for (const [name, implementation] of Object.entries({ paintLifecycle, drawSimulationFrame })) test(`${name}: original screen branches, layout, state, host request order and delay`, () => {
  const failures = [];
  for (const [index, row] of fixture.routines[name].cases.entries()) {
    const memory = loadPE32(original); memory.writeBytes(address, baseline);
    for (const input of row.imageInputs) memory.writeBytes(input.address, raw(input.bits));
    const before = memory.readBytes(address, size), expected = before.slice();
    for (const change of row.expected.imageChanges) expected.set(raw(change.after), change.address - address);
    assert.equal(hash(expected), row.expected.mutableBlockHash);
    const calls = [], dc = new GdiTrace(), buffer = new GdiTrace();
    const emit = (name, args) => calls.push(args === undefined ? { name } : { name, arguments: args });
    const options = { windowHandle: row.windowHandle, advanceFrame: () => {} };
    for (const child of ['drawStartScreen', 'drawResultsScreen', 'drawPauseScreen', 'drawForecastScreen', 'drawSimulationFrame']) options[child] = () => emit(child, []);
    for (const child of ['initializeBoatOptions', 'initializeRace']) options[child] = () => emit(child, []);
    for (const child of ['drawChart', 'drawCircle', 'drawScene', 'drawSailingHud', 'drawCompactHud', 'drawAdvice']) options[child] = (_memory, _dc, ...args) => emit(child, args.slice(0, -1));
    // Circle has no trailing renderer-options argument in the original wrapper.
    options.drawCircle = (_memory, _dc, ...args) => emit('drawCircle', args);
    options.host = {
      constructBufferedDC: () => { emit('constructBufferedDC'); return buffer; },
      getDeviceCaps: (_dc, index) => { emit('getDeviceCaps', [index]); return row.caps[index]; },
      applicationInstance: () => { emit('applicationInstance'); return row.applicationInstance; },
      createBitmap: ({ width, height, planes, bitsPixel }) => { emit('createBitmap', [width, height, planes, bitsPixel, 0]); return 0x41; },
      attachBitmap: () => emit('attachBitmap'), createCompatibleDC: () => { emit('createCompatibleDC'); return 2; },
      attachCompatibleDC: () => emit('attachCompatibleDC'), selectBitmap: (_dc, handle) => { emit('selectBitmap', [handle]); return 0x42; },
      bitBlt: (_front, _buffer, event) => emit('bitBlt', [event.x, event.y, event.width, event.height, event.sourceX, event.sourceY, event.rasterOperation]),
      deleteBitmap: () => emit('deleteBitmap'), invalidateRect: ({ windowHandle, rectangle, erase }) => emit('invalidateRect', [windowHandle, [rectangle.left, rectangle.top, rectangle.right, rectangle.bottom], erase]),
      destroyBufferedDC: () => emit('destroyBufferedDC'),
    };
    const duration = implementation(memory, dc, null, options);
    if (name === 'drawSimulationFrame') assert.equal(duration, row.expected.elapsedPaintTicks, `original tick boundary case ${index}`);
    const actual = memory.readBytes(address, size), offset = actual.findIndex((value, index) => value !== expected[index]);
    if (offset >= 0) failures.push({ index, address: `0x${(address + offset).toString(16)}`, actual: Array.from(actual.slice(offset, offset + 8)), expected: Array.from(expected.slice(offset, offset + 8)) });
    if (JSON.stringify(calls) !== JSON.stringify(row.expected.calls)) failures.push({ index, calls, expectedCalls: row.expected.calls });
    if (JSON.stringify(dc.events) !== JSON.stringify(row.expected.drawingCommands)) failures.push({ index, drawingCommands: dc.events, expectedCommands: row.expected.drawingCommands });
  }
  assert.equal(failures.length, 0, `${failures.length} differences; first ${JSON.stringify(failures.slice(0, 3))}`);
});
