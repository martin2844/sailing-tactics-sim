import type {RacePhaseActions, RacePhaseMemory} from '../race-phase-controller';

type LegacyCallback = (...args: unknown[]) => unknown;
type LegacyOptions = Record<string, unknown>;

function callback(options: LegacyOptions, name: string): LegacyCallback {
  const render = options.render as LegacyOptions | undefined;
  const engine = options.engine as LegacyOptions | undefined;
  const selected = options[name] ?? render?.[name] ?? engine?.[name];
  if (typeof selected !== 'function') throw new TypeError('Missing compatibility phase: ' + name);
  return selected as LegacyCallback;
}

/** Temporary adapter. New engine transitions own dispatch; legacy callbacks
 * still supply drawing-owned semantics until each callback is extracted.
 */
export function createCompatibilityActions(
  memory: RacePhaseMemory,
  dc: unknown,
  random: unknown,
  bindings: LegacyOptions,
  defaultSimulationFrame: LegacyCallback,
): RacePhaseActions {
  const options: LegacyOptions = {...bindings, rng: random};
  const draw = (name: string) => callback(options, name)(memory, dc, random, options);
  return {
    initializeBoatOptions: () => { callback(options, 'initializeBoatOptions')(memory, options); },
    initializeRace: () => { callback(options, 'initializeRace')(memory, random, options); },
    startScreen: () => { draw('drawStartScreen'); },
    resultsScreen: () => { draw('drawResultsScreen'); },
    forecastScreen: () => { draw('drawForecastScreen'); },
    pauseScreen: () => { draw('drawPauseScreen'); },
    simulationStep: () => {
      const selected = options.drawSimulationFrame ?? defaultSimulationFrame;
      if (typeof selected !== 'function') throw new TypeError('Missing compatibility simulation step');
      selected(memory, dc, random, options);
    },
    chart: mode => {
      callback(options, 'drawChart')(memory, dc, 0, 0,
        memory.readI32(0x4fe624), memory.readI32(0x4fe2a8), 0, mode, options);
    },
  };
}
