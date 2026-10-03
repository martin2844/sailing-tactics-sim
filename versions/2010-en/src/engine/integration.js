import { add32,sub32,imul32,idiv32,irem32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { scaledRandom } from '../../../../src/engine/integer-core.js';
import { wrapDegreesOnce } from './application.js';
import { resetBoat,recordTrails,recordWaypointHistory } from './movement-history.js';
import { advanceRaceTarget } from './race-targets.js';
import { respawnWaypoint } from './waypoints.js';
import { sampleCurrent,sampleVenueCurrent } from './current.js';
const at=(base,index,stride=4)=>add32(base,imul32(index,stride))>>>0;
const n=Float80.fromInteger,spill=value=>Float80.fromNumber(value.toNumber());
const abs=value=>value<0?sub32(0,value):value;
/** Complete0x43cf60, including 2010 clock, current cadence, wake and sound behavior. */
export function integratePositions(memory,rng,options={}){
 options={...options,rng};
 const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
 const f=address=>Float80.fromNumber(memory.readF64(address)),store=(address,value)=>memory.writeF64(address,value.toNumber());
 const rb=(base,boat)=>r(at(base,boat)),wb=(base,boat,value)=>w(at(base,boat),value),fb=(base,boat)=>f(at(base,boat,8));
 const sound=(id,flags)=>options.playSound?.({resourceId:id,moduleHandle:memory.readU32(0x5359c8),flags});
 if(r(0x4da174)>1){
  w(0x4fb9ac,Math.max(0,sub32(r(0x4fb9ac),1)));
  if(r(0x4da140)===2)w(0x4fb9b0,Math.max(0,sub32(r(0x4fb9b0),1)));
 }
 if(f(0x5359f0).compare(f(0x523378).add(f(0x523378)))<0&&r(0x4da1d8)<3){
  for(let boat=1;boat<=r(0x4da194);boat++){
   resetBoat(memory,boat);
   memory.writeF64(at(0x4f6af8,boat,8),rb(0x4f4d78,boat));memory.writeF64(at(0x4f6c10,boat,8),rb(0x4fc350,boat));
   if(boat>r(0x4da140)&&r(0x4da194)>2){
    const ratio=spill(n(scaledRandom(10,rng)).divide(f(0x4cc4c0).subtract(n(r(0x4da198)).multiply(f(0x4cc5c8)))));
    const complement=f(0x4cc650).subtract(ratio);
    store(at(0x4f6af8,boat,8),fb(0x4f6af8,boat).multiply(complement).add(n(r(0x4f6d38)).multiply(ratio)));
    store(at(0x4f6c10,boat,8),fb(0x4f6c10,boat).multiply(complement).add(n(r(0x4f7f88)).multiply(ratio)));
   }
   memory.writeBytes(at(0x4f83c0,boat,8),memory.readBytes(at(0x4f6af8,boat,8),8));memory.writeBytes(at(0x4fb090,boat,8),memory.readBytes(at(0x4f6c10,boat,8),8));
   wb(0x4f8538,boat,0);advanceRaceTarget(memory,boat,options);
   memory.writeF64(0x4fe938,sub32(r(0x522b94),r(0x4f7200)));wb(0x535740,boat,sub32(rb(0x522b90,boat),r(0x4f7200)));
   w(0x511624,1);w(0x511628,1);wb(0x4fe9d0,boat,0);wb(0x522ff0,boat,1);wb(0x4f4350,boat,0);
  }
  if(r(0x4da19c)===8&&r(0x4f8b78)===0){
   const automatic=r(0x5362d4)<181;
   memory.writeF64(0x4fe938,automatic?wrapDegreesOnce(sub32(r(0x5362d4),r(0x4f7200))):90);w(0x511624,automatic?1:0);
   if(r(0x4da140)===2){w(0x535748,automatic?wrapDegreesOnce(sub32(r(0x5362d4),r(0x4f7200))):90);w(0x511628,automatic?1:0);}
  }
 }
 if(f(0x5359f0).compare(f(0x535bc0).subtract(f(0x523378).multiply(f(0x4cc5c8))))<0){
  for(let index=0;index<=r(0x4da1f4);index++)respawnWaypoint(memory,index,rng,options);
 }
 if(r(0x4f8cd0)===r(0x4f42b8)&&r(0x5364c8)===1){w(0x511624,0);w(0x500384,0);if(r(0x4da140)===2){w(0x511628,0);w(0x500388,0);}}
 let dtScale=r(0x4da19c)===8||r(0x4da1f8)===5?f(0x4cc5d0):f(0x4cc5a8);
 if(r(0x525a9c)<2000)dtScale=f(0x4ccaf0);
 store(0x523378,f(0x523d48).multiply(dtScale).divide(n(r(0x4da178))));
 w(0x4da1ec,add32(r(0x4da1ec),1));if(r(0x4da1ec)>1000)w(0x4da1ec,1);
 const countdown=(threshold,lower,id)=>{
  if(r(0x4da1d8)>2&&f(0x5359f0).compare(f(0x523378).subtract(f(threshold)))<=0&&f(0x5359f0).compare(f(lower))>=0&&r(0x536484)===0)sound(id,0x40005);
 };
 countdown(0x4ccaf8,0x4cc698,r(0x5364c8)===0?0x8c:0x8e);
 countdown(0x4ccb00,0x4cc6a0,0x8e);countdown(0x4ccb08,0x4cc6a8,0x8e);
 countdown(0x4ccb10,0x4cc760,r(0x5364c8)===0?0x8c:0x8e);
 store(0x5359f0,f(0x5359f0).add(f(0x523378)));
 let clock=r(0x4da190)===7&&r(0x5364c8)===0?2.5:1.5;
 if(r(0x4da1f8)>0)clock=r(0x4da1f8)===5?0.6:0.45;
 if(r(0x5364c8)===1)clock=0.5;if(r(0x4da19c)===8)clock=12;if(f(0x5359f0).compare(f(0x4cc658))<=0)clock=1;
 memory.writeF64(0x4da160,clock);store(0x534d68,f(0x4da160).multiply(f(0x5359f0)).multiply(f(0x4cc768)));
 const hours=f(0x534d68).multiply(f(0x4ccb18)).truncI32();
 let hour=sub32(r(0x4faa58),hours);if(hour>=48)hour=sub32(hour,48);else if(hour>=24)hour=sub32(hour,24);
 w(0x4f6d60,hour);w(0x536450,hour<6||hour>20?1:0);
 w(0x4fad34,add32(f(0x534d68).truncI32(),imul32(hours,60)));
 if(r(0x4fad34)===30||r(0x4fad34)===59)w(0x5359d4,r(0x5362d4));
 if(f(0x5359f0).compare(f(0x4cc658))<0)w(0x4fb9b8,sub32(imul32(r(0x4fad34),-60),f(0x534d68).multiply(f(0x4ccb20)).truncI32()));
 store(0x5355f8,f(0x534d68).multiply(f(0x4ccae0)));
 if(f(0x5359f0).compare(f(0x4cc658))>=0)w(0x4fb9b8,f(0x5355f8).truncI32());
 w(0x4fe6c8,r(0x4f8cd0));w(0x4f8cd0,f(0x5359f0).truncI32());w(0x4faf90,0);
 const refresh=r(0x4da1f8)===5?f(0x4cc5a0):f(r(0x536408)!==0?0x4cca20:0x4cca38);
 if(f(0x5359f0).subtract(f(0x536230)).compare(refresh)>0){w(0x4faf90,1);w(0x536394,add32(r(0x536394),1));memory.writeBytes(0x536230,memory.readBytes(0x5359f0,8));if(r(0x536394)>6)w(0x536394,1);}
 let factor;
 for(let boat=r(0x4da194);boat>0;boat--){
  if(irem32(r(0x5364e8),8)===0){
   const x=fb(0x4f6af8,boat).truncI32(),y=fb(0x4f6c10,boat).truncI32();
   const strength=r(0x4da1f8)===0?sampleCurrent(memory,x,y,boat,options):sampleVenueCurrent(memory,x,y,boat,options);
   wb(0x536308,boat,strength);wb(0x4fb420,boat,wrapDegreesOnce(r(0x536418)));
  }
  const direction=wrapDegreesOnce(rb(0x4fb420,boat));wb(0x4fb420,boat,direction);
  const strength=abs(rb(0x536308,boat));
  let cx=0,cy=0;
  if(direction>=0&&direction<=359){cx=sub32(0,imul32(r(at(0x4f85c8,direction)),strength));cy=imul32(r(at(0x4f1740,direction)),strength);}
  let driftX=0,driftY=0;
  if(r(0x4f8cd0)<0){
   cx=idiv32(cx,3);cy=idiv32(cy,3);
   if(rb(0x4fdfe8,boat)<20&&boat<=r(0x4da140)&&r(0x4da198)>=8&&rb(0x4f8538,boat)<=8){
    const pair=options.trig.extended(r(0x4f7f94));driftX=pair.sine.multiply(f(0x4ccb28)).truncI32();driftY=pair.cosine.multiply(f(0x4ccb30)).truncI32();
   }
  }
  const currentX=add32(driftX,cx),currentY=add32(driftY,cy),speed=n(imul32(rb(0x4fdfe8,boat),100));
  const velocity=heading=>{
   const pair=options.trig.stored(heading),sineSpeed=spill(pair.sine.multiply(speed));
   return{x:sineSpeed.add(n(currentX)),y:spill(n(currentY).subtract(speed.multiply(pair.cosine))),sineSpeed,cosine:pair.cosine};
  };
  let vector=velocity(wrapDegreesOnce(rb(0x535740,boat)));
  wb(0x4fc230,boat,idiv32(vector.y.multiply(vector.y).add(vector.x.multiply(vector.x)).sqrt().truncI32(),100));
  let divisor=r(0x522ad0)>9?2600:2300;
  if(r(0x5363c4)===1||r(0x5363b8)===1||r(0x53652c)===1)divisor=add32(divisor,300);
  if(r(0x4faa48)<35&&r(0x4da190)!==3)divisor=sub32(divisor,200);if(r(0x5363cc)===1)divisor=sub32(divisor,200);
  const preciseFactor=f(0x523378).divide(n(divisor));factor=spill(preciseFactor);
  const y=factor.multiply(vector.y).add(fb(0x4f6c10,boat));
  const x=spill(preciseFactor.multiply(vector.x).add(fb(0x4f6af8,boat)));
  store(at(0x4f6af8,boat,8),x);store(at(0x4f6c10,boat,8),y);
  store(at(0x4f1610,boat,8),vector.sineSpeed.multiply(factor).add(x));
  store(at(0x4f3868,boat,8),n(imul32(rb(0x4fdfe8,boat),-100)).multiply(vector.cosine).multiply(factor).add(y));
  if(rb(0x4fe638,boat)>0){wb(0x5350d8,boat,0);wb(0x511620,boat,1);wb(0x512278,boat,70);wb(0x522ff0,boat,1);memory.writeF64(at(0x4f6af8,boat,8),rb(0x4fb548,boat));memory.writeF64(at(0x4f6c10,boat,8),rb(0x522af0,boat));}
  if(rb(0x4fe6d0,boat)>0)vector=velocity(wrapDegreesOnce(sub32(rb(0x522b90,boat),imul32(rb(0x522ff0,boat),r(0x4f7200)))));
  const scaledY=spill(vector.y.multiply(f(0x4da1b8)));
  wb(0x513480,boat,fb(0x4f6af8,boat).subtract(vector.x.multiply(f(0x4da1b8)).multiply(f(0x4ccb38))).truncI32());
  wb(0x513510,boat,fb(0x4f6c10,boat).subtract(scaledY.multiply(f(0x4ccb38))).truncI32());
  memory.writeBytes(at(0x4f83c0,boat,8),memory.readBytes(at(0x4f6af8,boat,8),8));memory.writeBytes(at(0x4fb090,boat,8),memory.readBytes(at(0x4f6c10,boat,8),8));
  const level=r(0x4da174),period=level>=9?1:level>=7?3:level>=5?6:level>=3?12:24;
  if(level<13&&irem32(r(0x4da1ec),period)===0)recordWaypointHistory(memory,boat);
 }
 if(!factor){if(options.uninitializedFactor===undefined)throw new RangeError('Original zero-boat integration requires an observed stack factor');factor=Float80.fromNumber(options.uninitializedFactor);}
 for(let patch=1;patch<=5;patch++){
  const direction=wrapDegreesOnce(wrapDegreesOnce(add32(rb(0x5357dc,patch-1),180)));
  const strength=rb(0x4f42a4,patch-1);
  const x=imul32(imul32(r(at(0x4f85c8,direction)),strength),10),y=imul32(imul32(r(at(0x4f1740,direction)),strength),-10);
  store(at(0x535468,patch-1,8),n(x).multiply(factor).add(fb(0x535468,patch-1)));
  store(at(0x4f4b10,patch-1,8),n(y).multiply(factor).add(fb(0x4f4b10,patch-1)));
 }
 const direction=wrapDegreesOnce(add32(r(0x5362d4),180));
 const pair=options.trig.extended(direction);
 for(let index=0;index<=r(0x4da1f4);index++){
  // Original43dd38..43dd5a scales the sine before multiplying by the stored
  // factor. The decompiler reassociates this expression.
  store(at(0x4f7220,index,8),pair.sine.multiply(n(r(0x522ad0))).multiply(f(0x4cc490)).multiply(factor).add(fb(0x4f7220,index)));
  store(at(0x4ff038,index,8),pair.cosine.multiply(n(r(0x522ad0))).multiply(f(0x4ccb40)).multiply(factor).add(fb(0x4ff038,index)));
 }
 if(r(0x536394)!==r(0x5364b8)){recordTrails(memory);w(0x534ea8,Math.min(500,add32(r(0x534ea8),1)));w(0x5364b8,r(0x536394));}
 for(let index=0;index<11;index++)w(0x4fb210+index*4,0);
 if(r(0x536484)!==0||r(0x4f7124)!==0||r(0x4f7128)!==0)return;
 if(irem32(r(0x4f8cd0),200)===0&&r(0x4f8cd0)>10){sound(0x86,0x40045);w(0x4f8cd0,add32(r(0x4f8cd0),1));}
 const extra=sub32(r(0x4da140),1);
 if((r(0x4f7094)===1||imul32(extra,r(0x4f7098))===1||r(0x51227c)>50)&&r(0x4f8cd0)>5&&r(0x4fe63c)===0)sound(0x98,0x40015);
 else if(r(0x4f8cd0)>5){
  const threshold=n(r(0x4faa48)).sqrt().multiply(f(0x4cc580));
  if((threshold.compare(n(r(0x4fdfec)))<0||threshold.compare(n(imul32(extra,r(0x4fdff0))))<0)&&r(0x4f7094)===0&&imul32(extra,r(0x4f7098))===0&&r(0x4feccc)>89)sound(0x8a,0x40015);
 }
 if(r(0x4f8cd0)>0&&r(0x4fe6c8)<1&&r(0x536484)===0)sound(r(0x5364c8)===0?0x8c:0x8e,r(0x5364c8)===0?0x40004:0x40005);
}
