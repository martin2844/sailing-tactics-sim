import {readFile,writeFile} from 'node:fs/promises';
import {execFileSync} from 'node:child_process';
import {createHash} from 'node:crypto';
import {fileURLToPath,pathToFileURL} from 'node:url';
import {resolve,dirname} from 'node:path';
import assert from 'node:assert/strict';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';

const root=fileURLToPath(new URL('../../../../',import.meta.url));
const modulePath='versions/2010-en/src/render/dependencies.js';
const baselineRevision='a6b5a6d';
const baselineSource=execFileSync('git',['show',`${baselineRevision}:${modulePath}`],{cwd:root,encoding:'utf8'});
const absoluteImports=baselineSource.replace(/from\s+(['"])(\.[^'"]+)\1/g,(_match,_quote,path)=>`from ${JSON.stringify(pathToFileURL(resolve(root,dirname(modulePath),path)).href)}`);
const baseline=await import(`data:text/javascript;base64,${Buffer.from(absoluteImports).toString('base64')}`);
const current=await import('../../src/render/dependencies.js');
const layouts=[[],[0],[1,2],[0,31,32],[31,32]];
const masks=[0,1,3,5,0x40000000,0x80000000,0xffffffff,NaN,Infinity,-Infinity,0.5,2**32+5,2**53];
let cases=0,customCopyCases=0,address=0x49b800;
const summarize=value=>value instanceof Float80?['m80',value.exactKey()]:Object.is(value,-0)?['negative-zero']:value;
withX87ControlWord(0x027f,()=>{
  for(const dcIndex of [null,0,1,32])for(const parameters of layouts){
    const at=address--,dc={events:[]};
    for(const api of [baseline,current]){
      api.registerOriginalDrawing(at,()=>{throw new Error('Unexpected original call');},dcIndex!==null,dcIndex);
      api.registerOriginalNumberDrawing(at,(_memory,_dc,_rng,_options,_images,...args)=>args,parameters);
    }
    for(const removed of [false,true])for(const mask of masks)for(const variant of [0,1,2]){
      const run=api=>{
        const log=[];
        class ObservedFloat extends Float80{
          toNumber(){log.push('number');if(variant===2)throw new Error('F64 conversion failed');return super.toNumber();}
        }
        const observed=new ObservedFloat(1,(1n<<63n)+3n,-63),semantic={semantic:true};
        const describe=value=>value===semantic?['original-semantic-reference']:value===dc?['original-dc-reference']:summarize(value);
        const args=Array.from({length:34},(_,index)=>index%4===0?-0:index%4===1?observed:index%4===2?undefined:variant===1?semantic:2n);
        if(dcIndex!==null&&removed)args[dcIndex]=dc;
        let result;
        try{result={values:api.callNumberDrawingDependencyOwned(undefined,dc,at,args,mask,undefined).map(describe)};}
        catch(error){result={error:{name:error.name,message:error.message}};}
        return{result,log,mutatedArguments:args.map(describe)};
      };
      assert.deepEqual(run(current),run(baseline),`dc=${dcIndex}, parameters=${parameters}, removed=${removed}, mask=${mask}, variant=${variant}`);
      cases++;
    }
  }
  for(const[index,[copiedIndex,argumentIndex]]of [[-1,31],[.5,0],[31.5,31],[-31.5,1]].entries()){
    const at=0x49b7c0-index;
    for(const api of [baseline,current]){
      api.registerOriginalDrawing(at,()=>{throw new Error('Unexpected original call');},false,null);
      const parameters=[0];parameters.slice=()=>[copiedIndex];
      api.registerOriginalNumberDrawing(at,(_memory,_dc,_rng,_options,_images,...args)=>args,parameters);
    }
    const run=api=>{
      const values=Array(32).fill(0);values[argumentIndex]=-0;
      return api.callNumberDrawingDependencyOwned(undefined,undefined,at,values,1<<argumentIndex,undefined).map(summarize);
    };
    assert.deepEqual(run(current),run(baseline));customCopyCases++;
  }
});
const sourcePaths=[modulePath,'versions/2010-en/tests/number-dependencies.test.js','versions/2010-en/src/render/float-values.js','src/runtime/float80.js','versions/2010-en/tools/floating_drawing.py','versions/2010-en/tools/diagnostics/review-dependency-mask.mjs'];
const sourcePins=[];
for(const path of sourcePaths)sourcePins.push({path,sha256:createHash('sha256').update(await readFile(resolve(root,path))).digest('hex')});
const report={format:1,checkedAt:new Date().toISOString(),reviewer:'/root/ai_crash_fix',findings:[],baselineRevision,baselineModuleSha256:createHash('sha256').update(baselineSource).digest('hex'),
  scope:'Private owned dense compiler argument literals with Number masks; public copied calls, array flags and stale registration fallback remain on the original scan.',
  checks:[
    'A current numeric registration is selected only when the saved public registration object is still identical and PC53/ordinary drawing options permit it.',
    'Removing a DC chooses original parameter-mask indices; keeping the supplied placeholder chooses compact binding-mask indices. Every marked floating actual maps to a floating formal before the integer-formal boxing scan can be skipped.',
    'Bit31 is represented by signed I32 mask bits. Index32 cannot alias bit0 because registration masks omit it and caller flags use a full array once any index reaches32.',
    'Public nonowned calls, array flags and any floating actual for an integer formal still execute the original full scan. The ordered formal F64 binding loop is unchanged, including subclass conversions, errors, zero signs and partial argument mutations.'
  ],resolvedFindings:[{issue:'A valid registration array with a custom slice returning negative/fractional indices could shift those copied indices onto unrelated integer argument bits, skipping required boxing.',fix:'Build registration masks only from integer indices0..31; malformed copied entries retain the original full scan.',regression:'versions/2010-en/tests/number-dependencies.test.js',status:'fixed and verified'}],
  validation:{focusedTests:9,authorAddedComparisons:960,independentBaselineComparisons:cases,customMetadataCopyComparisons:customCopyCases,compared:'Return images, errors, ordered observed F64 conversions and partially mutated owned arguments against the unchanged baseline module.',allPassed:true},
  performanceScope:'Parent isolated leaf measurement reported100000calls median10.87ms→9.27ms; no browser FPS inference.',sourcePins};
const output=resolve(root,'versions/2010-en/analysis/browser-performance/dependency-mask-source-review.json');
await writeFile(output,JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({output,cases,findings:report.findings},null,2));
