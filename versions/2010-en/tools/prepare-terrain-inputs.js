import { readFile,writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { TERRAIN_ROUTINES } from '../src/engine/terrain.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const sourceSha256=createHash('sha256').update(source).digest('hex');
const integerInputs={course:0x4da19c,shore:0x5230dc,shoreSign:0x5127a4,shoreOffset:0x5229d0,
  weather:0x4f69b8,island:0x4f8b78,forceCondition:0x4f8db8,reversal:0x4f4510,
  enlargedTerrain:0x53527c,reducedTerrain:0x5364c8};
const doubleInputs={xAspect:0x4fba00,yAspect:0x535558};
const integerOutputs={...integerInputs,ellipseRadius:0x4f4b00,ellipseCenterX:0x535bc8,
  ellipseCenterY:0x4f3858,channelMode:0x536300,channelCount:0x5364b4};
const defaults={course:1,shore:2,shoreSign:1,shoreOffset:1000,weather:0,island:0,
  forceCondition:0,reversal:0,enlargedTerrain:0,reducedTerrain:0};
const common={source:'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe',sourceSha256,
  x87ControlWord:'0x027f',mutableBlock:{address:0x4da000,size:0x60588},integerInputs,doubleInputs,
  integerOutputs,doubleOutputs:{},scope:'Complete defined terrain branches, all mutable bytes and RNG; continuous raw-radian shoreline is calculated from the original x87 operands.'};
const groups={initializeShoreline:[],initializeEllipse:[],initializeAdvancedTerrain:[]};
const add=(name,group,changes,seed=1,aspects={})=>groups[name].push({group,arguments:[],seed,
  inputs:{...defaults,...changes},doubleInputs:{xAspect:1,yAspect:1,...aspects}});
for(const course of [0,1,8,9,10,11])for(const shore of [0,1,2,4])
  for(const shoreSign of [-1,0,1])for(const shoreOffset of [-2000,1000])
    for(const seed of [1,2,0x20102002,0xffffffff])
      add('initializeShoreline','course-shore-sign-offset',{course,shore,shoreSign,shoreOffset},seed);
for(const weather of [0,1,2,3,4,5,6,7])for(const shore of [1,2,4])
  for(const island of [0,1])for(const forceCondition of [0,1])for(const reversal of [0,1])
    for(const course of [1,8])for(const seed of [1,0x20102002])
      add('initializeEllipse','course-and-geometry-flags',{weather,shore,island,forceCondition,reversal,course},seed);
for(const xAspect of [0,0.1,0.5,1,1.5,2])for(const yAspect of [0,0.3,1,2])
  for(const course of [1,8])add('initializeEllipse','binary64-aspect',{course},0x2010,{xAspect,yAspect});
for(const weather of [2,3,4,5,6,7])for(const enlargedTerrain of [0,1])
  for(const reducedTerrain of [0,1])for(let seed=1;seed<=16;seed++)
    add('initializeAdvancedTerrain','weather-and-size-flags',{weather,enlargedTerrain,reducedTerrain},seed);
for(const [name,cases]of Object.entries(groups)){
  const file={initializeShoreline:'shoreline',initializeEllipse:'ellipse',initializeAdvancedTerrain:'advanced-terrain'}[name];
  const manifest={...common,routine:{name,address:TERRAIN_ROUTINES[name],argumentTypes:[],returnType:'void'},cases};
  await writeFile(new URL(`../analysis/${file}-capture-inputs.json`,import.meta.url),JSON.stringify(manifest,null,2)+'\n');
  console.log(`${name}: ${cases.length} complete original input cases`);
}
