import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {clampedPointDistance,clampedPointDistanceExtended,nearestWaypointDistance,nearestWaypointDistanceExtended} from '../src/engine/waypoints.js';

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

const nearestCases=[
  {points:[],query:[NaN,Infinity],excluded:-1},
  {points:[[0,0]],query:[0,0],excluded:0},
  ...cases.slice(0,172).map(args=>({points:[[args[2],args[3]],[0,0],[50000,0]],query:args.slice(0,2),excluded:-1})),
  ...[NaN,Infinity,-Infinity,Float80.fromNumber(1),'1',undefined].map(value=>({points:[[0,0]],query:[value,0],excluded:-1})),
  ...[NaN,Infinity,-Infinity,2147483647,2147483648,4294967295,-1,0,1,2].map(excluded=>({points:[[0,0],[10,20],[30,40]],query:[3,4],excluded})),
];
for(let index=0;index<400;index++){
  const query=Array.from({length:2},()=>((next()/4294967296)-.5)*100000);
  const points=Array.from({length:8},()=>Array.from({length:2},()=>((next()/4294967296)-.5)*100000));
  nearestCases.push({points,query,excluded:index%10-1});
}
for(const cw of [0x007f,0x027f,0x037f])test(`nearest scan preserves extended minimum spills and failures under CW${cw.toString(16)}`,()=>{
  const memory=loadPE32(original);
  withX87ControlWord(cw,()=>{
    for(const [index,{points,query,excluded}] of nearestCases.entries()){
      memory.writeI32(0x4da1f4,points.length-1);
      for(const [point,[x,y]] of points.entries()){
        memory.writeF64(0x4f7220+point*8,x);
        memory.writeF64(0x4ff038+point*8,y);
      }
      const args=[...query,excluded];
      assert.deepEqual(capture(nearestWaypointDistance,memory,args),capture(nearestWaypointDistanceExtended,memory,args),`input ${index}`);
    }
  });
});

test('distance and nearest guards preserve altered clamp constants and unsupported loads',()=>{
  const memory=loadPE32(original),addresses=[0x4cc658,0x4cccc8,0x4cccc0];
  const saved=addresses.map(address=>memory.readF64(address));
  memory.writeI32(0x4da1f4,1);
  memory.writeF64(0x4f7220,0);memory.writeF64(0x4ff038,0);
  memory.writeF64(0x4f7228,1e154);memory.writeF64(0x4ff040,1e154);
  withX87ControlWord(0x027f,()=>{
    for(const address of addresses)for(const value of [-Infinity,-50000,-0,0,Number.MIN_VALUE,1,50000,Number.MAX_VALUE,Infinity,NaN]){
      addresses.forEach((slot,index)=>memory.writeF64(slot,saved[index]));
      memory.writeF64(address,value);
      for(const args of [[0,0,0,0],[1,2,3,4],[1e154,1e154,-1e154,-1e154]]){
        assert.deepEqual(capture(clampedPointDistance,memory,args),capture(clampedPointDistanceExtended,memory,args),`constant ${address.toString(16)} = ${value}`);
      }
      assert.deepEqual(capture(nearestWaypointDistance,memory,[3,4,-1]),capture(nearestWaypointDistanceExtended,memory,[3,4,-1]),`nearest constant ${address.toString(16)} = ${value}`);
    }
  });
});

test('nearest scan preserves failed original memory reads and count bounds',()=>{
  withX87ControlWord(0x027f,()=>{
    for(const count of [-2147483648,-1,0,2147483647]){
      const memory={readI32(){return count;},readF64(address){throw new RangeError(`Missing original memory at ${address}`);}};
      for(const excluded of [-1,0])assert.deepEqual(capture(nearestWaypointDistance,memory,[0,0,excluded]),capture(nearestWaypointDistanceExtended,memory,[0,0,excluded]));
    }
  });
});
