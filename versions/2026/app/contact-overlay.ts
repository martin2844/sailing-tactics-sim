import * as THREE from 'three';
import type {SceneSnapshot} from './protocol';
import {snapshotBodies} from './contact-shapes';
import {world} from './contact-geometry';
export class ContactOverlay {
 readonly group=new THREE.Group();private geometry=new THREE.BufferGeometry();private material=new THREE.LineBasicMaterial({vertexColors:true,depthTest:false,transparent:true,opacity:.9});
 constructor(){const lines=new THREE.LineSegments(this.geometry,this.material);lines.frustumCulled=false;lines.renderOrder=20;this.group.add(lines);this.group.visible=false;}
 update(state:SceneSnapshot,origin:{x:number;y:number},poses:{x:number;y:number;heading:number}[]){if(!this.group.visible)return;const positions:number[]=[],colors:number[]=[];
  const line=(a:{x:number;y:number},b:{x:number;y:number},c:THREE.Color)=>{positions.push(a.x-origin.x,.65,a.y-origin.y,b.x-origin.x,.65,b.y-origin.y);colors.push(c.r,c.g,c.b,c.r,c.g,c.b);};
  for(const body of snapshotBodies(state)){const id=body.key.startsWith('boat-')?Number(body.key.slice(5)):0;if(id)body.pose=poses[id-1];const color=new THREE.Color(id?'#fff4b0':body.key==='committee'?'#fb9079':'#ffbc52');for(const part of body.parts){const points=part.kind==='polygon'?world(part.points,body.pose):Array.from({length:32},(_,i)=>({x:body.pose.x+Math.sin(i*Math.PI/16)*part.radius,y:body.pose.y+Math.cos(i*Math.PI/16)*part.radius}));for(let i=0;i<points.length;i++)line(points[i],points[(i+1)%points.length],color);}}
  const old=this.geometry.getAttribute('position') as THREE.BufferAttribute|undefined,oldColor=this.geometry.getAttribute('color') as THREE.BufferAttribute|undefined;
  if(old&&oldColor&&old.array.length===positions.length){(old.array as Float32Array).set(positions);(oldColor.array as Float32Array).set(colors);old.needsUpdate=true;oldColor.needsUpdate=true;}
  else{this.geometry.dispose();this.geometry.setAttribute('position',new THREE.Float32BufferAttribute(positions,3));this.geometry.setAttribute('color',new THREE.Float32BufferAttribute(colors,3));}
 }
 dispose(){this.geometry.dispose();this.material.dispose();this.group.removeFromParent();}
}
