import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../src/runtime/memory.js';
import {PoseyRng} from '../../../src/engine/integer-core.js';
import {loadOriginalData,ORIGINAL_SOURCE_SHA256} from '../src/runtime/original-data.js';
import {initializeApplication,loadPreferences,saveApplicationPreferences,PREFERENCE_FIELDS} from '../src/engine/application.js';
import {handleMenuCommand,menuCommandState} from '../src/engine/menu-controller.js';
import {createHash} from 'node:crypto';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const manifest=JSON.parse(await readFile(new URL('../assets/data/original-memory.json',import.meta.url)));
const tables=JSON.parse(await readFile(new URL('../assets/data/trig-tables.json',import.meta.url)));
const segments=new Map(await Promise.all(manifest.segments.map(async row=>[row.file,new Uint8Array(await readFile(new URL('../assets/data/'+row.file,import.meta.url)))])));
const mode=0x4da16c,sessionCount=0x536420;
const initialize=(memory,preferences=null)=>initializeApplication(memory,new PoseyRng(),{preferences,timeSeed:1,screenHeight:768,integerTrig:tables});

test('2010 supplied executable and browser initial data both retain original full mode',()=>{
  assert.equal(createHash('sha256').update(source).digest('hex'),ORIGINAL_SOURCE_SHA256);
  assert.equal(loadPE32(source).readI32(mode),0);
  const memory=loadOriginalData(manifest,segments);
  assert.equal(memory.readI32(mode),0);
  initialize(memory);
  assert.equal(memory.readI32(mode),0);
  assert.ok(PREFERENCE_FIELDS.every(field=>mode<field.address||mode>=field.address+field.bytes),'Native preference fields never overlap the edition-mode word');
});

test('saved preference session counters cannot replace the full edition mode on reload',()=>{
  const memory=loadOriginalData(manifest,segments);initialize(memory);
  for(const count of [0,10,11,12,2147483647]){
    memory.writeI32(sessionCount,count);
    const preferences=saveApplicationPreferences(memory);
    assert.equal(memory.readI32(sessionCount),count,'Full edition does not increment the demo session counter');
    const reloaded=loadOriginalData(manifest,segments);
    loadPreferences(reloaded,preferences);assert.equal(reloaded.readI32(mode),0);
    initialize(reloaded,preferences);
    assert.equal(reloaded.readI32(mode),0);assert.equal(reloaded.readI32(sessionCount),count);
  }
});

test('full edition exposes all legitimate fleet sizes and its mode-gated tutorials',()=>{
  const memory=loadOriginalData(manifest,segments);initialize(memory);
  memory.writeI32(0x5363b0,0);
  for(const [command,count]of [[32805,2],[32806,5],[32807,10],[32808,15],[32809,20],[32810,25],[32811,30]]){
    assert.equal(menuCommandState(memory,command).enabled,true);
    handleMenuCommand(memory,command);
    assert.equal(memory.readI32(0x4da194),count);assert.equal(memory.readI32(mode),0);
  }
  assert.equal(menuCommandState(memory,32929).enabled,true,'Same Tack original full-mode tutorial');
  assert.equal(menuCommandState(memory,32930).enabled,true,'More original full-mode tutorial');
});
