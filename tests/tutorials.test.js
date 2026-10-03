import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createHullTrig } from '../src/engine/hull-geometry.js';
import { GdiTrace } from '../src/render/gdi.js';
import * as pages from '../src/render/tutorial-pages.js';
import * as controls from '../src/render/tutorial-controls.js';
import { drawPauseScreen } from '../src/render/tutorials.js';
import { readRoutineFixture } from './read-routine-fixture.js';
import { assertNativeAuthority } from './native-authority.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const names = [...Object.keys(pages.TUTORIAL_PAGE_ROUTINES),...Object.keys(controls.TUTORIAL_CONTROL_ROUTINES),'drawPauseScreen'];
const fixtures = await readRoutineFixture(new URL('./fixtures/original-tutorials.json',import.meta.url),names);
const readJson = async path => JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const [tables,trigCapture,hullCapture,forceCapture] = await Promise.all([
  readJson('../assets/data/trig-tables.json'),readJson('../assets/data/x87-trig.json'),readJson('../assets/data/x87-hull-trig.json'),readJson('../assets/data/x87-force-trig.json'),
]);
const trig=createCapturedTrig(trigCapture,undefined,forceCapture),hullTrig=createHullTrig(hullCapture);
const routines={...pages,...controls,drawPauseScreen},hash=bytes=>createHash('sha256').update(bytes).digest('hex');
const bytes=bits=>Uint8Array.from(Buffer.from(bits,'hex'));
function mergedRanges(writes) {
  const result=[];
  for(const [address,size] of writes.sort((a,b)=>a[0]-b[0]||a[1]-b[1])) {
    const last=result.at(-1);
    if(last&&address<=last.address+last.size) last.size=Math.max(last.address+last.size,address+size)-last.address;
    else result.push({address,size});
  }
  return result;
}
test('tutorial source covers31 remaining complete pages, all controls and the original dispatcher',()=>{
  assert.equal(fixtures.provenance.sha256,hash(original));
  assert.equal(fixtures.provenance.x87_control_word,'0x037f');
  assert.equal(Object.keys(pages.TUTORIAL_PAGE_ROUTINES).length,31);
  for(const [name,address] of Object.entries({...pages.TUTORIAL_PAGE_ROUTINES,...controls.TUTORIAL_CONTROL_ROUTINES,drawPauseScreen:0x41bb40})) assert.equal(fixtures.routines[name].address,address);
});

test('all tutorial pages and controls have unchanged native original authority for the canonical fixture',async()=>{
  await assertNativeAuthority('original-tutorials.json','tutorials-native-reference-comparison.json',fixtures);
});
for(const name of names) test(`${name}: complete original mutable bytes, ordered requests, stores and RNG (${fixtures.routines[name].cases.length} calls)`,()=>{
  const memory=loadPE32(original);
  for(const [address,values] of [[0x4a54a0,tables.sine],[0x4a3450,tables.cosine]]) values.forEach((value,index)=>memory.writeI32(address+index*4,value));
  const baseline=memory.bytes.slice(),block=fixtures.mutableBlock;
  let writes;
  for(const method of ['writeI32','writeU32','writeF64','writeBytes']) {
    const originalMethod=memory[method].bind(memory);
    memory[method]=(address,value)=>{if(writes)writes.push([address,method==='writeF64'?8:method==='writeBytes'?value.length:4]);return originalMethod(address,value);};
  }
  const failures=[];
  for(const [index,row] of fixtures.routines[name].cases.entries()) {
    memory.bytes.set(baseline);
    for(const input of row.imageInputs)memory.writeBytes(input.address,bytes(input.bits));
    const before=memory.readBytes(block.address,block.size),expected=memory.bytes.slice();
    for(const change of row.expected.imageChanges) {
      assert.equal(Buffer.from(before.slice(change.address-block.address,change.address-block.address+change.before.length/2)).toString('hex'),change.before);
      expected.set(bytes(change.after),change.address-memory.base);
    }
    assert.equal(hash(expected.slice(block.address-memory.base,block.address-memory.base+block.size)),row.expected.mutableBlockHash);
    const rng=new PoseyRng(row.seedAtCall),dc=new GdiTrace();writes=[];
    try {
      if(name in controls.TUTORIAL_CONTROL_ROUTINES) routines[name](memory,dc,...row.arguments);
      else routines[name](memory,dc,rng,{trig,hullTrig});
    } catch(error) {failures.push({index,error:error.stack});writes=undefined;continue;}
    const actualWrites=mergedRanges(writes);writes=undefined;
    const mismatch=memory.bytes.findIndex((value,offset)=>value!==expected[offset]);
    const command=dc.events.findIndex((event,i)=>JSON.stringify(event)!==JSON.stringify(row.expected.drawingCommands[i]));
    if(mismatch!==-1||command!==-1||dc.events.length!==row.expected.drawingCommands.length||rng.state!==row.expected.rngState||JSON.stringify(actualWrites)!==JSON.stringify(row.imageWrites)) failures.push({
      index,address:mismatch===-1?undefined:`0x${(memory.base+mismatch).toString(16)}`,
      actual:mismatch===-1?undefined:Buffer.from(memory.bytes.slice(mismatch,mismatch+16)).toString('hex'),
      expected:mismatch===-1?undefined:Buffer.from(expected.slice(mismatch,mismatch+16)).toString('hex'),command,
      actualCommands:command===-1?undefined:dc.events.slice(command,command+2),expectedCommands:command===-1?undefined:row.expected.drawingCommands.slice(command,command+2),
      commandCounts:[dc.events.length,row.expected.drawingCommands.length],rngState:rng.state,expectedRng:row.expected.rngState,
      stores:JSON.stringify(actualWrites)===JSON.stringify(row.imageWrites)?undefined:actualWrites,expectedStores:JSON.stringify(actualWrites)===JSON.stringify(row.imageWrites)?undefined:row.imageWrites,
    });
  }
  assert.equal(failures.length,0,`${name}: ${failures.length} exact failures. ${JSON.stringify(failures.slice(0,2))}`);
});
