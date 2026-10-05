import test from 'node:test';
import assert from 'node:assert/strict';
import {spawnSync} from 'node:child_process';
import {createHash} from 'node:crypto';
import {mkdtemp,mkdir,readFile,writeFile,readdir,rm} from 'node:fs/promises';
import {tmpdir} from 'node:os';
import {join,resolve} from 'node:path';
import {fileURLToPath} from 'node:url';

const root=fileURLToPath(new URL('../',import.meta.url));
const cli=join(root,'tools/evaluation/reanalyze.js');
const digest=bytes=>createHash('sha256').update(bytes).digest('hex');

function rawRun(edition){
  const samples=[0,1,2,3].map(index=>({frame:100+index,start:10+index*20,duration:4,
    time:2+index*.1,dt:.1,speed:10,autoSlow:0,error:null}));
  return {edition,scenario:{id:'matched',controlled:true},requested:{frames:4,warmup:2},
    expected:{frames:4,speed:10,dt:.1,autoSlow:0},samples,
    presentation:{samples:samples.map(row=>({frame:row.frame,time:row.time,
      timestamp:row.start+4,sampledAt:row.start+5}))},validation:{passed:true,failures:[]},
    inputLatency:{kind:'trusted input to changed completed canvas observed at rAF',
      count:12,mean:15,p50:15,p95:15,p99:15,max:15},
    metadata:{headless:false,gpu:true,gpuValidation:{passed:true},
      layoutViewportOverride:{width:1280,height:1050,deviceScaleFactor:1,mobile:false},
      environment:{devicePixelRatio:1,viewport:{width:1280,height:1050,outerWidth:1280,outerHeight:1050}},
      launch:{requested:{headless:false,gpu:true,width:1280,height:1050},
        version:{product:'Chrome/140',revision:'revision',jsVersion:'14',protocolVersion:'1.3'},
        systemInfo:{gpu:{devices:[{vendorId:4098,deviceId:123,driverVersion:'24'}],
          auxAttributes:{glRenderer:'ANGLE AMD'},featureStatus:{'2d_canvas':'enabled',
            gpu_compositing:'enabled',rasterization:'enabled'}}},
        window:{windowId:1,bounds:{width:1280,height:1050}}}},
    actual:{canvas:{width:1024,height:edition==='2002'?730:723,cssWidth:1028,
      cssHeight:edition==='2002'?732.84375:725.8125},dimensions:{width:1024,height:768,bitsPixel:24}},
    moduleSources:[{url:`http://127.0.0.1:8765/${edition}/play.js`,bytes:100,
      sha256:(edition==='2002'?'a':'b').repeat(64)}]};
}

async function fixture(t){
  const directory=await mkdtemp(join(tmpdir(),'tact-reanalysis-test-'));
  t.after(()=>rm(directory,{recursive:true,force:true}));
  const original=join(directory,'original');await mkdir(original);
  const report={format:1,startedAt:'2026-10-05T00:00:00Z',mode:'quick',status:'evaluation incomplete',
    source:{commit:'12345678',runtimeSha256:'c'.repeat(64),finalRuntimeSha256:'c'.repeat(64),
      harnessSha256:'d'.repeat(64),finalHarnessSha256:'d'.repeat(64)},
    configuration:{repeats:2,frames:4,warmup:2,scenarios:[{id:'matched',editions:['2002','2010']}]},
    checks:[{name:'correctness',passed:true}],failures:['Error: Comparison is invalid; see comparison evidence'],
    coverage:{physicalDisplayLatency:'not measured'},runs:[]};
  for(const edition of ['2002','2010'])for(const repeat of [1,2]){
    const rawPath=`${edition}-${repeat}/run.json`;await mkdir(join(original,`${edition}-${repeat}`));
    await writeFile(join(original,rawPath),JSON.stringify(rawRun(edition),null,2)+'\n');
    // Reanalysis must read the raw measurements rather than trust stale summaries.
    report.runs.push({edition,scenario:'matched',repeat,rawPath,summary:{valid:false},chart:[]});
  }
  const reportPath=join(original,'report.json');
  await writeFile(reportPath,JSON.stringify(report,null,2)+'\n');
  await writeFile(join(original,'index.html'),'Original report, preserved byte for byte.\n');
  await writeFile(join(original,'attachment.bin'),Buffer.from([0,255,1,128]));
  return {directory,original,reportPath,report};
}
async function fileHashes(directory){
  const values={};
  async function visit(relative=''){
    for(const entry of await readdir(join(directory,relative),{withFileTypes:true})){
      const path=join(relative,entry.name);
      if(entry.isDirectory())await visit(path);else values[path]=digest(await readFile(join(directory,path)));
    }
  }
  await visit();return values;
}
const invoke=reportPath=>spawnSync(process.execPath,[cli,reportPath],{cwd:root,encoding:'utf8',timeout:10000});
async function derivedDirectory(f){
  const entries=await readdir(f.directory);
  const derived=entries.filter(name=>name.startsWith('original-reanalysis-'));
  assert.equal(derived.length,1);return join(f.directory,derived[0]);
}

