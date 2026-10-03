import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import { WIND_ADDRESSES as a,updateGlobalWind,scheduleWindShift,bearingFromVector } from '../src/engine/wind.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
const groups=[
  ['original-wind.json',updateGlobalWind,(memory,rng)=>updateGlobalWind(memory,rng,{trig})],
  ['original-wind-schedule.json',scheduleWindShift,(memory,rng,args)=>scheduleWindShift(memory,...args)],
  ['original-wind-bearing.json',bearingFromVector,(memory,rng,args)=>bearingFromVector(memory,...args)],
];
for(const [file,translated,invoke]of groups){
  const fixture=await json(`fixtures/${file}`);
  test(`${translated.name}:native source, precision and complete typed address map`,()=>{
    assertNativeProvenance(source,fixture);
    for(const [field,address]of Object.entries({...fixture.integerInputs,...fixture.integerOutputs,...fixture.doubleInputs,...fixture.doubleOutputs}))assert.equal(a[field],address,field);
  });
  test(`${translated.name}:every native case matches full state, exact floating bits, RNG and return`,()=>{
    const harness=createNativeHarness(source,fixture);
    for(const [index,row]of fixture.cases.entries())harness.check(row,index,invoke);
  });
}
