import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { wrapDegreesOnce } from '../engine/integer-core.js';
import { readAnsiString, formatInteger, formatDecimal } from '../engine/hud-state.js';

const select=(memory,dc,address)=>{const handle=memory.readU32(address);if(handle)dc.selectObject(handle);};

/** Complete original 0x430f30: an integer-table arrow segment. */
export function drawArrowSegment(memory,dc,x,y,bearing,divisor) {
  [x,y,bearing,divisor]=[x,y,bearing,divisor].map(i32);
  dc.moveTo(x,y);dc.lineTo(add32(idiv32(memory.readI32(0x4a54a0+bearing*4),divisor),x),sub32(y,idiv32(memory.readI32(0x4a3450+bearing*4),divisor)));
}

/** Complete original 0x430eb0: shaft followed by its two arrowhead segments. */
export function drawArrow(memory,dc,x,y,bearing,divisor) {
  [x,y,bearing,divisor]=[x,y,bearing,divisor].map(i32);
  drawArrowSegment(memory,dc,x,y,wrapDegreesOnce(bearing),divisor);
  drawArrowSegment(memory,dc,x,y,wrapDegreesOnce(sub32(bearing,30)),imul32(divisor,2));
  drawArrowSegment(memory,dc,x,y,wrapDegreesOnce(add32(bearing,30)),imul32(divisor,2));
}

/** Complete original 0x430570 course labels, weather legend and north arrow. */
export function drawChartMarkLabel(memory,dc,mark,x,y) {
  [mark,x,y]=[mark,x,y].map(i32);
  const r=address=>memory.readI32(address),text=address=>readAnsiString(memory,address),mono=r(0x4ac92c),course=r(0x4ac940),fleet=r(0x49118c),courseOption=r(0x491160);
  dc.setBkMode(1);
  if(mono===0){dc.setBkColor(0xff0000);dc.setTextColor(0xffff);}
  if(mark===2)dc.textOut(sub32(x,50),add32(y,13),text(0x493550));
  if(mark===3){
    if(course===0)dc.textOut(add32(x,6),sub32(y,15),text(0x493544));
    if(course===1){const angle=r(0x4a4f8c),inRange=angle>=181&&angle<=319;dc.textOut(inRange?sub32(x,90):add32(x,6),sub32(y,inRange?22:15),text(0x493534));}
  }
  const secondBelow=r(0x4ac840)>=161&&r(0x4ac840)<=199,secondX=secondBelow?x:sub32(x,70),secondY=add32(y,secondBelow?10:-7);
  if(mark===4){
    if(imul32(courseOption,course)!==1)dc.textOut(secondX,secondY,text(0x493528));
    if(course===1&&courseOption===1&&fleet>14)dc.textOut(secondX,secondY,text(0x49351c));
  }
  if(mark===5){
    if(course===0&&(courseOption===0||(courseOption===1&&fleet>14)))dc.textOut(sub32(x,40),add32(y,8),text(0x493510));
    if(course===1)dc.textOut(sub32(x,40),add32(y,8),text(fleet<15?0x493500:0x4934f0));
  }
  dc.setBkMode(2);
  if(r(0x4ac970)===1||r(0x4ac974)===1)return;
  const width=r(0x4a763c),height=r(0x4a72d0),layout=r(0x4aa804),terrain=r(0x4a4958);
  let row=idiv32(imul32(height,2),5),column=7;
  if(layout===1)row=idiv32(imul32(height,3),5);
  if(layout===2)row=idiv32(imul32(height,2),5);
  if(layout===3)row=idiv32(height,5);
  if(layout===4){column=idiv32(imul32(width,4),5);row=idiv32(imul32(height,3),5);}
  if(mono===0){dc.setBkColor(0);dc.setTextColor(0xffff);}
  select(memory,dc,0x4a67ac);
  const suffix=text(0x4911f0),wind=formatInteger(r(0x4aa390));
  if(terrain===0||terrain===6||terrain===7)dc.textOut(column,row,text(0x4934dc)+wind+suffix);
  if(terrain>0&&terrain<4)dc.textOut(column,row,text(0x4934c8)+wind+suffix);
  if(terrain===4)dc.textOut(column,row,text(0x4934b4)+wind+suffix);
  select(memory,dc,mono===0?0x4a67ac:0x4a4ee4);
  const arrowX=add32(column,25);
  drawArrow(memory,dc,arrowX,add32(row,40),wrapDegreesOnce(r(0x4ac840)),5);
  row=add32(row,idiv32(height,8));
  const current=r(0x4aa800),abs=current<0?sub32(0,current):current;
  const tide=formatDecimal(memory,Float80.fromInteger(abs).multiply(Float80.fromNumber(memory.readF64(0x484d48))).toNumber());
  if(terrain===0||terrain===6||terrain===7)dc.textOut(column,row,text(0x4934a0)+tide+suffix);
  if(terrain===4)dc.textOut(column,row,text(0x493488)+tide+suffix);
  if(terrain===0||terrain===4||terrain===6||terrain===7)drawArrow(memory,dc,arrowX,add32(row,40),wrapDegreesOnce(add32(r(0x4aae1c),r(0x4aa298)<0?180:0)),5);
  if(mono===0)dc.setTextColor(0xffff);
  dc.textOut(sub32(width,70),idiv32(height,7),text(0x493480));
  drawArrow(memory,dc,sub32(width,55),add32(idiv32(height,7),35),180,5);
  dc.setTextColor(0);dc.setBkColor(0xffffff);
}

export const FUN_00430f30=drawArrowSegment;
export const FUN_00430eb0=drawArrow;
export const FUN_00430570=drawChartMarkLabel;
