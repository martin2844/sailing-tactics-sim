import * as THREE from 'three';
import {navigationTarget} from './navigation';
import {ScreenCourseLine} from './screen-course-line';
import type {NativeCourse,BoatView,CourseLine} from './protocol';
/** Presentation objects at native coordinates. Their shapes are modern artwork;
 * line endpoints, marks, target and close-hauled heading come from the engine.
 */
export class CourseScene {
 readonly group=new THREE.Group();private resources:{dispose:()=>void}[]=[];
 private marks:THREE.Group[]=[];private gates:THREE.Group[]=[];private committee=new THREE.Group();
 private start:ScreenCourseLine;private finish:ScreenCourseLine;private guides:ScreenCourseLine[]=[];private pin:THREE.Group;
 constructor(){
  const resource=<T extends {dispose:()=>void}>(item:T):T=>{this.resources.push(item);return item;};
  const material=(color:string)=>resource(new THREE.MeshStandardMaterial({color,roughness:.85,flatShading:true}));
  const base=resource(new THREE.CylinderGeometry(1.9,2.3,1.2,8)),top=resource(new THREE.ConeGeometry(1.9,3.4,8)),pole=resource(new THREE.CylinderGeometry(.12,.12,7,6));
  const rim=material('#182f3c'),colors=['#ef882b','#f4ca48','#f4ca48','#ef882b'];
  const buoy=(color:string,_label:string)=>{const g=new THREE.Group(),body=new THREE.Mesh(base,rim),cap=new THREE.Mesh(top,material(color));body.position.y=-.7;cap.position.y=1.6;g.add(body,cap);return g;};
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
  this.committee.add(hull,deck,cabin,glass,mast,flag);this.group.add(this.committee);
  const line=()=>{const line=new ScreenCourseLine();this.resources.push(line);return line;};
  this.start=line();this.finish=line();
  for(let i=0;i<20;i++){const guide=line();guide.group.visible=false;this.guides.push(guide);}
 }
 labelAnchors(course:NativeCourse){
  const result=this.marks.flatMap((mark,i)=>mark.visible?[{key:'mark-'+i,text:String(i+1),object:mark,height:5,point:course.marks[i],badge:true}]:[]);
  for(let i=0;i<2;i++)if(this.gates[i].visible)result.push({key:'gate-'+i,text:i?'Gate R':'Gate L',object:this.gates[i],height:5,point:course.gate![i],badge:false});
  result.push({key:'pin',text:'Pin',object:this.pin,height:5,point:course.finish.b,badge:false},{key:'committee',text:'Committee',object:this.committee,height:10,point:course.committee,badge:false});
  return result;
 }
 project(camera:THREE.Camera,origin:{x:number;y:number},width:number,height:number){
  for(const line of [this.start,this.finish,...this.guides]){if(!line.group.parent)this.group.parent?.add(line.group);line.project(camera,origin,width,height);}
 }
 update(course:NativeCourse,boat:BoatView,origin:{x:number;y:number},clock:number){
  this.group.position.set(-origin.x,0,-origin.y);
  for(let i=0;i<this.marks.length;i++){const p=course.marks[i],mark=this.marks[i];mark.position.set(p.x,0,p.y);mark.visible=!course.marks.slice(0,i).some(q=>q.x===p.x&&q.y===p.y);}
  for(let i=0;i<2;i++){const p=course.gate?.[i];this.gates[i].visible=!!p;if(p)this.gates[i].position.set(p.x,0,p.y);}
  if(course.gate?.length)this.marks[2].visible=false;
  this.pin.position.set(course.finish.b.x,0,course.finish.b.y);this.committee.position.set(course.committee.x,0,course.committee.y);this.committee.rotation.y=-course.committee.heading*Math.PI/180;
  this.start.set(course.start,.6,'#f6f9f4',2.2,10);this.finish.set(course.finish,.7,'#84e6c0',2.2,10);
  const coincident=course.start.a.x===course.finish.a.x&&course.start.a.y===course.finish.a.y&&course.start.b.x===course.finish.b.x&&course.start.b.y===course.finish.b.y;const recalling=boat.status===2;this.start.group.visible=!coincident||clock<0||recalling;this.finish.group.visible=!coincident||(clock>=0&&!recalling);
  const rays=course.guides??[],targetKind=navigationTarget(course,boat,clock).kind,target=course.navigationTarget??course.target;
  for(let i=0;i<this.guides.length;i++){
   const line=this.guides[i],ray=rays[i];line.group.visible=!!ray;
   if(!ray)continue;
   const angle=ray.bearing*Math.PI/180,length=Math.max(course.length*2,5000);
   const active=Math.hypot(ray.x-target.x,ray.y-target.y)<2||[24,25].includes(ray.type)&&['finish','gate'].includes(targetKind)||[4,5].includes(ray.type)&&targetKind==='start';
   line.set({a:{x:ray.x,y:ray.y},b:{x:ray.x+Math.sin(angle)*length,y:ray.y-Math.cos(angle)*length}},.8,active?'#efbd52':ray.type===3?'#a9bcc2':'#dbe9e8',active?1.8:1.1);
  }
 }
 reset(){this.group.visible=false;for(const line of [this.start,this.finish,...this.guides])line.group.visible=false;}
 dispose(){this.group.removeFromParent();for(const resource of this.resources)resource.dispose();}
}
