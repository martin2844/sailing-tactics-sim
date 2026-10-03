import { readFile,writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { WIND_ADDRESSES as a } from '../src/engine/wind.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const sourceSha256=createHash('sha256').update(source).digest('hex');
const constants=['degreeFactor','positiveTurnThreshold','positiveRevolution','negativeTurnThreshold','negativeRevolution','smoothingRate','bearingScale','bearingOffset'];
const doubles=['driftClock','smoothDirection','dt','bearingRadians'];
const excluded=new Set(['routine','schedule','bearing','cosine','sine','randomTable',...doubles,...constants]);
const integerInputs=Object.fromEntries(Object.entries(a).filter(([field])=>!excluded.has(field)));
const outputFields=['thermal','thermalWind','thermalDriftRate','strength','peakStrength','drift','condition1','condition2',
  'meanDirection','initialDirection','direction','tide','nextTime','target','range','period','targetIndex','timeIndex'];
const integerOutputs=Object.fromEntries(outputFields.map(field=>[field,a[field]]));
const doubleInputs=Object.fromEntries(doubles.map(field=>[field,a[field]]));
const doubleOutputs={smoothDirection:a.smoothDirection,bearingRadians:a.bearingRadians};
const values=Object.fromEntries(Object.keys(integerInputs).map((field,index)=>[field,0x13570000+index]));
Object.assign(values,{hour:14,dailyMinimum:5,dailyMaximum:20,thermalGain:10,weather:0,shore:1,reversal:0,
  venue:0,forceVenueDirection:0,customThermalDirection:280,thermalReversal:0,baseDirection:315,baseStrength:10,
  course:1,driftRate:2,forceCondition:0,customShoreDirection:90,customShoreStrength:4,customShoreMode:0,
  mode:0,time:100,resetTime:0,customLongShifts:0,nextTime:99,target:300,range:40,period:85,
  targetIndex:1,timeIndex:300,direction:280,condition1:1,condition2:1});
const doubleValues={driftClock:100,smoothDirection:280,dt:0.1,bearingRadians:-3};
const randomTable=Buffer.alloc(301*4);
for(let index=0;index<=300;index++)randomTable.writeInt32LE((index*37+11)%101,index*4);
const patches=[{address:a.randomTable,bytes:randomTable.toString('hex')}];
const cases=[];
const add=(group,changes={},doubleChanges={})=>cases.push({group,inputs:{...values,...changes},doubleInputs:{...doubleValues,...doubleChanges},patches,seed:(0x20102002+cases.length)>>>0});
const venues=[-1,0,1,2,3,4,5,6,7,8,9,10,11,12,100,101,102,103,104,105,106,999];
const directionEdges=[0,34,35,36,44,45,46,69,70,71,89,90,91,109,110,111,129,130,131,189,190,191,
  209,210,211,219,220,221,229,230,231,249,250,251,259,260,261,289,290,291,299,300,301,349,350,351,359,360];
for(const venue of venues)for(const direction of directionEdges)add('venue-condition-boundaries',{venue,direction});
for(const venue of venues)for(const hour of [0,8,9,10,11,16,17,18,22,23,24])add('thermal-hour-boundaries',{venue,hour});
for(const venue of venues)for(const time of [-1,0,9,10,11,99,100,101])add('reset-and-schedule-boundaries',{venue,time});
for(const weather of [-1,0,1,2,3,4,5,6])for(const hour of [9,10,11,17,18,22,23])add('weather-boundaries',{weather,hour});
for(const venue of venues)for(const course of [1,8])for(const thermalReversal of [-1,0,1])add('drift-scale-and-reversal',{venue,course,thermalReversal});
for(const venue of venues)for(const mode of [-1,0,1,2])add('mode-preservation',{venue,mode});
for(const customShoreStrength of [0,6,7])for(const customShoreMode of [0,1,2])for(const customLongShifts of [0,1])add('custom-venue',{venue:999,customShoreStrength,customShoreMode,customLongShifts});
for(const targetIndex of [1,299,300])for(const timeIndex of [1,299,300])add('table-index-rollover',{targetIndex,timeIndex});
for(const target of [-181,-180,-91,-90,-89,0,89,90,91,180,181,359,360,361])
  add('smoothing-boundaries',{target,nextTime:1000},{smoothDirection:0});
add('FST-retains-register',{target:0,nextTime:1000},{smoothDirection:1,dt:1e-15});
let state=0x2010;
const random=limit=>{state=(Math.imul(state,1664525)+1013904223)>>>0;return state%limit;};
for(let index=0;index<256;index++)add('mixed-inputs',{
  hour:random(25),dailyMinimum:random(10),dailyMaximum:10+random(20),thermalGain:random(20),weather:random(7),
  shore:random(4),reversal:random(2),venue:venues[random(venues.length)],forceVenueDirection:random(2),
  thermalReversal:random(3)-1,baseDirection:random(720)-360,baseStrength:random(25),course:random(10),driftRate:random(21)-10,
  forceCondition:random(2),mode:random(3),time:random(500)-170,resetTime:random(200)-170,target:random(360),
  nextTime:random(500)-170,targetIndex:1+random(300),timeIndex:1+random(300),tidePhaseHour:random(25),
  tideAmplitude:random(21)-10,direction:random(361),customThermalDirection:random(360),
},{driftClock:random(600)-300,smoothDirection:random(360),dt:random(100)/100});
// The two trig inputs stay inside the independently captured integer domain.
for(const row of cases){if(row.inputs.tidePhaseHour>24)row.inputs.tidePhaseHour=0;if(row.inputs.tideAmplitude>20)row.inputs.tideAmplitude=3;}
const common={source:'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe',sourceSha256,
  x87ControlWord:'0x027f',mutableBlock:{address:0x4da000,size:0x60588},integerInputs,integerOutputs,doubleInputs,doubleOutputs,
  inputEvidence:{randomTable:{address:a.randomTable,entries:301,note:'Explicit synthetic bounded random-table input; original indexed reads remain unchanged.'}},
  scope:'Prepared finite whole-routine calls; exact state, field bits, RNG ordering and residual EAX. Original FSIN inputs are captured multiples15/30; no whole-game claim.'};
await writeFile(new URL('../analysis/wind-capture-inputs.json',import.meta.url),JSON.stringify({...common,
  routine:{name:'updateGlobalWind',address:a.routine,argumentTypes:[],returnType:'void',residualEAX:true},cases},null,2)+'\n');

const scheduleCases=[];
const scheduleAdd=(group,args,changes={})=>scheduleCases.push({group,arguments:args,inputs:{...values,...changes},doubleInputs:doubleValues,patches,seed:1});
for(const targetIndex of [1,299,300])for(const timeIndex of [1,299,300])for(const range of [-0x80000000,-101,-1,0,1,100,0x7fffffff])
  scheduleAdd('index-and-product-boundaries',[90,range,100],{targetIndex,timeIndex,time:0x7fffffff});
for(let index=0;index<256;index++)scheduleAdd('mixed-full-I32',[random(0x100000000)|0,random(0x100000000)|0,random(0x100000000)|0],
  {targetIndex:1+random(300),timeIndex:1+random(300),time:random(0x100000000)|0});
await writeFile(new URL('../analysis/wind-schedule-capture-inputs.json',import.meta.url),JSON.stringify({...common,
  routine:{name:'scheduleWindShift',address:a.schedule,argumentTypes:['I32','I32','I32'],returnType:'I32'},cases:scheduleCases},null,2)+'\n');
const bearingCases=[];
const edges=[-0x80000000,-100,-1,0,1,100,0x7fffffff];
for(const y of edges)for(const x of edges)bearingCases.push({arguments:[y,x],inputs:{bearingRadians:-3},seed:1});
for(let index=0;index<1024;index++)bearingCases.push({arguments:[random(0x100000000)|0,random(0x100000000)|0],seed:1});
// bearingRadians is F64, so initialize it as an explicit double patch only.
for(const row of bearingCases){delete row.inputs;row.doubleInputs={bearingRadians:-3};}
await writeFile(new URL('../analysis/wind-bearing-capture-inputs.json',import.meta.url),JSON.stringify({...common,
  routine:{name:'bearingFromVector',address:a.bearing,argumentTypes:['I32','I32'],returnType:'I32'},cases:bearingCases},null,2)+'\n');
console.log(`${cases.length} complete wind, ${scheduleCases.length} scheduling, ${bearingCases.length} vector-bearing calls prepared.`);
