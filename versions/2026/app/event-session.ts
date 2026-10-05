import type {SceneSnapshot} from './protocol';
export type EventMode='race'|'championship';
export interface RaceRecord {race:number;boats:{id:number;name:string;finished:number;points:number}[]}
/** Modern event metadata; the native engine owns each score and weather stream.
 * Three-race chunks are native. Longer no-discard events aggregate those exact
 * native score units, retaining the original fractional ordering and ID ties. */
export class EventSession{
 readonly races:RaceRecord[]=[];activeRace=1;private recorded=false;
 constructor(readonly mode:EventMode,readonly length:number){if(mode!=='race'&&mode!=='championship'||!Number.isInteger(length)||length<1||length>10)throw Error('Invalid event');}
 receive(state:SceneSnapshot){if(!state.resultsReady||this.recorded)return;if(this.mode==='championship'&&!state.seriesScoring)throw Error('Championship requires native series scoring');const column=Math.max(0,Math.min(2,state.completedRaces-1));this.races.push({race:this.activeRace,boats:state.boats.map(b=>({id:b.id,name:b.name,finished:b.finished,points:b.points[column]}))});this.recorded=true;}
 get complete(){return this.recorded&&this.activeRace>=this.length;}
 get canContinue(){return this.mode==='championship'&&this.recorded&&!this.complete;}
 next(){if(!this.canContinue)throw Error('Event cannot continue');this.activeRace++;this.recorded=false;}
 get standings(){const scores=new Map<number,{id:number;name:string;points:number;finishes:number[]}>();for(const race of this.races)for(const boat of race.boats){let score=scores.get(boat.id);if(!score){score={id:boat.id,name:boat.name,points:0,finishes:[]};scores.set(boat.id,score);}score.points+=boat.points;score.finishes.push(boat.finished);}return [...scores.values()].sort((a,b)=>a.points-b.points||a.id-b.id);}
}
