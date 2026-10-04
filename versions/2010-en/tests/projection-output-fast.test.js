import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { Float80,withX87ControlWord } from '../../../src/runtime/float80.js';
import { originalDrawing0043e730 } from '../src/render/drawing-functions.js';
import { tryProjectScenePointOutputFast } from '../src/render/projection-output-fast.js';
import '../src/render/index.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const byteOptions={numberRendering:false,retainedDrawingStack:{[0x43e730]:[],[0x43ea10]:[],[0x43eb00]:[]}};
const memories=()=>[loadPE32(source),loadPE32(source)];
const patch=(pair,fields)=>{for(const memory of pair)for(const [kind,address,value] of fields)memory[`write${kind}`](address,value);};
const outputs=(memory,index)=>({distance:Buffer.from(memory.readBytes(0x4fbb88,8)).toString('hex'),
  degrees:memory.readI32(0x535ff4),y:memory.readI32(0x523660+index*4),x:memory.readI32(0x4fed58+index*4)});
const view=(pair,camera=1,mode=1)=>patch(pair,[['I32',0x4f71c0+camera*4,mode],['I32',0x4fbb90+camera*4,0],
  ['F64',0x4f6af8+camera*8,0],['F64',0x4f6c10+camera*8,0],['I32',0x4da148,200],
  ['I32',0x4f4b48,240],['I32',0x4fe2a8,734],['I32',0x4f40a8,512],['F64',0x5259d0,1]]);

test('certified point outputs match complete original stores across camera changes and perspective modes',()=>withX87ControlWord(0x027f,()=>{
  const pair=memories();let state=0x43e730,accepted=0;
  const random=()=>{state=(Math.imul(state,1664525)+1013904223)>>>0;return state;};
  for(let iteration=0;iteration<1000;iteration++){
    const camera=iteration%30+1,index=iteration%31,mode=iteration%2+1,selector=iteration%3===0?5:0;
    view(pair,camera,mode);
    const heading=random()%360,cameraX=(random()%200001-100000)/16,cameraY=(random()%200001-100000)/16;
    patch(pair,[['I32',0x4fbb90+camera*4,heading],['I32',0x5364c8,iteration%2],
      ['F64',0x4f6af8+camera*8,cameraX],['F64',0x4f6c10+camera*8,cameraY]]);
    const direction=(heading+(random()%22001-11000)/100)*Math.PI/180,distance=50+random()%20000;
    const x=cameraX+Math.sin(direction)*distance,y=cameraY-Math.cos(direction)*distance;
    const before=outputs(pair[0],index);
    if(tryProjectScenePointOutputFast(pair[0],index,x,y,camera,selector)!==true){
      assert.deepEqual(outputs(pair[0],index),before,'declined output computation writes nothing');
      continue;
    }
    accepted++;
    originalDrawing0043e730(pair[1],null,null,byteOptions,index,Float80.fromNumber(x),Float80.fromNumber(y),camera,selector);
    assert.deepEqual(outputs(pair[0],index),outputs(pair[1],index),`certified point ${iteration}`);
  }
  assert.ok(accepted>650,`the common path must certify a substantial corpus: ${accepted}/1000`);
}));

test('certified projection preserves original distance, bearing, row, column store order',()=>withX87ControlWord(0x027f,()=>{
  const pair=memories();view(pair);
  const writes=pair.map(()=>[]);
  for(const [index,memory] of pair.entries())for(const kind of ['F64','I32']){
    const original=memory[`write${kind}`].bind(memory);
    memory[`write${kind}`]=(address,value)=>{writes[index].push([kind,address,value]);return original(address,value);};
  }
  assert.equal(tryProjectScenePointOutputFast(pair[0],0,123.125,-1534.375,1,0),true);
  originalDrawing0043e730(pair[1],null,null,byteOptions,0,Float80.fromNumber(123.125),Float80.fromNumber(-1534.375),1,0);
  assert.deepEqual(writes[0],writes[1]);
  assert.deepEqual(writes[0].map(([,address])=>address),[0x4fbb88,0x535ff4,0x523660,0x4fed58]);
}));

test('unsupported controls, semantic arguments and provider/retained paths decline before stores or getters',()=>{
  for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
    const pair=memories();view(pair);const before=outputs(pair[0],0);
    const invalid=[[0,1,2,1,99],[31,1,2,1,0],[-1,1,2,1,0],[0,1,2,31,0],
      [0,undefined,2,1,0],[0,Infinity,2,1,0],[0,Float80.fromNumber(1),2,1,0],[0,1e20,2,1,0]];
    if(word!==0x027f)invalid.push([0,123.125,-1534.375,1,0]);
    for(const args of invalid){assert.equal(tryProjectScenePointOutputFast(pair[0],...args),undefined);assert.deepEqual(outputs(pair[0],0),before);}
    for(const field of ['sinCos','atan2','retainedDrawingStack','drawingDependencies']){
      let gets=0;const options=Object.defineProperty({},field,{get(){gets++;throw new Error('provider getter evaluated');}});
      assert.equal(tryProjectScenePointOutputFast(pair[0],0,123.125,-1534.375,1,0,options),undefined);
      assert.equal(gets,0);assert.deepEqual(outputs(pair[0],0),before);
    }
    patch(pair,[['I32',0x4f71c4,3]]);
    assert.equal(tryProjectScenePointOutputFast(pair[0],0,123.125,-1534.375,1,0),undefined);
    assert.deepEqual(outputs(pair[0],0),before);
  });
});

test('public Number routing retains original formal conversion and byte fallback semantics',()=>withX87ControlWord(0x027f,()=>{
  const pair=memories();view(pair);
  for(const args of [[0,123.125,-1534.375,1,0],[0,-0,-500,1,0],[0,Float80.fromNumber(-0),-500,1,0],
    [0,123.125,-1534.375,1,5],[0,Number.MIN_VALUE,-500,1,0],[0,2**63,-500,1,0]]){
    const observe=(memory,options)=>{try{originalDrawing0043e730(memory,null,null,options,...args);return {outputs:outputs(memory,0)};}
      catch(error){return {error:{name:error.name,message:error.message},outputs:outputs(memory,0)};}};
    assert.deepEqual(observe(pair[0],{}),observe(pair[1],byteOptions));
  }
}));
