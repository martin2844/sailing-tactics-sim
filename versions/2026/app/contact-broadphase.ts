import {CONTACT_SKIN,angleDelta,type Shape} from './contact-geometry.ts';
import type {Motion} from './contact-solver.ts';
interface Enclosure {radius:number;padding:number;minEdge:number}
const enclosures=new WeakMap<Shape[],Enclosure>();
// The existing subdivision fallback can hold an unresolved5mm interval. Its
// prediction must remain possible too, not just exact skin intersections.
const predictionSkin=CONTACT_SKIN+.005;
/** Enclose the polygon SAT skin as well as its vertices. Expanding every
 * supporting plane by skin moves a corner at most skin/secant(normal gap/2).
 * Angular/numerical slack makes the bound conservative; degenerate hulls fall
 * back to the existing solver. Catalog shape arrays are immutable. */
function enclosure(parts:Shape[]):Enclosure {
 let cached=enclosures.get(parts);if(cached)return cached;
 let radius=0,padding=predictionSkin,minEdge=Infinity;
 for(const part of parts){
  if(part.kind==='circle'){if(part.radius<0||!Number.isFinite(part.radius)){padding=Infinity;break;}radius=Math.max(radius,part.radius);continue;}
  if(part.points.length<3){padding=Infinity;break;}
  const angles:number[]=[];
  for(let n=0;n<part.points.length;n++){
   const p=part.points[n],q=part.points[(n+1)%part.points.length],dx=q.x-p.x,dy=q.y-p.y;
   radius=Math.max(radius,Math.hypot(p.x,p.y));minEdge=Math.min(minEdge,Math.hypot(dx,dy));
   const angle=(Math.atan2(dx,-dy)+Math.PI*2)%(Math.PI*2);angles.push(angle,(angle+Math.PI)%(Math.PI*2));
  }
  angles.sort((a,b)=>a-b);let gap=0;
  for(let n=0;n<angles.length;n++)gap=Math.max(gap,(angles[(n+1)%angles.length]+(n===angles.length-1?Math.PI*2:0))-angles[n]);
  padding=Math.max(padding,gap+.001>=Math.PI?Infinity:predictionSkin/Math.cos((gap+.001)/2)*1.01);
 }
 cached={radius,padding,minEdge};enclosures.set(parts,cached);return cached;
}
/** Error allowance for translation-only separating planes. Very short edges,
 * extreme coordinates or rotations retain iterative testing. The allowance
 * covers endpoint arithmetic and axis changes from translated-vertex rounding. */
export function translationProjectionSlack(a:Motion,b:Motion):number|undefined {
 if(angleDelta(a.to.heading,a.pose.heading)!==0||angleDelta(b.to.heading,b.pose.heading)!==0)return;
 const values=[a.pose.x,a.pose.y,a.to.x,a.to.y,b.pose.x,b.pose.y,b.to.x,b.to.y];if(values.some(v=>!Number.isFinite(v)))return;
 const scale=Math.max(1,...values.map(Math.abs)),aa=enclosure(a.parts),bb=enclosure(b.parts),edge=Math.min(aa.minEdge,bb.minEdge);
 if(scale>1e8||!Number.isFinite(aa.padding+bb.padding)||edge<=scale*Number.EPSILON*1e6)return;
 const travel=Math.hypot(a.to.x-a.pose.x,a.to.y-a.pose.y)+Math.hypot(b.to.x-b.pose.x,b.to.y-b.pose.y);
 return 1e-6+scale*Number.EPSILON*4096*(1+(aa.radius+bb.radius+travel)/edge);
}
/** Reject only translation-only predictions whose enclosing circles never
 * approach. Actual contacts, rotations and uncertain bounds use the same SAT
 * advancement/normal/time calculation as before. */
export function separatedTranslation(a:Motion,b:Motion):boolean {
 if(angleDelta(a.to.heading,a.pose.heading)!==0||angleDelta(b.to.heading,b.pose.heading)!==0)return false;
 const values=[a.pose.x,a.pose.y,a.to.x,a.to.y,b.pose.x,b.pose.y,b.to.x,b.to.y];
 if(values.some(v=>!Number.isFinite(v)))return false;
 const scale=Math.max(1,...values.map(Math.abs));if(scale>1e8)return false;
 const aa=enclosure(a.parts),bb=enclosure(b.parts),radius=aa.radius+bb.radius+aa.padding+bb.padding;
 if(!Number.isFinite(radius)||Math.min(aa.minEdge,bb.minEdge)<=scale*Number.EPSILON*1e6)return false;
 const x=b.pose.x-a.pose.x,y=b.pose.y-a.pose.y,vx=(b.to.x-b.pose.x)-(a.to.x-a.pose.x),vy=(b.to.y-b.pose.y)-(a.to.y-a.pose.y),speedSquared=vx*vx+vy*vy;
 const t=speedSquared?Math.max(0,Math.min(1,-(x*vx+y*vy)/speedSquared)):0;
 const closest=Math.hypot(x+vx*t,y+vy*t),slack=1e-6+scale*Number.EPSILON*4096;
 return closest>radius+slack;
}
