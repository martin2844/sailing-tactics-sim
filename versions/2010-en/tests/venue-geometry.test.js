import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { assertNativeProvenance,createNativeHarness } from './native-state.js';
import { initializeVenuePoint,VENUE_POINT_ROUTINES } from '../src/engine/venue-geometry.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
for(const venue of Object.keys(VENUE_POINT_ROUTINES)){
  const fixture=await json(`fixtures/original-venue-${venue}-point.json`);
  test(`venue${venue}:original preserved-code and precision evidence`,()=>assertNativeProvenance(source,fixture));
  test(`venue${venue}:every vertex, state byte and RNG matches native code`,()=>{
    const harness=createNativeHarness(source,fixture);
    for(const [index,row]of fixture.cases.entries()){
      harness.check(row,index,(memory,rng,args)=>initializeVenuePoint(memory,Number(venue),args[0],rng,{trig}));
    }
  });
}
