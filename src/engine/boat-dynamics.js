import { add32, i32, idiv32, imul32, sub32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { wrapDegreesOnce } from './integer-core.js';
import { nativeTrig, nativeSineRadians } from './native-trig.js';
import { apparentWind, APPARENT_WIND_ADDRESSES } from './apparent-wind.js';
import { BOAT_OPTION_ADDRESSES } from './boat-options.js';
import { CURRENT_ADDRESSES, sampleShorelineMetric, sampleSpatialMetric } from './current.js';
import { INTERFERENCE_ADDRESSES, updateInterference } from './interference.js';
import { PENALTY_ADDRESSES, updateMarkStartPenalties } from './penalties.js';
import { prestartSpeedPercent } from './movement-helpers.js';
import { spinnakerAnglePenalty } from './helpers.js';

export const BOAT_DYNAMICS_ADDRESSES = Object.freeze({
  ...BOAT_OPTION_ADDRESSES, ...CURRENT_ADDRESSES, ...INTERFERENCE_ADDRESSES,
  ...PENALTY_ADDRESSES,
  updateBoatDynamics: 0x00428c60,
  apparentWindKnots: APPARENT_WIND_ADDRESSES.apparentWindKnots,
  apparentWindAngle: APPARENT_WIND_ADDRESSES.apparentWindAngle,
  speedTenths: 0x004a7060,
  heelAngle: 0x004a6ec8,
  smoothSpeed: 0x004a71c8,
  previousMetric: 0x004a4510,
  player1SpinnakerControl: 0x004a4388,
  player2SpinnakerControl: 0x004a438c,
  spinnaker: 0x004abb70,
  penaltyDuration: 0x004a7644,
  player1Depth: 0x004aa718,
  sailAngle: 0x004a77e8,
  spinnakerThreshold: 0x004ab180,
  spinnakerDelay: 0x004a42f0,
  bearingToTarget: 0x004abc00,
  spinnakerHoldFlag: 0x004a76d0,
  sailTrim: 0x004a7768,
  jibSetting: 0x004a4ef8,
  sailingMode: 0x004a4170,
  spinnakerPenalty: 0x004ac5f0,
  depowerSetting: 0x004a85d0,
  depowerActual: 0x004a8aa8,
  downwindTrim: 0x004a5b7c,
  tackStartTime: 0x004a3a18,
  tackPenaltyDuration: 0x004ac9d4,
  crewTrim: 0x004ac4e8,
  speedScalePercent: 0x004a6fc8,
  accelerationScale: 0x004aa948,
  raceTime: 0x004ac1f8,
  heelWarning: 0x004a61f4,
  speedOverride: 0x004a5f90,
  preTackSpeed: 0x004ac570,
  tackSlowFlag: 0x004a46a8,
  boardSlowFlag: 0x004aad20,
  player1Vmg: 0x004a71c0,
  degreeFactor: 0x00484d40,
  percentageScale: 0x00484cc8,
  percentage: 0x00485020,
  powerScale: 0x00484d48,
  interferenceScale: 0x00485198,
  heelDragDefault: 0x00484f58,
  heelDragClass1: 0x00484ea8,
  heelDragLaser: 0x00484f48,
  heelDragClass2: 0x00484cf0,
  heelDragClass8: 0x004851a0,
  heelDragCatamaran: 0x004851a8,
  ten: 0x00484d58,
  lowerSpeedLimit: 0x00484d60,
  sportAngleOffset: 0x00484dc0,
  classAngleOffset: 0x00484e40,
  hullRatioScale: 0x00484fd8,
  resistanceBoundary: 0x004851b0,
  resistanceBase: 0x00484f60,
  resistanceLinearScale: 0x004851b8,
  resistanceLinearFactor: 0x004851c0,
  resistanceSqrtScale: 0x004851c8,
  aiComparisonScale: 0x00484fd0,
  aiClassSpeedOffset: 0x004851d0,
  upperSpeedLimit: 0x004851d8,
});

const a = BOAT_DYNAMICS_ADDRESSES;
const indexed = (base, boat, stride = 4) => add32(base, imul32(boat, stride)) >>> 0;
const absolute32 = value => value < 0 ? sub32(0, value) : value;
const spill = value => Float80.fromNumber(value.toNumber());

/**
 * Complete 0x428c60 connected boat dynamics. Floating expressions follow the
 * original instruction order and binary64 spill points. Normal finite engine
 * states require the native integer and fractional trigonometric references.
 * Original void callers consume memory/RNG/sound effects, not residual EAX.
 */
export function updateBoatDynamics(memory, boat, rng, options = {}) {
  boat = i32(boat);
  const read = field => memory.readI32(a[field]);
  const write = (field, value) => memory.writeI32(a[field], value);
  const rb = (field, index = boat) => memory.readI32(indexed(a[field], index));
  const wb = (field, value, index = boat) => memory.writeI32(indexed(a[field], index), value);
  const f = field => Float80.fromNumber(memory.readF64(a[field]));
  const fb = (field, index = boat) => Float80.fromNumber(memory.readF64(indexed(a[field], index, 8)));
  const wf = (field, value) => memory.writeF64(indexed(a[field], boat, 8), value.toNumber());
  const literalSpeed = value => {
    const bytes = new Uint8Array(8);
    const view = new DataView(bytes.buffer);
    view.setFloat64(0, value, true);
    const address = indexed(a.smoothSpeed, boat, 8);
    memory.writeU32(address, view.getUint32(0, true));
    memory.writeU32(address + 4, view.getUint32(4, true));
  };
  const oldSpeed = rb('speedTenths'), oldHeel = rb('heelAngle');
  wb('spinnaker', read('player1SpinnakerControl') === 1 ? 1 : 0, 1);
  write('penaltyDuration', 30);
  if (read('player2SpinnakerControl') === 1) wb('spinnaker', 1, 2);
  else if (read('humanBoatCount') === 2) wb('spinnaker', 0, 2);
  if (read('refreshFlag') === 1 && read('twoPlayerMode') === 0) {
    const source = indexed(a.cachedMetric, boat, 8), target = indexed(a.previousMetric, boat, 8);
    memory.writeU32(target, memory.readU32(source));
    memory.writeU32(target + 4, memory.readU32(source + 4));
  }
  const px = fb('positionX').truncI32(), py = fb('positionY').truncI32();
  if (read('spatialVariant') === 1) sampleShorelineMetric(memory, px, py, boat);
  else sampleSpatialMetric(memory, px, py, boat);
  if (boat === 1) write('player1Depth', fb('cachedMetric', 1).truncI32());
  const pressure = Float80.fromNumber(apparentWind(memory, rb('speedTenths'), boat));
  if (boat <= read('humanBoatCount') && add32(rb('penaltyTime'), read('penaltyDuration')) < read('time')) wb('penaltyCode', 0);
  if (read('time') < -150) wb('penaltyCode', 0);
  let angle = absolute32(sub32(rb('heading'), rb('trueWindDirection')));
  wb('angleToWind', angle);
  if (angle > 180) wb('angleToWind', sub32(360, angle));
  updateInterference(memory, boat, rng, options);
  angle = rb('angleToWind');
  const sailAngle = sub32(idiv32(imul32(sub32(angle, 40), 90), 140), 3);
  wb('sailAngle', sailAngle);
  if (sailAngle < 5) wb('sailAngle', 5);
  let boatClass = read('boatClass');
  write('spinnakerThreshold', boatClass === 2 || boatClass === 9 ? 140 : 105);
  if (boatClass === 8 || boatClass === 10 || read('skiffFlag') === 1 || read('sportBoatFlag') === 1) write('spinnakerThreshold', 97);
  let rawTrim;
  if (boat > read('humanBoatCount')) {
    rawTrim = angle > 59 ? 30 : 20;
    if (angle < 90 && rb('trueWindKnots') > 13) rawTrim = 10;
    if (rb('spinnakerDelay') > 0) wb('spinnakerDelay', sub32(rb('spinnakerDelay'), 1));
    if (read('spinnakerThreshold') < angle && boatClass > 1 && boatClass !== 9 && rb('bearingToTarget') > 90 && read('time') > 0 && rb('penaltyCode') !== 10 && rb('spinnakerHoldFlag') === 0) {
      if (rb('spinnakerDelay') === 0) {
        if (rb('spinnaker') === 0) wb('spinnakerDelay', 2);
        wb('spinnaker', 1);
      }
    } else if (rb('spinnakerDelay') === 0) wb('spinnaker', 0);
    if (rb('raceStage') < 3 && read('course') !== 8) wb('spinnaker', 0);
  } else rawTrim = imul32(rb('sailTrim'), 10);
  let trimPower = add32(rawTrim, 120);
  if (boatClass > 6 && boatClass < 9 && boat <= read('humanBoatCount') && rb('spinnaker') < 1) trimPower = add32(add32(trimPower, imul32(rb('jibSetting'), -25)), 25);
  let coefficient;
  if (angle < 61) {
    const shift = boatClass < 8 ? 80 : 60;
    coefficient = sub32(idiv32(imul32(add32(trimPower, shift), angle), 60), shift);
  } else coefficient = sub32(trimPower, idiv32(sub32(angle, 60), 6));
  if (boatClass < 6 || read('catamaranFlag') === 1) {
    coefficient = trimPower;
    if (angle < 71) coefficient = sub32(idiv32(imul32(add32(trimPower, 70), angle), 70), 70);
  }
  if (read('boardFlag') === 1) {
    if (rb('trueWindKnots') < 10) {
      trimPower = idiv32(imul32(trimPower, 8), 11);
      coefficient = trimPower;
      const threshold = add32(read('closehauledAngle'), 30);
      if (angle <= threshold) coefficient = sub32(idiv32(imul32(add32(trimPower, 80), angle), threshold), 80);
    } else {
      coefficient = trimPower;
      const threshold = add32(read('closehauledAngle'), 25);
      if (angle <= threshold) coefficient = sub32(idiv32(imul32(add32(trimPower, 140), angle), threshold), 140);
    }
  }
  if (read('skiffFlag') === 1) {
    coefficient = trimPower;
    const threshold = add32(read('closehauledAngle'), 12);
    if (angle <= threshold) coefficient = sub32(idiv32(imul32(add32(trimPower, 150), angle), threshold), 150);
  }
  if (angle < idiv32(imul32(read('closehauledAngle'), 2), 3)) coefficient = 0;
  let spinnakerPower = rb('spinnaker') < 1 ? 0 : 150;
  if (boat > read('humanBoatCount') && angle < 140 && rb('spinnaker') > 0 && rb('sailingMode') === 3) spinnakerPower = add32(spinnakerPower, 60);
  if (boat <= read('humanBoatCount')) wb('spinnakerPenalty', 0);
  if (rb('spinnaker') > 0 && boat <= read('humanBoatCount')) {
    spinnakerAnglePenalty(memory, boat);
    spinnakerPower = add32(imul32(rb('spinnakerPenalty'), -4), rb('sailingMode') === 3 && rb('angleToWind') < 140 ? 210 : 150);
  }
  if ((read('boatClass') === 2 || read('boatClass') === 9) && rb('spinnaker') > 0) {
    spinnakerPower = 75;
    if (boat <= read('humanBoatCount')) {
      spinnakerAnglePenalty(memory, boat);
      spinnakerPower = add32(imul32(rb('spinnakerPenalty'), -2), 75);
    }
  }
  boatClass = read('boatClass');
  if (boat <= read('humanBoatCount') && rb('depowerSetting') >= 0) {
    const setting = rb('depowerSetting');
    wb('depowerActual', setting);
    const limit = rb('angleToWind') < 91 || read('boardFlag') !== 0 ? 100 : imul32(sub32(140, rb('angleToWind')), 2);
    if (limit < setting) wb('depowerActual', limit);
    if (rb('depowerActual') < 0) wb('depowerActual', 0);
    if (read('boardFlag') === 1 && setting > 80) { coefficient = 3; wb('depowerActual', 90); }
    else coefficient = idiv32(imul32(sub32(100, rb('depowerActual')), coefficient), 100);
  }
  coefficient = add32(coefficient, spinnakerPower);
  if (coefficient < 3) coefficient = 3;
  if (rb('angleToWind') < sub32(read('closehauledAngle'), 10)) coefficient = 3;
  const heel = rb('heelAngle');
  const heelCosine = nativeTrig(heel < 1 ? 0 : wrapDegreesOnce(absolute32(heel)), options).cosine;
  // 0x4292a6..0x4292d4: coefficient*pressure*cos*.01*area*cos*.1.
  let power = spill(Float80.fromInteger(coefficient).multiply(pressure).multiply(heelCosine).multiply(f('percentageScale'))
    .multiply(Float80.fromInteger(read('sailArea'))).multiply(heelCosine).multiply(f('powerScale')));
  if (rb('interference') > 1) power = spill(power.multiply(f('interferenceScale')));
  let heelCorrection = idiv32(imul32(sub32(9, boatClass), 5), 2);
  if (boatClass === 3) heelCorrection = 22;
  if (rb('angleToWind') > 150) heelCorrection = 0;
  if (rb('angleToWind') > 160) heelCorrection = add32(heelCorrection, imul32(read('downwindTrim'), -4));
  if (boat <= read('humanBoatCount') && boatClass < 7) {
    write('tackPenaltyDuration', (rb('trueWindKnots') < 13 ? 1 : 0) + 5);
    if (read('boardFlag') === 1) write('tackPenaltyDuration', 2);
    if (rb('tackStartTime') <= read('time') && read('time') < add32(rb('lastTurnTime'), read('tackPenaltyDuration'))) heelCorrection = sub32(boatClass, 15);
  }
  let drag = f('heelDragDefault');
  if (read('boatClass') === 1) drag = f(read('optimistFlag') === 0 ? 'heelDragLaser' : 'heelDragClass1');
  if (read('boatClass') === 2) drag = f('heelDragClass2');
  if (read('boardFlag') === 1) drag = f('heelDragClass2');
  if (read('boatClass') === 8) drag = f('heelDragClass8');
  if (read('catamaranFlag') === 1) drag = f('heelDragCatamaran');
  if (read('sportBoatFlag') === 1) drag = f('ten');
  let heelTarget = sub32(nativeTrig(wrapDegreesOnce(rb('sailAngle')), options).cosine.multiply(power).divide(drag).truncI32(), heelCorrection);
  if (heelTarget < 0 && rb('angleToWind') < 161) heelTarget = 0;
  angle = rb('angleToWind');
  if (angle < 60 && heelTarget < 5) heelTarget = 5;
  if (heelTarget > 70) heelTarget = 70;
  let heelLimit = read('boatClass') < 6 ? 15 : 22;
  if (read('catamaranFlag') === 1) heelLimit = 10;
  if (boat > read('humanBoatCount') || rb('depowerSetting') < 0) {
    wb('depowerActual', 0);
    if (heelLimit < heelTarget) {
      const ratio = idiv32(imul32(heelLimit, 100), heelTarget);
      heelTarget = sub32(heelLimit, 1);
      wb('depowerActual', idiv32(sub32(100, ratio), 2));
    }
  }
  let forceAngle;
  if (angle <= 60) forceAngle = add32(add32(idiv32(imul32(angle, 10), 60), sub32(imul32(rb('crewTrim'), -3), idiv32(rb('depowerActual'), 4))), 10);
  else {
    forceAngle = sub32(22, idiv32(sub32(angle, 60), 6));
    if (angle <= sub32(180, rb('downwindLimit')) && (read('catamaranFlag') === 1 || read('boardFlag') === 1)) forceAngle = 22;
  }
  if (rawTrim > 20 && angle < 60) forceAngle = add32(forceAngle, idiv32(sub32(20, rawTrim), 3));
  if (rb('spinnaker') < 1) {
    if (boat <= read('humanBoatCount') && read('boatClass') > 6 && read('boatClass') < 9) forceAngle = add32(imul32(sub32(rb('jibSetting'), 2), 5), forceAngle);
  } else forceAngle = sub32(forceAngle, 8);
  if (rb('interference') > 1 && rb('speedTenths') > 20) forceAngle = sub32(forceAngle, boat > read('humanBoatCount') ? 6 : 4);
  if (forceAngle < 0) forceAngle = 0;
  forceAngle = add32(forceAngle, 12);
  if (rawTrim > 29 && angle < 60) forceAngle = sub32(forceAngle, 6);
  if (rawTrim === 20 && angle < 60 && rb('trueWindKnots') > 13) forceAngle = sub32(forceAngle, 4);
  let forceSailAngle = Float80.fromInteger(rb('sailAngle'));
  if (boat > read('humanBoatCount')) {
    if (read('sportBoatFlag') === 1) forceSailAngle = forceSailAngle.subtract(f('sportAngleOffset'));
    if (read('boatClass') === 6 || read('boatClass') === 2) forceSailAngle = forceSailAngle.subtract(f('classAngleOffset'));
  }
  const forceRadians = forceSailAngle.add(Float80.fromInteger(forceAngle)).multiply(f('degreeFactor'));
  let force = nativeSineRadians(forceRadians, options).multiply(power).multiply(f('ten'));
  if (boat <= read('humanBoatCount') && rb('depowerActual') > 80 && angle < 35) force = f('one');
  if (read('boatClass') === 7 || read('boatClass') === 8) force = f('percentage').subtract(Float80.fromInteger(rb('depowerActual'))).multiply(force).multiply(f('percentageScale'));
  let windDrag = Float80.fromInteger(idiv32(imul32(rb('trueWindKnots'), sub32(90, rb('angleToWind', 1))), 15));
  if (read('boatClass') > 5 && read('boatClass') < 9) windDrag = windDrag.multiply(f('half'));
  const hullExtended = Float80.fromInteger(read('length')).sqrt().multiply(f('ten'));
  const hullSpeed = spill(hullExtended);
  const hullRatio = spill(hullExtended.multiply(f('hullRatioScale')).divide(Float80.fromInteger(read('displacement'))));
  force = force.subtract(windDrag);
  const drive = force.compare(f('zero')) > 0 ? spill(force.sqrt()) : f('zero');
  let resistance;
  if (drive.compare(f('resistanceBoundary')) > 0) resistance = hullSpeed.subtract(hullRatio.subtract(hullSpeed).multiply(drive.subtract(f('resistanceBoundary')).sqrt()).multiply(f('resistanceSqrtScale')));
  else resistance = hullSpeed.multiply(f('resistanceBase')).subtract(hullSpeed.multiply(drive).multiply(f('resistanceLinearScale')).multiply(f('resistanceLinearFactor')));
  if (drive.compare(f('heelDragLaser')) < 0) resistance = drive.multiply(drive).multiply(f('percentageScale'));
  if (boat > read('humanBoatCount') && absolute32(sub32(angle, rb('angleToWind', 1))) < 30 && angle < sub32(170, rb('downwindLimit')) && read('time') < 10) {
    const playerComparison = spill(fb('smoothSpeed', 1).multiply(f('aiComparisonScale')));
    if (playerComparison.compare(resistance) < 0 && hullSpeed.multiply(f('aiComparisonScale')).compare(fb('smoothSpeed', 1)) < 0 && rb('interference', 1) === 0 && rb('penaltyCode', 1) === 0) resistance = playerComparison;
  }
  let speedScale = Float80.fromInteger(rb('speedScalePercent'));
  if (read('boatClass') > 6 && read('boatClass') < 9 && angle > 90 && boat > read('humanBoatCount')) speedScale = speedScale.subtract(f('aiClassSpeedOffset'));
  let targetSpeed = spill(speedScale.multiply(resistance).multiply(f('percentageScale')));
  if (boat <= read('humanBoatCount') && rb('depowerSetting') >= 0) {
    let reduction = heelLimit + 2 < heelTarget ? imul32(add32(sub32(heelTarget, heelLimit), 2), add32(sub32(heelTarget, heelLimit), 2)) : 0;
    if (add32(read('boatClass'), 30) < reduction) reduction = add32(read('boatClass'), 30);
    targetSpeed = spill(targetSpeed.subtract(Float80.fromInteger(reduction)));
  }
  updateMarkStartPenalties(memory, boat, rng, options);
  let inertia = Float80.fromInteger(read('displacement')).multiply(f('half'));
  if (read('boardFlag') === 1) inertia = Float80.fromInteger(read('displacement'));
  const priorSpeed = fb('smoothSpeed');
  wf('smoothSpeed', targetSpeed.subtract(priorSpeed).multiply(f('accelerationScale')).divide(inertia).add(priorSpeed));
  if (read('time') === rb('penaltyTime')) literalSpeed(0);
  if (fb('smoothSpeed').compare(f('upperSpeedLimit')) > 0) literalSpeed(200);
  if (fb('smoothSpeed').compare(f('lowerSpeedLimit')) < 0) literalSpeed(-10);
  wb('speedTenths', fb('smoothSpeed').truncI32());
  wb('heelAngle', idiv32(add32(oldHeel, heelTarget), 2));
  if (boat > read('humanBoatCount') && f('raceTime').compare(f('zero')) < 0) {
    const speed = idiv32(imul32(prestartSpeedPercent(memory, boat, rng), rb('speedTenths')), 100);
    wb('speedTenths', speed);
    if (speed < 25) wb('depowerActual', 40);
    if (rb('depowerActual') > 30) wb('heelAngle', 7);
    if (add32(oldSpeed, 6) < speed) wb('speedTenths', add32(oldSpeed, 6));
  }
  boatClass = read('boatClass');
  const classHalf = idiv32(boatClass, 2);
  if (fb('cachedMetric').compare(Float80.fromInteger(add32(classHalf, 3))) < 0) { wb('speedTenths', 5); wb('penaltyCode', 10); }
  if (fb('cachedMetric').compare(Float80.fromInteger(add32(classHalf, 1))) < 0) { wb('speedTenths', 0); wb('penaltyCode', 10); wb('heading', 0); }
  if (rb('heelAngle', 1) <= add32(heelLimit, 1)) write('heelWarning', 0);
  else { write('heelWarning', 1); if (rb('depowerSetting', 1) < 0) write('heelWarning', 0); }
  if (rb('raceStage') > 8 && boat > read('humanBoatCount')) wb('speedTenths', 25);
  if (!(rb('raceStage') > 8 && boat <= read('humanBoatCount')) && boat > read('humanBoatCount') && rb('speedOverride') >= 0) wb('speedTenths', idiv32(rb('speedOverride'), 2));
  wb('speedOverride', -1);
  let tackDuration = boatClass < 7 ? 5 : 8;
  if (boatClass < 3) tackDuration = 3;
  if (read('catamaranFlag') === 1 || read('skiffFlag') === 1) tackDuration = 8;
  if (read('boardFlag') === 1) tackDuration = 10;
  let recoveredSpeed = hullSpeed.truncI32();
  const turnTime = rb('lastTurnTime');
  if (read('time') === turnTime) wb('preTackSpeed', oldSpeed);
  const laserTack = (boatClass === 1 && read('boardFlag') === 0 && read('optimistFlag') === 0) || boatClass === 2;
  if (rb('angleToWind') < add32(read('closehauledAngle'), 5)) {
    const midpoint = add32(idiv32(tackDuration, 2), turnTime);
    if (add32(turnTime, 1) < read('time') && read('time') <= midpoint) {
      if (read('boardFlag') === 1 || oldSpeed < 5) recoveredSpeed = 15;
      if (rb('preTackSpeed') < recoveredSpeed) recoveredSpeed = rb('preTackSpeed');
      const speed = laserTack ? idiv32(imul32(recoveredSpeed, 3), 4) : idiv32(imul32(recoveredSpeed, 2), 3);
      wb('speedTenths', speed); wf('smoothSpeed', Float80.fromInteger(speed));
    }
    if (midpoint < read('time') && read('time') <= add32(tackDuration, turnTime)) {
      if (read('boardFlag') === 1 || oldSpeed < 5) recoveredSpeed = 25;
      if (rb('preTackSpeed') < recoveredSpeed) recoveredSpeed = rb('preTackSpeed');
      const speed = laserTack ? idiv32(imul32(recoveredSpeed, 5), 6) : idiv32(imul32(recoveredSpeed, 4), 5);
      wb('speedTenths', speed); wf('smoothSpeed', Float80.fromInteger(speed));
    }
    if (add32(tackDuration, turnTime) < read('time')) wb('tackSlowFlag', 0);
  }
  if (read('boardFlag') === 1 && rb('boardSlowFlag') === 1) {
    if (rb('speedTenths') > 29) wb('speedTenths', 30);
    if (add32(turnTime, 6) < read('time')) wb('boardSlowFlag', 0);
  }
  if (rb('raceStage') > 8 && boat > read('humanBoatCount')) { literalSpeed(30); wb('speedTenths', 30); }
  if (boat === 1) write('player1Vmg', nativeTrig(rb('angleToWind', 1), options).cosine.multiply(fb('smoothSpeed', 1)).multiply(f('ten')).truncI32());
}

export const FUN_00428c60 = updateBoatDynamics;
