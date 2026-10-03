import { add32,sub32,imul32,idiv32,i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { atan2Extended } from '../../../../src/runtime/atan.js';
import { wrapDegreesOnce,scaledRandom } from '../../../../src/engine/integer-core.js';

export const WIND_ADDRESSES=Object.freeze({
  routine:0x427540,schedule:0x427e30,bearing:0x427ee0,
  hour:0x4f6d60,dailyMinimum:0x4faf8c,dailyMaximum:0x4fe76c,
  thermalGain:0x4fea5c,weather:0x4f69b8,shore:0x5230dc,reversal:0x4f4510,
  venue:0x4da1f8,forceVenueDirection:0x4fb5d4,customThermalDirection:0x4da268,
  thermalReversal:0x53645c,baseDirection:0x4f46a8,baseStrength:0x4fe074,
  course:0x4da19c,driftRate:0x535204,driftClock:0x534d68,
  forceCondition:0x4f8db8,customShoreDirection:0x4da23c,
  customShoreStrength:0x522f08,customShoreMode:0x4da248,
  mode:0x536470,time:0x4f8cd0,resetTime:0x4f42b8,
  customLongShifts:0x536524,nextTime:0x534fdc,target:0x5364a8,
  range:0x522ae8,period:0x5233a0,targetIndex:0x4da1d0,timeIndex:0x4da1d4,
  smoothDirection:0x522f10,dt:0x523378,tidePhaseHour:0x4ffdd0,
  tideAmplitude:0x5359d0,cosine:0x4f1740,sine:0x4f85c8,randomTable:0x512d70,
  thermal:0x535ed0,thermalWind:0x4f8b7c,thermalDriftRate:0x5364f8,
  strength:0x522ad0,peakStrength:0x4fe08c,drift:0x522fe0,
  condition1:0x51158c,condition2:0x4fe15c,meanDirection:0x4f7f94,
  initialDirection:0x5359d4,direction:0x5362d4,tide:0x5229d8,
  bearingRadians:0x4f7f80,
  degreeFactor:0x4cc568,positiveTurnThreshold:0x4cc4d0,
  positiveRevolution:0x4cc8f0,negativeTurnThreshold:0x4cc8f8,
  negativeRevolution:0x4cc900,smoothingRate:0x4cc908,
  bearingScale:0x4cc910,bearingOffset:0x4cc4f8,
});

const indexed=(address,index)=>(address+Math.imul(i32(index),4))>>>0;

/** Original 0x427ee0, including its binary64 atan spill before integer return. */
export function bearingFromVector(memory,y,x,options={}) {
  const a=WIND_ADDRESSES;
  const angle=(options.atan2Extended??atan2Extended)(Float80.fromInteger(i32(y)),Float80.fromInteger(i32(x)));
  const result=Float80.fromNumber(memory.readF64(a.bearingOffset))
    .subtract(angle.multiply(Float80.fromNumber(memory.readF64(a.bearingScale))));
  memory.writeF64(a.bearingRadians,angle.toNumber());
  return wrapDegreesOnce(result.truncI32());
}

/** Complete original 0x427e30. Every product/add wraps as a signed x86 I32. */
export function scheduleWindShift(memory,center,range,period) {
  const a=WIND_ADDRESSES;
  center=i32(center);range=i32(range);period=i32(period);
  const targetIndex=memory.readI32(a.targetIndex),timeIndex=memory.readI32(a.timeIndex);
  const timeRandom=memory.readI32(indexed(a.randomTable,timeIndex));
  const targetRandom=memory.readI32(indexed(a.randomTable,targetIndex));
  memory.writeI32(a.nextTime,add32(add32(idiv32(imul32(timeRandom,7),10),period),memory.readI32(a.time)));
  const target=add32(sub32(idiv32(imul32(targetRandom,range),100),idiv32(range,2)),center);
  memory.writeI32(a.target,target);
  const followingTarget=add32(targetIndex,1),followingTime=add32(timeIndex,1);
  memory.writeI32(a.targetIndex,followingTarget>300?1:followingTarget);
  memory.writeI32(a.timeIndex,followingTime>300?1:followingTime);
  return target;
}

/**
 * Complete 2010 environmental wind update, original 0x427540.
 * The exact FSIN lookup is reusable numerical data: original FILD(angle), FMUL
 * stored factor bits3152cb9156df913f, FSIN. options.trig supplies the captured
 * reference for the active x87 precision. It is never an output-state lookup.
 * FPATAN's last extended bit remains subject to the shared numerical model's
 * documented hardware scope; every final field and store is compared strictly.
 */
export function updateGlobalWind(memory,rng,options={}) {
  const a=WIND_ADDRESSES;
  const read=field=>memory.readI32(a[field]);
  const write=(field,value)=>memory.writeI32(a[field],value);
  const constant=field=>Float80.fromNumber(memory.readF64(a[field]));
  if(memory.readF64(a.degreeFactor)!==0.017453529976437735)throw new RangeError('Unexpected 2010 wind degree factor');
  if(typeof options.trig?.extended!=='function')throw new TypeError('Load the 2010 native x87 reference before updating wind');
  const sine=angle=>options.trig.extended(angle).sine;
  const hour=read('hour'),minimum=read('dailyMinimum'),maximum=read('dailyMaximum');
  let thermal=add32(sine(imul32(sub32(hour,8),15)).multiply(Float80.fromInteger(sub32(maximum,minimum))).truncI32(),minimum);
  if(thermal<minimum)thermal=minimum;
  write('thermal',thermal);
  let thermalWind=idiv32(imul32(thermal,read('thermalGain')),maximum);
  const weather=read('weather');
  if(thermalWind<0||(weather>0&&weather<5))thermalWind=0;
  if(hour>22||hour<10)thermalWind=0;
  write('thermalWind',thermalWind);

  const venue=read('venue'),shore=read('shore'),reversal=read('reversal');
  let thermalDirection=imul32(add32(shore,1),90);
  if(reversal===1)thermalDirection=add32(thermalDirection,90);
  thermalDirection=wrapDegreesOnce(thermalDirection);
  let venueDirection=thermalDirection;
  if(venue===7||venue===1)venueDirection=190;
  if(read('forceVenueDirection')===1||venue===3)venueDirection=220;
  if(venue===2)venueDirection=135;
  if(venue===3)venueDirection=210;
  if(venue===6||venue===9)venueDirection=150;
  if(venue===10)venueDirection=225;
  if(venue===11)venueDirection=120;
  if(venue===12)venueDirection=80;
  if(venue===104)venueDirection=270;
  if(venue===100||venue===101||venue===102)venueDirection=220;
  if(venue===106)venueDirection=120;
  if(venue===999){thermalWind=idiv32(thermalWind,2);write('thermalWind',thermalWind);venueDirection=read('customThermalDirection');}
  const thermalDrift=read('thermalGain')<5||hour<11||hour>17?0:read('thermalReversal')!==0?-3:3;
  write('thermalDriftRate',thermalDrift);
  if(venue>0)thermalDirection=wrapDegreesOnce(venueDirection);
  const component=(table,angle,strength)=>idiv32(imul32(memory.readI32(indexed(a[table],angle)),strength),100);
  const baseDirection=wrapDegreesOnce(read('baseDirection')),baseStrength=read('baseStrength');
  const x=add32(component('cosine',baseDirection,baseStrength),component('cosine',thermalDirection,thermalWind));
  const y=add32(component('sine',baseDirection,baseStrength),component('sine',thermalDirection,thermalWind));
  const squared=add32(imul32(x,x),imul32(y,y));
  let strength=squared===0?baseStrength:Float80.fromInteger(squared).sqrt().truncI32();
  if(strength>22)strength=22;
  if(strength<9)strength=9;
  write('strength',strength);write('peakStrength',strength);
  if((strength>9&&hour>16)||hour<11)write('strength',sub32(strength,2));

  const driftMultiplier=read('course')===8||read('forceVenueDirection')===1?1:3;
  const vectorBearing=bearingFromVector(memory,y,x,options);
  const driftTime=Float80.fromNumber(memory.readF64(a.driftClock)).truncI32();
  const drift=idiv32(imul32(imul32(add32(thermalDrift,read('driftRate')),driftMultiplier),driftTime),60);
  const bearing=wrapDegreesOnce(add32(vectorBearing,drift));
  write('drift',drift);
  const condition=value=>{write('condition1',value);write('condition2',value);};
  if(venue===0){
    const relative=add32(sub32(bearing,imul32(shore,90)),90);
    const absolute=relative<0?sub32(0,relative):relative;
    condition(absolute<90||weather>0||read('forceCondition')===1||reversal===1?1:0);
  }
  if(venue>0)condition(0);
  if(venue===1||venue===7||venue===9||venue===10)condition(1);
  const previousDirection=read('direction');
  if(venue===2&&previousDirection>250&&previousDirection<360)condition(1);
  if(venue===3&&(previousDirection>250||previousDirection<70))condition(1);
  if(venue===6&&(previousDirection>230||previousDirection<130))condition(1);
  if(venue===11&&(previousDirection>230||previousDirection<90))condition(1);
  if(venue===12&&previousDirection>220&&previousDirection<300)condition(1);
  if(venue===103)condition(1);
  if(venue===105&&(previousDirection>290||previousDirection<70))condition(1);
  if(venue===106&&(previousDirection>130||previousDirection<70))condition(1);
  if(venue===104&&previousDirection>190&&previousDirection<350)condition(1);
  if(venue===100&&(previousDirection>260||previousDirection<210))condition(1);
  if(venue===101){
    if(previousDirection>110||previousDirection<35)condition(1);
    if(previousDirection<=110&&previousDirection>=35)condition(0);
  }
  if(venue===102&&(previousDirection>110||previousDirection<45))condition(1);
  if(venue===999){
    const relative=wrapDegreesOnce(sub32(previousDirection,read('customShoreDirection')));
    condition(relative<=90||read('customShoreStrength')>6||read('customShoreMode')===2?1:0);
  }

  const time=read('time');
  if(read('mode')===0){
    if(time<add32(read('resetTime'),10)){
      memory.writeF64(a.smoothDirection,bearing);
      write('direction',bearing);write('meanDirection',bearing);write('target',bearing);write('initialDirection',bearing);
    }else{
      if(read('condition1')===1){write('range',add32(scaledRandom(20,rng),20));write('period',add32(scaledRandom(20,rng),70));}
      else{write('range',add32(scaledRandom(15,rng),15));write('period',add32(scaledRandom(30,rng),95));}
      if(venue===0)write('period',sub32(read('period'),25));
      const reschedule=(range,period,periodRange,condition2)=>{
        write('range',add32(scaledRandom(range,rng),range));
        write('period',add32(scaledRandom(periodRange,rng),period));
        if(condition2!==undefined)write('condition2',condition2);
      };
      if(venue===5&&read('condition1')===0)reschedule(20,200,60,0);
      if((venue===7||venue===1||venue===9||venue===10)&&read('condition1')===0)reschedule(30,100,40,1);
      if(venue===104&&read('condition1')===0)reschedule(25,100,40,1);
      if((venue===105||venue===106)&&read('condition1')===0)reschedule(25,100,40,1);
      if(venue===999&&read('condition1')===0&&read('customLongShifts')===1)reschedule(25,100,40,1);
      if(venue===103)reschedule(30,100,40,1);
      if((venue===11||venue===104||venue===105||venue===106)&&read('condition2')===0)reschedule(25,100,40);
      if(read('nextTime')<time)write('target',scheduleWindShift(memory,bearing,read('range'),read('period')));
      const current=Float80.fromNumber(memory.readF64(a.smoothDirection));
      let difference=Float80.fromInteger(read('target')).subtract(current);
      if(difference.compare(constant('positiveTurnThreshold'))>0)difference=difference.subtract(constant('positiveRevolution'));
      if(difference.compare(constant('negativeTurnThreshold'))<0)difference=difference.subtract(constant('negativeRevolution'));
      const result=current.subtract(difference.multiply(Float80.fromNumber(memory.readF64(a.dt))).multiply(constant('smoothingRate')));
      // FST, then __ftol consumes the still-unspilled extended register.
      memory.writeF64(a.smoothDirection,result.toNumber());
      write('direction',wrapDegreesOnce(result.truncI32()));
    }
  }
  const tide=sine(imul32(sub32(read('hour'),read('tidePhaseHour')),30))
    .multiply(Float80.fromInteger(read('tideAmplitude'))).truncI32();
  write('tide',tide);
  return tide;
}
