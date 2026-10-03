import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';

const edition = new URL('../', import.meta.url);
const sourceSha256 = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
if (createHash('sha256').update(await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition))).digest('hex') !== sourceSha256)
  throw new Error('Preserved English source differs');
const integerInputs = { counter: 0x536430, angle1: 0x4feccc, angle2: 0x4fecd0,
  waves1: 0x535e44, waves2: 0x535e48, humans: 0x4da140, speedDivisor: 0x4da178,
  wind: 0x4fb384, soundDisabled: 0x536484, control1: 0x4f7124, control2: 0x4f7128,
  module: 0x5359c8, waypointLast: 0x4da1f4, flag1: 0x4f4b38, flag2: 0x4f4b3c, heave: 0x4f8ccc };
const doubleInputs = { previous1: 0x536550, nearest1: 0x536558, countdown1: 0x536560,
  previous2: 0x536568, nearest2: 0x536570, countdown2: 0x536578,
  boat1X: 0x4f6b00, boat1Y: 0x4f6c18, boat2X: 0x4f6b08, boat2Y: 0x4f6c20,
  waypoint0X: 0x4f7220, waypoint0Y: 0x4ff038, waypoint1X: 0x4f7228, waypoint1Y: 0x4ff040 };
const defaults = { counter: 0, angle1: 45, angle2: 45, waves1: 1, waves2: 1, humans: 2,
  speedDivisor: 171, wind: 13, soundDisabled: 0, control1: 0, control2: 0, module: 0x400000,
  waypointLast: 1, flag1: 99, flag2: 88, heave: -321 };
const doubles = { previous1: -123.5, nearest1: 100, countdown1: 0,
  previous2: -456.75, nearest2: 100, countdown2: 0, boat1X: 0, boat1Y: 0, boat2X: 0, boat2Y: 0,
  waypoint0X: 1000, waypoint0Y: 1000, waypoint1X: -1000, waypoint1Y: -1000 };
const cases = [];
const add = (label, inputs = {}, doubleChanges = {}, continuation = false) => cases.push({ label, arguments: [],
  ...(continuation ? { continue: true } : { seed: 0x4432b0 }),
  inputs: { ...defaults, ...inputs }, doubleInputs: { ...doubles, ...doubleChanges } });
for (const speedDivisor of [10, 15, 23, 34, 51, 76, 114, 171, 256, 384, 577, 865, 1297, 1946, 2919]) {
  for (const counter of new Set([-2147483648, -2, -1, 0, 1, 2, Math.trunc(speedDivisor / 3) - 1,
    Math.trunc(speedDivisor / 3), Math.trunc(speedDivisor / 3) + 1, 2147483647])) {
    for (const angle1 of [-2147483648, -1, 0, 59, 60, 79, 80, 89, 90, 91, 179, 359, 2147483647])
      add('all-original-speed-divisors-counter-wrap-and-angle-amplitude', { speedDivisor, counter, angle1 });
  }
}
for (const distance of [0, Number.MIN_VALUE, 1, 3.9999999999999996, 4, 4.000000000000001, 5]) {
  for (const countdown of [-Number.MIN_VALUE, -1, 0, 0.9999999999999999, 1, 1.0000000000000002, 2, 19, 20]) {
    for (const gate of ['audible', 'soundDisabled', 'control1', 'control2'])
      add('both-player-wave-nearness-countdown-and-sound-gates', { waves1: 3, waves2: 4,
        ...(gate === 'audible' ? {} : { [gate]: 1 }) }, { waypoint0X: distance, waypoint0Y: 0,
        countdown1: countdown, countdown2: countdown });
  }
}
for (const humans of [1, 2]) for (const waves1 of [0, 1, 2, 5, 2147483647]) for (const waves2 of [0, 1, 2, 5])
  for (const angle1 of [59, 60, 79, 80, 89, 90, 91])
    add('player-count-wave-strength-and-entry-gates', { humans, waves1, waves2, angle1, angle2: angle1 },
      { waypoint0X: 2, waypoint0Y: 0 });
for (const waypointLast of [-1, 0, 1]) for (const wind of [-2147483648, 0, 12, 13, 2147483647])
  for (const current of [1, 3, 100, 10000]) add('nearest-distance-and-raw-overlapping-previous-F64',
    { waypointLast, wind, waves1: 2, waves2: 2 },
    { nearest1: current, nearest2: -current, waypoint0X: 3, waypoint0Y: 0, waypoint1X: 10, waypoint1Y: 0 });
// A real retained sequence leaves distance, timers and counter owned by the original leaf.
cases.push({ label: 'retained-near-wave-sequence-start', arguments: [], seed: 0x4432b0,
  inputs: { ...defaults, waves1: 3, waves2: 3 }, doubleInputs: { ...doubles, waypoint0X: 2, waypoint0Y: 0 } });
for (let step = 0; step < 80; step++) cases.push({ label: 'retained-near-wave-sequence', arguments: [], continue: true });
const manifest = { source: 'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe', sourceSha256,
  routine: { name: 'updateWaveMotion', address: 0x4432b0, argumentTypes: [], returnType: 'void' },
  integerInputs, integerOutputs: integerInputs, doubleInputs, doubleOutputs: doubleInputs, cases,
  scope: 'Complete original no-argument wave/heave child with real nearest-waypoint dependency, startup027f precision, synthetic declared finite geometry, all original speed divisors, signed counter/amplitude wrap and sound gates. Both overlapping distance pairs are raw binary64. Expected output is captured independently from unchanged original instructions.' };
await writeFile(new URL('analysis/updateWaveMotion-capture-inputs.json', edition), JSON.stringify(manifest, null, 2) + '\n');
console.log(`${cases.length} original wave-motion input cases`);
