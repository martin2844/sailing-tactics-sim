import test from 'node:test';
import assert from 'node:assert/strict';
import {AddressSpaceMemory,originalAddressSpaceMemoryState} from '../../../src/runtime/memory.js';
import {withX87ControlWord,setX87ControlWord} from '../../../src/runtime/float80.js';
import {waterNumberMemoryEnabled} from '../src/render/water-number-domain.js';

const memory=()=>new AddressSpaceMemory(0x2000,0x4cc000);
test.beforeEach(()=>setX87ControlWord(0x027f));
test.afterEach(()=>setX87ControlWord(0x037f));

test('only unchanged ordinary memory in the reviewed nearest53 context is accepted',()=>{
  const value=memory(),state=originalAddressSpaceMemoryState(value);
  assert.ok(Object.isFrozen(state));
  assert.equal(state.view,value.view);assert.equal(state.bytes,value.bytes);
  assert.equal(waterNumberMemoryEnabled(value),true);
  for(const word of [0x037f,0x007f,0x027e]){
    assert.equal(withX87ControlWord(word,()=>waterNumberMemoryEnabled(value)),false);
  }
  assert.equal(waterNumberMemoryEnabled(new AddressSpaceMemory(4,0x4cc5c8)),false);
});

test('Proxy and duck-memory rejection precede all host traps and getters',()=>{
  let observed=0;
  const handler={get(){observed++;throw new Error('get');},getOwnPropertyDescriptor(){observed++;throw new Error('descriptor');},
    getPrototypeOf(){observed++;throw new Error('prototype');}};
  for(const value of [new Proxy(memory(),handler),new Proxy({},handler),null,undefined,1,
    {get view(){observed++;throw new Error('view');}}])assert.equal(waterNumberMemoryEnabled(value),false);
  assert.equal(observed,0);
});

test('replacement fields and SharedArrayBuffer-backed views conservatively decline',()=>{
  for(const change of [
    value=>{value.base++;},value=>{value.size--;},value=>{value.bytes=new Uint8Array(value.size);},
    value=>{value.view=new DataView(new ArrayBuffer(value.size));},
    value=>{value.view=new DataView(new SharedArrayBuffer(value.size));},
  ]){const value=memory();change(value);assert.equal(waterNumberMemoryEnabled(value),false);}
  for(const key of ['base','size','bytes','view','readF64','offset']){
    const value=memory();let observed=0;
    Object.defineProperty(value,key,{get(){observed++;throw new Error('host getter');}});
    assert.equal(waterNumberMemoryEnabled(value),false);assert.equal(observed,0);
  }
});

test('method/prototype changes and detached views decline without invoking replacements',()=>{
  let observed=0;
  for(const key of ['readF64','offset']){
    const value=memory();value[key]=()=>{observed++;throw new Error('replacement');};
    assert.equal(waterNumberMemoryEnabled(value),false);
  }
  const value=memory();
  Object.defineProperty(value.view,'getFloat64',{get(){observed++;throw new Error('view getter');}});
  assert.equal(waterNumberMemoryEnabled(value),false);assert.equal(observed,0);
  class CustomMemory extends AddressSpaceMemory{}
  assert.equal(waterNumberMemoryEnabled(new CustomMemory(0x2000,0x4cc000)),false);
  const changed=memory();Object.setPrototypeOf(changed,{});
  assert.equal(waterNumberMemoryEnabled(changed),false);
  const detached=memory();structuredClone(detached.bytes.buffer,{transfer:[detached.bytes.buffer]});
  assert.equal(waterNumberMemoryEnabled(detached),false);
});

test('constructor snapshots introduce no extra subclass field getters',()=>{
  const events=[],allocated={};
  class FieldMemory extends AddressSpaceMemory{
    set base(value){events.push(['base:set',value]);}
    get base(){throw new Error('unexpected base getter');}
    set size(value){events.push(['size:set',value]);}
    get size(){throw new Error('unexpected size getter');}
    set bytes(value){events.push(['bytes:set',value.length]);allocated.bytes=value;}
    get bytes(){events.push(['bytes:get']);return allocated.bytes;}
    set view(value){events.push(['view:set',value.byteLength]);allocated.view=value;}
    get view(){throw new Error('unexpected view getter');}
  }
  const value=new FieldMemory(0x2000,0x4cc000);
  assert.deepEqual(events,[['base:set',0x4cc000],['size:set',0x2000],['bytes:set',0x2000],['bytes:get'],['view:set',0x2000]]);
  const state=originalAddressSpaceMemoryState(value);
  assert.equal(state.bytes,allocated.bytes);assert.equal(state.view,allocated.view);
});

test('a constructor-original shared view declines even when all recorded identities match',()=>{
  const shared=new Uint8Array(new SharedArrayBuffer(0x2000));
  let allocated;
  class SharedViewMemory extends AddressSpaceMemory{
    set bytes(value){allocated=value;}
    get bytes(){return shared;}
    constructor(){
      super(0x2000,0x4cc000);
      Object.defineProperty(this,'bytes',{value:allocated});
      Object.setPrototypeOf(this,AddressSpaceMemory.prototype);
    }
  }
  const value=new SharedViewMemory();
  assert.equal(originalAddressSpaceMemoryState(value).view,value.view);
  assert.equal(originalAddressSpaceMemoryState(value).bytes,value.bytes);
  assert.equal(waterNumberMemoryEnabled(value),false);
});
