/** Recheck the complete 2002 player and preserve scoped, reproducible status. */
import assert from 'node:assert/strict';
import { createHash } from 'node:crypto';
import { createWriteStream,constants } from 'node:fs';
import { access,readFile,writeFile } from 'node:fs/promises';
import { finished } from 'node:stream/promises';
import { spawn,spawnSync } from 'node:child_process';
import { dirname,resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { readReferenceSummary } from './read-reference-summary.js';

const root=resolve(dirname(fileURLToPath(import.meta.url)),'..');
const originalHash='881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea';
const json=async path=>JSON.parse(await readFile(resolve(root,path),'utf8'));
const hash=bytes=>createHash('sha256').update(bytes).digest('hex');
assert.equal(hash(await readFile(resolve(root,'original/Tact02Demo.exe'))),originalHash);
const localPython=resolve(root,'tools/python-runtime/bin/python3');
const python=process.env.TACT_PYTHON||await access(localPython,constants.X_OK).then(()=>localPython,()=> 'python3');
for(const [name,args] of [
  ['Decompilation',['tools/verify_decompilation.py']],
  ['Resource integrity',['tools/extract_resources.py','--verify']],
  ['Resource decoding',['tests/test_resources.py','ResourcePreservationTests','StringResourcePaddingTests']],
]){
  const result=spawnSync(python,args,{cwd:root,encoding:'utf8',maxBuffer:8*1024*1024});
  if(result.error||result.status!==0)throw new Error(`${name}: ${result.error?.message??result.stdout+result.stderr}`);
  console.log(`${name}: passed`);
}

const logPath=resolve(root,'analysis/validation-2002-full.log'),log=createWriteStream(logPath);
let tail='';
const exitCode=await new Promise((resolveRun,reject)=>{
  const child=spawn(process.execPath,['tools/test-2002.js','--test-reporter=tap'],{cwd:root,stdio:['ignore','pipe','pipe']});
  const collect=bytes=>{log.write(bytes);tail=(tail+bytes.toString()).slice(-128*1024);};
  child.stdout.on('data',collect);child.stderr.on('data',collect);child.on('error',reject);child.on('close',resolveRun);
});
log.end();await finished(log);
if(exitCode!==0)throw new Error('2002 tests failed; see analysis/validation-2002-full.log');
const passedTests=Number(tail.match(/^# pass (\d+)$/m)?.[1]);
assert.ok(passedTests>0,'test runner must report its complete test count');assert.match(tail,/^# fail 0$/m);
console.log(`2002 tests: ${passedTests} passed`);

const [summary,coverage,manifest,index,startup]=await Promise.all([
  json('decompiled/summary.json'),json('analysis/decompilation-coverage.json'),json('assets/manifest.json'),
  json('analysis/native-reference-index.json'),json('analysis/startup-precision.json'),
]);
for(const row of [summary,coverage,manifest,startup])assert.equal(row.source_sha256,originalHash);
assert.equal(summary.export_complete,true);assert.equal(summary.failed,0);assert.equal(coverage.totals.unassigned_instruction_count,0);
assert.equal(startup.observed_x87_control_word,'0x027f');assert.equal(startup.target_text_unchanged_at_every_point,true);
const references=[];
for(const entry of index.reports){
  const {report,sha256}=await readReferenceSummary(resolve(root,entry.report));
  assert.equal(report.source_sha256,originalHash);assert.equal(report.x87_control_word,entry.control_word);
  for(const field of ['comparison_complete','all_fixture_cases_match','loaded_original_text_unchanged','original_file_unchanged'])assert.equal(report[field],true,`${entry.report}: ${field}`);
  assert.equal(report.process_exit_code,0);
  const count=report.function_cases??Object.values(report.groups).reduce((sum,row)=>sum+row.cases,0);
  assert.equal(count,entry.cases);
  if(report.exact_function_cases!==undefined)assert.equal(report.exact_function_cases,count);
  for(const [name,row] of Object.entries(report.groups)){assert.equal(row.cases,row.exact_matches,`${entry.report}: ${name}`);assert.equal(row.different_cases,0);}
  references.push({...entry,sha256,scope:report.scope});
}
assert.equal(references.reduce((sum,row)=>sum+row.cases,0),index.independent_original_calls);
assert.equal(new Set(index.addresses).size,index.unique_original_routine_addresses);
const report={
  target:'Posey Sailing Tactics Simulator 2002 demo',sourceSha256:originalHash,checkedAt:new Date().toISOString(),
  fullGamePlayable:true,demoOnly:true,fullGameBehaviorIdenticalVerified:false,
  player:'play.html',standaloneBuild:'dist/',
  decompilation:{functionsAndFunclets:summary.functions,failures:summary.failed,textBytes:coverage.totals.memory_bytes,
    functionBytes:coverage.totals.function_body_bytes,functionCoveragePercent:100*coverage.totals.function_body_bytes/coverage.totals.memory_bytes,
    undefinedBytes:coverage.totals.undefined_bytes,unassignedInstructions:0,scope:'Recovered pseudo-C; browser host supplies Windows services.'},
  extractedResources:manifest.resources.length,menuCommands:192,tutorialPages:39,
  translatedSubsystems:['Application and preference initialization','Course, terrain and race initialization','Wind and current',
    'Player controls and menu/dialog routing','Opponent tactics and encounters','Boat steering, sails and dynamics',
    'Position integration and race rules','Complete frame and paint ordering','Course, shore, boat and chart drawing',
    'HUD, screens and tutorials','Original audio requests and resources'],
  verification:{passed2002Tests:passedTests,testLog:'analysis/validation-2002-full.log',
    testLogSha256:hash(await readFile(logPath)),independentNativeVerificationCases:index.independent_original_calls,
    uniqueNativeOriginalRoutineAddresses:index.unique_original_routine_addresses,nativeReferenceScope:index.scope,nativeReports:references,
    applicationControlWord:'0x027f',startupReference:'analysis/startup-precision.json',
    playableBrowserReport:'analysis/play-browser-check/report.json',fontPixelCases:80},
  boundaries:['Finite recorded domains; no proof for every possible input or historical CPU',
    'Canvas shape rasterization differs from Windows GDI; measured System text is pixel-verified',
    'Browser audio scheduling and OS beep differ from Windows',
    'Browser host supplies device, window, modal and storage services; no full Windows MFC lifetime claim',
    'Shoreline starts from one measured original stack context; caller histories differ',
    'Original demo notices and restrictions are retained'],
};
await writeFile(resolve(root,'analysis/port-status.json'),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({tests:passedTests,decompiled:summary.functions,nativeCases:index.independent_original_calls,
  nativeAddresses:index.unique_original_routine_addresses,fullGamePlayable:true},null,2));
