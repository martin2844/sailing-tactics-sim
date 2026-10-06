import * as THREE from 'three';
import {OrbitControls} from 'three/addons/controls/OrbitControls.js';
import {NativeBoatMesh} from './native-boat-mesh';
import {MODEL_QUANTUM,type NativeModelPacket} from './native-models';
function previewDirection(packet:NativeModelPacket,start:number,end:number){
 const normal=new THREE.Vector3(1,0,1);let area=0;const point=(index:number)=>new THREE.Vector3(packet.positions[index*3]/MODEL_QUANTUM,packet.positions[index*3+1]/MODEL_QUANTUM,packet.positions[index*3+2]/MODEL_QUANTUM);
 for(let at=start;at<end;){const op=packet.records[at],part=packet.records[at+1],count=packet.records[at+6];at+=7;const indices=packet.records.subarray(at,at+count);at+=count;if(op===3)at+=2;
  if(op!==1||part!==5||count<3)continue;const anchor=point(indices[0]);for(let i=2;i<count;i++){const cross=point(indices[i-1]).sub(anchor).cross(point(indices[i]).sub(anchor));if(cross.lengthSq()>area){area=cross.lengthSq();normal.copy(cross);}}
 }
 normal.y=0;if(normal.z<0)normal.negate();normal.normalize();normal.y=.32;return normal.normalize();
}
/** Reuses the sailing model, with its own presentation camera. No engine input. */
export class BoatPreview {
 private renderer:THREE.WebGLRenderer;private scene=new THREE.Scene();private camera=new THREE.PerspectiveCamera(35,1,.1,20000);private controls:OrbitControls;
 private material=new THREE.MeshStandardMaterial({vertexColors:true,flatShading:true,side:THREE.DoubleSide,roughness:.85});private model?:NativeBoatMesh;
 private waterGeometry:THREE.BufferGeometry;private waterMaterial=new THREE.MeshStandardMaterial({vertexColors:true,flatShading:true,roughness:.88});
 private dirty=true;private observer:ResizeObserver;private width=0;private height=0;private lost=false;
 constructor(private canvas:HTMLCanvasElement){
  this.renderer=new THREE.WebGLRenderer({canvas,antialias:true,alpha:false});this.renderer.setPixelRatio(Math.min(devicePixelRatio,1.5));this.renderer.outputColorSpace=THREE.SRGBColorSpace;this.renderer.toneMapping=THREE.ACESFilmicToneMapping;this.renderer.toneMappingExposure=1.05;
  this.scene.background=new THREE.Color('#afd8e4');this.scene.add(new THREE.HemisphereLight('#fff9eb','#1d627c',2.4));const sun=new THREE.DirectionalLight('#fff3dc',2.4);sun.position.set(-250,400,-200);this.scene.add(sun);
  this.waterGeometry=new THREE.PlaneGeometry(16000,16000,64,64).toNonIndexed();this.waterGeometry.rotateX(-Math.PI/2);const colors:number[]=[];for(let i=0;i<this.waterGeometry.attributes.position.count;i++){const color=new THREE.Color('#177f9c').multiplyScalar(.88+.06*(Math.sin(Math.floor(i/3)*12.9898)+1));colors.push(color.r,color.g,color.b);}this.waterGeometry.setAttribute('color',new THREE.Float32BufferAttribute(colors,3));const water=new THREE.Mesh(this.waterGeometry,this.waterMaterial);water.position.y=-2.2;this.scene.add(water);
  this.controls=new OrbitControls(this.camera,canvas);this.controls.enablePan=false;this.controls.maxPolarAngle=Math.PI*.48;this.controls.addEventListener('change',()=>{this.dirty=true;});
  this.observer=new ResizeObserver(()=>{this.dirty=true;});this.observer.observe(canvas);
  canvas.addEventListener('webglcontextlost',event=>{event.preventDefault();this.lost=true;canvas.dataset.state='unavailable';});
 }
 get unavailable(){return this.lost;}
 receive(packet:NativeModelPacket){
  const at=packet.boats.findIndex((id,index)=>index%3===0&&id===1);if(at<0)return;
  const fresh=!this.model;if(!this.model){this.model=new NativeBoatMesh(this.material);this.scene.add(this.model.group);}this.model.update(packet,packet.boats[at+1],packet.boats[at+2]);
  if(fresh){const box=new THREE.Box3().setFromObject(this.model.group),center=box.getCenter(new THREE.Vector3()),size=box.getSize(new THREE.Vector3()),distance=Math.max(size.y,size.x,size.z)*1.75;this.controls.target.copy(center);this.camera.position.copy(center).add(previewDirection(packet,packet.boats[at+1],packet.boats[at+2]).multiplyScalar(distance));this.controls.minDistance=distance*.55;this.controls.maxDistance=distance*3;this.camera.near=Math.max(.1,distance/1000);this.camera.updateProjectionMatrix();this.controls.update();}
  this.canvas.dataset.state='ready';this.dirty=true;
 }
 reset(){this.model?.dispose();this.model=undefined;this.canvas.dataset.state='loading';this.dirty=true;}
 render(){if(!this.dirty||this.lost)return;const r=this.canvas.getBoundingClientRect(),w=Math.round(r.width),h=Math.round(r.height);if(!w||!h)return;if(w!==this.width||h!==this.height){this.width=w;this.height=h;this.renderer.setSize(w,h,false);this.camera.aspect=w/h;this.camera.updateProjectionMatrix();}
  // Refit vertically framed rigs on narrow previews without clipping their tips.
  if(this.model){const box=new THREE.Box3().setFromObject(this.model.group),radius=box.getBoundingSphere(new THREE.Sphere()).radius,minDistance=radius/Math.sin(Math.atan(Math.tan(this.camera.fov*Math.PI/360)*Math.min(1,this.camera.aspect)));const offset=this.camera.position.clone().sub(this.controls.target);if(offset.length()<minDistance){this.camera.position.copy(this.controls.target).add(offset.setLength(minDistance*1.02));this.controls.update();}}
  try{this.renderer.render(this.scene,this.camera);this.dirty=false;}catch(e){this.lost=true;this.canvas.dataset.state='unavailable';console.warn('Boat preview stopped',e);}
 }
 dispose(){this.reset();this.observer.disconnect();this.controls.dispose();this.waterGeometry.dispose();this.waterMaterial.dispose();this.material.dispose();this.renderer.dispose();}
}
