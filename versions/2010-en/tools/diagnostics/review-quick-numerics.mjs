import assert from 'node:assert/strict';
import { readFile, writeFile } from 'node:fs/promises';
import { execFileSync } from 'node:child_process';
import { createHash } from 'node:crypto';
import { Float80, withX87ControlWord } from '../../../../src/runtime/float80.js';
import { atan2Extended } from '../../../../src/runtime/atan.js';
import { sinCosX87 } from '../../../../src/runtime/transcendentals.js';

const root = new URL('../../../../', import.meta.url), edition = new URL('../../', import.meta.url);
const hex = value => Buffer.from(value.toBytes()).toString('hex');
const sha = value => createHash('sha256').update(value).digest('hex');
const historical = (commit, path) => execFileSync('git', ['show', `${commit}:${path}`], { cwd: root, encoding: 'utf8', maxBuffer: 2 ** 20 });
const importSource = async (source, location, extra = '') => import('data:text/javascript;base64,' + Buffer.from(source.replace(/from (['"])([^'"]+)\1/g,
  (_, quote, path) => 'from ' + JSON.stringify(new URL(path, location).href)) + '\n' + extra).toString('base64'));
const previousFloatSource = historical('15fd6ac', 'src/runtime/float80.js');
const previousFloat = await importSource(previousFloatSource, new URL('src/runtime/float80.js', root));
const originalAtanSource = historical('fb856db', 'src/runtime/atan.js');
const originalAtan = await importSource(originalAtanSource, new URL('src/runtime/atan.js', root), 'export { atanUnit };');
const originalTrigSource = historical('fb856db', 'src/runtime/transcendentals.js');
const originalTrig = await importSource(originalTrigSource, new URL('src/runtime/transcendentals.js', root));
const currentSources = await Promise.all(['float80', 'atan', 'transcendentals'].map(async name => ({ name, source: await readFile(new URL(`src/runtime/${name}.js`, root), 'utf8') })));
const exposedAtan = await importSource(currentSources.find(row => row.name === 'atan').source, new URL('src/runtime/atan.js', root), 'export { quickAtanUnit, fastAtanUnit, QUICK_SCALE, QUICK_SHIFT, QUICK_ANCHORS };');
const rawTrigSource = currentSources.find(row => row.name === 'transcendentals').source.replace(
  'const certifiedSine = certify(pairs[wrapped][0]);', 'return { sine: pairs[wrapped][0], cosine: pairs[wrapped][1] };').replace(
  'const certifiedSine=Float80.certifyInterval(sine-1024n,sine+1024n,-80);', 'return { sine, cosine };');
if (rawTrigSource === currentSources.find(row => row.name === 'transcendentals').source) throw new Error('Raw candidate observation did not match exactly');
const exposedTrig = await importSource(rawTrigSource, new URL('src/runtime/transcendentals.js', root), 'export { quickSinCos, fastSinCos, QUICK_SCALE, QUICK_SHIFT, FAST_SCALE, FAST_SHIFT, X87_PI };');

let random = 0x12feca9b13579n;
const random64 = () => random = BigInt.asUintN(64, random * 6364136223846793005n + 1442695040888963407n);
const absolute = value => value < 0n ? -value : value;
const endpoint = (type, integer, exponent) => new type(integer < 0n ? -1 : 1, absolute(integer), exponent);
const imageOrError = build => { try { return { bits: hex(build()) }; } catch (error) { return { error: `${error.name}: ${error.message}` }; } };
let constructors = 0, intervals = 0, integerLoads = 0;
const lengths = [0, 1, 24, 53, 63, 64, 65, 80, 112, 224, 512];
for (let index = 0; index < 18000; index++) {
  const length = lengths[index % lengths.length];
  let magnitude = length === 0 ? 0n : (1n << BigInt(length - 1)) | (random64() & ((1n << BigInt(Math.min(length, 64))) - 1n));
  if (length > 64) magnitude |= random64() << BigInt(length - 64);
  const exponent = [-16450, -16445, -16400, -112, -80, -63, 0, 16320, 16383, -Number.MAX_SAFE_INTEGER][index % 10] + (index % 10 === 9 ? 0 : Number(random64() % 17n) - 8);
  const sign = index % 2 ? -1 : 1;
  assert.deepEqual(imageOrError(() => new Float80(sign, magnitude, exponent)), imageOrError(() => new previousFloat.Float80(sign, magnitude, exponent)), `constructor${index}`);
  constructors++;
  const center = BigInt(sign) * magnitude, radius = random64() & 2047n;
  const lower = center - radius, upper = center + radius;
  if (lower < 0n && upper >= 0n) {
    assert.equal(Float80.certifyInterval(lower, upper, exponent), null);
  } else {
    let expected, actual;
    try {
      const low = endpoint(previousFloat.Float80, lower, exponent), high = endpoint(previousFloat.Float80, upper, exponent);
      expected = { bits: hex(low) === hex(high) ? hex(low) : null };
    } catch (error) { expected = { error: `${error.name}: ${error.message}` }; }
    try { const certified = Float80.certifyInterval(lower, upper, exponent); actual = { bits: certified ? hex(certified) : null }; }
    catch (error) { actual = { error: `${error.name}: ${error.message}` }; }
    assert.deepEqual(actual, expected, `interval${index}`);
  }
  intervals++;
}
for (let index = 0; index < 9000; index++) {
  const integer = BigInt.asIntN(index % 3 === 0 ? 64 : 53, random64());
  assert.equal(hex(Float80.fromInteger(integer)), hex(previousFloat.Float80.fromInteger(integer)), `integer-load${index}`);
  integerLoads++;
}

const originalScale = 1n << 224n;
const atanBounds = { 80: { candidates: 0, maximumUnits: 0 }, 112: { candidates: 0, maximumUnits: 0 } };
const trigBounds = { 80: { components: 0, maximumUnits: 0 }, 112: { components: 0, maximumUnits: 0 } };
let atanOutputs = 0, trigOutputs = 0;
const ratios = [0n, 1n, originalScale];
for (let index = 0n; index <= 64n; index++) for (const delta of [-1n, 0n, 1n]) {
  const anchor = index * originalScale / 64n + delta;
  if (anchor >= 0n && anchor <= originalScale) ratios.push(anchor);
  if (index < 64n) ratios.push((2n * index + 1n) * originalScale / 128n + delta);
}
for (let index = 0; index < 8000; index++) ratios.push((random64() << 160n) | (random64() << 96n) | (random64() << 32n));
for (const ratio of ratios) {
  const original = originalAtan.atanUnit(ratio);
  for (const precision of [80, 112]) {
    const scale = 1n << BigInt(precision), shift = BigInt(224 - precision);
    const candidate = precision === 80 ? exposedAtan.quickAtanUnit((ratio * scale) / originalScale) : exposedAtan.fastAtanUnit((ratio * scale) / originalScale);
    assert.notEqual(candidate, null);
    const difference = absolute((candidate << shift) - original);
    assert.ok(difference <= (1024n << shift), `atan${precision}: unrounded enclosure`);
    atanBounds[precision].candidates++;
    atanBounds[precision].maximumUnits = Math.max(atanBounds[precision].maximumUnits, Number(difference) / Number(1n << shift));
  }
}
for (let index = 0; index < 1800; index++) {
  const leftMagnitude = (1n << 63n) | (random64() >> 1n), rightMagnitude = (1n << 63n) | (random64() >> 1n);
  const difference = Number(random64() % 211n) - 105;
  for (const ySign of [1, -1]) for (const xSign of [1, -1]) for (const controlWord of [0x007f, 0x027f, 0x037f]) withX87ControlWord(controlWord, () => {
    const y = new Float80(ySign, leftMagnitude, -63 + difference), x = new Float80(xSign, rightMagnitude, -63);
    assert.equal(hex(atan2Extended(y, x)), hex(originalAtan.atan2Extended(y, x)), `atan-output${index}`);
    atanOutputs++;
  });
}

for (let index = 0; index < 2200; index++) {
  const magnitude = (1n << 63n) | (random64() >> 1n), exponent = -63 + Number(random64() % 161n) - 100;
  const value = new Float80(index % 2 ? -1 : 1, magnitude, exponent);
  const inputShift = value.exponent + 224;
  const input = BigInt(value.sign) * (inputShift >= 0 ? value.mantissa << BigInt(inputShift) : value.mantissa >> BigInt(-inputShift));
  const half = exposedTrig.X87_PI / 2n, quarter = exposedTrig.X87_PI / 4n;
  const quadrant = input >= 0n ? (input + quarter) / half : (input - quarter) / half;
  const reduced = input - quadrant * half;
  const squared = reduced * reduced / originalScale;
  let sine = reduced, cosine = originalScale, sineTerm = reduced, cosineTerm = originalScale;
  for (let term = 1n;; term++) {
    const even = term * 2n;
    sineTerm = -((sineTerm * squared) / originalScale) / (even * (even + 1n));
    cosineTerm = -((cosineTerm * squared) / originalScale) / ((even - 1n) * even);
    sine += sineTerm; cosine += cosineTerm;
    if (sineTerm === 0n && cosineTerm === 0n) break;
  }
  const wrapped = Number((quadrant % 4n + 4n) % 4n), pairs = [[sine, cosine], [cosine, -sine], [-sine, -cosine], [-cosine, sine]], original = pairs[wrapped];
  for (const precision of [80, 112]) {
    const candidate = precision === 80 ? exposedTrig.quickSinCos(reduced, quadrant) : exposedTrig.fastSinCos(reduced, quadrant);
    assert.notEqual(candidate, null);
    for (const [component, expected] of [['sine', original[0]], ['cosine', original[1]]]) {
      const shift = BigInt(224 - precision), difference = absolute((candidate[component] << shift) - expected);
      assert.ok(difference <= (1024n << shift), `sin-cos${precision}: unrounded enclosure`);
      trigBounds[precision].components++;
      trigBounds[precision].maximumUnits = Math.max(trigBounds[precision].maximumUnits, Number(difference) / Number(1n << shift));
    }
  }
  for (const controlWord of [0x007f, 0x027f, 0x037f]) withX87ControlWord(controlWord, () => {
    const actual = sinCosX87(value), expected = originalTrig.sinCosX87(value);
    assert.equal(hex(actual.sine), hex(expected.sine));
    assert.equal(hex(actual.cosine), hex(expected.cosine));
    trigOutputs += 2;
  });
}
for (const row of currentSources) assert.equal(await readFile(new URL(`src/runtime/${row.name}.js`, root), 'utf8'), row.source, 'Reviewed sources must remain unchanged during proof');
const report = { format: 1, status: 'exact', findings: [],
  scope: 'Independent interval/constructor differential against15fd6ac and unrounded80/112-bit candidate bounds plus final m80 outputs against the unchanged original224-bit algorithm atfb856db; fixed-seed finite corpus and separately established analytic enclosure bounds. This is not a universal claim about vendor transcendental approximations.',
  comparisons: { constructors, intervals, integerLoads, atanBounds, trigBounds, atanOutputs, trigOutputs },
  originalSources: [{ commit: '15fd6ac', path: 'src/runtime/float80.js', sha256: sha(previousFloatSource) }, { commit: 'fb856db', path: 'src/runtime/atan.js', sha256: sha(originalAtanSource) }, { commit: 'fb856db', path: 'src/runtime/transcendentals.js', sha256: sha(originalTrigSource) }],
  reviewedSources: currentSources.map(row => ({ path: `src/runtime/${row.name}.js`, sha256: sha(row.source) })),
  analyticBounds: {
    interval: 'Both endpoints are rounded by the same64-bit normalized() function as the previous public constructor. Monotonic nearest/even rounding certifies the complete interval only if canonical sign, mantissa and exponent agree; crossing signed zero remains uncertified.',
    atan: 'Exact nearest k/64 anchors leave residual magnitude<=1/128. Single quotient adds<1unit, original224-bit table truncation<1unit, initial ratio truncation<1unit; the existing229-unit series bound, PI/quadrant operations and negligible224-bit algorithm errors remain below244candidateunits at80/112 bits, within1024.',
    sinCos: 'The twelve-term quick polynomial has cos remainder S80/24!<2units and sin remainder S80/25!<1unit. Coefficient truncation<12units, eleven Horner truncations<11units, squared-input error<1unit (coefficient derivative sum<1), angle truncation<1unit and final sine multiply<1unit. Original224-bit error is negligible; total<30units. The112-bit series retains its previous<262-unit bound.',
  },
};
await writeFile(new URL('analysis/browser-performance/quick-numerical-review.json', edition), JSON.stringify(report, null, 2) + '\n');
console.log(JSON.stringify(report.comparisons, null, 2));
