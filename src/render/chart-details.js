import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { wrapDegreesOnce, scaledRandom } from '../engine/integer-core.js';
import { nativeTrig } from '../engine/native-trig.js';
import { targetRelativeBearing } from '../engine/target-bearing.js';
import { sinCosX87 } from '../runtime/transcendentals.js';
import { drawWakePoint } from './boat-primitives.js';
import { drawChartBoat } from './chart-boat.js';
import { drawCourseMark, drawHeadingIndicator } from './chart-symbols.js';
import { projectScenePoint } from './projection.js';

const f=Float80.fromNumber;
const select=(memory,dc,address)=>{const handle=memory.readU32(address);if(handle)dc.selectObject(handle);};

/** Complete original 0x420b20: displace a point along an integer bearing. */
export function displacePoint(memory,x,y,distance,bearing,options={}) {
  [x,y,distance,bearing]=[x,y,distance,bearing].map(i32);
  const {sine,cosine}=nativeTrig(wrapDegreesOnce(bearing),options);
  memory.writeI32(0x4a70e8,add32(x,sine.multiply(Float80.fromInteger(distance)).truncI32()));
  memory.writeI32(0x4aa81c,sub32(y,cosine.multiply(Float80.fromInteger(distance)).truncI32()));
}

/** Complete original 0x431890: wind patch outlines and both random/fixed dots. */
export function drawChartWindPatch(memory,dc,patch,camera,scale,x,y,left,top,right,bottom,mode,options={}) {
  [patch,camera,x,y,left,top,right,bottom,mode]=[patch,camera,x,y,left,top,right,bottom,mode].map(i32);
  if(memory.readI32(0x4ac98c)===1)return;
  const zoom=memory.readI32(0x4a8660+camera*4),width=memory.readI32(0x4a763c);
  let margin=idiv32(width,14);
  if(mode===1){if(zoom<5)margin=idiv32(imul32(width,2),3);if(zoom===8)margin=idiv32(width,3);if(zoom===16)margin=idiv32(width,8);}
  if(x<sub32(left,margin)||add32(margin,right)<x||add32(margin,bottom)<y||y<sub32(top,margin))return;
  let radius=Float80.fromInteger(memory.readI32(0x4a4ec0+patch*4)).multiply(f(scale)).truncI32();
  if(radius<5)radius=5;if(imul32(width,2)<radius)radius=imul32(width,2);
  if(zoom<9&&mode===1&&memory.readI32(0x4ac92c)===0){dc.selectStockObject(8);select(memory,dc,0x4a5b8c);dc.ellipse(sub32(x,radius),sub32(y,radius),add32(radius,x),add32(radius,y));}
  select(memory,dc,0x4a4dec);
  let randomCount=4;
  if(mode===1&&zoom<9){randomCount=zoom===8?6:1;if(zoom<5)randomCount=12;}
  const diameter=imul32(radius,2),originX=sub32(x,radius),originY=sub32(y,radius);
  for(let index=0;index<randomCount;index++)drawWakePoint(memory,dc,add32(scaledRandom(diameter,options.rng),originX),add32(scaledRandom(diameter,options.rng),originY),1);
  let count=12;
  if(mode===1&&zoom<33){if(zoom<5||zoom===8||zoom===16)count=32;if(zoom===32)count=16;}else count=16;
  for(let index=0;index<count;index++)drawWakePoint(memory,dc,
    add32(idiv32(imul32(diameter,memory.readI32(0x4a9454+index*4)),100),originX),
    add32(idiv32(imul32(diameter,memory.readI32(0x4a9458+index*4)),100),originY),1);
}

