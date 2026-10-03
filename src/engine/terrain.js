import { add32, sub32, imul32, idiv32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom } from './integer-core.js';
import { nativeTrig } from './native-trig.js';

const integer = Float80.fromInteger;
const fromBits = bits => Float80.fromBytes(Uint8Array.from(bits.match(/../g), byte => parseInt(byte, 16)));
export function createRawTrig(capture) {
  if (capture?.provenance?.authoritative_engine !== 'native-x87') throw new TypeError('Native raw-radian reference required');
  const rows = capture.angles ?? capture.values;
  return angle => {
    const row = rows?.[angle];
    if (!row) throw new RangeError(`Uncaptured raw integer-radian angle ${angle}`);
    return Object.freeze({ sine: fromBits(row.sineBits), cosine: fromBits(row.cosineBits) });
  };
}

/** Complete 0x41fd90, including its raw integer-radian FSIN input. */
export function initializeShoreline(memory, rng, options = {}) {
  if (!options.rawTrig) throw new Error('Native raw integer-radian FSIN reference required');
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const random = range => scaledRandom(range, rng);
  const special = [9, 10].includes(r(0x491194));
  const amplitude = special ? add32(random(80), 90) : 130;
  const wavelength = special ? add32(random(250), 200) : 325;
  w(0x4a6490, -5500); w(0x4a6494, -5500);
  w(0x4a68cc, r(0x4aa290)); w(0x4a68c8, imul32(r(0x4aa290), 6));
  const phase = special ? 50 : random(100);
  for (let index = 2; index < 36; index++) {
    const spread = random(40), x = imul32(index - 18, 250);
    w(0x4a6490 + index * 4, x);
    let y = add32(imul32(options.rawTrig(idiv32(add32(x, phase), wavelength)).sine.multiply(integer(add32(spread, amplitude))).truncI32(), r(0x4a8e8c)), r(0x4aa290));
    const cut = { 2: -100, 3: -300, 4: -600, 5: -1000, 8: -1000, 9: -500, 10: -100 }[index];
    if (cut != null) y = add32(y, imul32(r(0x4a8e8c), cut));
    if (index === 6 || index === 7) y = add32(r(0x4aa290), imul32(r(0x4a8e8c), -4000));
    w(0x4a68c8 + index * 4, y);
  }
  w(0x4a6520, 5500); w(0x4a6524, 5500); w(0x4a6958, r(0x4aa290));
  w(0x4ac5ec, r(0x4a68f0)); w(0x4aa818, r(0x4a64b8)); w(0x4a695c, imul32(r(0x4a8e8c), -6000));
  if (r(0x4aa804) === 1) {
    w(0x4ab9d0, sub32(r(0x4a690c), 500)); w(0x4aa28c, r(0x4a64d4));
    const source = r(0x491194) === 9 ? 0x4a64a8 : 0x4a6500;
    w(0x4aa654, sub32(r(source), r(0x491194) === 9 ? 100 : 0)); w(0x4aa658, r(source));
    const y = r(r(0x491194) === 9 ? 0x4a68e0 : 0x4a6938);
    w(0x4abc84, sub32(y, 900)); w(0x4abe5c, sub32(y, 1000));
    w(0x4a677c, sub32(r(r(0x491194) === 9 ? 0x4a68d8 : 0x4a6940), 1100));
  } else {
    w(0x4aa28c, r(r(0x491194) === 10 ? 0x4a64a8 : 0x4a64dc));
    w(0x4ab9d0, add32(r(r(0x491194) === 10 ? 0x4a68e0 : 0x4a6914), r(0x491194) === 10 ? 700 : 500));
    w(0x4aa654, r(0x4a64f4)); w(0x4aa658, r(0x4a64f4));
    w(0x4abc84, add32(r(0x4a692c), 900)); w(0x4abe5c, add32(r(0x4a692c), 1000));
    w(0x4a677c, add32(r(r(0x491194) === 10 ? 0x4a68d8 : 0x4a6940), 1100));
  }
  const earlyAnchor = r(0x4aa804) === 1 ? r(0x491194) === 9 : r(0x491194) === 10;
  w(0x4a61e0, r(earlyAnchor ? 0x4a64a0 : 0x4a6508));
  for (let index = 0; index < 5; index++) {
    const selected = random(28);
    w(0x4a899c + index * 4, r(0x4a649c + selected * 4));
    w(0x4ac674 + index * 4, add32(r(0x4a68c8 + (selected + 3) * 4), imul32(imul32(r(0x4a8e8c), 9 - index), -500)));
    w(0x4aa7b4 + index * 4, add32(random(60), 40));
  }
}