test('reanalysis recomputes complete raw evidence, preserves originals and pins the derived analysis',async t=>{
  const f=await fixture(t),before=await fileHashes(f.original),originalBytes=await readFile(f.reportPath);
  const result=invoke(f.reportPath);
  assert.equal(result.status,0,result.stderr);assert.match(result.stdout,/Reanalyzed report:/);
  assert.deepEqual(await fileHashes(f.original),before);
  const directory=await derivedDirectory(f),derived=JSON.parse(await readFile(join(directory,'report.json'),'utf8'));
  assert.equal(derived.comparison.verdict,'met');assert.equal(derived.comparison.context.valid,true);
  assert.equal(derived.comparison.context.surfaceDifferences.length,1);
  assert.ok(derived.runs.every(row=>row.summary.valid&&row.summary.sampleCount===4));
  assert.deepEqual(derived.failures,[]);
  assert.equal(derived.reanalysis.originalReportSha256,digest(originalBytes));
  assert.equal(resolve(directory,derived.reanalysis.originalReport),f.reportPath);
  assert.equal(derived.reanalysis.metricsSha256,digest(await readFile(join(root,'tools/evaluation/metrics.js'))));
  assert.equal(derived.reanalysis.runnerSha256,digest(await readFile(cli)));
  assert.deepEqual(JSON.parse(await readFile(join(directory,'reanalysis.json'),'utf8')),derived.reanalysis);
  const copied=await fileHashes(directory);
  for(const [path,hash] of Object.entries(before))if(path!=='report.json'&&path!=='index.html')assert.equal(copied[path],hash,path);
  assert.match(await readFile(join(directory,'index.html'),'utf8'),/physical monitor presentation is not measured/);
});

