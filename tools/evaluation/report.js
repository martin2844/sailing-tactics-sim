import {writeFile} from 'node:fs/promises';
import {join} from 'node:path';

const escape=value=>String(value??'').replace(/[&<>"']/g,c=>({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'}[c]));
const number=value=>Number.isFinite(value)?value.toFixed(2):'—';

export async function writeReport(directory,report){
  await writeFile(join(directory,'report.json'),JSON.stringify(report,null,2)+'\n');
  const rows=report.runs.map(run=>{
    const s=run.summary??{};
    return `<tr><td>${escape(run.scenario)}</td><td>${escape(run.edition)}</td><td>${run.repeat}</td>
      <td>${s.valid?'valid':'INVALID'}</td><td>${number(s.paintDuration?.p95)}</td><td>${number(s.contentInterval?.p95)}</td>
      <td>${number(s.contentInterval?.p99)}</td><td>${number(s.sampledContentFramesPerSecond)}</td>
      <td>${number(s.simulationSecondsPerWallSecond)}</td><td>${number(run.inputLatency?.p95)}</td>
      <td><a href="${escape(run.rawPath)}">raw</a></td></tr>`;
  }).join('');
  const charts=report.runs.map(run=>{
    const samples=run.chart??[],maximum=Math.max(50,...samples);
    const points=samples.map((v,i)=>`${(i/Math.max(1,samples.length-1)*900).toFixed(1)},${(150-v/maximum*140).toFixed(1)}`).join(' ');
    return `<details><summary>${escape(run.scenario)} · ${escape(run.edition)} · repeat ${run.repeat}</summary>
      <p>Paint work in milliseconds, by frame. Chart maximum ${number(maximum)} ms.</p>
      <svg viewBox="0 0 900 160" role="img" aria-label="Paint duration per frame"><line x1="0" y1="150" x2="900" y2="150" stroke="#adb7c5"/><polyline points="${points}" fill="none" stroke="#2563eb" stroke-width="1.5"/></svg></details>`;
  }).join('');
  const comparisons=(report.comparison?.groups??[]).flatMap(group=>group.metrics.map(metric=>
    `<tr><td>${escape(group.scenario)}</td><td>${escape(metric.metric)}</td><td>${number(metric.baseline.median)}</td><td>${number(metric.candidate.median)}</td><td>${number(metric.ratio)}×</td><td>${escape(metric.verdict)}${metric.provisional?' · variable repeats':''}</td></tr>`)).join('');
  const html=`<!doctype html><html lang="en"><meta charset="utf-8"><meta name="viewport" content="width=device-width">
  <title>Sailing simulator evaluation</title><style>body{font:16px/1.5 system-ui,sans-serif;max-width:1400px;margin:40px auto;padding:0 24px;color:#182735;background:#f6f8fa}h1{font-size:32px}table{border-collapse:collapse;width:100%;font-variant-numeric:tabular-nums;background:white}th,td{padding:8px 10px;border-bottom:1px solid #d9e0e7;text-align:left}th{font-size:12px}pre{white-space:pre-wrap;overflow-wrap:anywhere;background:#e9eef3;padding:16px}details{margin:12px 0}summary{cursor:pointer;font-weight:600}svg{width:100%;background:white}.scroll{overflow:auto}a{color:#1757b3}.status{font-size:22px;font-weight:650}</style>
  <h1>Sailing simulator evaluation</h1><p class="status">${escape(report.status)}</p>
  <p>${escape(report.startedAt)} · source ${escape(report.source?.commit?.slice(0,12))} · ${escape(report.mode)} · <a href="report.json">JSON report</a></p>
  <p>Timing runs use a visible browser and the desktop GPU. Completed canvas frames observed at requestAnimationFrame are a response proxy; physical monitor presentation is not measured. Default workloads differ between editions. Profiled runs are excluded from timing comparisons.</p>
  ${report.findings?.length?`<h2>Findings</h2><ul>${report.findings.map(finding=>`<li>${escape(finding)}</li>`).join('')}</ul>`:''}
  <h2>Checks and remaining coverage</h2><pre>${escape(JSON.stringify({checks:report.checks,coverage:report.coverage,failures:report.failures},null,2))}</pre>
  <h2>Measurements</h2><p>Durations and response are milliseconds. FPS counts distinct completed canvas frames seen by the observer; simulation rate is simulated seconds per wall second.</p>
  <div class="scroll"><table><thead><tr><th>Scenario</th><th>Edition</th><th>Repeat</th><th>Validity</th><th>Paint p95</th><th>Content interval p95</th><th>Content interval p99</th><th>Content FPS</th><th>Simulation rate</th><th>Input response p95</th><th>Evidence</th></tr></thead><tbody>${rows}</tbody></table></div>
  <h2>Comparison against 2002</h2><p>Median of the per-run tail measurements. Target ratio ≤1.10×; lower is better. Variable repeats have a range larger than 20% of their median.</p>
  <div class="scroll"><table><thead><tr><th>Scenario</th><th>Metric</th><th>2002 (ms)</th><th>2010 (ms)</th><th>Ratio</th><th>Target</th></tr></thead><tbody>${comparisons}</tbody></table></div>
  <details><summary>Comparison evidence and repeat ranges</summary><pre>${escape(JSON.stringify(report.comparison,null,2))}</pre></details>
  ${report.regression?`<h2>Comparison against previous evaluation</h2><pre>${escape(JSON.stringify(report.regression,null,2))}</pre>`:''}
  <h2>Frame traces</h2>${charts}<h2>Separate diagnostic profile</h2><pre>${escape(JSON.stringify(report.profile??'Not run',null,2))}</pre>
  ${report.additionalDiagnostics?`<h2>Additional diagnostic evidence</h2><pre>${escape(JSON.stringify(report.additionalDiagnostics,null,2))}</pre>`:''}
  <h2>Reproduction</h2><pre>${escape(JSON.stringify({command:report.command,environment:report.environment,source:report.source,configuration:report.configuration,reanalysis:report.reanalysis},null,2))}</pre></html>`;
  await writeFile(join(directory,'index.html'),html);
}
