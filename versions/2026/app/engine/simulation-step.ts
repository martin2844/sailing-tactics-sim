/** Ordered simulation phase orchestration. The world phase is temporarily
 * supplied by the compatibility adapter; no browser/presentation API is owned
 * by this driver. Native variable timestep is handled inside advance().
 */
export interface SimulationStepPhases {
  advance(): number;
  updateWorldState(): void;
  pace(): number;
  readTick?: () => number;
  enforceMinimumDuration?: (duration: number, started: number) => void;
  clearFrameWarnings(): void;
}
const elapsed = (now: number, started: number) => ((now >>> 0) - (started >>> 0)) >>> 0;
export const minimumStepDuration = (pace: number): number => pace >= 7 ? 0 : pace === 6 ? 30 : pace === 5 ? 60 : 80;

export function executeSimulationStep(phases: SimulationStepPhases): number {
  const started = phases.advance() >>> 0;
  phases.updateWorldState();
  const duration = minimumStepDuration(phases.pace());
  if (duration > 0 && phases.readTick) {
    let reads = 0;
    while (elapsed(phases.readTick(), started) < duration) {
      if (++reads > 1_000_000) throw new RangeError('Simulation tick host did not advance');
    }
  } else phases.enforceMinimumDuration?.(duration, started);
  // Preserve native failure behavior: do not clear warnings if an earlier
  // phase failed. Cleanup follows successful world/timing phases only.
  phases.clearFrameWarnings();
  return duration;
}
