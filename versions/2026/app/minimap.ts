import type {SceneSnapshot,CoursePoint} from './protocol';
import type {NativeTerrain} from './native-environment';
type Pose={x:number;y:number;heading:number};
/** A north-up chart of the same coordinates used by the sailing renderer. */
export class Minimap {
 readonly element:HTMLElement;private canvas:HTMLCanvasElement;private context:CanvasRenderingContext2D;
 private terrain?:NativeTerrain;private enabled=true;private lastDraw=-Infinity;private width=0;private height=0;
 constructor(private toggle:HTMLButtonElement){
  try{this.enabled=localStorage.getItem('tact2026.minimap')!=='off';}catch{}
  this.element=document.createElement('aside');this.element.id='minimap';this.element.setAttribute('aria-label','Course minimap');this.element.hidden=true;
  this.element.innerHTML='<div class="minimap-heading"><span>Course · north up</span><button type="button" aria-label="Hide minimap" title="Hide minimap">×</button></div><canvas aria-label="Top-down view of the course, land and fleet"></canvas><div class="minimap-legend"><i></i> Your boat <span>● Marks</span></div>';
  this.canvas=this.element.querySelector('canvas')!;this.context=this.canvas.getContext('2d')!;
  document.querySelector('.sailing')!.append(this.element);
  this.element.querySelector('button')!.onclick=()=>this.setEnabled(false);toggle.onclick=()=>this.setEnabled(!this.enabled);this.updateToggle();
 }
 private updateToggle(){this.toggle.setAttribute('aria-pressed',String(this.enabled));this.toggle.setAttribute('aria-controls','minimap');}
 private setEnabled(value:boolean){this.enabled=value;this.updateToggle();this.lastDraw=-Infinity;if(!value)this.element.hidden=true;try{localStorage.setItem('tact2026.minimap',value?'on':'off');}catch{}}
 receiveTerrain(value:NativeTerrain){this.terrain=value;this.lastDraw=-Infinity;}
 reset(){this.terrain=undefined;this.element.hidden=true;this.lastDraw=-Infinity;}
 render(state:SceneSnapshot,poses:Pose[],mode:string,now:number){
  const hidden=!this.enabled||mode==='overview'||document.body.classList.contains('choosing-race')||!!state.panel||state.resultsReady;
  if(hidden){this.element.hidden=true;this.lastDraw=-Infinity;return;}
  this.element.hidden=false;if(now-this.lastDraw<100)return;this.lastDraw=now;
  const rect=this.canvas.getBoundingClientRect(),w=Math.round(rect.width),h=Math.round(rect.height);if(!w||!h)return;
  const dpr=Math.min(devicePixelRatio,2);if(w!==this.width||h!==this.height||this.canvas.width!==Math.round(w*dpr)){this.width=w;this.height=h;this.canvas.width=Math.round(w*dpr);this.canvas.height=Math.round(h*dpr);}
  const c=this.context;c.setTransform(dpr,0,0,dpr,0,0);c.clearRect(0,0,w,h);c.fillStyle='#258ba1';c.fillRect(0,0,w,h);
  const course=state.course,points=[...course.marks,...(course.gate??[]),course.start.a,course.start.b,course.finish.a,course.finish.b,...poses];
  const xs=points.map(p=>p.x),ys=points.map(p=>p.y),minX=Math.min(...xs),maxX=Math.max(...xs),minY=Math.min(...ys),maxY=Math.max(...ys);
  const scale=Math.min((w-30)/Math.max(120,maxX-minX),(h-26)/Math.max(120,maxY-minY)),cx=(minX+maxX)/2,cy=(minY+maxY)/2;
  const project=(p:CoursePoint)=>({x:w/2+(p.x-cx)*scale,y:h/2+(p.y-cy)*scale});
  c.save();c.beginPath();c.rect(0,0,w,h);c.clip();
  for(const polygon of this.terrain?.polygons??[]){if(polygon.points.length<3)continue;c.beginPath();if(!polygon.landInside)c.rect(-1,-1,w+2,h+2);polygon.points.forEach((p,i)=>{const v=project(p);if(i)c.lineTo(v.x,v.y);else c.moveTo(v.x,v.y);});c.closePath();c.fillStyle='#86a16a';c.fill('evenodd');c.strokeStyle='#cee2af';c.lineWidth=.8;c.stroke();}
  const line=(a:CoursePoint,b:CoursePoint,color:string,dash:number[]=[])=>{const p=project(a),q=project(b);c.beginPath();c.moveTo(p.x,p.y);c.lineTo(q.x,q.y);c.strokeStyle=color;c.lineWidth=1.2;c.setLineDash(dash);c.stroke();c.setLineDash([]);};
  if(course.showMarkLines)for(const guide of course.guides??[]){const radians=guide.bearing*Math.PI/180,length=Math.hypot(maxX-minX,maxY-minY)*1.5;line(guide,{x:guide.x+Math.sin(radians)*length,y:guide.y-Math.cos(radians)*length},'#d8d59380',[3,4]);}
  line(course.start.a,course.start.b,'#fafcf6',[4,3]);line(course.finish.a,course.finish.b,'#e8c05c',[2,3]);
  for(const mark of [...course.marks,...(course.gate??[])]){const p=project(mark);c.beginPath();c.arc(p.x,p.y,2.8,0,Math.PI*2);c.fillStyle='#ffc36d';c.fill();c.strokeStyle='#674c24';c.lineWidth=.7;c.stroke();}
  const committee=project(course.committee);c.fillStyle='#f5f6ed';c.fillRect(committee.x-3,committee.y-2,6,4);
  // Draw the player's red hull last, with a white halo for visibility in a fleet.
  const order=poses.map((_,i)=>i).sort((a,b)=>Number(a===0)-Number(b===0));
  for(const index of order){const pose=poses[index],p=project(pose);c.save();c.translate(p.x,p.y);c.rotate(pose.heading*Math.PI/180);c.beginPath();c.moveTo(0,-(index===0?6:4));c.lineTo(3,4);c.lineTo(0,2);c.lineTo(-3,4);c.closePath();c.fillStyle=index===0?'#ba3344':state.boats[index].finished?'#a9d9d6':'#f1f6fa';c.strokeStyle=index===0?'#fff':'#204e5f';c.lineWidth=index===0?1.5:.7;c.fill();c.stroke();c.restore();}
  c.restore();c.font='600 10px "IBM Plex Sans",sans-serif';c.textAlign='right';c.fillStyle='#fff';c.fillText('N ↑',w-8,13);
 }
 dispose(){this.element.remove();}
}
