import { readFile,writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
const edition=new URL('../',import.meta.url),root=new URL('../../',edition);
const sourceSha256='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
const sha=value=>createHash('sha256').update(value).digest('hex');
if(sha(await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe',edition)))!==sourceSha256)throw new Error('Original target differs');
const load=async name=>{const bytes=await readFile(new URL(`tests/fixtures/${name}.json`,root));return{data:JSON.parse(bytes),hash:sha(bytes)};};
const integerPatch=(address,value)=>{const raw=Buffer.alloc(4);raw.writeInt32LE(value|0);return{address,bytes:raw.toString('hex')};};
async function save(name,address,argumentTypes,returnType,cases,evidence){
 const output={source:'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe',sourceSha256,
 routine:{name,address,argumentTypes,returnType},integerInputs:{},integerOutputs:{},doubleInputs:{},doubleOutputs:{},
 inputEvidence:evidence,cases};
 await writeFile(new URL(`analysis/${name}-capture-inputs.json`,edition),JSON.stringify(output,null,2)+'\n');
 console.log(name,cases.length);
}
const old=await load('original-movement-helpers');
await save('distance',0x439e80,['I32','F64','F64'],'float10',old.data.distanceToBoat.cases.map((row,index)=>({
 label:`distance-${index}`,arguments:[row.boat,row.inputBits.x,row.inputBits.y],seed:2010,
 patches:[{address:0x4f6af8+row.boat*8,bytes:row.inputBits.positionX},{address:0x4f6c10+row.boat*8,bytes:row.inputBits.positionY}],
})),{fixture:'tests/fixtures/original-movement-helpers.json',sha256:old.hash,scope:'Finite inputs only; expected complete mutable state, RNG and extended return captured anew from2010.'});
const leaves=await load('original-encounter-leaves');
const globals={boatCount:0x4da194,humanBoatCount:0x4da140,startMode:0x4da1d8,time:0x4f8cd0,endpointAX:0x536410,endpointAY:0x536414,endpointBX:0x4fe094,endpointBY:0x4fe2a0};
const indexed={raceStage:0x4f8538,targetX:0x4f4d78,targetY:0x4fc350};
await save('reset-boat',0x431960,['I32'],'void',leaves.data.routines.resetBoat.cases.map((row,index)=>({
 label:`reset-${index}`,arguments:[row.boat],seed:2010,
 patches:[...Object.entries(globals).map(([key,address])=>integerPatch(address,row.globals[key])),
 ...Object.entries(row.boats).flatMap(([boat,fields])=>Object.entries(indexed).map(([key,address])=>integerPatch(address+Number(boat)*4,fields[key])))],
})),{fixture:'tests/fixtures/original-encounter-leaves.json',sha256:leaves.hash,scope:'Complete reset synthetic inputs; all expected outputs newly captured from2010.'});
const trailCases=[];
for(const count of [0,1,2,3,10,100,499,500])for(const boats of [0,1,2,10,27,30]){
 const patches=[integerPatch(0x4da194,boats),integerPatch(0x534ea8,count)];
 for(let boat=1;boat<=boats;boat++){
  for(const [address,value]of [[0x4fecc8,[0,89,90,120][boat%4]],[0x4fe8a8,boat%3-1],[0x4fe2b0,boat%3-1]])patches.push(integerPatch(address+boat*4,value));
  for(const [address,value]of [[0x4f6af8,boat*17.25-340],[0x4f6c10,boat*-37.5+1380]]){
   const raw=Buffer.alloc(8);raw.writeDoubleLE(value);patches.push({address:address+boat*8,bytes:raw.toString('hex')});
  }
 }
 trailCases.push({label:`trails-${boats}-${count}`,seed:2010,patches});
}
await save('trails',0x444760,[],'void',trailCases,{scope:'All original boat counts and history boundaries, exact full mutable bytes.'});
const waypointCases=[];
for(const boat of [0,1,2,10,27,30])for(const seed of [0,1,0x12345678]){
 let state=seed>>>0;const bytes=Buffer.alloc(20*0x130);for(let i=0;i<bytes.length;i++){state=(Math.imul(state,1664525)+1013904223)>>>0;bytes[i]=state>>>24;}
 waypointCases.push({label:`waypoint-${boat}-${seed}`,arguments:[boat],seed:2010,
 patches:[{address:0x50f818,bytes:bytes.toString('hex')},{address:0x523e80,bytes:bytes.toString('hex')},
 {address:0x4f1610+boat*8,bytes:'fffffffffffff87f'},{address:0x4f3868+boat*8,bytes:'0000000000000080'}]});
}
await save('waypoint-history',0x465e10,['I32'],'void',waypointCases,{scope:'Raw opaque double-word copy history, including NaN payloads and negative zero; no numeric reinterpretation.'});
