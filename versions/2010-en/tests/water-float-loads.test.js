import test from 'node:test';
import assert from 'node:assert/strict';
import {spawnSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {pythonCommand} from '../../../tools/python-command.js';
import * as typed from '../src/render/typed-c.js';
import * as floating from '../src/render/float-values.js';
import {Float80} from '../../../src/runtime/float80.js';

let corpus;
const generated=()=>{
  if(corpus)return corpus;
  const python=`import sys,json,re
sys.path.insert(0,sys.argv[1])
from translate_drawing import ROOT,Translator
import floating_drawing as fd
fd.cache_water_float_loads=lambda source,*args:(source,{'eligible':False})
fd.eliminate_number_boolean_truth=lambda source,*args:(source,{'eligible':False,'removedConversions':0})
fd.install_water_number_slab=lambda original,cached,*args:(cached,{'eligible':False},None)
from cache_water_float_loads import cache_water_float_loads,NAME
original=Translator('originalDrawing00466330',0x466330,(ROOT/'analysis/drawing-corrections/00466330.c').read_text(),has_dc=True).generate('originalDrawing00466330')
candidate,report=cache_water_float_loads(original,NAME,0x466330)
start=original.index('function '+NAME+'(')
prefix,private=original[:start],original[start:]
mutations=[
 prefix+private.replace('case 214: {','case 214: { leak(framePointer(localFrame,272));',1),
 prefix+private.replace('case 200: {','case 200: { unknownCallback();',1),
 prefix+private.replace('pc = 211; continue;','pc = 210; continue;',1),
 prefix+private.replace('readLocalFloatNumber(framePointer(localFrame,272))','readLocalFloatNumber(framePointer(localFrame,280))',1),
 prefix+private.replace('let pc = 278;','let waterFloat272; let pc = 278;',1),
]
results=[cache_water_float_loads(source,NAME,0x466330) for source in mutations]
print(json.dumps({'original':original,'candidate':candidate,'report':report,'mutations':mutations,'results':results}))
`;
  const result=spawnSync(pythonCommand,['-c',python,fileURLToPath(new URL('../tools/',import.meta.url))],{
    encoding:'utf8',maxBuffer:5*1024*1024,
  });
  assert.equal(result.status,0,result.stderr);
  return corpus=JSON.parse(result.stdout);
};
const primary=source=>source.match(/function originalDrawing00466330Number\([^\n]*\) \{[\s\S]*?\n\}/)[0];

test('the reviewed water chain retains its first F64 load and complete original/byte fallbacks',()=>{
  const {original,candidate,report}=generated();
  assert.equal(report.eligible,true);
  assert.equal(report.originalLoads,22);assert.equal(report.retainedLoads,1);
  assert.equal(report.privateBodySha256,'52473853aedeb9a49cf2c0de9d3ffb232447888f95274301f392cb0f1759f52f');
  const before=primary(original),after=primary(candidate);
  assert.equal(candidate.replace(after,''),original.replace(before,''));
  assert.ok(after.includes('(waterFloat272=readLocalFloatNumber(framePointer(localFrame,272)))'));
  assert.equal((after.match(/waterFloat272/g)||[]).length,23);
});

test('outside frame escapes, unreviewed callbacks, changed control flow and views decline unchanged',()=>{
  const {mutations,results}=generated();
  for(const [index,[source,report]] of results.entries()){
    assert.equal(report.eligible,false,`mutation ${index}`);
    assert.equal(source,mutations[index]);
  }
});

const slab=source=>{
  const rows=[...primary(source).matchAll(/^    case (\d+): \{ (.*) \}\n/gm)]
    .filter(row=>Number(row[1])>=172&&Number(row[1])<=212).map(row=>row[0]).join('');
  const bindings={...typed,...floating,Float80};
  return new Function(...Object.keys(bindings),`const firstRead=readLocalFloatNumber; return function(input){
    const localFrame=createLocalFrame(880,[]),scalarArray568=Array(18).fill(undefined),scalarArray728=Array(18).fill(undefined);
    const scalarArrayF64Store=value=>fpScalarStoreF64(typeof value==='number'?fpLoad(value):value===undefined||value instanceof Float80?value:cFloat(value));
    const scalarArrayF64Read=value=>{value=fpScalarRead(value);return value instanceof Float80?value.toNumber():value;};
    let scalarStack4=input.x,scalarStack12=input.y,scalarStack264=input.scale,scalarStack552=input.phase;
    let [dVar1,dVar2,dVar3,dVar5,dVar6,dVar7,dVar8,dVar9,dVar10,dVar11,dVar12,dVar13,dVar14]=input.variables;
    let fVar26=input.sine,fVar27=input.cosine,iVar16,iVar24,waterFloat272,reads=0;
    const readLocalFloatNumber=pointer=>{reads++;return firstRead(pointer);};
    const r64=address=>({[0x4cc5c8]:.25,[0x4cc7b0]:.5,[0x4cc700]:2,[0x4cc618]:.125}[address]);
    if(input.initialized)writeLocalFloatNumber(framePointer(localFrame,272),input.factor);
    let pc=212;
    try{for(;;){switch(pc){${rows}
      case 171:return {arrays:[scalarArray568,scalarArray728],scale:scalarStack264,iVar16,iVar24,reads};
      default:throw new Error('Unexpected slab successor');
    }}}catch(error){return {error:{name:error.name,message:error.message},reads};}
  };`)(...Object.values(bindings));
};

test('actual water expressions preserve signed zeros, extended inputs and first-read failures',()=>{
  const {original,candidate}=generated(),before=slab(original),after=slab(candidate);
  const values=[0,-0,1,-1,.125,2**-1022,Number.MIN_VALUE,1e150,-1e150];
  for(const factor of values)for(const initialized of [true,false]){
    const input={factor,initialized,x:factor,y:-factor,scale:.75,phase:3,
      variables:[.5,.125,-.25,.1,.2,.3,.4,.5,.6,.7,.8,.9,1],
      sine:new Float80(1,(1n<<63n)+3n,-2),cosine:Float80.fromNumber(-.5)};
    const a=before(input),b=after(input),successful=!a.error;
    assert.equal(b.reads,1);
    if(successful)assert.equal(a.reads,22);else assert.equal(a.reads,1);
    delete a.reads;delete b.reads;assert.deepEqual(b,a);
  }
});
