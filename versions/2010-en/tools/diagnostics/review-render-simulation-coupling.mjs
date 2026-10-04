// Drawing may change pixels, but must leave every subsequent physics read,
// write and random result unchanged. This diagnostic observes original native
// retained profiles; it is a correctness trace, never a performance benchmark.
import fs from 'node:fs';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {createHash} from 'node:crypto';
import {performance} from 'node:perf_hooks';
import assert from 'node:assert/strict';
import {loadPE32,AddressSpaceMemory} from '../../../../src/runtime/memory.js';
import {withX87ControlWord} from '../../../../src/runtime/float80.js';
import {PoseyRng} from '../../../../src/engine/integer-core.js';
import {createCapturedTrig} from '../../src/engine/native-trig.js';
import {createEngineBindings} from '../../src/engine/port.js';
import {initializeGdiObjects} from '../../src/engine/application.js';
import {initializeRace} from '../../src/engine/initialization.js';
import {handleMenuCommand} from '../../src/engine/menu-controller.js';
import {advanceFrame} from '../../src/engine/frame.js';
import {createOriginalRenderer} from '../../src/render/index.js';
import {drawSimulationFrame} from '../../src/render/paint-lifecycle.js';
import {GdiTrace} from '../../src/render/gdi.js';
import {assertNativeProvenance} from '../../tests/native-state.js';
import {resetOriginalCStringContents,writeCString} from '../../src/render/text.js';

const repo=fileURLToPath(new URL('../../../../',import.meta.url));
const edition='versions/2010-en/';
const digest=bytes=>createHash('sha256').update(bytes).digest('hex');
const source=fs.readFileSync(path.join(repo,edition+'runtime/Tactics2010EnglishPreserved.exe'));
const json=file=>JSON.parse(fs.readFileSync(path.join(repo,edition+file),'utf8'));
const fixtureFiles=['original-retained-speed-ten-frames.json','original-retained-speed-ten-long-frames.json',
  'original-retained-frames.json','original-retained-graphics-frames.json'];
const trig=createCapturedTrig(json('assets/data/x87-trig.json'),json('assets/data/x87-stored-trig.json'));
const engine=createEngineBindings();
const originals=AddressSpaceMemory.prototype;
const widths={U8:1,I8:1,U16:2,I16:2,U32:4,I32:4,F32:4,F64:8};
const methods=[...Object.keys(widths).flatMap(kind=>['read'+kind,'write'+kind]),'readBytes','writeBytes','moveBytes'];
const ranges=values=>{
  const sorted=[...values].sort((a,b)=>a-b),result=[];
  for(const address of sorted){const last=result.at(-1);if(last&&address===last.address+last.size)last.size++;
    else result.push({address,size:1});}
  return result.map(row=>({...row,hex:'0x'+row.address.toString(16)}));
};
const readImage=(memory,address,size)=>originals.readBytes.call(memory,address,size);

// Hooks are installed only during the chosen phase and restored before the
// ordinary rendering graph runs. Thus raw water kernels retain their normal
// memory-domain eligibility in the differential comparison.
function observeMemory(memory,onRead,onWrite){
  const saved=methods.map(name=>[name,Object.getOwnPropertyDescriptor(memory,name)]);
  for(const name of methods){
    Object.defineProperty(memory,name,{configurable:true,writable:true,value:function(...args){
      const [address,value]=args,kind=name.replace(/^(?:read|write)/,'');
      if(name==='moveBytes'){
        onRead?.(name,value,args[2],readImage(this,value,args[2]));
        const result=originals[name].apply(this,args);
        onWrite?.(name,address,args[2],readImage(this,address,args[2]));return result;
      }
      const size=widths[kind]??(name==='readBytes'?value:value.byteLength??value.length);
      if(name.startsWith('read')){
        const result=originals[name].apply(this,args);
        onRead?.(name,address,size,readImage(this,address,size));return result;
      }
      const result=originals[name].apply(this,args);
      onWrite?.(name,address,size,readImage(this,address,size));return result;
    }});
  }
  return ()=>{for(const [name,descriptor]of saved){if(descriptor)Object.defineProperty(memory,name,descriptor);else delete memory[name];}};
}

