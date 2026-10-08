import * as THREE from 'three';
const sphere = new THREE.SphereGeometry(1, 8, 5).toNonIndexed().getAttribute('position');
export const vector = (x: number, y: number, z: number) => new THREE.Vector3(x, y, z);

/** Small triangle writer for merged, vertex-coloured study meshes. */
export class StudyMesh {
 private positions: number[] = [];
 private colours: number[] = [];
 triangle(a: THREE.Vector3, b: THREE.Vector3, c: THREE.Vector3, colour: THREE.Color) {
  for (const p of [a,b,c]) {this.positions.push(p.x,p.y,p.z); this.colours.push(colour.r,colour.g,colour.b);}
 }
 quad(a: THREE.Vector3, b: THREE.Vector3, c: THREE.Vector3, d: THREE.Vector3, colour: THREE.Color) {
  this.triangle(a,c,b,colour); this.triangle(a,d,c,colour);
 }
 rod(a: THREE.Vector3,b: THREE.Vector3,radius: number,colour: THREE.Color,endRadius=radius) {
  const axis=b.clone().sub(a).normalize();
  const u=new THREE.Vector3().crossVectors(axis,Math.abs(axis.y)>.9?vector(1,0,0):vector(0,1,0)).normalize();
  const v=new THREE.Vector3().crossVectors(axis,u);
  const ring=(center:THREE.Vector3,r:number)=>Array.from({length:8},(_,i)=>center.clone().addScaledVector(u,Math.cos(i*Math.PI/4)*r).addScaledVector(v,Math.sin(i*Math.PI/4)*r));
  const low=ring(a,radius),high=ring(b,endRadius);
  for(let i=0;i<8;i++){const j=(i+1)%8;this.quad(low[i],high[i],high[j],low[j],colour);this.triangle(a,low[j],low[i],colour);this.triangle(b,high[i],high[j],colour);}
 }
 box(center: THREE.Vector3,size: THREE.Vector3,colour: THREE.Color) {
  const p=Array.from({length:8},(_,i)=>center.clone().add(vector((i&1?1:-1)*size.x/2,(i&2?1:-1)*size.y/2,(i&4?1:-1)*size.z/2)));
  for(const [a,b,c,d] of [[0,1,3,2],[4,6,7,5],[0,4,5,1],[2,3,7,6],[0,2,6,4],[1,5,7,3]])this.quad(p[a],p[b],p[c],p[d],colour);
 }
 ellipsoid(center:THREE.Vector3,scale:THREE.Vector3,colour:THREE.Color) {
  for(let i=0;i<sphere.count;i+=3){const p=[0,1,2].map(j=>new THREE.Vector3().fromBufferAttribute(sphere,i+j).multiply(scale).add(center));this.triangle(p[0],p[1],p[2],colour);}
 }
 write(geometry: THREE.BufferGeometry) {
  const positions=Float32Array.from(this.positions),colours=Float32Array.from(this.colours);
  const before=geometry.getAttribute('position');
  if(before&&before.count===positions.length/3){before.array.set(positions);before.needsUpdate=true;const color=geometry.getAttribute('color');color.array.set(colours);color.needsUpdate=true;}
  else {geometry.dispose();geometry.deleteAttribute('normal');geometry.setAttribute('position',new THREE.BufferAttribute(positions,3));geometry.setAttribute('color',new THREE.BufferAttribute(colours,3));}
  geometry.computeVertexNormals();geometry.computeBoundingSphere();
 }
}
