import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import { apparentWindExtended } from '../src/engine/apparent-wind.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
const fixture=await json('fixtures/original-apparent-wind.json');
test('apparent wind:unchanged original native code and PC53 evidence',()=>assertNativeProvenance(source,fixture));
test('apparent wind:exact stored force/F80 return, vector fields and complete state',()=>{
 const harness=createNativeHarness(source,fixture);
 for(const[index,row]of fixture.cases.entries())harness.check(row,index,(memory,rng,args)=>apparentWindExtended(memory,...args,{trig}));
});
