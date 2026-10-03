import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { displayedTargetMark, readAnsiString } from '../engine/hud-state.js';
import { drawHudButton } from './hud.js';
import { drawChartObjects } from './chart-details.js';
import { drawChartMarkLabel } from './chart-labels.js';
import { drawBasicChartTerrain, drawAdvancedChartTerrain } from './chart-terrain.js';
import { drawWindVectorGrid, drawCurrentVectorGrid, drawWindChartOverlay, drawTideChartOverlay, drawCourseChartOverlay } from './chart-overlays.js';

const f=Float80.fromNumber,integer=Float80.fromInteger;
const select=(memory,dc,address)=>{const handle=memory.readU32(address);if(handle)dc.selectObject(handle);};

/** Complete original 0x407e40 chart composition and chart zoom click handling. */
export function drawChart(memory,dc,left,top,right,bottom,camera,mode,options={}){
  [left,top,right,bottom,camera,mode]=[left,top,right,bottom,camera,mode].map(i32);
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value),c=address=>f(memory.readF64(address)),text=address=>readAnsiString(memory,address);
  dc.pushClipRect(left,top,right,bottom);dc.selectStockObject(7);dc.selectStockObject(7);
  select(memory,dc,r(0x4ac92c)===0&&r(0x4ac98c)===0?0x4aa714:0x4aa7f4);
  if(r(0x4ac98c)===1&&mode>0&&mode<3)select(memory,dc,0x4aa7f4);
  if(mode===1&&((camera===1&&r(0x4aa62c)>0&&r(0x4a8664)===2)||(camera===2&&r(0x4aa638)>0&&r(0x4a8668)===2)))select(memory,dc,0x4a5b8c);
  dc.rectangle(left,top,right,bottom);
  let originX=mode,originY=mode,scale;
  if(mode===1){originX=idiv32(add32(imul32(right,5),imul32(left,4)),9);originY=idiv32(add32(imul32(bottom,5),imul32(top,4)),9);scale=c(0x4ab0c8).multiply(c(0x484cf0)).divide(integer(r(0x4a8660+camera*4))).toNumber();}
  if(mode===2){originX=idiv32(add32(right,left),2);originY=idiv32(add32(imul32(top,5),imul32(bottom,4)),9);scale=c(0x4ab0c8).multiply(c(r(0x491194)===8?(r(0x4a5a4c)===0?0x484d00:0x484d08):0x484cf8)).toNumber();}
  if(mode>2){
    originX=idiv32(add32(right,left),2);originY=idiv32(add32(bottom,top),2);
    let factor=0x484d10;if(r(0x4a4958)===2||r(0x4a4958)===3)factor=0x484d18;
    if(r(0x491194)===8&&r(0x4a5a4c)===0)factor=0x484d20;if(r(0x491194)===8&&r(0x4a5a4c)===1)factor=0x484d28;
    scale=c(0x4a8670).multiply(c(factor)).divide(integer(r(0x4ab184))).toNumber();
  }
  if(scale===undefined)throw new RangeError('Original chart drawing requires view mode1,2,3 or4');
  const centerX=mode===1?c(0x4a49e8+camera*8).truncI32():r(0x4aa594),centerY=mode===1?c(0x4a4ae0+camera*8).truncI32():r(0x4aa59c);
  if(r(0x4ac970)===1)drawWindVectorGrid(memory,dc,scale,originX,originY);
  if(r(0x4ac974)===1)drawCurrentVectorGrid(memory,dc,scale,originX,originY,options);
  const terrain=()=>{if(r(0x4a4958)<2)drawBasicChartTerrain(memory,dc,originX,originY,scale,centerX,centerY,mode,camera);if(r(0x4a4958)>1)drawAdvancedChartTerrain(memory,dc,originX,originY,scale,centerX,centerY,mode,camera);};
  if(mode>2)terrain();
  w(0x4aa7e0,displayedTargetMark(memory,camera));
  drawChartObjects(memory,dc,originX,originY,scale,centerX,centerY,mode,camera,left,top,right,bottom,{...options,drawChartMarkLabel});
  if(mode<3)terrain();
  if(r(0x4ac970)===1)drawWindChartOverlay(memory,dc,left,top,right);
  if(r(0x4ac974)===1)drawTideChartOverlay(memory,dc,left,top,right,options);
  if(r(0x4aa980)===1)drawCourseChartOverlay(memory,dc,left,top,right);
  dc.selectStockObject(7);
  if(mode===1){
    const height=idiv32(r(0x4a72d0),28),color=r(0x4ac92c)===0?0xffff00:0xffffff;
    dc.setBkColor(0x7f7f7f);dc.setTextColor(color);
    if(camera===1){
      const buttonRight=add32(integer(r(0x4a763c)).multiply(c(0x484cf8)).truncI32(),left);
      let row=top,buttonBottom=add32(row,height);
      drawHudButton(memory,dc,left,row,buttonRight,buttonBottom,1,-1);dc.textOut(add32(left,3),row,text(0x4918b4));drawHudButton(memory,dc,add32(left,1),row,buttonRight,buttonBottom,0,-1);
      row=add32(buttonBottom,2);
      if(left<r(0x4a774c)&&r(0x4a774c)<buttonRight&&r(0x4aa97c)<row&&sub32(row,height)<r(0x4aa97c)){
        w(0x4a8664,Math.max(2,idiv32(r(0x4a8664),2)));w(0x4aa97c,0);dc.setTextColor(0);dc.textOut(add32(left,3),sub32(sub32(row,height),2),text(0x4918b4));
      }
      buttonBottom=add32(row,height);drawHudButton(memory,dc,left,row,buttonRight,buttonBottom,1,-1);dc.setTextColor(color);dc.textOut(add32(left,5),row,text(0x4918b0));drawHudButton(memory,dc,left,row,buttonRight,buttonBottom,0,-1);
      if(left<r(0x4a774c)&&r(0x4a774c)<buttonRight&&r(0x4aa97c)<buttonBottom&&sub32(buttonBottom,height)<r(0x4aa97c)){
        w(0x4a8664,imul32(r(0x4a8664),2));w(0x4a775c,r(0x4a4958)<2?128:64);if(r(0x4a775c)<r(0x4a8664))w(0x4a8664,r(0x4a775c));w(0x4aa97c,0);dc.setTextColor(0);dc.textOut(add32(left,5),row,text(0x4918b0));
      }
    }
    if(camera===2){
      const buttonRight=add32(integer(r(0x4a763c)).multiply(c(0x484d30)).truncI32(),left);
      for(const [row,address] of [[top,0x4918a8],[add32(top,height),0x4918a0]]){
        const buttonBottom=add32(row,height);drawHudButton(memory,dc,left,row,buttonRight,buttonBottom,1,1);dc.setTextColor(color);dc.textOut(add32(left,3),row,text(address));drawHudButton(memory,dc,left,row,buttonRight,buttonBottom,0,1);
      }
    }
  }
  dc.popClipRect();
}

export const FUN_00407e40=drawChart;
