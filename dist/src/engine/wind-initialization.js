import { add32, sub32, imul32, idiv32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { scaledRandom, wrapDegreesOnce } from './integer-core.js';
import { nativeTrig } from './native-trig.js';

/** Complete startup helper 0x42e080: 301 scaled CRT random values, indices 0..300. */
export function initializeWindRandomTable(memory, rng) {
  let returned;
  for (let index = 0; index < 301; index++) {
    returned = scaledRandom(100, rng);
    memory.writeI32(0x4a9450 + index * 4, returned);
  }
  return returned;
}

/** Original 0x41b170: starting wind/weather parameters, with original RNG order. */
export function initializeWind(memory, rng) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const random = range => scaledRandom(range, rng);
  let value = random(4);
  w(0x4a70dc, add32(imul32(value, 3), 10));
  if (r(0x491154) === 1) w(0x4a70dc, add32(value, 8));
  if (r(0x491154) === 2) w(0x4a70dc, add32(value, 12));
  if (r(0x491154) === 3) w(0x4a70dc, add32(value, 16));
  value = random(7);
  w(0x4a5e88, add32(value, 1));
  if (r(0x491194) === 9) {
    if ((r(0x4a5e88) & 1) === 0) w(0x4a5e88, add32(value, 2));
    if (r(0x4a5e88) === 7) w(0x4a5e88, 1);
  }
  if (r(0x491194) === 10) w(0x4a5e88, r(0x4a5e88) > 4 ? 5 : 1);
  if (r(0x4a5e88) > 8) w(0x4a5e88, 1);
  if (r(0x4a5a4c) === 1) w(0x4a5e88, add32(idiv32(random(29), 10), 4));
  if (r(0x491194) === 8) {
    if (r(0x4a5a4c) === 0) w(0x4a5e88, random(10) < 5 ? 7 : 3);
  } else if (r(0x4a5a4c) === 0 && r(0x491140) === 2) w(0x4a5e88, 1);
  w(0x4a4430, wrapDegreesOnce(add32(sub32(random(14), 52), imul32(r(0x4a5e88), 45))));
  w(0x4ac1e0, random(10) < 5 ? 1 : 0);
  value = random(10);
  if (value < 6) w(0x4a8990, add32(r(0x4a5e88), 2));
  w(0x4aa8bc, value >= 6 ? 1 : 0);
  if (r(0x4a8990) > 8) w(0x4a8990, sub32(r(0x4a8990), 8));
  if (value > 5) w(0x4a8990, sub32(r(0x4a5e88), 2));
  if (r(0x4a8990) < 1) w(0x4a8990, add32(r(0x4a8990), 8));
  w(0x4abc7c, sub32(random(5), 2));
  if ([1, 2, 3].includes(r(0x4a8990))) w(0x4abc7c, add32(random(3), 3));
  if ([4, 5, 6].includes(r(0x4a8990))) w(0x4abc7c, sub32(sub32(0, random(3)), 3));
  if (r(0x4ac998) === 1) w(0x4abc7c, sub32(0, r(0x4abc7c)));
  const offset = r(0x4abc7c);
  w(0x4a5a48, (offset < 0 ? sub32(0, offset) : offset) > 4 ? 1 : 0);
  if (r(0x491194) === 8) w(0x4abc7c, idiv32(r(0x4abc7c), 2));
  w(0x4a8a78, 3); w(0x4a7758, 85); w(0x4a5b98, 1);
  if (r(0x4a5e88) > 7 || r(0x4a5e88) < 3) { w(0x4a8a78, 1); w(0x4a7758, 75); }
  if ([7, 3].includes(r(0x4a5e88))) { w(0x4a8a78, 2); w(0x4a7758, 80); }
  if ([2, 3].includes(r(0x4a5e88))) w(0x4a5b98, 3);
  if ([4, 5].includes(r(0x4a5e88))) w(0x4a5b98, 2);
  w(0x4a609c, add32(random(10), 58));
  w(0x4a79ec, idiv32(imul32(sub32(r(0x4a7758), r(0x4a609c)), 3), imul32(imul32(r(0x4a5b98), r(0x4a8a78)), 2)));
  if ([1, 2].includes(r(0x491154))) w(0x4a79ec, idiv32(r(0x4a79ec), 2));
  if (r(0x4a4958) > 0 && r(0x4a4958) < 5) w(0x4a79ec, 0);
  value = r(0x4ac990) === 1 ? 21 : add32(random(4), 10);
  w(0x4a5bac, value); w(0x4a4be4, value);
}

