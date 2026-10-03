import { i32, add32 } from '../runtime/c-types.js';

/** Original MFC 0x452790 left-button handler, including sequential invalidation. */
export function handleLeftButtonDown(memory,flags,x,y,options={}){
  flags=i32(flags);x=i32(x);y=i32(y);
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  const invalidate=()=>options.invalidateRect?.({windowHandle:options.windowHandle??0,rectangle:null,erase:0});
  w(0x4a774c,x);w(0x4aa97c,y);
  if(x>0&&x<add32(Math.trunc(r(0x4a763c)/3),2)&&y<add32(r(0x4a600c),20)&&r(0x4a600c)<y&&r(0x4ac980)>0){
    w(0x4a6774,add32(r(0x4a6774),1));if(r(0x4a6774)>r(0x491184))w(0x4a6774,0);
    w(0x4aa97c,0);w(0x4ac8fc,0);invalidate();
  }
  const screens=[0x4ac988,0x4ac984,0x4ac980,0x4ac974,0x4ac970,0x4ac968,0x4aa980,0x4ac938];
  if(r(0x4aa97c)>0&&screens.reduce((sum,address)=>add32(sum,r(address)),0)>0){
    for(const address of [0x4ac974,0x4ac970,0x4aa980,0x4ac968,0x4ac938,0x4ac988,0x4ac980,0x4ac984,0x4ac8fc])w(address,0);
    invalidate();
  }
  if(r(0x4ac8fc)===1){w(0x4ac8fc,0);invalidate();}
  options.defaultMouseHandler?.({message:513,flags,x,y});
}

/** Original right-button and mouse-move handlers retain their separate slots. */
export function handleRightButtonDown(memory,flags,x,y,options={}){
  flags=i32(flags);x=i32(x);y=i32(y);memory.writeI32(0x4ab188,x);memory.writeI32(0x4a4414,y);
  options.defaultMouseHandler?.({message:516,flags,x,y});
}
export function handleMouseMove(memory,flags,x,y,options={}){
  flags=i32(flags);x=i32(x);y=i32(y);memory.writeI32(0x4ac9e0,x);memory.writeI32(0x4ac9e4,y);
  options.defaultMouseHandler?.({message:512,flags,x,y});
}
export const MOUSE_ROUTINES=Object.freeze({handleLeftButtonDown:0x452790,handleRightButtonDown:0x4528d0,handleMouseMove:0x455730});
