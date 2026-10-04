import assert from 'node:assert/strict';
// Read-only runtime verification and microbenchmark; never part of the browser
// graph. Run from any directory with Node and an x86 C compiler installed:
// node versions/2010-en/tools/diagnostics/verify-float80-performance.mjs
import { readFileSync, writeFileSync, mkdtempSync, rmSync } from 'node:fs';
import { createHash } from 'node:crypto';
import { spawnSync } from 'node:child_process';
import { performance } from 'node:perf_hooks';
import { tmpdir } from 'node:os';
import { join } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import * as current from '../../../../src/runtime/float80.js';

const root = fileURLToPath(new URL('../../../../', import.meta.url));
const baselineCommit = 'fb856db76104e87ce63294aa9f7f71f2f5658b18';
const baseline = spawnSync('git', ['show', `${baselineCommit}:src/runtime/float80.js`], {cwd:root,encoding:'utf8'});
assert.equal(baseline.status, 0, `Baseline commit must exist in Git history: ${baseline.stderr}`);
const temporary = mkdtempSync(join(tmpdir(), 'tact-float80-proof-'));
const reference = join(temporary, 'reference.mjs');
writeFileSync(reference, baseline.stdout);
const original = await import(pathToFileURL(reference));
try {

const hex = value => Buffer.from(value.toBytes()).toString('hex');
const bits = number => { const result = Buffer.alloc(8); result.writeDoubleLE(number); return result.toString('hex'); };
let seed = 0x740e8e41;
const random = () => { seed ^= seed << 13; seed ^= seed >>> 17; seed ^= seed << 5; return seed >>> 0; };
const randomNumber = () => {
  const bytes = Buffer.alloc(8);
  bytes.writeUInt32LE(random(), 0);
  bytes.writeUInt32LE(((random() & 0x800fffff) | ((random() % 2047) << 20)) >>> 0, 4);
  return bytes.readDoubleLE();
};
let arithmeticChecks = 0, loadChecks = 0, conversionChecks = 0;
const cases = [];
const boundary = [0, -0, Number.MIN_VALUE, -Number.MIN_VALUE, 2 ** -1022, -(2 ** -1022), 1, -1, 1 + 2 ** -52,
  2 ** -52, 2 ** -53, 2 ** -54, 2 ** 53, -(2 ** 63), 2 ** 63, Number.MAX_VALUE, -Number.MAX_VALUE];
for (const left of boundary) for (const right of boundary) cases.push([left, right]);
for (let index = 0; index < 4000; index++) cases.push([randomNumber(), randomNumber()]);
for (const [left, right] of cases) {
  const a = current.Float80.fromNumber(left), b = original.Float80.fromNumber(left);
  assert.equal(hex(a), hex(b));
  assert.equal(a.mantissa, b.mantissa); assert.equal(a.exponent, b.exponent);
  assert.equal(bits(a.toNumber()), bits(b.toNumber())); loadChecks++;
  if (left >= -(2 ** 63) && left < 2 ** 63) {
    assert.equal(a.truncI64(), b.truncI64()); assert.equal(a.truncI32(), b.truncI32()); conversionChecks += 2;
  }
  for (const word of [0x007f, 0x027f, 0x037f]) {
    current.setX87ControlWord(word); original.setX87ControlWord(word);
    for (const operation of ['add', 'subtract', 'multiply', 'divide', 'sqrt']) {
      if (operation === 'divide' && right === 0 || operation === 'sqrt' && left < 0) continue;
      const actual = operation === 'sqrt' ? a.sqrt() : a[operation](current.Float80.fromNumber(right));
      const expected = operation === 'sqrt' ? b.sqrt() : b[operation](original.Float80.fromNumber(right));
      assert.equal(hex(actual), hex(expected), `${word}/${operation}/${bits(left)}/${bits(right)}`);
      assert.equal(bits(actual.toNumber()), bits(expected.toNumber())); arithmeticChecks++;
    }
  }
}
let extendedChecks = 0;
for (let index = 0; index < 2000; index++) {
  const exponent = random() % 32000 - 16445;
  const mantissa = (BigInt(random()) << 32n) | BigInt(random());
  const sign = random() & 1 ? 1 : -1;
  const left = new current.Float80(sign, mantissa, exponent), reference = new original.Float80(sign, mantissa, exponent);
  assert.equal(hex(left), hex(reference)); assert.equal(bits(left.toNumber()), bits(reference.toNumber()));
  for (const word of [0x007f, 0x027f, 0x037f]) {
    current.setX87ControlWord(word); original.setX87ControlWord(word);
    for (const operation of ['add', 'subtract', 'multiply', 'divide']) {
      const actual = left[operation](current.Float80.fromInteger(3));
      const expected = reference[operation](original.Float80.fromInteger(3));
      assert.equal(hex(actual), hex(expected)); assert.equal(bits(actual.toNumber()), bits(expected.toNumber())); extendedChecks++;
    }
  }
}

// Independently verify all native PC53 operations, including binary64 overflow
// and nonzero values whose stores round to zero. FLDT inputs are the exact same
// numeric values loaded by FLDL; the supplied probe executes x87 instructions.
const source = join(root, 'tools/capture_precision_native.c');
const binary = join(temporary, 'native-x87');
const compile = spawnSync('cc', ['-O2', source, '-o', binary], {encoding:'utf8'});
assert.equal(compile.status, 0, compile.stderr);
current.setX87ControlWord(0x027f);
const nativeCases = [];
for (const [left, right] of cases.slice(0, 2000)) {
  for (const operation of ['add', 'subtract', 'multiply', 'divide', 'sqrt']) {
    if (operation === 'divide' && right === 0 || operation === 'sqrt' && left < 0) continue;
    nativeCases.push({operation,left,right});
  }
}
const nativeInput = nativeCases.map(({operation,left,right}) => `027f ${operation} ${hex(current.Float80.fromNumber(left))} ${hex(current.Float80.fromNumber(right))}`).join('\n') + '\n';
const probe = spawnSync(binary, [], {encoding:'utf8',input:nativeInput,maxBuffer:8*1024*1024});
assert.equal(probe.status, 0, probe.stderr);
const rows = probe.stdout.trim().split('\n'); assert.equal(rows.length, nativeCases.length);
for (let index = 0; index < rows.length; index++) {
  const {operation,left,right} = nativeCases[index];
  const a = current.Float80.fromNumber(left), b = current.Float80.fromNumber(right);
  const value = operation === 'sqrt' ? a.sqrt() : a[operation](b);
  const [native80, native64] = rows[index].split(' ');
  assert.equal(hex(value), native80, `native ${index}/${operation}`);
  assert.equal(bits(value.toNumber()), native64, `native store ${index}/${operation}`);
}

function runBenchmark(module, rounds, period) {
  module.setX87ControlWord(0x027f);
  const samples = [];
  for (let pass = 0; pass < 5; pass++) {
    const start = performance.now(); let checksum = 0;
    for (let index = 0; index < rounds; index++) {
      const value = module.Float80.fromNumber((period ? index % period : index) + .25).multiply(module.Float80.fromNumber(.17))
        .add(module.Float80.fromInteger(3)).divide(module.Float80.fromInteger(7)).subtract(module.Float80.fromNumber(.01));
      checksum += value.toNumber(); checksum += value.truncI32();
    }
    samples.push(performance.now() - start); assert.ok(Number.isFinite(checksum));
  }
  return samples.sort((a,b)=>a-b)[2];
}
function runSqrtBenchmark(module, rounds) {
  module.setX87ControlWord(0x027f);
  const samples = [];
  for (let pass = 0; pass < 5; pass++) {
    const start = performance.now(); let checksum = 0;
    for (let index = 0; index < rounds; index++) checksum += module.Float80.fromNumber(index + .25).sqrt().toNumber();
    samples.push(performance.now() - start); assert.ok(Number.isFinite(checksum));
  }
  return samples.sort((a,b)=>a-b)[2];
}
const rounds = 50000;
const oldMs = runBenchmark(original, rounds), newMs = runBenchmark(current, rounds);
const oldRepeatedMs = runBenchmark(original, rounds, 512), newRepeatedMs = runBenchmark(current, rounds, 512);
const oldSqrtMs = runSqrtBenchmark(original, rounds), newSqrtMs = runSqrtBenchmark(current, rounds);
current.setX87ControlWord(0x037f); original.setX87ControlWord(0x037f);
const report = {
  kind:'Exact Float80 PC53 acceleration verification',
  sourceHash:createHash('sha256').update(readFileSync(join(root, 'src/runtime/float80.js'))).digest('hex'),
  baselineCommit,
  baselineSourceHash:createHash('sha256').update(baseline.stdout).digest('hex'),
  probeSource:'tools/capture_precision_native.c',
  probeSha256:createHash('sha256').update(readFileSync(source)).digest('hex'),
  differential:{loads:loadChecks,integerConversions:conversionChecks,arithmeticAcrossThreeControlWords:arithmeticChecks,extendedOperandArithmetic:extendedChecks,failures:0},
  nativeX87:{controlWord:'0x027f',cases:nativeCases.length,m80AndBinary64Comparisons:nativeCases.length*2,failures:0},
  benchmark:{runtime:process.version,rounds,medianOf:5,description:'fromNumber plus multiply/add/divide/subtract chain and binary64/int32 stores',uniqueValues:{baselineMs:oldMs,acceleratedMs:newMs,speedup:oldMs/newMs},repeated512Values:{baselineMs:oldRepeatedMs,acceleratedMs:newRepeatedMs,speedup:oldRepeatedMs/newRepeatedMs},sqrt:{baselineMs:oldSqrtMs,acceleratedMs:newSqrtMs,speedup:oldSqrtMs/newSqrtMs}},
  limitations:'Microbenchmarks are not browser frame timing; native x87 evidence is from the current x86 host. Math.sqrt supplies a candidate only: exact squared integer midpoint comparisons certify PC53 rounding; failed certificates use the original BigInt square root.'
};
writeFileSync(new URL('../../analysis/float80-performance-verification.json',import.meta.url),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify(report,null,2));
} finally {
  rmSync(temporary, {recursive:true,force:true});
}
