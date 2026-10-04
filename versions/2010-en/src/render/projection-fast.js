import { Float80, getX87ControlWord } from '../../../../src/runtime/float80.js';
import { sinCosX87 } from '../../../../src/runtime/transcendentals.js';
import { atan2ExtendedNumeric } from '../../../../src/runtime/atan.js';
import { certifiedSqrtNumber } from '../../../../src/runtime/certified-sqrt.js';
import { signedDegrees } from '../engine/ai-geometry.js';

const minimumNormal=2**-1022;
const cameras=new WeakMap();
const normal=value=>Number.isFinite(value)&&(value===0||Math.abs(value)>=minimumNormal);
const bounded=value=>normal(value)&&Math.abs(value)<=1e9;
const difference=(left,right)=>{
  const value=left-right;
  return normal(value)&&(value!==0||left===right)?value:undefined;
};
const argument=value=>{
  if(value instanceof Float80)return value.toNumber();
  // The generated C conversion loads integral Number arguments through FILD;
  // that conversion canonicalizes Number -0, unlike an existing Float80 -0.
  return typeof value==='number'?(value===0?0:value):undefined;
};

export function projectionFastEnabled(options={}){
  return getX87ControlWord()===0x027f&&(typeof options==='object'||typeof options==='function')&&options!==null
    &&!('sinCos' in options)&&!('atan2' in options);
}

/** Exact guarded camera geometry; no original image stores occur here. */
export function tryProjectionGeometry(memory,x,y,camera){
  if(getX87ControlWord()!==0x027f)return undefined;
  if(typeof camera!=='number'||!Number.isInteger(camera)||camera<1||camera>30)return undefined;
  if(!bounded(x)||!bounded(y))return undefined;
  const heading=memory.readI32(0x4fbb90+camera*4),radiansPerDegree=memory.readF64(0x4cc568);
  const cameraX=memory.readF64(0x4f6af8+camera*8),cameraY=memory.readF64(0x4f6c10+camera*8);
  const model=memory.readI32(0x5364c8);
  const offsetY=memory.readF64(model===1?0x4ccb58:0x4ccb20),offsetX=memory.readF64(model===1?0x4cc960:0x4ccae0);
  const zeroThreshold=memory.readF64(0x4cc658),pi=memory.readF64(0x4cc740),twoPi=memory.readF64(0x4cc748);
  const negativePi=memory.readF64(0x4cc750),negativeTwoPi=memory.readF64(0x4cc758),degreesPerRadian=memory.readF64(0x4cc3e8);
  if(heading<0||heading>=360||![radiansPerDegree,cameraX,cameraY,offsetY,offsetX,zeroThreshold,
    pi,twoPi,negativePi,negativeTwoPi,degreesPerRadian].every(bounded))return undefined;
  if(radiansPerDegree<=0||radiansPerDegree>1||Math.abs(degreesPerRadian)>1000
    ||Math.abs(pi)>10||Math.abs(negativePi)>10||Math.abs(twoPi)>20||Math.abs(negativeTwoPi)>20)return undefined;
  const radians=heading*radiansPerDegree;
  if(!normal(radians)||(radians===0&&heading!==0&&radiansPerDegree!==0))return undefined;
  let entries=cameras.get(memory);
  if(!entries){entries=new Array(31);cameras.set(memory,entries);}
  let origin=entries[camera];
  if(!origin||origin.heading!==heading||origin.model!==model||!Object.is(origin.radiansPerDegree,radiansPerDegree)
    ||!Object.is(origin.cameraX,cameraX)||!Object.is(origin.cameraY,cameraY)
    ||!Object.is(origin.offsetX,offsetX)||!Object.is(origin.offsetY,offsetY)){
    const angle=Float80.fromNumber(radians),pair=sinCosX87(angle);
    // FSIN/FCOS retain their exact 64-bit significands. Their multiplications
    // round at PC53 before the camera-origin subtraction, exactly as native.
    const sineOffset=pair.sine.multiply(Float80.fromNumber(offsetX)).toNumber();
    const cosineOffset=pair.cosine.multiply(Float80.fromNumber(offsetY)).toNumber();
    if(!bounded(sineOffset)||!bounded(cosineOffset))return undefined;
    if((sineOffset===0&&offsetX!==0&&pair.sine.mantissa!==0n)
      ||(cosineOffset===0&&offsetY!==0&&pair.cosine.mantissa!==0n))return undefined;
    const originX=difference(cameraX,sineOffset),originY=difference(cameraY,cosineOffset);
    if(originX===undefined||originY===undefined)return undefined;
    origin={heading,model,radiansPerDegree,cameraX,cameraY,offsetX,offsetY,radians,angle,x:originX,y:originY};
    entries[camera]=origin;
  }
  const dx=difference(x,origin.x),dy=difference(origin.y,y);
  if(dx===undefined||dy===undefined)return undefined;
  const xx=dx*dx,yy=dy*dy;
  if(!normal(xx)||!normal(yy)||(xx===0&&dx!==0)||(yy===0&&dy!==0))return undefined;
  const square=yy+xx;
  if(!normal(square))return undefined;
  const distance=square<=zeroThreshold?0:(certifiedSqrtNumber(square)??Float80.fromNumber(square).sqrt().toNumber());
  return {dx,dy,distance,origin,zeroThreshold,pi,twoPi,negativePi,negativeTwoPi,degreesPerRadian};
}

/** Exact PC53 arithmetic for the bounded camera domain; undefined declines. */
export function tryProjectPointFast(memory,args,options={}){
  if(!projectionFastEnabled(options))return undefined;
  const camera=args[2];
  if(typeof camera!=='number'||!Number.isInteger(camera)||camera<1||camera>30)return undefined;
  const geometry=tryProjectionGeometry(memory,argument(args[0]),argument(args[1]),camera);
  if(!geometry)return undefined;
  const {dx,dy,distance,origin,pi,twoPi,negativePi,negativeTwoPi,degreesPerRadian}=geometry;
  const bearing=atan2ExtendedNumeric(dx,dy).subtract(origin.angle).toNumber();
  if(!normal(bearing))return undefined;
  let wrapped=bearing;
  if(pi<wrapped){wrapped=difference(wrapped,twoPi);if(wrapped===undefined)return undefined;}
  if(wrapped<negativePi){wrapped=difference(wrapped,negativeTwoPi);if(wrapped===undefined)return undefined;}
  const angle=Float80.fromNumber(wrapped);
  // A normal product rounds exactly at PC53. FTOL64's low DWORD is ToInt32
  // inside its signed-I64 domain, preserving the original degree helper.
  const degreeProduct=wrapped*degreesPerRadian;
  if(!normal(degreeProduct)||(degreeProduct===0&&wrapped!==0&&degreesPerRadian!==0)
    ||degreeProduct<-(2**63)||degreeProduct>=2**63)return undefined;
  const degrees=signedDegrees(degreeProduct|0);
  memory.writeF64(0x4fbb88,distance);memory.writeI32(0x535ff4,degrees);
  return angle;
}
