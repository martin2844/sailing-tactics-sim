import { readFile, readdir, writeFile } from 'node:fs/promises';
import { createReadStream } from 'node:fs';
import { createHash } from 'node:crypto';

// Extend the published capture inventory without silently changing older proof.
// Reports are links to a proved source snapshot, never additional captures.
const edition = new URL('../', import.meta.url);
const indexPath = new URL('analysis/native-reference-index.json', edition);
const oldBytes = await readFile(indexPath), index = JSON.parse(oldBytes);
const hash = value => createHash('sha256').update(value).digest('hex');
async function hashFile(path) {
  const digest = createHash('sha256');
  for await (const chunk of createReadStream(new URL(path, edition))) digest.update(chunk);
  return digest.digest('hex');
}
const old = new Map(index.fixtures.map(entry => [entry.fixture, entry]));
const derived = [];
const names = (await readdir(new URL('tests/fixtures/', edition))).filter(name => name.endsWith('.json')).sort();
for (const name of names) {
  const path = `tests/fixtures/${name}`, digest = await hashFile(path);
  if (old.has(path)) {
    if (old.get(path).sha256 !== digest) throw new Error(`Published native fixture changed: ${path}`);
    continue;
  }
  const bytes = await readFile(new URL(path, edition)), fixture = JSON.parse(bytes);
  if (!fixture.cases) {
    if (!fixture.sourceFixture || !fixture.sourceFixtureSha256) throw new Error(`Unclassified evidence: ${path}`);
    const sourcePath = fixture.sourceFixture.replace(/^versions\/2010-en\//, '');
    if (await hashFile(sourcePath) !== fixture.sourceFixtureSha256) throw new Error(`Derived evidence source changed: ${path}`);
    derived.push({ fixture: path, sha256: digest, bytes: bytes.length,
      sourceFixture: sourcePath, sourceFixtureSha256: fixture.sourceFixtureSha256,
      countingScope: 'Derived observations from the named capture; no additional original calls.' });
    continue;
  }
  if (fixture.sourceSha256 !== index.sourceSha256 || fixture.provenance?.sha256 !== index.sourceSha256
      || fixture.provenance.loadedOriginalTextUnchanged !== true || fixture.provenance.originalFileUnchanged !== true)
    throw new Error(`Native capture integrity is not explicit: ${path}`);
  const counts = new Map();
  for (const row of fixture.cases) {
    const routine = row.routine ?? fixture.routine;
    const address = typeof routine?.address === 'string' ? Number(routine.address) : routine?.address;
    if (!Number.isInteger(address)) throw new Error(`Untyped original entrypoint: ${path}`);
    counts.set(address, (counts.get(address) ?? 0) + 1);
  }
  index.fixtures.push({ fixture: path, sha256: digest, bytes: bytes.length,
    capturedRows: fixture.cases.length, continuationRows: fixture.cases.filter(row => row.continue).length,
    routine: fixture.routine, mutableBlock: fixture.mutableBlock, provenance: fixture.provenance,
    orderedDrawingRequests: fixture.cases.reduce((sum, row) => sum + (row.expected?.drawingCommands?.length ?? 0), 0),
    orderedSoundRequests: fixture.cases.reduce((sum, row) => sum + (row.expected?.sounds?.length ?? 0), 0),
    sourceSha256: fixture.sourceSha256, category: 'fixed original routine calls',
    originalRoutineCalls: fixture.cases.length,
    routines: [...counts].sort((a, b) => a[0] - b[0]).map(([address, calls]) => ({ address, addressHex: `0x${address.toString(16).padStart(8, '0')}`, calls })),
    captureIntegrityVerified: true, matchingReports: [], sourceParityReportAvailable: false });
}

const reportPaths = [
  'analysis/initialized-screens-native-comparison.json',
  'analysis/initialized-island-chart-native-comparison.json',
  'analysis/initialized-venue-render-native-comparison.json',
  'analysis/island-shore-context-native-comparison.json',
  'analysis/retained-controllers-native-source-comparison.json',
  'analysis/scaled-random-native-comparison.json',
  'analysis/fresh-staged-focused-validation.json',
  'analysis/board-turn-native-source-comparison.json',
];
for (const path of reportPaths) {
  let bytes, report;
  try { bytes = await readFile(new URL(path, edition)); report = JSON.parse(bytes); }
  catch (error) { if (error.code === 'ENOENT') continue; throw error; }
  // The board review preserves its deliberately failing pre-fix replay too.
  // Only its three named post-fix replays establish the current source proof.
  const boardReplays = path === 'analysis/board-turn-native-source-comparison.json'
    ? ['board-turn-replay.log', 'retained-board-frames-replay.log', 'ai-board-fix-regression.log']
      .map(name => report.replays?.[name]) : undefined;
  const tests = report.tests ?? (boardReplays?.every(row => row && row.failed === 0 && row.passed === row.tests)
    ? { passed: boardReplays.reduce((sum, row) => sum + row.passed, 0), failed: 0 } : undefined);
  if (!(report.exact === true || (report.status === 'exact' && tests?.failed === 0)) || !tests) continue;
  const references = [...(report.fixtures ?? []), ...(report.fixture ? [report.fixture] : [])];
  for (const entry of index.fixtures) {
    if (!references.some(reference => (typeof reference === 'string' ? reference : reference.fixture ?? reference.path)?.replace(/^versions\/2010-en\//, '') === entry.fixture
        && (typeof reference === 'string' || (reference.sha256 ?? reference.fixtureSha256) === entry.sha256))) continue;
    entry.matchingReports = entry.matchingReports.filter(link => link.path !== path);
    entry.matchingReports.push({ path, sha256: hash(bytes), explicitSourceParityPassed: true });
    entry.sourceParityReportAvailable = true;
  }
}
// Confirm that previously published report links still point to their own bytes.
for (const entry of index.fixtures) for (const link of entry.matchingReports) {
  link.reportHashStillMatches = await hashFile(link.path) === link.sha256;
}

index.fixtures.sort((a, b) => a.fixture.localeCompare(b.fixture));
const unique = new Map();
for (const entry of index.fixtures) {
  if (unique.has(entry.sha256)) entry.aliasOf = unique.get(entry.sha256).fixture;
  else unique.set(entry.sha256, entry);
}
const entries = [...unique.values()], sum = key => entries.reduce((value, entry) => value + (entry[key] ?? 0), 0);
const routines = new Map();
for (const entry of entries) for (const routine of entry.routines)
  routines.set(routine.address, (routines.get(routine.address) ?? 0) + routine.calls);
const priorTotals = index.totals;
index.previousSnapshot ??= { indexSha256: hash(oldBytes), totals: priorTotals,
  scope: 'Earlier captured evidence snapshot, preserved separately from this extended inventory.' };
index.totals = {
  fixtureFiles: index.fixtures.length, uniqueFixtureHashes: unique.size,
  capturedRows: sum('capturedRows'), originalRoutineCalls: sum('originalRoutineCalls'),
  captureIntegrityVerifiedRoutineCalls: entries.filter(entry => entry.captureIntegrityVerified).reduce((total, entry) => total + entry.originalRoutineCalls, 0),
  continuationRows: sum('continuationRows'), distinctExplicitRoutineAddresses: routines.size,
  orderedDrawingRequests: sum('orderedDrawingRequests'), orderedSoundRequests: sum('orderedSoundRequests'),
  sourceParityReportLinkedRoutineCalls: entries.filter(entry => entry.matchingReports.some(link => link.explicitSourceParityPassed && link.reportHashStillMatches)).reduce((total, entry) => total + entry.originalRoutineCalls, 0),
};
index.routines = [...routines].sort((a, b) => a[0] - b[0]).map(([address, calls]) => ({ address, addressHex: `0x${address.toString(16).padStart(8, '0')}`, calls }));
index.derivedEvidence = derived;
index.generatedFrom = 'Published native fixture bytes checked against earlier immutable hashes, mixed per-case entrypoints, and exact report-hash links; reports and derived projections are never added to capture totals.';
index.replayStatusPolicy = 'Linked successful reports document their source snapshot. The final source suite determines current JavaScript parity; native integrity alone is not a replay pass.';
await writeFile(indexPath, JSON.stringify(index, null, 2) + '\n');
console.log(JSON.stringify(index.totals, null, 2));
