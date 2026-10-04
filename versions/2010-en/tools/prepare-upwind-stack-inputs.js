import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';

const edition = new URL('../', import.meta.url);
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const sourceSha256 = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
if (sha(await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition))) !== sourceSha256) throw new Error('Original English executable differs');
const initializedBytes = await readFile(new URL('tests/fixtures/original-initializeRace.json', edition));
const initialized = JSON.parse(initializedBytes);
const baselineFixture = JSON.parse(await readFile(new URL('tests/fixtures/original-boat-options.json', edition)));
const baseline = Buffer.from(baselineFixture.mutableBaseline, 'hex'), base = baselineFixture.mutableBlock.address;
const index = initialized.cases.findIndex(row => row.preparation.selector === 12 && row.preparation.course === 1 && row.preparation.venue === 0);
if (index < 0 || initialized.sourceSha256 !== sourceSha256 || !initialized.provenance.loadedOriginalTextUnchanged) throw new Error('Native keelboat initializer reference differs');
const initial = initialized.cases[index], state = Buffer.from(initialized.mutableBaseline, 'hex');
for (const patch of initial.patches ?? []) state.set(Buffer.from(patch.bytes, 'hex'), patch.address - base);
for (const change of initial.expected.imageChanges) state.set(Buffer.from(change.after, 'hex'), change.address - base);
if (sha(state) !== initial.expected.mutableSha256) throw new Error('Original initialized mutable image differs');
const integer = (address, value) => { const bytes = Buffer.alloc(4); bytes.writeInt32LE(value); return { address, bytes: bytes.toString('hex') }; };
const floating = (address, value) => { const bytes = Buffer.alloc(8); bytes.writeDoubleLE(value); return { address, bytes: bytes.toString('hex') }; };
const runs = [];
for (let start = 0; start < state.length;) {
  if (state[start] === baseline[start]) { start++; continue; }
  let end = start + 1;
  while (end < state.length && state[end] !== baseline[end]) end++;
  runs.push({ address: base + start, bytes: state.subarray(start, end).toString('hex') }); start = end;
}
const cases = [];
for (const fleet of [2, 3, 5, 10, 15, 20, 25, 30]) for (const boat of new Set([1, 2, fleet])) {
  for (const aiLevel of [1, 10]) for (const distance of [100, 101, 500]) for (const aheadRange of [89, 90]) {
    const branchInputs = { fleet, boat, aiLevel, distance, aheadRange, phase: 1, engaged: 1 };
    cases.push({ label: `fleet${fleet}-boat${boat}-ai${aiLevel}-distance${distance}-ahead${aheadRange}`,
      arguments: [40, boat], seed: initial.expected.rngState, branchInputs,
      patches: [...runs, ...[
        [0x4da194, fleet], [0x4da198, aiLevel], [0x4f8cd0, 100], [0x5364e8, 1], [0x53646c, 0],
        [0x4da170, 0], [0x4da1c4, 0], [0x53647c, 9], [0x4feccc, aheadRange],
        [0x4f7f9c, 0], [0x4fe15c, 0], [0x522b98, 0],
        [0x535740 + boat * 4, 10], [0x4fe8a8 + boat * 4, 0], [0x4fe6d0 + boat * 4, 0],
        [0x4f4350 + boat * 4, 0], [0x4f7f98 + boat * 4, 1], [0x4f8300 + boat * 4, distance],
        [0x522ff0 + boat * 4, 1],
      ].map(([address, value]) => integer(address, value)),
        floating(0x4f6b00, 0), floating(0x4f6c18, 0), floating(0x4f6b08, 0), floating(0x4f6c20, -100)],
    });
  }
}
// Initialized two-boat controls exercise the positive, zero and negative local
// result instead of assuming that reordering the conjunction is always inert.
for (const offset of [-100, 0, 100]) {
  const template = cases.find(row => row.branchInputs.fleet === 2 && row.branchInputs.boat === 1 && row.branchInputs.distance === 101 && row.branchInputs.aheadRange === 89);
  cases.push({ ...template, label: `two-boat-projection-offset${offset}`,
    branchInputs: { ...template.branchInputs, projectionOffset: offset },
    patches: [...template.patches, floating(0x4f6c20, offset)] });
}
const manifest = { source: 'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe', sourceSha256,
  routine: { name: 'updateUpwindTactics', address: 0x437e60, argumentTypes: ['I32', 'I32'], returnType: 'void' },
  integerInputs: {}, integerOutputs: { specialTacticalFlag: 0x53647c }, doubleInputs: {}, doubleOutputs: {},
  inputEvidence: { nativeInitializedFixture: 'tests/fixtures/original-initializeRace.json', sha256: sha(initializedBytes), fixtureCase: index,
    originalLoad: { address: 0x4380b6, bytes: '8b442418', operation: 'MOV EAX,[ESP+0x18]' },
    originalFleetGuard: { address: 0x4380c2, bytes: '83fe02', operation: 'CMP ESI,2' },
    scope: 'Native initialized keelboat image supplies explicit inputs only. Fleet counts, odd phase, engaged tactical state, 100/101 distance boundary, AI levels, and two-boat projection controls exercise the original retained-stack branch. All expected output bytes and RNG are captured from unchanged original instructions.' }, cases };
await writeFile(new URL('analysis/upwind-stack-capture-inputs.json', edition), JSON.stringify(manifest, null, 2) + '\n');
console.log(`Prepared ${cases.length} original upwind-stack branch cases`);
