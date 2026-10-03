import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createNativeHarness } from './native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { GdiTrace } from '../src/render/gdi.js';
import * as pages from '../src/render/tutorial-pages.js';
import '../src/render/index.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const trig=createCapturedTrig(await json('../assets/data/x87-trig.json'),await json('../assets/data/x87-stored-trig.json'));
const remaining=Object.keys(pages.TUTORIAL_PAGE_ROUTINES).filter(name=>Number(name.replace('drawTutorial',''))>8);

assert.equal(remaining.length,34,'All later original English tutorial pages are tested');
for(const name of remaining)test(`${name}: complete unchanged original state, names, sound and drawing order`,async()=>{
  const page=Number(name.replace('drawTutorial',''));
  const fixture=await json(`fixtures/original-tutorial-${page}.json`);
  assert.equal(fixture.routine.address,pages.TUTORIAL_PAGE_ROUTINES[name]);
  const harness=createNativeHarness(source,fixture);
  for(const [index,row] of fixture.cases.entries()){
    const sounds=[];let ticks=0,pixels=0;
    const dc=new GdiTrace({readPixel(){
      if(pixels>=row.host.pixels.length)throw new RangeError('Tutorial exceeded its declared pixel inputs');
      return row.host.pixels[pixels++];
    }});
    harness.check(row,index,(memory,rng)=>pages[name](memory,dc,rng,{
      trig,menuHeight:row.host.menuHeight,
      getTickCount:()=> (row.host.tickStart+ticks++)>>>0,
      getCursorPos:()=>({x:row.host.cursor[0],y:row.host.cursor[1]}),
      playSound:event=>{sounds.push(event);return 1;},
    }));
    assert.deepEqual(dc.events,row.expected.drawingCommands,`case ${index}: ordered original drawing/text`);
    assert.deepEqual(sounds,row.expected.sounds,`case ${index}: ordered original sounds`);
    assert.equal(pixels,row.expected.drawingCommands.filter(event=>event.op==='getPixel').length);
  }
});
