import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { atan2Extended } from '../runtime/atan.js';
import { sinCosX87 } from '../runtime/transcendentals.js';
import { wrapRadiansOnce } from '../engine/angles.js';
import { wrapDegreesOnce } from '../engine/integer-core.js';
import { nativeTrig } from '../engine/native-trig.js';
import { targetRelativeBearing } from '../engine/target-bearing.js';

const f=value=>Float80.fromNumber(value);
const signedDegrees=value=>{value=wrapDegreesOnce(value);return value>180?sub32(value,360):value;};

/** Complete original 0x42ad00: Manhattan radius around the three course marks. */
export function nearCourseMark(memory,radius,boat) {
  radius=i32(radius);boat=i32(boat);
  const x=f(memory.readF64(0x4a49e8+boat*8)).truncI32(),y=f(memory.readF64(0x4a4ae0+boat*8)).truncI32();
  const abs=value=>value<0?sub32(0,value):value;
  return [[0x4aa294,0x4aa388],[0x4aa38c,0x4aa588],[0x4aa288,0x4aa384]].some(([a,b])=>
    radius>=add32(abs(sub32(x,memory.readI32(a))),abs(sub32(y,memory.readI32(b)))))?1:0;
}

/** Complete original player camera helpers 0x415ac0 / 0x415c40. */
export function updateCameraHeading(memory,boat) {
  boat=i32(boat);if(boat!==1&&boat!==2)throw new RangeError('Original camera helper has only player1 and player2 variants');
  const r=address=>memory.readI32(address);
  const w=(address,value)=>memory.writeI32(address,value);
  const mode=0x4a4e88+boat*4,look=0x4a4608+boat*4,heading=0x4ac018+boat*4,wind=0x4aa5b0+boat*4,bearing=0x4a6830+boat*4;
  if(r(0x4aae20+boat*4)===1) {
    w(mode,2);if(r(0x4a5b80)<15&&r(0x4a5b80)>-30)w(mode,3);if(r(0x4a5b80)>=15&&r(0x4a5b80)<30)w(mode,1);
    if(nearCourseMark(memory,90,boat)===1)w(mode,3);
  }
  w(look,signedDegrees(r(look)));
  w(bearing,wrapDegreesOnce(add32(r(heading),r(look)===0&&r(0x4ac930)===0?imul32(r(0x4aa730+boat*4),-5):sub32(0,r(look)))));
  const forced=r(0x4a9440+boat*4);
  if(forced===-1||forced===1){w(bearing,wrapDegreesOnce(add32(r(wind),forced===-1?180:0)));w(look,wrapDegreesOnce(sub32(r(heading),r(bearing))));}
  if(forced===100&&(boat===1||r(0x491140)===2)) {
    const other=boat===1?2:1;
    const angle=targetRelativeBearing(memory,memory.readF64(0x4a49e8+other*8),memory.readF64(0x4a4ae0+other*8),0,boat);
    w(bearing,wrapDegreesOnce(angle.multiply(f(memory.readF64(0x484d78))).truncI32()));w(look,wrapDegreesOnce(sub32(r(heading),r(bearing))));
  }
}
export const updatePlayer1Camera=memory=>updateCameraHeading(memory,1);
export const updatePlayer2Camera=memory=>updateCameraHeading(memory,2);

/** Complete original 0x4060a0 unspilled projected-object sizing scalar. */
export function projectedSize(memory,y,boat) {
  y=i32(y);boat=i32(boat);
  let size=Float80.fromInteger(sub32(y,memory.readI32(0x491148))).multiply(f(memory.readF64(0x484cc8)));
  if(memory.readI32(0x4a4e88+boat*4)===1)size=size.multiply(f(memory.readF64(0x484cd0)));
  if(memory.readI32(0x4a763c)<900)size=size.multiply(f(memory.readF64(0x484cd8)));
  return size.subtract(f(memory.readF64(0x484ce0)));
}

/** Complete original 0x42c210 offset-eye distance and wrapped camera bearing. */
export function cameraRelativeBearing(memory,targetX,targetY,boat,options={}) {
  boat=i32(boat);
  const c=address=>f(memory.readF64(address));
  const heading=memory.readI32(0x4a6830+boat*4),radians=Float80.fromInteger(heading).multiply(c(0x484d40));
  const {sine,cosine}=nativeTrig(heading,options);
  const dy=c(0x4a4ae0+boat*8).subtract(cosine.multiply(c(0x485258))).subtract(f(targetY));
  const dx=f(targetX).subtract(c(0x4a49e8+boat*8).subtract(sine.multiply(c(0x484cc0))));
  const square=dy.multiply(dy).add(dx.multiply(dx));
  memory.writeF64(0x4a6828,square.compare(c(0x484e18))<=0?0:square.sqrt().toNumber());
  const angle=wrapRadiansOnce(atan2Extended(dx,dy).subtract(radians).toNumber());
  memory.writeI32(0x4ac66c,signedDegrees(f(angle).multiply(c(0x484d78)).truncI32()));
  return f(angle);
}

