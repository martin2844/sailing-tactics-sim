import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { handleMenuCommand } from '../src/engine/menu-controller.js';
import { handleDialogControl,closeOriginalDialog } from '../src/engine/dialogs.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const raw=await readFile(new URL('fixtures/original-modal-lifecycles.json',import.meta.url));
const fixture=JSON.parse(raw);
const digest=bytes=>createHash('sha256').update(bytes).digest('hex');
const fields=(memory,observation)=>observation.fields.map(([address])=>[address,memory.readU32(address)]);

test('modal references come from genuine intact original Windows dialogs with unchanged instructions',async()=>{
  assert.equal(digest(source),fixture.provenance.sourceSha256);
  assert.equal(fixture.provenance.loadedOriginalTextUnchanged,true);
  assert.equal(fixture.provenance.targetGameMemoryWrites,0);
  assert.equal(fixture.cases.length,8);
  assert.match(fixture.provenance.scope,/Only fixed original EndDialog\/InvalidateRect source calls and18 game globals/);
  assert.match(fixture.provenance.limitations,/whole MFC lifetime/);
  for (const evidence of fixture.provenance.evidence) {
    const bytes=await readFile(new URL('../'+evidence.path,import.meta.url));
    assert.equal(bytes.length,evidence.bytes);assert.equal(digest(bytes),evidence.sha256);
  }
});

for (const row of fixture.cases) test(`2010 actual dialog${row.resource} control${row.control} ${row.result===1?'OK':'Cancel'}: exact observed fields and ordered host calls`,async()=>{
  const memory=loadPE32(source),events=[];
  const nativeCalls=row.observations.filter(point=>['invalidate','end-dialog'].includes(point.point));
  let callIndex=0;
  const assertFields=observation=>assert.deepEqual(fields(memory,observation),observation.fields,observation.point+' original game globals');
  const inspectCall=(type,args)=>{
    const expected=nativeCalls[callIndex++];
    assert.equal(expected.point,type);assertFields(expected);
    const nativeArgs=expected[type==='invalidate'?'invalidateArgs':'endDialogArgs'];
    assert.deepEqual(args,nativeArgs,'actual original call arguments');events.push({type,args});
  };
  const before=row.observations.find(point=>point.point==='before-command');
  for (const [address,value] of before.fields)memory.writeU32(address,value);
  const nativeWindow=row.observations.find(point=>point.point==='radio-return');
  const viewWindow=nativeWindow.viewWindow,dialogWindow=nativeWindow.dialogWindow;
  const invalidate=({windowHandle,rectangle,erase})=>{assert.equal(rectangle,null);inspectCall('invalidate',[windowHandle,0,erase]);};
  let resolve;
  const command=handleMenuCommand(memory,row.command,{windowHandle:viewWindow,invalidateRect:invalidate,
    dialogHandler:resource=>{assert.equal(resource,row.resource);return new Promise(done=>{resolve=done;});}});
  assertFields(row.observations.find(point=>point.point==='command-entry'));
  assert.equal(handleDialogControl(memory,row.resource,row.control,{windowHandle:dialogWindow,invalidateRect:invalidate}),true);
  assertFields(nativeWindow);
  const result=closeOriginalDialog(memory,row.resource,row.result===1,{windowHandle:dialogWindow,invalidateRect:invalidate,
    endDialog:result=>{
      inspectCall('end-dialog',[dialogWindow,result]);
      assertFields(row.observations.find(point=>point.point==='end-dialog-return'));
    }});
  assert.equal(result,row.result);
  const modalReturn=row.observations.find(point=>point.point==='modal-return');
  assert.equal(modalReturn.eax,result);assertFields(modalReturn);
  resolve(result);assert.equal(await command,true);
  assertFields(row.observations.find(point=>point.point==='tail-complete'));
  assert.equal(callIndex,nativeCalls.length);
  assert.deepEqual(events,nativeCalls.map(point=>({type:point.point,args:point.point==='invalidate'?point.invalidateArgs:point.endDialogArgs})));
});
