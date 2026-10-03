import { add32,sub32,imul32,i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { atanExtended } from '../../../../src/runtime/atan.js';
import { wrapDegreesOnce } from '../../../../src/engine/integer-core.js';
export const APPARENT_WIND_ADDRESSES=Object.freeze({routine:0x43bb70,angle:0x4fecc8,trueWind:0x4fb380,
  apparentSpeed:0x534eb8,apparentAngle:0x4f4cd8,heading:0x535740,tack:0x522ff0,apparentDirection:0x535890});
const at=(base,index)=>(add32(base,imul32(index,4)))>>>0;

/** Complete43bb70. Return is the original stored force, promoted back to x87. */
export function apparentWindExtended(memory,speed,boat,options={}){
 speed=i32(speed);boat=i32(boat);
 const a=APPARENT_WIND_ADDRESSES,r=base=>memory.readI32(at(base,boat)),w=(base,value)=>memory.writeI32(at(base,boat),value);
 const f=address=>Float80.fromNumber(memory.readF64(address)),n=Float80.fromInteger;
 const angle=r(a.angle),wind=r(a.trueWind);
 if(typeof options.trig?.extended!=='function')throw new TypeError('Original2010 apparent wind requires native integer-angle captures');
 const pair=options.trig.extended(angle);
 let cross=pair.sine.multiply(n(wind));
 const longitudinal=Float80.fromNumber(pair.cosine.multiply(n(wind)).subtract(n(speed).multiply(f(0x4cc8b0))).toNumber());
 if(cross.compare(f(0x4cc650))<0)cross=f(0x4cc650);
 const square=cross.multiply(cross).add(longitudinal.multiply(longitudinal));
 let force=Float80.fromNumber(square.toNumber());
 w(a.apparentSpeed,square.sqrt().truncI32());
 const attenuation={7:0x4cc630,8:0x4cc468,9:0x4cc400};
 if(wind>9)force=Float80.fromNumber(force.multiply(f(0x4cc8d0)).toNumber());
 if(Object.hasOwn(attenuation,wind))force=Float80.fromNumber(force.multiply(f(attenuation[wind])).toNumber());
 let apparentAngle;
 if(longitudinal.compare(f(0x4cc658))===0)apparentAngle=90;
 else if(cross.compare(f(0x4cc658))===0&&angle<5)apparentAngle=0;
 else if(cross.compare(f(0x4cc658))===0&&angle>=0)apparentAngle=179;
 else{
  const atan=options.atanExtended??atanExtended;
  if(longitudinal.compare(f(0x4cc658))>0)apparentAngle=atan(cross.divide(longitudinal)).multiply(f(0x4cc3e8)).truncI32();
  if(longitudinal.compare(f(0x4cc658))<0)apparentAngle=sub32(90,atan(longitudinal.divide(cross).negate()).multiply(f(0x4cc910)).truncI32());
  if(angle>179)apparentAngle=179;
 }
 w(a.apparentAngle,apparentAngle);
 w(a.apparentDirection,wrapDegreesOnce(r(a.tack)===1?add32(r(a.heading),apparentAngle):sub32(r(a.heading),apparentAngle)));
 return force;
}
export function apparentWind(memory,speed,boat,options={}){return apparentWindExtended(memory,speed,boat,options).toNumber();}
