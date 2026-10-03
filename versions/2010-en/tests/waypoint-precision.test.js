import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {clampedPointDistance,clampedPointDistanceExtended} from '../src/engine/waypoints.js';

const original=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const cases=[];
for(const power of [-1074,-1022,-600,-513,-512,-511,-128,-1,0,1,255,510,511,512,1023]){
  const v=2**power;
  for(const sign of [-1,1])for(const args of [[sign*v,0,0,0],[0,sign*v,0,0],[sign*v,-sign*v,-sign*v,sign*v],[v,v,v,v]])cases.push(args);
}
for(const v of [-0,0,1,2,10,100,1000,10000,50000,1e150,1e154,1e155,1e308]){
  for(const other of [-0,0,v,-v])cases.push([v,other,other,v]);
}
let seed=0x523ade67;
const next=()=>{seed=(Math.imul(seed,1664525)+1013904223)>>>0;return seed;};
for(let index=0;index<2000;index++)cases.push(Array.from({length:4},()=>((next()/4294967296)-.5)*30000));
cases.push([NaN,0,0,0],[Infinity,0,0,0],[-Infinity,0,0,0],[Float80.fromNumber(1),0,0,0]);

const capture=(routine,memory,args)=>{
  try{return {bits:Buffer.from(routine(memory,...args).toBytes()).toString('hex')};}
  catch(error){return {error:error.constructor.name,message:error.message};}
};
for(const cw of [0x027f,0x037f])test(`distance guards preserve extended results and failures under CW${cw.toString(16)}`,()=>{
  const memory=loadPE32(original);
  withX87ControlWord(cw,()=>{
    for(const [index,args] of cases.entries()){
      assert.deepEqual(capture(clampedPointDistance,memory,args),capture(clampedPointDistanceExtended,memory,args),`input ${index}`);
    }
  });
});
