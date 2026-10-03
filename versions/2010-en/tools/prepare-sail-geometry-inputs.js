import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { withX87ControlWord } from '../../../src/runtime/float80.js';
import { initializeBoatOptions } from '../src/engine/boat-options.js';

const edition = new URL('../', import.meta.url);
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const source = await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition));
const oldSource = await readFile(new URL('../../../original/Tact02Demo.exe', import.meta.url));
const oldFixtureBytes = await readFile(new URL('../../../tests/fixtures/original-sail-geometry.json', import.meta.url));
const oldFixture = JSON.parse(oldFixtureBytes);
const sourceMapBytes = await readFile(new URL('analysis/sail-geometry-source-map.json', edition));
const sourceMap = JSON.parse(sourceMapBytes);
const optionFixtureBytes = await readFile(new URL('tests/fixtures/original-boat-options.json', edition));
const optionFixture = JSON.parse(optionFixtureBytes);
const baseline = Buffer.from(optionFixture.mutableBaseline, 'hex'), base = optionFixture.mutableBlock.address;
if (sha(source) !== optionFixture.sourceSha256 || sha(oldSource) !== oldFixture.provenance.sha256)
  throw new Error('Preserved source/input binary differs');
const memory = loadPE32(source), oldMemory = loadPE32(oldSource), oldBaseline = oldMemory.bytes.slice();
const mapped = new Map(Object.entries(sourceMap.addresses).map(([from, to]) => [Number(from), Number(to)]));
const geometryRanges = [
  { oldAddress: 0x4a3a38, address: 0x4f3a38, count: 17, stride: 8, type: 'F64', name: 'prepared hull Y' },
  { oldAddress: 0x4ac310, address: 0x535c68, count: 17, stride: 8, type: 'F64', name: 'prepared hull X' },
];
const controlRanges = [0x4a7768,0x4a4ef8,0x4a4170,0x4ac5f0,0x4a6ec8,0x4aa730,
  0x4a77e8,0x4a8aa8,0x4a85d0,0x4a7bc8,0x4abb70].map(oldAddress =>
  ({ oldAddress, address: mapped.get(oldAddress), count: 35, stride: 4, type: 'I32' }));
if (controlRanges.some(range => range.address === undefined)) throw new Error('Declared source mapping misses a control range');
function mapInputAddress(address) {
  const direct = mapped.get(address);
  if (direct !== undefined) return direct;
  for (const range of [...geometryRanges, ...controlRanges]) {
    if (address >= range.oldAddress && address < range.oldAddress + range.count * range.stride)
      return range.address + address - range.oldAddress;
  }
  throw new Error('Input outside the declared geometry/control mappings: 0x'+address.toString(16));
}
const oldRows = oldFixture.routines.initializeSailGeometry.cases;
if (oldRows.length !== 960) throw new Error('Finite geometry input domain differs');
function copyPreparedInput(oldIndex) {
  const row = oldRows[oldIndex];
  memory.writeBytes(base, baseline);
  oldMemory.bytes.set(oldBaseline);
  // These are exclusively old pre-call inputs produced by flat-hull preparation.
  // The old sail routine's expected output, return values and store traces are
  // never accessed; all 2010 expected output is captured from the target below.
  for (const input of row.imageInputs) oldMemory.writeBytes(input.address, Buffer.from(input.bits, 'hex'));
  for (const range of geometryRanges) {
    for (let index = 0; index < range.count; index++) {
      const address = range.oldAddress + index * range.stride;
      if (!Number.isFinite(oldMemory.readF64(address))) throw new Error('Old prepared geometry input is nonfinite');
    }
    memory.writeBytes(range.address, oldMemory.readBytes(range.oldAddress, range.count * range.stride));
  }
  for (const input of row.inputs) {
    const address = mapInputAddress(input.address);
    if (input.type === 'F64') {
      if (!Number.isFinite(input.value)) throw new Error('Old declared floating input is nonfinite');
      memory.writeF64(address, input.value);
    } else if (input.type === 'I32') memory.writeI32(address, input.value);
    else throw new Error('Unsupported declared old input type');
  }
  return row;
}
const differences = after => {
  const runs = []; let first = -1, last = -1;
  for (let index = 0; index < after.length; index++) if (after[index] !== baseline[index]) {
    if (first < 0) first = last = index;
    else if (index - last <= 16) last = index;
    else {
      runs.push({ address: base + first, bytes: Buffer.from(after.subarray(first, last + 1)).toString('hex') });
      first = last = index;
    }
  }
  if (first >= 0) runs.push({ address: base + first, bytes: Buffer.from(after.subarray(first, last + 1)).toString('hex') });
  return runs;
};
const cases = [];
const controls = { trim: 0x4fe778, jib: 0x4f7ee0, mode: 0x4f42c0, heel: 0x4fc2c0, tack: 0x522ff0,
  angleOffset: 0x4fe818, actualDepower: 0x512278, manualDepower: 0x500380, sailingAngle: 0x4fecc8,
  spin: 0x5350d8, retainedCrew: 0x535f68 };
