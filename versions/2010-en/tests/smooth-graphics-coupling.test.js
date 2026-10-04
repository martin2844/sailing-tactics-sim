import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {loadPE32} from '../../../src/runtime/memory.js';
import {withX87ControlWord} from '../../../src/runtime/float80.js';
import {PoseyRng} from '../../../src/engine/integer-core.js';
import {callDrawingDependency,callNumberDrawingDependencyOwned} from '../src/render/dependencies.js';
import '../src/render/drawing-functions.js';
import {reviewRenderSimulationCoupling} from '../tools/diagnostics/review-render-simulation-coupling.mjs';

const source=fs.readFileSync(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const memory=()=>{
  const image=loadPE32(source);
  image.writeI32(0x4da140,1);image.writeI32(0x4da1f4,1);
  image.writeF64(0x4f6b00,200);image.writeF64(0x4f6c18,300);
  image.writeF64(0x4f7228,-5000);image.writeF64(0x4ff040,-5000);
  return image;
};

test('renderer waypoint respawn keeps exact coordinates and random state on both dependency routes',()=>withX87ControlWord(0x027f,()=>{
  for(const heading of [-179,-91,-45,-1,0,1,17,45,89,91,137,179]){
    for(const numeric of [false,true]){
      const exact=memory(),smooth=memory(),a=new PoseyRng(0x12345678),b=new PoseyRng(0x12345678);
      exact.writeI32(0x4fbb94,heading);smooth.writeI32(0x4fbb94,heading);
      const invoke=(image,rng,options)=>numeric
        ?callNumberDrawingDependencyOwned(image,undefined,0x465ff0,[0],0,rng,options)
        :callDrawingDependency(image,undefined,0x465ff0,[0],rng,options);
      invoke(exact,a,{numberRendering:true});
      const options=Object.defineProperty({smoothGraphics:true,numberRendering:true},'unrelated',{get(){throw new Error('Unrelated options getter');}});
      invoke(smooth,b,options);
      assert.deepEqual(smooth.bytes,exact.bytes,`heading${heading},${numeric?'numeric':'public'}: persistent image`);
      assert.equal(b.state,a.state,'shared RNG is consumed identically');
      assert.equal(options.smoothGraphics,true,'caller drawing mode is not changed');
    }
  }
}));

test('exact provider and retained-override paths retain their original options identity and errors',()=>withX87ControlWord(0x027f,()=>{
  for(const numeric of [false,true])for(const field of ['sinCos','retainedDrawingStack']){
    const run=smooth=>{
      const image=memory(),rng=new PoseyRng(99),calls=[];
      const options=Object.defineProperty({smoothGraphics:smooth},field,{get(){calls.push(field);throw new Error('Original '+field);}});
      try{
        if(numeric)callNumberDrawingDependencyOwned(image,undefined,0x465ff0,[0],0,rng,options);
        else callDrawingDependency(image,undefined,0x465ff0,[0],rng,options);
      }catch(error){return {calls,error:{name:error.name,message:error.message},state:rng.state,bytes:Buffer.from(image.bytes)};}
      throw new Error('Expected original override failure');
    };
    assert.deepEqual(run(true),run(false));
  }
}));

test('both camera-heading writers keep exact shared-state projection on ordinary and fallback geometry',()=>withX87ControlWord(0x027f,()=>{
  for(const address of [0x41e0a0,0x41e220])for(const numeric of [false,true]){
    for(const target of [[400,-200],[1e10,-1e10],[-1e10,1e10],[1e10,1e-10]]){
      const exact=memory(),smooth=memory(),a=new PoseyRng(91),b=new PoseyRng(91);
      for(const image of [exact,smooth]){
        image.writeI32(0x4da140,2);image.writeI32(0x512d64,100);image.writeI32(0x512d68,100);
        image.writeF64(0x4f6b00,0);image.writeF64(0x4f6c18,0);
        image.writeF64(0x4f6b08,target[0]);image.writeF64(0x4f6c20,target[1]);
      }
      const invoke=(image,rng,options)=>numeric
        ?callNumberDrawingDependencyOwned(image,undefined,address,[],0,rng,options)
        :callDrawingDependency(image,undefined,address,[],rng,options);
      invoke(exact,a,{numberRendering:true});invoke(smooth,b,{smoothGraphics:true,numberRendering:true});
      assert.deepEqual(smooth.bytes,exact.bytes,`${address.toString(16)},${target}: shared heading and side effects`);
      assert.equal(b.state,a.state);
      assert.notEqual(exact.readI32(address===0x41e0a0?0x4fbb94:0x4fbb98),0,
        'the original inter-boat bearing branch executed');
    }
  }
}));

test('seven real retained render profiles keep all ordered next-frame physics reads/writes and RNG exact',()=>{
  const review=reviewRenderSimulationCoupling({frameLimit:3});
  assert.deepEqual(review.failures,[],'smooth rendering must not change any engine byte read/write or random call');
  assert.equal(review.profiles.length,7);
  assert.equal(review.profiles.reduce((sum,profile)=>sum+profile.frames,0),21);
  assert.ok(review.profiles.some(profile=>profile.rows.some(row=>row.changedByteCount>0)),
    'the smooth renderer really ran and changed rendering bytes');
  assert.ok(review.profiles.some(profile=>profile.rows.some(row=>row.renderRandomCalls>1000)),
    'shared drawing randomness participates in the comparison');
});
