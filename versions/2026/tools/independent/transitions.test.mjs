import test from 'node:test';
import assert from 'node:assert/strict';
import {makeRuntime} from './fixtures.mjs';
import {readCString,writeCString} from '../../public/legacy/versions/2010-en/src/render/text.js';

test('N/Space initializes a configured race without any screen lifecycle',()=>{
 const {memory,engine}=makeRuntime();engine.step();engine.key(78);
 assert.equal(memory.readI32(0x5363b0),0);engine.key(32);
 assert.equal(memory.readI32(0x5363b0),2);
 const time=memory.readF64(0x5359f0);engine.step();assert.ok(memory.readF64(0x5359f0)>time);
});
test('restoring an earlier full checkpoint also restores its leg replay boundary',()=>{
 const {memory,engine}=makeRuntime(),checkpoint=engine.checkpoint();
 for(let n=0;n<2000;n++)engine.step();assert.ok(memory.readF64(0x5359f0)>0);
 engine.restore(checkpoint);engine.key(8);
 const expected=checkpoint.replay.image.slice(),view=new DataView(expected.buffer);
 view.setInt32(0x53642c-memory.base,1,true);view.setInt32(0x5364ac-memory.base,0,true);
 assert.deepEqual(memory.bytes,expected);
 assert.deepEqual(engine.random.snapshot(),checkpoint.replay.random);
 assert.deepEqual(engine.raceWindow.checkpoint(),checkpoint.replay.raceWindow);
});

test('full checkpoints restore virtual CString host metadata as well as image bytes',()=>{
 const {memory,engine}=makeRuntime(),checkpoint=engine.checkpoint();
 const previous=readCString(memory,0x4fec34);writeCString(memory,0x4fec34,'Discarded future name');
 assert.equal(readCString(memory,0x4fec34),'Discarded future name');
 assert.deepEqual(memory.bytes,checkpoint.image);engine.restore(checkpoint);
 assert.equal(readCString(memory,0x4fec34),previous);
});
