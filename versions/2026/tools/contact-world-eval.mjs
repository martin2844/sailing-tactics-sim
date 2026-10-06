import assert from'node:assert/strict';import{readFile,mkdir,writeFile}from'node:fs/promises';import{resolve}from'node:path';
import{ContactWorld}from'../app/contact-world.ts';import{boatShapes,radius,obstacles}from'../app/contact-shapes.ts';import{separation}from'../app/contact-geometry.ts';
import{loadOriginalData}from'../public/legacy/versions/2010-en/src/runtime/original-data.js';import{AddressSpaceMemory}from'../public/legacy/src/runtime/memory.js';import{PoseyRng}from'../public/legacy/src/engine/integer-core.js';import{setX87ControlWord}from'../public/legacy/src/runtime/float80.js';import{initializeBoatOptions}from'../public/legacy/versions/2010-en/src/engine/boat-options.js';import{createCapturedTrig}from'../public/legacy/versions/2010-en/src/engine/native-trig.js';import{collisionPenalty,applyGeometryPenalty,checkNearRaceMarks,updateMarkStartPenalties}from'../public/legacy/versions/2010-en/src/engine/penalties.js';import{updateTack}from'../public/legacy/versions/2010-en/src/engine/ai-geometry.js';
const out=resolve(process.argv[2]);await mkdir(out,{recursive:true});const base=new URL('../../2010-en/assets/data/',import.meta.url),json=async f=>JSON.parse(await readFile(new URL(f,base),'utf8')),manifest=await json('original-memory.json'),source=loadOriginalData(manifest,new Map(await Promise.all(manifest.segments.map(async r=>[r.file,new Uint8Array(await readFile(new URL(r.file,base)))])))),trig=createCapturedTrig(await json('x87-trig.json'),await json('x87-stored-trig.json'));setX87ControlWord(0x027f);
const course={marks:[{x:1000,y:1000},{x:1200,y:1000},{x:1400,y:1000}],gate:[],finish:{a:{x:1600,y:1000},b:{x:1800,y:1000}},committee:{x:1600,y:1000,heading:0}};
function make(selector=12,clock=1000){const m=new AddressSpaceMemory(source.size,source.base);m.bytes.set(source.bytes);m.writeI32(0x4da144,selector);initializeBoatOptions(m);for(const[a,v]of[[0x4da194,2],[0x4da140,1],[0x4f8cd0,clock],[0x4da19c,5],[0x53527c,0],[0x4da1e4,9],[0x4f452c,0],[0x525a9c,2000],[0x523598,1200],[0x4f6d38,3000],[0x4f7f88,3000],[0x4da1d8,3]])m.writeI32(a,v);for(const[a,v]of[[0x536410,1600],[0x536414,1000],[0x4fe094,1800],[0x4fe2a0,1000],[0x5229d4,1000],[0x522ac8,1000],[0x522acc,1200],[0x522ae0,1000],[0x5229c8,1400],[0x522ac4,1000]])m.writeI32(a,v);for(let id=1;id<=2;id++){m.writeF64(0x4f6af8+id*8,id===1?0:4000);m.writeF64(0x4f6c10+id*8,0);for(const[a,v]of[[0x535740,0],[0x522b90,270],[0x522ff0,id===1?-1:1],[0x4fecc8,90],[0x4f8538,1],[0x4fe638,0],[0x535620,clock-60],[0x5116e0,0],[0x4fdfe8,80]])m.writeI32(a+id*4,v);m.writeF64(0x4fe180+id*8,80);}const rng=new PoseyRng(123),w=new ContactWorld({memory:m,rng,options:{trig},ModelMemory:AddressSpaceMemory,ModelRng:PoseyRng,collisionPenalty,applyPenalty:applyGeometryPenalty,checkNearRaceMarks,updateTack});w.seed();return {m,w,rng};}
function place(m,id,x,y,heading=0){m.writeF64(0x4f6af8+id*8,x);m.writeF64(0x4f6c10+id*8,y);m.writeI32(0x535740+id*4,heading);}
const checks=[];
for(const [key,clock,leg,long,windAngle,code]of[
 ['mark-0',1000,1,0,90,1],['pin',1000,1,0,90,0],['committee',1000,1,0,90,0],
 ['gate-0',1000,1,0,90,0],['gate-1',1000,1,0,90,0],
 ['committee',-120,1,0,90,1],['committee',11,1,0,90,0],
 ['committee',1000,9,0,90,1],['pin',1000,9,0,179,0],
 ['mark-2',29,1,0,90,0],['mark-2',30,1,0,90,1],['mark-2',1000,1,1,90,0]
]){
 const {m,w,rng}=make(12,clock);m.writeI32(0x4f8538+4,leg);m.writeI32(0x53527c,long);m.writeI32(0x4fecc8+4,windAngle);
 const c=structuredClone(course);if(key.startsWith('gate'))c.gate=[{x:1900,y:1000},{x:2100,y:1000}];const object=obstacles(c).find(o=>o.key===key);
 place(m,1,object.pose.x,object.pose.y+30);w.seed();const before=w.capture();place(m,1,object.pose.x,object.pose.y-30);const result=w.step(before,w.capture(),c);
 assert.equal(m.readI32(0x5116e0+4),code,key+' phase '+clock);
 const pos=result.poses.get('boat-1');assert.ok(separation({key:'boat-1',parts:boatShapes(12),radius:radius(boatShapes(12)),pose:pos},object).gap>=-.01);
 assert.equal(pos.x,m.readF64(0x4f6af8+8));assert.equal(pos.y,m.readF64(0x4f6c10+8));
 if(code){assert.equal(m.readI32(0x535620+4),clock);assert.ok(Math.hypot(pos.x-object.pose.x,pos.y-object.pose.y)>50,'Original penalty must relocate');assert.equal(rng.state!==123,clock<20);}
 else assert.equal(rng.state,123);
 const held=m.bytes.slice(),state=rng.state;w.step(w.capture(),w.capture(),c);assert.deepEqual(m.bytes,held,'Relocation must not sweep through objects again');assert.equal(rng.state,state);
 checks.push({key,clock,leg,long,windAngle,code,summary:{...w.summary},pos});
}
{
 const{m,w}=make();place(m,1,0,30);place(m,2,0,-30,180);w.seed();const before=w.capture();place(m,1,0,-30);place(m,2,0,30,180);const result=w.step(before,w.capture(),course);assert.equal(m.readI32(0x5116e0+4),4);assert.equal(m.readI32(0x5116e0+8),0);assert.ok(result.contacts.length);checks.push({name:'Port/starboard native foul with original relocation',summary:{...w.summary}});
}
{
 const{m,w}=make();m.writeI32(0x522ff0+4,1);m.writeI32(0x522ff0+8,1);place(m,1,0,10);place(m,2,0,-20);w.seed();const before=w.capture();place(m,1,0,-20);w.step(before,w.capture(),course);assert.equal(m.readI32(0x5116e0+4),6);assert.equal(m.readI32(0x5116e0+8),0);checks.push({name:'Clear-astern boat gets foul; ahead boat is not also windward-fouled',summary:{...w.summary}});
}
{
 const{m,w}=make();m.writeI32(0x522ff0+4,1);m.writeI32(0x522ff0+8,1);place(m,1,-15,0);place(m,2,15,0);w.seed();const before=w.capture();place(m,1,0,0);place(m,2,0,0);w.step(before,w.capture(),course);assert.equal(w.summary.fouls,1);assert.ok([m.readI32(0x5116e0+4),m.readI32(0x5116e0+8)].includes(5));checks.push({name:'Same-tack side contact produces one native windward foul',summary:{...w.summary}});
}
{
 const{m,w,rng}=make();const held=m.bytes.slice();w.step(w.capture(),w.capture(),course);assert.deepEqual(m.bytes,held);assert.equal(rng.state,123);assert.equal(w.summary.count,0);checks.push({name:'No-contact step leaves complete native image and RNG identical'});
}
{
 const{m,w}=make();place(m,1,6,-10,179);place(m,2,0,0,175);for(const id of[1,2]){m.writeI32(0x522b90+id*4,0);updateTack(m,id);m.writeI32(0x4fecc8+id*4,id===1?179:175);}w.seed();const before=w.capture(),angle=181*Math.PI/180;place(m,1,6+Math.sin(angle)*5,-10-Math.cos(angle)*5,181);updateTack(m,1);m.writeI32(0x4fecc8+4,179);w.step(before,w.capture(),course);assert.equal(m.readI32(0x5116e0+4),5);assert.equal(m.readI32(0x5116e0+8),0);checks.push({name:'Gybe contact uses tack and wind angle at impact, not after the intended turn',summary:{...w.summary}});
}

