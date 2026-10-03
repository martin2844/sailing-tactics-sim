import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { nativeTrig } from '../engine/native-trig.js';
import { bearingFromVector } from '../engine/angles.js';
import { sampleSpatialWind } from '../engine/spatial-wind.js';
import { sampleCurrent } from '../engine/current.js';
import { targetRelativeBearing } from '../engine/target-bearing.js';
import { sinCosX87 } from '../runtime/transcendentals.js';
import { formatInteger, formatDecimal, readAnsiString } from '../engine/hud-state.js';
import { drawArrow } from './chart-labels.js';

const f=Float80.fromNumber,integer=Float80.fromInteger;
const select=(memory,dc,address)=>{const handle=memory.readU32(address);if(handle)dc.selectObject(handle);};
const abs=value=>value<0?sub32(0,value):value;

function project(memory,x,y,scale,originX,originY){
  const bearing=targetRelativeBearing(memory,x,y,4,0);
  if(memory.readF64(0x4a6828)>memory.readF64(0x484d38))memory.writeF64(0x4a6828,7000);
  const {sine,cosine}=sinCosX87(bearing),distance=f(memory.readF64(0x4a6828));
  return [sine.multiply(f(scale)).multiply(distance).add(integer(originX)).truncI32(),integer(originY).subtract(cosine.multiply(f(scale)).multiply(distance)).truncI32()];
}

/** Complete original 0x408860 spatial wind vector grid. */
export function drawWindVectorGrid(memory,dc,scale,originX,originY){
  const r=address=>memory.readI32(address),spacing=idiv32(r(0x4ab184),r(0x491194)===8?9:5);
  for(let column=-10;column<=10;column++)for(let row=-10;row<=10;row++){
    const x=add32(imul32(column,spacing),r(0x4aa594)),y=add32(imul32(row,spacing),r(0x4aa59c));
    select(memory,dc,0x4a4ee4);const strength=sampleSpatialWind(memory,x,y,0);
    if(r(0x4a4390)===1)select(memory,dc,0x4abbf4);if(r(0x4a4390)===-1)select(memory,dc,0x4a39fc);
    if(r(0x4a5f0c)===1)select(memory,dc,0x4a67ac);if(r(0x4abd84)===1)select(memory,dc,0x4ac30c);
    if(r(0x4a5b94)===1)select(memory,dc,0x4a676c);
    if(r(0x4ac92c)===1){if(r(0x4a5b94)===0)select(memory,dc,0x4a4ee4);if(r(0x4a5b94)===1)select(memory,dc,0x4a4dec);}
    const [screenX,screenY]=project(memory,x,y,scale,i32(originX),i32(originY));drawArrow(memory,dc,screenX,screenY,r(0x4aaeac),idiv32(120,strength));
  }
}

/** Complete original 0x408b00 tide/current vector grid. */
export function drawCurrentVectorGrid(memory,dc,scale,originX,originY,options={}){
  const r=address=>memory.readI32(address),spacing=idiv32(r(0x4ab184),r(0x491194)===8?9:5);
  for(let column=-10;column<=10;column++)for(let row=-10;row<=10;row++){
    const x=add32(imul32(column,spacing),r(0x4aa594)),y=add32(imul32(row,spacing),r(0x4aa59c));
    select(memory,dc,0x4a4ee4);const strength=abs(sampleCurrent(memory,x,y,0,options));
    const [screenX,screenY]=project(memory,x,y,scale,i32(originX),i32(originY));if(strength>0)drawArrow(memory,dc,screenX,screenY,r(0x4aa960),idiv32(70,strength));
  }
}

