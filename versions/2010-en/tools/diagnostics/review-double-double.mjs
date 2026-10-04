import assert from 'node:assert/strict';
import {readFile,writeFile} from 'node:fs/promises';
import {execFileSync} from 'node:child_process';
import {createHash} from 'node:crypto';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';
import {atan2Extended,atan2ExtendedUncached,atan2ExtendedNumeric} from '../../../../src/runtime/atan.js';
import {dd,ddDiv} from '../../../../src/runtime/double-double.js';
import {sinCosX87,sinCosX87Number} from '../../../../src/runtime/transcendentals.js';

const root=new URL('../../../../',import.meta.url),edition=new URL('../../',import.meta.url);
const sha=value=>createHash('sha256').update(value).digest('hex');
const hex=value=>Buffer.from(value.toBytes()).toString('hex');
const absolute=value=>value<0n?-value:value;
const historical=(commit,path)=>execFileSync('git',['show',`${commit}:${path}`],{cwd:root,encoding:'utf8',maxBuffer:2**20});
const importSource=async(source,location,extra='')=>import('data:text/javascript;base64,'+Buffer.from(source.replace(/from (['"])([^'"]+)\1/g,
 (_all,_quote,path)=>'from '+JSON.stringify(new URL(path,location).href))+'\n'+extra).toString('base64'));
const sourceNames=['float80','atan','transcendentals','double-double','certified-sqrt'];
const currentSources=await Promise.all(sourceNames.map(async name=>({name,source:await readFile(new URL(`src/runtime/${name}.js`,root),'utf8')})));
const previousFloatSource=historical('15fd6ac','src/runtime/float80.js');
const previousFloat=await importSource(previousFloatSource,new URL('src/runtime/float80.js',root));
const originalAtanSource=historical('fb856db','src/runtime/atan.js');
const originalAtan=await importSource(originalAtanSource,new URL('src/runtime/atan.js',root),'export {atanUnit,PI};');
const originalTrigSource=historical('fb856db','src/runtime/transcendentals.js');
const originalTrig=await importSource(originalTrigSource,new URL('src/runtime/transcendentals.js',root));
function observeOnce(source,needle,replacement){
 assert.equal(source.split(needle).length-1,1,'Exactly one private certification site must match');
 return source.replace(needle,replacement);
}
const rawAtanSource=observeOnce(currentSources.find(row=>row.name==='atan').source,
 'return Float80.certifyInterval(fixed-DD_ERROR,fixed+DD_ERROR,-112);','return fixed;');
const rawAtan=await importSource(rawAtanSource,new URL('src/runtime/atan.js',root),'export {doubleAtan};');
const atanSource=currentSources.find(row=>row.name==='atan').source;
const calculateMarker='function calculateAtan2(y, x) {';
assert.equal(atanSource.split(calculateMarker).length-1,1,'Exactly one original Float80 calculation entry must match');
const calculateStart=atanSource.indexOf(calculateMarker);
const guardAtanSource=atanSource.slice(0,calculateStart)+observeOnce(atanSource.slice(calculateStart),
 'const ratio=ddDiv(dd(inverted?absX:absY),dd(inverted?absY:absX));',
 'numberGuardCalls++; const ratio=ddDiv(dd(inverted?absX:absY),dd(inverted?absY:absX));');
const guardAtan=await importSource(guardAtanSource,new URL('src/runtime/atan.js',root),'let numberGuardCalls=0; export {numberGuardCalls};');
const rawTrigSource=observeOnce(currentSources.find(row=>row.name==='transcendentals').source,
 'const certifiedSine=Float80.certifyInterval(s-DD_ERROR,s+DD_ERROR,-112);','return {sine:s,cosine:c};');
const rawTrig=await importSource(rawTrigSource,new URL('src/runtime/transcendentals.js',root),'export {doubleSinCos};');
let state=0x918ac21f65e713b9n;
const random64=()=>state=BigInt.asUintN(64,state*6364136223846793005n+1442695040888963407n);
const random224=()=>((random64()<<160n)|(random64()<<96n)|(random64()<<32n)|(random64()&0xffffffffn));
const S=1n<<224n,SHIFT=112n,ENCLOSURE=1n<<24n;
function originalReduced(reduced,quadrant){
 const squared=reduced*reduced/S;
 let sine=reduced,cosine=S,sineTerm=reduced,cosineTerm=S;
 for(let term=1n;;term++){
  const even=term*2n;
  sineTerm=-(sineTerm*squared/S)/(even*(even+1n));
  cosineTerm=-(cosineTerm*squared/S)/((even-1n)*even);
  sine+=sineTerm;cosine+=cosineTerm;
  if(sineTerm===0n&&cosineTerm===0n)break;
 }
 return [[sine,cosine],[cosine,-sine],[-sine,-cosine],[-cosine,sine]][Number((quadrant%4n+4n)%4n)];
}
const bounds={sinCos:{cases:0,components:0,maximumUnits112:0},atan:{cases:0,maximumUnits112:0},numberAtan:{cases:0,maximumUnits112:0,quadrants:[0,0,0,0]}};
const angles=[];
for(let anchor=-50n;anchor<=50n;anchor++)for(const offset of [-1n,0n,1n,-S/128n,S/128n]){
 const angle=anchor*S/64n+offset;
 if(absolute(angle)>S/(1n<<24n)&&absolute(angle)<=S*79n/100n)angles.push(angle);
}
for(const magnitude of [S/(1n<<24n),S*4n/5n])for(const delta of [0n,1n,-1n])for(const sign of [1n,-1n]){
 const angle=sign*(magnitude+delta);
 if(absolute(angle)>=S/(1n<<24n)&&absolute(angle)<=S*4n/5n)angles.push(angle);
}
while(angles.length<10000){
 let magnitude=random224()%(S*79n/100n);
 if(magnitude<S/(1n<<24n))magnitude+=S/(1n<<24n);
 angles.push(random64()&1n?-magnitude:magnitude);
}
let sinCosOutputs=0,atanOutputs=0,numberAtanOutputs=0,numericEntryOutputs=0,atanGuardFallbackOutputs=0,numericFallbackOutputs=0,numberTrigOutputs=0;
for(let index=0;index<10000;index++){
 const reduced=angles[index],quadrant=BigInt(index%19-9),candidate=rawTrig.doubleSinCos(reduced,quadrant);
 assert.notEqual(candidate,null,`Accepted bounded reduced angle ${index}`);
 const original=originalReduced(reduced,quadrant);
 for(const [component,expected]of [['sine',original[0]],['cosine',original[1]]]){
  const error=absolute((candidate[component]<<SHIFT)-expected);
  assert.ok(error<(ENCLOSURE<<SHIFT),`Unrounded DD ${component} enclosure ${index}`);
  bounds.sinCos.components++;
  bounds.sinCos.maximumUnits112=Math.max(bounds.sinCos.maximumUnits112,Number(error)/Number(1n<<SHIFT));
 }
 bounds.sinCos.cases++;
 const value=new Float80(reduced<0n?-1:1,absolute(reduced),-224);
 for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
  const actual=sinCosX87(value),expected=originalTrig.sinCosX87(value);
  assert.equal(hex(actual.sine),hex(expected.sine),`Final sine ${index}/${word}`);
  assert.equal(hex(actual.cosine),hex(expected.cosine),`Final cosine ${index}/${word}`);
  sinCosOutputs+=2;
 });
}
const ratios=[0n,1n,S];
for(let anchor=0n;anchor<=64n;anchor++)for(const delta of [-1n,0n,1n]){
 for(const ratio of [anchor*S/64n+delta,anchor<64n?(anchor*2n+1n)*S/128n+delta:-1n])
  if(ratio>=0n&&ratio<=S)ratios.push(ratio);
}
while(ratios.length<10000)ratios.push(random224());
for(let index=0;index<10000;index++){
 const ratio=ratios[index],inverted=Boolean(index&1),negativeX=Boolean(index&2),sign=index&4?-1:1;
 const candidate=rawAtan.doubleAtan(ratio,S,inverted,negativeX,sign);
 assert.notEqual(candidate,null,`Bounded DD atan ${index}`);
 let expected=originalAtan.atanUnit(ratio);
 if(inverted)expected=originalAtan.PI/2n-expected;
 if(negativeX)expected=originalAtan.PI-expected;
 expected*=BigInt(sign);
 const error=absolute((candidate<<SHIFT)-expected);
 assert.ok(error<(ENCLOSURE<<SHIFT),`Unrounded DD atan enclosure ${index}`);
 bounds.atan.cases++;
 bounds.atan.maximumUnits112=Math.max(bounds.atan.maximumUnits112,Number(error)/Number(1n<<SHIFT));
 // A zero denominator uses the original public quadrant path rather than
 // injecting an inverted zero into the private candidate.
 const small=new Float80(1,ratio,-224),large=Float80.fromInteger(1);
 const y=(inverted?large:small),x=(inverted?small:large);
 const signedY=sign<0?y.negate():y,signedX=negativeX?x.negate():x;
 for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
  assert.equal(hex(atan2Extended(signedY,signedX)),hex(originalAtan.atan2Extended(signedY,signedX)),`Final atan ${index}/${word}`);
  atanOutputs++;
 });
}
const binary64Pairs=[];
const edgeValues=[2**-100,2**-100+2**-152,2**-99,.5,1,1+2**-52,2,2**99,2**100-2**47,2**100];
for(const y of edgeValues)for(const x of edgeValues)binary64Pairs.push([y,x]);
for(let anchor=0;anchor<=64;anchor++)for(const delta of [-(2**-52),0,2**-52]){
 const ratio=anchor/64+delta;
 if(ratio>=2**-100&&ratio<=1){binary64Pairs.push([ratio,1]);binary64Pairs.push([1,ratio]);}
}
const randomMagnitude=()=>{
 const exponent=Number(random64()%200n)-100;
 return (1+Number(random64()>>11n)/2**53)*2**exponent;
};
while(binary64Pairs.length<2500)binary64Pairs.push([randomMagnitude(),randomMagnitude()]);
function originalBinaryRatio(y,x){
 let numerator=y.mantissa,denominator=x.mantissa;
 const difference=y.exponent-x.exponent;
 if(difference>=0)numerator<<=BigInt(difference);else denominator<<=BigInt(-difference);
 const inverted=numerator>denominator;
 return {ratio:((inverted?denominator:numerator)*S)/(inverted?numerator:denominator),inverted};
}
for(let index=0;index<2500;index++)for(let quadrant=0;quadrant<4;quadrant++){
 const [absY,absX]=binary64Pairs[index],negativeX=Boolean(quadrant&1),sign=quadrant&2?-1:1;
 const y=Float80.fromNumber(sign*absY),x=Float80.fromNumber(negativeX?-absX:absX);
 const {ratio,inverted}=originalBinaryRatio(y,x);
 const pair=ddDiv(dd(inverted?absX:absY),dd(inverted?absY:absX));
 const candidate=rawAtan.doubleAtan(0n,1n,inverted,negativeX,sign,pair);
 assert.notEqual(candidate,null,`Unrounded bounded Number atan ${index}/${quadrant}`);
 let expected=originalAtan.atanUnit(ratio);
 if(inverted)expected=originalAtan.PI/2n-expected;
 if(negativeX)expected=originalAtan.PI-expected;
 expected*=BigInt(sign);
 const error=absolute((candidate<<SHIFT)-expected);
 assert.ok(error<(ENCLOSURE<<SHIFT),`Number DD atan enclosure ${index}/${quadrant}`);
 bounds.numberAtan.cases++;bounds.numberAtan.quadrants[quadrant]++;
 bounds.numberAtan.maximumUnits112=Math.max(bounds.numberAtan.maximumUnits112,Number(error)/Number(1n<<SHIFT));
 const before=guardAtan.numberGuardCalls;
 guardAtan.atan2ExtendedUncached(y,x);
 assert.equal(guardAtan.numberGuardCalls,before+1,'Every bounded exact binary64 pair reaches the Number candidate');
 for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
  const expected=hex(originalAtan.atan2Extended(y,x));
  assert.equal(hex(atan2Extended(y,x)),expected,`Cached Number atan ${index}/${quadrant}/${word}`);
  assert.equal(hex(atan2ExtendedUncached(y,x)),expected,`Uncached Number atan ${index}/${quadrant}/${word}`);
  assert.equal(hex(atan2ExtendedNumeric(sign*absY,negativeX?-absX:absX)),expected,`Direct numeric atan ${index}/${quadrant}/${word}`);
  numericEntryOutputs++;
  numberAtanOutputs+=2;
 });
}
const outsidePairs=[];
for(const zero of [0,-0])for(const other of [0,-0,1,-1,Number.MIN_VALUE,Number.MAX_VALUE]){
 outsidePairs.push([Float80.fromNumber(zero),Float80.fromNumber(other)]);
 outsidePairs.push([Float80.fromNumber(other),Float80.fromNumber(zero)]);
}
for(const small of [Number.MIN_VALUE,2**-101,2**-100-2**-153])
 for(const large of [1,2**101,Number.MAX_VALUE])for(const sign of [-1,1]){
  outsidePairs.push([Float80.fromNumber(sign*small),Float80.fromNumber(large)]);
  outsidePairs.push([Float80.fromNumber(large),Float80.fromNumber(sign*small)]);
 }
