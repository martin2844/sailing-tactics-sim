import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';
import {execFileSync} from 'node:child_process';
import {resolve} from 'node:path';
import {fileURLToPath} from 'node:url';
const out=resolve(process.argv[2]);await mkdir(out,{recursive:true});
const namespaces=await Promise.all(['../../../','../public/legacy/'].map(async prefix=>{
  const load=path=>import(new URL(prefix+path,import.meta.url));
  const [memory,gdi,float,drawing]=await Promise.all([
    load('src/runtime/memory.js'),load('src/render/gdi.js'),load('src/runtime/float80.js'),
    load('versions/2010-en/src/render/drawing-functions.js')]);
  float.setX87ControlWord(0x027f);return {memory,gdi,float,drawing};
}));
const modes=[{numberRendering:true},{numberRendering:false},
  {numberRendering:false,retainedDrawingStack:{4459376:[]}}];
function draw(ns,options,x,span,dy){
  const memory=new ns.memory.AddressSpaceMemory(0x21c000);
  for(const[a,v]of[[0x50040c,1],[0x5230dc,1],[0x5362d4,180],[0x4fe2a8,1200]])memory.writeI32(a,v);
  for(let i=0;i<32;i++)memory.writeI32(0x512d70+i*4,100);
  memory.writeF64(0x4cc678,-.001);memory.writeF64(0x4cc3f0,.001);
  const dc=new ns.gdi.GdiTrace({readPixel:()=>0}),rng={state:123};
  ns.drawing.originalDrawing00440b70(memory,dc,rng,options,x,400,x+span,400+dy,600,1,0,0,1024,700,300,0);
  return {bytes:memory.bytes,events:dc.events,rng:rng.state};
}
const probeBinary=resolve(out,'shore-x87-probe');
execFileSync('cc',['-O0',fileURLToPath(new URL('./shore-x87-probe.c',import.meta.url)),'-o',probeBinary]);
const hardware=JSON.parse(execFileSync(probeBinary,{encoding:'utf8'}));
for(const row of hardware.slice(0,3)){assert.equal(row.result,'8000000000000000');assert.equal(row.lowDWORD,0);assert.ok(row.status&1);}
assert.equal(hardware[3].lowDWORD,20);
const zeroCases=[];let finiteComparisons=0;
for(const[mode,options]of modes.entries()){
  for(const x of[0,300,1024])for(const dy of[-40,0,40]){
    assert.throws(()=>draw(namespaces[0],options,x,0,dy),/Float80 division by zero/);
    const fixed=draw(namespaces[1],options,x,0,dy);
    assert.equal(fixed.rng,123);assert.ok(fixed.events.some(e=>e.op==='polygon'));
    zeroCases.push({mode,x,dy,events:fixed.events.length,rng:fixed.rng});
  }
  for(const x of[0,300,1024])for(const span of[-100,-2,-1,1,2,100])for(const dy of[-40,0,40]){
    assert.deepEqual(draw(namespaces[1],options,x,span,dy),draw(namespaces[0],options,x,span,dy));finiteComparisons++;
  }
}
// The general numeric runtime continues to reject unsupported exceptions.
assert.throws(()=>namespaces[1].float.Float80.fromNumber(1).divide(namespaces[1].float.Float80.fromNumber(0)),/division by zero/);
const report={passed:true,hardware,zeroCases,finiteComparisons,scope:'Actual recovered shore routine: frozen crash reproduction, adapted Number/exact/retained-frame paths, GDI/memory/RNG equality for nonzero spans; native x87 hardware conversion. Not a naturally sailed race.'};
await writeFile(resolve(out,'verification.json'),JSON.stringify(report,null,2));
console.log(JSON.stringify({passed:true,zeroCases:zeroCases.length,finiteComparisons}));
