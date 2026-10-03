import assert from 'node:assert/strict';
import test from 'node:test';
import {readFile} from 'node:fs/promises';
import {createNativeHarness,sha256} from './native-state.js';
import {GdiTrace} from '../src/render/gdi.js';
import {drawSailingHud} from '../src/render/hud.js';
import {readAnsiString} from '../src/render/text.js';

const root=new URL('../',import.meta.url);
const source=await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe',root));
const fixtureBytes=await readFile(new URL('tests/fixtures/original-drawing-hud-branches.json',root));
const fixture=JSON.parse(fixtureBytes);

test('HUD branch reference retains the original target and exercises every declared text branch',()=>{
  assert.equal(fixture.sourceSha256,sha256(source));
  assert.equal(fixture.routine.address,0x40f240);
  assert.equal(fixture.cases.length,26);
  assert.equal(new Set(fixture.cases.map(row=>row.label)).size,13);
  const {memory}=createNativeHarness(source,fixture);
  for(const row of fixture.cases){
    const literal=readAnsiString(memory,row.requiredLiteralAddress);
    assert.ok(literal.length>0);
    assert.ok(row.expected.drawingCommands.some(event=>event.op==='textOut'&&event.text.includes(literal)),
      `${row.label}: native instructions execute the declared original text branch`);
  }
});

test('all HUD text branches match unchanged native state, strings, RNG, sound and ordered requests',()=>{
  const harness=createNativeHarness(source,fixture);
  for(const [index,row] of fixture.cases.entries()){
    const dc=new GdiTrace(),sounds=[];
    harness.check(row,index,(memory,rng)=>drawSailingHud(memory,dc,...row.arguments.slice(1),{
      rng,playSound:event=>{sounds.push(event);return 1;},
    }));
    assert.deepEqual(dc.events,row.expected.drawingCommands,`${row.label}: all ordered GDI requests`);
    assert.deepEqual(sounds,row.expected.sounds,`${row.label}: all ordered sound requests`);
  }
});
