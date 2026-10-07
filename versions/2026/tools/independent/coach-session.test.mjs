import test from 'node:test';import assert from 'node:assert/strict';
import {makeRuntime} from './fixtures.mjs';
import {EventSession} from '../../app/event-session.ts';
import {sampleSpatialWind} from '../../public/legacy/versions/2010-en/src/engine/ai.js';
test('actual sheltered-wind producer survives the numerical integration reset',()=>{
 const {memory:m,engine:e}=makeRuntime();const wind=sampleSpatialWind(m,-1000,-1000,1,e.options);
 assert.ok(wind<m.readI32(0x522ad0)-1);assert.equal(m.readI32(0x4fb224),1);
 e.options.integratePositions(m,e.random.gameplay,e.options);assert.equal(m.readI32(0x4fb224),1);
 // At a fresh step this transient value must not survive without a producer.
 e.options.updateBoatWindAndAI=()=>{};e.step();assert.equal(m.readI32(0x4fb224),0);
});
test('manual-sheet heel warning survives integration during prestart',()=>{
 const {memory:m,engine:e}=makeRuntime({setupCommands:[32799,32816,32794,32806,32909]});e.key(114);e.key(79);let samples=0;
 for(let n=0;n<500;n++){e.step();const warning=m.readI32(0x4fc2c4)>m.readI32(0x4f4200)+1&&m.readI32(0x500384)>=0;
  if(warning)samples++;assert.equal(m.readI32(0x4fb21c),Number(warning));}
 assert.ok(samples>0);assert.ok(m.readI32(0x4f8cd0)<0);
});
test('replaying a completed active championship race removes its discarded receipt only',()=>{
 const session=new EventSession('championship',3);
 const state={resultsReady:true,seriesScoring:true,completedRaces:1,boats:[{id:1,name:'Fire',finished:1,points:[100,0,0]}]};
 session.receive(state);session.next();session.receive({...state,completedRaces:2,boats:[{...state.boats[0],points:[100,202,0]}]});
 assert.equal(session.races.length,2);session.rewindCurrentRace();assert.equal(session.races.length,1);assert.equal(session.activeRace,2);assert.equal(session.canContinue,false);
 session.receive({...state,completedRaces:2,boats:[{...state.boats[0],points:[100,303,0]}]});assert.equal(session.races.length,2);assert.equal(session.standings[0].points,403);
});
