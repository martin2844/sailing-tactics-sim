import assert from 'node:assert/strict';
import {readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {execFileSync} from 'node:child_process';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';
import {sinCosX87Number} from '../../../../src/runtime/transcendentals.js';
import {ddToFixed} from '../../../../src/runtime/double-double.js';

const root=new URL('../../../../',import.meta.url);
const path='src/runtime/transcendentals.js';
const source=await readFile(new URL(path,root),'utf8');
const dependencyPaths=['src/runtime/float80.js','src/runtime/atan.js','src/runtime/double-double.js','src/runtime/certified-sqrt.js'];
const dependencies=await Promise.all(dependencyPaths.map(async path=>({path,source:await readFile(new URL(path,root),'utf8')})));
const importSource=(text,extra='')=>import('data:text/javascript;base64,'+Buffer.from(text.replace(/from (['"])([^'"]+)\1/g,
  (_all,_quote,relative)=>'from '+JSON.stringify(new URL(relative,new URL(path,root)).href))+'\n'+extra).toString('base64'));
const current=await importSource(source,'export {reduceNumberAngle};');
const original=await importSource(execFileSync('git',['show','fb856db:src/runtime/transcendentals.js'],{cwd:root,encoding:'utf8'}));
const half=0x3243f6a8885a308d3n<<159n,quarter=half/2n;
let state=0x85fa3147;
const random=()=>{state^=state<<13;state^=state>>>17;state^=state<<5;return state>>>0;};
const view=new DataView(new ArrayBuffer(8));
function next(value,direction){
 view.setFloat64(0,value,true);
 let bits=view.getBigUint64(0,true);
 bits+=direction*(value>=0?1n:-1n);
 view.setBigUint64(0,bits,true);
 return view.getFloat64(0,true);
}
const values=[.5,-.5,2**20,-(2**20),next(.5,-1n),next(2**20,1n),0,-0,NaN,Infinity];
for(let q=-667543;q<=667543;q+=73){
 const boundary=Number(BigInt(2*q+1)*quarter)/2**224;
 if(Math.abs(boundary)<.5||Math.abs(boundary)>2**20)continue;
 values.push(next(boundary,-1n),boundary,next(boundary,1n));
}
while(values.length<100000)values.push((random()&1?-1:1)*(.5+random()/2**32*(2**20-.5)));
let exactReductions=0,declined=0,outputs=0;
const hex=value=>Buffer.from(value.toBytes()).toString('hex');
for(let i=0;i<values.length;i++){
 const value=values[i],reduced=current.reduceNumberAngle(value);
 if(!Number.isFinite(value)||Math.abs(value)<.5||Math.abs(value)>2**20){assert.equal(reduced,null);declined++;continue;}
 assert.notEqual(reduced,null);
 const angle=Float80.fromNumber(value);
 const input=BigInt(angle.sign)*(angle.mantissa<<BigInt(angle.exponent+224));
 const quadrant=input>=0n?(input+quarter)/half:(input-quarter)/half;
 assert.equal(BigInt(reduced.quadrant),quadrant,`Exact original quotient ${i}`);
 assert.equal(ddToFixed(reduced.angle,224),input-quadrant*half,`Exact original reduction ${i}`);
 exactReductions++;
 // Boundary cases plus a distributed sample test all final m80 images.
 if(i<55000||i%17===0)for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
  const actual=sinCosX87Number(value),expected=original.sinCosX87(angle);
  assert.equal(hex(actual.sine),hex(expected.sine),`Original sine ${i}/${word}`);
  assert.equal(hex(actual.cosine),hex(expected.cosine),`Original cosine ${i}/${word}`);
  outputs+=2;
 });
}
assert.equal(await readFile(new URL(path,root),'utf8'),source,'Reduction source changed during proof');
for(const row of dependencies)assert.equal(await readFile(new URL(row.path,root),'utf8'),row.source,'Reduction dependency changed during proof');
const report={checkedAt:new Date().toISOString(),source:{path,sha256:createHash('sha256').update(source).digest('hex')},
  sourcePins:dependencies.map(row=>({path:row.path,sha256:createHash('sha256').update(row.source).digest('hex')})),
  reference:'fb856db original224-bit x8766-bit-pi reduction and series',cases:values.length,exactReductions,declined,m80Outputs:outputs,
  result:'PASS: every accepted DD reduction is the exact original dyadic; all sampled m80 images match at PC24/53/64'};
await writeFile(new URL('../../analysis/browser-performance/number-reduction-review.json',import.meta.url),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify(report));
