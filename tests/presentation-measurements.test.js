import test from 'node:test';
import assert from 'node:assert/strict';
import vm from 'node:vm';
import {presentationMeasurementInstrumentation,summarizePresentation} from '../tools/presentation-measurements.js';

test('presentation sampling observes completed frame ids without advancing or scheduling a paint',()=>{
  const callbacks=[],state={frames:4,memory:{readF64:address=>address===17?8:undefined}};
  const context=vm.createContext({tact:{state},performance:{now:()=>23},
    requestAnimationFrame:callback=>callbacks.push(callback)});
  vm.runInContext(presentationMeasurementInstrumentation(17),context);
  assert.equal(callbacks.length,0);
  context.startPresentationMeasurements();callbacks.shift()(20);
  assert.equal(state.frames,4);
  assert.deepEqual(JSON.parse(JSON.stringify(context.presentationMeasurements)),[{timestamp:20,sampledAt:23,frame:4,time:8}]);
  context.stopPresentationMeasurements();callbacks.shift()(40);
  assert.equal(callbacks.length,0);assert.equal(context.presentationMeasurements.length,1);
});

test('presentation summary distinguishes repeated opportunities and unobserved completed updates',()=>{
  const rows=[{frame:4,sampledAt:0},{frame:5,sampledAt:20},{frame:5,sampledAt:40},
    {frame:7,sampledAt:70},{frame:8,sampledAt:90},{frame:9,sampledAt:110}];
  const result=summarizePresentation(rows,4,8);
  assert.equal(result.renderedUpdates,4);assert.equal(result.distinctCompletedFramesSampled,3);
  assert.equal(result.repeatedFrameOpportunities,1);assert.equal(result.renderedUpdatesWithoutSample,1);
  assert.equal(result.largestFrameJump,2);assert.equal(result.contentInterval.meanMs,35);
  assert.equal(result.contentInterval.maxMs,50);assert.equal(result.finalFence.frame,8);
  assert.equal(summarizePresentation([],4,8).sampledContentFramesPerSecond,null);
});