// Compare complete native state and RNG against the actual original branch
// executed directly, rather than a second copy of the response formulas.
for(const clock of[-120,19,20,1000])for(const id of[1,2])for(const kind of['port','astern','windward','tacking','room','tacking-mark','npc-respawn']){
 const {m,rng}=make(12,clock),other=3-id;place(m,id,0,0);place(m,other,2,0);
 m.writeI32(0x522ff0+id*4,kind==='port'?-1:1);m.writeI32(0x522ff0+other*4,1);m.writeI32(0x4f7090+id*4,kind==='tacking'?1:0);if(kind==='tacking')m.writeI32(0x4fecc8+id*4,40);
 if(kind==='room'){m.writeI32(0x4f452c,1);m.writeI32(0x4f4a68,0);m.writeI32(0x4f6d34,0);m.writeI32(0x5229c8,100);m.writeI32(0x522ac4,10);}
 if(kind==='tacking-mark'){m.writeI32(0x522ff0+other*4,-1);m.writeI32(0x4fecc8+id*4,40);m.writeI32(0x4f4350+id*4,clock-1);m.writeI32(0x5229d4,0);m.writeI32(0x522ac8,0);}
 if(kind==='npc-respawn'){m.writeI32(0x4f8538+id*4,4);m.writeI32(0x4f8538+other*4,1);}
 const opts={trig,geometryContact:true,geometryClearAstern:['astern','npc-respawn'].includes(kind),geometryOverlap:kind==='windward'};
 const reference=new AddressSpaceMemory(m.size,m.base);reference.bytes.set(m.bytes);const rr=new PoseyRng(rng.state);
 const decisionImage=new AddressSpaceMemory(m.size,m.base);decisionImage.bytes.set(m.bytes);let code=0,movement;
 collisionPenalty(decisionImage,other,id,2,new PoseyRng(rng.state),{...opts,geometryRuleOnly:true,geometryDecision:c=>{code||=c;},geometryMovement:k=>{movement=k;}});
 collisionPenalty(reference,other,id,2,rr,opts);
 if(movement)applyGeometryPenalty(m,id,{code,movement},rng,{trig});
 assert.deepEqual(m.bytes,reference.bytes,kind+' id '+id+' clock '+clock);assert.equal(rng.state,rr.state);
 checks.push({name:'Full image/RNG matches direct native response',kind,id,clock,code,movement});
}
for(const clock of[-120,19,20,1000]){
 const {m,rng}=make(12,clock);place(m,1,1000,1000);
 const reference=new AddressSpaceMemory(m.size,m.base);reference.bytes.set(m.bytes);const rr=new PoseyRng(rng.state);
 updateMarkStartPenalties(reference,1,rr,{trig});applyGeometryPenalty(m,1,{code:1,movement:'phase'},rng,{trig});
 assert.deepEqual(m.bytes,reference.bytes);assert.equal(rng.state,rr.state);checks.push({name:'Full image/RNG matches direct native mark-touch response',clock});
}
for(const elapsed of[0,49,50,51]){
 const {m,w}=make();m.writeI32(0x535620+8,1000-elapsed);place(m,1,0,30);place(m,2,0,-30,180);w.seed();const before=w.capture();place(m,1,0,-30);place(m,2,0,30,180);w.step(before,w.capture(),course);
 assert.equal(m.readI32(0x5116e0+4),elapsed<50?0:4);checks.push({name:'Original opponent timestamp grace boundary',elapsed});
}
await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,checks,scope:'Prepared native response evaluated against direct native full-memory and RNG results; ContactWorld hull contacts, original grace boundaries, mark phase/leg gates, relocation caching and impact-time rules. Synthetic impacts; live race checks are separate.'},null,2));console.log(JSON.stringify({passed:true,checks:checks.length}));
