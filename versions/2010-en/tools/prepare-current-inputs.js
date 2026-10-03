import { readFile,writeFile } from 'node:fs/promises';
import { CURRENT_ROUTINES } from '../src/engine/current.js';
import { ATTENUATION_DISTANCE_ADDRESS } from '../src/engine/spatial-metrics.js';
import { VENUE_POINT_DEFINITIONS as definitions } from '../src/engine/venue-definitions.js';
const reference=JSON.parse(await readFile(new URL('../analysis/sampleAttenuationDistance-capture-inputs.json',import.meta.url),'utf8'));
const commonGeometry=reference.cases[0].patches.slice(0,3);
const i32patch=(address,values)=>{const b=Buffer.alloc(values.length*4);values.forEach((v,i)=>b.writeInt32LE(v,i*4));return{address,bytes:b.toString('hex')};};
const f64patch=(address,values)=>{const b=Buffer.alloc(values.length*8);values.forEach((v,i)=>b.writeDoubleLE(v,i*8));return{address,bytes:b.toString('hex')};};
const integerInputs={...reference.integerInputs,course:0x4da19c,tideStrength:0x5359d0,time:0x4f42b8,lastTime:0x4f8cd0,
  phase:0x536404,hour:0x4f6d60,phaseHour:0x4ffdd0,baseDirection:0x523a54,forwardDirection:0x5229c4,
  reverseDirection:0x4fe160,shoreY:0x5229d0,currentEnabled:0x4da158,channel:0x536300,
  channelFirst:0x4fbac4,channelMiddle:0x4fbac8,channelLast:0x4fbacc,currentFlag:0x522fd8,currentRaw:0x5230d8,
  chosenDirection:0x536418,constant:0x536510,customDirection:0x4da26c,customAngle:0x4f4afc};
const doubleInputs={...reference.doubleInputs,drag0:0x4f4bc0,drag1:0x4f4bc8,drag2:0x4f4bd0,
  metric0:0x4ffcb8,metric1:0x4ffcc0,metric2:0x4ffcc8};
const defaults={...reference.cases[0].inputs,course:1,tideStrength:35,time:0,lastTime:20,phase:0,hour:12,phaseHour:18,
  baseDirection:105,forwardDirection:123,reverseDirection:234,shoreY:900,currentEnabled:1,channel:1,
  channelFirst:165,channelMiddle:75,channelLast:310,currentFlag:9,currentRaw:888,chosenDirection:789,scanLimit:2200,
  constant:0,customDirection:1,customAngle:140};
const doubleDefaults={xAspect:0.75,yAspect:1.25,drag0:0.25,drag1:-1.75,drag2:12.875,metric0:50,metric1:50,metric2:50};
const profiles=[{venue:0,inputs:{venue:0},patches:[]}];
for(const[venue,definition]of Object.entries(definitions)){
  const count=Math.max(...Object.keys(definition.points).map(Number));
  const patches=Object.values(definition.points).flatMap(point=>point.writes.map(([address,value])=>{
    const bytes=Buffer.alloc(4);bytes.writeUInt32LE(value);return{address,bytes:bytes.toString('hex')};
  }));
  profiles.push({venue:Number(venue),inputs:{venue:Number(venue),pointCount:count-2,markCount:Math.max(1,count-3),
    extraPointCount:2,harbor:Number(venue)===4?1:0},patches});
}
const groups={shorelineDirections:[],sampleCurrent:[],sampleVenueCurrent:[]};
const add=(name,args,changes={},doubles={},patches=[],group='connected-current-domain')=>groups[name].push({group,arguments:args,
  inputs:{...defaults,...changes},doubleInputs:{...doubleDefaults,...doubles},seed:0x2010,
  patches:[...commonGeometry,i32patch(0x522d30,[0,90,270]),i32patch(0x535a08,[11,23,37]),...patches]});
const coordinates=[[-7000,-4000],[-6000,5880],[-4001,1500],[-3000,-3401],[-2851,2000],[-2500,-1500],[-1801,-83],
  [-1001,0],[-601,-600],[-600,-400],[-599,-1],[-500,400],[-151,1400],[-150,1401],[-149,1600],[0,0],[1,1],
  [23,600],[300,1000],[1300,-2700],[1800,-300],[2260,0],[3000,-1399],[3600,0],[3770,200],
  [5000,3000],[6500,2200],[7500,-4200],[10000,3000],[14000,6500]];
