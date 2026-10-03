import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { Float80 } from '../src/runtime/float80.js';
import { atan2Extended } from '../src/runtime/atan.js';
import { sinCosX87 } from '../src/runtime/transcendentals.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { loadPE32 } from '../src/runtime/index.js';

const document = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const [extended, stored, force, atan, continuous, original] = await Promise.all([
  document('../assets/data/x87-trig.json'), document('../assets/data/x87-stored-trig.json'),
  document('../assets/data/x87-force-trig.json'), document('./fixtures/native-atan.json'), document('./fixtures/native-continuous-trig.json'),
  readFile(new URL('../original/Tact02Demo.exe', import.meta.url)),
]);
const from = bits => Float80.fromBytes(Buffer.from(bits, 'hex'));
const doubleBits = value => { const bytes = Buffer.alloc(8); bytes.writeDoubleLE(value); return bytes.toString('hex'); };

test('new native datasets identify unchanged probe sources and original constants', async () => {
  for (const capture of [stored, force, atan, continuous]) {
    const source = await readFile(new URL('../' + capture.provenance.probe_source, import.meta.url));
    assert.equal(createHash('sha256').update(source).digest('hex'), capture.provenance.probe_sha256);
    assert.equal(capture.provenance.control_word, '0x037f');
  }
  const memory = loadPE32(original);
  const hash = createHash('sha256').update(original).digest('hex');
  for (const capture of [stored, force]) {
    assert.equal(capture.provenance.sha256, hash);
    assert.equal(Buffer.from(memory.readBytes(capture.degreeFactorAddress, 8)).toString('hex'), capture.degreeFactorBits);
  }
});

test('66-bit-pi reduction matches all captured continuous binary64 sin/cos stores', () => {
  let extendedDifferences=0;
  for(const [index,row] of continuous.cases.entries()) {
    const pair=sinCosX87(from(row.inputBits));
    for(const name of ['sine','cosine']) {
      const result=pair[name], native=from(row.expected[name+'Bits']);
      assert.equal(doubleBits(result.toNumber()),row.expected[name+'DoubleBits'],`native ${name} ${index} binary64 store`);
      assert.equal(result.sign,native.sign,`native ${name} ${index} sign`);
      const exponent=Math.min(result.exponent,native.exponent);
      const difference=(result.mantissa<<BigInt(result.exponent-exponent))-(native.mantissa<<BigInt(native.exponent-exponent));
      assert.ok(difference>=-1n&&difference<=1n,`native ${name} ${index} extended accuracy`);
      if(difference!==0n)extendedDifferences++;
    }
  }
  assert.equal(extendedDifferences,49,'vendor final-bit differences remain explicit');
});

test('stored angle captures preserve the separate binary64 spill path', () => {
  const reference = createCapturedTrig(extended, stored, force);
  let differences = 0;
  for (let angle = -1080; angle <= 1080; angle++) {
    const pair = reference.stored(angle);
    assert.equal(Buffer.from(pair.sine.toBytes()).toString('hex'), stored.angles[angle].sineBits);
    assert.equal(Buffer.from(pair.cosine.toBytes()).toString('hex'), stored.angles[angle].cosineBits);
    if (stored.angles[angle].sineBits !== extended.angles[angle].sineBits) differences++;
  }
  assert.ok(differences > 1500, 'binary64 angle spill materially changes native extended results');
});

test('mathematical atan agrees with every captured binary64 FPATAN store', () => {
  let extendedDifferences = 0;
  for (const [index, row] of atan.cases.entries()) {
    const result = atan2Extended(from(row.yBits), from(row.xBits));
    assert.equal(doubleBits(result.toNumber()), row.expected.storedDoubleBits, `native FPATAN ${index} stored result`);
    const native = from(row.expected.extendedBits);
    assert.equal(result.sign, native.sign, `native FPATAN ${index} sign`);
    const exponent = Math.min(result.exponent, native.exponent);
    const difference = (result.mantissa << BigInt(result.exponent - exponent)) - (native.mantissa << BigInt(native.exponent - exponent));
    // This is an accuracy check, explicitly not extended instruction parity.
    assert.ok(difference >= -1n && difference <= 1n, `native FPATAN ${index} extended accuracy`);
    if (difference !== 0n) extendedDifferences++;
  }
  assert.equal(extendedDifferences, 14, 'retain visible evidence of vendor FPATAN final-bit differences');
});
