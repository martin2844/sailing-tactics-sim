import { add32, idiv32, imul32, sub32 } from '../../../../src/runtime/index.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { wrapDegreesOnce } from './application.js';

export const STEERING_ADDRESSES = Object.freeze({
  updatePlayer1Rudder: 0x0043e160,
  updatePlayer1Steering: 0x0043df50,
  updatePlayer2Steering: 0x0043e510,
  mouseGateY: 0x0052318c,
  viewportHeight: 0x004fe2a8,
  mouseGateLimit: 0x004f8ee4,
  gateDimension: 0x004f3ff0,
  mouseMinX: 0x005230e0,
  mouseMaxX: 0x00525a68,
  mouseX: 0x004f7f78,
  mouseCenterX: 0x004fe088,
  viewportWidth: 0x004fe624,
  humanBoatCount: 0x004da140,
  rig: 0x004da14c,
  boatClass: 0x004da190,
  speedDivisor: 0x004da178,
  rudder: 0x004fdfd0,
  speed1: 0x004fdfec,
  speed2: 0x004fdff0,
  tack1: 0x00522ff4,
  tack2: 0x00522ff8,
  previousTack1: 0x0053556c,
  previousTack2: 0x00535570,
  turnMode1: 0x004f7094,
  turnMode2: 0x004f7098,
  gybeMode1: 0x005356b4,
  gybeMode2: 0x005356b8,
  lockMode1: 0x004f6a6c,
  lockMode2: 0x004f6a70,
  sailingMode1: 0x004fbbac,
  sailingMode2: 0x004fbbb0,
  autopilot1: 0x00511624,
  autopilot2: 0x00511628,
  angle1: 0x004feccc,
  angle2: 0x004fecd0,
  trueWindDirection1: 0x00522b94,
  downwindLimit1: 0x004fae64,
  downwindLimit2: 0x004fae68,
  lockedHeadingOffset1: 0x004f3f64,
  heading1: 0x00535744,
  heading2: 0x00535748,
  tackStart1: 0x004f399c,
  tackStart2: 0x004f39a0,
  time: 0x004f8cd0,
  soundDisabled: 0x00536484,
  moduleHandle: 0x005359c8,
  firstButtonX: 0x004fe75c,
  firstButtonY: 0x005233a4,
  secondButtonX: 0x00525aa0,
  secondButtonY: 0x004f4680,
  buttonCenterX: 0x004fba18,
  buttonCenterY: 0x004fbba0,
  uiMode: 0x004f71c4,
  buttonLock: 0x005363b4,
  smoothHeading: 0x004fe938,
  steeringScale: 0x005259d0,
  rateBase: 0x004cc570,
  rateNumerator: 0x004cc7a8,
  rateScale: 0x004cc530,
  player2Rate: 0x004ccb48,
  buttonStepA: 0x004cc580,
  buttonStepB: 0x004cc588,
  zero: 0x004cc658,
  revolution: 0x004cc8f0,
  negativeRevolution: 0x004cc900,
  playSoundImport: 0x0053bc18,
});

const a = STEERING_ADDRESSES;
const absolute32 = value => value < 0 ? sub32(0, value) : value;
const extended = (memory, address) => Float80.fromNumber(memory.readF64(address));

function soundRequest(memory, options, flags = 0x40005) {
  if (memory.readI32(a.soundDisabled) === 0) {
    options.playSound?.({ resourceId: 0x86, moduleHandle: memory.readU32(a.moduleHandle), flags });
  }
}

function lockedHeading1(memory, includeOffset = false) {
  return sub32(memory.readI32(a.trueWindDirection1),
    imul32(add32(sub32(180, memory.readI32(a.downwindLimit1)), includeOffset ? memory.readI32(a.lockedHeadingOffset1) : 0), memory.readI32(a.tack1)));
}

function clearPlayer1Controls(memory) {
  for (const field of ['autopilot1', 'turnMode1', 'gybeMode1', 'lockMode1', 'sailingMode1']) memory.writeI32(a[field], 0);
}

function steeringRate(memory) {
  return extended(memory, a.rateBase).subtract(
    extended(memory, a.rateNumerator).divide(Float80.fromInteger(memory.readI32(a.speedDivisor))),
  );
}

