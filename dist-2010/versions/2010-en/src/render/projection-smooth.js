import {signedDegrees} from '../engine/ai-geometry.js';
import {trySmoothAtanNumber} from './smooth-math.js';

// The common perspective branch writes only distance/bearing scratch and two
// screen coordinates. Camera origins and distance keep the exact geometry path;
// opting in permits browser rounding for the final display angle and pixels.
export function tryProjectScenePointSmooth(memory,index,camera,selector,mode,geometry,options){
  const {dx,dy,distance,origin,zeroThreshold,pi,twoPi,negativePi,negativeTwoPi,degreesPerRadian}=geometry;
  const bearing=trySmoothAtanNumber(dx,dy,options);
  if(bearing===undefined)return undefined;
  let angle=bearing-origin.radians;
  if(angle>pi)angle-=twoPi;
  if(angle<negativePi)angle-=negativeTwoPi;
  const product=angle*degreesPerRadian;
  if(!Number.isFinite(product)||product<-(2**63)||product>=2**63)return undefined;
  const degrees=product|0;
  if(degrees>130||degrees< -130)return undefined;
  const cosine=Math.cos(angle);
  let depth=distance*cosine;
  const minimumDepth=memory.readF64(0x4cc580);
  if(!Number.isFinite(minimumDepth))return undefined;
  if(depth<minimumDepth)depth=10;
  const horizon=memory.readI32(0x4da148),height=memory.readI32(0x4f4b48)-horizon;
  const step=(Math.trunc(memory.readI32(0x4fe2a8)/9)|0)*height;
  let row;
  if(cosine<zeroThreshold){
    const first=horizon-step*memory.readF64(0x4cc8b0);
    const other=horizon-step*memory.readF64(0x4cc908);
    row=first-((first-other)*depth)*memory.readF64(0x4cc8b0);
  }else row=horizon+step/depth;
  if(!Number.isFinite(row))return undefined;
  if(selector===5){
    const upper70=memory.readF64(0x4cc4f0),lower70=memory.readF64(0x4ccb50),
      upper80=memory.readF64(0x4cc960),lower80=memory.readF64(0x4ccb58),
      upper90=memory.readF64(0x4cc4d0),lower90=memory.readF64(0x4cc8f8);
    if(![upper70,lower70,upper80,lower80,upper90,lower90].every(Number.isFinite))return undefined;
    if(upper70<degrees||degrees<lower70)row=horizon+horizon;
    if(upper80<degrees||degrees<lower80){
      row=horizon*memory.readF64(0x4cc538);
      if(!Number.isFinite(row))return undefined;
    }
    if(upper90<degrees||degrees<lower90)row=horizon;
  }
  if(!Number.isFinite(row)||row<-(2**63)||row>=2**63||height===0)return undefined;
  const coefficient=memory.readF64(mode===1?0x4cc5c0:0x4ccb60);
  const scaled=(memory.readF64(0x4cc418)-((row-horizon)*coefficient)/height)*memory.readF64(0x5259d0);
  const column=(angle*scaled)*memory.readF64(0x4ccb68);
  if(!Number.isFinite(column)||column<-(2**63)||column>=2**63)return undefined;
  const pixelX=((column|0)+memory.readI32(0x4f40a8))|0;
  memory.writeF64(0x4fbb88,distance);
  memory.writeI32(0x535ff4,signedDegrees(degrees));
  memory.writeI32(0x523660+index*4,row|0);
  memory.writeI32(0x4fed58+index*4,pixelX);
  return true;
}
