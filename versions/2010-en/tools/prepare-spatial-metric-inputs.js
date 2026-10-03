import { readFile,writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { SPATIAL_METRIC_ROUTINES,ATTENUATION_DISTANCE_ADDRESS } from '../src/engine/spatial-metrics.js';
import { VENUE_POINT_DEFINITIONS as definitions } from '../src/engine/venue-definitions.js';

const routines={...SPATIAL_METRIC_ROUTINES,sampleAttenuationDistance:ATTENUATION_DISTANCE_ADDRESS};
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const sourceSha256=createHash('sha256').update(source).digest('hex');
const integerInputs={venue:0x4da1f8,weather:0x4f69b8,shorelineVariant:0x50040c,shore:0x5230dc,
  centerX:0x535bc8,centerY:0x4f3858,radius:0x4f4b00,island:0x4f8b78,reversal:0x4f4510,
  metricMode:0x5364b0,pointCount:0x522f08,extraPointCount:0x511374,backgroundPointCount:0x535e3c,
  markCount:0x535498,harbor:0x4fb5d4,scanLimit:0x4da218,scanHeading:0x5362d4};
const doubleInputs={xAspect:0x4fba00,yAspect:0x535558};
const defaults={venue:0,weather:0,shorelineVariant:0,shore:2,centerX:0,centerY:0,radius:3000,
  island:0,reversal:0,metricMode:0,pointCount:3,extraPointCount:0,backgroundPointCount:0,markCount:3,harbor:0,scanLimit:7777,scanHeading:0};
const patchI32=(address,values)=>{const b=Buffer.alloc(values.length*4);values.forEach((v,i)=>b.writeInt32LE(v,i*4));return{address,bytes:b.toString('hex')};};
const patchF64=(address,values)=>{const b=Buffer.alloc(values.length*8);values.forEach((v,i)=>b.writeDoubleLE(v,i*8));return{address,bytes:b.toString('hex')};};
const geometry=[patchI32(0x4fb6b8,Array.from({length:182},(_,i)=>(i-18)*250)),
  patchI32(0x4fbc38,Array.from({length:182},(_,i)=>900-(i%7)*31)),
  patchF64(0x4ffdd8,Array.from({length:181},(_,i)=>1500+(i%29)*13))];
const common={source:'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe',sourceSha256,
  x87ControlWord:'0x027f',mutableBlock:{address:0x4da000,size:0x60588},integerInputs,
  integerOutputs:{},doubleInputs,doubleOutputs:{bearingScratch:0x4f7f80},
  scope:'Original complete metric/projection functions. Shoreline/radial arrays are explicit synthetic input geometry; named venue definitions are source literals independently verified by1312nativecalls. No final-state lookup.'};
const groups=Object.fromEntries(Object.keys(routines).map(name=>[name,[]]));
const add=(name,args,changes={},extraPatches=[],group='normal-domain')=>groups[name].push({group,arguments:args,
  inputs:{...defaults,...changes},doubleInputs:{xAspect:0.75,yAspect:1.25},seed:1,patches:[...geometry,...extraPatches]});
for(const heading of[-360,-1,0,1,44,89,90,179,180,269,270,359,360,361,720])
  for(const distance of[-2000,-1,0,1,100,3000])add('projectPoint',[123,-456,distance,heading]);
for(const x of[-6000,-4001,-4000,-3999,-3751,-3750,-3749,-1,0,125,3999])
  for(const y of[-2000,0,869,870,900,2000])for(const shore of[1,2,3,4])add('sampleShorelineMetric',[x,y],{shore});
let state=0x2010;const random=limit=>{state=(Math.imul(state,1664525)+1013904223)>>>0;return state%limit;};
for(let i=0;i<256;i++)add('sampleRadialMetric',[random(20001)-10000,random(20001)-10000]);
const coordinates=[[0,0],[1,-1],[-500,700],[1499,0],[1500,0],[3000,0],[-3000,1500],[6500,2200],[-1600,-300],[2100,-1800],[-5000,3000]];
for(const weather of[0,1,2,3,4,5,6,7])for(const shorelineVariant of[0,1])for(const island of[0,1])
  for(const reversal of[0,1])for(const[x,y]of coordinates.filter(pair=>pair[0]<=3999))
    add('sampleSpatialMetric',[x,y,0],{weather,shorelineVariant,island,reversal});
for(const[venue,definition]of Object.entries(definitions)){
  const points=Object.keys(definition.points).map(Number),count=Math.max(...points);
  const patches=Object.values(definition.points).flatMap(point=>point.writes.map(([address,value])=>{
    const bytes=Buffer.alloc(4);bytes.writeUInt32LE(value);return{address,bytes:bytes.toString('hex')};
  }));
  for(const includeBackground of[0,1])for(const mode of[0,1,2])for(const[x,y]of coordinates){
    const changes={venue:Number(venue),pointCount:count-2,markCount:Math.max(1,count-3),extraPointCount:2,
      backgroundPointCount:0,metricMode:includeBackground,harbor:Number(venue)===4?1:0};
    add('sampleVenueMetric',[0,x,y,mode,includeBackground],changes,patches,'source-literal-venue-geometry');
    if(mode===0)add('sampleSpatialMetric',[x,y,0],changes,patches,'connected-named-venue-dispatch');
  }
}
for(const x of[-1001,-1000,-999,0,999,1000,1001])for(const y of[-1001,-1000,-999,0,999,1000,1001]){
  add('pointInXStrip',[-1000,1000,-1000,1000,-800,800,x,y]);
  add('pointInYStrip',[-1000,1000,-800,-1000,800,1000,x,y]);
}
for(const mode of[0,1])for(const heading of[-720,-1,0,90,180,270,360,721])
  for(const weather of[0,3])for(const[x,y]of[[0,0],[1500,0],[3000,0],[-3000,1500]])
    add('sampleAttenuationDistance',[mode,x,y,1],{weather,scanHeading:heading},[patchI32(0x522d34,[heading])],'basic-probe-boundaries');
for(const[venue,definition]of Object.entries(definitions)){
  const count=Math.max(...Object.keys(definition.points).map(Number));
  const patches=Object.values(definition.points).flatMap(point=>point.writes.map(([address,value])=>{
    const bytes=Buffer.alloc(4);bytes.writeUInt32LE(value);return{address,bytes:bytes.toString('hex')};
  }));
  for(const mode of[0,1])for(const heading of[0,90,180,270])for(const[x,y]of[[0,0],[-500,700],[2100,-1800]])
    add('sampleAttenuationDistance',[mode,x,y,1],{venue:Number(venue),pointCount:count-2,markCount:Math.max(1,count-3),
      extraPointCount:2,harbor:Number(venue)===4?1:0,scanHeading:heading},[...patches,patchI32(0x522d34,[heading])],'named-venue-probe-boundaries');
}
for(const[name,cases]of Object.entries(groups)){
  if(process.argv[2]&&process.argv[2]!==name)continue;
  const returns=name==='projectPoint'?'void':name.startsWith('pointIn')||name==='sampleAttenuationDistance'?'I32':'float10';
  const argumentsCount=name==='projectPoint'||name==='sampleAttenuationDistance'?4:name.startsWith('pointIn')?8:name==='sampleVenueMetric'?5:name==='sampleSpatialMetric'?3:2;
  const manifest={...common,routine:{name,address:routines[name],argumentTypes:Array(argumentsCount).fill('I32'),returnType:returns},cases};
  await writeFile(new URL(`../analysis/${name}-capture-inputs.json`,import.meta.url),JSON.stringify(manifest,null,2)+'\n');
  console.log(`${name}: ${cases.length} complete native input cases`);
}
