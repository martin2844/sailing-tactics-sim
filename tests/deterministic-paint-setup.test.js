import test from 'node:test';
import assert from 'node:assert/strict';
import vm from 'node:vm';
import {spawnSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {AddressSpaceMemory} from '../src/runtime/memory.js';
import {handleMenuCommand} from '../versions/2010-en/src/engine/menu-controller.js';
import {deterministicPaintSetupInstrumentation,assertDeterministicSetupMatches,deterministicSetupSnapshotExpression,deterministicFinalPaintSnapshotInstrumentation,disableOriginalAutomaticSlowdown} from '../tools/deterministic-paint-setup.js';
import {paintMeasurementInstrumentation} from '../tools/paint-measurements.js';

test('the opt-in setup gate retains and releases each original callback exactly once',()=>{
  const timers=[],events=[];
  const context=vm.createContext({Date:class extends Date{},performance:{now:()=>10},setTimeout:(callback,delay)=>timers.push({callback,delay}),
    MessageChannel:undefined,record:value=>events.push(value)});
  vm.runInContext(deterministicPaintSetupInstrumentation()+paintMeasurementInstrumentation('paintMeasurements.push(start);',{setupGate:true})+`
    function paint(){record('original');}
    setTimeout(paint,5);
    setTimeout(()=>record('unrelated'),2);
  `,context);
  assert.deepEqual(timers.map(row=>row.delay),[5,2]);
  timers.shift().callback();assert.equal(context.paintSetupGate.queued,1);assert.equal(events.length,0);
  timers.shift().callback();assert.deepEqual(events,['unrelated']);
  context.paintSetupGate.step('one');assert.deepEqual(events,['unrelated','original']);
  assert.equal(context.paintSetupGate.queued,0);assert.equal(context.paintMeasurements.length,1);
  assert.throws(()=>context.paintSetupGate.step('none'),/exactly one/);
  vm.runInContext('setTimeout(paint,0);',context);timers.shift().callback();
  context.paintSetupGate.release();assert.equal(events.filter(value=>value==='original').length,2);
  vm.runInContext('setTimeout(paint,0);',context);timers.shift().callback();
  assert.equal(events.filter(value=>value==='original').length,3);
  assert.equal(context.paintSetupGate.queued,0);assert.equal(context.paintMeasurements.length,3);
});

test('the diagnostic turns an enabled native automatic-slowdown setting off with one menu command and one paint',async()=>{
  for(const setting of [0,1,2]){
    const memory=new AddressSpaceMemory(0x140000);memory.writeI32(0x4da1dc,setting);
    const events=[];
    const result=await disableOriginalAutomaticSlowdown(()=>memory.readI32(0x4da1dc),id=>{
      events.push(['command',id]);
      assert.equal(handleMenuCommand(memory,id,{invalidateRect:()=>events.push(['invalidate'])}),true);
    },label=>events.push(['paint',label]));
    assert.equal(memory.readI32(0x4da1dc),0);assert.equal(result.before,setting);assert.equal(result.after,0);
    assert.deepEqual(events,setting===0?[]:[['command',32984],['invalidate'],['paint','menu32984 disable automatic slowdown']]);
    assert.deepEqual(result.intervention,setting===0?null:{command:32984,label:'Slow Simulator if Foul Likely',paintCount:1});
  }
  for(const setting of [-1,3]){
    await assert.rejects(disableOriginalAutomaticSlowdown(()=>setting,()=>assert.fail('unexpected menu command'),()=>assert.fail('unexpected paint')),/unsupported state/);
  }
});

test('the optional native2010 setting rejects2002 before launching a browser',()=>{
  const result=spawnSync(process.execPath,[fileURLToPath(new URL('../tools/diagnostics/measure-2010-pace.mjs',import.meta.url)),'unsupported-auto-slow-check'],{
    env:{...process.env,TACT_PACE_EDITION:'2002',TACT_PACE_NO_AUTO_SLOW:'1'},encoding:'utf8',timeout:10000,
  });
  assert.equal(result.status,1);assert.match(result.stderr,/TACT_PACE_NO_AUTO_SLOW covers the original2010 menu only/);
});

test('deterministic setup validation requires the whole image, RNG, frame and ordered command history',()=>{
  const reference={entry:{frame:20,rngState:123,memoryBase:0x400000,memorySize:20,memorySha256:'image'},history:[{kind:'command',id:32909}]};
  assert.doesNotThrow(()=>assertDeterministicSetupMatches(structuredClone(reference),reference));
  for(const key of Object.keys(reference.entry)){
    const changed=structuredClone(reference);changed.entry[key]='different';
    assert.throws(()=>assertDeterministicSetupMatches(changed,reference),new RegExp(key));
  }
  const changed=structuredClone(reference);changed.history.push({kind:'paint'});
  assert.throws(()=>assertDeterministicSetupMatches(changed,reference),/history differs/);
  const source=deterministicSetupSnapshotExpression({time:1,clock:2,speed:3,divisor:4,racing:5,mode:6,overlays:[7]});
  assert.match(source,/bytes=m.bytes.slice\(\)/);assert.match(source,/s.rng.state/);
  assert.doesNotMatch(source,/write|rng.state\s*=/);
});

test('the measured final image and RNG are copied at the target paint before asynchronous hashing',async()=>{
  const bytes=new Uint8Array([1,2,3]),values=new Map([[2,100],[3,10],[4,76],[5,2],[6,0],[7,0]]);
  const state={frames:24,rng:{state:123},error:null,memory:{base:0x400000,size:3,bytes,
    readF64:()=>100.25,readI32:address=>values.get(address)}};
  let resolveHash,hashedBytes;
  const context=vm.createContext({tact:{state},paintMeasurementFinalFrame:25,crypto:{subtle:{digest:(_algorithm,image)=>{
    hashedBytes=image;return new Promise(resolve=>{resolveHash=resolve;});
  }}}});
  const source=deterministicFinalPaintSnapshotInstrumentation({time:1,clock:2,speed:3,divisor:4,racing:5,mode:6,autoSlow:7});
  vm.runInContext(source,context);assert.equal(context.paintMeasurementFinalSnapshot,undefined);
  state.frames=25;vm.runInContext(source,context);
  state.frames=26;state.rng.state=456;bytes.fill(9);values.set(2,101);
  assert.deepEqual([...hashedBytes],[1,2,3]);
  resolveHash(new Uint8Array([0xab,0x01]).buffer);
  const final=await context.paintMeasurementFinalSnapshot;
  assert.equal(final.frame,25);assert.equal(final.rngState,123);assert.equal(final.clock,100);
  assert.equal(final.memorySha256,'ab01');assert.equal(final.autoSlow,0);
});
