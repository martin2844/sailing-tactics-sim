import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {AddressSpaceMemory} from '../../../../src/runtime/memory.js';
import * as typed from '../../../2010-en/src/render/typed-c.js';
import {scalarRead,scalarStoreI32} from '../../../2010-en/src/render/scalar-stack.js';
import {updateFoulSlowdown} from '../../app/engine/rules/foul-slowdown.ts';
import {createFoulSlowdownState} from '../../app/engine/compatibility/foul-slowdown-state.ts';

// Execute the unchanged recovered control block; its exits reach style drawing,
// which is excluded here. This is reference extraction for a test, not a second
// manually rewritten implementation of the decision under test.
const source=await readFile(new URL('../../../2010-en/src/render/drawing-functions.js',import.meta.url),'utf8');
const start=source.indexOf('function originalDrawing0041ce80Original('),end=source.indexOf('\nfunction originalDrawing0041ce80ByteFrame(',start);
const block=source.slice(start,end).split('\n').filter(line=>/^\s*case (4[2-9]|5[0-5]):/.test(line));
assert.equal(block.length,14,'Frozen warning-control boundaries changed');
const names=['cAdd','cMul','cCompare','cTruth','readPointer','writePointer'];
const referenceFactory=new Function(...names,'scalarRead','scalarStoreI32',`return (memory,boat)=>{
 const r32=a=>memory.readI32(a),w32=(a,v)=>memory.writeI32(a,v);
 const scalarStack12=scalarStoreI32(boat);let iVar4,iVar8,pc=55;
 for(;;)switch(pc){case 41:return true;case 36:return false;${block.join('\n')}default:throw Error('Unexpected reference exit');}
};`);
const original=referenceFactory(...names.map(name=>typed[name]),scalarRead,scalarStoreI32);
function memory({mode,warning,previous,pace,finished,cooldown,human,clock}){
 const m=new AddressSpaceMemory(0x21c000);
 for(const[a,v]of[[0x4da1dc,mode],[0x4da1e0,10],[0x4f8cd0,clock],[0x4da140,human?1:0],[0x4f7124,warning],[0x4faf84,previous],[0x4da174,pace],[0x4da178,76],[0x4fe63c,finished],[0x4fb9ac,cooldown]])m.writeI32(a,v);
 return m;
}

test('slowdown state and branch match recovered warning block across eligibility and grace boundaries',()=>{
 for(const mode of[0,1,2])for(const warning of[-1,0,2])for(const previous of[0,2])for(const pace of[1,10])for(const finished of[0,1])for(const cooldown of[0,1])for(const human of[false,true])for(const clock of[14,15]){
   const input={mode,warning,previous,pace,finished,cooldown,human,clock},a=memory(input),b=memory(input);
   const expected=original(a,1),actual=updateFoulSlowdown(createFoulSlowdownState(b,1));
   assert.equal(actual,expected);assert.deepEqual(b.bytes,a.bytes,JSON.stringify(input));
 }
});
