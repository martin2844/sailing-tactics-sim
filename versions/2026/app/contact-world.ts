import {boatShapes,radius,obstacles,type Obstacle} from './contact-shapes.ts';
import {separation,world,angleDelta,distance,dot,type Body,type Pose,type Point} from './contact-geometry.ts';
import {solveMotions,type Motion,type Contact} from './contact-solver.ts';
import type {NativeCourse} from './protocol';
export interface ContactEvent {clock:number;a:number;other:string;penalties:{boat:number;code:number}[]}
export interface ContactSummary {count:number;fouls:number;held:number;latest?:ContactEvent;workMs:number}
interface Decision {code:number;movement:'phase'|'shift'|'respawn'}
interface State extends Pose {id:number;finished:boolean}
export function contactCourse(m:any):Pick<NativeCourse,'marks'|'gate'|'finish'|'committee'>{
 const p=(x:number,y:number)=>({x:m.readI32(x),y:m.readI32(y)}),finish={a:p(0x536410,0x536414),b:p(0x4fe094,0x4fe2a0)};
 return {finish,committee:{...finish.a,heading:m.readI32(0x4f7f94)},marks:[p(0x5229d4,0x522ac8),p(0x522acc,0x522ae0),p(0x5229c8,0x522ac4)],gate:m.readI32(0x4da1e8)?[p(0x4f4a68,0x4f6d34),p(0x523248,0x52359c)]:[]};
}
/** Owns collision state in the authoritative worker; graphics never drive it. */
export class ContactWorld {
 private previous=new Map<number,State>();private pairs=new Set<string>();private previousClock?:number;private ruleMemory:any;
 readonly summary:ContactSummary={count:0,fouls:0,held:0,workMs:0};
 private context:any;
 constructor(context:any){this.context=context;this.ruleMemory=new context.ModelMemory(context.memory.size,context.memory.base);}
 reset(){this.previous.clear();this.pairs.clear();this.previousClock=undefined;Object.assign(this.summary,{count:0,fouls:0,held:0,latest:undefined,workMs:0});}
 capture():State[]{const m=this.context.memory;return Array.from({length:m.readI32(0x4da194)},(_,i)=>{const id=i+1;return {id,x:m.readF64(0x4f6af8+id*8),y:m.readF64(0x4f6c10+id*8),heading:m.readI32(0x535740+id*4),finished:m.readI32(0x4fe638+id*4)>0};});}
 seed(){this.previous=new Map(this.capture().map(b=>[b.id,b]));this.previousClock=this.context.memory.readI32(0x4f8cd0);}
 step(before:State[],after:State[],course=contactCourse(this.context.memory)){
  const started=performance.now(),m=this.context.memory,clock=m.readI32(0x4f8cd0);if(this.previousClock!==undefined&&clock<this.previousClock)this.reset();
  const parts=boatShapes(m.readI32(0x4da144)),r=radius(parts),humans=m.readI32(0x4da140),old=new Map(before.map(b=>[b.id,b]));
  const moving:Motion[]=after.map(b=>{const start=old.get(b.id)!,previous=this.previous.get(b.id),pose=b.finished?b:{...start,heading:previous&&distance(previous,start)<.1?previous.heading:start.heading};return {key:'boat-'+b.id,parts,radius:r,pose,to:{...b},human:b.id<=humans,fixed:b.finished};});
  const fixed=obstacles(course),solved=solveMotions(moving,fixed);if(solved.held)this.summary.held++;
  // Native rule decisions read a stable contact-time image. Neither private
  // rule evaluation nor a prior participant's penalty can relocate the other.
  const decisions=new Map<number,Decision>(),nextPairs=new Set<string>();
  for(const c of solved.contacts){if(c.uncertain)continue;const key=[c.a,c.b].sort().join(':');nextPairs.add(key);if(c.initial)continue;
   if(!this.pairs.has(key))this.summary.count++;const a=Number(c.a.slice(5)),b=c.b.startsWith('boat-')?Number(c.b.slice(5)):0,penalties:{boat:number;code:number}[]=[];
   if(!old.get(a)?.finished){
    if(!b){const object=fixed.find(o=>o.key===c.b);if(object&&this.markEligible(a,object)){decisions.set(a,{code:1,movement:'phase'});penalties.push({boat:a,code:1});}}
    else if(!old.get(b)?.finished){for(const[id,other,pose,otherPose]of[[a,b,c.poseA,c.poseB],[b,a,c.poseB,c.poseA]] as const){const decision=this.decide(id,other,pose,otherPose,parts);if(decision){decisions.set(id,decision);if(decision.code)penalties.push({boat:id,code:decision.code});}}}
   }
   this.summary.fouls+=penalties.length;if(a<=humans||b&&b<=humans)this.summary.latest={clock,a:a<=humans?a:b,other:a<=humans?(b?'boat-'+b:fixed.find(o=>o.key===c.b)?.name??c.b):'boat-'+a,penalties};
  }
  const involved=new Set(solved.contacts.flatMap(c=>[c.a,c.b]));
  for(const b of after){if(b.finished||!involved.has('boat-'+b.id)&&!solved.held)continue;const pose=solved.poses.get('boat-'+b.id)!;const dx=pose.x-b.x,dy=pose.y-b.y;
   if(dx!==0)for(const address of[0x4f6af8,0x4f1610,0x4f83c0])m.writeF64(address+b.id*8,m.readF64(address+b.id*8)+dx);
   if(dy!==0)for(const address of[0x4f6c10,0x4f3868,0x4fb090])m.writeF64(address+b.id*8,m.readF64(address+b.id*8)+dy);
   m.writeI32(0x513480+b.id*4,m.readI32(0x513480+b.id*4)+Math.round(dx));m.writeI32(0x513510+b.id*4,m.readI32(0x513510+b.id*4)+Math.round(dy));
   if(Math.abs(angleDelta(pose.heading,b.heading))>.01){m.writeI32(0x535740+b.id*4,Math.round((pose.heading+360)%360));this.context.updateTack?.(m,b.id);const relative=Math.abs(angleDelta(m.readI32(0x535740+b.id*4),m.readI32(0x522b90+b.id*4)));m.writeI32(0x4fecc8+b.id*4,Math.round(relative));}
   const start=old.get(b.id)!,wanted=distance(start,b),travel=distance(start,pose);if(wanted>.01&&travel<wanted*.98){const rate=Math.max(0,Math.min(1,travel/wanted));m.writeI32(0x4fdfe8+b.id*4,Math.round(m.readI32(0x4fdfe8+b.id*4)*rate));m.writeF64(0x4fe180+b.id*8,m.readF64(0x4fe180+b.id*8)*rate);}
  }
  for(const[id,decision]of decisions){
   this.context.applyPenalty(m,id,decision,this.context.rng,this.context.options);
   // Native dynamics zeroes speed for a same-clock penalty. Contact resolution
   // follows integration, so reproduce that response without advancing twice.
   m.writeI32(0x4fdfe8+id*4,0);m.writeF64(0x4fe180+id*8,0);
   solved.poses.set('boat-'+id,this.capture().find(b=>b.id===id)!);
  }
  // Episodes count contacts only; native grace controls foul eligibility. Cache
  // relocated poses so the next frame never sweeps a penalty teleport.
  const bodies=[...after.map(b=>({key:'boat-'+b.id,pose:solved.poses.get('boat-'+b.id)!,parts,radius:r})),...fixed];
  for(const key of this.pairs){const [a,b]=key.split(':');const aa=bodies.find(v=>v.key===a),bb=bodies.find(v=>v.key===b);if(aa&&bb&&distance(aa.pose,bb.pose)<aa.radius+bb.radius+1&&separation(aa,bb).gap<.7)nextPairs.add(key);}
  this.pairs=new Set([...nextPairs].filter(key=>{const [a,b]=key.split(':'),aa=bodies.find(v=>v.key===a),bb=bodies.find(v=>v.key===b);return aa&&bb&&distance(aa.pose,bb.pose)<aa.radius+bb.radius+1&&separation(aa,bb).gap<.7;}));this.previous=new Map(this.capture().map(b=>[b.id,b]));this.previousClock=clock;this.summary.workMs=performance.now()-started;return solved;
 }
 private markEligible(id:number,object:Obstacle){
  // Hull geometry supplies proximity; the original helper supplies phase,
  // leg and angle gates. Gate endpoints had no direct native mark-touch branch.
  if(object.key.startsWith('gate-'))return false;
  const image=this.ruleMemory;image.bytes.set(this.context.memory.bytes);
  image.writeF64(0x4f6af8+id*8,object.pose.x);image.writeF64(0x4f6c10+id*8,object.pose.y);
  return this.context.checkNearRaceMarks(image,1,id)===1;
 }
 private decide(id:number,other:number,pose:Pose,otherPose:Pose,parts:Body['parts']){
  const {memory:m,rng,options,ModelRng}=this.context,image=this.ruleMemory;image.bytes.set(m.bytes);
  for(const[b,p]of[[id,pose],[other,otherPose]] as const){image.writeF64(0x4f6af8+b*8,p.x);image.writeF64(0x4f6c10+b*8,p.y);image.writeI32(0x535740+b*4,Math.round((p.heading+360)%360));this.context.updateTack(image,b);image.writeI32(0x4fecc8+b*4,Math.round(Math.abs(angleDelta(image.readI32(0x535740+b*4),image.readI32(0x522b90+b*4)))));}
  const angle=otherPose.heading*Math.PI/180,forward={x:Math.sin(angle),y:-Math.cos(angle)},points=(p:Pose)=>parts.flatMap(s=>s.kind==='polygon'?world(s.points,p):[]),own=points(pose).map(p=>dot(p,forward)),opponent=points(otherPose).map(p=>dot(p,forward));
  const clearAstern=Math.max(...own)<=Math.min(...opponent)+.2,ownAngle=pose.heading*Math.PI/180,ownForward={x:Math.sin(ownAngle),y:-Math.cos(ownAngle)},reverseOwn=points(pose).map(p=>dot(p,ownForward)),reverseOther=points(otherPose).map(p=>dot(p,ownForward)),otherAstern=Math.max(...reverseOther)<=Math.min(...reverseOwn)+.2;let result=0,movement:Decision['movement']|undefined;
  this.context.collisionPenalty(image,other,id,Math.round(distance(pose,otherPose)),new ModelRng(rng.state),{...options,geometryContact:true,geometryRuleOnly:true,geometryClearAstern:clearAstern,geometryOverlap:!clearAstern&&!otherAstern,geometryDecision:(code:number)=>{result||=code;},geometryMovement:(kind:Decision['movement'])=>{movement=kind;}});return movement?{code:result,movement}:undefined;
 }
}
