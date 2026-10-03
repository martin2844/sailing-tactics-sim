import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { createNativeHarness } from './native-state.js';
import { distanceToBoat } from '../src/engine/movement.js';
import { resetBoat,recordTrails,recordWaypointHistory } from '../src/engine/movement-history.js';
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const fromBits=value=>Buffer.from(value,'hex').readDoubleLE();
for(const [file,translated]of [['distance',(memory,_rng,args)=>distanceToBoat(memory,args[0],fromBits(args[1]),fromBits(args[2]))],
 ['reset-boat',(memory,_rng,args)=>resetBoat(memory,args[0])],['trails',memory=>recordTrails(memory)],
 ['waypoint-history',(memory,_rng,args)=>recordWaypointHistory(memory,args[0])]]){
 const fixture=JSON.parse(await readFile(new URL(`fixtures/original-${file}.json`,import.meta.url),'utf8'));
 test(`${file}: strict full original mutable state, RNG and floating return`,()=>{
  const harness=createNativeHarness(source,fixture);
  for(const [index,row]of fixture.cases.entries())harness.check(row,index,translated);
 });
}
