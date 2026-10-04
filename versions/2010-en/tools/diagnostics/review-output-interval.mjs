import assert from 'node:assert/strict';
import {readFile,writeFile} from 'node:fs/promises';
import {execFileSync} from 'node:child_process';
import {createHash} from 'node:crypto';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';
import * as interval from '../../../../src/runtime/output-interval.js';
import {certifiedSqrtNumber} from '../../../../src/runtime/certified-sqrt.js';

const started=performance.now();
const root=new URL('../../../../',import.meta.url),edition=new URL('../../',import.meta.url);
const sha=value=>createHash('sha256').update(value).digest('hex');
const paths=['src/runtime/output-interval.js','src/runtime/certified-sqrt.js','src/runtime/float80.js','src/runtime/atan.js','src/runtime/transcendentals.js',
 'versions/2010-en/src/render/projection-fast.js','versions/2010-en/src/render/projection-output-fast.js','versions/2010-en/tools/floating_drawing.py'];
const sources=await Promise.all(paths.map(async path=>({path,source:await readFile(new URL(path,root),'utf8')})));
const historical=(commit,path)=>execFileSync('git',['show',`${commit}:${path}`],{cwd:root,encoding:'utf8',maxBuffer:2**20});
const importSource=async(source,path)=>import('data:text/javascript;base64,'+Buffer.from(source.replace(/from (['"])([^'"]+)\1/g,
 (_all,_quote,location)=>'from '+JSON.stringify(new URL(location,new URL(path,root)).href))).toString('base64'));
const oldFloatSource=historical('15fd6ac','src/runtime/float80.js'),old=await importSource(oldFloatSource,'src/runtime/float80.js');
const oldAtanSource=historical('fb856db','src/runtime/atan.js'),atan=await importSource(oldAtanSource,'src/runtime/atan.js');
const oldTrigSource=historical('fb856db','src/runtime/transcendentals.js'),trig=await importSource(oldTrigSource,'src/runtime/transcendentals.js');
const counts={atanPairs:0,atanM80Images:0,cosIntervals:0,cosM80Images:0,sinM80Images:0,operations:0,acceptedOperations:0,
 interiorM80Images:0,declinedOperations:0,singletonCornerCases:0,truncationCases:0,truncationImages:0,
 rootCases:0,acceptedRoots:0,declinedRoots:0};
const enclosed=(value,bounds,Type=Float80)=>bounds&&value.compare(Type.fromNumber(bounds[0]))>=0&&value.compare(Type.fromNumber(bounds[1]))<=0;
const bits=new DataView(new ArrayBuffer(8));
function next(value,up){
 if(value===0)return up?Number.MIN_VALUE:-Number.MIN_VALUE;
 bits.setFloat64(0,value,true);
 bits.setBigUint64(0,bits.getBigUint64(0,true)+((value>0)===up?1n:-1n),true);
 return bits.getFloat64(0,true);
}
let state=0x436ea710;
const random=()=>{state=(Math.imul(state,1664525)+1013904223)>>>0;return state;};
const unit=()=>random()/2**32;
const words=[0x007f,0x027f,0x037f];
const edge=[2**-100,next(2**-100,true),1,next(1,false),next(1,true),next(2**100,false),2**100];
const pairs=[];
for(const y of edge)for(const x of edge)pairs.push([y,x]);
for(let index=0;index<=64;index++)for(const ratio of [index/64,(index+.5)/64]){
 for(const value of [next(ratio,false),ratio,next(ratio,true)])if(value>=2**-100&&value<=1)pairs.push([value,1]);
}
while(pairs.length<1000)pairs.push([(1+unit())*2**(random()%200-100),(1+unit())*2**(random()%200-100)]);
for(const pair of pairs)for(const signY of [-1,1])for(const signX of [-1,1]){
 const y=pair[0]*signY,x=pair[1]*signX,bounds=interval.atan2Interval(y,x);
 assert.ok(bounds,'bounded pair must have an enclosure');counts.atanPairs++;
 for(const word of words)withX87ControlWord(word,()=>{
  assert.ok(enclosed(atan.atan2Extended(Float80.fromNumber(y),Float80.fromNumber(x)),bounds),`atan enclosure ${y}/${x}/${word}`);
  counts.atanM80Images++;
 });
}
for(const y of [0,-0,1,-1])for(const x of [0,-0,1,-1]){
 const bounds=interval.atan2Interval(y,x);assert.ok(bounds);counts.atanPairs++;
 for(const word of words)withX87ControlWord(word,()=>{
  const value=atan.atan2Extended(Float80.fromNumber(y),Float80.fromNumber(x));
  assert.ok(enclosed(value,bounds));
  if(y===0&&x>=0&&!Object.is(x,-0))assert.ok(Object.is(bounds[0],y)&&Object.is(bounds[1],y),'axis enclosure keeps the original zero sign');
  counts.atanM80Images++;
 });
}
for(const bad of [Number.MIN_VALUE,next(2**-100,false),next(2**100,true),Number.MAX_VALUE,Infinity,NaN,undefined]){
 assert.equal(interval.atan2Interval(bad,1),undefined);assert.equal(interval.atan2Interval(1,bad),undefined);
}

const angles=[-16,next(-16,true),0,-0,next(16,false),16];
const half=new Float80(1,0x3243f6a8885a308d3n,-65).toNumber();
for(let quadrant=-10;quadrant<=10;quadrant++)for(const center of [quadrant*half,(quadrant+.5)*half]){
 for(const angle of [next(center,false),center,next(center,true)])if(angle>=-16&&angle<=16)angles.push(angle);
}
while(angles.length<2000)angles.push(unit()*32-16);
for(let index=0;index<angles.length;index++){
 const center=angles[index],radius=[0,2**-40,2**-12,2**-11][index%4];
 const low=Math.max(-16,center-radius),high=Math.min(16,center+radius);
 const angle=[low,high],bounds=interval.cosX87Interval(angle),sineBounds=interval.sinX87Interval(angle);
 assert.ok(bounds);assert.ok(sineBounds);counts.cosIntervals++;
 for(const value of [low,low+(high-low)/2,high])for(const word of words)withX87ControlWord(word,()=>{
  const result=trig.sinCosX87(Float80.fromNumber(value));
  assert.ok(enclosed(result.cosine,bounds),`cos enclosure ${angle}/${value}/${word}`);
  assert.ok(enclosed(result.sine,sineBounds),`sin enclosure ${angle}/${value}/${word}`);
  counts.cosM80Images++;
  counts.sinM80Images++;
 });
}
assert.deepEqual(interval.cosX87Interval([0,0]),[1,1]);assert.deepEqual(interval.cosX87Interval([-0,-0]),[1,1]);
for(const zero of [0,-0]){
 const bounds=interval.sinX87Interval([zero,zero]);assert.ok(Object.is(bounds[0],zero)&&Object.is(bounds[1],zero));
}
for(const value of [[-17,-17],[17,17],[-1,1],[NaN,1],[1,Infinity],[1,0]])assert.equal(interval.cosX87Interval(value),undefined);

const magnitudes=()=>{const value=(1+unit())*2**(random()%601-300);return random()&0x80000000?-value:value;};
const interior=(bounds,fraction)=>old.withX87ControlWord(0x037f,()=>{
 const low=old.Float80.fromNumber(bounds[0]),high=old.Float80.fromNumber(bounds[1]);
 const value=low.add(high.subtract(low).multiply(old.Float80.fromNumber(fraction)));
 return value.compare(low)<0?low:value.compare(high)>0?high:value;
});
for(let index=0;index<4000;index++){
 const a=[magnitudes(),magnitudes()].sort((x,y)=>x-y),b=[magnitudes(),magnitudes()].sort((x,y)=>x-y);
 for(const [method,name]of [['add','intervalAdd'],['subtract','intervalSub'],['multiply','intervalMul'],['divide','intervalDiv']]){
  const bounds=interval[name](a,b);counts.operations++;
  if(bounds===undefined){counts.declinedOperations++;continue;}
  counts.acceptedOperations++;
  for(const fraction of [0,1,1/2048,2047/2048,unit()]){
   const left=interior(a,fraction),right=interior(b,1-fraction);
   const value=old.withX87ControlWord(0x027f,()=>left[method](right));
   assert.ok(enclosed(value,bounds,old.Float80),`RN53/m80 ${method} ${a}/${b}/${fraction}`);
   counts.interiorM80Images++;
  }
 }
}
for(const [method,a,b]of [
 ['intervalMul',[2**-1022,2**-1022],[.5,.5]],
 ['intervalMul',[2**-1022,2**-1022],[2**-1022,2**-1022]],
 ['intervalAdd',[Number.MIN_VALUE,Number.MIN_VALUE],[Number.MIN_VALUE,Number.MIN_VALUE]],
 ['intervalDiv',[2**-1022,2**-1022],[2**100,2**100]],
 ['intervalDiv',[1,1],[-1,1]],['intervalMul',[Number.MAX_VALUE,Number.MAX_VALUE],[2,2]],
])assert.equal(interval[method](a,b),undefined,'uncertain exponents and zero denominators retain the original path');

function fourCorners(method,a,b){
 if(method==='div'&&b[0]<=0&&b[1]>=0)return undefined;
 const corner=(x,y)=>{
  const value=method==='mul'?x*y:x/y;
  const exactZero=method==='mul'?x===0||y===0:x===0&&y!==0;
  return Number.isFinite(value)&&(Math.abs(value)>=2**-1022||value===0&&exactZero)?value:undefined;
 };
 const points=[corner(a[0],b[0]),corner(a[0],b[1]),corner(a[1],b[0]),corner(a[1],b[1])];
 return points.includes(undefined)?undefined:[Math.min(...points),Math.max(...points)];
}
const cornerIntervals=[[0,0],[-0,-0],[0,-0],[-0,0],[1,1],[-1,-1],[-1,1],[1,2],[-2,-1],
 [2**-1022,2**-1022],[-(2**-1022),-(2**-1022)],[2**-1022,1],[-1,-(2**-1022)],
 [Number.MIN_VALUE,Number.MIN_VALUE],[-Number.MIN_VALUE,Number.MIN_VALUE],
 [Number.MAX_VALUE,Number.MAX_VALUE],[-Number.MAX_VALUE,Number.MAX_VALUE]];
for(let index=0;index<30;index++){
 const x=magnitudes(),y=magnitudes();cornerIntervals.push([x,x]);cornerIntervals.push([Math.min(x,y),Math.max(x,y)]);
}
for(const a of cornerIntervals)for(const b of cornerIntervals)for(const method of ['mul','div']){
 const expected=fourCorners(method,a,b),actual=interval[method==='mul'?'intervalMul':'intervalDiv'](a,b);
 assert.equal(actual===undefined,expected===undefined,`singleton ${method} domain ${a}/${b}`);
 if(expected){assert.ok(Object.is(actual[0],expected[0]));assert.ok(Object.is(actual[1],expected[1]));}
 counts.singletonCornerCases++;
}

const conversions=[[-.9,.9],[0,0],[-0,-0],[-(2**63),-(2**63)],
 [next(2**63,false),next(2**63,false)],[next(-(2**63),true),next(-(2**63),true)],
 [-.5,2**32+.5],[-(2**32)-.5,-.5],[-3*2**32-.5,-.5],[-(2**63),2**63],
 [2**63,2**63],[next(-(2**63),false),next(-(2**63),false)]];
for(const value of [-(2**32),-1,0,1,2**32])for(const delta of [-.5,0,.5])conversions.push([value+delta,value+delta]);
for(const bounds of conversions){
 counts.truncationCases++;
 const low=old.Float80.fromNumber(bounds[0]),high=old.Float80.fromNumber(bounds[1]);
 let expected;
 try{const a=low.truncI64(),b=high.truncI64();if(a===b)expected=Number(BigInt.asIntN(32,a));}catch{}
 assert.equal(interval.intervalTruncI32(bounds),expected,`complete FTOL64 certificate ${bounds}`);
 if(expected!==undefined)for(const fraction of [0,.25,.5,.75,1]){
  assert.equal(interior(bounds,fraction).truncI32(),expected);counts.truncationImages++;
 }
}
const rootValues=[{value:0,category:'zero'},{value:-0,category:'zero'}];
const rootCoverage={};
for(let exponent=-100;exponent<=100;exponent++){
 const value=2**exponent;
 for(const sample of [next(value,false),value,next(value,true)])rootValues.push({value:sample,category:'powerBoundary'});
}
for(let index=0;index<10000;index++){
 const mantissa=2**52+random()*2**20+(random()&0xfffff);
 rootValues.push({value:mantissa/2**52*2**(random()%200-100),category:'randomFullMantissa'});
}
for(const rootValue of [1,3,7,100,123.125,1023,2**26,2**50]){
 const square=rootValue*rootValue;
 for(const sample of [next(square,false),square,next(square,true)])rootValues.push({value:sample,category:'squareBoundary'});
}
for(const {value,category} of rootValues){
 const coverage=rootCoverage[category]??=( {cases:0,accepted:0,declined:0});coverage.cases++;
 const actual=certifiedSqrtNumber(value);counts.rootCases++;
 if(actual===undefined){counts.declinedRoots++;coverage.declined++;continue;}
 const expected=old.withX87ControlWord(0x027f,()=>old.Float80.fromNumber(value).sqrt().toNumber());
 assert.ok(Object.is(actual,expected),`certified sqrt against untouched root arithmetic ${value}`);
 counts.acceptedRoots++;
 coverage.accepted++;
}
assert.ok(rootCoverage.randomFullMantissa.accepted>rootCoverage.randomFullMantissa.cases*.99,'the random bounded root proof exercises accepted certificates');
for(const row of sources)assert.equal(await readFile(new URL(row.path,root),'utf8'),row.source,'Runtime source changed during the independent proof');
const report={format:1,status:'exact',findings:[],counts,rootCoverage,runtimeMs:performance.now()-started,
 scope:'Bounded atan/sine/cosine enclosures against the untouched original224 algorithms, RN53 endpoint bounds against prior Float80 arithmetic with retained m80 interiors, full signed-I64 truncation before DWORD wrapping, certified binary64 roots against prior exact midpoint arithmetic and strict exponent/domain declines.',
 reviewedSources:sources.map(row=>({path:row.path,sha256:sha(row.source)})),
 referenceSources:[['15fd6ac','src/runtime/float80.js',oldFloatSource],['fb856db','src/runtime/atan.js',oldAtanSource],['fb856db','src/runtime/transcendentals.js',oldTrigSource]].map(([commit,path,source])=>({commit,path,sha256:sha(source)})),
 diagnostic:{path:'tools/diagnostics/review-output-interval.mjs',sha256:sha(await readFile(new URL(import.meta.url)))}};
await writeFile(new URL('analysis/browser-performance/projection-output-interval-review.json',edition),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify(counts,null,2));
