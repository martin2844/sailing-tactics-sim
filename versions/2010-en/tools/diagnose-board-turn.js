import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { createNativeHarness } from '../tests/native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { updateBoatWindAndAI } from '../src/engine/ai.js';
import { originalUpdateBoatWindAndAI } from '../src/engine/ai-functions.js';

const edition = new URL('../', import.meta.url);
const json = async path => JSON.parse(await readFile(new URL(path, edition), 'utf8'));
const digest = bytes => createHash('sha256').update(bytes).digest('hex');
const before = process.argv.includes('--before');
const testedSource = before ? 'analysis/source-review-history/ai-functions-pre-board-fix.js' : 'src/engine/ai-functions.js';
const testedBytes = await readFile(new URL(testedSource, edition));
const speedRead = testedBytes.toString('utf8').split('\n').find(line => line.includes('case 30:') && line.includes('0x4fb380'));
if (!speedRead || !originalUpdateBoatWindAndAI.toString().includes(speedRead.trim())) throw new Error('Loaded AI module does not match the declared before/after source; use the preserved loader for --before');
const source = await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition));
const fixtureBytes = await readFile(new URL('tests/fixtures/original-board-turn.json', edition));
const fixture = JSON.parse(fixtureBytes);
const trig = createCapturedTrig(await json('assets/data/x87-trig.json'));
const harness = createNativeHarness(source, fixture);
const mismatches = [];
for (const [index, row] of fixture.cases.entries()) {
  const sounds = [];
  let failure;
  try {
    harness.check(row, index, (memory, rng, args) => updateBoatWindAndAI(memory, ...args, rng,
      { trig, rng, playSound: event => { sounds.push(event); return 1; } }));
  } catch (error) { failure = error.message; }
  if (failure || JSON.stringify(sounds) !== JSON.stringify(row.expected.sounds)) {
    const boat = row.branchInputs.boat;
    mismatches.push({ case: index, label: row.label, branchInputs: row.branchInputs,
      expectedHeading: row.expected.integers[`heading${boat}`], actualHeading: harness.memory.readI32(0x535740 + boat * 4),
      expectedTurnMode: row.expected.integers[`turnMode${boat}`], actualTurnMode: harness.memory.readI32(0x522e68 + boat * 4),
      expectedRng: row.expected.rngState, actualRng: harness.rng.state, failure });
  }
}
const report = { sourceSha256: digest(source), fixture: 'tests/fixtures/original-board-turn.json', fixtureSha256: digest(fixtureBytes),
  testedSource, testedSourceSha256: digest(testedBytes), beforeFix: before,
  cases: fixture.cases.length, exact: fixture.cases.length - mismatches.length, mismatches };
await writeFile(new URL(`analysis/board-turn-${before ? 'before' : 'after'}-fix-comparison.json`, edition), JSON.stringify(report, null, 2) + '\n');
console.log(`${before ? 'Before' : 'After'} fix: ${report.exact}/${report.cases} exact; ${mismatches.length} independently captured original-code mismatches`);
if (before ? !mismatches.length : mismatches.length) process.exitCode = 1;
