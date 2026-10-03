import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { saveRaceState,restoreRaceState } from '../src/engine/snapshots.js';
import { assertNativeProvenance,sha256 } from './native-state.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const fixture=JSON.parse(await readFile(new URL('fixtures/original-snapshots.json',import.meta.url),'utf8'));
const baseline=assertNativeProvenance(source,fixture);

test('complete 2010 snapshots match every native mutable byte, including retained save/restore chains',()=>{
  const memory=loadPE32(source),base=fixture.mutableBlock.address;
  const prefix=memory.readBytes(memory.base,base-memory.base);
  const suffix=memory.readBytes(base+baseline.length,memory.size-(base-memory.base)-baseline.length);
  let state=1;
  for (const [index,row] of fixture.cases.entries()) {
    if (!row.continue) {memory.writeBytes(base,baseline);state=row.seed;}
    for (const patch of [...fixture.profiles[row.profile].patches,...row.patches]) memory.writeBytes(patch.address,Buffer.from(patch.bytes,'hex'));
    const before=memory.readBytes(base,baseline.length),expected=before.slice();
    for (const change of row.expected.imageChanges) {
      const offset=change.address-base,width=change.before.length/2;
      assert.equal(Buffer.from(before.subarray(offset,offset+width)).toString('hex'),change.before,`case${index}: original before bytes`);
      expected.set(Buffer.from(change.after,'hex'),offset);
    }
    (row.kind===9?saveRaceState:restoreRaceState)(memory);
    assert.deepEqual(row.expected.events,[],`case${index}: original has no host callbacks`);
    assert.equal(row.expected.rngState,state,`case${index}: original RNG untouched`);
    const actual=memory.readBytes(base,baseline.length);
    assert.equal(sha256(actual),row.expected.mutableSha256,`case${index} ${row.label}: complete native SHA256`);
    assert.deepEqual(actual,expected,`case${index} ${row.label}: complete native word stores`);
  }
  assert.deepEqual(memory.readBytes(memory.base,prefix.length),prefix);
  assert.deepEqual(memory.readBytes(base+baseline.length,suffix.length),suffix);
});

test('snapshot fixture contains original signed-count boundaries, all30 boats and native continuation',()=>{
  const counts=new Set(fixture.cases.flatMap(row=>row.patches.filter(patch=>patch.address===0x4da194).map(patch=>Buffer.from(patch.bytes,'hex').readInt32LE())));
  assert.ok(counts.has(-2147483648));assert.ok(counts.has(-1));assert.ok(counts.has(0));assert.ok(counts.has(30));
  assert.equal(fixture.cases.filter(row=>row.continue).length,8);
  assert.deepEqual([...new Set(fixture.cases.map(row=>row.kind))].sort((a,b)=>a-b),[9,10]);
});
