import assert from 'node:assert/strict';
import {readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {performance} from 'node:perf_hooks';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';

const root=new URL('../../../../',import.meta.url),edition=new URL('../../',import.meta.url);
const source=await readFile(new URL('src/runtime/float80.js',root),'utf8');
const sqrtSource=await readFile(new URL('src/runtime/certified-sqrt.js',root),'utf8');
const importFloat=source=>import('data:text/javascript;base64,'+Buffer.from(source.replace(/from (['"])([^'"]+)\1/g,
 (_all,_quote,path)=>'from '+JSON.stringify(new URL(path,new URL('src/runtime/float80.js',root)).href))).toString('base64'));
const start=source.indexOf('    if(arithmeticPrecision===53){\n      const leftNumber='),end=source.indexOf('    return arithmeticResult(this.sign * other.sign, this.mantissa * other.mantissa',start);
assert.ok(start>0&&end>start,'The additive mixed branch must be uniquely recognized');
let baselineSource=source.slice(0,start)+source.slice(end);
const method=baselineSource.indexOf('  multiplyNumber(value){'),methodEnd=baselineSource.indexOf('\n  divide(other)',method);
assert.ok(method>0&&methodEnd>method);
baselineSource=baselineSource.slice(0,method)+'  multiplyNumber(value){return this.multiply(Float80.fromNumber(value));}\n'+baselineSource.slice(methodEnd);
const baseline=await importFloat(baselineSource);
const observed=await importFloat(source+'\nexport {mixedBinary64Product};');
const hex=value=>Buffer.from(value.toBytes()).toString('hex');
const sha=value=>createHash('sha256').update(value).digest('hex');
let state=0x59ed18a6f7c043e1n;
const random=()=>state=BigInt.asUintN(64,state*6364136223846793005n+1442695040888963407n);
const vectors=[];
for(let index=0;index<20000;index++){
 let mantissa,exponent,factor;
 if(index<8192){
  const high=[1n<<52n,(1n<<52n)+1n,(1n<<53n)-2n,(1n<<53n)-1n][index>>11];
  mantissa=(high<<11n)|BigInt(index&2047);exponent=-63;factor=1;
 }else{
  mantissa=random()|(1n<<63n);
  exponent=[-163,-162,-100,-64,-63,-10,0,35,36][index%9];
  const exp=Number(random()%200n)-100;
  factor=index%3?(1+Number(random()>>11n)/2**53)*2**exp:2**[ -100,-40,0,10,99,100 ][index%6];
 }
 vectors.push({mantissa,exponent,sign:index&1?-1:1,factor:index&2?-factor:factor});
}
let accepted=0,declined=0,images=0,otherPrecisionImages=0,nativeImages=0;
withX87ControlWord(0x027f,()=>baseline.withX87ControlWord(0x027f,()=>{
 for(const [index,row]of vectors.entries()){
  const current=new Float80(row.sign,row.mantissa,row.exponent),previous=new baseline.Float80(row.sign,row.mantissa,row.exponent);
  const factor=Float80.fromNumber(row.factor),oldFactor=baseline.Float80.fromNumber(row.factor);
  const expected=hex(previous.multiply(oldFactor));
  for(const actual of [current.multiply(factor),factor.multiply(current),current.multiplyNumber(row.factor)]){
   assert.equal(hex(actual),expected,`Mixed product ${index}`);images++;
  }
  const candidate=observed.mixedBinary64Product({mantissa:row.mantissa,exponent:row.exponent},row.factor);
  if(Number.isNaN(candidate))declined++;
  else{assert.equal(hex(Float80.fromNumber(row.sign*(row.factor<0?-candidate:candidate))),expected);accepted++;}
 }
}));
for(const word of [0x007f,0x037f])withX87ControlWord(word,()=>baseline.withX87ControlWord(word,()=>{
 for(const row of vectors.slice(0,256)){
  const current=new Float80(row.sign,row.mantissa,row.exponent),previous=new baseline.Float80(row.sign,row.mantissa,row.exponent);
  assert.equal(hex(current.multiplyNumber(row.factor)),hex(previous.multiplyNumber(row.factor)));otherPrecisionImages++;
 }
}));
const native=JSON.parse(await readFile(new URL('tests/fixtures/native-precision.json',root),'utf8'));
for(const row of native.cases){
 if(row.operation!=='multiply')continue;
 const left=Float80.fromBytes(Buffer.from(row.leftBits,'hex')),right=Float80.fromBytes(Buffer.from(row.rightBits,'hex'));
 for(const [a,b]of [[left,right],[right,left]]){
  const number=b.exactNumber();if(Number.isNaN(number))continue;
  const result=withX87ControlWord(row.controlWord,()=>a.multiplyNumber(number));
  assert.equal(hex(result),row.expected.extendedBits,'Captured native mixed product');nativeImages++;
 }
}
const currentPairs=vectors.slice(9000,9256).map(row=>[new Float80(row.sign,row.mantissa,row.exponent),row.factor]);
const oldPairs=vectors.slice(9000,9256).map(row=>[new baseline.Float80(row.sign,row.mantissa,row.exponent),row.factor]);
const run=pairs=>{let checksum=0;const start=performance.now();for(let index=0;index<20000;index++){
 const pair=pairs[index&255];checksum+=pair[0].multiplyNumber(pair[1]).exactNumber();
}return{milliseconds:performance.now()-start,checksum};};
const samples=[];
withX87ControlWord(0x027f,()=>baseline.withX87ControlWord(0x027f,()=>{
 run(currentPairs);run(oldPairs);
 for(let round=0;round<7;round++){
  let current,previous;
  if(round&1){previous=run(oldPairs);current=run(currentPairs);}else{current=run(currentPairs);previous=run(oldPairs);}
  assert.ok(Object.is(current.checksum,previous.checksum));samples.push({current:current.milliseconds,baseline:previous.milliseconds});
 }
}));
const median=values=>values.sort((a,b)=>a-b)[values.length>>1];
const currentMedian=median(samples.map(row=>row.current)),baselineMedian=median(samples.map(row=>row.baseline));
assert.equal(await readFile(new URL('src/runtime/float80.js',root),'utf8'),source,'Float source changed during proof');
assert.equal(await readFile(new URL('src/runtime/certified-sqrt.js',root),'utf8'),sqrtSource,'Float dependency changed during proof');
const report={format:1,status:'exact',findings:[],cases:20000,images,otherPrecisionImages,nativeImages,accepted,declined,
 scope:'All2048low-bit residues around four rounding/power-of-two boundaries, random bounded m80×binary64 pairs, both operand orders, primitive Number entry, alternate controls and existing native multiplication captures. Microtiming compares only the additive branch and operand carrier allocation against the same source with that optimization removed.',
 sourcePins:[{path:'src/runtime/float80.js',sha256:sha(source)},{path:'src/runtime/certified-sqrt.js',sha256:sha(sqrtSource)},{path:'tools/diagnostics/review-mixed-multiply.mjs',sha256:sha(await readFile(new URL(import.meta.url)))}],
 benchmark:{callsPerSample:20000,samples,currentMedian,baselineMedian,speedup:baselineMedian/currentMedian,scope:'Isolated leaf method; no browser FPS inference.'}};
await writeFile(new URL('analysis/browser-performance/mixed-multiply-review.json',edition),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({cases:report.cases,images,otherPrecisionImages,nativeImages,accepted,declined,benchmark:report.benchmark},null,2));
