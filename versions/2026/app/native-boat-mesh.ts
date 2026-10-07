import * as THREE from 'three';
import {MODEL_QUANTUM,type NativeModelPacket} from './native-models';
import {drawOpenDeck,type MeshPrimitive} from './boat-deck';
import {drawCrew} from './boat-crew';
import {triangulateSail} from './sail-triangulation';
import {SailDetailSurface,type SailAnchor} from './sail-detail';
import type {BoatView} from './protocol';
import {BOAT_MODEL_SCALE} from './world-objects';
const primitiveSphere=new THREE.SphereGeometry(1,8,6).toNonIndexed();
const spherePoints=primitiveSphere.getAttribute('position');
const rodAngles=Array.from({length:5},(_,i)=>({cos:Math.cos(i/5*Math.PI*2),sin:Math.sin(i/5*Math.PI*2)}));
const colors=new Map<number,THREE.Color>();
function nativeColor(value:number){let color=colors.get(value);if(!color){color=new THREE.Color().setRGB((value&255)/255,((value>>>8)&255)/255,((value>>>16)&255)/255,THREE.SRGBColorSpace);colors.set(value,color);}return color;}
export class NativeBoatMesh {
 readonly group=new THREE.Group();readonly geometry=new THREE.BufferGeometry();readonly mesh:THREE.Mesh;
 private before?:Float32Array;private current?:Float32Array;private topology='';
 private motion=Uint8Array.from([]);private pivot=new THREE.Vector3();private mast=new THREE.Vector3(0,1,0);private sailHeight=1;private nativeBoomBearing=0;private hasRig=false;
 private sailAttachments:{vertex:number;faceBase:number;weights:[number,number,number];offset:THREE.Vector3}[]=[];
 constructor(material:THREE.Material){this.mesh=new THREE.Mesh(this.geometry,material);this.mesh.frustumCulled=false;this.group.add(this.mesh);this.group.scale.setScalar(BOAT_MODEL_SCALE);}
 update(packet:NativeModelPacket,start:number,end:number){
  const positions:number[]=[],rgb:number[]=[],motion:number[]=[];let movingPart=0,movingEnds:THREE.Vector3[]=[];const point=(index:number)=>new THREE.Vector3(packet.positions[index*3]/MODEL_QUANTUM,packet.positions[index*3+1]/MODEL_QUANTUM,packet.positions[index*3+2]/MODEL_QUANTUM);
  this.sailAttachments=[];let detailAnchors:SailAnchor[]=[];const clothFaces:number[]=[];
  const put=(v:THREE.Vector3,color:THREE.Color)=>{
   if(detailAnchors.length){const anchor=detailAnchors.reduce((a,b)=>a.point.distanceToSquared(v)<b.point.distanceToSquared(v)?a:b);this.sailAttachments.push({vertex:positions.length/3,faceBase:clothFaces[anchor.face],weights:anchor.weights,offset:v.clone().sub(anchor.point)});}
   positions.push(v.x,v.y,v.z);rgb.push(color.r,color.g,color.b);motion.push(movingPart===1?1:movingPart===2&&movingEnds.some(p=>p.distanceToSquared(v)<.0064)?2:0);
  };
  const triangle=(a:THREE.Vector3,b:THREE.Vector3,c:THREE.Vector3,color:THREE.Color)=>{put(a,color);put(b,color);put(c,color);};
  const axis=new THREE.Vector3(),u=new THREE.Vector3(),v=new THREE.Vector3(),reference=new THREE.Vector3(),ring=Array.from({length:10},()=>new THREE.Vector3());
  const rod=(a:THREE.Vector3,b:THREE.Vector3,color:THREE.Color,radius=.008)=>{
   axis.copy(b).sub(a);if(axis.lengthSq()<.000001)return;axis.normalize();reference.set(Math.abs(axis.y)>.9?1:0,Math.abs(axis.y)>.9?0:1,0);u.crossVectors(axis,reference).normalize().multiplyScalar(radius);v.crossVectors(axis,u);
   // Reuse one ring's scratch vectors for every native pen/limb. Emission
   // copies coordinates, so no reference to these vectors escapes this call.
   for(let i=0;i<5;i++){const {cos,sin}=rodAngles[i],x=u.x*cos+v.x*sin,y=u.y*cos+v.y*sin,z=u.z*cos+v.z*sin;ring[i].set(a.x+x,a.y+y,a.z+z);ring[i+5].set(b.x+x,b.y+y,b.z+z);}
   for(let i=0;i<5;i++){const next=(i+1)%5;triangle(ring[i],ring[i+5],ring[next+5],color);triangle(ring[i],ring[next+5],ring[next],color);}
  };
  const primitives:MeshPrimitive[]=[];
  for(let at=start;at<end;){const op=packet.records[at++],part=packet.records[at++],fill=nativeColor(packet.colors[packet.records[at++]]),stroke=nativeColor(packet.colors[packet.records[at++]]),flags=packet.records[at++],radius=packet.records[at++]/MODEL_QUANTUM,count=packet.records[at++];const points=Array.from(packet.records.slice(at,at+count),point);at+=count;const p:MeshPrimitive={op,part,fill,stroke,flags,radius,points};if(op===3){p.rx=packet.records[at++]/MODEL_QUANTUM;p.ry=packet.records[at++]/MODEL_QUANTUM;}primitives.push(p);}
  const deck=primitives.find(p=>p.part===4&&p.op===1&&p.points.length===11),cockpit=primitives.find(p=>p.part===4&&p.op===1&&p.points.length===4);
  const main=primitives.find(p=>p.part===5&&p.op===1),boom=main?primitives.find(p=>p.part===6&&p.op===2&&p.points[0].distanceToSquared(main.points[0])<.0004&&p.points[1].distanceToSquared(main.points.at(-1)!)<.0004):undefined;
  const cloth=main?new SailDetailSurface(main.points):undefined;
  this.hasRig=!!main&&!!boom;
  if(main&&boom){this.pivot.copy(boom.points[0]);const tip=main.points.reduce((a,b)=>a.y>b.y?a:b);this.mast.copy(tip).sub(this.pivot);this.sailHeight=this.mast.length();this.mast.normalize();const direction=boom.points[1].clone().sub(this.pivot);this.nativeBoomBearing=Math.atan2(direction.x,direction.z);}
  const dressed=new Set<MeshPrimitive>();let crew:MeshPrimitive[]=[];
  for(const p of primitives){if(p.part!==2)continue;crew.push(p);if(p.op===3){if(drawCrew(crew,triangle,rod))for(const piece of crew)dressed.add(piece);crew=[];}}
  const topology:number[]=[];
  for(const p of primitives){const {op,part,fill,stroke,flags,radius,points}=p;topology.push(op,part,points.length);
   movingPart=part===5?1:0;movingEnds=[];
   if(boom&&p.op===2&&p!==boom&&part!==2&&part!==1&&part!==4){movingEnds=points.filter(v=>v.distanceToSquared(boom.points[1])<.0004);if(movingEnds.length)movingPart=2;}
   if(p===boom){movingPart=2;movingEnds=points;}
   if(dressed.has(p)){topology.push(2026);continue;}
   if(deck&&cockpit){if(p===cockpit)continue;if(p===deck){topology.push(...drawOpenDeck(deck,cockpit,triangle,rod));continue;}}
   if(op===1){
    // The same recovered polygon contour determines its triangulation. Curved
    // sails keep all native edge vertices rather than becoming one triangle.
    const faces=part===5?triangulateSail(points):THREE.ShapeUtils.triangulateShape(points.map(p=>new THREE.Vector2(p.x*Math.cos(-.6108735491753208)+p.z*Math.sin(-.6108735491753208),p.y-.3*(-p.x*Math.sin(-.6108735491753208)+p.z*Math.cos(-.6108735491753208)))),[]);topology.push(...faces.flat());
    if(!(flags&2))for(const face of faces){if(p===main)clothFaces.push(positions.length/3);triangle(points[face[0]],points[face[1]],points[face[2]],fill);}
    if(!(flags&1))for(let i=0;i<points.length;i++)rod(points[i],points[(i+1)%points.length],stroke,radius);
   }else if(op===2){if(!(flags&1)){
    if(part===5&&cloth&&clothFaces.length){
     const segments=cloth.segments(points[0],points[1]);topology.push(-5,segments.length,...segments.map(segment=>segment[0].face));
     for(const segment of segments){detailAnchors=segment;rod(segment[0].point,segment[1].point,stroke,radius);}detailAnchors=[];
    }else rod(points[0],points[1],stroke,radius);
   }}
   else if(op===3){const rx=p.rx!,ry=p.ry!;const center=points[0];
    if(!(flags&2))for(let i=0;i<spherePoints.count;i++){const p=new THREE.Vector3(spherePoints.getX(i)*rx,spherePoints.getY(i)*ry,spherePoints.getZ(i)*rx).add(center);put(p,fill);}
   }else throw new Error('Unreviewed native mesh operation '+op);
  }
  const key=topology.join(',');const next=Float32Array.from(positions);
  this.motion=Uint8Array.from(motion);
  this.before=this.current&&this.current.length===next.length&&this.topology===key?this.current:next;this.current=next;this.topology=key;
  const attribute=this.geometry.getAttribute('position') as THREE.BufferAttribute|undefined;
  if(!attribute||attribute.array.length!==next.length){
   // Dispose the previous GPU attributes when native topology changes; normals
   // must also be resized. Ordinary animation updates existing buffers.
   this.geometry.dispose();this.geometry.deleteAttribute('normal');this.geometry.deleteAttribute('color');
   this.geometry.setAttribute('position',new THREE.BufferAttribute(next.slice(),3).setUsage(THREE.DynamicDrawUsage));
  }
  const colorAttribute=this.geometry.getAttribute('color') as THREE.BufferAttribute|undefined;
  if(colorAttribute&&colorAttribute.array.length===rgb.length){(colorAttribute.array as Float32Array).set(rgb);colorAttribute.needsUpdate=true;}
  else this.geometry.setAttribute('color',new THREE.Float32BufferAttribute(rgb,3).setUsage(THREE.DynamicDrawUsage));
  this.interpolate(1);this.geometry.computeVertexNormals();this.geometry.computeBoundingBox();this.geometry.boundingBox!.expandByScalar(.15);
 }
 interpolate(alpha:number,rig?:BoatView,time=0){if(!this.current||!this.before)return;const attribute=this.geometry.getAttribute('position') as THREE.BufferAttribute,a=attribute.array as Float32Array;for(let i=0;i<a.length;i++)a[i]=this.before[i]+(this.current[i]-this.before[i])*alpha;
  let sailSwing=0;
  if(rig&&this.hasRig){
   const relative=((rig.windFrom-rig.heading+540)%360)-180,released=Math.max(0,Math.min(1,(35-Math.abs(relative))/30));
   if(released>0){
    const target=-relative*Math.PI/180,difference=Math.atan2(Math.sin(target-this.nativeBoomBearing),Math.cos(target-this.nativeBoomBearing)),swing=released*(difference+Math.sin(time*3.1+rig.id)*.12);
    const cos=Math.cos(swing),sin=Math.sin(swing),axis=this.mast,pivot=this.pivot;
    sailSwing=swing;
    for(let vertex=0;vertex<this.motion.length;vertex++){const kind=this.motion[vertex];if(!kind)continue;const i=vertex*3,x=a[i]-pivot.x,y=a[i+1]-pivot.y,z=a[i+2]-pivot.z,dot=x*axis.x+y*axis.y+z*axis.z;
     const radial=Math.hypot(x-dot*axis.x,y-dot*axis.y,z-dot*axis.z);if(radial<.025)continue;
     a[i]=pivot.x+x*cos+(axis.y*z-axis.z*y)*sin+axis.x*dot*(1-cos);
     a[i+1]=pivot.y+y*cos+(axis.z*x-axis.x*z)*sin+axis.y*dot*(1-cos);
     a[i+2]=pivot.z+z*cos+(axis.x*y-axis.y*x)*sin+axis.z*dot*(1-cos);
     if(kind===1)a[i]+=released*Math.min(1,radial/.6)*Math.sin(Math.PI*Math.max(0,Math.min(1,dot/this.sailHeight)))*(.04+.06*Math.min(1,Math.max(0,rig.luff)/90))*Math.sin(time*9.3+dot*2.4+rig.id);
    }
   }
  }
  // Apply attachments after cloth deformation. Barycentric centres follow the
  // rendered triangles, including interpolated/luffing states; rod radius
  // protrudes on both sides and still respects normal depth occlusion.
  const offset=new THREE.Vector3();
  for(const attachment of this.sailAttachments){
   offset.copy(attachment.offset);if(sailSwing)offset.applyAxisAngle(this.mast,sailSwing);
   for(let k=0;k<3;k++){let value=offset.getComponent(k);for(let i=0;i<3;i++)value+=a[(attachment.faceBase+i)*3+k]*attachment.weights[i];a[attachment.vertex*3+k]=value;}
  }
  attribute.needsUpdate=true;}
 dispose(){this.geometry.dispose();this.group.removeFromParent();}
}
