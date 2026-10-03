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

test('CDC virtual pointers and semantic CString data preserve their separate meanings',()=>{
  const dc=new GdiTrace(),memory={readI32(){throw new Error('Unexpected numeric pointer read');}};
  const table=readPointer(memory,dc,4);
  readPointer(memory,pointerAdd(table,0x2c),4)(7);
  assert.deepEqual(dc.events,[{op:'selectStockObject',index:7}]);
  assert.equal(readPointer(memory,'original text',4),'original text');
});
