import test from 'node:test';import assert from 'node:assert/strict';
import {makeRuntime} from './fixtures.mjs';
import {prepareFleetSpawns} from '../../app/engine/compatibility/spawn-state.ts';
import {boatShapes,radius,obstacles} from '../../app/contact-shapes.ts';
import {distance,separation} from '../../app/contact-geometry.ts';
import {contactCourse} from '../../app/contact-world.ts';
import {AddressSpaceMemory} from '../../public/legacy/src/runtime/memory.js';
import {sampleSpatialMetric} from '../../public/legacy/versions/2010-en/src/engine/spatial-metrics.js';
import {boatChoices} from '../../app/native-catalog.ts';
function settle(m,e){const image=new AddressSpaceMemory(m.size,m.base);image.bytes.set(m.bytes);prepareFleetSpawns(m,{depth:(x,y)=>sampleSpatialMetric(image,Math.round(x),Math.round(y),1,e.options).toNumber()});}
function bodies(m){const parts=boatShapes(m.readI32(0x4da144));return Array.from({length:m.readI32(0x4da194)},(_,i)=>({key:'boat-'+(i+1),parts,radius:radius(parts),pose:{x:m.readF64(0x4f6b00+i*8),y:m.readF64(0x4f6c18+i*8),heading:m.readI32(0x535744+i*4)}}));}
test('all27 hull classes initialize clear at5/30fleets without RNG consumption or penalty timestamps',()=>{
 for(const boat of boatChoices)for(const fleet of[5,30]){
  const {memory:m,engine:e}=makeRuntime({setupCommands:[32799,32816,boat.command,fleet===5?32806:32811,32909]});
  const before=e.random.snapshot();settle(m,e);assert.deepEqual(e.random.snapshot(),before);
  const boats=bodies(m),fixed=obstacles(contactCourse(m));
  for(let i=0;i<boats.length;i++){
   for(let j=i+1;j<boats.length;j++)assert.ok(distance(boats[i].pose,boats[j].pose)>=boats[i].radius+boats[j].radius+4-.00001);
   for(const obstacle of fixed)assert.ok(separation(boats[i],obstacle).gap>=4-.00001);
   const id=i+1;assert.equal(m.readF64(0x4f1610+id*8),boats[i].pose.x);assert.equal(m.readF64(0x4f3868+id*8),boats[i].pose.y);
   assert.equal(m.readI32(0x535620+id*4),-2000);
  }
  const bytes=m.bytes.slice();settle(m,e);assert.deepEqual(m.bytes,bytes,'Layout is idempotent');
 }
});
