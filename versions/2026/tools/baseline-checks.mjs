import {spawn, execFileSync} from 'node:child_process';
import {readFile, writeFile, mkdir, copyFile} from 'node:fs/promises';
import {createWriteStream} from 'node:fs';
import {createHash} from 'node:crypto';
import {resolve, dirname} from 'node:path';
import {fileURLToPath} from 'node:url';
import {setTimeout as pause} from 'node:timers/promises';
import {verifyReference} from './reference.mjs';

const repository = fileURLToPath(new URL('../../../', import.meta.url));
const args = process.argv.slice(2);
if (![4, 6].includes(args.length) || args[0] !== '--root' || args[2] !== '--output' || (args.length === 6 && args[4] !== '--resume')) {
  throw new Error('Usage: node versions/2026/tools/baseline-checks.mjs --root DETACHED_REFERENCE --output NEW_REPORT_DIRECTORY [--resume PREVIOUS_REPORT_DIRECTORY]');
}
const root = resolve(args[1]), output = resolve(args[3]);
if (root === resolve(repository)) throw new Error('Baseline checks require a separate reference checkout');
const manifest = JSON.parse(await readFile(new URL('../analysis/baseline/reference.json', import.meta.url), 'utf8'));
const commit = execFileSync('git', ['rev-parse', 'HEAD'], {cwd: root}).toString().trim();
if (commit !== manifest.reference.commit) throw new Error('Checkout HEAD is not the frozen reference');
const previousDirectory = args[5] ? resolve(args[5]) : null;
const previous = previousDirectory ? JSON.parse(await readFile(resolve(previousDirectory, 'report.json'), 'utf8')) : null;
if (previous && (previous.referenceCommit !== commit || previous.referenceCheckout !== root)) throw new Error('Resume reference differs');
if (previous && (previous.passed || previous.steps.some(step => step.id === 'source-browser'))) {
  throw new Error('Resume is limited to the reviewed pre-browser dependency failure; use a fresh reference checkout for later runs');
}
await mkdir(output, {recursive: false});
const collectorBytes = await readFile(fileURLToPath(import.meta.url));
await writeFile(resolve(output, 'collector-baseline-checks.mjs'), collectorBytes, {flag: 'wx'});
const referenceTool = await readFile(new URL('./reference.mjs', import.meta.url));
await writeFile(resolve(output, 'collector-reference.mjs'), referenceTool, {flag: 'wx'});
const report = {task: 'BASE-02', startedAt: new Date().toISOString(), referenceCommit: commit,
  referenceCheckout: root, node: process.version, steps: [], passed: false,
  previousRun: previousDirectory,
  collectorSha256: createHash('sha256').update(collectorBytes).digest('hex'),
  referenceToolSha256: createHash('sha256').update(referenceTool).digest('hex'),
  referenceManifestSha256: createHash('sha256').update(await readFile(new URL('../analysis/baseline/reference.json', import.meta.url))).digest('hex'),
  scope: 'Reproduction of finite existing source/native-fixture/browser/export checks; no complete-race or performance certificate.'};
const reportPath = resolve(output, 'report.json');
const save = () => writeFile(reportPath, JSON.stringify(report, null, 2) + '\n');
report.before = await verifyReference(root, manifest);
await save();
const port = process.env.TACT_BASELINE_PORT ?? '0';
if (!/^\d+$/.test(port) || (port !== '0' && Number(port) < 1024) || Number(port) > 65535) throw new Error('Invalid baseline port');
let baseUrl;
const python = process.env.TACT_PYTHON ?? resolve(repository, 'tools/python-runtime/bin/python3');
const pythonPath = [resolve(repository, 'tools/python-libs'), process.env.PYTHONPATH].filter(Boolean).join(':');
const env = {...process.env, TACT_PYTHON: python, PYTHONPATH: pythonPath,
  TACT_HOST: '127.0.0.1', TACT_PORT: port,
  TACT_HUD_REPORT: resolve(output, 'hud.json'),
  TACT_FONT_REPORT: resolve(output, 'font-atlas.json'),
  TACT_CANVAS_REPORT_DIR: resolve(output, 'canvas-parity'),
  TACT_2010_FULL_REPORT: 'base-02-full-version.json'};
let activeChild, server;

