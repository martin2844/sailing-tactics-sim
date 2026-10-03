import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';

const edition = new URL('../', import.meta.url);
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const sourceSha256 = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
if (sha(await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition))) !== sourceSha256) throw new Error('Original target differs');
const fixtureBytes = await readFile(new URL('tests/fixtures/original-initializeRace.json', edition));
const fixture = JSON.parse(fixtureBytes);
if (fixture.sourceSha256 !== sourceSha256 || fixture.provenance.loadedOriginalTextUnchanged !== true || fixture.provenance.x87ControlWord !== '0x027f') throw new Error('Original initialized input authority differs');
const scalar = JSON.parse(await readFile(new URL('tests/fixtures/original-boat-options.json', edition)));
const baseline = Buffer.from(scalar.mutableBaseline, 'hex');
const base = scalar.mutableBlock.address;
const integerPatch = (address, value) => { const bytes = Buffer.alloc(4); bytes.writeInt32LE(value | 0); return { address, bytes: bytes.toString('hex') }; };
const doublePatch = (address, value) => { const bytes = Buffer.alloc(8); bytes.writeDoubleLE(value); return { address, bytes: bytes.toString('hex') }; };
const indexed = (fields, boat) => Object.entries(fields).map(([address, value]) => integerPatch(+address + boat * 4, value));
const positions = (boat, x, y) => [doublePatch(0x4f6af8 + boat * 8, x), doublePatch(0x4f6c10 + boat * 8, y)];
const runs = bytes => {
  const result = []; let first = -1, last = -1;
  for (let index = 0; index < bytes.length; index++) if (bytes[index] !== baseline[index]) {
    if (first < 0) first = last = index;
    else if (index - last <= 16) last = index;
    else { result.push({ address: base + first, bytes: bytes.subarray(first, last + 1).toString('hex') }); first = last = index; }
  }
  if (first >= 0) result.push({ address: base + first, bytes: bytes.subarray(first, last + 1).toString('hex') });
  return result;
};
const profiles = fixture.cases.map((row, index) => {
  const bytes = Buffer.from(fixture.mutableBaseline, 'hex');
  for (const patch of row.patches ?? []) bytes.set(Buffer.from(patch.bytes, 'hex'), patch.address - base);
  for (const patch of row.expected.imageChanges) bytes.set(Buffer.from(patch.after, 'hex'), patch.address - base);
  if (sha(bytes) !== row.expected.mutableSha256) throw new Error('Native initialized input state differs');
  return { index, patches: runs(bytes), boats: bytes.readInt32LE(0x4da194 - base),
    venue: bytes.readInt32LE(0x4da1f8 - base), selector: row.preparation.selector,
    course: bytes.readInt32LE(0x4da19c - base), seed: row.expected.rngState };
});
const terrainBytes = await readFile(new URL('tests/fixtures/original-advanced-terrain.json', edition));
const terrain = JSON.parse(terrainBytes);
if (terrain.sourceSha256 !== sourceSha256 || terrain.provenance.loadedOriginalTextUnchanged !== true) throw new Error('Native advanced geometry input authority differs');
const weatherGeometry = new Map();
for (const row of terrain.cases) if (!weatherGeometry.has(row.inputs.weather) && row.inputs.enlargedTerrain === 0 && row.inputs.reducedTerrain === 0) {
  weatherGeometry.set(row.inputs.weather, [
    ...Object.entries(row.inputs).map(([field, value]) => integerPatch(terrain.integerInputs[field], value)),
    ...Object.entries(row.doubleInputs ?? {}).map(([field, value]) => doublePatch(terrain.doubleInputs[field], value)),
    ...row.expected.imageChanges.map(change => ({ address: change.address, bytes: change.after })),
  ]);
}
const groups = {
  updateBoatWindAndAI: [0x434f70, ['I32'], 'void', []],
  chooseDownwindHeading: [0x435fe0, ['I32', 'I32', 'I32'], 'I32', []],
  scoreDownwindTurn: [0x436400, ['I32', 'I32', 'I32'], 'I32', []],
  sampleSpatialWind: [0x436ba0, ['I32', 'I32', 'I32'], 'I32', []],
  updateUpwindTactics: [0x437e60, ['I32', 'I32'], 'void', []],
  updateCollisionAvoidance: [0x439100, ['I32'], 'void', []],
  avoidAiCollision: [0x4391f0, ['I32', 'I32', 'I32', 'I32'], 'void', []],
  warnHumanRightOfWay: [0x439a30, ['I32', 'I32', 'I32'], 'void', []],
  requestRightOfWaySound: [0x439df0, ['I32'], 'void', []],
  sampleVenueWind: [0x488d70, ['I32', 'I32', 'I32'], 'I32', []],
};
const add = (name, profile, args, label, extra = []) => groups[name][3].push({
  label, arguments: args, seed: profile.seed, patches: [...profile.patches, ...extra],
  preparation: { source: 'Native initialized 2010 output used only as explicitly recorded next input',
    fixtureCase: profile.index, selector: profile.selector, venue: profile.venue, course: profile.course },
});
const active = (boat, time = 100) => [integerPatch(0x4f8cd0, time), integerPatch(0x4f42b8, -170), integerPatch(0x5359c8, 0x400000), integerPatch(0x536484, 0),
  ...indexed({ 0x4fad40: time, 0x4fe638: 0, 0x4fe9d0: time - 30, 0x4f4350: time - 30 }, boat)];
