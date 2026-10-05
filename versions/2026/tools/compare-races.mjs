import {readFile,writeFile,readdir} from 'node:fs/promises';
import {resolve,join} from 'node:path';
import {gunzipSync} from 'node:zlib';
import {createHash} from 'node:crypto';
const [first,second,destination]=process.argv.slice(2);
if(!destination||process.argv.length!==5)throw new Error('Usage: node compare-races.mjs FIRST_DIRECTORY SECOND_DIRECTORY NEW_REPORT.json');
const a=JSON.parse(await readFile(resolve(first,'report.json'))),b=JSON.parse(await readFile(resolve(second,'report.json')));
const finish=r=>r.finishSnapshot??r.finalSnapshot;
const equal=(x,y)=>JSON.stringify(x)===JSON.stringify(y);
const report={format:1,first,second,
  scope:'Unmasked whole-image hashes are compared separately from sampled telemetry, RNG, controls and transitions. A matching sampled trace is not a whole-state determinism certificate.',
  bothComplete:a.complete===true&&b.complete===true,
  entryImageEqual:a.setup.entry.memorySha256===b.setup.entry.memorySha256,
  finishImageEqual:finish(a).memorySha256===finish(b).memorySha256,
  finishRngEqual:finish(a).rngState===finish(b).rngState,
  controlsEqual:equal(a.commands,b.commands),transitionsEqual:equal(a.transitions,b.transitions),samplesEqual:equal(a.samples,b.samples)};
try{
  const x=gunzipSync(await readFile(resolve(first,'finish-memory.bin.gz'))),y=gunzipSync(await readFile(resolve(second,'finish-memory.bin.gz')));
  if(x.length!==y.length)throw new Error('Image sizes differ');
  for(const [bytes,snapshot]of [[x,finish(a)],[y,finish(b)]])if(bytes.length!==snapshot.memorySize||createHash('sha256').update(bytes).digest('hex')!==snapshot.memorySha256)throw new Error('Archived image does not match its captured snapshot');
  const words=[];let differentBytes=0;
  for(let i=0;i<x.length;i++){if(x[i]!==y[i])differentBytes++;}
  for(let i=0;i<x.length;i+=4){if(!x.subarray(i,i+4).equals(y.subarray(i,i+4)))words.push({address:'0x'+(finish(a).memoryBase+i).toString(16),first:x.subarray(i,i+4).toString('hex'),second:y.subarray(i,i+4).toString('hex')});}
  report.byteDifference={differentBytes,words};
  const root=resolve(new URL('../../../',import.meta.url).pathname);
  const files=[];
  for(const folder of ['versions/2010-en/src/engine','versions/2010-en/src/render']){
    for(const name of await readdir(join(root,folder)))if(name.endsWith('.js'))files.push(join(folder,name));
  }
  report.literalReferences={};
  for(const word of words){
    const hits=[];
    for(const file of files){const lines=(await readFile(join(root,file),'utf8')).split('\n');
      lines.forEach((line,index)=>{if(line.includes(word.address))hits.push({file,line:index+1,text:line.trim().slice(0,600)});});}
    report.literalReferences[word.address]=hits;
  }
  report.referenceScope='Literal source mentions are candidate readers/writers, not exhaustive alias analysis; computed addresses may reference the same bytes.';
}catch(error){if(error.code!=='ENOENT')throw error;report.byteDifferenceUnavailable='An earlier collector saved hashes without raw finish images.';}
await writeFile(resolve(destination),JSON.stringify(report,null,2)+'\n',{flag:'wx'});
console.log(JSON.stringify({...report,literalReferences:report.literalReferences?Object.keys(report.literalReferences).length:undefined},null,2));
