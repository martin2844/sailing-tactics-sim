import source from './generated/starter-samples.json?raw';
import type {NativeModelPacket} from './native-models';
import type {NativeCourse,SceneSnapshot} from './protocol';
import type {NativeTerrain} from './native-environment';
export interface CourseSample {course:NativeCourse;terrain:NativeTerrain;wind:number;configuration:SceneSnapshot['configuration']}
type BoatSample=Record<'positions'|'records'|'colors'|'boats',number[]>;
type StoredSample=Omit<CourseSample,'terrain'>&{terrain:number};
const atlas=JSON.parse(source) as {boats:Record<string,BoatSample>;courses:Record<string,StoredSample>;venues:Record<string,StoredSample>;terrains:NativeTerrain[]};
const boats=new Map<number,NativeModelPacket>();
/** Static native samples keep option browsing independent of the race worker. */
export function boatSample(id:number){let packet=boats.get(id);if(!packet){const data=atlas.boats[id];if(!data)throw Error('Missing native boat sample '+id);packet={positions:Int16Array.from(data.positions),records:Int16Array.from(data.records),colors:Uint32Array.from(data.colors),boats:Uint32Array.from(data.boats),workMs:0};boats.set(id,packet);}return packet;}
export function courseSample(course:number,area:number):CourseSample{const family=course>=6?6:[3,4,5].includes(course)?3:1,data=area===32799?atlas.courses[course]:atlas.venues[area+':'+family]??atlas.venues[area];if(!data)throw Error('Missing course sample '+area+'/'+course);return {...data,terrain:atlas.terrains[data.terrain]};}
