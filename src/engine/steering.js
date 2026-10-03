import { add32, idiv32, imul32, sub32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { wrapDegreesOnce } from './integer-core.js';

export const STEERING_ADDRESSES = Object.freeze({
  updatePlayer1Rudder: 0x0042ba00,
  updatePlayer1Steering: 0x0042b7f0,
  updatePlayer2Steering: 0x0042bda0,
  mouseGateY: 0x004aa824,
  viewportHeight: 0x004a72d0,
  mouseGateLimit: 0x004a5ba0,
  gateDimension: 0x004a3f04,
  mouseMinX: 0x004aa808,
  mouseMaxX: 0x004ab150,
  mouseX: 0x004a4f80,
  mouseCenterX: 0x004a70ec,
  viewportWidth: 0x004a763c,
  humanBoatCount: 0x00491140,
  rig: 0x0049114c,
  boatClass: 0x00491188,
  speedDivisor: 0x00491170,
  rudder: 0x004a7044,
  speed1: 0x004a7064,
  speed2: 0x004a7068,
  tack1: 0x004aa734,
  tack2: 0x004aa738,
  previousTack1: 0x004abe74,
  previousTack2: 0x004abe78,
  turnMode1: 0x004a4dfc,
  turnMode2: 0x004a4e00,
  gybeMode1: 0x004abf9c,
  gybeMode2: 0x004abfa0,
  lockMode1: 0x004a496c,
  lockMode2: 0x004a4970,
  sailingMode1: 0x004a684c,
  sailingMode2: 0x004a6850,
  autopilot1: 0x004a8914,
  autopilot2: 0x004a8918,
  angle1: 0x004a7bcc,
  angle2: 0x004a7bd0,
  trueWindDirection1: 0x004aa5b4,
  downwindLimit1: 0x004a5f14,
  downwindLimit2: 0x004a5f18,
  heading1: 0x004ac01c,
  heading2: 0x004ac020,
  tackStart1: 0x004a3a1c,
  tackStart2: 0x004a3a20,
  time: 0x004a5b80,
  soundDisabled: 0x004ac9c0,
  moduleHandle: 0x004ac1d4,
  firstButtonX: 0x004a774c,
  firstButtonY: 0x004aa97c,
  secondButtonX: 0x004ab188,
  secondButtonY: 0x004a4414,
  buttonCenterX: 0x004a67b0,
  buttonCenterY: 0x004a6840,
  uiMode: 0x004a4e8c,
  buttonLock: 0x004ac8fc,
  smoothHeading: 0x004a78e8,
  steeringScale: 0x004ab0c8,
  rateBase: 0x00484d48,
  rateNumerator: 0x00484f50,
  rateScale: 0x00484dd8,
  player2Rate: 0x00485240,
  buttonStepA: 0x00484d58,
  buttonStepB: 0x00484d60,
  zero: 0x00484e18,
  revolution: 0x00485098,
  negativeRevolution: 0x004850a8,
  playSoundImport: 0x004b1c18,
});

const a = STEERING_ADDRESSES;
const absolute32 = value => value < 0 ? sub32(0, value) : value;
const extended = (memory, address) => Float80.fromNumber(memory.readF64(address));

function soundRequest(memory, options) {
  if (memory.readI32(a.soundDisabled) === 0) {
    options.playSound?.({ resourceId: 0x86, moduleHandle: memory.readU32(a.moduleHandle), flags: 0x40005 });
  }
}

function lockedHeading1(memory) {
  return sub32(memory.readI32(a.trueWindDirection1),
    imul32(sub32(180, memory.readI32(a.downwindLimit1)), memory.readI32(a.tack1)));
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
 * Complete 0x42ba00 control/rudder update. Preserve native precision64 operation
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
    rudder = imul32(rigTack(), read('speed1') < 21 ? -300 : -600);
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
    soundRequest(memory, options);
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
  if (read('lockMode1') === 1) memory.writeF64(a.smoothHeading, lockedHeading1(memory));
  return rudder;
}

/** Complete 0x42b7f0 first-player steering, including the original UI control globals. */
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

/** Complete 0x42bda0 second-player steering; its native rate omits the rig factor. */
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

export const FUN_0042ba00 = updatePlayer1Rudder;
export const FUN_0042b7f0 = updatePlayer1Steering;
export const FUN_0042bda0 = updatePlayer2Steering;
