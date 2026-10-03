import { add32,sub32,imul32,idiv32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { scaledRandom,wrapDegreesOnce } from '../../../../src/engine/integer-core.js';
import { projectPoint } from './spatial-metrics.js';
import { advanceRaceTarget } from './race-targets.js';
import { initializeCourse } from './course.js';
import { sampleCurrent } from './current.js';

export const STARTING_POSITION_ROUTINE=0x42f530;
const absolute=value=>value<0?sub32(0,value):value;

/** Complete42f530, with original2010 close-hauled angles and paired-boat setup. */
export function placeStartingBoats(memory,rng,options={}){
  if(memory.readI32(0x4da194)>34)throw new RangeError('Original2010 placement overflows its 34-slot tack stack array above34 boats; normal menus cap boats at30');
  options={...options,rng,projectPoint:options.projectPoint??projectPoint,
    initializeCourse:options.initializeCourse??initializeCourse,sampleCurrent:options.sampleCurrent??sampleCurrent};
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  const random=range=>scaledRandom(range,rng),point=(...args)=>options.projectPoint(memory,...args,options);
  const angles=[],tacks=[];
  const selection=random(10);
  for(let boat=1;boat<=r(0x4da194);boat++){
    const offset=(boat-1)*4,positionOffset=(boat-1)*8;
    tacks[boat-1]=1;
    if(r(0x4da19c)===8)angles[boat-1]=180;
    else{
      angles[boat-1]=add32(random(40),110);
      if(random(100)>80&&r(0x4da140)<boat){tacks[boat-1]=-1;angles[boat-1]=sub32(-110,random(40));}
    }
    if(r(0x4da194)===2&&r(0x536470)===0){
      const first=selection<6?1:2,second=selection<6?2:1;
      angles[0]=selection<6?320:40;angles[1]=selection<6?40:320;
      w(0x522ff0+first*4,-1);w(0x535740+first*4,wrapDegreesOnce(add32(r(0x535208),145)));
      w(0x522ff0+second*4,1);w(0x535740+second*4,wrapDegreesOnce(sub32(r(0x535208),130)));
      if(second===1)w(0x535744,wrapDegreesOnce(sub32(r(0x535208),152)));
      if(first===1)w(0x535744,wrapDegreesOnce(add32(r(0x535208),167)));
    }
    if(r(0x4da194)===2)w(0x511624,0);
    w(0x4f4298,r(0x535748));
    const strength=r(0x522ad0),difficulty=r(0x4da190);
    let closehaul;
    if(r(0x5363b8)===0&&r(0x5363c4)===0&&r(0x53652c)===0){
      closehaul=add32(sub32(idiv32(strength,-3),idiv32(difficulty,6)),49);
    }else closehaul=sub32(46,idiv32(strength,8));
    if(r(0x5364bc)===1)closehaul=sub32(48,idiv32(strength,3));
    if(difficulty===3&&r(0x5363c4)===0)closehaul=add32(closehaul,2);
    if((r(0x5363c4)===1||r(0x53652c)===1)&&strength<10)closehaul=add32(closehaul,4);
    if(r(0x5363c0)===1)closehaul=add32(closehaul,2);
    if(difficulty===1&&strength<10)closehaul=add32(closehaul,5);
    if(difficulty===8)closehaul=sub32(closehaul,4);
    if(r(0x5363bc)===1)closehaul=strength<10?60:57;
    if(difficulty===1)closehaul=add32(sub32(closehaul,1),r(0x4fe77c));
    if(r(0x536528)===1&&strength<10)closehaul=add32(closehaul,4);
    if(r(0x53652c)===1&&strength<10)closehaul=add32(closehaul,4);
    w(0x4f7200,closehaul);
    if(r(0x4da194)>2||r(0x4da19c)===8){
      w(0x535744+offset,wrapDegreesOnce(r(0x4da19c)===8?r(0x535208):add32(imul32(closehaul,tacks[boat-1]),r(0x535208))));
      if(r(0x4da140)<boat)w(0x535744+offset,random(360));
    }
    memory.writeF64(0x4fe938,r(0x535744));
    const divisor=strength<11?5:4,width=r(0x523598);
    let distance=add32(random(idiv32(imul32(width,2),3)),idiv32(width,divisor));
    if(tacks[boat-1]<0)distance=add32(random(idiv32(width,2)),idiv32(width,divisor));
    if(r(0x4da194)===2)distance=idiv32(width,2);
    if(r(0x4da1d8)===10)distance=imul32(distance,2);
    const heading=wrapDegreesOnce(add32(r(0x535208),angles[boat-1]));
    if(r(0x4da194)===2)distance=idiv32(imul32(distance,8),3);
    point(r(0x4f4d7c+offset),r(0x4fc354+offset),distance,heading);
    memory.writeF64(0x4f6b00+positionOffset,r(0x4fe080));memory.writeF64(0x4f6c18+positionOffset,r(0x523180));
    if(r(0x5359d0)>0){
      if(typeof options.sampleCurrent!=='function')throw new TypeError('Original current sampler required for2010 initial boat placement');
      const current=options.sampleCurrent(memory,r(0x4fe080),r(0x523180),boat,options);
      const currentHeading=wrapDegreesOnce(r(0x536418));
      const third=idiv32(current,3);
      point(Float80.fromNumber(memory.readF64(0x4f6b00+positionOffset)).truncI32(),
        Float80.fromNumber(memory.readF64(0x4f6c18+positionOffset)).truncI32(),
        idiv32(imul32(absolute(third),r(0x523598)),30),currentHeading);
      memory.writeF64(0x4f6b00+positionOffset,r(0x4fe080));memory.writeF64(0x4f6c18+positionOffset,r(0x523180));
    }
  }
  if(r(0x4da194)>2&&r(0x4da19c)!==8){
    const blend=random(16);
    memory.writeF64(0x4f6b00,idiv32(add32(add32(imul32(blend,r(0x4fe094)),r(0x5229c8)),imul32(r(0x536410),sub32(16,blend))),17));
    memory.writeF64(0x4f6c18,idiv32(add32(add32(imul32(blend,r(0x4fe2a0)),r(0x522ac4)),imul32(r(0x536414),sub32(16,blend))),17));
    if(r(0x4da1f8)===5){
      memory.writeF64(0x4f6b00,idiv32(add32(r(0x5229c8),imul32(add32(r(0x4fe094),r(0x536410)),50)),101));
      memory.writeF64(0x4f6c18,idiv32(add32(r(0x522ac4),imul32(add32(r(0x4fe2a0),r(0x536414)),50)),101));
    }
  }
  if(r(0x4da1d8)<3){
    for(let boat=1;boat<=r(0x4da194);boat++){
      memory.writeF64(0x4f6b00+(boat-1)*8,r(0x4f4d7c+(boat-1)*4));
      memory.writeF64(0x4f6c18+(boat-1)*8,r(0x4fc354+(boat-1)*4));
      (options.advanceRaceTarget??advanceRaceTarget)(memory,boat,options);w(0x522ff0+boat*4,1);
    }
    if(r(0x4da19c)===8){w(0x511624,0);w(0x511628,0);}
    else{
      memory.writeF64(0x4fe938,wrapDegreesOnce(sub32(r(0x5362d4),r(0x4f7200))));
      w(0x535748,wrapDegreesOnce(sub32(r(0x5362d4),r(0x4f7200))));
    }
  }
  const count=r(0x4da194);
  if(count>0){
    memory.writeBytes(0x4fb098,memory.readBytes(0x4f6c18,count*8));
    memory.writeBytes(0x4f83c8,memory.readBytes(0x4f6b00,count*8));
    memory.writeBytes(0x4f3870,memory.readBytes(0x4f6c18,count*8));
    memory.writeBytes(0x4f1618,memory.readBytes(0x4f6b00,count*8));
  }
}
