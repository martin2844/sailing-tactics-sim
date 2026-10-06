import * as THREE from 'three';
import type {CoursePoint as Point} from './protocol';
import {insidePolygon,coastDistance} from './coast-geometry.ts';
export interface CoastalLand {geometry:THREE.BufferGeometry;sites:Point[];contains:(p:Point)=>boolean;height:(p:Point)=>number}
function relaxFaces(points:Point[],faces:number[][]){
 const cross=(a:Point,b:Point,c:Point)=>(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
 const quality=(a:number,b:number,c:number)=>Math.abs(cross(points[a],points[b],points[c]))/Math.max((points[a].x-points[b].x)**2+(points[a].y-points[b].y)**2,(points[b].x-points[c].x)**2+(points[b].y-points[c].y)**2,(points[c].x-points[a].x)**2+(points[c].y-points[a].y)**2);
 // Improve only interior diagonals; native coast and water-hole edges stay
 // constrained. Earcut's Steiner bridges otherwise produce long thin stripes.
 for(let pass=0;pass<30;pass++){
  const edges=new Map<string,{face:number;a:number;b:number;c:number}[]>();
  faces.forEach((f,face)=>{for(let i=0;i<3;i++){const a=f[i],b=f[(i+1)%3],c=f[(i+2)%3],key=Math.min(a,b)+','+Math.max(a,b),entries=edges.get(key)??[];entries.push({face,a,b,c});edges.set(key,entries);}});
  let changed=false;const touched=new Set<number>();
  for(const pair of edges.values()){
   if(pair.length!==2)continue;const[first,second]=pair;if(touched.has(first.face)||touched.has(second.face))continue;
   const {a,b,c}=first,d=second.c;
   if(cross(points[c],points[d],points[a])*cross(points[c],points[d],points[b])>=0)continue;
   if(Math.min(quality(c,d,a),quality(d,c,b))<=Math.min(quality(a,b,c),quality(b,a,d))+1e-6)continue;
   faces[first.face]=[c,d,a];faces[second.face]=[d,c,b];touched.add(first.face);touched.add(second.face);changed=true;
  }
  if(!changed)break;
 }
}
/** Native shoreline is fixed. Interior Steiner vertices add faceted relief
 * without changing the navigable coastline or drawing random simulation data. */
export function buildCoastalLand(polygon:{landInside:boolean;points:Point[]}):CoastalLand {
 const coast=polygon.points.filter((p,i,a)=>!i||p.x!==a[i-1].x||p.y!==a[i-1].y).map(p=>({...p}));
 if(coast.length>2&&coast[0].x===coast.at(-1)!.x&&coast[0].y===coast.at(-1)!.y)coast.pop();
 const contains=(p:Point)=>insidePolygon(p,coast)===polygon.landInside;
 const center={x:coast.reduce((s,p)=>s+p.x,0)/coast.length,y:coast.reduce((s,p)=>s+p.y,0)/coast.length};
 const sites:Point[]=[];
 const add=(p:Point)=>{if(contains(p)&&coastDistance(p,[coast])>25&&!sites.some(q=>Math.hypot(q.x-p.x,q.y-p.y)<60))sites.push(p);};
 for(let i=0;i<coast.length;i+=Math.max(1,Math.ceil(coast.length/24))){const p=coast[i],length=Math.hypot(p.x-center.x,p.y-center.y);if(!length)continue;const direction=polygon.landInside?-1:1;for(const inset of[100,250,450])add({x:p.x+(p.x-center.x)/length*inset*direction,y:p.y+(p.y-center.y)/length*inset*direction});}
 if(polygon.landInside){
  const xs=coast.map(p=>p.x),ys=coast.map(p=>p.y),minX=Math.min(...xs),maxX=Math.max(...xs),minY=Math.min(...ys),maxY=Math.max(...ys);
  for(let x=1;x<8;x++)for(let y=1;y<8;y++)add({x:minX+(maxX-minX)*x/8,y:minY+(maxY-minY)*y/8});
 }else for(let i=0;i<12;i++){const a=i*Math.PI/6;add({x:center.x+Math.cos(a)*12000,y:center.y+Math.sin(a)*12000});}
 if(sites.length>110)sites.splice(110);
 const outside=polygon.landInside?coast:[{x:-30000,y:-30000},{x:30000,y:-30000},{x:30000,y:30000},{x:-30000,y:30000}];
 const holes=polygon.landInside?[]:[coast],all=[...outside,...holes.flat(),...sites];
 const project=(p:Point)=>new THREE.Vector2(p.x,p.y);
 const faces=THREE.ShapeUtils.triangulateShape(outside.map(project),[...holes.map(h=>h.map(project)),...sites.map(p=>[project(p)])]);
 relaxFaces(all,faces);
 const fieldHeight=(p:Point)=>{const distance=coastDistance(p,[coast]),t=Math.min(1,distance/180),smooth=t*t*(3-2*t),ridge=(Math.sin(p.x/310+p.y/470)+Math.cos(p.y/220-p.x/570)+2)/4;return 1+(18+48*ridge)*smooth;};
 const heights=all.map(fieldHeight);
 const positions:number[]=[],colors:number[]=[];const sand=new THREE.Color('#c8b68b'),grass=new THREE.Color('#698753'),rock=new THREE.Color('#8d9186');
 for(const face of faces){const vertices=face.map(i=>all[i]),h=face.map(i=>heights[i]),mean=h.reduce((s,v)=>s+v,0)/3;const color=mean<7?sand.clone().lerp(grass,Math.max(0,(mean-1)/6)):grass.clone().lerp(rock,Math.max(0,(mean-40)/45));for(let i=0;i<3;i++){positions.push(vertices[i].x,h[i],vertices[i].y);colors.push(color.r,color.g,color.b);}}
 // Vertical shore below the waterline; no expanded green skirt over water.
 for(let i=0;i<coast.length;i++){
  const a=coast[i],b=coast[(i+1)%coast.length],vertices=[[a.x,1,a.y],[b.x,1,b.y],[a.x,-5,a.y],[a.x,-5,a.y],[b.x,1,b.y],[b.x,-5,b.y]];
  for(const v of vertices){positions.push(...v);colors.push(rock.r*.8,rock.g*.8,rock.b*.8);}
 }
 const geometry=new THREE.BufferGeometry();geometry.setAttribute('position',new THREE.Float32BufferAttribute(positions,3));geometry.setAttribute('color',new THREE.Float32BufferAttribute(colors,3));geometry.computeVertexNormals();
 const height=(p:Point)=>{
  for(const [ia,ib,ic]of faces){const a=all[ia],b=all[ib],c=all[ic],den=(b.y-c.y)*(a.x-c.x)+(c.x-b.x)*(a.y-c.y);if(Math.abs(den)<1e-8)continue;const u=((b.y-c.y)*(p.x-c.x)+(c.x-b.x)*(p.y-c.y))/den,v=((c.y-a.y)*(p.x-c.x)+(a.x-c.x)*(p.y-c.y))/den,w=1-u-v;if(Math.min(u,v,w)>=-1e-6)return u*heights[ia]+v*heights[ib]+w*heights[ic];}
  return fieldHeight(p);
 };
 return {geometry,sites,contains,height};
}
