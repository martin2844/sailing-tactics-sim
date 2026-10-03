import {readFile,writeFile}from'node:fs/promises';
import {createHash}from'node:crypto';
const edition=new URL('../',import.meta.url);
const sourceSha256='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
if(createHash('sha256').update(await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe',edition))).digest('hex')!==sourceSha256)throw new Error('Original source differs');
const patchI=(address,value)=>{const b=Buffer.alloc(4);b.writeInt32LE(value|0);return{address,bytes:b.toString('hex')};};
const patchF=(address,value)=>{const b=Buffer.alloc(8);b.writeDoubleLE(value);return{address,bytes:b.toString('hex')};};
const write=async(name,address,argumentTypes,returnType,cases)=>{
 const manifest={sourceSha256,routine:{name,address,argumentTypes,returnType},integerInputs:{},integerOutputs:{},doubleInputs:{},doubleOutputs:{},
 scope:'Complete unchanged2010 original routine and actual original children; finite prepared valid states, every mutable byte, RNG, exact floating return and ordered sound requests.',cases};
 await writeFile(new URL(`analysis/${name}-capture-inputs.json`,edition),JSON.stringify(manifest,null,2)+'\n');console.log(name,cases.length);
};
const distanceCases=[];
for(const delta of[0,-0,1,-1,1e-150,1e150,1000,50000,1e9])for(const origin of[0,-0,17.25,-1000]){
 distanceCases.push({arguments:[origin,origin+17,origin+delta,origin+delta+17],seed:2010});
}
await write('clamped-point-distance',0x4662d0,['F64','F64','F64','F64'],'float10',distanceCases);
const nearestCases=[],respawnCases=[];
for(const count of[-1,0,1,4,10,20])for(const humans of[1,2])for(const heading of[0,90,180,270,359]){
 const patches=[patchI(0x4da1f4,count),patchI(0x4da140,humans)];
 for(let boat=0;boat<=20;boat++){
  patches.push(patchI(0x4fbb90+boat*4,heading),patchF(0x4f6af8+boat*8,boat*20-100),patchF(0x4f6c10+boat*8,boat*-35+500),
   patchF(0x4f7220+boat*8,boat*40-300),patchF(0x4ff038+boat*8,boat*-80+200));
 }
 for(const excluded of[-1,0,1,count])nearestCases.push({arguments:[31.25,-217.5,excluded],seed:2010,patches});
 for(const index of[0,Math.max(0,count)])respawnCases.push({arguments:[index],seed:2010+heading,patches});
}
await write('nearest-waypoint',0x466230,['F64','F64','I32'],'float10',nearestCases);
await write('respawn-waypoint',0x465ff0,['I32'],'void',respawnCases);
const integrationCases=[];
const times=[-301,-180,-120,-60,-10,-1,0,0.1,1,5,6,100,199.9,200,800,10000];
for(const boats of[1,2,10,27,30])for(const time of times)for(const scenario of[0,1,2]){
 const level=[1,8,12][scenario],humans=scenario===1?2:1,venue=scenario===2?5:0;
 const values={boatCount:boats,humanBoatCount:humans,speedLevel:level,speedDivisor:[50,10,1][scenario],
 class:[0,7,10][scenario],course:scenario===1?8:1,venue,difficulty:8,startMode:10,
 length:40,wind:15,startHour:9,waypoints:scenario===2?2:-1,framePhase:scenario===2?1:0,
 soundDisabled:0,optimist:scenario===2?1:0,skiff:scenario===1?1:0,cat:0,foiling:scenario===2?1:0,
 cycle:[23,2,5][scenario],phase:1,previousPhase:0,history:2,windDirection:90,mouseMagnitude:scenario===2?75:0};
 const addresses={boatCount:0x4da194,humanBoatCount:0x4da140,speedLevel:0x4da174,speedDivisor:0x4da178,class:0x4da190,
 course:0x4da19c,venue:0x4da1f8,difficulty:0x4da198,startMode:0x4da1d8,length:0x4faa48,wind:0x522ad0,
 startHour:0x4faa58,waypoints:0x4da1f4,framePhase:0x5364e8,soundDisabled:0x536484,optimist:0x5363cc,
 skiff:0x5363c4,cat:0x5363b8,foiling:0x53652c,cycle:0x4da1ec,phase:0x536394,previousPhase:0x5364b8,
 history:0x534ea8,windDirection:0x5362d4,mouseMagnitude:0x51227c};
 const patches=Object.entries(addresses).map(([name,address])=>patchI(address,values[name]));
 for(const[address,value]of[[0x5359c8,0x76543210],[0x4f42b8,-180],[0x4f8cd0,Math.trunc(time)],
  [0x4fb9ac,5],[0x4fb9b0,5],[0x5364c8,scenario===1?1:0],[0x525a9c,scenario===0?1999:2500],[0x4feccc,100],
  [0x4f7094,scenario===2?1:0],[0x4f7098,0],[0x4f7124,0],[0x4f7128,0],[0x5359d0,0]])patches.push(patchI(address,value));
 for(const[address,value]of[[0x5359f0,time],[0x523d48,1.0625],[0x523378,0.5],[0x535bc0,-1000],[0x536230,time-10],[0x4da1b8,1.25]])patches.push(patchF(address,value));
 for(let boat=1;boat<=boats;boat++){
  for(const[base,value]of[[0x4fdfe8,boat*2+15],[0x535740,(boat*73+90)%360],[0x4fb420,(boat*41)%360],
   [0x536308,boat%5-2],[0x4f8538,4],[0x4fe638,scenario===2&&boat%3===0?1:0],[0x4fe6d0,scenario===1&&boat%2===0?1:0],
   [0x522b90,90],[0x522ff0,1],[0x4fb548,boat*30],[0x522af0,boat*-15],[0x4f7200,45]])patches.push(patchI(base===0x4f7200?base:base+boat*4,value));
  patches.push(patchF(0x4f6af8+boat*8,boat*30.125-350),patchF(0x4f6c10+boat*8,boat*-45.75+1700));
 }
 for(let patch=0;patch<5;patch++){patches.push(patchI(0x5357dc+patch*4,patch*47),patchI(0x4f42a4+patch*4,patch+10),patchF(0x535468+patch*8,patch*333),patchF(0x4f4b10+patch*8,patch*-777));}
 for(let index=0;index<=Math.max(-1,values.waypoints);index++){patches.push(patchF(0x4f7220+index*8,index*40),patchF(0x4ff038+index*8,index*80));}
 integrationCases.push({label:`integration-${boats}-${time}-${scenario}`,seed:2010,patches});
}
await write('integration',0x43cf60,[],'void',integrationCases);
