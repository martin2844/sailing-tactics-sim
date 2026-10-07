import test from 'node:test';import assert from 'node:assert/strict';
import {PlaybackPacer,playbackRates,parsePlaybackValue,playbackValue,validatePlayback} from '../../app/engine/time/playback.ts';
import {AnimationClock} from '../../app/presentation/animation-clock.ts';
import {makeRuntime} from './fixtures.mjs';
import {updateFoulSlowdown} from '../../app/engine/rules/foul-slowdown.ts';
import {createFoulSlowdownState} from '../../app/engine/compatibility/foul-slowdown-state.ts';

test('clock deadlines retain target rates across timer/work jitter without native minimum delays',()=>{
 for(const rate of playbackRates){
  const p=new PlaybackPacer();p.configure({mode:'clock',rate},0,-100);
  let now=0,time=-100;
  for(let n=0;n<200;n++){
   now+=n%7+1;time+=.06;
   const delay=p.delay(now,time,80,n%7+1);now+=delay;
   assert.ok(Math.abs(now-(time+100)*1000/rate)<1e-7);
  }
 }
});
test('hold/resume, checkpoint rewind, long stalls and precision changes rebase clock deadlines',()=>{
 const p=new PlaybackPacer();p.configure({mode:'clock',rate:8},0,100);
 assert.ok(Math.abs(p.delay(1,100.08,30,1)-9)<1e-7);
 p.togglePrecision(10,100.08);assert.equal(p.state(6,6).active.rate,1);
 assert.ok(Math.abs(p.delay(20,100.16,30,10)-70)<1e-7);
 p.togglePrecision(90,100.16);assert.equal(p.state(6,6).active.rate,8);
 p.reset(10000,100.16);assert.ok(p.delay(10001,100.24,30,1)<10);
 assert.equal(p.delay(20000,100.24,30,2),80,'Held step discards elapsed wall debt');
 assert.equal(p.delay(21000,100.32,30,2),0,'Long stall discards debt');
 assert.ok(p.delay(21001,100.4,30,1)<10);
 assert.equal(p.delay(22000,50,30,2),80,'Rewind never waits for discarded future game time');
 p.slowForWarning(22000,50);assert.equal(p.state(6,1).active.rate,1);p.adjustRate(1,22000,50);assert.equal(p.state(6,6).selected.rate,2);
 p.togglePrecision(23000,50);assert.equal(p.state(6,6).active.rate,1);p.beginRace(24000,-170);assert.equal(p.state(6,6).active.rate,2,'New race starts at the selected rate');
});
test('legacy scheduling and all15 encoded choices retain the recovered timing contract',()=>{
 const p=new PlaybackPacer();for(let level=1;level<=15;level++){
  const choice={mode:'legacy',level};assert.deepEqual(parsePlaybackValue(playbackValue(choice,true),true),choice);
  p.configure(choice,100,50);assert.equal(p.delay(120,50.1,80,20),60);assert.equal(p.delay(500,55,0,40),0);
 }
 for(const rate of playbackRates)assert.deepEqual(parsePlaybackValue('clock:'+rate),{mode:'clock',rate});
 for(const bad of [{mode:'clock',rate:3},{mode:'clock',rate:'1'},{mode:'legacy',level:16},null])assert.throws(()=>validatePlayback(bad));
});
test('elapsed cosmetic time freezes/resumes without debt or rate-dependent input',()=>{
 const c=new AnimationClock();assert.equal(c.sample(0),0);c.setPaused(false);assert.equal(c.sample(100),0);assert.equal(c.sample(900),.8);
 c.setPaused(true);assert.equal(c.sample(600000),.8);c.setPaused(false);assert.equal(c.sample(700000),.8);assert.equal(c.sample(700500),1.3);
 c.reset();assert.equal(c.sample(900000),0);assert.throws(()=>c.sample(NaN));
});
test('host pacing metadata cannot change a fixed numerical input/step trajectory',()=>{
 const a=makeRuntime({speed:6}),b=makeRuntime({speed:6}),p=new PlaybackPacer();let now=0;
 for(let n=0;n<150;n++){
  if([10,50,90].includes(n)){a.engine.key(84);b.engine.key(84);}
  p.configure({mode:'clock',rate:playbackRates[n%4]},now,b.memory.readF64(0x5359f0));
  a.engine.step();b.engine.step();now+=5+p.delay(now+5,b.memory.readF64(0x5359f0),80,5);
 }
 assert.deepEqual(a.memory.bytes,b.memory.bytes);assert.deepEqual(a.engine.random.snapshot(),b.engine.random.snapshot());
});
test('original automatic foul slowdown resumes safely through a modern rate control',()=>{
 const {memory:m,engine:e}=makeRuntime({speed:6}),p=new PlaybackPacer();p.configure({mode:'clock',rate:8},0,100);
 m.writeI32(0x4f8cd0,100);m.writeI32(0x4da1dc,1);m.writeI32(0x4f7124,4);m.writeI32(0x4faf84,0);m.writeI32(0x4fb9ac,0);
 updateFoulSlowdown(createFoulSlowdownState(m,1));assert.equal(m.readI32(0x4da174),1);p.slowForWarning(0,100);assert.equal(p.state(6,1).active.rate,1);
 // Match the public modern PageUp path, including its numerical restoration.
 e.key(82);assert.equal(m.readI32(0x5233a8),1);p.adjustRate(1,1,100);e.restoreSpeed(6);
 assert.equal(p.state(6,6).active.rate,2);assert.equal(m.readI32(0x4da174),6);assert.equal(m.readI32(0x4da1dc),2);assert.equal(m.readI32(0x4da1e0),100);assert.equal(m.readI32(0x5233a8),1,'Pace restoration keeps held panel open');
});
