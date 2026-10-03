import { add32,sub32,imul32,idiv32,i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { wrapDegreesOnce } from '../../../../src/engine/integer-core.js';
import { bearingFromVector } from './wind.js';
import { pointInXStrip,pointInYStrip,sampleSpatialMetric,sampleAttenuationDistance } from './spatial-metrics.js';
import { clampedPointDistance } from './waypoints.js';

export const CURRENT_ROUTINES=Object.freeze({shorelineDirections:0x431200,sampleCurrent:0x42fca0,
  sampleVenueCurrent:0x430260});
const n=Float80.fromInteger;
const absolute=value=>value<0?sub32(0,value):value;

/** Complete431200. Preserves retained directions in the original uncovered venue regions. */
export function shorelineDirections(memory,x,y,options={}){
  x=i32(x);y=i32(y);
  const r=a=>memory.readI32(a),w=(a,v)=>memory.writeI32(a,v),f=a=>Float80.fromNumber(memory.readF64(a));
  const set=(forward,reverse)=>{w(0x5229c4,forward);w(0x4fe160,reverse);};
  const venue=r(0x4da1f8);
  if(venue===0){
    if(r(0x4f69b8)===5){set(y<=0?90:270,y<=0?270:90);return;}
    let heading=bearingFromVector(memory,sub32(r(0x535bc8),x),sub32(y,r(0x4f3858)),options);
    if(r(0x4f8b78)===0)heading=add32(heading,180);
    set(wrapDegreesOnce(add32(heading,90)),wrapDegreesOnce(sub32(heading,90)));
  }
  if(venue===1){if(x>-2500&&x<-830&&y>-83&&y<3200)w(0x5229c4,340);w(0x4fe160,160);}
  if(venue===2)set(60,240);
  if(venue===3){
    if(x<-1800)set(25,205);else if(x<23)set(180,360);else if(x<2260)set(25,205);else if(x<3600)set(210,30);
    if(x>3769)set(90,270);
  }
  if(r(0x4fb5d4)===1){
    if(x<6550&&y>0&&y<4700)set(190,10);
    if(x<9940&&y<-1000&&y>-5240)set(210,30);
    if(x>6900&&x<14000&&y>2600)set(80,260);
    if(x>10487&&y<2200)set(345,165);
  }
  if(venue===6){
    set(-900,-900);
    if(x<3000){if(y>1799)set(370,190);}else set(150,30);
    // The original contradictory pair is intentionally retained.
    if(x<-300&&y>-1400&&y<-3400)set(90,270);
    if(x<3000){if(y<1401&&y<-1399)set(310,130);if(y<-3399)set(370,190);}
  }
  if(venue===7){if(x<=0)set(y<-400?390:340,y<-400?210:160);else set(160,340);}
  const strip=(...args)=>pointInXStrip(memory,...args,x,y)===1;
  if(venue===9&&strip(-5730,1580,-325,2214,1700,5130))set(280,100);
  if(venue===10){
    if(strip(-4400,5140,2800,6400,-2450,1500))set(245,65);
    if(strip(-4400,1430,-1140,6400,-5400,-2450))set(65,245);
  }
  if(venue===11&&x<1000)set(380,200);
  if(venue===12)set(350,190);
  if(venue===103){set(1000,1000);if(x>1000)set(160,340);if(y>1500)set(250,70);}
  if(venue===105){set(1000,1000);if(x>-2850)set(80,260);}
  if(venue===100){set(1000,1000);if(y<=0){if(x>-4000&&y<-1300)set(100,280);}else if(y<5100&&x>0)set(215,395);}
  if(venue===101){
    set(1000,1000);if(y>1000&&x>-3000&&x<2300)set(270,90);
    if(y<-1000&&x>-4000&&x<3100)set(70,250);
  }
  if(venue===106){set(1000,1000);if(y<-800)set(45,315);if(y>0)set(295,115);}
  if(venue===102){set(1000,1000);if(x<-350&&y<1600)set(0,180);if(x<1850&&y>1599)set(320,140);}
  if(venue===999){
    const first=Float80.fromNumber(clampedPointDistance(memory,x,y,r(0x53521c),r(0x4f4b5c)).toNumber());
    const second=clampedPointDistance(memory,x,y,r(0x535230),r(0x4f4b70));
    const orientation=f(second.compare(first)<0?0x4fafd8:0x4fafb0);
    set(wrapDegreesOnce(orientation.multiply(f(0x4cc3e8)).truncI32()),
      wrapDegreesOnce(sub32(180,orientation.multiply(f(0x4cc910)).truncI32())));
  }
}

/** Complete42fca0, including original feedback, every basic channel and attenuation order. */
export function sampleCurrent(memory,x,y,boat,options={}){
  x=i32(x);y=i32(y);boat=i32(boat);
  const r=a=>memory.readI32(a),w=(a,v)=>memory.writeI32(a,v),f=a=>Float80.fromNumber(memory.readF64(a));
  const tide=r(0x5359d0);if(tide===0)return 0;
  memory.writeF64(0x4f4bc0+boat*8,f(0x4f4bc0+boat*8).multiply(f(0x4cc930)).subtract(n(r(0x535a08+boat*4)).multiply(f(0x4cc678))).toNumber());
  if(boat===1)w(0x522fd8,0);
  const metric=add32(r(0x4f42b8),10)<r(0x4f8cd0)&&boat>0?f(0x4ffcb8+boat*8):sampleSpatialMetric(memory,x,y,0,options);
  const depth=metric.truncI32(),angle=imul32(sub32(add32(add32(depth<30?1:0,r(0x536404)),r(0x4f6d60)),r(0x4ffdd0)),30);
  if(typeof options.trig?.extended!=='function')throw new TypeError('Original2010 current requires native integer-angle captures');
  let strength=options.trig.extended(angle).sine.multiply(n(tide)).truncI32();w(0x5230d8,strength);
  if(r(0x4f8b78)===1&&absolute(sub32(x,r(0x535bc8)))<200){strength=idiv32(imul32(strength,14),10);if(boat===1)w(0x522fd8,-1);}
  const weather=r(0x4f69b8);
  if(depth<70&&weather!==4){strength=idiv32(imul32(strength,depth),70);if(boat===1)w(0x522fd8,1);}
  let direction=wrapDegreesOnce(add32(r(0x523a54),strength<0?180:0));
  if((r(0x4da19c)===2||r(0x4da19c)===4)&&depth<70){
    shorelineDirections(memory,x,y,options);direction=r(0x5229c4);
    if(strength<0)direction=wrapDegreesOnce(add32(direction,180));
  }
  if(depth<90&&r(0x4f8b78)===1){
    const product=imul32(idiv32(sub32(x,r(0x535bc8)),100),idiv32(sub32(y,r(0x4f3858)),100));
    const quadrant=product<1?-1:1,base=r(0x523a54)<181?1:-1;
    direction=add32(direction,imul32(imul32(quadrant,base),-45));
  }
  if(r(0x50040c)===1&&idiv32(imul32(absolute(r(0x5229d0)),8),10)<absolute(y)){
    if(y<0&&r(0x5230dc)===1)direction=add32(direction,90);
    if(y>0&&r(0x5230dc)===3)direction=sub32(direction,90);
  }
  direction=wrapDegreesOnce(direction);
  let channel=1;
  if(weather===4){
    if(r(0x536300)===1){
      if(y<-400){let value=r(0x4fbac4);if(x<0){channel=2;value=r(0x4fbacc);}w(0x522d28,wrapDegreesOnce(sub32(value,180)));}
      else w(0x522d28,r(0x4fbac8));
    }
    if(r(0x536300)===2){
      if(x<-599){let value=r(0x4fbacc);if(y<0){channel=2;value=r(0x4fbac4);}w(0x522d28,wrapDegreesOnce(sub32(value,180)));}
      if(x>=-599&&x<-150){const value=y<0?r(0x4fbac4):r(0x4fbacc);w(0x522d28,wrapDegreesOnce(idiv32(add32(sub32(value,180),r(0x4fbac8)),2)));}
      if(x>-150)w(0x522d28,r(0x4fbac8));
    }
    if(r(0x4da158)===0)strength=tide;
    if(depth<50)strength=idiv32(imul32(strength,depth),100);
    if(channel===2)strength=idiv32(imul32(strength,3),4);
    direction=wrapDegreesOnce(add32(r(0x522d28),strength<0||r(0x4da158)===0?180:0));
  }
  if(weather===5){w(0x522d28,r(0x536300)===1?(x<=0?75:90):(x<=0?105:90));direction=wrapDegreesOnce(add32(r(0x522d28),strength<0||r(0x4da158)===0?180:0));}
  if(weather===6){
    w(0x522d28,y<-999?180:(x<=0?155:135));if(y>-601)w(0x522d28,90);
    direction=wrapDegreesOnce(add32(r(0x522d28),strength<0||r(0x4da158)===0?180:0));
  }
  if(weather===7){
    w(0x522d28,y<1001?(x<=0?285:270):10);if(y>600&&y<1001)w(0x522d28,x<=0?330:310);
    direction=wrapDegreesOnce(add32(r(0x522d28),strength<0||r(0x4da158)===0?180:0));
  }
  let attenuation=r(0x4da218);if(depth<301)attenuation=sampleAttenuationDistance(memory,0,x,y,boat,options);
  if(attenuation<r(0x4da218)){strength=idiv32(imul32(strength,attenuation),r(0x4da218));if(boat===1)w(0x522fd8,2);}
  w(0x536418,direction);w(0x522d30+boat*4,direction);
  const result=absolute(strength);w(0x535a08+boat*4,result);return result;
}

/** Complete430260. Tide-disabled original venue paths return before their undefined locals. */
export function sampleVenueCurrent(memory,x,y,boat,options={}){
  x=i32(x);y=i32(y);boat=i32(boat);
  const r=a=>memory.readI32(a),w=(a,v)=>memory.writeI32(a,v),f=a=>Float80.fromNumber(memory.readF64(a));
  const tide=r(0x5359d0);if(tide===0)return 0;
  memory.writeF64(0x4f4bc0+boat*8,f(0x4f4bc0+boat*8).multiply(f(0x4cc930)).subtract(n(r(0x535a08+boat*4)).multiply(f(0x4cc678))).toNumber());
  const metric=add32(r(0x4f42b8),1)<r(0x4f8cd0)&&boat>0?f(0x4ffcb8+boat*8):sampleSpatialMetric(memory,x,y,0,options);
  let depth=metric.truncI32();
  if(typeof options.trig?.extended!=='function')throw new TypeError('Original2010 venue current requires native integer-angle captures');
  const venue=r(0x4da1f8);
  const oscillation=offset=>options.trig.extended(imul32(sub32(add32(add32(offset,r(0x536404)),r(0x4f6d60)),r(0x4ffdd0)),30)).sine.multiply(n(tide)).truncI32();
  let strength=oscillation(depth<30&&venue!==7?1:0);
  if(r(0x536510)===1)strength=tide;
  if(boat===1)w(0x522fd8,0);w(0x5230d8,strength);
  let heading=boat,coefficient;
  const set=(value,address)=>{heading=value;coefficient=f(address);};
  const testX=(...args)=>pointInXStrip(memory,...args,x,y)===1;
  if(venue===1){
    if(y<-2300)set(150,0x4cc538);
    if(y<-1499&&y>-2301)set(160,0x4cc6b0);
    if(y<701&&y>-1501)set(170,0x4cc4f8);
    if(y>700)set(180,0x4cc668);
    if(y>1600)set(180,0x4cc400);
    if(y<251&&y>-1501&&x<-2300)set(90,0x4cc600);
    if(x>1300)set(90,0x4cc468);
    if(x>2190&&y>980)set(100,0x4cc570);
    if(x<-3600)coefficient=f(0x4cc570);
    if(y<300&&y>-1450&&x<-1800&&x>-2800)heading=135;
    if(y<0&&y>-900&&x<2250&&x>870)set(125,0x4cc650);
  }
  if(venue===2){
    set(70,0x4cc650);
    if(testX(-1325,525,-4000,2000,-5000,-790))heading=110;
    if(testX(-1140,-1730,-4000,100,-5000,-2300))heading=170;
  }
  if(venue===3){
    if(x<72)set(200,y<-3000?0x4cc650:0x4cc738);
    else if(y<-3000)set(210,0x4cc650);
    else if(y<-1399){set(180,0x4cc650);if(x<3400)set(195,0x4cc600);}
    else{set(x>1800?165:180,0x4cc4f8);}
  }
  if(r(0x4fb5d4)===1){
    set(90,0x4cc650);if(x>16636)coefficient=f(0x4cc660);
    if(x<16638&&x>14689)set(y<2150?110:75,0x4cc4f8);
    if(y<2150&&x>10399&&x<14690)set(100,0x4cc668);
    if(y>2149&&x>9774&&x<14690)set(80,0x4cc668);
    if(y<2112){
      if(x<10400&&x>8999)set(60,0x4cc468);
      if(x<9000&&x>5989)set(60,0x4cc668);
      if(x<5990)set(y>-6251?70:80,0x4cc668);
    }
    if(y<2112&&x<10340&&x>7560)coefficient=f(0x4cc538);
    if(y>2111){
      if(x<9975&&x>6549)set(90,0x4cc650);
      if(x<6550&&x>4999)set(130,0x4cc400);
      if(x<5000&&x>3499)set(130,0x4cc650);
      if(x<5000&&x>-9001)set(130,0x4cc650);
      if(x<775&&x>-9001)set(130,0x4cc738);
    }
    if(y>4249&&y<7300&&x<6475&&x>-1)set(130,0x4cc3f8);
    if(y>-1001&&y<1100&&x<10700&&x>7199)set(290,0x4cc5f0);
    if(y>1920&&y<3500&&x<-1140&&x>-9000)heading=90;
    if(strength>=0&&y>-8874&&y<-3700&&x<10225&&x>7670)coefficient=f(0x4cc5f0);
  }
  if(venue===6){set(x<300?180:190,0x4cc508);if(y<1490){if(x<-880)heading=165;if(x<-2500)heading=140;}}
  if(venue===7){
    set(y<-1300?180:y<-750?170:y<1381?160:150,strength>=0?0x4cc938:0x4cc730);
    let offset=depth<15?1:0;
    if((x<-450&&y<0||x<-400&&y>=0||x<-350&&y>599)&&strength>=0)offset=1;
    strength=oscillation(offset);
  }
  if(venue===9){
    set(x<4660&&y<3300&&y>-1160?120:140,0x4cc650);
    if(testX(-90,-6200,-8000,10565,665,9680))coefficient=n(2);
    if(x>-700&&x<6000&&y<2112&&y>75){heading=100;coefficient=n(2);}
    if(testX(-6080,80,-1004,-700,75,2112))set(105,0x4cc708);
  }
  if(venue===11){
    heading=y>2099?90:105;coefficient=Float80.fromNumber(x<0?0.8:1.5);
    if(y<0)heading=120;if(y<-4300)heading=75;
    if(x>5650&&x<10950&&y>1910&&y<2443){heading=100;coefficient=n(4);}
    if(testX(5313,4434,3555,10250,4070,4767))set(100,0x4cc710);
  }
  if(venue===100){
    const positive=strength>=0;set(80,0x4cc650);
    if(x<-1300&&y<-1800)set(190,positive?0x4cc680:0x4cc668);
    if(x<-500&&y>-1801)set(70,positive?0x4cc600:0x4cc650);
    if(x<4400&&y>-1801)set(70,positive?0x4cc600:0x4cc650);
    if(x>4399&&y>-1801)set(80,positive?0x4cc940:0x4cc468);
    if(!positive&&pointInYStrip(memory,-3650,4050,1270,-238,5130,2050,x,y)===1)heading=50;
    if(x<2250&&x>-2500&&y>5370){set(120,positive?0x4cc948:0x4cc730);strength=oscillation(-1);}
    if(x<-2500&&y>5370){set(110,positive?0x4cc548:0x4cc708);strength=oscillation(-1);}
    if(x<500&&y<1400&&y>-1400)coefficient=Float80.fromNumber(coefficient.multiply(f(0x4cc668)).toNumber());
  }
  if(venue===101){set(70,x<-4800?0x4cc658:0x4cc650);if(x<-300&&y<-500)coefficient=Float80.fromNumber(coefficient.multiply(f(0x4cc668)).toNumber());}
  if(venue===104){
    set(x>0||y<-1800?200:180,0x4cc400);
    if(y<0)coefficient=f(x<0?0x4cc820:0x4cc950);
    if(strength>=0)coefficient=Float80.fromNumber(coefficient.multiply(f(0x4cc600)).toNumber());
  }
  if(venue===105){
    set(180,y<-2300||y>1400?0x4cc658:0x4cc708);
    if(y<-1349)heading=160;
    if(y<-1000&&y>-1350&&x<-2750)heading=180;
    if(x>-2000)heading=160;
    if(x<-2750&&y>-1000)heading=200;
    for(const condition of[x>-1260,x>600,y>-600,y<-600&&x>-2450&&x<-1259,strength>=0])
      if(condition)coefficient=Float80.fromNumber(coefficient.multiply(f(0x4cc668)).toNumber());
  }
  if(venue===106)set(300,x>1000?0x4cc660:x>0?0x4cc778:0x4cc668);
  if(venue===102){
    set(x<-1000?325:300,0x4cc708);strength=oscillation(0);
    if(y>200&&strength<0)set(270,0x4cc4f8);
  }
  if(venue===999){
    heading=f(0x4fafb0).multiply(f(0x4cc3e8)).truncI32();
    if(r(0x4f4afc)>130&&r(0x522f08)>6){
      if(f(0x4fafb0).compare(f(0x4fafd8))<0)heading=wrapDegreesOnce(idiv32(sub32(sub32(f(0x4fafb0).multiply(f(0x4cc3e8)).truncI32(),f(0x4fafd8).multiply(f(0x4cc910)).truncI32()),180),2));
      if(f(0x4fafd8).compare(f(0x4fafb0))<0){
        heading=wrapDegreesOnce(sub32(-180,f(0x4fafb0).multiply(f(0x4cc910)).truncI32()));
        heading=wrapDegreesOnce(add32(idiv32(sub32(heading,f(0x4fafd8).multiply(f(0x4cc910)).truncI32()),2),180));
      }
    }
    coefficient=f(0x4cc650);if(r(0x4da26c)!==1)heading=wrapDegreesOnce(add32(heading,180));
  }
  if(coefficient===undefined)throw new RangeError('Original2010 venue-current coefficient is undefined for this tide-enabled configuration');
  if(depth<50)strength=n(depth).multiply(n(strength)).multiply(f(0x4cc958)).truncI32();
  if(boat===1&&depth<11)w(0x522fd8,-1);
  strength=n(strength).multiply(coefficient).truncI32();
  w(0x523a54,heading);w(0x536418,wrapDegreesOnce(add32(heading,strength<0?180:0)));w(0x522d30+boat*4,r(0x536418));
  let attenuation=depth;
  if(depth<81||venue!==0)attenuation=sampleAttenuationDistance(memory,0,x,y,boat,options);else attenuation=r(0x4da218);
  if(attenuation<r(0x4da218)){strength=idiv32(imul32(attenuation,strength),r(0x4da218));if(boat===1)w(0x522fd8,2);}
  // The original repeats this attenuation for every boat.
  if(attenuation<r(0x4da218))strength=idiv32(imul32(attenuation,strength),r(0x4da218));
  const result=absolute(strength);if(boat>0)w(0x535a08+boat*4,result);return result;
}
