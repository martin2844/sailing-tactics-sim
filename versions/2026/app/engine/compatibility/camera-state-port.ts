import type {CameraStatePort} from '../view/camera-state';
interface CameraMemory {
  readI32(address: number): number;
  readF64(address: number): number;
  writeI32(address: number, value: number): void;
}
export interface CameraNumerics {
  coordinateLow32(value: number): number;
  bearingToOtherBoat(boat: number): number;
}
const slot = (base: number, boat: number) => (base + Math.imul(boat, 4)) >>> 0;
const absolute32 = (value: number) => ((value ^ (value >> 31)) - (value >> 31)) | 0;

export function createCameraStatePort(memory: CameraMemory, numeric: CameraNumerics): CameraStatePort {
  return {
    automatic: boat => memory.readI32(slot(0x523a58, boat)) === 1,
    clock: () => memory.readI32(0x4f8cd0),
    setViewpoint: (boat, value) => memory.writeI32(slot(0x4f71c0, boat), value),
    nearMark: (boat, radius) => {
      const x = numeric.coordinateLow32(memory.readF64((0x4f6af8 + Math.imul(boat, 8)) >>> 0));
      const y = numeric.coordinateLow32(memory.readF64((0x4f6c10 + Math.imul(boat, 8)) >>> 0));
      return [[0x5229d4,0x522ac8],[0x522acc,0x522ae0],[0x5229c8,0x522ac4]].some(([ax,ay]) => {
        const dx = (x - memory.readI32(ax)) | 0, dy = (y - memory.readI32(ay)) | 0;
        return radius >= ((absolute32(dx) + absolute32(dy)) | 0);
      });
    },
    lookOffset: boat => memory.readI32(slot(0x4f49a0, boat)),
    setLookOffset: (boat, value) => memory.writeI32(slot(0x4f49a0, boat), value),
    hasExplicitLook: () => memory.readI32(0x5363e8) !== 0,
    tack: boat => memory.readI32(slot(0x522ff0, boat)),
    heading: boat => memory.readI32(slot(0x535740, boat)),
    cameraHeading: boat => memory.readI32(slot(0x4fbb90, boat)),
    setCameraHeading: (boat, value) => memory.writeI32(slot(0x4fbb90, boat), value),
    mode: boat => memory.readI32(slot(0x512d60, boat)),
    windFrom: boat => memory.readI32(slot(0x522b90, boat)),
    humanPlayers: () => memory.readI32(0x4da140),
    bearingToOtherBoat: numeric.bearingToOtherBoat,
  };
}
