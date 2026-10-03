import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { displayedTargetMark, formatInteger, readAnsiString } from '../engine/hud-state.js';
import { projectScenePoint, projectedSize, updatePlayer1Camera, updatePlayer2Camera } from './projection.js';
import { drawSky } from './sky.js';
import { drawWaterRipples, drawLargeWaves } from './water.js';
import { drawSceneWindPatch } from './scene-wind.js';
import { drawSceneObjects } from './scene-objects.js';
import { drawProjectedShoreline, drawShoreMarker, drawHarborHouse, drawHarborBuilding,
  drawShoreBuilding, drawShoreHouse, drawLighthouse, drawHeadingIndicator, drawSceneLayline } from './shore.js';

const select = (memory,dc,address) => { const handle=memory.readU32(address);if(handle)dc.selectObject(handle); };
const absolute = value => sub32(value^(value>>31),value>>31);

/** Original 0x430f90 penalty/finish/suspended-motion text and color changes. */
export function drawSceneWarning(memory,dc,left,camera){
  left=i32(left);camera=i32(camera);
  const r=address=>memory.readI32(address),text=address=>readAnsiString(memory,address);
  if(r(0x4ac92c)===0){dc.setBkColor(r(0x4ac8fc)===1?0xffffff:0);dc.setTextColor(0xff);}
  const penalty=r(0x4a89c0+camera*4);
  const messages=new Map([[1,0x4936c4],[2,0x49369c],[3,0x493668],[4,0x493644],
    [5,0x49361c],[6,0x4935f4],[7,0x4935c8],[10,0x4935bc]]);
  if(messages.has(penalty))dc.textOut(left,1,text(messages.get(penalty)));
  if(penalty===11)dc.textOut(left,1,text(0x49317c)+formatInteger(camera)+text(0x4935b0)
    +formatInteger(r(0x4a7648+camera*4))+text(0x493590));
  if(r(0x4ac8fc)===1&&camera===r(0x491140))dc.textOut(left,1,text(0x493564));
  if(r(0x4ac968)===1&&camera===r(0x491140))dc.textOut(left,1,text(0x493564));
  dc.setBkColor(0xffffff);dc.setTextColor(0);
}

