// Supplementary generated inputs; no native fixture or executable is changed.
import {readFileSync,writeFileSync} from 'node:fs';
import {createHash} from 'node:crypto';
import {loadPE32} from '../../../../src/runtime/memory.js';
import {withX87ControlWord} from '../../../../src/runtime/float80.js';
import {nearestWaypointDistance,nearestWaypointDistanceExtended} from '../../src/engine/waypoints.js';
const source=readFileSync(new URL('../../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const memory=loadPE32(source);
const waypointCount=600,queryCount=300;
memory.writeI32(0x4da1f4,waypointCount-1);
let seed=0xbba293d4;
const next=()=>{seed=(Math.imul(seed,1664525)+1013904223)>>>0;return (seed/4294967296-.5)*15000;};
for(let index=0;index<waypointCount;index++){
 memory.writeF64(0x4f7220+index*8,next());memory.writeF64(0x4ff038+index*8,next());
}
const queries=Array.from({length:queryCount},()=>[next(),next(),-1]);
const run=routine=>{
 const started=performance.now(),bits=[];let checksum=0;
 for(const args of queries){const result=routine(memory,...args);checksum+=result.toNumber();bits.push(Buffer.from(result.toBytes()).toString('hex'));}
 return {elapsedMs:performance.now()-started,checksum,bits};
};
withX87ControlWord(0x027f,()=>{
 const expected=run(nearestWaypointDistanceExtended),actual=run(nearestWaypointDistance);
 const report={scope:'Supplementary deterministic PC53 nearest scan over finite generated waypoint coordinates; exact Float80 return comparison to the unchanged extended helper. These are generated checks, not additional native captures.',sourceSha256:createHash('sha256').update(source).digest('hex'),waypointSourceSha256:createHash('sha256').update(readFileSync(new URL('../../src/engine/waypoints.js',import.meta.url))).digest('hex'),controlWord:'0x027f',seed:'0xbba293d4',queries:queryCount,waypoints:waypointCount,candidates:queryCount*waypointCount,extendedMs:expected.elapsedMs,optimizedMs:actual.elapsedMs,speedup:expected.elapsedMs/actual.elapsedMs,exact:JSON.stringify(actual.bits)===JSON.stringify(expected.bits),checksum:actual.checksum};
 writeFileSync(process.argv[2]??'/tmp/tact-nearest-waypoint-scan-check.json',JSON.stringify(report,null,2)+'\n');
 console.log(JSON.stringify(report,null,2));process.exitCode=report.exact?0:1;
});