function record(group, oldIndex, arguments_, preparation) {
  if (arguments_.some(value => !Number.isFinite(value))) throw new Error('Nonfinite argument outside leaf domain');
  cases.push({ group, arguments: arguments_, seed: (0x20100000 + cases.length * 37) >>> 0,
    patches: differences(memory.readBytes(base, baseline.length)), preparation: {
      oldFiniteInputCase: oldIndex, original2002FlatHullArguments: oldRows[oldIndex].prepareOriginal[0].arguments,
      source: 'Finite synthetic pre-call hull inputs and typed controls only; all expected output is fresh original2010 native execution.',
      ...preparation,
    } });
}
for (let index = 0; index < oldRows.length; index++) {
  const row = copyPreparedInput(index);
  record('mapped2002-finite-input-domain', index, row.arguments, { selector: null,
    boatClass: memory.readI32(0x4da190), globals: 'Mapped old synthetic class/subtype combinations; all new subtype flags retain original2010 baseline values' });
}
function prepare(selector, boat, changes = {}, argumentChanges = {}, group = 'all27-original-selector-subtypes') {
  const oldIndex = (cases.length * 17) % oldRows.length;
  const oldRow = copyPreparedInput(oldIndex);
  for (const [field, value] of Object.entries({ ...optionFixture.cases[0].inputs, selector }))
    memory.writeI32(optionFixture.integerInputs[field], value);
  withX87ControlWord(0x027f, () => initializeBoatOptions(memory));
  memory.writeI32(0x4da140, changes.humans ?? 1);
  const defaults = { trim: 2, jib: 2, mode: 2, heel: 10, tack: 1, angleOffset: 5,
    actualDepower: 21, manualDepower: 25, sailingAngle: 120, spin: 1, retainedCrew: 99 };
  for (const [field, value] of Object.entries({ ...defaults, ...changes })) {
    if (field === 'humans' || field === 'flags' || field === 'sway' || field === 'drift') continue;
    if (controls[field] === undefined) throw new Error('Unknown explicit sail control');
    memory.writeI32(controls[field] + boat * 4, value);
  }
  for (const [address, value] of Object.entries(changes.flags ?? {})) memory.writeI32(Number(address), value);
  memory.writeF64(0x4f3f50, changes.sway ?? 3.25);
  memory.writeF64(0x5355f8, changes.drift ?? 3.99);
  const arguments_ = [argumentChanges.height ?? oldRow.arguments[0], boat, argumentChanges.baseIndex ?? 3,
    argumentChanges.curvature ?? 31, argumentChanges.viewHeading ?? 11, argumentChanges.widthScale ?? oldRow.arguments[5]];
  record(group, oldIndex, arguments_, { selector, boatClass: memory.readI32(0x4da190), changes, argumentChanges,
    sourceOptions: 'Complete independently proven original2010 boat-options source supplies all menu subtype flags before explicit boundary overrides' });
}
for (let selector = 1; selector <= 27; selector++) for (const boat of [1, 2]) for (const tack of [-1, 1])
  for (const spin of [0, 1]) prepare(selector, boat, { tack, spin });
for (const selector of [1, 3, 7, 11, 12, 13, 15, 16, 17, 19, 20, 24, 25, 26, 27])
  for (const trim of [0, 1, 2, 3, 4, 5]) for (const boat of [1, 2])
    prepare(selector, boat, { trim, jib: trim, humans: 2 }, {}, 'trim-jib-and-human-versus-ai');
