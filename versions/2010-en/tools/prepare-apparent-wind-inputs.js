import { readFile,writeFile } from 'node:fs/promises';
import { APPARENT_WIND_ADDRESSES as a } from '../src/engine/apparent-wind.js';
const prior=JSON.parse(await readFile(new URL('../analysis/wind-bearing-capture-inputs.json',import.meta.url),'utf8'));
const cases=[];
const add=(speed,boat,angle,wind,tack=1,heading=105,group='apparent-wind-domain')=>{
 const inputs={};for(const field of['angle','trueWind','heading','tack','apparentSpeed','apparentAngle','apparentDirection'])inputs[field]=
  ({angle,trueWind:wind,heading,tack,apparentSpeed:777,apparentAngle:123,apparentDirection:999})[field];
 cases.push({group,arguments:[speed,boat],inputs,seed:1});
};
for(let angle=0;angle<=180;angle++)for(const wind of[7,8,9,10,15])for(const speed of[0,10,100])for(const tack of[-1,1])add(speed,1,angle,wind,tack);
for(const angle of[-720,-360,-1,0,1,89,90,179,180,181,269,270,359,360,361,720])
 for(const wind of[-1,0,1,6,20])for(const speed of[-100,1,99])add(speed,1,angle,wind,1,359,'clamp-and-branch-boundaries');
const common={source:prior.source,sourceSha256:prior.sourceSha256,x87ControlWord:'0x027f',mutableBlock:prior.mutableBlock,
 integerInputs:Object.fromEntries(Object.entries(a).filter(([field])=>field!=='routine').map(([field,address])=>[field,address+4])),
 integerOutputs:Object.fromEntries(['apparentSpeed','apparentAngle','apparentDirection'].map(field=>[field,a[field]+4])),
 routine:{name:'apparentWindExtended',address:a.routine,argumentTypes:['I32','I32'],returnType:'float10'},
 scope:'Complete2010 apparent-wind43bb70, including stored force calibration and direction side effects; native integer-angle trig and PC53 arithmetic, exact vendor FPATAN quantized fields checked.',cases};
await writeFile(new URL('../analysis/apparent-wind-capture-inputs.json',import.meta.url),JSON.stringify(common,null,2)+'\n');
console.log(`${cases.length} complete apparent-wind input cases`);
