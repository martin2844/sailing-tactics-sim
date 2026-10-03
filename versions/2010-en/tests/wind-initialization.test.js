import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import { initializeWind,initializeTide,initializeWindSources,respawnWindPatch } from '../src/engine/wind-initialization.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
for(const [file,translated,invoke]of [
  ['wind-start',initializeWind,(memory,rng)=>initializeWind(memory,rng)],
  ['tide-initialization',initializeTide,(memory,rng)=>initializeTide(memory,rng)],
  ['wind-sources',initializeWindSources,(memory,rng)=>initializeWindSources(memory,rng)],
  ['wind-patch',respawnWindPatch,(memory,rng,args)=>respawnWindPatch(memory,args[0],rng,{trig})],
]){
  const fixture=await json(`fixtures/original-${file}.json`);
  test(`${translated.name}:original preserved-code and precision evidence`,()=>assertNativeProvenance(source,fixture));
  test(`${translated.name}:every complete mutable state, exact floating bits and RNG match native code`,()=>{
    const harness=createNativeHarness(source,fixture);
    for(const [index,row]of fixture.cases.entries())harness.check(row,index,invoke);
  });
}