/** Complete original 0x431440, including chart and projected scene laylines. */
export function drawLaylines(memory,dc,x,y,selector,boat,mode,mark,options={}) {
  [x,y,selector,boat,mode,mark]=[x,y,selector,boat,mode,mark??0].map(i32);
  const r=address=>memory.readI32(address),offset=boat*4,gybe=r(0x4a5f10+offset),pointOfSail=r(0x4a7bc8+offset);
  if(!((r(0x491194)!==8||mode!==0||idiv32(imul32(r(0x491148),3),2)<=y)&&r(0x4a5b80)>-1&&r(0x4ac93c)<1&&(pointOfSail<91||gybe>19)))return;
  let wind=boat;
  if(mode===1){const reference=r(0x4ab160+offset);if(reference===0)wind=wrapDegreesOnce(sub32(r(0x4aa5b0+offset),r(0x4a6830+offset)));if(reference===1)wind=wrapDegreesOnce(sub32(r(0x4aa5b0+offset),r(0x4ac018+offset)));if(reference===2)wind=0;}
  if(r(0x4ac92c)===0)select(memory,dc,selector===3?0x4ac84c:0x4a705c);
  if(r(0x4ac92c)===1)dc.selectStockObject(6);
  let spread=(selector===1||selector>3)?r(0x4a4eb0):y;
  if(selector===2)spread=sub32(180,gybe);
  const abs=spread<0?sub32(0,spread):spread;if(abs>176)spread=0;if(selector===3)spread=90;
  if(mode===1){
    for(const side of [-1,1]){
      const bearing=wrapDegreesOnce(add32(add32(wind,180),imul32(side,spread))),{sine,cosine}=nativeTrig(bearing,options);
      dc.moveTo(x,y);
      if(selector!==(side===-1?5:4))dc.lineTo(sub32(x,sine.multiply(f(memory.readF64(0x4852d0))).truncI32()),sub32(y,cosine.multiply(f(memory.readF64(0x4852d8))).truncI32()));
    }
    return;
  }
  const markX=f(memory.readF64(0x4a52f0+mark*8)).truncI32(),markY=f(memory.readF64(0x4a60b0+mark*8)).truncI32();
  projectScenePoint(memory,0,markX,markY,boat,99,options);
  const originX=r(0x4a7c48),originY=r(0x4aaa48),distance=imul32(idiv32(r(0x4aa6e0+offset),10),10);
  for(const side of [1,-1]){
    displacePoint(memory,markX,markY,distance,wrapDegreesOnce(add32(add32(r(0x4aa5b0+offset),imul32(side,spread)),180)),options);
    projectScenePoint(memory,0,r(0x4a70e8),r(0x4aa81c),boat,99,options);
    dc.moveTo(originX,originY);
    if(selector!==(side===1?4:5))dc.lineTo(r(0x4a7c48),r(0x4aaa48));
  }
}

