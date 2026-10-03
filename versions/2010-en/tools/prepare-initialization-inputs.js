import { readFile,writeFile } from 'node:fs/promises';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { withX87ControlWord } from '../../../src/runtime/float80.js';
import { PoseyRng } from '../../../src/engine/integer-core.js';
import { initializeBoatOptions } from '../src/engine/boat-options.js';
import { initializeConfiguration } from '../src/engine/configuration.js';
import { initializeWind,initializeTide,initializeWindSources } from '../src/engine/wind-initialization.js';
import { updateGlobalWind } from '../src/engine/wind.js';
import { initializeCourse } from '../src/engine/course.js';
import { resetBoat } from '../src/engine/movement-history.js';
import { INITIALIZATION_ROUTINES } from '../src/engine/initialization.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const baselineFixture=await json('../tests/fixtures/original-boat-options.json'),baseline=Buffer.from(baselineFixture.mutableBaseline,'hex');
const config=await json('../analysis/configuration-capture-inputs.json');
const memory=loadPE32(source),rng=new PoseyRng(),trig=createCapturedTrig(await json('../assets/data/x87-trig.json'));
const base=baselineFixture.mutableBlock.address;
const integers={...config.integerInputs,selector:0x4da144,humans:0x4da140,skill:0x4da198,
 pose:0x4da188,name:0x4da1f0,stage:0x4da1d8,windSetting:0x4da154,tideSetting:0x4da158,
 oneBoat:0x536470,retainAi:0x5363fc,baseWindSector:0x4fad38,prevTide:0x5359d0,
 initialFinish:0x5364e0,startAX:0x536410,startAY:0x536414,startBX:0x4fe094,startBY:0x4fe2a0,
 markX:0x5229d4,markY:0x522ac8,markEX:0x5229c8,markEY:0x522ac4,
 width:0x523598,courseHeading:0x535208,windDirection:0x5362d4,windStrength:0x522ad0,
 time:0x4f42b8,lastTime:0x4f8cd0};
const defaults={...config.cases[0].inputs,selector:12,humans:1,skill:10,pose:6,name:1,stage:5,
 course:1,difficulty:6,boatClass:6,boatCount:12,windSetting:2,tideSetting:1,oneBoat:0,retainAi:0,prevTide:0,
 initialFinish:0,baseWindSector:3,flag5363f8:0,flag53646c:0,enlargedTerrain:0,
 startAX:0,startAY:350,startBX:250,startBY:350,markX:0,markY:-750,markEX:0,markEY:1100,
 width:220,courseHeading:105,windDirection:105,windStrength:12,time:-170,lastTime:-170};
const groups={placeStartingBoats:[],initializeBoats:[],initializeRace:[]};
const differences=after=>{
 const runs=[];let start=-1,last=-1;
 for(let i=0;i<after.length;i++)if(after[i]!==baseline[i]){
  if(start<0){start=i;last=i;}else if(i-last<=16)last=i;else{runs.push({address:base+start,bytes:Buffer.from(after.subarray(start,last+1)).toString('hex')});start=i;last=i;}
 }
 if(start>=0)runs.push({address:base+start,bytes:Buffer.from(after.subarray(start,last+1)).toString('hex')});
 return runs;
};
const prepare=(name,changes,group)=>{
 memory.writeBytes(base,baseline);rng.srand(0x20100000+groups[name].length*37);
 const inputs={...defaults,...changes};for(const[field,value]of Object.entries(inputs))memory.writeI32(integers[field],value);
 memory.writeF64(0x4da160,1);memory.writeF64(0x4da178,1);memory.writeF64(0x523d48,1);memory.writeF64(0x5359f0,-170.5);
 memory.writeF64(0x4fba00,0.75);memory.writeF64(0x535558,1.25);
 withX87ControlWord(0x027f,()=>{
  initializeBoatOptions(memory);
  if(name!=='initializeRace'){
   initializeConfiguration(memory,rng,{trig});initializeWind(memory,rng);initializeTide(memory,rng);
   updateGlobalWind(memory,rng,{trig});initializeWindSources(memory,rng);initializeCourse(memory,1,rng,{trig});
   if(name==='placeStartingBoats')for(let boat=1;boat<=memory.readI32(0x4da194);boat++)resetBoat(memory,boat);
  }
 });
 groups[name].push({group,arguments:[],seed:rng.state,patches:differences(memory.readBytes(base,baseline.length)),
  preparation:{source:'Complete source-derived option/configuration/wind/course functions; no captured resulting output.',selector:inputs.selector,
   course:inputs.course,venue:inputs.venue,stage:inputs.stage,boats:inputs.boatCount,humans:inputs.humans}});
};
for(let selector=1;selector<=27;selector++)for(const boatCount of[2,12]){
 prepare('initializeBoats',{selector,boatCount,name:selector%15+1},'all27boat-selectors-and-counts');
 prepare('placeStartingBoats',{selector,boatCount},'all27boat-selectors-and-counts');
}
for(const stage of[1,2,5,10])for(const humans of[1,2])for(const boatCount of[2,15,30])
 for(const venue of[0,5]){
  prepare('initializeBoats',{stage,humans,boatCount,venue,pose:stage===1?2:6},'stage-human-count-and-venue-five');
  prepare('placeStartingBoats',{stage,humans,boatCount,venue,pose:stage===1?2:6},'stage-human-count-and-venue-five');
 }
for(const field of['oneBoat','retainAi','enlargedTerrain','reducedTerrain','flag53640c','flag536408','placementMode'])
 for(const stage of[1,5]){
  prepare('initializeBoats',{[field]:1,stage,boatCount:15,pose:2},'retained-ai-placement-and-size-flags');
  prepare('placeStartingBoats',{[field]:1,stage,boatCount:15,pose:2},'retained-ai-placement-and-size-flags');
 }
for(let selector=1;selector<=27;selector++)prepare('initializeRace',{selector,boatCount:12,name:selector%15+1},'all27boat-options-through-race-initializer');
for(const venue of[0,1,2,3,4,5,6,7,9,10,11,12,100,101,102,103,104,105,106,999])
 for(const stage of[1,5,10])prepare('initializeRace',{venue,stage,boatCount:stage===1?2:12},'allvenues-through-complete-race-initializer');
for(const course of[1,2,3,4,7,8,9,10])for(const humans of[1,2])
 prepare('initializeRace',{course,humans,difficulty:7,boatClass:7,selector:14,boatCount:humans===2?2:15},'course-human-class-and-offshore-rules');
for(const name of Object.keys(groups)){
 if(process.argv[2]&&process.argv[2]!==name)continue;
 const manifest={source:baselineFixture.source,sourceSha256:baselineFixture.sourceSha256,x87ControlWord:'0x027f',
  mutableBlock:baselineFixture.mutableBlock,integerInputs:{},integerOutputs:{},doubleInputs:{},doubleOutputs:{},
  routine:{name,address:INITIALIZATION_ROUTINES[name],argumentTypes:[],returnType:'void'},cases:groups[name],
  scope:'Complete original routine with source-derived prepared finite game states, real coupled children and semantic CString contents. No captured output substitution.'};
 await writeFile(new URL(`../analysis/${name}-capture-inputs.json`,import.meta.url),JSON.stringify(manifest,null,2)+'\n');
 console.log(`${name}: ${groups[name].length} complete native input cases`);
}
