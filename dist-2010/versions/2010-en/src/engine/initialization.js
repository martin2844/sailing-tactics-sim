import { add32,sub32,imul32,idiv32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { scaledRandom } from '../../../../src/engine/integer-core.js';
import { initializeConfiguration } from './configuration.js';
import { initializeWind,initializeTide,initializeWindSources,respawnWindPatch } from './wind-initialization.js';
import { updateGlobalWind } from './wind.js';
import { resetBoat } from './movement-history.js';
import { placeStartingBoats } from './starting-positions.js';
import { initializeCourse } from './course.js';
import { writeCString,readAnsiString } from '../render/text.js';

export const INITIALIZATION_ROUTINES=Object.freeze({initializeBoats:0x42b2e0,
  placeStartingBoats:0x42f530,initializeCourse:0x42dea0,initializeRace:0x41be70});

const fixedNameAddresses=[0x4dd6f0,0x4dd6e8,0x4dd6e0,0x4dd6d8,0x4dd6d0,0x4dd6c8,
  0x4dd6c0,0x4dd6b8,0x4dd6b0,0x4dd6a8,0x4dd6a0,0x4dd698,0x4dd690,0x4dd688,
  0x4dd680,0x4dd678,0x4dd670,0x4dd668,0x4dd660,0x4dd658,0x4dd650,0x4dd648,
  0x4dd640,0x4dd634,0x4dd62c,0x4dd624,0x4dd61c,0x4dd614,0x4dd60c];
const playerNameAddresses=[0x4db774,0x4db76c,0x4db764,0x4db75c,0x4db754,0x4db750,
  0x4db744,0x4db73c,0x4db734,0x4db72c,0x4db724,0x4db71c,0x4db700,0x4db714,0x4db70c];

/** Complete42b2e0, including original placement/reset calls and semantic CString names. */
export function initializeBoats(memory,rng,options={}) {
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  const random=range=>scaledRandom(range,rng);
  const fill=(address,count,value)=>{
    if(count<=0)return;
    const bytes=new Uint8Array(count*4),view=new DataView(bytes.buffer);
    for(let index=0;index<count;index++)view.setInt32(index*4,value,true);
    memory.writeBytes(address,bytes);
  };
  const venue=r(0x4da1f8);
  fill(0x5135a0,0x3cab,-10000);fill(0x525ab8,0x3cab,-10000);fill(0x500420,0x3cab,-1);
  w(0x4f8dbc,-1);w(0x4f7f90,-1);w(0x534ea8,0);w(0x536394,0);
  memory.writeBytes(0x536230,memory.readBytes(0x5359f0,8));w(0x4fb9ac,0);w(0x4fb9b0,0);
  if(venue!==999)w(0x536524,0);
  for(const address of[0x4da220,0x4da228])w(address,-30000);
  for(const address of[0x4da21c,0x4da224])w(address,30000);
  w(0x4fe770,r(0x4f69b8)<2?128:64);w(0x536418,0);
  if(r(0x4fb5d4)===1||[2,3,11,9].includes(venue))w(0x4fe770,512);
  for(let value=40,index=0;value<131;value+=10,index++)w(0x4f8d84+index*4,value);
  w(0x4da208,venue===0?(r(0x4da19c)===8?75:500):2000);
  const venueDistance={1:2000,2:2000,4:1800,5:1800,7:3000,10:2500,100:1500,101:2500,103:3000,105:1100};
  if(venueDistance[venue]!==undefined)w(0x4da208,venueDistance[venue]);
  w(0x4fe630,-700);
  if(r(0x4da1e8)===1&&(r(0x4da194)<11||r(0x4da19c)===8))w(0x4da1e8,0);
  for(const[address,value]of[[0x4da1cc,-1],[0x4da1e0,-500],[0x4f3f64,0],[0x4f3f68,0],
    [0x536428,0],[0x4da1a0,1000],[0x4da1a4,-300]])w(address,value);
  if(r(0x536470)===1){w(0x4da194,2);w(0x4fe9d8,0);w(0x4da190,7);}
  w(0x4da170,sub32(random(25),102));
  for(const base of[0x4f3f60,0x5359e0,0x4f49a0,0x512d60,0x4faf80,0x4fbab0])fill(base,3,0);
  fill(0x4f71c0,3,2);fill(0x50f6d0,3,4);fill(0x4f3998,3,20000);
  w(0x4fc3e4,r(0x4da19c)===8?90:89);
  for(let index=0;index<3;index++){
    const address=0x525a78+index*4;
    if(r(address)<0||r(address)>2)w(address,1);
  }
  let boatCount=r(0x4da194);
  for(let boat=1;boat<=boatCount;boat++){
    const offset=(boat-1)*4;
    w(0x4fe8ac+offset,0);w(0x4fad44+offset,r(0x4f42b8));w(0x536244+offset,0);
    w(0x5232ec+offset,add32(random(6),12));
    if(r(0x4fb5d4)===1)w(0x5232ec+offset,add32(add32(random(6),15),r(0x4da1fc)));
    if(r(0x4da1f8)>0&&r(0x4da1f8)!==5)w(0x5232ec+offset,8);
    if(r(0x4da1f8)===999&&r(0x4da248)===2)w(0x5232ec+offset,add32(sub32(random(4),1),r(0x4da1fc)));
    w(0x4f447c+offset,0);if(r(0x5363f8)===1)w(0x4da168,0);
    w(0x4faef4+offset,-1);
    for(const base of[0x4f4534,0x522e6c,0x4f4a74,0x4fe6d4])w(base+offset,0);
    w(0x4fe188+(boat-1)*8,0);w(0x4fe18c+(boat-1)*8,0);w(0x522ff4+offset,1);
    if(r(0x5363fc)===0)w(0x4f49bc+offset,sub32(idiv32(random(499),200),1));
    w(0x522dd4+offset,-700);w(0x5230f4+offset,-1000);w(0x522c24+offset,-1000);
    const speedLevel=r(0x4da198),boardFlag=r(0x5363c0);
    if(r(0x4da140)<boat){
      let rate=add32(add32(add32(r(0x4f49bc+offset),idiv32(sub32(speedLevel,7),2)),-1),r(0x4fc3e4));
      if(speedLevel>9)rate=add32(rate,1);
      if(boardFlag===1)rate=sub32(rate,2);
      if(r(0x4da194)===2)rate=sub32(rate,2);
      if(speedLevel>11)rate=add32(rate,1);if(speedLevel>13)rate=add32(rate,1);
      if(speedLevel===1)rate=idiv32(imul32(rate,85),100);
      w(0x4fc3e4+offset,rate);
    }
    w(0x4f42c4+offset,r(0x4da190)===10||r(0x5363c4)===1||boardFlag>0||r(0x4da190)===8||r(0x53652c)===1?3:2);
    const phase=random(25);boatCount=r(0x4da194);w(0x4fadd4+offset,boatCount===2?0:phase);
    w(0x5350dc+offset,0);
    for(const base of[0x4f4354,0x4fe9d4,0x535624])w(base+offset,-2000);
    w(0x4fe63c+offset,0);
    if(r(0x5363fc)===0)for(let word=0;word<3;word++)w(0x4fbf34+(boat-1)*16+word*4,0);
  }
  const humanPlayers=r(0x4da140);
  if(humanPlayers>0){
    for(const base of[0x4f6a6c,0x4fbbac,0x4f7124,0x5116e4])fill(base,humanPlayers&0x3fffffff,0);
    w(0x4f4520,0);w(0x4f4524,0);
    for(const base of[0x4f7ee4,0x4fe77c])fill(base,humanPlayers&0x3fffffff,1);
    fill(0x500384,humanPlayers&0x3fffffff,-1);
  }
  memory.writeF64(0x536230,r(0x4f42b8));
  for(const[address,value]of[[0x534d64,30000],[0x5233a8,1],[0x536460,0],[0x536464,0],[0x536394,0]])w(address,value);
  if(r(0x536470)===1)memory.writeF64(0x536230,0);
  const baseRate=r(0x4fc3e4);
  if(boatCount===2){w(0x4fc3e8,add32(sub32(r(0x4da198),10),baseRate));if(r(0x5363c0)===1)w(0x4fc3e8,sub32(r(0x4fc3e8),1));}
  if(humanPlayers===2)w(0x4fc3e8,add32(r(0x536400),baseRate));
  w(0x4faf90,1);w(0x534fdc,add32(r(0x4f42b8),10));
  for(const address of[0x4f6d64,0x536404,0x534ea8,0x4f6d2c,0x534e94,0x534ea4,
    0x4fe768,0x4fafa0,0x5350d4,0x525a64])w(address,0);
  for(let boat=1;boat<=boatCount;boat++){
    if(r(0x536470)===0){(options.resetBoat??resetBoat)(memory,boat,options);boatCount=r(0x4da194);}
    else w(0x4f8538+boat*4,1);
  }
  for(let boat=1;boat<=r(0x4da194);boat++){
    (options.resetBoat??resetBoat)(memory,boat,options);
    const offset=(boat-1)*4;
    let x,y;
    if(r(0x53527c)===1){x=add32(sub32(random(200),100),r(0x4f6d38));y=add32(sub32(random(200),100),r(0x4f7f88));}
    else if(r(0x5364c8)!==0||r(0x53640c)!==0){
      x=add32(idiv32(add32(r(0x5229d4),imul32(r(0x536410),2)),3),sub32(random(100),50));
      y=add32(idiv32(add32(r(0x522ac8),imul32(r(0x536414),2)),3),sub32(random(100),50));
    }else if(r(0x4da19c)===8||r(0x4da1f8)===5){
      x=add32(idiv32(add32(r(0x5229d4),imul32(r(0x536410),8)),9),sub32(random(300),150));
      y=add32(idiv32(add32(r(0x522ac8),imul32(r(0x536414),8)),9),sub32(random(300),150));
    }else{
      const drawX=random(300);x=add32(sub32(drawX,150),idiv32(add32(r(0x5229d4),imul32(r(0x536410),3)),4));
      const drawY=random(300);y=add32(sub32(drawY,150),idiv32(add32(r(0x522ac8),imul32(r(0x536414),3)),4));
    }
    w(0x4fb54c+offset,x);w(0x522af4+offset,y);
  }
  (options.placeStartingBoats??placeStartingBoats)(memory,rng,options);
  fill(0x53601c,0x7b,0);
  if(r(0x4da1d8)<3){w(0x511624,1);if(r(0x4da140)===2)w(0x511628,1);}
  w(0x4da1e4,r(0x53527c)===1&&r(0x536408)===0?(r(0x4da194)<16?4:6):8);
  w(0x5233a4,0);boatCount=r(0x4da194);
  for(let boat=0;boat<boatCount;boat++){
    const inputOffset=boat*8;
    for(let row=0;row<22;row++){
      const offset=add32(inputOffset+8,imul32(-row,0x130));
      memory.writeBytes((0x511108+offset)>>>0,memory.readBytes(0x4f1618+inputOffset,8));
      memory.writeBytes((0x525770+offset)>>>0,memory.readBytes(0x4f3870+inputOffset,8));
    }
  }
  if(r(0x5364c8)===1){w(0x512d64,1);w(0x512d68,1);w(0x4da14c,1);}
  for(const[index,address]of fixedNameAddresses.entries())writeCString(memory,0x4fec38+index*4,readAnsiString(memory,address));
  const name=r(0x4da1f0);
  if(name>=1&&name<=15)writeCString(memory,0x4fec34,readAnsiString(memory,playerNameAddresses[name-1]));
}

/** Complete41be70, preserving configuration, wind and initialization call order. */
export function initializeRace(memory,rng,options={}) {
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  if([3,4,6].includes(r(0x4da188))||r(0x4da19c)===8)w(0x4da1e8,0);
  w(0x5364e0,0);initializeConfiguration(memory,rng,options);
  w(0x5363f4,0);w(0x5359f4,0xc0655000);w(0x500418,r(0x4da19c)===8?675:300);
  w(0x4f42b8,-170);w(0x4f8cd0,-170);
  if(r(0x4da1d8)<3){w(0x4f42b8,0);w(0x4f8cd0,0);w(0x5359f4,0);}
  if(r(0x4da1d8)===10){w(0x4f42b8,-340);w(0x4f8cd0,-340);w(0x5359f4,0xc0755000);}
  w(0x5359f0,0);
  const clock=Float80.fromNumber(memory.readF64(0x5359f0));
  memory.writeF64(0x534d68,clock.multiply(Float80.fromNumber(memory.readF64(0x4cc768))).toNumber());
  memory.writeBytes(0x535bc0,memory.readBytes(0x5359f0,8));
  if(r(0x4da1f8)<999)w(0x536510,0);
  initializeWind(memory,rng);initializeTide(memory,rng);updateGlobalWind(memory,rng,options);initializeWindSources(memory,rng);
  (options.initializeCourse??initializeCourse)(memory,1,rng,options);initializeBoats(memory,rng,options);
  for(let patch=1;patch<=5;patch++){w(0x523630+patch*4,-300);respawnWindPatch(memory,patch,rng,options);}
}
