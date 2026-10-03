import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { PoseyRng } from '../../../src/engine/integer-core.js';
import { withX87ControlWord } from '../../../src/runtime/float80.js';
import { handleKeyDown } from '../src/engine/keyboard.js';
import { handleMenuCommand,menuCommandState,MENU_COMMAND_ROUTINES,MENU_UPDATE_ROUTINES } from '../src/engine/menu-controller.js';
import { handleLeftButtonDown,handleRightButtonDown,handleMouseMove,handleMouseWheel } from '../src/engine/mouse.js';
import { handleDialogControl,DIALOG_CONTROLS } from '../src/engine/dialogs.js';
import { sha256,assertNativeProvenance } from './native-state.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const fixture=JSON.parse(await readFile(new URL('fixtures/original-controllers.json',import.meta.url),'utf8'));
const baseline=assertNativeProvenance(source,fixture);
const windowHandle=0x20000001;
const defaults=event=>({type:'default',...event,result:1});

function replay(memory,rng,row) {
  const events=[];
  const options={rng,windowHandle,invalidateRect:event=>events.push({type:'invalidateRect',...event}),
    defaultKeyHandler:({key,repeat,flags})=>{events.push(defaults({message:0x100,wparam:key>>>0,lparam:((repeat&0xffff)|(flags<<16))>>>0}));return 1;},
    defaultMouseHandler:({message,flags,delta,x,y})=>{
      events.push(defaults({message,wparam:message===0x20a ? ((flags&0xffff)|(delta<<16))>>>0 : flags>>>0,lparam:((x&0xffff)|(y<<16))>>>0}));return 1;
    },
  };
  let returned;
  if (row.kind===1) returned=handleKeyDown(memory,row.arguments[0],{...options,repeat:row.arguments[1],flags:row.arguments[2]});
  else if (row.kind===2) {returned=handleMenuCommand(memory,row.identifier,options);assert.equal(returned,true);}
  else if (row.kind===3) events.push(...menuCommandState(memory,row.identifier).events);
  else if (row.kind===4) handleLeftButtonDown(memory,...row.arguments,options);
  else if (row.kind===5) handleRightButtonDown(memory,...row.arguments,options);
  else if (row.kind===6) handleMouseMove(memory,...row.arguments,options);
  else if (row.kind===7) {returned=handleMouseWheel(memory,...row.arguments,options);assert.equal(returned>>>0,row.expected.eax);}
  else if (row.kind===8) {returned=handleDialogControl(memory,row.identifier>>>16,row.identifier&0xffff,options);assert.equal(returned,true);}
  else throw new Error('Unrecognized captured controller kind');
  return events;
}

test('the original controller source and retained MFC host binding evidence are explicit',()=>{
  assert.equal(fixture.provenance.loadedOriginalTextUnchanged,true);
  assert.match(fixture.provenance.hostBindings,/original 4ac701\/4c04f2 execute/);
  assert.match(fixture.provenance.limitations,/modal-window/);
  assert.equal(Object.keys(MENU_COMMAND_ROUTINES).length,311);
  assert.equal(Object.keys(MENU_UPDATE_ROUTINES).length,311);
  const kinds=new Set(fixture.cases.map(row=>row.kind));
  assert.deepEqual([...kinds].sort(),[1,2,3,4,5,6,7,8]);
  const commands=new Set(fixture.cases.filter(row=>row.kind===2).map(row=>row.identifier));
  for (const command of Object.keys(MENU_COMMAND_ROUTINES)) if (![32823,32779].includes(+command)) assert.ok(commands.has(+command));
  const updates=new Set(fixture.cases.filter(row=>row.kind===3).map(row=>row.identifier));
  assert.equal(updates.size,311);
  const radio=new Set(fixture.cases.filter(row=>row.kind===8).map(row=>row.identifier));
  for (const [resource,controls] of Object.entries(DIALOG_CONTROLS)) for (const control of Object.keys(controls)) assert.ok(radio.has((resource<<16)|control));
  for (const row of fixture.cases) for (const binding of row.expected.runtimeBindings) {
    assert.ok([0x538010,0x538148].includes(binding.address));assert.equal(binding.retained,binding.bound);
  }
});

for (const [kind,label] of [[1,'keyboard'],[2,'menu commands'],[3,'CCmdUI updates'],[4,'left button'],[5,'right button'],[6,'mouse move'],[7,'wheel'],[8,'dialog radios']]) {
  const cases=fixture.cases.map((row,index)=>({row,index})).filter(({row})=>row.kind===kind);
  test(`2010 ${label}: ${cases.length} strict native whole-state/RNG/ordered callback cases`,()=>{
    const memory=loadPE32(source),rng=new PoseyRng();
    const base=fixture.mutableBlock.address;
    const prefix=memory.readBytes(memory.base,base-memory.base);
    const suffix=memory.readBytes(base+baseline.length,memory.size-(base-memory.base)-baseline.length);
    for (const {row,index} of cases) {
      if (!row.continue) {memory.writeBytes(base,baseline);rng.srand(row.seed);}
      const patches=[...fixture.profiles[row.profile].patches,...row.patches];
      for (const patch of patches) memory.writeBytes(patch.address,Buffer.from(patch.bytes,'hex'));
      const before=memory.readBytes(base,baseline.length),expected=before.slice();
      for (const change of row.expected.imageChanges) {
        const offset=change.address-base,width=change.before.length/2;
        assert.equal(Buffer.from(before.subarray(offset,offset+width)).toString('hex'),change.before,`case${index} ${row.label}: original before bytes`);
        expected.set(Buffer.from(change.after,'hex'),offset);
      }
      const events=withX87ControlWord(0x027f,()=>replay(memory,rng,row));
      assert.deepEqual(events,row.expected.events,`case${index} ${row.label}: ordered native UI callbacks`);
      assert.equal(rng.state,row.expected.rngState,`case${index} ${row.label}: native RNG`);
      const actual=memory.readBytes(base,baseline.length);
      assert.equal(sha256(actual),row.expected.mutableSha256,`case${index} ${row.label}: entire mutable SHA256`);
      assert.deepEqual(actual,expected,`case${index} ${row.label}: all native mutable bytes`);
    }
    assert.deepEqual(memory.readBytes(memory.base,prefix.length),prefix,'preserved immutable prefix');
    assert.deepEqual(memory.readBytes(base+baseline.length,suffix.length),suffix,'preserved immutable suffix');
  });
}

test('modal command tails run after an asynchronous dialog resolves, including Cancel',async()=>{
  for (const [command,resource,erase] of [[32823,132,1],[32779,131,0]]) {
    const memory=loadPE32(source),events=[];
    memory.writeI32(0x5363b4,1);memory.writeI32(0x4da140,1);
    let resolve;
    const result=handleMenuCommand(memory,command,{dialogHandler:id=>{assert.equal(id,resource);return new Promise(done=>{resolve=done;});},invalidateRect:event=>events.push(event)});
    assert.equal(memory.readI32(0x5363b4),1);assert.equal(memory.readI32(0x4da140),1);assert.equal(events.length,0);
    resolve(2);assert.equal(await result,true);
    assert.equal(memory.readI32(0x5363b4),0);assert.equal(memory.readI32(0x4da140),command===32779?2:1);assert.equal(events[0].erase,erase);
  }
});
