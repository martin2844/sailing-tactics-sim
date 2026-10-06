/** Automatic slowdown is a rules/control response, not a boat drawing effect. */
export interface FoulSlowdownState {
  readonly clock: number;
  readonly graceStarted: number;
  readonly human: boolean;
  readonly warning: number;
  readonly finished: number;
  mode: number;
  previousWarning: number;
  cooldown: number;
  pace: number;
  divisor: number;
  savedPace: number;
  savedDivisor: number;
}

/** Returns whether the boat has a qualifying pending warning. The temporary
 * rendering adapter uses that result to retain its original style branch.
 */
export function updateFoulSlowdown(state: FoulSlowdownState): boolean {
  if (state.mode === 2 && ((state.graceStarted + 4) | 0) < state.clock) state.mode = 1;
  const mode = state.mode;
  if (state.warning === 0 && state.human) state.previousWarning = 0;
  if (!(state.warning > 0 && state.human && state.finished === 0 && state.cooldown === 0)) return false;
  if (mode === 1 && state.previousWarning === 0) {
    if (state.pace > 1) {
      state.savedPace = state.pace;
      state.savedDivisor = state.divisor;
      state.cooldown = 90;
    }
    state.divisor = 2919;
    state.pace = 1;
  }
  return true;
}
