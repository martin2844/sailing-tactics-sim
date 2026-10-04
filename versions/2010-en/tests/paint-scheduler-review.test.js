import test from 'node:test';
import assert from 'node:assert/strict';
import vm from 'node:vm';
import {readFile} from 'node:fs/promises';
import {paintMeasurementInstrumentation} from '../../../tools/paint-measurements.js';

const source=await readFile(new URL('../src/play.js',import.meta.url),'utf8');
const binding=source.match(/^const paintQueue=typeof MessageChannel[^\n]*\nif\(paintQueue\)[^\n]*$/m)?.[0];
const request=source.slice(source.indexOf('function requestPaint(delay=0){'),source.indexOf('\nfunction paint(){'));
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
  const state={ready:true,closed:false,error:null,modal:false,pending:false,nextPaint:false};
  const context=vm.createContext({state,Math,Date:class extends Date{},performance:{now:()=>10},
    MessageChannel:channel?Channel:undefined,MessagePort:Port,
    setTimeout(callback,delay){timers.push({callback,delay});},
    paint:function paint(){assert.equal(state.pending,true);state.pending=false;paints.push('paint');},
  });
  if(instrument)vm.runInContext(paintMeasurementInstrumentation('paintMeasurements.push("measured");'),context);
  vm.runInContext(binding+'\n'+request+'\nglobalThis.schedule=requestPaint;',context);
  return {context,state,messages,timers,paints};
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
