import {CONTACT_SKIN,shapeSeparation,prepareShape,preparedProjection,preparedShapeSeparation,separation,interpolate,angleDelta,distance,dot,type AxisNormalizer,type PreparedShape,type Body,type Pose,type Point} from './contact-geometry.ts';
import {separatedTranslation,translationProjectionSlack} from './contact-broadphase.ts';
export interface Motion extends Body {to:Pose;human?:boolean;fixed?:boolean}
export interface Contact {a:string;b:string;time:number;normal:Point;initial:boolean;uncertain?:boolean;poseA:Pose;poseB:Pose}
export interface SweptContact {time:number;normal:Point;uncertain?:boolean}
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
interface PreparedMotion {bounds:ReturnType<typeof bounds>;parts?:PreparedShape[];evaluate?:((t:number)=>PreparedShape)[]}
/** Reuse iteration scratch without changing any transform/normal arithmetic.
 * Returned scratch is internal; separation normals are copied before reuse. */
function shapeEvaluator(m:Motion,index:number,normalize:AxisNormalizer):(t:number)=>PreparedShape {
 const shape=m.parts[index],pose={...m.pose},points=shape.kind==='polygon'?shape.points.map(()=>({x:0,y:0})):[],directions=points.map(()=>({x:0,y:0}));
 const result:PreparedShape={shape,pose,points,directions},dx=m.to.x-m.pose.x,dy=m.to.y-m.pose.y,rotation=angleDelta(m.to.heading,m.pose.heading);
 const heading=interpolate(m.pose,m.to,0).heading,angle=heading*Math.PI/180,c=Math.cos(angle),s=Math.sin(angle);
 const products=shape.kind==='polygon'&&rotation===0?shape.points.map(p=>({xc:p.x*c,ys:p.y*s,xs:p.x*s,yc:p.y*c})):undefined;
 return t=>{
  pose.x=m.pose.x+dx*t;pose.y=m.pose.y+dy*t;pose.heading=m.pose.heading+rotation*t;
  if(shape.kind==='polygon'){
   const fixed=products&&Number.isFinite(t),a=pose.heading*Math.PI/180,cos=fixed?c:Math.cos(a),sin=fixed?s:Math.sin(a);
   for(let n=0;n<points.length;n++){
    const p=shape.points[n],q=points[n],v=products?.[n];
    q.x=fixed?pose.x+v!.xc-v!.ys:pose.x+p.x*cos-p.y*sin;
    q.y=fixed?pose.y+v!.xs+v!.yc:pose.y+p.x*sin+p.y*cos;
   }
   for(let n=0;n<points.length;n++){const p=points[n],q=points[(n+1)%points.length];directions[n]=normalize(q.x-p.x,q.y-p.y);}
  }return result;
 };
}
/** One query scope may reuse motions only while their poses, destinations and
 * shape arrays stay immutable. Contact resolution continues to use sweep(). */
