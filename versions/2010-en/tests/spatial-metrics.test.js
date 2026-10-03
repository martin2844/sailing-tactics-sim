import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import * as metrics from '../src/engine/spatial-metrics.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
for(const name of Object.keys(metrics.SPATIAL_METRIC_ROUTINES)){
  const fixture=await json(`fixtures/original-${name}.json`);
  test(`${name}:original preserved-code and precision evidence`,()=>assertNativeProvenance(source,fixture));
  test(`${name}:whole state, exactextended return, stored bits and RNG match native code`,()=>{
    const harness=createNativeHarness(source,fixture);
    for(const[index,row]of fixture.cases.entries())harness.check(row,index,(memory,rng,args)=>metrics[name](memory,...args,{trig}));
  });
}
