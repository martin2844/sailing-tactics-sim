import { add32,sub32,imul32,idiv32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { sinCosX87 } from '../../../../src/runtime/transcendentals.js';
import { scaledRandom } from '../../../../src/engine/integer-core.js';

const integer=Float80.fromInteger;
const trig=(angle,options)=>{
  if(typeof options.trig?.extended!=='function')throw new TypeError('Load the 2010 native integer-angle reference before initializing terrain');
  return options.trig.extended(angle);
};

/** Complete 0x42da80; 2010 divides the raw-radian phase in x87. */
export function initializeShoreline(memory, rng, options = {}) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const random = range => scaledRandom(range, rng);
  const special = [9, 10].includes(r(0x4da19c));
  const amplitude = special ? add32(random(80), 90) : 130;
  const wavelength = special ? add32(random(250), 200) : 325;
  w(0x4fb6b8, -5500); w(0x4fb6bc, -5500);
  w(0x4fbc3c, r(0x5229d0)); w(0x4fbc38, imul32(r(0x5229d0), 6));
  const phase = special ? 50 : random(100);
  for (let index = 2; index < 36; index++) {
    const spread = random(40), x = imul32(index - 18, 250);
    w(0x4fb6b8 + index * 4, x);
    const radians=integer(x).add(integer(phase)).divide(integer(wavelength));
    const sine=(options.sinCosX87??sinCosX87)(radians).sine;
    let y = add32(imul32(sine.multiply(integer(add32(spread, amplitude))).truncI32(), r(0x5127a4)), r(0x5229d0));
    const cut = { 2: -100, 3: -300, 4: -600, 5: -1000, 8: -1000, 9: -500, 10: -100 }[index];
    if (cut != null) y = add32(y, imul32(r(0x5127a4), cut));
    if (index === 6 || index === 7) y = add32(r(0x5229d0), imul32(r(0x5127a4), -4000));
    w(0x4fbc38 + index * 4, y);
  }
  w(0x4fb748, 5500); w(0x4fb74c, 5500); w(0x4fbcc8, r(0x5229d0));
  w(0x535f64, r(0x4fbc60)); w(0x52317c, r(0x4fb6e0)); w(0x4fbccc, imul32(r(0x5127a4), -6000));
  if (r(0x5230dc) === 1) {
    w(0x534ea0, sub32(r(0x4fbc7c), 500)); w(0x5229cc, r(0x4fb6fc));
    const source = r(0x4da19c) === 9 ? 0x4fb6d0 : 0x4fb728;
    w(0x522e5c, sub32(r(source), r(0x4da19c) === 9 ? 100 : 0)); w(0x522e60, r(source));
    const y = r(r(0x4da19c) === 9 ? 0x4fbc50 : 0x4fbca8);
    w(0x535278, sub32(y, 900)); w(0x535554, sub32(y, 1000));
    w(0x4fb9bc, sub32(r(r(0x4da19c) === 9 ? 0x4fbc48 : 0x4fbcb0), 1100));
  } else {
    w(0x5229cc, r(r(0x4da19c) === 10 ? 0x4fb6d0 : 0x4fb704));
    w(0x534ea0, add32(r(r(0x4da19c) === 10 ? 0x4fbc50 : 0x4fbc84), r(0x4da19c) === 10 ? 700 : 500));
    w(0x522e5c, r(0x4fb71c)); w(0x522e60, r(0x4fb71c));
    w(0x535278, add32(r(0x4fbc9c), 900)); w(0x535554, add32(r(0x4fbc9c), 1000));
    w(0x4fb9bc, add32(r(r(0x4da19c) === 10 ? 0x4fbc48 : 0x4fbcb0), 1100));
  }
  const earlyAnchor = r(0x5230dc) === 1 ? r(0x4da19c) === 9 : r(0x4da19c) === 10;
  w(0x4fb208, r(earlyAnchor ? 0x4fb6c8 : 0x4fb730));
  for (let index = 0; index < 5; index++) {
    const selected = random(28);
    w(0x5116bc + index * 4, r(0x4fb6c4 + selected * 4));
    w(0x535ffc + index * 4, add32(r(0x4fbc38 + (selected + 3) * 4), imul32(imul32(r(0x5127a4), 9 - index), -500)));
    w(0x523084 + index * 4, add32(random(60), 40));
  }
}

