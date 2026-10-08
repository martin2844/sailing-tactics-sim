import * as THREE from 'three';
import {OrbitControls} from 'three/addons/controls/OrbitControls.js';
import {OptimistStudy} from './models/optimist-study';
import {OPTIMIST} from './models/optimist-spec';

const canvas=document.querySelector<HTMLCanvasElement>('#view')!;
const container=document.getElementById('viewport')!;
const renderer=new THREE.WebGLRenderer({canvas,antialias:true,preserveDrawingBuffer:true});
renderer.setPixelRatio(Math.min(devicePixelRatio,2));
renderer.outputColorSpace=THREE.SRGBColorSpace;
renderer.toneMapping=THREE.ACESFilmicToneMapping;
renderer.toneMappingExposure=.95;
renderer.shadowMap.enabled=true;
renderer.shadowMap.type=THREE.PCFSoftShadowMap;
const scene=new THREE.Scene();
scene.background=new THREE.Color('#dce3e7');
scene.add(new THREE.HemisphereLight('#edf3f8','#53636b',2));
const sun=new THREE.DirectionalLight('#fff9ec',2.4);
sun.position.set(-3,7,-4);sun.castShadow=true;sun.shadow.mapSize.set(2048,2048);
Object.assign(sun.shadow.camera,{left:-4,right:4,top:4,bottom:-4,near:.1,far:20});
sun.shadow.bias=-.0004;sun.shadow.normalBias=.005;scene.add(sun);
const floor=new THREE.Mesh(new THREE.PlaneGeometry(100,100),new THREE.MeshStandardMaterial({color:'#bac8ce',roughness:1}));
floor.rotation.x=-Math.PI/2;floor.position.y=-.8;floor.receiveShadow=true;scene.add(floor);
const model=new OptimistStudy();scene.add(model.group);
const camera=new THREE.PerspectiveCamera(32,1,.03,100);
const controls=new OrbitControls(camera,canvas);
controls.enableDamping=true;controls.minDistance=2;controls.maxDistance=14;
let automaticFrame=true;
const views={quarter:[-4.5,1.4,5.8],side:[-1,0,0],bow:[0,.2,-1],stern:[0,.2,1],top:[0,1,.0001]} satisfies Record<string,number[]>;

function activeView(name:string){
 for(const button of document.querySelectorAll<HTMLButtonElement>('[data-view]'))button.setAttribute('aria-pressed',String(button.dataset.view===name));
}
function fitView(direction=camera.position.clone().sub(controls.target).normalize()){
 // Drain any orbit damping before applying a precise preset.
 controls.enableDamping=false;controls.update();controls.enableDamping=true;
 model.group.updateMatrixWorld(true);
 const center=new THREE.Box3().setFromObject(model.group,true).getCenter(new THREE.Vector3());
 controls.target.copy(center);camera.position.copy(center).add(direction);camera.lookAt(center);
 const inverse=camera.quaternion.clone().invert();
 const tanY=Math.tan(THREE.MathUtils.degToRad(camera.fov/2)),tanX=tanY*camera.aspect;
 let distance=controls.minDistance;
 const point=new THREE.Vector3();
 for(const mesh of [model.hull,model.rig,model.sailor,model.window]){
  if(!mesh.visible)continue;
  const positions=mesh.geometry.getAttribute('position');
  for(let i=0;i<positions.count;i++){
   point.fromBufferAttribute(positions,i).applyMatrix4(mesh.matrixWorld).sub(center).applyQuaternion(inverse);
   distance=Math.max(distance,point.z+Math.max(Math.abs(point.x)/tanX,Math.abs(point.y)/tanY)/.88);
  }
 }
 camera.position.copy(center).addScaledVector(direction,distance);
 controls.maxDistance=Math.max(14,distance*2);controls.update();
 renderer.render(scene,camera);
}
function setView(name:keyof typeof views){automaticFrame=true;fitView(new THREE.Vector3(...views[name]).normalize());activeView(name);}
function setBearing(degrees:number){const a=THREE.MathUtils.degToRad(degrees);automaticFrame=true;fitView(new THREE.Vector3(Math.sin(a),.325,-Math.cos(a)).normalize());activeView('');}
controls.addEventListener('start',()=>{automaticFrame=false;activeView('');});
for(const button of document.querySelectorAll<HTMLButtonElement>('[data-view]'))button.onclick=()=>setView(button.dataset.view as keyof typeof views);
document.getElementById('fit')!.onclick=()=>{automaticFrame=true;fitView();};
for(const id of ['trim','heel','crew','luff','penalty'] as const){
 const input=document.getElementById(id) as HTMLInputElement;
 input.addEventListener('input',()=>{
  const value=input.type==='range'?Number(input.value):input.checked;
  model.update({[id]:id==='luff'?Number(value):value});
  const output=document.getElementById(id+'-value') as HTMLOutputElement|null;
  if(output)output.value=value+'°';
  if(automaticFrame)fitView();
 });
}
new ResizeObserver(()=>{
 const {width,height}=container.getBoundingClientRect();
 if(!width||!height)return;
 renderer.setSize(width,height,false);camera.aspect=width/height;camera.updateProjectionMatrix();
 if(automaticFrame)fitView();
}).observe(container);
setView('quarter');
renderer.setAnimationLoop(t=>{
 if((document.getElementById('luff') as HTMLInputElement).checked)model.update({time:t/1000});
 controls.update();renderer.render(scene,camera);
});
Object.assign(window,{optimistStudy:{model,renderer,scene,camera,controls,spec:OPTIMIST,setView,setBearing,fitView,render:()=>renderer.render(scene,camera)},studyReady:true});
