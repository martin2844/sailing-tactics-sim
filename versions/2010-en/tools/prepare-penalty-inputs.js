import { readFile,writeFile } from 'node:fs/promises';
import { PENALTY_ROUTINES } from '../src/engine/penalties.js';
const prior=JSON.parse(await readFile(new URL('../analysis/sampleCurrent-capture-inputs.json',import.meta.url),'utf8'));
const globalFields={boats:0x4da194,humans:0x4da140,course:0x4da19c,stage:0x4da1d8,venue:0x4da1f8,time:0x4f8cd0,
 lastTime:0x4f42b8,startTime:0x4da170,skill:0x4da198,boatClass:0x4da190,span:0x523598,courseLength:0x525a9c,
 soundDisabled:0x536484,module:0x5359c8,reverse:0x53646c,longCourse:0x53527c,twoPlayer:0x4f452c,
 catamaran:0x5363b8,board:0x5363bc,modelYacht:0x5364c8,canvas:0x5364c4,
 finalLeg:0x4da1e4,width:0x4fe624,spinLimit:0x525a98,closehaul:0x4f7200,
 ax:0x536410,ay:0x536414,bx:0x4fe094,by:0x4fe2a0,cx:0x5229d4,cy:0x522ac8,
 dx:0x522acc,dy:0x522ae0,ex:0x5229c8,ey:0x522ac4,leftX:0x4f4a68,leftY:0x4f6d34,
 rightX:0x523248,rightY:0x52359c,spawnX:0x4f6d38,spawnY:0x4f7f88};
const indexed={tack:0x522ff0,heading:0x535740,direction:0x522b90,apparentDirection:0x535890,wind:0x4fb380,
 angle:0x4fecc8,downwind:0x4fae60,leg:0x4f8538,finish:0x4fe638,penaltyTime:0x535620,
 interference:0x4fe8a8,blocked:0x4f4208,turn:0x4f7090,lastTurn:0x4f4350,rate:0x4fc230,
 targetX:0x4f4d78,targetY:0x4fc350,spinMode:0x4f42c0,spinDrag:0x535f68,blanket:0x4fbab0};
const defaults={boats:2,humans:1,course:1,stage:5,venue:0,time:100,lastTime:-170,startTime:-90,skill:10,
 boatClass:6,span:125,courseLength:1000,soundDisabled:0,module:0x12340000,reverse:0,longCourse:0,twoPlayer:0,
 catamaran:0,board:0,modelYacht:0,canvas:0,finalLeg:8,width:900,spinLimit:105,closehaul:45,
 ax:0,ay:0,bx:100,by:0,cx:1000,cy:-1000,dx:-1000,dy:-1000,ex:0,ey:1000,
 leftX:-90,leftY:1000,rightX:90,rightY:1000,spawnX:50,spawnY:20};
const boatDefaults={tack:1,heading:45,direction:0,apparentDirection:40,wind:12,angle:45,downwind:20,
 leg:2,finish:0,penaltyTime:-500,interference:0,blocked:0,turn:0,lastTurn:0,rate:89,
 targetX:50,targetY:0,spinMode:2,spinDrag:77,blanket:88};
const i32=(address,value)=>{const b=Buffer.alloc(4);b.writeInt32LE(value);return{address,bytes:b.toString('hex')};};
const f64=(address,value)=>{const b=Buffer.alloc(8);b.writeDoubleLE(value);return{address,bytes:b.toString('hex')};};
const metadata=Object.fromEntries(Object.keys(PENALTY_ROUTINES).map(name=>[name,[]]));
const add=(name,args,changes={},boat1={},boat2={},position1=[100.75,200.25],position2=[150.25,240.5],group='connected-penalty-domain')=>{
 const patches=[f64(0x4f6b00,position1[0]),f64(0x4f6c18,position1[1]),f64(0x4f6b08,position2[0]),f64(0x4f6c20,position2[1]),
  f64(0x5359f0,-170.5),f64(0x523d48,1)];
 for(const[b,values]of[[1,{...boatDefaults,...boat1}],[2,{...boatDefaults,tack:-1,...boat2}]])
  for(const[field,value]of Object.entries(values))patches.push(i32(indexed[field]+b*4,value));
 metadata[name].push({group,arguments:args,inputs:{...defaults,...changes},seed:(0x20100000+metadata[name].length)>>>0,patches});
};
for(const time of[-180,-169,-168,-167,-151,-150,-3,-2,-1,0,1,3,4,19,20,30,31,49,50,100])
 for(const humans of[1,2])for(const boat of[1,2]){
  add('respawnNearStart',[boat],{time,humans});
  add('updateMarkStartPenalties',[boat],{time,humans});
 }
