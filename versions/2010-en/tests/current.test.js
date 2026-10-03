import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import * as current from '../src/engine/current.js';
import { sampleAttenuationDistance } from '../src/engine/spatial-metrics.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
for(const[name,invoke]of Object.entries({sampleAttenuationDistance,...Object.fromEntries(Object.keys(current.CURRENT_ROUTINES).map(name=>[name,current[name]]))})){
 const fixture=await json(`fixtures/original-${name}.json`);
 test(`${name}:original preserved-code and PC53 evidence`,()=>assertNativeProvenance(source,fixture));
 test(`${name}:complete state, return, feedback and RNG match native code`,()=>{
  const harness=createNativeHarness(source,fixture);
  for(const[index,row]of fixture.cases.entries())harness.check(row,index,(memory,rng,args)=>invoke(memory,...args,{trig}));
 });
}
