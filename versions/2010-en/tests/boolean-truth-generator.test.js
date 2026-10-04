import test from 'node:test';
import assert from 'node:assert/strict';
import {spawnSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {pythonCommand} from '../../../tools/python-command.js';
import * as typed from '../src/render/typed-c.js';
import * as floating from '../src/render/float-values.js';
import {Float80} from '../../../src/runtime/float80.js';

const body=`{
  const result=cTruth((cTruth(cCompare(memory.first(),0,">")) && cTruth((memory.middle(),fpCompare(memory.second(),0,"<=")))) || cTruth((!cTruth(memory.third()))));
  return {result,raw:cTruth(memory.raw),floating:cTruth(fpTruth(memory.floating))};
}`;
const fixture=`function truthCaseNumber(memory, dc, rng, options = {}) ${body}
function truthCaseOriginal(memory, dc, rng, options = {}) ${body}
function truthCaseNumberByteFrame(memory, dc, rng, options = {}) ${body}`;
const python=`import sys,json
sys.path.insert(0,sys.argv[1])
from eliminate_boolean_truth import eliminate_number_boolean_truth,is_boolean_expression
request=json.load(sys.stdin)
if 'expressions' in request:
 print(json.dumps([is_boolean_expression(value) for value in request['expressions']]))
else:
 print(json.dumps([eliminate_number_boolean_truth(value,'truthCaseNumber',0x424320) for value in request['sources']]))
`;
const compile=request=>{
  const result=spawnSync(pythonCommand,['-c',python,fileURLToPath(new URL('../tools/',import.meta.url))],{
    input:JSON.stringify(request),encoding:'utf8',maxBuffer:10*1024*1024,
  });
  assert.equal(result.status,0,result.stderr);
  return JSON.parse(result.stdout);
};
const instantiate=source=>{
  const bindings={...typed,...floating};
  return new Function(...Object.keys(bindings),source+'\nreturn truthCaseNumber;')(...Object.values(bindings));
};

test('Boolean proof accepts only fixed helper/group/logical results and rejects unknown values',()=>{
  const yes=['cCompare(a,b,"==")','fpCompare(a,b,"<")','cTruth(value)','fpTruth(value)',
    '((cCompare(a,b,"==")))','cTruth(a) && fpCompare(b,c,"<=")',
    'cTruth(a) || (fpCompare(b,c,"<=") && cCompare(d,e,"!="))',
    '(effects(), cCompare(a,b,"=="))','(!cTruth(value))','true','false'];
  const no=['value','0','1','callback()','object.cCompare(a,b,"==")','cCompare(a,b,"==") + 1',
    '!cCompare(a,b,"==") + 1','cCompare(a,b,"==") && value','value || fpCompare(a,b,"<")',
    '(cCompare(a,b,"=="),value)','flag ? cCompare(a,b,"==") : value','cCompare(a,b,"=="'];
  assert.deepEqual(compile({expressions:[...yes,...no]}),[...yes.map(()=>true),...no.map(()=>false)]);
});

test('the private Number body drops identity conversions without altering original or byte bodies',()=>{
  const [source,record]=compile({sources:[fixture]})[0];
  assert.equal(record.eligible,true);assert.equal(record.removedConversions,5);
  assert.equal(source.slice(source.indexOf('\nfunction truthCaseOriginal')),fixture.slice(fixture.indexOf('\nfunction truthCaseOriginal')));
  assert.ok(source.includes('raw:cTruth(memory.raw)'));
  assert.ok(source.includes('(!cTruth(memory.third()))'));
  assert.equal(compile({sources:[source]})[0][0],source,'transformation is idempotent');
});

test('comparison errors, comma effects, getters and short-circuit prefixes remain exact',()=>{
  const original=instantiate(fixture),candidate=instantiate(compile({sources:[fixture]})[0][0]);
  const values=[-1,0,-0,1,undefined,null,Float80.fromNumber(-.5),Float80.fromNumber(.5),NaN,Infinity];
  const run=(fn,a,b,mode)=>{
    const events=[];
    const memory={first(){events.push('first');if(mode==='first')throw new Error('first callback');return a;},
      middle(){events.push('middle');if(mode==='middle')throw new Error('middle callback');},
      second(){events.push('second');if(mode==='second')throw new Error('second callback');return b;},
      third(){events.push('third');if(mode==='third')throw new Error('third callback');return a;},
      get raw(){events.push('raw');if(mode==='raw')throw new Error('raw getter');return b;},
      get floating(){events.push('floating');if(mode==='floating')throw new Error('floating getter');return a;}};
    try{return {returned:fn(memory,null,null,{}),events};}
    catch(error){return {error:{name:error.name,message:error.message},events};}
  };
  for(const mode of ['normal','first','middle','second','third','raw','floating'])for(const a of values)for(const b of values){
    assert.deepEqual(run(candidate,a,b,mode),run(original,a,b,mode),mode);
  }
});

test('shadowed helpers, dynamic scopes and unknown private shapes decline unchanged',()=>{
  const sources=[
    fixture.replace('memory, dc, rng, options = {}','memory, cTruth, rng, options = {}'),
    fixture.replace('  const result=','  const cCompare=()=>false;\n  const result='),
    fixture.replace('  const result=','  eval(memory.source);\n  const result='),
    fixture.replace('cTruth(memory.raw)','memory.cTruth(memory.raw)'),
    fixture.replaceAll('truthCaseNumber','truthCaseOther'),
    fixture+'\nfunction truthCaseNumber() {}',
  ];
  for(const [index,[source,record]] of compile({sources}).entries()){
    assert.equal(record.eligible,false,`case${index}`);
    assert.equal(source,sources[index],`case${index}: source remains exact`);
  }
});
