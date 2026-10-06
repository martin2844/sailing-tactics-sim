import type {NativeTerrain} from './native-environment';
import type {CoursePoint as Point} from './protocol';
import {insidePolygon,coastDistance,clearWaterSegment,distance} from './coast-geometry.ts';
const wrap=(a:number)=>(a%360+360)%360;
const delta=(a:number,b:number)=>((a-b+540)%360)-180;
/** A 2026 shore-avoidance layer around the original sailing AI. Route points
 * are navigation aids only: original leg targets, finish tests and sailing
 * dynamics remain authoritative. No private waypoint advances a race leg. */
export class IslandNavigator {
 readonly polygons:Point[][];readonly nodes:Point[]=[];private edges:{to:number;cost:number}[][]=[];
 readonly active=new Set<number>();private routes=new Map<number,{goal:Point;points:Point[];clock:number;escape?:Point}>();
 private depth:(p:Point)=>number;private groundingDepth:number;
 readonly margin=75;
 constructor(terrain:NativeTerrain,depth:(p:Point)=>number,groundingDepth:number){
  this.depth=depth;this.groundingDepth=groundingDepth;
  this.polygons=terrain.polygons.filter(p=>p.landInside).map(p=>p.points);
  for(const polygon of this.polygons){
   const center={x:polygon.reduce((s,p)=>s+p.x,0)/polygon.length,y:polygon.reduce((s,p)=>s+p.y,0)/polygon.length};
   for(let i=0;i<polygon.length;i+=Math.ceil(polygon.length/14)){
    const p=polygon[i],length=distance(p,center);if(!length)continue;
    for(let scale=2;scale<=10;scale++){
     const q={x:p.x+(p.x-center.x)/length*this.margin*scale,y:p.y+(p.y-center.y)/length*this.margin*scale};
     if(this.safe(q)){this.nodes.push(q);break;}
    }
   }
  }
  // A union of overlapping native venue islands can hide every local corner
  // on one side. Offshore bounding corners keep the visibility graph connected.
  const all=this.polygons.flat(),minX=Math.min(...all.map(p=>p.x)),maxX=Math.max(...all.map(p=>p.x)),minY=Math.min(...all.map(p=>p.y)),maxY=Math.max(...all.map(p=>p.y));
  for(const x of[minX-this.margin*5,maxX+this.margin*5])for(const y of[minY-this.margin*5,maxY+this.margin*5])if(this.safe({x,y}))this.nodes.push({x,y});
  if(this.nodes.length>128)this.nodes.splice(128);
  this.edges=this.nodes.map(()=>[]);
  for(let a=0;a<this.nodes.length;a++)for(let b=a+1;b<this.nodes.length;b++)if(this.clear(this.nodes[a],this.nodes[b])){
   const cost=distance(this.nodes[a],this.nodes[b]);this.edges[a].push({to:b,cost});this.edges[b].push({to:a,cost});
  }
 }
 safe(p:Point){return !this.polygons.some(poly=>insidePolygon(p,poly))&&coastDistance(p,this.polygons)>=this.margin&&this.depth(p)>this.groundingDepth+4;}
 clear(a:Point,b:Point){return clearWaterSegment(a,b,this.polygons,this.margin);}
 nearestWater(p:Point){
  if(this.safe(p))return p;
  let best:Point|undefined;
  for(let radius=50;radius<=3000&&!best;radius+=50)for(let angle=0;angle<360;angle+=15){
   const q={x:p.x+Math.sin(angle*Math.PI/180)*radius,y:p.y+Math.cos(angle*Math.PI/180)*radius};if(this.safe(q)&&(!best||distance(q,p)<distance(best,p)))best=q;
  }
  if(!best)throw Error('Island navigation could not find safe water');return {x:Math.round(best.x),y:Math.round(best.y)};
 }
 route(start:Point,goal:Point):Point[]{
  if(this.clear(start,goal))return [];
  const n=this.nodes.length,nodes=[...this.nodes,start,goal],edges=this.edges.map(e=>e.slice());edges.push([],[]);
  for(let i=0;i<n;i++)for(const extra of[n,n+1])if(this.clear(nodes[i],nodes[extra])){const cost=distance(nodes[i],nodes[extra]);edges[i].push({to:extra,cost});edges[extra].push({to:i,cost});}
  const costs=nodes.map(()=>Infinity),previous=nodes.map(()=>-1),done=new Set<number>();costs[n]=0;
  for(let count=0;count<nodes.length;count++){
   let next=-1;for(let i=0;i<nodes.length;i++)if(!done.has(i)&&(next<0||costs[i]<costs[next]))next=i;
   if(next<0||!Number.isFinite(costs[next]))break;if(next===n+1)break;done.add(next);
   for(const edge of edges[next])if(costs[next]+edge.cost<costs[edge.to]){costs[edge.to]=costs[next]+edge.cost;previous[edge.to]=next;}
  }
  if(previous[n+1]<0)return [];
  const result:Point[]=[];for(let at=n+1;at!==n;at=previous[at])result.unshift(nodes[at]);return result;
 }
 steer(memory:{readI32:(a:number)=>number;readF64:(a:number)=>number;writeI32:(a:number,v:number)=>void},id:number){
  const i=(a:number)=>memory.readI32(a),d=(a:number)=>memory.readF64(a),w=(a:number,v:number)=>memory.writeI32(a,v),clock=i(0x4f8cd0);
  this.active.delete(id);
  if(id<=i(0x4da140)||clock<0||i(0x4fe638+id*4)>0)return;
  const start={x:d(0x4f6af8+id*8),y:d(0x4f6c10+id*8)},goal={x:i(0x4f4d78+id*4),y:i(0x4fc350+id*4)},heading=i(0x535740+id*4),look=140;
  const step=(h:number)=>({x:start.x+Math.sin(h*Math.PI/180)*look,y:start.y-Math.cos(h*Math.PI/180)*look});
  const nearCoast=coastDistance(start,this.polygons)<this.margin||this.polygons.some(p=>insidePolygon(start,p));
  if(!nearCoast&&this.clear(start,goal)&&this.clear(start,step(heading))){this.routes.delete(id);return;}
  let route=this.routes.get(id);
  if(!route||distance(route.goal,goal)>1||clock-route.clock>8){route={goal,points:this.route(start,goal),clock};this.routes.set(id,route);}
  while(route.points.length&&distance(start,route.points[0])<85)route.points.shift();
  // Shortcut only if the complete buffered coast remains clear.
  while(route.points.length>1&&this.clear(start,route.points[1]))route.points.shift();
  if(nearCoast&&(!route.escape||distance(start,route.escape)<85))route.escape=this.nearestWater(start);
  const aim=nearCoast?route.escape!:route.points[0]??goal,bearing=wrap(Math.atan2(aim.x-start.x,start.y-aim.y)*180/Math.PI),wind=i(0x522b90+id*4),close=Math.max(45,i(0x4f7200)+5);
  const candidates=[bearing,wrap(wind+close),wrap(wind-close)];for(let angle=0;angle<360;angle+=15)candidates.push(angle);
  const safe=candidates.filter(h=>Math.abs(delta(h,wind))>=close&&(nearCoast?coastDistance(step(h),this.polygons)>coastDistance(start,this.polygons)&&!this.polygons.some(p=>insidePolygon(step(h),p)):this.clear(start,step(h))));
  if(!safe.length)return;
  safe.sort((a,b)=>Math.abs(delta(a,bearing))-Math.abs(delta(b,bearing))+.08*(Math.abs(delta(a,heading))-Math.abs(delta(b,heading))));
  const desired=safe[0],change=delta(desired,heading),next=wrap(Math.round(heading+Math.max(-8,Math.min(8,change))));
  // If a gradual turn still points ashore, use the safe heading immediately.
  const result=this.clear(start,step(next))?next:Math.round(desired),relative=delta(result,wind),tack=relative>0?-1:1;
  if(i(0x522ff0+id*4)!==tack)w(0x4f4350+id*4,clock);
  w(0x535740+id*4,wrap(result));w(0x522ff0+id*4,tack);w(0x4fecc8+id*4,Math.abs(relative));this.active.add(id);
 }
}
