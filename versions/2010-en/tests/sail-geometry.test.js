import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { assertNativeProvenance, createNativeHarness } from './native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { initializeSailGeometry } from '../src/render/sail-geometry.js';

const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const source = await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe', import.meta.url));
const fixtureBytes = await readFile(new URL('fixtures/original-sail-geometry.json', import.meta.url));
const fixture = JSON.parse(fixtureBytes);
const trig = createCapturedTrig(await json('../assets/data/x87-trig.json'));
const baseline = assertNativeProvenance(source, fixture);
const groups = new Map();
for (const [index, row] of fixture.cases.entries()) {
  if (!groups.has(row.group)) groups.set(row.group, []);
  groups.get(row.group).push({ index, row });
}
const report = { sourceSha256: sha(source), fixtureSha256: sha(fixtureBytes),
  sourceModuleSha256: sha(await readFile(new URL('../src/render/sail-geometry.js', import.meta.url))),
  originalTextAndFileUnchanged: true, x87ControlWord: '0x027f', routine: fixture.routine,
  comparison: 'Every normalized mutable byte, exact SHA256, immutable image prefix/suffix, original RNG and all captured integer/double fields. No tolerance or old expected outputs.',
  caseCount: fixture.cases.length, groups: [], failures: [], exact: false };

test('2010 sail geometry uses fresh original native output and only declared older finite inputs', async () => {
  assert.deepEqual(fixture.routine.argumentTypes, ['F64', 'I32', 'I32', 'I32', 'I32', 'F64']);
  assert.equal(fixture.routine.address, 0x41bfb0);
  assert.equal(fixture.routine.returnType, 'void');
  assert.equal(fixture.cases.length, 2971);
  assert.equal(fixture.inputEvidence.oldExpectedOutputsUsed, false);
  assert.equal(fixture.inputEvidence.oldInputCases, 960);
  assert.equal(groups.get('mapped2002-finite-input-domain').length, 960);
  assert.equal(sha(await readFile(new URL('../../../tests/fixtures/original-sail-geometry.json', import.meta.url))),
    fixture.inputEvidence.finiteInputFixtureSha256);
  assert.equal(sha(await readFile(new URL('../analysis/sail-geometry-source-map.json', import.meta.url))),
    fixture.inputEvidence.sourceMappingSha256);
  assert.ok(fixture.inputEvidence.geometryRanges.every(range => range.stride === 8 && range.type === 'F64'));
  assert.ok(fixture.inputEvidence.controlRanges.every(range => range.stride === 4 && range.type === 'I32'));
  assert.deepEqual([...new Set(fixture.cases.map(row => row.preparation.selector).filter(Boolean))].sort((a,b) => a-b),
    Array.from({length:27}, (_,index) => index+1));
  for (const row of fixture.cases) {
    assert.ok(row.arguments.every(Number.isFinite));
    assert.equal(row.continue, undefined);
    assert.equal(row.expected.rngState, row.seed);
    assert.deepEqual(row.expected.sounds ?? [], []);
  }
});

function mismatch(expected, actual, base) {
  const index = actual.findIndex((value, offset) => value !== expected[offset]);
  if (index < 0) return undefined;
  const address = base + index;
  const region = [0x4f3ac0, 0x4feaf0, 0x511410, 0x535cf0]
    .find(start => address >= start && address < start + (start === 0x511410 ? 72 : 176));
  const offset = region === undefined ? index : region - base + Math.floor((address-region)/8)*8;
  const result = { firstAddress: '0x'+address.toString(16), fieldAddress: '0x'+(base+offset).toString(16),
    expectedBits: Buffer.from(expected.subarray(offset,offset+8)).toString('hex'),
    actualBits: Buffer.from(actual.subarray(offset,offset+8)).toString('hex') };
  if (region !== undefined) {
    result.expectedValue = Buffer.from(expected.subarray(offset,offset+8)).readDoubleLE();
    result.actualValue = Buffer.from(actual.subarray(offset,offset+8)).readDoubleLE();
  }
  return result;
}

for (const [group, rows] of groups) test(`${group}: ${rows.length} complete sail geometry calls match original native bits`, () => {
  const harness = createNativeHarness(source, fixture);
  const failures = [];
  for (const {index,row} of rows) {
    let expected;
    try {
      harness.check(row,index,(memory,rng,arguments_) => {
        expected = memory.readBytes(fixture.mutableBlock.address, baseline.length);
        for (const change of row.expected.imageChanges)
          expected.set(Buffer.from(change.after,'hex'),change.address-fixture.mutableBlock.address);
        return initializeSailGeometry(memory,...arguments_,{trig});
      });
    } catch (error) {
      const actual = harness.memory.readBytes(fixture.mutableBlock.address,baseline.length);
      failures.push({index,group,arguments:row.arguments,preparation:row.preparation,error:error.message,
        ...(expected ? mismatch(expected,actual,fixture.mutableBlock.address) : {})});
    }
  }
  report.groups.push({group,cases:rows.length,exactCases:rows.length-failures.length,failedCases:failures.length});
  report.failures.push(...failures);
  assert.equal(failures.length,0,`${failures.length} exact discrepancies; first ${JSON.stringify(failures.slice(0,4))}`);
});

test.after(async () => {
  report.exact = report.failures.length === 0 && report.groups.reduce((sum,group) => sum+group.cases,0) === fixture.cases.length;
  await writeFile(new URL('../analysis/sail-geometry-native-comparison.json',import.meta.url),JSON.stringify(report,null,2)+'\n');
});