/** Complete original 0x421d90 chart object traversal and drawing order. */
export function drawChartObjects(memory,dc,originX,originY,scale,centerX,centerY,mode,camera,left,top,right,bottom,options={}) {
  [originX,originY,centerX,centerY,mode,camera,left,top,right,bottom]=[originX,originY,centerX,centerY,mode,camera,left,top,right,bottom].map(i32);
  const r=address=>memory.readI32(address),view=mode>0&&mode<3;
  const project=(x,y,selector=mode)=>{
    const bearing=targetRelativeBearing(memory,x,y,selector,camera);
    if(memory.readF64(0x4a6828)>memory.readF64(0x484d38))memory.writeF64(0x4a6828,7000);
    const {sine,cosine}=sinCosX87(bearing),distance=f(memory.readF64(0x4a6828));
    return [sine.multiply(f(scale)).multiply(distance).add(Float80.fromInteger(originX)).truncI32(),Float80.fromInteger(originY).subtract(cosine.multiply(f(scale)).multiply(distance)).truncI32()];
  };
  if(r(0x4ac98c)===0&&(mode===1||mode===2))for(let patch=1;patch<=5;patch++){
    const [x,y]=project(memory.readF64(0x4abd90+(patch-1)*8),memory.readF64(0x4a4730+(patch-1)*8));
    drawChartWindPatch(memory,dc,patch,camera,scale,x,y,left,top,right,bottom,mode,options);
  }
  if(r(0x4ac958)===1&&mode===1){
    const players=r(0x49118c)===2?2:r(0x491140);
    for(let player=1;player<=players;player++){
      if(player===1)select(memory,dc,r(0x4ac92c)===1?0x4a4ee4:0x4a676c);
      if(player===2)select(memory,dc,r(0x4ac92c)===1?0x4a4dec:0x4a39fc);
      for(let step=1;step<=r(0x4ab9d8);step++){
        const [x,y]=project(r(0x4a9a0c+player*0x25c+(step-1)*4),r(0x4ab1a4+player*0x25c+(step-1)*4),1);drawWakePoint(memory,dc,x,y,1);
      }
    }
  }
  const count=mode>1?r(0x491140):r(0x49118c),offset=camera*4;
  let selectedX=0,selectedY=0,startX=0,startY=0;
  const line=(x,y,selector)=>drawLaylines(memory,dc,x,y,selector,camera,1,0,options);
  for(let object=1;object<=add32(count,5);object++){
    const [x,y]=project(memory.readF64(0x4a52f0+object*8),memory.readF64(0x4a60b0+object*8));
    if(object<6){
      if(object===r(0x4aa7e0)){selectedX=x;selectedY=y;}
      const leg=r(0x4a6ba0+offset),angle=r(0x4a7bc8+offset),gybe=r(0x4a5f10+offset),enabled=r(0x49117c)===1;
      if(object===3&&view&&leg===1){if(angle<70&&enabled)line(x,y,1);if(sub32(165,gybe)<angle&&r(0x491194)===8&&enabled)line(x,y,2);}
      if(object===4&&leg===2&&view){if(angle<add32(r(0x4a4eb0),10)&&enabled)line(x,y,1);if(sub32(160,gybe)<angle&&enabled)line(x,y,2);}
      if(object===5&&leg===3&&view&&(r(0x491160)===0||(r(0x491160)===1&&r(0x49118c)>14))){if(angle<add32(r(0x4a4eb0),10)&&enabled)line(x,y,1);if(sub32(160,gybe)<angle&&enabled)line(x,y,2);}
      if(object===2&&leg===0&&view&&angle<90&&enabled)line(x,y,r(0x4ac9a8)===1?5:4);
      if(object===1&&leg===0&&view&&angle<90&&enabled)line(x,y,r(0x4ac9a8)===1?4:5);
      if(x<right&&left<x&&top<y&&y<bottom)drawCourseMark(memory,dc,x,y,object,mode,camera,{...options,drawChartBoat});
      if(mode>2){if(typeof options.drawChartMarkLabel!=='function')throw new Error('Original chart mark text renderer is required');options.drawChartMarkLabel(memory,dc,object,x,y,options);}
    }else{
      const boat=sub32(object,5);
      if(boat===camera&&view){select(memory,dc,0x4a71bc);dc.moveTo(x,y);dc.lineTo(selectedX,selectedY);if(r(0x4a7bc8+offset)<add32(r(0x4a4eb0),10)&&mode===1&&r(0x49117c)===1)line(x,y,3);if(sub32(165,r(0x4a5f10+offset))<r(0x4a7bc8+offset)&&mode===1&&r(0x49117c)===1)line(x,y,3);}
      if(mode===1&&x<right&&left<x&&top<y&&y<bottom){if(r(0x4a8660+offset)<8)drawChartBoat(memory,dc,x,y,boat,camera,options);else drawHeadingIndicator(memory,dc,x,y,boat,camera,1);}
      if(mode>1){drawHeadingIndicator(memory,dc,x,y,boat,1,mode);if(r(0x491140)===2)drawHeadingIndicator(memory,dc,x,y,boat,2,mode);}
    }
    if(object===1){startX=x;startY=y;}
    if(object===2&&r(0x4a5b80)<1){dc.selectStockObject(7);dc.moveTo(startX,startY);dc.lineTo(x,y);}
  }
}

export const FUN_00420b20=displacePoint;
export const FUN_00431890=drawChartWindPatch;
export const FUN_00431440=drawLaylines;
export const FUN_00421d90=drawChartObjects;
