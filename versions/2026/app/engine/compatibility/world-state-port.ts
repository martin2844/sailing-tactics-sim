import type {WorldStatePort} from '../world-state';
import type {WaypointMemory} from './waypoint-port';
interface WorldMemory extends WaypointMemory {
  writeI32(address: number, value: number): void;
}
interface WorldSystems {
  camera(boat: 1 | 2): void;
  waveMotion(): void;
  respawnWave(index: number): void;
  slowdown(boat: number): boolean;
}
const waveRadius = 2000;
const slot = (base: number, boat: number) => (base + Math.imul(boat, 4)) >>> 0;

export function createWorldStatePort(memory: WorldMemory, systems: WorldSystems): WorldStatePort {
  return {
    boats: () => memory.readI32(0x4da194),
    humanPlayers: () => memory.readI32(0x4da140),
    normalizeNpcRig: boat => {
      memory.writeI32(slot(0x4fe778, boat), 1);
      memory.writeI32(slot(0x4f7ee0, boat), 1);
      const kind = memory.readI32(0x4da190);
      const blade = kind === 10 || kind === 8 || memory.readI32(0x5363c4) === 1
        || memory.readI32(0x5363c0) > 0 || memory.readI32(0x53652c) === 1;
      memory.writeI32(slot(0x4f42c0, boat), blade ? 3 : 2);
      memory.writeI32(slot(0x535f68, boat), 0);
    },
    updateViewState: systems.camera,
    refreshWaveField: () => {
      const count = memory.readI32(0x4da1f4);
      if (count < 0 || count > 397) throw new RangeError('Unsupported wave-field size');
      const x = memory.readF64(0x4f6b00), y = memory.readF64(0x4f6c18);
      for (let index = 0; index <= count; index++) {
        const wx = memory.readF64(0x4f7220 + index * 8), wy = memory.readF64(0x4ff038 + index * 8);
        if (!Number.isFinite(wx) || !Number.isFinite(wy) || Math.hypot(wx - x, wy - y) > waveRadius) systems.respawnWave(index);
      }
    },
    updateWaveMotion: systems.waveMotion,
    updateFoulSlowdown: systems.slowdown,
    copyWarningLatch: boat => memory.writeI32(slot(0x4faf80, boat), memory.readI32(slot(0x4f7120, boat))),
  };
}