/** Complete 0x41f5b0: original elliptical shoreline/island and decoration RNG. */
export function initializeEllipse(memory, rng, options = {}) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const f = address => Float80.fromNumber(memory.readF64(address));
  const random = range => scaledRandom(range, rng);
  const copy = (target, source, offset = 0) => w(target, add32(r(source), offset));
  w(0x4abae8, 3000); w(0x4ac284, 0); w(0x4a3a08, 0);
  w(0x4a3a08, sub32(random(200), 100));
  if (r(0x4aa804) === 2) w(0x4ac284, -1250);
  if (r(0x4aa804) === 4) w(0x4ac284, 1250);
  if (r(0x4a4958) === 1) { w(0x4ac284, 0); w(0x4a3a08, 0); w(0x4abae8, 1250); }
  if (r(0x4a4958) > 1) { w(0x4ac284, 0); w(0x4a3a08, 0); }
  if (r(0x4a5a4c) === 1) { w(0x4ac284, r(0x491194) === 8 ? 700 : 500); w(0x4a3a08, 0); w(0x4abae8, r(0x491194) === 8 ? 700 : 420); }
  if (r(0x4a5b9c) === 1) { w(0x4ac284, 0); w(0x4a3a08, 0); w(0x4abae8, r(0x491194) === 8 ? 2500 : 1350); }
  for (let angle = 0; angle < 360; angle += 10) {
    const radius = integer(add32(random(idiv32(r(0x4abae8), 20)), r(0x4abae8)));
    const { sine, cosine } = nativeTrig(angle, options);
    w(0x4a6490 + angle / 10 * 4, add32(sine.multiply(f(0x4a6470)).multiply(radius).truncI32(), r(0x4ac284)));
    w(0x4a68c8 + angle / 10 * 4, sub32(r(0x4a3a08), cosine.multiply(f(0x4abe60)).multiply(radius).truncI32()));
  }
  copy(0x4a6520, 0x4a6490); copy(0x4a6958, 0x4a68c8);
  const divisor = r(0x491194) === 8 && r(0x4a5a4c) === 0 ? 1 : 2;
  if (r(0x4a4378) === 1) copy(0x4a64fc, 0x4a64fc, -300);
  copy(0x4a6528, 0x4a6490, 7500); copy(0x4a652c, 0x4a64d8, 7500); copy(0x4a6524, 0x4a6490); copy(0x4a6530, 0x4a64d8);
  w(0x4a695c, sub32(r(0x4a68c8), idiv32(6000, divisor)));
  w(0x4a6964, add32(idiv32(6000, divisor), r(0x4a6910)));
  copy(0x4a6538, 0x4a6490, -7500); copy(0x4a6534, 0x4a64d8, -7500);
  if (r(0x4a5a4c) === 0 && r(0x4a4958) === 0 && r(0x4a5b9c) === 0) {
    if (r(0x4aa804) === 2) for (const [t, s, d = 0] of [[0x4ac5ec, 0x4a68f0], [0x4aa818, 0x4a64b8], [0x4ab9d0, 0x4a6900], [0x4aa28c, 0x4a64c8, 400], [0x4aa654, 0x4a64a8, 900], [0x4aa658, 0x4a64a8, 1000], [0x4abc84, 0x4a68e0], [0x4abe5c, 0x4a68e0], [0x4a61e0, 0x4a64d4, 700], [0x4a677c, 0x4a690c]]) copy(t, s, d);
    if (r(0x4aa804) === 4) for (const [t, s, d = 0] of [[0x4ac5ec, 0x4a6930], [0x4aa28c, 0x4a64ec, -200], [0x4aa818, 0x4a64f8], [0x4aa654, 0x4a64e0, -900], [0x4ab9d0, 0x4a6924], [0x4aa658, 0x4a64e0, -1000], [0x4a61e0, 0x4a6514, -700], [0x4abc84, 0x4a6918], [0x4abe5c, 0x4a6918], [0x4a677c, 0x4a694c]]) copy(t, s, d);
  }
  if (r(0x4a5b9c) === 1) for (const [t, s, d = 0] of [[0x4aa28c, 0x4a64d8], [0x4ab9d0, 0x4a6910, 500], [0x4aa818, 0x4a6490], [0x4abc84, 0x4a6904, 900], [0x4abe5c, 0x4a6904, 1000], [0x4a677c, 0x4a6940, -700], [0x4ac5ec, 0x4a68c8], [0x4aa654, 0x4a64cc], [0x4aa658, 0x4a64cc], [0x4a61e0, 0x4a6508]]) copy(t, s, d);
  if (r(0x4a4958) === 1) for (const [t, s, d = 0] of [[0x4aa818, 0x4a6490], [0x4aa28c, 0x4a64f8, -500], [0x4ac5ec, 0x4a68c8], [0x4ab9d0, 0x4a6930], [0x4abc84, 0x4a6904, 900], [0x4abe5c, 0x4a6904, 1000], [0x4aa654, 0x4a64cc], [0x4a677c, 0x4a6940, -700], [0x4aa658, 0x4a64cc], [0x4a61e0, 0x4a6508]]) copy(t, s, d);
  if (r(0x4a5a4c) === 1) {
    copy(0x4aa818, 0x4ac284); copy(0x4ac5ec, 0x4a3a08, r(0x491194) === 8 ? 450 : 200);
    w(0x4aa28c, -1000); w(0x4ab9d0, -4000); w(0x4aa654, 1000); w(0x4abc84, -6000); w(0x4aa658, 800); w(0x4abe5c, -6000);
    if (r(0x491194) === 8) { copy(0x4a61e0, 0x4ac284); copy(0x4a677c, 0x4a3a08, -800); }
    else { w(0x4a61e0, 1000); w(0x4a677c, -4000); }
  }
  if (r(0x4a4378) === 1) for (const [t, s, d = 0] of [[0x4aa818, 0x4a64ec, 100], [0x4ac5ec, 0x4a6924], [0x4a3c00, 0x4a6940], [0x4aa28c, 0x4a64fc, -1500], [0x4a72c4, 0x4a64fc, -1000], [0x4aa654, 0x4a6498, -900], [0x4ab9d0, 0x4a6934, 100], [0x4a77e4, 0x4a6934, -200], [0x4aa658, 0x4a649c, -1000], [0x4abc84, 0x4a68d0], [0x4a61e0, 0x4a6500, -700], [0x4abe5c, 0x4a68d4], [0x4a677c, 0x4a6938], [0x4aaec8, 0x4a6504, -700], [0x4aaec0, 0x4a6508, -700], [0x4a3a30, 0x4a693c]]) copy(t, s, d);
  for (const [t, s] of [[0x4a6960, 0x4a695c], [0x4a6968, 0x4a6964], [0x4a696c, 0x4a6964], [0x4a6970, 0x4a695c]]) copy(t, s);
  for (let index = 0; index < 5; index++) {
    let selected = add32(random(12), r(0x4aa804) === 4 ? 21 : 3);
    if (r(0x4a4958) === 1) selected = add32(random(30), 3);
    const x = 0x4a6490 + selected * 4, y = 0x4a68c8 + selected * 4;
    const outputX = 0x4a899c + index * 4, outputY = 0x4ac674 + index * 4;
    if (selected < 5 || selected > 32) { copy(outputX, x); w(outputY, sub32(sub32(r(y), 2000), random(2000))); }
    // Original assembly's contradictory test always executes this block.
    w(outputX, add32(add32(random(2000), 2000), r(x))); copy(outputY, y);
    if (selected > 13 && selected < 24) { copy(outputX, x); w(outputY, add32(add32(random(2000), 2000), r(y))); }
    if (selected >= 24 && selected <= 32) { w(outputX, add32(sub32(random(2000), 2000), r(x))); copy(outputY, y); }
    if (r(0x4a5b9c) === 1) {
      const branch = random(100);
      selected = add32(random(4), branch < 50 ? 2 : 29);
      copy(outputX, 0x4a6490 + selected * 4);
      w(outputY, sub32(sub32(r(0x4a68c8 + selected * 4), 2000), random(2000)));
    }
    if (r(0x4a4378) === 1) {
      selected = add32(random(10), 22); const offset = random(2000);
      copy(outputY, 0x4a68c8 + selected * 4); w(outputX, sub32(sub32(r(0x4a6490 + selected * 4), 2000), offset));
    }
    w(0x4aa7b4 + index * 4, add32(random(60), 40));
  }
}

