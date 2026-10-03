import { add32, sub32, imul32, idiv32, i32, u32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { advanceFrame, finishFrame, minimumFrameDuration } from '../engine/frame.js';

export const PAINT_ROUTINES=Object.freeze({paintLifecycle:0x404510,drawSimulationFrame:0x4049f0});
export const PAINT_CALLBACK_ROUTINES=Object.freeze({
  initializeBoatOptions:0x420c00,initializeRace:0x41be70,drawStartScreen:0x413bc0,
  drawResultsScreen:0x428b70,drawForecastScreen:0x4298f0,drawPauseScreen:0x427f10,
  drawScene:0x405320,drawChart:0x407ff0,drawAdvice:0x406590,
  drawSailingHud:0x40f240,drawCompactHud:0x412d30,
});
function required(options,name) {
  const callback=options[name] ?? options.render?.[name] ?? options.engine?.[name];
  if (typeof callback!=='function') throw new TypeError(`Original 2010 paint branch requires ${name} (0x${PAINT_CALLBACK_ROUTINES[name]?.toString(16) ?? 'unknown'})`);
  return callback;
}

function calibratePaintScale(memory) {
  const width=memory.readI32(0x4fe624),height=memory.readI32(0x4f3ff0);
  const clientHeight=width<801 ? sub32(height,30) : sub32(height,idiv32(height,17));
  memory.writeI32(0x4fe2a8,clientHeight);
  memory.writeF64(0x50f6e0,Float80.fromInteger(height).multiply(Float80.fromNumber(memory.readF64(0x4cc3d8))).toNumber());
  memory.writeF64(0x5259d0,Float80.fromInteger(memory.readI32(0x4f4084)).multiply(Float80.fromNumber(memory.readF64(0x4cc3e0))).toNumber());
  return {width,height:clientHeight,bitsPixel:memory.readI32(0x52362c)};
}

/** Display-cap stores, the original 1280×768 limits and retained F64 scales. */
export function configurePaintDimensions(memory,{width,height,bitsPixel,applicationInstance}) {
  width=i32(width);height=i32(height);bitsPixel=i32(bitsPixel);
  memory.writeI32(0x52362c,bitsPixel);memory.writeU32(0x5359c8,u32(applicationInstance));
  memory.writeI32(0x4f4084,width);
  if (width>1280) {width=1280;memory.writeI32(0x4f4084,width);}
  memory.writeI32(0x4fe624,width);memory.writeI32(0x4f3ff0,height);
  if (height>768) memory.writeI32(0x4f3ff0,768);
  return calibratePaintScale(memory);
}

/** Complete drawing suffix of 0x4049f0; callbacks may mutate the original image. */
export function composeRaceFrame(memory,dc,rng,options={}) {
  options={...options,rng};
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  const width=()=>r(0x4fe624),height=()=>r(0x4fe2a8);
  const scene=(...args)=>required(options,'drawScene')(memory,dc,...args,options);
  const chart=(...args)=>required(options,'drawChart')(memory,dc,...args,options);
  const advice=(...args)=>required(options,'drawAdvice')(memory,dc,...args,options);
  const sailing=(...args)=>required(options,'drawSailingHud')(memory,dc,...args,options);
  const compact=(...args)=>required(options,'drawCompactHud')(memory,dc,...args,options);
  const pause=()=>required(options,'drawPauseScreen')(memory,dc,rng,options);
  const showPause=()=>r(0x536444)===2 || r(0x536444)===300;
  if (r(0x4da140)===1 && r(0x4f71c4)<3) {
    scene(0,0,width(),idiv32(height(),2),1);w(0x535564,idiv32(height(),2));
    if (showPause()) pause();
    if (r(0x4da1a8)===0) {
      if (r(0x536478)===0) chart(0,idiv32(height(),2),idiv32(width(),3),height(),1,2);
      else advice(0,idiv32(height(),2),idiv32(width(),3),height(),1,2);
    }
    const left=r(0x4da1a8)===1 ? 0 : idiv32(width(),3);
    const right=r(0x4da1a8)===1 ? idiv32(width(),2) : idiv32(imul32(width(),2),3);
    chart(right,idiv32(height(),2),width(),height(),1,1);
    sailing(left,idiv32(height(),2),right,height(),1);
    w(0x5230e0,left);w(0x525a68,right);
  }
  if (r(0x4da140)===1 && r(0x4f71c4)===3) {
    scene(idiv32(width(),3),0,width(),height(),1);w(0x535564,height());
    if (showPause()) pause();
    chart(0,0,idiv32(width(),3),idiv32(height(),2),1,1);
    if (showPause()) pause();
    sailing(0,idiv32(height(),2),idiv32(width(),3),height(),1);
    w(0x525a68,idiv32(width(),3));w(0x5230e0,0);
  }
  if (r(0x4da140)===2) {
    scene(0,0,idiv32(width(),2),idiv32(height(),2),2);
    if (showPause()) pause();
    scene(idiv32(width(),2),0,width(),idiv32(height(),2),1);w(0x535564,idiv32(height(),2));
    if (showPause()) pause();
    const inset=idiv32(width(),30);
    chart(0,idiv32(height(),2),sub32(idiv32(width(),3),inset),height(),2,1);
    compact(sub32(idiv32(width(),3),inset),idiv32(height(),2),idiv32(width(),2),height(),2);
    chart(idiv32(width(),2),idiv32(height(),2),sub32(idiv32(imul32(width(),5),6),idiv32(inset,2)),height(),1,1);
    compact(sub32(idiv32(imul32(width(),5),6),idiv32(inset,2)),idiv32(height(),2),width(),height(),1);
  }
}

/** Complete original frame, with explicit tick or browser scheduling bindings. */
export function drawSimulationFrame(memory,dc,rng,options={}) {
  options={...options,rng};
  const started=(options.advanceFrame ?? advanceFrame)(memory,rng,options);
  composeRaceFrame(memory,dc,rng,options);
  const duration=minimumFrameDuration(memory);
  if (duration>0 && typeof options.getTickCount==='function') {
    let reads=0;
    while (u32(u32(options.getTickCount())-u32(started))<duration) {
      if (++reads>1_000_000) throw new RangeError('Original frame tick host did not advance');
    }
  } else options.enforceMinimumPaintDuration?.(duration,started);
  finishFrame(memory);
  return duration;
}

/** Screen dispatch from 0x404510, with original sequential state reloads. */
export function drawPaintContent(memory,dc,rng,options={}) {
  options={...options,rng};
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  const chart=mode=>required(options,'drawChart')(memory,dc,0,0,r(0x4fe624),r(0x4fe2a8),0,mode,options);
  const pause=()=>required(options,'drawPauseScreen')(memory,dc,rng,options);
  const next=add32(r(0x5364e8),1);w(0x5364e8,next);if (next>60) w(0x5364e8,1);
  if (r(0x5363b0)===0) {
    required(options,'initializeBoatOptions')(memory,options);
    required(options,'initializeRace')(memory,rng,options);
    required(options,'drawStartScreen')(memory,dc,rng,options);
  }
  if (r(0x5363b0)===1) {
    if (r(0x5363fc)>0 && r(0x536424)===0) w(0x536444,400);
    required(options,'initializeBoatOptions')(memory,options);
    required(options,'initializeRace')(memory,rng,options);w(0x5363b0,2);
  }
  if (r(0x5363f4)>0) {
    if (r(0x5233a8)===0) {required(options,'drawResultsScreen')(memory,dc,rng,options);w(0x5363b4,0);}
    else chart(3);
    if (r(0x536444)===300) pause();
  }
  if (r(0x5363f4)!==0) return;
  if (r(0x5363f0)===1 && r(0x5363b0)===2 && r(0x5233a8)===0) required(options,'drawForecastScreen')(memory,dc,rng,options);
  if ([0,2,300].includes(r(0x536444)) && r(0x5363b0)>1 && r(0x5363f0)===0 && r(0x5233a8)===0 && r(0x536434)===0 && r(0x536438)===0) {
    (options.drawSimulationFrame ?? drawSimulationFrame)(memory,dc,rng,options);
  }
  if (r(0x5363b0)>0 && r(0x5363f0)===0 && r(0x5233a8)===1) chart(3);
  if (r(0x5363b0)>0 && r(0x5363f0)===0 && r(0x536434)===1 && r(0x536444)===0) chart(4);
  if (r(0x5363b0)>0 && r(0x5363f0)===0 && r(0x536438)===1 && r(0x536444)===0) chart(5);
  if (r(0x536444)!==0 && r(0x536444)>=0) pause();
}

/** Original allocation, dispatch, blit, invalidation and destructor order. */
export function paintLifecycle(memory,frontDc,rng,options={}) {
  options={...options,rng};
  const host=options.host;
  if (!host) throw new TypeError('Original 2010 paint lifecycle requires a surface host');
  const buffer=host.constructBufferedDC();
  memory.writeI32(0x52362c,i32(host.getDeviceCaps(frontDc,12)));
  memory.writeU32(0x5359c8,u32(host.applicationInstance()));
  let width=i32(host.getDeviceCaps(frontDc,8));memory.writeI32(0x4f4084,width);
  if (width>1280) {width=1280;memory.writeI32(0x4f4084,width);}
  memory.writeI32(0x4fe624,width);
  const height=i32(host.getDeviceCaps(frontDc,10));memory.writeI32(0x4f3ff0,height);
  if (height>768) memory.writeI32(0x4f3ff0,768);
  const dimensions=calibratePaintScale(memory);
  const bitmap=host.createBitmap({...dimensions,planes:1,pixels:null});host.attachBitmap(bitmap);
  host.attachCompatibleDC(buffer,host.createCompatibleDC(frontDc));
  const previous=host.selectBitmap(buffer,bitmap);
  drawPaintContent(memory,buffer,rng,options);
  host.bitBlt(frontDc,buffer,{x:0,y:0,width:memory.readI32(0x4fe624),height:dimensions.height,sourceX:0,sourceY:0,rasterOperation:0xcc0020});
  host.selectBitmap(buffer,previous===0 ? null : previous);host.deleteBitmap(bitmap);
  const rectangle={bottom:memory.readI32(0x4fe2a8),top:0,left:0,right:memory.readI32(0x4fe624)};
  if (memory.readI32(0x5363b4)===0 && memory.readI32(0x5363b0)>0 && memory.readI32(0x5363f0)===0 && memory.readI32(0x536440)===0) {
    host.invalidateRect({windowHandle:options.windowHandle ?? 0,rectangle,erase:0});
  }
  if (memory.readI32(0x5364fc)===1) host.invalidateRect({windowHandle:options.windowHandle ?? 0,rectangle:null,erase:0});
  host.destroyBitmapObjects?.();
  host.destroyBufferedDC(buffer);
}
