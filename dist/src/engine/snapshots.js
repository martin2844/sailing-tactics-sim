import { add32 } from '../runtime/index.js';
import { SNAPSHOT_MAPS } from './snapshot-maps.js';

function copyWords(memory, source, destination, words) {
  // Native REP MOVSD advances forward, including its overlap behavior.
  for (let index = 0; index < words; index++) memory.writeU32(destination + index * 4, memory.readU32(source + index * 4));
}
function copyState(memory, map, count) {
  if (count > 0) {
    for (const row of map.arrays) copyWords(memory, row.source, row.destination, (count & 0x3fffffff) * (row.stride / 4));
  }
  for (const row of map.scalars) copyWords(memory, row.source, row.destination, 1);
}

/** Complete original 0x44dfe0 remembered race-leg state. */
export function saveRaceState(memory) {
  copyState(memory, SNAPSHOT_MAPS.save, memory.readI32(0x49118c));
}

/** Complete original 0x44dbc0 leg restart, finish reset and cleared trails. */
export function restoreRaceState(memory) {
  const count = memory.readI32(0x49118c);
  if (count > 0) {
    for (const [address,value] of [[0x4a89c4,0],[0x4abf1c,-1000],[0x4a764c,0]]) {
      for(let index=0;index<(count&0x3fffffff);index++)memory.writeI32(address+index*4,value);
    }
  }
  copyState(memory, SNAPSHOT_MAPS.restore, count);
  memory.writeI32(0x4a4be8,0);memory.writeI32(0x4ab8b4,30000);
  memory.writeI32(0x4911c0,add32(memory.readI32(0x4aaa38),1));
  for(const address of [0x4a9a08,0x4ab1a0])for(let index=0;index<453;index++)memory.writeI32(address+index*4,-10000);
  memory.writeI32(0x4ab9d8,0);memory.writeI32(0x4ac8dc,0);
}