/** Complete 0x44e470: advanced-weather course boundaries and current channels. */
export function initializeAdvancedTerrain(memory, rng, options = {}) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const f = address => Float80.fromNumber(memory.readF64(address));
  const random = range => scaledRandom(range, rng);
  const copy = (target, source, offset = 0) => w(target, add32(r(source), offset));
  const weather = r(0x4a4958);
  const radius = weather === 5 ? 1300 : weather === 6 ? 1500 : weather === 7 ? 1600 : 1200;
  w(0x4ac85c, random(100) < 50 ? 2 : 1);
  if (weather === 2) {
    w(0x4ac85c, random(100) < 33 ? 2 : 1);
    if (random(100) > 66) w(0x4ac85c, 3);
  }
  if (weather === 6 || weather === 7) w(0x4ac85c, 1);
  const mode = r(0x4ac85c);
  let channels;
  // Each row is [radius addition, start index, end index, direction degrees].
  if (weather === 2 && mode === 1) channels = [[radius, 0, 50, 50], [idiv32(radius * 2, 3), 70, 130, 200]];
  if (weather === 2 && mode === 2) channels = [[idiv32(radius, 2), 140, 180, 320], [idiv32(radius, 2), 60, 120, 180]];
  if (weather === 2 && mode === 3) channels = [[idiv32(radius, 2), 0, 50, 50], [idiv32(radius * 2, 3), 60, 105, 164]];
  if (weather === 3 && mode === 1) channels = [[radius / 2, 0, 30, 30], [radius / 3, 70, 110, 180], [radius / 2, 150, 180, 330], [radius / 2, 130, 150, 280], [radius, 30, 70, 100]];
  if (weather === 3 && mode === 2) channels = [[radius / 2, 0, 30, 30], [idiv32(radius * 2, 3), 40, 80, 120], [radius, 80, 140, 220], [radius / 3, 150, 180, 330], [radius, 120, 140, 260]];
  if (weather === 4 && mode === 1) channels = [[radius * 2, 0, 40, 40], [radius * 2, 50, 120, 170], [radius * 2, 140, 170, 310]];
  if (weather === 4 && mode === 2) channels = [[radius * 2, 130, 170, 300], [radius * 2, 10, 70, 80], [radius * 2, 90, 130, 220]];
  if (weather === 5 && mode === 1) channels = [[radius * 2, 0, 90, 90], [idiv32(radius * 3, 2), 90, 170, 260]];
  if (weather === 5 && mode !== 1) channels = [[idiv32(radius * 3, 2), 0, 90, 90], [idiv32(radius * 3, 2), 100, 180, 280]];
  if (weather === 6) channels = [[radius * 2, 155, 15, 350], [radius * 4, 20, 90, 110], [radius * 3, 90, 160, 250]];
  if (weather === 7) channels = [[radius * 2, 75, 115, 0], [radius * 4, 0, 70, 70], [radius * 3, 115, 180, 294]];
  if (!channels) throw new RangeError(`Original advanced weather domain requires 2..7; received ${weather}`);
  w(0x4ac9f4, channels.length);
  channels.forEach(([, start, end, direction], index) => { w(0x4a7184 + index * 4, start); w(0x4a5a54 + index * 4, end); w(0x4a67bc + index * 4, direction); });
  for (let index = 0; index < 180; index++) {
    const boundary = 0x4a8028 + index * 8;
    memory.writeF64(boundary, radius);
    const negativeAngle = -2 * index;
    for (let channel = 0; channel < channels.length; channel++) {
      const [addition, start, end] = channels[channel];
      let active = index >= start && index <= end;
      if (weather === 6) {
        active = channel === 0 || active;
        if (channel === 0 && negativeAngle < -30 && negativeAngle >= -180) active = false;
        if (channel === 0 && negativeAngle < -180 && negativeAngle > -310) active = false;
      }
      let contribution = 0;
      if (active) {
        let angle = integer(sub32(index, start)).divide(integer(sub32(end, start))).multiply(f(0x484d28)).truncI32();
        if (weather === 6 && channel === 0) {
          if (negativeAngle <= -310) angle = sub32(90, integer(add32(negativeAngle, 360)).multiply(f(0x485400)).truncI32());
          if (negativeAngle >= -30) angle = sub32(90, integer(index * 2).multiply(f(0x485408)).truncI32());
        }
        const sine = nativeTrig(angle, options).sine;
        contribution = integer(addition).multiply(sine).multiply(sine).multiply(sine).multiply(sine).truncI32();
      }
      memory.writeF64(boundary, integer(contribution).add(f(boundary)).toNumber());
    }
    const enlarged = integer(random(15)).add(f(boundary));
    // FST/FSTP at 0x44ec72..88: products use the stored binary64 radius.
    const storedRadius = Float80.fromNumber(enlarged.toNumber());
    memory.writeF64(boundary, storedRadius.toNumber());
    const { sine, cosine } = nativeTrig(index * 2, options);
    const x = sine.multiply(storedRadius), y = cosine.multiply(storedRadius);
    w(0x4a6490 + index * 4, x.truncI32()); w(0x4a68c8 + index * 4, y.negate().truncI32());
    w(0x4a8e90 + index * 4, x.multiply(f(0x484eb8)).truncI32());
    w(0x4a9168 + index * 4, y.multiply(f(0x484f30)).truncI32());
  }
  memory.writeBytes(0x4a85c8, memory.readBytes(0x4a8028, 8));
  copy(0x4a6760, 0x4a6490); copy(0x4a6b98, 0x4a68c8);
  const decorationIndices = weather < 5 ? [100, 108, 122, 133, 150, 35, 50] : weather === 5 ? [155, 174, 5, 18, 30, 85, 97] : weather === 6 ? [135, 145, 152, 20, 25, 33, 40] : [43, 52, 60, 70, 120, 130, 135];
  for (let index = 0; index < 7; index++) {
    const selected = decorationIndices[index];
    copy(0x4a899c + index * 4, 0x4a6490 + selected * 4, weather < 5 ? (index < 5 ? -4000 : 4000) : 0);
    copy(0x4ac674 + index * 4, 0x4a68c8 + selected * 4, weather < 5 ? 0 : weather === 5 ? (index < 5 ? -3000 : 3000) : weather === 6 ? -3000 : 3000);
    w(0x4aa7b4 + index * 4, add32(random(60), 50));
  }
  copy(0x4ab9d0, 0x4a6968 + mode * 20); copy(0x4aa28c, 0x4a6530 + mode * 20, 2000);
  if (weather === 5) { copy(0x4ab9d0, 0x4a6b34, -1000); copy(0x4aa28c, 0x4a66fc); }
  if (weather < 6) {
    if (mode === 1) for (const [t, s, d = 0] of [[0x4aa654, 0x4a6494], [0x4aa658, 0x4a6498], [0x4abc84, 0x4a68cc, -2000], [0x4ac564, 0x4a69cc, 2000], [0x4aa95c, 0x4a6594, 3000], [0x4aa994, 0x4a6634, -2000], [0x4ac8e0, 0x4a6a6c, 1000]]) copy(t, s, d);
    else for (const [t, s, d = 0] of [[0x4aa654, 0x4a65fc], [0x4abc84, 0x4a6a34, 2000], [0x4aa658, 0x4a6600], [0x4ac564, 0x4a68d4, -3000], [0x4aa95c, 0x4a649c], [0x4aa994, 0x4a6634, -2000], [0x4ac8e0, 0x4a6a6c, 1000]]) copy(t, s, d);
    copy(0x4abe5c, 0x4abc84);
  }
  if (weather === 5) for (const [t, s, d = 0] of [[0x4a4418, 0x4a6538, 1000], [0x4a63b8, 0x4a6970], [0x4a643c, 0x4a697c], [0x4a4420, 0x4a6544, 1000], [0x4a77e4, 0x4a6af8, -1000], [0x4a72c4, 0x4a66c0, -2000]]) copy(t, s, d);
  if (weather === 4 && mode === 1) for (const [t, s, d = 0] of [[0x4a4418, 0x4a65cc], [0x4a63b8, 0x4a6a04, 3000], [0x4a4420, 0x4a65d8], [0x4a643c, 0x4a6a10, 3000], [0x4a72c4, 0x4a66c0, -2000], [0x4a77e4, 0x4a6af8, -1000]]) copy(t, s, d);
  if (weather === 4 && mode === 2) for (const [t, s, d = 0] of [[0x4a4418, 0x4a6518, 3000], [0x4a63b8, 0x4a6950], [0x4a4420, 0x4a6528, 3000], [0x4a643c, 0x4a6960], [0x4a72c4, 0x4a6670, -2000], [0x4a77e4, 0x4a6aa8, -2000], [0x4aa994, 0x4a6648, -2000], [0x4ac8e0, 0x4a6a80, 1000], [0x4ab9d0, 0x4a69b8, 2000], [0x4aa28c, 0x4a6580, 2000]]) copy(t, s, d);
  if (weather === 6) for (const [t, s, d = 0] of [[0x4aa95c, 0x4a66c0], [0x4ab9d0, 0x4a6968, -1000], [0x4aa654, 0x4a64a8], [0x4aa658, 0x4a64ac], [0x4aa28c, 0x4a6530], [0x4abc84, 0x4a68e0, -2000], [0x4a72c4, 0x4a6710], [0x4a77e4, 0x4a6b48, -1000], [0x4ac564, 0x4a6af8, -1000], [0x4abe5c, 0x4a68e4, -2000]]) copy(t, s, d);
  if (weather === 7) for (const [t, s, d = 0] of [[0x4aa28c, 0x4a6580], [0x4ab9d0, 0x4a69b8, 1000], [0x4a77e4, 0x4a69f4, 1000], [0x4aa95c, 0x4a6670], [0x4aa654, 0x4a660c], [0x4a72c4, 0x4a65bc], [0x4ac564, 0x4a6aa8, 1000], [0x4abc84, 0x4a6a44, 2000], [0x4abe5c, 0x4a6a4c, 2000], [0x4aa658, 0x4a6614]]) copy(t, s, d);
}

export const TERRAIN_ROUTINES = Object.freeze({ initializeShoreline: 0x41fd90, initializeEllipse: 0x41f5b0, initializeAdvancedTerrain: 0x44e470 });
