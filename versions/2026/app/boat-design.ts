import * as THREE from 'three';
import type {MeshPrimitive} from './boat-deck';
// Panel strips avoid ear-clipping narrow slivers along the curved leech.
export const OPTIMIST_SAIL_FACES=[[0,8,1],[1,8,7],[1,7,2],[2,7,6],[2,6,3],[3,6,5],[3,5,4]];
export type Triangle=(a:THREE.Vector3,b:THREE.Vector3,c:THREE.Vector3,color:THREE.Color)=>void;
export type Rod=(a:THREE.Vector3,b:THREE.Vector3,color:THREE.Color,radius?:number)=>void;
export function boatFrame(deck:MeshPrimitive){
 const right=deck.points[3].clone().sub(deck.points[8]);right.z=0;right.normalize();
 const up=new THREE.Vector3(-right.y,right.x,0),height=(deck.points[3].y+deck.points[8].y)/2;
 return {right,up,at:(x:number,y:number,z:number)=>new THREE.Vector3(right.x*x+up.x*y,height+right.y*x+up.y*y,z)};
}
/** Art coordinates are independent of the old screen painter's exaggeration.
 * Source trim, heel, camber and penalty colours still supply the animated pose. */
export function designRig(primitives:MeshPrimitive[],classId:number){
 const deck=primitives.find(p=>p.part===4&&p.op===1&&p.points.length===11);
 const main=primitives.find(p=>p.part===5&&p.op===1);
 if(!deck||!main)return primitives;
 const frame=boatFrame(deck),cloth=new THREE.Color('#aebabb'),spar=new THREE.Color('#556976');
 if(classId!==1){
  const factor=.72;
  return primitives.map(p=>{
   if(![5,6].includes(p.part)&&!(p.part===3&&p.op===1))return p;
   const points=p.points.map(v=>v.clone().addScaledVector(frame.up,.16-(1-factor)*v.dot(frame.up)));
   const onLuff=(v:THREE.Vector3)=>main.points.slice(0,5).some(q=>q.distanceToSquared(v)<.0004);
   const sparLine=p.part===6&&p.op===2&&((onLuff(p.points[0])&&onLuff(p.points[1]))||(p.points[0].distanceToSquared(main.points[0])<.0004&&p.points[1].distanceToSquared(main.points.at(-1)!)<.0004));
   return {...p,points,stroke:p.part===5?cloth:p.part===6?spar:p.stroke,radius:p.part===5?.01:sparLine?.027:p.radius};
  });
 }
 const nativeFoot=main.points.at(-1)!.clone().sub(main.points[0]);
 const direction=nativeFoot.addScaledVector(frame.up,-nativeFoot.dot(frame.up)).normalize();
 const normal=new THREE.Vector3().crossVectors(frame.up,direction).normalize();
 const camber=THREE.MathUtils.clamp(main.points[6].clone().sub(main.points[0]).dot(normal),-.18,.18);
 const base=frame.at(0,.16,-1.42),tack=base.clone().addScaledVector(frame.up,.5);
 const point=(width:number,height:number,billow=0)=>tack.clone().addScaledVector(direction,width).addScaledVector(frame.up,height).addScaledVector(normal,billow);
 const points=[point(0,0),point(0,1),point(0,2),point(0,3),point(2.7,3.25,camber*.3),point(2.92,2.5,camber*.7),point(3.08,1.7,camber),point(3.17,.85,camber*.6),point(3.2,0)];
 const line=(a:THREE.Vector3,b:THREE.Vector3,part:number,color:THREE.Color,radius:number):MeshPrimitive=>({op:2,part,points:[a,b],fill:main.fill,stroke:color,flags:0,radius});
 const rig:MeshPrimitive[]=[{...main,points,stroke:cloth,radius:.01}];
 for(const [luff,leech]of [[1,7],[2,6]])rig.push(line(points[luff],points[leech],5,cloth,.01));
 rig.push(line(base,points[3],6,spar,.028),line(points[0],points[8],6,spar,.028),line(point(0,.95),points[4],5,spar,.022));
 rig.push(line(point(1.65,0),frame.at(0,-.08,.45),6,new THREE.Color('#6a8790'),.008));
 return [...primitives.filter(p=>p.part!==5&&p.part!==6),...rig];
}
