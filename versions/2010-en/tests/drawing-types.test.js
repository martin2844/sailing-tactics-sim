import test from 'node:test';
import assert from 'node:assert/strict';
import {Float80} from '../../../src/runtime/float80.js';
import {createLocalFrame,framePointer,writeLocal,readLocal,readLocalArgument,cWordArgument,cString,cRawWord,cConcat,bitsAsF64,cBits,cI64,readPointer,pointerAdd} from '../src/render/typed-c.js';
import {GdiTrace} from '../src/render/gdi.js';
import {writeCString} from '../src/render/text.js';

test('unknown register spills retain undefined bytes until original stores define them',()=>{
  const frame=createLocalFrame(16),at=framePointer(frame,4);
  writeLocal(at,undefined,4);
  assert.throws(()=>readLocal(at,4),/undefined retained local/);
  writeLocal(at,0x12345678,4);
  assert.equal(readLocal(at,4),0x12345678);
  writeLocal(framePointer(frame,6),undefined,2);
  assert.throws(()=>readLocal(at,4),/undefined retained local/);
  assert.equal(readLocal(at,2),0x5678);
});

test('an unused argument propagates unknown bytes and still fails if the callee reads them',()=>{
  const caller=createLocalFrame(4),callee=createLocalFrame(4);
  writeLocal(framePointer(callee,0),readLocalArgument(framePointer(caller,0),4),4);
  assert.throws(()=>readLocal(framePointer(callee,0),4),/undefined retained local/);
  writeLocal(framePointer(callee,0),cWordArgument(readLocalArgument(framePointer(caller,0),4)),4);
  assert.throws(()=>readLocal(framePointer(callee,0),4),/undefined retained local/);
  writeLocal(framePointer(caller,0),123,4);
  writeLocal(framePointer(callee,0),readLocalArgument(framePointer(caller,0),4),4);
  assert.equal(readLocal(framePointer(callee,0),4),123);
});

test('CString object inputs retain semantic boat names independently of allocator identities',()=>{
  const memory={readU8(){throw new Error('A CString object is not a literal byte string');}};
  writeCString(memory,0x4fec34,'Sailing name');
  assert.equal(cString(memory,0x4fec34),'Sailing name');
});

test('raw DWORD extraction reconstructs floating bits independently of numeric truncation',()=>{
  const value=Float80.fromNumber(123.456),view=new DataView(new ArrayBuffer(8));
  view.setFloat64(0,123.456,true);
  const lower=cRawWord(value);
  assert.equal(lower,view.getInt32(0,true));
  assert.notEqual(lower,value.truncI32());
  assert.equal(bitsAsF64(cConcat(view.getInt32(4,true),lower,4,4)).toNumber(),123.456);
});

test('original scene DWORD constructions preserve binary64 values rather than numeric integer casts',()=>{
  assert.equal(bitsAsF64(cBits(cI64(0x3ff00000),32,'<<')).toNumber(),1);
  assert.equal(bitsAsF64(cBits(cI64(0x3ff80000),32,'<<')).toNumber(),1.5);
});

test('packed double argument slots preserve the untouched word after an original DWORD write',()=>{
  const frame=createLocalFrame(16),at=framePointer(frame,4),view=new DataView(new ArrayBuffer(8));
  view.setFloat64(0,123.456,true);
  writeLocal(at,Float80.fromNumber(123.456),8,'float');
  assert.equal(readLocal(at,4),view.getInt32(0,true));
  assert.equal(readLocal(framePointer(frame,8),4),view.getInt32(4,true));
  writeLocal(at,0x13572468,4);
  assert.equal(readLocal(at,4),0x13572468);
  assert.equal(readLocal(framePointer(frame,8),4),view.getInt32(4,true));
});

test('partial three-byte state reads preserve the remaining byte and avoid a four-byte access',()=>{
  const frame=createLocalFrame(4),at=framePointer(frame,0);
  writeLocal(at,0x12345678,4);
  assert.equal(readLocal(framePointer(frame,1),3),0x123456);
  writeLocal(framePointer(frame,1),0xabcdef,3);
  assert.equal(readLocal(at,4),0xabcdef78|0);
  assert.equal(readLocal(at,1),0x78);
});

