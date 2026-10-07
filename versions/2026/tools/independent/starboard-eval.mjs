import assert from 'node:assert/strict';
import {readFile,mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {makeRuntime} from './fixtures.mjs';
import {ContactWorld} from '../../app/contact-world.ts';
import {AddressSpaceMemory} from '../../public/legacy/src/runtime/memory.js';
import {PoseyRng} from '../../public/legacy/src/engine/integer-core.js';
import {collisionPenalty,applyGeometryPenalty,checkNearRaceMarks} from '../../public/legacy/versions/2010-en/src/engine/penalties.js';
import {updateTack} from '../../public/legacy/versions/2010-en/src/engine/ai-geometry.js';
import {collisionPenalty as frozenPenalty} from '../../../2010-en/src/engine/penalties.js';
import {createCapturedTrig} from '../../../2010-en/src/engine/native-trig.js';
const data=new URL('../../../2010-en/assets/data/',import.meta.url);const asset=name=>new URL(name,data);
const legacyTrig=createCapturedTrig(JSON.parse(await readFile(asset('x87-trig.json'),'utf8')),JSON.parse(await readFile(asset('x87-stored-trig.json'),'utf8')));
function fixture(humanPort,clock=1000,otherElapsed=60){
 const {memory:m,engine:e}=makeRuntime();m.writeI32(0x4da194,2);m.writeI32(0x4da140,1);m.writeI32(0x4f8cd0,clock);
 m.writeI32(0x4f452c,0);m.writeI32(0x53527c,0);m.writeI32(0x4da1e4,9);m.writeI32(0x4da19c,5);
 m.writeI32(0x525a9c,2000);m.writeI32(0x523598,1200);m.writeI32(0x4f6d38,3000);m.writeI32(0x4f7f88,3000);
 for(const [i,[x,y]]of [[0,[0x536410,0x536414]],[1,[0x4fe094,0x4fe2a0]],[2,[0x5229d4,0x522ac8]],[3,[0x522acc,0x522ae0]],[4,[0x5229c8,0x522ac4]]]){m.writeI32(x,6000+i*500);m.writeI32(y,6000);}
 for(const id of[1,2]){
  const port=id===1?humanPort:!humanPort;m.writeF64(0x4f6af8+id*8,port?-20:20);m.writeF64(0x4f6c10+id*8,20);
  for(const [a,v]of[[0x535740,port?45:315],[0x522b90,0],[0x4fecc8,45],[0x4f8538,1],[0x4fe638,0],[0x535620,clock-(id===2?otherElapsed:60)],[0x5116e0,0],[0x4f7090,0],[0x4f4350,clock-100],[0x4fdfe8,80]])m.writeI32(a+id*4,v);
  m.writeF64(0x4fe180+id*8,80);updateTack(m,id);
 }
 const world=new ContactWorld({memory:m,rng:e.random.gameplay,options:e.options,ModelMemory:AddressSpaceMemory,ModelRng:PoseyRng,collisionPenalty,applyPenalty:applyGeometryPenalty,checkNearRaceMarks,updateTack});world.seed();
 return {m,e,world};
}
const checks=[];
for(const clock of[-100,1000])for(const humanPort of[true,false]){
 const {m,e,world}=fixture(humanPort,clock),before=world.capture();
 // Frozen classifier on the same opposite-tack state, outside mark-room/tacking exceptions.
 const frozen=new AddressSpaceMemory(m.size,m.base);frozen.bytes.set(m.bytes);
 frozenPenalty(frozen,2,1,2,new PoseyRng(e.random.gameplay.state),{...e.options,trig:legacyTrig});
 assert.equal(frozen.readI32(0x5116e4),humanPort?4:0,'Frozen human right-of-way');
 for(const id of[1,2]){const port=id===1?humanPort:!humanPort;m.writeF64(0x4f6af8+id*8,port?5:-5);m.writeF64(0x4f6c10+id*8,-5);}
 const solved=world.step(before,world.capture());
 assert.ok(solved.contacts.length,'Actual swept hull contact required');
 assert.equal(m.readI32(0x5116e4),humanPort?4:0,'Geometry human right-of-way');
 const penalized=humanPort?1:2,protectedBoat=3-penalized;
 assert.equal(m.readI32(0x535620+penalized*4),clock,'Port boat receives the native penalty timestamp');
 assert.equal(m.readI32(0x535620+protectedBoat*4),clock-60,'Starboard boat receives no penalty');
 checks.push({clock,humanTack:humanPort?'port':'starboard',nativeHumanCode:frozen.readI32(0x5116e4),geometryHumanCode:m.readI32(0x5116e4),penalizedBoat:penalized,event:world.summary.latest});
}
for(const elapsed of[49,50]){
 const {m,world}=fixture(true,1000,elapsed),before=world.capture();m.writeF64(0x4f6b00,5);m.writeF64(0x4f6c18,-5);m.writeF64(0x4f6b08,-5);m.writeF64(0x4f6c20,-5);world.step(before,world.capture());assert.equal(m.readI32(0x5116e4),elapsed===49?0:4);checks.push({opponentElapsed:elapsed,humanCode:m.readI32(0x5116e4)});
}
if(process.argv[2]){const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});await writeFile(resolve(output,'starboard.json'),JSON.stringify({passed:true,checks,scope:'Actual swept hull contacts on controlled opposite-tack fixtures, compared with the frozen2010 numerical classifier; prestart/racing and original49/50-second opponent grace.'},null,2));}
console.log(JSON.stringify({passed:true,checks:checks.length}));
