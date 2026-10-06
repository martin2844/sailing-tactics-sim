import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';
import {sinCosX87} from '../../../../src/runtime/transcendentals.js';
import {nearestWaypointDistance} from '../../../2010-en/src/engine/waypoints.js';
import {updateWaveMotion as original} from '../../../2010-en/src/engine/wave-motion.js';
import {updateWaveMotion} from '../../app/engine/environment/wave-motion.ts';
import {createWaveMotionPort} from '../../app/engine/compatibility/wave-motion-port.ts';
const source=await readFile(new URL('../../../2010-en/runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
function image(angle,waves,players,divisor,phase,countdown,muted){
 const m=loadPE32(source);
 for(const[a,v]of[[0x4feccc,angle],[0x4fecd0,angle],[0x535e44,waves],[0x535e48,waves],[0x4fb384,15],[0x4da140,players],[0x4da178,divisor],[0x536430,phase],[0x4da1f4,0],[0x536484,muted],[0x4f7124,0],[0x4f7128,0]])m.writeI32(a,v);
 for(const boat of[1,2]){m.writeF64(0x4f6af8+boat*8,100);m.writeF64(0x4f6c10+boat*8,100);}
 m.writeF64(0x4f7220,101);m.writeF64(0x4ff038,101);
 for(const[a,v]of[[0x536558,100],[0x536570,100],[0x536560,countdown],[0x536578,countdown]])m.writeF64(a,v);
 return m;
}

test('typed wave/heave state and ordered sound events match native arithmetic across thresholds',()=>withX87ControlWord(0x027f,()=>{
 for(const angle of[59,60,79,80,89,90,160])for(const waves of[1,3])for(const players of[1,2])for(const divisor of[76,2919])for(const phase of[0,1000])for(const countdown of[0,.5,20])for(const muted of[0,1]){
   const a=image(angle,waves,players,divisor,phase,countdown,muted),b=image(angle,waves,players,divisor,phase,countdown,muted),sa=[],sb=[];
   original(a,{playSound:event=>sa.push(event)});
   updateWaveMotion(createWaveMotionPort(b,{number:Float80.fromNumber,integer:Float80.fromInteger,
     sine:phase=>sinCosX87(phase).sine,nearest:(x,y)=>nearestWaypointDistance(b,x,y,-1),playSound:event=>sb.push(event)}));
   assert.deepEqual(b.bytes,a.bytes);assert.deepEqual(sb,sa);
 }
}));
