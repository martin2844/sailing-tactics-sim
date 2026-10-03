import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import { initializeCustomVenuePoint } from '../src/engine/custom-venue.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const fixture=await json('fixtures/original-custom-venue.json');
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
test('custom venue:original preserved-code and precision evidence',()=>assertNativeProvenance(source,fixture));
test('custom venue:all preset writes, generated vertices, target bytes and RNG match native code',()=>{
  const harness=createNativeHarness(source,fixture);
  for(const[index,row]of fixture.cases.entries()){
    harness.check(row,index,(memory,rng,args)=>initializeCustomVenuePoint(memory,args[0],{trig}));
  }
});
