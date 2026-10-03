import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { handleKeyDown } from '../src/engine/keyboard.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixture = JSON.parse(await readFile(new URL('./fixtures/original-keyboard.json', import.meta.url), 'utf8'));
const tables = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json', import.meta.url), 'utf8'));
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
const raw = bits => Uint8Array.from(Buffer.from(bits, 'hex'));

test('original keyboard references preserve source, host-stub scope and all 256 virtual keys', () => {
  assert.equal(fixture.provenance.sha256, hash(original));
  assert.equal(fixture.provenance.invalidateRectImport, '004b1bc4');
  assert.equal(fixture.provenance.defaultWindowRoutine, '00468021');
  const cases = fixture.routines.handleKeyDown.cases;
  assert.equal(cases.length, 1382);
  assert.equal(new Set(cases.map(row => row.arguments[0])).size, 256);
  assert.ok(cases.some(row => row.inputs.some(input => input.address === 0x491164 && input.value === 1)));
});

test('keyboard matches all 1382 original whole-state changes and ordered host requests', () => {
  const memory = loadPE32(original);
  for (const [address, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine]]) values.forEach((value, index) => memory.writeI32(address + index * 4, value));
  const { address, size } = fixture.mutableBlock;
  const baseline = memory.readBytes(address, size);
  const failures = [];
  for (const [index, row] of fixture.routines.handleKeyDown.cases.entries()) {
    memory.writeBytes(address, baseline);
    for (const input of row.imageInputs) memory.writeBytes(input.address, raw(input.bits));
    const before = memory.readBytes(address, size), expected = before.slice();
    for (const change of row.expected.imageChanges) {
      assert.equal(Buffer.from(before.slice(change.address - address, change.address - address + change.before.length / 2)).toString('hex'), change.before, `case ${index} captured input`);
      expected.set(raw(change.after), change.address - address);
    }
    assert.equal(hash(expected), row.expected.mutableBlockHash);
    const hostEvents = [];
    handleKeyDown(memory, row.arguments[0], { windowHandle: fixture.windowHandle,
      invalidateRect: event => { hostEvents.push({ op: 'invalidateRect', ...event }); return 1; },
      defaultKeyHandler: () => hostEvents.push({ op: 'defaultKeyHandler' }),
      repeatCount: row.arguments[1], flags: row.arguments[2] });
    const actual = memory.readBytes(address, size);
    const offset = actual.findIndex((value, at) => value !== expected[at]);
    if (offset >= 0) failures.push({ index, key: row.arguments[0], address: `0x${(address + offset).toString(16)}`,
      expected: Buffer.from(expected.slice(offset, offset + 16)).toString('hex'), actual: Buffer.from(actual.slice(offset, offset + 16)).toString('hex') });
    if (JSON.stringify(hostEvents) !== JSON.stringify(row.expected.hostEvents)) failures.push({ index, hostEvents, expected: row.expected.hostEvents });
  }
  assert.equal(failures.length, 0, `${failures.length} differences; first: ${JSON.stringify(failures.slice(0, 10))}`);
});
