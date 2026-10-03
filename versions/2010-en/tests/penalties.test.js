import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import * as penalties from '../src/engine/penalties.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
for(const name of Object.keys(penalties.PENALTY_ROUTINES)){
 const fixture=await json(`fixtures/original-${name}.json`);
 test(`${name}:preserved original native instructions and PC53 evidence`,()=>assertNativeProvenance(source,fixture));
 test(`${name}:complete connected state, RNG, returns and ordered sounds match native code`,()=>{
  const harness=createNativeHarness(source,fixture);
  for(const[index,row]of fixture.cases.entries()){
   const sounds=[],options={trig,playSound:event=>sounds.push(event)};
   harness.check(row,index,(memory,rng,args)=>{
    if(['respawnNearStart','collisionPenalty','updateMarkStartPenalties','updateInterference','prestartSpeedPercent'].includes(name))
     return penalties[name](memory,...args,rng,options);
    return penalties[name](memory,...args,options);
   });
   assert.deepEqual(sounds,row.expected.sounds,`case${index}:ordered original sound requests`);
  }
 });
}
