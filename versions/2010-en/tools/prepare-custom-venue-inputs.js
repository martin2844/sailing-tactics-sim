import { readFile,writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { CUSTOM_VENUE_ADDRESSES as a } from '../src/engine/custom-venue.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const sourceSha256=createHash('sha256').update(source).digest('hex');
const excluded=new Set(['initializeCustomVenuePoint','terrainHeight','terrainWind','drawStart','drawEnd','noise']);
const integerInputs={...Object.fromEntries(Object.entries(a).filter(([key])=>!excluded.has(key))),
  pointCount:0x522f08,boatCount:0x4da194,placementMode:0x4da1e8,
  firstCenterX:0x53521c,firstCenterY:0x4f4b5c,secondCenterX:0x535230,secondCenterY:0x4f4b70};
const defaults={length:2000,firstHeading:90,firstLeft:0,firstRight:0,firstSize:0,firstWind:2,firstSign:1,
  secondHeading:270,secondLeft:0,secondRight:0,secondSize:0,secondWind:3,secondMode:0,secondSign:-1,
  firstBearing:17,secondBearing:19,pointCount:10,boatCount:2,placementMode:0,
  firstCenterX:123,firstCenterY:-456,secondCenterX:789,secondCenterY:-987};
const cases=[];
const add=(index,group,changes={},noiseKind=0)=>{
  const noise=Buffer.alloc(72*4);
  for(let vertex=0;vertex<72;vertex++)noise.writeInt32LE(noiseKind===0?vertex%17:noiseKind===1?0:(vertex*37)%101-50,vertex*4);
  cases.push({group,arguments:[index],seed:(0x2010+cases.length*71)>>>0,
    inputs:{...defaults,...changes},doubleInputs:{},patches:[{address:a.noise,bytes:noise.toString('hex')}]});
};
for(let index=1;index<=5;index++)for(const firstLeft of[-1,0,1])for(const firstRight of[-1,0,1])
  for(const length of[1500,2000,2500])for(const firstSize of[0,1,2])
    add(index,'first-bay-settings',{firstLeft,firstRight,length,firstSize},index%3);
for(let index=6;index<=10;index++)for(const secondLeft of[-1,0,1])for(const secondRight of[-1,0,1])
  for(const length of[1500,2000,2500])for(const secondSize of[0,1])
    add(index,'second-bay-settings',{secondLeft,secondRight,length,secondSize},index%3);
for(const index of[6,7,8])for(const secondMode of[0,1,2,3])for(const secondLeft of[-1,0,1])
  for(const secondRight of[-1,0,1])for(const length of[1500,2000,2500])
    for(const placementMode of[0,1])add(index,'second-bay-mode-and-gap',{secondMode,secondLeft,secondRight,length,placementMode});
for(let index=1;index<=10;index++)for(const heading of[-90,0,1,44,47,90,180,270,359,360,450])
  for(const placementMode of[-1,0,1,2])
    add(index,'orientation-and-placement',{firstHeading:heading,secondHeading:heading,placementMode,boatCount:index%2?0:30},2);
for(const firstWind of[-1,0,1,2])for(const secondWind of[-1,0,1,2])
  for(const index of[1,2,3,6,7,8])add(index,'retained-and-clamped-wind',{firstWind,secondWind});
const manifest={source:'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe',sourceSha256,
  x87ControlWord:'0x027f',routine:{name:'initializeCustomVenuePoint',address:a.initializeCustomVenuePoint,
    argumentTypes:['I32'],returnType:'void'},mutableBlock:{address:0x4da000,size:0x60588},
  integerInputs,integerOutputs:integerInputs,doubleInputs:{},doubleOutputs:{},cases,
  scope:'Complete original custom constructor for all10preset points; explicit settings−1/0/1, original integer length presets, both bay modes, retained centers and fixed vertex noise. No RNG draws in the original routine.'};
await writeFile(new URL('../analysis/custom-venue-capture-inputs.json',import.meta.url),JSON.stringify(manifest,null,2)+'\n');
console.log(`${cases.length} complete custom venue input cases.`);
