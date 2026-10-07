import {readFile,mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {createHash} from 'node:crypto';
import {EngineRuntime} from '../../app/engine/runtime.ts';
import {loadOriginalData} from '../../public/legacy/versions/2010-en/src/runtime/original-data.js';
import {initializeApplication} from '../../public/legacy/versions/2010-en/src/engine/application.js';
import {initializeBoatOptions} from '../../public/legacy/versions/2010-en/src/engine/boat-options.js';
import {initializeRace} from '../../public/legacy/versions/2010-en/src/engine/initialization.js';
import {createEngineBindings} from '../../public/legacy/versions/2010-en/src/engine/port.js';
import {handleMenuCommand} from '../../public/legacy/versions/2010-en/src/engine/menu-controller.js';
import {handleKeyDown} from '../../public/legacy/versions/2010-en/src/engine/keyboard.js';
import {createCapturedTrig} from '../../public/legacy/versions/2010-en/src/engine/native-trig.js';
import {advanceFrame} from '../../public/legacy/versions/2010-en/src/engine/frame.js';
import {setX87ControlWord,Float80} from '../../public/legacy/src/runtime/float80.js';
import {sinCosX87} from '../../public/legacy/src/runtime/transcendentals.js';
import {scaledRandom} from '../../public/legacy/src/engine/integer-core.js';
import {nearestWaypointDistance} from '../../public/legacy/versions/2010-en/src/engine/waypoints.js';
import {targetRelativeBearing} from '../../public/legacy/versions/2010-en/src/engine/ai-geometry.js';
import {distanceToBoat} from '../../public/legacy/versions/2010-en/src/engine/movement.js';
const output=resolve(process.argv[2]);await mkdir(output);
const data=new URL('../../public/legacy/versions/2010-en/assets/data/',import.meta.url),json=async name=>JSON.parse(await readFile(new URL(name,data),'utf8'));
const manifest=await json('original-memory.json'),segments=new Map(await Promise.all(manifest.segments.map(async s=>[s.file,new Uint8Array(await readFile(new URL(s.file,data)))])));
setX87ControlWord(0x027f);
const trig=createCapturedTrig(await json('x87-trig.json'),await json('x87-stored-trig.json')),integerTrig=await json('trig-tables.json');
const numeric={initializeApplication,initializeBoatOptions,initializeRace,advanceFrame,command:handleMenuCommand,key:handleKeyDown,bindings:createEngineBindings,
 number:Float80.fromNumber,integer:Float80.fromInteger,sinCos:sinCosX87,scaledRandom,nearest:nearestWaypointDistance,bearing:(m,x,y,boat)=>targetRelativeBearing(m,x,y,0,boat),distance:distanceToBoat};
const hash=m=>createHash('sha256').update(m.bytes).digest('hex');
const runs=[];
for(const cosmeticWork of[0,7]){
 const memory=loadOriginalData(manifest,segments),engine=new EngineRuntime(memory,numeric,{seed:1546300800,setupCommands:[32799,32816,32789,32806,32909],postSetupCommands:[32850],integerTrig,trig});
 const checkpoint=engine.checkpoint();
 for(let n=0;n<20;n++)engine.step();
 const advanced={hash:hash(memory),random:engine.random.snapshot()};
 engine.restore(checkpoint);
 for(let n=0;n<20;n++)engine.step();
 if(hash(memory)!==advanced.hash||JSON.stringify(engine.random.snapshot())!==JSON.stringify(advanced.random))throw Error('Checkpoint does not replay deterministically');
 engine.restore(checkpoint);
 for(const key of[70,191,82,87,219]){
   engine.key(key);const held=hash(memory),random=engine.random.snapshot();
   engine.step();
   if(hash(memory)!==held||JSON.stringify(engine.random.snapshot())!==JSON.stringify(random))throw Error('Held panel/freeze mutated state');
   engine.restore(checkpoint);
 }
 const boundaries=[];let steps=0;
 for(;steps<60000;steps++){
   for(let n=0;n<cosmeticWork;n++)engine.random.presentation.rand();
   engine.step();
   if(steps%2000===0)boundaries.push({step:steps,hash:hash(memory),rng:engine.random.gameplay.state,clock:memory.readI32(0x4f8cd0)});
   if(memory.readI32(0x5363f4)!==0)break;
 }
 const boats=Array.from({length:5},(_,i)=>{const id=i+1;return{id,finished:memory.readI32(0x4fe638+id*4),dnf:engine.raceWindow.dnfs.has(id)};});
 if(!boats.slice(1).every(b=>b.finished>0&&!b.dnf)||!boats[0].dnf)throw Error('Headless race failed');
 const finalHash=hash(memory),finalRng=engine.random.gameplay.state,finalClock=memory.readI32(0x4f8cd0);
 const winner=boats.find(b=>b.finished===1);
 if(!winner||memory.readI32(0x4fbf24+winner.id*16)!==100)throw Error('Winner score is not 100');
 const scores=boats.map(b=>memory.readI32(0x4fbf24+b.id*16));
 engine.nextRace();
 if(engine.raceWindow.firstFinish!==undefined||engine.raceWindow.dnfs.size||memory.readI32(0x5363f4)||memory.readI32(0x53642c)||memory.readI32(0x5363b0)!==2)throw Error('Next race did not reset');
 if(boats.some((b,i)=>memory.readI32(0x4fbf24+b.id*16)!==scores[i]))throw Error('Next race lost series scores');
 const beforeNext=memory.readF64(0x5359f0);engine.step();
 if(memory.readF64(0x5359f0)<=beforeNext)throw Error('Next race did not advance');
 runs.push({cosmeticWork,steps,boats,boundaries,hash:finalHash,rng:finalRng,clock:finalClock,scores,checkpointReplay:true,heldPanels:true,nextRace:true});
}
if(runs[0].hash!==runs[1].hash||runs[0].rng!==runs[1].rng||JSON.stringify(runs[0].boundaries)!==JSON.stringify(runs[1].boundaries))throw Error('Cosmetic work changed gameplay');
await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,runs,scope:'Actual Node race with no DOM/Canvas/GDI/WebGL and identical gameplay/wave state despite extra cosmetic draws; numerical primitives retain their separate frozen comparisons.'},null,2));
console.log(JSON.stringify({passed:true,runs:runs.map(r=>({steps:r.steps,clock:r.clock,boats:r.boats}))}));
