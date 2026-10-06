import type {NativeCourse,SceneSnapshot} from './protocol';
import type {NativeTerrain} from './native-environment';
export interface CourseSample {routeHints?:{from:{x:number;y:number};to:{x:number;y:number};points:{x:number;y:number}[]}[];course:NativeCourse;terrain:NativeTerrain;wind:number;configuration:SceneSnapshot['configuration']}
export type StoredSample=Omit<CourseSample,'terrain'>&{terrain:number|NativeTerrain};
export interface CourseAtlas {courses:Record<string,StoredSample>;venues:Record<string,StoredSample>;terrains:NativeTerrain[]}
export function sampleFromAtlas(atlas:CourseAtlas,course:number,area:number,windDirection?:number):CourseSample{
 const family=course>=6?6:[3,4,5].includes(course)?3:1,key=area+':'+family;
 const exact=windDirection===undefined?undefined:atlas.venues[key+':'+windDirection],data=exact??(area===32799?atlas.courses[course]:atlas.venues[key]??atlas.venues[area]);
 if(!data)throw Error('Missing course sample '+area+'/'+course);
 const terrain=typeof data.terrain==='number'?atlas.terrains[data.terrain]:data.terrain;
 if(windDirection===undefined||exact)return {...data,terrain};
 // Other venues use a schematic rotation of native sample marks about Start.
 // The fixed long-distance routes retain their geographical marks.
 const fixed=[32802,32964,33018].includes(area),origin={x:(data.course.start.a.x+data.course.start.b.x)/2,y:(data.course.start.a.y+data.course.start.b.y)/2},angle=(windDirection-data.wind)*Math.PI/180,rotate=(p:{x:number;y:number})=>fixed?{...p}:{x:origin.x+(p.x-origin.x)*Math.cos(angle)-(p.y-origin.y)*Math.sin(angle),y:origin.y+(p.x-origin.x)*Math.sin(angle)+(p.y-origin.y)*Math.cos(angle)};
 return {...data,terrain,wind:windDirection,course:{...data.course,marks:data.course.marks.map(rotate),start:{a:rotate(data.course.start.a),b:rotate(data.course.start.b)},finish:{a:rotate(data.course.finish.a),b:rotate(data.course.finish.b)},committee:{...rotate(data.course.committee),heading:windDirection}}};
}
