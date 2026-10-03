import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import { initializeCourse } from '../src/engine/course.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
const fixture=await json('fixtures/original-initializeCourse.json');
test('initializeCourse:original preserved-code and PC53 evidence',()=>assertNativeProvenance(source,fixture));
test('initializeCourse:complete mark/target writes, RNG and all mutable bytes match native code',()=>{
 const harness=createNativeHarness(source,fixture);
 for(const[index,row]of fixture.cases.entries())harness.check(row,index,(memory,rng,args)=>initializeCourse(memory,...args,rng,{trig}));
});