for (const profile of profiles) {
  const boat = Math.min(3, profile.boats), time = [-170, -1, 0, 9, 10, 30, 31, 100, 500][profile.index % 9];
  for (const index of new Set([1, 2, boat])) if (index <= profile.boats) add('updateBoatWindAndAI', profile, [index], 'native-initialized-options-venues-and-courses', active(index, time));
  for (const angle of [0, 44, 70, 71, 100, 179, 180, 359]) {
    add('chooseDownwindHeading', profile, [angle, 47, boat], 'all-native-options-and-turn-thresholds', active(boat));
    add('scoreDownwindTurn', profile, [angle, (angle + 120) % 360, boat], 'all-native-options-and-turn-thresholds', active(boat));
  }
  for (const angle of [0, 45, 90, 180, 270, 359]) add('updateUpwindTactics', profile, [angle, boat], 'all-native-options-venues-and-course-tactics', active(boat));
  for (const [x, y] of [[0, 0], [-1200, -900], [2300, -1700], [-3400, 2400]]) {
    add('sampleSpatialWind', profile, [x, y, 1], 'all-native-venues-and-initialized-shore-points', active(1));
    if (profile.venue > 0) add('sampleVenueWind', profile, [x, y, 1], 'all-native-venues-and-initialized-shore-points', active(1));
  }
  add('updateCollisionAvoidance', profile, [1], 'all-native-classes-counts-and-venues', active(1));
  add('updateCollisionAvoidance', profile, [boat], 'all-native-classes-counts-and-venues', active(boat));
}
// Specific branch inputs supplement genuine original initialized configurations.
const standard = profiles[0];
for (const time of [-170, -4, -1, 0, 1, 2, 3, 9, 10, 30, 31, 100, 500]) for (const boat of [1, 2, 3]) {
  add('updateBoatWindAndAI', standard, [boat], 'time-gates-and-rate-limiter', active(boat, time));
  add('updateBoatWindAndAI', standard, [boat], 'rate-limiter-early-return', [...active(boat, time), ...indexed({ 0x4fad40: time + 2 }, boat)]);
  add('updateBoatWindAndAI', standard, [boat], 'frozen-original-heading-branch', [...active(boat, time), ...indexed({ 0x4fe638: 1 }, boat)]);
}
for (const field of [0x511624, 0x511628, 0x4f6a70, 0x53527c, 0x536408, 0x5363f8, 0x5364cc, 0x5363c0, 0x5363c4, 0x536528, 0x53652c, 0x536530]) for (const boat of [1, 2, 3]) {
  add('updateBoatWindAndAI', standard, [boat], 'new-2010-class-and-control-flags', [...active(boat), integerPatch(field, 1), integerPatch(0x4da140, 2)]);
}
for (const weather of [0, 1, 2, 3, 4, 5, 6, 7]) for (const boat of [0, 1, 2, 3]) for (const [x, y] of [[0, 0], [100, -100], [-950, -400], [1700, 1000]]) {
  add('sampleSpatialWind', standard, [x, y, boat], 'weather-overlap-and-zero-boat', [...(weatherGeometry.get(weather) ?? []), integerPatch(0x4f69b8, weather), ...active(boat)]);
}
for (const time of [-1, 0, 2, 3, 30, 31, 100]) for (const otherTack of [-1, 1]) for (const tack of [-1, 1]) for (const distance of [0, 3, 4, 5, 10, 21, 22]) {
  const patches = [...active(3, time), integerPatch(0x4da140, 1), ...positions(2, 0, -2000), ...positions(3, 5, -2000 + distance),
    ...indexed({ 0x522ff0: otherTack, 0x522b90: 0, 0x535740: 45, 0x4fecc8: 45, 0x4fdfe8: 70 }, 2),
    ...indexed({ 0x522ff0: tack, 0x522b90: 0, 0x535740: 315, 0x4fecc8: 45, 0x4f4208: 0, 0x4fe6d0: 0, 0x4f8300: 300, 0x534f50: 5 }, 3)];
  add('avoidAiCollision', standard, [distance, 2, 3, tack], 'time-radius-overlap-and-tack-branches', patches);
  add('warnHumanRightOfWay', standard, [distance, 2, 3], 'time-radius-overlap-and-tack-branches', patches);
}
for (const profile of profiles.filter(row => row.venue > 0)) for (const boat of [0, 2]) add('sampleVenueWind', profile, [-330, -1000, boat], 'venue-cached-direction-both-player-and-zero', active(boat));
for (const boat of [1, 2, 3]) for (const time of [-1, 0, 1, 9, 10, 30, 100]) for (const last of [-100, -1, 0, 1, 9, 100]) for (const disabled of [0, 1]) {
  add('requestRightOfWaySound', standard, [boat], 'original-sound-delay-and-disable-gates', [...active(boat, time), integerPatch(0x536484, disabled), integerPatch(0x4da140, 2),
    ...indexed({ 0x522dd0: last, 0x4f7120: 1, 0x4fe6d0: 0 }, boat)]);
}
for (const [name, [address, argumentTypes, returnType, cases]] of Object.entries(groups)) {
  const result = { source: 'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe', sourceSha256,
    routine: { name, address, argumentTypes, returnType }, integerInputs: {}, integerOutputs: {}, doubleInputs: {}, doubleOutputs: {},
    inputEvidence: { nativeInitializedFixture: 'tests/fixtures/original-initializeRace.json', sha256: sha(fixtureBytes),
      nativeAdvancedGeometryFixture: 'tests/fixtures/original-advanced-terrain.json', nativeAdvancedGeometrySha256: sha(terrainBytes),
      scope: 'Initialized native outputs are declared input bytes only. Every new AI return, final byte, RNG and ordered sound is captured independently from the original AI instructions.' }, cases };
  await writeFile(new URL(`analysis/${name}-capture-inputs.json`, edition), JSON.stringify(result, null, 2) + '\n');
  console.log(`${name}: ${cases.length} complete original-routine inputs`);
}
