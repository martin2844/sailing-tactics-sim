import { add32, idiv32, imul32, irem32, sub32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom, wrapDegreesOnce } from './integer-core.js';
import { sampleCurrent } from './current.js';
import { resetBoat } from './penalties.js';
import { advanceRaceTarget } from './race-targets.js';
import { recordTrails } from './trails.js';
import { nativeTrig } from './native-trig.js';

export const INTEGRATION_ADDRESSES = Object.freeze({
  integratePositions: 0x0042adb0,
  raceTime: 0x004ac1f8, dt: 0x004aa948, timeFactor: 0x004ab0c0,
  speedDivisor: 0x00491170, startMode: 0x004911cc,
  boatCount: 0x0049118c, humanBoatCount: 0x00491140,
  difficulty: 0x00491190, course: 0x00491194, islandFlag: 0x004a5a4c,
  closehauledAngle: 0x004a4eb0, smoothHeading: 0x004a78e8,
  heading: 0x004ac018, speed: 0x004a7060, tack: 0x004aa730,
  trueWindDirection: 0x004aa5b0, autopilot1: 0x004a8914, autopilot2: 0x004a8918,
  leg: 0x004a5420, legStarted: 0x004a41f0, controlStarted: 0x004a7970,
  positionX: 0x004a49e8, positionY: 0x004a4ae0,
  renderPositionX: 0x004a5318, renderPositionY: 0x004a60d8,
  targetX: 0x004a4888, targetY: 0x004a6f48,
  startCenterX: 0x004a4be0, startCenterY: 0x004a4f84,
  windDirection: 0x004ac840, baseWindDirection: 0x004a4f8c,
  clockRate: 0x0049115c, boatClass: 0x00491188,
  timeMinutes: 0x004ab8b8, startHour: 0x004a5bac, hour: 0x004a4be4,
  night: 0x004ac98c, minutes: 0x004a5e84, seconds: 0x004a6778,
  driftClock: 0x004abef0, previousTime: 0x004a76c8, time: 0x004a5b80,
  lastRefreshTime: 0x004ac828, refreshFlag: 0x004a60a0,
  refreshPhase: 0x004ac8dc, previousTrailPhase: 0x004ac9f8,
  currentStrength: 0x004ac860, currentDirection: 0x004a63c0,
  sampledCurrentDirection: 0x004aa960, sine: 0x004a54a0, cosine: 0x004a3450,
  rateCoefficient: 0x004a6e48, windStrength: 0x004aa390,
  skiffFlag: 0x004ac90c, catamaranFlag: 0x004ac900, optimistFlag: 0x004ac914,
  length: 0x004a5ba4, penaltyFlag: 0x004a76d0,
  screenX: 0x004a9908, screenY: 0x004a9988,
  patchDirection: 0x004ac0a0, patchStrength: 0x004a4150,
  patchX: 0x004abd88, patchY: 0x004a4728,
  trailCount: 0x004ab9d8, clearedFlags: 0x004a61e8,
  soundDisabled: 0x004ac9c0, moduleHandle: 0x004ac1d4,
  soundGate1: 0x004a4e7c, soundGate2: 0x004a4e80,
  turnMode1: 0x004a4dfc, turnMode2: 0x004a4e00,
  soundTurnMagnitude: 0x004a8aac, angle1: 0x004a7bcc,
  dtScale: 0x00484d88, one: 0x00484e10, zero: 0x00484e18,
  randomDenominatorBase: 0x004850c8, randomDifficultyScale: 0x00484e80,
  countdownThreshold: 0x00485208, countdownLower: 0x00484f00,
  shortCountdownThreshold: 0x00485210, shortCountdownLower: 0x00485218,
  minuteScale: 0x00484f08, hourScale: 0x00485220,
  sixty: 0x00484cc0, refreshPeriod: 0x00484eb8,
  prestartDriftX: 0x00485228, prestartDriftY: 0x00485230,
  screenScale: 0x004911a8, screenProjectionScale: 0x00485238,
});

const a = INTEGRATION_ADDRESSES;
const at = (base, index, stride = 4) => add32(base, imul32(index, stride)) >>> 0;
const integer = value => Float80.fromInteger(value);
const extended = (memory, address) => Float80.fromNumber(memory.readF64(address));
const absolute32 = value => value < 0 ? sub32(0, value) : value;

