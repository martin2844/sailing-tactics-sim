import {Float80} from '../../../../src/runtime/float80.js';
import {atan2ExtendedNumeric} from '../../../../src/runtime/atan.js';
import {certifiedSqrtNumber} from '../../../../src/runtime/certified-sqrt.js';
import {fpDrawingEnabled,fpMul,fpSub,fpI32,fpToNumber} from './float-values.js';

const minimumNormal=2**-1022;
const normal=value=>typeof value==='number'&&Number.isFinite(value)
  &&(value===0||Math.abs(value)>=minimumNormal);
const bounded=value=>normal(value)&&Math.abs(value)<=1e9;
const difference=(left,right)=>{
  const value=left-right;
  return normal(value)&&(value!==0||left===right)?value:undefined;
};

/** Exact PC53 43ec20 camera geometry after the original F64 formal stores. */
export function tryProjectChartPointFast(memory,x,y,selector,camera,options={}){
  if(!fpDrawingEnabled(options)||'events' in Number.prototype||'frame' in Number.prototype
    ||'dc' in Number.prototype||'array' in Number.prototype||!bounded(x)||!bounded(y)
    ||typeof selector!=='number'||!Number.isInteger(selector)||selector< -2147483648||selector>2147483647
    ||typeof camera!=='number'||!Number.isInteger(camera)||camera<1||camera>30)return undefined;
  const originX=selector<2?memory.readF64(0x4f6af8+camera*8):memory.readI32(0x536410);
  const originY=selector<2?memory.readF64(0x4f6c10+camera*8):memory.readI32(0x536414);
  if(!bounded(originX)||!bounded(originY))return undefined;
  const dx=difference(x,originX),dy=difference(originY,y);
  if(dx===undefined||dy===undefined)return undefined;
  const xx=dx*dx,yy=dy*dy;
  if(!normal(xx)||!normal(yy)||(xx===0&&dx!==0)||(yy===0&&dy!==0))return undefined;
  const square=yy+xx;
  if(!normal(square))return undefined;
  const candidate=certifiedSqrtNumber(square);
  const distance=candidate===undefined?Float80.fromNumber(square).sqrt().toNumber():candidate;
  const zeroThreshold=memory.readF64(0x4cc658),pi=memory.readF64(0x4cc740),
    degreesPerRadian=memory.readF64(0x4cc3e8);
  if(!bounded(zeroThreshold)||!bounded(pi)||Math.abs(pi)>10
    ||!bounded(degreesPerRadian)||Math.abs(degreesPerRadian)>1000)return undefined;
  // This native axis branch deliberately uses the stored 3.1416 constant.
  // It is distinct from mathematical atan2, including its degree truncation.
  const bearing=dx===zeroThreshold?(dy<=zeroThreshold?pi:zeroThreshold):atan2ExtendedNumeric(dx,dy);
  const absoluteDegrees=fpI32(fpMul(bearing,degreesPerRadian));
  let result;
  if(selector!==0&&selector<3){
    let headingAddress;
    if(selector===-1)headingAddress=0x4fbb90+camera*4;
    else if(selector===1||selector===2){
      const mode=memory.readI32(0x525a78+camera*4);
      if(mode===0)headingAddress=0x4fbb90+camera*4;
      else if(mode===1)headingAddress=0x535740+camera*4;
      else if(mode===2)headingAddress=0x522b90+camera*4;
    }
    let angle=dx;
    if(headingAddress!==undefined){
      const heading=memory.readI32(headingAddress),radiansPerDegree=memory.readF64(0x4cc568);
      if(!normal(radiansPerDegree)||radiansPerDegree<=0||radiansPerDegree>1)return undefined;
      const offset=heading*radiansPerDegree;
      if(!normal(offset)||(offset===0&&heading!==0))return undefined;
      angle=fpToNumber(fpSub(bearing,offset));
    }
    if(!normal(angle))return undefined;
    result=Float80.fromNumber(angle);
  }else{
    const angle=fpToNumber(bearing);
    if(!normal(angle))return undefined;
    result=Float80.fromNumber(angle);
  }
  // Unsupported inputs decline without stores, preserving the original
  // fallback's partial-write/error behavior. Accepted calls retain both stores.
  memory.writeF64(0x4fbb88,distance);
  memory.writeI32(0x4f4b40,absoluteDegrees);
  return result;
}
