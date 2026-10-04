import {readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {performance} from 'node:perf_hooks';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';

const runtimeUrl=new URL('../../../../src/runtime/float80.js',import.meta.url);
const source=await readFile(runtimeUrl,'utf8');
const old=`  const high=Number(parts.mantissa>>11n)*2**(parts.exponent+11);
  const tail=Number(parts.mantissa&2047n)*2**parts.exponent;
  const factor=Math.abs(value),product=high*factor;
  const splitHigh=134217729*high,ah=splitHigh-(splitHigh-high),al=high-ah;`;
const replacement=`  let split=mixedSplitCache.get(parts);
  if(!split){
    const high=Number(parts.mantissa>>11n)*2**(parts.exponent+11);
    const tail=Number(parts.mantissa&2047n)*2**parts.exponent;
    const splitHigh=134217729*high,ah=splitHigh-(splitHigh-high),al=high-ah;
    split={high,tail,ah,al};mixedSplitCache.set(parts,split);
  }
  const {high,tail,ah,al}=split;
  const factor=Math.abs(value),product=high*factor;`;
let bareSource=source;
if(source.split(old).length!==2){
  if(source.split(replacement).length!==2||source.split('const mixedSplitCache=new WeakMap();').length!==2)throw new Error('Expected one cached mixed-product decomposition block');
  bareSource=source.replace(replacement,old).replace('const mixedSplitCache=new WeakMap();','');
}
const importFloat=body=>import(`data:text/javascript;base64,${Buffer.from(body.replace(/from\s+(['"])([^'"]+)\1/g,(_,quote,path)=>`from ${quote}${new URL(path,runtimeUrl).href}${quote}`)).toString('base64')}`);
const uncached=await importFloat(bareSource);
const candidate=await importFloat(bareSource.replace('function mixedBinary64Product(parts,value){','const mixedSplitCache=new WeakMap();\nfunction mixedBinary64Product(parts,value){').replace(old,replacement));
const mantissas=Array.from({length:128},(_,i)=>(1n<<63n)+(BigInt(i+1)*0x01badc0ffee12345n&((1n<<63n)-1n)));
const inputs=mantissas.map((m,i)=>new uncached.Float80(i&1?-1:1,m,-67+i%6));
const cachedInputs=mantissas.map((m,i)=>new candidate.Float80(i&1?-1:1,m,-67+i%6));
const factors=Array.from({length:2048},(_,i)=>(i&1?-1:1)*(0.125+(i*14777%40001)/997));
const unbox=value=>typeof value==='number'?value:value.toNumber();
const methods=[
  ['old-boxed',i=>unbox(inputs[i%128].multiplyNumber(factors[i%2048]))],
  ['unboxed',i=>unbox(inputs[i%128].multiplyNumberUnboxed(factors[i%2048]))],
  ['unboxed-cached-split-prototype',i=>unbox(cachedInputs[i%128].multiplyNumberUnboxed(factors[i%2048]))],
];
const observations=[];
withX87ControlWord(0x027f,()=>uncached.withX87ControlWord(0x027f,()=>candidate.withX87ControlWord(0x027f,()=>{
  for(let i=0;i<8192;i++){
    const expected=methods[0][1](i);
    for(const [name,method] of methods.slice(1))if(!Object.is(method(i),expected))throw new Error(`Differential failure ${name}/${i}`);
  }
  for(const [,method] of methods)for(let i=0;i<20000;i++)method(i);
  const iterations=100000;
  for(let round=0;round<5;round++)for(let order=0;order<methods.length;order++){
    const [name,method]=methods[(order+round)%methods.length];
    let sum=0;const started=performance.now();
    for(let i=0;i<iterations;i++)sum+=method(i);
    observations.push({name,round,iterations,milliseconds:performance.now()-started,sum});
  }
})));
const report={format:1,checkedAt:new Date().toISOString(),scope:'Isolated Node retained-m80 multiplication loop; timings are not browser FPS measurements.',
  sourceSha256:createHash('sha256').update(source).digest('hex'),
  differentialImages:16384,observations,
  medians:Object.fromEntries(methods.map(([name])=>[name,observations.filter(row=>row.name===name).map(row=>row.milliseconds).sort((a,b)=>a-b)[2]]))};
await writeFile(new URL('../../analysis/browser-performance/mixed-unboxed-throughput.json',import.meta.url),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({differentialImages:report.differentialImages,medians:report.medians}));
