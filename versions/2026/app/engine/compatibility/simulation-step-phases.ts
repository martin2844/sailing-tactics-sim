import type {SimulationStepPhases} from '../simulation-step';
import type {RacePhaseMemory} from '../race-phase-controller';
interface LegacyFrameCallbacks {
  advance(memory: RacePhaseMemory, random: unknown, options: Record<string, unknown>): number;
  compose(memory: RacePhaseMemory, dc: unknown, random: unknown, options: Record<string, unknown>): void;
}

/** Temporary world traversal adapter. Numerical phase order/timing and warning
 * cleanup belong to the new engine; composition remains until world extraction.
 */
export function createSimulationStepPhases(
  memory: RacePhaseMemory,
  dc: unknown,
  random: unknown,
  options: Record<string, unknown>,
  legacy: LegacyFrameCallbacks,
): SimulationStepPhases {
  const ticks = options.getTickCount;
  const enforce = options.enforceMinimumPaintDuration;
  return {
    advance: () => legacy.advance(memory, random, options),
    updateWorldState: () => legacy.compose(memory, dc, random, options),
    pace: () => memory.readI32(0x4da174),
    readTick: typeof ticks === 'function' ? () => ticks.call(options) as number : undefined,
    enforceMinimumDuration: typeof enforce === 'function' ? (duration, start) => { enforce.call(options, duration, start); } : undefined,
    clearFrameWarnings: () => {
      memory.writeI32(0x4f7124, 0);
      memory.writeI32(0x4f7128, 0);
    },
  };
}