test('incomplete and changed-source collections are rejected before creating derived evidence',async t=>{
  for(const [name,mutate,message] of [
    ['missing run',report=>report.runs.pop(),/Incomplete collection/],
    ['duplicate run',report=>{report.runs[3]={...report.runs[2]};},/Duplicate run identity/],
    ['unplanned repeat',report=>{report.runs[0].repeat=99;},/Unplanned run identity/],
    ['zero repeat',report=>{report.runs[0].repeat=0;},/Unplanned run identity/],
    ['noninteger repeat',report=>{report.runs[0].repeat=1.5;},/Unplanned run identity/],
    ['string repeat',report=>{report.runs[0].repeat='1';},/Unplanned run identity/],
    ['unplanned scenario',report=>{report.runs[0].scenario='unplanned';},/Unplanned run identity/],
    ['unplanned edition',report=>{report.runs[0].edition='2008';},/Unplanned run identity/],
    ['reused raw observations',report=>{report.runs[3].rawPath=report.runs[2].rawPath;},/Duplicate raw observations/],
    ['aliased raw observations',report=>{report.runs[3].rawPath='2010-2/../2010-1/run.json';},/Duplicate raw observations/],
    ['changed runtime',report=>{report.source.finalRuntimeSha256='e'.repeat(64);},/Runtime changed/],
    ['missing final runtime',report=>{delete report.source.finalRuntimeSha256;},/Runtime changed/],
    ['matching malformed runtime pins',report=>{report.source.runtimeSha256=report.source.finalRuntimeSha256='not-a-hash';},/Runtime changed/],
    ['matching nonstring runtime pins',report=>{report.source.runtimeSha256=report.source.finalRuntimeSha256=1;},/Runtime changed/],
    ['changed harness',report=>{report.source.finalHarnessSha256='e'.repeat(64);},/Collection harness changed/],
    ['matching malformed harness pins',report=>{report.source.harnessSha256=report.source.finalHarnessSha256='not-a-hash';},/Collection harness changed/],
    ['failed correctness',report=>{report.checks[0].passed=false;},/Correctness checks did not all pass/],
    ['nonboolean passed flag',report=>{report.checks[0].passed='false';},/Correctness checks did not all pass/],
    ['runtime failure',report=>{report.failures=['RangeError: rendering stopped'];},/collection or runtime failure/],
  ])await t.test(name,async child=>{
    const f=await fixture(child);mutate(f.report);await writeFile(f.reportPath,JSON.stringify(f.report)+'\n');
    const before=await fileHashes(f.original),result=invoke(f.reportPath);
    assert.equal(result.status,1,result.stdout);assert.match(result.stderr,message);
    assert.deepEqual(await fileHashes(f.original),before);
    assert.deepEqual(await readdir(f.directory),['original']);
  });
});

test('failed raw validation and short raw observations cannot be rescued by a compact report',async t=>{
  for(const [name,mutate,message] of [
    ['validation flag false',raw=>{raw.validation.passed=false;},/A raw run failed validation/],
    ['missing validation flag',raw=>{delete raw.validation.passed;},/A raw run failed validation/],
    ['passed flag with recorded failures',raw=>{raw.validation.failures=['settings drift'];},/raw run failed validation/],
    ['short samples',raw=>raw.samples.pop(),/short_sample/],
    ['incomparable input latency',raw=>{raw.inputLatency.kind='different response boundary';},/incomparable input-latency/],
  ])await t.test(name,async child=>{
    const f=await fixture(child),rawPath=join(f.original,f.report.runs[0].rawPath);
    const raw=JSON.parse(await readFile(rawPath,'utf8'));mutate(raw);await writeFile(rawPath,JSON.stringify(raw)+'\n');
    const before=await fileHashes(f.original),result=invoke(f.reportPath);
    assert.equal(result.status,1,result.stdout);assert.match(result.stderr,message);
    assert.deepEqual(await fileHashes(f.original),before);
    assert.deepEqual(await readdir(f.directory),['original']);
  });
});

test('the requested frame budget cannot be reduced by editing the raw expected count',async t=>{
  const f=await fixture(t);
  for(const row of f.report.runs){
    const path=join(f.original,row.rawPath),raw=JSON.parse(await readFile(path,'utf8'));
    raw.expected.frames=3;raw.samples.pop();raw.presentation.samples.pop();
    await writeFile(path,JSON.stringify(raw)+'\n');
  }
  const before=await fileHashes(f.original),result=invoke(f.reportPath);
  assert.equal(result.status,1,result.stdout);
  assert.deepEqual(await fileHashes(f.original),before);
  assert.deepEqual(await readdir(f.directory),['original']);
});

test('diagnostic reanalysis never exits as an acceptance success even when measured metrics pass',async t=>{
  const f=await fixture(t);f.report.configuration.diagnostic=true;
  await writeFile(f.reportPath,JSON.stringify(f.report)+'\n');
  const result=invoke(f.reportPath);assert.equal(result.status,3,result.stderr);
  const directory=await derivedDirectory(f),derived=JSON.parse(await readFile(join(directory,'report.json'),'utf8'));
  assert.equal(derived.comparison.verdict,'met');assert.match(derived.status,/diagnostic only/);assert.match(derived.status,/no acceptance claim/);
});
