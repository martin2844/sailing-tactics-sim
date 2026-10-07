import {Vector2,Vector3} from 'three';
import {triangulateSail} from './sail-triangulation';
export interface SailAnchor {point:Vector3;face:number;weights:[number,number,number]}
export type SailDetailSegment=[SailAnchor,SailAnchor];

/** Lift pen strokes onto the actual cloth faces, splitting at triangle edges.
 * Native batten curves can bulge through a triangulated3D sail. Cloth-plane
 * clipping preserves their layout and makes both sides share one surface. */
export class SailDetailSurface {
 readonly faces:number[][];
 private readonly plane:Vector2[];
 private readonly across:Vector3;
 private readonly up:Vector3;
 constructor(private readonly points:readonly Vector3[]){
  this.faces=triangulateSail(points);
  this.across=points.at(-1)!.clone().sub(points[0]).normalize();
  this.up=points.reduce((a,b)=>a.y>b.y?a:b).clone().sub(points[0]);
  this.up.addScaledVector(this.across,-this.up.dot(this.across)).normalize();
  this.plane=points.map(point=>this.project(point));
 }
 private project(point:Vector3):Vector2 {
  const offset=point.clone().sub(this.points[0]);return new Vector2(offset.dot(this.across),offset.dot(this.up));
 }
 segments(a:Vector3,b:Vector3):SailDetailSegment[]{
  const first=this.project(a),last=this.project(b),segments:SailDetailSegment[]=[];
  for(let face=0;face<this.faces.length;face++){
   const indices=this.faces[face],p=indices.map(i=>this.plane[i]);
   const denominator=(p[1].y-p[2].y)*(p[0].x-p[2].x)+(p[2].x-p[1].x)*(p[0].y-p[2].y);
   if(Math.abs(denominator)<1e-12)continue;
   const weights=(v:Vector2):[number,number,number]=>{
    const x=((p[1].y-p[2].y)*(v.x-p[2].x)+(p[2].x-p[1].x)*(v.y-p[2].y))/denominator;
    const y=((p[2].y-p[0].y)*(v.x-p[2].x)+(p[0].x-p[2].x)*(v.y-p[2].y))/denominator;return [x,y,1-x-y];
   };
   const from=weights(first),to=weights(last);let lo=0,hi=1;
   for(let i=0;i<3;i++){
    const delta=to[i]-from[i];
    if(Math.abs(delta)<1e-12){if(from[i]<-1e-7){hi=-1;break;}}
    else if(delta>0)lo=Math.max(lo,-from[i]/delta);else hi=Math.min(hi,-from[i]/delta);
   }
   if(hi-lo<1e-7)continue;
   const anchor=(t:number):SailAnchor=>{
    const w=from.map((v,i)=>v+(to[i]-v)*t) as [number,number,number];
    const point=new Vector3();for(let i=0;i<3;i++)point.addScaledVector(this.points[indices[i]],w[i]);return {point,face,weights:w};
   };
   segments.push([anchor(lo),anchor(hi)]);
  }
  return segments;
 }
}
