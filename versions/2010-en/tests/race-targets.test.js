import assert from 'node:assert/strict';
import test from 'node:test';
import {readFile}from'node:fs/promises';
import {createNativeHarness}from'./native-state.js';
import {createCapturedTrig}from'../src/engine/native-trig.js';
import {advanceRaceTarget}from'../src/engine/race-targets.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const fixture=await json('fixtures/original-advanceRaceTarget.json');
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'),await json('../assets/data/x87-stored-trig.json'));
test('Full target advancement: entire original state, RNG and ordered sounds across dynamic course/finish branches',()=>{
 const harness=createNativeHarness(source,fixture);
 for(const[index,row]of fixture.cases.entries()){
  const sounds=[];
  harness.check(row,index,(memory,rng,args)=>advanceRaceTarget(memory,args[0],{rng,trig,playSound:event=>sounds.push(event)}));
  assert.deepEqual(sounds,row.expected.sounds,`case${index}:ordered original sound requests`);
 }
});
