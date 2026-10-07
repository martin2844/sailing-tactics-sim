/** Gameplay world updates are explicit and do not depend on drawing order,
 * camera occlusion, pixels, fonts or a graphics backend.
 */
export interface WorldStatePort {
  boats(): number;
  humanPlayers(): number;
  normalizeNpcRig(boat: number): void;
  updateViewState(boat: 1 | 2): void;
  refreshWaveField(): void;
  updateWaveMotion(): void;
  updateFoulSlowdown(boat: number): boolean;
  copyWarningLatch(boat: number): void;
}

export function updateWorldState(port: WorldStatePort): void {
  port.updateViewState(1);
  if (port.humanPlayers() === 2) port.updateViewState(2);
  port.refreshWaveField();
  port.updateWaveMotion();
  for (let boat = 1; boat <= port.boats(); boat++) {
    if (boat > port.humanPlayers()) port.normalizeNpcRig(boat);
    if (port.updateFoulSlowdown(boat)) port.copyWarningLatch(boat);
  }
}
