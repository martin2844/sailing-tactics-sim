import { readFile,writeFile } from 'node:fs/promises';
import { COURSE_ROUTINE } from '../src/engine/course.js';
import { VENUE_POINT_DEFINITIONS as definitions } from '../src/engine/venue-definitions.js';
const reference=JSON.parse(await readFile(new URL('../analysis/sampleAttenuationDistance-capture-inputs.json',import.meta.url),'utf8'));
const commonGeometry=reference.cases[0].patches.slice(0,3);
const integerInputs={...reference.integerInputs,boats:0x4da194,humans:0x4da140,skill:0x4da198,pose:0x4da188,
 course:0x4da19c,placement:0x4da1e8,stage:0x4da1d8,baseHeading:0x4f7f94,reverseCourse:0x53646c,
 longCourse:0x53527c,shortCourse:0x5364c8,smallBoat:0x5363cc,wideHull:0x5363b8,skiff:0x5363c4,
 board:0x5363bc,flyingScot:0x53652c,tideStrength:0x5359d0,shortened:0x4da168,
 dynamicCourse:0x5363f8,lengthReduction:0x53640c,nearFinish:0x536408,initialFinish:0x5364e0,
 courseStage:0x4fad38,customLength:0x4da238,markX:0x5229d4,markY:0x522ac8,
 leftX:0x4f4a68,leftY:0x4f6d34,rightX:0x523248,rightY:0x52359c};
const defaults={...reference.cases[0].inputs,boats:8,humans:1,skill:7,pose:6,course:1,placement:0,stage:5,
 baseHeading:105,reverseCourse:0,longCourse:0,shortCourse:0,smallBoat:0,wideHull:0,skiff:0,board:0,flyingScot:0,
 tideStrength:0,shortened:0,dynamicCourse:0,lengthReduction:0,nearFinish:0,initialFinish:0,courseStage:3,
 customLength:2000,markX:1000,markY:-750,leftX:333,leftY:-777,rightX:-666,rightY:999};
const profiles=[{venue:0,inputs:{venue:0},patches:[]}];
for(const[venue,definition]of Object.entries(definitions)){
 const count=Math.max(...Object.keys(definition.points).map(Number));
 const patches=Object.values(definition.points).flatMap(point=>point.writes.map(([address,value])=>{
  const bytes=Buffer.alloc(4);bytes.writeUInt32LE(value);return{address,bytes:bytes.toString('hex')};
 }));
 profiles.push({venue:Number(venue),inputs:{venue:Number(venue),pointCount:count-2,markCount:Math.max(1,count-3),
  extraPointCount:2,harbor:Number(venue)===4?1:0},patches});
}
profiles.push({...profiles.find(p=>p.venue===4),venue:5,inputs:{...profiles.find(p=>p.venue===4).inputs,venue:5}});
const cases=[];
const add=(mode,changes={},profile=profiles[0],group='course-initialization')=>cases.push({group,arguments:[mode],
 inputs:{...defaults,...profile.inputs,...changes},doubleInputs:{xAspect:0.75,yAspect:1.25},seed:0x2010+cases.length,
 patches:[...commonGeometry,...profile.patches]});
for(const course of[1,2,3,4,5,6,7,8,9,10])for(const boats of[2,3,14,15,35])for(const mode of[1,2,3])for(const reverseCourse of[0,1])
 add(mode,{course,boats,reverseCourse},profiles[0],'basic-course-modes-count-and-reversal');
for(const profile of profiles.slice(1))for(const mode of[1,2,3])for(const boats of[2,15])for(const longCourse of[0,1])
 add(mode,{boats,longCourse},profile,'named-venue-course-lengths-and-mark-order');
for(const flag of['smallBoat','wideHull','skiff','board','flyingScot','island','shortCourse','shortened','lengthReduction','nearFinish'])
 for(const boats of[2,8,15,35])for(const course of[1,8,9,10])add(1,{boats,course,[flag]:1},profiles[0],'flag-specific-rounding-and-length');
for(const mode of[1,2,3])for(const pose of[1,2,6,7])for(const humans of[1,2])for(const initialFinish of[0,1])
 add(mode,{placement:1,boats:8,pose,humans,initialFinish,dynamicCourse:1},profiles[0],'per-boat-alternate-finish-targets');
for(const heading of[0,1,90,179,180,270,359,360])for(const skill of[8,9])for(const tideStrength of[7,8,14,15])
 add(1,{baseHeading:heading,skill,tideStrength},profiles[0],'native-heading-and-radius-thresholds');
for(const mode of[1,2,3])for(const courseStage of[3,4,5])for(const reverseCourse of[0,1])
 add(mode,{courseStage,reverseCourse},profiles.find(p=>p.venue===5),'special-venue-five-mark-overrides');
for(const customLength of[1500,2000,2500])for(const mode of[1,2,3])
 add(mode,{venue:999,customLength},profiles.find(p=>p.venue===1),'custom-course-length');
const manifest={...reference,integerInputs,integerOutputs:{},doubleOutputs:{},
 scope:'Complete original42dea0 course preparation, all original mark writes and boat target rows; source-literal venue geometry and explicit synthetic basic geometry; no captured state lookup.',
 routine:{name:'initializeCourse',address:COURSE_ROUTINE,argumentTypes:['I32'],returnType:'void'},cases};
await writeFile(new URL('../analysis/initializeCourse-capture-inputs.json',import.meta.url),JSON.stringify(manifest,null,2)+'\n');
console.log(`initializeCourse: ${cases.length} complete native input cases`);
