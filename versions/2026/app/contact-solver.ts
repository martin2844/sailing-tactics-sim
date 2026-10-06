import {CONTACT_SKIN,shapeSeparation,separation,interpolate,angleDelta,distance,dot,type Body,type Pose,type Point} from './contact-geometry.ts';
export interface Motion extends Body {to:Pose;human?:boolean;fixed?:boolean}
export interface Contact {a:string;b:string;time:number;normal:Point;initial:boolean;poseA:Pose;poseB:Pose}
export interface SweptContact {time:number;normal:Point}
const localBounds=new WeakMap<Body['parts'],{minX:number;maxX:number;minY:number;maxY:number}>();
function bounds(m:Motion){
 let local=localBounds.get(m.parts);if(!local){const points=m.parts.flatMap(s=>s.kind==='circle'?[{x:-s.radius,y:-s.radius},{x:s.radius,y:s.radius}]:s.points);local={minX:Math.min(...points.map(p=>p.x)),maxX:Math.max(...points.map(p=>p.x)),minY:Math.min(...points.map(p=>p.y)),maxY:Math.max(...points.map(p=>p.y))};localBounds.set(m.parts,local);}
 let minX=Infinity,maxX=-Infinity,minY=Infinity,maxY=-Infinity;
 for(const pose of[m.pose,m.to]){const angle=pose.heading*Math.PI/180,c=Math.cos(angle),s=Math.sin(angle);for(const x of[local.minX,local.maxX])for(const y of[local.minY,local.maxY]){const px=pose.x+x*c-y*s,py=pose.y+x*s+y*c;minX=Math.min(minX,px);maxX=Math.max(maxX,px);minY=Math.min(minY,py);maxY=Math.max(maxY,py);}}
 // Every intermediate rotated vertex lies within half the swept angular arc
 // of an endpoint. This bound is conservative for translation plus rotation.
 const padding=m.radius*Math.abs(angleDelta(m.to.heading,m.pose.heading))*Math.PI/360;
 return {minX:minX-padding,maxX:maxX+padding,minY:minY-padding,maxY:maxY+padding};
}
export function sweep(a:Motion,b:Motion):SweptContact|null{
 const ab=bounds(a),bb=bounds(b);if(ab.maxX+CONTACT_SKIN<bb.minX||bb.maxX+CONTACT_SKIN<ab.minX||ab.maxY+CONTACT_SKIN<bb.minY||bb.maxY+CONTACT_SKIN<ab.minY)return null;
 const da={x:a.to.x-a.pose.x,y:a.to.y-a.pose.y},db={x:b.to.x-b.pose.x,y:b.to.y-b.pose.y},rotationA=angleDelta(a.to.heading,a.pose.heading)*Math.PI/180,rotationB=angleDelta(b.to.heading,b.pose.heading)*Math.PI/180;
 const speed=Math.hypot(da.x-db.x,da.y-db.y)+Math.abs(rotationA)*a.radius+Math.abs(rotationB)*b.radius;
 let best:SweptContact|null=null;
 for(const aa of a.parts)for(const bs of b.parts){
  const at=(t:number)=>shapeSeparation(aa,interpolate(a.pose,a.to,t),bs,interpolate(b.pose,b.to,t));
  const initial=at(0);if(initial.gap<=CONTACT_SKIN&&Math.abs(rotationA)+Math.abs(rotationB)<1e-10&&dot({x:da.x-db.x,y:da.y-db.y},initial.normal)<=1e-9)continue;
  let t=0,leaving=false;
  if(initial.gap<=CONTACT_SKIN&&speed>0){const probe=at(Math.min(1,.01/speed));leaving=probe.gap>initial.gap+1e-7;}
  for(let n=0;n<128;n++){
   const hit=at(t);
   if(hit.gap<=CONTACT_SKIN&&!leaving){if(!best||t<best.time)best={time:t,normal:hit.normal};break;}
   if(speed<1e-10||t>=1||best&&t>=best.time)break;
   if(leaving&&hit.gap>CONTACT_SKIN)leaving=false;
   const step=leaving?.05/speed:Math.max(1e-8,(hit.gap-CONTACT_SKIN*.5)*.9/speed);t=Math.min(1,t+step);
  }
 }return best;
}
/** Equal-mass, non-bouncing hull contact with tangential sliding. Initial
 * placement overlap is resolved separately and does not constitute a foul. */
