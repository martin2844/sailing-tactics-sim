import { add32, imul32 } from '../../../../src/runtime/c-types.js';
import { SNAPSHOT_MAPS } from './snapshot-maps.js';

export const SNAPSHOT_ROUTINES=Object.freeze({saveRaceState:0x4645a0,restoreRaceState:0x464180});
function copyWords(memory,source,destination,count) {
  // Original REP MOVSD advances forwards, including any overlapping input.
  for (let index=0;index<count;index++) memory.writeU32(destination+index*4,memory.readU32(source+index*4));
}
function copyArrays(memory,rows,count) {
  if (count<=0) return;
  for (const row of rows) {
    const words=row.stride===8 ? imul32(count,8)>>>2 : count&0x3fffffff;
    copyWords(memory,row.source,row.destination,words);
  }
}
function copyScalars(memory,rows) {
  for (const row of rows) memory.writeU32(row.destination,memory.readU32(row.source));
}

export function saveRaceState(memory) {
  copyArrays(memory,SNAPSHOT_MAPS.save.arrays,memory.readI32(0x4da194));
  copyScalars(memory,SNAPSHOT_MAPS.save.scalars);
}

/** Complete original restore, including both 15,531-word history resets. */
export function restoreRaceState(memory) {
  const count=memory.readI32(0x4da194);
  if (count>0) {
    for (const [address,value] of [[0x5116e4,0],[0x535624,-1000],[0x4fe63c,0]]) {
      for (let index=0;index<(count&0x3fffffff);index++) memory.writeI32(address+index*4,value);
    }
  }
  copyArrays(memory,SNAPSHOT_MAPS.restore.arrays,count);
  const scalars=SNAPSHOT_MAPS.restore.scalars;
  const beforeX=scalars.findIndex(row=>row.destination===0x5359f0);
  copyScalars(memory,scalars.slice(0,beforeX));
  // The original zero/limit stores precede the stage increment and final Y.
  memory.writeI32(0x4f6d64,0);memory.writeI32(0x534d64,30000);
  copyScalars(memory,scalars.slice(beforeX,beforeX+1));
  memory.writeI32(0x4da1cc,add32(memory.readI32(0x523648),1));
  copyScalars(memory,scalars.slice(beforeX+1,beforeX+2));
  for (const address of [0x5135a0,0x525ab8]) for (let index=0;index<0x3cab;index++) memory.writeI32(address+index*4,-10000);
  memory.writeI32(0x534ea8,0);memory.writeI32(0x536394,0);
  copyScalars(memory,scalars.slice(beforeX+2));
}
