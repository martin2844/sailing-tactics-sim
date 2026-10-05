import {spawn,execFileSync} from 'node:child_process';
import {createHash} from 'node:crypto';
import {mkdir,readFile,writeFile,open,readdir} from 'node:fs/promises';
import {resolve,join,relative} from 'node:path';
import {fileURLToPath} from 'node:url';
import os from 'node:os';
import {scenarios} from './evaluation/scenarios.js';
import {runScenario} from './evaluation/run-scenario.js';
import {summarizeRun,compareRuns,compareRunContexts} from './evaluation/metrics.js';
import {measureInputResponse} from './evaluation/input-response.js';
import {writeReport} from './evaluation/report.js';
import {validateBaselineReport} from './evaluation/baseline.js';

const root=fileURLToPath(new URL('../',import.meta.url));
const options={mode:'quick',repeats:5,frames:null,warmup:60,baseUrl:'http://127.0.0.1:8765',profile:true};
for(let i=2;i<process.argv.length;i++){
  const key=process.argv[i];
  if(key==='--no-profile'){options.profile=false;continue;}
  if(key==='--diagnostic'){options.diagnostic=true;continue;}
  if(!['--mode','--repeats','--frames','--warmup','--base-url','--output','--scenarios','--baseline','--note'].includes(key))throw new Error(`Unknown option ${key}`);
  const value=process.argv[++i];if(value===undefined||value.startsWith('--'))throw new Error(`Missing value for ${key}`);
  options[{'--base-url':'baseUrl'}[key]??key.slice(2)]=value;
}
if(!['quick','release'].includes(options.mode))throw new Error('Mode must be quick or release');
for(const key of ['repeats','frames','warmup']){
  options[key]=Number(options[key]??(options.mode==='quick'?180:600));
  if(!Number.isSafeInteger(options[key])||options[key]<(key==='repeats'?2:key==='warmup'?0:30))throw new Error(`Invalid ${key}`);
}
const selected=options.scenarios?options.scenarios.split(',').map(id=>{
  const scenario=scenarios.find(s=>s.id===id);if(!scenario)throw new Error(`Unknown scenario ${id}`);return scenario;
}):scenarios.filter(s=>options.mode==='release'||s.quick);
if(new Set(selected.map(s=>s.id)).size!==selected.length)throw new Error('Duplicate scenario selection');
// Reject unusable references before launching checks or collecting new timings.
let previous,baselinePin;
if(options.baseline){
  const path=resolve(root,options.baseline),bytes=await readFile(path);
  previous=validateBaselineReport(JSON.parse(bytes));
  if(Boolean(previous.configuration.diagnostic)!==Boolean(options.diagnostic))throw new Error('Diagnostic and acceptance runs cannot form a regression comparison');
  if(previous.configuration.warmup!==options.warmup)throw new Error('Baseline uses a different warmup frame count');
  if(previous.configuration.frames!==options.frames)throw new Error('Baseline uses a different measured frame count');
  for(const scenario of selected.filter(s=>s.editions.includes('2010'))){
    if(!previous.runs.some(r=>r.edition==='2010'&&r.scenario===scenario.id))throw new Error(`Baseline is missing the 2010 scenario ${scenario.id}`);
  }
  baselinePin={path,sha256:createHash('sha256').update(bytes).digest('hex')};
}
const git=(...args)=>execFileSync('git',args,{cwd:root,encoding:'utf8'}).trim();
const commit=git('rev-parse','HEAD');
const startedAt=new Date().toISOString();
const directory=resolve(root,options.output??`versions/2010-en/analysis/evaluation/${startedAt.replace(/[:.]/g,'-')}-${commit.slice(0,8)}`);
await mkdir(directory,{recursive:true});
// Refuse to overwrite a previous evaluation or silently combine two runs.
const lock=await open(join(directory,'manifest.lock'),'wx');await lock.close();
const report={format:1,startedAt,mode:options.mode,status:'running',command:process.argv,
  source:{commit,trackedDiffSha256:createHash('sha256').update(git('diff','HEAD','--')).digest('hex')},
  environment:{node:process.version,platform:process.platform,release:os.release(),cpus:os.cpus()[0]?.model,
    logicalCpus:os.cpus().length,totalMemory:os.totalmem(),display:process.env.DISPLAY??null,waylandDisplay:process.env.WAYLAND_DISPLAY??null},
  configuration:{...options,scenarios:selected},baseline:baselinePin,checks:[],runs:[],failures:[],comparison:null,
  coverage:{throughput:'pending',inputResponse:'pending',actualCanvasParity:'pending',
    longRaceFinish:'not evaluated by the quick suite',physicalDisplayLatency:'not measured',native2010:'existing finite reference tests; no new native capture'}};