test('cached local views enforce declared scalar widths and exact frame bounds',()=>{
  const frame=createLocalFrame(16),at=framePointer(frame,0);
  writeLocal(at,0x12345678,4);
  writeLocal(framePointer(frame,4),0xabcdef01,4);
  for(const size of [0,NaN,'invalid']){
    assert.throws(()=>readLocal(at,size),RangeError);
    assert.throws(()=>writeLocal(at,1,size),RangeError);
  }
  assert.throws(()=>readLocal(at,4,'float'),RangeError);
  assert.throws(()=>writeLocal(at,1,4,'float'),RangeError);
  assert.equal(readLocal(at,4),0x12345678);
  assert.equal(readLocal(framePointer(frame,4),4),0xabcdef01|0);
  for(const offset of [-1,13,Infinity]){
    assert.throws(()=>readLocal(framePointer(frame,offset),4),RangeError);
    assert.throws(()=>writeLocal(framePointer(frame,offset),1,4),RangeError);
    assert.throws(()=>readLocalArgument(framePointer(frame,offset),4),RangeError);
  }
  assert.equal(readLocalArgument(framePointer(frame,8),4),undefined);
  writeLocal(framePointer(frame,12),0x76543210,4);
  assert.equal(readLocal(framePointer(frame,12),4),0x76543210);
});

test('local byte validity preserves original index coercion for unusual host pointers',()=>{
  const frame=createLocalFrame(8);
  writeLocal(framePointer(frame,0),0x12345678,4);
  assert.equal(readLocal(framePointer(frame,.5),4),0x12345678);
  assert.equal(readLocal(framePointer(frame,NaN),4),0x12345678);
  assert.equal(readLocalArgument(framePointer(frame,4.5),1),undefined);
  writeLocal(framePointer(frame,4.5),0xab,1);
  assert.equal(readLocal(framePointer(frame,4.5),1),0xab);
});

test('compact frame materialization retains double words, undefined bytes and escaped pointers',()=>{
  const frame=createLocalFrame(288),escaped=framePointer(frame,4),view=new DataView(new ArrayBuffer(8));
  view.setFloat64(0,-123.456,true);
  writeLocal(escaped,Float80.fromNumber(-123.456),8,'float');
  writeLocal(framePointer(frame,28),0xabcdef01,4);
  writeLocal(framePointer(frame,8),undefined,4);
  assert.equal(readLocal(escaped,4),view.getInt32(0,true));
  assert.equal(readLocalArgument(escaped,8,'float'),undefined);
  const bytes=frame.bytes,valid=frame.valid;
  assert.equal(bytes.length,288);assert.equal(valid.length,288);
  assert.notEqual(bytes.buffer,valid.buffer);
  assert.equal(new DataView(bytes.buffer).getInt32(4,true),view.getInt32(0,true));
  assert.equal(new DataView(bytes.buffer).getInt32(8,true),view.getInt32(4,true));
  assert.deepEqual(Array.from(valid.subarray(4,12)),[1,1,1,1,0,0,0,0]);
  assert.equal(readLocal(framePointer(frame,28),4),0xabcdef01|0);
  writeLocal(framePointer(frame,256),0x12345678,4);
  assert.equal(readLocal(framePointer(frame,256),4),0x12345678);
  writeLocal(escaped,0x76543210,4);
  assert.equal(new DataView(bytes.buffer).getInt32(4,true),0x76543210);
  assert.equal(frame.bytes,bytes);assert.equal(frame.valid,valid);
});

test('public local byte and validity mutations remain visible to retained pointers',()=>{
  const frame=createLocalFrame(32),at=framePointer(frame,0);
  writeLocal(at,123,4);
  const bytes=frame.bytes,valid=frame.valid;
  new DataView(bytes.buffer).setInt32(0,-456,true);
  assert.equal(readLocal(at,4),-456);
  valid[2]=0;
  assert.throws(()=>readLocal(at,4),/undefined retained local/);
  assert.equal(readLocalArgument(at,4),undefined);
  valid[2]=1;
  assert.equal(readLocal(at,4),-456);
  assert.deepEqual(Array.from(bytes.subarray(4)),Array(28).fill(0));
});