export function runCouplingProfile(fixture,profile,{smoothGraphics=false,frameLimit=3,ledger=false}={}){
  const memory=loadPE32(source),rng=new PoseyRng(),baseline=assertNativeProvenance(source,fixture);
  const render=createOriginalRenderer(smoothGraphics?{smoothGraphics:true}:{});
  const records=[],previousRenderWrites=new Set(),coupledBytes=new Set(),engineReadBytes=new Set(),renderWriteBytes=new Set();
  let objects=new Map(),phase='caller',currentRandoms=[],frames=0;
  const rand=rng.rand;
  rng.rand=function(){const before=this.state,result=rand.call(this);currentRandoms.push({phase,before,result,after:this.state});return result;};
  for(const row of fixture.cases.filter(candidate=>candidate.profile===profile.name)){
    if(row.phase==='frame'&&frames>=frameLimit)break;
    if(!row.continue){memory.writeBytes(fixture.mutableBlock.address,baseline);resetOriginalCStringContents(memory);}
    if('seed'in row||!row.continue)rng.srand(row.seed??1);
    for(const [field,value]of Object.entries(row.inputs??{}))memory.writeI32(fixture.integerInputs[field],value);
    for(const [field,value]of Object.entries(row.doubleInputs??{}))memory.writeF64(fixture.doubleInputs[field],value);
    for(const patch of row.patches??[])memory.writeBytes(patch.address,Buffer.from(patch.bytes,'hex'));
    for(const string of row.strings??[])writeCString(memory,string.address,new TextDecoder('windows-1252').decode(Buffer.from(string.bytes,'hex')));
    let ticks=0,pixels=0,restoreRender;
    const sounds=[],callbacks=[],hash=createHash('sha256'),engineWritten=new Set(),engineReads=new Set();
    currentRandoms=[];phase='caller';
    const dc=new GdiTrace({objects,readPixel(){
      if(pixels>=row.host.pixels.length)throw new RangeError('Coupling trace exceeded declared native pixel inputs');
      return row.host.pixels[pixels++];
    }});
    const trace=(name,address,size,bytes)=>{hash.update(name+':'+address+':'+size+':');hash.update(bytes);};
    const options={engine,render,trig,rng,
      playSound:event=>{sounds.push(event);return 1;},messageBeep:type=>{dc.emit({op:'messageBeep',type});return 1;},
      ...(row.host?{menuHeight:row.host.menuHeight,getCursorPos:()=>({x:row.host.cursor[0],y:row.host.cursor[1]}),
        getTickCount:()=>(row.host.tickStart+ticks++)>>>0}:{}),
      advanceFrame(memory,rng,exactOptions){
        phase='engine';
        const restore=observeMemory(memory,(name,address,size,bytes)=>{
          trace(name,address,size,bytes);
          for(let offset=0;offset<size;offset++){
            const byte=address+offset;engineReads.add(byte);engineReadBytes.add(byte);
            if(!engineWritten.has(byte)&&previousRenderWrites.has(byte))coupledBytes.add(byte);
          }
        },(name,address,size,bytes)=>{
          trace(name,address,size,bytes);for(let offset=0;offset<size;offset++)engineWritten.add(address+offset);
        });
        let started;
        try{started=advanceFrame(memory,rng,exactOptions);}finally{restore();}
        phase='render';previousRenderWrites.clear();
        if(ledger)restoreRender=observeMemory(memory,undefined,(_name,address,size)=>{
          for(let offset=0;offset<size;offset++){previousRenderWrites.add(address+offset);renderWriteBytes.add(address+offset);}
        });
        return started;
      },
    };
    try{withX87ControlWord(0x027f,()=>{
      if(row.phase==='initialize'){
        if(profile.constructorGraphics||fixture.inputEvidence?.constructorObjectCount===90)objects=initializeGdiObjects(memory);
        return initializeRace(memory,rng,options);
      }
      if(row.phase==='select-speed-ten')return handleMenuCommand(memory,row.identifier,{...options,windowHandle:row.windowHandle,
        invalidateRect:event=>callbacks.push({type:'invalidateRect',...event})});
      return drawSimulationFrame(memory,dc,rng,options);
    });}finally{restoreRender?.();}
    if(!smoothGraphics){
      assert.equal(digest(readImage(memory,fixture.mutableBlock.address,baseline.length)),row.expected.mutableSha256,
        profile.name+' '+row.phase+' '+(row.frame??'')+': exact trace remains native');
      assert.equal(rng.state,row.expected.rngState);
      if(row.phase==='frame')assert.deepEqual(dc.events,row.expected.drawingCommands,'exact instrumented GDI remains native');
    }
    records.push({phase:row.phase,frame:row.frame,engineTraceSha256:hash.digest('hex'),
      rngState:rng.state,randoms:currentRandoms.slice(),sounds,callbacks,ticks,pixels,
      engineReads,engineWritten,image:readImage(memory,fixture.mutableBlock.address,baseline.length),
      drawingCommandCount:dc.events.length});
    if(row.phase==='frame')frames++;
  }
  return {records,frameCount:frames,coupledRanges:ranges(coupledBytes),engineReadBytes,renderWriteBytes,
    renderingWritesReadByEngine:ranges(new Set([...renderWriteBytes].filter(address=>engineReadBytes.has(address))))};
}

