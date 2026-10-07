import test from 'node:test';import assert from 'node:assert/strict';
import {makeRuntime} from './fixtures.mjs';
import {simulatorSpeeds} from '../../app/engine/speed.ts';
test('every original speed restores from Space, including selections made while slowed and checkpoint/restart',()=>{
 for(const {level,command}of simulatorSpeeds){
  const {memory:m,engine:e}=makeRuntime({speed:level});assert.equal(m.readI32(0x4da174),level);
  e.key(32);assert.equal(m.readI32(0x4da174),1);assert.equal(e.selectedSpeed,level);
  const checkpoint=e.checkpoint();e.key(32);assert.equal(m.readI32(0x4da174),level);
  e.command(32909);e.restore(checkpoint);e.key(32);assert.equal(m.readI32(0x4da174),level);
  e.key(78);e.key(32);assert.equal(e.selectedSpeed,level);assert.equal(m.readI32(0x4da174),level);
  e.command(command);e.key(32);e.command(32876);assert.equal(e.selectedSpeed,5);e.key(32);assert.equal(m.readI32(0x4da174),1);e.key(32);assert.equal(m.readI32(0x4da174),5);
 }
});
test('Space restoring the selected speed retains original four-second foul slowdown grace',()=>{
 const {memory:m,engine:e}=makeRuntime();m.writeI32(0x4f8cd0,500);m.writeI32(0x4da1dc,1);e.key(32);assert.equal(m.readI32(0x4da174),1);
 e.key(32);assert.equal(m.readI32(0x4da174),10);assert.equal(m.readI32(0x4da1dc),2);assert.equal(m.readI32(0x4da1e0),500);
});