/** Complete 0x42d280: original elliptical shoreline/island and decoration RNG. */
export function initializeEllipse(memory, rng, options = {}) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const f = address => Float80.fromNumber(memory.readF64(address));
  const random = range => scaledRandom(range, rng);
  const copy = (target, source, offset = 0) => w(target, add32(r(source), offset));
  w(0x4f4b00, 3000); w(0x535bc8, 0); w(0x4f3858, 0);
  w(0x4f3858, sub32(random(200), 100));
  if (r(0x5230dc) === 2) w(0x535bc8, -1250);
  if (r(0x5230dc) === 4) w(0x535bc8, 1250);
  if (r(0x4f4510) === 1) w(0x4f4b00,4000);
  if (r(0x4f69b8) === 1) { w(0x535bc8, 0); w(0x4f3858, 0); w(0x4f4b00, 1500); }
  if (r(0x4f69b8) > 1) { w(0x535bc8, 0); w(0x4f3858, 0); }
  if (r(0x4f8b78) === 1) { w(0x535bc8, r(0x4da19c) === 8 ? 700 : 500); w(0x4f3858, 0); w(0x4f4b00, r(0x4da19c) === 8 ? 700 : 420); }
  if (r(0x4f8db8) === 1) { w(0x535bc8, 0); w(0x4f3858, 0); w(0x4f4b00, r(0x4da19c) === 8 ? 2500 : 1350); }
  for (let angle = 0; angle < 360; angle += 10) {
    const radius = integer(add32(random(idiv32(r(0x4f4b00), 30)), r(0x4f4b00)));
    const { sine, cosine } = trig(angle,options);
    w(0x4fb6b8 + angle / 10 * 4, add32(sine.multiply(f(0x4fba00)).multiply(radius).truncI32(), r(0x535bc8)));
    w(0x4fbc38 + angle / 10 * 4, sub32(r(0x4f3858), cosine.multiply(f(0x535558)).multiply(radius).truncI32()));
  }
  copy(0x4fb748, 0x4fb6b8); copy(0x4fbcc8, 0x4fbc38);
  const divisor = r(0x4da19c) === 8 && r(0x4f8b78) === 0 ? 1 : 2;
  if (r(0x4f4510) === 1) copy(0x4fb724, 0x4fb724, -300);
  copy(0x4fb750, 0x4fb6b8, 7500); copy(0x4fb754, 0x4fb700, 7500); copy(0x4fb74c, 0x4fb6b8); copy(0x4fb758, 0x4fb700);
  w(0x4fbccc, sub32(r(0x4fbc38), idiv32(6000, divisor)));
  w(0x4fbcd4, add32(idiv32(6000, divisor), r(0x4fbc80)));
  copy(0x4fb760, 0x4fb6b8, -7500); copy(0x4fb75c, 0x4fb700, -7500);
  if (r(0x4f8b78) === 0 && r(0x4f69b8) === 0 && r(0x4f8db8) === 0) {
    if (r(0x5230dc) === 2) for (const [t, s, d = 0] of [[0x535f64, 0x4fbc60], [0x52317c, 0x4fb6e0], [0x534ea0, 0x4fbc70], [0x5229cc, 0x4fb6f0, 400], [0x522e5c, 0x4fb6d0, 900], [0x522e60, 0x4fb6d0, 1000], [0x535278, 0x4fbc50], [0x535554, 0x4fbc50], [0x4fb208, 0x4fb6fc, 700], [0x4fb9bc, 0x4fbc7c]]) copy(t, s, d);
    if (r(0x5230dc) === 4) for (const [t, s, d = 0] of [[0x535f64, 0x4fbca0], [0x5229cc, 0x4fb714, -200], [0x52317c, 0x4fb720], [0x522e5c, 0x4fb708, -900], [0x534ea0, 0x4fbc94], [0x522e60, 0x4fb708, -1000], [0x4fb208, 0x4fb73c, -700], [0x535278, 0x4fbc88], [0x535554, 0x4fbc88], [0x4fb9bc, 0x4fbcbc]]) copy(t, s, d);
  }
  if (r(0x4f8db8) === 1) for (const [t, s, d = 0] of [[0x5229cc, 0x4fb700], [0x534ea0, 0x4fbc80, 500], [0x52317c, 0x4fb6b8], [0x535278, 0x4fbc74, 900], [0x535554, 0x4fbc74, 1000], [0x4fb9bc, 0x4fbcb0, -700], [0x535f64, 0x4fbc38], [0x522e5c, 0x4fb6f4], [0x522e60, 0x4fb6f4], [0x4fb208, 0x4fb730]]) copy(t, s, d);
  if (r(0x4f69b8) === 1) for (const [t, s, d = 0] of [[0x52317c, 0x4fb6b8], [0x5229cc, 0x4fb720, -500], [0x535f64, 0x4fbc38], [0x534ea0, 0x4fbca0], [0x535278, 0x4fbc74, 900], [0x535554, 0x4fbc74, 1000], [0x522e5c, 0x4fb6f4], [0x4fb9bc, 0x4fbcb0, -700], [0x522e60, 0x4fb6f4], [0x4fb208, 0x4fb730]]) copy(t, s, d);
  if (r(0x4f8b78) === 1) {
    copy(0x52317c, 0x535bc8); copy(0x535f64, 0x4f3858, r(0x4da19c) === 8 ? 450 : 200);
    w(0x5229cc, -1000); w(0x534ea0, -4000); w(0x522e5c, 1000); w(0x535278, -6000); w(0x522e60, 800); w(0x535554, -6000);
    if (r(0x4da19c) === 8) { copy(0x4fb208, 0x535bc8); copy(0x4fb9bc, 0x4f3858, -800); }
    else { w(0x4fb208, 1000); w(0x4fb9bc, -4000); }
  }
  if (r(0x4f4510) === 1) for (const [t, s, d = 0] of [[0x52317c, 0x4fb714, 100], [0x535f64, 0x4fbc94], [0x4f3c00, 0x4fbcb0], [0x5229cc, 0x4fb724, -1500], [0x4fe29c, 0x4fb724, -1000], [0x522e5c, 0x4fb6c0, -900], [0x534ea0, 0x4fbca4, 100], [0x4fe810, 0x4fbca4, -200], [0x522e60, 0x4fb6c4, -1000], [0x535278, 0x4fbc40], [0x4fb208, 0x4fb728, -700], [0x535554, 0x4fbc44], [0x4fb9bc, 0x4fbca8], [0x523b10, 0x4fb72c, -700], [0x523b08, 0x4fb730, -700], [0x4f3a30, 0x4fbcac]]) copy(t, s, d);
  for (const [t, s] of [[0x4fbcd0, 0x4fbccc], [0x4fbcd8, 0x4fbcd4], [0x4fbcdc, 0x4fbcd4], [0x4fbce0, 0x4fbccc]]) copy(t, s);
  for (let index = 0; index < 5; index++) {
    let selected = add32(random(12), r(0x5230dc) === 4 ? 21 : 3);
    if (r(0x4f69b8) === 1) selected = add32(random(30), 3);
    const x = 0x4fb6b8 + selected * 4, y = 0x4fbc38 + selected * 4;
    const outputX = 0x5116bc + index * 4, outputY = 0x535ffc + index * 4;
    if (selected < 5 || selected > 32) { copy(outputX, x); w(outputY, sub32(sub32(r(y), 2000), random(2000))); }
    // Original assembly's contradictory test always executes this block.
    w(outputX, add32(add32(random(2000), 2000), r(x))); copy(outputY, y);
    if (selected > 13 && selected < 24) { copy(outputX, x); w(outputY, add32(add32(random(2000), 2000), r(y))); }
    if (selected >= 24 && selected <= 32) { w(outputX, add32(sub32(random(2000), 2000), r(x))); copy(outputY, y); }
    if (r(0x4f8db8) === 1) {
      const branch = random(100);
      selected = add32(random(4), branch < 50 ? 2 : 29);
      copy(outputX, 0x4fb6b8 + selected * 4);
      w(outputY, sub32(sub32(r(0x4fbc38 + selected * 4), 2000), random(2000)));
    }
    if (r(0x4f4510) === 1) {
      selected = add32(random(10), 22); const offset = random(2000);
      copy(outputY, 0x4fbc38 + selected * 4); w(outputX, sub32(sub32(r(0x4fb6b8 + selected * 4), 2000), offset));
    }
    w(0x523084 + index * 4, add32(random(60), 40));
  }
}

