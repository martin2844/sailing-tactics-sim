import { createHash } from 'node:crypto';
import { readFile,writeFile } from 'node:fs/promises';

const root=new URL('../',import.meta.url);
const path='analysis/retained-graphics-frames-capture-inputs.json';
const bytes=await readFile(new URL(path,root));
const originalInputs=JSON.parse(bytes);
if(originalInputs.sourceSha256!=='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'
  ||originalInputs.profiles.length!==1||originalInputs.inputEvidence.constructorObjectCount!==90)throw new Error('Original initializer/constructor input identity differs');
const patchI32=(address,value)=>{const bytes=Buffer.alloc(4);bytes.writeInt32LE(value);return {address,bytes:bytes.toString('hex')};};
const afterFastForward=process.argv.includes('--after-fast-forward');
const profiles=(afterFastForward?[{name:'speed-ten-started-after-original-fast-forward',stage:1}]:[{name:'speed-ten-full-fleet-prestart',stage:5},{name:'speed-ten-full-fleet-started',stage:1}])
  .map(profile=>({...profile,constructorGraphics:true,frames:afterFastForward?110:20,
    ...(afterFastForward?{fastForwardFrames:80,speedTenFrames:30,afterMenuRequired:{speedLevel:10,speedDivisor:76}}:{}),
    required:{selector:12,boatClass:6,course:1,venue:0,humans:1,boats:20,speedLevel:afterFastForward?15:10,speedDivisor:afterFastForward?10:76}}));
const cases=[];
for(const profile of profiles){
  const initialized=structuredClone(originalInputs.cases[0]);
  initialized.profile=profile.name;
  initialized.patches.push(patchI32(0x4da1d8,profile.stage),patchI32(0x4da194,20),patchI32(0x4da174,afterFastForward?15:10),patchI32(0x4da178,afterFastForward?10:76));
  initialized.preparation.requested={...initialized.preparation.requested,...profile.required,stage:profile.stage,
    ...(afterFastForward?{speedLevel:15,speedDivisor:10}:{})};
  cases.push(initialized);
  for(let frame=0;frame<(afterFastForward?110:profile.frames);frame++){
    if(afterFastForward&&frame===80)cases.push({profile:profile.name,label:'Original speed10 menu handler after80 native speed15 frames',
      phase:'select-speed-ten',kind:2,identifier:32909,continue:true,arguments:[],patches:[],
      routine:{name:'handleMenuCommand',address:0x493bd0,argumentTypes:[],returnType:'void'},
      windowHandle:0x20000001});
    const row=structuredClone(originalInputs.cases[frame%100+1]);row.profile=profile.name;row.frame=frame;
    row.patches=[patchI32(0x5364e8,frame%60+1)];row.callerInput.value=frame%60+1;
    row.host.tickStart=10000+frame*100;
    cases.push(row);
  }
}
const manifest={...originalInputs,
  integerOutputs:{...originalInputs.integerOutputs,speedLevel:0x4da174,speedDivisor:0x4da178},
  doubleOutputs:{...originalInputs.doubleOutputs,timeStep:0x523378,timeFactor:0x523d48},
  inputEvidence:{...originalInputs.inputEvidence,baseInputManifest:path,baseInputManifestSha256:createHash('sha256').update(bytes).digest('hex'),
    scope:afterFastForward?'Original stage1 immediate-start native initialization with20 Keelboats,80 continuous original speed15/divisor10 frames, then the original32909 speed10 menu handler, followed by30 continuous speed10/divisor76 frames. No gameplay state is injected between frames except the explicitly recorded original paint-caller phase. The actual native handler owns the speed transition; all AI, physics, rendering, sounds and CString children execute.':
      'Two genuine speed10/divisor76 full20-boat Keelboat configurations, before and after the original stage1 immediate-start initialization. Each native initializer is followed by20 continuous complete original frames with all actual AI, physics, render, sound and CString children. Only the original paint-caller phase counter changes between frames; no captured initialized output is supplied.'},
  profiles,cases};
await writeFile(new URL(`analysis/retained-speed-ten-${afterFastForward?'long-':''}frames-capture-inputs.json`,root),JSON.stringify(manifest,null,2)+'\n');
console.log(afterFastForward?'Prepared one original initialization,80 native speed15 frames, original speed10 menu transition, and30 native speed10 frames':'Prepared two original speed10 initializations and40 continuous native full frames');