export function solveMotions(input:Motion[],obstacles:Body[]){
 const bodies=input.map(m=>({...m,pose:{...m.pose},to:{...m.to},velocity:{x:m.fixed?0:m.to.x-m.pose.x,y:m.fixed?0:m.to.y-m.pose.y},angular:m.fixed?0:angleDelta(m.to.heading,m.pose.heading)}));
 const fixed=obstacles.map(b=>({...b,pose:{...b.pose},to:{...b.pose},velocity:{x:0,y:0},angular:0,fixed:true,human:false}));
 const all=[...bodies,...fixed],contacts=new Map<string,Contact>();let initialIterations=0,iterations=0;
 const record=(a:typeof all[number],b:typeof all[number],time:number,normal:Point,initial:boolean)=>{const key=[a.key,b.key].sort().join(':');if(!contacts.has(key))contacts.set(key,{a:a.key,b:b.key,time,normal,initial,poseA:{...a.pose},poseB:{...b.pose}});};
 const weights=(a:typeof all[number],b:typeof all[number],initial=false)=>{let wa=a.fixed?0:1,wb=b.fixed?0:1;if(initial&&wa&&wb&&a.human!==b.human){if(a.human)wa=0;else wb=0;}const total=wa+wb;return {a:wa/total,b:wb/total};};
 for(let pass=0;pass<48;pass++){
  let changed=false;
  for(let i=0;i<all.length;i++)for(let j=i+1;j<all.length;j++){
   const a=all[i],b=all[j];if(a.fixed&&b.fixed||distance(a.pose,b.pose)>a.radius+b.radius)continue;
   const hit=separation(a,b);if(hit.gap>=-.005)continue;const w=weights(a,b,true),amount=-hit.gap+CONTACT_SKIN;
   record(a,b,0,hit.normal,true);for(const[m,sign,weight]of[[a,-1,w.a],[b,1,w.b]] as const){const dx=hit.normal.x*amount*weight*sign,dy=hit.normal.y*amount*weight*sign;m.pose.x+=dx;m.pose.y+=dy;m.to.x+=dx;m.to.y+=dy;}
   changed=true;initialIterations++;
  }if(!changed)break;
 }
 let time=0;
 for(;iterations<96&&time<1;iterations++){
  let next:{a:typeof all[number];b:typeof all[number];hit:SweptContact}|undefined;
  for(let i=0;i<all.length;i++)for(let j=i+1;j<all.length;j++){
   const a=all[i],b=all[j];if(a.fixed&&b.fixed)continue;
   a.to={x:a.pose.x+a.velocity.x*(1-time),y:a.pose.y+a.velocity.y*(1-time),heading:a.pose.heading+a.angular*(1-time)};
   b.to={x:b.pose.x+b.velocity.x*(1-time),y:b.pose.y+b.velocity.y*(1-time),heading:b.pose.heading+b.angular*(1-time)};
   const hit=sweep(a,b);if(hit&&(!next||hit.time<next.hit.time))next={a,b,hit};
  }
  const dt=(next?next.hit.time:1)*(1-time);for(const m of bodies){m.pose.x+=m.velocity.x*dt;m.pose.y+=m.velocity.y*dt;m.pose.heading+=m.angular*dt;}time+=dt;if(!next)break;
  const {a,b,hit}=next,w=weights(a,b);record(a,b,time,hit.normal,false);
  const closing=dot({x:a.velocity.x-b.velocity.x,y:a.velocity.y-b.velocity.y},hit.normal);
  if(closing>0){a.velocity.x-=hit.normal.x*closing*w.a;a.velocity.y-=hit.normal.y*closing*w.a;b.velocity.x+=hit.normal.x*closing*w.b;b.velocity.y+=hit.normal.y*closing*w.b;}
  // Prevent rotation through a hull/mark during the remainder of this step.
  a.angular=0;b.angular=0;
  const amount=Math.max(0,CONTACT_SKIN-separation(a,b).gap)+.001;
  a.pose.x-=hit.normal.x*amount*w.a;a.pose.y-=hit.normal.y*amount*w.a;b.pose.x+=hit.normal.x*amount*w.b;b.pose.y+=hit.normal.y*amount*w.b;
 }
 // If a dense corner exhausts the bounded solver, remaining movement stays
 // held rather than advancing unchecked through geometry.
 return {poses:new Map(bodies.map(m=>[m.key,m.pose])),contacts:[...contacts.values()],iterations,initialIterations,held:time<1};
}