/** Original 0x41b510: tide parameters. Disabled tide retains the other globals. */
export function initializeTide(memory, rng) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const random = range => scaledRandom(range, rng);
  if ((r(0x491158) === 0 && r(0x4a4958) !== 4) || (r(0x4a4958) > 0 && r(0x4a4958) < 4)) {
    w(0x4ac1dc, 0); return;
  }
  w(0x4ac1dc, add32(random(8), 7));
  w(0x4aae1c, wrapDegreesOnce(imul32(r(0x4aa804), 90)));
  if (r(0x4a4958) === 4) {
    w(0x4ac1dc, add32(random(4), 11));
    w(0x4aae1c, r(0x4ac85c) === 1 ? 170 : 80);
  }
  const value = random(12);
  w(0x4a796c, add32(value, 7));
  w(0x4a8020, add32(value, value < 5 ? 13 : 1));
}

/** Original 0x42e0a0: seven primary and five shoreline-aligned wind sources. */
export function initializeWindSources(memory, rng) {
  const random = range => scaledRandom(range, rng);
  for (let index = 0, base = 400; index < 7; index++, base += 50) {
    memory.writeI32(0x4a8870 + index * 4, add32(random(20), base - 450));
    memory.writeI32(0x4a44f0 + index * 4, add32(random(15), 3));
    memory.writeI32(0x4a4928 + index * 4, add32(random(40), 20));
  }
  const direction = imul32(memory.readI32(0x4aa804), 90);
  for (const [index, offset, range, addition] of [[0, -135, 4, 1], [1, -115, 7, 3], [2, -82, 7, 3], [3, -70, 7, 3], [4, -55, 4, 1]]) {
    memory.writeI32(0x4a885c + index * 4, add32(direction, offset));
    memory.writeI32(0x4a44dc + index * 4, add32(random(range), addition));
  }
}

/** Complete 0x41e9c0: one original localized wind-patch respawn. */
export function respawnWindPatch(memory, patch, rng, options = {}) {
  const r = address => memory.readI32(address), w = (address, value) => memory.writeI32(address, value);
  const random = range => scaledRandom(range, rng);
  const distance = add32(random(2000), 500);
  const direction = wrapDegreesOnce(add32(sub32(random(140), 70), r(0x4ac840)));
  const trunc = address => Float80.fromNumber(memory.readF64(address)).truncI32();
  let x = trunc(0x4a49f0), y = trunc(0x4a4ae8);
  if (r(0x491140) !== 1) { x = idiv32(add32(x, trunc(0x4a49f8)), 2); y = idiv32(add32(y, trunc(0x4a4af0)), 2); }
  const { sine, cosine } = nativeTrig(direction, options);
  memory.writeF64(0x4abd88 + patch * 8, sine.multiply(Float80.fromInteger(distance)).add(Float80.fromInteger(x)).toNumber());
  memory.writeF64(0x4a4728 + patch * 8, Float80.fromInteger(y).subtract(cosine.multiply(Float80.fromInteger(distance))).toNumber());
  w(0x4a4e98 + patch * 4, add32(add32(random(2), 2), imul32(r(0x4a888c), 2)));
  w(0x4aaa20 + patch * 4, add32(imul32(add32(random(300), 150), r(0x49115c)), r(0x4a5b80)));
  w(0x4a4ec0 + patch * 4, add32(random(300), 150));
  const half = idiv32(r(0x4aa390), 2);
  w(0x4a4150 + patch * 4, add32(random(half), half));
  const jitter = idiv32(sub32(random(16), 8), add32(r(0x4a888c), 1));
  const center = add32(jitter, r(0x4ac840));
  w(0x4ac0a0 + patch * 4, r(0x4ac998) === 0 ? add32(center, r(0x4a4e98 + patch * 4)) : sub32(center, r(0x4a4e98 + patch * 4)));
}

export const WIND_INITIALIZATION_ROUTINES = Object.freeze({ initializeWindRandomTable: 0x42e080, initializeWind: 0x41b170, initializeTide: 0x41b510, initializeWindSources: 0x42e0a0, respawnWindPatch: 0x41e9c0 });
