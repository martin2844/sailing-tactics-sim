import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile,readdir } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import { initializeRace } from '../src/engine/initialization.js';
import { integratePositions } from '../src/engine/integration.js';
import { updateBoatDynamics } from '../src/engine/boat-dynamics.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { readCString } from '../src/render/text.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'),await json('../assets/data/x87-stored-trig.json'));
const fixtures=await readdir(new URL('fixtures/',import.meta.url));
for(const filename of fixtures.filter(name=>/^original-retained-(integration(?:-expanded-\d+|-modes)?|dynamics-integration)\.json$/.test(name)&&(!process.env.TACT_RETAINED_FIXTURE||name===process.env.TACT_RETAINED_FIXTURE)).sort()){
const fixture=await json(`fixtures/${filename}`);
test(`${filename}:unchanged original code, retained chains and live CString/RNG evidence`,()=>{
 assertNativeProvenance(source,fixture);
 assert.ok(fixture.chains.length>=1);
 for(const chain of fixture.chains){
  const rows=fixture.cases.slice(chain.start,chain.start+(chain.callCount??chain.steps+1));
  assert.equal(rows[0].routine.address,0x41be70);
  assert.equal(rows[0].continue,undefined);
  assert.ok(chain.steps>=50&&chain.steps<=100);
  assert.equal(rows.filter(row=>row.routine.address===0x43cf60).length,chain.steps);
  for(const row of rows.slice(1)){
   assert.ok([0x43cf60,0x43a030].includes(row.routine.address));assert.equal(row.continue,true);
   assert.equal('seed' in row,false);
   if(row.routine.address===0x43cf60)assert.equal(row.expected.globalStrings.length,36);
  }
 }
});
test(`${filename}:every live mutable byte, original name, RNG and ordered sound matches`,()=>{
 const harness=createNativeHarness(source,fixture);let names;
 for(const[index,row]of fixture.cases.entries()){
  const sounds=[];
  const invoke=row.routine.address===0x41be70?initializeRace:row.routine.address===0x43cf60?integratePositions:row.routine.address===0x43a030?updateBoatDynamics:undefined;
  assert.equal(typeof invoke,'function');
  harness.check(row,index,(memory,rng,args)=>row.routine.address===0x43a030?invoke(memory,...args,rng,{trig,playSound:event=>sounds.push(event)}):invoke(memory,rng,{trig,playSound:event=>sounds.push(event)}));
  assert.deepEqual(sounds,row.expected.sounds,`chain${row.chain} step${row.step}:original ordered sounds`);
  const currentNames=Array.from({length:35},(_,boat)=>readCString(harness.memory,0x4fec30+boat*4));
  if(row.routine.address===0x41be70)names=currentNames;
  else assert.deepEqual(currentNames,names,`chain${row.chain} step${row.step}:retained original boat names`);
 }
});
}
