import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import { updateBoatDynamics } from '../src/engine/boat-dynamics.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
const fixture=await json('fixtures/original-updateBoatDynamics.json');
test('complete boat dynamics:original unchanged native code and PC53 evidence',()=>assertNativeProvenance(source,fixture));
test('complete boat dynamics:every mutable byte, RNG and ordered sounds match original code',()=>{
 const harness=createNativeHarness(source,fixture);
 for(const[index,row]of fixture.cases.entries()){
  const sounds=[];
  harness.check(row,index,(memory,rng,args)=>updateBoatDynamics(memory,...args,rng,{trig,playSound:event=>sounds.push(event)}));
  assert.deepEqual(sounds,row.expected.sounds,`case${index}:ordered original sound requests`);
 }
});
