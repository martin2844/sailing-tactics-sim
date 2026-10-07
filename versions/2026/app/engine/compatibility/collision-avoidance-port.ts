import type {EngineMemory,EngineOptions,CollisionNumerics} from '../ports.ts';
import type {RandomStream} from '../random/streams.ts';
import {updateCollisionAvoidance} from '../ai/collision-avoidance.ts';
const slot=(base:number,boat:number)=>(base+Math.imul(boat,4))>>>0;
export function runCollisionAvoidance(memory:EngineMemory,random:RandomStream,options:EngineOptions,boat:number,numeric:CollisionNumerics):void {
 if(!numeric.supported()||options.retainedDrawingStack!==undefined||!Number.isInteger(boat)||boat<1||boat>memory.readI32(0x4da194)){
  numeric.reference(memory,random,{...options,fastCollisionAvoidance:undefined},boat);return;
 }
 updateCollisionAvoidance({
  boats:()=>memory.readI32(0x4da194),humans:()=>memory.readI32(0x4da140),clock:()=>memory.readI32(0x4f8cd0),
  lastAvoidance:id=>memory.readI32(slot(0x4fe9d0,id)),clearAvoidance:id=>memory.writeI32(slot(0x4fe6d0,id),0),
  x:id=>memory.readI32(slot(0x513480,id)),y:id=>memory.readI32(slot(0x513510,id)),
  heading:id=>memory.readI32(slot(0x535740,id)),setHeading:(id,value)=>memory.writeI32(slot(0x535740,id),value),
  avoid:(distance,other,id)=>numeric.avoid(memory,random,options,distance,other,id,2),
  warn:(distance,other,id)=>numeric.warn(memory,random,options,distance,other,id),extendedDistance:numeric.distance,
 },boat);
}
