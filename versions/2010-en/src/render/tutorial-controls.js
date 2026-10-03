import {i32,add32,idiv32} from '../../../../src/runtime/c-types.js';
import {readAnsiString} from './text.js';
import {registerOriginalDrawing} from './dependencies.js';

export const TUTORIAL_CONTROL_ROUTINES=Object.freeze({selectBoatTextColor:0x41f3e0,drawTutorialAdvanceButton:0x463c90,drawTutorialAdvanceHint:0x463df0});

/** All original independent color branches, including zero/out-of-range boats. */
export function selectBoatTextColor(memory,dc,boat){
  boat=i32(boat);
  if(memory.readI32(0x5363e4)!==0){dc.setTextColor(0);return;}
  if(boat===1)dc.setTextColor(0xff);
  if(boat===2)dc.setTextColor(0xff00);
  if([3,12,21].includes(boat))dc.setTextColor(0x7f7f);
  if([4,13,22,0].includes(boat))dc.setTextColor(0x7f7f7f);
  if([5,14,23].includes(boat))dc.setTextColor(0x7f7f);
  if([6,15,24].includes(boat))dc.setTextColor(0xff00ff);
  if([7,16,25].includes(boat))dc.setTextColor(0x7fff);
  if([8,17,26].includes(boat))dc.setTextColor(0x7f);
  if([9,18,27].includes(boat))dc.setTextColor(0x7f00);
  if([10,19,28].includes(boat))dc.setTextColor(0x7f007f);
  if(boat===11 || boat===20 || boat>28)dc.setTextColor(0xffff00);
}

export function drawTutorialAdvanceButton(memory,dc,lineHeight){
  lineHeight=i32(lineHeight);
  const brush=memory.readU32(0x4fe07c),top=memory.readI32(0x4faf7c);
  if(brush!==0)dc.selectObject(brush);
  dc.selectStockObject(7);
  dc.rectangle(0,top,add32(idiv32(memory.readI32(0x4fe624),3),4),add32(add32(top,3),lineHeight));
  dc.setBkColor(0x7f7f7f);dc.setTextColor(0);
  const restore=memory.readI32(0x4fb9b4)===memory.readI32(0x4da18c);
  if(memory.readI32(0x5363e4)===0)dc.setTextColor(restore?0xffff00:0xffff);
  dc.textOut(2,add32(top,2),readAnsiString(memory,restore?0x4ec1a0:0x4ec17c));
  dc.setBkColor(0xffffff);dc.setTextColor(0);
}

/** Preserve both successive original hint draws, including their actual padding. */
export function drawTutorialAdvanceHint(memory,dc,_unused,lineHeight){
  lineHeight=i32(lineHeight);
  const y=add32(memory.readI32(0x4faf7c),-lineHeight);
  const colors=memory.readI32(0x5363e4)===0;
  if(memory.readI32(0x4fb9b4)<memory.readI32(0x4da18c)){
    if(colors)dc.setTextColor(0);
    dc.textOut(3,y,readAnsiString(memory,0x4ec250));
    if(colors)dc.setTextColor(0xff);
    dc.textOut(3,y,readAnsiString(memory,0x61b064));
  }else{
    if(colors)dc.setTextColor(0xff);
    dc.textOut(3,y,readAnsiString(memory,0x4ec1c4));
  }
}

registerOriginalDrawing(0x41f3e0,(memory,dc,_rng,_options,...args)=>selectBoatTextColor(memory,dc,...args));
registerOriginalDrawing(0x463c90,(memory,dc,_rng,_options,...args)=>drawTutorialAdvanceButton(memory,dc,...args));
registerOriginalDrawing(0x463df0,(memory,dc,_rng,_options,...args)=>drawTutorialAdvanceHint(memory,dc,...args));
