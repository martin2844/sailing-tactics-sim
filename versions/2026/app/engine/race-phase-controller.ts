/** State transitions recovered from the 2010 screen dispatcher.
 * Actions are injected so the controller has no Canvas, GDI or UI dependency.
 * Sequential reloads are deliberate: actions may change later branch eligibility.
 */
export interface RacePhaseMemory {
  readI32(address: number): number;
  writeI32(address: number, value: number): void;
}
export interface RacePhaseActions {
  initializeBoatOptions(): void;
  initializeRace(): void;
  startScreen(): void;
  resultsScreen(): void;
  forecastScreen(): void;
  pauseScreen(): void;
  simulationStep(): void;
  chart(mode: 3 | 4 | 5): void;
}
const field = {
  cycle: 0x5364e8,
  phase: 0x5363b0,
  completedRaces: 0x5363fc,
  singleRaceScoring: 0x536424,
  pausePage: 0x536444,
  results: 0x5363f4,
  courseChart: 0x5233a8,
  redraw: 0x5363b4,
  forecast: 0x5363f0,
  windChart: 0x536434,
  currentChart: 0x536438,
} as const;

export function dispatchRacePhases(memory: RacePhaseMemory, actions: RacePhaseActions): void {
  const read = (address: number) => memory.readI32(address);
  const next = (read(field.cycle) + 1) | 0;
  memory.writeI32(field.cycle, next);
  if (next > 60) memory.writeI32(field.cycle, 1);

  if (read(field.phase) === 0) {
    actions.initializeBoatOptions();
    actions.initializeRace();
    actions.startScreen();
  }
  if (read(field.phase) === 1) {
    if (read(field.completedRaces) > 0 && read(field.singleRaceScoring) === 0) {
      memory.writeI32(field.pausePage, 400);
    }
    actions.initializeBoatOptions();
    actions.initializeRace();
    memory.writeI32(field.phase, 2);
  }
  if (read(field.results) > 0) {
    if (read(field.courseChart) === 0) {
      actions.resultsScreen();
      memory.writeI32(field.redraw, 0);
    } else actions.chart(3);
    if (read(field.pausePage) === 300) actions.pauseScreen();
  }
  if (read(field.results) !== 0) return;

  if (read(field.forecast) === 1 && read(field.phase) === 2 && read(field.courseChart) === 0) {
    actions.forecastScreen();
  }
  const pause = read(field.pausePage);
  if ([0, 2, 300].includes(pause) && read(field.phase) > 1
    && read(field.forecast) === 0 && read(field.courseChart) === 0
    && read(field.windChart) === 0 && read(field.currentChart) === 0) {
    actions.simulationStep();
  }
  if (read(field.phase) > 0 && read(field.forecast) === 0 && read(field.courseChart) === 1) actions.chart(3);
  if (read(field.phase) > 0 && read(field.forecast) === 0 && read(field.windChart) === 1 && read(field.pausePage) === 0) actions.chart(4);
  if (read(field.phase) > 0 && read(field.forecast) === 0 && read(field.currentChart) === 1 && read(field.pausePage) === 0) actions.chart(5);
  if (read(field.pausePage) !== 0 && read(field.pausePage) >= 0) actions.pauseScreen();
}