for(const tack of[-1,1])for(const reverse of[0,1])for(const course of[1,8])for(const leg of[2,3,4,7,8])
 for(const angle of[139,140,141,159,160,179])for(const boat of[1,2])
  add('shiftPenaltyPosition',[boat],{reverse,course},{tack,leg,angle},{tack,leg,angle});
for(const radius of[1,2,3,4])for(const time of[10,11,29,30,31])for(const longCourse of[0,1])for(const leg of[2,8])
 for(const[position,index]of[[[0,0],0],[[100,0],1],[[1000,-1000],2],[[-1000,-1000],3],[[0,1000],4]])
  add('checkNearRaceMarks',[radius,1],{time,longCourse},{leg}, {},position,[150,200],`mark-radius-${index}`);
for(const time of[0,3,4,19,20,30,31,100])for(const humans of[1,2])for(const blocked of[0,1])for(const tack of[-1,1])
 for(const distance of[3,5,6,15,16])
  add('collisionPenalty',[2,1,distance],{time,humans},{blocked,tack}, {},[100,200],[100+distance,200]);
for(const longCourse of[0,1])for(const twoPlayer of[0,1])for(const angle of[54,55,56,160])
 for(const position of[[0,1000],[-1000,-1000],[-90,1000],[1000,-1000]])
  add('collisionPenalty',[2,1,5],{longCourse,twoPlayer},{angle,tack:1,leg:3},{tack:1,leg:3},position,[position[0]+4,position[1]+2],'finish-zone-original-asymmetric-calls');
for(const distance of[0,1,5,6,7,8,9,19,20,29,30,39,40,49,50,64,65,74,75,79,80])for(const tack of[-1,1])
 for(const heading of[0,45,90,179,180,270,359])
  add('updateInterference',[1],{time:100},{tack,heading,angle:50},{tack:1,heading:90,angle:79},[100,200],[100+distance,200]);
for(const boats of[2,3])for(const time of[-170,-100,-89,-1,0])for(const skill of[1,2,10,12,13])for(const interference of[0,1,2])
 add('prestartSpeedPercent',[2],{boats,time,skill},{},{interference},[100,200],[250.75,200.25]);
for(const angle of[0,96,97,104,105,106,167,168,169,188,189])for(const boatClass of[1,2,3,6,9])for(const canvas of[0,1])
 add('updateSpinnakerDrag',[1],{boatClass,canvas},{angle,spinMode:3});
for(const[name,cases]of Object.entries(metadata)){
 if(process.argv[2]&&process.argv[2]!==name)continue;
 const argTypes=name==='checkNearRaceMarks'?['I32','I32']:name==='collisionPenalty'?['I32','I32','I32']:['I32'];
 const manifest={source:prior.source,sourceSha256:prior.sourceSha256,x87ControlWord:'0x027f',mutableBlock:prior.mutableBlock,
  integerInputs:globalFields,integerOutputs:{},doubleInputs:{},doubleOutputs:{},routine:{name,address:PENALTY_ROUTINES[name],argumentTypes:argTypes,
    returnType:['checkNearRaceMarks','prestartSpeedPercent'].includes(name)?'I32':'void'},
  scope:'Complete2010 encounter and penalty routines with explicit finite positions, original coupled geometry/reset calls, valid tack±1, RNG and ordered sound observations.',cases};
 await writeFile(new URL(`../analysis/${name}-capture-inputs.json`,import.meta.url),JSON.stringify(manifest,null,2)+'\n');
 console.log(`${name}: ${cases.length} complete native input cases`);
}
