import {readFile,writeFile}from'node:fs/promises';
import {createHash}from'node:crypto';
import {loadPE32}from'../../../src/runtime/memory.js';
const edition=new URL('../',import.meta.url);
const hash=bytes=>createHash('sha256').update(bytes).digest('hex');
const original=await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe',edition));
const existingBytes=await readFile(new URL('analysis/initialized-screens-capture-inputs.json',edition));
const existing=JSON.parse(existingBytes);
const referenceBytes=await readFile(new URL('tests/fixtures/original-boat-options.json',edition));
const reference=JSON.parse(referenceBytes);
if(hash(original)!==existing.sourceSha256||reference.sourceSha256!==existing.sourceSha256)throw new Error('Original source hash differs');
const input=existing.cases.find(row=>row.phase==='boat-options'&&row.profile==='selector12-initialized-screens');
if(!input||input.preparation.customCourseEditor!==0)throw new Error('Verified normal initialization recipe is unavailable');
const memory=loadPE32(original),base=reference.mutableBlock.address,baseline=Buffer.from(reference.mutableBaseline,'hex');
memory.writeBytes(base,baseline);
for(const patch of input.patches)memory.writeBytes(patch.address,Buffer.from(patch.bytes,'hex'));
// Legitimate pre-initialization Round-the-Island selection; let original
// configuration determine all island/shore/class/subtype settings itself.
memory.writeI32(0x4da19c,7);
const bytes=memory.readBytes(base,baseline.length),patches=[];let first=-1,last=-1;
for(let i=0;i<bytes.length;i++)if(bytes[i]!==baseline[i]){if(first<0)first=last=i;else if(i-last<=16)last=i;else{patches.push({address:base+first,bytes:Buffer.from(bytes.subarray(first,last+1)).toString('hex')});first=last=i;}}
if(first>=0)patches.push({address:base+first,bytes:Buffer.from(bytes.subarray(first,last+1)).toString('hex')});
const profile={name:'selector12-course7-initialized-island-scene',selector:12,course:7,venue:0,boats:12,humans:1,stage:5,width:1024,height:768,bitsPixel:24};
const scene={name:'drawScene',address:0x405320,argumentTypes:['CDC','I32','I32','I32','I32','I32'],returnType:'void'};
const manifest={...existing,routine:scene,profiles:[profile],cases:[
 {...input,profile:profile.name,patches,preparation:{...input.preparation,requestedCourse:7,scope:'Verified selector12 initialized-screen input; pre-call course selection changed to legitimate Round-the-Island7. No initialized output, names, island flags or retained stack values are supplied.'}},
 {profile:profile.name,phase:'race-initialization',routine:{name:'initializeRace',address:0x41be70,argumentTypes:[],returnType:'void'},continue:true,arguments:[]},
 {profile:profile.name,phase:'drawScene',routine:scene,continue:true,arguments:[0,0,0,1024,361,1],host:{menuHeight:20,cursor:[64,72],tickStart:10000,pixels:Array(1024).fill(0xffffff)}}
 ],integerOutputs:{...existing.integerOutputs,boatClass:0x4da190,raw4da188:0x4da188,displaySetting4da174:0x4da174,island:0x4f8b78,flag4fb5d4:0x4fb5d4,shorelineVariant:0x50040c,shorelineMode:0x4f7ed8},inputEvidence:{...existing.inputEvidence,initializedScreensManifest:'analysis/initialized-screens-capture-inputs.json',initializedScreensManifestSha256:hash(existingBytes),baselineFixtureSha256:hash(referenceBytes),scope:'Fresh bounded original420c00→41be70→405320 island scene observation with preserved original code/data/CStrings/RNG, original constructor90 logical GDI handles and positive1024×768 paint calibration. Declared white GetPixel host bindings are observational inputs, not a raster identity claim. No retained local or stack values are invented or injected.'}};
await writeFile(new URL('analysis/initialized-island-scene-capture-inputs.json',edition),JSON.stringify(manifest,null,2)+'\n');
console.log('Prepared three genuine original calls for selector12/course7, without stack injections');
