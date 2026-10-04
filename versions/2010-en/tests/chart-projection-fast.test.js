import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {originalDrawing0043ec20} from '../src/render/drawing-functions.js';
import {tryProjectChartPointFast} from '../src/render/chart-projection-fast.js';
import '../src/render/index.js';

const executable=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const originals={numberRendering:false,retainedDrawingStack:{[0x43ec20]:[]}};
const pair=()=>[loadPE32(executable),loadPE32(executable)];
const patch=(memories,fields)=>{for(const memory of memories)for(const [kind,address,value] of fields)memory[`write${kind}`](address,value);};
const resultBits=value=>Buffer.from(value.toBytes()).toString('hex');
const cells=memory=>[Buffer.from(memory.readBytes(0x4fbb88,8)).toString('hex'),memory.readI32(0x4f4b40)];
const compare=(memories,x,y,selector,camera)=>{
  const result=tryProjectChartPointFast(memories[0],x,y,selector,camera);
  assert.ok(result instanceof Float80,'bounded sample accepts exact chart projection');
  const original=originalDrawing0043ec20(memories[1],null,null,originals,Float80.fromNumber(x),Float80.fromNumber(y),selector,camera);
  assert.equal(resultBits(result),resultBits(original));
  assert.deepEqual(cells(memories[0]),cells(memories[1]));
};

test('exact chart leaf matches original camera, global-origin and heading modes over 1200 points',()=>withX87ControlWord(0x027f,()=>{
  const memories=pair();let state=0x43ec20;
  const random=()=>{state=(Math.imul(state,1664525)+1013904223)>>>0;return state;};
  const selectors=[-3,-2,-1,0,1,2,3,4];
  for(let index=0;index<1200;index++){
    const camera=index%30+1,selector=selectors[index%selectors.length];
    patch(memories,[['F64',0x4f6af8+camera*8,(random()%200001-100000)/8],
      ['F64',0x4f6c10+camera*8,(random()%200001-100000)/8],['I32',0x536410,random()%20001-10000],
      ['I32',0x536414,random()%20001-10000],['I32',0x525a78+camera*4,index%5],
      ['I32',0x4fbb90+camera*4,random()%360],['I32',0x535740+camera*4,random()%360],
      ['I32',0x522b90+camera*4,random()%360]]);
    compare(memories,(random()%200001-100000)/16,(random()%200001-100000)/16,selector,camera);
  }
}));

test('exact chart leaf preserves literal axis constants, signed zero and two-store order',()=>withX87ControlWord(0x027f,()=>{
  const memories=pair();patch(memories,[['F64',0x4f6b00,0],['F64',0x4f6c18,0],
    ['I32',0x536410,0],['I32',0x536414,0],['I32',0x4fbb94,0],['I32',0x525a7c,0]]);
  for(const x of [-0,0,-1,1])for(const y of [-0,0,-1,1])for(const selector of [-1,0,1,2,3])compare(memories,x,y,selector,1);
  for(const [address,value] of [[0x4cc740,3],[0x4cc658,1],[0x4cc568,.02],[0x4cc3e8,58]]){
    patch(memories,[[ 'F64',address,value]]);
    for(const x of [0,1,1.125])compare(memories,x,-2.25,-1,1);
  }
  const writes=memories.map(()=>[]);
  for(const [index,memory] of memories.entries())for(const kind of ['F64','I32']){
    const original=memory[`write${kind}`].bind(memory);
    memory[`write${kind}`]=(address,value)=>{writes[index].push([kind,address,value]);return original(address,value);};
  }
  compare(memories,123.125,-1534.375,-1,1);
  assert.deepEqual(writes[0],writes[1]);
  assert.deepEqual(writes[0].map(([,address])=>address),[0x4fbb88,0x4f4b40]);
}));

test('unsupported chart controls and arguments decline before outputs or provider getters',()=>{
  for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
    const memories=pair(),before=cells(memories[0]);
    const cases=[[undefined,2,-1,1],[Infinity,2,-1,1],[Float80.fromNumber(1),2,-1,1],
      [Number.MIN_VALUE,0,-1,1],[1e20,2,-1,1],[1,2,-1,31],[1,2,Float80.fromNumber(1),1]];
    if(word!==0x027f)cases.push([123.125,-1534.375,-1,1]);
    for(const args of cases){assert.equal(tryProjectChartPointFast(memories[0],...args),undefined);assert.deepEqual(cells(memories[0]),before);}
    for(const field of ['sinCos','atan2','retainedDrawingStack','drawingDependencies','numberRendering']){
      let gets=0;const options=Object.defineProperty({},field,{get(){gets++;throw new Error('provider getter');}});
      assert.equal(tryProjectChartPointFast(memories[0],123.125,-1534.375,-1,1,options),undefined);
      assert.equal(gets,0);assert.deepEqual(cells(memories[0]),before);
    }
  });
});
