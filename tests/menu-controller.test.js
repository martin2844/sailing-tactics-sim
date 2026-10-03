import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { handleMenuCommand, menuCommandState, MENU_COMMAND_ROUTINES, MENU_UPDATE_ROUTINES } from '../src/engine/menu-controller.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixture = JSON.parse(await readFile(new URL('./fixtures/original-menu-controller.json', import.meta.url), 'utf8'));
const tables = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json', import.meta.url), 'utf8'));
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
const raw = bits => Uint8Array.from(Buffer.from(bits, 'hex'));
const memory = loadPE32(original);
for (const [address, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine]]) values.forEach((value, index) => memory.writeI32(address + index * 4, value));
const { address, size } = fixture.mutableBlock;
const baseline = memory.readBytes(address, size);

test('menu references cover the full recovered menu map and preserve the original source', () => {
  assert.equal(fixture.provenance.sha256, hash(original));
  assert.equal(Object.keys(MENU_COMMAND_ROUTINES).length, 192);
  assert.equal(Object.keys(MENU_UPDATE_ROUTINES).length, 190);
  assert.equal(Object.values(fixture.routines).filter(row => row.kind === 'command').length, 187);
  assert.equal(Object.values(fixture.routines).filter(row => row.kind === 'update').length, 190);
});

for (const kind of ['command', 'update']) test(`all original menu ${kind} handlers preserve exact state and ordered host requests`, () => {
  const failures = [];
  for (const [name, routine] of Object.entries(fixture.routines)) {
    if (routine.kind !== kind) continue;
    for (const [index, row] of routine.cases.entries()) {
      memory.writeBytes(address, baseline);
      for (const input of row.imageInputs) memory.writeBytes(input.address, raw(input.bits));
      const before = memory.readBytes(address, size), expected = before.slice();
      for (const change of row.expected.imageChanges) {
        assert.equal(Buffer.from(before.slice(change.address - address, change.address - address + change.before.length / 2)).toString('hex'), change.before);
        expected.set(raw(change.after), change.address - address);
      }
      assert.equal(hash(expected), row.expected.mutableBlockHash);
      const hostEvents = [];
      if (kind === 'command') assert.equal(handleMenuCommand(memory, routine.commandId, {
        windowHandle: fixture.windowHandle, invalidateRect: event => hostEvents.push({ op: 'invalidateRect', ...event }),
      }), true);
      else hostEvents.push(...menuCommandState(memory, routine.commandId).events);
      const actual = memory.readBytes(address, size);
      const offset = actual.findIndex((value, at) => value !== expected[at]);
      if (offset >= 0) failures.push({ name, index, address: `0x${(address + offset).toString(16)}`,
        expected: Buffer.from(expected.slice(offset, offset + 16)).toString('hex'), actual: Buffer.from(actual.slice(offset, offset + 16)).toString('hex') });
      if (JSON.stringify(hostEvents) !== JSON.stringify(row.expected.hostEvents)) failures.push({ name, index, hostEvents, expected: row.expected.hostEvents });
    }
  }
  assert.equal(failures.length, 0, `${failures.length} differences; first: ${JSON.stringify(failures.slice(0, 10))}`);
});

test('modal menu operations expose the original resource ID and preserve state ordering', () => {
  memory.writeBytes(address, baseline);
  assert.throws(() => handleMenuCommand(memory, 32823), /modal dialog host/);
  const events = [];
  assert.equal(handleMenuCommand(memory, 32779, { windowHandle: fixture.windowHandle,
    dialogHandler: event => events.push({ op: 'dialog', ...event }),
    invalidateRect: event => events.push({ op: 'invalidateRect', humans: memory.readI32(0x491140), ...event }),
  }), true);
  assert.deepEqual(events, [
    { op: 'dialog', resourceId: 131, originalAddress: 0x450db0 },
    { op: 'invalidateRect', humans: 1, windowHandle: fixture.windowHandle, rectangle: null, erase: 0 },
  ]);
  assert.equal(memory.readI32(0x491140), 2);
  assert.equal(handleMenuCommand(memory, -1), false);
});

test('asynchronous browser dialogs defer the original tail until modal completion', async () => {
  for (const command of [57664, 32823, 32779]) {
    memory.writeBytes(address, baseline); memory.writeI32(0x4ac8fc, 1);
    const events = []; let close;
    const result = handleMenuCommand(memory, command, {
      dialogHandler: event => { events.push({ op: 'dialog', ...event }); return new Promise(resolve => { close = resolve; }); },
      invalidateRect: event => events.push({ op: 'invalidateRect', humans: memory.readI32(0x491140), ...event }),
    });
    assert.ok(result instanceof Promise);
    assert.equal(memory.readI32(0x4ac8fc), 1); assert.equal(memory.readI32(0x491140), 1); assert.equal(events.length, 1);
    close(); assert.equal(await result, true);
    if (command !== 57664) { assert.equal(memory.readI32(0x4ac8fc), 0); assert.equal(events[1].humans, 1); }
    assert.equal(memory.readI32(0x491140), command === 32779 ? 2 : 1);
  }
});
