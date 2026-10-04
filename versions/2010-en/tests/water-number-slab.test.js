import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {spawnSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {pythonCommand} from '../../../tools/python-command.js';
import {AddressSpaceMemory} from '../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import * as typed from '../src/render/typed-c.js';
import * as floating from '../src/render/float-values.js';
import {tryWaterNumberSlab} from '../src/render/water-number-slab.js';

const parameters=['scalarStack4','scalarStack12','scalarStack264','scalarStack552','waterFloat272',
  'dVar1','dVar2','dVar3','dVar5','dVar6','dVar7','dVar8','dVar9','dVar10','dVar11','dVar12','dVar13','dVar14'];
const input=[100,-70,.75,3,1,.5,.25,-.125,.1,.2,.3,.4,.5,.6,.7,.8,.9,1,100.1,99.9,.1];
const memory=()=>{
  const value=new AddressSpaceMemory(0x2000,0x4cc000);
  for(const [address,coefficient] of [[0x4cc5c8,.25],[0x4cc7b0,.5],[0x4cc700,2],[0x4cc618,.125]])value.writeF64(address,coefficient);
  return value;
};
const before=(()=>{
  const source=readFileSync(new URL('../src/render/drawing-functions.js',import.meta.url),'utf8');
  const primary=source.match(/function originalDrawing00466330Number\([^\n]*\) \{[\s\S]*?\n\}/)[0]
    .replace(/case 208: \{ const waterSlab=.*?continue;\} /,'case 208: { ');
  const rows=[...primary.matchAll(/^    case (\d+): \{ (.*) \}\n/gm)]
    .filter(row=>Number(row[1])>=172&&Number(row[1])<=208).map(row=>row[0]).join('');
  const bindings={...typed,...floating,Float80};
  return new Function(...Object.keys(bindings),`return function(memory,...input){
    let [${parameters.join(',')}]=input;
    const scalarArray568=Array(18).fill(undefined),scalarArray728=Array(18).fill(undefined);
    scalarArray728[0]=input[18];scalarArray728[6]=input[19];scalarArray568[6]=input[20];
    const scalarArrayF64Store=value=>fpScalarStoreF64(typeof value==='number'?fpLoad(value):value===undefined||value instanceof Float80?value:cFloat(value));
    const scalarArrayF64Read=value=>{value=fpScalarRead(value);return value instanceof Float80?value.toNumber():value;};
    const r64=address=>fpLoad(memory.readF64(address));
    let iVar16,iVar24,pc=208;
    for(;;){switch(pc){${rows}
      case 171:return [...scalarArray568,...scalarArray728,scalarStack264];
      default:throw new Error('Unexpected slab successor');
    }}
  };`)(...Object.values(bindings));
})();

test('the certified water kernel reproduces the pinned expression tree and declines future source changes',()=>{
  const python=`import sys,json
sys.path.insert(0,sys.argv[1])
from translate_drawing import ROOT,Translator
import floating_drawing as fd
fd.cache_water_float_loads=lambda source,*args:(source,{'eligible':False})
fd.eliminate_number_boolean_truth=lambda source,*args:(source,{'eligible':False,'removedConversions':0})
fd.install_water_number_slab=lambda original,cached,*args:(cached,{'eligible':False},None)
from water_number_slab import build_water_number_slab,install_water_number_slab
from cache_water_float_loads import cache_water_float_loads,NAME
s=Translator('originalDrawing00466330',0x466330,(ROOT/'analysis/drawing-corrections/00466330.c').read_text(),has_dc=True).generate('originalDrawing00466330')
code,report=build_water_number_slab(s)
start=s.index('function originalDrawing00466330Number(')
mutated=s[:start]+s[start:].replace('case 199: {','case 199: { unknownCallback();',1)
cached,_=cache_water_float_loads(s,NAME,0x466330)
installed,installation,_=install_water_number_slab(s,cached,NAME,0x466330)
changed_cached=cached[:start]+cached[start:].replace('case 214: {','case 214: { unknownCallback();',1)
declined_install=install_water_number_slab(s,changed_cached,NAME,0x466330)
print(json.dumps([code,{key:value for key,value in report.items() if key!='operations'},build_water_number_slab(mutated),installed,installation,changed_cached,declined_install[:2]]))
`;
  const result=spawnSync(pythonCommand,['-c',python,fileURLToPath(new URL('../tools/',import.meta.url))],{encoding:'utf8',maxBuffer:1024*1024});
  assert.equal(result.status,0,result.stderr);
  const [code,report,declined,installed,installation,changedCached,declinedInstall]=JSON.parse(result.stdout);
  assert.equal(code,readFileSync(new URL('../src/render/water-number-slab.js',import.meta.url),'utf8'));
  assert.equal(report.eligible,true);assert.equal(report.arithmeticOperations,129);
  assert.equal(report.outputs,37);assert.equal(report.originalMemoryReads,18);assert.equal(report.retainedMemoryReads,4);
  assert.equal(declined[0],null);assert.equal(declined[1].eligible,false);
  assert.equal(installation.eligible,true);
  assert.ok(installed.includes('scalarStack264=waterSlab[36]; iVar16=0; iVar24=0; pc=171; continue;}'));
  assert.ok(installed.includes('tryWaterNumberSlab(memory,scalarStack4,scalarStack12,scalarStack264'));
  assert.equal(declinedInstall[0],changedCached);assert.equal(declinedInstall[1].eligible,false);
});

test('all accepted random and signed-zero cases match the actual129-operation source exactly',()=>withX87ControlWord(0x027f,()=>{
  const value=memory();let seed=0x5070,accepted=0;
  const random=()=>{seed=(Math.imul(seed,1664525)+1013904223)>>>0;return seed/2**32;};
  for(let index=0;index<600;index++){
    const args=index<4?input.map((_v,i)=>i%2===index%2?-0:0)
      :input.map(v=>Math.sign(v)*(random()+.125)*2**(Math.floor(random()*41)-20));
    const result=tryWaterNumberSlab(value,...args);
    assert.ok(result,'moderate finite corpus must certify');accepted++;
    const expected=before(value,...args);
    for(let at=0;at<37;at++)assert.ok(Object.is(result[at],expected[at]),`case ${index},output ${at}`);
  }
  assert.equal(accepted,600);
}));

test('underflow, overflow, unknown inputs and precision changes reject without changing prior outputs',()=>withX87ControlWord(0x027f,()=>{
  const value=memory(),scratch=tryWaterNumberSlab(value,...input),unchanged=Array.from(scratch);
  for(const [index,replacement] of [[0,undefined],[1,NaN],[2,Infinity],[3,Float80.fromNumber(.5)],
    [4,Number.MIN_VALUE],[5,Number.MAX_VALUE],[7,2**-1022]]){
    const args=input.slice();args[index]=replacement;
    if(index===5)args[7]=Number.MAX_VALUE;
    assert.equal(tryWaterNumberSlab(value,...args),undefined,`input ${index}`);
    assert.deepEqual(Array.from(scratch),unchanged,'a rejection makes no output stores');
  }
  assert.equal(withX87ControlWord(0x037f,()=>tryWaterNumberSlab(value,...input)),undefined);
  value.writeF64(0x4cc5c8,NaN);
  assert.equal(tryWaterNumberSlab(value,...input),undefined);
  assert.deepEqual(Array.from(scratch),unchanged);
}));

test('custom-memory fallback is selected before any speculative read or Proxy observation',()=>withX87ControlWord(0x027f,()=>{
  let calls=0;
  const custom={readF64(){calls++;return .5;}};
  assert.equal(tryWaterNumberSlab(custom,...input),undefined);assert.equal(calls,0);
  const proxy=new Proxy(memory(),{get(){calls++;throw new Error('get');},getPrototypeOf(){calls++;throw new Error('prototype');},
    getOwnPropertyDescriptor(){calls++;throw new Error('descriptor');}});
  assert.equal(tryWaterNumberSlab(proxy,...input),undefined);assert.equal(calls,0);
}));

test('an externally detached scratch causes a safe decline',()=>withX87ControlWord(0x027f,()=>{
  const value=memory(),scratch=tryWaterNumberSlab(value,...input);
  structuredClone(scratch.buffer,{transfer:[scratch.buffer]});
  assert.equal(tryWaterNumberSlab(value,...input),undefined);
}));
