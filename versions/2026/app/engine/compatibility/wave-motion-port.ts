import type {WaveConstant, WaveMotionPort, WaveValue} from '../environment/wave-motion';
export interface WaveMemory {
  readI32(address: number): number;
  readU32(address: number): number;
  readF64(address: number): number;
  readBytes(address: number, length: number): Uint8Array;
  writeI32(address: number, value: number): void;
  writeF64(address: number, value: number): void;
  writeBytes(address: number, bytes: Uint8Array): void;
}
export interface WaveNumerics {
  number(value: number): WaveValue;
  integer(value: number): WaveValue;
  sine(phase: WaveValue): WaveValue;
  nearest(x: number, y: number): WaveValue;
  playSound?(event: {resourceId: number; moduleHandle: number; flags: number}): unknown;
}
const fields = {zero: 0x4cc658, one: 0x4cc650, nearDistance: 0x4cc710, cycleScale: 0x4ccbb0} satisfies Record<WaveConstant, number>;
const distance = (boat: 1 | 2) => boat === 1 ? 0x536558 : 0x536570;
const previous = (boat: 1 | 2) => boat === 1 ? 0x536550 : 0x536568;
const countdown = (boat: 1 | 2) => boat === 1 ? 0x536560 : 0x536578;

export function createWaveMotionPort(memory: WaveMemory, numeric: WaveNumerics): WaveMotionPort {
  const value = (address: number) => numeric.number(memory.readF64(address));
  return {
    get phase() { return memory.readI32(0x536430); },
    set phase(v) { memory.writeI32(0x536430, v); },
    get heave() { return memory.readI32(0x4f8ccc); },
    set heave(v) { memory.writeI32(0x4f8ccc, v); },
    get divisor() { return memory.readI32(0x4da178); },
    get players() { return memory.readI32(0x4da140); },
    windAngle: boat => memory.readI32(0x4fecc8 + boat * 4),
    waveFactor: boat => memory.readI32(0x535e40 + boat * 4),
    get trueWind() { return memory.readI32(0x4fb384); },
    setNearFlag: (boat, v) => memory.writeI32(0x4f4b34 + boat * 4, v),
    savePreviousDistance: boat => memory.writeBytes(previous(boat), memory.readBytes(distance(boat), 8)),
    nearest: boat => numeric.nearest(memory.readF64(0x4f6af8 + boat * 8), memory.readF64(0x4f6c10 + boat * 8)),
    storeDistance: (boat, v) => memory.writeF64(distance(boat), v),
    distance: boat => value(distance(boat)), previousDistance: boat => value(previous(boat)),
    countdown: boat => value(countdown(boat)), storeCountdown: (boat, v) => memory.writeF64(countdown(boat), v),
    integer: numeric.integer, constant: name => value(fields[name]), sine: numeric.sine,
    audible: () => memory.readI32(0x536484) === 0 && memory.readI32(0x4f7124) === 0 && memory.readI32(0x4f7128) === 0,
    sound: (resourceId, flags) => { numeric.playSound?.({resourceId, flags, moduleHandle: memory.readU32(0x5359c8)}); },
  };
}
