import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { Float80, withX87ControlWord } from '../../../src/runtime/float80.js';
import { sinCosX87 } from '../../../src/runtime/transcendentals.js';
import { atan2Extended } from '../../../src/runtime/atan.js';
import { originalDrawing0043ea10 } from '../src/render/drawing-functions.js';
import { tryProjectPointFast } from '../src/render/projection-fast.js';
import '../src/render/index.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const byteOptions={retainedDrawingStack:{[0x43ea10]:[]}};
const bits=value=>Buffer.from(value.toBytes()).toString('hex');
const observe=(memory,options,args)=>{
  try{
    const result=originalDrawing0043ea10(memory,null,null,options,...args);
    return {returnBits:bits(result),distanceBits:Buffer.from(memory.readBytes(0x4fbb88,8)).toString('hex'),degrees:memory.readI32(0x535ff4)};
  }catch(error){return {error:{name:error.constructor.name,message:error.message},distanceBits:Buffer.from(memory.readBytes(0x4fbb88,8)).toString('hex'),degrees:memory.readI32(0x535ff4)};}
};
const pair=()=>[loadPE32(source),loadPE32(source)];
const patch=(memories,fields)=>{for(const memory of memories)for(const [type,address,value] of fields)memory[`write${type}`](address,value);};

test('bounded camera projection matches the unchanged byte translation across camera changes and exact Float80 arguments',()=>{
  const memories=pair();let randomState=0x2010;
  const random=()=>{randomState=(Math.imul(randomState,1664525)+1013904223)>>>0;return randomState;};
  withX87ControlWord(0x027f,()=>{
    for(let index=0;index<600;index++){
      const camera=index%30+1,heading=index%4===0?0:random()%360;
      patch(memories,[['I32',0x4fbb90+camera*4,heading],['I32',0x5364c8,index%2],
        ['F64',0x4f6af8+camera*8,(random()%200001-100000)/8],['F64',0x4f6c10+camera*8,(random()%200001-100000)/8]]);
      const x=(random()%200001-100000)/16,y=(random()%200001-100000)/16;
      const args=index%3===0?[Float80.fromNumber(x),Float80.fromNumber(y),camera]:[x,y,camera];
      assert.deepEqual(observe(memories[0],{},args),observe(memories[1],byteOptions,args),`case ${index}`);
      // The same retained camera origin must also work for a different point.
      args[0]=x+.125;args[1]=y-.375;
      assert.deepEqual(observe(memories[0],{},args),observe(memories[1],byteOptions,args),`cached camera ${index}`);
    }
  });
});

test('projection preserves signed zero, coincident points and mutated camera constants',()=>{
  const memories=pair();
  withX87ControlWord(0x027f,()=>{
    patch(memories,[['I32',0x4fbb94,0],['F64',0x4f6b00,0],['F64',0x4f6c18,0],
      ['F64',0x4ccae0,0],['F64',0x4ccb20,0]]);
    for(const x of [-0,0,Float80.fromNumber(-0),Float80.fromNumber(0),1,-1])for(const y of [-0,0,Float80.fromNumber(-0),Float80.fromNumber(0),1,-1]){
      const args=[x,y,1];assert.deepEqual(observe(memories[0],{},args),observe(memories[1],byteOptions,args));
    }
    for(const [address,value] of [[0x4f6b00,-0],[0x4f6c18,-0],[0x4ccae0,-0],[0x4ccae0,25],
      [0x4ccb20,90],[0x4cc568,.02],[0x4f6b00,75],[0x4f6c18,-100]]){
      patch(memories,[['F64',address,value]]);
      assert.deepEqual(observe(memories[0],{},[10.125,-80.25,1]),observe(memories[1],byteOptions,[10.125,-80.25,1]));
    }
  });
});

test('custom trig/atan callbacks and explicitly retained local frames keep the original invocation semantics',()=>{
  const memories=pair();
  withX87ControlWord(0x027f,()=>{
    for(const memory of memories)patch([memory],[['I32',0x4fbb94,90],['F64',0x4f6b00,100],['F64',0x4f6c18,-200]]);
    const calls=[[],[]],options=calls.map(rows=>({sinCos(value){rows.push(['trig',bits(value)]);return sinCosX87(value);},
      atan2(y,x){rows.push(['atan',bits(y),bits(x)]);return atan2Extended(y,x);}}));
    assert.equal(tryProjectPointFast(memories[0],[300,400,1],options[0]),undefined);
    assert.deepEqual(observe(memories[0],options[0],[300,400,1]),observe(memories[1],{...options[1],...byteOptions},[300,400,1]));
    assert.deepEqual(calls[0],calls[1]);assert.equal(calls[0].filter(row=>row[0]==='trig').length,2);
    assert.deepEqual(observe(memories[0],Object.freeze({}),[300,400,1]),observe(memories[1],byteOptions,[300,400,1]));
    assert.deepEqual(observe(memories[0],1,[300,400,1]),observe(memories[1],byteOptions,[300,400,1]));
    let accesses=0;const retained=Object.defineProperty({},0x43ea10,{get(){accesses++;return [];}});
    assert.deepEqual(observe(memories[0],{retainedDrawingStack:retained},[300,400,1]),observe(memories[1],byteOptions,[300,400,1]));
    assert.equal(accesses,1);
  });
});

test('non-PC53 control words, extended/subnormal arithmetic and malformed arguments decline without target writes',()=>{
  for(const cw of [0x007f,0x027f,0x037f])withX87ControlWord(cw,()=>{
    const memories=pair();patch(memories,[['I32',0x4fbb94,1],['F64',0x4f6b00,0],['F64',0x4f6c18,0]]);
    const cases=[[Number.MIN_VALUE,0,1],[1e20,0,1],[Infinity,0,1],[undefined,0,1],[1,2,Float80.fromInteger(1)],[1,2,31]];
    for(const args of cases){
      const before=Buffer.from(memories[0].readBytes(0x4fbb88,8)).toString('hex');
      assert.equal(tryProjectPointFast(memories[0],args,{}),undefined);
      assert.equal(Buffer.from(memories[0].readBytes(0x4fbb88,8)).toString('hex'),before);
      assert.deepEqual(observe(memories[0],{},args),observe(memories[1],byteOptions,args),`CW ${cw.toString(16)}, args ${args}`);
    }
  });
  withX87ControlWord(0x027f,()=>{
    const memories=pair();patch(memories,[['I32',0x4fbb94,1],['F64',0x4f6b00,0],['F64',0x4f6c18,0],
      ['F64',0x4cc568,1e-300],['F64',0x4ccae0,1e-300]]);
    assert.equal(tryProjectPointFast(memories[0],[0,0,1],{}),undefined,'nonzero extended product cannot be rounded to zero');
    assert.deepEqual(observe(memories[0],{},[0,0,1]),observe(memories[1],byteOptions,[0,0,1]));
  });
});
