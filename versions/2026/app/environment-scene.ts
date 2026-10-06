import * as THREE from 'three';
import type {NativeTerrain} from './native-environment';
import type {SceneSnapshot} from './protocol';
import {buildCoastalLand,type CoastalLand} from './coastal-land';
import {mergeGeometries} from 'three/addons/utils/BufferGeometryUtils.js';
/** Native coast / gust positions; low-poly land and wave artwork. */
export class EnvironmentScene {
 readonly group=new THREE.Group();private land=new THREE.Group();private gusts:THREE.Mesh[]=[];
 private material=new THREE.MeshStandardMaterial({vertexColors:true,flatShading:true,side:THREE.DoubleSide,roughness:1});
 private treeMaterial=new THREE.MeshStandardMaterial({vertexColors:true,flatShading:true,roughness:1});private rockMaterial=new THREE.MeshStandardMaterial({color:'#7e877b',flatShading:true,roughness:1});
 private treeGeometry:THREE.BufferGeometry;private rockGeometry=new THREE.IcosahedronGeometry(1,0);
 private terrainResources:{dispose:()=>void}[]=[];readonly surfaces:CoastalLand[]=[];private lighthouse?:THREE.Group;
 private gustMaterial=new THREE.MeshBasicMaterial({color:'#1d5d75',transparent:true,opacity:.2,depthWrite:false});
 private gustGeometry=new THREE.CircleGeometry(1,24);private waveGeometry=new THREE.PlaneGeometry(8,.28);private waveMaterial=new THREE.MeshBasicMaterial({color:'#b4e0e4',transparent:true,opacity:.35,depthWrite:false});
 private waves:THREE.InstancedMesh;private matrix=new THREE.Matrix4();private position=new THREE.Vector3();private scale=new THREE.Vector3();private quaternion=new THREE.Quaternion();
 terrain?:NativeTerrain;
 constructor(){
  const pieces=[new THREE.CylinderGeometry(1.5,2,14,5).translate(0,7,0),new THREE.ConeGeometry(9,23,6).translate(0,20,0),new THREE.ConeGeometry(6.5,20,6).translate(0,29,0)].map((g,i)=>{const geometry=g.toNonIndexed(),color=new THREE.Color(i?'#365f45':'#746451');geometry.setAttribute('color',new THREE.Float32BufferAttribute(Array.from({length:geometry.attributes.position.count},()=>[color.r,color.g,color.b]).flat(),3));g.dispose();return geometry;});
  this.treeGeometry=mergeGeometries(pieces)!;for(const g of pieces)g.dispose();
  this.group.add(this.land);this.gustGeometry.rotateX(-Math.PI/2);this.waveGeometry.rotateX(-Math.PI/2);for(let n=0;n<5;n++){const m=new THREE.Mesh(this.gustGeometry,this.gustMaterial);m.visible=false;this.gusts.push(m);this.group.add(m);}this.waves=new THREE.InstancedMesh(this.waveGeometry,this.waveMaterial,128);this.waves.instanceMatrix.setUsage(THREE.DynamicDrawUsage);this.waves.frustumCulled=false;this.group.add(this.waves);
 }
 setTerrain(data:NativeTerrain){this.resetLand();this.terrain=data;
  const locations:{x:number;y:number;surface:CoastalLand}[]=[];
  for(const polygon of data.polygons){const surface=buildCoastalLand(polygon);this.surfaces.push(surface);this.terrainResources.push(surface.geometry);this.land.add(new THREE.Mesh(surface.geometry,this.material));const stride=Math.max(1,Math.ceil(surface.sites.length/Math.max(12,Math.floor(160/data.polygons.length))));for(let i=0;i<surface.sites.length;i+=stride)if(locations.length<160)locations.push({...surface.sites[i],surface});}
  const trees=new THREE.InstancedMesh(this.treeGeometry,this.treeMaterial,locations.length),rocks=new THREE.InstancedMesh(this.rockGeometry,this.rockMaterial,Math.min(40,locations.length));
  this.terrainResources.push(trees,rocks);this.land.add(trees,rocks);
  locations.forEach((p,i)=>{const scale=.65+(Math.sin(p.x*.07+p.y*.11)+1)*.25;this.position.set(p.x,p.surface.height(p),p.y);this.scale.setScalar(scale);this.quaternion.setFromAxisAngle(new THREE.Vector3(0,1,0),p.x*.01);this.matrix.compose(this.position,this.quaternion,this.scale);trees.setMatrixAt(i,this.matrix);if(i<rocks.count){this.position.set(p.x+12,p.surface.height(p)+2,p.y+4);this.scale.set(7,5,6);this.matrix.compose(this.position,this.quaternion,this.scale);rocks.setMatrixAt(i,this.matrix);}});
  trees.instanceMatrix.needsUpdate=true;rocks.instanceMatrix.needsUpdate=true;
  const native=data.landmarks?.find(p=>this.surfaces.some(s=>s.contains(p))),fallback=locations.find(p=>p.surface.height(p)>15),site=native??fallback;
  if(site){const surface=this.surfaces.find(s=>s.contains(site))!;this.lighthouse=this.buildLighthouse();this.lighthouse.position.set(site.x,surface.height(site),site.y);this.land.add(this.lighthouse);}
 }
 private buildLighthouse(){
  const group=new THREE.Group(),resource=<T extends {dispose:()=>void}>(v:T)=>{this.terrainResources.push(v);return v;},white=resource(new THREE.MeshStandardMaterial({color:'#eef0e7',flatShading:true,roughness:.8})),red=resource(new THREE.MeshStandardMaterial({color:'#a24937',flatShading:true,roughness:.9})),dark=resource(new THREE.MeshStandardMaterial({color:'#293e3d',flatShading:true,roughness:.8}));
  const piece=(g:THREE.BufferGeometry,m:THREE.Material,y:number)=>{const mesh=new THREE.Mesh(resource(g),m);mesh.position.y=y;group.add(mesh);};
  piece(new THREE.CylinderGeometry(10,12,4,10),dark,2);piece(new THREE.CylinderGeometry(6,9,50,10),white,28);piece(new THREE.CylinderGeometry(6.8,7.4,8,10),red,33);piece(new THREE.CylinderGeometry(9.5,9.5,2,10),dark,54);piece(new THREE.CylinderGeometry(5,5,8,8),dark,59);piece(new THREE.ConeGeometry(10,9,10),red,67);
  return group;
 }
 update(state:SceneSnapshot,origin:{x:number;y:number},time:number){this.group.position.set(-origin.x,0,-origin.y);
  const patches=state.environment?.gusts??[];for(let n=0;n<this.gusts.length;n++){const p=patches[n],m=this.gusts[n];m.visible=!!p&&p.strength>0;if(p){m.position.set(p.x,-1.85,p.y);m.scale.set(p.width,1,p.width);}}
  const conditions=state.environment?.waves??1,wind=state.windDirection*Math.PI/180,sin=Math.sin(wind),cos=Math.cos(wind),travel=time*(1.2+Math.min(5,conditions)*.5),tile=1600;
  // Fixed native-world cells, deterministic offsets and the native clock. A
  // pause/freeze stops them; camera movement cannot advance their phase.
  for(let n=0;n<128;n++){const x0=(n%16)*100+(n%7)*8,z0=Math.floor(n/16)*200+(n%11)*9,x=origin.x+(((x0+sin*travel-origin.x)%tile+tile)%tile)-tile/2,z=origin.y+(((z0-cos*travel-origin.y)%tile+tile)%tile)-tile/2,crest=Math.sin(time*1.8+n*1.7);
   this.position.set(x,-1.95+Math.max(0,crest)*Math.min(.7,conditions*.13),z);this.scale.set(1+conditions*.25,.4+Math.max(0,crest)*.8,1);this.quaternion.setFromAxisAngle(new THREE.Vector3(0,1,0),-wind);this.matrix.compose(this.position,this.quaternion,this.scale);this.waves.setMatrixAt(n,this.matrix);}
  this.waves.instanceMatrix.needsUpdate=true;
 }
 private resetLand(){for(const r of this.terrainResources)r.dispose();this.terrainResources.length=0;this.land.clear();this.surfaces.length=0;this.lighthouse=undefined;}
 reset(){this.resetLand();this.terrain=undefined;for(const gust of this.gusts)gust.visible=false;}
 dispose(){this.resetLand();this.group.removeFromParent();this.material.dispose();this.treeMaterial.dispose();this.treeGeometry.dispose();this.rockMaterial.dispose();this.rockGeometry.dispose();this.gustMaterial.dispose();this.gustGeometry.dispose();this.waveGeometry.dispose();this.waveMaterial.dispose();this.waves.dispose();}
}
