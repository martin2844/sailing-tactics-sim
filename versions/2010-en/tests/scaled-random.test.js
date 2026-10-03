import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { scaledRandom } from '../src/engine/application.js';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const fixture=JSON.parse(await readFile(new URL('fixtures/original-scaled-random.json',import.meta.url),'utf8'));

test('signed random helper reference covers its original guard and divisor boundaries',()=>{
  assertNativeProvenance(source,fixture);
  assert.equal(fixture.routine.address,0x41e000);
  assert.deepEqual(fixture.routine.argumentTypes,['I32']);
  assert.equal(fixture.cases.length,45);
  assert.deepEqual([...new Set(fixture.cases.map(row=>row.seed))],[1,2002,0xffffffff]);
  assert.deepEqual([...new Set(fixture.cases.map(row=>row.arguments[0]))],
    [-2147483648,-2147483647,-32001,-32000,-100,-2,-1,0,1,2,100,32000,32001,2147483646,2147483647]);
  for(const value of [-100,-2]){
    const row=fixture.cases.find(row=>row.seed===2002&&row.arguments[0]===value);
    assert.equal(row.expected.eax,6576,'the original retains a negative divisor then clamps it to one');
  }
});

test('45 original signed-range calls match exact returns, RNG, all mutable bytes and immutable scope',()=>{
  const harness=createNativeHarness(source,fixture);
  for(const [index,row]of fixture.cases.entries())harness.check(row,index,(_memory,rng,args)=>scaledRandom(args[0],rng));
});