test('replacement local byte arrays and slices become the storage seen by retained pointers',()=>{
  for(const sliced of [false,true]){
    const frame=createLocalFrame(8),at=framePointer(frame,0);
    writeLocal(at,123,4);
    const original=frame.bytes,buffer=new Uint8Array(sliced?16:8);
    const replacement=sliced?buffer.subarray(4,12):buffer;
    const replacementView=new DataView(replacement.buffer,replacement.byteOffset,replacement.byteLength);
    replacementView.setInt32(0,456,true);
    frame.bytes=replacement;
    assert.equal(frame.bytes,replacement);
    assert.equal(readLocal(at,4),456);
    writeLocal(at,789,4);
    assert.equal(replacementView.getInt32(0,true),789);
    assert.equal(new DataView(original.buffer).getInt32(0,true),123);
    replacementView.setInt32(0,-321,true);
    assert.equal(readLocal(at,4),-321);
    assert.throws(()=>writeLocal(framePointer(frame,5),1,4),/memory access exceeds frame/);
    assert.throws(()=>readLocal(framePointer(frame,5),4),/memory access exceeds frame/);
  }
});

test('malformed replacement byte storage fails on access and can be replaced again',()=>{
  const frame=createLocalFrame(8),at=framePointer(frame,0);
  writeLocal(at,123,4);
  const original=frame.bytes;
  for(const invalid of [null,undefined,{}]){
    assert.doesNotThrow(()=>{frame.bytes=invalid;});
    assert.throws(()=>readLocal(at,4),TypeError);
    assert.throws(()=>writeLocal(at,456,4),TypeError);
    frame.bytes=original;
    assert.equal(readLocal(at,4),123);
  }
});

test('compact nonsemantic I32 stores retain DataView coercion and failure behavior',()=>{
  const values=[{frame:null},{array:null},{dc:null},
    {frame:null,valueOf:()=>123.75},{array:null,valueOf:()=>4294967295},
    {dc:null,valueOf:()=>NaN},{frame:null,valueOf:()=>Infinity},
    {array:null,valueOf:()=>2n},{dc:null,valueOf:()=>Symbol('invalid')},
    {frame:null,valueOf:()=>{throw new RangeError('coercion failed');}}];
  for(const value of values){
    const frame=createLocalFrame(4),at=framePointer(frame,0),view=new DataView(new ArrayBuffer(4));
    writeLocal(at,123,4);view.setInt32(0,123,true);
    let error;
    try{view.setInt32(0,value,true);}catch(caught){error=caught;}
    if(error)assert.throws(()=>writeLocal(at,value,4),{name:error.name,message:error.message});
    else writeLocal(at,value,4);
    assert.equal(readLocal(at,4),view.getInt32(0,true));
  }
});

test('compact frames preserve semantic overlap and caller mutations of the public Map',()=>{
  const frame=createLocalFrame(32),at=framePointer(frame,0);
  writeLocal(at,'first',4);
  assert.equal(readLocal(at,4),'first');
  const semantic=frame.semantic;
  semantic.set(0,{size:4,value:'second'});
  assert.equal(readLocal(at,4),'second');
  writeLocal(framePointer(frame,1),0xab,1);
  assert.equal(semantic.has(0),false);
  assert.equal(readLocal(at,4),0xab00);
  assert.equal(frame.semantic,semantic);
});

test('prepared retained local byte rows keep their original validity and bounds',()=>{
  const frame=createLocalFrame(288,[{offset:256,bytes:'78563412'},{offset:4,bytes:'efcdab89'}]);
  assert.equal(readLocal(framePointer(frame,256),4),0x12345678);
  assert.equal(readLocal(framePointer(frame,4),4),0x89abcdef|0);
  assert.throws(()=>readLocal(framePointer(frame,0),4),/undefined retained local/);
  assert.throws(()=>createLocalFrame(8,[{offset:6,bytes:'010203'}]),/Declared retained local exceeds frame/);
});

test('CDC virtual pointers and semantic CString data preserve their separate meanings',()=>{
  const dc=new GdiTrace(),memory={readI32(){throw new Error('Unexpected numeric pointer read');}};
  const table=readPointer(memory,dc,4);
  readPointer(memory,pointerAdd(table,0x2c),4)(7);
  assert.deepEqual(dc.events,[{op:'selectStockObject',index:7}]);
  assert.equal(readPointer(memory,'original text',4),'original text');
});
