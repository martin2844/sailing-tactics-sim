import type {PreciseValue} from '../waypoints/respawn';
export interface WaveValue extends PreciseValue {
  subtract(other: PreciseValue): WaveValue;
  multiply(other: PreciseValue): WaveValue;
  divide(other: PreciseValue): WaveValue;
  truncI32(): number;
}
export type WaveConstant = 'zero' | 'one' | 'nearDistance' | 'cycleScale';
export interface WaveMotionPort {
  phase: number;
  heave: number;
  readonly divisor: number;
  readonly players: number;
  windAngle(boat: 1 | 2): number;
  waveFactor(boat: 1 | 2): number;
  readonly trueWind: number;
  setNearFlag(boat: 1 | 2, value: number): void;
  savePreviousDistance(boat: 1 | 2): void;
  nearest(boat: 1 | 2): WaveValue;
  storeDistance(boat: 1 | 2, value: number): void;
  distance(boat: 1 | 2): WaveValue;
  previousDistance(boat: 1 | 2): WaveValue;
  countdown(boat: 1 | 2): WaveValue;
  storeCountdown(boat: 1 | 2, value: number): void;
  integer(value: number): WaveValue;
  constant(name: WaveConstant): WaveValue;
  sine(phase: WaveValue): WaveValue;
  audible(): boolean;
  sound(resourceId: number, flags: number): void;
}

export function updateWaveMotion(port: WaveMotionPort): void {
  port.phase = (port.phase + 1) | 0;
  port.setNearFlag(1, 0); port.setNearFlag(2, 0);
  const nearWave = (boat: 1 | 2) => {
    port.savePreviousDistance(boat);
    port.storeDistance(boat, port.nearest(boat).toNumber());
    const remaining = port.countdown(boat).subtract(port.constant('one'));
    port.storeCountdown(boat, remaining.toNumber());
    if (remaining.compare(port.constant('zero')) < 0) port.storeCountdown(boat, 0);
    if (port.distance(boat).compare(port.constant('nearDistance')) < 0
      && port.distance(boat).compare(port.previousDistance(boat)) < 0
      && port.countdown(boat).compare(port.constant('zero')) === 0 && port.waveFactor(boat) > 1) {
      if (boat === 1) port.phase = Math.trunc(port.divisor / 5) | 0;
      port.storeCountdown(boat, 20);
      if (port.audible()) port.sound(0x99, 0x40045);
      port.setNearFlag(boat, 1);
    }
  };
  if (port.windAngle(1) < 80 && port.waveFactor(1) > 1) nearWave(1);
  if (port.windAngle(2) < 80 && port.waveFactor(2) > 1 && port.players === 2) nearWave(2);
  if (port.phase === 1 && port.windAngle(1) <= 90 && port.audible()) port.sound(0x97, 0x40015);
  if (port.phase > (Math.trunc(port.divisor / 3) | 0)) port.phase = 0;
  const angle = port.windAngle(1), waves = port.waveFactor(1);
  const amplitude = angle < 60 ? (Math.imul(waves, 2) + 2) | 0
    : angle < 90 ? (waves + 2) | 0 : port.trueWind > 12 ? 2 : 1;
  const phase = port.integer(port.phase).multiply(port.constant('cycleScale')).divide(port.integer(port.divisor));
  port.heave = port.integer(amplitude).multiply(port.sine(phase)).truncI32();
}
