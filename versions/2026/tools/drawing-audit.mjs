import {readFile,writeFile,readdir,mkdir} from 'node:fs/promises';
import {resolve} from 'node:path';
import {createHash} from 'node:crypto';
import {gzipSync,gunzipSync} from 'node:zlib';
import {referenceSession,closeReferenceServer} from './reference-session.mjs';
const output=resolve(process.argv[2]??'');if(!process.argv[2]||process.argv.length!==3)throw new Error('Usage: node drawing-audit.mjs NEW_DIRECTORY');await mkdir(output);
const root=new URL('../../../',import.meta.url),inventory=[];
for(const folder of ['versions/2010-en/src/render/','versions/2010-en/src/engine/']){
  for(const name of await readdir(new URL(folder,root))){if(!name.endsWith('.js'))continue;const path=folder+name,source=await readFile(new URL(path,root),'utf8');let routine='module';
    source.split('\n').forEach((line,index)=>{
      const declaration=line.match(/^(?:export )?function\s+(\w+)/);if(declaration)routine=declaration[1];
      for(const [kind,pattern]of Object.entries({write:/\b(?:w32|w64|w|wb|writePointer|memory\.write\w+)\s*\(/,read:/\b(?:r32|r64|r|rb|readPointer|memory\.read\w+)\s*\(/,rng:/scaledRandom\s*\(|\.rand\s*\(|0x41e000/,retained:/retainedDrawingStack|restoreShoreStackFrame|saveShoreStackFrame|createLocalFrame|scalarStack/,pixel:/\.getPixel\s*\(/})){
        if(pattern.test(line))inventory.push({path,line:index+1,routine,kind,addresses:[...new Set(line.match(/0x[\da-f]+/gi)??[])],text:line.trim().slice(0,1200)});
      }
    });
  }
}
await writeFile(resolve(output,'static-inventory.json'),JSON.stringify({scope:'Conservative source-line candidates, including computed addresses; not complete alias analysis or proof of purity.',inventory},null,2)+'\n');
const observer=`(()=>{
  const s=tact.state,m=s.memory,events=[],stack=[],wrappedDc=new WeakSet();let randomCalls=0,pixelCalls=0;
  const rand=s.rng.rand;s.rng.rand=function(){randomCalls++;return rand.call(this);};
  const changed=(a,b)=>{const out=[];for(let i=0;i<a.length;i+=4)if(a[i]!==b[i]||a[i+1]!==b[i+1]||a[i+2]!==b[i+2]||a[i+3]!==b[i+3])out.push('0x'+(m.base+i).toString(16));return out;};
  for(const name of Object.keys(s.options)){
    if(!/^(draw|update|initialize|integrate|saveRaceState|restoreRaceState|respawn)/.test(name)||typeof s.options[name]!=='function')continue;
    const original=s.options[name];s.options[name]=function(...args){
      const dc=name.startsWith('draw')?args[1]:null;
      if(dc&&typeof dc.getPixel==='function'&&!wrappedDc.has(dc)){wrappedDc.add(dc);const get=dc.getPixel;dc.getPixel=function(...a){pixelCalls++;return get.apply(this,a);};}
      const before=m.bytes.slice(),rngBefore=s.rng.state,rc=randomCalls,pc=pixelCalls,shore=s.options.shoreStack?.snapshot();
      stack.push(name);
      try{return original.apply(this,args);}finally{stack.pop();events.push({frame:s.frames,name,parent:stack.at(-1)??'paint',boat:name==='updateBoatWindAndAI'||name==='updateBoatDynamics'?args[1]:null,netChangedWords:changed(before,m.bytes),rngBefore,rngAfter:s.rng.state,randomCalls:randomCalls-rc,pixelCalls:pixelCalls-pc,shoreBefore:shore,shoreAfter:s.options.shoreStack?.snapshot()});}
    };
  }
  globalThis.auditTrace={events,get randomCalls(){return randomCalls;},get pixelCalls(){return pixelCalls;}};
})()`;
const report={format:1,scope:'Bounded same-input comparison. Observer forwards original calls, records net image changes per phase, RNG calls, real GetPixel calls and retained shoreline state. Net deltas omit intermediate/restored writes; static inventory and conservative dependencies cover that limitation.',runs:[]};
try{
  for(const traced of [false,true]){
    const session=await referenceSession();
    try{
      if(traced)await session.browser.evaluate(observer);
      const stages=[];
      for(const [label,commands,count]of [['racing',[],12],['forecast',[32907],1],['dismiss forecast',[],1],['wind chart',[32902],1],['dismiss chart',[],1]]){
        if(label.startsWith('dismiss'))await session.key('Space',' ',32);
        for(const id of commands)await session.command(id);
        for(let i=0;i<count;i++)await session.step(label+' '+i);
        const snapshot=await session.snapshot();
        const bytes=Buffer.from(await session.browser.evaluate(`(()=>{const a=tact.state.memory.bytes;let s='';for(let i=0;i<a.length;i+=8192)s+=String.fromCharCode(...a.subarray(i,i+8192));return btoa(s);})()`),'base64');
        const image=(traced?'traced-':'plain-')+stages.length+'.bin.gz';await writeFile(resolve(output,image),gzipSync(bytes));
        stages.push({label,snapshot,image});
      }
      report.runs.push({traced,setup:session.setup,stages,modules:await session.modules(),...(traced?{trace:await session.browser.evaluate('({events:auditTrace.events,randomCalls:auditTrace.randomCalls,pixelCalls:auditTrace.pixelCalls,shore:tact.state.options.shoreStack?.snapshot()})')}:{})});
    }finally{await session.close();}
  }
  report.comparisons=[];
  for(let i=0;i<report.runs[0].stages.length;i++){
    const a=report.runs[0].stages[i],b=report.runs[1].stages[i],x=gunzipSync(await readFile(resolve(output,a.image))),y=gunzipSync(await readFile(resolve(output,b.image))),words=[];
    for(let offset=0;offset<x.length;offset+=4)if(!x.subarray(offset,offset+4).equals(y.subarray(offset,offset+4)))words.push({address:'0x'+(a.snapshot.memoryBase+offset).toString(16),plain:x.subarray(offset,offset+4).toString('hex'),traced:y.subarray(offset,offset+4).toString('hex')});
    report.comparisons.push({stage:a.label,imageEqual:words.length===0,rngEqual:a.snapshot.rngState===b.snapshot.rngState,words});
  }
  report.passed=report.comparisons.every(c=>c.imageEqual&&c.rngEqual);
  if(!report.passed)process.exitCode=1;
}catch(error){report.failure=String(error.stack??error);process.exitCode=1;}
finally{await closeReferenceServer();report.collectorSha256=createHash('sha256').update(await readFile(new URL(import.meta.url))).digest('hex');await writeFile(resolve(output,'trace.json'),JSON.stringify(report,null,2)+'\n');}
console.log(JSON.stringify({passed:report.passed,failure:report.failure,comparisons:report.comparisons?.map(c=>({...c,words:c.words.length})),runs:report.runs.map(r=>({traced:r.traced,traceEvents:r.trace?.events.length,randomCalls:r.trace?.randomCalls,pixelCalls:r.trace?.pixelCalls}))},null,2));