/** Complete original 0x42c2e0 distant/top camera projection. */
export function projectDistantPoint(memory,verticalScale,index,x,y,boat) {
  index=i32(index);boat=i32(boat);
  const c=address=>f(memory.readF64(address));
  const factor=c(0x4ab0c8).multiply(c(0x4851f0)).toNumber();
  const bearing=targetRelativeBearing(memory,x,y,-1,boat);
  memory.writeI32(0x4ac66c,signedDegrees(bearing.multiply(c(0x484d78)).truncI32()));
  const angle=wrapRadiansOnce(wrapRadiansOnce(bearing.toNumber()));
  if(memory.readF64(0x4a6828)>memory.readF64(0x485260))memory.writeF64(0x4a6828,1500);
  const {sine,cosine}=sinCosX87(f(angle)),distance=c(0x4a6828).multiply(c(0x485268));
  memory.writeI32(0x4aaa48+index*4,Float80.fromInteger(memory.readI32(0x4a4760)).subtract(cosine.multiply(f(factor)).multiply(distance).multiply(f(verticalScale))).truncI32());
  memory.writeI32(0x4a7c48+index*4,Float80.fromInteger(memory.readI32(0x4a3fa0)).add(sine.multiply(f(factor)).multiply(distance)).truncI32());
}

/** Complete original 0x42bfc0 near/distant first-person projection selector. */
export function projectScenePoint(memory,index,x,y,boat,selector,options={}) {
  index=i32(index);boat=i32(boat);selector=i32(selector);
  const c=address=>f(memory.readF64(address));
  const r=address=>memory.readI32(address);
  if(r(0x4a4e88+boat*4)===3){projectDistantPoint(memory,0.7,index,x,y,boat);return;}
  const horizon=r(0x491148),bearing=cameraRelativeBearing(memory,x,y,boat,options);
  const degrees=bearing.multiply(c(0x484d78)).truncI32(),limit=selector===99?70:130;
  if(degrees<=limit&&degrees>=-limit) {
    const {cosine}=sinCosX87(bearing),distance=c(0x4a6828).multiply(cosine);
    let depth=distance.toNumber();if(distance.compare(c(0x484d58))<0)depth=10;
    // 42c0ef retains eye-height and the projected row in ST0/ST1. The
    // decompiler's apparent doubles here have no FST instruction before
    // __ftol; spilling a value just below an integer changes visibility/sort.
    const height=Float80.fromInteger(r(0x4a4760)).subtract(Float80.fromInteger(horizon));
    let row;
    if(cosine.compare(c(0x484e18))<0) {
      const step=Float80.fromInteger(idiv32(r(0x4a72d0),9)).multiply(height);
      row=Float80.fromInteger(horizon).subtract(step.multiply(c(0x485060)));
      row=row.subtract(row.subtract(Float80.fromInteger(horizon).subtract(step.multiply(c(0x4850b0)))).multiply(f(depth)).multiply(c(0x485060)));
    }else row=Float80.fromInteger(horizon).add(Float80.fromInteger(idiv32(r(0x4a72d0),9)).multiply(height).divide(f(depth)));
    memory.writeI32(0x4aaa48+index*4,row.truncI32());
    const mode=r(0x4a4e88+boat*4);
    if(mode===1)depth=c(0x484f48).subtract(row.subtract(Float80.fromInteger(horizon)).multiply(c(0x485248)).divide(height)).multiply(c(0x4ab0c8)).toNumber();
    if(mode===2)depth=c(0x484cf0).subtract(row.subtract(Float80.fromInteger(horizon)).multiply(c(0x484e80)).divide(height)).multiply(c(0x4ab0c8)).toNumber();
    memory.writeI32(0x4a7c48+index*4,add32(bearing.multiply(f(depth)).multiply(c(0x485250)).truncI32(),r(0x4a3fa0)));return;
  }
  projectDistantPoint(memory,0.4,index,x,y,boat);
  if(r(0x4aaa48+index*4)<horizon)memory.writeI32(0x4aaa48+index*4,horizon);
}

export const FUN_004060a0=projectedSize;
export const FUN_0042c210=cameraRelativeBearing;
export const FUN_0042c2e0=projectDistantPoint;
export const FUN_0042bfc0=projectScenePoint;
