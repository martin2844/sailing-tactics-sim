import type {RacePhaseMemory} from '../race-phase-controller';
import type {FoulSlowdownState} from '../rules/foul-slowdown';
const slot = (base: number, boat: number) => (base + Math.imul(boat, 4)) >>> 0;

export function createFoulSlowdownState(memory: RacePhaseMemory, boat: number): FoulSlowdownState {
  return {
    get clock() { return memory.readI32(0x4f8cd0); },
    get graceStarted() { return memory.readI32(0x4da1e0); },
    get human() { return boat <= memory.readI32(0x4da140); },
    get warning() { return memory.readI32(slot(0x4f7120, boat)); },
    get finished() { return memory.readI32(slot(0x4fe638, boat)); },
    get mode() { return memory.readI32(0x4da1dc); },
    set mode(value) { memory.writeI32(0x4da1dc, value); },
    get previousWarning() { return memory.readI32(slot(0x4faf80, boat)); },
    set previousWarning(value) { memory.writeI32(slot(0x4faf80, boat), value); },
    get cooldown() { return memory.readI32(slot(0x4fb9a8, boat)); },
    set cooldown(value) { memory.writeI32(slot(0x4fb9a8, boat), value); },
    get pace() { return memory.readI32(0x4da174); },
    set pace(value) { memory.writeI32(0x4da174, value); },
    get divisor() { return memory.readI32(0x4da178); },
    set divisor(value) { memory.writeI32(0x4da178, value); },
    get savedPace() { return memory.readI32(0x4da180); },
    set savedPace(value) { memory.writeI32(0x4da180, value); },
    get savedDivisor() { return memory.readI32(0x4da17c); },
    set savedDivisor(value) { memory.writeI32(0x4da17c, value); },
  };
}
