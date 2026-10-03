import { add32,sub32,imul32,idiv32,i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { scaledRandom,wrapDegreesOnce } from '../../../../src/engine/integer-core.js';
import { initializeShoreline,initializeEllipse,initializeAdvancedTerrain } from './terrain.js';
import { initializeVenuePoint } from './venue-geometry.js';
import { initializeCustomVenuePoint } from './custom-venue.js';

export const CONFIGURATION_ADDRESSES=Object.freeze({
  initializeConfiguration:0x42c060,venue:0x4da1f8,course:0x4da19c,
  boatClass:0x4da188,boatCount:0x4da194,difficulty:0x4da190,
  placementMode:0x4da1e8,tideSetting:0x4da168,weather:0x4f69b8,
  island:0x4f8b78,shore:0x5230dc,reversal:0x4f4510,
  xAspect:0x4fba00,yAspect:0x535558,
  shorelineMode:0x4f7ed8,shorelineVariant:0x50040c,forceCondition:0x4f8db8,
  enlargedTerrain:0x53527c,reducedTerrain:0x5364c8,
  pointCount:0x522f08,visiblePointCount:0x4fe764,markCount:0x535498,
  extraPointCount:0x511374,backgroundPointCount:0x535e3c,
  channelCount:0x5364b4,
});

// Original literal configuration assignments. Each child still computes its
// entire geometry from the current inputs and consumes the original RNG draws.
const venues=Object.freeze({
  1:{pointCount:21,visiblePointCount:17,markCount:17,shore:1,extraPointCount:0,backgroundPointCount:0,clearHeight:true,channels:[330,280,180,80]},
  2:{pointCount:21,visiblePointCount:21,markCount:19,shore:4,extraPointCount:0,backgroundPointCount:0,clearHeight:true,channels:[330]},
  3:{pointCount:15,visiblePointCount:13,markCount:11,shore:1,extraPointCount:0,backgroundPointCount:0,clearHeight:true,channels:[20]},
  4:{pointCount:7,visiblePointCount:7,markCount:7,shore:1,extraPointCount:1,backgroundPointCount:5,clearHeight:true,channels:null},
  5:{pointCount:7,visiblePointCount:7,markCount:7,shore:1,extraPointCount:1,backgroundPointCount:5,clearHeight:true,channels:null,pointVenue:4},
  6:{pointCount:18,visiblePointCount:12,markCount:13,shore:4,extraPointCount:0,backgroundPointCount:0,channels:[20,180,300]},
  7:{pointCount:18,visiblePointCount:18,markCount:11,shore:1,extraPointCount:2,backgroundPointCount:0,clearHeight:true,channels:[0,150]},
  9:{pointCount:15,visiblePointCount:14,markCount:10,shore:1,extraPointCount:0,backgroundPointCount:0,channels:[310,10,120]},
  10:{pointCount:14,visiblePointCount:14,markCount:8,shore:1,extraPointCount:0,backgroundPointCount:0,channels:[70,260]},
  11:{pointCount:16,visiblePointCount:16,markCount:11,shore:4,extraPointCount:2,backgroundPointCount:0,channels:[25,200]},
  12:{pointCount:14,visiblePointCount:12,markCount:8,shore:4,extraPointCount:0,backgroundPointCount:0,channels:[0,170]},
  100:{pointCount:14,visiblePointCount:13,markCount:9,shore:1,extraPointCount:2,backgroundPointCount:0,unboundedDrawing:true,channels:[]},
  101:{pointCount:15,visiblePointCount:15,markCount:12,shore:1,extraPointCount:2,backgroundPointCount:0,unboundedDrawing:true,channels:[]},
  102:{pointCount:14,visiblePointCount:13,markCount:10,shore:1,extraPointCount:2,backgroundPointCount:0,unboundedDrawing:true,channels:[]},
  103:{pointCount:16,visiblePointCount:15,markCount:9,shore:1,extraPointCount:0,backgroundPointCount:0,channels:[]},
  104:{pointCount:14,visiblePointCount:14,markCount:10,shore:2,extraPointCount:0,backgroundPointCount:0,unboundedDrawing:true,channels:[]},
  105:{pointCount:15,visiblePointCount:15,markCount:9,shore:1,extraPointCount:3,backgroundPointCount:0,channels:[]},
  106:{pointCount:11,visiblePointCount:11,markCount:7,shore:4,extraPointCount:0,backgroundPointCount:0,unboundedDrawing:true,channels:[]},
});

/** Complete42c060: custom, basic and named venue configuration with original call order. */
export function initializeConfiguration(memory,rng,options={}) {
  const a=CONFIGURATION_ADDRESSES;
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  const read=key=>r(a[key]),write=(key,value)=>w(a[key],value);
  const f=address=>Float80.fromNumber(memory.readF64(address));
  const n=Float80.fromInteger,random=range=>scaledRandom(range,rng);
  const floating=(key,value)=>memory.writeF64(a[key],value instanceof Float80?value.toNumber():value);
  const ellipse=()=>initializeEllipse(memory,rng,options);
  const count=()=>add32(add32(read('backgroundPointCount'),read('extraPointCount')),read('pointCount'));
  if(read('venue')===999){
    w(0x4da220,-30000);w(0x4da228,-30000);w(0x4da21c,30000);w(0x4da224,30000);
    write('markCount',r(0x536508)===1?5:10);
    if(r(0x536504)===3)write('markCount',8);
    if(r(0x536504)===1)write('markCount',6);
    write('weather',0);write('extraPointCount',0);write('shore',add32(idiv32(r(0x4da23c),90),1));
    write('backgroundPointCount',0);write('visiblePointCount',read('markCount'));write('pointCount',read('markCount'));
    if(read('markCount')!==0)for(let index=1;index<=count();index++){
      w(0x535310+index*4,0);w(0x535370+index*4,72);
      initializeCustomVenuePoint(memory,index,options);
    }
    write('channelCount',0);
    const difference=sub32(r(0x51359c),r(0x4f711c));
    const magnitude=difference<0?sub32(0,difference):difference;
    w(0x4f4afc,magnitude);
    if(magnitude>180)w(0x4f4afc,sub32(360,magnitude));
    if(r(0x4f4afc)<50&&magnitude<50){
      w(0x4fbac4,idiv32(add32(r(0x4f711c),r(0x51359c)),2));
      w(0x4fbac8,wrapDegreesOnce(add32(r(0x4fbac4),180)));write('channelCount',2);
    }
    if(r(0x4f4afc)>130){
      if(r(0x4f711c)<r(0x51359c)){
        const heading=wrapDegreesOnce(sub32(r(0x51359c),180));
        w(0x4fbac4,idiv32(add32(heading,r(0x4f711c)),2));
      }
      if(r(0x51359c)<r(0x4f711c)){
        const heading=wrapDegreesOnce(sub32(r(0x4f711c),180));
        w(0x4fbac4,idiv32(add32(heading,r(0x51359c)),2));
      }
      if(r(0x4f4afc)===0)w(0x4fbac4,r(0x51359c));
      w(0x4fbac8,wrapDegreesOnce(add32(r(0x4fbac4),180)));write('channelCount',2);
    }
    if(r(0x5364fc)===1)return;
  }
  if(read('venue')<1){
    if(read('course')===8&&read('difficulty')!==7)write('course',1);
    let course=read('course');write('reversal',course===11?1:0);
    if(course===7){
      for(const address of[0x4da168,0x5363f8,0x53640c,0x4da1e8,0x53527c])w(address,0);
      if(read('boatClass')<3||read('boatClass')>4)write('boatClass',3);
    }
    write('forceCondition',0);
    for(let boat=0;boat<read('boatCount');boat++)w(0x4fe2b4+boat*4,0);
    write('shorelineVariant',0);write('shorelineMode',0);
    if(course===0){course=add32(random(r(0x53640c)===1||r(0x536408)===1?5:6),1);write('course',course);}
    if(course===1||course===3){write('shorelineMode',1);write('shorelineVariant',1);}
    if(course<5){write('weather',0);write('island',0);write('shore',course);}
    if(course===5){write('weather',1);write('island',0);write('shore',1);}
    if(course===6){write('shorelineVariant',0);write('weather',5);write('shore',1);write('island',0);}
    if(course===7){
      write('island',1);write('shore',1);write('weather',0);w(0x53640c,0);write('tideSetting',0);w(0x53646c,0);
    }
    if(course===8){
      for(const address of[0x5363f8,0x53640c,0x4f8db8,0x4f69b8,0x536408,0x4da1e8,0x53527c])w(address,0);
      if(read('island')===1){
        write('island',1);write('shore',1);write('shorelineVariant',0);write('shorelineMode',0);
        write('tideSetting',0);w(0x53646c,0);write('boatClass',3);
      }else{
        write('boatClass',1);write('shorelineVariant',1);write('shorelineMode',1);write('island',0);write('tideSetting',1);
        write('shore',random(10)<6?1:3);course=read('course');
      }
    }
    if(course===9||course===10){
      write('shorelineMode',0);write('shorelineVariant',0);write('shore',course===9?1:3);
      write('weather',course===9?6:7);write('forceCondition',0);write('island',0);
    }
    if(course===11){write('shorelineVariant',0);write('shore',4);write('weather',0);write('island',0);write('forceCondition',0);}
    if(course>=12&&course<=14){
      write('weather',course-10);write('island',0);write('shore',4);write('shorelineVariant',0);write('forceCondition',0);write('shorelineMode',0);
    }
    if(read('weather')>1){initializeAdvancedTerrain(memory,rng,options);return;}
    w(0x5229d0,read('shore')===1?-950:950);w(0x5127a4,read('shore')===1?1:-1);
    if(read('shorelineMode')===1){write('shorelineVariant',1);initializeShoreline(memory,rng,options);course=read('course');}
    if(course===2||course===4){
      floating('xAspect',f(0x4cc6b0).subtract(n(random(2)).multiply(f(0x4cc8b0))));
      floating('yAspect',f(0x4cc468).subtract(n(random(2)).multiply(f(0x4cc8b0))));ellipse();course=read('course');
    }
    if(read('weather')===1){
      floating('xAspect',f(0x4cc600).subtract(n(random(10)).multiply(f(0x4cc8b0))));
      floating('yAspect',f(0x4cc600).subtract(n(random(10)).multiply(f(0x4cc8b0))));
      if(read('enlargedTerrain')===1&&read('reducedTerrain')===0){
        floating('xAspect',f(0x4cc650).subtract(n(random(10)).multiply(f(0x4cc908))));
        floating('yAspect',f(0x4cc650).subtract(n(random(10)).multiply(f(0x4cc908))));
      }
      ellipse();course=read('course');
    }
    if(read('forceCondition')===1){floating('xAspect',3);floating('yAspect',1);ellipse();course=read('course');}
    if(read('island')===1){floating('xAspect',0.5);floating('yAspect',course===8?1.4:1.1);ellipse();}
    w(0x5229c4,imul32(read('shore'),90));w(0x4fe160,add32(r(0x5229c4),180));
    if(r(0x4fe160)>360)w(0x4fe160,sub32(r(0x5229c4),180));
    if(read('reversal')===1){write('shore',4);floating('xAspect',0.65);floating('yAspect',1.5);ellipse();}
    return;
  }
  write('course',0);write('island',0);write('weather',0);write('channelCount',0);
  w(0x4fb5d4,read('venue')===4||read('venue')===5?1:0);
  const definition=venues[read('venue')];
  if(!definition)return;
  for(const field of['pointCount','visiblePointCount','markCount','shore','extraPointCount','backgroundPointCount'])write(field,definition[field]);
  if(read('venue')===5){write('enlargedTerrain',0);write('placementMode',0);}
  for(let index=1;index<=count();index++){
    if(definition.clearHeight){memory.writeU32(0x4f45c0+index*8,0);memory.writeU32(0x4f45c4+index*8,0);}
    w(0x535310+index*4,definition.unboundedDrawing?-1:0);w(0x535370+index*4,definition.unboundedDrawing?-1:72);
    initializeVenuePoint(memory,definition.pointVenue??read('venue'),index,rng,options);
  }
  if(definition.channels!==null){
    write('channelCount',definition.channels.length);
    for(const[index,direction]of definition.channels.entries())w(0x4fbac4+index*4,direction);
  }
}
