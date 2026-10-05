import {compareRuns} from './metrics.js';

const requireEvidence=(condition,message)=>{
  if(!condition)throw new Error(`Invalid evaluation baseline: ${message}`);
};
const sha256=value=>typeof value==='string'&&/^[0-9a-f]{64}$/.test(value);
const identity=(scenario,edition,repeat)=>JSON.stringify([scenario,edition,repeat]);

/** Validate saved collection evidence without I/O or modifying the report.
 * Performance misses and diagnostic reports remain usable references; the
 * caller must separately match its diagnostic mode and collection settings.
 */
export function validateBaselineReport(report){
  requireEvidence(report?.format===1,'unsupported report format');
  for(const field of ['runtimeSha256','harnessSha256']){
    const finalField=field==='runtimeSha256'?'finalRuntimeSha256':'finalHarnessSha256';
    requireEvidence(sha256(report.source?.[field])&&report.source[field]===report.source[finalField],
      `${field} is missing, invalid, or differs from the final source pin`);
  }
  requireEvidence(Array.isArray(report.checks)&&report.checks.length>0&&report.checks.every(check=>check?.passed===true),
    'correctness checks must all have passed');
  requireEvidence(Array.isArray(report.failures)&&report.failures.length===0,'collection failures must be empty');
  requireEvidence(typeof report.status==='string'&&report.status.includes('evaluation complete;'),
    'collection did not finish');
  for(const result of [report.comparison,report.regression])if(result!==undefined&&result!==null)
    requireEvidence(['met','not_met'].includes(result.verdict),'a saved comparison is invalid');

  const configuration=report.configuration;
  requireEvidence(Number.isSafeInteger(configuration?.repeats)&&configuration.repeats>=2,
    'planned repeat count is invalid');
  requireEvidence(Number.isSafeInteger(configuration.frames)&&configuration.frames>=2,
    'planned frame count is invalid');
  requireEvidence(Array.isArray(configuration.scenarios)&&configuration.scenarios.length>0,
    'planned scenarios are missing');
  let plannedCount=0;
  const scenarios=new Map(),groups=new Map();
  for(const scenario of configuration.scenarios){
    requireEvidence(typeof scenario?.id==='string'&&scenario.id.length>0&&!scenarios.has(scenario.id),
      'planned scenario identity is missing or duplicated');
    requireEvidence(Array.isArray(scenario.editions)&&scenario.editions.length>0
      &&new Set(scenario.editions).size===scenario.editions.length
      &&scenario.editions.every(edition=>edition==='2002'||edition==='2010'),
    `planned editions are invalid for ${scenario.id}`);
    scenarios.set(scenario.id,new Set(scenario.editions));
    plannedCount+=scenario.editions.length*configuration.repeats;
    requireEvidence(Number.isSafeInteger(plannedCount),'planned run count is invalid');
  }
  requireEvidence(Array.isArray(report.runs)&&report.runs.length===plannedCount,
    'run collection is incomplete or has extra observations');
  const observed=new Set();
  for(const row of report.runs){
    const key=identity(row?.scenario,row?.edition,row?.repeat);
    requireEvidence(scenarios.get(row?.scenario)?.has(row?.edition)
      &&Number.isSafeInteger(row?.repeat)&&row.repeat>=1&&row.repeat<=configuration.repeats
      &&!observed.has(key),'run identity is unplanned or duplicated');
    observed.add(key);
    requireEvidence(row.validation?.passed===true&&Array.isArray(row.validation.failures)&&row.validation.failures.length===0,
      `run validation failed for ${key}`);
    requireEvidence(row.summary?.valid===true&&row.summary.expected?.frames===configuration.frames,
      `run summary is invalid or has a different frame count for ${key}`);
    requireEvidence(row.inputLatency?.count===12,'every run requires twelve measured input responses');
    const groupKey=identity(row.scenario,row.edition,0);
    if(!groups.has(groupKey))groups.set(groupKey,[]);
    groups.get(groupKey).push(row);
  }
  // Reuse the metric contract for summary shape, sample counts, finite timing
  // statistics and repeat settings. Comparing an arm with itself validates the
  // evidence without rejecting a legitimate performance or latency miss.
  for(const [key,rows]of groups){
    const result=compareRuns(rows,rows);
    requireEvidence(result.verdict!=='invalid',`timing evidence is invalid for ${key}: ${JSON.stringify(result.errors.length?result.errors:result.groups.flatMap(group=>group.errors))}`);
  }
  return report;
}
