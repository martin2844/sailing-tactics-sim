import { add32,sub32,imul32,idiv32,i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { sinCosX87 } from '../../../../src/runtime/transcendentals.js';
import { wrapDegreesOnce } from '../../../../src/engine/integer-core.js';
import { VENUE_GEOMETRY_ADDRESSES as a } from './venue-geometry.js';

export const CUSTOM_VENUE_ADDRESSES=Object.freeze({
  initializeCustomVenuePoint:0x48b8a0,length:0x4da238,
  firstHeading:0x4da23c,firstLeft:0x4da240,firstRight:0x4da244,firstSize:0x4da248,
  firstWind:0x4da250,firstSign:0x4da270,
  secondHeading:0x4da25c,secondLeft:0x4da254,secondRight:0x4da258,secondSize:0x4da260,
  secondWind:0x536500,secondMode:0x536504,secondSign:0x4da274,
  firstBearing:0x51359c,secondBearing:0x4f711c,
  terrainHeight:0x4f45c0,terrainWind:0x4f3ef0,
  drawStart:0x535310,drawEnd:0x535370,noise:0x512d70,
});
const notchFactors=[0x4ccac8,0x4ccd68,0x4cc848,0x4cc6c0,0x4ccc70,0x4cc508,
  0x4ccc00,0x4ccbe0,0x4cc738,0x4cc738,0x4ccbe0,0x4ccc00,0x4cc508,
  0x4ccc70,0x4cc6c0,0x4cc848,0x4ccd68,0x4ccac8];
const indexed=(base,index,stride=4)=>(base+Math.imul(i32(index),stride))>>>0;
const spill=value=>Float80.fromNumber(value.toNumber());

/** Complete original48b8a0, including retained centers, two custom bays and72 vertices. */
export function initializeCustomVenuePoint(memory,index,options={}) {
  index=i32(index);
  if(index<1||index>10)throw new RangeError('Original custom point presets are defined for indices1..10');
  if(typeof options.trig?.extended!=='function')throw new TypeError('Load the 2010 native integer-angle reference before generating custom points');
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  const f=address=>Float80.fromNumber(memory.readF64(address));
  const n=Float80.fromInteger;
  const read=key=>r(CUSTOM_VENUE_ADDRESSES[key]);
  const write=key=>value=>w(CUSTOM_VENUE_ADDRESSES[key],value);
  const wi=(field,value)=>w(indexed(a[field],index),value);
  const wf=(field,value)=>memory.writeF64(indexed(a[field],index,8),value instanceof Float80?value.toNumber():value);
  const setHeight=value=>memory.writeF64(indexed(CUSTOM_VENUE_ADDRESSES.terrainHeight,index,8),value);
  const setWind=value=>w(indexed(CUSTOM_VENUE_ADDRESSES.terrainWind,index),value);
  const setDrawing=(start,end)=>{w(indexed(CUSTOM_VENUE_ADDRESSES.drawStart,index),start);w(indexed(CUSTOM_VENUE_ADDRESSES.drawEnd,index),end);};
  const length=read('length');
  const firstSize=read('firstSize');
  const firstFactor=Float80.fromNumber(firstSize===1?0.98:firstSize===2?0.7:1.35);
  const secondFactor=Float80.fromNumber(read('secondSize')===1?1:1.4);
  const coordinate=(angle,factorsX,factorsY)=>{
    const pair=options.trig.extended(i32(angle));
    const product=(value,factors)=>factors.reduce((acc,operand)=>acc.multiply(operand),value.multiply(n(length)));
    wi('centerX',product(pair.sine,factorsX).truncI32());
    wi('centerY',product(pair.cosine,factorsY).truncI32());
  };
  const orientation=degrees=>wf('orientation',n(wrapDegreesOnce(i32(degrees))).multiply(f(0x4cc568)));
  const sign=(left,right)=>left===-1&&right===1?1:left===1&&right===-1?-1:0;
  const side=(heading,setting,reverse=false)=>{
    if(![-1,0,1].includes(setting))throw new RangeError('Original custom side settings require−1,0,1');
    const delta=setting===1?15:setting===-1?-15:0;
    return{heading:add32(heading,reverse?-delta:delta),factor:Float80.fromNumber(setting===1?1.7:setting===0?2:2.5)};
  };
  const pointAspect=()=>wf('aspect',length===1500?0.5:length===2500?0.44:0.48);
  let gap=0;

  if(index===1){
    const left=read('firstLeft'),right=read('firstRight'),heading=read('firstHeading');
    if(left===-1&&right===-1){
      const extra=f(firstSize===2?0x4cc538:0x4cd028);
      coordinate(heading,[extra,firstFactor,f(0x4cd030)],[extra,firstFactor,f(0x4cd038)]);
    }
    if(left===0&&right===0)coordinate(heading,[firstFactor,f(0x4cd040)],[firstFactor,f(0x4cd048)]);
    if(left===1&&right===1){
      const extra=f(firstSize===2?0x4cd050:0x4cc468);
      coordinate(heading,[extra,firstFactor,f(0x4cd030)],[extra,firstFactor,f(0x4cd038)]);
    }
    const turn=sign(left,right);write('firstSign')(turn);
    if(turn!==0)coordinate(heading,[firstFactor,f(0x4cd000)],[firstFactor,f(0x4cd058)]);
    pointAspect();wi('radius',imul32(length,4));
    if(left===-1&&right===-1&&firstSize===0)wi('radius',imul32(length,5));
    if(left===-1&&right===-1&&firstSize===2)wi('radius',add32(idiv32(length,15),imul32(length,4)));
    orientation(add32(heading,turn===1?84:turn===-1?96:90));
    write('firstBearing')(f(indexed(a.orientation,index,8)).multiply(f(0x4cc3e8)).truncI32());
    wi('notch',left===-1&&right===-1?-1:turn===1?12:turn===-1?8:10);
    setHeight(0);setWind(read('firstWind'));
    setDrawing(left===1&&right===1?14:10,left===1&&right===1?22:26);
  }
  if(index===2||index===3){
    const reverse=index===3;
    const heading=read('firstHeading'),setting=read(reverse?'firstRight':'firstLeft');
    const info=side(add32(heading,90),setting,reverse);
    const offset=length===1500?50:length===2500?44:47;
    coordinate(add32(heading,reverse?-offset:offset),[firstFactor,info.factor,f(0x4cca00)],[firstFactor,info.factor,f(0x4cd070)]);
    wi('radius',imul32(length,firstSize>0?5:6));wf('aspect',0.3);
    // The third point intentionally tests the first side here, not the second.
    if(index===2&&read('firstLeft')===-1||index===3&&read('firstLeft')===1){
      wi('radius',n(r(indexed(a.radius,index))).multiply(f(0x4cc7b8)).truncI32());
    }
    orientation(info.heading);wi('notch',reverse?9:10);
    setHeight(0);setWind(Math.min(read('firstWind'),1));setDrawing(5,36);
  }
  if(index===4||index===5){
    const heading=read('firstHeading'),left=read('firstLeft'),right=read('firstRight');
    coordinate(add32(heading,index===4?-30:25),[firstFactor,f(0x4cc7a0)],[firstFactor,f(0x4cc798)]);
    wi('radius',imul32(length,9));wf('aspect',left===1&&right===1?0.48:f(0x4cc660));
    const delta=read('firstSign')!==0?18:0;
    const setting=index===4?left:right;
    side(0,setting);
    const offset=setting===1?(index===4?delta:-delta):setting===-1?(index===4?-delta:delta):0;
    orientation(add32(add32(heading,90),offset));wi('notch',index===4?8:10);
    setHeight(1);setWind(0);setDrawing(0,0);
  }
  if(index===6){
    const left=read('secondLeft'),right=read('secondRight'),heading=read('secondHeading');
    if(left===-1&&right===-1)coordinate(heading,[secondFactor,f(0x4cd078)],[secondFactor,f(0x4cd080)]);
    if(left===0&&right===0)coordinate(heading,[secondFactor,f(0x4cd088)],[secondFactor,f(0x4cd090)]);
    if(left===1&&right===1)coordinate(heading,[secondFactor,f(0x4cd098)],[secondFactor,f(0x4cd0a0)]);
    const turn=sign(left,right);write('secondSign')(turn);
    if(turn!==0)coordinate(heading,[secondFactor,f(0x4cd000)],[secondFactor,f(0x4cd058)]);
    pointAspect();wi('radius',imul32(length,read('secondMode')===1?5:4));
    orientation(add32(heading,turn===1?84:turn===-1?96:90));
    write('secondBearing')(f(indexed(a.orientation,index,8)).multiply(f(0x4cc3e8)).truncI32());
    wi('notch',left===-1&&right===-1?-1:turn===1?12:turn===-1?8:10);
    setHeight(0);setWind(read('secondWind'));
    if(read('secondMode')>0){wi('radius',idiv32(r(indexed(a.radius,index)),3));setWind(0);}
    setDrawing(10,26);
  }
  if(index===7||index===8){
    const reverse=index===8,heading=read('secondHeading');
    const setting=read(reverse?'secondRight':'secondLeft');
    const info=side(add32(heading,90),setting,reverse);
    const offset=length===1500?50:length===2500?44:47;
    coordinate(add32(heading,reverse?-offset:offset),[secondFactor,info.factor,f(0x4cca00)],[secondFactor,info.factor,f(0x4cd070)]);
    wf('aspect',f(0x4cc660));wi('radius',imul32(length,6));
    if(index===7&&read('secondLeft')===-1||index===8&&read('secondLeft')===1){
      wi('radius',n(r(indexed(a.radius,index))).multiply(f(0x4cc7b8)).truncI32());
    }
    orientation(info.heading);wi('notch',10);setHeight(0);setWind(Math.min(read('secondWind'),1));
    if(read('secondMode')===3){
      wi('radius',idiv32(r(indexed(a.radius,index)),3));wi('notch',reverse?1:30);gap=reverse?34:4;setWind(0);
    }
    setDrawing(0,72);
  }
  if(index===9||index===10){
    const heading=read('secondHeading'),left=read('secondLeft'),right=read('secondRight');
    coordinate(add32(heading,index===9?-30:25),[secondFactor,f(0x4cc7a0)],[secondFactor,f(0x4cc798)]);
    wi('radius',imul32(length,9));wf('aspect',left===1&&right===1?0.52:f(0x4cceb0));
    const delta=read('secondSign')!==0?18:0;
    // Both original outer second-bay points read secondLeft for orientation.
    side(0,left);orientation(add32(add32(heading,90),left===1?delta:left===-1?-delta:0));
    wi('notch',10);setHeight(1);setWind(0);setDrawing(0,0);
  }

  const rotation=(options.sinCosX87??sinCosX87)(f(indexed(a.orientation,index,8)));
  const rotationCosine=spill(rotation.cosine),rotationSine=spill(rotation.sine);
  const radiusBase=r(indexed(a.radius,index)),centerX=r(indexed(a.centerX,index)),centerY=r(indexed(a.centerY,index));
  const notch=r(indexed(a.notch,index)),polygonOffset=imul32(index,0x124);
  for(let vertex=0;vertex<72;vertex++){
    let radius=n(sub32(radiusBase,r(CUSTOM_VENUE_ADDRESSES.noise+vertex*4)));
    if(notch>0)for(const [offset,address]of notchFactors.entries()){
      if(vertex===add32(notch,offset))radius=spill(radius.multiply(f(address)));
    }
    if(gap>0){
      if(vertex===gap-1)radius=spill(radius.multiply(f(0x4ccd70)));
      if(vertex===gap)radius=spill(radius.multiply(f(0x4cc630)));
      if(vertex===gap+1)radius=spill(radius.multiply(f(0x4ccd70)));
    }
    const {sine,cosine}=options.trig.extended(vertex*5);
    const localX=sine.multiply(f(indexed(a.aspect,index,8))).multiply(radius);
    const localY=cosine.multiply(radius).negate(),storedY=spill(localY);
    const x=localX.multiply(rotationCosine).subtract(localY.multiply(rotationSine));
    const y=localX.multiply(rotationSine).add(storedY.multiply(rotationCosine));
    const offset=add32(polygonOffset,vertex*4);
    w((a.polygonX+offset)>>>0,add32(x.truncI32(),centerX));
    // The final Y truncation reloads its binary64 spill at48ce6b.
    w((a.polygonY+offset)>>>0,add32(spill(y).truncI32(),centerY));
  }
  w((a.polygonX+polygonOffset+0x120)>>>0,r((a.polygonX+polygonOffset)>>>0));
  w((a.polygonY+polygonOffset+0x120)>>>0,r((a.polygonY+polygonOffset)>>>0));
  const pointCount=r(a.pointCount),placement=r(a.placementMode);
  for(let point=0,offset=imul32(r(a.boatCount),8);point<pointCount;point++,offset=add32(offset,8)){
    if(placement===0||placement===1){
      const extra=placement===1?16:0;
      memory.writeF64((a.targetX+offset+extra)>>>0,r(a.centerX+4+point*4));
      memory.writeF64((a.targetY+offset+extra)>>>0,r(a.centerY+4+point*4));
    }
  }
}
