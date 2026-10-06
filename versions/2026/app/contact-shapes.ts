import catalog from './generated/contact-shapes.json';
import {BUOY_RADIUS,COMMITTEE_OUTLINE} from './world-objects.ts';
import type {NativeCourse,SceneSnapshot} from './protocol';
import type {Shape,Body,Pose} from './contact-geometry.ts';
export const boatShapes=(selector:number)=>(catalog.boats as unknown as Record<string,Shape[]>)[selector]??(()=>{throw Error('Missing contact hull '+selector);})();
export const radius=(parts:Shape[])=>Math.max(...parts.map(p=>p.kind==='circle'?p.radius:Math.max(...p.points.map(v=>Math.hypot(v.x,v.y)))));
export interface Obstacle extends Body {type:'mark'|'committee';name:string}
export function obstacles(course:NativeCourse):Obstacle[]{
 const result:Obstacle[]=[];
 const add=(key:string,name:string,p:Pose,parts:Shape[],type:Obstacle['type']='mark')=>{if(result.some(b=>Math.hypot(b.pose.x-p.x,b.pose.y-p.y)<.01))return;result.push({key,name,type,pose:p,parts,radius:radius(parts)});};
 add('committee','Committee boat',{...course.committee,heading:course.committee.heading},[{kind:'polygon',points:COMMITTEE_OUTLINE}],'committee');
 const circle:Shape[]=[{kind:'circle',radius:BUOY_RADIUS}];
 add('pin','Start pin',{...course.finish.b,heading:0},circle);
 course.marks.forEach((p,i)=>{if(i===2&&course.gate?.length)return;add('mark-'+i,['Windward mark','Reach mark','Leeward mark'][i],{...p,heading:0},circle);});
 course.gate?.forEach((p,i)=>add('gate-'+i,i?'Gate right':'Gate left',{...p,heading:0},circle));return result;
}
export function snapshotBodies(state:SceneSnapshot):Body[]{const parts=boatShapes(state.configuration.selector),r=radius(parts);return [...state.boats.map(b=>({key:'boat-'+b.id,parts,radius:r,pose:{x:b.x,y:b.y,heading:b.heading}})),...obstacles(state.course)];}
