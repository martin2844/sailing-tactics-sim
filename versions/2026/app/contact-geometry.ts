export interface Point {x:number;y:number}
export interface Pose extends Point {heading:number}
export type Shape={kind:'polygon';points:Point[]}|{kind:'circle';radius:number};
export interface Body {key:string;pose:Pose;parts:Shape[];radius:number}
export interface Separation {gap:number;normal:Point}
export const CONTACT_SKIN=.04;
export const dot=(a:Point,b:Point)=>a.x*b.x+a.y*b.y;
export const distance=(a:Point,b:Point)=>Math.hypot(a.x-b.x,a.y-b.y);
export const angleDelta=(a:number,b:number)=>((a-b+540)%360)-180;
export function hull(points:Point[]):Point[]{
 const sorted=[...new Map(points.map(p=>[p.x+','+p.y,p])).values()].sort((a,b)=>a.x-b.x||a.y-b.y);
 const cross=(o:Point,a:Point,b:Point)=>(a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x),lo:Point[]=[],hi:Point[]=[];
 for(const p of sorted){while(lo.length>1&&cross(lo.at(-2)!,lo.at(-1)!,p)<=0)lo.pop();lo.push(p);}
 for(const p of sorted.slice().reverse()){while(hi.length>1&&cross(hi.at(-2)!,hi.at(-1)!,p)<=0)hi.pop();hi.push(p);}lo.pop();hi.pop();return lo.concat(hi);
}
export function area(points:Point[]){return Math.abs(points.reduce((sum,p,i)=>{const q=points[(i+1)%points.length];return sum+p.x*q.y-q.x*p.y;},0))/2;}
export function world(points:Point[],pose:Pose){const a=pose.heading*Math.PI/180,c=Math.cos(a),s=Math.sin(a);return points.map(p=>({x:pose.x+p.x*c-p.y*s,y:pose.y+p.x*s+p.y*c}));}
export type AxisNormalizer=(dx:number,dy:number)=>Point;
const normalizedAxis:AxisNormalizer=(dx,dy)=>{const n=Math.hypot(dx,dy);return {x:-dy/n,y:dx/n};};
function axes(points:Point[],normalize:AxisNormalizer){return points.map((p,i)=>{const q=points[(i+1)%points.length];return normalize(q.x-p.x,q.y-p.y);});}
function project(points:Point[],axis:Point){let min=Infinity,max=-Infinity;for(const point of points){const value=dot(point,axis);min=Math.min(min,value);max=Math.max(max,value);}return {min,max};}
export interface PreparedShape {shape:Shape;pose:Pose;points:Point[];directions:Point[];projections?:WeakMap<Point,{min:number;max:number}>}
/** Prepared geometry is scoped to an immutable pose, not retained across
 * integration/response updates. Transform arithmetic and axis order are exact. */
