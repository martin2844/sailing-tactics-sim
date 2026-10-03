import { i32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { targetRelativeBearing } from '../engine/target-bearing.js';
import { sinCosX87 } from '../runtime/transcendentals.js';

const f=Float80.fromNumber;
const select=(memory,dc,address)=>{const handle=memory.readU32(address);if(handle)dc.selectObject(handle);};
const polygon=(memory,dc,count)=>dc.polygon(Array.from({length:count},(_,index)=>({x:memory.readI32(0x4a4ca8+index*8),y:memory.readI32(0x4a4cac+index*8)})));
function fillPoints(memory,indices) {
  indices.forEach((index,at)=>{memory.writeI32(0x4a4ca8+at*8,memory.readI32(0x4a4f90+index*4));memory.writeI32(0x4a4cac+at*8,memory.readI32(0x4a5bb0+index*4));});
}
const consecutive=(start,count)=>Array.from({length:count},(_,index)=>start+index);

/** Complete original 0x422970 river shore polygon. */
export function drawRiverShore(memory,dc){fillPoints(memory,consecutive(0,38));polygon(memory,dc,38);}
/** Complete original 0x4232e0 alternate shore polygon. */
export function drawAlternateShore(memory,dc){fillPoints(memory,consecutive(0,37));polygon(memory,dc,37);}

/** Complete original 0x422cf0: the two shore polygons and visible outlines. */
export function drawSplitShore(memory,dc) {
  const r=address=>memory.readI32(address);
  for(const [excluded,start,closing] of [[4,0,[40,39,38,37]],[2,18,[37,42,41,40]]]){
    if(r(0x491194)===excluded)continue;
    fillPoints(memory,[...consecutive(start,19),...closing]);dc.selectStockObject(8);polygon(memory,dc,23);
    if(r(0x4ac1e0)===0)select(memory,dc,r(0x4ac92c)===0?0x4a3f9c:0x4a4ee4);
    if(r(0x4ac1e0)===1)select(memory,dc,0x4aa634);
    dc.moveTo(r(0x4a4f90+start*4),r(0x4a5bb0+start*4));
    for(let index=1;index<=18;index++)dc.lineTo(r(0x4a4f90+(start+index)*4),r(0x4a5bb0+(start+index)*4));
  }
}

function project(memory,originX,originY,scale,mode,camera,x,y,destinationX,destinationY,count) {
  const maximum=f(memory.readF64(0x4850f0)),minimum=f(memory.readF64(0x4850f8));
  for(let index=0;index<count;index++){
    const bearing=targetRelativeBearing(memory,memory.readI32(x+index*4),memory.readI32(y+index*4),mode,camera);
    if(memory.readF64(0x4a6828)>memory.readF64(0x484d38))memory.writeF64(0x4a6828,7000);
    const {sine,cosine}=sinCosX87(bearing),distance=f(memory.readF64(0x4a6828));
    let horizontal=sine.multiply(f(scale)).multiply(distance).add(Float80.fromInteger(originX));
    let vertical=Float80.fromInteger(originY).subtract(cosine.multiply(f(scale)).multiply(distance));
    let storedX=horizontal.toNumber();if(horizontal.compare(maximum)>0)storedX=8000;if(storedX<memory.readF64(0x4850f8))storedX=-8000;
    if(vertical.compare(maximum)>0)vertical=maximum;if(vertical.compare(minimum)<0)vertical=minimum;
    memory.writeI32(destinationX+index*4,f(storedX).truncI32());memory.writeI32(destinationY+index*4,vertical.truncI32());
  }
}

/** Complete original 0x4226c0: project and draw the basic course shoreline. */
export function drawBasicChartTerrain(memory,dc,originX,originY,scale,centerX,centerY,mode,camera) {
  [originX,originY,centerX,centerY,mode,camera]=[originX,originY,centerX,centerY,mode,camera].map(i32);
  const r=address=>memory.readI32(address);
  if(r(0x4a8660+camera*4)<17&&memory.readF64(0x4a7f28+camera*8)>memory.readF64(0x4850e8)&&mode===1)return;
  project(memory,originX,originY,scale,mode,camera,0x4a6490,0x4a68c8,0x4a4f90,0x4a5bb0,r(0x4a864c)===1?41:43);
  select(memory,dc,r(0x4ac92c)===0&&r(0x4ac98c)===0?0x4a621c:0x4a70e4);
  if(r(0x4ac1e0)===0)select(memory,dc,r(0x4ac92c)===0?0x4a3f9c:0x4a4ee4);
  if(r(0x4ac1e0)===1)select(memory,dc,0x4aa634);
  if(r(0x4a864c)===0&&r(0x4a5a4c)===0)drawSplitShore(memory,dc);
  if(r(0x4a864c)===1)drawRiverShore(memory,dc);
  if(r(0x4a5a4c)===1)drawAlternateShore(memory,dc);
}

/** Complete original 0x44f630: visible advanced-shore quads in traversal order. */
export function drawAdvancedShore(memory,dc) {
  const r=address=>memory.readI32(address);
  dc.selectStockObject(8);select(memory,dc,r(0x4ac92c)===0?0x4a621c:0x4a70e4);
  for(let index=0;index<180;index++){
    const x=r(0x4a4f90+index*4),nextX=r(0x4a4f94+index*4),y=r(0x4a5bb0+index*4),nextY=r(0x4a5bb4+index*4);
    if((x<=r(0x4a763c)||nextX<=r(0x4a763c))&&(x>-1||nextX>-1)&&(y>-1||nextY>-1)&&(y<=r(0x4a72d0)||nextY<=r(0x4a72d0))){
      for(const [address,value] of [[0x4a4ca8,r(0x4a7360+index*4)],[0x4a4cb8,nextX],[0x4a4cac,r(0x4a8b28+index*4)],[0x4a4cbc,nextY],
        [0x4a4cc0,r(0x4a7364+index*4)],[0x4a4cc4,r(0x4a8b2c+index*4)],[0x4a4cb0,x],[0x4a4cb4,y]])memory.writeI32(address,value);
      polygon(memory,dc,4);
    }
  }
}

/** Complete original 0x44f320: both advanced shore point sets and closure. */
export function drawAdvancedChartTerrain(memory,dc,originX,originY,scale,centerX,centerY,mode,camera) {
  [originX,originY,centerX,centerY,mode,camera]=[originX,originY,centerX,centerY,mode,camera].map(i32);
  if(memory.readI32(0x4a8660+camera*4)<17&&mode<3)return;
  project(memory,originX,originY,scale,mode,camera,0x4a6490,0x4a68c8,0x4a4f90,0x4a5bb0,180);
  memory.writeI32(0x4a5260,memory.readI32(0x4a4f90));memory.writeI32(0x4a5e80,memory.readI32(0x4a5bb0));
  project(memory,originX,originY,scale,mode,camera,0x4a8e90,0x4a9168,0x4a7360,0x4a8b28,180);
  memory.writeI32(0x4a8df8,memory.readI32(0x4a8b28));memory.writeI32(0x4a7630,memory.readI32(0x4a7360));
  select(memory,dc,memory.readI32(0x4ac92c)===0?0x4a621c:0x4a70e4);select(memory,dc,0x4aa634);
  drawAdvancedShore(memory,dc);
}

export const FUN_00422970=drawRiverShore;
export const FUN_004232e0=drawAlternateShore;
export const FUN_00422cf0=drawSplitShore;
export const FUN_004226c0=drawBasicChartTerrain;
export const FUN_0044f630=drawAdvancedShore;
export const FUN_0044f320=drawAdvancedChartTerrain;
