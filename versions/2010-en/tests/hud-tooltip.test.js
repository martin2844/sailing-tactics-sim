import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {originalDrawing004640e0} from '../src/render/drawing-functions.js';
import {callDrawingDependency,callNumberDrawingDependencyOwned} from '../src/render/dependencies.js';
import {GdiTrace} from '../src/render/gdi.js';
import {drawSailingHud} from '../src/render/hud.js';
import {createNativeHarness} from './native-state.js';

const source=new Uint8Array(await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url)));
const fixture=JSON.parse(await readFile(new URL('fixtures/original-hud-tooltip.json',import.meta.url)));
const retained=[{offset:0,bytes:'a5'.repeat(256)}];

for(const route of ['public','dependency','owned-number','retained'])test(`HUD tooltip ${route}: four original stack words match native text, pixels, colors and state`,()=>{
  const harness=createNativeHarness(source,fixture);
  assert.equal(fixture.cases.length,36);
  for(const [index,row]of fixture.cases.entries()){
    const dc=new GdiTrace();
    const options=route==='retained'?{retainedDrawingStack:{[0x4640e0]:retained}}:{};
    harness.check(row,index,(memory,rng,args)=>{
      const values=args.slice(1);
      if(route==='dependency')return callDrawingDependency(memory,dc,0x4640e0,[dc,...values],rng,options);
      if(route==='owned-number')return callNumberDrawingDependencyOwned(memory,dc,0x4640e0,[dc,...values],0,rng,options);
      return originalDrawing004640e0(memory,dc,rng,options,...values);
    });
    assert.deepEqual(dc.events,row.expected.drawingCommands,`${row.name}: every original GDI request`);
    const text=dc.events.find(event=>event.op==='textOut');
    if(row.inputs.showHelp===0)assert.equal(text,undefined);
    else{
      assert.equal(text.x,row.inputs.width<700?row.arguments[2]+1:row.arguments[3]);
      assert.equal(text.y,row.inputs.baselineY-Math.trunc(row.inputs.height/50)-row.arguments[1]);
    }
  }
});

test('HUD tooltip keeps undefined-argument checks instead of assigning arbitrary retained bytes',()=>{
  const memory=createNativeHarness(source,fixture).memory;
  memory.writeI32(0x4da1b0,1);
  memory.writeI32(0x4fe624,1024);
  for(const options of [{},{retainedDrawingStack:{[0x4640e0]:retained}}]){
    assert.throws(()=>originalDrawing004640e0(memory,new GdiTrace(),undefined,options,undefined,341,417),
      /undefined retained local/);
  }
});

const controls=JSON.parse(await readFile(new URL('fixtures/original-hud-tooltip-controls.json',import.meta.url)));
for(const mode of ['original','number'])test(`full HUD ${mode}: native tooltip arguments and speed controls at clock -71`,()=>{
  const harness=createNativeHarness(source,controls);
  assert.equal(controls.cases.length,18);
  for(const [index,row]of controls.cases.entries()){
    const dc=new GdiTrace(),sounds=[];
    harness.check(row,index,(memory,rng,args)=>drawSailingHud(memory,dc,...args.slice(1),{
      rng,numberRendering:mode==='number',playSound:event=>sounds.push(event),
      menuHeight:row.host.menuHeight,getCursorPos:()=>({x:row.host.cursor[0],y:row.host.cursor[1]}),
    }));
    assert.deepEqual(dc.events,row.expected.drawingCommands,`${row.label}: complete GDI order`);
    assert.deepEqual(sounds,row.expected.sounds,`${row.label}: complete sound order`);
    const tooltipCalls=row.expected.callObservations.filter(call=>call.returnAddress===0x46416f);
    assert.equal(tooltipCalls.length,row.label.endsWith('-outside')?0:1,
      `${row.label}: exercised the original tooltip call`);
    const faster=row.label.endsWith('-click-faster');
    assert.equal(row.expected.integers.speed,faster?2:1);
    assert.equal(row.expected.integers.divisor,faster?1946:2919);
    assert.equal(row.expected.integers.clickY,0);
  }
});
