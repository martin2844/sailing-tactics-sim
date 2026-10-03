import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';

const edition = new URL('../', import.meta.url);
const sourceSha256 = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
if (sha(await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition))) !== sourceSha256) throw new Error('Preserved English target differs');
const integerPatch = (address, value) => { const bytes = Buffer.alloc(4); bytes.writeInt32LE(value | 0); return { address, bytes: bytes.toString('hex') }; };
const doublePatch = (address, value) => { const bytes = Buffer.alloc(8); bytes.writeDoubleLE(value); return { address, bytes: bytes.toString('hex') }; };
const n = (values, boat = 1) => Object.entries(values).map(([address, value]) => integerPatch(+address + boat * 4, value));
const positions = (boat, x, y) => [doublePatch(0x4f6af8 + boat * 8, x), doublePatch(0x4f6c10 + boat * 8, y)];
async function save(name, address, argumentTypes, returnType, cases) {
  const output = { source: 'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe', sourceSha256,
    routine: { name, address, argumentTypes, returnType }, integerInputs: {}, integerOutputs: {}, doubleInputs: {}, doubleOutputs: {},
    inputEvidence: { scope: 'Explicit finite synthetic states and edge inputs only; no expected values derived from JavaScript. Original 2010 instructions provide every return, full mutable-image delta and RNG state.' }, cases };
  await writeFile(new URL(`analysis/${name}-capture-inputs.json`, edition), JSON.stringify(output, null, 2) + '\n');
  console.log(`${name}: ${cases.length} original-code inputs`);
}

const angles = [-2147483648, -2147483647, -1081, -1080, -721, -720, -361, -360, -181, -180, -1, 0, 1, 179, 180, 181, 359, 360, 361, 719, 720, 1080, 2147483646, 2147483647];
let cases = angles.map(value => ({ label: `signed-${value}`, seed: 2010, arguments: [value] }));
for (let value = -765; value <= 765; value += 3) cases.push({ label: `signed-grid-${value}`, seed: 2010, arguments: [value] });
await save('signedDegrees', 0x41e3a0, ['I32'], 'I32', cases);

cases = [];
for (const boat of [0, 1, 2, 10, 27, 30]) for (const wind of [-360, -1, 0, 89, 180, 359, 720, -2147483648, 2147483647]) for (const difference of [-361, -181, -180, -179, -1, 0, 1, 179, 180, 181, 361]) {
  cases.push({ label: `tack-${boat}-${wind}-${difference}`, seed: 2010, arguments: [boat], patches: n({ 0x522b90: wind, 0x535740: (wind + difference) | 0, 0x522ff0: 7 }, boat) });
}
await save('updateTack', 0x435f90, ['I32'], 'void', cases);

cases = [];
for (const boat of [0, 1, 2, 10, 27, 30]) for (const wind of [0, 89, 180, 359, -2147483648, 2147483647]) for (const tack of [-2147483648, -2, -1, 0, 1, 2, 2147483647]) for (const extra of [-5, 0, 7]) {
  cases.push({ label: `closehauled-${boat}-${wind}-${tack}-${extra}`, seed: 2010, arguments: [boat], patches: [integerPatch(0x4f7200, 47), ...n({ 0x522b90: wind, 0x522ff0: tack, 0x5359e0: extra, 0x535740: 17 }, boat)] });
}
await save('setClosehauledHeading', 0x437520, ['I32'], 'void', cases);

cases = [];
const coordinates = [[0, -0], [30.5, -21.25], [-1200.125, 975.875], [1e8 + 0.125, -1e8 + 0.25], [100.00000000000001, -99.99999999999999], [Number.MIN_VALUE, -Number.MIN_VALUE]];
for (const boat of [0, 1, 2, 10, 27, 30]) for (const [x, y] of coordinates) for (const [venue, time] of [[0, 0], [5, -150], [5, 9], [5, 10], [5, 11], [6, 9]]) {
  cases.push({ label: `start-${boat}-${x}-${y}-${venue}-${time}`, seed: 2010, arguments: [boat], patches: [...positions(boat, x, y), ...Object.entries({ 0x4da1f8: venue, 0x4f8cd0: time, 0x5229d4: 70, 0x522ac8: -110, 0x536410: -170, 0x536414: -15, 0x4fe094: 250, 0x4fe2a0: 15 }).map(([address, value]) => integerPatch(+address, value))] });
}
for (const value of [-2147483648, -1, 0, 1, 2147483647]) cases.push({ label: `start-midpoint-overflow-${value}`, seed: 2010, arguments: [1], patches: [...positions(1, 0, 0), ...[0x536410, 0x536414, 0x4fe094, 0x4fe2a0].map(address => integerPatch(address, value))] });
await save('signedStartDistance', 0x437d40, ['I32'], 'float10', cases);

cases = [];
for (const boat of [0, 1, 2, 10, 27]) for (const angle of [-360, -181, -1, 0, 1, 29, 90, 179, 180, 181, 270, 359, 360, 720]) for (const selector of [0, 1, 2]) for (const tack of [-1, 0, 1]) {
  const other = boat + 1;
  cases.push({ label: `projection-${boat}-${angle}-${selector}-${tack}`, seed: 2010, arguments: [boat, selector, other], patches: [...positions(boat, 210.125, -330.75), ...positions(other, 197.875, -305.625), ...n({ 0x522b90: angle, 0x535740: angle, 0x522ff0: tack }, boat)] });
}
for (const x of [0, Number.MIN_VALUE, 1e8, -1e8]) for (const selector of [0, 1]) cases.push({ label: `projection-coincident-${x}-${selector}`, seed: 2010, arguments: [1, selector, 2], patches: [...positions(1, x, x), ...positions(2, x, x), ...n({ 0x522b90: 0, 0x535740: 0, 0x522ff0: 0 })] });
await save('relativeProjection', 0x439ec0, ['I32', 'I32', 'I32'], 'I64', cases);

cases = [];
for (const boat of [0, 1, 2, 10, 27, 30]) for (const selector of [-4, -1, 0, 1, 2, 3, 4]) for (const mode of [-1, 0, 1, 2, 3]) for (const [x, y] of [[0, 0], [1024.125, -2010.75], [-900.5, 330.25], [2147483647, -2147483648]]) {
  cases.push({ label: `bearing-${boat}-${selector}-${mode}-${x}-${y}`, seed: 2010, arguments: [x, y, selector, boat], patches: [...positions(boat, 0, 0), integerPatch(0x536410, 90), integerPatch(0x536414, -120), ...n({ 0x525a78: mode, 0x4fbb90: -45, 0x535740: 180, 0x522b90: 359 }, boat)] });
}
await save('targetRelativeBearing', 0x43ec20, ['F64', 'F64', 'I32', 'I32'], 'float10', cases);

cases = [];
for (const boat of [0, 1, 2, 10, 27]) for (const angle of [-360, -181, -1, 0, 1, 29, 90, 179, 180, 181, 270, 359, 360, 720]) for (const [dx, dy] of [[0, 0], [3, 4], [-10.5, 10.5], [100, -100], [-100, 100]]) {
  const other = boat + 1;
  cases.push({ label: `ahead-${boat}-${angle}-${dx}-${dy}`, seed: 2010, arguments: [boat, other], patches: [...positions(boat, 1000.125, -700.75), ...positions(other, 1000.125 + dx, -700.75 + dy), ...n({ 0x522b90: angle }, boat)] });
}
await save('aheadAstern', 0x464050, ['I32', 'I32'], 'I64', cases);
