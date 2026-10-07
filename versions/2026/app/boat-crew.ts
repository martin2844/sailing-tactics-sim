import * as THREE from 'three';
import type {MeshPrimitive} from './boat-deck';
type Triangle=(a:THREE.Vector3,b:THREE.Vector3,c:THREE.Vector3,color:THREE.Color)=>void;
type Rod=(a:THREE.Vector3,b:THREE.Vector3,color:THREE.Color,radius?:number)=>void;
const skin=new THREE.Color('#d7a17c'),hair=new THREE.Color('#44342b'),trousers=new THREE.Color('#253746'),boots=new THREE.Color('#17232b');
const vest=new THREE.Color('#ef7835'),vestShade=new THREE.Color('#be562f'),vestTrim=new THREE.Color('#f5d482'),helmet=new THREE.Color('#edc94d');
const black=new THREE.Color(0);
const sphere=new THREE.SphereGeometry(1,8,5).toNonIndexed();
const spherePoints=sphere.getAttribute('position');
const jointPoints=new THREE.OctahedronGeometry(1).getAttribute('position');
/** Dress the native torso/foot/hand anchors, retaining their hiking and heel.
 * The three colored strokes are sides of a torso, not three separate limbs.
 * Returns false for unreviewed source layouts so they keep their native shape.
 */