for(const profile of profiles)for(const[x,y]of coordinates)add('shorelineDirections',[x,y],profile.inputs,{},profile.patches,'all-venue-retained-direction-regions');
for(const weather of[0,5])for(const island of[0,1])for(const y of[-1,0,1])add('shorelineDirections',[123,y],{weather,island});
for(const first of[-1.25,0,0.3,1.7])for(const second of[-0.8,0,0.5,2])for(const[x,y]of[[0,0],[1000,2000],[6000,-4000]])
  add('shorelineDirections',[x,y],{venue:999},{},[i32patch(0x53521c,[0]),i32patch(0x4f4b5c,[0]),
    i32patch(0x535230,[6000]),i32patch(0x4f4b70,[-4000]),f64patch(0x4fafb0,[first]),f64patch(0x4fafd8,[second])],'custom-two-center-distance-spills');
for(const weather of[0,1,2,3,4,5,6,7])for(const boat of[0,1,2])for(const[x,y]of coordinates)
  add('sampleCurrent',[x,y,boat],{weather}, {}, [],'all-basic-weather-channel-regions');
for(const metric of[0,10.999,11,29.999,30,49.999,50,69.999,70,89.999,90,299.999,300,300.999,301,320])
 for(const strength of[-90,-1,0,1,90])for(const boat of[1,2])
  add('sampleCurrent',[0,0,boat],{tideStrength:strength,course:2},{metric1:metric,metric2:metric},[],'cached-depth-truncation-and-strength');
for(const hour of[0,1,6,12,18,23])for(const phaseHour of[1,6,18,24])for(const phase of[0,1,6])
  add('sampleCurrent',[400,-300,1],{hour,phaseHour,phase},{metric1:30},[],'captured-angle-hour-boundaries');
for(const weather of[0,4,5,6,7])for(const channel of[1,2])for(const enabled of[0,1])for(const[x,y]of coordinates.slice(5,24))
  add('sampleCurrent',[x,y,1],{weather,channel,currentEnabled:enabled,island:1,shorelineVariant:1,course:4},
    {metric1:42},[],'island-shoreline-and-channel-feedback');
for(const profile of profiles.filter(p=>p.venue!==0))for(const hour of[12,23])for(const boat of[0,1,2])for(const[x,y]of coordinates){
  const unsupported=[10,12,103].includes(profile.venue);
  add('sampleVenueCurrent',[x,y,boat],{...profile.inputs,hour,tideStrength:unsupported?0:35},
    {metric1:42,metric2:90},profile.patches,'legitimate-venue-current-profiles');
}
for(const profile of profiles.filter(p=>[1,3,7,9,11,100,101,102,104,105,106].includes(p.venue)))
 for(const metric of[0,10.999,11,14.999,15,29.999,30,49.999,50,80.999,81,300])for(const constant of[0,1])
  add('sampleVenueCurrent',[-500,700,1],{...profile.inputs,constant},{metric1:metric},profile.patches,'depth-truncation-and-constant-current');
for(const[x,y]of coordinates)for(const hour of[12,23])
  add('sampleVenueCurrent',[x,y,1],{venue:4,harbor:1,hour},{metric1:42},profiles.find(p=>p.venue===4).patches,'harbor-current-zone-boundaries');
for(const first of[-1.25,0,0.3,1.7])for(const second of[-0.8,0,0.5,2])for(const direction of[0,1])
  add('sampleVenueCurrent',[400,-300,1],{venue:999,customDirection:direction,customAngle:140,pointCount:10,markCount:3,extraPointCount:0},
    {metric1:42},[...profiles.find(p=>p.venue===1).patches,f64patch(0x4fafb0,[first]),f64patch(0x4fafd8,[second])],'custom-direction-order-and-average');
for(const[name,cases]of Object.entries(groups)){
  if(process.argv[2]&&process.argv[2]!==name)continue;
  const manifest={...reference,integerInputs,integerOutputs:{...integerInputs},doubleInputs,
    doubleOutputs:{bearingScratch:0x4f7f80,drag0:0x4f4bc0,drag1:0x4f4bc8,drag2:0x4f4bd0},
    scope:'Complete original current and shoreline direction routines, with all named profiles, source-literal geometry and explicit synthetic basic geometry. No captured output lookup.',
    routine:{name,address:CURRENT_ROUTINES[name]??0x430260,argumentTypes:Array(name==='shorelineDirections'?2:3).fill('I32'),returnType:name==='shorelineDirections'?'void':'I32'},cases};
  await writeFile(new URL(`../analysis/${name}-capture-inputs.json`,import.meta.url),JSON.stringify(manifest,null,2)+'\n');
  console.log(`${name}: ${cases.length} complete native input cases`);
}
