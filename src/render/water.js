import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { nativeTrig } from '../engine/native-trig.js';
import { scaledRandom, wrapDegreesOnce } from '../engine/integer-core.js';
import { drawWakePoint } from './boat-primitives.js';

const f=Float80.fromNumber,integer=Float80.fromInteger;
const abs=value=>value<0?sub32(0,value):value;
const select=(memory,dc,address)=>{const handle=memory.readU32(address);if(handle)dc.selectObject(handle);};

/** Complete original 0x42fe00. */
export function drawRippleSegment(_memory,dc,x,y,dy,dx){
  [x,y,dy,dx]=[x,y,dy,dx].map(i32);dc.moveTo(x,y);dc.lineTo(add32(dx,x),add32(dy,y));
}

/** Complete original 0x42f930 fine surface ripples and wind-patch flecks. */
export function drawWaterRipples(memory,dc,camera,left,top,right,bottom,options={}){
  [camera,left,top,right,bottom]=[camera,left,top,right,bottom].map(i32);
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value),c=address=>f(memory.readF64(address)),offset=camera*4;
  const view=r(camera===1?0x4a475c:0x4a4770);
  w(0x4aca18,add32(r(0x4aca18),1));const phase=integer(r(0x4aca18));
  let count=imul32(r(0x4ac4e8+offset),30);if(count>99)count=99;
  const divisor=integer(r(0x491170)),waveScale=c(0x4852b0).divide(divisor).toNumber(),speedScale=c(0x4a71c8+camera*8).multiply(c(0x4852b8)).divide(divisor).toNumber();
  const angle=wrapDegreesOnce(sub32(0,add32(imul32(r(0x4a7bc8+offset),r(0x4aa730+offset)),view))),wave=nativeTrig(angle,options),heading=nativeTrig(view,options);
  const horizontal=wave.sine.multiply(f(waveScale)).multiply(phase).subtract(heading.sine.multiply(f(speedScale)).multiply(phase)).truncI32();
  const vertical=heading.cosine.multiply(f(speedScale)).add(wave.cosine.multiply(f(waveScale))).multiply(phase).multiply(c(0x4852c0)).truncI32();
  if(idiv32(r(0x4a763c),5)<abs(horizontal)||idiv32(r(0x4a72d0),8)<abs(vertical))w(0x4aca18,0);
  const side=nativeTrig(wrapDegreesOnce(add32(angle,90)),options);
  let dx=side.sine.multiply(c(0x484eb8)).truncI32(),dy=side.cosine.multiply(c(0x484eb8)).truncI32();
  const doubledX=imul32(dx,2),doubledY=imul32(dy,2),widthStep=idiv32(sub32(right,left),50),middle=r(0x4a4e88+offset)<3?idiv32(bottom,2):0;
  select(memory,dc,0x4a4ee4);
  const lifetime=divisor.sqrt().truncI32();
  const tick=index=>{
    const address=0x4ac694+index*4;
    if(scaledRandom(100,options.rng)<3)w(address,lifetime);if(r(address)>0)w(address,sub32(r(address),1));return r(address);
  };
  for(let index=0;index<count;index++){
    const active=tick(index),y=add32(imul32(idiv32(bottom,80),r(0x4a9458+index*4)),vertical),x=sub32(add32(imul32(r(0x4a9454+index*4),widthStep),horizontal),idiv32(sub32(right,left),2));
    if(idiv32(count,2)<index+1){dy=doubledY;dx=doubledX;}
    if(idiv32(bottom,4)<y&&y<bottom&&left<x&&x<right&&active===0){if(middle<y)drawRippleSegment(memory,dc,x,y,dy,dx);else drawWakePoint(memory,dc,x,y,1);}
  }
  if((camera===1&&r(0x4aa62c)===0)||(camera===2&&r(0x4aa638)===0)||r(0x4ac8f8)===0||r(0x4ac98c)===1)return;
  select(memory,dc,r(0x4ac92c)===0?0x4ab9cc:0x4a4dec);
  for(let index=0;index<100;index++){
    const active=tick(index),y=add32(add32(idiv32(imul32(r(0x4a4760),2),3),idiv32(imul32(vertical,2),3)),idiv32(imul32(sub32(r(0x4a9454+index*4),50),idiv32(bottom,40)),3));
    if(middle<y&&active===0)drawWakePoint(memory,dc,add32(add32(idiv32(imul32(imul32(sub32(r(0x4a9458+index*4),50),widthStep),2),3),idiv32(imul32(horizontal,2),3)),r(0x4a3fa0)),y,1);
  }
}

