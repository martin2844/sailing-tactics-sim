import * as THREE from 'three';
export interface MeshPrimitive {op:number;part:number;fill:THREE.Color;stroke:THREE.Color;flags:number;radius:number;points:THREE.Vector3[];rx?:number;ry?:number}
type Triangle=(a:THREE.Vector3,b:THREE.Vector3,c:THREE.Vector3,color:THREE.Color)=>void;
type Rod=(a:THREE.Vector3,b:THREE.Vector3,color:THREE.Color,radius?:number)=>void;
// The native painter overlays a cockpit rectangle on a complete deck. In 3D
// that creates intersecting faces. Cut its real footprint out of the deck.
export function drawOpenDeck(deck:MeshPrimitive,cockpit:MeshPrimitive,triangle:Triangle,rod:Rod):number[]{
 const project=(p:THREE.Vector3)=>new THREE.Vector2(p.x,p.z);
 const fullFaces=THREE.ShapeUtils.triangulateShape(deck.points.map(project),[]);
 function surfaceY(p:THREE.Vector3){
  for(const [ia,ib,ic]of fullFaces){const a=deck.points[ia],b=deck.points[ib],c=deck.points[ic];
   const denominator=(b.z-c.z)*(a.x-c.x)+(c.x-b.x)*(a.z-c.z);
   if(Math.abs(denominator)<1e-9)continue;
   const wa=((b.z-c.z)*(p.x-c.x)+(c.x-b.x)*(p.z-c.z))/denominator,wb=((c.z-a.z)*(p.x-c.x)+(a.x-c.x)*(p.z-c.z))/denominator,wc=1-wa-wb;
   if(Math.min(wa,wb,wc)>=-1e-6)return wa*a.y+wb*b.y+wc*c.y;
  }
  // Paired integer projections can place a cockpit's stern edge a fraction
  // beyond the deck's matching edge. Snap only within the measured lift error
  // (0.012 model units); this also handles genuinely open transom cockpits.
  let closest:THREE.Vector3|undefined,distance=Infinity;
  for(let i=0;i<deck.points.length;i++){const a=deck.points[i],b=deck.points[(i+1)%deck.points.length],dx=b.x-a.x,dz=b.z-a.z,t=Math.max(0,Math.min(1,((p.x-a.x)*dx+(p.z-a.z)*dz)/(dx*dx+dz*dz))),q=a.clone().lerp(b,t),d=Math.hypot(p.x-q.x,p.z-q.z);if(d<distance){distance=d;closest=q;}}
  if(closest&&distance<=.012){p.x=closest.x;p.z=closest.z;return closest.y;}
  throw new Error('Native cockpit lies outside its deck by '+distance.toFixed(5));
 }
 const rim=cockpit.points.map(value=>{const p=value.clone();p.y=surfaceY(p);return p;});
 const vertices=[...deck.points,...rim],faces=THREE.ShapeUtils.triangulateShape(deck.points.map(project),[rim.map(project)]);
 for(const [a,b,c]of faces)triangle(vertices[a],vertices[b],vertices[c],deck.fill);
 const floor=rim.map(p=>p.clone().add(new THREE.Vector3(0,-.14,0))),wall=deck.fill.clone().multiplyScalar(.72);
 // Floor and vertical coaming walls are separated from the deck's opening.
 triangle(floor[0],floor[1],floor[2],cockpit.fill);triangle(floor[0],floor[2],floor[3],cockpit.fill);
 for(let i=0;i<rim.length;i++){const next=(i+1)%rim.length;triangle(rim[i],floor[i],floor[next],wall);triangle(rim[i],floor[next],rim[next],wall);if(!(cockpit.flags&1))rod(rim[i],rim[next],cockpit.stroke,cockpit.radius);}
 if(!(deck.flags&1))for(let i=0;i<deck.points.length;i++)rod(deck.points[i],deck.points[(i+1)%deck.points.length],deck.stroke,deck.radius);
 return faces.flat();
}
