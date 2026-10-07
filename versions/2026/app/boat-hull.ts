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
 const sheer=deck.points;
 const ring=(depth:number,width:number,length:number)=>sheer.map(p=>new THREE.Vector3(p.x*width,p.y-depth,p.z*length));
 const rail=ring(.035,.99,.997),stripe=ring(.12,.97,.993),shoulder=ring(.26,.92,.978),lower=ring(.51,.66,.935),keel=ring(.66,.28,.88);
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
 const surface={...deck,fill:deckColor,stroke:rubber,radius:.013};
 if(well)drawOpenDeck(surface,{...well,fill:new THREE.Color(classId===1?'#4b7381':'#354e5b'),stroke:rubber,radius:.012},triangle,rod);
 else{
  const faces=THREE.ShapeUtils.triangulateShape(sheer.map(p=>new THREE.Vector2(p.x,p.z)),[]);
  for(const [a,b,c]of faces)triangle(sheer[a],sheer[b],sheer[c],deckColor);
 }
 // Bow and stern carry simple class-specific deck hardware, below the rig.
 const point=(x:number,z:number)=>{
  let nearest=sheer[0],distance=Infinity;for(const p of sheer){const d=(p.x-x)**2+(p.z-z)**2;if(d<distance){distance=d;nearest=p;}}
  return new THREE.Vector3(x,nearest.y+.018,z);
 };
 const bow=classId===1?-1.55:-2.35;
 rod(point(-.12,bow),point(.12,bow),new THREE.Color('#7b9697'),.018);
 if(classId===12){
  const cleat=new THREE.Color('#718d91');
  for(const z of [-1.45,1.35])rod(point(-.15,z),point(.15,z),cleat,.018);
 }
}
