import { readFile,writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { WIND_INITIALIZATION_ADDRESSES as a } from '../src/engine/wind-initialization.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const sourceSha256=createHash('sha256').update(source).digest('hex');
const excluded=new Set(['initializeWind','initializeTide','initializeWindSources','respawnWindPatch','windChangeSpeed','degreeFactor',
  'boatX','boatY','patchX','patchY','patchStrength','patchNextTime','patchWidth','patchSpeed','patchDirection',
  'primaryDirection','primaryStrength','primaryWidth','shoreDirection','shoreStrength']);
const integerInputs=Object.fromEntries(Object.entries(a).filter(([field])=>!excluded.has(field)));
const integerOutputs={...integerInputs};
const doubleInputs={windChangeSpeed:a.windChangeSpeed};
const doubleOutputs={};
for(let patch=1;patch<=5;patch++){
  for(const field of ['patchStrength','patchNextTime','patchWidth','patchSpeed','patchDirection'])integerOutputs[`${field}${patch}`]=a[field]+patch*4;
  for(const field of ['patchX','patchY'])doubleOutputs[`${field}${patch}`]=a[field]+patch*8;
}
for(let index=0;index<7;index++)for(const field of ['primaryDirection','primaryStrength','primaryWidth'])integerOutputs[`${field}${index}`]=a[field]+index*4;
for(let index=0;index<5;index++)for(const field of ['shoreDirection','shoreStrength'])integerOutputs[`${field}${index}`]=a[field]+index*4;
const values=Object.fromEntries(Object.keys(integerInputs).map((field,index)=>[field,0x13570000+index]));
Object.assign(values,{windSetting:0,tideSetting:1,course:1,venue:0,humanPlayers:1,island:0,weather:0,
  thermalReversal:0,offshoreCourseFlag:0,customShoreMode:0,customShoreDirection:90,customShoreSign:1,
  customThermalDirection:180,customFirstX:-1,customFirstY:-1,customSecondX:1,customSecondY:1,
  customShoreEnabled:1,customAngle:90,customShoreStrength:10,customNoTide:0,forceVenueDirection:0,
  customOppositeShoreFlag:0,channelSide:1,optimistFlag:0,shore:1,direction:280,strength:12,condition:1,time:100,
  driftSector:0,baseDirection:315});
const boatPositions=Buffer.alloc(32);
for(const [index,value]of [1000.75,-2000.75,3000.25,4000.25].entries())boatPositions.writeDoubleLE(value,index*8);
const patches=[{address:a.boatX+8,bytes:boatPositions.subarray(0,16).toString('hex')},
  {address:a.boatY+8,bytes:boatPositions.subarray(16).toString('hex')}];
const venues=[-1,0,1,2,3,4,5,6,7,8,9,10,11,12,100,101,102,103,104,105,106,999];
const make=()=>[];
const add=(cases,group,changes={},args=[],doubleChanges={})=>cases.push({group,arguments:args,
  inputs:{...values,...changes},doubleInputs:{windChangeSpeed:1,...doubleChanges},patches,
  seed:(0x20101000+cases.length*37)>>>0});
let state=0x2010;
const random=limit=>{state=(Math.imul(state,1664525)+1013904223)>>>0;return state%limit;};
const wind=make();
for(const venue of venues)for(const windSetting of [-1,0,1,2,3,4])for(const course of [1,8,9,10])add(wind,'venues-strength-course',{venue,windSetting,course});
for(const humanPlayers of [0,1,2,3])for(const island of [0,1,2])for(const thermalReversal of [-1,0,1,2])for(const offshoreCourseFlag of [0,1])add(wind,'retained-and-reversal-flags',{humanPlayers,island,thermalReversal,offshoreCourseFlag});
for(const customShoreMode of [0,1,2,3])for(const customOppositeShoreFlag of [0,1])for(const customShoreDirection of [0,89,90,179,180,269,270,359])add(wind,'custom-thermal-direction',{venue:999,customShoreMode,customOppositeShoreFlag,customShoreDirection});
for(let index=0;index<256;index++)add(wind,'mixed-flags',{venue:venues[random(venues.length)],windSetting:random(5),
  course:random(15),humanPlayers:random(3),island:random(2),weather:random(7),thermalReversal:random(3)-1,
  offshoreCourseFlag:random(2),customShoreMode:random(4),customOppositeShoreFlag:random(2),customShoreDirection:random(360)});
const tide=make();
for(const venue of venues)for(const tideSetting of [-1,0,1,2])for(const weather of [0,1,3,4,5])
  for(const forceVenueDirection of [0,1])for(const optimistFlag of [0,1])add(tide,'enable-venue-overrides',{venue,tideSetting,weather,forceVenueDirection,optimistFlag});
for(const customAngle of [29,30,31,49,50,51,89,129,130,131,149,150,151])
  for(const customShoreMode of [0,1,2])for(const customShoreEnabled of [0,1])for(const geometry of [0,1,2]){
    add(tide,'custom-angle-and-geometry',{venue:999,customAngle,customShoreMode,customShoreEnabled,
      customFirstX:geometry>0?-1:10,customFirstY:geometry>0?-1:10,
      customSecondX:geometry===2?-1:10,customSecondY:geometry===2?-1:10});
  }
for(const customNoTide of [0,1])for(const customShoreStrength of [9,10,11])add(tide,'custom-disable',{venue:999,customNoTide,customShoreStrength});
const sources=make();
for(const venue of venues)for(const shore of [-1,0,1,2,3,4])add(sources,'venue-and-shore',{venue,shore});
const patch=make();
for(let index=1;index<=5;index++)for(const humanPlayers of [1,2])for(const venue of [-1,0,1,101,999])
  for(const forceVenueDirection of [0,1])for(const windSetting of [0,1])for(const thermalReversal of [-1,0,1])
    add(patch,'players-venue-RNG-and-direction',{humanPlayers,venue,forceVenueDirection,windSetting,thermalReversal},[index]);
for(const windChangeSpeed of [0,0.01,0.5,1,1.25,2,10])add(patch,'binary64-time-scale',{},[1],{windChangeSpeed});
for(const strength of [-1,0,1,2,3,9,10,11,22])add(patch,'half-strength-scaled-RNG',{strength},[5]);
const common={source:'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe',sourceSha256,
  x87ControlWord:'0x027f',mutableBlock:{address:0x4da000,size:0x60588},integerInputs,integerOutputs,doubleInputs,doubleOutputs,
  scope:'Prepared complete original initialization children; all mutable bytes, exact indexed outputs and RNG are compared. No whole-game claim.'};
for(const [name,file,cases,args]of [
  ['initializeWind','wind-start',wind,[]],['initializeTide','tide-initialization',tide,[]],
  ['initializeWindSources','wind-sources',sources,[]],['respawnWindPatch','wind-patch',patch,['I32']],
]){
  const manifest={...common,routine:{name,address:a[name],argumentTypes:args,returnType:'void'},cases};
  await writeFile(new URL(`../analysis/${file}-capture-inputs.json`,import.meta.url),JSON.stringify(manifest,null,2)+'\n');
  console.log(`${name}: ${cases.length} whole-routine input cases.`);
}
