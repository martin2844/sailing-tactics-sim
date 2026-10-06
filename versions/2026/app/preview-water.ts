import type {CoursePoint as Point,CourseLine} from './protocol';
import type {NativeTerrain} from './native-environment';
import {insidePolygon,pointSegmentDistance,segmentDistance,distance} from './coast-geometry.ts';
/** Presentation geometry only: bounded lakes and land islands both constrain water. */
export class PreviewWater {
 private edges:{a:Point;b:Point}[]=[];private nodes?:Point[];private visibility?:Uint8Array;
 readonly terrain:NativeTerrain;
 constructor(terrain:NativeTerrain){this.terrain=terrain;for(const polygon of terrain.polygons)for(let i=0;i<polygon.points.length;i++)this.edges.push({a:polygon.points[i],b:polygon.points[(i+1)%polygon.points.length]});}
 contains(p:Point){return this.terrain.polygons.every(poly=>poly.landInside?!insidePolygon(p,poly.points):insidePolygon(p,poly.points));}
 clearance(p:Point){return Math.min(Infinity,...this.edges.map(e=>pointSegmentDistance(p,e.a,e.b)));}
 safe(p:Point,margin=0){return this.contains(p)&&this.clearance(p)>margin;}
 clear(a:Point,b:Point,margin=0){return this.safe(a,margin)&&this.safe(b,margin)&&this.edges.every(e=>segmentDistance(a,b,e.a,e.b)>margin);}
 nearest(p:Point,margin=1):Point{
  if(this.safe(p,margin))return {...p};const candidates:Point[]=[];
  for(const {a,b}of this.edges){const x=b.x-a.x,y=b.y-a.y,l=x*x+y*y;if(!l)continue;const t=Math.max(0,Math.min(1,((p.x-a.x)*x+(p.y-a.y)*y)/l)),q={x:a.x+t*x,y:a.y+t*y},length=Math.sqrt(l);for(const sign of[-1,1])for(const factor of[1.1,2,4])candidates.push({x:q.x-sign*y/length*margin*factor,y:q.y+sign*x/length*margin*factor});}
  candidates.sort((a,b)=>distance(a,p)-distance(b,p));const found=candidates.find(q=>this.safe(q,margin));if(found)return found;
  // A margin may exceed the width of a narrow river. Keep the point in water;
  // its on-screen symbol will shrink to the available shoreline clearance.
  if(margin>1)return this.nearest(p,1);
  throw Error('No water available for the course sample');
 }
 line(line:CourseLine):CourseLine{
  if(this.clear(line.a,line.b,.1))return {a:{...line.a},b:{...line.b}};
  const midpoint={x:(line.a.x+line.b.x)/2,y:(line.a.y+line.b.y)/2},half={x:(line.b.x-line.a.x)/2,y:(line.b.y-line.a.y)/2};
  for(const margin of[distance(line.a,line.b)/2+10,50,10,1]){const center=this.nearest(midpoint,margin);for(const ratio of[1,.75,.5,.25,.1]){const a={x:center.x-half.x*ratio,y:center.y-half.y*ratio},b={x:center.x+half.x*ratio,y:center.y+half.y*ratio};if(this.clear(a,b,.1))return{a,b};}}
  const a=this.nearest(line.a),b=this.nearest(line.b);return this.clear(a,b)?{a,b}:{a,b:a};
 }
 rectangle(corners:Point[]){return corners.every((p,i)=>this.clear(p,corners[(i+1)%4],.1))&&!this.terrain.polygons.some(poly=>poly.landInside&&poly.points.some(p=>insidePolygon(p,corners)));}
 route(start:Point,goal:Point):Point[]{
  if(this.clear(start,goal,.1))return[goal];
  if(!this.nodes){const nodes:Point[]=[];for(const poly of this.terrain.polygons){const step=Math.max(1,Math.ceil(poly.points.length/32));for(let i=0;i<poly.points.length;i+=step){const p=poly.points[i],before=poly.points[(i+poly.points.length-1)%poly.points.length],after=poly.points[(i+1)%poly.points.length],dx=after.x-before.x,dy=after.y-before.y,length=Math.hypot(dx,dy)||1;for(const sign of[-1,1])for(const margin of[20,80]){const q={x:p.x-dy/length*margin*sign,y:p.y+dx/length*margin*sign};if(this.safe(q,1))nodes.push(q);}}}const all=this.terrain.polygons.filter(p=>p.landInside).flatMap(p=>p.points);if(all.length){const minX=Math.min(...all.map(p=>p.x)),maxX=Math.max(...all.map(p=>p.x)),minY=Math.min(...all.map(p=>p.y)),maxY=Math.max(...all.map(p=>p.y));for(const margin of[100,500])for(const x of[minX-margin,maxX+margin])for(const y of[minY-margin,maxY+margin])if(this.safe({x,y},1))nodes.unshift({x,y});}this.nodes=nodes.length>256?Array.from({length:256},(_,i)=>nodes[Math.floor(i*nodes.length/256)]):nodes;this.visibility=new Uint8Array(this.nodes.length*this.nodes.length);}
  const nodes=[start,goal,...this.nodes],costs=nodes.map(()=>Infinity),previous=nodes.map(()=>-1),done=new Set<number>();costs[0]=0;
  for(let n=0;n<nodes.length;n++){let at=-1;for(let i=0;i<nodes.length;i++)if(!done.has(i)&&(at<0||costs[i]<costs[at]))at=i;if(at<0||!Number.isFinite(costs[at]))break;if(at===1){const result:Point[]=[];for(let i=1;i!==0;i=previous[i])result.unshift(nodes[i]);return result;}done.add(at);for(let i=0;i<nodes.length;i++){if(done.has(i))continue;const cost=costs[at]+distance(nodes[at],nodes[i]);if(cost>=costs[i])continue;let clear:boolean;if(at>=2&&i>=2){const count:number=this.nodes.length,index:number=(at-2)*count+i-2,cached=this.visibility![index];clear=cached?cached===2:this.clear(nodes[at],nodes[i],.1);this.visibility![index]=this.visibility![(i-2)*count+at-2]=clear?2:1;}else clear=this.clear(nodes[at],nodes[i],.1);if(clear){costs[i]=cost;previous[i]=at;}}}
  return [];
 }
}
