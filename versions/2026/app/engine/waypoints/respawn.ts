/** Recovered waypoint placement, with exact arithmetic supplied by the numeric
 * port. Placement/RNG ordering is gameplay behavior, not a rendering operation.
 */
export interface PreciseValue {
  add(other: PreciseValue): PreciseValue;
  subtract(other: PreciseValue): PreciseValue;
  multiply(other: PreciseValue): PreciseValue;
  compare(other: PreciseValue): number;
  toNumber(): number;
}
export type SpawnScale = 'initialX' | 'initialY' | 'retryX' | 'retryY' | 'margin' | 'clearance';
export interface WaypointSpawnPort {
  humanPlayers(): number;
  boatX(boat: number): number;
  boatY(boat: number): number;
  heading(boat: number): number;
  trig(heading: number): {sine: PreciseValue; cosine: PreciseValue};
  number(value: number): PreciseValue;
  integer(value: number): PreciseValue;
  constant(scale: SpawnScale): PreciseValue;
  random(span: number): number;
  storeX(index: number, value: number): void;
  storeY(index: number, value: number): void;
  loadX(index: number): number;
  loadY(index: number): number;
  nearest(x: number, y: number, excluded: number): PreciseValue;
}

export function respawnWaypoint(port: WaypointSpawnPort, requestedIndex: number): void {
  const index = requestedIndex | 0;
  const players = port.humanPlayers();
  const boat = players === 1 ? 1 : players === 2 ? (index % 2 !== 0 ? 2 : 1) : index;
  const spawn = (xScale: SpawnScale, yScale: SpawnScale) => {
    // Store X before the second random draw, matching the original call order.
    const xRandom = port.random(880);
    const sine = port.trig(port.heading(boat)).sine;
    const x = port.number(port.boatX(boat))
      .subtract(sine.multiply(port.constant(xScale)))
      .subtract(port.constant('margin')).add(port.integer(xRandom));
    port.storeX(index, x.toNumber());
    const yRandom = port.random(880);
    const cosine = port.trig(port.heading(boat)).cosine;
    const y = port.number(port.boatY(boat))
      .subtract(cosine.multiply(port.constant(yScale)))
      .subtract(port.constant('margin')).add(port.integer(yRandom));
    port.storeY(index, y.toNumber());
  };
  const crowded = () => port.nearest(port.loadX(index), port.loadY(index), index)
    .compare(port.constant('clearance')) < 0;
  spawn('initialX', 'initialY');
  if (crowded()) spawn('retryX', 'retryY');
  if (crowded()) spawn('retryX', 'retryY');
}
