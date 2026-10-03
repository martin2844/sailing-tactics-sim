import { add32, sub32, imul32, idiv32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom, wrapDegreesOnce } from './integer-core.js';
import { initializeCourse } from './course.js';
import { initializeShoreline, initializeEllipse, initializeAdvancedTerrain } from './terrain.js';
import { initializeWind, initializeTide, initializeWindSources, respawnWindPatch } from './wind-initialization.js';
import { updateGlobalWind } from './wind.js';
import { resetBoat } from './penalties.js';
import { sampleCurrent } from './current.js';
import { projectPoint, advanceRaceTarget } from './race-targets.js';

export { createHullTrig, initializeCurvedHull, initializeFlatHull } from './hull-geometry.js';
export { createRawTrig } from './terrain.js';

/** Complete original 0x41f0b0: configuration normalization and native terrain. */
export function initializeCourseConfiguration(memory, rng, options = {}) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const f = address => Float80.fromNumber(memory.readF64(address));
  const random = range => scaledRandom(range, rng);
  if (r(0x491194) === 8 && r(0x491188) !== 7) w(0x491194, 1);
  let course = r(0x491194);
  w(0x4a4378, course === 11 ? 1 : 0);
  if (course === 7) {
    w(0x491160, 0); w(0x4ac940, 0); w(0x4ac954, 0);
    if (r(0x491180) < 3 || r(0x491180) > 4) w(0x491180, 3);
  }
  w(0x4a5b9c, 0);
  for (let boat = 0; boat < r(0x49118c); boat++) w(0x4a72dc + boat * 4, 0);
  w(0x4a864c, 0); w(0x4a4ef0, 0);
  if (course === 0) { course = add32(random(r(0x4ac954) === 1 || r(0x4ac950) === 1 ? 5 : 6), 1); w(0x491194, course); }
  if (course === 1 || course === 3) { w(0x4a4ef0, 1); w(0x4a864c, 1); }
  if (course < 5) { w(0x4a4958, 0); w(0x4a5a4c, 0); w(0x4aa804, course); }
  if (course === 5) { w(0x4a4958, 1); w(0x4a5a4c, 0); w(0x4aa804, 1); }
  if (course === 6) { w(0x4a864c, 0); w(0x4a4958, 5); w(0x4aa804, 1); w(0x4a5a4c, 0); }
  if (course === 7) { w(0x4a5a4c, 1); w(0x4aa804, 1); w(0x4a4958, 0); w(0x4ac954, 0); w(0x491160, 0); w(0x4ac9a8, 0); }
  if (course === 8) {
    w(0x4ac940, 0); w(0x4ac954, 0); w(0x4a5b9c, 0); w(0x4a4958, 0); w(0x4ac950, 0);
    if (r(0x4a5a4c) === 1) { w(0x4a5a4c, 1); w(0x4aa804, 1); w(0x4a864c, 0); w(0x4a4ef0, 0); w(0x491160, 0); w(0x4ac9a8, 0); w(0x491180, 3); }
    else { w(0x491180, 1); w(0x4a864c, 1); w(0x4a4ef0, 1); w(0x4a5a4c, 0); w(0x491160, 1); w(0x4aa804, random(10) < 6 ? 1 : 3); }
  }
  if (course === 9 || course === 10) { w(0x4a4ef0, 0); w(0x4a864c, 0); w(0x4aa804, course === 9 ? 1 : 3); w(0x4a4958, course === 9 ? 6 : 7); w(0x4a5a4c, 0); w(0x4a5b9c, 0); }
  if (course === 11) { w(0x4a864c, 0); w(0x4aa804, 4); w(0x4a4958, 0); w(0x4a5a4c, 0); w(0x4a5b9c, 0); }
  if (course >= 12 && course <= 14) { w(0x4a4958, course - 10); w(0x4a5a4c, 0); w(0x4aa804, 4); w(0x4a864c, 0); w(0x4a5b9c, 0); w(0x4a4ef0, 0); }
  if (r(0x4a4958) >= 2) { initializeAdvancedTerrain(memory, rng, options); return; }
  w(0x4aa290, r(0x4aa804) === 1 ? -900 : 900); w(0x4a8e8c, r(0x4aa804) === 1 ? 1 : -1);
  if (r(0x4a4ef0) === 1) { w(0x4a864c, 1); initializeShoreline(memory, rng, options); }
  if ([2, 4].includes(r(0x491194))) {
    memory.writeF64(0x4a6470, f(0x484fe0).subtract(Float80.fromInteger(random(2)).multiply(f(0x485060))).toNumber());
    memory.writeF64(0x4abe60, f(0x484ed0).subtract(Float80.fromInteger(random(2)).multiply(f(0x485060))).toNumber());
    initializeEllipse(memory, rng, options);
  }
  if (r(0x4a4958) === 1) {
    memory.writeF64(0x4a6470, f(0x484ec8).subtract(Float80.fromInteger(random(10)).multiply(f(0x485060))).toNumber());
    memory.writeF64(0x4abe60, f(0x484ec8).subtract(Float80.fromInteger(random(10)).multiply(f(0x485060))).toNumber());
    initializeEllipse(memory, rng, options);
  }
  if (r(0x4a5b9c) === 1) { memory.writeF64(0x4a6470, 3); memory.writeF64(0x4abe60, 1); initializeEllipse(memory, rng, options); }
  if (r(0x4a5a4c) === 1) { memory.writeF64(0x4a6470, 0.5); memory.writeF64(0x4abe60, r(0x491194) === 8 ? 1.4 : 1.1); initializeEllipse(memory, rng, options); }
  w(0x4aa284, imul32(r(0x4aa804), 90)); w(0x4a71a8, add32(r(0x4aa284), 180));
  if (r(0x4a71a8) > 360) w(0x4a71a8, sub32(r(0x4aa284), 180));
  if (r(0x4a4378) === 1) { w(0x4aa804, 4); memory.writeF64(0x4a6470, 0.65); memory.writeF64(0x4abe60, 1.5); initializeEllipse(memory, rng, options); }
}