for (const selector of [3, 7, 11, 12, 13, 17, 25, 26, 27])
  for (const sailingAngle of [29, 30, 31, 35, 36, 101, 102, 103, 111, 112, 113, 131, 132, 133, 180])
    for (const spin of [-1, 0, 1, 2])
      prepare(selector, 1, { sailingAngle, spin, mode: spin === 2 ? 3 : 2 }, {}, 'jib-angle-spinnaker-and-override-boundaries');
for (const selector of [3, 7, 11, 12, 15, 17, 25, 26, 27])
  for (const heel of [-1, 0, 10, 70, 90]) for (const depower of [19, 20, 21, 69, 70, 71])
    prepare(selector, 2, { heel, actualDepower: depower, manualDepower: depower, humans: 2 }, {}, 'heel-and-depower-cutoffs');
for (const selector of [1, 3, 12, 17, 25, 26, 27]) for (const curvature of [-1, 0, 1, 4, 5, 15, 31, 80, 180])
  for (const viewHeading of [-180, -11, -10, 0, 10, 11, 180])
    prepare(selector, 1, {}, { curvature, viewHeading }, 'curvature-and-heading-thresholds');
for (const selector of [3, 25, 26, 27]) for (const drift of [-3.99, -0, 0, 2.99, 3.99, 4])
  for (const boat of [1, 2]) prepare(selector, boat, { drift }, {}, 'board-drift-truncation-and-signed-zero');
for (const selector of [1, 12, 17, 25, 26, 27]) for (const height of [0, 0.1, 17.3, 17.300000000000004, 35.5])
  for (const widthScale of [0, 0.01, 0.4, 0.4000000000000001, 1.3])
    prepare(selector, 1, {}, { height, widthScale }, 'finite-height-width-binary64-boundaries');
for (const selector of [25, 26, 27]) for (const boat of [1, 2, 30]) for (const baseIndex of [1, 3, 4, 15])
  prepare(selector, boat, {}, { baseIndex }, 'new-classes-full-index-strides');
const flags = [0x5363b8,0x5363bc,0x5363c0,0x5363c4,0x5363cc,0x4fb410,0x5364bc,0x5364c0,
  0x5364c4,0x5364c8,0x536528,0x53652c,0x536530];
for (const flag of flags) for (const value of [-1, 0, 1, 2, 3]) for (const boat of [1, 2])
  prepare(12, boat, { flags: { [flag]: value } }, {}, 'raw-subtype-exact-one-and-positive-tests');
const manifest = { source: optionFixture.source, sourceSha256: optionFixture.sourceSha256,
  x87ControlWord: '0x027f', mutableBlock: optionFixture.mutableBlock,
  routine: { name: 'initializeSailGeometry', address: 0x41bfb0,
    argumentTypes: ['F64', 'I32', 'I32', 'I32', 'I32', 'F64'], returnType: 'void' },
  integerInputs: {}, integerOutputs: {}, doubleInputs: {}, doubleOutputs: {}, cases,
  inputEvidence: { finiteInputFixture: 'tests/fixtures/original-sail-geometry.json',
    finiteInputFixtureSha256: sha(oldFixtureBytes), finiteInputSourceSha256: sha(oldSource), oldInputCases: oldRows.length,
    fieldsReadFromOldCases: ['arguments', 'inputs', 'imageInputs', 'prepareOriginal.arguments'],
    oldExpectedOutputsUsed: false, sourceMapping: 'analysis/sail-geometry-source-map.json', sourceMappingSha256: sha(sourceMapBytes),
    geometryRanges, controlRanges, original2010OptionsFixtureSha256: sha(optionFixtureBytes),
    scope: 'Build-time preparation copies declared finite hull/control inputs only. No runtime address adapter, original2002 routine call or old expected output is used. Every expected output comes from an unchanged original2010 0x41bfb0 call at precision53.' },
};
await writeFile(new URL('analysis/sail-geometry-capture-inputs.json', edition), JSON.stringify(manifest, null, 2)+'\n');
console.log(`${cases.length} complete 2010 sail geometry inputs, including ${oldRows.length} declared older finite input seeds`);
