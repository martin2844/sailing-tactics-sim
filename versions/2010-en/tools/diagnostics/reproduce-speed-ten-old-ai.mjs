import { createHash } from 'node:crypto';
import { execFileSync } from 'node:child_process';
import { readFile,writeFile } from 'node:fs/promises';
import { createNativeHarness } from '../../tests/native-state.js';
import { createCapturedTrig } from '../../src/engine/native-trig.js';
import { createEngineBindings } from '../../src/engine/port.js';
import { initializeGdiObjects } from '../../src/engine/application.js';
import { initializeRace } from '../../src/engine/initialization.js';
import { handleMenuCommand } from '../../src/engine/menu-controller.js';
import { createOriginalRenderer } from '../../src/render/index.js';
import { drawSimulationFrame } from '../../src/render/paint-lifecycle.js';
import { GdiTrace } from '../../src/render/gdi.js';

const edition=new URL('../../',import.meta.url),root=new URL('../../',edition);
const json=async path=>JSON.parse(await readFile(new URL(path,edition),'utf8'));
const source=await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe',edition));
const fixture=await json('tests/fixtures/original-retained-speed-ten-long-frames.json');
const aiUrl=new URL('src/engine/ai-functions.js',edition);
const oldSource=execFileSync('git',['show','15fd6ac:versions/2010-en/src/engine/ai-functions.js'],{cwd:root,encoding:'utf8'});
const standalone=oldSource.replace(/from (['"])([^'"]+)\1/g,(_match,_quote,specifier)=>`from ${JSON.stringify(new URL(specifier,aiUrl).href)}`);
const oldAI=await import('data:text/javascript;base64,'+Buffer.from(standalone).toString('base64'));
const trig=createCapturedTrig(await json('assets/data/x87-trig.json'),await json('assets/data/x87-stored-trig.json'));
let lastBoat;
const engine={...createEngineBindings(),updateBoatWindAndAI:(memory,boat,rng,options)=>{
  lastBoat=boat;return oldAI.originalUpdateBoatWindAndAI(memory,rng,{...options,rng},boat);
}};
const render=createOriginalRenderer(),harness=createNativeHarness(source,fixture);
let objects=new Map(),matchedFrames=0,failure;
for(const [index,row] of fixture.cases.entries()){
  let pixels=0,ticks=0;const sounds=[],callbacks=[];
  const dc=new GdiTrace({objects,readPixel:()=>row.host.pixels[pixels++]});
  const options={engine,render,trig,
    playSound:event=>{sounds.push(event);return 1;},messageBeep:type=>{dc.emit({op:'messageBeep',type});return 1;},
    ...(row.host?{menuHeight:row.host.menuHeight,getCursorPos:()=>({x:row.host.cursor[0],y:row.host.cursor[1]}),
      getTickCount:()=>(row.host.tickStart+ticks++)>>>0}:{}),
  };
  try{
    harness.check(row,index,(memory,rng)=>{
      if(row.phase==='initialize'){objects=initializeGdiObjects(memory);return initializeRace(memory,rng,options);}
      if(row.phase==='select-speed-ten')return handleMenuCommand(memory,row.identifier,{...options,windowHandle:row.windowHandle,
        invalidateRect:event=>callbacks.push({type:'invalidateRect',...event})});
      return drawSimulationFrame(memory,dc,rng,options);
    });
    if(row.phase==='frame')matchedFrames++;
  }catch(error){
    failure={case:index,phase:row.phase,frame:row.frame,boat:lastBoat,name:error.constructor.name,message:error.message,
      clock:harness.memory.readI32(0x4f8cd0),preciseTime:harness.memory.readF64(0x5359f0),
      speed:harness.memory.readI32(0x4da174),divisor:harness.memory.readI32(0x4da178),
      fleet:harness.memory.readI32(0x4da194),engaged:harness.memory.readI32(0x4f7f98+lastBoat*4),
      targetDistance:harness.memory.readI32(0x4f8300+lastBoat*4)};break;
  }
}
const report={format:1,checkedAt:new Date().toISOString(),oldCommit:'15fd6accd0eb2f191d18bd1d9f8a310c68660839',
  oldAiSourceSha256:createHash('sha256').update(oldSource).digest('hex'),sourceSha256:fixture.sourceSha256,
  fixture:'tests/fixtures/original-retained-speed-ten-long-frames.json',matchedNativeFramesBeforeFailure:matchedFrames,failure,
  scope:'Diagnostic replay of the same retained original native input/state expectations using the previous published AI module. Imports point to current exact numeric helpers; production files and native expectations are unchanged. Prior frames retain complete native mutable-state/RNG hashes. This identifies an original gameplay trigger for the decompiler conjunction ordering defect.'};
await writeFile(new URL('analysis/browser-performance/speed-ten-crash-reproduction.json',edition),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify(report));
if(failure?.name!=='RangeError'||failure?.message!=='Original C reads an undefined retained local byte')process.exitCode=1;