/** Complete original 0x42fe40 larger surface wave streaks. */
export function drawLargeWaves(memory,dc,camera,left,top,right,bottom,options={}){
  [camera,left,top,right,bottom]=[camera,left,top,right,bottom].map(i32);
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value),c=address=>f(memory.readF64(address)),offset=camera*4,width=r(0x4a763c),horizon=r(0x491148);
  const view=r(0x4a475c);
  let angle=wrapDegreesOnce(sub32(0,add32(imul32(r(0x4a7bc8+offset),r(0x4aa730+offset)),view)));angle=imul32(idiv32(angle,2),2);
  const wave=nativeTrig(angle,options),heading=nativeTrig(view,options),phase=integer(r(0x4aca20)),divisor=integer(r(0x491170));
  const waveScale=c(0x4852b0).divide(divisor),speedScale=c(0x4a71c8+camera*8).multiply(c(0x4852b8)).divide(divisor).toNumber(),storedSine=f(wave.sine.toNumber());
  const horizontal=waveScale.multiply(phase).multiply(storedSine).subtract(heading.sine.multiply(f(speedScale)).multiply(phase)).truncI32();
  let vertical=waveScale.multiply(wave.cosine).add(heading.cosine.multiply(f(speedScale))).multiply(phase).multiply(c(0x4852c0)).truncI32();
  if(idiv32(width,4)<abs(horizontal)||idiv32(r(0x4a72d0),6)<abs(vertical))w(0x4aca20,0);
  const reset=r(0x4aca20)===0,viewForward=abs(view)<20,tack=r(0x4aa730+offset),shift=reset?0:horizontal;
  w(0x4aca24,viewForward?(tack===-1?add32(add32(idiv32(width,3),shift),left):add32(sub32(shift,idiv32(width,3)),right)):add32(idiv32(add32(left,right),2),shift));
  if(reset)vertical=0;
  w(0x4aca28,add32(idiv32(add32(horizon,imul32(bottom,2)),3),vertical));w(0x4aca20,add32(r(0x4aca20),1));
  const spacing=c(r(0x4ac4e8+offset)>1?0x484ea8:0x484e88),side=nativeTrig(wrapDegreesOnce(add32(angle,90)),options);
  const dx=side.sine.multiply(integer(width)).truncI32(),dy=side.cosine.multiply(integer(width)).truncI32(),height=sub32(bottom,horizon);
  let shiftX=0,shiftY=0;
  for(let index=0;index<=120;index++){
    const delay=0x4aa398+index*4;if(scaledRandom(100,options.rng)<2)w(delay,idiv32(r(0x491170),4));if(r(delay)>0)w(delay,sub32(r(delay),1));
    if(r(delay)<1){
      const baseY=add32(add32(r(0x4aca28),imul32(r(0x4a9450+index*4),-3)),100);
      const endY=add32(idiv32(imul32(add32(idiv32(height,40),idiv32(imul32(idiv32(r(0x4a9454+index*4),30),height),200)),baseY),height),baseY);
      const random=scaledRandom(100,options.rng);
      const brush=baseY>idiv32(imul32(height,4),5)?(random<50?0x4a622c:0x4a442c):(random>49?0x4aa954:0x4aa644);select(memory,dc,brush);
      for(const sideSign of [1,-1]){
        const centerY=add32(r(0x4aca28),imul32(sideSign,shiftY)),centerX=add32(r(0x4aca24),imul32(sideSign,shiftX));
        if(idiv32(width,4)<abs(dy)){
          const endX=add32(idiv32(imul32(sub32(endY,centerY),dx),dy),centerX);
          if(idiv32(bottom,2)<baseY){dc.moveTo(add32(idiv32(imul32(sub32(baseY,centerY),dx),dy),centerX),baseY);dc.lineTo(endX,endY);}
        }else if(add32(idiv32(sub32(bottom,horizon),2),horizon)<centerY){
          const x=idiv32(imul32(width,r(0x4a9450+index*4)),100);dc.moveTo(x,centerY);dc.lineTo(add32(idiv32(width,40),x),sub32(centerY,idiv32(dy,40)));
        }
      }
    }
    shiftX=add32(shiftX,spacing.multiply(storedSine).truncI32());shiftY=add32(shiftY,spacing.multiply(wave.cosine).truncI32());
  }
}

export const FUN_0042fe00=drawRippleSegment;
export const FUN_0042f930=drawWaterRipples;
export const FUN_0042fe40=drawLargeWaves;
