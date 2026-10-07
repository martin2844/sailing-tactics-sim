import {clearFleetLayout} from '../spawn/fleet-layout.ts';
import {boatShapes,radius,obstacles} from '../../contact-shapes.ts';
import {contactCourse} from '../../contact-world.ts';
import {world} from '../../contact-geometry.ts';
import {PreviewWater} from '../../preview-water.ts';
import {readNativeTerrain} from '../../native-environment.ts';
import type {EngineMemory} from '../ports.ts';
interface SpawnNumerics {depth(x:number,y:number):number}

/** Apply hull-aware clearance once at race initialization. Synchronize movement
 * aliases so the first solver step never treats this setup relocation as travel. */
export function prepareFleetSpawns(memory:EngineMemory,numeric:SpawnNumerics):void {
 const r=(address:number)=>memory.readI32(address),count=r(0x4da194);
 const parts=boatShapes(r(0x4da144)),size=radius(parts),water=new PreviewWater(readNativeTerrain(memory));
 const course=contactCourse(memory),line=course.finish;
 const side=(p:{x:number;y:number})=>(line.b.x-line.a.x)*(p.y-line.a.y)-(line.b.y-line.a.y)*(p.x-line.a.x);
 const limit=Math.max(r(0x4da1fc),r(0x5363b8)===1?memory.readF64(0x4cc728):Math.trunc(r(0x4da190)/2)+3);
 const boats=Array.from({length:count},(_,index)=>{const id=index+1;return {key:'boat-'+id,parts,radius:size,pose:{x:memory.readF64(0x4f6af8+id*8),y:memory.readF64(0x4f6c10+id*8),heading:r(0x535740+id*4)}};});
 const before=new Map(boats.map(boat=>[boat.key,boat.pose]));
 const placed=clearFleetLayout({boats,obstacles:obstacles(course),safe:body=>{
  const original=before.get(body.key)!;
  if(r(0x4f8cd0)<0&&side(original)*side(body.pose)<0)return false;
  if(!water.safe(body.pose,body.radius+1)||numeric.depth(body.pose.x,body.pose.y)<=limit+2)return false;
  return body.parts.every(part=>part.kind==='circle'||world(part.points,body.pose).every(p=>numeric.depth(p.x,p.y)>limit+1));
 }});
 for(let index=0;index<count;index++){
  const id=index+1,pose=placed[index].pose,old=boats[index].pose;
  if(pose.x===old.x&&pose.y===old.y)continue;
  for(const base of[0x4f6af8,0x4f1610,0x4f83c0])memory.writeF64(base+id*8,pose.x);
  for(const base of[0x4f6c10,0x4f3868,0x4fb090])memory.writeF64(base+id*8,pose.y);
  memory.writeI32(0x513480+id*4,Math.trunc(pose.x));memory.writeI32(0x513510+id*4,Math.trunc(pose.y));
  memory.writeF64(0x4ffcb8+id*8,numeric.depth(pose.x,pose.y));
 }
}
