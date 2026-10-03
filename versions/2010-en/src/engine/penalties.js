import { add32,sub32,imul32,idiv32,i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { scaledRandom,wrapDegreesOnce } from '../../../../src/engine/integer-core.js';
import { resetBoat } from './movement-history.js';
import { distanceToBoat } from './movement.js';
import { signedStartDistance,aheadAstern,relativeProjection,projectionLow32 } from './ai-geometry.js';
import { bearingFromVector } from './wind.js';
export const PENALTY_ROUTINES=Object.freeze({respawnNearStart:0x43c980,shiftPenaltyPosition:0x43ca40,
 checkNearRaceMarks:0x43ccf0,collisionPenalty:0x43c440,updateMarkStartPenalties:0x43c1e0,
 updateInterference:0x43be00,updateSpinnakerDrag:0x43c140,prestartSpeedPercent:0x43c2c0});
const at=(base,boat,stride=4)=>add32(base,imul32(boat,stride))>>>0;
const f=(memory,address)=>Float80.fromNumber(memory.readF64(address));
const n=Float80.fromInteger;
const absolute=value=>value<0?sub32(0,value):value;
const spill=value=>Float80.fromNumber(value.toNumber());
function sound(memory,boat,gate,options){
 if(boat<=memory.readI32(0x4da140)&&memory.readI32(0x536484)===0&&gate)
  options.playSound?.({resourceId:0x89,moduleHandle:memory.readU32(0x5359c8),flags:0x40005});
}
/** Complete43c980, including its narrower time-based sound gate and two draws. */
export function respawnNearStart(memory,boat,rng,options={}){
 boat=i32(boat);const r=a=>memory.readI32(a),range=idiv32(r(0x523598),6);
 sound(memory,boat,add32(r(0x4f42b8),10)<r(0x4f8cd0),options);resetBoat(memory,boat);
 memory.writeF64(at(0x4f6af8,boat,8),add32(scaledRandom(range,rng),sub32(r(0x4f6d38),idiv32(range,2))));
 memory.writeF64(at(0x4f6c10,boat,8),add32(scaledRandom(range,rng),sub32(r(0x4f7f88),idiv32(range,2))));
}
/** Complete43ca40 for the defined original tack±1 domain. */
export function shiftPenaltyPosition(memory,boat,options={}){
 boat=i32(boat);const r=a=>memory.readI32(a),rb=a=>r(at(a,boat));
 const tack=rb(0x522ff0);if(tack!==1&&tack!==-1)throw new RangeError('Original2010 shift angle is undefined for tacks outside±1');
 sound(memory,boat,r(0x4f8cd0)>-168,options);
 const distance=r(0x4da19c)===8?n(125):n(idiv32(r(0x525a9c),r(0x53527c)===1?20:10));
 let heading=rb(0x535740),stage=rb(0x4f8538);
 if(r(0x4da19c)!==8&&(stage<4||stage===8))heading=sub32(rb(0x522b90),imul32(tack,r(0x4f7200)));
 const below=rb(0x4fecc8)<sub32(160,rb(0x4fae60)),reverse=r(0x53646c)===1;
 const offset=reverse?(tack===1?(below?180:-160):(below?-160:180)):(tack===1?(below?160:180):(below?170:160));
 const angle=wrapDegreesOnce(add32(heading,offset));
 if(typeof options.trig?.extended!=='function')throw new TypeError('Original2010 penalty shift requires native angle captures');
 const pair=options.trig.extended(angle);
 memory.writeF64(at(0x4f6af8,boat,8),pair.sine.multiply(distance).add(f(memory,at(0x4f6af8,boat,8))).toNumber());
 memory.writeF64(at(0x4f6c10,boat,8),f(memory,at(0x4f6c10,boat,8)).subtract(pair.cosine.multiply(distance)).toNumber());
}
/** Complete43ccf0; the final start endpoint has radius+3 in2010. */
export function checkNearRaceMarks(memory,radius,boat){
 radius=i32(radius);boat=i32(boat);const r=a=>memory.readI32(a);
 const x=f(memory,at(0x4f6af8,boat,8)).truncI32(),y=f(memory,at(0x4f6c10,boat,8)).truncI32();
 const distance=(ax,ay)=>add32(absolute(sub32(x,r(ax))),absolute(sub32(y,r(ay))));
 let a=distance(0x536410,0x536414),b=distance(0x4fe094,0x4fe2a0);
 const c=distance(0x5229d4,0x522ac8),d=distance(0x522acc,0x522ae0);let e=distance(0x5229c8,0x522ac4);
 const time=r(0x4f8cd0),long=r(0x53527c),leg=r(at(0x4f8538,boat)),finalLeg=r(0x4da1e4);
 if(sub32(170,r(at(0x4fae60,boat)))<r(at(0x4fecc8,boat))&&time>30)a=b=1000;
 if(time<30)e=1000;
 let result=1;
 if((long===0||leg!==finalLeg)&&radius<a&&radius<c&&radius<d&&radius<e&&add32(radius,3)<b)result=0;
 if(long===0&&time>10&&leg!==finalLeg&&radius<c&&radius<d&&radius<e)result=0;
 if(long===1&&radius<a&&radius<c&&radius<d&&add32(radius,3)<b)result=0;
 return result;
}
const penaltyMovement=(memory,boat,rng,options)=>{
 if(memory.readI32(0x4f8cd0)<20){resetBoat(memory,boat);respawnNearStart(memory,boat,rng,options);}
 else shiftPenaltyPosition(memory,boat,options);
};
/** Complete43c1e0 original mark contact and premature-start routing. */
export function updateMarkStartPenalties(memory,boat,rng,options={}){
 boat=i32(boat);const r=a=>memory.readI32(a),wb=(a,v)=>memory.writeI32(at(a,boat),v);
 if(checkNearRaceMarks(memory,(r(0x4fe624)<901?1:0)+1,boat)===1){
  if(boat<=r(0x4da140))wb(0x5116e0,1);penaltyMovement(memory,boat,rng,options);wb(0x535620,r(0x4f8cd0));
 }
 if(r(0x4f8cd0)<51){
  const distance=signedStartDistance(memory,boat);
  if(distance.compare(f(memory,0x4cc658))<=0&&r(0x4f8cd0)>-3&&r(0x4f8cd0)<1&&r(0x4da1d8)>2){
   if(boat<=r(0x4da140))wb(0x5116e0,2);
   resetBoat(memory,boat);respawnNearStart(memory,boat,rng,options);wb(0x535620,r(0x4f8cd0));
  }
 }
}
/** Complete43c440 collision rules, retaining the original asymmetric duplicate-coordinate calls. */
export function collisionPenalty(memory,other,boat,distance,rng,options={}){
 other=i32(other);boat=i32(boat);distance=i32(distance);
 const r=a=>memory.readI32(a),rb=(a,b=boat)=>r(at(a,b)),wb=(a,v)=>memory.writeI32(at(a,boat),v);
 const time=()=>r(0x4f8cd0),humans=()=>r(0x4da140);
 const dist=(b,x,y)=>distanceToBoat(memory,b,r(x),r(y));
 if(rb(0x4fe638)>0||time()<add32(rb(0x535620,other),50))return;
 const radius=n(r(0x4da194)===2?30:40),ahead=projectionLow32(aheadAstern(memory,boat,other,options));
 if((dist(boat,0x522acc,0x522ae0).compare(radius)<0||dist(boat,0x5229c8,0x522ac4).compare(radius)<0)&&r(0x4f452c)===0&&r(0x53527c)===0){
  const ownStart=spill(dist(boat,0x4fe094,0x4fe2a0));
  if(dist(other,0x4fe094,0x4fe2a0).compare(ownStart)<0&&distance<16&&time()>30&&ahead>-6&&rb(0x4fecc8)>55){
   wb(0x535620,time());if(boat<=humans())wb(0x5116e0,3);shiftPenaltyPosition(memory,boat,options);
  }
 }
 if(dist(boat,0x5229c8,0x522ac4).compare(radius)<0&&r(0x53527c)===1){
  const own=spill(dist(boat,0x5229c8,0x5229c8));
  if(own.compare(dist(other,0x5229c8,0x522ac4))<=0||distance>15||time()<31||ahead<-5||rb(0x4fecc8)<56)return;
  wb(0x535620,time());if(boat<=humans())wb(0x5116e0,3);shiftPenaltyPosition(memory,boat,options);return;
 }
 const nearAux=dist(boat,0x4f4a68,0x4f6d34).compare(radius)<0||dist(boat,0x523248,0x52359c).compare(radius)<0;
 if(nearAux&&r(0x4f452c)===1){
  const own=spill(dist(boat,0x5229c8,0x522ac4));
  if(dist(other,0x5229c8,0x5229c8).compare(own)<=0)return;
  wb(0x535620,time());if(boat<=humans())wb(0x5116e0,3);shiftPenaltyPosition(memory,boat,options);return;
 }
 const tack=rb(0x522ff0),same=tack===rb(0x522ff0,other),blocked=rb(0x4f4208)===1;
 const apply=code=>{wb(0x535620,time());if(boat<=humans())wb(0x5116e0,code);penaltyMovement(memory,boat,rng,options);};
 if(tack===-1&&rb(0x522ff0,other)===1){apply(4);return;}
 if(blocked&&same&&absolute(sub32(rb(0x4f8538),rb(0x4f8538,other)))<2){wb(0x5116e0,6);wb(0x535620,time());penaltyMovement(memory,boat,rng,options);return;}
 let checkProjection=true;
 if(blocked&&boat>humans()){
  if(same){if(time()<4){wb(0x535620,time());resetBoat(memory,boat);respawnNearStart(memory,boat,rng,options);return;}}
  else checkProjection=false;
 }
 if(checkProjection&&same&&projectionLow32(relativeProjection(memory,other,1,boat,options))>=0&&distance<=add32(r(0x5363b8),5)&&sub32(rb(0x4fecc8,other),30)<rb(0x4fecc8)){apply(5);return;}
 if(boat>humans())return;
 if(rb(0x4f7090)===1&&rb(0x4fecc8)<=54){apply(7);return;}
 if(dist(boat,0x5229d4,0x522ac8).compare(f(memory,0x4cc4c0))>=0||sub32(time(),rb(0x4f4350))>5||rb(0x4fecc8)>54)return;
 wb(0x535620,time());wb(0x5116e0,7);shiftPenaltyPosition(memory,boat,options);
}
/** Complete43be00 descending encounter scan and connected collision routing. */
export function updateInterference(memory,boat,rng,options={}){
 boat=i32(boat);const r=a=>memory.readI32(a),rb=(a,b=boat)=>r(at(a,b)),wb=(a,v)=>memory.writeI32(at(a,boat),v);
 if(r(0x4da194)===2&&![1,-1].includes(rb(0x522ff0)))throw new RangeError('Original2010 two-boat interference requires defined tack±1');
 if(boat===1)memory.writeI32(0x5231a8,rb(0x4fe8a8));
 for(const a of[0x4fe8a8,0x4f4208,0x4f7f98,0x5239c8])wb(a,0);
 const position=(a,b)=>f(memory,at(a,b,8)).truncI32();
 const folded=v=>v>180?sub32(360,v):v;
 for(let other=r(0x4da194);other>0;other--){
  if(other===boat)continue;
  const dx=sub32(position(0x4f6af8,other),position(0x4f6af8,boat)),dy=sub32(position(0x4f6c10,boat),position(0x4f6c10,other));
  const distance=add32(absolute(dx),absolute(dy));
  if(distance<30&&rb(0x522ff0)===rb(0x522ff0,other))wb(0x5239c8,1);
  if(distance>=80)continue;
  const bearing=bearingFromVector(memory,dx,dy,options),windDifference=folded(absolute(sub32(rb(0x535890),bearing))),
   headingDifference=folded(wrapDegreesOnce(absolute(sub32(rb(0x535740),bearing))));
  const near=rb(0x4fb380)<11?30:20,humans=r(0x4da140);
  if(headingDifference<40&&distance<near&&boat>humans){wb(0x4f4208,1);wb(0x522dd0,r(0x4f8cd0));}
  if(headingDifference<25&&distance<near&&r(0x5363bc)===0&&boat<=humans)wb(0x4f4208,1);
  if(headingDifference<30&&distance<near&&r(0x5363bc)===1&&boat<=humans)wb(0x4f4208,1);
  let tack=rb(0x522ff0);if(tack!==rb(0x522ff0,other))wb(0x4f4208,0);
  let leader;
  if(r(0x4da194)===2){if(tack===1)leader=absolute(projectionLow32(aheadAstern(memory,boat,other,options)))>9?65:75;tack=rb(0x522ff0);if(tack===-1)leader=50;}
  else leader=tack===1?40:30;
  if(distance<leader&&headingDifference>100&&tack===rb(0x522ff0,other)&&windDifference<120&&tack===1)wb(0x4f7f98,other);
  if(windDifference<25)wb(0x4fe8a8,tack===rb(0x522ff0,other)?2:12);
  if(headingDifference<23&&tack===rb(0x522ff0,other)&&rb(0x4fecc8)<60&&rb(0x4fecc8,other)<80)wb(0x4fe8a8,3);
  let threshold=6;
  if(tack!==rb(0x522ff0,other)){const delta=sub32(rb(0x535740),rb(0x535740,other));if(wrapDegreesOnce(delta)>=30&&wrapDegreesOnce(add32(delta,180))>=30)threshold=8;}
  if(r(0x5363b8)===1)threshold=8;if(r(0x4fe624)>900)threshold--;
  if(distance<threshold)collisionPenalty(memory,other,boat,distance,rng,options);
 }
}
/** Complete43c140 spinnaker angle and blanketing state. */
export function updateSpinnakerDrag(memory,boat){
 boat=i32(boat);const r=a=>memory.readI32(a),rb=a=>r(at(a,boat)),wb=(a,v)=>memory.writeI32(at(a,boat),v);
 const angle=rb(0x4fecc8),limit=r(0x525a98);wb(0x535f68,0);
 if(angle<limit&&angle>=sub32(limit,8))wb(0x535f68,30);
 if(angle<sub32(limit,8))wb(0x535f68,100);
 wb(0x4fbab0,rb(0x4f42c0)===3&&sub32(188,rb(0x4fae60))<angle&&r(0x4da190)>2&&r(0x4da190)!==9&&r(0x5364c4)===0?1:0);
}
/** Complete43c2c0; original finite x87 spills and single optional RNG draw. */
export function prestartSpeedPercent(memory,boat,rng){
 boat=i32(boat);const r=a=>memory.readI32(a),rb=a=>r(at(a,boat));
 if(r(0x4da194)===2&&boat===2&&r(0x4f8cd0)<r(0x4da170))return 100;
 const dx=n(rb(0x4f4d78)).subtract(f(memory,at(0x4f6af8,boat,8))),dy=n(rb(0x4fc350)).subtract(f(memory,at(0x4f6c10,boat,8)));
 const square=spill(dy.multiply(dy).add(dx.multiply(spill(dx))));
 let skill=r(0x4da198)<13?r(0x4da198):12;
 if(r(0x4da19c)===8&&r(0x4f8b78)===0)skill=0;if(r(0x4da198)===2)skill=-5;if(r(0x4da198)===1)skill=-10;
 const draw=r(0x4da194)>2?n(scaledRandom(17,rng)):f(memory,0x4cc658);
 const distance=square.compare(f(memory,0x4cc658))>0?spill(square.sqrt().subtract(n(imul32(sub32(15,skill),4))).subtract(draw)):f(memory,0x4cc658);
 let rate=spill(n(rb(0x4fc230)).multiply(f(memory,0x4cc618)));
 if(rate.compare(f(memory,0x4cc730))<=0)rate=f(memory,0x4cc730);
 if(rb(0x4fe8a8)>0)rate=f(memory,0x4cc4f8);
 rate=spill(rate.multiply(f(memory,0x5359f0)).divide(f(memory,0x523d48)).negate());
 const percent=rate.compare(f(memory,0x4cc658))<=0||rate.compare(distance)<=0?100:distance.multiply(f(memory,0x4cc488)).divide(rate).truncI32();
 return rb(0x4fe8a8)<1?percent:100;
}