export function createSweepQuery(){
 const cache=new WeakMap<Motion,PreparedMotion>();
 const axes=new Map<number|string,Map<number|string,Point>>();let entries=0;
 const key=(value:number):number|string=>value===0?(Object.is(value,-0)?'-0':'+0'):value;
 const normalize:AxisNormalizer=(dx,dy)=>{
  const x=key(dx),y=key(dy);let row=axes.get(x),axis=row?.get(y);if(axis)return axis;
  const n=Math.hypot(dx,dy);axis={x:-dy/n,y:dx/n};
  // Equal edge vectors produce exactly equal normals. Sharing their identity
  // also shares cached projections; no quantization/angle rounding is used.
  if(entries<8192){if(!row){row=new Map();axes.set(x,row);}row.set(y,axis);entries++;}return axis;
 };
 return (a:Motion,b:Motion)=>{if(separatedTranslation(a,b))return null;const hit=sweepMotion(a,b,cache,normalize);return hit?{...hit,normal:{...hit.normal}}:null;};
}
export function sweep(a:Motion,b:Motion):SweptContact|null{return sweepMotion(a,b);}
function sweepMotion(a:Motion,b:Motion,cache?:WeakMap<Motion,PreparedMotion>,normalize?:AxisNormalizer):SweptContact|null{
 const prepare=(m:Motion)=>{let item=cache?.get(m);if(!item){item={bounds:bounds(m)};cache?.set(m,item);}return item;};
 const am=prepare(a),bm=prepare(b),ab=am.bounds,bb=bm.bounds;if(ab.maxX+CONTACT_SKIN<bb.minX||bb.maxX+CONTACT_SKIN<ab.minX||ab.maxY+CONTACT_SKIN<bb.minY||bb.maxY+CONTACT_SKIN<ab.minY)return null;
 const initialParts=(m:Motion,item:PreparedMotion)=>item.parts??=(m.parts.map(part=>({...prepareShape(part,interpolate(m.pose,m.to,0),normalize),projections:new WeakMap()})));
 const atShape=(m:Motion,item:PreparedMotion,index:number,t:number)=>{
  if(t===0)return initialParts(m,item)[index];
  item.evaluate??=m.parts.map((_,n)=>shapeEvaluator(m,n,normalize!));return item.evaluate[index](t);
 };
 if(cache){
  const slack=translationProjectionSlack(a,b);
  if(slack!==undefined){
   const relative={x:(a.to.x-a.pose.x)-(b.to.x-b.pose.x),y:(a.to.y-a.pose.y)-(b.to.y-b.pose.y)},skin=CONTACT_SKIN+.005+slack;
   const clear=(aa:PreparedShape,bb:PreparedShape)=>{
    for(const directions of[aa.directions,bb.directions])for(const axis of directions){
     const ap=preparedProjection(aa,axis),bp=preparedProjection(bb,axis),along=dot(relative,axis),forward=bp.min-ap.max,backward=ap.min-bp.max;
     // A common separating plane at both endpoints separates the entire
     // linear trajectory. Near skin/work-cap uncertainty keeps the solver.
     if(Math.min(forward,forward-along)>skin||Math.min(backward,backward+along)>skin)return true;
    }return false;
   };
   if(initialParts(a,am).every(aa=>initialParts(b,bm).every(bb=>clear(aa,bb))))return null;
  }
 }
 const da={x:a.to.x-a.pose.x,y:a.to.y-a.pose.y},db={x:b.to.x-b.pose.x,y:b.to.y-b.pose.y},rotationA=angleDelta(a.to.heading,a.pose.heading)*Math.PI/180,rotationB=angleDelta(b.to.heading,b.pose.heading)*Math.PI/180;
 const translationSpeed=Math.hypot(da.x-db.x,da.y-db.y);
 let best:SweptContact|null=null;
 for(let ai=0;ai<a.parts.length;ai++)for(let bi=0;bi<b.parts.length;bi++){
  const aa=a.parts[ai],bs=b.parts[bi];
  const angularSpeed=(aa.kind==='circle'?0:Math.abs(rotationA)*a.radius)+(bs.kind==='circle'?0:Math.abs(rotationB)*b.radius),speed=translationSpeed+angularSpeed;
  const at=(t:number)=>{
   if(!cache)return shapeSeparation(aa,interpolate(a.pose,a.to,t),bs,interpolate(b.pose,b.to,t));
   const result=preparedShapeSeparation(atShape(a,am,ai,t),atShape(b,bm,bi,t));return {gap:result.gap,normal:{...result.normal}};
  };
  const initial=at(0);if(initial.gap<=CONTACT_SKIN&&angularSpeed<1e-10&&dot({x:da.x-db.x,y:da.y-db.y},initial.normal)<=1e-9)continue;
  let t=0,leaving=false,previousGap=initial.gap;
  if(initial.gap<=CONTACT_SKIN&&speed>0){const probe=at(Math.min(1,.01/speed));leaving=probe.gap>initial.gap+1e-7;}
  let completed=false;
  for(let n=0;n<128;n++){
   const hit=at(t);
   if(leaving&&hit.gap<previousGap-1e-8)leaving=false;
   previousGap=hit.gap;
   if(hit.gap<=CONTACT_SKIN&&!leaving){if(!best||t<best.time)best={time:t,normal:hit.normal};completed=true;break;}
   if(speed<1e-10||t>=1||best&&t>=best.time){completed=true;break;}
   if(leaving&&hit.gap>CONTACT_SKIN)leaving=false;
   const closing=Math.max(0,dot({x:da.x-db.x,y:da.y-db.y},hit.normal))+angularSpeed;
   const step=leaving?.05/speed:closing<1e-10?1:Math.max(1e-8,(hit.gap-CONTACT_SKIN*.5)*.9/closing);t=Math.min(1,t+step);
  }
  if(!completed){
   // A fixed separating plane bounds an entire time interval. Subdivision
   // finishes difficult grazing/rotation cases without treating a work cap as
   // clear space. The last unresolved interval holds movement, without a foul.
   const intervals:[number,number][]=[[t,best?.time??1]];let visited=0;
   while(intervals.length){const[lo,hi]=intervals.pop()!,mid=(lo+hi)/2,hit=at(mid),axisSpeed=Math.abs(dot({x:da.x-db.x,y:da.y-db.y},hit.normal))+angularSpeed;
    if(hit.gap>axisSpeed*(hi-lo)/2+CONTACT_SKIN)continue;
    if((hi-lo)*speed<.005){const candidate={time:lo,normal:hit.normal,uncertain:hit.gap>CONTACT_SKIN&&at(lo).gap>CONTACT_SKIN&&at(hi).gap>CONTACT_SKIN};if(!best||lo<best.time)best=candidate;break;}
    if(++visited>512){const candidate={time:lo,normal:at(lo).normal,uncertain:true};if(!best||lo<best.time)best=candidate;break;}
    intervals.push([mid,hi],[lo,mid]);
   }
  }
 }return best;
}
/** Equal-mass, non-bouncing hull contact with tangential sliding. Initial
 * placement overlap is resolved separately and does not constitute a foul. */