for(const large of [2**100+2**48,2**101,Number.MAX_VALUE])for(const sign of [-1,1]){
 outsidePairs.push([Float80.fromNumber(sign*large),Float80.fromNumber(1)]);
 outsidePairs.push([Float80.fromNumber(1),Float80.fromNumber(sign*large)]);
}
outsidePairs.push([new Float80(1,(1n<<63n)+1n,-63),Float80.fromInteger(1)]);
outsidePairs.push([Float80.fromInteger(1),new Float80(-1,(1n<<63n)+1n,-63)]);
for(const [y,x]of outsidePairs){
 const before=guardAtan.numberGuardCalls;
 guardAtan.atan2ExtendedUncached(y,x);
 assert.equal(guardAtan.numberGuardCalls,before,'Signed zero, non-binary64 and out-of-domain operands retain the full legacy path');
 for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
  const expected=hex(originalAtan.atan2Extended(y,x));
  assert.equal(hex(atan2Extended(y,x)),expected);assert.equal(hex(atan2ExtendedUncached(y,x)),expected);
  atanGuardFallbackOutputs+=2;
  if(!Number.isNaN(y.exactNumber())&&!Number.isNaN(x.exactNumber())){
   assert.equal(hex(atan2ExtendedNumeric(y.exactNumber(),x.exactNumber())),expected,'Direct numeric fallback preserves axes and out-of-domain binary64');
   numericFallbackOutputs++;
  }
 });
}
for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
 const values=[0,-0,Number.MIN_VALUE,-Number.MIN_VALUE,2**-101,-(2**-101),2**-24,-(2**-24),.5,-.5,.8,-.8];
 for(let index=0;index<2200;index++)values.push(Number(random64()>>11n)/2**53*100000-50000);
 for(const value of values){
  const actual=sinCosX87Number(value),expected=originalTrig.sinCosX87(Float80.fromNumber(value));
  assert.equal(hex(actual.sine),hex(expected.sine));assert.equal(hex(actual.cosine),hex(expected.cosine));
  assert.ok(Object.isFrozen(actual));numberTrigOutputs+=2;
 }
});
const intervalResult=(type,lower,upper,exponent)=>{
 try{
  const build=value=>new type(value<0n?-1:1,absolute(value),exponent);
  const low=build(lower),high=build(upper);return {bits:hex(low)===hex(high)?hex(low):null};
 }catch(error){return {error:`${error.name}: ${error.message}`};}
};
const certifyResult=(lower,upper,exponent)=>{
 try{const value=Float80.certifyInterval(lower,upper,exponent);return {bits:value?hex(value):null};}
 catch(error){return {error:`${error.name}: ${error.message}`};}
};
let certificates=0,conversions=0;
function checkInterval(lower,upper,exponent=-112){
 const expected=lower<0n&&upper>=0n?{bits:null}:intervalResult(previousFloat.Float80,lower,upper,exponent);
 assert.deepEqual(certifyResult(lower,upper,exponent),expected,`Certificate ${certificates}: ${lower}/${upper}/${exponent}`);certificates++;
}
for(let shift=0n;shift<=50n;shift++)for(const mantissa of [(1n<<63n)-1n,1n<<63n,(1n<<63n)+1n,(1n<<64n)-2n,(1n<<64n)-1n]){
 const center=mantissa<<shift,unit=1n<<shift,half=unit>>1n;
 for(const delta of [-half-1n,-half,-half+1n,-1n,0n,1n,half-1n,half,half+1n])
  for(const radius of [0n,1n,2n,ENCLOSURE,unit,unit+1n])for(const sign of [1n,-1n]){
   const left=center+delta-radius,right=center+delta+radius;
   if(left>=0n)checkInterval(sign>0n?left:-right,sign>0n?right:-left);
  }
}
for(const center of [0n,1n,2n,1n<<24n,(1n<<114n)-1n,1n<<114n,(1n<<114n)+1n])for(const radius of [0n,1n,ENCLOSURE]){
 checkInterval(center-radius,center+radius);checkInterval(-center-radius,-center+radius);
}
for(let index=0;index<12000;index++){
 const length=[0,1,24,53,64,65,80,112,224][index%9];
 let magnitude=length===0?0n:1n<<BigInt(length-1);
 if(length)magnitude|=random224()&((1n<<BigInt(length))-1n);
 const exponent=[-16450,-16445,-1138,-1127,-1126,-1086,-1074,-1073,-1023,-1022,-1011,-63,-11,0,959,960,961,970,971,972,1023,1024,1025,16000,16320][index%25]+Number(random64()%7n)-3;
 const sign=index&1?-1:1;
 const convert=type=>{
  try{
   const value=new type(sign,magnitude,exponent).toNumber(),bytes=Buffer.alloc(8);bytes.writeDoubleLE(value);
   return {bits:bytes.toString('hex')};
  }catch(error){return {error:`${error.name}: ${error.message}`};}
 };
 assert.deepEqual(convert(Float80),convert(previousFloat.Float80),`Binary64 store ${index}`);conversions++;
}
for(const row of currentSources)assert.equal(await readFile(new URL(`src/runtime/${row.name}.js`,root),'utf8'),row.source,'Runtime source changed during proof');
const report={format:1,status:'exact',findings:[],
 scope:'Independent unrounded DD candidate enclosures, final m80 outputs against the untouched original224 algorithms, fixed112 certification against prior public constructors, direct binary64 stores and Number trig cache images. Generated finite corpora supplement separate unchanged native fixtures.',
 comparisons:{bounds,sinCosOutputs,atanOutputs,numberAtanOutputs,numericEntryOutputs,atanGuardFallbackOutputs,numericFallbackOutputs,numberTrigOutputs,certificates,conversions},
 enclosure:{precision:112,radius:ENCLOSURE.toString(),absolute:'2^-88'},
 originalSources:[{commit:'15fd6ac',path:'src/runtime/float80.js',sha256:sha(previousFloatSource)},{commit:'fb856db',path:'src/runtime/atan.js',sha256:sha(originalAtanSource)},{commit:'fb856db',path:'src/runtime/transcendentals.js',sha256:sha(originalTrigSource)}],
 reviewedSources:currentSources.map(row=>({path:`src/runtime/${row.name}.js`,sha256:sha(row.source)})),
 reviewDiagnostic:{path:'tools/diagnostics/review-double-double.mjs',sha256:sha(await readFile(new URL(import.meta.url),'utf8'))},
 absoluteErrorReview:{path:'analysis/browser-performance/double-double-bounds.md',sha256:sha(await readFile(new URL('analysis/browser-performance/double-double-bounds.md',edition))),derivedBound:'2^-94',productionEnclosure:'2^-88'},
};
await writeFile(new URL('analysis/browser-performance/double-double-review.json',edition),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify(report.comparisons,null,2));
