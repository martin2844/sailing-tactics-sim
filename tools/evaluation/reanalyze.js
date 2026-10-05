import assert from 'node:assert/strict';
import {createHash} from 'node:crypto';
import {readFile,writeFile,cp} from 'node:fs/promises';
import {resolve,dirname,basename,join,sep,relative} from 'node:path';
import {summarizeRun,compareRuns,compareRunContexts} from './metrics.js';
import {writeReport} from './report.js';

// Recompute summaries from complete saved observations without rerunning the
// simulator. Preserve the original report and identify the new analysis code.
const path=process.argv[2];
if(!path||process.argv.length!==3)throw new Error('Usage: node tools/evaluation/reanalyze.js REPORT.json');
const originalPath=resolve(path),originalDirectory=dirname(originalPath),bytes=await readFile(originalPath);
const report=JSON.parse(bytes),source=report.source;
const sha256=value=>typeof value==='string'&&/^[0-9a-f]{64}$/.test(value);
assert.equal(report.format,1,'Unsupported evaluation format');
assert.ok(sha256(source?.runtimeSha256)&&source.runtimeSha256===source.finalRuntimeSha256,'Runtime changed or final source check is missing');
assert.ok(sha256(source?.harnessSha256)&&source.harnessSha256===source.finalHarnessSha256,'Collection harness changed or final source check is missing');
assert.ok(report.checks.length&&report.checks.every(check=>check.passed===true),'Correctness checks did not all pass');
assert.ok(Array.isArray(report.failures)&&report.failures.every(message=>typeof message==='string'&&message.startsWith('Error: Comparison is invalid;')),'A collection or runtime failure cannot be reclassified as a timing pass');
assert.ok(!report.configuration.baseline,'A regression report must be recollected or reanalyzed with its original baseline context');
assert.ok(Number.isSafeInteger(report.configuration.repeats)&&report.configuration.repeats>=2,'Invalid planned repeat count');
assert.ok(Number.isSafeInteger(report.configuration.frames)&&report.configuration.frames>=2,'Invalid planned frame budget');
assert.ok(Number.isSafeInteger(report.configuration.warmup)&&report.configuration.warmup>=0,'Invalid planned warmup budget');
assert.ok(Array.isArray(report.configuration.scenarios)&&report.configuration.scenarios.length>0,'Missing planned scenarios');
const planned=new Map();let wanted=0;
for(const scenario of report.configuration.scenarios){
  assert.ok(typeof scenario?.id==='string'&&scenario.id.length>0&&!planned.has(scenario.id),'Invalid or duplicate planned scenario');
  assert.ok(Array.isArray(scenario.editions)&&scenario.editions.length>0
    &&new Set(scenario.editions).size===scenario.editions.length
    &&scenario.editions.every(edition=>edition==='2002'||edition==='2010'),'Invalid planned editions');
  planned.set(scenario.id,new Set(scenario.editions));
  wanted+=scenario.editions.length*report.configuration.repeats;
  assert.ok(Number.isSafeInteger(wanted),'Invalid planned run count');
}
assert.equal(report.runs.length,wanted,'Incomplete collection');
assert.equal(new Set(report.runs.map(run=>JSON.stringify([run.scenario,run.edition,run.repeat]))).size,wanted,'Duplicate run identity');
const rawPaths=new Set();
for(const row of report.runs){
  assert.ok(planned.get(row.scenario)?.has(row.edition)&&Number.isSafeInteger(row.repeat)
    &&row.repeat>=1&&row.repeat<=report.configuration.repeats,'Unplanned run identity');
  assert.ok(typeof row.rawPath==='string'&&row.rawPath.length>0,'Missing raw observations path');
  const rawPath=resolve(originalDirectory,row.rawPath);
  assert.ok(rawPath.startsWith(originalDirectory+sep),'Raw observations must belong to this evaluation');
  assert.ok(!rawPaths.has(rawPath),'Duplicate raw observations');rawPaths.add(rawPath);
  const raw=JSON.parse(await readFile(rawPath,'utf8'));
  assert.equal(raw.validation?.passed,true,'A raw run failed validation');
  assert.ok(Array.isArray(raw.validation.failures)&&raw.validation.failures.length===0,'A raw run failed validation: recorded failures');
  assert.equal(raw.edition,row.edition);assert.equal(raw.scenario.id,row.scenario);
  assert.equal(raw.requested.frames,report.configuration.frames);
  assert.equal(raw.expected.frames,report.configuration.frames,'Raw expected frame count differs from the collection budget');
  assert.equal(raw.requested.warmup,report.configuration.warmup);
  row.summary=summarizeRun({samples:raw.samples,presentation:raw.presentation?.samples??raw.presentation,
    expected:raw.expected,controlled:raw.scenario.controlled});
  assert.equal(row.summary.valid,true,JSON.stringify(row.summary.invariants.errors));
  row.inputLatency=raw.inputLatency;row.actual=raw.actual;row.metadata=raw.metadata;row.moduleSources=raw.moduleSources;
  assert.ok(row.inputLatency?.count===12,'Missing camera response measurements');
}
const pairs=report.configuration.scenarios.filter(s=>s.editions.includes('2002')&&s.editions.includes('2010')).map(s=>s.id);
const baseline=report.runs.filter(r=>r.edition==='2002'&&pairs.includes(r.scenario));
const candidate=report.runs.filter(r=>r.edition==='2010'&&pairs.includes(r.scenario));
assert.ok(pairs.length,'No cross-edition comparison to reanalyze');
report.comparison=compareRuns(baseline,candidate,{maxRatio:1.1});
assert.ok(report.comparison.groups.every(group=>group.latency.availability==='available'),
  'Missing or incomparable input-latency measurements');
report.comparison.context=compareRunContexts(baseline,candidate);
assert.ok(report.comparison.context.valid,JSON.stringify(report.comparison.context.errors));
assert.notEqual(report.comparison.verdict,'invalid');
const now=new Date().toISOString(),directory=join(dirname(originalDirectory),`${basename(originalDirectory)}-reanalysis-${now.replace(/[:.]/g,'-')}`);
await cp(originalDirectory,directory,{recursive:true,force:false,errorOnExist:true});
report.reanalysis={at:now,originalReport:relative(directory,originalPath),
  originalReportSha256:createHash('sha256').update(bytes).digest('hex'),
  metricsSha256:createHash('sha256').update(await readFile(new URL('./metrics.js',import.meta.url))).digest('hex'),
  runnerSha256:createHash('sha256').update(await readFile(new URL('./reanalyze.js',import.meta.url))).digest('hex'),
  scope:'Same complete raw observations and source-pinned collection; summaries and context classification recomputed. Original evidence remains unchanged.'};
report.failures=[];
const missed=report.comparison.verdict==='not_met',provisional=report.comparison.provisional;
report.status=`${report.configuration.diagnostic?'diagnostic only: ':''}evaluation complete; measured targets ${missed?'not met':provisional?'provisionally met':'met'}; ${report.configuration.diagnostic?'no acceptance claim':'remaining coverage still required'}`;
await writeReport(directory,report);
await writeFile(join(directory,'reanalysis.json'),JSON.stringify(report.reanalysis,null,2)+'\n');
console.log(`Reanalyzed report: ${join(directory,'index.html')}`);
process.exitCode=missed?2:provisional||report.configuration.diagnostic?3:0;
