import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { wrapRadiansOnce, bearingFromVector } from '../src/engine/angles.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-angles.json', import.meta.url), 'utf8'));

test('angle fixtures identify the original binary, x87 mode, and boundary inputs', () => {
  assert.equal(fixtures.provenance.sha256, createHash('sha256').update(original).digest('hex'));
  assert.equal(fixtures.provenance.engine, 'Unicorn');
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  const bitPatterns = new Set(fixtures.wrapRadiansOnce.map(fixture => fixture.inputBits));
  assert.ok(bitPatterns.has('0000000000000000'), 'positive zero');
  assert.ok(bitPatterns.has('0000000000000080'), 'negative zero');
  assert.ok(fixtures.wrapRadiansOnce.length >= 528);
  assert.ok(fixtures.bearingFromVector.length >= 4145);
});

test('all radian outputs match the exact binary64 return bits of original instructions', () => {
  for (const [index, fixture] of fixtures.wrapRadiansOnce.entries()) {
    // JSON numbers cannot retain every signed-zero representation: decode bits.
    const input = Buffer.from(fixture.inputBits, 'hex').readDoubleLE();
    const bits = Buffer.alloc(8);
    bits.writeDoubleLE(wrapRadiansOnce(input));
    assert.equal(bits.toString('hex'), fixture.bits,
      `radian native case ${index}, input bits ${fixture.inputBits}`);
  }
});

test('all signed integer vector bearings match execution of original FPATAN instructions', () => {
  for (const [index, { param1, param2, expected }] of fixtures.bearingFromVector.entries()) {
    assert.equal(bearingFromVector(param1, param2), expected,
      `bearing native case ${index}, vector (${param1}, ${param2})`);
  }
});
