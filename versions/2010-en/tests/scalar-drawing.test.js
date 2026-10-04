import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {createNativeHarness} from './native-state.js';
import {GdiTrace} from '../src/render/gdi.js';
import {drawTutorial2} from '../src/render/tutorial-pages.js';
import {originalDrawAdvice} from '../src/render/render-functions.js';
import {originalDrawCircle,SCREEN_HELPER_ROUTINES} from '../src/render/screen-helper-functions.js';
import '../src/render/index.js';

const json=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const generation=await json('../analysis/scalar-stack-generation.json');
const eligible=Object.values(generation.modules).flat().filter(row=>row.eligible);
const retainedDrawingStack=Object.fromEntries(eligible.map(row=>[row.address,[]]));

for(const [fixtureFile,call] of [
  ['original-tutorial-2.json',drawTutorial2],
  ['original-drawing-advice.json',originalDrawAdvice],
])test(`${fixtureFile}: scalar and explicitly retained byte paths each match the unchanged native captures`,async()=>{
  const fixture=await json(`fixtures/${fixtureFile}`);
  assert.ok(eligible.some(row=>row.address===fixture.routine.address));
  for(const mode of ['scalar','byte-frame']){
    const harness=createNativeHarness(source,fixture);
    for(const [index,row] of fixture.cases.entries()){
      const dc=new GdiTrace(),options=mode==='byte-frame'?{retainedDrawingStack}:{};
      harness.check(row,index,(memory,rng,args)=>call(memory,dc,rng,options,...args.slice(1)));
      assert.deepEqual(dc.events,row.expected.drawingCommands,`${mode}, case ${index}: all original ordered requests`);
    }
  }
});

test('explicit retained inputs use the byte frame once and preserve initialization/bounds failures',()=>{
  const address=SCREEN_HELPER_ROUTINES.originalDrawCircle;
  const memory={readI32(){throw new Error('Circle unexpectedly accessed global memory');}};
  const draw=(args,rows)=>{
    const dc=new GdiTrace();
    let reads=0;
    const stack=Object.defineProperty({},address,{get(){reads++;return rows;}});
    try{
      originalDrawCircle(memory,dc,undefined,{retainedDrawingStack:stack},...args);
      return {events:dc.events,reads};
    }catch(error){return {error:{name:error.constructor.name,message:error.message},reads};}
  };
  const args=[7,20,30];
  for(const rows of [undefined,null,[],[{offset:4,bytes:'efcdab89'}]]){
    assert.deepEqual(draw(args,rows),{events:[{op:'ellipse',left:13,top:23,right:27,bottom:37}],reads:1});
  }
  assert.deepEqual(draw(args,[{offset:255,bytes:'0102'}]),{
    error:{name:'RangeError',message:'Declared retained local exceeds frame'},reads:1});
  const expected={error:{name:'RangeError',message:'Original C reads an undefined retained local byte'},reads:1};
  assert.deepEqual(draw([undefined,20,30],undefined),expected);
  assert.deepEqual(draw([undefined,20,30],[{offset:4,bytes:'07000000'}]),expected,
    'Undefined caller argument still invalidates explicitly retained bytes before a strict read');
});
