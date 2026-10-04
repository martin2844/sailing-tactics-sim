import test from 'node:test';
import assert from 'node:assert/strict';
import {spawnSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {pythonCommand} from '../../../tools/python-command.js';
import * as typed from '../src/render/typed-c.js';
import * as scalar from '../src/render/scalar-stack.js';
import {Float80} from '../../../src/runtime/float80.js';

const address=0x424320;
const fixture=`export function pointCase(memory, dc, rng, options = {}, ...originalArgs) {
  const localFrame=createLocalFrame(16,options.retainedDrawingStack?.[${address}]??[]);
  writeLocal(framePointer(localFrame,0),originalArgs[0],4,"int");
  let pc=1;
  for (;;) { switch (pc) {
    case 0: { return [readLocal(framePointer(localFrame,0),4,"int"),readLocal(framePointer(localFrame,4),4,"int"),readLocal(framePointer(localFrame,8),4,"int")]; }
    case 1: { writeLocalPoint(framePointer(localFrame,4),dc.moveTo()); pc=0; continue; }
  } }
}`;
const python=`import sys,json
sys.path.insert(0,sys.argv[1])
from optimize_static_locals import promote_static_locals
cases=json.load(sys.stdin)
print(json.dumps([promote_static_locals(source,'pointCase',0x424320,16) for source in cases]))
`;
const compile=sources=>{
  const result=spawnSync(pythonCommand,['-c',python,fileURLToPath(new URL('../tools/',import.meta.url))],{
    input:JSON.stringify(sources),encoding:'utf8',maxBuffer:10*1024*1024,
  });
  assert.equal(result.status,0,result.stderr);
  return JSON.parse(result.stdout);
};
const instantiate=source=>{
  const bindings={...typed,...scalar};
  return new Function(...Object.keys(bindings),source.replace('export function','function')+'\nreturn pointCase;')(...Object.values(bindings));
};

test('fixed private POINT stores become scalars while the complete byte fallback stays unchanged',()=>{
  const [source,record]=compile([fixture])[0];
  assert.equal(record.eligible,true);assert.equal(record.expandedPointStores,1);
  assert.deepEqual(record.slots.map(row=>row.offset),[0,4,8]);
  const expected=fixture.replace('export function pointCase(memory, dc, rng, options = {}, ...originalArgs)',
    'function pointCaseByteFrame(memory, dc, rng, options, originalArgs, retainedLocalBytes)')
    .replace(`createLocalFrame(16,options.retainedDrawingStack?.[${address}]??[])`,'createLocalFrame(16,retainedLocalBytes)');
  assert.ok(source.endsWith(expected));
});

test('POINT expression, x/y getters, coercions and strict failures keep their original order',()=>{
  const original=instantiate(fixture),promoted=instantiate(compile([fixture])[0][0]);
  const values=[0,-0,0xffffffff,2**40,1.25,undefined,Float80.fromNumber(1.75),'semantic point',
    {frame:{},offset:0},Infinity,NaN,{valueOf(){throw new RangeError('point conversion failed');}}];
  const run=(fn,x,y,mode)=>{
    const events=[];
    const point=mode==='null'?null:mode==='undefined'?undefined:{
      get x(){events.push('x');if(mode==='throw-x')throw new Error('x getter');return x;},
      get y(){events.push('y');if(mode==='throw-y')throw new Error('y getter');return y;},
    };
    const dc={moveTo(){events.push('move');if(mode==='throw-move')throw new Error('move callback');return point;}};
    try{return {returned:fn(null,dc,null,{},7),events};}
    catch(error){return {error:{name:error.name,message:error.message},events};}
  };
  for(const mode of ['normal','null','undefined','throw-x','throw-y','throw-move'])for(const x of values)for(const y of values){
    assert.deepEqual(run(promoted,x,y,mode),run(original,x,y,mode),mode);
  }
});

test('POINT promotion declines escaping, overlapping, out-of-bounds and observed-return cases',()=>{
  const point='writeLocalPoint(framePointer(localFrame,4),dc.moveTo());';
  const sources=[
    fixture.replace(point,'return writeLocalPoint(framePointer(localFrame,4),dc.moveTo());'),
    fixture.replace(point,'const observed=writeLocalPoint(framePointer(localFrame,4),dc.moveTo());'),
    fixture.replace(point,'writeLocalPoint(framePointer(localFrame,12),dc.moveTo());'),
    fixture.replace(point,'writeLocalPoint(pointerAdd(framePointer(localFrame,4),memory.delta),dc.moveTo());'),
    fixture.replace('  let pc=1;','  memory.escape(framePointer(localFrame,0));\n  let pc=1;'),
    fixture.replace('  let pc=1;','  writeLocal(framePointer(localFrame,6),1,4,"int");\n  let pc=1;'),
    fixture.replace('  let pc=1;','  const scalarPointValue0=0;\n  let pc=1;'),
  ];
  for(const [index,[source,record]] of compile(sources).entries()){
    assert.equal(record.eligible,false,`case${index}`);
    assert.equal(source,sources[index],`case${index}: declined source stays exact`);
  }
});
