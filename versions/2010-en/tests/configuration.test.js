import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import { initializeConfiguration } from '../src/engine/configuration.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const fixture=await json('fixtures/original-configuration.json');
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
test('configuration:original preserved-code and precision evidence',()=>assertNativeProvenance(source,fixture));
test('configuration:all complete course, venue, floating, preserved bytes and RNG match native code',()=>{
  const harness=createNativeHarness(source,fixture);
  for(const[index,row]of fixture.cases.entries()){
    harness.check(row,index,(memory,rng)=>initializeConfiguration(memory,rng,{trig}));
  }
});
