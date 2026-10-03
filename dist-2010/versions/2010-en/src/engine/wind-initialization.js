import { add32,sub32,imul32,idiv32,i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { wrapDegreesOnce,scaledRandom } from '../../../../src/engine/integer-core.js';

export const WIND_INITIALIZATION_ADDRESSES=Object.freeze({
  initializeWind:0x426ab0,initializeTide:0x427090,initializeWindSources:0x441400,
  respawnWindPatch:0x42b0b0,windSetting:0x4da154,tideSetting:0x4da158,
  course:0x4da19c,venue:0x4da1f8,humanPlayers:0x4da140,island:0x4f8b78,
  weather:0x4f69b8,thermalReversal:0x53645c,offshoreCourseFlag:0x536454,
  customShoreMode:0x4da248,customShoreDirection:0x4da23c,
  customShoreSign:0x4da214,customThermalDirection:0x4da268,
  customFirstX:0x4da240,customFirstY:0x4da244,
  customSecondX:0x4da254,customSecondY:0x4da258,
  customShoreEnabled:0x4da260,customAngle:0x4f4afc,customShoreStrength:0x522f08,
  customNoTide:0x536514,forceVenueDirection:0x4fb5d4,
  customOppositeShoreFlag:0x53646c,channelSide:0x536300,
  optimistFlag:0x5363cc,shore:0x5230dc,
  baseStrength:0x4fe074,windSector:0x4fad38,baseDirection:0x4f46a8,
  shiftSide:0x5359d8,driftSector:0x5116b0,driftSectorSide:0x523244,
  driftRate:0x535204,strongDrift:0x4f8b74,
  sunFactor:0x511cf8,dailyMaximum:0x4fe76c,cloudFactor:0x4f8d78,
  dailyMinimum:0x4faf8c,thermalGain:0x4fea5c,startHour:0x4faa58,hour:0x4f6d60,
  meanDirection:0x4f7f94,tideAmplitude:0x5359d0,tideDirection:0x523a54,
  tideTargetDirection:0x522d28,tideHour:0x4fe9cc,tidePhaseHour:0x4ffdd0,
  primaryDirection:0x511570,primaryStrength:0x4f4868,primaryWidth:0x4f4e28,
  shoreDirection:0x51155c,shoreStrength:0x4f4854,
  direction:0x5362d4,strength:0x522ad0,condition:0x51158c,time:0x4f8cd0,
  boatX:0x4f6af8,boatY:0x4f6c10,patchX:0x535460,patchY:0x4f4b08,
  patchStrength:0x4f71d8,patchNextTime:0x523630,patchWidth:0x4f7ea0,
  patchSpeed:0x4f42a0,patchDirection:0x5357d8,
  windChangeSpeed:0x4da160,degreeFactor:0x4cc568,
});

/** Complete 0x426ab0, including venue/custom rules and original RNG ordering. */
export function initializeWind(memory,rng) {
  const a=WIND_INITIALIZATION_ADDRESSES;
  const r=field=>memory.readI32(a[field]),w=(field,value)=>memory.writeI32(a[field],value);
  const random=range=>scaledRandom(range,rng);
  let value=random(4);
  w('baseStrength',add32(imul32(value,3),10));
  if(r('windSetting')===1)w('baseStrength',add32(idiv32(value,2),9));
  if(r('windSetting')===2)w('baseStrength',add32(value,12));
  if(r('windSetting')===3)w('baseStrength',add32(idiv32(value,2),15));
  value=random(79);w('windSector',add32(idiv32(value,10),1));
  if(r('course')===9){
    if((r('windSector')&1)===0)w('windSector',add32(idiv32(value,10),2));
    if(r('windSector')===7)w('windSector',1);
  }
  if(r('course')===10)w('windSector',r('windSector')>4?5:1);
  if(r('windSector')>8)w('windSector',1);
  if(r('island')===1)w('windSector',add32(idiv32(random(29),10),4));
  if(r('course')===8){
    if(r('island')===0)w('windSector',random(10)<5?7:3);
  }else if(r('island')===0&&r('humanPlayers')===2&&r('venue')===0)w('windSector',1);
  w('baseDirection',wrapDegreesOnce(add32(add32(random(14),-52),imul32(r('windSector'),45))));
  if(r('venue')===5){
    w('windSector',add32(idiv32(random(29),10),4));
    if(random(100)<25){w('windSector',random(100)>49?2:1);w('customOppositeShoreFlag',1);w('customShoreSign',-1);}
    w('baseDirection',sub32(imul32(r('windSector'),45),45));
    if(r('windSector')===1)w('baseDirection',30);
    if(r('windSector')===2)w('baseDirection',sub32(r('baseDirection'),20));
    if(r('windSector')===4)w('baseDirection',add32(r('baseDirection'),20));
    if(r('windSector')>5)w('baseDirection',sub32(r('baseDirection'),10));
  }
  w('shiftSide',r('venue')===0?(random(10)<5?1:0):1);
  if(r('venue')===6||r('venue')===104||r('venue')===105)w('shiftSide',0);
  value=random(10);
  if(value<6)w('driftSector',add32(r('windSector'),2));
  w('driftSectorSide',value>=6?1:0);
  if(r('driftSector')>8)w('driftSector',sub32(r('driftSector'),8));
  if(value>5)w('driftSector',sub32(r('windSector'),2));
  if(r('driftSector')<1)w('driftSector',add32(r('driftSector'),8));
  if(r('venue')===999&&r('customShoreMode')===2){
    if(r('customOppositeShoreFlag')===1){w('customShoreSign',-1);value=add32(r('customShoreDirection'),90);}
    else{w('customShoreSign',1);value=sub32(r('customShoreDirection'),90);}
    w('customThermalDirection',wrapDegreesOnce(value));
    w('windSector',add32(idiv32(r('customThermalDirection'),45),1));
    if(r('windSector')>8)w('windSector',sub32(idiv32(r('customThermalDirection'),45),7));
    w('baseDirection',r('customThermalDirection'));w('meanDirection',r('customThermalDirection'));
    if(r('windSector')<1)w('windSector',add32(r('windSector'),8));
  }
  w('driftRate',sub32(random(5),2));
  if([1,2,8].includes(r('driftSector')))w('driftRate',add32(random(3),3));
  if([4,5,6].includes(r('driftSector')))w('driftRate',sub32(sub32(0,random(3)),3));
  if(r('thermalReversal')===1)w('driftRate',sub32(0,r('driftRate')));
  value=r('driftRate');w('strongDrift',(value<0?sub32(0,value):value)>3?1:0);
  if(r('course')===8)w('driftRate',idiv32(r('driftRate'),2));
  w('sunFactor',3);w('dailyMaximum',85);w('cloudFactor',1);
  if(r('windSector')>7||r('windSector')<3){w('sunFactor',1);w('dailyMaximum',75);}
  if(r('windSector')===7||r('windSector')===3){w('sunFactor',2);w('dailyMaximum',80);}
  if(r('windSector')===2||r('windSector')===3)w('cloudFactor',3);
  if(r('windSector')===4||r('windSector')===5)w('cloudFactor',2);
  if(r('windSetting')===1)w('cloudFactor',3);
  w('dailyMinimum',add32(random(10),r('venue')<6?48:58));
  if(r('venue')===106)w('dailyMinimum',add32(random(4),68));
  w('thermalGain',idiv32(imul32(sub32(r('dailyMaximum'),r('dailyMinimum')),3),imul32(imul32(r('cloudFactor'),r('sunFactor')),2)));
  if(r('cloudFactor')>2)w('thermalGain',0);
  if(r('windSetting')===1&&r('thermalGain')>2)w('thermalGain',2);
  if(r('windSetting')===2&&r('thermalGain')>7)w('thermalGain',7);
  if(r('weather')>0&&r('weather')<5)w('thermalGain',0);
  if(r('venue')===103||r('venue')===105)w('thermalGain',0);
  if(r('venue')===999&&r('customShoreMode')===2)w('thermalGain',idiv32(r('thermalGain'),2));
  value=r('offshoreCourseFlag')===1?21:add32(random(4),10);
  w('startHour',value);w('hour',value);
}

/** Complete 0x427090. Disabled current retains all other prior tide fields. */
export function initializeTide(memory,rng) {
  const a=WIND_INITIALIZATION_ADDRESSES;
  const r=field=>memory.readI32(a[field]),w=(field,value)=>memory.writeI32(a[field],value);
  const random=range=>scaledRandom(range,rng);
  if((r('tideSetting')===0&&r('weather')!==4)||(r('weather')>0&&r('weather')<4)
    ||r('venue')===10||r('venue')===12||r('venue')===103){w('tideAmplitude',0);return;}
  w('tideAmplitude',add32(random(8),7));
  w('tideDirection',wrapDegreesOnce(imul32(r('shore'),90)));
  if(r('weather')===4){w('tideAmplitude',add32(random(4),11));w('tideDirection',r('channelSide')===1?170:80);}
  w('tideTargetDirection',r('tideDirection'));
  if(r('tideSetting')===1){
    const setStrength=(venue,range,addition)=>{if(r('venue')===venue)w('tideAmplitude',add32(random(range),addition));};
    setStrength(1,9,11);setStrength(2,7,9);setStrength(3,7,9);
    if(r('forceVenueDirection')===1)w('tideAmplitude',add32(random(9),11));
    setStrength(6,7,9);setStrength(7,9,11);setStrength(9,9,12);setStrength(11,9,11);
    setStrength(105,9,11);setStrength(104,9,11);setStrength(100,9,11);
    setStrength(101,4,5);setStrength(102,9,11);setStrength(106,20,30);
    if(r('venue')===999){
      const first=r('customFirstX')===-1&&r('customFirstY')===-1?1:0;
      const second=r('customSecondX')===-1&&r('customSecondY')===-1?1:0;
      w('tideAmplitude',add32(random(5),9));
      if(first===1)w('tideAmplitude',add32(random(5),10));
      if(r('customShoreMode')>0&&r('customShoreEnabled')===1)w('tideAmplitude',add32(random(5),10));
      if(r('customShoreMode')===2&&r('customShoreEnabled')===1)w('tideAmplitude',add32(random(4),9));
      let lowCurrent=r('customAngle')>30&&r('customAngle')<150&&r('customShoreStrength')===10;
      if(first+second===2&&(r('customAngle')<50||r('customAngle')>130))lowCurrent=false;
      if((r('customShoreMode')===0||r('customShoreEnabled')===0)
        &&(r('customAngle')<50||r('customAngle')>130)&&first+second===1)lowCurrent=false;
      if(lowCurrent)w('tideAmplitude',3);
      if(r('customNoTide')===1)w('tideAmplitude',0);
    }
    if(r('optimistFlag')===1)w('tideAmplitude',idiv32(r('tideAmplitude'),2));
  }
  if(r('venue')===1)w('tideTargetDirection',180);
  if(r('venue')===6)w('tideTargetDirection',190);
  if(r('venue')===7)w('tideTargetDirection',150);
  w('tideDirection',r('tideTargetDirection'));
  const value=random(12);w('tideHour',add32(value,7));w('tidePhaseHour',add32(value,value<5?13:1));
}

/** Complete 0x441400, seven primary sources and five venue/shore sources. */
export function initializeWindSources(memory,rng) {
  const a=WIND_INITIALIZATION_ADDRESSES,random=range=>scaledRandom(range,rng);
  for(let index=0,base=400;index<7;index++,base+=50){
    memory.writeI32(a.primaryDirection+index*4,add32(add32(random(20),base),-450));
    memory.writeI32(a.primaryStrength+index*4,add32(random(15),3));
    memory.writeI32(a.primaryWidth+index*4,add32(random(40),20));
  }
  let direction=sub32(imul32(memory.readI32(a.shore),90),90);
  const venue=memory.readI32(a.venue);if(venue===103)direction=310;
  const offsets=[-45,-25,8,20,35];
  if(venue===0){
    for(const [index,range,addition]of [[0,4,1],[1,7,3],[2,7,3],[3,7,3],[4,4,1]]){
      memory.writeI32(a.shoreDirection+index*4,add32(direction,offsets[index]));
      memory.writeI32(a.shoreStrength+index*4,add32(random(range),addition));
    }
  }else{
    for(const [index,strength]of [3,6,7,7,3].entries()){
      memory.writeI32(a.shoreDirection+index*4,add32(direction,offsets[index]));
      memory.writeI32(a.shoreStrength+index*4,strength);
    }
  }
}

/** Complete 0x42b0b0, including separately consumed venue width draws. */
export function respawnWindPatch(memory,patch,rng,options={}) {
  const a=WIND_INITIALIZATION_ADDRESSES;
  patch=i32(patch);
  const indexed=(address,stride)=>(address+Math.imul(patch,stride))>>>0;
  const r=field=>memory.readI32(a[field]),w=(field,value)=>memory.writeI32(a[field],value);
  const random=range=>scaledRandom(range,rng);
  const trunc=address=>Float80.fromNumber(memory.readF64(address)).truncI32();
  const distance=add32(random(2000),500);
  const direction=wrapDegreesOnce(add32(add32(random(140),r('direction')),-70));
  let x=trunc(a.boatX+8),y;
  if(r('humanPlayers')===1)y=trunc(a.boatY+8);
  else{
    x=idiv32(add32(x,trunc(a.boatX+16)),2);
    y=idiv32(add32(trunc(a.boatY+8),trunc(a.boatY+16)),2);
  }
  if(typeof options.trig?.extended!=='function')throw new TypeError('Load the 2010 native x87 reference before respawning wind');
  if(memory.readF64(a.degreeFactor)!==0.017453529976437735)throw new RangeError('Unexpected 2010 wind degree factor');
  const {sine,cosine}=options.trig.extended(direction);
  memory.writeF64(indexed(a.patchX,8),sine.multiply(Float80.fromInteger(distance)).add(Float80.fromInteger(x)).toNumber());
  memory.writeF64(indexed(a.patchY,8),Float80.fromInteger(y).subtract(cosine.multiply(Float80.fromInteger(distance))).toNumber());
  const strengthAddress=indexed(a.patchStrength,4);
  memory.writeI32(strengthAddress,add32(add32(random(2),imul32(r('condition'),2)),2));
  if(r('windSetting')===1)memory.writeI32(strengthAddress,2);
  const nextTime=Float80.fromInteger(add32(random(300),150))
    .multiply(Float80.fromNumber(memory.readF64(a.windChangeSpeed))).truncI32();
  memory.writeI32(indexed(a.patchNextTime,4),add32(nextTime,r('time')));
  memory.writeI32(indexed(a.patchWidth,4),add32(random(400),200));
  if(r('forceVenueDirection')===1)memory.writeI32(indexed(a.patchWidth,4),add32(random(400),300));
  if(r('venue')>0)memory.writeI32(indexed(a.patchWidth,4),add32(random(400),300));
  const speedRandom=random(idiv32(r('strength'),2));
  memory.writeI32(indexed(a.patchSpeed,4),add32(speedRandom,idiv32(r('strength'),2)));
  const jitter=sub32(random(4),2),strength=memory.readI32(strengthAddress);
  const center=r('direction');
  const finalDirection=r('thermalReversal')===0?add32(add32(jitter,imul32(strength,3)),center):add32(sub32(jitter,imul32(strength,3)),center);
  memory.writeI32(indexed(a.patchDirection,4),finalDirection);
  return r('thermalReversal')===0?center:finalDirection;
}
