import test from 'node:test';import assert from 'node:assert/strict';import {profileNumericalWork} from '../../app/engine/diagnostics/work-profile.ts';import {makeRuntime} from './fixtures.mjs';
test('worker cost profiling preserves the actual numerical trajectory and restores all callbacks',()=>{
 const a=makeRuntime({speed:6}),b=makeRuntime({speed:6}),before={...b.engine.options};for(let n=0;n<50;n++)a.engine.step();
 const report=profileNumericalWork(b.engine.options,()=>b.engine.step(),50);
 assert.deepEqual(b.memory.bytes,a.memory.bytes);assert.deepEqual(b.engine.random.snapshot(),a.engine.random.snapshot());assert.deepEqual(b.engine.options,before);
 assert.equal(report.steps,50);assert.equal(report.phases.updateBoatWindAndAI.calls,250);assert.ok(report.phases.originalUpdateBoatWindAndAI.calls===250);assert.ok(report.totalMs>=0);
});
test('profiling restores callback identities and observer presence after the original failure',()=>{
 for(const present of[false,true]){const failure=Error('original numerical failure'),fn=function(value){assert.equal(this,options);assert.equal(value,42);throw failure},options={updateGlobalWind:fn};if(present)options.aiWorkObserver=undefined;
 assert.throws(()=>profileNumericalWork(options,()=>options.updateGlobalWind(42),1),e=>e===failure);
 assert.equal(options.updateGlobalWind,fn);assert.equal(Object.hasOwn(options,'aiWorkObserver'),present);}
});
