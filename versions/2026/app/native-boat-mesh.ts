import * as THREE from 'three';
import {MODEL_QUANTUM,type NativeModelPacket} from './native-models';
import {drawOpenDeck,type MeshPrimitive} from './boat-deck';
import {drawCrew} from './boat-crew';
const primitiveSphere=new THREE.SphereGeometry(1,8,6).toNonIndexed();
const spherePoints=primitiveSphere.getAttribute('position');
const rodAngles=Array.from({length:5},(_,i)=>({cos:Math.cos(i/5*Math.PI*2),sin:Math.sin(i/5*Math.PI*2)}));
const colors=new Map<number,THREE.Color>();
function nativeColor(value:number){let color=colors.get(value);if(!color){color=new THREE.Color().setRGB((value&255)/255,((value>>>8)&255)/255,((value>>>16)&255)/255,THREE.SRGBColorSpace);colors.set(value,color);}return color;}
export class NativeBoatMesh {
 readonly group=new THREE.Group();readonly geometry=new THREE.BufferGeometry();readonly mesh:THREE.Mesh;
 private before?:Float32Array;private current?:Float32Array;private topology='';
 constructor(material:THREE.Material){this.mesh=new THREE.Mesh(this.geometry,material);this.mesh.frustumCulled=false;this.group.add(this.mesh);this.group.scale.setScalar(4);}
 update(packet:NativeModelPacket,start:number,end:number){
  const positions:number[]=[],rgb:number[]=[];const point=(index:number)=>new THREE.Vector3(packet.positions[index*3]/MODEL_QUANTUM,packet.positions[index*3+1]/MODEL_QUANTUM,packet.positions[index*3+2]/MODEL_QUANTUM);
  const put=(v:THREE.Vector3,color:THREE.Color)=>{positions.push(v.x,v.y,v.z);rgb.push(color.r,color.g,color.b);};
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
  const dressed=new Set<MeshPrimitive>();let crew:MeshPrimitive[]=[];
  for(const p of primitives){if(p.part!==2)continue;crew.push(p);if(p.op===3){if(drawCrew(crew,triangle,rod))for(const piece of crew)dressed.add(piece);crew=[];}}
  const topology:number[]=[];
  for(const p of primitives){const {op,part,fill,stroke,flags,radius,points}=p;topology.push(op,part,points.length);
   if(dressed.has(p)){topology.push(2026);continue;}
   if(deck&&cockpit){if(p===cockpit)continue;if(p===deck){topology.push(...drawOpenDeck(deck,cockpit,triangle,rod));continue;}}
   if(op===1){
    // The same recovered polygon contour determines its triangulation. Curved
    // sails keep all native edge vertices rather than becoming one triangle.
    const plane=points.map(p=>new THREE.Vector2(p.x*Math.cos(-.6108735491753208)+p.z*Math.sin(-.6108735491753208),p.y-.3*(-p.x*Math.sin(-.6108735491753208)+p.z*Math.cos(-.6108735491753208))));
    const faces=THREE.ShapeUtils.triangulateShape(plane,[]);topology.push(...faces.flat());
    if(!(flags&2))for(const face of faces)triangle(points[face[0]],points[face[1]],points[face[2]],fill);
    if(!(flags&1))for(let i=0;i<points.length;i++)rod(points[i],points[(i+1)%points.length],stroke,radius);
   }else if(op===2){if(!(flags&1)){rod(points[0],points[1],stroke,radius);}}
   else if(op===3){const rx=p.rx!,ry=p.ry!;const center=points[0];
    if(!(flags&2))for(let i=0;i<spherePoints.count;i++){const p=new THREE.Vector3(spherePoints.getX(i)*rx,spherePoints.getY(i)*ry,spherePoints.getZ(i)*rx).add(center);put(p,fill);}
   }else throw new Error('Unreviewed native mesh operation '+op);
  }
  const key=topology.join(',');const next=Float32Array.from(positions);
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
  this.interpolate(1);this.geometry.computeVertexNormals();
 }
 interpolate(alpha:number){if(!this.current||!this.before)return;const attribute=this.geometry.getAttribute('position') as THREE.BufferAttribute,a=attribute.array as Float32Array;for(let i=0;i<a.length;i++)a[i]=this.before[i]+(this.current[i]-this.before[i])*alpha;attribute.needsUpdate=true;}
 dispose(){this.geometry.dispose();this.group.removeFromParent();}
}
