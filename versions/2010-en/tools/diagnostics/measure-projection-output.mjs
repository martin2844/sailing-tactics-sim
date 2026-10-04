import assert from 'node:assert/strict';
import {createHash} from 'node:crypto';
import {readFile,writeFile} from 'node:fs/promises';
import {performance} from 'node:perf_hooks';
import {loadPE32} from '../../../../src/runtime/memory.js';
import {withX87ControlWord} from '../../../../src/runtime/float80.js';
import {tryProjectScenePointOutputFast} from '../../src/render/projection-output-fast.js';
import '../../src/render/index.js';

// A controlled leaf comparison: both virtual modules use the current Number
// compiler and helpers. The baseline removes only the certified output hook.
// Production files are never rewritten, and private exports exist only here.
const generatedUrl=new URL('../../src/render/drawing-functions.js',import.meta.url);
const generated=await readFile(generatedUrl,'utf8');
const hook='  if(tryProjectScenePointOutputFast(memory,scalarStack0,scalarStack4,scalarStack12,scalarStack20,scalarStack24,options))return;\n';
assert.equal(generated.split(hook).length,2,'one scoped output hook');
const moduleSource=(source)=>source.replace(
  'function originalDrawing0043e730Number(',
  'export function originalDrawing0043e730Number('
).replace(/^registerOriginal(?:Number)?Drawing\([^\n]+\);\n/gm,'')
  .replace(/from\s+(['"])([^'"]+)\1/g,(_,quote,target)=>`from ${quote}${new URL(target,generatedUrl).href}${quote}`);
const importSource=source=>import(`data:text/javascript;base64,${Buffer.from(moduleSource(source)).toString('base64')}`);
const baseline=await importSource(generated.replace(hook,''));
const candidate=await importSource(generated);
const executable=await readFile(new URL('../../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const memory=loadPE32(executable);
const setView=()=>{
  for(const [address,value] of [[0x4f71c4,1],[0x4fbb94,0],[0x5364c8,0],
    [0x4da148,200],[0x4f4b48,240],[0x4fe2a8,734],[0x4f40a8,512]])memory.writeI32(address,value);
  for(const [address,value] of [[0x4f6b00,0],[0x4f6c18,0],[0x5259d0,1]])memory.writeF64(address,value);
};
const outputs=()=>[Buffer.from(memory.readBytes(0x4fbb88,8)).toString('hex'),
  memory.readI32(0x535ff4),memory.readI32(0x523660),memory.readI32(0x4fed58)];
let state=0x43e730;
const random=()=>{state=(Math.imul(state,1664525)+1013904223)>>>0;return state;};
const points=Array.from({length:1000},()=>{
  const direction=(random()%22001-11000)/100*Math.PI/180,distance=50+random()%20000;
  return [Math.sin(direction)*distance,-Math.cos(direction)*distance];
});
const call=(module,point)=>module.originalDrawing0043e730Number(memory,null,null,{},true,0,...point,1,0);
const median=values=>[...values].sort((a,b)=>a-b)[Math.floor(values.length/2)];
const sha=source=>createHash('sha256').update(source).digest('hex');
const report=withX87ControlWord(0x027f,()=>{
  setView();let accepted=0;
  for(const point of points){
    const before=outputs();
    const result=tryProjectScenePointOutputFast(memory,0,...point,1,0);
    if(result!==true){assert.deepEqual(outputs(),before);continue;}
    accepted++;const expected=outputs();call(baseline,point);assert.deepEqual(outputs(),expected);
  }
  for(let iteration=0;iteration<200;iteration++){
    call(baseline,points[iteration]);call(candidate,points[iteration]);
  }
  const samples={baseline:[],candidate:[]};
  const modules={baseline,candidate};
  for(let round=0;round<7;round++)for(const name of round%2?['candidate','baseline']:['baseline','candidate']){
    const start=performance.now();for(const point of points)call(modules[name],point);
    samples[name].push(performance.now()-start);
  }
  const baselineMedian=median(samples.baseline),candidateMedian=median(samples.candidate);
  return {format:1,checkedAt:new Date().toISOString(),scope:'Controlled point kernel; current Number baseline differs only by removal of the certified output hook. This is not a browser FPS estimate.',
    setup:{camera:1,mode:1,selector:0,heading:0,model:0,points:1000,bearingDegrees:[-110,110],distance:[50,20049],seed:'0x43e730'},
    acceptance:{accepted,total:points.length,fraction:accepted/points.length,acceptedOutputImagesExact:true,declinedOutputsUnchanged:true},
    timing:{rounds:7,warmupPointsPerPath:200,samplesMs:samples,medianMs:{baseline:baselineMedian,candidate:candidateMedian},
      medianSpeedup:baselineMedian/candidateMedian,medianMicrosecondsPerPoint:{baseline:baselineMedian,candidate:candidateMedian}},
    generatedSourceSha256:sha(generated),virtualBaselineSha256:sha(generated.replace(hook,''))};
});
report.sourcePins=await Promise.all(['../../src/render/projection-output-fast.js','../../src/render/projection-fast.js',
  '../../../../src/runtime/output-interval.js'].map(async path=>({path:new URL(path,import.meta.url).pathname,
    sha256:sha(await readFile(new URL(path,import.meta.url)))})));
const reportUrl=new URL('../../analysis/browser-performance/projection-output-leaf-throughput.json',import.meta.url);
await writeFile(reportUrl,`${JSON.stringify(report,null,2)}\n`);
console.log(JSON.stringify({acceptance:report.acceptance,timing:report.timing,report:reportUrl.pathname},null,2));