export function reviewRenderSimulationCoupling({frameLimit=3,ledger=false,files=fixtureFiles}={}){
  const profiles=[],failures=[];
  for(const file of files){
    const fixture=json('tests/fixtures/'+file);
    for(const profile of fixture.profiles){
      const exact=runCouplingProfile(fixture,profile,{frameLimit,ledger});
      const smooth=ledger?undefined:runCouplingProfile(fixture,profile,{smoothGraphics:true,frameLimit});
      const rows=[];
      for(const [index,row]of exact.records.entries()){
        const candidate=smooth?.records[index];
        const changed=[];
        if(candidate)for(let offset=0;offset<row.image.length;offset++)if(row.image[offset]!==candidate.image[offset])changed.push(fixture.mutableBlock.address+offset);
        const fields=candidate?['engineTraceSha256','rngState','randoms','sounds','callbacks','ticks','pixels']:[];
        const mismatches=fields.filter(field=>!Object.is(row[field],candidate[field])&&JSON.stringify(row[field])!==JSON.stringify(candidate[field]));
        if(mismatches.length)failures.push({profile:profile.name,phase:row.phase,frame:row.frame,mismatches});
        rows.push({phase:row.phase,frame:row.frame,engineTraceSha256:row.engineTraceSha256,
          ...(candidate?{smoothEngineTraceSha256:candidate.engineTraceSha256}:{}),
          rngState:row.rngState,...(candidate?{smoothRngState:candidate.rngState}:{}),
          engineRandomCalls:row.randoms.filter(event=>event.phase==='engine').length,
          renderRandomCalls:row.randoms.filter(event=>event.phase==='render').length,
          engineReadByteCount:row.engineReads.size,engineWrittenByteCount:row.engineWritten.size,
          changedByteCount:changed.length,changedRanges:ranges(changed),mismatches});
      }
      profiles.push({file,profile:profile.name,frames:exact.frameCount,rows,
        ...(ledger?{readBeforeOverwriteCoupledRanges:exact.coupledRanges,
          renderingWritesReadByEngine:exact.renderingWritesReadByEngine}:{}),
      });
    }
  }
  return {scope:ledger?'Native-validated exact instrumented rendering writes and subsequent engine reads before overwrite.'
    :'Real exact and smooth renderers; exact ordered engine byte read/write traces, phase-labelled RNG calls, sounds and host consumption. Declared native GetPixel answers, not Canvas raster feedback.',
    frameLimit,ledger,profiles,failures,pass:failures.length===0};
}

if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)){
  const frameLimit=Number(process.argv.find(value=>value.startsWith('--frames='))?.split('=')[1]??3);
  const ledger=process.argv.includes('--ledger'),start=performance.now();
  const report=reviewRenderSimulationCoupling({frameLimit,ledger});
  report.elapsedMs=performance.now()-start;
  const files=['src/runtime/memory.js','src/runtime/float80.js','src/engine/integer-core.js',
    ...['src/render/float-values.js','src/render/smooth-math.js','src/render/projection-smooth.js',
      'src/render/projection-output-fast.js','src/render/projection-fast.js','src/render/drawing-functions.js',
      'src/render/render-functions.js','src/render/paint-lifecycle.js','src/render/dependencies.js','src/render/index.js',
      'src/engine/frame.js','src/engine/port.js','tools/diagnostics/review-render-simulation-coupling.mjs',
      ...fixtureFiles.map(file=>'tests/fixtures/'+file)].map(file=>edition+file)];
  report.sourceSha256=Object.fromEntries(files.map(file=>[file,digest(fs.readFileSync(path.join(repo,file)))]));
  const output=path.join(repo,edition+'analysis/browser-performance/render-simulation-'+(ledger?'coupling-ledger':'smooth-review')+'.json');
  fs.writeFileSync(output,JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({output,elapsedMs:report.elapsedMs,profiles:report.profiles.length,
    frames:report.profiles.reduce((sum,profile)=>sum+profile.frames,0),pass:report.pass,failures:report.failures}));
  if(!report.pass)process.exitCode=1;
}
