import assert from 'node:assert/strict';
import {readFile,writeFile} from 'node:fs/promises';
import {execFileSync} from 'node:child_process';
import {createHash} from 'node:crypto';
import {fileURLToPath} from 'node:url';
import {loadPE32} from '../../../../src/runtime/memory.js';
import {withX87ControlWord} from '../../../../src/runtime/float80.js';
import {sampleVenueMetric} from '../../src/engine/spatial-metrics.js';

const root=new URL('../../../../',import.meta.url),edition=new URL('../../',import.meta.url);
const moduleUrl=new URL('src/engine/spatial-metrics.js',edition);
const oldSource=execFileSync('git',['show','a6b5a6d:versions/2010-en/src/engine/spatial-metrics.js'],{
  cwd:fileURLToPath(root),encoding:'utf8',stdio:'pipe'});
const absoluteSource=oldSource.replace(/from\s+(['"])([^'"]+)\1/g,(_,quote,path)=>`from ${quote}${new URL(path,moduleUrl).href}${quote}`);
const previous=await import(`data:text/javascript;base64,${Buffer.from(absoluteSource).toString('base64')}`);
const executable=await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe',edition));
const fixture=JSON.parse(await readFile(new URL('tests/fixtures/original-sampleVenueMetric.json',edition),'utf8'));
const baseline=Buffer.from(fixture.mutableBaseline,'hex');
const memory=loadPE32(executable),nativeRead32=memory.readI32.bind(memory),nativeRead64=memory.readF64.bind(memory);
const sha=value=>createHash('sha256').update(value).digest('hex');
const observedPaths=['src/engine/venue-metric-number.js','src/engine/spatial-metrics.js','src/render/float-values.js'];
const snapshots=await Promise.all(observedPaths.map(path=>readFile(new URL(path,edition),'utf8')));
const floatSource=await readFile(new URL('src/runtime/float80.js',root),'utf8');
let cases=0,readComparisons=0;
const run=(routine,row,kind)=>{
  memory.writeBytes(fixture.mutableBlock.address,baseline);
  for(const [field,value] of Object.entries(row.inputs??{}))memory.writeI32(fixture.integerInputs[field],value);
  for(const [field,value] of Object.entries(row.doubleInputs??{}))memory.writeF64(fixture.doubleInputs[field],value);
  for(const patch of row.patches??[])memory.writeBytes(patch.address,Buffer.from(patch.bytes,'hex'));
  const reads=[];let factorReads=0,providerReads=0;
  memory.readI32=address=>{
    reads.push(['I32',address]);
    if(kind==='throw-int'&&address===0x522cb4)throw new RangeError('injected notch read');
    return nativeRead32(address);
  };
  memory.readF64=address=>{
    reads.push(['F64',address]);
    if(kind==='changing-factor'&&address===0x4cc920)return ++factorReads%2?0.25:0.125;
    if(kind==='throw-double'&&address===0x4fb5e8)throw new TypeError('injected point scale read');
    if(kind==='zero-scale'&&address===0x4fb5e8)return -0;
    if(kind==='nonfinite-factor'&&address===0x4cc920)return Infinity;
    if(kind==='subnormal-angle'&&address===0x4fafb0)return -Number.MIN_VALUE;
    return nativeRead64(address);
  };
  const options=kind==='provider-accessor'?{get sinCosX87(){providerReads++;return undefined;}}:{};
  const before=memory.readBytes(memory.base,memory.size);
  let result,error;
  try{result=Buffer.from(routine(memory,...row.arguments,options).toBytes()).toString('hex');}
  catch(caught){error={name:caught.name,message:caught.message};}
  assert.deepEqual(memory.readBytes(memory.base,memory.size),before,'metric remains read-only');
  return {result,error,reads,providerReads};
};
for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
  for(const index of [0,29,51,113,221,447,691,1001])for(const kind of [
    'plain','changing-factor','throw-int','throw-double','zero-scale','nonfinite-factor','subnormal-angle','provider-accessor']){
    const row=fixture.cases[index],expected=run(previous.sampleVenueMetric,row,kind),actual=run(sampleVenueMetric,row,kind);
    assert.deepEqual(actual,expected,`word${word.toString(16)} row${index} ${kind}`);
    readComparisons+=expected.reads.length;cases++;
  }
});
memory.readI32=nativeRead32;memory.readF64=nativeRead64;
const sourcePins=[];
for(let index=0;index<observedPaths.length;index++){
  assert.equal(await readFile(new URL(observedPaths[index],edition),'utf8'),snapshots[index],'Source changed during proof');
  sourcePins.push({path:'versions/2010-en/'+observedPaths[index],sha256:sha(snapshots[index])});
}
assert.equal(await readFile(new URL('src/runtime/float80.js',root),'utf8'),floatSource,'Float source changed during proof');
sourcePins.push({path:'src/runtime/float80.js',sha256:sha(floatSource)});
const report={format:1,checkedAt:new Date().toISOString(),findings:[],cases,orderedReadComparisons:readComparisons,
  baseline:{commit:'a6b5a6d',path:'versions/2010-en/src/engine/spatial-metrics.js',sha256:sha(oldSource)},
  scope:'Independent exact-image/exception/read-order comparisons against the untouched prior JavaScript routine at PC24/53/64. Stateful mutable coefficients, thrown integer/F64 reads, zero divisors, nonfinite factors, subnormal angles and provider accessors supplement the native fixture suite.',
  sourcePins};
await writeFile(new URL('analysis/browser-performance/venue-metric-number-review.json',edition),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({cases,orderedReadComparisons:readComparisons,findings:[]}));
