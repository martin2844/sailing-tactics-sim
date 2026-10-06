import * as THREE from 'three';
import {boatName} from './fleet-names';
import {navigationTarget} from './navigation';
import type {SceneSnapshot} from './protocol';
import type {NativeBoatMesh} from './native-boat-mesh';
import type {CourseScene} from './course-scene';
interface Rect {x:number;y:number;w:number;h:number}
interface Projected {x:number;y:number;depth:number}
interface Candidate {key:string;text:string;anchor:Projected;priority:number;badge:boolean;active:boolean;boat?:number;bounds?:Rect}
export interface PlacedLabel extends Rect {key:string;text:string;anchor:Projected;active:boolean;boat?:number;badge:boolean}
const overlaps=(a:Rect,b:Rect,gap=3)=>a.x<b.x+b.w+gap&&a.x+a.w+gap>b.x&&a.y<b.y+b.h+gap&&a.y+a.h+gap>b.y;
/** One screen-space drawing surface for all world annotations. Arbitrary names
 * stay canvas text; no camera-dependent scaling or per-name GPU textures. */
export class SceneLabels {
 readonly canvas=document.createElement('canvas');readonly placed:PlacedLabel[]=[];
 readonly names=new Map<number,string>();
 readonly boatBounds=new Map<number,Rect&{depth:number}>();readonly reserved:Rect[]=[];
 showAll=false;selected?:number;private hovered?:number;private down?:{x:number;y:number};
 private ctx:CanvasRenderingContext2D;private width=0;private height=0;private dpr=0;
 private slots=new Map<string,number>();
 private metrics=new Map<string,{text:string;width:number}>();private scratch=new THREE.Vector3();
 private pointer=(event:PointerEvent)=>{
  const r=this.sceneCanvas.getBoundingClientRect(),x=event.clientX-r.left,y=event.clientY-r.top;
  const hit=[...this.boatBounds].filter(([,b])=>x>=b.x&&x<=b.x+b.w&&y>=b.y&&y<=b.y+b.h).sort((a,b)=>a[1].depth-b[1].depth)[0]?.[0];
  if(event.type==='pointerdown')this.down={x,y};
  else if(event.type==='pointerup'){if(this.down&&Math.hypot(x-this.down.x,y-this.down.y)<5)this.selected=hit===this.selected?undefined:hit;this.down=undefined;}
  else if(event.type==='pointerleave'){this.hovered=undefined;this.down=undefined;}
  else if(!event.buttons)this.hovered=hit;
 };
 constructor(private sceneCanvas:HTMLCanvasElement){
  this.canvas.className='world-labels';this.canvas.setAttribute('aria-hidden','true');
  sceneCanvas.after(this.canvas);this.ctx=this.canvas.getContext('2d')!;
  for(const type of ['pointermove','pointerdown','pointerup','pointerleave'] as const)sceneCanvas.addEventListener(type,this.pointer);
  void document.fonts.ready.then(()=>this.metrics.clear());
 }
 private project(point:THREE.Vector3,camera:THREE.Camera):Projected|undefined{
  const depth=-point.clone().applyMatrix4(camera.matrixWorldInverse).z;
  if(depth<=0)return;const v=point.clone().project(camera);
  if(v.z< -1||v.z>1)return;
  return {x:(v.x+1)*this.width/2,y:(1-v.y)*this.height/2,depth};
 }
 private measure(text:string){
  let value=this.metrics.get(text);if(value)return value;
  this.ctx.font='12px "IBM Plex Sans",sans-serif';let displayed=text;
  while(this.ctx.measureText(displayed).width>132&&displayed.length>1)displayed=displayed.slice(0,-1);
  if(displayed!==text)displayed=displayed.slice(0,-1)+'…';
  value={text:displayed,width:Math.min(132,this.ctx.measureText(displayed).width)};this.metrics.set(text,value);return value;
 }
 private reservations(){
  this.reserved.length=0;
  const origin=this.sceneCanvas.getBoundingClientRect();
  for(const element of document.querySelectorAll<HTMLElement>('.instruments,.cameras,.common-keys,#minimap,#notice,#starter,#native-panel,#race-results')){
   if(!element.getClientRects().length)continue;const r=element.getBoundingClientRect();
   this.reserved.push({x:r.left-origin.left,y:r.top-origin.top,w:r.width,h:r.height});
  }
 }
 render(state:SceneSnapshot,camera:THREE.Camera,models:Map<number,NativeBoatMesh>,course:CourseScene,now:number){
  const rect=this.sceneCanvas.getBoundingClientRect(),dpr=Math.min(devicePixelRatio,2);
  if(rect.width!==this.width||rect.height!==this.height||dpr!==this.dpr){
   this.width=rect.width;this.height=rect.height;this.dpr=dpr;this.canvas.width=Math.round(this.width*dpr);this.canvas.height=Math.round(this.height*dpr);

  }
  const ctx=this.ctx;ctx.setTransform(dpr,0,0,dpr,0,0);ctx.clearRect(0,0,this.width,this.height);this.placed.length=0;this.boatBounds.clear();
  this.names.clear();for(const boat of state.boats)this.names.set(boat.id,boatName(boat));
  if(document.body.classList.contains('choosing-race')||document.querySelector('#native-panel:not([hidden]),#race-results:not([hidden])'))return;
  this.reservations();const candidates:Candidate[]=[];
  for(const boat of state.boats){
   const model=models.get(boat.id),box=model?.geometry.boundingBox;if(!model||!box)continue;
   const points:Projected[]=[];
   for(let i=0;i<8;i++){
    this.scratch.set(i&1?box.max.x:box.min.x,i&2?box.max.y:box.min.y,i&4?box.max.z:box.min.z).applyMatrix4(model.group.matrixWorld);
    const p=this.project(this.scratch,camera);if(p)points.push(p);
   }
   if(points.length!==8)continue;
   const x=Math.min(...points.map(p=>p.x)),y=Math.min(...points.map(p=>p.y)),w=Math.max(...points.map(p=>p.x))-x,h=Math.max(...points.map(p=>p.y))-y,depth=Math.min(...points.map(p=>p.depth));
   if(x+w<0||y+h<0||x>this.width||y>this.height)continue;
   const bounds={x,y,w,h,depth};this.boatBounds.set(boat.id,bounds);
   const selected=boat.id===this.selected||boat.id===this.hovered;
   if(boat.id===1&&!selected&&!this.showAll)continue;
   if(!selected&&!this.showAll&&w<15)continue;
   candidates.push({key:'boat-'+boat.id,text:boatName(boat),anchor:{x:x+w/2,y,depth},priority:selected?1:6+depth/10000,badge:false,active:selected,boat:boat.id,bounds});
  }
  const targetKind=navigationTarget(state.course,state.boats[0],state.clock).kind;
  for(const anchor of course.labelAnchors(state.course)){
   this.scratch.set(0,anchor.height,0).applyMatrix4(anchor.object.matrixWorld);const point=this.project(this.scratch,camera);
   if(!point||point.x<0||point.x>this.width||point.y<0||point.y>this.height)continue;
   const active=anchor.key===targetKind||targetKind==='gate'&&anchor.key.startsWith('gate-')||['start','finish'].includes(targetKind)&&['pin','committee'].includes(anchor.key);
   candidates.push({key:anchor.key,text:anchor.text,anchor:point,priority:active?0:state.clock<0&&['pin','committee'].includes(anchor.key)?2:3,badge:anchor.badge,active});
  }
  candidates.sort((a,b)=>a.priority-b.priority||a.anchor.depth-b.anchor.depth||a.key.localeCompare(b.key));
  const occupied=[...this.reserved],boats=[...this.boatBounds.values()];let nearby=0;
  for(const candidate of candidates){
   if(candidate.boat&&candidate.priority>=6&&!this.showAll&&nearby>=4)continue;
   const measured=this.measure(candidate.text),w=candidate.badge?20:Math.ceil(measured.width)+12,h=20;
   const {x,y}=candidate.anchor;
   const slots=[{x:x-w/2,y:y-h-8},{x:x+10,y:y-h/2},{x:x-w-10,y:y-h/2},
    {x:x-w/2,y:y-h-30},{x:x+20,y:y-h-12},{x:x-w-20,y:y-h-12}];
   const previous=this.slots.get(candidate.key);const ordered=previous===undefined?slots:[slots[previous],...slots.filter((_,i)=>i!==previous)];
   const slot=ordered.find(s=>s.x>=8&&s.y>=8&&s.x+w<=this.width-8&&s.y+h<=this.height-8
    &&!occupied.some(r=>overlaps({...s,w,h},r))&&!boats.some(r=>overlaps({...s,w,h},r,2)));
   if(!slot)continue;this.slots.set(candidate.key,slots.indexOf(slot));
   const label={...slot,w,h,key:candidate.key,text:measured.text,anchor:candidate.anchor,active:candidate.active,boat:candidate.boat,badge:candidate.badge};
   this.placed.push(label);occupied.push(label);if(candidate.boat&&candidate.priority>=6)nearby++;
   const endX=Math.max(slot.x,Math.min(slot.x+w,x)),endY=Math.max(slot.y,Math.min(slot.y+h,y));
   ctx.strokeStyle=candidate.active?'#efbd52':'#d7e8ecb3';ctx.lineWidth=1;ctx.beginPath();ctx.moveTo(x,y);ctx.lineTo(endX,endY);ctx.stroke();
   ctx.fillStyle=candidate.badge?(candidate.active?'#efbd52':'#f4f7f8eb'):'#12303de0';
   ctx.beginPath();ctx.roundRect(slot.x,slot.y,w,h,candidate.badge?10:3);ctx.fill();
   if(candidate.active&&!candidate.badge){ctx.strokeStyle='#efbd52';ctx.stroke();}
   ctx.font=(candidate.badge?'600 ':'')+'12px "IBM Plex Sans",sans-serif';ctx.textAlign='center';ctx.textBaseline='middle';ctx.fillStyle=candidate.badge?'#12303d':'#f4f7f8';
   ctx.fillText(measured.text,slot.x+w/2,slot.y+h/2);
  }
 }
 reset(){this.slots.clear();this.selected=undefined;this.hovered=undefined;this.down=undefined;this.placed.length=0;this.boatBounds.clear();this.names.clear();this.ctx.clearRect(0,0,this.width*this.dpr,this.height*this.dpr);}
 dispose(){for(const type of ['pointermove','pointerdown','pointerup','pointerleave'] as const)this.sceneCanvas.removeEventListener(type,this.pointer);this.canvas.remove();this.metrics.clear();}
}
