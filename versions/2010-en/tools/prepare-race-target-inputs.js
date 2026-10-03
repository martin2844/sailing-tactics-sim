import{readFile,writeFile}from'node:fs/promises';
import{createHash}from'node:crypto';
const edition=new URL('../',import.meta.url),bytes=await readFile(new URL('tests/fixtures/original-initializeCourse.json',edition));
const fixture=JSON.parse(bytes),patchI=(address,value)=>{const raw=Buffer.alloc(4);raw.writeInt32LE(value|0);return{address,bytes:raw.toString('hex')};};
const patchF=(address,value)=>{const raw=Buffer.alloc(8);raw.writeDoubleLE(value);return{address,bytes:raw.toString('hex')};};
const cases=[];
for(let sample=0;sample<28;sample++){
 const inputIndex=Math.floor(sample*(fixture.cases.length-1)/27),row=fixture.cases[inputIndex];
 const state=Buffer.from(fixture.mutableBaseline,'hex');
 const basePatches=[...Object.entries(row.inputs??{}).map(([field,value])=>patchI(fixture.integerInputs[field],value)),
 ...Object.entries(row.doubleInputs??{}).map(([field,value])=>patchF(fixture.doubleInputs[field],value)),...row.patches??[],
 ...row.expected.imageChanges.map(change=>({address:change.address,bytes:change.after}))];
 for(const patch of basePatches)state.set(Buffer.from(patch.bytes,'hex'),patch.address-0x4da000);
 const boats=state.readInt32LE(0x4da194-0x4da000),finalLeg=state.readInt32LE(0x4da1e4-0x4da000);
 for(const boat of[1,Math.max(1,boats)])for(const leg of[0,1,2,6,7,finalLeg])for(const scenario of[0,1,2]){
  const patches=[...basePatches];
  for(const[address,value]of[[0x4da1cc,scenario===0?1:5],[0x5363f8,scenario===1?1:0],[0x536408,scenario!==0?1:0],
   [0x53527c,scenario===2?1:0],[0x5363f4,0],[0x5363fc,0],[0x536424,scenario===1?1:0],
   [0x4f8cd0,531],[0x536484,0],[0x5359c8,0x76543210],[0x4f6d64,scenario],[0x4f6a58,scenario===2?1:0],
   [0x5364c8,scenario===2?1:0]])patches.push(patchI(address,value));
  for(let other=1;other<=boats;other++){
   for(const[base,value]of[[0x4f8538,other===boat?leg:6],[0x4fe2b0,scenario],[0x522ff0,other%2?-1:1],
    [0x4fe638,scenario===2?1:0]])patches.push(patchI(base+other*4,value));
  }
  cases.push({label:`advance-${inputIndex}-${boat}-${leg}-${scenario}`,arguments:[boat],seed:row.seed??2010,patches});
 }
}
const manifest={sourceSha256:fixture.sourceSha256,routine:{name:'advanceRaceTarget',address:0x437570,argumentTypes:['I32'],returnType:'void'},
 integerInputs:{},integerOutputs:{},doubleInputs:{},doubleOutputs:{},
 inputEvidence:{fixture:'tests/fixtures/original-initializeCourse.json',sha256:createHash('sha256').update(bytes).digest('hex'),
 scope:'Prepared start/course geometry checkpoints from independently verified original initialization. Every target-parent expected byte, RNG and sound is captured anew; production code computes every transition.'},cases};
await writeFile(new URL('analysis/advanceRaceTarget-capture-inputs.json',edition),JSON.stringify(manifest,null,2)+'\n');console.log(cases.length);
