import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { wrapDegreesOnce, scaledRandom } from '../engine/integer-core.js';
import { selectBoatColor, selectSailColor } from './boat-primitives.js';
import { selectHeadingColor } from './chart-symbols.js';

const f = value => Float80.fromNumber(value);
function select(memory, dc, address) { const handle=memory.readU32(address);if(handle)dc.selectObject(handle); }
function polygon(memory,dc,coordinates) {
  const points=coordinates.map(([x,y],index)=>{
    x=f(x).truncI32();y=f(y).truncI32();
    memory.writeI32(0x4a4ca8+index*8,x);memory.writeI32(0x4a4cac+index*8,y);return{x,y};
  });
  dc.polygon(points);
}
function relativeHeading(memory,boat,camera,offset=0) {
  const r=base=>memory.readI32(base+camera*4);
  let angle=wrapDegreesOnce(add32(sub32(memory.readI32(0x4ac018+boat*4),r(0x4ac018)),offset));
  if(r(0x4ab160)===0)angle=wrapDegreesOnce(add32(sub32(angle,r(0x4a6830)),r(0x4ac018)));
  if(r(0x4ab160)===2)angle=wrapDegreesOnce(add32(sub32(angle,r(0x4aa5b0)),r(0x4ac018)));
  return wrapDegreesOnce(angle);
}

/** Complete original 0x423830 twin-hull chart connectors. */
export function drawChartCatamaran(memory,dc,x,y,boat,camera) {
  [x,y,boat,camera]=[x,y,boat,camera].map(i32);
  const c=address=>f(memory.readF64(address));
  const zoom=memory.readI32(0x4a8660+camera*4);
  selectHeadingColor(memory,dc,boat);
  let scale=c(0x484cf0).subtract(c(0x485100).divide(Float80.fromInteger(zoom))).multiply(c(0x4a8670)).multiply(c(0x484db0)).toNumber();
  if(zoom>4)scale=7.75;
  const angle=relativeHeading(memory,boat,camera);
  const points=[-25,-155,25,155,-25].map(offset=>{
    const direction=wrapDegreesOnce(add32(offset,angle));
    return [sub32(x,Float80.fromInteger(memory.readI32(0x4a54a0+direction*4)).multiply(f(scale)).multiply(c(0x484e28)).truncI32()),
      sub32(y,Float80.fromInteger(memory.readI32(0x4a3450+direction*4)).multiply(f(scale)).multiply(c(0x484cc8)).truncI32())];
  });
  dc.moveTo(...points[0]);dc.lineTo(...points[1]);dc.moveTo(...points[2]);dc.lineTo(...points[3]);
  const weighted=(left,right,weight,divisor)=>left.map((value,index)=>idiv32(add32(value,imul32(right[index],weight)),divisor));
  dc.moveTo(...weighted(points[0],points[1],1,2));dc.lineTo(...weighted(points[2],points[3],1,2));
  dc.moveTo(...weighted(points[0],points[1],7,8));dc.lineTo(...weighted(points[2],points[3],7,8));
}

