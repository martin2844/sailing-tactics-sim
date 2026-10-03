import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {loadOriginalData,ORIGINAL_SOURCE_SHA256,MUTABLE_BASE,MUTABLE_SIZE} from '../src/runtime/original-data.js';
import {initializeIntegerTrig} from '../src/engine/application.js';
import {withX87ControlWord} from '../../../src/runtime/float80.js';
import {GdiTrace} from '../src/render/gdi.js';
import * as screens from '../src/render/screens.js';
import * as controls from '../src/render/tutorial-controls.js';
import * as depth from '../src/render/scene-depth.js';
import {resetOriginalCStringContents,originalCStringContents} from '../src/render/text.js';

const data=new URL('../assets/data/',import.meta.url);
const manifest=JSON.parse(await readFile(new URL('original-memory.json',data)));
const segments=new Map(await Promise.all(manifest.segments.map(async row=>[row.file,new Uint8Array(await readFile(new URL(row.file,data)))])));
const trig=JSON.parse(await readFile(new URL('trig-tables.json',data)));
const hash=bytes=>createHash('sha256').update(bytes).digest('hex');
const decoder=new TextDecoder('windows-1252');
const cases={
 demo:(m,d,r,o)=>screens.drawDemoScreen(m,d,r,o),
 results:(m,d,r,o)=>screens.drawResultsScreen(m,d,r,o),
 advice:(m,d,r,o,a)=>screens.drawAdvice(m,d,...a,{...o,rng:r}),
 jibe:(m,d,r,o,a)=>screens.drawJibeAdvice(m,d,...a,{...o,rng:r}),
 tack:(m,d,r,o,a)=>screens.drawTackAdvice(m,d,...a,{...o,rng:r}),
 'text-color':(m,d,r,o,a)=>controls.selectBoatTextColor(m,d,...a),
 'advance-button':(m,d,r,o,a)=>controls.drawTutorialAdvanceButton(m,d,...a),
 'advance-hint':(m,d,r,o,a)=>controls.drawTutorialAdvanceHint(m,d,...a),
 'depth-sort':(m,d,r,o,a)=>depth.sortSceneDepths(m,...a),
 'depth-select':(m,d,r,o,a)=>depth.selectNearestSceneObject(m,...a),
};

for(const [name,call] of Object.entries(cases))test(`2010 ${name}: exact original requests/state/text/RNG`,async()=>{
 const fixture=JSON.parse(await readFile(new URL(`fixtures/original-drawing-${name}.json`,import.meta.url)));
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
  for(const patch of row.patches)memory.writeBytes(patch.address,Uint8Array.from(Buffer.from(patch.bytes,'hex')));
  const expected=memory.readBytes(MUTABLE_BASE,MUTABLE_SIZE);
  for(const change of row.expected.imageChanges){
   const offset=change.address-MUTABLE_BASE;
   assert.equal(Buffer.from(expected.slice(offset,offset+change.before.length/2)).toString('hex'),change.before);
   expected.set(Buffer.from(change.after,'hex'),offset);
  }
  const rng={state:row.seed,next(){throw new Error('Unexpected RNG consumption');}};
  const dc=new GdiTrace();
  const args=fixture.routine.argumentTypes[0]==='CDC'?row.arguments.slice(1):row.arguments;
  withX87ControlWord(0x027f,()=>call(memory,dc,rng,{},args));
  assert.deepEqual(dc.events,row.expected.drawingCommands??[],`case ${index}: drawing order/text`);
  assert.equal(rng.state,row.expected.rngState,`case ${index}: RNG`);
  assert.deepEqual(memory.readBytes(MUTABLE_BASE,MUTABLE_SIZE),expected,`case ${index}: every mutable byte`);
  assert.equal(hash(expected),row.expected.mutableSha256);
  if(row.expected.globalStrings)assert.deepEqual(originalCStringContents(memory),row.expected.globalStrings.map(s=>({address:s.address,text:decoder.decode(Buffer.from(s.bytes,'hex'))})),`case ${index}: semantic global CStrings`);
 }
});
