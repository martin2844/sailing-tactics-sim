import * as THREE from 'three';
import type {NativeTerrain} from './native-environment';
import type {SceneSnapshot} from './protocol';
/** Native coast / gust positions; low-poly land and wave artwork. */
export class EnvironmentScene {
 readonly group=new THREE.Group();private land=new THREE.Group();private gusts:THREE.Mesh[]=[];
 private material=new THREE.MeshStandardMaterial({color:'#68845b',flatShading:true,side:THREE.DoubleSide,roughness:1});
 private gustMaterial=new THREE.MeshBasicMaterial({color:'#1d5d75',transparent:true,opacity:.2,depthWrite:false});
 private gustGeometry=new THREE.CircleGeometry(1,24);private waveGeometry=new THREE.PlaneGeometry(8,.28);private waveMaterial=new THREE.MeshBasicMaterial({color:'#b4e0e4',transparent:true,opacity:.35,depthWrite:false});
 private waves:THREE.InstancedMesh;private matrix=new THREE.Matrix4();private position=new THREE.Vector3();private scale=new THREE.Vector3();private quaternion=new THREE.Quaternion();
 terrain?:NativeTerrain;
 constructor(){this.group.add(this.land);this.gustGeometry.rotateX(-Math.PI/2);this.waveGeometry.rotateX(-Math.PI/2);for(let n=0;n<5;n++){const m=new THREE.Mesh(this.gustGeometry,this.gustMaterial);m.visible=false;this.gusts.push(m);this.group.add(m);}this.waves=new THREE.InstancedMesh(this.waveGeometry,this.waveMaterial,128);this.waves.instanceMatrix.setUsage(THREE.DynamicDrawUsage);this.waves.frustumCulled=false;this.group.add(this.waves);}
 setTerrain(data:NativeTerrain){this.resetLand();this.terrain=data;
  for(const polygon of data.polygons){const points=polygon.points.map(p=>new THREE.Vector2(p.x,-p.y));let shape:THREE.Shape;
   if(polygon.landInside)shape=new THREE.Shape(points);
   else{shape=new THREE.Shape([new THREE.Vector2(-30000,-30000),new THREE.Vector2(30000,-30000),new THREE.Vector2(30000,30000),new THREE.Vector2(-30000,30000)]);shape.holes.push(new THREE.Path(points));}
   const geometry=new THREE.ExtrudeGeometry(shape,{depth:5,bevelEnabled:false,curveSegments:1});geometry.rotateX(-Math.PI/2);const mesh=new THREE.Mesh(geometry,this.material);mesh.position.y=-3;this.land.add(mesh);
  }
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
 private resetLand(){for(const object of [...this.land.children]){(object as THREE.Mesh).geometry.dispose();object.removeFromParent();}}
 reset(){this.resetLand();this.terrain=undefined;for(const gust of this.gusts)gust.visible=false;}
 dispose(){this.resetLand();this.group.removeFromParent();this.material.dispose();this.gustMaterial.dispose();this.gustGeometry.dispose();this.waveGeometry.dispose();this.waveMaterial.dispose();this.waves.dispose();}
}
