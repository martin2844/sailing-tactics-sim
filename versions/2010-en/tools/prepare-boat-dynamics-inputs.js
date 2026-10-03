import { readFile,writeFile } from 'node:fs/promises';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { withX87ControlWord } from '../../../src/runtime/float80.js';
import { initializeBoatOptions } from '../src/engine/boat-options.js';
import { resetBoat } from '../src/engine/movement-history.js';
import { BOAT_DYNAMICS_ADDRESS } from '../src/engine/boat-dynamics.js';
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const original=JSON.parse(await readFile(new URL('../tests/fixtures/original-boat-options.json',import.meta.url),'utf8'));
const memory=loadPE32(source),baseline=Buffer.from(original.mutableBaseline,'hex'),base=original.mutableBlock.address;
const cases=[];
const globalFields={boats:0x4da194,humans:0x4da140,course:0x4da19c,stage:0x4da1d8,skill:0x4da198,
 time:0x4f8cd0,lastTime:0x4f42b8,refresh:0x5364e8,motion:0x4da174,pose:0x4f8ccc,
 manualSpin1:0x4f4520,manualSpin2:0x4f4524,soundDisabled:0x536484,module:0x5359c8,
 courseLength:0x525a9c,span:0x523598,longCourse:0x53527c,twoPlayer:0x4f452c,
 finalLeg:0x4da1e4,startTime:0x4da170,depthLimit:0x4da1fc,width:0x4fe624,
 windDirection:0x5362d4,windStrength:0x522ad0,
 ax:0x536410,ay:0x536414,bx:0x4fe094,by:0x4fe2a0,cx:0x5229d4,cy:0x522ac8,
 dx:0x522acc,dy:0x522ae0,ex:0x5229c8,ey:0x522ac4,leftX:0x4f4a68,leftY:0x4f6d34,
 rightX:0x523248,rightY:0x52359c,spawnX:0x4f6d38,spawnY:0x4f7f88};
const boatFields={tack:0x522ff0,heading:0x535740,direction:0x522b90,apparentDirection:0x535890,
 wind:0x4fb380,angle:0x4fecc8,speed:0x4fdfe8,heel:0x4fc2c0,trim:0x4fe778,
 jib:0x4f7ee0,depower:0x500380,actualDepower:0x512278,crew:0x535e40,
 leg:0x4f8538,finish:0x4fe638,penaltyTime:0x535620,penaltyCode:0x5116e0,
 lastTurn:0x4f4350,turn:0x4f7090,spin:0x5350d8,spinDelay:0x4f4478,spinHold:0x4fe6d0,
 targetBearing:0x535178,scale:0x4fc3e0,rate:0x4fc230,overrideSpeed:0x4faef0,
 preTackSpeed:0x535ed8,boardSlow:0x523938,spinMode:0x4f42c0,
 interference:0x4fe8a8,blocked:0x4f4208,targetX:0x4f4d78,targetY:0x4fc350,
 finishX:0x4fb548,finishY:0x522af0};
const defaults={boats:2,humans:1,course:1,stage:5,skill:10,time:100,lastTime:99,refresh:1,motion:5,pose:3,
 manualSpin1:0,manualSpin2:0,soundDisabled:0,module:0x12340000,courseLength:1000,span:125,
 longCourse:0,twoPlayer:0,finalLeg:8,startTime:-90,depthLimit:8,width:900,windDirection:0,windStrength:12,
 ax:-125,ay:1000,bx:125,by:1000,cx:0,cy:-1000,dx:-1000,dy:-1000,ex:0,ey:1500,
 leftX:-90,leftY:1500,rightX:90,rightY:1500,spawnX:50,spawnY:20};
const boatDefaults={tack:1,heading:45,direction:0,apparentDirection:90,wind:12,angle:45,speed:40,heel:10,
 trim:2,jib:2,depower:-1,actualDepower:0,crew:5,leg:3,finish:0,penaltyTime:-500,penaltyCode:0,
 lastTurn:-100,turn:0,spin:0,spinDelay:0,spinHold:0,targetBearing:120,scale:89,rate:89,
 overrideSpeed:-1,preTackSpeed:40,boardSlow:0,spinMode:2,interference:0,blocked:0,targetX:50,targetY:1000,
 finishX:0,finishY:1500};