function initializeStartAngle(memory) {
  const r = address => memory.readI32(address);
  const wind = r(0x4aa390), boatClass = r(0x491188), catamaran = r(0x4ac900);
  let angle = catamaran === 0 ? add32(sub32(idiv32(wind, -3), idiv32(boatClass, 6)), 45) : sub32(46, idiv32(wind, 8));
  if (boatClass === 3) angle = add32(angle, 3);
  if (boatClass === 7) angle = sub32(angle, 2);
  if (boatClass === 8) angle = sub32(angle, 6);
  if (r(0x4ac904) === 1) angle = 55;
  if (boatClass < 7 || catamaran === 1 || r(0x4ac908) === 1) { if (wind < 11) angle = add32(angle, 3); if (wind < 8) angle = add32(angle, 3); }
  memory.writeI32(0x4a4eb0, angle);
}

/** Complete 0x420dd0: starting positions, including both native two-boat modes. */
export function placeStartingBoats(memory, rng, options = {}) {
  options = { ...options, rng };
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const random = range => scaledRandom(range, rng);
  let selection = random(10);
  const angles = [], tacks = [];
  const copyPositions = () => {
    if (r(0x49118c) > 0) {
      memory.writeBytes(0x4a60e0, memory.readBytes(0x4a4ae8, r(0x49118c) * 8));
      memory.writeBytes(0x4a5320, memory.readBytes(0x4a49f0, r(0x49118c) * 8));
    }
  };
  for (let boat = 1; boat <= r(0x49118c); boat++) {
    tacks[boat - 1] = 1;
    if (r(0x491194) === 8) angles[boat - 1] = 180;
    else {
      angles[boat - 1] = add32(random(40), 110);
      if (random(100) > 80 && r(0x491140) < boat) { tacks[boat - 1] = -1; angles[boat - 1] = sub32(-110, random(40)); }
    }
    if (r(0x49118c) === 2 && r(0x4ac9ac) === 0) {
      const first = selection < 6 ? 1 : 2, second = selection < 6 ? 2 : 1;
      angles[0] = selection < 6 ? 290 : 70; angles[1] = selection < 6 ? 70 : 290;
      w(0x4aa730 + first * 4, -1); w(0x4ac018 + first * 4, wrapDegreesOnce(add32(r(0x4abc80), 145)));
      w(0x4aa730 + second * 4, 1); w(0x4ac018 + second * 4, wrapDegreesOnce(sub32(r(0x4abc80), 130)));
    }
    if (r(0x49118c) === 2 && r(0x4ac9ac) === 1) {
      const first = selection < 6 ? 1 : 2, second = selection < 6 ? 2 : 1;
      selection = first;
      w(0x4aa730 + first * 4, 1); w(0x4ac018 + first * 4, wrapDegreesOnce(sub32(r(0x4abc80), 45)));
      w(0x4aa730 + second * 4, -1); w(0x4ac018 + second * 4, wrapDegreesOnce(add32(r(0x4abc80), 45)));
      memory.writeF64(0x4a78e8, r(0x4ac01c));
      memory.writeF64(0x4a49e8 + first * 8, idiv32(add32(r(0x4a70f8), imul32(r(0x4aa594), 3)), 4));
      memory.writeF64(0x4a4ae0 + first * 8, idiv32(add32(r(0x4a72c8), imul32(r(0x4aa59c), 3)), 4));
      memory.writeF64(0x4a49e8 + second * 8, idiv32(add32(r(0x4aa594), imul32(r(0x4a70f8), 3)), 4));
      memory.writeF64(0x4a4ae0 + second * 8, idiv32(add32(r(0x4aa59c), imul32(r(0x4a72c8), 3)), 4));
      for (let other = 1; other <= r(0x49118c); other++) { w(0x4a6f48 + other * 4, r(0x4a8a84)); w(0x4a4888 + other * 4, r(0x4a8a54)); w(0x4a5420 + other * 4, 1); }
      copyPositions(); w(0x4a8914, 1); return;
    }
    if (r(0x49118c) === 2 && r(0x4ac9ac) === 0) w(0x4a8914, 0);
    w(0x4a414c, r(0x4ac020)); initializeStartAngle(memory);
    if (r(0x49118c) > 2 || r(0x491194) === 8) {
      w(0x4ac018 + boat * 4, wrapDegreesOnce(r(0x491194) === 8 ? r(0x4abc80) : add32(imul32(r(0x4a4eb0), tacks[boat - 1]), r(0x4abc80))));
      if (r(0x491140) < boat) w(0x4ac018 + boat * 4, random(360));
    }
    memory.writeF64(0x4a78e8, r(0x4ac01c));
    const divisor = r(0x4aa390) < 11 ? 5 : 4;
    let distance = add32(random(idiv32(imul32(r(0x4aa998), 2), 3)), idiv32(r(0x4aa998), divisor));
    if (tacks[boat - 1] < 0) distance = add32(random(idiv32(r(0x4aa998), 2)), idiv32(r(0x4aa998), divisor));
    if (r(0x49118c) === 2) distance = idiv32(r(0x4aa998), 2);
    if (r(0x4911cc) === 10) distance = imul32(distance, 2);
    projectPoint(memory, r(0x4a4888 + boat * 4), r(0x4a6f48 + boat * 4), distance, wrapDegreesOnce(add32(r(0x4abc80), angles[boat - 1])), options);
    memory.writeF64(0x4a49e8 + boat * 8, r(0x4a70e8)); memory.writeF64(0x4a4ae0 + boat * 8, r(0x4aa81c));
    if (r(0x4ac1dc) > 0) {
      const current = sampleCurrent(memory, r(0x4a70e8), r(0x4aa81c), boat,options);
      const third = idiv32(current, 3), absolute = third < 0 ? sub32(0, third) : third;
      projectPoint(memory, Float80.fromNumber(memory.readF64(0x4a49e8 + boat * 8)).truncI32(), Float80.fromNumber(memory.readF64(0x4a4ae0 + boat * 8)).truncI32(), idiv32(imul32(absolute, r(0x4aa998)), 30), wrapDegreesOnce(r(0x4aa960)), options);
      memory.writeF64(0x4a49e8 + boat * 8, r(0x4a70e8)); memory.writeF64(0x4a4ae0 + boat * 8, r(0x4aa81c));
    }
  }
  if (r(0x49118c) > 2 && r(0x491194) !== 8) {
    const blend = random(16);
    memory.writeF64(0x4a49f0, idiv32(add32(add32(imul32(blend, r(0x4a70f8)), r(0x4aa288)), imul32(r(0x4aa594), sub32(16, blend))), 17));
    memory.writeF64(0x4a4ae8, idiv32(add32(add32(imul32(blend, r(0x4a72c8)), r(0x4aa384)), imul32(r(0x4aa59c), sub32(16, blend))), 17));
  }
  if (r(0x4911cc) < 3) {
    for (let boat = 1; boat <= r(0x49118c); boat++) {
      memory.writeF64(0x4a49e8 + boat * 8, r(0x4a4888 + boat * 4)); memory.writeF64(0x4a4ae0 + boat * 8, r(0x4a6f48 + boat * 4));
      advanceRaceTarget(memory, boat, options); w(0x4aa730 + boat * 4, 1);
    }
    if (r(0x491194) === 8) { w(0x4a8914, 0); w(0x4a8918, 0); }
    else { memory.writeF64(0x4a78e8, wrapDegreesOnce(sub32(r(0x4ac840), r(0x4a4eb0)))); w(0x4ac020, wrapDegreesOnce(sub32(r(0x4ac840), r(0x4a4eb0)))); }
  }
  copyPositions();
}

