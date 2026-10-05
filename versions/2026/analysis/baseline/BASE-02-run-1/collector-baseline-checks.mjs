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
if (args.length !== 4 || args[0] !== '--root' || args[2] !== '--output') {
  throw new Error('Usage: node versions/2026/tools/baseline-checks.mjs --root DETACHED_REFERENCE --output NEW_REPORT_DIRECTORY');
}
const root = resolve(args[1]), output = resolve(args[3]);
if (root === resolve(repository)) throw new Error('Baseline checks require a separate reference checkout');
const manifest = JSON.parse(await readFile(new URL('../analysis/baseline/reference.json', import.meta.url), 'utf8'));
const commit = execFileSync('git', ['rev-parse', 'HEAD'], {cwd: root}).toString().trim();
if (commit !== manifest.reference.commit) throw new Error('Checkout HEAD is not the frozen reference');
await mkdir(output, {recursive: false});
const report = {task: 'BASE-02', startedAt: new Date().toISOString(), referenceCommit: commit,
  referenceCheckout: root, node: process.version, steps: [], passed: false,
  scope: 'Reproduction of finite existing source/native-fixture/browser/export checks; no complete-race or performance certificate.'};
const reportPath = resolve(output, 'report.json');
const save = () => writeFile(reportPath, JSON.stringify(report, null, 2) + '\n');
report.before = await verifyReference(root, manifest);
await save();
const port = process.env.TACT_BASELINE_PORT ?? '8766';
if (!/^\d+$/.test(port) || Number(port) < 1024 || Number(port) > 65535) throw new Error('Invalid baseline port');
const baseUrl = `http://127.0.0.1:${port}`;
const python = process.env.TACT_PYTHON ?? resolve(repository, 'tools/python-runtime/bin/python3');
const env = {...process.env, TACT_PYTHON: python, TACT_URL: baseUrl,
  TACT_2010_URL: `${baseUrl}/versions/2010-en/play.html`,
  TACT_HOST: '127.0.0.1', TACT_PORT: port,
  TACT_HUD_REPORT: resolve(output, 'hud.json'),
  TACT_FONT_REPORT: resolve(output, 'font-atlas.json'),
  TACT_CANVAS_REPORT_DIR: resolve(output, 'canvas-parity'),
  TACT_2010_FULL_REPORT: 'base-02-full-version.json'};
let activeChild, server;

async function run(id, executable, arguments_, overrides = {}) {
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
  const summary = bytes.toString().match(/# (?:tests|pass|fail|skipped) \d+/g);
  if (summary) step.testSummary = summary;
  await save(); console.log(`${step.passed ? 'PASS' : 'FAIL'} ${id}`);
  return step.passed;
}

async function startServer() {
  // A fresh owned server is required; never silently test a pre-existing page.
  try { await fetch(`${baseUrl}/`, {signal: AbortSignal.timeout(500)}); throw new Error('Baseline port already serves another process'); }
  catch (error) { if (error.message === 'Baseline port already serves another process') throw error; }
  const log = createWriteStream(resolve(output, 'server.log'), {flags: 'wx'});
  server = spawn(process.execPath, ['tools/serve.js'], {cwd: root, env, stdio: ['ignore', 'pipe', 'pipe']});
  server.stdout.pipe(log); server.stderr.pipe(log, {end: false});
  let launchError; server.on('error', error => {launchError = error;});
  for (let attempt = 0; attempt < 100; attempt++) {
    if (launchError) throw launchError;
    if (server.exitCode !== null) throw new Error('Owned baseline server exited before readiness');
    try { if ((await fetch(`${baseUrl}/versions/2010-en/play.html`, {signal: AbortSignal.timeout(500)})).ok) return; } catch {}
    await pause(100);
  }
  throw new Error('Owned baseline server did not become ready');
}

try {
  await run('restore-shared-evidence', process.execPath, ['tools/restore-evidence.js']);
  await run('restore-2010-evidence', process.execPath, ['tools/restore-2010-evidence.js']);
  await run('2010-tests', 'npm', ['run', 'test:2010']);
  await run('evaluation-tests', process.execPath, ['--test', 'tests/evaluation-baseline.test.js', 'tests/evaluation-metrics.test.js', 'tests/evaluation-reanalysis.test.js', 'tests/evaluation-window-visibility.test.js']);
  await run('assets', python, ['versions/2010-en/tools/test_assets.py']);
  await run('decompilation', python, ['versions/2010-en/tools/verify_decompilation.py']);
  await startServer();
  await run('source-browser', process.execPath, ['tools/check-2010-browser.js']);
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
