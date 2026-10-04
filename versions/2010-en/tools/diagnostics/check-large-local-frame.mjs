// Generated JavaScript differential checks supplement the unchanged native fixtures.
import {execFileSync} from 'node:child_process';
import {createHash} from 'node:crypto';
import {readFileSync,writeFileSync} from 'node:fs';
import {performance} from 'node:perf_hooks';
import {fileURLToPath} from 'node:url';
import * as current from '../../src/render/typed-c.js';
import {Float80} from '../../../../src/runtime/float80.js';

const sourceUrl=new URL('../../src/render/typed-c.js',import.meta.url);
const root=fileURLToPath(new URL('../../../../',import.meta.url));
const revision='15fd6ac';
const referenceSource=execFileSync('git',['show',`${revision}:versions/2010-en/src/render/typed-c.js`],{cwd:root,encoding:'utf8'});
const reference=await import('data:text/javascript;base64,'+Buffer.from(referenceSource
 .replace(/from (['"])(\.[^'"]+)\1/g,(_all,quote,path)=>`from ${quote}${new URL(path,sourceUrl).href}${quote}`)).toString('base64'));
const hash=bytes=>createHash('sha256').update(bytes).digest('hex');
const containerSource=source=>source.slice(source.indexOf('const localScalarView='),source.indexOf('export function cAdd('));
const sourcePin=hash(containerSource(readFileSync(sourceUrl,'utf8')));
const sizes=[96,292,688,4096,65536];
const negativeZero=Float80.fromNumber(-0),ordinaryFloat=Float80.fromNumber(-123.456);
const throwingValue={frame:null,valueOf(){throw new RangeError('retained coercion failed');}};
const hostValue={frame:{identity:'retained host'},offset:4};
const normalize=value=>{
 if(value===undefined)return {undefined:true};
 if(value instanceof Float80)return {m80:Buffer.from(value.toBytes()).toString('hex')};
 if(typeof value==='bigint')return {bigint:value.toString()};
 if(typeof value==='number'&&(!Number.isFinite(value)||Object.is(value,-0)))return {number:Object.is(value,-0)?'-0':String(value)};
 if(typeof value==='function')return {function:value.name};
 return value;
};
const snapshot=frame=>({bytes:hash(frame.bytes),valid:hash(frame.valid),
 semantic:Array.from(frame.semantic,([at,row])=>[at,{size:row.size,value:normalize(row.value)}])});
function initialize(module,size){
 const frame=module.createLocalFrame(size);
 for(const offset of new Set([0,28,60,64,Math.floor((size-4)/4)*4]))
  if(offset>=0&&offset+4<=size)module.writeLocal(module.framePointer(frame,offset),0x89abcdef^offset,4);
 if(size>=40)module.writeLocal(module.framePointer(frame,32),negativeZero,8,'float');
 return frame;
}
function execute(module,frame,row){
 let value,error;
 try{
  switch(row.operation){
   case 'byteMutation':value=frame.bytes[row.offset]=row.value;break;
   case 'validMutation':value=frame.valid[row.offset]=row.value;break;
   case 'semanticMutation':value=frame.semantic.set(row.offset,{size:row.size,value:row.value}).size;break;
   case 'replaceBytes':{
    const buffer=new Uint8Array(frame.bytes.length+32),replacement=buffer.subarray(16,buffer.length-16);
    replacement.set(frame.bytes);frame.bytes=replacement;value=frame.bytes.length;break;
   }
   case 'replaceValid':frame.valid=Uint8Array.from(frame.valid);value=frame.valid.length;break;
   case 'replaceView':frame.view=new DataView(frame.bytes.buffer,frame.bytes.byteOffset,frame.bytes.byteLength);value=frame.view.byteLength;break;
   case 'malformedBytes':frame.bytes=new Uint8Array(0);value=frame.bytes.length;break;
   default:value=module[row.operation](module.framePointer(frame,row.offset),...(row.operation==='writeLocal'?[row.value,row.size,row.kind]:[row.size,row.kind]));
  }
 }catch(caught){error={name:caught.constructor.name,message:caught.message};}
 return {value:normalize(value),error};
}
let boundaryChecks=0,sequenceChecks=0,sequenceOperations=0;
const failures=[];
const compare=(label,actual,expected)=>{
 if(JSON.stringify(actual)!==JSON.stringify(expected))failures.push({label,actual,expected});
};
for(const size of sizes){
 const offsets=Array.from(new Set([-1,0,28,31,32,60,63,64,252,255,256,284,288,size-8,size-4,size-1,size,size+1]));
 for(const offset of offsets)for(const width of [0,1,2,3,4,8,31,32,33])
  for(const kind of ['int','float'])for(const operation of ['readLocal','readLocalArgument','writeLocal']){
   const values=operation==='writeLocal'?[0x89abcdef,negativeZero,undefined,'retained host',throwingValue]:[undefined];
   for(const value of values){
    const row={operation,offset,size:width,kind,value};
    const capture=module=>{const frame=initialize(module,size);return {result:execute(module,frame,row),...snapshot(frame)};};
    boundaryChecks++;
    compare({frameSize:size,operation,offset,width,kind,value:normalize(value)},capture(current),capture(reference));
   }
  }
 // Preserve the prior host-index and width coercions beyond the first mask.
 for(const offset of [28.5,64.5,NaN,Infinity,undefined,'28','0x40'])
  for(const width of [undefined,NaN,-1,.5,3.5,'4','invalid'])for(const operation of ['readLocal','readLocalArgument','writeLocal']){
   const row={operation,offset,size:width,kind:'int',value:1};
   const capture=module=>{const frame=initialize(module,size);return {result:execute(module,frame,row),...snapshot(frame)};};
   boundaryChecks++;
   compare({frameSize:size,operation,offset:String(offset),width:String(width)},capture(current),capture(reference));
  }
}
let seed=0x71fc293d;
const next=()=>seed=(Math.imul(seed,1664525)+1013904223)>>>0;
for(const size of sizes)for(let index=0;index<100;index++){
 const rows=[];
 for(let step=0;step<64;step++){
  const width=(next()>>>31)?4:8,offset=(next()%Math.floor((size-width)/4+1))*4;
  const operation=['writeLocal','writeLocal','readLocal','readLocalArgument'][next()>>>30];
  const value=[next()|0,ordinaryFloat,negativeZero,undefined,'retained host',hostValue,0x100000001n][next()%7];
  rows.push({operation,offset,size:width,kind:width===8?'float':'int',value});
  if(step===14)rows.push({operation:'writeLocal',offset:17,size:Math.min(size-17,75),value:undefined});
  if(step===15)rows.push({operation:'writeLocal',offset:28,size:8,kind:'float',value:negativeZero});
  if(step===16)rows.push({operation:'readLocal',offset:28,size:8,kind:'float'});
  if(step===31&&index%4===0)rows.push({operation:'byteMutation',offset:next()%size,value:next()&255});
  if(step===32&&index%4===0)rows.push({operation:'validMutation',offset:next()%size,value:next()&1});
  if(step===31&&index%4===1)rows.push({operation:'replaceBytes'});
  if(step===32&&index%4===1)rows.push({operation:'replaceView'});
  if(step===31&&index%4===2)rows.push({operation:'semanticMutation',offset:next()%Math.floor(size/4)*4,size:8,value:'public semantic slot'});
  if(step===32&&index%4===2)rows.push({operation:'replaceValid'});
  if(step===33&&index%10===0)rows.push({operation:'writeLocal',offset:31,size:3,kind:'int',value:0x123456});
 }
 const capture=module=>{const frame=initialize(module,size);const results=rows.map(row=>execute(module,frame,row));return {results,...snapshot(frame)};};
 sequenceChecks++;sequenceOperations+=rows.length;
 compare({frameSize:size,sequence:index},capture(current),capture(reference));
}
// Replacement storage is the public API. Check that access and coercion errors
// still originate from that storage after high slots have been packed.
for(const size of sizes){
 const rows=[{operation:'malformedBytes'},{operation:'readLocal',offset:64,size:4},
  {operation:'writeLocal',offset:64,size:4,value:throwingValue},{operation:'readLocalArgument',offset:64,size:4}];
 const capture=module=>{const frame=initialize(module,size);return {results:rows.map(row=>execute(module,frame,row)),...snapshot(frame)};};
 sequenceChecks++;sequenceOperations+=rows.length;compare({frameSize:size,sequence:'malformed replacement storage'},capture(current),capture(reference));
}

// Paired, alternating leaf measurements isolate the container; they are not a
// claim about browser FPS. Values and public final images are checked above.
const benchmarkCases=[{name:'small32 integer slots',size:32,offsets:[0,4,8,12,16,20,24,28],float:false},
 {name:'large688 integer slots',size:688,offsets:[256,260,284,288,508,512,640,684],float:false},
 {name:'large688 binary64 slots',size:688,offsets:[256,284,288,504,508,636,640,680],float:true},
 {name:'large688 binary64 Number loads',size:688,offsets:[256,284,288,504,508,636,640,680],float:true,numberLoad:true}];
let sink=0;
function workload(module,configuration,frames){
 const before=performance.now();let checksum=0;
 for(let index=0;index<frames;index++){
  const frame=module.createLocalFrame(configuration.size);
  for(const offset of configuration.offsets){
   const pointer=module.framePointer(frame,offset);
   module.writeLocal(pointer,configuration.float?ordinaryFloat:(index^offset),configuration.float?8:4,configuration.float?'float':'int');
   const result=configuration.numberLoad&&module===current?module.readLocalFloatNumber(pointer):
    module.readLocal(pointer,configuration.float?8:4,configuration.float?'float':'int');
   checksum^=configuration.float?(typeof result==='number'?result:result.toNumber())|0:result;
  }
 }
 sink^=checksum;return performance.now()-before;
}
const performanceResults=[];
for(const configuration of benchmarkCases){
 workload(reference,configuration,300);workload(current,configuration,300);
 const currentMs=[],referenceMs=[],frames=10000;
 for(let pass=0;pass<7;pass++){
  for(const module of pass%2?[current,reference]:[reference,current]){
   const elapsed=workload(module,configuration,frames);
   (module===current?currentMs:referenceMs).push(elapsed);
  }
 }
 const median=values=>[...values].sort((a,b)=>a-b)[Math.floor(values.length/2)];
 performanceResults.push({name:configuration.name,framesPerSample:frames,scalarReadWritePairsPerSample:frames*configuration.offsets.length,
  ...(configuration.numberLoad?{currentLoad:'readLocalFloatNumber',referenceLoad:'readLocal(...,8,"float").toNumber()'}:{}),
  currentMs,referenceMs,medianCurrentMs:median(currentMs),medianReferenceMs:median(referenceMs),speedup:median(referenceMs)/median(currentMs)});
}
const finalPin=hash(containerSource(readFileSync(sourceUrl,'utf8')));
if(finalPin!==sourcePin)failures.push({label:'container source changed during verification',before:sourcePin,after:finalPin});
const report={scope:'Supplementary differential proof of public LocalFrame behavior against the prior JavaScript implementation. Covers high aligned slots, cross-block validity, undefined values, semantic overlap, escaped/public arrays, byte-array replacement, index/width coercion, exact numeric and signed-zero returns, and exception names/messages. The performance samples measure only this container; native fixtures and browser measurements are separate evidence.',
 referenceRevision:revision,referenceContainerSha256:hash(containerSource(referenceSource)),currentContainerSha256:sourcePin,
 frameSizes:sizes,boundaryChecks,sequenceChecks,sequenceOperations,exact:failures.length===0,failures,
 performance:{node:process.version,alternatingSamples:true,results:performanceResults,checksum:sink}};
writeFileSync(process.argv[2]??'/tmp/tact-large-local-frame-review.json',JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({...report,failures:failures.slice(0,3),failureCount:failures.length},null,2));
process.exitCode=failures.length?1:0;
