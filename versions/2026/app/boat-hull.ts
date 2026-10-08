import * as THREE from 'three';
import type {MeshPrimitive} from './boat-deck';
import {boatFrame,type Triangle,type Rod} from './boat-design';

/** Authored class silhouettes, fitted to the simulation's existing footprint. */
export function drawModernHull(classId:number,deck:MeshPrimitive,_cockpit:MeshPrimitive|undefined,hull:MeshPrimitive[],triangle:Triangle,rod:Rod){
 const frame=boatFrame(deck),at=frame.at;
 const white=new THREE.Color('#eeeede'),edge=new THREE.Color('#d2dcd7'),inside=new THREE.Color('#bdccca');
 const paint=(hull.find(p=>p.op===1)?.fill??new THREE.Color('#bf3d43')).clone().lerp(new THREE.Color('#566576'),.15);
 const dark=new THREE.Color('#293e4d'),metal=new THREE.Color('#72878c');
 const outline:number[][]=classId===1?
  [[-.63,-2],[.63,-2],[.83,-1.65],[.9,-.8],[.91,.5],[.86,1.72],[.73,2],[-.73,2],[-.86,1.72],[-.91,.5],[-.9,-.8],[-.83,-1.65]]:
  [[0,-3],[.32,-2.65],[.58,-2],[.76,-1.15],[.85,-.2],[.83,.8],[.73,1.6],[.59,2],[-.59,2],[-.73,1.6],[-.83,.8],[-.85,-.2],[-.76,-1.15],[-.58,-2],[-.32,-2.65]];
 const ring=(y:number,width=1,length=1)=>outline.map(([x,z])=>at(x*width,y+(z< -1?(-z-1)*.035:0),z*length));
 const sheer=ring(.2),lip=ring(.13,1.015),side=ring(-.2,.96,.99),stripe=ring(-.34,.91,.98),bottom=ring(-.62,.67,.94);
 const quad=(a:THREE.Vector3,b:THREE.Vector3,c:THREE.Vector3,d:THREE.Vector3,color:THREE.Color)=>{triangle(a,b,c,color);triangle(a,c,d,color);};
 const strip=(a:THREE.Vector3[],b:THREE.Vector3[],color:THREE.Color)=>{for(let i=0;i<a.length;i++){const j=(i+1)%a.length;quad(a[i],b[i],b[j],a[j],color);}};
 for(let i=1;i<bottom.length-1;i++)triangle(bottom[0],bottom[i+1],bottom[i],paint);
 strip(sheer,lip,white);strip(lip,side,white);strip(side,stripe,paint);strip(stripe,bottom,paint.clone().multiplyScalar(.72));
 const well:number[][]=classId===1?[[-.64,-1.1],[.64,-1.1],[.69,1.48],[.52,1.7],[-.52,1.7],[-.69,1.48]]:
  classId===2?[[-.28,-.2],[.28,-.2],[.34,1.4],[.22,1.62],[-.22,1.62],[-.34,1.4]]:
  [[-.36,.05],[.36,.05],[.4,1.5],[.28,1.75],[-.28,1.75],[-.4,1.5]];
 const contour=outline.map(([x,z])=>new THREE.Vector2(x,z)),hole=well.map(([x,z])=>new THREE.Vector2(x,z));
 const rim=well.map(([x,z])=>at(x,.2,z)),floor=well.map(([x,z])=>at(x,-.2,z));
 const vertices=[...sheer,...rim];
 for(const [a,b,c]of THREE.ShapeUtils.triangulateShape(contour,[hole]))triangle(vertices[a],vertices[b],vertices[c],white);
 strip(rim,floor,inside);
 for(const [a,b,c]of THREE.ShapeUtils.triangulateShape(hole,[]))triangle(floor[a],floor[b],floor[c],edge);
 // A bevel gives the coaming a highlight without black cartoon outlines.
 for(let i=0;i<rim.length;i++)rod(rim[i],rim[(i+1)%rim.length],edge,.017);
 const box=(x:number,y:number,z:number,w:number,h:number,l:number,color:THREE.Color)=>{
  const p=[at(x-w/2,y,z-l/2),at(x+w/2,y,z-l/2),at(x+w/2,y,z+l/2),at(x-w/2,y,z+l/2)];
  const q=p.map(v=>v.clone().addScaledVector(frame.up,h));quad(q[0],q[1],q[2],q[3],color);strip(p,q,color);
 };
 if(classId===1){
  box(0,-.2,-.35,.15,.36,.8,white);box(0,.13,-1.28,1.37,.09,.25,white);
  for(const side of [-1,1]){box(side*.73,-.05,.3,.16,.17,1.35,edge);rod(at(side*.25,-.12,.1),at(side*.25,-.12,1.45),dark,.026);}
 }else if(classId===2){
  box(0,.205,-.58,.085,.015,.52,dark);rod(at(0,-.1,.05),at(0,-.1,1.45),dark,.025);
 }else{
  const lower=[at(-.36,.2,-1.65),at(.36,.2,-1.65),at(.52,.2,-.05),at(-.52,.2,-.05)];
  const roof=[at(-.25,.42,-1.55),at(.25,.42,-1.55),at(.4,.47,-.15),at(-.4,.47,-.15)];
  strip(lower,roof,edge);quad(...roof as [THREE.Vector3,THREE.Vector3,THREE.Vector3,THREE.Vector3],white);
  box(0,.46,-.68,.4,.025,.48,dark);
  for(const side of [-1,1]){
   const stations=[[-2,.48],[-.5,.78],[1.5,.64]].map(([z,x])=>at(side*x,.49,z));
   for(const p of stations)rod(p.clone().addScaledVector(frame.up,-.29),p,metal,.009);
   for(let i=1;i<stations.length;i++)rod(stations[i-1],stations[i],metal,.006);
  }
 }
 // Rudder blade and tiller are genuine volume, with the blade below the water.
 box(0,-.7,2.12,.07,.82,.3,white);rod(at(0,.24,2.2),at(0,.3,.9),dark,.023);
}
