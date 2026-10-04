import {Float80} from '../../../../src/runtime/float80.js';
import {certifiedSqrtNumber} from '../../../../src/runtime/certified-sqrt.js';
import {intervalAdd as add,intervalSub as sub,intervalMul as mul,intervalTruncI32,
  atan2Interval,sinX87Interval,cosX87Interval} from '../../../../src/runtime/output-interval.js';
import {fpDrawingEnabled} from './float-values.js';

const exact=value=>[value,value];
const valid=value=>value&&Number.isFinite(value[0])&&Number.isFinite(value[1])&&value[0]<=value[1];
const normal=value=>typeof value==='number'&&Number.isFinite(value)&&(value===0||Math.abs(value)>=2**-1022);
const bounded=value=>normal(value)&&Math.abs(value)<=1e9;
const i32=value=>typeof value==='number'&&Number.isInteger(value)&&value>=-2147483648&&value<=2147483647;
const difference=(a,b)=>{const value=a-b;return normal(value)&&(value!==0||a===b)?value:undefined;};

/** Certify the integer coordinates in the private 468440 chart-point windows. */
export function tryProjectChartPointOutputFast(memory,x,y,selector,camera,scale,centerX,centerY,clampDistance,options={}){
  if(!fpDrawingEnabled(options)||'events' in Number.prototype||'frame' in Number.prototype
    ||'dc' in Number.prototype||'array' in Number.prototype||!bounded(x)||!bounded(y)||!bounded(scale)
    ||!i32(selector)||!i32(camera)||camera<1||camera>30||!i32(centerX)||!i32(centerY)
    ||typeof clampDistance!=='boolean')return undefined;
  const originX=selector<2?memory.readF64(0x4f6af8+camera*8):memory.readI32(0x536410);
  const originY=selector<2?memory.readF64(0x4f6c10+camera*8):memory.readI32(0x536414);
  if(!bounded(originX)||!bounded(originY))return undefined;
  const dx=difference(x,originX),dy=difference(originY,y);
  if(dx===undefined||dy===undefined)return undefined;
  const xx=dx*dx,yy=dy*dy,square=yy+xx;
  if(!normal(xx)||!normal(yy)||!normal(square)||(xx===0&&dx!==0)||(yy===0&&dy!==0))return undefined;
  const originalDistance=certifiedSqrtNumber(square)??Float80.fromNumber(square).sqrt().toNumber();
  const zero=memory.readF64(0x4cc658),pi=memory.readF64(0x4cc740),degrees=memory.readF64(0x4cc3e8);
  if(!bounded(zero)||!bounded(pi)||Math.abs(pi)>10||!bounded(degrees)||Math.abs(degrees)>1000)return undefined;
  const bearing=dx===zero?exact(dy<=zero?pi:zero):atan2Interval(dx,dy);
  const absoluteDegrees=intervalTruncI32(mul(bearing,exact(degrees)));
  if(absoluteDegrees===undefined)return undefined;
  let angle=bearing;
  if(selector!==0&&selector<3){
    let headingAddress;
    if(selector===-1)headingAddress=0x4fbb90+camera*4;
    else if(selector===1||selector===2){
      const mode=memory.readI32(0x525a78+camera*4);
      if(mode===0)headingAddress=0x4fbb90+camera*4;
      else if(mode===1)headingAddress=0x535740+camera*4;
      else if(mode===2)headingAddress=0x522b90+camera*4;
    }
    angle=exact(dx);
    if(headingAddress!==undefined){
      const heading=memory.readI32(headingAddress),radians=memory.readF64(0x4cc568);
      if(!normal(radians)||radians<=0||radians>1)return undefined;
      angle=sub(bearing,mul(exact(heading),exact(radians)));
    }
  }
  if(!valid(angle))return undefined;
  let distance=originalDistance,clamped=false;
  if(clampDistance){
    const limit=memory.readF64(0x4ccd88);
    if(!Number.isFinite(limit))return undefined;
    if(limit<distance){distance=25000;clamped=true;}
  }
  let column=add(mul(mul(sinX87Interval(angle),exact(scale)),exact(distance)),exact(centerX));
  let row=sub(exact(centerY),mul(mul(cosX87Interval(angle),exact(scale)),exact(distance)));
  if(!valid(column)||!valid(row))return undefined;
  const upper=memory.readF64(0x4ccd78),lower=memory.readF64(0x4ccd80);
  if(!Number.isFinite(upper)||!Number.isFinite(lower))return undefined;
  if(upper<column[0])column=exact(10000);
  else if(upper<column[1])return undefined;
  if(column[1]<lower)column=exact(-10000);
  else if(column[0]<lower)return undefined;
  if(upper<row[0])row=exact(upper);
  else if(upper<row[1])return undefined;
  if(row[1]<lower)row=exact(lower);
  else if(row[0]<lower)return undefined;
  // The reference window retains full I64 coordinates; a later venue branch
  // divides the row before narrowing it. The loop observes only low DWORDs.
  if(!clampDistance&&[column,row].some(bounds=>!i32(Math.trunc(bounds[0]))||!i32(Math.trunc(bounds[1]))))return undefined;
  const pixelX=intervalTruncI32(column),pixelY=intervalTruncI32(row);
  if(pixelX===undefined||pixelY===undefined)return undefined;
  // These are the original projection stores, followed by the loop's optional
  // literal distance clamp. The caller then stores/uses the certified pixels.
  memory.writeF64(0x4fbb88,originalDistance);
  memory.writeI32(0x4f4b40,absoluteDegrees);
  if(clamped){memory.writeI32(0x4fbb88,0);memory.writeI32(0x4fbb8c,0x40d86a00);}
  return {x:pixelX,y:pixelY};
}