export function drawCrew(primitives:MeshPrimitive[],triangle:Triangle,rod:Rod,classId?:number):boolean{
 const modern=classId===1||classId===2||classId===12;
 const head=primitives.at(-1),lines=primitives.slice(0,-1);
 if(!head||head.op!==3||(head.flags&2)||lines.length<5||lines.some(p=>p.op!==2)||lines.slice(0,5).some(p=>(p.flags&1)||p.stroke.equals(black)))return false;
 const near=(a:THREE.Vector3,b:THREE.Vector3)=>a.distanceToSquared(b)<1e-6;
 if(!near(lines[0].points[1],lines[1].points[0])||!near(lines[1].points[1],lines[2].points[0])||!near(lines[0].points[0],lines[3].points[0])||!near(lines[2].points[1],lines[4].points[0]))return false;
 const hipA=lines[0].points[0],hipB=lines[2].points[1],nativeShoulderA=lines[0].points[1],nativeShoulderB=lines[1].points[1];
 // The old screen painter makes people much too small beside the 3D hull.
 // Keep seated hips, feet and sheet hand fixed; grow the upper body from them.
 const scale=classId===1?1.75:classId===2?1.6:classId===12?1.4:1;
 const shoulderA=hipA.clone().add(nativeShoulderA.clone().sub(hipA).multiplyScalar(scale));
 const shoulderB=hipB.clone().add(nativeShoulderB.clone().sub(hipB).multiplyScalar(scale));
 const up=shoulderA.clone().add(shoulderB).sub(hipA).sub(hipB).normalize(),across=shoulderB.clone().sub(shoulderA).normalize();
 const normal=new THREE.Vector3().crossVectors(across,up).normalize();
 const jersey=lines[0].stroke,shade=jersey.clone().multiplyScalar(.68);
 const quad=(a:THREE.Vector3,b:THREE.Vector3,c:THREE.Vector3,d:THREE.Vector3,color:THREE.Color)=>{triangle(a,b,c,color);triangle(a,c,d,color);};
 const torso=[hipA,shoulderA,shoulderB,hipB],front=torso.map(p=>p.clone().addScaledVector(normal,.055*scale)),back=torso.map(p=>p.clone().addScaledVector(normal,-.055*scale));
 quad(...front as [THREE.Vector3,THREE.Vector3,THREE.Vector3,THREE.Vector3],jersey);quad(...back as [THREE.Vector3,THREE.Vector3,THREE.Vector3,THREE.Vector3],shade);
 for(let i=0;i<4;i++){const j=(i+1)%4;quad(front[i],back[i],back[j],front[j],shade);}
 if(modern){
  // Life jacket panels follow the recovered shoulders and hips on every tack.
  // Both faces are dressed because crew can hike to either side of the boat.
  for(const side of [1,-1]){
   const toward=(p:THREE.Vector3)=>p.clone().addScaledVector(normal,side*.064*scale);
   const shoulderLeft=toward(shoulderA),shoulderRight=toward(shoulderB);
   const waistLeft=toward(hipA),waistRight=toward(hipB);
   quad(waistLeft,shoulderLeft,shoulderRight,waistRight,side===1?vest:vestShade);
   const left=waistLeft.clone().lerp(shoulderLeft,.42),right=waistRight.clone().lerp(shoulderRight,.42);
   rod(left,right,vestTrim,.012);
   const collar=shoulderLeft.clone().lerp(shoulderRight,.5);
   rod(collar.clone().lerp(shoulderLeft,.28),collar.clone().lerp(shoulderRight,.28),vestTrim,.012);
  }
 }
 const ellipsoid=(center:THREE.Vector3,rx:number,ry:number,rz:number,color:THREE.Color,cap=false)=>{
  const source=cap?spherePoints:jointPoints;
  for(let i=0;i<source.count;i+=3){const points=[0,1,2].map(j=>new THREE.Vector3(source.getX(i+j)*rx,source.getY(i+j)*ry,source.getZ(i+j)*rz).add(center));
   const top=(source.getY(i)+source.getY(i+1)+source.getY(i+2))/3;
   triangle(points[0],points[1],points[2],cap&&top>.35?(modern?helmet:hair):color);
  }
 };
 const limb=(a:THREE.Vector3,b:THREE.Vector3,radius:number,color:THREE.Color)=>rod(a,b,color,radius);
 // Keep the original foot anchors: the renderer must not reposition the crew
 // independently of the native hiking calculation or tack.
 for(const [hip,foot]of [[hipA,lines[3].points[1]],[hipB,lines[4].points[1]]]){
  const knee=hip.clone().lerp(foot,.5).addScaledVector(up,.045);
  limb(hip,knee,.038,trousers);limb(knee,foot,.03,trousers);ellipsoid(knee,.037,.037,.037,trousers);ellipsoid(foot,.055,.026,.04,boots);
 }
 // The painter omits the far-side arm on the opposite tack. Recover its pose
 // from the same hip/foot anchors instead of dropping back to a wire person.
 const arm=lines.slice(5).find(p=>p.points[0].distanceTo(nativeShoulderB)<.2);
 const hand=arm?arm.points[1]:hipB.clone().lerp(lines[4].points[1],.52).addScaledVector(up,.03);
 for(const [shoulder,grip]of [[shoulderB,hand],[shoulderA,hand.clone().addScaledVector(across,-.12)]]){
  const elbow=shoulder.clone().lerp(grip,.5).addScaledVector(normal,.055);
  limb(shoulder,elbow,.031,jersey);ellipsoid(elbow,.031,.031,.031,skin);limb(elbow,grip,.023,skin);ellipsoid(grip,.027,.031,.027,skin);
 }
 const neck=shoulderA.clone().lerp(shoulderB,.5),nativeNeck=nativeShoulderA.clone().lerp(nativeShoulderB,.5);
 const center=neck.clone().add(head.points[0].clone().sub(nativeNeck).multiplyScalar(scale)).addScaledVector(up,modern ? .075*scale : .055);
 limb(neck,center,.031*scale,skin);ellipsoid(center,Math.max(head.rx??0,modern ? .105 : .075)*scale,Math.max(head.ry??0,modern ? .105 : .08)*scale,Math.max(head.rx??0,modern ? .105 : .075)*scale,skin,true);
 // A final black stroke on the helmsman is the native tiller/sheet, not a limb.
 for(const line of lines.slice(5))if(line!==arm&&!(line.flags&1))rod(line.points[0],line.points[1],line.stroke,line.radius);
 return true;
}
