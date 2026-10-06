import source from './generated/starter-samples.json?raw';
import type {NativeModelPacket} from './native-models';
import {sampleFromAtlas,type CourseSample,type CourseAtlas} from './preview-sample';
export type {CourseSample} from './preview-sample';
type BoatSample=Record<'positions'|'records'|'colors'|'boats',number[]>;
const atlas=JSON.parse(source) as CourseAtlas&{boats:Record<string,BoatSample>};
const boats=new Map<number,NativeModelPacket>();
/** Static native samples keep option browsing independent of the race worker. */
export function boatSample(id:number){let packet=boats.get(id);if(!packet){const data=atlas.boats[id];if(!data)throw Error('Missing native boat sample '+id);packet={positions:Int16Array.from(data.positions),records:Int16Array.from(data.records),colors:Uint32Array.from(data.colors),boats:Uint32Array.from(data.boats),workMs:0};boats.set(id,packet);}return packet;}
export function courseSample(course:number,area:number,windDirection?:number):CourseSample{return sampleFromAtlas(atlas,course,area,windDirection);}
