import * as THREE from 'three';
import {OPTIMIST, DEFAULT_OPTIMIST_POSE, type OptimistPose} from './optimist-spec';
import {StudyMesh,vector as V} from './study-mesh';
const C=(hex:string)=>new THREE.Color(hex);
const white=C('#e5e9e8'),inside=C('#cbd3d3'),rim=C('#eaf0ed'),bag=C('#909da3');
const spar=C('#4c555b'),rope=C('#526974'),navy=C('#26343f'),jersey=C('#6b7b85'),skin=C('#ac8872'),hair=C('#35312e');
const U=[0,.1,.2,.4,.6,.8,1],T=[0,.1,.2,.4,.6,.8,1];

/** Isolated visual prototype. No imports into the playable fleet or engine. */
export class OptimistStudy {
 readonly group=new THREE.Group();
 private material=new THREE.MeshStandardMaterial({vertexColors:true,roughness:.78,flatShading:true,side:THREE.DoubleSide});
 private glassMaterial=new THREE.MeshStandardMaterial({color:'#9eafba',roughness:.28,transparent:true,opacity:.24,depthWrite:false,side:THREE.DoubleSide});
 readonly hull=new THREE.Mesh(new THREE.BufferGeometry(),this.material);
 readonly rig=new THREE.Mesh(new THREE.BufferGeometry(),this.material);
 readonly sailor=new THREE.Mesh(new THREE.BufferGeometry(),this.material);
 readonly window=new THREE.Mesh(new THREE.BufferGeometry(),this.glassMaterial);
 private pose:OptimistPose={...DEFAULT_OPTIMIST_POSE};
 private tack=1;
 constructor(){
  this.group.add(this.hull,this.rig,this.sailor,this.window);
  for(const mesh of [this.hull,this.rig,this.sailor]){mesh.castShadow=true;mesh.receiveShadow=true;}
  // Thin double-sided cloth self-shadows produce acne at these dimensions.
  // It still casts a shadow onto the hull; its own facets receive direct light.
  this.rig.receiveShadow=false;
  this.buildHull();this.update(this.pose);
 }
 private buildHull(){
  const mesh=new StudyMesh();
  // z, sheer half-width, sheer height, chine half-width, chine height.
  const stations=[[-1.18,.38,.37,.32,.13],[-.65,.515,.335,.445,.025],[0,.56,.32,.48,0],[.65,.535,.325,.455,.025],[1.18,.47,.34,.4,.09]];
  const contour=[...stations.map(([z,w,y])=>V(w,y,z)),...stations.slice().reverse().map(([z,w,y])=>V(-w,y,z))];
  const chine=[...stations.map(([z,,,w,y])=>V(w,y,z< -1?-1.07:z>1?1.15:z)),...stations.slice().reverse().map(([z,,,w,y])=>V(-w,y,z< -1?-1.07:z>1?1.15:z))];
  const inset=contour.map(p=>V(p.x-Math.sign(p.x)*.023,p.y-.005,p.z+(p.z< -1?.023:p.z>1?-.023:0)));
  const floor=chine.map(p=>V(p.x-Math.sign(p.x)*.018,p.y+.027,p.z+(p.z< -1?.02:p.z>1?-.02:0)));
  for(let i=0;i<contour.length;i++){const j=(i+1)%contour.length;
   mesh.quad(contour[i],chine[i],chine[j],contour[j],white);
   mesh.quad(contour[i],contour[j],inset[j],inset[i],rim);
   mesh.quad(inset[i],inset[j],floor[j],floor[i],inside);
   const rail=(p:THREE.Vector3)=>V(p.x-Math.sign(p.x)*.009,p.y,p.z+(p.z< -1?.009:p.z>1?-.009:0));
   mesh.rod(rail(contour[i]),rail(contour[j]),.009,rim);
  }
  for(let i=0;i<stations.length-1;i++){const j=9-i;mesh.quad(chine[i],chine[j],chine[j-1],chine[i+1],white);mesh.quad(floor[i],floor[i+1],floor[j-1],floor[j],inside);}
  mesh.box(V(0,.325,-.72),V(.96,.035,.12),white);
  mesh.box(V(0,.155,-.15),V(.046,.24,.35),white);
  mesh.box(V(0,.10,-.3),V(.88,.055,.055),white);
  mesh.box(V(0,-.26,-.15),V(.018,.61,.27),C('#b8b4a0'));
  mesh.box(V(0,-.17,1.30),V(.027,.77,.22),C('#b9a77e'));
  mesh.box(V(0,.287,1.30),V(.027,.15,.17),C('#b9a77e')); // Rudder head joins blade, upper fitting and tiller.
  for(const y of [.17,.30])mesh.rod(V(-.027,y,1.18),V(-.027,y,1.34),.012,spar);
  mesh.rod(V(0,.36,1.37),V(0,.405,.35),.012,spar);
  mesh.ellipsoid(V(0,.18,-.93),V(.36,.12,.15),bag);
  for(const side of [-1,1]){
   mesh.ellipsoid(V(side*.35,.16,.46),V(.09,.105,.46),bag);
   for(const z of [.19,.72])mesh.rod(V(side*.26,.22,z),V(side*.44,.21,z),.008,spar);
   mesh.box(V(side*.17,.08,.57),V(.044,.012,.75),navy);
  }
  mesh.write(this.hull.geometry);
 }
 private buildSailor(side:number){
  const mesh=new StudyMesh();
  const at=(x:number,y:number,z:number)=>V(side*x,y,z);
  const hip=at(.54,.365,.36),shoulder=at(.63,.73,.34);
  const axis=shoulder.clone().sub(hip).normalize(),cross=V(0,0,1),depth=new THREE.Vector3().crossVectors(axis,cross).normalize();
  const rings=[{c:hip,w:.12,d:.075},{c:hip.clone().lerp(shoulder,.76),w:.155,d:.10},{c:shoulder,w:.135,d:.075}].map(({c,w,d})=>Array.from({length:8},(_,i)=>c.clone().addScaledVector(cross,Math.cos(i*Math.PI/4)*w).addScaledVector(depth,Math.sin(i*Math.PI/4)*d)));
  for(let r=0;r<2;r++)for(let i=0;i<8;i++){const j=(i+1)%8;mesh.quad(rings[r][i],rings[r+1][i],rings[r+1][j],rings[r][j],navy);}
  for(let i=0;i<8;i++)mesh.triangle(shoulder,rings[2][i],rings[2][(i+1)%8],navy);
  for(const dz of [-.115,.115]){
   const h=at(.52,.36,.36+dz),knee=at(.26,.31,.36+dz),foot=at(.10,.085,.42+dz);
   mesh.rod(h,knee,.069,navy,.061);mesh.ellipsoid(knee,V(.062,.061,.06),navy);mesh.rod(knee,foot,.052,navy,.033);mesh.ellipsoid(foot,V(.08,.039,.046),C('#272c31'));
   const arm=shoulder.clone().add(V(0,0,dz*1.25)),elbow=at(.49,.535,.36+dz*1.8),hand=at(.275,.46,.36+dz*1.7);
   mesh.rod(arm,elbow,.044,jersey,.035);mesh.rod(elbow,hand,.037,jersey,.026);mesh.ellipsoid(hand,V(.042,.024,.033),skin);
  }
  mesh.rod(shoulder,at(.63,.80,.34),.037,skin);
  mesh.ellipsoid(at(.635,.866,.335),V(.075,.104,.074),skin);
  mesh.ellipsoid(at(.646,.920,.341),V(.078,.063,.079),hair);
  mesh.ellipsoid(at(.564,.872,.335),V(.022,.019,.02),skin);
  mesh.write(this.sailor.geometry);
 }
 update(patch:Partial<OptimistPose>){
  const old=this.pose;this.pose={...old,...patch};const pose=this.pose;
  this.group.rotation.z=THREE.MathUtils.degToRad(pose.heel);
  this.sailor.visible=pose.crew;
  const tack=pose.trim===0?this.tack:Math.sign(pose.trim);
  if(!this.sailor.geometry.getAttribute('position')||tack!==this.tack)this.buildSailor(-tack);
  this.tack=tack;
  if(this.rig.geometry.getAttribute('position')&&old.trim===pose.trim&&old.luff===pose.luff&&old.penalty===pose.penalty&&(pose.luff===0||old.time===pose.time))return;
  const mesh=new StudyMesh(),glass=new StudyMesh();
  const trim=THREE.MathUtils.degToRad(pose.trim),origin=V(0,OPTIMIST.tackHeight,OPTIMIST.mastZ);
  const transform=(p:THREE.Vector3)=>p.applyAxisAngle(V(0,1,0),trim).add(origin);
  const raw=(u:number,v:number)=>{
   const {tack,throat,peak,clew}=OPTIMIST.sail;
   const width=THREE.MathUtils.lerp(THREE.MathUtils.lerp(tack[0],clew[0],u),THREE.MathUtils.lerp(throat[0],peak[0],u),v);
   const height=THREE.MathUtils.lerp(THREE.MathUtils.lerp(tack[1],clew[1],u),THREE.MathUtils.lerp(throat[1],peak[1],u),v);
   const billow=this.tack*(.055*(1-pose.luff)+pose.luff*.016*Math.sin(pose.time*9+v*7))*Math.sin(Math.PI*u)*Math.sin(Math.PI*v);
   return transform(V(billow,height,width));
  };
  const points=T.map(v=>U.map(u=>raw(u,v)));
  const cloth=pose.penalty?C('#171b20'):C('#e9e9e1');
  for(let j=0;j<T.length-1;j++)for(let i=0;i<U.length-1;i++){
   const writer=i===2&&j===1?glass:mesh;
   writer.quad(points[j][i],points[j][i+1],points[j+1][i+1],points[j+1][i],cloth);
  }
  // Sample the emitted triangle plane for details; never place them on an
  // independent smooth surface that could disappear through the cloth.
  const surface=(u:number,v:number)=>{
   const i=Math.max(0,U.findIndex((n,i)=>i<U.length-1&&u<=U[i+1])),j=Math.max(0,T.findIndex((n,j)=>j<T.length-1&&v<=T[j+1]));
   const a=(u-U[i])/(U[i+1]-U[i]),b=(v-T[j])/(T[j+1]-T[j]);
   return a>=b?points[j][i].clone().multiplyScalar(1-a).addScaledVector(points[j][i+1],a-b).addScaledVector(points[j+1][i+1],b):points[j][i].clone().multiplyScalar(1-b).addScaledVector(points[j+1][i+1],a).addScaledVector(points[j+1][i],b-a);
  };
  const stroke=(a:number[],b:number[],radius:number,colour:THREE.Color)=>{const steps=24;for(let i=0;i<steps;i++)mesh.rod(surface(a[0]+(b[0]-a[0])*i/steps,a[1]+(b[1]-a[1])*i/steps),surface(a[0]+(b[0]-a[0])*(i+1)/steps,a[1]+(b[1]-a[1])*(i+1)/steps),radius,colour);};
  for(const v of [.3,.65])stroke([.76,v],[1,v],.0035,C('#d1d6d4'));
  // Lay the insignia out in metres, not UVs: the tapered sail must not
  // stretch its circle into an oval or skew the vertical stem.
  const metric=(width:number,height:number)=>{
   let u=.5,v=.75;
   const {throat,peak,clew}=OPTIMIST.sail;
   for(let n=0;n<8;n++){
    const wu=clew[0]+(peak[0]-clew[0])*v,wv=(peak[0]-clew[0])*u;
    const hu=clew[1]+(peak[1]-throat[1]-clew[1])*v,hv=throat[1]+(peak[1]-throat[1]-clew[1])*u;
    const dw=u*wu-width,dh=clew[1]*u*(1-v)+(throat[1]+(peak[1]-throat[1])*u)*v-height,det=wu*hv-wv*hu;
    u-=(dw*hv-dh*wv)/det;v-=(wu*dh-hu*dw)/det;
   }
   return surface(u,v);
  };
  const ink=C('#324861');
  for(let i=0;i<32;i++){const a=i*Math.PI/16,b=(i+1)*Math.PI/16;mesh.rod(metric(.90+.13*Math.cos(a),1.94+.13*Math.sin(a)),metric(.90+.13*Math.cos(b),1.94+.13*Math.sin(b)),.007,ink);}
  for(let i=0;i<16;i++)mesh.rod(metric(.90,1.965-i*.018),metric(.90,1.965-(i+1)*.018),.007,ink);
  const foot=raw(1,0),peak=raw(1,1),throat=raw(0,1);
  mesh.rod(V(0,OPTIMIST.mastStep,OPTIMIST.mastZ),V(0,OPTIMIST.mastStep+OPTIMIST.mastLength,OPTIMIST.mastZ),.022,spar);
  mesh.rod(origin,foot,.014,spar);
  mesh.rod(transform(V(0,.5,0)),peak,.012,spar);
  mesh.rod(V(0,.19,OPTIMIST.mastZ),raw(.2,0),.003,rope);
  mesh.rod(raw(.53,0),V(0,.26,.13),.003,rope);mesh.rod(V(0,.26,.13),V(-this.tack*.275,.46,.165),.003,rope);
  mesh.rod(V(0,.405,.35),V(-this.tack*.275,.46,.55),.005,spar);
  for(let i=0;i<=7;i++){
   const p=raw(0,i/7);mesh.rod(p.clone().add(V(-.025,0,0)),p.clone().add(V(.025,0,0)),.002,rope);
   const f=raw(i/7,0);mesh.rod(f.clone().add(V(0,-.018,0)),f.clone().add(V(0,.018,0)),.002,rope);
  }
  const flag=throat.clone().add(V(0,.16,0));mesh.rod(throat,flag,.0018,spar);mesh.triangle(flag,flag.clone().add(V(.1,.014,0)),flag.clone().add(V(.07,.038,0)),C('#964740'));
  mesh.write(this.rig.geometry);glass.write(this.window.geometry);
 }
 dispose(){for(const m of [this.hull,this.rig,this.sailor,this.window])m.geometry.dispose();this.material.dispose();this.glassMaterial.dispose();this.group.removeFromParent();}
}
