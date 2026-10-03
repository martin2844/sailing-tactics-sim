import { readFile,writeFile } from 'node:fs/promises';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { updateSpeedDivisor } from '../src/engine/application.js';
const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const initial=await json('../analysis/initializeRace-capture-inputs.json');
const memory=loadPE32(await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url)));
const initialization={name:'initializeRace',address:0x41be70,argumentTypes:[],returnType:'void'};
const integration={name:'integratePositions',address:0x43cf60,argumentTypes:[],returnType:'void'};
const dynamics={name:'updateBoatDynamics',address:0x43a030,argumentTypes:['I32'],returnType:'void'};
const all=process.argv.includes('--all');
const remaining=process.argv.includes('--remaining'),physics=process.argv.includes('--physics');
const modes=process.argv.includes('--modes');
const patchI=(address,value)=>{const bytes=Buffer.alloc(4);bytes.writeInt32LE(value);return{address,bytes:bytes.toString('hex')};};
const requests=[
 {selector:1,venue:0,stage:5},{selector:12,venue:0,stage:5},{selector:17,venue:0,stage:5},
 {selector:25,venue:0,stage:5},{selector:26,venue:0,stage:5},{selector:27,venue:0,stage:5},
 {venue:5,stage:1},{venue:9,stage:5},{venue:100,stage:10},{venue:999,stage:5},
 {course:8,humans:2},{venue:105,stage:1},
];
const same=(candidate,request)=>Object.entries(request).every(([key,value])=>candidate.preparation[key]===value);
const representative=requests.map(request=>{
 const row=initial.cases.find(candidate=>same(candidate,request));
 if(!row)throw new Error('Prepared legitimate initialization profile missing:'+JSON.stringify(request));
 return row;
});
const modeProfiles=[];
if(modes){
 const template=initial.cases.find(row=>same(row,{selector:12,venue:0,stage:5}));
 for(const course of[5,6,11,12,13,14])for(const stage of[1,2,5])modeProfiles.push({...template,
  preparation:{...template.preparation,course,stage,boats:2},
  patches:[...template.patches,patchI(0x4da19c,course),patchI(0x4da1d8,stage),patchI(0x4da194,2)]});
 for(const tide of[0,1])for(const stage of[1,2,5])modeProfiles.push({...template,
  preparation:{...template.preparation,tide,stage,boats:2},
  patches:[...template.patches,patchI(0x4da158,tide),patchI(0x4da1d8,stage),patchI(0x4da194,2)]});
}
const rows=modes?modeProfiles:remaining?initial.cases.filter(row=>!representative.includes(row)):all?initial.cases:representative;
const groups=remaining?Array.from({length:Math.ceil(rows.length/13)},(_,index)=>rows.slice(index*13,(index+1)*13)):[rows];
for(const[groupIndex,profiles]of groups.entries()){
 const cases=[],chains=[];
 for(const[index,row]of profiles.entries()){
 const originalIndex=initial.cases.indexOf(row),level=originalIndex>=0&&originalIndex%3===0?7:15;
 memory.writeI32(0x4da174,level);updateSpeedDivisor(memory);
 const divisor=memory.readI32(0x4da178);
 const start=cases.length,steps=remaining||physics||modes?50:100;
 cases.push({...row,routine:initialization,
  patches:[...(row.patches??[]),patchI(0x4da174,level),patchI(0x4da178,divisor),patchI(0x4da17c,divisor)],
  chain:index,step:-1,group:'actual-original-initialization-before-retained-integration'});
 let callCount=1;
 for(let step=0;step<steps;step++){
  const phase=physics||index%2===0?[patchI(0x5364e8,step%60+1)]:[];
  if(physics)for(let boat=1;boat<=row.preparation.boats;boat++){
   cases.push({routine:dynamics,arguments:[boat],continue:true,chain:index,step,group:'actual-retained-dynamics',patches:boat===1?phase:[]});callCount++;
  }
  cases.push({routine:integration,arguments:[],continue:true,chain:index,step,group:'retained-initialized-integration',patches:physics?[]:phase});callCount++;
 }
 chains.push({index,start,steps,callCount,originalProfileIndex:originalIndex,profile:row.preparation,motionLevel:level,speedDivisor:divisor,
  cadence:physics||index%2===0?'Explicit original paint-counter input1..60; only that field is supplied between calls.':'No supplied state changes between integration calls.'});
}
const manifest={source:initial.source,sourceSha256:initial.sourceSha256,x87ControlWord:'0x027f',mutableBlock:initial.mutableBlock,
 integerInputs:{},integerOutputs:{},doubleInputs:{},doubleOutputs:{},routine:integration,chains,cases,
 scope:`Actual unchanged native initializeRace followed by${remaining||physics||modes?50:100} retained original integratePositions calls per profile${physics?', each preceded by the complete actual boat-dynamics routine for every initialized boat':''}. Full mutable state, actual CString names, RNG and ordered sounds remain live across continuation calls; no captured output substitution. Optional explicit paint-counter cadence is identified per chain. Speed divisor and saved divisor are correctly prepared as I32 from the complete original speed mapping.${modes?' Additional legitimate menu courses5/6/11/12/13/14, start modes1/2/5 and current enabled/disabled settings are explicit pre-initialization inputs.':''}`};
const name=modes?'retained-integration-modes':physics?'retained-dynamics-integration':remaining?`retained-integration-expanded-${groupIndex}`:all?'retained-integration-all':'retained-integration';
await writeFile(new URL(`../analysis/${name}-capture-inputs.json`,import.meta.url),JSON.stringify(manifest,null,2)+'\n');
console.log(`${name}: ${chains.length} initialized chains, ${cases.length} original calls (${chains.reduce((sum,chain)=>sum+chain.steps,0)} retained integration steps)`);
}
