import test from 'node:test';
import assert from 'node:assert/strict';
import {PoseyRng} from '../../../../src/engine/integer-core.js';
import {RandomStream,RandomStreams} from '../../app/engine/random/streams.ts';

test('new owned stream retains the recovered distribution and state exactly',()=>{
 for(const seed of[0,1,1546300800,0xffffffff]){
   const original=new PoseyRng(seed),current=new RandomStream(seed);
   for(let n=0;n<1000;n++){assert.equal(current.rand(),original.rand());assert.equal(current.state,original.state);}
 }
});

test('cosmetic and wave activity cannot advance gameplay randomness',()=>{
 const a=new RandomStreams(7),b=new RandomStreams(7);
 for(let n=0;n<100;n++){a.presentation.rand();a.waves.rand();}
 for(let n=0;n<100;n++)assert.equal(a.gameplay.rand(),b.gameplay.rand());
 assert.notEqual(a.waves.state,b.waves.state);assert.notEqual(a.presentation.state,b.presentation.state);
 const state=a.snapshot(),next=[a.gameplay.rand(),a.waves.rand(),a.presentation.rand()];
 a.restore(state);assert.deepEqual([a.gameplay.rand(),a.waves.rand(),a.presentation.rand()],next);
});
