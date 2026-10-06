import {IslandNavigator} from './island-navigation';
import {courseSample} from './starter-samples';
import {courseChoices,type RaceSettings} from './race-settings';
import type {CoursePoint} from './protocol';
const routes:Record<number,string[]>={1:['W','L'],2:['W','L','W','L'],3:['W','R','L'],4:['W','R','L','W','R','L'],5:['W','R','L','W','L'],6:['W','L'],7:['W','L','W','L']};
/** OG-style course-choice diagrams, using native sample marks and shorelines.
 * Paths describe rounding order; they do not predict tacks or a seeded race. */
export class CoursePreview {
 private navigation=new Map<number,IslandNavigator>();
 constructor(private element:HTMLElement){}
 update(settings:RaceSettings){
  const area=settings.area??32799,sample=courseSample(settings.course,area);if(!sample)return;
  const course=sample.course,mid=(a:CoursePoint,b:CoursePoint)=>({x:(a.x+b.x)/2,y:(a.y+b.y)/2}),start=mid(course.start.a,course.start.b);
  const marks=course.marks.map(p=>settings.short?{x:start.x+(p.x-start.x)*.7,y:start.y+(p.y-start.y)*.7}:p);
  const w=marks[0],r=marks[1],l=marks[2],downwind=settings.course>=6;
  const finish=downwind?l:mid(course.finish.a,course.finish.b),anchors:Record<string,CoursePoint>={W:w,R:r,L:l};
  const sequence=routes[settings.course],roundings=[...new Set(sequence)],island=[32801,32802,32964,33018].includes(area);
  const targets=[start,...sequence.map(key=>anchors[key]),finish],path=[start];let navigator=this.navigation.get(area);if(island&&!navigator){navigator=new IslandNavigator(sample.terrain,()=>200,0);this.navigation.set(area,navigator);}for(const point of targets.slice(1)){const from=path.at(-1)!;if(navigator&&!navigator.clear(from,point))path.push(...navigator.route(from,point));else path.push(point);}
  const points=[start,finish,...roundings.map(key=>anchors[key]),...path];
  // Wind-up, matching the original course-choice diagrams' convention.
  const bearing=sample.wind*Math.PI/180,rotate=(p:CoursePoint)=>({x:(p.x-start.x)*Math.cos(bearing)+(p.y-start.y)*Math.sin(bearing),y:-(p.x-start.x)*Math.sin(bearing)+(p.y-start.y)*Math.cos(bearing)});
  const rotated=points.map(rotate),xs=rotated.map(p=>p.x),ys=rotated.map(p=>p.y),minX=Math.min(...xs),maxX=Math.max(...xs),minY=Math.min(...ys),maxY=Math.max(...ys),scale=Math.min(330/Math.max(150,maxX-minX),125/Math.max(150,maxY-minY));
  const project=(p:CoursePoint)=>{const q=rotate(p);return{x:240+(q.x-(minX+maxX)/2)*scale,y:95+(q.y-(minY+maxY)/2)*scale};},pair=(p:CoursePoint)=>{const q=project(p);return q.x.toFixed(2)+','+q.y.toFixed(2);};
  let land='';
  for(const polygon of sample.terrain.polygons){const path=polygon.points.map((p,i)=>(i?'L':'M')+pair(p)).join(' ')+' Z';land+=`<path d="${polygon.landInside?'':'M0 0 H480 V190 H0 Z '}${path}" fill-rule="evenodd" fill="#91ac78" stroke="#718c59" stroke-width="1"/>`;}

  const segments=path.slice(1).map((p,i)=>{const a=project(path[i]),b=project(p),offset=(i%2?1:-1)*2;return `<path d="M ${a.x+offset} ${a.y} L ${b.x+offset} ${b.y}" marker-mid="url(#course-arrow)" stroke="#315e78" stroke-width="1.7" fill="none"/><path d="M ${a.x+offset} ${a.y} L ${(a.x+b.x)/2+offset} ${(a.y+b.y)/2}" marker-end="url(#course-arrow)" stroke="#315e78" stroke-width="1.7"/>`;}).join('');
  const sp=project(start),fp=project(finish),marker=(key:string)=>{const p=project(anchors[key]),label=key==='W'?'Windward':key==='R'?'Reach':settings.gate?'Gate':'Leeward';return `${key==='L'&&settings.gate?'':`<circle cx="${p.x}" cy="${p.y}" r="4" fill="#e6ab46" stroke="#8e642b"/>`}<text x="${p.x+(key==='R'?-9:9)}" y="${p.y+4}" text-anchor="${key==='R'?'end':'start'}">${label}</text>`;};
  const gate=settings.gate?`<circle cx="${project(l).x-10}" cy="${project(l).y}" r="3" fill="#e6ab46"/><circle cx="${project(l).x+10}" cy="${project(l).y}" r="3" fill="#e6ab46"/>`:'';
  this.element.dataset.course=String(settings.course);this.element.dataset.area=String(area);this.element.dataset.short=String(!!settings.short);this.element.dataset.gate=String(!!settings.gate);
  const routeText=['Start',...sequence.map(key=>key==='W'?'Windward':key==='R'?'Reach':settings.gate?'Gate':'Leeward'),'Finish'].join(' → ');
  this.element.innerHTML=`<div class="course-preview-title"><strong>${courseChoices.find(c=>c.value===settings.course)!.label}</strong><span>Course sample</span></div><svg viewBox="0 0 480 190" role="img" aria-label="${routeText}" xmlns="http://www.w3.org/2000/svg"><defs><marker id="course-arrow" markerWidth="5" markerHeight="5" refX="4" refY="2.5" orient="auto"><path d="M0 0 L5 2.5 L0 5" fill="#315e78"/></marker><clipPath id="course-clip"><rect width="480" height="190" rx="6"/></clipPath></defs><g clip-path="url(#course-clip)"><rect width="480" height="190" fill="#e0edf0"/>${land}<g font-family="IBM Plex Sans,sans-serif" font-size="11" fill="#163f57">${segments}<path d="M ${sp.x-18} ${sp.y} H ${sp.x+18}" stroke="#568f85" stroke-width="2" stroke-dasharray="4 3"/><text x="${sp.x+23}" y="${sp.y-7}" text-anchor="start">Start</text><path d="M ${fp.x-18} ${fp.y+6} H ${fp.x+18}" stroke="#a57829" stroke-width="2" stroke-dasharray="2 3"/><text x="${fp.x+23}" y="${fp.y+20}" text-anchor="start">Finish</text>${roundings.map(marker).join('')}${gate}<text x="18" y="24">↑ Wind</text><text x="462" y="177" text-anchor="end">${settings.short?'Short course · ':''}Not to scale</text></g></g></svg><p class="course-preview-route">${routeText}</p>`;
 }
}
