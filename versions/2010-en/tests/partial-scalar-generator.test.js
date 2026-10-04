import test from 'node:test';
import assert from 'node:assert/strict';
import {execFileSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {pythonCommand} from '../../../tools/python-command.js';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {createLocalFrame,framePointer,writeLocal,readLocal,writeLocalFloatNumber,readLocalFloatNumber,readLocalFloatWordsNumber,cFloat} from '../src/render/typed-c.js';
import {scalarStoreI32} from '../src/render/scalar-stack.js';
import {fpScalarRead,fpScalarStoreF64,fpLoad} from '../src/render/float-values.js';

let emitted;
const cells=()=>{
  if(!emitted){
    const root=fileURLToPath(new URL('../../../',import.meta.url));
    emitted=JSON.parse(execFileSync(pythonCommand,[
      fileURLToPath(new URL('partial-scalar-generator.py',import.meta.url)),'--emit-cell-contract',
    ],{cwd:root,encoding:'utf8',stdio:'pipe'}));
  }
  const bindings=emitted.bindings.replaceAll('scalarRead(', 'fpScalarRead(').replaceAll('scalarStoreF64(', 'fpScalarStoreF64(');
  return new Function('Float80','fpScalarRead','fpScalarStoreF64','fpLoad','cFloat',`${bindings}\nreturn {arrays:[scalarArray396,scalarArray476,scalarArray568,scalarArray728],storeF64:scalarArrayF64Store,readF64:scalarArrayF64Read,readWords:scalarFloatWordsNumber};`)(Float80,fpScalarRead,fpScalarStoreF64,fpLoad,cFloat);
};
const capture=call=>{
  try{return {value:call()};}catch(error){return {error:{name:error.constructor.name,message:error.message}};}
};

test('partial scalar generation proves array bounds, alias disjointness and unchanged retained fallback',()=>{
  for(const array of cells().arrays){
    assert.equal(array.length,18);
    for(let index=0;index<18;index++){
      assert.ok(Object.hasOwn(array,index));
      assert.equal(array[index],undefined);
      assert.throws(()=>fpScalarRead(array[index]),/undefined retained local byte/);
    }
  }
});

for(const cw of [0x007f,0x027f,0x037f])test(`promoted F64 cells and CONCAT44 loads retain binary64 images and failures under CW${cw.toString(16)}`,()=>{
  withX87ControlWord(cw,()=>{
    const {storeF64,readF64,readWords}=cells();
    const values=[undefined,-0,0,-1,1,Number.MIN_VALUE,-Number.MIN_VALUE,Number.MAX_VALUE,
      NaN,Infinity,-Infinity,1n,1n<<100n,Float80.fromNumber(-0),
      new Float80(1,(1n<<63n)+1025n,-63),new Float80(1,1n<<63n,2000),
      'semantic string',{frame:createLocalFrame(8),offset:0},{events:[]},()=>123];
    for(const [index,value] of values.entries())for(const [load,byteLoad] of [[readF64,readLocalFloatNumber],[readWords,at=>readLocalFloatWordsNumber(null,at)]]){
      const actual=capture(()=>load(storeF64(value)));
      const expected=capture(()=>{
        const at=framePointer(createLocalFrame(880),728);
        writeLocalFloatNumber(at,value);
        return byteLoad(at);
      });
      assert.deepEqual(actual,expected,`input${index}, ${load===readF64?'named F64':'CONCAT44'} load`);
      if(expected.value&&typeof expected.value==='object'||typeof expected.value==='function')assert.equal(actual.value,expected.value);
    }
  });
});

test('promoted I32 array stores retain signed wrapping and strict invalidation',()=>{
  for(const value of [undefined,-0,0,-1,0xffffffff,0x100000001,-0x80000001,1n<<64n,NaN,Infinity,{events:[]}]){
    assert.deepEqual(capture(()=>fpScalarRead(scalarStoreI32(value))),capture(()=>{
      const at=framePointer(createLocalFrame(880),476);
      writeLocal(at,value,4,'int');return readLocal(at,4,'int');
    }));
  }
  const array=cells().arrays[0],frame=createLocalFrame(880),at=framePointer(frame,396);
  for(const value of [17,undefined,-1,undefined,0xffffffff]){
    array[0]=scalarStoreI32(value);writeLocal(at,value,4,'int');
    assert.deepEqual(capture(()=>fpScalarRead(array[0])),capture(()=>readLocal(at,4,'int')));
  }
});

test('array overflow spills fail only when loaded and can be overwritten',()=>{
  const {storeF64,readF64,readWords}=cells();
  const huge=new Float80(1,1n<<63n,2000),at=framePointer(createLocalFrame(880),568);
  let value;
  assert.doesNotThrow(()=>{value=storeF64(huge);writeLocalFloatNumber(at,huge);});
  for(const load of [readF64,readWords])assert.deepEqual(capture(()=>load(value)),
    capture(()=>readLocalFloatWordsNumber(null,at)));
  value=storeF64(-0);writeLocalFloatNumber(at,-0);
  assert.ok(Object.is(readF64(value),readLocalFloatNumber(at)));
  assert.ok(Object.is(readWords(value),readLocalFloatWordsNumber(null,at)));
});

test('emitted CONCAT44 helper retains the zero-byte image of semantic F64 cells',()=>{
  const {readF64,readWords}=cells();
  for(const value of [{frame:createLocalFrame(8),offset:0},{events:[]},'text',()=>42]){
    const at=framePointer(createLocalFrame(880),728);
    writeLocal(at,value,8,'float');
    assert.equal(readF64(value),readLocalFloatNumber(at));
    assert.ok(Object.is(readWords(value),readLocalFloatWordsNumber(null,at)));
  }
});
