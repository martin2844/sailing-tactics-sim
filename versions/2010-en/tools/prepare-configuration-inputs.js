import { readFile,writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { CONFIGURATION_ADDRESSES as a } from '../src/engine/configuration.js';
import { CUSTOM_VENUE_ADDRESSES as custom } from '../src/engine/custom-venue.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const sourceSha256=createHash('sha256').update(source).digest('hex');
const skip=new Set(['initializeConfiguration','xAspect','yAspect']);
const integerInputs={...Object.fromEntries(Object.entries(a).filter(([field])=>!skip.has(field))),
  firstHeading:custom.firstHeading,firstLeft:custom.firstLeft,firstRight:custom.firstRight,
  firstSize:custom.firstSize,firstWind:custom.firstWind,firstSign:custom.firstSign,
  secondHeading:custom.secondHeading,secondLeft:custom.secondLeft,secondRight:custom.secondRight,
  secondSize:custom.secondSize,secondWind:custom.secondWind,secondSign:custom.secondSign,
  secondMode:custom.secondMode,customLength:custom.length,customSmall:0x536508,customEarlyReturn:0x5364fc,
  flag5363f8:0x5363f8,flag53640c:0x53640c,flag536408:0x536408,flag53646c:0x53646c};
const doubleInputs={xAspect:a.xAspect,yAspect:a.yAspect};
const defaults={venue:0,course:1,boatClass:6,boatCount:12,difficulty:6,placementMode:0,
  tideSetting:1,weather:0,island:0,shore:2,reversal:0,shorelineMode:0,shorelineVariant:0,
  forceCondition:0,enlargedTerrain:0,reducedTerrain:0,pointCount:3,visiblePointCount:7,markCount:9,
  extraPointCount:2,backgroundPointCount:1,channelCount:5,
  firstHeading:90,firstLeft:0,firstRight:0,firstSize:0,firstWind:2,firstSign:1,
  secondHeading:270,secondLeft:0,secondRight:0,secondSize:0,secondWind:1,secondSign:-1,
  secondMode:0,customLength:2000,customSmall:0,customEarlyReturn:1,
  flag5363f8:1,flag53640c:0,flag536408:0,flag53646c:1};
const cases=[];
const add=(group,changes={},seed=1)=>cases.push({group,arguments:[],seed,inputs:{...defaults,...changes},doubleInputs:{xAspect:0.75,yAspect:1.25}});
for(let course=0;course<=14;course++)for(const difficulty of[6,7])for(const island of[0,1])
  for(const enlargedTerrain of[0,1])for(const reducedTerrain of[0,1])for(const boatCount of[2,12])
    for(const seed of[1,0x20102002])add('basic-course-and-size-flags',{course,difficulty,island,enlargedTerrain,reducedTerrain,boatCount},seed);
for(const boatClass of[0,1,2,3,4,6,7,10])for(const course of[7,8])for(const difficulty of[6,7])
  add('class-retention-and-forced-course',{boatClass,course,difficulty});
for(const venue of[1,2,3,4,5,6,7,8,9,10,11,12,100,101,102,103,104,105,106])
  for(const placementMode of[-1,0,1,2])for(const seed of[1,0x20102002])
    add('named-venue-and-placement',{venue,placementMode,enlargedTerrain:1},seed);
for(const firstLeft of[-1,0,1])for(const firstRight of[-1,0,1])for(const secondMode of[0,1,2,3])
  for(const customSmall of[0,1])for(const customEarlyReturn of[0,1])for(const customLength of[1500,2000,2500])
    add('custom-venue-settings-and-return',{venue:999,firstLeft,firstRight,
      secondLeft:firstRight,secondRight:firstLeft,secondMode,customSmall,customEarlyReturn,customLength});
for(const venue of[-1,0,8,13,999])for(const course of[-1,1,15])add('retained-selector-state',{venue,course});
const manifest={source:'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe',sourceSha256,
  x87ControlWord:'0x027f',routine:{name:'initializeConfiguration',address:a.initializeConfiguration,
    argumentTypes:[],returnType:'void'},mutableBlock:{address:0x4da000,size:0x60588},
  integerInputs,integerOutputs:integerInputs,doubleInputs,doubleOutputs:doubleInputs,cases,
  scope:'Complete42c060, including original custom999 fall-through behavior, all supported basic courses and named venues with child geometry and RNG.'};
await writeFile(new URL('../analysis/configuration-capture-inputs.json',import.meta.url),JSON.stringify(manifest,null,2)+'\n');
console.log(`${cases.length} complete configuration input cases.`);
