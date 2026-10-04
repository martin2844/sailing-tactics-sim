import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {AddressSpaceMemory} from '../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import * as typed from '../src/render/typed-c.js';
import * as floating from '../src/render/float-values.js';
import {tryWaterNumberSlab} from '../src/render/water-number-slab.js';

const parameters=['scalarStack4','scalarStack12','scalarStack264','scalarStack552','waterFloat272',
  'dVar1','dVar2','dVar3','dVar5','dVar6','dVar7','dVar8','dVar9','dVar10','dVar11','dVar12','dVar13','dVar14'];
const input=[100,-70,.75,3,1,.5,.25,-.125,.1,.2,.3,.4,.5,.6,.7,.8,.9,1,100.1,99.9,.1];
const constants=[[0x4cc5c8,.25],[0x4cc7b0,.5],[0x4cc700,2],[0x4cc618,.125]];
const source=readFileSync(new URL('../src/render/drawing-functions.js',import.meta.url),'utf8');
const primary=source.match(/function originalDrawing00466330Number\([^\n]*\) \{[\s\S]*?\n\}/)?.[0];
assert.ok(primary,'the actual generated private Number water body must exist');
const actualRows=[...primary.matchAll(/^    case (\d+): \{ (.*) \}\n/gm)]
  .filter(row=>Number(row[1])>=172&&Number(row[1])<=208).map(row=>row[0]).join('');
assert.equal((actualRows.match(/tryWaterNumberSlab\(/g)||[]).length,1,'this test must exercise the integrated kernel');
const originalRows=actualRows.replace(/case 208: \{ const waterSlab=.*?continue;\} /,'case 208: { ');
assert.notEqual(originalRows,actualRows);
assert.equal(originalRows.includes('tryWaterNumberSlab'),false);

function compile(rows){
  const bindings={...typed,...floating,Float80,tryWaterNumberSlab};
  return new Function(...Object.keys(bindings),`return function(memory,input){
    let [${parameters.join(',')}]=input;
    const scalarArray568=Array(18).fill(undefined),scalarArray728=Array(18).fill(undefined);
    scalarArray728[0]=input[18];scalarArray728[6]=input[19];scalarArray568[6]=input[20];
    const scalarArrayF64Store=value=>fpScalarStoreF64(typeof value==='number'?fpLoad(value):value===undefined||value instanceof Float80?value:cFloat(value));
    const scalarArrayF64Read=value=>{value=fpScalarRead(value);return value instanceof Float80?value.toNumber():value;};
    const reads=[],r64=address=>{reads.push(address);return fpLoad(memory.readF64(address));};
    let iVar16=77,iVar24=88,pc=208,error;
    try{for(;;){switch(pc){${rows}
      case 171:break;
      default:throw new Error('Unexpected slab successor');
    }break;}}
    catch(caught){error={name:caught.name,message:caught.message};}
    return {arrays:[scalarArray568,scalarArray728],scale:scalarStack264,iVar16,iVar24,error,reads};
  };`)(...Object.values(bindings));
}
const before=compile(originalRows),after=compile(actualRows);

function memory(){
  const value=new AddressSpaceMemory(0x2000,0x4cc000);
  for(const [address,coefficient] of constants)value.writeF64(address,coefficient);
  return value;
}
function compare(args,{word=0x027f,configure,checkReads=false}={}){
  return withX87ControlWord(word,()=>{
    const original=memory(),candidate=memory(),events=[[],[]];
    const memories=[original,candidate].map((value,index)=>configure?.(value,events[index])??value);
    const expected=before(memories[0],args),actual=after(memories[1],args);
    if(checkReads)assert.deepEqual(actual.reads,expected.reads,'fallback keeps the original F64 load/error order');
    delete expected.reads;delete actual.reads;
    assert.deepEqual(actual,expected,'both partial arrays, scalar and induction locals survive the same failure');
    assert.deepEqual(events[1],events[0],'custom memory observes only the complete original path');
    assert.deepEqual(candidate.bytes,original.bytes,'the speculative kernel does not write memory');
    return {expected,original,candidate};
  });
}

test('the actual integrated case208 copies all certified outputs before advancing to171',()=>{
  let seed=0x4466330;
  const random=()=>{seed=(Math.imul(seed,1664525)+1013904223)>>>0;return seed/2**32;};
  for(let index=0;index<96;index++){
    const args=index<4?input.map((_value,position)=>position%2===index%2?-0:0)
      :input.map(value=>Math.sign(value)*(random()+.125)*2**(Math.floor(random()*31)-15));
    withX87ControlWord(0x027f,()=>assert.ok(tryWaterNumberSlab(memory(),...args)));
    const {expected}=compare(args);
    assert.equal(expected.error,undefined);assert.equal(expected.iVar16,0);assert.equal(expected.iVar24,0);
  }
});

test('unsupported operands and late invalid constants preserve original partial stores and failures',()=>{
  const replacements=[undefined,NaN,Infinity,-Infinity,Number.MIN_VALUE,2**-1022,
    Float80.fromNumber(.5),new Float80(1,(1n<<63n)+3n,-2)];
  let cases=0,errors=0;
  for(let index=0;index<input.length;index++)for(const replacement of replacements){
    const args=input.slice();args[index]=replacement;
    const {expected}=compare(args);cases++;if(expected.error)errors++;
  }
  for(const [address] of constants)for(const coefficient of [NaN,Infinity,-Infinity,Number.MIN_VALUE]){
    const {expected}=compare(input,{configure:value=>{value.writeF64(address,coefficient);},checkReads:!Number.isFinite(coefficient)});
    cases++;if(expected.error)errors++;
  }
  for(const word of [0x037f,0x007f,0x027e])compare(input,{word,checkReads:true});
  const overflow=input.slice();overflow[5]=Number.MAX_VALUE;overflow[7]=Number.MAX_VALUE;
  compare(overflow,{checkReads:true});
  assert.equal(cases,184);assert.ok(errors>80,'the comparison includes failures after earlier array writes');
});

test('custom methods, Proxy access and throwing getters preserve memory-read and error ordering',()=>{
  const originalRead=AddressSpaceMemory.prototype.readF64;
  for(const stop of [0,1,3,7,12])compare(input,{checkReads:true,configure:(value,events)=>{
    let calls=0;
    value.readF64=function(address){
      events.push(['read',address]);
      if(++calls===stop)throw new Error(`original read${stop}`);
      return originalRead.call(this,address);
    };
  }});
  for(const stop of [0,1,4,11])compare(input,{checkReads:true,configure:(value,events)=>{
    let calls=0;
    Object.defineProperty(value,'readF64',{get(){
      events.push(['getter']);
      if(++calls===stop)throw new Error(`original getter${stop}`);
      return originalRead;
    }});
  }});
  compare(input,{checkReads:true,configure:(value,events)=>new Proxy(value,{get(target,key,receiver){
    events.push(['get',String(key)]);return Reflect.get(target,key,receiver);
  }})});
});