const differences=after=>{
 const runs=[];let start=-1,last=-1;
 for(let index=0;index<after.length;index++)if(after[index]!==baseline[index]){
  if(start<0){start=index;last=index;}else if(index-last<=16)last=index;
  else{runs.push({address:base+start,bytes:Buffer.from(after.subarray(start,last+1)).toString('hex')});start=index;last=index;}
 }
 if(start>=0)runs.push({address:base+start,bytes:Buffer.from(after.subarray(start,last+1)).toString('hex')});
 return runs;
};
const optionInput=original.cases[0].inputs;
const prepare=(selector,boat,changes={},boatChanges={},otherChanges={},doubles={},group='all27-classes-complete-angle-sweep')=>{
 memory.writeBytes(base,baseline);
 for(const[field,value]of Object.entries({...optionInput,selector}))memory.writeI32(original.integerInputs[field],value);
 withX87ControlWord(0x027f,()=>initializeBoatOptions(memory));
 for(const[field,value]of Object.entries({...defaults,...changes}))memory.writeI32(globalFields[field],value);
 for(let b=1;b<=2;b++){
  resetBoat(memory,b);
  for(const[field,value]of Object.entries({...boatDefaults,...(b===boat?boatChanges:otherChanges)}))memory.writeI32(boatFields[field]+b*4,value);
  memory.writeF64(0x4f6af8+b*8,b===boat?100.75:500.25);
  memory.writeF64(0x4f6c10+b*8,b===boat?200.25:550.75);
  memory.writeF64(0x4fe180+b*8,doubles.speed??40.5);
  memory.writeF64(0x4ffcb8+b*8,doubles.depth??1000.5);
 }
 if(doubles.position){memory.writeF64(0x4f6af8+boat*8,doubles.position[0]);memory.writeF64(0x4f6c10+boat*8,doubles.position[1]);}
 if(doubles.otherPosition){const other=3-boat;memory.writeF64(0x4f6af8+other*8,doubles.otherPosition[0]);memory.writeF64(0x4f6c10+other*8,doubles.otherPosition[1]);}
 memory.writeF64(0x523378,doubles.step??1);memory.writeF64(0x5359f0,doubles.raceTime??100.5);memory.writeF64(0x523d48,1);
 cases.push({group,arguments:[boat],seed:(0x20100000+cases.length*37)>>>0,patches:differences(memory.readBytes(base,baseline.length)),
  preparation:{selector,boat,changes,boatChanges,otherChanges,doubles,source:'Complete source-derived boat options/reset, with explicit finite game state; no captured output substitution.'}});
};
for(let selector=1;selector<=27;selector++)for(let angle=0;angle<=180;angle++)
 prepare(selector,angle%2+1,{}, {heading:angle,angle,wind:angle%3===0?8:angle%3===1?12:16});
for(let selector=1;selector<=27;selector++)for(const trim of[0,1,2,3,4])for(const depower of[-1,0,30,81,100])
 prepare(selector,1,{manualSpin1:trim%2},{heading:55,angle:55,trim,depower,jib:trim,wind:16},{},{step:0.25},'trim-jib-depower-and-spinnaker');
for(let selector=1;selector<=27;selector++)for(const heel of[-5,0,5,9,10,19,45,70,90])
 prepare(selector,2,{}, {heading:110,angle:110,heel,wind:20},{},{step:0.5},'heel-and-human-versus-ai-spills');
for(const time of[-180,-151,-150,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,19,20,30,31,50,51,100])for(const selector of[1,6,12,17,25,26,27])
 for(const boat of[1,2])prepare(selector,boat,{time,lastTime:time-1},{lastTurn:0,angle:45,heading:45,penaltyTime:0,boardSlow:1},{},{raceTime:time+0.5},'prestart-penalty-time-and-tack-recovery');
for(const depth of[0,1,2,3,4,5,6,8,10])for(const selector of[1,6,12,17,25,26,27])for(const boat of[1,2])
 prepare(selector,boat,{}, {heading:160,angle:160},{},{depth},'grounding-thresholds-and-depth-state');
for(const refresh of[-2,-1,0,1,2,3])for(const selector of[1,12,27])
 prepare(selector,1,{refresh},{heading:105,angle:105},{},{},'original-odd-refresh-gate');
for(const finish of[1,2])for(const heading of[0,45,160])for(const boat of[1,2])
 prepare(12,boat,{}, {finish,heading,angle:heading},{},{position:[0,1500]},'finish-heading-overwrite-and-grounding-order');
for(const distance of[0,1,5,7,19,29,39,79])for(const tack of[-1,1])for(const boat of[1,2])
 prepare(12,boat,{time:100,manualSpin1:1},{tack,heading:45,angle:45},{tack:1,heading:50,angle:50},{otherPosition:[100.75+distance,200.25]},'connected-interference-collision-and-shift');
for(let selector=1;selector<=27;selector++)for(const wind of[1,7,9,10,11,13,14,17])for(const boat of[1,2])
 prepare(selector,boat,{windStrength:wind},{wind,heading:105,angle:105},{},{step:1/60},'wind-calibration-and-coefficient-boundaries');
for(let selector=1;selector<=27;selector++)for(const angle of[30,45,60,105,170])for(const depower of[-1,80])
 prepare(selector,2,{humans:2,manualSpin2:angle>104?1:0},{heading:angle,angle,depower,trim:3,jib:1,wind:13},{},{speed:31.125,step:0.02},'second-human-original-controls-and-continuous-heel');
const manifest={source:original.source,sourceSha256:original.sourceSha256,x87ControlWord:'0x027f',mutableBlock:original.mutableBlock,
 integerInputs:{},integerOutputs:{},doubleInputs:{},doubleOutputs:{},routine:{name:'updateBoatDynamics',address:BOAT_DYNAMICS_ADDRESS,argumentTypes:['I32'],returnType:'void'},
 scope:'Complete2010 boat dynamics across27 valid boat selectors, all181 sailing angles, trim/heel/grounding/turn/start/finish/encounter branches with exact original children, PC53 and native ordered sound capture.',cases};
await writeFile(new URL('../analysis/updateBoatDynamics-capture-inputs.json',import.meta.url),JSON.stringify(manifest,null,2)+'\n');
console.log(`${cases.length} complete boat-dynamics input cases`);
