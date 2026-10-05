import * as THREE from 'three';
import type {CourseLine} from './protocol';
/** Clip the centreline before expanding in screen pixels. This admits rays
 * crossing the near plane without enormous/invalid projected geometry. */
export function clipCourseSegment(a:THREE.Vector4,b:THREE.Vector4){
 let lo=0,hi=1;
 for(const plane of [(v:THREE.Vector4)=>v.w+v.x,(v:THREE.Vector4)=>v.w-v.x,(v:THREE.Vector4)=>v.w+v.y,(v:THREE.Vector4)=>v.w-v.y,(v:THREE.Vector4)=>v.w+v.z,(v:THREE.Vector4)=>v.w-v.z]){
  const x=plane(a),y=plane(b);if(x<0&&y<0)return;
  if(x<0)lo=Math.max(lo,x/(x-y));else if(y<0)hi=Math.min(hi,x/(x-y));
  if(lo>hi)return;
 }
 const first=a.clone().lerp(b,lo),last=a.clone().lerp(b,hi);
 if(first.w<=0||last.w<=0)return;
 return [new THREE.Vector3(first.x/first.w,first.y/first.w,first.z/first.w),new THREE.Vector3(last.x/last.w,last.y/last.w,last.z/last.w)] as const;
}
/** Ordinary depth-tested meshes work with both Three renderer backends.
 * Pixel expansion is presentation only; native anchors/bearings stay intact. */
export class ScreenCourseLine {
 readonly group=new THREE.Group();readonly layers:THREE.Mesh<THREE.BufferGeometry,THREE.MeshBasicMaterial>[]=[];
 value?:CourseLine;pixelWidth=1.4;dash=0;private y=0;
 constructor(){
  for(let layer=0;layer<2;layer++){
   const geometry=new THREE.BufferGeometry(),positions=new THREE.Float32BufferAttribute(new Float32Array(256*18),3).setUsage(THREE.DynamicDrawUsage);
   geometry.setAttribute('position',positions);geometry.setDrawRange(0,0);
   const material=new THREE.MeshBasicMaterial({color:layer?'#dbe9e8':'#17404e',side:THREE.DoubleSide,depthTest:true,depthWrite:false,toneMapped:false,fog:false});
   const mesh=new THREE.Mesh(geometry,material);mesh.frustumCulled=false;mesh.renderOrder=layer+2;this.layers.push(mesh);this.group.add(mesh);
  }
 }
 set(value:CourseLine,y:number,color:string,pixelWidth:number,dash=0){this.value=value;this.y=y;this.pixelWidth=pixelWidth;this.dash=dash;this.layers[1].material.color.set(color);}
 project(camera:THREE.Camera,origin:{x:number;y:number},width:number,height:number){
  for(const mesh of this.layers)mesh.geometry.setDrawRange(0,0);
  if(!this.group.visible||!this.value||width<=0||height<=0)return;
  const {a,b}=this.value,matrix=new THREE.Matrix4().multiplyMatrices(camera.projectionMatrix,camera.matrixWorldInverse);
  const clipped=clipCourseSegment(new THREE.Vector4(a.x-origin.x,this.y,a.y-origin.y,1).applyMatrix4(matrix),new THREE.Vector4(b.x-origin.x,this.y,b.y-origin.y,1).applyMatrix4(matrix));if(!clipped)return;
  const [first,last]=clipped,dx=(last.x-first.x)*width/2,dy=(last.y-first.y)*height/2,length=Math.hypot(dx,dy);if(length<.5)return;
  const nx=-dy/length,ny=dx/length;
  for(let layer=0;layer<2;layer++){
   const mesh=this.layers[layer],attribute=mesh.geometry.getAttribute('position') as THREE.BufferAttribute,half=(this.pixelWidth+(layer?0:1.5))/2;
   let count=0;
   const segment=(from:number,to:number)=>{
    const p=first.clone().lerp(last,from),q=first.clone().lerp(last,to),ox=nx*half*2/width,oy=ny*half*2/height;
    const corners=[new THREE.Vector3(p.x+ox,p.y+oy,p.z),new THREE.Vector3(p.x-ox,p.y-oy,p.z),new THREE.Vector3(q.x+ox,q.y+oy,q.z),new THREE.Vector3(q.x-ox,q.y-oy,q.z)].map(v=>v.unproject(camera));
    for(const index of [0,1,2,2,1,3]){const point=corners[index];attribute.setXYZ(count++,point.x,point.y,point.z);}
   };
   if(this.dash){const period=Math.max(this.dash*1.7,length/256);for(let at=0,n=0;at<length&&n<256;at+=period,n++)segment(at/length,Math.min(length,at+this.dash)/length);}
   else segment(0,1);
   attribute.needsUpdate=true;mesh.geometry.setDrawRange(0,count);
  }
 }
 dispose(){this.group.removeFromParent();for(const mesh of this.layers){mesh.geometry.dispose();mesh.material.dispose();}}
}
