import * as THREE from 'three';
import type {BoatModel} from './boat-model';
import {OPTIMIST_HULL_STATIONS} from './models/optimist-spec';
import {OPTIMIST_WORLD_SCALE} from './models/optimist-boat-mesh';

/** Keep the water surface outside the open Optimist hull, without changing
 * its measured interior or lifting it artificially above the water. */
export class OptimistWaterMask {
 private boats = {value:Array.from({length:30},()=>new THREE.Vector4())};
 private count = {value:0};
 constructor(material:THREE.MeshStandardMaterial){
  material.onBeforeCompile=shader=>{
   shader.uniforms.optimistHulls=this.boats;shader.uniforms.optimistCount=this.count;
   shader.vertexShader='varying vec3 waterWorld;\n'+shader.vertexShader;
   shader.vertexShader=shader.vertexShader.replace('#include <worldpos_vertex>','#include <worldpos_vertex>\nwaterWorld=(modelMatrix*vec4(transformed,1.0)).xyz;');
   shader.fragmentShader=`
    varying vec3 waterWorld;
    uniform vec4 optimistHulls[30];
    uniform int optimistCount;
    // z, gunwale half-width/height, chine half-width/height, in metres.
    vec4 hullSection(float z){
     ${OPTIMIST_HULL_STATIONS.slice(0,-1).map((station,i)=>{
      const next=OPTIMIST_HULL_STATIONS[i+1],float=(n:number)=>Number(n).toFixed(6);
      return `if(z<${float(next[0])})return mix(vec4(${station.slice(1).map(float).join(',')}),vec4(${next.slice(1).map(float).join(',')}),clamp((z-(${float(station[0])}))/${float(next[0]-station[0])},0.0,1.0));`;
     }).join('\n')}
     return vec4(${OPTIMIST_HULL_STATIONS.at(-1)!.slice(1).map(n=>n.toFixed(6)).join(',')});
    }
   `+shader.fragmentShader;
   shader.fragmentShader=shader.fragmentShader.replace('#include <clipping_planes_fragment>',`#include <clipping_planes_fragment>
    for(int i=0;i<30;i++){
     if(i>=optimistCount)break;
     vec4 hull=optimistHulls[i];
     vec2 delta=(waterWorld.xz-hull.xy)/${OPTIMIST_WORLD_SCALE.toFixed(12)};
     if(dot(delta,delta)>1.9)continue;
     float c=cos(hull.z),s=sin(hull.z);
     vec2 local=vec2(delta.x*c-delta.y*s,delta.x*s+delta.y*c);
     if(abs(local.y)>1.18)continue;
     float y=.13-local.x*sin(hull.w);
     float x=local.x*cos(hull.w);
     vec4 section=hullSection(local.y);
     float width=mix(section.z,section.x,clamp((y-section.w)/(section.y-section.w),0.0,1.0));
     if(y>=section.w&&y<=section.y&&abs(x)<width)discard;
    }
   `);
  };
  material.customProgramCacheKey=()=> 'optimist-open-hull-v1';
 }
 update(models:Iterable<BoatModel>){
  let count=0;
  for(const model of models){
   if(model.waterHullHeel===undefined)continue;
   if(count===this.boats.value.length)break;
   this.boats.value[count++].set(model.group.position.x,model.group.position.z,model.group.rotation.y,model.waterHullHeel);
  }
  this.count.value=count;
 }
}
