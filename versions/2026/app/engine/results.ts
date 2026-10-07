export interface ResultMemory {
  readI32(address: number): number;
  writeI32(address: number, value: number): void;
}

/** Recovered low-point units: first place is 100, subsequent places rank*101.
 * This transition previously lived in the results painter. */
export function finalizeResults(memory: ResultMemory): void {
  const count = memory.readI32(0x4da194);
  const races = memory.readI32(0x5363fc);
  const column = Math.max(0, Math.min(2, races - 1));
  for (let boat = 1; boat <= count; boat++) {
    const rank = memory.readI32(0x4fe638 + boat * 4);
    if (rank === 1) memory.writeI32(0x4f8dbc, boat);
    if (memory.readI32(0x536424) !== 0) continue;
    const row = 0x4fbf24 + boat * 16;
    memory.writeI32(row + column * 4, rank === 1 ? 100 : Math.imul(rank, 101));
    for (let previous = 0; previous < column; previous++) {
      if (memory.readI32(row + previous * 4) === 0) memory.writeI32(row + previous * 4, 3100);
    }
    const total = (memory.readI32(row) + memory.readI32(row + 4) + memory.readI32(row + 8)) | 0;
    memory.writeI32(0x4fc164 + (boat - 1) * 4, total);
  }
  memory.writeI32(0x53642c, 1);
}
