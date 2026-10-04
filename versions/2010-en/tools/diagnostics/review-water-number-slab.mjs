// Reproduce exact water-slab acceptance/output proof from existing native
// fixtures. Add --measure for a paired full-overhead leaf benchmark; it is
// CPU throughput evidence, not browser FPS or native executable timing.
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {registerHooks} from 'node:module';
import {spawnSync} from 'node:child_process';
import {createHash} from 'node:crypto';
import {performance} from 'node:perf_hooks';
import {AddressSpaceMemory} from '../../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';
import * as typed from '../../src/render/typed-c.js';
import * as floating from '../../src/render/float-values.js';
import {tryWaterNumberSlab} from '../../src/render/water-number-slab.js';

const repo=fileURLToPath(new URL('../../../../',import.meta.url));
const edition='versions/2010-en/';
const output=path.join(repo,edition+'analysis/browser-performance/water-number-slab-review.json');
const log=path.join(repo,edition+'analysis/browser-performance/water-number-slab-review.log');
const parameters=['scalarStack4','scalarStack12','scalarStack264','scalarStack552','waterFloat272',
  'dVar1','dVar2','dVar3','dVar5','dVar6','dVar7','dVar8','dVar9','dVar10','dVar11','dVar12','dVar13','dVar14',
  'waterArray728Zero','waterArray728Six','waterArray568Six'];
const actualArguments=[...parameters.slice(0,18),'scalarArray728[0]','scalarArray728[6]','scalarArray568[6]'];
const addresses=[0x4cc5c8,0x4cc7b0,0x4cc700,0x4cc618];
const withoutKernel=body=>{
  const candidate=body.replace(/case 208: \{ const waterSlab=.*?continue;\} /,'case 208: { ');
  if(candidate===body)throw new Error('Reviewed water kernel entry not found');
  return candidate;
};
const primary=source=>{
  const match=source.match(/function originalDrawing00466330Number\([^\n]*\) \{[\s\S]*?\n\}/);
  if(!match)throw new Error('Reviewed private water function not found');
  return match[0];
};

function captureNative(){
  const report={calls:0,accepted:0,rejected:0,compared:0,inputs:[]};let pending;
  globalThis.__waterCapture=(memory,...input)=>{
    report.calls++;
    const result=tryWaterNumberSlab(memory,...input);
    if(!result){report.rejected++;pending=undefined;return;}
    report.accepted++;pending={output:Array.from(result),input};
    report.inputs.push({input,constants:addresses.map(address=>memory.readF64(address))});
  };
  globalThis.__waterFinished=(array568,array728,scale)=>{
    if(!pending)return;
    const actual=[...array568,...array728,scale];
    for(let index=0;index<37;index++)if(!Object.is(actual[index],pending.output[index])){
      throw new Error('Certified water output differs: '+JSON.stringify({index,actual:actual[index],certified:pending.output[index],input:pending.input}));
    }
    report.compared++;pending=undefined;
  };
  registerHooks({load(url,context,nextLoad){
    const result=nextLoad(url,context);
    if(!url.endsWith('/versions/2010-en/src/render/drawing-functions.js'))return result;
    const source=String(result.source),original=primary(source);
    let body=withoutKernel(original);
    body=body.replace('case 208: {','case 208: { globalThis.__waterCapture(memory,'+actualArguments.join(',')+');')
      .replace('case 171: {','case 171: { globalThis.__waterFinished(scalarArray568,scalarArray728,scalarStack264);');
    return {...result,source:source.replace(original,body)};
  }});
  process.on('exit',()=>{
    if(report.calls)fs.writeFileSync(process.env.TACT_WATER_CAPTURE_OUTPUT,JSON.stringify(report));
  });
}

