import { add32,sub32,imul32,idiv32,i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { sinCosX87 } from '../../../../src/runtime/transcendentals.js';
import { scaledRandom } from '../../../../src/engine/integer-core.js';
import { VENUE_POINT_DEFINITIONS } from './venue-definitions.js';

export const VENUE_GEOMETRY_ADDRESSES=Object.freeze({
  orientation:0x4fafa8,aspect:0x4fb5e0,radius:0x534fe0,
  centerX:0x535218,centerY:0x4f4b58,notch:0x522cb0,
  polygonX:0x4f1cf8,polygonY:0x4f8ee8,
  pointCount:0x522f08,boatCount:0x4da194,placementMode:0x4da1e8,
  targetX:0x4f83c8,targetY:0x4fb098,
  half:0x4cc4f8,
});
export const VENUE_POINT_ROUTINES=Object.freeze(Object.fromEntries(
  Object.entries(VENUE_POINT_DEFINITIONS).map(([venue,definition])=>[venue,definition.routine]),
));

const notchFactors=[0x4ccac8,0x4ccd68,0x4cc848,0x4cc6c0,0x4ccc70,0x4cc508,
  0x4ccc00,0x4ccbe0,0x4cc738,0x4cc738,0x4ccbe0,0x4ccc00,0x4cc508,
  0x4ccc70,0x4cc6c0,0x4cc848,0x4ccd68,0x4ccac8];
const indexed=(base,index,stride=4)=>(base+Math.imul(i32(index),stride))>>>0;
const spill=value=>Float80.fromNumber(value.toNumber());

/**
 * Complete named-venue point constructors listed in VENUE_POINT_ROUTINES.
 * Definition data contains the original literal writes before point generation;
 * generated vertices are calculated here, including all 72 original RNG draws.
 * Each function's first multiplication order comes from its native opcode audit.
 * Orientation FSIN/FCOS results and local point components spill to binary64 at
 * the original boundaries. Continuous trig uses the shared documented x87 model;
 * strict native whole-routine tests establish final-state parity for the cases.
 */
export function initializeVenuePoint(memory,venue,index,rng,options={}) {
  index=i32(index);venue=i32(venue);
  const definition=VENUE_POINT_DEFINITIONS[venue];
  if(!definition)throw new RangeError(`No original named-venue constructor for ${venue}`);
  if(typeof options.trig?.extended!=='function')throw new TypeError('Load the 2010 native integer-angle reference before generating venue points');
  const point=definition.points[index];
  let gap=definition.defaultGap==='indexEquals1'?(index===1?1:0):definition.defaultGap;
  if(point){
    for(const [address,value]of point.writes)memory.writeU32(address,value);
    if(point.gap!==null)gap=i32(point.gap);
  }
  const a=VENUE_GEOMETRY_ADDRESSES;
  const integer=field=>memory.readI32(indexed(a[field],index));
  const floating=field=>Float80.fromNumber(memory.readF64(indexed(a[field],index,8)));
  const constant=address=>Float80.fromNumber(memory.readF64(address));
  const rotation=(options.sinCosX87??sinCosX87)(floating('orientation'));
  const rotationCosine=spill(rotation.cosine),rotationSine=spill(rotation.sine);
  const polygonOffset=imul32(index,0x124);
  for(let vertex=0,angle=0;angle<356;vertex++,angle+=5){
    const baseRadius=integer('radius');
    let randomRange=idiv32(baseRadius,30);
    if(floating('aspect').compare(constant(a.half))<0){
      if(angle<40||angle>320)randomRange=idiv32(baseRadius,40);
      if(angle>140&&angle<220)randomRange=idiv32(baseRadius,40);
    }
    let radius=Float80.fromInteger(sub32(integer('radius'),scaledRandom(randomRange,rng)));
    const notch=integer('notch');
    if(notch>0){
      for(const [offset,address]of notchFactors.entries()){
        if(vertex===add32(notch,offset))radius=spill(radius.multiply(constant(address)));
      }
    }
    if(gap>0){
      if(vertex===sub32(gap,1))radius=spill(radius.multiply(constant(0x4ccd70)));
      if(vertex===gap)radius=spill(radius.multiply(constant(0x4cc630)));
      if(vertex===add32(gap,1))radius=spill(radius.multiply(constant(0x4ccd70)));
    }
    const {sine,cosine}=options.trig.extended(angle);
    const aspect=floating('aspect');
    const localX=spill(definition.aspectFirst?sine.multiply(aspect).multiply(radius):sine.multiply(radius).multiply(aspect));
    const localY=spill(cosine.multiply(radius).negate());
    const x=rotationCosine.multiply(localX).subtract(rotationSine.multiply(localY));
    const y=rotationSine.multiply(localX).add(rotationCosine.multiply(localY));
    const offset=add32(polygonOffset,imul32(vertex,4));
    memory.writeI32((a.polygonX+offset)>>>0,add32(x.truncI32(),integer('centerX')));
    memory.writeI32((a.polygonY+offset)>>>0,add32(y.truncI32(),integer('centerY')));
  }
  memory.writeI32((a.polygonX+polygonOffset+0x120)>>>0,memory.readI32((a.polygonX+polygonOffset)>>>0));
  memory.writeI32((a.polygonY+polygonOffset+0x120)>>>0,memory.readI32((a.polygonY+polygonOffset)>>>0));
  if(!definition.copyTargets)return;
  const pointCount=memory.readI32(a.pointCount),placement=memory.readI32(a.placementMode);
  let targetOffset=imul32(memory.readI32(a.boatCount),8);
  for(let count=0;count<pointCount;count++,targetOffset=add32(targetOffset,8)){
    if(placement===0||placement===1){
      const extra=placement===1?16:0;
      memory.writeF64((a.targetX+targetOffset+extra)>>>0,memory.readI32(a.centerX+4+count*4));
      memory.writeF64((a.targetY+targetOffset+extra)>>>0,memory.readI32(a.centerY+4+count*4));
    }
  }
}
