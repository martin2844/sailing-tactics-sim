import { add32,sub32,imul32,idiv32,i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { sinCosX87 } from '../../../../src/runtime/transcendentals.js';
import { wrapDegreesOnce } from '../../../../src/engine/integer-core.js';
import { bearingFromVector } from './wind.js';

export const SPATIAL_METRIC_ROUTINES=Object.freeze({projectPoint:0x42f220,
  sampleShorelineMetric:0x42f270,sampleSpatialMetric:0x42f330,sampleRadialMetric:0x42f480,
  sampleVenueMetric:0x47d5f0,pointInXStrip:0x47def0,pointInYStrip:0x47dfa0});
export const ATTENUATION_DISTANCE_ADDRESS=0x488b90;
const n=Float80.fromInteger;
const spill=value=>Float80.fromNumber(value.toNumber());
const absolute=value=>value<0?sub32(0,value):value;

/** Complete42f220; stores original integer projection globals. */
export function projectPoint(memory,x,y,distance,heading,options={}){
  x=i32(x);y=i32(y);distance=i32(distance);heading=wrapDegreesOnce(i32(heading));
  if(typeof options.trig?.extended!=='function')throw new TypeError('Native 2010 integer-angle reference required');
  const pair=options.trig.extended(heading);
  memory.writeI32(0x4fe080,add32(pair.sine.multiply(n(distance)).truncI32(),x));
  memory.writeI32(0x523180,sub32(y,pair.cosine.multiply(n(distance)).truncI32()));
}

/** Complete42f270, including signed-wrap slope differences and original shore overrides. */
export function sampleShorelineMetric(memory,x,y){
  x=i32(x);y=i32(y);
  const r=address=>memory.readI32(address),f=address=>Float80.fromNumber(memory.readF64(address));
  let index=add32(idiv32(sub32(x,r(0x4fb6c0)),250),2);if(index<2)index=2;
  const shoreY=r(0x4fbc38+index*4);
  let value=add32(n(sub32(r(0x4fbc3c+index*4),shoreY)).multiply(n(sub32(x,r(0x4fb6b8+index*4)))).multiply(f(0x4cc918)).truncI32(),shoreY);
  if(index<3)value=r(0x4fbc40);
  let result=n(absolute(sub32(value,y))).multiply(f(0x4cc8a8));
  if(r(0x5230dc)===1&&y<value||r(0x5230dc)===3&&value<y)result=f(0x4cc658);
  return result;
}

/** Complete42f480, preserving the bearing side effect and signed32 squared distance. */
export function sampleRadialMetric(memory,x,y,options={}){
  x=i32(x);y=i32(y);
  const f=address=>Float80.fromNumber(memory.readF64(address));
  const heading=bearingFromVector(memory,x,sub32(0,y),options);
  let index=idiv32(heading,2);if(index<0||index>180)index=0;
  let boundary=f(0x4ffdd8+index*8);
  if(absolute(heading)%2!==0&&index<=178)boundary=boundary.add(f(0x4ffde0+index*8)).multiply(f(0x4cc4f8));
  const radius=n(add32(imul32(x,x),imul32(y,y))).sqrt();
  let result=f(0x4cc710).subtract(f(0x4cc650).subtract(radius.divide(boundary)).multiply(f(0x4cc928)));
  if(result.compare(f(0x4cc658))<0)result=f(0x4cc658);
  return result;
}

/** Complete original horizontal strip helper; caller uses its low signed32 return. */
export function pointInXStrip(memory,x0,y0,lower0,x1,lower1,upper1,x,y){
  [x0,y0,lower0,x1,lower1,upper1,x,y]=[x0,y0,lower0,x1,lower1,upper1,x,y].map(i32);
  if(x<x0)return-1;if(x1<x)return-2;
  const width=n(sub32(x1,x0)),dx=n(sub32(x,x0));
  const lower=add32(n(sub32(lower1,lower0)).divide(width).multiply(dx).truncI32(),lower0);
  if(y<lower)return-3;
  const upper=add32(n(sub32(upper1,y0)).divide(width).multiply(dx).truncI32(),y0);
  return y<=upper?1:-4;
}

/** Complete original vertical strip helper; signed32 differences wrap before x87. */
export function pointInYStrip(memory,x0,y0,lower1,y1,upper1,upper0,x,y){
  [x0,y0,lower1,y1,upper1,upper0,x,y]=[x0,y0,lower1,y1,upper1,upper0,x,y].map(i32);
  if(y0<y)return-1;if(y<y1)return-2;
  const height=n(sub32(y1,y0)),dy=n(sub32(y,y0));
  const lower=add32(n(sub32(lower1,x0)).divide(height).multiply(dy).truncI32(),x0);
  if(x<lower)return-3;
  const upper=add32(n(sub32(upper1,upper0)).divide(height).multiply(dy).truncI32(),upper0);
  return x<=upper?1:-4;
}

/** Complete47d5f0: nearest venue point metric and all original local exceptions. */
export function sampleVenueMetric(memory,boat,x,y,mode,includeBackground,options={}){
  boat=i32(boat);x=i32(x);y=i32(y);mode=i32(mode);includeBackground=i32(includeBackground);
  const r=address=>memory.readI32(address),f=address=>Float80.fromNumber(memory.readF64(address));
  const venue=r(0x4da1f8),testX=(...args)=>pointInXStrip(memory,...args,x,y)===1;
  const testY=(...args)=>pointInYStrip(memory,...args,x,y)===1;
  const initialBounds={2:70,3:90,999:90,6:90,7:15,9:18,10:40,11:11,12:45,105:25,104:17,100:70,101:55,106:15,102:32};
  let initial=initialBounds[venue]??110;
  if(venue===6){
    if(testY(-6000,5880,-5000,-3000,3734,1860))initial=40;
    if(testY(-6000,5880,-5000,-3000,2734,860))initial=30;
  }
  let nearest=Float80.fromNumber(initial);
  const pointCount=r(0x522f08),extras=r(0x511374),marks=r(0x535498);
  let count=includeBackground===0?(extras!==0?add32(pointCount,extras):marks):add32(add32(extras,r(0x535e3c)),pointCount);
  if(mode===2)count=marks;
  for(let point=1;point<=count;point++){
    if(point>marks&&count-extras>point&&includeBackground===0)continue;
    const orientation=f(0x4fafa8+point*8).negate();
    const rotation=(options.sinCosX87??sinCosX87)(orientation);
    const dx=n(sub32(x,r(0x535218+point*4))),dy=n(sub32(y,r(0x4f4b58+point*4)));
    let localX=rotation.cosine.multiply(dx).subtract(rotation.sine.multiply(dy));
    const localY=spill(rotation.cosine.multiply(dy).add(spill(rotation.sine).multiply(dx)));
    const notch=r(0x522cb0+point*4),zero=f(0x4cc658);
    if(notch>0&&notch<36&&localX.compare(zero)>0||notch>36&&localX.compare(zero)<0)localX=localX.multiply(f(0x4cc468));
    const scaledX=localX.divide(f(0x4fb5e0+point*8));
    const square=localY.multiply(localY).add(scaledX.multiply(scaledX));
    let normalized=square.compare(zero)<0||square.compare(f(0x4cccc8))>0?f(0x4cccc0):square.sqrt().divide(n(r(0x534fe0+point*4)));
    const coefficients={1:0x4cc650,2:0x4cc650,3:0x4cc650,7:0x4cc770,9:0x4cc518,10:0x4cc660,
      11:0x4cc6d8,12:0x4cc6d8,103:0x4cc508,105:0x4cc5f0,104:0x4cc638,100:0x4cc770,
      101:0x4cc668,106:0x4cc570,102:0x4cc570};
    let coefficient=f(coefficients[venue]??0x4cc4f8);
    if(venue===999)coefficient=f(r(0x4da248)===2?(r(0x4da240)===1&&r(0x4da244)===1?0x4ccfc0:0x4cc630):0x4cc650);
    let value=normalized.multiply(f(0x4cc920)).subtract(f(0x4cc920)).multiply(coefficient);
    if(value.compare(zero)<0)value=zero;
    if(venue===7&&point===3&&y>-2700&&y<-300&&x<2160&&x>1300)value=f(0x4cc730);
    if(pointCount<point)value=value.subtract(f(0x4cc788));
    if(value.compare(nearest)<0)nearest=spill(value);
  }
  const below=address=>nearest.compare(f(address))<0;
  const set=value=>{nearest=Float80.fromNumber(value);};
  if(venue===7){
    if(testY(500,0,900,-2400,2000,2000)&&below(0x4cc418))set(9);
    if(testY(1600,2100,500,0,3000,3000)&&below(0x4cc418))set(9);
    if(x<-1200&&x>-1715&&y<300&&y>-600&&below(0x4cc418))set(9);
  }
  if(r(0x4fb5d4)===1&&x<3625&&y<6270&&nearest.compare(Float80.fromNumber(initial))<0)set(50);
  if(venue===10&&below(0x4cc838)&&testX(-7000,2700,850,2450,-3450,-1700))set(15);
  if(venue===9){
    if(testX(-90,-6200,-8000,10565,665,10280))set(30);
    if(x>-700&&x<9900&&y<912&&y>-125)set(19);
    if(testX(-6080,-720,-1404,-700,-125,912))set(22);
  }
  if(venue===11){
    if(x>6650&&x<10950&&y>2010&&y<2343&&below(0x4cc418))set(9);
    if(testX(6313,4434,3555,10250,4070,4767)&&below(0x4cc580))set(10);
  }
  if(venue===104&&x>-2345&&x<-1276&&y>-1600&&below(0x4cc5d0))set(25);
  if(venue===105&&testY(-3380,-1243,-3580,-2470,-3120,-2740)&&below(0x4cc5a0))set(30);
  if(venue===102&&testY(-1400,-1700,-5500,-3400,-270,791)&&below(0x4cc5a0))set(30);
  return nearest;
}

/** Complete42f330 spatial dispatcher with original ellipse spill and bounded result. */
export function sampleSpatialMetric(memory,x,y,boat,options={}){
  x=i32(x);y=i32(y);boat=i32(boat);
  const r=address=>memory.readI32(address),f=address=>Float80.fromNumber(memory.readF64(address));
  if(r(0x4f69b8)>1&&r(0x4da1f8)===0)return sampleRadialMetric(memory,x,y,options);
  if(r(0x50040c)===1&&r(0x4da1f8)===0)return sampleShorelineMetric(memory,x,y);
  if(r(0x4da1f8)>0&&(r(0x5364b0)===0||r(0x5364b0)===1))return sampleVenueMetric(memory,boat,x,y,0,r(0x5364b0),options);
  const dx=n(sub32(x,r(0x535bc8))).divide(f(0x4fba00));
  const dy=n(sub32(y,r(0x4f3858))).divide(f(0x535558));
  let result=f(0x4cc920).subtract(dy.multiply(dy).add(dx.multiply(spill(dx))).sqrt().divide(n(r(0x4f4b00))).multiply(f(0x4cc920)));
  result=r(0x4f8b78)===0?result.add(result):result.negate();
  if(r(0x4f4510)===1)result=result.add(result);
  if(result.compare(f(0x4cc658))<0)result=f(0x4cc658);
  if(result.compare(f(0x4cc490))>0)result=f(0x4cc490);
  return result;
}

/** Complete488b90; twenty-one original probes and profile-specific scan limits. */
export function sampleAttenuationDistance(memory,mode,x,y,boat,options={}){
  mode=i32(mode);x=i32(x);y=i32(y);boat=i32(boat);
  if(mode!==0&&mode!==1)throw new RangeError('Original attenuation sampler has defined metric inputs for modes0/1');
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  const f=address=>Float80.fromNumber(memory.readF64(address));
  const venue=r(0x4da1f8);
  w(0x4da218,r(0x4fb5d4)===1||venue===11?6600:2200);
  if([6,9,104,100].includes(venue))w(0x4da218,4400);
  if(venue===101||venue===103)w(0x4da218,4100);
  if(venue===106)w(0x4da218,3300);
  let heading=wrapDegreesOnce(mode===1?r(0x5362d4):r(0x522d30+boat*4));
  for(let step=1;step<=21;step++){
    const maximum=r(0x4da218),distance=maximum>=6001?step*3:maximum>4000?step*2:step;
    heading=wrapDegreesOnce(wrapDegreesOnce(heading));
    if(heading<0||heading>360)heading=0;
    const testX=add32(imul32(r(0x4f85c8+heading*4),distance),x);
    const testY=sub32(y,imul32(r(0x4f1740+heading*4),distance));
    const metric=venue<1?sampleSpatialMetric(memory,testX,testY,boat,options):sampleVenueMetric(memory,boat,testX,testY,mode===1?2:1,0,options);
    const stored=spill(metric);
    if(mode===0&&stored.compare(f(0x4cc728))<0||mode===1&&stored.compare(f(0x4cc650))<=0)return imul32(distance,100);
  }
  return r(0x4da218);
}
