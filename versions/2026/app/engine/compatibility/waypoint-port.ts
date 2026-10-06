import type {PreciseValue, SpawnScale, WaypointSpawnPort} from '../waypoints/respawn';

export interface WaypointMemory {
  readI32(address: number): number;
  readF64(address: number): number;
  writeF64(address: number, value: number): void;
}
export interface WaypointNumerics {
  number(value: number): PreciseValue;
  integer(value: number): PreciseValue;
  sinCos(angle: PreciseValue): {sine: PreciseValue; cosine: PreciseValue};
  random(span: number): number;
  nearest(x: number, y: number, excluded: number): PreciseValue;
}
const constantAddress: Readonly<Record<SpawnScale, number>> = {
  initialX: 0x4ccb40, initialY: 0x4cc490, retryX: 0x4cc928, retryY: 0x4cc488,
  margin: 0x4cccb8, clearance: 0x4cc5a0,
};
const address = (base: number, index: number, stride: number) => (base + Math.imul(index, stride)) >>> 0;

/** Address mapping and numeric interop are temporary compatibility details.
 * The domain algorithm owns placement and never receives a drawing context.
 */
export function createWaypointPort(memory: WaypointMemory, numeric: WaypointNumerics): WaypointSpawnPort {
  return {
    humanPlayers: () => memory.readI32(0x4da140),
    boatX: boat => memory.readF64(address(0x4f6af8, boat, 8)),
    boatY: boat => memory.readF64(address(0x4f6c10, boat, 8)),
    heading: boat => memory.readI32(address(0x4fbb90, boat, 4)),
    trig: heading => numeric.sinCos(numeric.integer(heading).multiply(numeric.number(memory.readF64(0x4cc568)))),
    number: numeric.number, integer: numeric.integer,
    constant: scale => numeric.number(memory.readF64(constantAddress[scale])),
    random: numeric.random,
    storeX: (index, value) => memory.writeF64(address(0x4f7220, index, 8), value),
    storeY: (index, value) => memory.writeF64(address(0x4ff038, index, 8), value),
    loadX: index => memory.readF64(address(0x4f7220, index, 8)),
    loadY: index => memory.readF64(address(0x4ff038, index, 8)),
    nearest: numeric.nearest,
  };
}
