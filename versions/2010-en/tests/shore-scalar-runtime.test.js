import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../src/runtime/memory.js';
import {withX87ControlWord} from '../../../src/runtime/float80.js';
import {PoseyRng} from '../../../src/engine/integer-core.js';
import {assertNativeProvenance,sha256} from './native-state.js';
import {initializeGdiObjects} from '../src/engine/application.js';
import {GdiTrace} from '../src/render/gdi.js';
import {resetOriginalCStringContents} from '../src/render/text.js';
import {originalDrawing0047ed40} from '../src/render/drawing-functions.js';
import '../src/render/index.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const fixture=await json('fixtures/original-initialized-venue-render.json');
const baseline=assertNativeProvenance(source,fixture),snapshots=new Map(),builder=loadPE32(source);
for(const row of fixture.cases){
  if(!row.continue)builder.writeBytes(fixture.mutableBlock.address,baseline);
  for(const [field,value] of Object.entries(row.inputs??{}))builder.writeI32(fixture.integerInputs[field],value);
  for(const [field,value] of Object.entries(row.doubleInputs??{}))builder.writeF64(fixture.doubleInputs[field],value);
  for(const patch of row.patches??[])builder.writeBytes(patch.address,Buffer.from(patch.bytes,'hex'));
  for(const change of row.expected.imageChanges){
    assert.equal(Buffer.from(builder.readBytes(change.address,change.before.length/2)).toString('hex'),change.before);
    builder.writeBytes(change.address,Buffer.from(change.after,'hex'));
  }
  assert.equal(sha256(builder.readBytes(fixture.mutableBlock.address,fixture.mutableBlock.size)),row.expected.mutableSha256);
  if(row.phase==='drawScene')snapshots.set(row.profile,{image:builder.readBytes(builder.base,builder.size),seed:row.expected.rngState});
}
const generation=await json('../analysis/floating-drawing-generation.json');

for(const profile of fixture.profiles)test(`shoreline venue${profile.venue}: promoted and byte functions agree on native scene input images`,()=>{
  const promotion=generation.modules['drawing-functions.js'].find(row=>row.address===0x47ed40);
  assert.equal(promotion.scalarMode,'partial');
  assert.equal(promotion.scalarAccesses,326);
  assert.ok(!promotion.slots.some(row=>row.offset===264));
  const snapshot=snapshots.get(profile.name),memory=loadPE32(source),objects=initializeGdiObjects(memory);
  let eventCount=0;
  const run=(index,options)=>{
    memory.writeBytes(memory.base,snapshot.image);resetOriginalCStringContents(memory);
    const rng=new PoseyRng();rng.srand(snapshot.seed);
    const dc=new GdiTrace({objects:new Map(objects),readPixel:()=>0xffffff});
    let returned,error;
    try{returned=withX87ControlWord(0x027f,()=>originalDrawing0047ed40(memory,dc,rng,options,index,1));}
    catch(caught){error={name:caught.constructor.name,message:caught.message};}
    return {returned,error,events:dc.events,random:rng.state,image:memory.readBytes(memory.base,memory.size)};
  };
  for(let index=1;index<=12;index++){
    const promoted=run(index,{}),byte=run(index,{numberRendering:false});
    assert.deepEqual(promoted,byte,`shore feature${index}: every image byte, returned value, error, RNG and ordered GDI request`);
    assert.equal(promoted.error,undefined,`shore feature${index}: initialized native scene input succeeds`);
    eventCount+=promoted.events.length;
  }
  // The retained venue2 scene has no visible shoreline among these features;
  // its early-return paths are compared too. Other profiles exercise the
  // complete aliased point/array drawing paths.
  if(profile.venue!==2)assert.ok(eventCount>0,'visible features exercise drawing and aliased point buffers');
});
