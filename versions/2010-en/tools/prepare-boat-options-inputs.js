import { readFile,writeFile,mkdir } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { BOAT_OPTION_ADDRESSES as addresses } from '../src/engine/boat-options.js';

const directory=new URL('../analysis/',import.meta.url);await mkdir(directory,{recursive:true});
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const sourceSha256=createHash('sha256').update(source).digest('hex');
const inputOnly=new Set(['routine','selector','lengthOverride','displacementOverride','sailAreaOverride','sailPercentOverride','timeFactorNumerator']);
const outputFields=Object.keys(addresses).filter(field=>!inputOnly.has(field));
const integerOutputs=outputFields.filter(field=>field!=='timeFactor');
const inputs={};
for(const [index,field]of integerOutputs.entries())inputs[field]=0x13579b00+index;
Object.assign(inputs,{selector:1,boatClass:6,lengthOverride:0,displacementOverride:0,sailAreaOverride:0,sailPercentOverride:0,
  length:25,rig:1,course:8,offshoreCourseFlag:77});
const cases=[];
const add=(group,changes)=>cases.push({group,inputs:{...inputs,...changes},seed:2002+cases.length});
for(let selector=1;selector<=27;selector++){
  for(const lengthOverride of [0,19,20,21,29,35,49,50,51])add('length-overrides',{selector,lengthOverride});
  for(const override of [-0x80000000,-1,0,7,8,9,10,11,12,0x7fffffff]){
    add('displacement-overrides',{selector,displacementOverride:override});
    add('sail-area-overrides',{selector,sailAreaOverride:override});
  }
  for(const sailPercentOverride of [-0x80000000,-1,0,1,80,100,0x7fffffff])add('sail-percent-overrides',{selector,sailPercentOverride});
  for(const course of [-0x80000000,0,1,7,8,9,0x7fffffff])add('course-retention',{selector,course});
  for(const rig of [-0x80000000,-1,0,1])add('rig-retention',{selector,rig});
}
for(const selector of [-0x80000000,-1,0,28,0x7fffffff]){
  for(const boatClass of [-1,0,1,2,3,4,5,6,7,8,9,10,11,0x7fffffff]){
    for(const length of [1,25,50,0x7fffffff])add('invalid-selector-retained-class',{selector,boatClass,length});
  }
}
let state=0x20102002;
const random=limit=>{state=(Math.imul(state,1664525)+1013904223)>>>0;return state%limit;};
for(let index=0;index<128;index++)add('mixed-inputs',{
  selector:random(30)-1,boatClass:random(15)-2,length:1+random(100),lengthOverride:random(80)-10,
  displacementOverride:random(20)-4,sailAreaOverride:random(20)-4,sailPercentOverride:random(160)-20,
  course:random(12),rig:random(5)-2,offshoreCourseFlag:random(4)-1,
});
const manifest={source:'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe',sourceSha256,
  routine:{name:'initializeBoatOptions',address:addresses.routine,argumentTypes:[],returnType:'void',residualEAX:true},
  x87ControlWord:'0x027f',mutableBlock:{address:0x4da000,size:0x60588},
  integerInputs:Object.fromEntries(Object.entries(addresses).filter(([field])=>field!=='routine'&&field!=='timeFactor'&&field!=='timeFactorNumerator')),
  integerOutputs:Object.fromEntries(integerOutputs.map(field=>[field,addresses[field]])),
  doubleOutputs:{timeFactor:addresses.timeFactor},doubleConstants:{timeFactorNumerator:{address:addresses.timeFactorNumerator,bits:'0000000000002e40'}},
  scope:'Prepared finite isolated complete routine; all27 selectors, invalid retained classes, exact integer bounds and positive retained lengths. No nonpositive-length masked nonfinite arithmetic claim.',
  cases};
await writeFile(new URL('boat-options-capture-inputs.json',directory),JSON.stringify(manifest,null,2)+'\n');
console.log(`${cases.length} prepared whole-routine calls; ${integerOutputs.length} I32 outputs and one binary64 output.`);
