import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom } from '../engine/integer-core.js';
import { projectScenePoint } from './projection.js';
import { drawWakePoint } from './boat-primitives.js';

const f=Float80.fromNumber,integer=Float80.fromInteger;
const select=(memory,dc,address)=>{const handle=memory.readU32(address);if(handle)dc.selectObject(handle);};

/** Complete original 0x431b30 first-person wind-patch extent and flecks. */
export function drawSceneWindPatch(memory,dc,patch,camera,left,top,right,bottom,options={}){
  [patch,camera,left,top,right,bottom]=[patch,camera,left,top,right,bottom].map(i32);
  const r=address=>memory.readI32(address);
  if(r(0x4ac98c)===1)return;
  const x=memory.readF64(0x4abd88+patch*8),y=memory.readF64(0x4a4728+patch*8),radius=r(0x4a4ec0+patch*4),halfWidth=idiv32(sub32(right,left),2);
  projectScenePoint(memory,0,x,y,camera,0,options);const centerX=r(0x4a7c48),centerY=r(0x4aaa48);
  if(centerX<sub32(left,halfWidth)||add32(halfWidth,right)<centerX||add32(idiv32(sub32(bottom,top),2),bottom)<centerY)return;
  const xs=[],ys=[];
  for(const [edgeX,edgeY] of [[f(x).subtract(integer(radius)).toNumber(),y],[x,f(y).subtract(integer(radius)).toNumber()],
    [integer(radius).add(f(x)).toNumber(),y],[x,integer(radius).add(f(y)).toNumber()]]){
    projectScenePoint(memory,0,edgeX,edgeY,camera,0,options);xs.push(r(0x4a7c48));ys.push(r(0x4aaa48));
  }
  let minimumX=Math.min(2000,...xs),maximumX=Math.max(-2000,...xs),minimumY=Math.min(2000,...ys),maximumY=Math.max(-2000,...ys);
  if(right<minimumX||maximumX<left||bottom<minimumY)return;
  if(maximumY>bottom)maximumY=bottom;if(minimumX<sub32(0,r(0x4a763c)))minimumX=sub32(0,r(0x4a763c));if(imul32(r(0x4a763c),2)<maximumX)maximumX=imul32(r(0x4a763c),2);
  dc.selectStockObject(8);select(memory,dc,r(0x4aaa1c)<9?0x4aa82c:0x4ac1cc);
  if(r(0x4a4e88+camera*4)<3&&r(0x4ac92c)===0)dc.ellipse(minimumX,minimumY,maximumX,maximumY);
  const horizon=r(0x491148);
  const size=integer(sub32(centerY,horizon)).multiply(f(memory.readF64(0x484cf0))).divide(integer(sub32(bottom,horizon))).multiply(integer(radius)).truncI32();
  const margin=idiv32(size,30);
  if(centerX<sub32(left,margin)||add32(right,margin)<centerX||add32(bottom,margin)<centerY)return;
  const count=Math.min(70,idiv32(size,2));select(memory,dc,r(0x4ac92c)===0?0x4ab9cc:0x4a4dec);
  for(let index=1;index<=count;index++){
    const px=index%5===0?scaledRandom(sub32(maximumX,minimumX),options.rng):idiv32(imul32(r(0x4a9454+(index-1)*4),sub32(maximumX,minimumX)),100);
    const py=index%5===0?scaledRandom(sub32(maximumY,minimumY),options.rng):idiv32(imul32(sub32(maximumY,minimumY),r(0x4a9458+(index-1)*4)),100);
    if(add32(horizon,15)<add32(py,minimumY))drawWakePoint(memory,dc,add32(px,minimumX),add32(py,minimumY),1);
  }
}

export const FUN_00431b30=drawSceneWindPatch;
