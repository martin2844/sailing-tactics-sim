import * as THREE from 'three';
const sphere = new THREE.SphereGeometry(1, 8, 5).toNonIndexed().getAttribute('position');
const rodAxis=new THREE.Vector3(),rodU=new THREE.Vector3(),rodV=new THREE.Vector3(),rodReference=new THREE.Vector3();
const rodRing=Array.from({length:16},()=>new THREE.Vector3());
const rodAngles=Array.from({length:8},(_,i)=>[Math.cos(i*Math.PI/4),Math.sin(i*Math.PI/4)]);
export const vector = (x: number, y: number, z: number) => new THREE.Vector3(x, y, z);

/** Small triangle writer for merged, vertex-coloured study meshes. */
export class StudyMesh {
 private positions: number[] = [];
 private colours: number[] = [];
 get coordinateCount(){return this.positions.length;}
 writePositions(geometry:THREE.BufferGeometry,offset:number){
  const position=geometry.getAttribute('position'),normal=geometry.getAttribute('normal');position.array.set(this.positions,offset);
  // Reorient the two flexible sheets' flat normals without scanning the rig.
  for(let i=0;i<this.positions.length;i+=9){
   rodAxis.fromArray(this.positions,i+3).sub(rodU.fromArray(this.positions,i));
   rodV.fromArray(this.positions,i+6).sub(rodU);rodAxis.cross(rodV).normalize();
   for(let j=0;j<9;j+=3)normal.setXYZ((offset+i+j)/3,rodAxis.x,rodAxis.y,rodAxis.z);
  }
  position.needsUpdate=true;normal.needsUpdate=true;
 }
 triangle(a: THREE.Vector3, b: THREE.Vector3, c: THREE.Vector3, colour: THREE.Color) {
  for (const p of [a,b,c]) {this.positions.push(p.x,p.y,p.z); this.colours.push(colour.r,colour.g,colour.b);}
 }
 quad(a: THREE.Vector3, b: THREE.Vector3, c: THREE.Vector3, d: THREE.Vector3, colour: THREE.Color) {
  this.triangle(a,c,b,colour); this.triangle(a,d,c,colour);
 }
 rod(a: THREE.Vector3,b: THREE.Vector3,radius: number,colour: THREE.Color,endRadius=radius) {
  // Emission copies each coordinate, so these scratch vectors can be reused.
  // This avoids allocating thousands of temporary vectors per animated rig.
  rodAxis.copy(b).sub(a).normalize();
  rodReference.set(Math.abs(rodAxis.y)>.9?1:0,Math.abs(rodAxis.y)>.9?0:1,0);
  rodU.crossVectors(rodAxis,rodReference).normalize();rodV.crossVectors(rodAxis,rodU);
  for(let i=0;i<8;i++){
   const [cos,sin]=rodAngles[i];
   const x=rodU.x*cos+rodV.x*sin,y=rodU.y*cos+rodV.y*sin,z=rodU.z*cos+rodV.z*sin;
   rodRing[i].set(a.x+x*radius,a.y+y*radius,a.z+z*radius);
   rodRing[i+8].set(b.x+x*endRadius,b.y+y*endRadius,b.z+z*endRadius);
  }
  for(let i=0;i<8;i++){const j=(i+1)%8;this.quad(rodRing[i],rodRing[i+8],rodRing[j+8],rodRing[j],colour);this.triangle(a,rodRing[j],rodRing[i],colour);this.triangle(b,rodRing[i+8],rodRing[j+8],colour);}
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
