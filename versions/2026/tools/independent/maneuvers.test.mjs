import test from 'node:test';
import assert from 'node:assert/strict';
import {makeRuntime} from './fixtures.mjs';
import {loadPE32} from '../../../../src/runtime/memory.js';
import {readFile} from 'node:fs/promises';
import {withX87ControlWord} from '../../../../src/runtime/float80.js';
import {updatePlayer1Steering as original} from '../../../2010-en/src/engine/steering.js';
import {updatePlayer1Steering as adapted} from '../../public/legacy/versions/2010-en/src/engine/steering.js';
const executable=await readFile(new URL('../../../2010-en/runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const wait=(engine,condition,limit=600)=>{for(let n=0;n<limit;n++){engine.step();if(condition())return n+1;}assert.fail('Maneuver did not complete');};

test('Space toggles speed1 and selected speed while preserving freeze; a held panel still dismisses',()=>{
 const {memory:m,engine:e}=makeRuntime();e.step();e.key(32);assert.equal(m.readI32(0x4da174),1);
 e.key(32);assert.equal(m.readI32(0x4da174),10);
 const time=m.readF64(0x5359f0);e.step();assert.ok(m.readF64(0x5359f0)>time);
 e.key(70);e.command(32909);e.key(32);assert.equal(m.readI32(0x4da174),1);assert.equal(m.readI32(0x53642c),1);
 e.key(191);e.key(32);assert.equal(m.readI32(0x536444),0);
});

test('zero legacy hit coordinates cannot cancel either tack or jibe on either tack',()=>{
 for(const boatCommand of[32781,32789,32794])for(const pace of[32872,32909]){
  const {memory:m,engine:e}=makeRuntime({setupCommands:[32799,32816,boatCommand,32806,pace]});
  for(let n=0;n<60;n++)e.step();
  for(let turn=0;turn<2;turn++){
   for(let n=0;n<60;n++)e.step();
   const before=m.readI32(0x522ff4);e.key(84);e.step();assert.equal(m.readI32(0x4f7094),1);
   wait(e,()=>m.readI32(0x4f7094)===0&&m.readI32(0x522ff4)===-before);
   assert.equal(m.readI32(0x511624),1);assert.ok(m.readI32(0x4feccc)<70);
  }
  e.command(32848);wait(e,()=>m.readI32(0x4fbbac)===0&&m.readI32(0x4feccc)>130);
  for(let turn=0;turn<2;turn++){
   const before=m.readI32(0x522ff4);e.key(74);e.step();assert.equal(m.readI32(0x5356b4),1);
   wait(e,()=>m.readI32(0x5356b4)===0&&m.readI32(0x522ff4)===-before);
   assert.ok(m.readI32(0x4feccc)>120);
  }
 }
});

test('screen-free steering retains frozen rudder/heading arithmetic for neutral original UI',()=>withX87ControlWord(0x027f,()=>{
 for(const heading of[1,90,180,359])for(const mode of['tack','jibe'])for(const tack of[-1,1])for(const divisor of[76,2919]){
  const a=loadPE32(executable),b=loadPE32(executable);
  for(const m of[a,b]){
   for(const[address,value]of[[0x4da140,1],[0x4da190,6],[0x4da14c,-1],[0x4da178,divisor],[0x4fe624,1024],[0x4fe2a8,723],[0x4f3ff0,768],[0x52318c,500],[0x4f8ee4,0],[0x4fba18,512],[0x4fbba0,600],[0x4fe75c,0],[0x5233a4,0],[0x525aa0,0],[0x4f4680,0],[0x4f71c4,2],[0x5363b4,0],[0x4f7094,mode==='tack'?1:0],[0x5356b4,mode==='jibe'?1:0],[0x511624,0],[0x4fbbac,0],[0x4f6a6c,0],[0x522ff4,tack],[0x53556c,tack],[0x4fdfec,40]])m.writeI32(address,value);
   m.writeF64(0x4fe938,heading);m.writeF64(0x5259d0,.512);
  }
  original(a);adapted(b,{legacyScreenSteering:false});assert.deepEqual(b.bytes,a.bytes);
 }
}));

test('two-boat keyboard maneuvers target the2026 player rather than boat2',()=>{
 const {memory:m,engine:e}=makeRuntime({setupCommands:[32799,32816,32789,32805,32909]});e.step();
 e.key(84);assert.equal(m.readI32(0x4f7094),1);assert.equal(m.readI32(0x4f7098),0);
 e.key(74);assert.equal(m.readI32(0x5356b4),1);assert.equal(m.readI32(0x5356b8),0);
});
