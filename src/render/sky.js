import { i32, add32, sub32, imul32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { signedDegreesOnce } from '../engine/hud-state.js';

const select=(memory,dc,address)=>{const handle=memory.readU32(address);if(handle)dc.selectObject(handle);};

/** Complete original 0x4060f0 sky/cloud geometry, retaining discarded angle wraps. */
export function drawSky(memory,dc,camera){
  camera=i32(camera);const r=address=>memory.readI32(address);
  const scale=Float80.fromNumber(memory.readF64(0x4ab0c8)).multiply(Float80.fromNumber(memory.readF64(0x484ce8))).truncI32();
  dc.selectStockObject(8);
  if(r(0x4ac98c)===0)for(let index=0;index<7;index++){
    let heading=r(0x4a6830+camera*4),angle;
    if(heading<180||heading>270){heading=signedDegreesOnce(heading);angle=sub32(r(0x4a8870+index*4),heading);signedDegreesOnce(angle);}else angle=sub32(r(0x4a8870+index*4),heading);
    const y=r(0x4a44f0+index*4),x=add32(imul32(angle,scale),r(0x4a3fa0)),width=r(0x4a4928+index*4);
    select(memory,dc,r(0x4a5b98)<3?0x4a3efc:0x4aa7f4);dc.ellipse(x,add32(y,1),add32(x,width),add32(y,9));
    if(r(0x4a5b98)<3)dc.selectStockObject(0);else select(memory,dc,0x4a70e4);
    dc.pie(x,y,add32(x,width),add32(y,11),add32(add32(x,width),1),add32(y,5),sub32(x,1),add32(y,5));
  }
  dc.selectStockObject(8);select(memory,dc,r(0x4ac92c)===0&&r(0x4ac98c)===0?0x4ac8ec:0x4aa7f4);
  if(r(0x4ac98c)===1)dc.selectStockObject(4);
  const horizon=r(0x491148),xs=[],ys=[];let middleAngle=camera;
  for(let index=3;index<8;index++){
    const heading=r(0x4a6830+camera*4);
    const angle=heading<180||heading>270?signedDegreesOnce(sub32(r(0x4a8850+index*4),signedDegreesOnce(heading))):sub32(r(0x4a8850+index*4),heading);
    if(index===5)middleAngle=angle;
    xs[index]=add32(imul32(angle,scale),r(0x4a3fa0));ys[index]=sub32(sub32(horizon,r(0x4a44d0+index*4)),1);
  }
  for(const [address,value] of [[0x4a4cb0,xs[4]],[0x4a4cb8,xs[5]],[0x4a4cc0,xs[6]],[0x4a4cc8,xs[7]],[0x4a4cd0,add32(xs[7],100)],
    [0x4a4ca8,xs[3]],[0x4a4cb4,ys[4]],[0x4a4cbc,ys[5]],[0x4a4cc4,ys[6]],[0x4a4ccc,ys[7]],[0x4a4cac,horizon],[0x4a4cd4,horizon]])memory.writeI32(address,value);
  const abs=middleAngle<0?sub32(0,middleAngle):middleAngle;
  if(abs<110)dc.polygon(Array.from({length:6},(_,index)=>({x:r(0x4a4ca8+index*8),y:r(0x4a4cac+index*8)})));
}

export const FUN_004060f0=drawSky;
