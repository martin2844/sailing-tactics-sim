import test from 'node:test';
import assert from 'node:assert/strict';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {createLocalFrame,framePointer,readLocal,readLocalArgument,writeLocal} from '../src/render/typed-c.js';
import {scalarRead,scalarReadArgument,scalarStoreI32,scalarStoreF64} from '../src/render/scalar-stack.js';
import {GdiTrace} from '../src/render/gdi.js';

const capture=call=>{
  try{
    const value=call();
    return value instanceof Float80?{bits:Buffer.from(value.toBytes()).toString('hex')}:{value};
  }catch(error){return {name:error.constructor.name,message:error.message};}
};
const inputs=[undefined,null,false,true,0,-0,1,-1,2147483647,2147483648,4294967295,4294967296,
  1.5,-1.5,Number.MIN_VALUE,Number.MAX_VALUE,Infinity,-Infinity,NaN,1n,-1n,1n<<40n,
  '', 'original boat name',new GdiTrace(),()=>123,
  {frame:createLocalFrame(8),offset:0},{array:[1,2],offset:0},{dc:new GdiTrace(),offset:0},
  {clipRect:[0,0,10,20]},{restoreClip:true},{stockObject:5},
  {frame:null},{array:null},{dc:null},{events:null},
  {frame:false,valueOf:()=>4294967297},{array:0,valueOf:()=>-3},
  {dc:null,valueOf:()=>1n},{frame:null,valueOf:()=>Symbol('invalid')},
  {array:null,valueOf:()=>{throw new RangeError('stored conversion failed');}},
  Float80.fromNumber(-0),Float80.fromNumber(Number.MIN_VALUE),Float80.fromNumber(1.5),
  new Float80(-1,(1n<<63n)+1025n,-63),new Float80(1,1n<<63n,2000)];

for(const cw of [0x007f,0x027f,0x037f])for(const [size,kind,store] of [[4,'int',scalarStoreI32],[8,'float',scalarStoreF64]]){
  test(`scalar ${kind} slots match stored bytes, semantic identities and failures under CW${cw.toString(16)}`,()=>{
    withX87ControlWord(cw,()=>{
      // Both packed argument slots and high materialized stack offsets must
      // produce exactly the same result as the proven byte-frame operations.
      for(const offset of [0,4,32,40])for(const [index,value] of inputs.entries()){
        const actual=capture(()=>scalarRead(store(value)));
        const expected=capture(()=>{
          const frame=createLocalFrame(64),at=framePointer(frame,offset);
          writeLocal(at,value,size,kind);return readLocal(at,size,kind);
        });
        assert.deepEqual(actual,expected,`offset ${offset}, input ${index}`);
        if(expected.value&&typeof expected.value==='object'||typeof expected.value==='function'||typeof expected.value==='string'){
          assert.equal(actual.value,expected.value,`offset ${offset}, input ${index}: semantic identity`);
        }
      }
    });
  });
}

test('undefined scalar arguments propagate until a strict local read observes them',()=>{
  for(const [size,kind,store] of [[4,'int',scalarStoreI32],[8,'float',scalarStoreF64]]){
    const frame=createLocalFrame(16),at=framePointer(frame,0);
    assert.equal(readLocalArgument(at,size,kind),undefined);
    let scalar;
    assert.equal(scalar,undefined);
    scalar=store(scalar);
    assert.deepEqual(capture(()=>scalarRead(scalar)),capture(()=>readLocal(at,size,kind)));
    scalar=store(123);
    writeLocal(at,123,size,kind);
    assert.deepEqual(capture(()=>scalarRead(scalar)),capture(()=>readLocal(at,size,kind)));
    scalar=store(undefined);
    writeLocal(at,undefined,size,kind);
    assert.deepEqual(capture(()=>scalarRead(scalar)),capture(()=>readLocal(at,size,kind)));
  }
});

test('finite extended overflow is allowed at a binary64 store and rejected only at a later load',()=>{
  for(const sign of [1,-1]){
    const huge=new Float80(sign,1n<<63n,2000),frame=createLocalFrame(16),at=framePointer(frame,0);
    let scalar;
    assert.doesNotThrow(()=>{scalar=scalarStoreF64(huge);writeLocal(at,huge,8,'float');});
    assert.deepEqual(capture(()=>scalarRead(scalar)),capture(()=>readLocal(at,8,'float')));
    assert.deepEqual(capture(()=>scalarReadArgument(scalar)),capture(()=>readLocalArgument(at,8,'float')));
    scalar=scalarStoreF64(7);writeLocal(at,7,8,'float');
    assert.deepEqual(capture(()=>scalarRead(scalar)),capture(()=>readLocal(at,8,'float')));
  }
  assert.equal(scalarReadArgument(undefined),undefined);
  for(const value of [Infinity,-Infinity,NaN])assert.throws(()=>scalarStoreF64(value),/NaN or infinite inputs/);
});
