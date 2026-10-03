import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/memory.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createHullTrig } from '../src/engine/hull-geometry.js';
import { drawScene } from '../src/render/scene.js';
import { GdiTrace } from '../src/render/gdi.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const [original,fixture,tables,extended,stored,force,hull]=await Promise.all([
  readFile(new URL('../original/Tact02Demo.exe',import.meta.url)),json('./fixtures/original-scene-composition.json'),json('../assets/data/trig-tables.json'),
  json('../assets/data/x87-trig.json'),json('../assets/data/x87-stored-trig.json'),json('../assets/data/x87-force-trig.json'),json('../assets/data/x87-hull-trig.json'),
]);
const trig=createCapturedTrig(extended,stored,force),hullTrig=createHullTrig(hull);
test('complete original scene composition, including retained shoreline inputs',()=>{
  assert.equal(createHash('sha256').update(original).digest('hex'),fixture.provenance.sha256);
  const memory=loadPE32(original);tables.sine.forEach((value,index)=>memory.writeI32(0x4a54a0+index*4,value));tables.cosine.forEach((value,index)=>memory.writeI32(0x4a3450+index*4,value));
  const block=fixture.mutableBlock,baseline=memory.bytes.slice(),failures=[];
  for(const [index,row] of fixture.routines.drawScene.cases.entries()){
    memory.bytes.set(baseline);for(const input of row.imageInputs)memory.writeBytes(input.address,Uint8Array.from(Buffer.from(input.bits,'hex')));
    const expected=memory.readBytes(block.address,block.size);for(const change of row.expected.imageChanges)expected.set(Buffer.from(change.after,'hex'),change.address-block.address);
    assert.equal(createHash('sha256').update(expected).digest('hex'),row.expected.mutableBlockHash);
    const rng=new PoseyRng(row.seedAtCall);let pixel=0;
    const dc=new GdiTrace({readPixel:()=>{if(pixel>=row.pixelReadValues.length)throw new RangeError('Original pixel input bound exceeded');return row.pixelReadValues[pixel++];}});
    const observed=row.shorelineStackObservations[0];
    const shorelineStack=observed?{...observed,...observed.consumed}:undefined;
    try{drawScene(memory,dc,...row.arguments,{rng,trig,hullTrig,shorelineStack,messageBeep:type=>dc.emit({op:'messageBeep',type})});}
    catch(error){failures.push({index,configuration:row.configuration,error:error.message});continue;}
    const actual=memory.readBytes(block.address,block.size),mismatch=actual.findIndex((value,offset)=>value!==expected[offset]);
    if(mismatch!==-1)failures.push({index,address:(block.address+mismatch).toString(16),actual:Buffer.from(actual.slice(mismatch,mismatch+16)).toString('hex'),expected:Buffer.from(expected.slice(mismatch,mismatch+16)).toString('hex')});
    const mismatchDrawing=dc.events.findIndex((command,n)=>JSON.stringify(command)!==JSON.stringify(row.expected.drawingCommands[n]));
    if(mismatchDrawing!==-1||dc.events.length!==row.expected.drawingCommands.length)failures.push({index,command:mismatchDrawing,actual:dc.events.slice(Math.max(0,mismatchDrawing),Math.max(0,mismatchDrawing)+2),expected:row.expected.drawingCommands.slice(Math.max(0,mismatchDrawing),Math.max(0,mismatchDrawing)+2)});
    if(rng.state!==row.expected.rngState)failures.push({index,rng:rng.state,expectedRng:row.expected.rngState});
  }
  assert.equal(failures.length,0,`${failures.length} mismatches; first: ${JSON.stringify(failures.slice(0,16))}`);
});
