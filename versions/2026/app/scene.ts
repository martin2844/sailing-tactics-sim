import {WATER_SURFACE_Y} from './world-objects';
import {AnimationClock} from './presentation/animation-clock';
import * as THREE from 'three';
import {OrbitControls} from 'three/addons/controls/OrbitControls.js';
import {NativeBoatLayer} from './native-boat-layer';
import type {SceneSnapshot} from './protocol';
import {NativeBoatMesh} from './native-boat-mesh';
import {CourseScene} from './course-scene';
import {EnvironmentScene} from './environment-scene';
import type {NativeTerrain} from './native-environment';
import {SceneLabels} from './scene-labels';
import {Minimap} from './minimap';
import type {NativeModelPacket} from './native-models';
import {ContactOverlay} from './contact-overlay';
export type Backend='webgl2'|'webgpu';
type Renderer=THREE.WebGLRenderer|import('three/webgpu').WebGPURenderer;
export interface RenderSample {intervalMs:number;cpuMs:number;changed:boolean;poseChanged:boolean;sequence:number;alpha:number;calls:number;triangles:number}
export class SailingScene {
  private readonly animationClock=new AnimationClock();
 readonly contactOverlay=new ContactOverlay();
  readonly scene=new THREE.Scene();readonly camera=new THREE.PerspectiveCamera(45,1,1,70000);
  private renderer!:Renderer;private controls:OrbitControls;private water:THREE.Mesh;
  private previous?:SceneSnapshot;private latest?:SceneSnapshot;private received=0;private span=40;private lastDraw=0;private lastPose='';private mode='chase';private paused=false;private disposed=false;private width=0;private height=0;
  private geometries=new Set<THREE.BufferGeometry>();private materials=new Set<THREE.Material>();private observer:ResizeObserver;
  private queryExtension:any;private pendingQueries:WebGLQuery[]=[];readonly gpuMs:number[]=[];private gl?:WebGL2RenderingContext;
  actualBackend='initializing';adapterInfo:unknown;readonly samples:RenderSample[]=[];private lastWaterPhase=-1;private cameraDirty=true;private origin=new THREE.Vector3();private nativeBoats:NativeBoatLayer;
  private models=new Map<number,NativeBoatMesh>();private modelMaterial:THREE.Material;private modelReceived=0;private modelSpan=40;modelSequence=0;hasModels=false;modelPacket?:NativeModelPacket;readonly modelCosts:number[]=[];readonly modelBytes:number[]=[];readonly modelBuildCosts:number[]=[];
  private environment=new EnvironmentScene();private course=new CourseScene();readonly labels:SceneLabels;readonly minimap:Minimap;
  constructor(private canvas:HTMLCanvasElement,boatCanvas:HTMLCanvasElement,private onSample:(sample:RenderSample)=>void,private onFailure:(message:string)=>void){
    this.nativeBoats=new NativeBoatLayer(boatCanvas);
    this.labels=new SceneLabels(canvas);this.minimap=new Minimap(document.getElementById('minimap-toggle') as HTMLButtonElement);
    boatCanvas.hidden=true;
    this.modelMaterial=this.material(new THREE.MeshStandardMaterial({vertexColors:true,flatShading:true,side:THREE.DoubleSide,roughness:.85}));
    this.scene.background=new THREE.Color('#afd8e4');this.scene.fog=new THREE.Fog('#afd8e4',8000,40000);
    this.scene.add(new THREE.HemisphereLight('#fff9eb','#1d627c',2.4));
    const sun=new THREE.DirectionalLight('#fff3dc',2.4);sun.position.set(-250,400,-200);this.scene.add(sun);
    this.controls=new OrbitControls(this.camera,canvas);this.controls.enableDamping=false;this.controls.minDistance=35;this.controls.maxDistance=50000;this.controls.maxPolarAngle=Math.PI*.48;this.controls.enablePan=false;
    let pointerStart:{x:number;y:number;mode:string}|undefined;
    canvas.addEventListener('pointerdown',event=>{pointerStart={x:event.clientX,y:event.clientY,mode:this.mode};},{capture:true});
    canvas.addEventListener('pointerup',event=>{if(pointerStart&&Math.hypot(event.clientX-pointerStart.x,event.clientY-pointerStart.y)<5)this.mode=pointerStart.mode;pointerStart=undefined;},{capture:true});
    this.controls.addEventListener('start',()=>{this.mode='orbit';});this.controls.addEventListener('change',()=>{this.cameraDirty=true;});
    this.camera.position.set(90,70,145);this.controls.target.set(0,12,0);this.controls.update();
    const geo=this.geometry(new THREE.PlaneGeometry(12000,12000,96,96).toNonIndexed());geo.rotateX(-Math.PI/2);
    // Presentation-only facets, independent of original wind/wave randomness.
    const position=geo.attributes.position;const colors=[];
    for(let i=0;i<position.count;i++){const x=position.getX(i),z=position.getZ(i);position.setY(i,0);const color=new THREE.Color('#177f9c');const face=Math.floor(i/3);color.multiplyScalar(.88+.12*(Math.sin(face*12.9898)+1)/2);colors.push(color.r,color.g,color.b);}
    geo.setAttribute('color',new THREE.Float32BufferAttribute(colors,3));geo.computeVertexNormals();
    this.water=new THREE.Mesh(geo,this.material(new THREE.MeshStandardMaterial({vertexColors:true,flatShading:true,roughness:.88,metalness:.05})));this.water.position.y=WATER_SURFACE_Y;this.scene.add(this.water);const distantWater=new THREE.Mesh(this.geometry(new THREE.PlaneGeometry(160000,160000)),this.material(new THREE.MeshStandardMaterial({color:new THREE.Color('#177f9c').multiplyScalar(.9),roughness:.88,metalness:.05})));distantWater.rotation.x=-Math.PI/2;distantWater.position.y=-4.2;this.scene.add(distantWater);
    this.scene.add(this.environment.group);
    this.scene.add(this.course.group);
    this.scene.add(this.contactOverlay.group);
    this.observer=new ResizeObserver(()=>this.resize());this.observer.observe(canvas);
    canvas.addEventListener('webglcontextlost',event=>{event.preventDefault();this.onFailure('Graphics stopped. Restart to restore the scene.');});
  }
  private geometry<T extends THREE.BufferGeometry>(g:T):T{this.geometries.add(g);return g;}
  private material<T extends THREE.Material>(m:T):T{this.materials.add(m);return m;}
  receiveTerrain(data:NativeTerrain){this.environment.setTerrain(data);this.minimap.receiveTerrain(data);this.cameraDirty=true;}
  async initialize(backend:Backend){
    if(backend==='webgpu'){
      const {WebGPURenderer}=await import('three/webgpu');
      const renderer=new WebGPURenderer({canvas:this.canvas,antialias:true,alpha:false});await renderer.init();
      this.renderer=renderer;const native=(renderer.backend as unknown as {isWebGPUBackend?:boolean}).isWebGPUBackend===true;
      this.actualBackend=native?'WebGPU':'WebGL 2 (WebGPU fallback)';
      this.adapterInfo=(renderer.backend as unknown as {adapter?:{info?:unknown}}).adapter?.info??null;
    }else{
      const renderer=new THREE.WebGLRenderer({canvas:this.canvas,antialias:true,alpha:false,powerPreference:'high-performance'});this.renderer=renderer;this.actualBackend='WebGL 2';
      this.gl=renderer.getContext() as WebGL2RenderingContext;this.queryExtension=this.gl.getExtension('EXT_disjoint_timer_query_webgl2');
      const debug=this.gl.getExtension('WEBGL_debug_renderer_info');this.adapterInfo=debug?{vendor:this.gl.getParameter(debug.UNMASKED_VENDOR_WEBGL),renderer:this.gl.getParameter(debug.UNMASKED_RENDERER_WEBGL)}:null;
    }
    if(this.disposed){this.renderer.dispose();return;}
    this.renderer.setPixelRatio(Math.min(devicePixelRatio,1.5));this.renderer.outputColorSpace=THREE.SRGBColorSpace;
    this.renderer.toneMapping=THREE.ACESFilmicToneMapping;this.renderer.toneMappingExposure=1.05;this.resize();
  }
  resize(){if(!this.renderer||this.disposed)return;const rect=this.canvas.getBoundingClientRect();const w=Math.max(1,Math.round(rect.width)),h=Math.max(1,Math.round(rect.height));if(w===this.width&&h===this.height)return;this.width=w;this.height=h;this.camera.aspect=w/h;this.camera.updateProjectionMatrix();this.renderer.setSize(w,h,false);this.cameraDirty=true;}
  setCamera(mode:'chase'|'overview'){this.mode=mode;this.cameraDirty=true;this.controls.target.set(0,8,0);if(mode==='chase')this.camera.position.set(90,70,145);else{
    const state=this.latest,points=state?[...state.course.marks,...(state.course.gate??[]),state.course.start.a,state.course.start.b,state.course.finish.a,state.course.finish.b,state.course.target,...state.boats]:[{x:0,y:0}],xs=points.map(p=>p.x),ys=points.map(p=>p.y),minX=Math.min(...xs),maxX=Math.max(...xs),minY=Math.min(...ys),maxY=Math.max(...ys),height=Math.max(580,Math.max((maxX-minX)/Math.max(.5,this.camera.aspect-.4),maxY-minY)*1.5);
    this.controls.target.set((minX+maxX)/2-(state?.boats[0].x??0),0,(minY+maxY)/2-(state?.boats[0].y??0));this.camera.position.copy(this.controls.target).add(new THREE.Vector3(0,height,height*.2));
   }this.controls.update();}
  useNativeCamera(){this.mode='native';this.cameraDirty=true;}
  zoomTactical(ratio:number){if(!Number.isFinite(ratio)||ratio<=0)return;this.mode='orbit';const offset=this.camera.position.clone().sub(this.controls.target);offset.multiplyScalar(ratio);offset.setLength(Math.max(this.controls.minDistance,Math.min(this.controls.maxDistance,offset.length())));this.camera.position.copy(this.controls.target).add(offset);this.controls.update();this.cameraDirty=true;}
  setTacticalOrientation(value:number){this.setCamera('overview');const bearing=value===2?this.latest?.windDirection??0:this.latest?.boats[0].heading??0,angle=bearing*Math.PI/180,offset=this.camera.position.clone().sub(this.controls.target),distance=Math.hypot(offset.x,offset.z);this.camera.position.copy(this.controls.target).add(new THREE.Vector3(-distance*Math.sin(angle),offset.y,distance*Math.cos(angle)));this.controls.update();}
  setPaused(value:boolean){this.paused=value;this.animationClock.setPaused(value);this.cameraDirty=true;}
  get cameraMode(){return this.mode;}
  receive(value:SceneSnapshot){if(this.latest&&value.generation!==this.latest.generation){this.previous=undefined;this.latest=undefined;}const now=performance.now();this.span=this.latest?Math.max(1,now-this.received):40;this.previous=this.latest;this.latest=value;this.received=now;
    this.nativeBoats.receive(value.nativeVisuals);
  }
  receiveModels(value:{generation:number;sequence:number;packet:NativeModelPacket}){if(this.latest&&value.generation!==this.latest.generation)return;const p=value.packet,now=performance.now();this.modelPacket=p;this.modelSpan=this.hasModels?Math.max(1,now-this.modelReceived):40;this.modelReceived=now;this.modelSequence=value.sequence;
    for(let at=0;at<p.boats.length;at+=3){const id=p.boats[at];let model=this.models.get(id);if(!model){model=new NativeBoatMesh(this.modelMaterial);this.models.set(id,model);this.scene.add(model.group);}model.update(p,p.boats[at+1],p.boats[at+2],this.latest?.configuration.selector);}
    this.hasModels=true;if(this.modelCosts.length<4000){this.modelCosts.push(p.workMs);this.modelBytes.push(p.positions.byteLength+p.records.byteLength+p.colors.byteLength+p.boats.byteLength);this.modelBuildCosts.push(performance.now()-now);}this.cameraDirty=true;
  }
  reset(){this.animationClock.reset();this.minimap.reset();this.environment.reset();this.labels.reset();for(const model of this.models.values())model.dispose();this.models.clear();this.hasModels=false;this.modelPacket=undefined;this.modelSequence=0;this.modelCosts.length=0;this.modelBytes.length=0;this.modelBuildCosts.length=0;this.nativeBoats.reset();this.course.reset();this.previous=undefined;this.latest=undefined;this.lastPose='';this.lastDraw=0;}
  render(now:number){
    if(this.disposed||!this.renderer||!this.latest)return;
    if(this.lastDraw&&now-this.lastDraw<1000/60-.6)return;
    const current=this.latest,old=this.previous??current,alpha=this.paused?1:Math.min(1,Math.max(0,(now-this.received)/this.span));
    // A native penalty relocates immediately; never animate its jump through the fleet.
    const poses=current.boats.map((boat,i)=>{const prior=old.boats[i]??boat,before=boat.penaltyClock!==prior.penaltyClock?boat:prior;const delta=((boat.heading-before.heading+540)%360)-180;return{x:before.x+(boat.x-before.x)*alpha,y:before.y+(boat.y-before.y)*alpha,heading:before.heading+delta*alpha};});
    const player=poses[0];this.origin.set(player.x,0,player.y);
    this.contactOverlay.update(current,player,poses);
    this.course.group.visible=true;this.course.update(current.course,current.boats[0],{x:player.x,y:player.y},current.clock);
    if(this.mode==='chase'){
      const bearing=player.heading*Math.PI/180;
      this.controls.target.set(0,12,0);this.camera.position.set(-Math.sin(bearing)*170,70,Math.cos(bearing)*170);this.controls.update();
    }
    if(this.mode==='native'){
      const view=current.view;let bearing=player.heading+view.lookDegrees;
      if(view.lookMode===1)bearing=current.windDirection;else if(view.lookMode===-1)bearing=current.windDirection+180;
      const target=view.lookMode===100?(poses[current.boats.findIndex(b=>b.id===view.otherBoat)]??poses[1]??player):player;
      const distance=view.viewpoint===2?300:view.viewpoint===3?180:95,height=view.viewpoint===3?240:view.viewpoint===2?115:52,angle=bearing*Math.PI/180;
      this.controls.target.set(target.x-player.x,12,target.y-player.y);this.camera.position.copy(this.controls.target).add(new THREE.Vector3(-Math.sin(angle)*distance,height,Math.cos(angle)*distance));this.controls.update();
    }
    const cameraDistance=this.camera.position.distanceTo(this.controls.target);this.water.visible=cameraDistance<5000;
    const near=Math.max(1,Math.min(500,cameraDistance/100));if(near!==this.camera.near){this.camera.near=near;this.camera.updateProjectionMatrix();}
    const visualTime=old.time+(current.time-old.time)*alpha;
    const animationTime=this.animationClock.sample(now);
    this.environment.update(current,{x:player.x,y:player.y},visualTime);
    for(let index=0;index<current.boats.length;index++){const model=this.models.get(current.boats[index].id);if(model){const pose=poses[index];model.group.position.set(pose.x-player.x,0,pose.y-player.y);model.group.rotation.y=-pose.heading*Math.PI/180;model.interpolate(this.paused?1:Math.min(1,Math.max(0,(now-this.modelReceived)/this.modelSpan)),current.boats[index],animationTime);}}
    // Camera and water presentation never mutate the native engine.
    const phase=this.paused?this.lastWaterPhase:current.time*.025;
    this.water.position.y=WATER_SURFACE_Y;
    const poseKey=poses.map(p=>`${p.x.toFixed(5)},${p.y.toFixed(5)},${p.heading.toFixed(4)}`).join('|');const poseChanged=poseKey!==this.lastPose;
    const changed=poseChanged||this.cameraDirty||phase!==this.lastWaterPhase;const start=performance.now();
    this.pollQueries();let query:WebGLQuery|null=null;
    if(this.gl&&this.queryExtension&&this.pendingQueries.length<8){query=this.gl.createQuery();if(query)this.gl.beginQuery(this.queryExtension.TIME_ELAPSED_EXT,query);}
    this.renderer.info.autoReset=false;this.renderer.info.reset();
    this.camera.updateMatrixWorld();this.course.project(this.camera,{x:player.x,y:player.y},this.width,this.height);
    this.renderer.render(this.scene,this.camera);
    this.minimap.render(current,poses,this.mode,now);
    this.labels.render(current,this.camera,this.models,this.course,now);
    if(query&&this.gl){this.gl.endQuery(this.queryExtension.TIME_ELAPSED_EXT);this.pendingQueries.push(query);}
    const info=this.renderer.info;const sample={intervalMs:this.lastDraw?now-this.lastDraw:0,cpuMs:performance.now()-start,changed,poseChanged,sequence:current.sequence,alpha,calls:'drawCalls' in info.render?info.render.drawCalls:info.render.calls,triangles:info.render.triangles};
    if(this.samples.length<4000)this.samples.push(sample);this.onSample(sample);this.lastDraw=now;this.lastPose=poseKey;this.cameraDirty=false;this.lastWaterPhase=phase;
  }
  private pollQueries(){if(!this.gl||!this.queryExtension)return;const gl=this.gl;const disjoint=gl.getParameter(this.queryExtension.GPU_DISJOINT_EXT);for(let i=this.pendingQueries.length-1;i>=0;i--){const query=this.pendingQueries[i];if(gl.getQueryParameter(query,gl.QUERY_RESULT_AVAILABLE)){if(!disjoint&&this.gpuMs.length<4000)this.gpuMs.push(gl.getQueryParameter(query,gl.QUERY_RESULT)/1e6);gl.deleteQuery(query);this.pendingQueries.splice(i,1);}else if(disjoint){gl.deleteQuery(query);this.pendingQueries.splice(i,1);}}}
  resetMetrics(){this.samples.length=0;this.gpuMs.length=0;this.modelCosts.length=0;this.modelBytes.length=0;this.modelBuildCosts.length=0;this.lastDraw=0;}
  dispose(){this.disposed=true;this.contactOverlay.dispose();this.environment.dispose();this.minimap.dispose();this.labels.dispose();for(const model of this.models.values())model.dispose();this.course.dispose();this.observer.disconnect();this.controls.dispose();for(const g of this.geometries)g.dispose();for(const m of this.materials)m.dispose();if(this.gl)for(const q of this.pendingQueries)this.gl.deleteQuery(q);this.renderer?.dispose();}
}
