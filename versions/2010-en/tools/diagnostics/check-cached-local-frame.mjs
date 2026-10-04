// Supplementary differential checks; unchanged native captures remain authoritative.
import {execFileSync} from 'node:child_process';
import {writeFileSync} from 'node:fs';
import {fileURLToPath} from 'node:url';
import * as current from '../../src/render/typed-c.js';
import {Float80} from '../../../../src/runtime/float80.js';

const sourceUrl=new URL('../../src/render/typed-c.js',import.meta.url);
const root=fileURLToPath(new URL('../../../../',import.meta.url));
const revision='fb856db76104e87ce63294aa9f7f71f2f5658b18';
const oldSource=execFileSync('git',['show',`${revision}:versions/2010-en/src/render/typed-c.js`],{cwd:root,encoding:'utf8'})
 .replace(/from (['"])(\.[^'"]+)\1/g,(_all,quote,path)=>`from ${quote}${new URL(path,sourceUrl).href}${quote}`);
const old=await import('data:text/javascript;base64,'+Buffer.from(oldSource).toString('base64'));
const capture=(module,operation,offset,size,kind,value)=>{
 const frame=module.createLocalFrame(16);
 module.writeLocal(module.framePointer(frame,0),0x12345678,4);
 module.writeLocal(module.framePointer(frame,4),0x76543210,4);
 let result,error;
 try{result=module[operation](module.framePointer(frame,offset),...(operation==='writeLocal'?[value,size,kind]:[size,kind]));}
 catch(caught){error={name:caught.constructor.name,message:caught.message};}
 if(result instanceof Float80)result={m80:Buffer.from(result.toBytes()).toString('hex')};
 else if(typeof result==='bigint')result={bigint:result.toString()};
 else if(typeof result==='number'&&!Number.isFinite(result))result=String(result);
 return {result,error,bytes:Buffer.from(frame.bytes).toString('hex'),valid:Array.from(frame.valid),semantic:Array.from(frame.semantic)};
};
let checks=0;const failures=[];
for(const offset of [-1,0,.5,1,1.5,4,4.5,8,12,13,15,16,NaN,Infinity,undefined,'1','0x4'])
 for(const size of [undefined,NaN,-Infinity,-1,0,1,2,3,4,5,8,16,17,.5,3.5,'4','invalid'])
 for(const kind of ['int','float'])for(const operation of ['readLocal','readLocalArgument','writeLocal']){
  const values=operation==='writeLocal'?[1,0xabcdef01,1.5,Float80.fromNumber(1.5),undefined,'boat',1n,true]:[undefined];
  for(const value of values){
   checks++;const args=[operation,offset,size,kind,value],actual=capture(current,...args),expected=capture(old,...args);
   if(JSON.stringify(actual)!==JSON.stringify(expected))failures.push({operation,offset:String(offset),size:String(size),kind,value:String(value),actual,expected});
  }
 }
// Keep arrays unobserved across multiple calls so this checks the compact path
// before materialization, then check direct mutations after it materializes.
let sequenceSeed=0x52a613cd;
const next=()=>{sequenceSeed=(Math.imul(sequenceSeed,1664525)+1013904223)>>>0;return sequenceSeed;};
const captureSequence=(module,operations)=>{
 const frame=module.createLocalFrame(32),results=[];
 for(const row of operations){
  let result,error;
  try{
   if(row.operation==='byteMutation')result=frame.bytes[row.offset]=row.value;
   else if(row.operation==='validMutation')result=frame.valid[row.offset]=row.value;
   else if(row.operation==='semanticMutation')result=frame.semantic.set(row.offset,{size:4,value:row.value}).size;
   else result=module[row.operation](module.framePointer(frame,row.offset),...(row.operation==='writeLocal'?[row.value,row.size,row.kind]:[row.size,row.kind]));
  }catch(caught){error={name:caught.constructor.name,message:caught.message};}
  if(result instanceof Float80)result={m80:Buffer.from(result.toBytes()).toString('hex')};
  else if(typeof result==='bigint')result={bigint:result.toString()};
  results.push({result,error});
 }
 return {results,bytes:Buffer.from(frame.bytes).toString('hex'),valid:Array.from(frame.valid),semantic:Array.from(frame.semantic)};
};
let sequenceChecks=0,sequenceOperations=0;
for(let index=0;index<600;index++){
 const operations=[];
 for(let step=0;step<40;step++){
  const operation=['writeLocal','writeLocal','readLocal','readLocalArgument'][next()>>>30];
  const size=(next()>>>31)?4:8,kind=size===8?'float':'int';
  const offset=(next()>>>29)*4;
  const value=[next()|0,(next()%10000)/13,undefined,'retained host',Float80.fromNumber(-0)][next()%5];
  operations.push({operation,offset,size,kind,value});
  if(step===20&&index%3===0)operations.push({operation:'byteMutation',offset:next()%32,value:next()&255});
  if(step===21&&index%3===0)operations.push({operation:'validMutation',offset:next()%32,value:next()&1});
  if(step===22&&index%3===1)operations.push({operation:'semanticMutation',offset:next()%8*4,value:'host overwrite'});
 }
 sequenceChecks++;sequenceOperations+=operations.length;
 const actual=captureSequence(current,operations),expected=captureSequence(old,operations);
 if(JSON.stringify(actual)!==JSON.stringify(expected))failures.push({sequence:index,actual,expected});
}
const report={scope:'Supplementary local-frame differential check against the prior JavaScript implementation; exact return, storage, byte validity, semantic slots and failure name/message over scalar widths, undefined values, unusual host indices, sequences before array materialization, and public byte/validity/semantic mutations. These are generated checks, not native captures.',referenceRevision:revision,checks,sequenceChecks,sequenceOperations,exact:failures.length===0,failures};
writeFileSync(process.argv[2]??'/tmp/tact-cached-local-frame-guard-check.json',JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({...report,failures:failures.slice(0,5),failureCount:failures.length},null,2));
process.exitCode=failures.length?1:0;
