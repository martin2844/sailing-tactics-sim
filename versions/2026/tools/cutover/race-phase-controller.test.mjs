import assert from 'node:assert/strict';
import {test} from 'node:test';
import {AddressSpaceMemory} from '../../../../src/runtime/memory.js';
import {drawPaintContent} from '../../public/legacy/versions/2010-en/src/render/paint-lifecycle.js';
import {dispatchRacePhases} from '../../app/engine/race-phase-controller.ts';
// Pure controller is imported directly; the comparison uses actual recovered
// dispatch with stub actions, exercising state gates independently of drawing.
const addresses = {phase:0x5363b0,pause:0x536444,results:0x5363f4,course:0x5233a8,forecast:0x5363f0,wind:0x536434,current:0x536438};
const scenarios = [
  {}, {pause:2}, {pause:300}, {pause:6}, {forecast:1}, {course:1}, {wind:1}, {current:1},
  {results:1}, {results:1,pause:300}, {results:1,course:1}, {wind:1,current:1},
  {pause:300,course:1}, {forecast:1,course:1},
];

function run(phase,scenario,modern,mutate) {
  const memory = new AddressSpaceMemory(0x21c000), log = [];
  for (const [name,value] of Object.entries({phase,...scenario})) memory.writeI32(addresses[name],value);
  memory.writeI32(0x5364e8,60);memory.writeI32(0x5363fc,1);
  memory.writeI32(0x4fe624,1024);memory.writeI32(0x4fe2a8,723);
  const action = name => { log.push(name);if(mutate&&name==='start')memory.writeI32(addresses.phase,1);if(mutate&&name==='results')memory.writeI32(addresses.results,0); };
  const actions = {
    initializeBoatOptions:()=>action('boat-options'),initializeRace:()=>action('race-init'),
    startScreen:()=>action('start'),resultsScreen:()=>action('results'),forecastScreen:()=>action('forecast'),
    pauseScreen:()=>action('pause'),simulationStep:()=>action('step'),chart:mode=>action('chart-'+mode),
  };
  if(modern)dispatchRacePhases(memory,actions);
  else drawPaintContent(memory,{}, {}, {
    initializeBoatOptions:actions.initializeBoatOptions,initializeRace:actions.initializeRace,
    drawStartScreen:actions.startScreen,drawResultsScreen:actions.resultsScreen,drawForecastScreen:actions.forecastScreen,
    drawPauseScreen:actions.pauseScreen,drawSimulationFrame:actions.simulationStep,
    drawChart:(image,dc,x,y,w,h,owner,mode)=>{assert.deepEqual([x,y,w,h,owner],[0,0,1024,723,0]);actions.chart(mode);},
  });
  return {memory,log};
}

test('independent phase dispatch matches recovered state, call order and sequential reloads',()=>{
  for(const phase of[0,1,2,3])for(const scenario of scenarios)for(const mutate of[false,true]){
    const old=run(phase,scenario,false,mutate),modern=run(phase,scenario,true,mutate);
    assert.deepEqual(modern.memory.bytes,old.memory.bytes);
    assert.deepEqual(modern.log,old.log,'phase '+phase+' '+JSON.stringify(scenario)+' '+mutate);
  }
});

test('cycle advancement retains signed DWORD overflow',()=>{
  const memory = new AddressSpaceMemory(0x21c000);
  memory.writeI32(0x5363b0,-1);memory.writeI32(0x5364e8,0x7fffffff);
  const unused = new Proxy({}, {get(){return ()=>{throw Error('Unexpected phase');};}});
  dispatchRacePhases(memory,unused);
  assert.equal(memory.readI32(0x5364e8),-2147483648);
});
