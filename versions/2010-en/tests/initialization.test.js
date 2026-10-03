import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import { initializeBoats,initializeRace } from '../src/engine/initialization.js';
import { placeStartingBoats } from '../src/engine/starting-positions.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
for(const[name,translated]of Object.entries({placeStartingBoats,initializeBoats,initializeRace})){
 const fixture=await json(`fixtures/original-${name}.json`);
 test(`${name}:original unchanged native code and legitimate boat-count evidence`,()=>assertNativeProvenance(source,fixture));
 test(`${name}:complete state, names, RNG and ordered sounds match original native code`,()=>{
  const harness=createNativeHarness(source,fixture);
  for(const[index,row]of fixture.cases.entries()){
   const sounds=[];
   harness.check(row,index,(memory,rng)=>translated(memory,rng,{trig,playSound:event=>sounds.push(event)}));
   assert.deepEqual(sounds,row.expected.sounds,`case${index}:original ordered sounds`);
  }
 });
}
