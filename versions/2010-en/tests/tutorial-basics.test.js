import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {loadOriginalData,ORIGINAL_SOURCE_SHA256,MUTABLE_BASE,MUTABLE_SIZE} from '../src/runtime/original-data.js';
import {initializeIntegerTrig} from '../src/engine/application.js';
import {withX87ControlWord} from '../../../src/runtime/float80.js';
import {GdiTrace} from '../src/render/gdi.js';
import * as pages from '../src/render/tutorial-pages.js';
import {resetOriginalCStringContents,originalCStringContents} from '../src/render/text.js';

const data=new URL('../assets/data/',import.meta.url);
const manifest=JSON.parse(await readFile(new URL('original-memory.json',data)));
const segments=new Map(await Promise.all(manifest.segments.map(async row=>[row.file,new Uint8Array(await readFile(new URL(row.file,data)))])));
const trig=JSON.parse(await readFile(new URL('trig-tables.json',data)));
const hash=bytes=>createHash('sha256').update(bytes).digest('hex');

for(let page=1;page<=8;page++)test(`2010 tutorial ${page}: all ordered original requests and complete state`,async()=>{
  const fixture=JSON.parse(await readFile(new URL(`fixtures/original-tutorial-${page}.json`,import.meta.url)));
  assert.equal(fixture.sourceSha256,ORIGINAL_SOURCE_SHA256);
  assert.equal(fixture.routine.address,pages.TUTORIAL_PAGE_ROUTINES[`drawTutorial${page}`]);
  assert.equal(fixture.provenance.x87ControlWord,'0x027f');
  assert.equal(fixture.provenance.loadedOriginalTextUnchanged,true);
  assert.equal(fixture.provenance.originalFileUnchanged,true);
  const memory=loadOriginalData(manifest,segments);
  initializeIntegerTrig(memory,trig);
  const baseline=memory.readBytes(MUTABLE_BASE,MUTABLE_SIZE);
  assert.equal(hash(baseline),fixture.provenance.mutableBaselineSha256,'independent original data + JS integer trig matches native prepared baseline');
  assert.equal(Buffer.from(baseline).toString('hex'),fixture.mutableBaseline);
  for(const [index,row] of fixture.cases.entries()){
    memory.writeBytes(MUTABLE_BASE,baseline);
    resetOriginalCStringContents(memory);
    for(const [name,value] of Object.entries(row.inputs))memory.writeI32(fixture.integerInputs[name],value);
    const before=memory.readBytes(MUTABLE_BASE,MUTABLE_SIZE);
    const rng={state:row.seed,next(){throw new Error('Basic tutorial consumed an unexpected RNG value');}};
    const dc=new GdiTrace();
    withX87ControlWord(0x027f,()=>pages[`drawTutorial${page}`](memory,dc,rng));
    assert.deepEqual(dc.events,row.expected.drawingCommands,`case ${index}: complete request order/text/coordinates`);
    assert.equal(rng.state,row.expected.rngState,`case ${index}: RNG`);
    assert.deepEqual(memory.readBytes(MUTABLE_BASE,MUTABLE_SIZE),before,`case ${index}: original basic page is read-only`);
    assert.deepEqual(row.expected.imageChanges,[],`case ${index}: original native write scope`);
    assert.equal(hash(memory.readBytes(MUTABLE_BASE,MUTABLE_SIZE)),row.expected.mutableSha256,`case ${index}: full original mutable block`);
    assert.deepEqual(originalCStringContents(memory),row.expected.globalStrings.map(s=>({address:s.address,text:new TextDecoder('windows-1252').decode(Buffer.from(s.bytes,'hex'))})),`case ${index}: all original global CString contents`);
  }
});
