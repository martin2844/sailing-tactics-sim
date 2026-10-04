import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { assertNativeProvenance, createNativeHarness } from '../tests/native-state.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { originalUpdateUpwindTactics } from '../src/engine/ai-functions.js';

const edition = new URL('../', import.meta.url);
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const source = await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition));
const fixtureBytes = await readFile(new URL('tests/fixtures/original-upwind-stack.json', edition));
const fixture = JSON.parse(fixtureBytes);
assertNativeProvenance(source, fixture);
const trig = createCapturedTrig(JSON.parse(await readFile(new URL('assets/data/x87-trig.json', edition))));
const generatedUrl = new URL('src/engine/ai-functions.js', edition);
const current = await readFile(generatedUrl, 'utf8');
// Reconstruct only the previous conjunction in memory. No production file or
// expected fixture is altered, and all numeric helpers remain identical.
const originalGuard = '(cTruth(cCompare(0,readLocal(framePointer(localFrame,264),4,"int"),"<")) && cTruth(cCompare(iVar4,2,"==")))';
const guarded = '(cTruth(cCompare(iVar4,2,"==")) && cTruth(cCompare(0,readLocal(framePointer(localFrame,264),4,"int"),"<")))';
if (current.split(guarded).length !== 2) throw new Error('Corrected conjunction must occur exactly once');
const previous = current.replace(guarded, originalGuard);
const loadable = previous.replace(/from (['"])([^'"]+)\1/g,
  (_, quote, specifier) => 'from ' + JSON.stringify(new URL(specifier, generatedUrl).href));
const previousFunction = (await import('data:text/javascript;base64,' + Buffer.from(loadable).toString('base64'))).originalUpdateUpwindTactics;
const compare = invoke => {
  const harness = createNativeHarness(source, fixture), result = { cases: fixture.cases.length, exact: 0, undefinedStackErrors: 0, otherErrors: [] };
  for (const [index, row] of fixture.cases.entries()) {
    try {
      harness.check(row, index, (memory, rng, args) => invoke(memory, rng, { trig }, ...args));
      result.exact++;
    } catch (error) {
      if (error instanceof RangeError && error.message === 'Original C reads an undefined retained local byte') result.undefinedStackErrors++;
      else result.otherErrors.push({ index, label: row.label, message: error.message });
    }
  }
  return result;
};
const report = { format: 1, status: 'exact', sourceSha256: sha(source),
  finding: 'The original upwind helper loads an uninitialized stack cell for fleets other than two. Both outcomes then return without further stores because ESI != 2. The JavaScript byte-frame check turned this irrelevant original read into a fatal error.',
  correction: 'Evaluate the fleet == 2 integer guard first. The original stack value is read only on its initialized two-boat path. No default bytes, changed RNG, skipped initialized comparison, or demo/licensing modifications are introduced.',
  originalInstructions: [
    { address: 0x4380b6, bytes: '8b442418', operation: 'MOV EAX,[ESP+0x18]' },
    { address: 0x4380bc, bytes: '0f8e2f100000', operation: 'JLE 0x4390f1' },
    { address: 0x4380c2, bytes: '83fe02', operation: 'CMP ESI,2' },
    { address: 0x4380c5, bytes: '0f8526100000', operation: 'JNE 0x4390f1' },
    { address: 0x4380cb, bytes: '891d7c645300', operation: 'MOV [0x53647c],EBX' },
  ], beforeFix: compare(previousFunction), afterFix: compare(originalUpdateUpwindTactics),
  fixture: { path: 'tests/fixtures/original-upwind-stack.json', sha256: sha(fixtureBytes), nativeCalls: fixture.cases.length, nativeAuthority: fixture.provenance },
  sources: await Promise.all(['src/engine/ai-functions.js', 'tools/translate_ai.py', 'tools/prepare-upwind-stack-inputs.js', 'tests/upwind-stack.test.js'].map(async path => ({ path, sha256: sha(await readFile(new URL(path, edition))) }))),
  scope: '279 finite calls from unchanged native code compare all mutable image bytes and retained RNG; fleet2/3/5/10/15/20/25/30, AI levels1/10, distance100/101/500 and initialized positive/zero/negative two-boat projection controls. This proof concerns the reported dead stack read rather than arbitrary Windows stack contents.',
  expectedFilesChanged: false,
};
if (report.beforeFix.undefinedStackErrors === 0 || report.beforeFix.otherErrors.length || report.afterFix.exact !== fixture.cases.length) {
  throw new Error('Native differential proof failed: ' + JSON.stringify(report));
}
await writeFile(new URL('analysis/upwind-stack-native-comparison.json', edition), JSON.stringify(report, null, 2) + '\n');
console.log(JSON.stringify({ beforeFix: report.beforeFix, afterFix: report.afterFix }));