/**
 * Complete 0x43e160 control/rudder update. Preserve observed startup precision53 operation
 * order until the final FSTP binary64 heading store. Sound requests carry the
 * exact original PlaySoundA arguments; its return has no effect on game state.
 * The optional sound callback observes events and must not mutate image memory.
 */
export function updatePlayer1Rudder(memory, options = {}) {
  const read = field => memory.readI32(a[field]);
  const write = (field, value) => memory.writeI32(a[field], value);
  let rudder = 0;
  const mouseActive = sub32(read('mouseGateY'), idiv32(read('viewportHeight'), 50))
      < sub32(read('mouseGateLimit'), idiv32(read('gateDimension'), 15))
    && sub32(read('mouseMinX'), 20) < read('mouseX')
    && read('mouseX') < add32(read('mouseMaxX'), 20)
    && read('humanBoatCount') === 1;
  if (mouseActive) {
    rudder = Float80.fromInteger(sub32(read('mouseCenterX'), read('mouseX')))
      .divide(extended(memory, a.steeringScale)).truncI32();
    if (idiv32(read('viewportWidth'), 12) < absolute32(sub32(read('mouseX'), read('mouseCenterX')))) rudder = imul32(rudder, 3);
  } else if (read('turnMode1') === 0 && read('gybeMode1') === 0) {
    write('rudder', 0);
  }
  if (rudder !== 0) {
    write('rudder', idiv32(rudder, 10));
    clearPlayer1Controls(memory);
  }
  const rigTack = () => imul32(read('rig'), read('tack1'));
  if (read('turnMode1') !== 0 || read('sailingMode1') === 3) {
    rudder = imul32(rigTack(), read('speed1') < 21 ? -300 : -400);
    write('rudder', idiv32(rudder, 10));
  }
  if (read('gybeMode1') === 1) {
    rudder = imul32(rigTack(), 250);
    write('rudder', idiv32(rudder, 10));
  }
  if (read('sailingMode1') === 1 || read('sailingMode1') === 2) {
    rudder = imul32(rigTack(), read('boatClass') < 3 ? 300 : 400);
    write('rudder', idiv32(rudder, 10));
  }
  // Native order is rate * rudder * rig, rather than multiplying both signed
  // integers first or adopting the reassociation in the decompiled C.
  const rate = steeringRate(memory).multiply(extended(memory, a.rateScale)).divide(extended(memory, a.steeringScale));
  const delta = rate.multiply(Float80.fromInteger(rudder)).multiply(Float80.fromInteger(read('rig')));
  memory.writeF64(a.smoothHeading, extended(memory, a.smoothHeading).subtract(delta).toNumber());
  if (read('gybeMode1') === 1 && read('tack1') !== read('previousTack1')) {
    write('gybeMode1', 0);
    memory.writeF64(a.smoothHeading, lockedHeading1(memory));
    write('lockMode1', 1);
    write('rudder', 0);
    soundRequest(memory, options, 0x40045);
  }
  if (read('sailingMode1') === 1 && sub32(180, read('downwindLimit1')) < read('angle1')) {
    write('sailingMode1', 0);
    write('lockMode1', 1);
    write('rudder', 0);
    memory.writeF64(a.smoothHeading, lockedHeading1(memory));
  }
  if (read('sailingMode1') === 2 && read('angle1') > 90) {
    write('rudder', 0);
    write('sailingMode1', 0);
  }
  if (read('sailingMode1') === 3 && read('angle1') < 90) {
    write('sailingMode1', 0);
    write('rudder', 0);
  }
  if (read('lockMode1') === 1) memory.writeF64(a.smoothHeading, lockedHeading1(memory, true));
  return rudder;
}

