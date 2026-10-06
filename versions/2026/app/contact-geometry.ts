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
function axes(points:Point[]){return points.map((p,i)=>{const q=points[(i+1)%points.length],dx=q.x-p.x,dy=q.y-p.y,n=Math.hypot(dx,dy);return {x:-dy/n,y:dx/n};});}
function project(points:Point[],axis:Point){const values=points.map(p=>dot(p,axis));return {min:Math.min(...values),max:Math.max(...values)};}
export function shapeSeparation(a:Shape,ap:Pose,b:Shape,bp:Pose):Separation {
 if(a.kind==='circle'&&b.kind==='circle'){const dx=bp.x-ap.x,dy=bp.y-ap.y,d=Math.hypot(dx,dy);return {gap:d-a.radius-b.radius,normal:d?{x:dx/d,y:dy/d}:{x:1,y:0}};}
 const av=a.kind==='polygon'?world(a.points,ap):[],bv=b.kind==='polygon'?world(b.points,bp):[],directions=[...axes(av),...axes(bv)];
 if(a.kind==='circle'||b.kind==='circle'){
  const center=a.kind==='circle'?ap:bp,vertices=a.kind==='circle'?bv:av;
  const nearest=vertices.reduce((p,q)=>distance(p,center)<distance(q,center)?p:q),dx=nearest.x-center.x,dy=nearest.y-center.y,d=Math.hypot(dx,dy);if(d)directions.push({x:dx/d,y:dy/d});
 }
 let best:Separation={gap:-Infinity,normal:{x:1,y:0}};
 for(const axis of directions){const aa=a.kind==='circle'?{min:dot(ap,axis)-a.radius,max:dot(ap,axis)+a.radius}:project(av,axis),bb=b.kind==='circle'?{min:dot(bp,axis)-b.radius,max:dot(bp,axis)+b.radius}:project(bv,axis),forward=bb.min-aa.max,backward=aa.min-bb.max,gap=Math.max(forward,backward);if(gap>best.gap)best={gap,normal:forward>=backward?axis:{x:-axis.x,y:-axis.y}};}
 return best;
}
export function separation(a:Body,b:Body):Separation {let result:Separation={gap:Infinity,normal:{x:1,y:0}};for(const aa of a.parts)for(const bb of b.parts){const next=shapeSeparation(aa,a.pose,bb,b.pose);if(next.gap<result.gap)result=next;}return result;}
export function interpolate(a:Pose,b:Pose,t:number):Pose{return {x:a.x+(b.x-a.x)*t,y:a.y+(b.y-a.y)*t,heading:a.heading+angleDelta(b.heading,a.heading)*t};}
