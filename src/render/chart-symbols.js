import { add32, sub32, imul32, idiv32, i32 } from '../runtime/c-types.js';
import { wrapDegreesOnce } from '../engine/integer-core.js';

function select(memory, dc, address) {
  const handle = memory.readU32(address);
  if (handle) dc.selectObject(handle);
}

/** Complete original 0x4166e0 pen selection and successive overrides. */
export function selectHeadingColor(memory, dc, boat) {
  boat = i32(boat);
  if (memory.readI32(0x4ac92c) !== 0) {
    if (boat === 1) select(memory, dc, 0x4a4ee4);
    if (boat >= 2) select(memory, dc, 0x4a4dec);
    return;
  }
  if (boat === 1) select(memory, dc, 0x4a676c);
  if (boat === 2) select(memory, dc, 0x4a39fc);
  for (const [boats, address] of [
    [[3,12,21],0x4a67ac], [[0,4,13,22],0x4aa634], [[5,14,23],0x4a3f9c],
    [[6,15,24],0x4abbf4], [[7,16,25],0x4a4dec], [[8,17,26],0x4aa7ec],
    [[9,18,27],0x4a3a2c], [[10,19,28],0x4aa7d4],
  ]) if (boats.includes(boat)) select(memory, dc, address);
  if (boat === 11 || boat === 20 || boat > 28) select(memory, dc, 0x4ac30c);
  if (memory.readI32(0x4ac98c) === 1) {
    select(memory, dc, boat === 1 ? 0x4aa7ec : 0x4aa634);
    if (boat === 2 && memory.readI32(0x491140) === 2) select(memory, dc, 0x4a3a2c);
  }
}

/** Complete original 0x423670 small heading vector and player markers. */
export function drawHeadingIndicator(memory, dc, x, y, boat, camera, mode) {
  [x,y,boat,camera,mode] = [x,y,boat,camera,mode].map(i32);
  selectHeadingColor(memory, dc, boat);
  if (memory.readI32(0x4ac98c) === 1 && boat !== camera && memory.readI32(0x4a8660+camera*4) >= 9) return;
  const heading = base => memory.readI32(base+camera*4);
  let angle = wrapDegreesOnce(add32(sub32(memory.readI32(0x4ac018+boat*4),heading(0x4ac018)),180));
  if (heading(0x4ab160) === 0) angle=wrapDegreesOnce(add32(sub32(angle,heading(0x4a6830)),heading(0x4ac018)));
  if (heading(0x4ab160) === 2) angle=wrapDegreesOnce(add32(sub32(angle,heading(0x4aa5b0)),heading(0x4ac018)));
  if (mode > 2) angle=add32(memory.readI32(0x4ac018+boat*4),180);
  angle=wrapDegreesOnce(angle);
  dc.moveTo(x,y);
  dc.lineTo(add32(x,idiv32(memory.readI32(0x4a54a0+angle*4),10)),sub32(y,idiv32(memory.readI32(0x4a3450+angle*4),10)));
  if (boat===1) {
    dc.moveTo(sub32(x,4),y);dc.lineTo(add32(x,4),y);
    dc.moveTo(x,sub32(y,4));dc.lineTo(x,add32(y,4));
  }
  if (boat===2 && memory.readI32(0x491140)===2) {
    dc.moveTo(sub32(x,3),sub32(y,3));dc.lineTo(add32(x,3),sub32(y,3));
    dc.lineTo(add32(x,3),add32(y,3));dc.lineTo(sub32(x,3),add32(y,3));dc.lineTo(sub32(x,3),sub32(y,3));
  }
}

/** Complete original 0x423640. */
export function drawCircle(_memory,dc,radius,x,y) {
  [radius,x,y]=[radius,x,y].map(i32);
  dc.ellipse(sub32(x,radius),sub32(y,radius),add32(x,radius),add32(y,radius));
}

/** Complete original 0x424890, with the detailed buoy drawing supplied below. */
export function drawCourseMark(memory,dc,x,y,mark,mode,camera,options={}) {
  [x,y,mark,mode,camera]=[x,y,mark,mode,camera].map(i32);
  dc.selectStockObject(7);
  select(memory,dc,[3,5].includes(mark)?0x4a3a14:0x4a6234);
  if(mark===2)select(memory,dc,0x4a3a14);
  if(memory.readI32(0x4ac92c)===1 || mark===2)dc.selectStockObject(0);
  let radius=Math.max(3,idiv32(8,memory.readI32(0x4a8660+camera*4)));
  if(mode===3)radius=4;
  if(mark===2)radius=add32(radius,1);
  drawCircle(memory,dc,radius,x,y);
  if(mark===2&&mode===1&&memory.readI32(0x4a8660+camera*4)<8) {
    if(typeof options.drawChartBoat!=='function')throw new Error('Detailed chart buoy renderer has not been installed');
    options.drawChartBoat(memory,dc,x,y,0,1,options);
  }
}

export const FUN_004166e0=selectHeadingColor;
export const FUN_00423670=drawHeadingIndicator;
export const FUN_00423640=drawCircle;
export const FUN_00424890=drawCourseMark;