/** Complete original 0x42adb0 clock/current/position integration and sounds. */
export function integratePositions(memory, rng, options = {}) {
  options = { ...options, rng };
  const read = key => memory.readI32(a[key]);
  const write = (key, value) => memory.writeI32(a[key], value);
  const floating = key => extended(memory, a[key]);
  const readBoat = (key, boat) => memory.readI32(at(a[key], boat));
  const writeBoat = (key, boat, value) => memory.writeI32(at(a[key], boat), value);
  const boatFloating = (key, boat) => extended(memory, at(a[key], boat, 8));
  const sound = (resourceId, flags) => {
    const result = options.playSound?.({ resourceId, moduleHandle: memory.readU32(a.moduleHandle), flags });
    return result == null ? 1 : result | 0;
  };
  let finalStoredFactor;
  if (floating('raceTime').compare(floating('dt').add(floating('dt'))) < 0 && read('startMode') < 3) {
    for (let boat = 1; boat <= read('boatCount'); boat = add32(boat, 1)) {
      resetBoat(memory, boat);
      memory.writeF64(at(a.positionX, boat, 8), readBoat('targetX', boat));
      memory.writeF64(at(a.positionY, boat, 8), readBoat('targetY', boat));
      if (boat > read('humanBoatCount') && read('boatCount') > 2) {
        const numerator = integer(scaledRandom(10, rng));
        const denominator = floating('randomDenominatorBase').subtract(integer(read('difficulty')).multiply(floating('randomDifficultyScale')));
        // FSTP of the blend ratio at 0x42ae86; complement remains in ST0.
        const ratio = Float80.fromNumber(numerator.divide(denominator).toNumber());
        const complement = floating('one').subtract(ratio);
        const x = boatFloating('positionX', boat).multiply(complement)
          .add(integer(read('startCenterX')).multiply(ratio));
        const y = boatFloating('positionY', boat).multiply(complement)
          .add(integer(read('startCenterY')).multiply(ratio));
        memory.writeF64(at(a.positionX, boat, 8), x.toNumber());
        memory.writeF64(at(a.positionY, boat, 8), y.toNumber());
      }
      memory.writeBytes(at(a.renderPositionX, boat, 8), memory.readBytes(at(a.positionX, boat, 8), 8));
      memory.writeBytes(at(a.renderPositionY, boat, 8), memory.readBytes(at(a.positionY, boat, 8), 8));
      writeBoat('leg', boat, 0);
      advanceRaceTarget(memory, boat, options);
      memory.writeF64(a.smoothHeading, sub32(readBoat('trueWindDirection', 1), read('closehauledAngle')));
      writeBoat('heading', boat, sub32(readBoat('trueWindDirection', boat), read('closehauledAngle')));
      write('autopilot1', 1);
      write('autopilot2', 1);
      writeBoat('controlStarted', boat, 0);
      writeBoat('tack', boat, 1);
      writeBoat('legStarted', boat, 0);
    }
    if (read('course') === 8 && read('islandFlag') === 0) {
      const direction = read('windDirection');
      memory.writeF64(a.smoothHeading, direction <= 180 ? wrapDegreesOnce(sub32(direction, read('closehauledAngle'))) : 90);
      write('autopilot1', direction <= 180 ? 1 : 0);
      if (read('humanBoatCount') === 2) {
        writeBoat('heading', 2, direction <= 180 ? wrapDegreesOnce(sub32(direction, read('closehauledAngle'))) : 90);
        write('autopilot2', direction <= 180 ? 1 : 0);
      }
    }
  }
  const dtExact = floating('timeFactor').multiply(floating('dtScale')).divide(integer(read('speedDivisor')));
  memory.writeF64(a.dt, dtExact.toNumber());
  // Native FST does not pop: first countdown comparison uses unrounded dt.
  if (floating('raceTime').compare(dtExact.subtract(floating('countdownThreshold'))) <= 0
    && floating('raceTime').compare(floating('countdownLower')) > 0 && read('soundDisabled') === 0) sound(0x8c, 0x40005);
  if (read('startMode') === 10 && floating('raceTime').compare(floating('dt').subtract(floating('shortCountdownThreshold'))) <= 0
    && floating('raceTime').compare(floating('shortCountdownLower')) >= 0 && read('soundDisabled') === 0) sound(0x8c, 0x40005);
  memory.writeF64(a.raceTime, floating('raceTime').add(floating('dt')).toNumber());
  let clockRate = read('boatClass') === 7 ? 3 : 2;
  if (read('course') === 8) clockRate = 12;
  if (floating('raceTime').compare(floating('zero')) <= 0) clockRate = 1;
  write('clockRate', clockRate);
  const minuteExact = integer(clockRate).multiply(floating('raceTime')).multiply(floating('minuteScale'));
  memory.writeF64(a.timeMinutes, minuteExact.toNumber());
  const elapsedHours = minuteExact.multiply(floating('hourScale')).truncI32();
  let hour = sub32(read('startHour'), elapsedHours);
  if (hour > 23) hour = sub32(hour, 24);
  write('hour', hour);
  write('night', hour >= 6 && hour <= 20 ? 0 : 1);
  const minutes = add32(floating('timeMinutes').truncI32(), imul32(elapsedHours, 60));
  write('minutes', minutes);
  write('seconds', floating('raceTime').compare(floating('zero')) < 0
    ? sub32(floating('timeMinutes').multiply(floating('sixty')).truncI32(), imul32(minutes, 60)) : 0);
  memory.writeF64(a.driftClock, floating('timeMinutes').multiply(floating('sixty')).toNumber());
  write('previousTime', read('time'));
  write('time', floating('raceTime').truncI32());
  write('refreshFlag', 0);
  if (floating('raceTime').subtract(floating('lastRefreshTime')).compare(floating('refreshPeriod')) > 0) {
    write('refreshFlag', 1);
    const phase = add32(read('refreshPhase'), 1);
    write('refreshPhase', phase > 6 ? 1 : phase);
    memory.writeBytes(a.lastRefreshTime, memory.readBytes(a.raceTime, 8));
  }
  for (let boat = read('boatCount'); boat > 0; boat = sub32(boat, 1)) {
    if (read('refreshFlag') === 1) {
      const current = sampleCurrent(memory, boatFloating('positionX', boat).truncI32(), boatFloating('positionY', boat).truncI32(), boat,options);
      writeBoat('currentStrength', boat, current);
      writeBoat('currentDirection', boat, wrapDegreesOnce(read('sampledCurrentDirection')));
    }
    const direction = wrapDegreesOnce(readBoat('currentDirection', boat));
    writeBoat('currentDirection', boat, direction);
    const strength = absolute32(readBoat('currentStrength', boat));
    let currentX = sub32(0, imul32(memory.readI32(at(a.sine, direction)), strength));
    let currentY = imul32(memory.readI32(at(a.cosine, direction)), strength);
    let driftX = 0;
    let driftY = 0;
    if (read('time') < 0) {
      currentX = idiv32(currentX, 3);
      currentY = idiv32(currentY, 3);
      if (readBoat('speed', boat) < 20 && boat <= read('humanBoatCount') && read('difficulty') > 7 && readBoat('leg', boat) < 9) {
        const pair = nativeTrig(read('baseWindDirection'), options);
        driftX = pair.sine.multiply(floating('prestartDriftX')).truncI32();
        driftY = pair.cosine.multiply(floating('prestartDriftY')).truncI32();
      }
    }
    const totalCurrentX = add32(driftX, currentX);
    const totalCurrentY = add32(driftY, currentY);
    const speed = integer(imul32(readBoat('speed', boat), 100));
    const velocity = heading => {
      const pair = nativeTrig(heading, { ...options, stored: true });
      return {
        x: pair.sine.multiply(speed).add(integer(totalCurrentX)),
        y: Float80.fromNumber(integer(totalCurrentY).subtract(pair.cosine.multiply(speed)).toNumber()),
      };
    };
    let vector = velocity(wrapDegreesOnce(readBoat('heading', boat)));
    writeBoat('rateCoefficient', boat, idiv32(vector.x.multiply(vector.x).add(vector.y.multiply(vector.y)).sqrt().truncI32(), 100));
    let divisor = read('windStrength') >= 10 ? 2600 : 2300;
    if (read('skiffFlag') === 1 || read('catamaranFlag') === 1) divisor = add32(divisor, 300);
    if (read('length') < 35 && read('boatClass') !== 3) divisor = sub32(divisor, 200);
    if (read('optimistFlag') === 1) divisor = sub32(divisor, 200);
    const factor = floating('dt').divide(integer(divisor));
    finalStoredFactor = Float80.fromNumber(factor.toNumber());
    const positionX = factor.multiply(vector.x).add(boatFloating('positionX', boat));
    const positionY = finalStoredFactor.multiply(vector.y).add(boatFloating('positionY', boat));
    memory.writeF64(at(a.positionX, boat, 8), positionX.toNumber());
    memory.writeF64(at(a.positionY, boat, 8), positionY.toNumber());
    if (readBoat('penaltyFlag', boat) > 0) {
      vector = velocity(wrapDegreesOnce(sub32(readBoat('trueWindDirection', boat), imul32(readBoat('tack', boat), read('closehauledAngle')))));
    }
    writeBoat('screenX', boat, boatFloating('positionX', boat)
      .subtract(vector.x.multiply(floating('screenScale')).multiply(floating('screenProjectionScale'))).truncI32());
    writeBoat('screenY', boat, boatFloating('positionY', boat)
      .subtract(vector.y.multiply(floating('screenScale')).multiply(floating('screenProjectionScale'))).truncI32());
    memory.writeBytes(at(a.renderPositionX, boat, 8), memory.readBytes(at(a.positionX, boat, 8), 8));
    memory.writeBytes(at(a.renderPositionY, boat, 8), memory.readBytes(at(a.positionY, boat, 8), 8));
  }
  // With zero boats the original uses an uninitialized stack slot here. The
  // caller can provide a captured slot; no invented factor is substituted.
  if (!finalStoredFactor) {
    if (options.uninitializedFactor === undefined) throw new RangeError('Original zero-boat integration requires the captured uninitialized factor');
    finalStoredFactor = Float80.fromNumber(options.uninitializedFactor);
  }
  for (let patch = 1; patch <= 5; patch++) {
    const direction = wrapDegreesOnce(add32(readBoat('patchDirection', patch), 180));
    const strength = readBoat('patchStrength', patch);
    const driftX = imul32(imul32(memory.readI32(at(a.sine, direction)), strength), 10);
    const driftY = imul32(imul32(memory.readI32(at(a.cosine, direction)), strength), -10);
    memory.writeF64(at(a.patchX, patch, 8), integer(driftX).multiply(finalStoredFactor).add(boatFloating('patchX', patch)).toNumber());
    memory.writeF64(at(a.patchY, patch, 8), integer(driftY).multiply(finalStoredFactor).add(boatFloating('patchY', patch)).toNumber());
  }
  if (read('refreshPhase') !== read('previousTrailPhase')) {
    recordTrails(memory);
    const count = add32(read('trailCount'), 1);
    write('trailCount', count > 150 ? 150 : count);
    write('previousTrailPhase', read('refreshPhase'));
  }
  for (let index = 0; index < 11; index++) memory.writeI32(a.clearedFlags + index * 4, 0);
  for (const gate of ['soundDisabled', 'soundGate1', 'soundGate2']) {
    const value = read(gate);
    if (value !== 0) return value;
  }
  if (irem32(read('time'), 200) === 0) sound(0x86, 0x40045);
  const extraHuman = sub32(read('humanBoatCount'), 1);
  if (read('turnMode1') === 1 || imul32(read('turnMode2'), extraHuman) === 1 || read('soundTurnMagnitude') > 50) sound(0x88, 0x40015);
  else if (readBoat('speed', 1) > 20 || imul32(readBoat('speed', 2), extraHuman) > 20) sound(read('angle1') < 90 ? 0x8b : 0x8a, 0x40015);
  const time = read('time');
  if (time <= 0) return time;
  const previousTime = read('previousTime');
  if (previousTime > 0) return previousTime;
  const disabled = read('soundDisabled');
  if (disabled !== 0) return disabled;
  return sound(0x8c, 0x40005);
}

export const FUN_0042adb0 = integratePositions;
