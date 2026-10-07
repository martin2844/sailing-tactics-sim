import assert from 'node:assert/strict';
import {readFile,mkdir,writeFile} from 'node:fs/promises';
import {stripTypeScriptTypes} from 'node:module';
import {resolve} from 'node:path';
import {makeRuntime} from './independent/fixtures.mjs';
import {studioRigWidth} from '../app/presentation/model-profile.ts';
import {boatChoices} from '../app/native-catalog.ts';
import {nativePlaybackSpeed,playbackRates} from '../app/engine/time/playback.ts';
import {AddressSpaceMemory} from '../public/legacy/src/runtime/memory.js';
import {PoseyRng} from '../public/legacy/src/engine/integer-core.js';
import {GdiTrace} from '../public/legacy/versions/2010-en/src/render/gdi.js';
import {nativeModelDrawBoatNumber} from '../public/legacy/versions/2010-en/src/render/drawing-functions.js';
import {createOriginalRenderer} from '../public/legacy/versions/2010-en/src/render/index.js';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});
// Vite resolves these extensionless imports in production. Resolve the two
// executable imports for Node while evaluating the actual extractor source.
let source=await readFile(new URL('../app/native-models.ts',import.meta.url),'utf8');
for(const name of ['./native-visuals','./presentation/model-profile'])source=source.replaceAll("'"+name+"'",JSON.stringify(new URL('../app/'+name.slice(2)+'.ts',import.meta.url).href));
const {createModelExtractor}=await import('data:text/javascript;base64,'+Buffer.from(stripTypeScriptTypes(source)).toString('base64'));
const shore=JSON.parse(await readFile(new URL('../public/legacy/versions/2010-en/assets/data/initial-shoreline-stack.json',import.meta.url),'utf8'));
const classes=[];
for(const boat of boatChoices){
 const {memory,engine}=makeRuntime({setupCommands:[32799,32816,boat.command,32806,32909],speed:6});
 const extractor=createModelExtractor({memory,rng:engine.random.presentation,options:{...engine.options,...createOriginalRenderer({initialShoreStack:shore,smoothGraphics:true})},objects:engine.objects,ModelMemory:AddressSpaceMemory,ModelRng:PoseyRng,TraceDc:GdiTrace,modelDraw:nativeModelDrawBoatNumber});
 const states=[];
 for(const state of ['initial','sailing']){
  engine.restoreSpeed(6);
  if(state==='sailing'){engine.key(67);for(let n=0;n<40;n++)engine.step();}
  let reference;
  const samples=[];
  for(const rate of playbackRates){
   engine.restoreSpeed(nativePlaybackSpeed({mode:'clock',rate}));
   const image=memory.bytes.slice(),random=engine.random.snapshot(),packet=extractor.extract([1],studioRigWidth);
   assert.deepEqual(memory.bytes,image,boat.label+'/'+state+'/'+rate+' memory isolation');
   assert.deepEqual(engine.random.snapshot(),random,boat.label+'/'+state+'/'+rate+' RNG isolation');
   if(reference)for(const name of ['positions','records','colors','boats'])assert.deepEqual(packet[name],reference[name],boat.label+'/'+state+'/'+rate+'/'+name);
   else reference=packet;
   samples.push({rate,nativeSpeed:engine.selectedSpeed,vertices:packet.positions.length/3});
  }
  states.push({state,time:memory.readF64(0x5359f0),samples});
 }
 classes.push({id:boat.value,label:boat.label,states});
}
const receipt={passed:true,classes,scope:'Actual native extractor and recovered drawing routines: all27 classes, two physical states and eight multipliers. Byte-identical packets at each fixed physical state; full memory/RNG isolation for every extraction. Node checks geometry data, not all-class visual appearance or wall-time performance.'};
await writeFile(resolve(output,'verification.json'),JSON.stringify(receipt,null,2));
console.log(JSON.stringify({passed:true,classes:classes.length,extractions:classes.length*2*playbackRates.length}));
