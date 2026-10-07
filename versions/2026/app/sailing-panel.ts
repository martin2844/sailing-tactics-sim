import {shortcutGroups} from './hotkeys';
import type {NativeTerrain} from './native-environment';
import type {SceneSnapshot,CoursePoint} from './protocol';
const svgNS='http://www.w3.org/2000/svg';

/** DOM/SVG presentation of held race information. No engine paint or bitmap. */
export class SailingPanel {
 private signature='';
 private terrain?:NativeTerrain;
 constructor(private content:HTMLElement){}
 update(state:SceneSnapshot,terrain?:NativeTerrain):void {
  const signature=JSON.stringify([state.generation,state.panel,state.course.start,state.course.finish,state.course.marks,state.course.gate,state.boats.map(b=>[b.x,b.y,b.heading])]);
  if(signature===this.signature&&terrain===this.terrain)return;this.signature=signature;this.terrain=terrain;this.content.replaceChildren();
  if(state.panel==='Race course')this.course(state,terrain);
  else {
   const list=document.createElement('dl');
   for(const [title,text]of shortcutGroups){const row=document.createElement('div'),term=document.createElement('dt'),description=document.createElement('dd');term.textContent=title;description.textContent=text;row.append(term,description);list.append(row);}
   this.content.append(list);
  }
 }
 private course(state:SceneSnapshot,terrain?:NativeTerrain):void {
  const course=state.course,points=[...course.marks,...(course.gate??[]),course.start.a,course.start.b,course.finish.a,course.finish.b,...state.boats];
  const xs=points.map(p=>p.x),ys=points.map(p=>p.y),cx=(Math.min(...xs)+Math.max(...xs))/2,cy=(Math.min(...ys)+Math.max(...ys))/2;
  const scale=Math.min(680/Math.max(120,Math.max(...xs)-Math.min(...xs)),440/Math.max(120,Math.max(...ys)-Math.min(...ys)));
  const project=(p:CoursePoint)=>({x:400+(p.x-cx)*scale,y:270+(p.y-cy)*scale});
  const svg=document.createElementNS(svgNS,'svg');svg.setAttribute('viewBox','0 0 800 540');svg.setAttribute('role','img');svg.setAttribute('aria-label','Current race course, north up');
  const node=(tag:string,attributes:Record<string,string|number>)=>{const value=document.createElementNS(svgNS,tag);for(const [key,text]of Object.entries(attributes))value.setAttribute(key,String(text));svg.append(value);return value;};
  node('rect',{width:800,height:540,fill:'#e0edf0'});
  for(const polygon of terrain?.polygons??[]){const path=polygon.points.map((p,i)=>{const q=project(p);return `${i?'L':'M'}${q.x} ${q.y}`;}).join(' ')+' Z';node('path',{d:(polygon.landInside?'':'M0 0 H800 V540 H0 Z ')+path,'fill-rule':'evenodd',fill:'#91ac78',stroke:'#718c59'});}
  const line=(a:CoursePoint,b:CoursePoint,color:string)=>{const p=project(a),q=project(b);node('line',{x1:p.x,y1:p.y,x2:q.x,y2:q.y,stroke:color,'stroke-width':3,'stroke-dasharray':'6 4'});};
  line(course.start.a,course.start.b,'#568f85');line(course.finish.a,course.finish.b,'#a57829');
  const label=(p:CoursePoint,text:string)=>{const q=project(p);node('text',{x:q.x+8,y:q.y-8,fill:'#163f57','font-size':16}).textContent=text;};
  course.marks.forEach((p,i)=>{const q=project(p);node('circle',{cx:q.x,cy:q.y,r:5,fill:'#e6ab46',stroke:'#8e642b'});label(p,'Mark '+(i+1));});
  for(const p of course.gate??[]){const q=project(p);node('circle',{cx:q.x,cy:q.y,r:4,fill:'#e6ab46'});}
  for(const boat of state.boats){const q=project(boat);node('path',{
   d:'M0 -7 L4 5 L0 3 L-4 5 Z',transform:`translate(${q.x} ${q.y}) rotate(${boat.heading})`,
   fill:boat.id===1?'#ba3344':'#f1f6fa',stroke:boat.id===1?'#fff':'#315e78','stroke-width':1,
  });}
  label(course.start.a,'Start');label(course.finish.b,'Finish');node('text',{x:760,y:28,fill:'#163f57','font-size':16}).textContent='N ↑';
  this.content.append(svg);
 }
}
