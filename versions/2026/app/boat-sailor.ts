import * as THREE from 'three';
import type {MeshPrimitive} from './boat-deck';
import {boatFrame,type Triangle,type Rod} from './boat-design';

const navy=new THREE.Color('#263e53'),boots=new THREE.Color('#23313c');
const skin=new THREE.Color('#d4a17e'),orange=new THREE.Color('#ee783d');
const cap=new THREE.Color('#e9e8d9'),strap=new THREE.Color('#4b4d47');
const sphere=new THREE.SphereGeometry(1,8,5).toNonIndexed().getAttribute('position');

/** Authored seated sailors; recovered crew anchors choose tack and hiking lean. */
export function drawSailors(deck:MeshPrimitive,primitives:MeshPrimitive[],classId:number,triangle:Triangle,rod:Rod){
 const frame=boatFrame(deck),heads=primitives.filter(p=>p.part===2&&p.op===3);
 const count=classId===12?3:1,scale=classId===12?.62:1;
 for(let person=0;person<count;person++){
  const source=heads[person]??heads[0];
  const side=(source?.points[0].dot(frame.right)??1)<0?-1:1;
  const lean=THREE.MathUtils.clamp(Math.abs(source?.points[0].dot(frame.right)??.8)-.65,0,.4);
  const z=classId===12?.15+person*.6:.85;
  const point=(x:number,y:number,dz:number)=>frame.at(side*(.77+x*scale),.26+y*scale,z+dz*scale);
  const ellipsoid=(center:THREE.Vector3,rx:number,ry:number,rz:number,color:THREE.Color)=>{
   for(let i=0;i<sphere.count;i+=3){
    const p=[0,1,2].map(j=>center.clone().addScaledVector(frame.right,sphere.getX(i+j)*rx*scale).addScaledVector(frame.up,sphere.getY(i+j)*ry*scale).add(new THREE.Vector3(0,0,sphere.getZ(i+j)*rz*scale)));
    triangle(p[0],p[1],p[2],color);
   }
  };
  const limb=(a:THREE.Vector3,b:THREE.Vector3,radius:number,color:THREE.Color)=>rod(a,b,color,radius*scale);
  // Feet stay in the cockpit; two bent legs remain separate from every view.
  for(const dz of [-.17,.17]){
   const hip=point(0,0,dz),knee=point(-.38,.04,dz),ankle=point(-.57,-.29,dz);
   limb(hip,knee,.115,navy);ellipsoid(knee,.115,.11,.11,navy);limb(knee,ankle,.085,navy);
   ellipsoid(point(-.64,-.32,dz),.16,.075,.105,boots);
  }
  const hip=point(0,.08,0),shoulder=point(.08+lean,.61,0);
  // Eight-sided, tapered jacket with shoulders, rather than a flat torso slab.
  const loops=[{at:hip,width:.21,depth:.13},{at:hip.clone().lerp(shoulder,.72),width:.27,depth:.16},{at:shoulder,width:.23,depth:.13}];
  const rings=loops.map(({at,width,depth})=>Array.from({length:8},(_,i)=>at.clone().add(new THREE.Vector3(0,0,Math.cos(i*Math.PI/4)*width*scale)).addScaledVector(frame.right,Math.sin(i*Math.PI/4)*depth*scale)));
  for(let k=0;k<2;k++)for(let i=0;i<8;i++){const j=(i+1)%8,color=orange.clone().multiplyScalar(i%3===0?.9:1);triangle(rings[k][i],rings[k+1][i],rings[k+1][j],color);triangle(rings[k][i],rings[k+1][j],rings[k][j],color);}
  for(let i=0;i<8;i++){triangle(shoulder,rings[2][i],rings[2][(i+1)%8],orange);triangle(hip,rings[0][(i+1)%8],rings[0][i],navy);}
  for(const dz of [-.23,.23]){
   const arm=point(.08+lean,.56,dz),elbow=point(-.18,.31,dz*1.1),hand=point(-.4,.22,dz*.7);
   ellipsoid(arm,.105,.13,.12,navy);limb(arm,elbow,.079,navy);ellipsoid(elbow,.075,.075,.075,skin);limb(elbow,hand,.062,skin);ellipsoid(hand,.075,.07,.065,skin);
  }
  const neck=point(.08+lean,.69,0),head=point(.08+lean,.83,0);
  limb(shoulder,neck,.075,skin);ellipsoid(head,.145,.18,.145,skin);
  ellipsoid(point(.08+lean,.94,0),.155,.085,.155,cap);
  // Cap visor points inward, toward the sail; no oversized helmet.
  ellipsoid(point(-.07+lean,.93,0),.16,.024,.135,cap);
  limb(point(-.07+lean,.19,-.2),point(-.07+lean,.19,.2),.019,strap);
 }
}
