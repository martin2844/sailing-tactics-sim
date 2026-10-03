import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import { initializeShoreline,initializeEllipse,initializeAdvancedTerrain } from '../src/engine/terrain.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
for(const [file,translated]of [
  ['shoreline',initializeShoreline],['ellipse',initializeEllipse],['advanced-terrain',initializeAdvancedTerrain],
]){
  const fixture=await json(`fixtures/original-${file}.json`);
  test(`${translated.name}:original preserved-code and precision evidence`,()=>assertNativeProvenance(source,fixture));
  test(`${translated.name}:every geometry byte, exact floating field and RNG match native code`,()=>{
    const harness=createNativeHarness(source,fixture);
    for(const [index,row]of fixture.cases.entries())harness.check(row,index,(memory,rng)=>translated(memory,rng,{trig}));
  });
}
