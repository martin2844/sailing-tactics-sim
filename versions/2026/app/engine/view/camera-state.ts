/** Compatibility view state influences legacy world calculations. This phase
 * owns those stores; it performs no projection, drawing or pixel access.
 */
export interface CameraStatePort {
  automatic(boat: number): boolean;
  clock(): number;
  setViewpoint(boat: number, value: number): void;
  nearMark(boat: number, radius: number): boolean;
  lookOffset(boat: number): number;
  setLookOffset(boat: number, value: number): void;
  hasExplicitLook(): boolean;
  tack(boat: number): number;
  heading(boat: number): number;
  cameraHeading(boat: number): number;
  setCameraHeading(boat: number, value: number): void;
  mode(boat: number): number;
  windFrom(boat: number): number;
  humanPlayers(): number;
  bearingToOtherBoat(boat: number): number;
}
const wrapOnce = (value: number) => value < 0 ? (value + 360) | 0 : value > 359 ? (value - 360) | 0 : value;
const signedOnce = (value: number) => value > 180 ? (value - 360) | 0 : value < -180 ? (value + 360) | 0 : value;

export function updateCompatibilityCamera(port: CameraStatePort, boat: 1 | 2): void {
  if (port.automatic(boat)) {
    port.setViewpoint(boat, 2);
    const clock = port.clock();
    if (clock < 15) {
      if (clock > -30) port.setViewpoint(boat, 3);
    } else if (clock < 30) port.setViewpoint(boat, 1);
    if (port.nearMark(boat, 90)) port.setViewpoint(boat, 3);
  }
  port.setLookOffset(boat, signedOnce(port.lookOffset(boat)));
  const offset = port.lookOffset(boat) === 0 && !port.hasExplicitLook()
    ? Math.imul(port.tack(boat), -5) : (-port.lookOffset(boat)) | 0;
  port.setCameraHeading(boat, wrapOnce((port.heading(boat) + offset) | 0));
  const mode = port.mode(boat);
  if (mode === -1 || mode === 1) {
    port.setCameraHeading(boat, wrapOnce(mode === -1 ? (port.windFrom(boat) + 180) | 0 : port.windFrom(boat)));
    port.setLookOffset(boat, wrapOnce((port.heading(boat) - port.cameraHeading(boat)) | 0));
  }
  if (mode === 100 && (boat === 1 || port.humanPlayers() === 2)) {
    port.setCameraHeading(boat, wrapOnce(port.bearingToOtherBoat(boat)));
    port.setLookOffset(boat, wrapOnce((port.heading(boat) - port.cameraHeading(boat)) | 0));
  }
}