/** Complete 0x41eb80: original race globals, boat attributes and placement. */
export function initializeBoats(memory, rng, options = {}) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const random = range => scaledRandom(range, rng);
  w(0x4911c0, -1); memory.writeBytes(0x4aa398, new Uint8Array(121 * 4));
  w(0x4911d4, -500); w(0x4ac964, 0); w(0x491198, 1000); w(0x49119c, -300);
  if (r(0x4ac9ac) === 1) { w(0x49118c, 2); w(0x4a7978, 0); w(0x491188, 7); }
  w(0x491168, sub32(random(25), 135));
  for (let index = 0; index < 3; index++) {
    w(0x4a4e88 + index * 4, 2); w(0x4a8660 + index * 4, 4); w(0x4a4608 + index * 4, 0);
    w(0x4a9440 + index * 4, 0); w(0x4a3a18 + index * 4, 20000); w(0x4a6090 + index * 4, 0);
    if (r(0x4ab160 + index * 4) < 0 || r(0x4ab160 + index * 4) > 2) w(0x4ab160 + index * 4, 1);
  }
  w(0x4a6fcc, 95);
  for (let boat = 1; boat <= r(0x49118c); boat++) {
    const offset = (boat - 1) * 4;
    w(0x4a42f4 + offset, 0); if (r(0x4ac940) === 1) w(0x491160, 0);
    for (const base of [0x4a439c, 0x4aa664, 0x4a46ac, 0x4a76d4]) w(base + offset, 0);
    w(0x4a71d0 + (boat - 1) * 8, 0); w(0x4a71d4 + (boat - 1) * 8, 0);
    w(0x4a5f94 + offset, -1); w(0x4aa734 + offset, 1);
    if (r(0x4ac944) === 0) w(0x4a461c + offset, sub32(idiv32(random(49), 10), 2));
    const skill = r(0x491190), baseRate = r(0x4a6fcc);
    if (r(0x491140) < boat) {
      let rate = add32(add32(r(0x4a461c + offset), r(0x491194) === 8 ? sub32(idiv32(sub32(skill, 7), 2), 1) : sub32(skill, 8)), baseRate);
      if (r(0x4ac908) === 1) rate = sub32(rate, 2);
      if (skill === 1) rate = idiv32(imul32(rate, 85), 100);
      if (skill > 11) rate = add32(rate, 1); if (skill > 13) rate = add32(rate, 1);
      w(0x4a6fcc + offset, rate);
    }
    w(0x4a4174 + offset, r(0x491188) === 10 || r(0x4ac90c) === 1 || r(0x4ac908) === 1 || r(0x491188) === 8 ? 3 : 2);
    const phase = random(25); w(0x4a5e94 + offset, r(0x49118c) === 2 ? 0 : phase);
    for (const base of [0x4a41f4, 0x4a7974, 0x4abf1c]) w(base + offset, -2000);
    w(0x4abb74 + offset, 0); w(0x4a764c + offset, 0);
    if (r(0x4ac944) === 0) for (let index = 0; index < 3; index++) w(0x4a6bc4 + (boat - 1) * 16 + index * 4, 0);
  }
  if (r(0x491140) > 0) {
    w(0x4a4388, 0); w(0x4a438c, 0);
    for (let index = 0; index < r(0x491140); index++) {
      for (const base of [0x4a496c, 0x4a684c, 0x4a4e7c, 0x4a89c4]) w(base + index * 4, 0);
      w(0x4a4efc + index * 4, 1); w(0x4a776c + index * 4, 1); w(0x4a85d4 + index * 4, -1);
    }
  }
  memory.writeF64(0x4ac828, r(0x4ac9ac) === 1 ? 0 : r(0x4a4168));
  w(0x4ab8b4, 30000); w(0x4aa980, 1); w(0x4ac99c, 0); w(0x4ac9a0, 0); w(0x4ac8dc, 0);
  if (r(0x49118c) === 2) { let rate = add32(sub32(r(0x491190), r(0x4ac9ac) === 1 ? 12 : 10), r(0x4a6fcc)); if (r(0x4ac908) === 1) rate = sub32(rate, 1); w(0x4a6fd0, rate); }
  if (r(0x491140) === 2) w(0x4a6fd0, add32(r(0x4ac948), r(0x4a6fcc)));
  w(0x4abae4, add32(r(0x4a4168), 10)); w(0x4a60a0, 1);
  for (const address of [0x4a4be8, 0x4ac94c, 0x4ab9d8, 0x4a4bd8, 0x4ab9c4, 0x4ab9d4, 0x4a7754, 0x4a60a8, 0x4abb6c, 0x4ab14c]) w(address, 0);
  for (let boat = 1; boat <= r(0x49118c); boat++) { if (r(0x4ac9ac) === 0) resetBoat(memory, boat); else w(0x4a5420 + boat * 4, 1); }
  placeStartingBoats(memory, rng, options);
  memory.writeBytes(0x4ac694, new Uint8Array(400));
  if (r(0x4911cc) < 3) { w(0x4a8914, 1); if (r(0x491140) === 2) w(0x4a8918, 1); }
}

