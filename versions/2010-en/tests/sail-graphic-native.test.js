import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {originalDrawing00482ae0} from '../src/render/drawing-functions.js';
import {GdiTrace} from '../src/render/gdi.js';
import {createNativeHarness} from './native-state.js';

const source=new Uint8Array(await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url)));
const fixture=JSON.parse(await readFile(new URL('fixtures/original-sail-graphic-points.json',import.meta.url)));
for(const mode of ['original','number','byte-frame'])test(`sail graphic ${mode}: negative POINTs and reused DWORDs match original x86`,()=>{
  const harness=createNativeHarness(source,fixture);
  assert.equal(fixture.cases.length,8);
  let negativePositions=0;
  for(const [index,row]of fixture.cases.entries()){
    const dc=new GdiTrace();
    harness.check(row,index,(memory,rng,args)=>originalDrawing00482ae0(memory,dc,rng,{
      numberRendering:mode==='number',
      ...(mode==='byte-frame'?{retainedDrawingStack:{[0x482ae0]:[]}}:{}),
      playSound:()=>{throw new Error('Unexpected sail graphic sound');},
    },...args.slice(1)));
    assert.deepEqual(dc.events,row.expected.drawingCommands,`${row.name}: all original GDI requests`);
    assert.deepEqual(row.expected.sounds,[]);
    negativePositions+=dc.events.filter(event=>event.op==='moveTo'&&event.y<0).length;
  }
  assert.ok(negativePositions>0,'native cases include negative real MoveTo POINT returns');
});
