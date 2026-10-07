import {readFile} from 'node:fs/promises';
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
import {originalCStringContents,resetOriginalCStringContents,writeCString} from '../../public/legacy/versions/2010-en/src/render/text.js';
const data=new URL('../../public/legacy/versions/2010-en/assets/data/',import.meta.url),json=async name=>JSON.parse(await readFile(new URL(name,data),'utf8'));
const manifest=await json('original-memory.json'),segments=new Map(await Promise.all(manifest.segments.map(async s=>[s.file,new Uint8Array(await readFile(new URL(s.file,data)))])));
setX87ControlWord(0x027f);
const trig=createCapturedTrig(await json('x87-trig.json'),await json('x87-stored-trig.json')),integerTrig=await json('trig-tables.json');
const numeric={captureStrings:originalCStringContents,restoreStrings:(m,cells)=>{resetOriginalCStringContents(m);for(const {address,text}of cells)writeCString(m,address,text);},initializeApplication,initializeBoatOptions,initializeRace,advanceFrame,command:handleMenuCommand,key:handleKeyDown,bindings:createEngineBindings,
 number:Float80.fromNumber,integer:Float80.fromInteger,sinCos:sinCosX87,scaledRandom,nearest:nearestWaypointDistance,bearing:(m,x,y,boat)=>targetRelativeBearing(m,x,y,0,boat),distance:distanceToBoat};

export function makeRuntime(configuration={}){
 const memory=loadOriginalData(manifest,segments);
 const engine=new EngineRuntime(memory,numeric,{seed:1546300800,setupCommands:[32799,32816,32789,32806,32909],postSetupCommands:[32850],integerTrig,trig,...configuration});
 return {memory,engine};
}
