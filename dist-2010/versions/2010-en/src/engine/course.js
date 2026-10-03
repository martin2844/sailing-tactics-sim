import { add32,sub32,imul32,idiv32,i32,u32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { scaledRandom,wrapDegreesOnce } from '../../../../src/engine/integer-core.js';
import { projectPoint,sampleSpatialMetric } from './spatial-metrics.js';
import { bearingFromVector } from './wind.js';
export const COURSE_ROUTINE=0x42dea0;

/** Complete42dea0. Mode controls retained marks and all ten-word per-boat target rows. */
export function initializeCourse(memory,mode,rng,options={}){
 mode=i32(mode);
 const r=a=>memory.readI32(a),w=(a,v)=>memory.writeI32(a,v);
 const project=options.projectPoint??projectPoint;
 const point=(x,y,distance,heading)=>project(memory,x,y,distance,heading,options);
 const into=(ax,ay,x,y,distance,heading)=>{point(x,y,distance,heading);w(ax,r(0x4fe080));w(ay,r(0x523180));};
 const heading=()=>r(0x535208),hand=()=>r(0x4da214);
 const offset=angle=>add32(heading(),imul32(hand(),angle));
 const metric=(x,y)=>sampleSpatialMetric(memory,x,y,0,options);
 const measure=(x,y,index)=>{
  const dx=sub32(x,r(0x536410)),dy=sub32(r(0x536414),y);
  w(0x4fb518+index*4,bearingFromVector(memory,dx,dy,options));
  const a=Float80.fromNumber(dx),b=Float80.fromNumber(dy);
  w(0x4fb530+index*4,a.multiply(a).add(b.multiply(b)).sqrt().truncI32());
 };
 const venue=r(0x4da1f8),course=r(0x4da19c),count=r(0x4da194);
 w(0x4da214,r(0x53646c)===1?-1:1);w(0x535208,r(0x4f7f94));w(0x525a9c,1000);
 if(venue===0&&r(0x53527c)===1){if(r(0x5364c8)===0)w(0x525a9c,1880);if(r(0x5364c8)===1)w(0x525a9c,800);}
 if(venue===999)w(0x525a9c,r(0x4da238));
 let radius=(r(0x4da198)>8?0:6)+(count===2?41:44);
 if(r(0x5363cc)===1)radius=add32(radius,2);
 if(r(0x5363b8)===1||r(0x5363c4)===1||r(0x5363bc)===1||r(0x53652c)===1)radius=add32(radius,5);
 if(r(0x4f8b78)===1)radius=add32(radius,3);
 if(course===8){
  if(r(0x4f8b78)===0){w(0x525a9c,3300);w(0x535208,90);w(0x4da168,1);}
  if(r(0x4f8b78)===1)w(0x525a9c,2200);
  radius=add32(radius,r(0x4f8b78)===0?30:20);
 }
 if(venue===5)radius=add32(radius,7);
 if(r(0x5359d0)>7)radius=add32(radius,3);
 if(r(0x5359d0)>14)radius=add32(radius,2);
 w(0x523598,imul32(add32(count,10),10));if(count===2)w(0x523598,125);
 w(0x536410,0);w(0x536414,0);
 if(course===1)w(0x536414,350);if(course===2)w(0x536410,-250);
 if(course===3)w(0x536414,-350);if(course===4)w(0x536410,250);
 if(r(0x4f4510)===1)w(0x536410,500);
 if(course===9){w(0x536410,0);w(0x536414,-400);}
 if(course===10){w(0x536410,0);w(0x536414,400);}
 if(venue===5){w(0x536410,4000);w(0x536414,-1000);if(r(0x4fad38)===4){w(0x536410,1000);w(0x536414,0);}}
 const lengths={1:1500,2:2000,3:2000,4:2400,5:3000,6:2000,7:1000,9:1500,10:1500,11:2000,12:2500,
  100:1800,101:2000,102:2000,103:1500,104:1900,105:1850,106:1500};
 if(Object.hasOwn(lengths,venue))w(0x525a9c,lengths[venue]);
 if(venue===2){w(0x536410,700);w(0x536414,1100);}
 if(venue===104)w(0x536410,150);
 if(venue===999)w(0x525a9c,r(0x4da238));
 if(venue>0&&r(0x53527c)===1)w(0x525a9c,idiv32(imul32(r(0x525a9c),9),5));
 if(r(0x53640c)===1)w(0x525a9c,imul32(idiv32(r(0x525a9c),10),7));
 if(r(0x5363cc)===1)w(0x525a9c,imul32(idiv32(r(0x525a9c),10),7));
 if(r(0x5364c8)===1)w(0x525a9c,idiv32(r(0x525a9c),2));
 if(r(0x53527c)===1){
  const distance=r(0x5364c8)===0?idiv32(r(0x525a9c),2):800;
  into(0x536410,0x536414,r(0x536410),r(0x536414),distance,wrapDegreesOnce(add32(heading(),180)));
 }
 let lateral=r(0x4f8b78)===1?r(0x525a9c):idiv32(imul32(r(0x525a9c),3),4);
 if(course===10)lateral=idiv32(r(0x525a9c),3);
 if(r(0x4da168)===1)lateral=count<15?1:r(0x525a9c);
 w(0x4da214,r(0x53646c)===1&&r(0x4f8b78)===0?-1:1);
 if(mode<3||r(0x5363f8)===0){
  into(0x4fe094,0x4fe2a0,r(0x536410),r(0x536414),r(0x523598),offset(90));
  if(count===2)into(0x4fe094,0x4fe2a0,r(0x536410),r(0x536414),r(0x523598),add32(heading(),90));
  w(0x4fb518,wrapDegreesOnce(offset(90)));w(0x4fb530,r(0x523598));
 }
 if(venue!==5&&mode<2)into(0x5229d4,0x522ac8,idiv32(add32(r(0x4fe094),r(0x536410)),2),
  idiv32(add32(r(0x4fe2a0),r(0x536414)),2),r(0x525a9c),heading());
 measure(r(0x5229d4),r(0x522ac8),1);metric(r(0x5229d4),r(0x522ac8));
 let lateralHeading=r(0x4f8b78)===1||course===9?offset(-90):add32(imul32(sub32(scaledRandom(60,rng),120),hand()),heading());
 if(course===10)lateralHeading=offset(-110);
 if(r(0x4da168)===1&&count>14){lateralHeading=offset(-5);lateral=r(0x525a9c);}
 into(0x522acc,0x522ae0,r(0x536410),r(0x536414),lateral,lateralHeading);
 w(0x4fb520,wrapDegreesOnce(lateralHeading));w(0x4fb538,lateral);metric(r(0x522acc),r(0x522ae0));
 const finalAngle=r(0x4f8b78)===0?180:200;
 into(0x5229c8,0x522ac4,r(0x536410),r(0x536414),r(0x525a9c),offset(-finalAngle));
 w(0x4fb524,wrapDegreesOnce(offset(-finalAngle)));
 if(r(0x53527c)===1){
  if(r(0x536408)===1){w(0x5229c8,r(0x536410));w(0x522ac4,r(0x536414));}
  else into(0x5229c8,0x522ac4,idiv32(add32(r(0x536410),r(0x4fe094)),2),
   idiv32(add32(r(0x4fe2a0),r(0x536414)),2),20,add32(r(0x4f7f94),180));
  w(0x4fb524,wrapDegreesOnce(offset(-180)));
 }
 if(r(0x4da1e8)===1){
  into(0x4f4a68,0x4f6d34,r(0x5229c8),r(0x522ac4),90,offset(-85));
  into(0x523248,0x52359c,r(0x5229c8),r(0x522ac4),90,offset(85));
 }
 w(0x4fb53c,r(0x525a9c));
 if(venue===5){
  if(r(0x4fad38)<4){w(0x5229c8,275);w(0x522ac4,8820);w(0x5229d4,10160);w(0x522ac8,-9420);w(0x4da214,-1);}
  else{w(0x5229d4,275);w(0x522ac8,8820);w(0x5229c8,10160);w(0x522ac4,-9420);w(0x4da214,1);}
  w(0x53646c,r(0x4fad38)<4?1:0);w(0x522ae0,-3300);w(0x522acc,14444);
  measure(r(0x5229d4),r(0x522ac8),1);measure(r(0x522acc),r(0x522ae0),2);measure(r(0x5229c8),r(0x522ac4),3);
 }
 metric(r(0x5229c8),r(0x522ac4));
 into(0x4f6d38,0x4f7f88,r(0x536410),r(0x536414),200,add32(heading(),170));
 const twoThirds=u32(imul32(radius,2))/3>>>0;
 for(let boat=1;boat<=r(0x4da194);boat++){
  const delta=(boat-1)*40,target=(index,x,y,distance,direction)=>into(0x5117ac+delta+index*4,0x511d2c+delta+index*4,x,y,distance,direction);
  target(0,r(0x5229d4),r(0x522ac8),radius,offset(90));
  target(1,r(0x5229d4),r(0x522ac8),twoThirds,heading());
  target(2,r(0x5229d4),r(0x522ac8),radius,offset(-60));
  if(r(0x4da168)===1&&r(0x4da194)<15){
   const enlarged=u32(imul32(radius,3))>>>1;
   target(0,r(0x5229d4),r(0x522ac8),enlarged,offset(90));
   target(1,r(0x5229d4),r(0x522ac8),radius,offset(-15));
   target(2,r(0x5229d4),r(0x522ac8),enlarged,offset(-90));
  }
  if(r(0x4da168)===1&&r(0x4da194)>14){
   if(r(0x5363b8)===0&&r(0x5363c4)===0&&r(0x53652c)===0)point(r(0x522acc),r(0x522ae0),twoThirds,offset(-10));
   if(r(0x5363b8)===1||r(0x5363c4)===1||r(0x53652c)===1)point(r(0x522acc),r(0x522ae0),imul32(radius,3)>>2,offset(-10));
  }
  if(r(0x4da168)===0)point(r(0x522acc),r(0x522ae0),radius,offset(-55));
  w(0x5117b8+delta,r(0x4fe080));w(0x511d38+delta,r(0x523180));
  if(venue===5&&hand()===1){w(0x5117b8+delta,14600);w(0x511d38+delta,4300);}
  target(4,r(0x522acc),r(0x522ae0),radius,offset(-135));
  if(venue===5&&hand()===-1){w(0x5117bc+delta,15100);w(0x511d3c+delta,2700);}
  target(5,r(0x5229c8),r(0x522ac4),radius,offset(course===8?-135:-115));
  target(6,r(0x5229c8),r(0x522ac4),radius,offset(135));
  if(course===8)target(5,r(0x5229c8),r(0x522ac4),radius,offset(-135));
  if(r(0x4da168)===1&&r(0x4da194)<15){
   w(0x522acc,r(0x5229c8));w(0x522ae0,r(0x522ac4));
   for(const index of[3,4]){w(0x5117ac+delta+index*4,r(0x5117c0+delta));w(0x511d2c+delta+index*4,r(0x511d40+delta));}
   w(0x4fb520,r(0x4fb524));w(0x4fb538,r(0x4fb53c));
  }
  w(0x5117c8+delta,idiv32(add32(r(0x536410),r(0x4fe094)),2));w(0x511d48+delta,idiv32(add32(r(0x4fe2a0),r(0x536414)),2));
  w(0x5117cc+delta,r(0x5117ac+delta));w(0x511d4c+delta,r(0x511d2c+delta));
  const pose=r(0x4da188),alternate=mode===3&&boat>r(0x4da140)||pose===7&&r(0x5364e0)===0||pose===2||pose===1;
  if(r(0x4da1e8)===1&&alternate){
   if(boat%2===0){
    target(5,r(0x4f4a68),r(0x4f6d34),radius,add32(r(0x4f7f94),imul32(hand(),110)));
    target(6,r(0x4f4a68),r(0x4f6d34),radius,add32(r(0x4f7f94),imul32(hand(),-145)));
   }else{
    target(5,r(0x523248),r(0x52359c),radius,add32(r(0x4f7f94),imul32(hand(),-110)));
    target(6,r(0x523248),r(0x52359c),radius,add32(r(0x4f7f94),imul32(hand(),145)));
   }
  }
 }
 for(const[index,[x,y]]of[[0,[0x536410,0x536414]],[1,[0x4fe094,0x4fe2a0]],[2,[0x5229d4,0x522ac8]],
  [3,[0x522acc,0x522ae0]],[4,[0x5229c8,0x522ac4]]]){memory.writeF64(0x4f83a0+index*8,r(x));memory.writeF64(0x4fb070+index*8,r(y));}
 const finalCount=r(0x4da194);
 memory.writeF64(0x4f83c8+finalCount*8,r(0x4f4a68));memory.writeF64(0x4fb098+finalCount*8,r(0x4f6d34));
 memory.writeF64(0x4f83d0+finalCount*8,r(0x523248));memory.writeF64(0x4fb0a0+finalCount*8,r(0x52359c));
}
