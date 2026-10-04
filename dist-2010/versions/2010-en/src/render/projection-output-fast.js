import { intervalAdd as add,intervalSub as sub,intervalMul as mul,intervalDiv as div,intervalTruncI32,
  atan2Interval,cosX87Interval } from '../../../../src/runtime/output-interval.js';
import { signedDegrees } from '../engine/ai-geometry.js';
import { projectionFastEnabled,tryProjectionGeometry } from './projection-fast.js';
import {tryProjectScenePointSmooth} from './projection-smooth.js';

const exact=value=>[value,value];
const valid=value=>value&&Number.isFinite(value[0])&&Number.isFinite(value[1])&&value[0]<=value[1];

/** Certify the four original stores of the common 43e730 perspective branches. */
export function tryProjectScenePointOutputFast(memory,index,x,y,camera,selector,options={}){
  if(!projectionFastEnabled(options)||'retainedDrawingStack' in options||'drawingDependencies' in options
    ||'events' in Number.prototype||'frame' in Number.prototype||'dc' in Number.prototype||'array' in Number.prototype
    ||(selector!==0&&selector!==5)||typeof index!=='number'||!Number.isInteger(index)
    ||index<0||index>30||typeof camera!=='number'||!Number.isInteger(camera)||camera<1||camera>30
    ||typeof x!=='number'||typeof y!=='number'||!Number.isFinite(x)||!Number.isFinite(y))return undefined;
  const mode=memory.readI32(0x4f71c0+camera*4);
  if(mode!==1&&mode!==2)return undefined;
  const geometry=tryProjectionGeometry(memory,x,y,camera);
  if(!geometry)return undefined;
  if(tryProjectScenePointSmooth(memory,index,camera,selector,mode,geometry,options))return true;
  const {dx,dy,distance,origin,zeroThreshold,pi,twoPi,negativePi,negativeTwoPi,degreesPerRadian}=geometry;
  let angle=sub(atan2Interval(dx,dy),exact(origin.radians));
  if(!valid(angle))return undefined;
  if(angle[0]>pi)angle=sub(angle,exact(twoPi));
  else if(angle[1]>pi)return undefined;
  if(!valid(angle))return undefined;
  if(angle[1]<negativePi)angle=sub(angle,exact(negativeTwoPi));
  else if(angle[0]<negativePi)return undefined;
  if(!valid(angle))return undefined;
  const degreeProduct=mul(angle,exact(degreesPerRadian));
  if(!valid(degreeProduct))return undefined;
  const rawDegrees=intervalTruncI32(degreeProduct);
  if(rawDegrees===undefined||rawDegrees>130||rawDegrees< -130)return undefined;
  const cosine=cosX87Interval(angle);
  if(!valid(cosine))return undefined;
  let depth=mul(exact(distance),cosine);
  if(!valid(depth))return undefined;
  const minimumDepth=memory.readF64(0x4cc580);
  if(!Number.isFinite(minimumDepth))return undefined;
  if(depth[1]<minimumDepth)depth=exact(10);
  else if(depth[0]<minimumDepth)return undefined;

  const horizon=memory.readI32(0x4da148),height=memory.readI32(0x4f4b48)-horizon;
  const verticalUnit=Math.trunc(memory.readI32(0x4fe2a8)/9)|0;
  const step=mul(exact(verticalUnit),exact(height));
  let row;
  if(cosine[1]<zeroThreshold){
    const first=sub(exact(horizon),mul(step,exact(memory.readF64(0x4cc8b0))));
    const other=sub(exact(horizon),mul(step,exact(memory.readF64(0x4cc908))));
    row=sub(first,mul(mul(sub(first,other),depth),exact(memory.readF64(0x4cc8b0))));
  }else if(cosine[0]>=zeroThreshold){
    row=add(exact(horizon),div(step,depth));
  }else return undefined;
  if(!valid(row))return undefined;
  if(selector===5){
    const upper70=memory.readF64(0x4cc4f0),lower70=memory.readF64(0x4ccb50),
      upper80=memory.readF64(0x4cc960),lower80=memory.readF64(0x4ccb58),
      upper90=memory.readF64(0x4cc4d0),lower90=memory.readF64(0x4cc8f8);
    if(![upper70,lower70,upper80,lower80,upper90,lower90].every(Number.isFinite))return undefined;
    if(upper70<rawDegrees||rawDegrees<lower70)row=add(exact(horizon),exact(horizon));
    if(upper80<rawDegrees||rawDegrees<lower80){
      row=mul(exact(horizon),exact(memory.readF64(0x4cc538)));
      if(!valid(row))return undefined;
    }
    if(upper90<rawDegrees||rawDegrees<lower90)row=exact(horizon);
  }
  if(!valid(row))return undefined;
  const pixelY=intervalTruncI32(row);
  if(pixelY===undefined||height===0)return undefined;
  const coefficient=memory.readF64(mode===1?0x4cc5c0:0x4ccb60);
  const scaledDepth=mul(sub(exact(memory.readF64(0x4cc418)),
    div(mul(sub(row,exact(horizon)),exact(coefficient)),exact(height))),exact(memory.readF64(0x5259d0)));
  const column=mul(mul(angle,scaledDepth),exact(memory.readF64(0x4ccb68)));
  if(!valid(column))return undefined;
  const relativeX=intervalTruncI32(column);
  if(relativeX===undefined)return undefined;
  const pixelX=(relativeX+memory.readI32(0x4f40a8))|0;
  // Every branch and final integer conversion is certified before the first
  // image store. The original distance, bearing, row, column order is retained.
  memory.writeF64(0x4fbb88,distance);
  memory.writeI32(0x535ff4,signedDegrees(rawDegrees));
  memory.writeI32(0x523660+index*4,pixelY);
  memory.writeI32(0x4fed58+index*4,pixelX);
  return true;
}
