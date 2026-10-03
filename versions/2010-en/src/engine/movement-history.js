import { add32,sub32,imul32,i32,idiv32 } from '../../../../src/runtime/index.js';
import { Float80 } from '../../../../src/runtime/float80.js';

const at=(base,index,stride=4)=>add32(base,imul32(index,stride))>>>0;

/** Complete 0x431960. All interpolation products use signed 32-bit arithmetic. */
export function resetBoat(memory,boat){
  boat=i32(boat);
  const count=memory.readI32(0x4da194),humans=memory.readI32(0x4da140);
  const mode=memory.readI32(0x4da1d8),span=add32(count,1);
  const ax=memory.readI32(0x536410),ay=memory.readI32(0x536414);
  const bx=memory.readI32(0x4fe094),by=memory.readI32(0x4fe2a0);
  memory.writeI32(at(0x4f8538,boat),0);
  const interpolate=(from,to)=>idiv32(add32(imul32(from,sub32(span,boat)),imul32(boat,to)),span);
  const store=(x,y)=>{memory.writeI32(at(0x4f4d78,boat),x);memory.writeI32(at(0x4fc350,boat),y);};
  if(mode===2)store(interpolate(ax,bx),interpolate(ay,by));
  if(mode===1)store(interpolate(bx,ax),interpolate(by,ay));
  if(boat>humans&&mode>2)store(interpolate(ax,bx),interpolate(ay,by));
  if(mode>2&&(boat<=humans||count===2||memory.readI32(0x4f8cd0)>-30)){
    store(idiv32(add32(ax,bx),2),idiv32(add32(by,ay),2));
  }
}

/** Complete 0x444760, including all boats, 501-slot stride and state flags. */
export function recordTrails(memory){
  for(let boat=1;boat<=memory.readI32(0x4da194);boat++){
    const offset=imul32(boat,0x7d4);
    const x=at(0x5135a4,boat,0x7d4),y=at(0x525abc,boat,0x7d4),flags=at(0x500424,boat,0x7d4);
    memory.writeI32(x,Float80.fromNumber(memory.readF64(at(0x4f6af8,boat,8))).truncI32());
    memory.writeI32(y,Float80.fromNumber(memory.readF64(at(0x4f6c10,boat,8))).truncI32());
    let flag=memory.readI32(at(0x4fecc8,boat))<90?1:0;
    if(memory.readI32(at(0x4fe8a8,boat))>0)flag=flag===1?3:2;
    if(memory.readI32(at(0x4fe2b0,boat))>0)flag=add32(flag,10);
    memory.writeI32(flags,flag);
    for(let index=sub32(memory.readI32(0x534ea8),1);index>0;index--){
      const delta=imul32(index,4);
      // The native history first writes slot0, then copies it into slot1.
      for(const base of [x,y,flags])memory.writeU32(add32(base,delta)>>>0,memory.readU32(add32(base,sub32(delta,4))>>>0));
    }
  }
}

/** Complete 0x465e10: raw double-word copies retain every IEEE bit pattern. */
export function recordWaypointHistory(memory,boat){
  let offset=imul32(i32(boat),8);
  memory.writeBytes(add32(0x50f818,offset)>>>0,memory.readBytes(add32(0x4f1610,offset)>>>0,8));
  memory.writeBytes(add32(0x523e80,offset)>>>0,memory.readBytes(add32(0x4f3868,offset)>>>0,8));
  for(let count=19;count>0;count--){
    memory.writeBytes(add32(0x510ea8,offset)>>>0,memory.readBytes(add32(0x510d78,offset)>>>0,8));
    memory.writeBytes(add32(0x525510,offset)>>>0,memory.readBytes(add32(0x5253e0,offset)>>>0,8));
    offset=sub32(offset,0x130);
  }
}
