import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { withX87ControlWord } from '../../../src/runtime/float80.js';
import { PoseyRng } from '../../../src/engine/integer-core.js';
import { initializeApplication,saveApplicationPreferences,PREFERENCE_FIELDS,PREFERENCE_BYTES } from '../src/engine/application.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const raw=await readFile(new URL('fixtures/original-application.json',import.meta.url));
const fixture=JSON.parse(raw),baseline=Uint8Array.from(Buffer.from(fixture.mutableBaseline,'hex'));
const base=fixture.mutableBlock.address,size=fixture.mutableBlock.size;
const sha=data=>createHash('sha256').update(data).digest('hex');
function apply(state,changes) {
  for(const change of changes) {
    const offset=change.address-base,width=change.before.length/2;
    assert.equal(Buffer.from(state.subarray(offset,offset+width)).toString('hex'),change.before,'recorded native before bytes');
    state.set(Buffer.from(change.after,'hex'),offset);
  }
  return state;
}

test('constructor/archive references execute both complete original bodies with explicit host normalization',async()=>{
  assert.equal(sha(source),fixture.provenance.sha256);
  assert.equal(fixture.provenance.loadedOriginalTextUnchanged,true);
  assert.equal(fixture.provenance.originalFileUnchanged,true);
  assert.equal(fixture.provenance.x87ControlWord,'0x027f');
  assert.match(fixture.provenance.hostBindings,/Private actual p.tac file/);
  assert.match(fixture.provenance.engine,/actual original CFile\/CArchive/);
  assert.equal(fixture.cases.length,58);
  assert.equal(PREFERENCE_FIELDS.reduce((bytes,field)=>bytes+field.bytes,0),PREFERENCE_BYTES);
  assert.equal(PREFERENCE_BYTES,636);
  const published=JSON.parse(await readFile(new URL('../analysis/native-source-sets/manifest.json',import.meta.url)));
  const capture=published.captures.find(row=>row.provenance.runnerSha256===fixture.provenance.runnerSha256);
  assert.ok(capture,'Exact historical compiler-input snapshot is published');
  assert.deepEqual(capture.provenance,fixture.provenance);
  assert.equal(capture.provenanceFixture.sha256,sha(raw));
  const bundle=published.bundles.find(row=>row.sha256===capture.sourceBundleSha256);
  assert.ok(bundle);
  assert.equal(sha(JSON.stringify(bundle.files.map(row=>({bytes:row.bytes,name:row.name,sha256:row.sha256})))),bundle.sha256);
  assert.deepEqual(bundle.files.map(row=>row.name).sort(),Object.keys(fixture.provenance.runnerSources).sort());
  for(const row of bundle.files) {
    const bytes=await readFile(new URL('../'+bundle.path+'/'+row.name,import.meta.url));
    assert.equal(bytes.length,row.bytes);
    assert.equal(sha(bytes),fixture.provenance.runnerSources[row.name]);
  }
  const binary=await readFile(new URL('../'+capture.nativeBinarySnapshot.path,import.meta.url));
  assert.equal(binary.length,capture.nativeBinarySnapshot.bytes);
  assert.equal(sha(binary),fixture.provenance.runnerSha256);
});

test('58 complete constructors match all native mutable bytes, RNG and90 ordered GDI requests each',()=>{
  const memory=loadPE32(source);
  const prefix=memory.readBytes(memory.base,base-memory.base),suffix=memory.readBytes(base+size,memory.size-(base-memory.base)-size);
  for(const row of fixture.cases) {
    const prepared=apply(baseline.slice(),row.expected.preparedChanges);
    assert.equal(sha(prepared),row.expected.preparedSha256,row.label+' native prepared image');
    memory.writeBytes(base,prepared);
    const integerTrig={sine:Array.from({length:362},(_,index)=>memory.readI32(0x4f85c8+index*4)),cosine:Array.from({length:362},(_,index)=>memory.readI32(0x4f1740+index*4))};
    const rng=new PoseyRng(),objects=[];
    withX87ControlWord(0x027f,()=>initializeApplication(memory,rng,{preferences:row.preferences===null?null:Buffer.from(row.preferences,'hex'),timeSeed:row.timeSeed,screenHeight:row.screenHeight,integerTrig,
      createGdiObject:definition=>{objects.push(definition);return definition.handleAddress;}}));
    const expected=apply(prepared.slice(),row.expected.constructor.imageChanges);
    const actual=memory.readBytes(base,size);
    assert.equal(sha(actual),row.expected.constructor.mutableSha256,row.label+' native whole-image SHA');
    assert.deepEqual(actual,expected,row.label+' all constructor native bytes');
    assert.equal(rng.state,row.expected.constructor.rngState,row.label+' original CRT RNG');
    const requests=row.expected.events.filter(event=>['createPen','createBrush'].includes(event.type)).map(event=>
      event.type==='createPen'?{kind:'pen',color:event.color,style:event.style,width:event.width,handleAddress:event.handleAddress}:{kind:'brush',color:event.color,handleAddress:event.handleAddress});
    assert.deepEqual(objects,requests,row.label+' all ordered native GDI request arguments');
    const metrics=row.expected.events.filter(event=>event.type==='systemMetrics');
    assert.deepEqual(metrics,[{type:'systemMetrics',index:1,value:row.screenHeight}]);
    const opens=row.expected.events.filter(event=>event.type==='openArchive');
    assert.deepEqual(opens,[{type:'openArchive',name:'p.tac',access:0x80000000,share:0,disposition:3,attributes:128},
      {type:'openArchive',name:'p.tac',access:0x40000000,share:0,disposition:2,attributes:128}]);
  }
  assert.deepEqual(memory.readBytes(memory.base,prefix.length),prefix,'immutable prefix');
  assert.deepEqual(memory.readBytes(base+size,suffix.length),suffix,'immutable suffix');
});

test('58 original archive saves match exact636bytes and demo session-store ordering',()=>{
  const memory=loadPE32(source);
  for(const row of fixture.cases) {
    const state=apply(baseline.slice(),row.expected.preparedChanges);
    apply(state,row.expected.constructor.imageChanges);memory.writeBytes(base,state);
    const actualArchive=saveApplicationPreferences(memory);
    assert.equal(Buffer.from(actualArchive).toString('hex'),row.expected.savedArchive,row.label+' original CArchive output including unaligned F64 and repeated fields');
    apply(state,row.expected.save.imageChanges);
    assert.equal(sha(memory.readBytes(base,size)),row.expected.save.mutableSha256,row.label+' original save whole-image SHA');
    assert.deepEqual(memory.readBytes(base,size),state,row.label+' all save native bytes');
  }
});

test('normalization retains complete native raw allocator, TLS and GDI-handle evidence',()=>{
  for(const row of fixture.cases) {
    const raw=apply(baseline.slice(),row.expected.preparedChanges);
    for(const phase of ['prepared','constructor','save']) {
      const expected=row.expected.rawRuntime[phase];apply(raw,expected.imageChanges);
      assert.equal(sha(raw),expected.mutableSha256,row.label+' raw native '+phase+' SHA');
    }
    assert.equal(row.expected.events.filter(event=>event.type==='createPen').length,56);
    assert.equal(row.expected.events.filter(event=>event.type==='createBrush').length,34);
    for(const event of row.expected.events.filter(event=>event.nativeHandle!==undefined))assert.ok(event.nativeHandle>0&&event.handleAddress>=base&&event.handleAddress<base+size);
  }
});