/** Complete 0x404880 camera scene composition. Drawing helpers retain native argument order. */
export function drawScene(memory,dc,left,top,right,bottom,camera,options={}){
  [left,top,right,bottom,camera]=[left,top,right,bottom,camera].map(i32);
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value),text=address=>readAnsiString(memory,address);
  dc.pushClipRect(left,top,right,bottom);
  w(0x4a3fa0,idiv32(add32(right,left),2));
  const height=sub32(bottom,top),viewAddress=0x4a4e88+camera*4;
  let eye=sub32(bottom,idiv32(height,10));
  if(r(viewAddress)===1)eye=sub32(eye,idiv32(height,15));
  if(r(viewAddress)===2)eye=sub32(eye,idiv32(height,7));
  if(r(viewAddress)===3)eye=sub32(eye,idiv32(height,5));
  if(r(0x4a72d0)>600&&r(viewAddress)<3)eye=sub32(eye,idiv32(height,7));
  w(0x4a4760,eye);
  updatePlayer1Camera(memory);if(r(0x491140)===2)updatePlayer2Camera(memory);
  w(0x491148,r(viewAddress)>2?0:30);
  dc.selectStockObject(7);
  select(memory,dc,r(0x4ac92c)===0&&r(0x4ac98c)===0?0x4a6dac:0x4aa7f4);
  if(r(0x4ac98c)===1&&r(0x4aaa1c)>8)select(memory,dc,0x4a7bc4);
  dc.rectangle(left,top,right,bottom);
  for(let patch=1;patch<6;patch++)if(r(0x4ac98c)===0)drawSceneWindPatch(memory,dc,patch,camera,left,top,right,bottom,options);
  if(r(0x4ac928)===0&&r(0x49116c)<13&&r(0x4ac92c)===0&&r(0x4ac98c)===0)drawLargeWaves(memory,dc,camera,left,top,right,bottom,options);
  drawWaterRipples(memory,dc,camera,left,top,right,bottom,options);
  dc.selectStockObject(7);
  const twilight=r(0x4a4be4)===20||r(0x4a4be4)===6;
  select(memory,dc,r(0x4ac92c)===0&&r(0x4a5b98)<3?(twilight?0x4aa714:0x4a469c):(twilight?0x4a70e4:0x4a3efc));
  if(r(0x4ac98c)===1)select(memory,dc,0x4ac8f4);
  dc.rectangle(left,top,right,r(0x491148));
  if(r(viewAddress)<3)drawSky(memory,dc,camera);
  const shore=(first,last)=>drawProjectedShoreline(memory,dc,r(0x491148),first,last,camera,left,top,right,bottom,r(0x491148),options);
  if(r(0x4a4958)<2){if(r(0x4a864c)===1)shore(2,36);if(r(0x4a864c)===0)shore(0,36);}else shore(0,180);
  const project=(xAddress,yAddress)=>projectScenePoint(memory,0,r(xAddress),r(yAddress),camera,0,options);
  const inView=()=>left<r(0x4a7c48)&&r(0x4a7c48)<right&&r(0x4aaa48)<bottom;
  const draw=(fn,...args)=>fn(memory,dc,r(0x4a7c48),r(0x4aaa48),...args,options);
  const at=(x,y,fn,...args)=>{project(x,y);if(inView())draw(fn,...args);};
  if(r(0x4a5a4c)===0){
    const count=r(0x4a4958)<3||r(0x4a4958)>7?5:7;
    for(let index=1;index<=count;index++){
      project(0x4a899c+(index-1)*4,0x4ac674+(index-1)*4);
      const x=r(0x4a7c48),y=sub32(r(0x4aaa48),idiv32(r(0x4a72d0),300));
      if(x>=0&&x<=r(0x4a763c)&&y>=r(0x491148)&&y<=idiv32(r(0x4a72d0),2)){
        const size=Float80.fromInteger(r(0x4aa7b4+(index-1)*4)).multiply(projectedSize(memory,y,camera)).truncI32();
        if(y<idiv32(r(0x4a72d0),2)&&x>0&&x<r(0x4a763c)){
          if(r(0x4ac92c)===0&&r(0x4ac98c)===0){dc.selectStockObject(8);select(memory,dc,0x4a621c);}
          else {select(memory,dc,0x4a71bc);select(memory,dc,0x4a70e4);}
          if(r(0x4ac98c)===1){dc.selectStockObject(8);select(memory,dc,0x4aa7f4);}
          const points=[{x:sub32(x,imul32(size,4)),y},{x,y:sub32(y,idiv32(size,2))},{x:add32(x,imul32(size,index%2?5:3)),y}];
          for(let p=0;p<3;p++){w(0x4a4ca8+p*8,points[p].x);w(0x4a4cac+p*8,points[p].y);}
          dc.polygon(points);dc.selectStockObject(7);dc.moveTo(points[0].x,points[0].y);dc.lineTo(points[1].x,points[1].y);dc.lineTo(points[2].x,points[2].y);
        }
      }
    }
  }
  if(r(0x4a4958)>1){
    w(0x4a4378,0);
    if(r(0x4a4958)<6){
      project(0x4aa28c,0x4ab9d0);draw(r(0x4ac85c)===2&&r(0x4a4958)===5?drawHarborBuilding:drawHarborHouse);
      at(0x4aa654,0x4abc84,drawLighthouse,1);at(0x4aa658,0x4abe5c,drawLighthouse,2);at(0x4aa95c,0x4ac564,drawShoreHouse,0);
      at(0x4aa994,0x4ac8e0,r(0x4a4958)===2||r(0x4a4958)===4?drawHarborBuilding:drawShoreBuilding);
      const riverLights=()=>{project(0x4a4418,0x4a63b8);if(inView())w(0x4a4378,1);draw(drawLighthouse,1);at(0x4a4420,0x4a643c,drawLighthouse,2);w(0x4a4378,0);};
      if(r(0x4a4958)===4){riverLights();at(0x4a72c4,0x4a77e4,drawShoreBuilding);}
      if(r(0x4a4958)===5){if(r(0x4ac85c)===2)riverLights();if(r(0x4ac85c)===1)at(0x4a72c4,0x4a77e4,drawShoreBuilding);}
    }
    if(r(0x4a4958)===6||r(0x4a4958)===7){
      at(0x4aa28c,0x4ab9d0,drawHarborHouse);at(0x4a72c4,0x4a77e4,drawShoreBuilding);at(0x4aa95c,0x4ac564,drawShoreHouse,0);
      if(r(0x4a4958)===7)w(0x4a4378,1);
      at(0x4aa654,0x4abc84,drawLighthouse,1);at(0x4aa658,0x4abe5c,drawLighthouse,2);w(0x4a4378,0);
    }
  }else{
    project(0x4aa28c,0x4ab9d0);
    if(inView()){
      if(r(0x4a4378)===0)drawHarborHouse(memory,dc,r(0x4a7c48),r(0x4a5a4c)===0?r(0x4aaa48):r(0x491148),options);
      if(r(0x4a4378)===1)draw(drawHarborBuilding);
    }
    if(r(0x4a4378)===1)at(0x4a72c4,0x4a77e4,drawShoreBuilding);
    if(r(0x4a5a4c)===0||r(0x491194)===8){at(0x4aa654,0x4abc84,drawLighthouse,1);at(0x4aa658,0x4abe5c,drawLighthouse,2);}
    project(0x4a61e0,0x4a677c);
    if(inView()){
      if(r(0x4a5a4c)!==0&&r(0x491194)===8){if(memory.readF64(0x4a4ae8)>r(0x4a3a08))draw(drawShoreHouse,0);}
      else drawShoreHouse(memory,dc,r(0x4a7c48),r(0x4a5a4c)!==0?r(0x491148):r(0x4aaa48),0,options);
    }
    if(r(0x4a4378)===1){at(0x4aaec8,0x4a3a30,drawShoreHouse,1);at(0x4aaec0,0x4a3c00,drawShoreHouse,3);}
    if(r(0x4a4958)===0){project(0x4aa818,0x4ac5ec);if(inView()&&(r(0x4a4378)===0||r(0x4a4378)===1))draw(drawShoreMarker,r(0x4a4378));}
    if(r(0x491194)===8&&memory.readF64(0x4a4ae8)<=r(0x4a3a08)&&r(0x4a5a4c)===1){project(0x4a61e0,0x4a677c);draw(drawShoreHouse,0);}
  }
  w(0x4aa7e0,displayedTargetMark(memory,camera));
  drawSceneObjects(memory,dc,camera,left,top,right,bottom,r(0x491148),options.rng,options);
  drawHeadingIndicator(memory,dc,camera,right,bottom,options);
  for(const selector of [0,1,-1])drawSceneLayline(memory,dc,selector,camera,left,bottom,right,options);
  dc.selectStockObject(7);dc.popClipRect();
  if(r(0x4ac8fc)===1||r(0x4a89c0+camera*4)>0)drawSceneWarning(memory,dc,left,camera);
  if(r(0x4ac9f0)<1){
    if(r(0x4ac9ac)===1){
      dc.setTextColor(0);dc.setBkColor(0xff00);
      const advice=r(0x491198);
      const messages=new Map([[-10,0x4912c0],[-9,0x4912a4],[-1,0x491280],[-7,0x49126c],[-2,0x491264],[-3,0x491258],[-4,0x491240],[-5,0x491234],[-6,0x491220],[-16,0x49120c],[-8,0x4911f4]]);
      if(messages.has(advice))dc.textOut(idiv32(r(0x4a763c),3),sub32(bottom,15),text(messages.get(advice)));
      if(advice>=0&&advice<361)dc.textOut(idiv32(r(0x4a763c),3),sub32(bottom,15),text(0x49129c)+formatInteger(r(0x4ac020))+text(0x491294));
      const beep=()=>options.messageBeep?options.messageBeep(0):options.beep?.();
      if(advice!==r(0x4a4ed8)&&advice<0&&r(0x4ac9c0)===0)beep();
      if(absolute(sub32(advice,r(0x4a4ed8)))>5&&advice<361&&advice>=0&&r(0x4ac9c0)===0)beep();
      dc.setTextColor(0);dc.setBkColor(0xffffff);
    }
    w(0x4a4ed8,r(0x491198));
    if(r(0x4a5b80)<1&&r(0x491140)===2&&camera===1){
      const y=r(0x4ac8fc)===1||r(0x4a89c4)>0?20:0;
      dc.setTextColor(r(0x4ac92c)===0?0xff:0);
      dc.textOut(left,y,text(0x4911f0)+formatInteger(absolute(r(0x4a5e84)))+text(0x4911e8)+formatInteger(absolute(r(0x4a6778)))+text(0x4911e0));
      dc.setTextColor(0);
    }
    select(memory,dc,0x4a4dec);dc.moveTo(left,top);dc.lineTo(right,top);dc.lineTo(right,bottom);dc.lineTo(left,bottom);dc.lineTo(left,top);
  }
}

export const FUN_00404880=drawScene;
export const FUN_00430f90=drawSceneWarning;