function measureLeaf(capture,source){
  const body=withoutKernel(primary(source));
  const rows=[...body.matchAll(/^    case (\d+): \{ (.*) \}\n/gm)]
    .filter(row=>Number(row[1])>=172&&Number(row[1])<=208).map(row=>row[0]).join('');
  const bindings={...typed,...floating,Float80};
  const original=new Function(...Object.keys(bindings),`return function(memory,scalarArray568,scalarArray728,${parameters.join(',')}){
    scalarArray728[0]=waterArray728Zero;scalarArray728[6]=waterArray728Six;scalarArray568[6]=waterArray568Six;
    const scalarArrayF64Store=value=>fpScalarStoreF64(typeof value==='number'?fpLoad(value):value===undefined||value instanceof Float80?value:cFloat(value));
    const scalarArrayF64Read=value=>{value=fpScalarRead(value);return value instanceof Float80?value.toNumber():value;};
    const r64=address=>fpLoad(memory.readF64(address));let pc=208,iVar16,iVar24;
    for(;;){switch(pc){${rows}case 171:return scalarStack264;}}
  };`)(...Object.values(bindings));
  const commits=Array.from({length:36},(_,index)=>`scalarArray${index<18?568:728}[${index%18}]=result[${index}];`).join('\n');
  const candidate=new Function('tryWaterNumberSlab',`return function(memory,scalarArray568,scalarArray728,${parameters.join(',')}){
    const result=tryWaterNumberSlab(memory,${parameters.join(',')});
    if(!result)throw new Error('Captured native slab declined');
    ${commits}return result[36];
  };`)(tryWaterNumberSlab);
  const unique=new Set(capture.inputs.map(row=>JSON.stringify(row.constants)));
  if(unique.size!==1)throw new Error('Leaf benchmark requires coefficient-state partition');
  const memory=new AddressSpaceMemory(0x2000,0x4cc000),a568=Array(18).fill(0),a728=Array(18).fill(0);
  for(let index=0;index<4;index++)memory.writeF64(addresses[index],capture.inputs[0].constants[index]);
  const run=new Function('performance',`return function(fn,memory,a568,a728,inputs,repeat){
    let checksum=0;const start=performance.now();
    for(let iteration=0;iteration<repeat;iteration++)for(const record of inputs){const a=record.input;
      checksum+=fn(memory,a568,a728,${parameters.map((_,index)=>'a['+index+']').join(',')});
    }return {ms:performance.now()-start,checksum};
  };`)(performance);
  return withX87ControlWord(0x027f,()=>{
    for(let pass=0;pass<3;pass++){run(original,memory,a568,a728,capture.inputs,1);run(candidate,memory,a568,a728,capture.inputs,1);}
    const rounds=[];
    for(let index=0;index<7;index++){
      const first=index%2?candidate:original,second=index%2?original:candidate;
      const a=run(first,memory,a568,a728,capture.inputs,3),b=run(second,memory,a568,a728,capture.inputs,3);
      if(a.checksum!==b.checksum)throw new Error('Leaf checksum differs');
      rounds.push(index%2?{originalMs:b.ms,candidateMs:a.ms}:{originalMs:a.ms,candidateMs:b.ms});
    }
    const median=key=>rounds.map(row=>row[key]).sort((a,b)=>a-b)[3];
    const originalMedianMs=median('originalMs'),candidateMedianMs=median('candidateMs');
    return {scope:'Node leaf CPU only; includes domain guards,21 caller inputs and37 owned-array copies. No browser FPS claim.',
      callsPerRound:3*capture.inputs.length,rounds,originalMedianMs,candidateMedianMs,speedup:originalMedianMs/candidateMedianMs};
  });
}

if(process.env.TACT_WATER_CAPTURE_OUTPUT){
  captureNative();
}else{
  const temporary=fs.mkdtempSync(path.join(os.tmpdir(),'tact-water-slab-')),capturePath=path.join(temporary,'native-inputs.json');
  const command=['--import',fileURLToPath(import.meta.url),'--test','--test-reporter=tap',edition+'tests/retained-speed-ten-frames.test.js'];
  const result=spawnSync(process.execPath,command,{cwd:repo,encoding:'utf8',maxBuffer:20*1024*1024,
    env:{...process.env,TACT_WATER_CAPTURE_OUTPUT:capturePath}});
  fs.writeFileSync(log,result.stdout+result.stderr);
  if(result.status!==0)throw new Error('Native water proof failed; see '+log);
  const capture=JSON.parse(fs.readFileSync(capturePath,'utf8'));
  if(capture.accepted!==capture.compared)throw new Error('Accepted slabs were not all compared');
  const paths=['src/runtime/memory.js','src/runtime/float80.js',...['src/render/drawing-functions.js','src/render/water-number-slab.js',
    'src/render/water-number-domain.js','src/render/float-values.js','src/render/typed-c.js','src/render/scalar-stack.js',
    'tools/water_number_slab.py','tools/cache_water_float_loads.py','tools/floating_drawing.py','tools/translate_drawing_closure.py',
    'tools/diagnostics/review-water-number-slab.mjs','runtime/Tactics2010EnglishPreserved.exe',
    'tests/fixtures/original-retained-speed-ten-frames.json','tests/fixtures/original-retained-speed-ten-long-frames.json'].map(file=>edition+file)];
  const sourceSha256=Object.fromEntries(paths.map(file=>[file,createHash('sha256').update(fs.readFileSync(path.join(repo,file))).digest('hex')]));
  const drawing=fs.readFileSync(path.join(repo,edition+'src/render/drawing-functions.js'),'utf8');
  const receipt={checkedAt:new Date().toISOString(),scope:'Speculative water arithmetic acceptance and exact binary64-output equivalence against the preserved original Number case chain during native190 replay.',
    command:'node '+edition+'tools/diagnostics/review-water-number-slab.mjs'+(process.argv.includes('--measure')?' --measure':''),
    native:{tests:Number(result.stdout.match(/^# tests (\d+)$/m)?.[1]),failures:0},
    corpus:{calls:capture.calls,accepted:capture.accepted,rejected:capture.rejected,compared:capture.compared,outputsPerAcceptedCall:37},
    sourceSha256,temporaryNativeInputs:capturePath};
  if(process.argv.includes('--measure'))receipt.leafTiming=measureLeaf(capture,drawing);
  fs.writeFileSync(output,JSON.stringify(receipt,null,2)+'\n');
  console.log(JSON.stringify({report:output,corpus:receipt.corpus,leafTiming:receipt.leafTiming}));
}
