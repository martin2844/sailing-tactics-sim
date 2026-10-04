import test from 'node:test';
import assert from 'node:assert/strict';
import vm from 'node:vm';
import {readFile} from 'node:fs/promises';
import {paintMeasurementInstrumentation} from '../../../tools/paint-measurements.js';

const source=await readFile(new URL('../src/play.js',import.meta.url),'utf8');
const binding=source.match(/^const paintQueue=typeof MessageChannel[^\n]*\nif\(paintQueue\)[^\n]*$/m)?.[0];
const request=source.slice(source.indexOf('function requestPaint(delay=0){'),source.indexOf('\nfunction paint(){'));
const paintPreamble=source.slice(source.indexOf('function paint(){'),source.indexOf('  state.nextPaint=false;',source.indexOf('function paint(){')));
const visibility=source.match(/^document.addEventListener\('visibilitychange',[\s\S]*?^\}\);/m)?.[0];
assert.ok(binding&&request.startsWith('function requestPaint(delay=0){'));

function environment(channel=true,instrument=false){
  const messages=[],timers=[],paints=[];
  class Port{
    get onmessage(){return this.handler;}
    set onmessage(value){this.handler=value;}
  }
  class Channel{
    constructor(){this.port1=new Port();this.port2={postMessage:value=>messages.push(()=>this.port1.onmessage({data:value}))};}
  }
  const state={ready:true,closed:false,error:null,modal:false,pending:false,nextPaint:false,deferredPaintDue:null};
  let now=10;const listeners=new Map();
  const document={visibilityState:'visible',addEventListener(name,callback){listeners.set(name,callback);}};
  const context=vm.createContext({state,document,Math,Date:class extends Date{},performance:{now:()=>now},
    MessageChannel:channel?Channel:undefined,MessagePort:Port,
    setTimeout(callback,delay){timers.push({callback,delay});},
    recordPaint(){assert.equal(state.pending,false);paints.push('paint');},
  });
  vm.runInContext(paintPreamble+'state.nextPaint=false;recordPaint();}\n',context);
  if(instrument)vm.runInContext(paintMeasurementInstrumentation('paintMeasurements.push("measured");'),context);
  vm.runInContext(binding+'\n'+request+'\n'+visibility+'\nglobalThis.schedule=requestPaint;',context);
  return {context,state,messages,timers,paints,document,listeners,advance:duration=>now+=duration};
}

test('actual requestPaint uses asynchronous immediate tasks with pending deduplication',()=>{
  const {context,state,messages,timers,paints}=environment();
  context.schedule();context.schedule(0);context.schedule(-1);
  assert.equal(messages.length,1);assert.equal(timers.length,0);assert.equal(paints.length,0);
  assert.equal(state.pending,true);assert.equal(state.nextPaint,true);
  messages.shift()();assert.equal(paints.length,1);assert.equal(state.pending,false);
  context.schedule(5);assert.equal(timers.length,1);assert.equal(timers[0].delay,5);
  assert.equal(messages.length,0);timers.shift().callback();assert.equal(paints.length,2);
});

test('hidden pages retain one invalidation without executing a queued paint or advancing the game',()=>{
  const {context,state,messages,paints,document,listeners}=environment();
  context.schedule();document.visibilityState='hidden';
  messages.shift()();assert.equal(paints.length,0);assert.equal(state.pending,false);assert.equal(state.nextPaint,true);
  context.schedule();context.schedule();assert.equal(messages.length,0);
  document.visibilityState='visible';listeners.get('visibilitychange')();
  assert.equal(messages.length,1);messages.shift()();assert.equal(paints.length,1);
  listeners.get('visibilitychange')();assert.equal(messages.length,0,'an uninvalidated frozen page stays frozen');
});

test('visibility resumes only the remaining positive delay and respects modal and terminal states',()=>{
  const {context,state,messages,timers,paints,document,listeners,advance}=environment();
  document.visibilityState='hidden';context.schedule(20);context.schedule();
  assert.equal(timers.length,0);assert.equal(messages.length,0);advance(8);
  document.visibilityState='visible';listeners.get('visibilitychange')();
  assert.equal(timers[0].delay,12);assert.equal(state.deferredPaintDue,null);
  advance(12);document.visibilityState='hidden';timers.shift().callback();assert.equal(paints.length,0);
  state.modal=true;document.visibilityState='visible';listeners.get('visibilitychange')();
  assert.equal(messages.length,0);state.modal=false;context.schedule();messages.shift()();assert.equal(paints.length,1);
  for(const field of ['closed','error']){
    state.nextPaint=true;state[field]=true;listeners.get('visibilitychange')();
    assert.equal(messages.length,0);assert.equal(timers.length,0);state[field]=false;
  }
});

test('missing channel and inactive/modal states preserve the existing timer/request behavior',()=>{
  const {context,state,messages,timers}=environment(false);
  context.schedule(-3);assert.equal(messages.length,0);assert.equal(timers[0].delay,0);
  timers.shift().callback();
  state.modal=true;context.schedule();assert.equal(state.nextPaint,true);assert.equal(state.pending,false);assert.equal(timers.length,0);
  state.modal=false;context.schedule();assert.equal(timers.length,1);timers.shift().callback();
  for(const field of ['closed','error']){
    state[field]=true;state.nextPaint=false;context.schedule();
    assert.equal(state.nextPaint,false);assert.equal(state.pending,false);assert.equal(timers.length,0);state[field]=false;
  }
  state.ready=false;context.schedule();assert.equal(timers.length,0);
});

test('measurement instrumentation observes both actual paint scheduling routes',()=>{
  const {context,messages,timers,paints}=environment(true,true);
  context.schedule();messages.shift()();context.schedule(3);timers.shift().callback();
  assert.equal(paints.length,2);assert.deepEqual(Array.from(context.paintMeasurements),['measured','measured']);
  vm.runInContext('const unrelated=new MessageChannel();unrelated.port1.onmessage=()=>42;unrelated.port2.postMessage(0);',context);
  assert.equal(messages.shift()(),42);
  assert.equal(context.paintMeasurements.length,2,'unrelated message handlers are not measured as paints');
});