/** Complete 0x464a30: advanced-weather course boundaries and current channels. */
export function initializeAdvancedTerrain(memory, rng, options = {}) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const f = address => Float80.fromNumber(memory.readF64(address));
  const random = range => scaledRandom(range, rng);
  const copy = (target, source, offset = 0) => w(target, add32(r(source), offset));
  const weather = r(0x4f69b8);
  let radius = weather === 5 || weather === 6 ? 1500 : weather === 7 ? 1600 : 1200;
  if(r(0x53527c)===1)radius=idiv32(imul32(radius,4),3);
  if(r(0x5364c8)===1)radius=imul32(radius,3)>>2;
  w(0x536300, random(100) < 50 ? 2 : 1);
  if (weather === 2) {
    w(0x536300, random(100) < 33 ? 2 : 1);
    if (random(100) > 66) w(0x536300, 3);
  }
  if (weather === 6 || weather === 7) w(0x536300, 1);
  const mode = r(0x536300);
  let channels;
  // Each row is [radius addition, start index, end index, direction degrees].
  if (weather === 2 && mode === 1) channels = [[radius, 0, 50, 50], [idiv32(radius * 2, 3), 70, 130, 200]];
  if (weather === 2 && mode === 2) channels = [[idiv32(radius, 2), 140, 180, 320], [idiv32(radius, 2), 60, 120, 180]];
  if (weather === 2 && mode === 3) channels = [[idiv32(radius, 2), 0, 50, 50], [idiv32(radius * 2, 3), 60, 105, 164]];
  if (weather === 3 && mode === 1) channels = [[idiv32(radius,2), 0, 30, 30], [idiv32(radius,3), 70, 110, 180], [idiv32(radius,2), 150, 180, 330], [idiv32(radius,2), 130, 150, 280], [radius, 30, 70, 100]];
  if (weather === 3 && mode === 2) channels = [[idiv32(radius,2), 0, 30, 30], [idiv32(radius * 2, 3), 40, 80, 120], [radius, 80, 140, 220], [idiv32(radius,3), 150, 180, 330], [radius, 120, 140, 260]];
  if (weather === 4 && mode === 1) channels = [[radius * 2, 0, 40, 40], [radius * 2, 50, 120, 170], [radius * 2, 140, 170, 310]];
  if (weather === 4 && mode === 2) channels = [[radius * 2, 130, 170, 300], [radius * 2, 10, 70, 80], [radius * 2, 90, 130, 220]];
  // The original writes weather5 twice; the second assignments below win.
  if (weather === 5 && mode === 1) channels = [[radius * 2, 0, 90, 90], [radius * 2, 90, 170, 260]];
  if (weather === 5 && mode !== 1) channels = [[idiv32(radius * 5, 2), 0, 90, 90], [idiv32(radius * 5, 2), 100, 180, 280]];
  if (weather === 6) channels = [[radius * 2, 155, 15, 350], [radius * 4, 20, 90, 110], [radius * 3, 90, 160, 250]];
  if (weather === 7) channels = [[radius * 2, 75, 115, 0], [radius * 4, 0, 70, 70], [radius * 3, 115, 180, 294]];
  if (!channels) throw new RangeError(`Original advanced weather domain requires 2..7; received ${weather}`);
  w(0x5364b4, channels.length);
  channels.forEach(([, start, end, direction], index) => { w(0x4fe134 + index * 4, start); w(0x4f8b84 + index * 4, end); w(0x4fbac4 + index * 4, direction); });
  for (let index = 0; index < 180; index++) {
    const boundary = 0x4ffdd8 + index * 8;
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
        let angle = integer(sub32(index, start)).divide(integer(sub32(end, start))).multiply(f(0x4cc478)).truncI32();
        if (weather === 6 && channel === 0) {
          if (negativeAngle <= -310) angle = sub32(90, integer(add32(negativeAngle, 360)).multiply(f(0x4ccca8)).truncI32());
          if (negativeAngle >= -30) angle = sub32(90, integer(index * 2).multiply(f(0x4cccb0)).truncI32());
        }
        const sine = trig(angle,options).sine;
        contribution = integer(addition).multiply(sine).multiply(sine).multiply(sine).multiply(sine).truncI32();
      }
      memory.writeF64(boundary, integer(contribution).add(f(boundary)).toNumber());
    }
    const enlarged = integer(random(15)).add(f(boundary));
    // FST/FSTP at 0x46531e..34: products use the stored binary64 radius.
    const storedRadius = Float80.fromNumber(enlarged.toNumber());
    memory.writeF64(boundary, storedRadius.toNumber());
    const { sine, cosine } = trig(index*2,options);
    const x = sine.multiply(storedRadius), y = cosine.multiply(storedRadius);
    w(0x4fb6b8 + index * 4, x.truncI32()); w(0x4fbc38 + index * 4, y.negate().truncI32());
    w(0x5127a8 + index * 4, x.multiply(f(0x4cc730)).truncI32());
    w(0x512a80 + index * 4, y.multiply(f(0x4cc788)).truncI32());
  }
  memory.writeBytes(0x500378, memory.readBytes(0x4ffdd8, 8));
  copy(0x4fb988, 0x4fb6b8); copy(0x4fbf08, 0x4fbc38);
  const decorationIndices = weather < 5 ? [100, 108, 122, 133, 150, 35, 50] : weather === 5 ? [155, 174, 5, 18, 30, 85, 97] : weather === 6 ? [135, 145, 152, 20, 25, 33, 40] : [43, 52, 60, 70, 120, 130, 135];
  for (let index = 0; index < 7; index++) {
    const selected = decorationIndices[index];
    copy(0x5116bc + index * 4, 0x4fb6b8 + selected * 4, weather < 5 ? (index < 5 ? -4000 : 4000) : 0);
    copy(0x535ffc + index * 4, 0x4fbc38 + selected * 4, weather < 5 ? 0 : weather === 5 ? (index < 5 ? -3000 : 3000) : weather === 6 ? -3000 : 3000);
    w(0x523084 + index * 4, add32(random(60), 50));
  }
  copy(0x534ea0, 0x4fbcd8 + mode * 20); copy(0x5229cc, 0x4fb758 + mode * 20, 2000);
  if (weather === 5) { copy(0x534ea0, 0x4fbea4, -1000); copy(0x5229cc, 0x4fb924); }
  if (weather < 6) {
    if (mode === 1) for (const [t, s, d = 0] of [[0x522e5c, 0x4fb6bc], [0x522e60, 0x4fb6c0], [0x535278, 0x4fbc3c, -2000], [0x535ecc, 0x4fbd3c, 2000], [0x52338c, 0x4fb7bc, 3000], [0x523594, 0x4fb85c, -2000], [0x536398, 0x4fbddc, 1000]]) copy(t, s, d);
    else for (const [t, s, d = 0] of [[0x522e5c, 0x4fb824], [0x535278, 0x4fbda4, 2000], [0x522e60, 0x4fb828], [0x535ecc, 0x4fbc44, -3000], [0x52338c, 0x4fb6c4], [0x523594, 0x4fb85c, -2000], [0x536398, 0x4fbddc, 1000]]) copy(t, s, d);
    copy(0x535554, 0x535278);
  }
  if (weather === 5) for (const [t, s, d = 0] of [[0x4f4690, 0x4fb760, 1000], [0x4fb418, 0x4fbce0], [0x4fb4ac, 0x4fbcec], [0x4f4698, 0x4fb76c, 1000], [0x4fe810, 0x4fbe68, -1000], [0x4fe29c, 0x4fb8e8, -2000]]) copy(t, s, d);
  if (weather === 4 && mode === 1) for (const [t, s, d = 0] of [[0x4f4690, 0x4fb7f4], [0x4fb418, 0x4fbd74, 3000], [0x4f4698, 0x4fb800], [0x4fb4ac, 0x4fbd80, 3000], [0x4fe29c, 0x4fb8e8, -2000], [0x4fe810, 0x4fbe68, -1000]]) copy(t, s, d);
  if (weather === 4 && mode === 2) for (const [t, s, d = 0] of [[0x4f4690, 0x4fb740, 3000], [0x4fb418, 0x4fbcc0], [0x4f4698, 0x4fb750, 3000], [0x4fb4ac, 0x4fbcd0], [0x4fe29c, 0x4fb898, -2000], [0x4fe810, 0x4fbe18, -2000], [0x523594, 0x4fb870, -2000], [0x536398, 0x4fbdf0, 1000], [0x534ea0, 0x4fbd28, 2000], [0x5229cc, 0x4fb7a8, 2000]]) copy(t, s, d);
  if (weather === 6) for (const [t, s, d = 0] of [[0x52338c, 0x4fb8e8], [0x534ea0, 0x4fbcd8, -1000], [0x522e5c, 0x4fb6d0], [0x522e60, 0x4fb6d4], [0x5229cc, 0x4fb758], [0x535278, 0x4fbc50, -2000], [0x4fe29c, 0x4fb938], [0x4fe810, 0x4fbeb8, -1000], [0x535ecc, 0x4fbe68, -1000], [0x535554, 0x4fbc54, -2000]]) copy(t, s, d);
  if (weather === 7) for (const [t, s, d = 0] of [[0x5229cc, 0x4fb7a8], [0x534ea0, 0x4fbd28, 1000], [0x4fe810, 0x4fbd64, 1000], [0x52338c, 0x4fb898], [0x522e5c, 0x4fb834], [0x4fe29c, 0x4fb7e4], [0x535ecc, 0x4fbe18, 1000], [0x535278, 0x4fbdb4, 2000], [0x535554, 0x4fbdbc, 2000], [0x522e60, 0x4fb83c]]) copy(t, s, d);
}

export const TERRAIN_ROUTINES = Object.freeze({ initializeShoreline: 0x42da80, initializeEllipse: 0x42d280, initializeAdvancedTerrain: 0x464a30 });