/** Complete original 0x423aa0 detailed chart boat, sails, warning colors and buoy. */
export function drawChartBoat(memory,dc,x,y,boat,camera,options={}) {
  [x,y,boat,camera]=[x,y,boat,camera].map(i32);
  const c=address=>f(memory.readF64(address));
  const r=address=>memory.readI32(address);
  const b=address=>r(address+boat*4);
  const lookup=(base,angle)=>Float80.fromInteger(r(base+angle*4));
  const buoy=boat===0,catamaran=r(0x4ac900)===1;
  if(catamaran&&boat>0)drawChartCatamaran(memory,dc,x,y,boat,camera);
  let scale=c(0x484cf0).subtract(c(0x485100).divide(Float80.fromInteger(r(0x4a8660+camera*4)))).multiply(c(0x4a8670)).multiply(c(0x484e30)).toNumber();
  if(buoy){scale=f(scale).multiply(c(0x484dc0)).toNumber();memory.writeI32(0x4a7060,0);memory.writeI32(0x4ac018,r(0x4aa5b4));}
  let angle=relativeHeading(memory,boat,camera);
  if(buoy) {
    angle=wrapDegreesOnce(sub32(r(0x4aa5b0+camera*4),r(0x4ac018+camera*4)));
    const mode=r(0x4ab160+camera*4);
    if(mode===0)angle=wrapDegreesOnce(add32(sub32(angle,r(0x4a6830+camera*4)),r(0x4ac018+camera*4)));
    if(mode===2)angle=wrapDegreesOnce(add32(sub32(angle,r(0x4aa5b0+camera*4)),r(0x4ac018+camera*4)));
    angle=wrapDegreesOnce(angle);
  }
  const sine=lookup(0x4a54a0,angle),cosine=lookup(0x4a3450,angle);
  const tipX=f(x).subtract(f(scale).multiply(sine).multiply(c(catamaran&&boat>0?0x485128:0x485118))).toNumber();
  const tipY=f(y).subtract(f(scale).multiply(cosine).multiply(c(catamaran&&boat>0?0x485130:0x485120))).toNumber();
  const axisX=[1,2,3].map(index=>f(tipX).subtract(sine.multiply(Float80.fromInteger(index)).multiply(f(scale)).multiply(c(0x485138))).toNumber());
  const axisY=[1,2,3].map(index=>f(tipY).subtract(cosine.multiply(Float80.fromInteger(index)).multiply(f(scale)).multiply(c(0x485140))).toNumber());
  let widthX=f(scale).multiply(c(0x485110)).multiply(cosine).toNumber();
  let widthY=f(scale).multiply(c(0x485110)).multiply(sine).toNumber();
  const leftX=[0x484fb8,0x484cc8,0x485148].map((address,index)=>f(axisX[index]).subtract(f(widthX).multiply(c(address))).toNumber());
  const leftY=[0x484fb8,0x484cc8,0x485148].map((address,index)=>f(axisY[index]).subtract(f(widthY).multiply(c(address))).toNumber());
  const rightX=axisX.map((value,index)=>f(value).add(f(value)).subtract(f(leftX[index])).toNumber());
  const rightY=axisY.map((value,index)=>f(value).add(f(value)).subtract(f(leftY[index])).toNumber());
  const wakeDivisor=add32(scaledRandom(50,options.rng),80);
  widthX=f(widthX).divide(Float80.fromInteger(wakeDivisor)).toNumber();widthY=f(widthY).divide(Float80.fromInteger(wakeDivisor)).toNumber();
  const wakeLeft=[f(axisX[0]).subtract(f(widthX)).toNumber(),f(axisY[0]).subtract(f(widthY)).toNumber()];
  const wakeRight=[f(axisX[0]).add(f(widthX)).toNumber(),f(axisY[0]).add(f(widthY)).toNumber()];
  if(!catamaran&&b(0x4a7060)>35&&!buoy) {
    dc.selectStockObject(6);if(r(0x4a8660+camera*4)<10)select(memory,dc,0x4a4ee4);
    dc.moveTo(...wakeLeft.map(value=>f(value).truncI32()));dc.lineTo(f(tipX).truncI32(),f(tipY).truncI32());dc.lineTo(...wakeRight.map(value=>f(value).truncI32()));
  }
  dc.selectStockObject(7);selectBoatColor(memory,dc,boat);
  if(!catamaran||buoy)polygon(memory,dc,[[tipX,tipY],[leftX[0],leftY[0]],[leftX[1],leftY[1]],[leftX[2],leftY[2]],[rightX[2],rightY[2]],[rightX[1],rightY[1]],[rightX[0],rightY[0]]]);
  dc.selectStockObject(7);
  if(buoy)return;
  const mastX=cosine.multiply(f(scale)).multiply(c(0x484fe8)).multiply(c(0x484cc8)).toNumber();
  const mastY=sine.multiply(f(scale)).multiply(c(0x484fe8)).multiply(c(0x484cc8)).toNumber();
  const leanAngle=wrapDegreesOnce(add32(add32(scaledRandom(3,options.rng),6),idiv32(b(0x4a6ec8),2)));
  const lean=lookup(0x4a54a0,leanAngle).multiply(c(0x484f60)).multiply(Float80.fromInteger(b(0x4aa730))).toNumber();
  const mastHeight=f(scale).multiply(c(0x484da0)).toNumber();
  const leanX=f(mastX).multiply(f(lean)).toNumber(),leanY=f(mastY).multiply(f(lean)).toNumber();
  const low=[f(axisX[0]).subtract(f(leanX).multiply(c(0x484cc8))).toNumber(),f(axisY[0]).subtract(f(leanY).multiply(c(0x484cc8))).toNumber()];
  const high=[f(axisX[0]).subtract(f(leanX).multiply(c(0x484d48))).toNumber(),f(axisY[0]).subtract(f(leanY).multiply(c(0x484d48))).toNumber()];
  let sheet=idiv32(imul32(b(0x4a77e8),2),3);
  const mainAngle=wrapDegreesOnce(add32(imul32(add32(sheet,10),b(0x4aa730)),angle));
  const mainX=lookup(0x4a54a0,mainAngle).multiply(f(mastHeight)).toNumber();
  const mainY=lookup(0x4a3450,mainAngle);
  const clew=[f(low[0]).subtract(f(mainX).multiply(c(0x484cc8))).toNumber(),f(low[1]).subtract(mainY.multiply(f(mastHeight)).multiply(c(0x484e28))).toNumber()];
  const curve=[f(low[0]).add(f(high[0])).multiply(c(0x484da8)).subtract(f(mainX).multiply(c(0x485150))).toNumber(),
    f(low[1]).add(f(high[1])).multiply(c(0x484da8)).subtract(mainY.multiply(f(mastHeight)).multiply(c(0x485158))).toNumber()];
  const jibLength=f(scale).multiply(c(0x484f10)).toNumber();
  if(sheet>60)sheet=60;if(b(0x4aa730)===-1)sheet=sub32(0,sheet);
  const jibAngle=wrapDegreesOnce(add32(sheet,angle));
  const jib=[f(tipX).subtract(lookup(0x4a54a0,jibAngle).multiply(f(jibLength)).multiply(c(0x484cc8))).toNumber(),
    f(tipY).subtract(lookup(0x4a3450,jibAngle).multiply(f(jibLength)).multiply(c(0x484e28))).toNumber()];
  const lower=r(0x491150)===100?high:[f(axisX[0]).subtract(f(high[0]).multiply(c(0x484e98))).multiply(c(0x484db0)).toNumber(),
    f(axisY[0]).subtract(f(high[1]).multiply(c(0x484e98))).multiply(c(0x484db0)).toNumber()];
  const spinnaker=b(0x4abb70),boatClass=r(0x491188);
  let kite;
  if(spinnaker>0) {
    let kiteAngle=sub32(b(0x4a77e8),160);if(b(0x4aa730)===-1)kiteAngle=sub32(0,kiteAngle);
    angle=wrapDegreesOnce(add32(kiteAngle,angle));
    kite=[f(tipX).subtract(lookup(0x4a54a0,angle).multiply(f(jibLength)).multiply(c(0x484cc8))).toNumber(),
      f(tipY).subtract(lookup(0x4a3450,angle).multiply(f(jibLength)).multiply(c(0x484e28))).toNumber()];
  }
  if(spinnaker<1&&boatClass>1){dc.selectStockObject(0);if(r(0x4ac92c)===0&&boatClass===7)select(memory,dc,0x4ab17c);polygon(memory,dc,[[tipX,tipY],jib,lower]);}
  if(spinnaker===1&&boatClass>1&&boatClass!==9) {
    if(r(0x4ac92c)===0&&boatClass>2&&boatClass<8){dc.selectStockObject(8);selectSailColor(memory,dc,boat);}else{dc.selectStockObject(0);select(memory,dc,0x4a4ee4);}
    if(r(0x4ac92c)===0&&boatClass===10){dc.selectStockObject(8);selectSailColor(memory,dc,boat);}
    polygon(memory,dc,[lower,[tipX,tipY],kite]);if(boatClass>2&&boatClass!==9)polygon(memory,dc,[lower,[tipX,tipY],jib]);
  }
  dc.selectStockObject(7);dc.selectStockObject(0);
  if(boat===1&&r(0x4ac9bc)===1)select(memory,dc,0x4a6234);
  if(boat===2&&r(0x4ac9bc)===1)select(memory,dc,0x4aa98c);
  if(boat>10&&camera<21&&r(0x4ac9bc)===1)select(memory,dc,0x4a4f7c);
  if(boat>20&&r(0x4ac9bc)===1)select(memory,dc,0x4a5afc);
  if(r(0x4a5b80)<add32(b(0x4abf18),r(0x4a7644))&&b(0x4a89c0)<11)dc.selectStockObject(4);
  polygon(memory,dc,[low,high,curve,clew]);
  dc.moveTo(f(axisX[0]).truncI32(),f(axisY[0]).truncI32());dc.lineTo(f(high[0]).truncI32(),f(high[1]).truncI32());
}

export const FUN_00423830=drawChartCatamaran;
export const FUN_00423aa0=drawChartBoat;
