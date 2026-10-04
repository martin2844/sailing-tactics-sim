import { Float80,getX87ControlWord } from '../../../../src/runtime/float80.js';
import { sub32 } from '../../../../src/runtime/c-types.js';
import { sinCosX87Number } from '../../../../src/runtime/transcendentals.js';
import { fpLoad,fpBox,fpStoreF64,fpAdd,fpSub,fpMul,fpDiv,fpNeg,fpCompare } from '../render/float-values.js';

const coefficients={1:0x4cc650,2:0x4cc650,3:0x4cc650,7:0x4cc770,9:0x4cc518,10:0x4cc660,
  11:0x4cc6d8,12:0x4cc6d8,103:0x4cc508,105:0x4cc5f0,104:0x4cc638,100:0x4cc770,
  101:0x4cc668,106:0x4cc570,102:0x4cc570};

export function numberVenueMetricEnabled(options){
  return getX87ControlWord()===0x027f&&options!==null
    &&(typeof options==='object'||typeof options==='function')&&!('sinCosX87' in options);
}

/** The original 47d5f0 point loop, keeping certified PC53 values unboxed.
 * All integer differences wrap before conversion. Transcendental results keep
 * their full m80 significands; each original spill still rounds to binary64.
 * The floating helpers fall back to extended arithmetic outside their domain.
 * Reads and comparisons retain source order, including mutable coefficients.
 */
export function sampleVenuePointsNumber(memory,x,y,venue,includeBackground,initial,pointCount,extras,marks,count){
  const r=address=>memory.readI32(address),f=address=>fpLoad(memory.readF64(address));
  let nearest=initial;
  for(let point=1;point<=count;point++){
    if(point>marks&&count-extras>point&&includeBackground===0)continue;
    const orientation=fpNeg(f(0x4fafa8+point*8));
    const rotation=sinCosX87Number(orientation);
    const dx=sub32(x,r(0x535218+point*4)),dy=sub32(y,r(0x4f4b58+point*4));
    let localX=fpSub(fpMul(rotation.cosine,dx),fpMul(rotation.sine,dy));
    const localY=fpStoreF64(fpAdd(fpMul(rotation.cosine,dy),fpMul(fpStoreF64(rotation.sine),dx)));
    const notch=r(0x522cb0+point*4),zero=f(0x4cc658);
    if(notch>0&&notch<36&&fpCompare(localX,zero,'>')||notch>36&&fpCompare(localX,zero,'<'))localX=fpMul(localX,f(0x4cc468));
    const scaledX=fpDiv(localX,f(0x4fb5e0+point*8));
    const square=fpAdd(fpMul(localY,localY),fpMul(scaledX,scaledX));
    const normalized=fpCompare(square,zero,'<')||fpCompare(square,f(0x4cccc8),'>')
      ?f(0x4cccc0):fpDiv(fpBox(square).sqrt(),r(0x534fe0+point*4));
    let coefficient=f(coefficients[venue]??0x4cc4f8);
    if(venue===999)coefficient=f(r(0x4da248)===2?(r(0x4da240)===1&&r(0x4da244)===1?0x4ccfc0:0x4cc630):0x4cc650);
    let value=fpMul(fpSub(fpMul(normalized,f(0x4cc920)),f(0x4cc920)),coefficient);
    if(fpCompare(value,zero,'<'))value=zero;
    if(venue===7&&point===3&&y>-2700&&y<-300&&x<2160&&x>1300)value=f(0x4cc730);
    if(pointCount<point)value=fpSub(value,f(0x4cc788));
    if(fpCompare(value,nearest,'<'))nearest=fpStoreF64(value);
  }
  return Float80.fromNumber(nearest);
}