async function run(id, executable, arguments_, overrides = {}) {
  const prior = previous?.steps.find(step => step.id === id && step.passed);
  if (prior) {
    const bytes = await readFile(resolve(previousDirectory, prior.log));
    if (createHash('sha256').update(bytes).digest('hex') !== prior.logSha256) throw new Error(`Previous log differs: ${id}`);
    await writeFile(resolve(output, prior.log), bytes, {flag: 'wx'});
    report.steps.push({...prior, reusedFrom: previousDirectory}); await save();
    console.log(`REUSE PASS ${id}`); return true;
  }
  const log = `${id}.log`, logStream = createWriteStream(resolve(output, log), {flags: 'wx'});
  const step = {id, executable, arguments: arguments_, startedAt: new Date().toISOString(), log};
  report.steps.push(step); await save(); console.log(`START ${id}`);
  const code = await new Promise(resolveExit => {
    activeChild = spawn(executable, arguments_, {cwd: root, env: {...env, ...overrides}, stdio: ['ignore', 'pipe', 'pipe']});
    activeChild.stdout.pipe(logStream, {end: false}); activeChild.stderr.pipe(logStream, {end: false});
    let settled = false;
    const finish = (exitCode, signal, error) => {
      if (settled) return; settled = true; clearTimeout(timeout);
      step.signal = signal; if (error) step.error = String(error);
      logStream.end(() => resolveExit(exitCode ?? 1));
    };
    const timeout = setTimeout(() => {step.timedOut = true; activeChild.kill('SIGKILL');}, 30 * 60 * 1000);
    activeChild.once('error', error => finish(1, null, error));
    activeChild.once('close', (exitCode, signal) => finish(exitCode, signal));
  });
  activeChild = null; step.exitCode = code; step.finishedAt = new Date().toISOString(); step.passed = code === 0;
  const bytes = await readFile(resolve(output, log));
  step.logSha256 = createHash('sha256').update(bytes).digest('hex');
  const summary = bytes.toString().match(/(?:#|ℹ) (?:tests|pass|fail|skipped) \d+/g);
  if (summary) step.testSummary = summary;
  await save(); console.log(`${step.passed ? 'PASS' : 'FAIL'} ${id}`);
  return step.passed;
}

async function startServer() {
  // A fresh owned server is required; never silently test a pre-existing page.
  const log = createWriteStream(resolve(output, 'server.log'), {flags: 'wx'});
  server = spawn(process.execPath, ['tools/serve.js'], {cwd: root, env, stdio: ['ignore', 'pipe', 'pipe']});
  server.stdout.pipe(log); server.stderr.pipe(log, {end: false});
  let launchError, serverOutput = ''; server.on('error', error => {launchError = error;});
  server.stdout.on('data', bytes => {
    serverOutput += bytes.toString();
    const address = serverOutput.match(/http:\/\/127\.0\.0\.1:(\d+)/);
    if (address) baseUrl = address[0];
  });
  for (let attempt = 0; attempt < 100; attempt++) {
    if (launchError) throw launchError;
    if (server.exitCode !== null) throw new Error('Owned baseline server exited before readiness');
    try {
      if (baseUrl && (await fetch(`${baseUrl}/versions/2010-en/play.html`, {signal: AbortSignal.timeout(500)})).ok) {
        env.TACT_URL = baseUrl; env.TACT_2010_URL = `${baseUrl}/versions/2010-en/play.html`;
        report.server = {processId: server.pid, baseUrl, portAssignment: port === '0' ? 'owned ephemeral listener' : 'explicit'};
        return;
      }
    } catch {}
    await pause(100);
  }
  throw new Error('Owned baseline server did not become ready');
}

try {
  const dependencyCode = 'import hashlib,json,pycparser,pefile; from pathlib import Path; assert pycparser.__version__=="2.23"; print(json.dumps({"pycparser":pycparser.__version__,"pycparserModule":pycparser.__file__,"pycparserSha256":hashlib.sha256(Path(pycparser.__file__).read_bytes()).hexdigest(),"pefile":pefile.__version__,"pefileModule":pefile.__file__}))';
  if (!await run('python-dependencies', python, ['-c', dependencyCode])) throw new Error('Python dependency preflight failed');
  await run('restore-shared-evidence', process.execPath, ['tools/restore-evidence.js']);
  await run('restore-2010-evidence', process.execPath, ['tools/restore-2010-evidence.js']);
  const failedSuite = previous?.steps.find(step => step.id === '2010-tests' && !step.passed);
  if (failedSuite) {
    const previousLog = await readFile(resolve(previousDirectory, failedSuite.log), 'utf8');
    if (createHash('sha256').update(previousLog).digest('hex') !== failedSuite.logSha256) throw new Error('Previous failed-suite log differs');
    const files = [...new Set([...previousLog.matchAll(/^test at (versions\/2010-en\/tests\/[a-z0-9-]+\.test\.js):/gm)].map(match => match[1]))].sort();
    if (!previousLog.includes("ModuleNotFoundError: No module named 'pycparser'") || files.length !== 5) throw new Error('Resume requires the reviewed five-file dependency failure');
    report.testRemediation = {originalRun: previousDirectory, originalLog: failedSuite.log, files,
      scope: 'Original passing cases remain evidence in the first run; rerun all five affected test files after restoring the documented Python dependency. This is not a new all-suite run.'};
    await run('2010-tests-remediation', process.execPath, ['--test', '--test-concurrency=1', ...files]);
  } else await run('2010-tests', 'npm', ['run', 'test:2010']);
  await run('evaluation-tests', process.execPath, ['--test', 'tests/evaluation-baseline.test.js', 'tests/evaluation-metrics.test.js', 'tests/evaluation-reanalysis.test.js', 'tests/presentation-measurements.test.js', 'tests/browser-session.test.js', 'tests/evaluation-window-visibility.test.js']);
  await run('assets', python, ['versions/2010-en/tools/test_assets.py']);
  await run('decompilation', python, ['versions/2010-en/tools/verify_decompilation.py']);
  await startServer();
  await run('source-browser', process.execPath, ['tools/check-2010-browser.js']);
  await copyFile(resolve(root, 'versions/2010-en/analysis/browser-verification.json'), resolve(output, 'source-browser.json'));
  await run('source-hud', process.execPath, ['tools/check-2010-hud-browser.js']);
  await run('source-full-version', process.execPath, ['tools/check-2010-full-version.js']);
  await run('canvas-parity', process.execPath, ['versions/2010-en/tools/diagnostics/check-smooth-graphics-browser.mjs']);
  await run('font-atlas', process.execPath, ['tools/evaluation/check-font-atlas.js']);
  await run('build', process.execPath, ['tools/build-2010-browser.js']);
  const standalone = {TACT_2010_URL: `${baseUrl}/dist-2010/versions/2010-en/play.html`, TACT_2010_FULL_REPORT: 'base-02-standalone-full-version.json'};
  await run('standalone-browser', process.execPath, ['tools/check-2010-browser.js'], standalone);
  // The existing checker names nested /play.html reports as source reports.
  // Preserve it immediately; do not infer artifact identity from its filename.
  await copyFile(resolve(root, 'versions/2010-en/analysis/browser-verification.json'), resolve(output, 'standalone-browser.json'));
  await run('standalone-full-version', process.execPath, ['tools/check-2010-full-version.js'], standalone);
  const archiveCheck = `import hashlib,json,pathlib,zipfile
r=pathlib.Path('.')
m=json.loads((r/'dist-2010/port-manifest.json').read_text())
for f in m['files']:
 b=(r/'dist-2010'/f['path']).read_bytes()
 assert len(b)==f['bytes'] and hashlib.sha256(b).hexdigest()==f['sha256'],f['path']
expected={str(p.relative_to(r/'dist-2010')):p for p in (r/'dist-2010').rglob('*') if p.is_file()}
with zipfile.ZipFile(r/'posey-2010-browser.zip') as z:
 assert len(z.namelist())==len(set(z.namelist()))
 assert set(z.namelist())==set(expected)
 for name,p in expected.items(): assert z.read(name)==p.read_bytes(),name
print(json.dumps({'manifestFiles':len(m['files']),'zipEntries':len(expected),'allBytesEqual':True}))`;
  await run('export-and-zip', python, ['-c', archiveCheck]);
  for (const name of ['base-02-full-version.json', 'base-02-standalone-full-version.json', 'decompilation-export-verification.json']) {
    await copyFile(resolve(root, 'versions/2010-en/analysis', name), resolve(output, name));
  }
  const generatedReports = new Set(['versions/2010-en/analysis/browser-verification.json']);
  report.after = await verifyReference(root, {...manifest, files: manifest.files.filter(row => !generatedReports.has(row.path))});
  report.after.excludedGeneratedReports = [...generatedReports];
  report.preservationWorkspace = await verifyReference(repository, manifest);
  report.passed = report.steps.every(step => step.passed);
} catch (error) {
  report.failure = error.stack ?? String(error);
} finally {
  activeChild?.kill('SIGKILL');
  if (server) {
    server.kill();
    await Promise.race([new Promise(done => server.once('exit', done)), pause(3000)]);
    if (server.exitCode === null) server.kill('SIGKILL');
  }
  report.finishedAt = new Date().toISOString(); await save();
}
console.log(JSON.stringify({passed: report.passed, report: reportPath, failure: report.failure}, null, 2));
if (!report.passed) process.exitCode = 1;
