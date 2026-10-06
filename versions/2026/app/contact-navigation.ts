import{boatShapes,radius,obstacles}from'./contact-shapes.ts';
import{contactCourse}from'./contact-world.ts';
import{sweep,type Motion}from'./contact-solver.ts';
import{angleDelta,type Point}from'./contact-geometry.ts';
const wrap=(angle:number)=>(angle%360+360)%360;
/** A short-range clearance layer. Native AI still chooses tactics and race
 * targets; this only avoids rigid contacts along the intended sailing path. */
export class ContactNavigator {
 readonly active=new Set<number>();
 constructor(private waterClear?:(a:Point,b:Point)=>boolean){}
 steer(m:any,id:number){
  this.active.delete(id);const i=(a:number)=>m.readI32(a),d=(a:number)=>m.readF64(a),w=(a:number,v:number)=>m.writeI32(a,v);
  if(id<=i(0x4da140)||i(0x4fe638+id*4)>0)return;
  const parts=boatShapes(i(0x4da144)),r=radius(parts),start={x:d(0x4f6af8+id*8),y:d(0x4f6c10+id*8)},heading=i(0x535740+id*4),wind=i(0x522b90+id*4),close=Math.max(38,i(0x4f7200));
  const look=Math.max(32,r*3),speed=Math.max(1,i(0x4fc230+id*4)/10),horizon=Math.min(30,look/(speed*.4));
  const fixed=obstacles(contactCourse(m)).filter(b=>Math.hypot(b.pose.x-start.x,b.pose.y-start.y)<look+r+b.radius+5);
  const neighbors:Motion[]=[];for(let other=1;other<=i(0x4da194);other++){if(other===id)continue;const pose={x:d(0x4f6af8+other*8),y:d(0x4f6c10+other*8),heading:i(0x535740+other*4)};if(Math.hypot(pose.x-start.x,pose.y-start.y)>look*2+r*2)continue;const distance=i(0x4fe638+other*4)>0?0:i(0x4fc230+other*4)/10*.4*horizon,angle=pose.heading*Math.PI/180;neighbors.push({key:'boat-'+other,parts,radius:r,pose,to:{x:pose.x+Math.sin(angle)*distance,y:pose.y-Math.cos(angle)*distance,heading:pose.heading}});}
  if(!fixed.length&&!neighbors.length)return;
  const risk=(angle:number)=>{
   const radians=angle*Math.PI/180,to={x:start.x+Math.sin(radians)*look,y:start.y-Math.cos(radians)*look,heading:angle};
   if(this.waterClear&&!this.waterClear(start,to))return {time:0,water:false};
   const candidate:Motion={key:'boat-'+id,parts,radius:r,pose:{...start,heading:angle},to};let time=1;
   for(const b of fixed){const hit=sweep(candidate,{...b,to:b.pose});if(hit)time=Math.min(time,hit.time);}
   for(const b of neighbors){const hit=sweep(candidate,b);if(hit)time=Math.min(time,hit.time);}
   return {time,water:true};
  };
  const original=risk(heading);if(original.time>.55)return;
  const target={x:i(0x4f4d78+id*4),y:i(0x4fc350+id*4)},bearing=wrap(Math.atan2(target.x-start.x,start.y-target.y)*180/Math.PI);
  const candidates=[heading,bearing,wrap(wind+close+5),wrap(wind-close-5)];for(const delta of[-90,-60,-45,-30,-20,-10,10,20,30,45,60,90])candidates.push(wrap(heading+delta));
  const evaluated=candidates.filter(h=>Math.abs(angleDelta(h,wind))>=close).map(h=>({h,...risk(h)})).filter(v=>v.water);
  evaluated.sort((a,b)=>(b.time-a.time)*180+Math.abs(angleDelta(a.h,bearing))-Math.abs(angleDelta(b.h,bearing))+.2*(Math.abs(angleDelta(a.h,heading))-Math.abs(angleDelta(b.h,heading))));
  const best=evaluated[0];if(!best||best.time<=original.time+.05)return;
  const change=angleDelta(best.h,heading),gentle=wrap(Math.round(heading+Math.max(-5,Math.min(5,change)))),next=risk(gentle).time>.2?gentle:Math.round(best.h),relative=angleDelta(next,wind),tack=relative>0?-1:1;
  if(i(0x522ff0+id*4)!==tack)w(0x4f4350+id*4,i(0x4f8cd0));w(0x535740+id*4,wrap(next));w(0x522ff0+id*4,tack);w(0x4fecc8+id*4,Math.abs(Math.round(relative)));this.active.add(id);
 }
}
