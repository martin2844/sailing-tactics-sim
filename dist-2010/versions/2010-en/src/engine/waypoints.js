import { add32,sub32,imul32,i32 } from '../../../../src/runtime/c-types.js';
import { Float80,getX87ControlWord } from '../../../../src/runtime/float80.js';
import { scaledRandom } from '../../../../src/engine/integer-core.js';
const at=(base,index,stride=4)=>add32(base,imul32(index,stride))>>>0;
const f=(memory,address)=>Float80.fromNumber(memory.readF64(address));

/** Extended-exponent path for 0x4662d0, including its explicit X spill. */
export function clampedPointDistanceExtended(memory,x0,y0,x1,y1){
 const dx=Float80.fromNumber(x0).subtract(Float80.fromNumber(x1));
 const dy=Float80.fromNumber(y1).subtract(Float80.fromNumber(y0));
 const square=dy.multiply(dy).add(dx.multiply(Float80.fromNumber(dx.toNumber())));
 if(square.compare(f(memory,0x4cc658))<=0)return f(memory,0x4cc658);
 if(square.compare(f(memory,0x4cccc8))<0)return square.sqrt();
 return f(memory,0x4cccc0);
}

const normalOrZero=value=>Number.isFinite(value)&&(value===0||Math.abs(value)>=2.2250738585072014e-308);

// Only PC53 arithmetic with representable normal intermediates enters this
// path. Undefined selects the original extended-exponent implementation.
function normalClampedDistance(memory,x0,y0,x1,y1){
 if(!Number.isFinite(x0)||!Number.isFinite(y0)||!Number.isFinite(x1)||!Number.isFinite(y1))return;
 const dx=x0-x1,dy=y1-y0;
 if(!normalOrZero(dx)||!normalOrZero(dy))return;
 const xx=dx*dx,yy=dy*dy;
 if(!normalOrZero(xx)||!normalOrZero(yy)||(xx===0&&dx!==0)||(yy===0&&dy!==0))return;
 const square=yy+xx;
 if(!normalOrZero(square))return;
 const floor=memory.readF64(0x4cc658);
 if(!Number.isFinite(floor))return;
 if(square<=floor)return floor;
 const ceiling=memory.readF64(0x4cccc8);
 if(!Number.isFinite(ceiling))return;
 if(square<ceiling)return Math.sqrt(square);
 const cap=memory.readF64(0x4cccc0);
 if(Number.isFinite(cap))return cap;
}

/** Complete 0x4662d0. PC53 normal arithmetic has binary64 significand rounding. */
export function clampedPointDistance(memory,x0,y0,x1,y1){
 if(getX87ControlWord()===0x027f&&
    [x0,y0,x1,y1].every(value=>typeof value==='number'&&Number.isFinite(value))){
  const value=normalClampedDistance(memory,x0,y0,x1,y1);
  if(value!==undefined)return Float80.fromNumber(value);
 }
 // Binary64's exponent limits differ from x87. Keep the exact original path
 // for other control words, nonfinite inputs, subnormals and product underflow.
 return clampedPointDistanceExtended(memory,x0,y0,x1,y1);
}

/** Original extended scan, including the F64 spill after each new minimum. */
export function nearestWaypointDistanceExtended(memory,x,y,excluded){
 excluded=i32(excluded);
 let nearest=Float80.fromNumber(50000);
 for(let index=0;index<=memory.readI32(0x4da1f4);index++){
  if(excluded<0||index!==excluded){
   const distance=clampedPointDistanceExtended(memory,x,y,memory.readF64(at(0x4f7220,index,8)),memory.readF64(at(0x4ff038,index,8)));
   if(distance.compare(nearest)<0)nearest=Float80.fromNumber(distance.toNumber());
  }
 }
 return nearest;
}

/** Complete0x466230; PC53 normal distances and stored minima are binary64. */
export function nearestWaypointDistance(memory,x,y,excluded){
 if(getX87ControlWord()!==0x027f||typeof x!=='number'||typeof y!=='number')return nearestWaypointDistanceExtended(memory,x,y,excluded);
 excluded=i32(excluded);
 let nearest=50000;
 for(let index=0;index<=memory.readI32(0x4da1f4);index++){
  if(excluded<0||index!==excluded){
   const x1=memory.readF64(at(0x4f7220,index,8)),y1=memory.readF64(at(0x4ff038,index,8));
   const distance=normalClampedDistance(memory,x,y,x1,y1);
   if(distance!==undefined){
    if(distance<nearest)nearest=distance;
   }else{
    const extended=clampedPointDistanceExtended(memory,x,y,x1,y1);
    if(extended.compare(Float80.fromNumber(nearest))<0)nearest=extended.toNumber();
   }
  }
 }
 return Float80.fromNumber(nearest);
}

/** Complete0x465ff0, with allthree original collision attempts and RNG draws. */
export function respawnWaypoint(memory,index,rng,options={}){
 index=i32(index);
 const humans=memory.readI32(0x4da140);
 let boat=humans===1?1:index;
 if(humans===2)boat=(index%2!==0?1:0)+1;
 if(typeof options.trig?.extended!=='function')throw new TypeError('Original2010 waypoint requires native angle captures');
 const spawn=(xScale,yScale)=>{
  const xRandom=scaledRandom(880,rng);
  let pair=options.trig.extended(memory.readI32(at(0x4fbb90,boat)));
  const x=f(memory,at(0x4f6af8,boat,8)).subtract(pair.sine.multiply(f(memory,xScale))).subtract(f(memory,0x4cccb8)).add(Float80.fromInteger(xRandom));
  memory.writeF64(at(0x4f7220,index,8),x.toNumber());
  const yRandom=scaledRandom(880,rng);
  pair=options.trig.extended(memory.readI32(at(0x4fbb90,boat)));
  const y=f(memory,at(0x4f6c10,boat,8)).subtract(pair.cosine.multiply(f(memory,yScale))).subtract(f(memory,0x4cccb8)).add(Float80.fromInteger(yRandom));
  memory.writeF64(at(0x4ff038,index,8),y.toNumber());
 };
 const crowded=()=>nearestWaypointDistance(memory,memory.readF64(at(0x4f7220,index,8)),memory.readF64(at(0x4ff038,index,8)),index).compare(f(memory,0x4cc5a0))<0;
 spawn(0x4ccb40,0x4cc490);
 if(crowded())spawn(0x4cc928,0x4cc488);
 if(crowded())spawn(0x4cc928,0x4cc488);
}