/** Complete original 0x413f00 fresh-race call sequence. */
export function initializeRace(memory, rng, options = {}) {
  initializeCourseConfiguration(memory, rng, options);
  memory.writeI32(0x4ac93c, 0); memory.writeI32(0x4a8658, memory.readI32(0x491194) === 8 ? 675 : 300);
  let time = -170;
  if (memory.readI32(0x4ac9ac) === 1 || memory.readI32(0x4911cc) < 3) time = 0;
  if (memory.readI32(0x4911cc) === 10) time = -340;
  const raceTime = time === -170 ? -170.5 : time === -340 ? -341 : 0;
  memory.writeI32(0x4a4168, time); memory.writeI32(0x4a5b80, time); memory.writeF64(0x4ac1f8, raceTime);
  memory.writeF64(0x4ab8b8, Float80.fromNumber(raceTime).multiply(Float80.fromNumber(memory.readF64(0x484f08))).toNumber());
  initializeWind(memory, rng); initializeTide(memory, rng); updateGlobalWind(memory, rng, options);
  initializeWindSources(memory, rng); initializeCourse(memory, 10, rng, options); initializeBoats(memory, rng, options);
  for (let patch = 1; patch <= 5; patch++) { memory.writeI32(0x4aaa20 + patch * 4, -300); respawnWindPatch(memory, patch, rng, options); }
}

export const INITIALIZATION_ROUTINES = Object.freeze({ initializeCourseConfiguration: 0x41f0b0, placeStartingBoats: 0x420dd0, initializeBoats: 0x41eb80, initializeRace: 0x413f00 });
