import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {loadOriginalData,ORIGINAL_SOURCE_SHA256,MUTABLE_BASE,MUTABLE_SIZE} from '../src/runtime/original-data.js';
import {initializeIntegerTrig} from '../src/engine/application.js';
import {withX87ControlWord} from '../../../src/runtime/float80.js';
import {GdiTrace} from '../src/render/gdi.js';
import {drawSailingHud,drawCompactHud} from '../src/render/hud.js';
import {resetOriginalCStringContents,originalCStringContents} from '../src/render/text.js';

const data=new URL('../assets/data/',import.meta.url);
const manifest=JSON.parse(await readFile(new URL('original-memory.json',data)));
const segments=new Map(await Promise.all(manifest.segments.map(async row=>[row.file,new Uint8Array(await readFile(new URL(row.file,data)))])));
const trig=JSON.parse(await readFile(new URL('trig-tables.json',data)));
const hash=bytes=>createHash('sha256').update(bytes).digest('hex');
const decoder=new TextDecoder('windows-1252');

for(const [name,call] of [['hud',drawSailingHud],['compact-hud',drawCompactHud],['hud-nearest',drawSailingHud]])test(`2010 ${name}: complete original state/text/request authority`,async()=>{
  const fixture=JSON.parse(await readFile(new URL(`fixtures/original-drawing-${name==='hud'?'hud-with-sounds':name}.json`,import.meta.url)));
  assert.equal(fixture.sourceSha256,ORIGINAL_SOURCE_SHA256);
  assert.equal(fixture.provenance.x87ControlWord,'0x027f');
  assert.equal(fixture.provenance.loadedOriginalTextUnchanged,true);
  assert.equal(fixture.provenance.originalFileUnchanged,true);
  const memory=loadOriginalData(manifest,segments);initializeIntegerTrig(memory,trig);
  const baseline=memory.readBytes(MUTABLE_BASE,MUTABLE_SIZE);
  assert.equal(hash(baseline),fixture.provenance.mutableBaselineSha256);
  for(const [index,row] of fixture.cases.entries()){
    memory.writeBytes(MUTABLE_BASE,baseline);resetOriginalCStringContents(memory);
    for(const [field,value] of Object.entries(row.inputs))memory.writeI32(fixture.integerInputs[field],value);
    for(const patch of row.patches??[])memory.writeBytes(patch.address,Uint8Array.from(Buffer.from(patch.bytes,'hex')));
    const expected=memory.readBytes(MUTABLE_BASE,MUTABLE_SIZE);
    for(const change of row.expected.imageChanges){
      const offset=change.address-MUTABLE_BASE;
      assert.equal(Buffer.from(expected.slice(offset,offset+change.before.length/2)).toString('hex'),change.before);
      expected.set(Buffer.from(change.after,'hex'),offset);
    }
    const rng={state:row.seed,next(){throw new Error('Unexpected HUD RNG consumption');}};
    const dc=new GdiTrace(),sounds=[];
    withX87ControlWord(0x027f,()=>call(memory,dc,...row.arguments.slice(1),{rng,playSound:event=>sounds.push(event)}));
    assert.deepEqual(dc.events,row.expected.drawingCommands,`case ${index}: all ordered requests`);
    assert.equal(rng.state,row.expected.rngState,`case ${index}: RNG`);
    assert.deepEqual(sounds,row.expected.sounds??[],`case ${index}: ordered sound requests`);
    assert.deepEqual(memory.readBytes(MUTABLE_BASE,MUTABLE_SIZE),expected,`case ${index}: all mutable bytes`);
    assert.equal(hash(expected),row.expected.mutableSha256);
    assert.deepEqual(originalCStringContents(memory),row.expected.globalStrings.map(s=>({address:s.address,text:decoder.decode(Buffer.from(s.bytes,'hex'))})),`case ${index}: all global strings`);
  }
});
