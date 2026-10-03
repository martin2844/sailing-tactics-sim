import { i16, i32, add32, sub32, idiv32 } from '../../../../src/runtime/c-types.js';

export const MOUSE_ROUTINES = Object.freeze({
  handleLeftButtonDown:0x493350,handleRightButtonDown:0x4934b0,
  handleMouseMove:0x4964c0,handleMouseWheel:0x497600,
});

/** Complete 0x493350; the native screen sum is retained across invalidation. */
export function handleLeftButtonDown(memory, flags, x, y, options = {}) {
  flags=i32(flags);x=i32(x);y=i32(y);
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  const invalidate=()=>options.invalidateRect?.({windowHandle:options.windowHandle ?? 0,rectangle:null,erase:0});
  w(0x4fe75c,x);w(0x5233a4,y);
  if (x>0 && x<add32(idiv32(r(0x4fe624),3),2) && y<add32(r(0x4faf7c),20) && y>r(0x4faf7c) && r(0x536444)>0) {
    const next=add32(r(0x4fb9b4),1);w(0x4fb9b4,next);
    if (next>r(0x4da18c)) w(0x4fb9b4,0);
    w(0x5233a4,0);w(0x5363b4,0);invalidate();
  }
  let screens=add32(r(0x53644c),r(0x536448));
  for (const address of [0x536444,0x536438,0x536434,0x53642c,0x5233a8,0x5363f0]) screens=add32(screens,r(address));
  if (r(0x5233a4)>add32(idiv32(r(0x4fe2a8),16),20) && screens>0) {
    for (const address of [0x536438,0x536434,0x5233a8,0x53642c,0x5363f0,0x53644c,0x536444,0x536448,0x5363b4]) w(address,0);
    invalidate();
  }
  if (r(0x5233a4)>0 && screens===0 && r(0x5363b4)===1) {
    w(0x5363b4,0);invalidate();
  }
  options.defaultMouseHandler?.({message:0x201,flags,x,y});
}

export function handleRightButtonDown(memory, flags, x, y, options = {}) {
  flags=i32(flags);x=i32(x);y=i32(y);
  memory.writeI32(0x525aa0,x);memory.writeI32(0x4f4680,y);
  options.defaultMouseHandler?.({message:0x204,flags,x,y});
}

export function handleMouseMove(memory, flags, x, y, options = {}) {
  flags=i32(flags);x=i32(x);y=i32(y);
  memory.writeI32(0x5364a0,x);memory.writeI32(0x5364a4,y);
  options.defaultMouseHandler?.({message:0x200,flags,x,y});
}

/** The signed-short wheel delta changes boat one's sheet once per nonzero sign. */
export function handleMouseWheel(memory, flags, delta, x, y, options = {}) {
  flags=i32(flags);delta=i16(delta);x=i32(x);y=i32(y);
  const detents=idiv32(delta,120);
  if (detents>0) {
    const value=add32(memory.readI32(0x500384),5);
    memory.writeI32(0x500384,value>90 ? 90 : value);
  }
  if (detents<0) {
    const value=sub32(memory.readI32(0x500384),5);
    memory.writeI32(0x500384,value<0 ? 0 : value);
  }
  return options.defaultMouseHandler?.({message:0x20a,flags,delta,x,y});
}
