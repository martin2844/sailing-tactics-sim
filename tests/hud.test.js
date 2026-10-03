import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { assertNativeAuthority } from './native-authority.js';
import { loadPE32 } from '../src/runtime/index.js';
import { GdiTrace } from '../src/render/gdi.js';
import { drawPlayer1Controls, drawPlayer2Controls, drawSteeringPanel, drawSecondPlayerControls, drawTacticalPanel, drawCompactHud, drawSailingHud, getHudText } from '../src/render/hud.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixture = JSON.parse(await readFile(new URL('./fixtures/original-hud.json', import.meta.url), 'utf8'));
const tables = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json', import.meta.url), 'utf8'));
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
const bytes = bits => Uint8Array.from(Buffer.from(bits, 'hex'));
const initial = loadPE32(original);
for (const [address, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine]]) values.forEach((value, index) => initial.writeI32(address + index * 4, value));
const { address, size } = fixture.mutableBlock;
const baseline = initial.readBytes(address, size);

test('HUD original evidence declares its host-pointer normalization explicitly', () => {
  assert.equal(fixture.provenance.sha256, hash(original));
  assert.deepEqual(fixture.provenance.normalizations.map(row => [row.address, row.size]), [[0x4a7048, 4]]);
});

test('all HUD fixture bytes have strict unchanged-original native authority', async () => {
  await assertNativeAuthority('original-hud.json', 'hud-native-reference-comparison.json', fixture);
});

for (const [name, implementation] of Object.entries({ drawPlayer1Controls, drawPlayer2Controls, drawSteeringPanel, drawSecondPlayerControls, drawTacticalPanel, drawCompactHud, drawSailingHud })) test(`${name}: all original mutable fields, text, clipping and ordered GDI requests`, () => {
  const failures = [];
  for (const [index, row] of fixture.routines[name].cases.entries()) {
    const memory = loadPE32(original);
    memory.writeBytes(address, baseline);
    for (const input of row.imageInputs) memory.writeBytes(input.address, bytes(input.bits));
    const before = memory.readBytes(address, size), expected = before.slice();
    for (const change of row.expected.imageChanges) {
      assert.equal(Buffer.from(before.slice(change.address - address, change.address - address + change.before.length / 2)).toString('hex'), change.before);
      expected.set(bytes(change.after), change.address - address);
    }
    assert.equal(hash(expected), row.expected.mutableBlockHash);
    const dc = new GdiTrace();
    implementation(memory, dc, ...row.arguments, { messageBeep: type => dc.emit({ op: 'messageBeep', type }) });
    const actual = memory.readBytes(address, size), offset = actual.findIndex((value, at) => value !== expected[at]);
    if (offset >= 0) failures.push({ index, address: `0x${(address + offset).toString(16)}`, actual: Buffer.from(actual.slice(offset, offset + 16)).toString('hex'), expected: Buffer.from(expected.slice(offset, offset + 16)).toString('hex') });
    if (JSON.stringify(dc.events) !== JSON.stringify(row.expected.drawingCommands)) {
      const event = dc.events.findIndex((value, at) => JSON.stringify(value) !== JSON.stringify(row.expected.drawingCommands[at]));
      failures.push({ index, event, actualEvent: dc.events[event], expectedEvent: row.expected.drawingCommands[event] });
    }
    if ('hudText' in row.expected && getHudText(memory) !== row.expected.hudText) failures.push({ index, actualText: getHudText(memory), expectedText: row.expected.hudText });
  }
  assert.equal(failures.length, 0, `${failures.length} differences; first ${JSON.stringify(failures.slice(0, 8))}`);
});
