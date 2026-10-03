import { add32,sub32,imul32,idiv32,i32 } from '../../../../src/runtime/c-types.js';
import { scaledRandom } from '../../../../src/engine/integer-core.js';
import { wrapDegreesOnce } from './application.js';
import { projectPoint } from './spatial-metrics.js';
import { initializeCourse } from './course.js';
const at=(base,index,stride=4)=>add32(base,imul32(index,stride))>>>0;
/** Complete0x437570, with original dynamic course/finish transitions. */
export function advanceRaceTarget(memory,boat,options={}){
 boat=i32(boat);
 const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
 const rb=base=>r(at(base,boat)),wb=(base,value)=>w(at(base,boat),value);
 let handedness=r(0x53646c)===1?-1:1;
 w(0x4da214,handedness);
 let leg=rb(0x4f8538);
 if((leg===6||leg===7)&&boat>r(0x4da140))wb(0x4f4350,r(0x4f8cd0));
 const initialize=mode=>initializeCourse(memory,mode,options.rng,options);
 const project=(x,y,direction,distance)=>projectPoint(memory,x,y,distance,direction,options);
 if(leg===7&&r(0x536408)===1&&rb(0x4fe2b0)===0){
  wb(0x4f8538,0);wb(0x4fe2b0,1);wb(0x4f4d78,r(at(0x511784,boat,0x28)));wb(0x4fc350,r(at(0x511d04,boat,0x28)));
  if(r(0x5363f8)===1&&boat===1){
   w(0x4da168,1);initialize(2);
   w(0x523598,add32(imul32(r(0x4da194),3),40));
   const direction=add32(r(0x535208),imul32(r(0x4da214),90));
   project(r(0x536410),r(0x536414),direction,r(0x523598));
   w(0x4fe2a0,r(0x523180));w(0x4fe094,r(0x4fe080));w(0x4fb518,wrapDegreesOnce(direction));w(0x4fb530,r(0x523598));
   if(r(0x4da194)>0){
    const x=idiv32(add32(r(0x536410),r(0x4fe094)),2),y=idiv32(add32(r(0x4fe2a0),r(0x536414)),2);
    for(let other=1;other<=r(0x4da194);other++){w(at(0x5117a0,other,0x28),x);w(at(0x511d20,other,0x28),y);}
   }
   memory.writeF64(0x4fb078,r(0x4fe2a0));memory.writeF64(0x4f83a8,r(0x4fe094));
   const x=r(0x5117c0),y=r(0x511d40);
   for(let other=2;other<=r(0x4da194);other++){
    const prior=r(at(0x4f8538,other));
    if(prior>2&&prior<6){w(at(0x4f8538,other),6);w(at(0x4f4d78,other),x);w(at(0x4fc350,other),y);}
   }
   handedness=r(0x4da214);
  }
 }
 if(r(0x5363f8)===1&&r(0x4da1cc)===5){initialize(3);handedness=r(0x4da214);}
 if(r(0x5363f8)===0&&r(0x53527c)===0&&rb(0x4f8538)===2){
  w(0x523598,add32(imul32(r(0x4da194),3),40));
  project(r(0x536410),r(0x536414),add32(r(0x535208),imul32(handedness,90)),r(0x523598));
  w(0x4fe2a0,r(0x523180));w(0x4fe094,r(0x4fe080));memory.writeF64(0x4f83a8,r(0x4fe080));memory.writeF64(0x4fb078,r(0x523180));
  w(at(0x511d20,boat,0x28),idiv32(add32(r(0x536414),r(0x4fe2a0)),2));
  // First mark uses the original ten-word boat stride.
  w(at(0x5117a0,boat,0x28),idiv32(add32(r(0x4fe080),r(0x536410)),2));
  handedness=r(0x4da214);
 }
 if(r(0x53527c)===1&&(r(0x536408)===0||r(0x4da1cc)>4||r(0x4fe63c)>0||
   (r(0x4da188)===7&&r(0x4fe2b4)>0&&r(0x4f853c)>1))&&r(0x4da1cc)>1){
  w(0x5364e0,1);w(0x4da1e4,r(0x4da194)<16?4:6);
  const direction=wrapDegreesOnce(add32(r(0x4f7f94),r(0x4da194)<3?90:imul32(handedness,90)));
  project(r(0x536410),r(0x536414),direction,add32(imul32(r(0x4da194),3),40));
  w(0x4fe094,r(0x4fe080));w(0x4fe2a0,r(0x523180));
  const x=idiv32(add32(r(0x4fe080),r(0x536410)),2),y=idiv32(add32(r(0x536414),r(0x523180)),2);
  memory.writeF64(0x4f83c0,x);memory.writeF64(0x4fb090,y);memory.writeF64(0x4f83a8,r(0x4fe080));memory.writeF64(0x4fb078,r(0x523180));
  w(0x5229c8,x);w(0x522ac4,y);
  for(let other=1;other<=r(0x4da194);other++){
   const otherLeg=r(at(0x4f8538,other));
   if(otherLeg===6&&r(0x4da194)>15){
    // The native routine deliberately writes this boat's mark repeatedly while
    // copying its values to each matching other boat's immediate target.
    let markX=x,markY=y;
    if(boat>r(0x4da140)&&r(at(0x4fe2b0,boat))>0){
     if(rb(0x522ff0)===-1){markX=idiv32(add32(r(0x4fe080),x),2);markY=idiv32(add32(r(0x523180),y),2);}
     else{markX=idiv32(add32(r(0x536410),x),2);markY=idiv32(add32(r(0x536414),y),2);}
    }
    w(at(0x511798,boat,0x28),markX);w(at(0x511d18,boat,0x28),markY);
    w(at(0x4f4d78,other),markX);w(at(0x4fc350,other),markY);
   }
   if(otherLeg>2&&r(0x4da194)<11){w(at(0x4f4d78,other),x);w(at(0x4fc350,other),y);w(at(0x511790,boat,0x28),x);w(at(0x511d10,boat,0x28),y);}
  }
 }
 const finalLeg=r(0x4da1e4);
 leg=rb(0x4f8538);
 if(leg===sub32(finalLeg,1)&&r(0x536408)===1&&rb(0x4fe2b0)===1)wb(0x4fe2b0,2);
 if(leg===finalLeg){
  wb(0x4fe2b0,0);
  if(r(0x4f6a58)===0){w(0x4f6d64,add32(r(0x4f6d64),1));if(boat<=r(0x4da140))w(0x534d64,r(0x4f8cd0));}
  if(r(0x4f6a58)>0)w(0x4f6d64,add32(r(0x4da194),1));
 }
 leg=add32(leg,1);wb(0x4f8538,leg);
 wb(0x4f4d78,r(at(0x511780,add32(leg,imul32(boat,10)))));wb(0x4fc350,r(at(0x511d00,add32(leg,imul32(boat,10)))));
 if(boat>r(0x4da140))wb(0x4f4350,r(0x4f8cd0));
 if(leg>finalLeg){
  if(r(0x53527c)===0){wb(0x4f4d78,r(at(0x5117a4,boat,0x28)));wb(0x4fc350,r(at(0x511d24,boat,0x28)));}
  else{
   if(!options.rng)throw new TypeError('Original2010 target advancement requires RNG');
   wb(0x4f4d78,add32(sub32(scaledRandom(60,options.rng),30),r(0x4f6d38)));
   wb(0x4fc350,add32(sub32(scaledRandom(60,options.rng),30),r(0x4f7f88)));
  }
 }
 if(rb(0x4f8538)>r(0x4da1e4)){
  wb(0x4fe638,r(0x4f6d64));
  const sound=id=>{if(r(0x536484)===0)options.playSound?.({resourceId:id,moduleHandle:memory.readU32(0x5359c8),flags:0x40005});};
  if(r(0x4f6d64)===1)sound(r(0x5364c8)===0?0x8c:0x8e);
  if(boat<=r(0x4da140)&&r(0x4f6d64)>1)sound(0x8e);
  if(boat===1||(boat===2&&r(0x4da140)===2)){w(0x522f20,r(0x4da174));w(0x5362f0,r(0x4da178));}
  if(rb(0x4fe638)>0&&r(0x536424)<1&&boat<=r(0x4da140)){wb(0x5116e0,11);wb(0x535620,r(0x4f8cd0));}
  if(r(0x4fe63c)>0&&r(0x536424)===1&&r(0x4da140)===1){w(0x5363f4,1);w(0x5363fc,add32(r(0x5363fc),1));}
  let allFinished=true;
  for(let other=1;other<=r(0x4da194);other++)if(r(at(0x4fe638,other))===0)allFinished=false;
  if(allFinished){w(0x5363f4,1);w(0x5363fc,add32(r(0x5363fc),1));}
 }
 if(r(0x5363f8)===1&&r(0x5363f4)===1)w(0x4da168,0);
}
