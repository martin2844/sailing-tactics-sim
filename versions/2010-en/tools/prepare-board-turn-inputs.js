import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';

const edition = new URL('../', import.meta.url);
const digest = bytes => createHash('sha256').update(bytes).digest('hex');
const sourceSha256 = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
if (digest(await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition))) !== sourceSha256) throw new Error('Original English executable differs');
const initializedBytes = await readFile(new URL('tests/fixtures/original-initializeRace.json', edition));
const initialized = JSON.parse(initializedBytes);
const options = JSON.parse(await readFile(new URL('tests/fixtures/original-boat-options.json', edition)));
const baseline = Buffer.from(options.mutableBaseline, 'hex'), base = options.mutableBlock.address;
const index = initialized.cases.findIndex(row => row.preparation.selector === 3 && row.preparation.course === 1 && row.preparation.venue === 0);
if (index < 0 || initialized.sourceSha256 !== sourceSha256 || !initialized.provenance.loadedOriginalTextUnchanged) throw new Error('Native board initializer reference differs');
const initial = initialized.cases[index], board = Buffer.from(initialized.mutableBaseline, 'hex');
for (const patch of initial.patches ?? []) board.set(Buffer.from(patch.bytes, 'hex'), patch.address - base);
for (const change of initial.expected.imageChanges) board.set(Buffer.from(change.after, 'hex'), change.address - base);
if (digest(board) !== initial.expected.mutableSha256 || board.readInt32LE(0x5363bc - base) !== 1) throw new Error('Original board initialized state differs');
const integer = (address, value) => { const bytes = Buffer.alloc(4); bytes.writeInt32LE(value); return { address, bytes: bytes.toString('hex') }; };
const runs = [];
for (let start = 0; start < board.length;) {
  if (board[start] === baseline[start]) { start++; continue; }
  let end = start + 1;
  while (end < board.length && board[end] !== baseline[end]) end++;
  runs.push({ address: base + start, bytes: board.subarray(start, end).toString('hex') }); start = end;
}
const cases = [];
for (const boat of [1, 2, 3, 12]) for (const boardFlag of [0, 1]) for (const speed of [9, 10]) {
  for (const turnMode of [-1, 0, 1]) for (const elapsed of [0, 1, 2, 3, 4, 5, 6, 10]) {
    cases.push({ label: `boat${boat}-board${boardFlag}-speed${speed}-turn${turnMode}-elapsed${elapsed}`,
      arguments: [boat], seed: initial.expected.rngState,
      branchInputs: { boat, boardFlag, speed, turnMode, time: 100, lastTurnTime: 100 - elapsed, elapsed, humans: 1 },
      patches: [...runs, ...[
        [0x4f8cd0, 100], [0x4f42b8, -170], [0x5364e8, 1], [0x534d64, 100], [0x5363bc, boardFlag],
        [0x4da140, 1], [0x5359c8, 0x400000], [0x536484, 0], [0x4fad40 + boat * 4, 100],
        [0x4fe638 + boat * 4, 0], [0x4fe9d0 + boat * 4, 70], [0x4f4350 + boat * 4, 100 - elapsed],
        [0x4fb380 + boat * 4, speed], [0x522e68 + boat * 4, turnMode], [0x4fe6d0 + boat * 4, 0],
        [0x4f8538 + boat * 4, 0],
        [0x4f4d78 + boat * 4, Math.trunc(board.readDoubleLE(0x4f6af8 + boat * 8 - base)) + 10000],
        [0x4fc350 + boat * 4, Math.trunc(board.readDoubleLE(0x4f6c10 + boat * 8 - base)) + 10000],
      ].map(([address, value]) => integer(address, value))],
    });
  }
}
const integerOutputs = { boardFlag: 0x5363bc, closehauledAngle: 0x4f7200, humans: 0x4da140 };
for (const boat of [1, 2, 3, 12]) for (const [name, address] of Object.entries({ speed: 0x4fb380, heading: 0x535740,
  turnMode: 0x522e68, tack: 0x522ff0, lastTurnTime: 0x4f4350, windDirection: 0x522b90 })) integerOutputs[`${name}${boat}`] = address + boat * 4;
const manifest = { source: 'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe', sourceSha256,
  routine: { name: 'updateBoatWindAndAI', address: 0x434f70, argumentTypes: ['I32'], returnType: 'void' },
  integerInputs: {}, integerOutputs, doubleInputs: {}, doubleOutputs: {},
  inputEvidence: { nativeInitializedFixture: 'tests/fixtures/original-initializeRace.json', sha256: digest(initializedBytes), fixtureCase: index,
    originalInstruction: { address: 0x435e2b, bytes: '8b04b580b34f00', meaning: 'MOV EAX,[ESI*4+0x4fb380]' },
    scope: 'Original native board initialization supplies explicit starting bytes. Finite speed9/10, human/AI indices, turn mode and cooldown boundaries are explicit inputs; every new output is captured independently from original instructions. BoardFlag0 is an explicit counterfactual gate control.' }, cases };
await writeFile(new URL('analysis/board-turn-capture-inputs.json', edition), JSON.stringify(manifest, null, 2) + '\n');
console.log(`Prepared ${cases.length} independent original board-turn cases from native initialized board profile ${index}`);
