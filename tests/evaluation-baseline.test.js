import test from 'node:test';
import assert from 'node:assert/strict';
import {summarizeRun} from '../tools/evaluation/metrics.js';
import {validateBaselineReport} from '../tools/evaluation/baseline.js';

function completeReport(){
  const frames=30,summary=summarizeRun({
    samples:Array.from({length:frames},(_,i)=>({frame:100+i,start:100+i*20,duration:5,
      time:i/10,dt:.1,speed:10,autoSlow:0,error:null})),
    presentation:Array.from({length:frames},(_,i)=>({frame:100+i,timestamp:105+i*20,sampledAt:106+i*20,time:i/10})),
    expected:{frames,speed:10,dt:.1,autoSlow:0},controlled:true,
  });
  const report={format:1,status:'evaluation complete; measured smoothness targets not met',
    source:{runtimeSha256:'a'.repeat(64),finalRuntimeSha256:'a'.repeat(64),
      harnessSha256:'b'.repeat(64),finalHarnessSha256:'b'.repeat(64)},
    checks:[{name:'correctness',passed:true}],failures:[],
    configuration:{mode:'quick',frames,repeats:2,scenarios:[{id:'controlled',editions:['2002','2010']}]},
    comparison:{verdict:'not_met'},runs:[]};
  for(const edition of ['2002','2010'])for(const repeat of [1,2])report.runs.push({
    edition,repeat,scenario:'controlled',validation:{passed:true,failures:[]},summary:structuredClone(summary),
    inputLatency:{kind:'trusted input to changed completed canvas observed at rAF',
      count:12,mean:150,p50:150,p95:150,p99:150,max:150},
  });
  return report;
}

function declines(mutate,pattern){
  const report=completeReport();mutate(report);
  assert.throws(()=>validateBaselineReport(report),pattern);
}

test('complete performance misses and diagnostic reports remain valid without mutation',()=>{
  const report=completeReport(),before=structuredClone(report);
  assert.strictEqual(validateBaselineReport(report),report);
  assert.deepEqual(report,before);
  report.configuration.diagnostic=true;
  report.status='diagnostic only: evaluation complete; measured targets not met; no acceptance claim';
  assert.strictEqual(validateBaselineReport(report),report);
});

test('initial and final runtime and harness pins must be valid and identical',()=>{
  for(const field of ['runtimeSha256','harnessSha256']){
    declines(r=>{delete r.source[field];},/source pin/);
    declines(r=>{r.source[field]='not a hash';},/source pin/);
  }
  for(const field of ['finalRuntimeSha256','finalHarnessSha256']){
    declines(r=>{delete r.source[field];},/source pin/);
    declines(r=>{r.source[field]='c'.repeat(64);},/source pin/);
  }
});

test('failed checks and incomplete or invalid report outcomes cannot become baselines',()=>{
  declines(r=>{r.checks=[];},/correctness/);
  for(const value of [false,1,'true',undefined])declines(r=>{r.checks[0].passed=value;},/correctness/);
  declines(r=>{r.failures=['input probe failed'];},/collection failures/);
  declines(r=>{r.status='evaluation incomplete';},/did not finish/);
  declines(r=>{r.comparison.verdict='invalid';},/comparison is invalid/);
});

test('all planned scenario edition repeat identities must occur exactly once',()=>{
  declines(r=>{r.runs.pop();},/incomplete/);
  declines(r=>{r.runs.push(structuredClone(r.runs[0]));},/extra observations/);
  declines(r=>{r.runs[3]=structuredClone(r.runs[0]);},/duplicated/);
  for(const [field,value]of [['repeat',3],['repeat','2'],['edition','2008'],['scenario','unplanned']])
    declines(r=>{r.runs[0][field]=value;},/unplanned/);
  declines(r=>{r.configuration.scenarios.push(structuredClone(r.configuration.scenarios[0]));},/scenario identity/);
  declines(r=>{r.configuration.scenarios[0].editions=['2010','2010'];},/planned editions/);
  declines(r=>{r.configuration.repeats=Number.MAX_SAFE_INTEGER;},/planned run count/);
});

test('paint summaries cannot hide failed input or run validation',()=>{
  declines(r=>{r.runs[1].validation.passed=false;},/run validation failed/);
  declines(r=>{r.runs[1].validation.failures=['camera timeout'];},/run validation failed/);
  declines(r=>{delete r.runs[1].validation;},/run validation failed/);
  declines(r=>{delete r.runs[1].inputLatency;},/twelve/);
  declines(r=>{r.runs[1].inputLatency.count=11;},/twelve/);
  declines(r=>{r.runs[1].inputLatency.p95=NaN;},/timing evidence/);
});

test('summary validity includes complete samples and finite metric evidence',()=>{
  declines(r=>{r.runs[0].summary.valid=1;},/run summary/);
  declines(r=>{r.runs[0].summary.expected.frames=29;},/frame count/);
  declines(r=>{r.runs[0].summary.sampleCount=29;},/timing evidence/);
  declines(r=>{r.runs[0].summary.invariants.errors.push({code:'runtime_error'});},/timing evidence/);
  declines(r=>{r.runs[0].summary.contentInterval.p99=Infinity;},/timing evidence/);
});