/** Complete 0x43df50 first-player steering, including the original UI control globals. */
export function updatePlayer1Steering(memory, options = {}) {
  updatePlayer1Rudder(memory, options);
  const read = field => memory.readI32(a[field]);
  const write = (field, value) => memory.writeI32(a[field], value);
  const lowerButton = Math.max(read('firstButtonY'), read('secondButtonY'));
  if (lowerButton < idiv32(read('viewportHeight'), 2) || read('uiMode') === 3) {
    const threshold = idiv32(read('viewportWidth'), 9);
    const closeToCenter = (x, y) => absolute32(sub32(read(x), read('buttonCenterX'))) < threshold
      && absolute32(sub32(read(y), read('buttonCenterY'))) < threshold && read('buttonLock') === 0;
    if (closeToCenter('firstButtonX', 'firstButtonY')) {
      memory.writeF64(a.smoothHeading, extended(memory, a.smoothHeading).subtract(extended(memory, a.buttonStepA)).toNumber());
      write('firstButtonX', 0);
      write('firstButtonY', 0);
      clearPlayer1Controls(memory);
    }
    if (closeToCenter('secondButtonX', 'secondButtonY')) {
      memory.writeF64(a.smoothHeading, extended(memory, a.smoothHeading).subtract(extended(memory, a.buttonStepB)).toNumber());
      write('secondButtonX', 0);
      write('secondButtonY', 0);
      clearPlayer1Controls(memory);
    }
  }
  if (extended(memory, a.smoothHeading).compare(extended(memory, a.revolution)) > 0) {
    memory.writeF64(a.smoothHeading, extended(memory, a.smoothHeading).subtract(extended(memory, a.revolution)).toNumber());
  }
  if (extended(memory, a.smoothHeading).compare(extended(memory, a.zero)) < 0) {
    memory.writeF64(a.smoothHeading, extended(memory, a.smoothHeading).subtract(extended(memory, a.negativeRevolution)).toNumber());
  }
  const heading = extended(memory, a.smoothHeading).truncI32();
  write('heading1', heading);
  if (read('turnMode1') === 1 && read('tack1') !== read('previousTack1')) {
    write('autopilot1', 1);
    write('turnMode1', 0);
    write('lockMode1', 0);
    write('rudder', 0);
    write('sailingMode1', 0);
    write('tackStart1', read('time'));
  }
  if (read('turnMode1') === -1 && read('angle1') < 70) {
    write('autopilot1', 1);
    write('turnMode1', 0);
    write('lockMode1', 0);
    write('rudder', 0);
    write('sailingMode1', 0);
  }
  const wrapped = wrapDegreesOnce(heading);
  write('heading1', wrapped);
  return wrapped;
}

/** Complete 0x43e510 second-player steering; its native rate omits the rig factor. */
export function updatePlayer2Steering(memory, options = {}) {
  const read = field => memory.readI32(a[field]);
  const write = (field, value) => memory.writeI32(a[field], value);
  const rotate = rudder => {
    const delta = steeringRate(memory).multiply(extended(memory, a.player2Rate)).multiply(Float80.fromInteger(rudder));
    return Float80.fromInteger(read('heading2')).subtract(delta).truncI32();
  };
  if (read('turnMode2') !== 0 || read('sailingMode2') === 3) {
    const rudder = imul32(read('tack2'), read('speed2') < 21 ? -200 : -350);
    write('heading2', wrapDegreesOnce(rotate(rudder)));
  }
  if (read('tack2') !== read('previousTack2') && read('turnMode2') === 1) {
    write('autopilot2', 1);
    write('turnMode2', 0);
    write('tackStart2', read('time'));
  }
  if (read('turnMode2') === -1 && read('angle2') < 70) {
    write('autopilot2', 1);
    write('turnMode2', 0);
  }
  if (read('gybeMode2') !== 0 || read('sailingMode2') === 1 || read('sailingMode2') === 2) {
    const rudder = imul32(read('tack2'), read('boatClass') < 3 ? 150 : 300);
    write('heading2', rotate(rudder));
    if (read('tack2') !== read('previousTack2')) {
      write('lockMode2', 1);
      write('gybeMode2', 0);
      soundRequest(memory, options);
    }
    if (read('sailingMode2') === 1 && sub32(180, read('downwindLimit2')) < read('angle2')) {
      write('lockMode2', 1);
      write('gybeMode2', 0);
      write('sailingMode2', 0);
    }
  }
  if (read('sailingMode2') === 2 && read('angle2') > 90) {
    write('sailingMode2', 0);
    write('rudder', 0);
  }
  if (read('sailingMode2') === 3 && read('angle2') < 90) {
    write('sailingMode2', 0);
    write('rudder', 0);
  }
  const heading = wrapDegreesOnce(read('heading2'));
  write('heading2', heading);
  return heading;
}

export const FUN_0043e160 = updatePlayer1Rudder;
export const FUN_0043df50 = updatePlayer1Steering;
export const FUN_0043e510 = updatePlayer2Steering;