export function solveMotions(input:Motion[],obstacles:Body[]){
 const bodies=input.map(m=>({...m,pose:{...m.pose},to:{...m.to},velocity:{x:m.fixed?0:m.to.x-m.pose.x,y:m.fixed?0:m.to.y-m.pose.y},angular:m.fixed?0:angleDelta(m.to.heading,m.pose.heading)}));
 const fixed=obstacles.map(b=>({...b,pose:{...b.pose},to:{...b.pose},velocity:{x:0,y:0},angular:0,fixed:true,human:false}));
 const all=[...bodies,...fixed],contacts=new Map<string,Contact>();let initialIterations=0,iterations=0,placementFallback=false,uncertain=false;
 const record=(a:typeof all[number],b:typeof all[number],time:number,normal:Point,initial:boolean,uncertain=false)=>{const key=[a.key,b.key].sort().join(':');if(!contacts.has(key))contacts.set(key,{a:a.key,b:b.key,time,normal,initial,uncertain,poseA:{...a.pose},poseB:{...b.pose}});};
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
 let residual=false;for(let i=0;i<all.length;i++)for(let j=i+1;j<all.length;j++)if(!(all[i].fixed&&all[j].fixed)&&distance(all[i].pose,all[j].pose)<all[i].radius+all[j].radius&&separation(all[i],all[j]).gap<-.005)residual=true;
 if(residual){
  placementFallback=true;const placed=all.filter(b=>b.fixed),ordered=bodies.filter(b=>!b.fixed).slice().sort((a,b)=>Number(!!b.human)-Number(!!a.human));
  for(const b of ordered){const clear=(p:Pose)=>placed.every(other=>distance(p,other.pose)>b.radius+other.radius+.05||separation({...b,pose:p},other).gap>=.04);let pose:Pose|undefined=clear(b.pose)?b.pose:undefined;
   for(let ring=2;ring<=512&&!pose;ring+=2)for(let angle=0;angle<360;angle+=15){const candidate={...b.pose,x:b.pose.x+Math.cos(angle*Math.PI/180)*ring,y:b.pose.y+Math.sin(angle*Math.PI/180)*ring};if(clear(candidate)){pose=candidate;break;}}
   if(!pose){uncertain=true;continue;}const dx=pose.x-b.pose.x,dy=pose.y-b.pose.y;if(dx||dy){contacts.set(b.key+':spawn',{a:b.key,b:'spawn',time:0,normal:{x:0,y:0},initial:true,poseA:{...b.pose},poseB:{...pose}});b.pose={...pose};b.to.x+=dx;b.to.y+=dy;}placed.push(b);
  }
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
  const {a,b,hit}=next,w=weights(a,b);record(a,b,time,hit.normal,false,!!hit.uncertain);
  if(hit.uncertain){a.velocity={x:0,y:0};b.velocity={x:0,y:0};a.angular=0;b.angular=0;uncertain=true;continue;}
  const closing=dot({x:a.velocity.x-b.velocity.x,y:a.velocity.y-b.velocity.y},hit.normal);
  if(closing>0){a.velocity.x-=hit.normal.x*closing*w.a;a.velocity.y-=hit.normal.y*closing*w.a;b.velocity.x+=hit.normal.x*closing*w.b;b.velocity.y+=hit.normal.y*closing*w.b;}
  // Prevent rotation through a hull/mark during the remainder of this step.
  a.angular=0;b.angular=0;
  const amount=Math.max(0,CONTACT_SKIN-separation(a,b).gap)+.001;
  a.pose.x-=hit.normal.x*amount*w.a;a.pose.y-=hit.normal.y*amount*w.a;b.pose.x+=hit.normal.x*amount*w.b;b.pose.y+=hit.normal.y*amount*w.b;
 }
 // If a dense corner exhausts the bounded solver, remaining movement stays
 // held rather than advancing unchecked through geometry.
 return {poses:new Map(bodies.map(m=>[m.key,m.pose])),contacts:[...contacts.values()],iterations,initialIterations,placementFallback,held:time<1||uncertain};
}