let ownedServer;
const delay=ms=>new Promise(r=>setTimeout(r,ms));
async function sourceDigest(){
  const files=[];
  async function walk(dir){for(const item of await readdir(join(root,dir),{withFileTypes:true})){
    const name=join(dir,item.name);if(item.isDirectory())await walk(name);else if(item.isFile())files.push(name);
  }}
  await walk('src');await walk('versions/2010-en/src');files.push('play.html','versions/2010-en/play.html');files.sort();
  const hash=createHash('sha256');for(const file of files){hash.update(file+'\0');hash.update(await readFile(join(root,file)));}
  return hash.digest('hex');
}
async function harnessDigest(){
  const files=(await readdir(join(root,'tools/evaluation'))).filter(name=>name.endsWith('.js')).map(name=>`tools/evaluation/${name}`);
  files.push('tools/evaluate.js','tools/browser-session.js','tools/paint-measurements.js',
    'tools/presentation-measurements.js','tools/deterministic-paint-setup.js',
    'tools/check-2010-hud-browser.js','versions/2010-en/tools/diagnostics/check-smooth-graphics-browser.mjs');
  const hash=createHash('sha256');for(const file of files.sort()){hash.update(file+'\0');hash.update(await readFile(join(root,file)));}
  return hash.digest('hex');
}
async function ensureServer(){
  const url=new URL(options.baseUrl);
  const alive=async()=>{try{return(await fetch(new URL('/play.html',url),{signal:AbortSignal.timeout(1000)})).ok;}catch{return false;}};
  if(await alive())return;
  if(!['127.0.0.1','localhost'].includes(url.hostname))throw new Error('External server unavailable');
  ownedServer=spawn(process.execPath,['tools/serve.js'],{cwd:root,env:{...process.env,TACT_HOST:url.hostname,TACT_PORT:url.port||'80'},stdio:'ignore'});
  let launchError;ownedServer.on('error',e=>{launchError=e;});
  for(let n=0;n<100;n++){if(launchError)throw launchError;if(await alive())return;await delay(100);}
  throw new Error('Local evaluation server did not start');
}
async function check(label,args,env={}){
  console.log(`Checking ${label}…`);
  const path=join(directory,`${label}.log`),file=await open(path,'w');
  const start=Date.now();let code;
  try{code=await new Promise((accept,reject)=>{
    const child=spawn(process.execPath,args,{cwd:root,env:{...process.env,...env},stdio:['ignore',file.fd,file.fd]});
    child.once('error',reject);child.once('exit',code=>accept(code));
  });}finally{await file.close();}
  report.checks.push({name:label,passed:code===0,exitCode:code,durationSeconds:(Date.now()-start)/1000,log:relative(directory,path)});
  await writeReport(directory,report);if(code!==0)throw new Error(`${label} failed; see ${path}`);
}
function compact(run,scenario,edition,repeat,rawPath){
  const expected=run.expected??{frames:options.frames};
  const summary=summarizeRun({samples:run.samples,presentation:run.presentation?.samples??run.presentation,
    expected,controlled:scenario.controlled});
  return {edition,scenario:scenario.id,repeat,controlled:scenario.controlled,expected,summary,
    inputLatency:run.inputLatency,rawPath,metadata:run.metadata,actual:run.actual,moduleSources:run.moduleSources,
    validation:run.validation,chart:run.samples?.map(s=>s.duration)??[]};
}
function profileSummary(profile){
  const nodes=new Map(profile.nodes.map(n=>[n.id,n]));const totals=new Map();
  let total=0;for(let i=0;i<(profile.samples?.length??0);i++){
    const node=nodes.get(profile.samples[i]),weight=profile.timeDeltas?.[i]??1;if(!node)continue;total+=weight;
    const f=node.callFrame,key=`${f.functionName||'(anonymous)'} @ ${f.url}:${f.lineNumber+1}`;totals.set(key,(totals.get(key)??0)+weight);
  }
  return [...totals].sort((a,b)=>b[1]-a[1]).slice(0,20).map(([frame,time])=>({frame,selfPercent:100*time/total}));
}
function compare(baseline,candidate){
  const result=compareRuns(baseline,candidate,{maxRatio:1.1});
  result.context=compareRunContexts(baseline,candidate);
  for(const group of result.groups)if(group.latency.availability!=='available')
    result.errors.push({code:'incomparable_input_latency',scenario:group.scenario,message:group.latency.reason});
  if(!result.context.valid||result.errors.length)result.verdict='invalid';
  return result;
}
try{
  report.source.runtimeSha256=await sourceDigest();report.source.harnessSha256=await harnessDigest();await ensureServer();
  await check('evaluation-tests',['--test','tests/evaluation-metrics.test.js','tests/evaluation-baseline.test.js',
    'tests/evaluation-reanalysis.test.js','tests/presentation-measurements.test.js','tests/browser-session.test.js']);
  if(options.mode==='release'){
    await check('2002-tests',['tools/test-2002.js']);await check('2010-tests',['tools/test-2010.js']);
  }
  await check('2010-hud',['tools/check-2010-hud-browser.js'],{TACT_URL:options.baseUrl,TACT_HUD_REPORT:join(directory,'hud.json')});
  await check('canvas-parity',['versions/2010-en/tools/diagnostics/check-smooth-graphics-browser.mjs'],{
    TACT_2010_URL:new URL('/versions/2010-en/play.html',options.baseUrl).href,TACT_CANVAS_REPORT_DIR:join(directory,'canvas-parity')});
  report.coverage.actualCanvasParity='passed: real Canvas exact/smooth engine trace comparison';
  // No correctness tests, parallel browsers, or CPU profiling during these runs.
  for(const scenario of selected)for(let repeat=1;repeat<=options.repeats;repeat++){
    const editions=repeat%2?scenario.editions:[...scenario.editions].reverse();
    for(const edition of editions){
      const id=`${scenario.id}-${edition}-${repeat}`,outputDir=join(directory,id);
      console.log(`Measuring ${id} (${options.frames} frames)…`);
      let run;
      try{run=await runScenario({edition,scenario,frames:options.frames,warmup:options.warmup,baseUrl:options.baseUrl,outputDir,
        afterMeasurement:measureInputResponse});}
      catch(error){
        if(error.report){
          await writeFile(join(outputDir,'run.json'),JSON.stringify(error.report,null,2)+'\n');
          report.runs.push(compact(error.report,scenario,edition,repeat,`${id}/run.json`));
        }
        throw error;
      }
      const row=compact(run,scenario,edition,repeat,`${id}/run.json`);report.runs.push(row);
      // Preserve the exact returned data even if runner's own filename changes.
      await writeFile(join(outputDir,'run.json'),JSON.stringify(run,null,2)+'\n');
      await writeReport(directory,report);
      if(!row.summary.valid||run.validation?.passed===false)throw new Error(`Invalid measured run: ${id}`);
      console.log(`  p95 work ${row.summary.paintDuration?.p95?.toFixed(1)} ms; observed FPS ${row.summary.sampledContentFramesPerSecond?.toFixed(1)}`);
    }
  }
  report.coverage.throughput=`${report.runs.length} sequential headed runs`;
  report.coverage.inputResponse='12 trusted camera clicks per run; changed completed canvas frame observed at rAF';
  const pairs=selected.filter(s=>s.editions.includes('2002')&&s.editions.includes('2010')).map(s=>s.id);
  if(pairs.length)report.comparison=compare(report.runs.filter(r=>r.edition==='2002'&&pairs.includes(r.scenario)),
    report.runs.filter(r=>r.edition==='2010'&&pairs.includes(r.scenario)));
  if(previous){
    const ids=new Set(selected.map(s=>s.id));
    report.regression=compare(previous.runs.filter(r=>r.edition==='2010'&&ids.has(r.scenario)),report.runs.filter(r=>r.edition==='2010'));
  }
  if(options.profile){
    const worst=report.runs.filter(r=>r.edition==='2010').sort((a,b)=>(b.summary.paintDuration?.p95??0)-(a.summary.paintDuration?.p95??0))[0];
    if(worst){
      const scenario=selected.find(s=>s.id===worst.scenario),outputDir=join(directory,'diagnostic-profile');
      console.log(`Profiling ${scenario.id} separately…`);
      const run=await runScenario({edition:'2010',scenario,frames:options.frames,warmup:options.warmup,baseUrl:options.baseUrl,outputDir,profile:true});
      const stages=new Map();
      for(const row of run.profile?.stages??[]){
        const value=stages.get(row.name)??{calls:0,totalMs:0};value.calls++;value.totalMs+=row.duration;stages.set(row.name,value);
      }
      report.profile={scenario:scenario.id,scope:'Diagnostic only; excluded from performance comparisons. Nested stage times overlap.',report:'diagnostic-profile/run.json',
        stageCoverage:run.profile?.stageCoverage,stages:[...stages].map(([name,value])=>({name,...value,msPerPaint:value.totalMs/options.frames})).sort((a,b)=>b.totalMs-a.totalMs)};
      await writeFile(join(outputDir,'run.json'),JSON.stringify(run,null,2)+'\n');
      const names=await readdir(outputDir),name=names.find(n=>n.endsWith('.cpuprofile'));
      if(name){report.profile.path=`diagnostic-profile/${name}`;report.profile.hottestSelfFrames=profileSummary(JSON.parse(await readFile(join(outputDir,name),'utf8')));}
    }
  }
  const finalDigest=await sourceDigest();report.source.finalRuntimeSha256=finalDigest;
  if(finalDigest!==report.source.runtimeSha256)throw new Error('Runtime source changed during evaluation; timing comparison invalid');
  report.source.finalHarnessSha256=await harnessDigest();
  if(report.source.finalHarnessSha256!==report.source.harnessSha256)throw new Error('Evaluation implementation changed during the run');
  const verdicts=[report.comparison,report.regression].filter(Boolean);
  if(verdicts.some(result=>result.verdict==='invalid'))throw new Error('Comparison is invalid; see comparison evidence');
  const targetMissed=verdicts.some(result=>result.verdict==='not_met');
  const provisional=verdicts.some(result=>result.provisional);
  report.status=targetMissed?'evaluation complete; measured smoothness targets not met'
    :provisional?'evaluation complete; targets provisionally met, variable repeats require confirmation'
    :verdicts.length?'evaluation complete; measured targets met, remaining coverage still required'
    :'evaluation complete; no reference comparison selected';
  if(targetMissed)process.exitCode=2;else if(provisional)process.exitCode=3;
  if(options.diagnostic){report.status=`diagnostic only: ${report.status}; no acceptance claim`;process.exitCode=targetMissed?2:3;}
}catch(error){report.status='evaluation incomplete';report.failures.push(error.stack??String(error));console.error(error.message??String(error));process.exitCode=1;}
finally{
  report.finishedAt=new Date().toISOString();
  try{await writeReport(directory,report);}finally{if(ownedServer)ownedServer.kill('SIGTERM');}
  console.log(`Evaluation report: ${join(directory,'index.html')}`);
}
