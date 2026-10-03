import assert from 'node:assert/strict';
import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { createNativeHarness } from './native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { integratePositions } from '../src/engine/integration.js';
import { clampedPointDistance,nearestWaypointDistance,respawnWaypoint } from '../src/engine/waypoints.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'),await json('../assets/data/x87-stored-trig.json'));
for(const [name,translated]of [['clamped-point-distance',(memory,_rng,args)=>clampedPointDistance(memory,...args)],
 ['nearest-waypoint',(memory,_rng,args)=>nearestWaypointDistance(memory,...args)],
 ['respawn-waypoint',(memory,rng,args)=>respawnWaypoint(memory,args[0],rng,{trig})],
 ['integration',(memory,rng,_args,sounds)=>integratePositions(memory,rng,{trig,playSound:event=>sounds.push(event)})]]){
 const fixture=await json(`fixtures/original-${name}.json`);
 test(`${name}: strict full mutable bytes, RNG, F80 and ordered sounds`,()=>{
  const harness=createNativeHarness(source,fixture);
  for(const[index,row]of fixture.cases.entries()){
   const sounds=[];
   harness.check(row,index,(memory,rng,args)=>translated(memory,rng,args,sounds));
   if(row.expected.sounds)assert.deepEqual(sounds,row.expected.sounds,`case${index}:original sounds`);
  }
 });
}
