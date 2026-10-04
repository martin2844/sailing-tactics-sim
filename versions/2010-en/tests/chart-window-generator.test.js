import test from 'node:test';
import assert from 'node:assert/strict';
import {execFileSync} from 'node:child_process';
import {readFile} from 'node:fs/promises';
import {fileURLToPath} from 'node:url';
import {pythonCommand} from '../../../tools/python-command.js';
import {loadPE32} from '../../../src/runtime/memory.js';
import {PoseyRng} from '../../../src/engine/integer-core.js';
import {withX87ControlWord} from '../../../src/runtime/float80.js';
import {GdiTrace} from '../src/render/gdi.js';
import '../src/render/index.js';

const root=fileURLToPath(new URL('../../../',import.meta.url));
const python=pythonCommand;
const script=fileURLToPath(new URL('chart-window-generator.py',import.meta.url));
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const moduleUrl=new URL('../src/render/drawing-functions.js',import.meta.url);
const generated=await readFile(moduleUrl,'utf8');
let header=generated.slice(0,generated.indexOf('export function originalDrawScene('));
if(!header.includes('tryProjectChartPointOutputFast'))header+=`import {tryProjectChartPointOutputFast} from './chart-output-fast.js';\n`;
if(!header.includes('originalNumberDrawingIsCurrent'))header+=`import {originalNumberDrawingIsCurrent} from './dependencies.js';\n`;
header=header.replace(/from\s+(['"])([^'"]+)\1/g,(_,quote,path)=>`from ${quote}${new URL(path,moduleUrl).href}${quote}`);
const contract=JSON.parse(execFileSync(python,[script,'--emit-window-contract'],{cwd:root,encoding:'utf8',stdio:'pipe'}));
const importBody=body=>import(`data:text/javascript;base64,${Buffer.from(header+body.replace('function originalDrawing00468440Number(','export function originalDrawing00468440Number(')).toString('base64')}`);
const baseline=await importBody(contract.baseline),candidate=await importBody(contract.candidate);
assert.equal(contract.candidate.split('tryProjectChartPointOutputFast(').length-1,2);
const observed=await importBody('export const chartCertificates=[];\n'+
  'function observeChartPoint(...args){const result=tryProjectChartPointOutputFast(...args);chartCertificates.push({loop:args[8],accepted:result!==undefined});return result;}\n'+
  contract.candidate.replaceAll('tryProjectChartPointOutputFast(','observeChartPoint('));

function setup(memory,venue=100){
  for(const [address,value]of [[0x5364fc,0],[0x4da1f8,venue],[0x5233a8,1],[0x4fb5d4,0],
    [0x536410,0],[0x536414,0],[0x4f5494,0],[0x4fca90,234],[0x4f71c4,3]])memory.writeI32(address,value);
  for(let index=0;index<73;index++){
    memory.writeI32(0x4f1cf8+5*292+index*4,1000+index*20);
    memory.writeI32(0x4f8ee8+5*292+index*4,-400-index*10);
  }
  memory.writeI32(0x535218+5*4,1000);memory.writeI32(0x4f4b58+5*4,-400);
}
function invoke(module,memory,args){
  const dc=new GdiTrace(),rng=new PoseyRng();let error;
  try{module.originalDrawing00468440Number(memory,dc,rng,{},true,...args);}
  catch(caught){error={name:caught.name,message:caught.message};}
  return {error,events:dc.events,rng:rng.state};
}
function compare(args,{venue=100,patch,candidateModule=candidate}={}){
  const memories=[loadPE32(source),loadPE32(source)];
  for(const memory of memories){setup(memory,venue);patch?.(memory);}
  const expected=invoke(baseline,memories[0],args),actual=invoke(candidateModule,memories[1],args);
  assert.deepEqual(actual,expected);
  assert.deepEqual(Buffer.from(memories[1].bytes),Buffer.from(memories[0].bytes));
  return {expected,memories};
}

test('chart windows fail closed on changed CFG, observers and formal storage',()=>{
  execFileSync(python,[script],{cwd:root,stdio:'pipe'});
  assert.equal(contract.proof.eligible,true);
});

test('certified and declined complete chart windows preserve low-word landmark labels and GDI',()=>withX87ControlWord(0x027f,()=>{
  for(const scale of [.1,0,.125,1]){
    const {expected}=compare([0,0,512,400,scale,5,0,2,3,1]);
    assert.equal(expected.error,undefined);
    assert.ok(expected.events.length>0);
  }
}));

test('unknown floating scale fails after the same original projection stores',()=>withX87ControlWord(0x027f,()=>{
  const {expected,memories}=compare([0,0,512,400,undefined,5,0,2,3,1]);
  assert.match(expected.error?.message??'',/undefined retained local byte/);
  assert.notEqual(memories[0].readF64(0x4fbb88),0,'original chart projection has already stored distance');
}));

test('wide first-reference coordinates preserve full-I64 division in the venue102 branch',()=>withX87ControlWord(0x027f,()=>{
  const {expected,memories}=compare([0,0,0,0,0,5,0,2,3,1],{venue:102,patch:memory=>{
    memory.writeF64(0x4ccd80,2**32);memory.writeF64(0x4ccd78,2**32+1000);
  }});
  assert.equal(expected.error,undefined);
  // The loop overwrites 4f5494 as one of its output points; use that observed
  // I32 value in the original venue expression before its final narrowing.
  const pointTerm=BigInt(memories[0].readI32(0x4f5494)*19);
  const expectedLabelX=Number(BigInt.asIntN(32,((2n**32n+pointTerm)/20n)-35n));
  const prematurelyWrappedX=Number(BigInt.asIntN(32,(pointTerm/20n)-35n));
  assert.notEqual(expectedLabelX,prematurelyWrappedX);
  assert.ok(expected.events.some(event=>event.op==='textOut'&&event.x===expectedLabelX),
    'the full reference coordinate remains available to the later division and its landmark-label offset');
}));

test('last-loop certificate state preserves the later low-word label expression after mixed fallbacks',()=>withX87ControlWord(0x027f,()=>{
  for(const [scale,lastAccepted] of [[0,true],[.125,false],[.125,true]]){
    observed.chartCertificates.length=0;
    const {expected}=compare([0,0,512,400,scale,5,0,2,3,1],{candidateModule:observed,patch:memory=>{
      if(scale!==0&&lastAccepted){
        memory.writeI32(0x4f1cf8+5*292+72*4,2417);
        memory.writeI32(0x4f8ee8+5*292+72*4,-1117);
      }
    }});
    assert.equal(expected.error,undefined);
    const loop=observed.chartCertificates.filter(row=>row.loop);
    assert.equal(loop.length,73);
    assert.equal(loop.at(-1).accepted,lastAccepted);
    if(scale===0)assert.ok(loop.every(row=>row.accepted),'the high word is never materialized by a loop fallback');
    else assert.ok(loop.some(row=>row.accepted)&&loop.some(row=>!row.accepted),'both optimized and original loop windows execute');
    assert.ok(expected.events.some(event=>event.op==='textOut'&&event.text==='Fl W lighthouse'));
  }
}));
