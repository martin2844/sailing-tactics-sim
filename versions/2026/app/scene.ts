import * as THREE from 'three';
import {OrbitControls} from 'three/addons/controls/OrbitControls.js';
import {NativeBoatLayer} from './native-boat-layer';
import type {SceneSnapshot} from './protocol';
import {NativeBoatMesh} from './native-boat-mesh';
import type {NativeModelPacket} from './native-models';
export type Backend='webgl2'|'webgpu';
type Renderer=THREE.WebGLRenderer|import('three/webgpu').WebGPURenderer;
export interface RenderSample {intervalMs:number;cpuMs:number;changed:boolean;poseChanged:boolean;sequence:number;alpha:number;calls:number;triangles:number}
export class SailingScene {
  readonly scene=new THREE.Scene();readonly camera=new THREE.PerspectiveCamera(45,1,1,20000);
  private renderer!:Renderer;private controls:OrbitControls;private water:THREE.Mesh;
  private previous?:SceneSnapshot;private latest?:SceneSnapshot;private received=0;private span=40;private lastDraw=0;private lastPose='';private mode='chase';private paused=false;private disposed=false;private width=0;private height=0;
  private geometries=new Set<THREE.BufferGeometry>();private materials=new Set<THREE.Material>();private observer:ResizeObserver;
  private queryExtension:any;private pendingQueries:WebGLQuery[]=[];readonly gpuMs:number[]=[];private gl?:WebGL2RenderingContext;
  actualBackend='initializing';adapterInfo:unknown;readonly samples:RenderSample[]=[];private lastWaterPhase=-1;private cameraDirty=true;private origin=new THREE.Vector3();private nativeBoats:NativeBoatLayer;
  private models=new Map<number,NativeBoatMesh>();private modelMaterial:THREE.Material;private modelReceived=0;private modelSpan=40;modelSequence=0;hasModels=false;modelPacket?:NativeModelPacket;readonly modelCosts:number[]=[];readonly modelBytes:number[]=[];readonly modelBuildCosts:number[]=[];
  constructor(private canvas:HTMLCanvasElement,boatCanvas:HTMLCanvasElement,private onSample:(sample:RenderSample)=>void,private onFailure:(message:string)=>void){
    this.nativeBoats=new NativeBoatLayer(boatCanvas);
    boatCanvas.hidden=true;
    this.modelMaterial=this.material(new THREE.MeshStandardMaterial({vertexColors:true,flatShading:true,side:THREE.DoubleSide,roughness:.85}));
    this.scene.background=new THREE.Color('#afd8e4');this.scene.fog=new THREE.Fog('#afd8e4',1700,6500);
    this.scene.add(new THREE.HemisphereLight('#fff9eb','#1d627c',2.4));
    const sun=new THREE.DirectionalLight('#fff3dc',2.4);sun.position.set(-250,400,-200);this.scene.add(sun);
    this.controls=new OrbitControls(this.camera,canvas);this.controls.enableDamping=false;this.controls.minDistance=35;this.controls.maxDistance=3000;this.controls.maxPolarAngle=Math.PI*.48;this.controls.enablePan=false;
    this.controls.addEventListener('start',()=>{this.mode='orbit';});this.controls.addEventListener('change',()=>{this.cameraDirty=true;});
    this.camera.position.set(90,70,145);this.controls.target.set(0,12,0);this.controls.update();
    const geo=this.geometry(new THREE.PlaneGeometry(12000,12000,96,96).toNonIndexed());geo.rotateX(-Math.PI/2);
    // Presentation-only facets, independent of original wind/wave randomness.
    const position=geo.attributes.position;const colors=[];
    for(let i=0;i<position.count;i++){const x=position.getX(i),z=position.getZ(i);position.setY(i,Math.sin(x*.004+z*.007)*.6);const color=new THREE.Color('#177f9c');const face=Math.floor(i/3);color.multiplyScalar(.78+.24*(Math.sin(face*12.9898)+1)/2);colors.push(color.r,color.g,color.b);}
    geo.setAttribute('color',new THREE.Float32BufferAttribute(colors,3));geo.computeVertexNormals();
    this.water=new THREE.Mesh(geo,this.material(new THREE.MeshStandardMaterial({vertexColors:true,flatShading:true,roughness:.88,metalness:.05})));this.water.position.y=-1.5;this.scene.add(this.water);
    this.buildShore();
    this.observer=new ResizeObserver(()=>this.resize());this.observer.observe(canvas);
    canvas.addEventListener('webglcontextlost',event=>{event.preventDefault();this.onFailure('Graphics stopped. Restart to restore the scene.');});
  }
  private geometry<T extends THREE.BufferGeometry>(g:T):T{this.geometries.add(g);return g;}
  private material<T extends THREE.Material>(m:T):T{this.materials.add(m);return m;}
  private buildShore(){
    // Round Lake silhouette is an illustrative model, not extracted coastline.
    const ring=this.geometry(new THREE.RingGeometry(1650,4500,32,2));ring.rotateX(-Math.PI/2);
    const land=new THREE.Mesh(ring,this.material(new THREE.MeshStandardMaterial({color:'#567f56',flatShading:true,side:THREE.DoubleSide})));land.position.y=2;this.scene.add(land);
    const treeGeo=this.geometry(new THREE.ConeGeometry(18,65,5)),treeMaterial=this.material(new THREE.MeshStandardMaterial({color:'#345c47',flatShading:true}));
    const trees=new THREE.InstancedMesh(treeGeo,treeMaterial,64),matrix=new THREE.Matrix4();
    for(let i=0;i<64;i++){const angle=i/64*Math.PI*2,radius=1770+(i%5)*54;matrix.makeTranslation(Math.sin(angle)*radius,32,Math.cos(angle)*radius);trees.setMatrixAt(i,matrix);}this.scene.add(trees);
  }
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
  setCamera(mode:'chase'|'overview'){this.mode=mode;this.cameraDirty=true;this.controls.target.set(0,8,0);if(mode==='chase')this.camera.position.set(90,70,145);else this.camera.position.set(0,580,480);this.controls.update();}
  setPaused(value:boolean){this.paused=value;this.cameraDirty=true;}
  receive(value:SceneSnapshot){if(this.latest&&value.generation!==this.latest.generation){this.previous=undefined;this.latest=undefined;}const now=performance.now();this.span=this.latest?Math.max(1,now-this.received):40;this.previous=this.latest;this.latest=value;this.received=now;
    this.nativeBoats.receive(value.nativeVisuals);
  }
  receiveModels(value:{generation:number;sequence:number;packet:NativeModelPacket}){if(this.latest&&value.generation!==this.latest.generation)return;const p=value.packet,now=performance.now();this.modelPacket=p;this.modelSpan=this.hasModels?Math.max(1,now-this.modelReceived):40;this.modelReceived=now;this.modelSequence=value.sequence;
    for(let at=0;at<p.boats.length;at+=3){const id=p.boats[at];let model=this.models.get(id);if(!model){model=new NativeBoatMesh(this.modelMaterial);this.models.set(id,model);this.scene.add(model.group);}model.update(p,p.boats[at+1],p.boats[at+2]);}
    this.hasModels=true;if(this.modelCosts.length<4000){this.modelCosts.push(p.workMs);this.modelBytes.push(p.positions.byteLength+p.records.byteLength+p.colors.byteLength+p.boats.byteLength);this.modelBuildCosts.push(performance.now()-now);}this.cameraDirty=true;
  }
  reset(){for(const model of this.models.values())model.dispose();this.models.clear();this.hasModels=false;this.modelPacket=undefined;this.modelSequence=0;this.modelCosts.length=0;this.modelBytes.length=0;this.modelBuildCosts.length=0;this.nativeBoats.reset();this.previous=undefined;this.latest=undefined;this.lastPose='';this.lastDraw=0;}
  render(now:number){
    if(this.disposed||!this.renderer||!this.latest)return;
    if(this.lastDraw&&now-this.lastDraw<1000/60-.6)return;
    const current=this.latest,old=this.previous??current,alpha=this.paused?1:Math.min(1,Math.max(0,(now-this.received)/this.span));
    const poses=current.boats.map((boat,i)=>{const before=old.boats[i]??boat;const delta=((boat.heading-before.heading+540)%360)-180;return{x:before.x+(boat.x-before.x)*alpha,y:before.y+(boat.y-before.y)*alpha,heading:before.heading+delta*alpha};});
    const player=poses[0];this.origin.set(player.x,0,player.y);
    for(let index=0;index<current.boats.length;index++){const model=this.models.get(current.boats[index].id);if(model){const pose=poses[index];model.group.position.set(pose.x-player.x,0,pose.y-player.y);model.group.rotation.y=-pose.heading*Math.PI/180;model.interpolate(this.paused?1:Math.min(1,Math.max(0,(now-this.modelReceived)/this.modelSpan)));}}
    // Translate the shore in native world coordinates; water is effectively infinite.
    for(const child of this.scene.children)if(child instanceof THREE.InstancedMesh||child instanceof THREE.Mesh&&child.geometry.type==='RingGeometry'){child.position.x=-player.x;child.position.z=-player.y;}
    // Chase camera remains north-up in this bounded prototype; orbit never touches the engine.
    const phase=this.paused?this.lastWaterPhase:current.time*.025;
    this.water.position.y=-2.2+(phase>=0?Math.sin(phase)*.12:Math.sin(current.time*.025)*.12);
    const poseKey=poses.map(p=>`${p.x.toFixed(5)},${p.y.toFixed(5)},${p.heading.toFixed(4)}`).join('|');const poseChanged=poseKey!==this.lastPose;
    const changed=poseChanged||this.cameraDirty||phase!==this.lastWaterPhase;const start=performance.now();
    this.pollQueries();let query:WebGLQuery|null=null;
    if(this.gl&&this.queryExtension&&this.pendingQueries.length<8){query=this.gl.createQuery();if(query)this.gl.beginQuery(this.queryExtension.TIME_ELAPSED_EXT,query);}
    this.renderer.info.autoReset=false;this.renderer.info.reset();
    this.renderer.render(this.scene,this.camera);
    if(query&&this.gl){this.gl.endQuery(this.queryExtension.TIME_ELAPSED_EXT);this.pendingQueries.push(query);}
    const info=this.renderer.info;const sample={intervalMs:this.lastDraw?now-this.lastDraw:0,cpuMs:performance.now()-start,changed,poseChanged,sequence:current.sequence,alpha,calls:'drawCalls' in info.render?info.render.drawCalls:info.render.calls,triangles:info.render.triangles};
    if(this.samples.length<4000)this.samples.push(sample);this.onSample(sample);this.lastDraw=now;this.lastPose=poseKey;this.cameraDirty=false;this.lastWaterPhase=phase;
  }
  private pollQueries(){if(!this.gl||!this.queryExtension)return;const gl=this.gl;const disjoint=gl.getParameter(this.queryExtension.GPU_DISJOINT_EXT);for(let i=this.pendingQueries.length-1;i>=0;i--){const query=this.pendingQueries[i];if(gl.getQueryParameter(query,gl.QUERY_RESULT_AVAILABLE)){if(!disjoint&&this.gpuMs.length<4000)this.gpuMs.push(gl.getQueryParameter(query,gl.QUERY_RESULT)/1e6);gl.deleteQuery(query);this.pendingQueries.splice(i,1);}else if(disjoint){gl.deleteQuery(query);this.pendingQueries.splice(i,1);}}}
  resetMetrics(){this.samples.length=0;this.gpuMs.length=0;this.modelCosts.length=0;this.modelBytes.length=0;this.modelBuildCosts.length=0;this.lastDraw=0;}
  dispose(){this.disposed=true;for(const model of this.models.values())model.dispose();this.observer.disconnect();this.controls.dispose();for(const g of this.geometries)g.dispose();for(const m of this.materials)m.dispose();if(this.gl)for(const q of this.pendingQueries)this.gl.deleteQuery(q);this.renderer?.dispose();}
}
