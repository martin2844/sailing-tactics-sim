import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { assertNativeAuthority } from './native-authority.js';
import { loadPE32 } from '../src/runtime/index.js';
import { updateDisplayedLeg, displayedTargetMark, signedDegreesOnce, formatInteger, formatDecimal } from '../src/engine/hud-state.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixture = JSON.parse(await readFile(new URL('./fixtures/original-hud-state.json', import.meta.url), 'utf8'));
const tables = JSON.parse(await readFile(new URL('../assets/data/trig-tables.json', import.meta.url), 'utf8'));
const memory = loadPE32(original);
for (const [address, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine]]) values.forEach((value, index) => memory.writeI32(address + index * 4, value));
const { address, size } = fixture.mutableBlock;
const baseline = memory.readBytes(address, size);
const raw = bits => Uint8Array.from(Buffer.from(bits, 'hex'));
const hash = bytes => createHash('sha256').update(bytes).digest('hex');

test('HUD helper references retain source, signed boundaries and original text quirks', () => {
  assert.equal(fixture.provenance.sha256, hash(original));
  assert.ok(fixture.signedDegrees.some(row => row.input === -2147483648));
  assert.ok(fixture.decimalFormatting.some(row => row.expected === '-1.-1'));
  assert.ok(fixture.decimalFormatting.some(row => row.input === -0.9 && row.expected === '0.-9'));
});

test('signed angle and integer text match all unchanged original helper calls', () => {
  for (const row of fixture.signedDegrees) assert.equal(signedDegreesOnce(row.input), row.expected, String(row.input));
  for (const row of fixture.integerFormatting) assert.equal(formatInteger(row.input), row.expected, String(row.input));
});

test('decimal text preserves binary64 input and unspilled x87 decimal truncation', () => {
  for (const row of fixture.decimalFormatting) {
    const value = Buffer.from(row.inputBits, 'hex').readDoubleLE();
    assert.equal(formatDecimal(memory, value), row.expected, row.inputBits);
  }
});

test('all HUD progress and numeric text fixture bytes have strict original native authority', async () => {
  await assertNativeAuthority('original-hud-state.json', 'hud-state-native-reference-comparison.json', fixture);
  const report = JSON.parse(await readFile(new URL('../analysis/hud-state-native-reference-comparison.json', import.meta.url), 'utf8'));
  for (const name of ['signedDegrees', 'integerFormatting', 'decimalFormatting']) {
    assert.equal(report.groups[name].cases, fixture[name].length);
    assert.equal(report.groups[name].exact_matches, fixture[name].length);
    assert.equal(report.groups[name].different_cases, 0);
  }
});

for (const [name, implementation] of Object.entries({ updateDisplayedLeg, displayedTargetMark })) test(`${name} matches all original complete mutable-state records`, () => {
  const failures = [];
  for (const [index, row] of fixture.routines[name].cases.entries()) {
    memory.writeBytes(address, baseline);
    for (const input of row.imageInputs) memory.writeBytes(input.address, raw(input.bits));
    const before = memory.readBytes(address, size), expected = before.slice();
    for (const change of row.expected.imageChanges) {
      assert.equal(Buffer.from(before.slice(change.address - address, change.address - address + change.before.length / 2)).toString('hex'), change.before);
      expected.set(raw(change.after), change.address - address);
    }
    assert.equal(hash(expected), row.expected.mutableBlockHash);
    const result = implementation(memory, ...row.arguments);
    if ('residualEAX' in row.expected && result !== row.expected.residualEAX) failures.push({ index, result, expectedReturn: row.expected.residualEAX });
    const actual = memory.readBytes(address, size), offset = actual.findIndex((value, at) => value !== expected[at]);
    if (offset >= 0) failures.push({ index, address: `0x${(address + offset).toString(16)}`,
      actual: Buffer.from(actual.slice(offset, offset + 16)).toString('hex'), expected: Buffer.from(expected.slice(offset, offset + 16)).toString('hex') });
  }
  assert.equal(failures.length, 0, JSON.stringify(failures.slice(0, 10)));
});