/** Complete original 0x4094c0 wind chart legend and suspended-movement text. */
export function drawWindChartOverlay(memory,dc,left,top,right){
  [left,top,right]=[left,top,right].map(i32);
  const r=address=>memory.readI32(address),text=address=>readAnsiString(memory,address),mono=r(0x4ac92c);
  dc.selectStockObject(4);dc.selectStockObject(6);dc.rectangle(left,top,right,add32(top,20));dc.setBkColor(0);dc.setTextColor(0xffffff);
  dc.textOut(1,1,text(0x491a44));
  if(mono===0){
    for(const [color,x,address] of [[0xffff,200,0x491a3c],[0xff00ff,280,0x491a30],[0xff00,390,0x491a24],[0xff,500,0x491a1c],[0xffff00,550,0x491a10]]){dc.setTextColor(color);dc.textOut(x,1,text(address));}
  }else dc.textOut(200,1,text(0x4919ec));
  if(mono===0){dc.setTextColor(0x7f);dc.setBkColor(0xffffff);}
  dc.textOut(1,idiv32(r(0x4a72d0),27),text(0x4918bc));
}

/** Complete original 0x409050 course information and leg compass bearings. */
export function drawCourseChartOverlay(memory,dc,left,top,right){
  [left,top,right]=[left,top,right].map(i32);
  const r=address=>memory.readI32(address),text=address=>readAnsiString(memory,address),mono=r(0x4ac92c),height=r(0x4a72d0);
  dc.setBkMode(1);dc.selectStockObject(4);dc.selectStockObject(6);dc.rectangle(left,top,right,add32(top,40));dc.setBkColor(0);dc.setTextColor(mono===0?0xffff:0xffffff);
  dc.textOut(1,1,text(r(0x4ac9a8)===1?0x4919c4:0x4919a0));
  const longCourse=r(0x491160)===0||r(0x49118c)>14;
  const bearings=[r(0x4abc80),bearingFromVector(sub32(r(0x4aa38c),r(0x4aa294)),sub32(r(0x4aa388),r(0x4aa588))),
    longCourse?bearingFromVector(sub32(r(0x4aa288),r(0x4aa38c)),sub32(r(0x4aa588),r(0x4aa384))):r(0x4abc80)];
  for(const [index,address] of [0x491994,0x491980,0x491974].entries())dc.textOut(index===0?1:index*160,idiv32(height,30),text(address)+formatInteger(bearings[index])+text(0x49198c));
  if(longCourse)dc.textOut(480,idiv32(height,30),text(0x491968)+formatInteger(r(0x4abc80))+text(0x49198c));
  dc.setBkMode(2);if(mono===0){dc.setTextColor(0x7f);dc.setBkColor(0xffffff);}
  dc.textOut(1,idiv32(imul32(height,2),27),text(0x4918bc));
}

/** Complete original 0x408c70 tide time and deep-water strength overlay. */
export function drawTideChartOverlay(memory,dc,left,top,right,options={}){
  [left,top,right]=[left,top,right].map(i32);
  const r=address=>memory.readI32(address),text=address=>readAnsiString(memory,address),mono=r(0x4ac92c),offset=r(0x4ac94c);
  dc.selectStockObject(4);dc.selectStockObject(6);dc.rectangle(left,top,right,add32(top,20));dc.setBkColor(0);dc.setTextColor(mono===0?0xffff:0xffffff);dc.textOut(1,1,text(0x491958));
  if(mono===0)dc.setTextColor(0xff00ff);
  dc.textOut(150,1,offset<1?text(0x491924):text(0x491944)+formatInteger(offset)+text(offset<2?0x491934:0x49193c));
  if(mono===0)dc.setTextColor(0xffff);
  const angle=imul32(add32(sub32(offset,r(0x4a8020)),r(0x4a4be4)),30),{sine}=nativeTrig(angle,options);
  const strength=abs(sine.multiply(integer(r(0x4ac1dc))).truncI32());
  const value=formatDecimal(memory,integer(strength).multiply(f(memory.readF64(0x484d48))).toNumber());
  dc.textOut(370,1,text(0x49190c)+value+text(strength<11?0x4918fc:0x491904));
  if(mono===0){dc.setTextColor(0x7f);dc.setBkColor(0xffffff);}
  dc.textOut(1,idiv32(r(0x4a72d0),27),text(0x4918bc));
}

export const FUN_00408860=drawWindVectorGrid;
export const FUN_00408b00=drawCurrentVectorGrid;
export const FUN_004094c0=drawWindChartOverlay;
export const FUN_00409050=drawCourseChartOverlay;
export const FUN_00408c70=drawTideChartOverlay;
