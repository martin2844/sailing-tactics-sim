import * as THREE from 'three';
import {drawOpenDeck,type MeshPrimitive} from './boat-deck';

type Triangle=(a:THREE.Vector3,b:THREE.Vector3,c:THREE.Vector3,color:THREE.Color)=>void;
type Rod=(a:THREE.Vector3,b:THREE.Vector3,color:THREE.Color,radius?:number)=>void;

/** Faceted topsides built around the recovered sheer and deck outline. */
export function drawModernHull(classId:number,deck:MeshPrimitive,cockpit:MeshPrimitive|undefined,hull:MeshPrimitive[],triangle:Triangle,rod:Rod){
 const paint=hull.find(p=>p.op===1)?.fill??new THREE.Color('#cf343b');
 const deckColor=new THREE.Color(classId===1?'#f5f0d7':classId===2?'#f6f5e9':'#e7ebdf');
 const railColor=new THREE.Color(classId===1?'#f4f4e6':classId===2?'#e9f2ee':'#e3e9e5');
 const rubber=new THREE.Color('#243f49');
 const deep=paint.clone().multiplyScalar(.58),chine=paint.clone().multiplyScalar(.77);
 // The original projection pinches the Optimist's bow to a point. A real
 // Optimist is a pram: flatten that short forward edge while retaining the
 // original length, beam and mast position.
 const sheer=deck.points.map(p=>p.clone());
 if(classId===1){
  sheer[0].x=Math.abs(sheer.at(-1)!.x);sheer[0].z=sheer.at(-1)!.z;
  sheer[1].x=Math.max(sheer[1].x,.42);sheer[1].z=-1.82;
 }
 const deckFaces=THREE.ShapeUtils.triangulateShape(sheer.map(p=>new THREE.Vector2(p.x,p.z)),[]);
 const deckY=(x:number,z:number)=>{
  for(const [ia,ib,ic]of deckFaces){const a=sheer[ia],b=sheer[ib],c=sheer[ic],denominator=(b.z-c.z)*(a.x-c.x)+(c.x-b.x)*(a.z-c.z);
   if(Math.abs(denominator)<1e-9)continue;
   const wa=((b.z-c.z)*(x-c.x)+(c.x-b.x)*(z-c.z))/denominator,wb=((c.z-a.z)*(x-c.x)+(a.x-c.x)*(z-c.z))/denominator,wc=1-wa-wb;
   if(Math.min(wa,wb,wc)>=-1e-6)return wa*a.y+wb*b.y+wc*c.y;
  }
  return sheer.reduce((nearest,p)=>Math.hypot(p.x-x,p.z-z)<Math.hypot(nearest.x-x,nearest.z-z)?p:nearest,sheer[0]).y;
 };
 const ring=(depth:number,width:number,length:number)=>sheer.map(p=>new THREE.Vector3(p.x*width,p.y-depth,p.z*length));
 const draft=classId===2?.78:classId===12?1.15:1;
 const rail=ring(.035,.99,.997),stripe=ring(.12,.97,.993),shoulder=ring(.26*draft,.92,.978),lower=ring(.51*draft,.66,.935),keel=ring(.66*draft,.28,.88);
 const strip=(upper:THREE.Vector3[],bottom:THREE.Vector3[],colors:THREE.Color[])=>{
  for(let i=0;i<upper.length;i++){const j=(i+1)%upper.length,color=colors[i%colors.length];
   triangle(upper[i],bottom[i],bottom[j],color);triangle(upper[i],bottom[j],upper[j],color);
  }
 };
 strip(sheer,rail,[railColor]);strip(rail,stripe,[rubber]);
 strip(stripe,shoulder,[paint.clone().lerp(deckColor,.22),paint]);
 strip(shoulder,lower,[paint,chine]);strip(lower,keel,[chine,deep]);
 for(let i=0;i<sheer.length;i++)rod(sheer[i],sheer[(i+1)%sheer.length],rubber,.012);
 // The Optimist source drawing has a solid painted deck. Give its open well
 // real depth, using the same clipping path as the larger boats' native well.
 const well=cockpit??(classId===1?{
  op:1,part:4,fill:new THREE.Color('#477887'),stroke:rubber,flags:0,radius:.014,
  points:[[-.39,-.95],[.39,-.95],[.43,1.18],[-.43,1.18]].map(([x,z])=>new THREE.Vector3(x,0,z)),
 } satisfies MeshPrimitive:undefined);
 const surface={...deck,points:sheer,fill:deckColor,stroke:rubber,radius:.013};
 if(well)drawOpenDeck(surface,{...well,fill:new THREE.Color(classId===1?'#4b7381':'#354e5b'),stroke:rubber,radius:.012},triangle,rod);
 else{
  for(const [a,b,c]of deckFaces)triangle(sheer[a],sheer[b],sheer[c],deckColor);
 }
 // Bow and stern carry simple class-specific deck hardware, below the rig.
 const point=(x:number,z:number,lift=.018)=>new THREE.Vector3(x,deckY(x,z)+lift,z);
 const bow=classId===1?-1.55:-2.35;
 rod(point(-.12,bow),point(.12,bow),new THREE.Color('#7b9697'),.018);
 if(classId===12){
  const cleat=new THREE.Color('#718d91');
  for(const z of [-1.45,1.35])rod(point(-.15,z),point(.15,z),cleat,.018);
  // Low cabin trunk, hatch and restrained lifelines follow the J/24 profile.
  const front=[point(-.29,-1.82),point(.29,-1.82)],rear=[point(-.34,-1.07),point(.34,-1.07)];
  const top=[front[0].clone().add(new THREE.Vector3(0,.13,0)),front[1].clone().add(new THREE.Vector3(0,.13,0)),rear[1].clone().add(new THREE.Vector3(0,.18,0)),rear[0].clone().add(new THREE.Vector3(0,.18,0))];
  const roof=new THREE.Color('#f4f4e9'),window=new THREE.Color('#496b78');
  triangle(top[0],top[1],top[2],roof);triangle(top[0],top[2],top[3],roof);
  for(const [a,b,c,d]of [[front[0],rear[0],top[3],top[0]],[front[1],rear[1],top[2],top[1]]]){triangle(a,b,c,window);triangle(a,c,d,window);}
  const rail=new THREE.Color('#8da4a6');
  for(const side of [-1,1]){
   const stations=[[-1.72,.36],[-.15,.72],[1.3,.62]].map(([z,beam])=>point(side*beam,z,.21));
   for(const post of stations)rod(point(post.x,post.z),post,rail,.007);
   for(let i=1;i<stations.length;i++)rod(stations[i-1],stations[i],rail,.006);
  }
 }else if(classId===2){
  // A visible centreboard slot and longitudinal hiking strap distinguish the
  // ILCA's open, shallow cockpit from a generic dayboat deck.
  const slot=new THREE.Color('#536f76'),strap=new THREE.Color('#344f57');
  const a=point(-.045,-1.6),b=point(.045,-1.6),c=point(.045,-1.11),d=point(-.045,-1.11);
  triangle(a,b,c,slot);triangle(a,c,d,slot);
  rod(point(0,-.81,-.055),point(0,.76,-.055),strap,.025);
 }
}