export function prepareShape(shape:Shape,pose:Pose,normalize:AxisNormalizer=normalizedAxis):PreparedShape {
 const points=shape.kind==='polygon'?world(shape.points,pose):[];
 return {shape,pose,points,directions:axes(points,normalize)};
}
export function shapeSeparation(a:Shape,ap:Pose,b:Shape,bp:Pose):Separation {
 return preparedShapeSeparation(prepareShape(a,ap),prepareShape(b,bp));
}
export function preparedProjection(prepared:PreparedShape,axis:Point):{min:number;max:number} {
 const cached=prepared.projections?.get(axis);if(cached)return cached;
 const shape=prepared.shape,pose=prepared.pose,result=shape.kind==='circle'?{min:dot(pose,axis)-shape.radius,max:dot(pose,axis)+shape.radius}:project(prepared.points,axis);
 prepared.projections?.set(axis,result);return result;
}
export function preparedShapeSeparation(aa:PreparedShape,bb:PreparedShape):Separation {
 const a=aa.shape,ap=aa.pose,b=bb.shape,bp=bb.pose;
 if(a.kind==='circle'&&b.kind==='circle'){const dx=bp.x-ap.x,dy=bp.y-ap.y,d=Math.hypot(dx,dy);return {gap:d-a.radius-b.radius,normal:d?{x:dx/d,y:dy/d}:{x:1,y:0}};}
 if(!aa.projections&&!bb.projections)return scratchSeparation(aa,bb);
 const av=aa.points,bv=bb.points,directions=[...aa.directions,...bb.directions];
 if(a.kind==='circle'||b.kind==='circle'){
  const center=a.kind==='circle'?ap:bp,vertices=a.kind==='circle'?bv:av;
  const nearest=vertices.reduce((p,q)=>distance(p,center)<distance(q,center)?p:q),dx=nearest.x-center.x,dy=nearest.y-center.y,d=Math.hypot(dx,dy);if(d)directions.push({x:dx/d,y:dy/d});
 }
 let best:Separation={gap:-Infinity,normal:{x:1,y:0}};
 for(const axis of directions){const aInterval=preparedProjection(aa,axis),bInterval=preparedProjection(bb,axis),forward=bInterval.min-aInterval.max,backward=aInterval.min-bInterval.max,gap=Math.max(forward,backward);if(gap>best.gap)best={gap,normal:forward>=backward?axis:{x:-axis.x,y:-axis.y}};}
 return best;
}
/** Dynamic sweep iterations have no reusable projection cache. Keep minima,
 * maxima and the winning normal in scalar locals instead of allocating two
 * interval objects per axis and a new result for every improving axis. */
function scratchSeparation(aa:PreparedShape,bb:PreparedShape):Separation {
 const a=aa.shape,b=bb.shape,av=aa.points,bv=bb.points;let extra:Point|undefined;
 if(a.kind==='circle'||b.kind==='circle'){
  const center=a.kind==='circle'?aa.pose:bb.pose,vertices=a.kind==='circle'?bv:av;
  const nearest=vertices.reduce((p,q)=>distance(p,center)<distance(q,center)?p:q),dx=nearest.x-center.x,dy=nearest.y-center.y,length=Math.hypot(dx,dy);if(length)extra={x:dx/length,y:dy/length};
 }
 let gap=-Infinity,nx=1,ny=0;
 const ac=aa.directions.length,bc=bb.directions.length;
 for(let n=0;n<ac+bc+(extra?1:0);n++){
  const axis=n<ac?aa.directions[n]:n<ac+bc?bb.directions[n-ac]:extra!;
  let amin=Infinity,amax=-Infinity,bmin=Infinity,bmax=-Infinity;
  if(a.kind==='circle'){const value=dot(aa.pose,axis);amin=value-a.radius;amax=value+a.radius;}
  else for(const p of av){const value=dot(p,axis);amin=Math.min(amin,value);amax=Math.max(amax,value);}
  if(b.kind==='circle'){const value=dot(bb.pose,axis);bmin=value-b.radius;bmax=value+b.radius;}
  else for(const p of bv){const value=dot(p,axis);bmin=Math.min(bmin,value);bmax=Math.max(bmax,value);}
  const forward=bmin-amax,backward=amin-bmax,next=Math.max(forward,backward);
  if(next>gap){gap=next;nx=forward>=backward?axis.x:-axis.x;ny=forward>=backward?axis.y:-axis.y;}
 }
 return {gap,normal:{x:nx,y:ny}};
}
export function separation(a:Body,b:Body):Separation {let result:Separation={gap:Infinity,normal:{x:1,y:0}};for(const aa of a.parts)for(const bb of b.parts){const next=shapeSeparation(aa,a.pose,bb,b.pose);if(next.gap<result.gap)result=next;}return result;}
export function interpolate(a:Pose,b:Pose,t:number):Pose{return {x:a.x+(b.x-a.x)*t,y:a.y+(b.y-a.y)*t,heading:a.heading+angleDelta(b.heading,a.heading)*t};}
