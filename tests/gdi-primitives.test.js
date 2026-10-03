import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { GdiTrace } from '../src/render/gdi.js';
import * as primitives from '../src/render/boat-primitives.js';
import * as symbols from '../src/render/chart-symbols.js';
import { drawChartBoat, drawChartCatamaran } from '../src/render/chart-boat.js';
import * as chartDetails from '../src/render/chart-details.js';
import * as chartTerrain from '../src/render/chart-terrain.js';
import * as chartLabels from '../src/render/chart-labels.js';
import * as chartOverlays from '../src/render/chart-overlays.js';
import { drawChart } from '../src/render/chart.js';
import { drawSky } from '../src/render/sky.js';
import * as water from '../src/render/water.js';
import { drawSceneWindPatch } from '../src/render/scene-wind.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';

const original = await readFile(new URL('../original/Tact02Demo.exe',import.meta.url));
const tables=JSON.parse(await readFile(new URL('../assets/data/trig-tables.json',import.meta.url),'utf8'));
const readJson=async path=>JSON.parse(await readFile(new URL(path,import.meta.url),'utf8'));
const fixtures=await Promise.all(['original-gdi-primitives.json','original-chart-details.json','original-chart-terrain.json','original-chart-wrapper.json','original-scene-surface.json'].map(name=>readJson(`./fixtures/${name}`)));
const trig=createCapturedTrig(...await Promise.all(['x87-trig.json','x87-stored-trig.json','x87-force-trig.json'].map(name=>readJson(`../assets/data/${name}`))));
const functions={...primitives,...symbols,...chartDetails,...chartTerrain,...chartLabels,...chartOverlays,...water,drawChart,drawChartBoat,drawChartCatamaran,drawSky,drawSceneWindPatch};
const hash=bytes=>createHash('sha256').update(bytes).digest('hex');

for(const fixture of fixtures){
assert.equal(fixture.provenance.sha256,hash(original));
for(const [name,group] of Object.entries(fixture.routines))test(`${name}: original ordered drawing commands, complete state and RNG (${group.cases.length} cases)`,()=>{
  const memory=loadPE32(original);
  for(const [base,values] of [[0x4a54a0,tables.sine],[0x4a3450,tables.cosine]])values.forEach((value,index)=>memory.writeI32(base+index*4,value));
  const {address:base,size}=fixture.mutableBlock,baseline=memory.readBytes(base,size),failures=[];
  for(const [index,row] of group.cases.entries()){
    memory.writeBytes(base,baseline);
    for(const patch of row.imageInputs)memory.writeBytes(patch.address,new Uint8Array(Buffer.from(patch.bits,'hex')));
    const expected=memory.readBytes(base,size);
    for(const change of row.expected.imageChanges){
      assert.equal(Buffer.from(expected.slice(change.address-base,change.address-base+change.before.length/2)).toString('hex'),change.before);
      expected.set(Buffer.from(change.after,'hex'),change.address-base);
    }
    assert.equal(hash(expected),row.expected.mutableBlockHash);
    const rng=new PoseyRng(row.seedAtCall),dc=new GdiTrace();
    try{functions[name](memory,...(group.argumentTypes[0]==='CDC'?[dc]:[]),...row.arguments,{rng,drawChartBoat,trig,drawChartMarkLabel:chartLabels.drawChartMarkLabel});}
    catch(error){failures.push({index,error:error.message});continue;}
    const actual=memory.readBytes(base,size),offset=actual.findIndex((value,at)=>value!==expected[at]);
    if(offset>=0)failures.push({index,stateAddress:`0x${(base+offset).toString(16)}`,expected:Buffer.from(expected.slice(offset,offset+16)).toString('hex'),actual:Buffer.from(actual.slice(offset,offset+16)).toString('hex')});
    if(rng.state!==row.expected.rngState)failures.push({index,rng:rng.state,expectedRng:row.expected.rngState});
    try{assert.deepEqual(dc.events,row.expected.drawingCommands);}
    catch{
      const event=dc.events.findIndex((value,at)=>JSON.stringify(value)!==JSON.stringify(row.expected.drawingCommands[at]));
      failures.push({index,drawingEvent:event,actual:dc.events[event],expected:row.expected.drawingCommands[event],actualCount:dc.events.length,expectedCount:row.expected.drawingCommands.length});
    }
  }
  assert.equal(failures.length,0,`${failures.length} mismatches; first: ${JSON.stringify(failures.slice(0,8))}`);
});
}
