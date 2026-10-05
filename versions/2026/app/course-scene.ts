import * as THREE from 'three';
import type {NativeCourse,BoatView,CourseLine} from './protocol';
/** Presentation objects at native coordinates. Their shapes are modern artwork;
 * line endpoints, marks, target and close-hauled heading come from the engine.
 */
export class CourseScene {
 readonly group=new THREE.Group();private resources:{dispose:()=>void}[]=[];
 private marks:THREE.Group[]=[];private gates:THREE.Group[]=[];private committee=new THREE.Group();
 private start:THREE.Line;private finish:THREE.Line;private laylines:THREE.Line[]=[];private markLines:THREE.Line[][]=[];private equalLine:THREE.Line;private pin:THREE.Group;
 constructor(){
  const resource=<T extends {dispose:()=>void}>(item:T):T=>{this.resources.push(item);return item;};
  const material=(color:string)=>resource(new THREE.MeshStandardMaterial({color,roughness:.85,flatShading:true}));
  const base=resource(new THREE.CylinderGeometry(1.9,2.3,1.2,8)),top=resource(new THREE.ConeGeometry(1.9,3.4,8)),pole=resource(new THREE.CylinderGeometry(.12,.12,7,6));
  const rim=material('#182f3c'),colors=['#ef882b','#f4ca48','#f4ca48','#ef882b'];
  const buoy=(color:string,label:string)=>{const g=new THREE.Group(),body=new THREE.Mesh(base,rim),cap=new THREE.Mesh(top,material(color));body.position.y=-.7;cap.position.y=1.6;g.add(body,cap);g.add(this.label(label,resource));return g;};
  for(let i=0;i<3;i++){const mark=buoy(colors[i],String(i+1));this.marks.push(mark);this.group.add(mark);}
  for(let i=0;i<2;i++){const mark=buoy('#f4ca48',i===0?'Gate L':'Gate R');mark.visible=false;this.gates.push(mark);this.group.add(mark);}
  this.pin=buoy(colors[3],'Pin');this.group.add(this.pin);
  const hullShape=new THREE.Shape();hullShape.moveTo(-3,7);hullShape.lineTo(3,7);hullShape.lineTo(3,-4);hullShape.lineTo(0,-8);hullShape.lineTo(-3,-4);hullShape.closePath();
  const hullGeometry=resource(new THREE.ExtrudeGeometry(hullShape,{depth:2.3,bevelEnabled:false}));hullGeometry.rotateX(Math.PI/2);
  const hull=new THREE.Mesh(hullGeometry,material('#e9eeee'));hull.position.y=1.2;
  const deck=new THREE.Mesh(resource(new THREE.BoxGeometry(5.5,.5,10)),material('#364f5b'));deck.position.y=1.3;
  const cabin=new THREE.Mesh(resource(new THREE.BoxGeometry(4.5,3.2,4.5)),material('#f6f7f1'));cabin.position.set(0,3,0);
  const glass=new THREE.Mesh(resource(new THREE.BoxGeometry(4.6,1.1,4.6)),material('#286679'));glass.position.set(0,3.5,0);
  const mast=new THREE.Mesh(pole,rim);mast.position.set(0,6.6,3);
  const flag=new THREE.Mesh(resource(new THREE.PlaneGeometry(3,2)),resource(new THREE.MeshBasicMaterial({color:'#edc43c',side:THREE.DoubleSide})));flag.position.set(1.5,9,3);
  this.committee.add(hull,deck,cabin,glass,mast,flag,this.label('Committee',resource));this.group.add(this.committee);
  const line=(color:string,dashed=false)=>{const geometry=resource(new THREE.BufferGeometry());geometry.setAttribute('position',new THREE.Float32BufferAttribute(new Float32Array(6),3).setUsage(THREE.DynamicDrawUsage));
   geometry.setAttribute('lineDistance',new THREE.Float32BufferAttribute(new Float32Array(2),1).setUsage(THREE.DynamicDrawUsage));
   const material=resource(dashed?new THREE.LineDashedMaterial({color,dashSize:8,gapSize:5,depthTest:false}):new THREE.LineBasicMaterial({color,depthTest:false}));const line=new THREE.Line(geometry,material);line.frustumCulled=false;line.renderOrder=2;this.group.add(line);return line;};
  this.start=line('#f5f8fc',true);this.finish=line('#5ce5b3',true);this.laylines=[line('#55c78c',true),line('#f78283',true)];
  for(let i=0;i<3;i++)this.markLines.push([line('#55c78c',true),line('#f78283',true)]);
  this.equalLine=line('#c5d6df',true);
 }
 private label(text:string,resource:<T extends {dispose:()=>void}>(item:T)=>T){const canvas=document.createElement('canvas');canvas.width=text.length<3?64:text.length<5?128:256;canvas.height=64;const context=canvas.getContext('2d')!;context.fillStyle='#f4f7f8';context.fillRect(0,0,canvas.width,64);context.fillStyle='#12303d';context.font='600 34px "IBM Plex Sans", sans-serif';context.textAlign='center';context.textBaseline='middle';context.fillText(text,canvas.width/2,32);
  const texture=resource(new THREE.CanvasTexture(canvas));texture.colorSpace=THREE.SRGBColorSpace;const material=resource(new THREE.SpriteMaterial({map:texture,depthTest:false,sizeAttenuation:false})),sprite=new THREE.Sprite(material);sprite.position.y=15;sprite.scale.set(canvas.width/64*.0325,.0325,1);sprite.renderOrder=3;return sprite;}
 private line(line:THREE.Line,value:CourseLine,y:number){const p=line.geometry.getAttribute('position') as THREE.BufferAttribute;p.setXYZ(0,value.a.x,y,value.a.y);p.setXYZ(1,value.b.x,y,value.b.y);p.needsUpdate=true;const distance=line.geometry.getAttribute('lineDistance') as THREE.BufferAttribute;distance.setX(1,Math.hypot(value.b.x-value.a.x,value.b.y-value.a.y));distance.needsUpdate=true;}
 update(course:NativeCourse,boat:BoatView,origin:{x:number;y:number},clock:number){
  this.group.position.set(-origin.x,0,-origin.y);
  for(let i=0;i<this.marks.length;i++){const p=course.marks[i],mark=this.marks[i];mark.position.set(p.x,0,p.y);mark.visible=!course.marks.slice(0,i).some(q=>q.x===p.x&&q.y===p.y);}
  for(let i=0;i<2;i++){const p=course.gate?.[i];this.gates[i].visible=!!p;if(p)this.gates[i].position.set(p.x,0,p.y);}
  if(course.gate?.length)this.marks[2].visible=false;
  this.pin.position.set(course.finish.b.x,0,course.finish.b.y);this.committee.position.set(course.committee.x,0,course.committee.y);this.committee.rotation.y=-course.committee.heading*Math.PI/180;
  this.line(this.start,course.start,.3);this.line(this.finish,course.finish,.4);
  const coincident=course.start.a.x===course.finish.a.x&&course.start.a.y===course.finish.a.y&&course.start.b.x===course.finish.b.x&&course.start.b.y===course.finish.b.y;this.start.visible=!coincident||clock<0;this.finish.visible=!coincident||clock>=0;
  for(let i=0;i<2;i++){const line=this.laylines[i],angle=(boat.windFrom+(i===0?-course.closeAngle:course.closeAngle))*Math.PI/180,length=course.length*1.4;line.visible=course.showLaylines;
   this.line(line,{a:course.target,b:{x:course.target.x-Math.sin(angle)*length,y:course.target.y+Math.cos(angle)*length}},.6);}
  // Native 0x444890 uses the close-hauled angle on beats and
  // 180 minus the native downwind angle on runs; the rays extend back from marks.
  for(let i=0;i<3;i++)for(let side=0;side<2;side++){
   const line=this.markLines[i][side],point=course.marks[i],upwind=i===0,spread=upwind?course.closeAngle:180-course.downwindAngle,
    angle=(boat.windFrom+(side===0?-spread:spread))*Math.PI/180,length=course.length*1.4;
   line.visible=course.showMarkLines&&this.marks[i].visible;this.line(line,{a:point,b:{x:point.x-Math.sin(angle)*length,y:point.y+Math.cos(angle)*length}},.7);
  }
  const equalAngle=(boat.windFrom+90)*Math.PI/180,dx=Math.sin(equalAngle)*course.length*.7,dy=-Math.cos(equalAngle)*course.length*.7;
  this.equalLine.visible=course.showMarkLines;this.line(this.equalLine,{a:{x:boat.x-dx,y:boat.y-dy},b:{x:boat.x+dx,y:boat.y+dy}},.65);
 }
 reset(){this.group.visible=false;}
 dispose(){this.group.removeFromParent();for(const resource of this.resources)resource.dispose();}
}
