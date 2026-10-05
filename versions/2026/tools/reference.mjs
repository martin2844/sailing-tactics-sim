import {readFile, writeFile, mkdir, lstat} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {execFileSync} from 'node:child_process';
import {dirname, resolve, relative, sep} from 'node:path';
import {fileURLToPath} from 'node:url';

const repository = fileURLToPath(new URL('../../../', import.meta.url));
const manifestPath = fileURLToPath(new URL('../analysis/baseline/reference.json', import.meta.url));
const reference = '64d5cdf';
const executable = 'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe';
const executableHash = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
const confirmation = 'versions/2010-en/analysis/evaluation/2026-10-05T07-51-35-087Z-83bc7ef0/';
const historical = new Set([
  'versions/2010-en/README.md',
  'versions/2010-en/analysis/native-reference-index.json',
  'versions/2010-en/analysis/full-version-audit.json',
  'versions/2010-en/analysis/full-version-browser-check.json',
  'versions/2010-en/analysis/browser-verification.json',
  'versions/2010-en/analysis/standalone-browser-verification.json',
  'versions/2010-en/analysis/hud-controls-verification.json',
  'versions/2010-en/analysis/publication-verification.json',
  'versions/2010-en/analysis/evaluation/CANVAS-FIX.md',
  'evidence/manifest.json', 'package.json', 'posey-2010-browser.zip',
  'THIRD-PARTY-NOTICES.md',
]);

function category(path) {
  if (path.startsWith('versions/2010-en/src/')) return '2010-source';
  if (path.startsWith('versions/2010-en/assets/')) return '2010-assets';
  if (path.startsWith('versions/2010-en/runtime/')) return 'native-runtime-provenance';
  if (path.startsWith('versions/2010-en/decompiled/')) return 'recovered-source';
  if (path.startsWith('versions/2010-en/evidence/')) return 'native-evidence';
  if (path.startsWith('versions/2010-en/tests/') || path.startsWith('versions/2010-en/tools/')) return '2010-verification';
  if (path.startsWith('src/')) return 'shared-source';
  if (path.startsWith('assets/') || path.startsWith('LICENSES/')) return 'shared-assets';
  if (path.startsWith('tools/') || path.startsWith('tests/evaluation-')) return 'shared-verification';
  if (path.startsWith('dist-2010/')) return 'standalone-export';
  if (path.startsWith(confirmation)) return 'latest-confirmation';
  if (historical.has(path) || path === 'versions/2010-en/play.html') return 'reference-metadata';
  return null;
}

const sha256 = bytes => createHash('sha256').update(bytes).digest('hex');
const git = (root, ...args) => execFileSync('git', args, {cwd: root, maxBuffer: 32 * 1024 * 1024}).toString();

async function regularFile(root, path) {
  const location = resolve(root, path);
  if (!path || path.includes('\\') || relative(root, location) !== path || !location.startsWith(root + sep)) {
    throw new Error(`Invalid reference path: ${path}`);
  }
  if (!(await lstat(location)).isFile()) throw new Error(`Reference input is not a regular file: ${path}`);
  return readFile(location);
}

export async function verifyReference(root, manifest) {
  root = resolve(root);
  if (manifest.format !== 1 || !Array.isArray(manifest.files) || !manifest.files.length) throw new Error('Invalid reference manifest');
  const paths = new Set();
  const groups = {};
  for (const row of manifest.files) {
    if (paths.has(row.path)) throw new Error(`Duplicate reference path: ${row.path}`);
    paths.add(row.path);
    const bytes = await regularFile(root, row.path);
    if (bytes.length !== row.bytes || sha256(bytes) !== row.sha256) throw new Error(`Reference differs: ${row.path}`);
    groups[row.category] = (groups[row.category] ?? 0) + 1;
  }
  const original = manifest.files.find(row => row.path === executable);
  if (!original || original.sha256 !== executableHash) throw new Error('Missing exact preserved executable identity');
  return {passed: true, referenceCommit: manifest.reference.commit, files: paths.size, groups};
}

async function freeze(root) {
  if (git(root, 'rev-parse', '--show-object-format').trim() !== 'sha1') throw new Error('Unexpected Git object format');
  const commit = git(root, 'rev-parse', `${reference}^{commit}`).trim();
  const tree = git(root, 'rev-parse', `${commit}^{tree}`).trim();
  const entries = git(root, 'ls-tree', '-r', '-z', commit).split('\0').filter(Boolean);
  const files = [];
  for (const entry of entries) {
    const [metadata, path] = entry.split('\t');
    const group = category(path);
    if (!group) continue;
    const [mode, type, blob] = metadata.split(' ');
    if (type !== 'blob' || !['100644', '100755'].includes(mode)) throw new Error(`Unsupported reference input: ${path}`);
    const bytes = await regularFile(root, path);
    const currentBlob = createHash('sha1').update(`blob ${bytes.length}\0`).update(bytes).digest('hex');
    if (currentBlob !== blob) throw new Error(`Working input differs from frozen commit: ${path}`);
    files.push({path, category: group, bytes: bytes.length, sha256: sha256(bytes), gitBlob: blob});
  }
  files.sort((a, b) => a.path < b.path ? -1 : a.path > b.path ? 1 : 0);
  const manifest = {
    format: 1,
    created: '2026-10-05',
    reference: {commit, tree, executable, executableSha256: executableHash},
    scope: 'Exact Git-tracked 2010 source/assets/runtime/recovered code/native archives, shared source/assets and verification tools, standalone export, historical metadata and final Canvas confirmation. Shared trees are deliberately broader than the 2010 import graph. Expanded evidence is identified by its pinned archive manifest, not duplicated here. Untracked experiments and other editions are excluded.',
    latestEvaluation: {directory: confirmation, scope: 'Finite Canvas, HUD, font, engine-trace, throughput and input evidence; not a complete-race certificate.'},
    files,
  };
  const report = await verifyReference(root, manifest);
  await mkdir(dirname(manifestPath), {recursive: true});
  await writeFile(manifestPath, JSON.stringify(manifest, null, 2) + '\n', {flag: 'wx'});
  return report;
}

if (process.argv[1] && resolve(process.argv[1]) === fileURLToPath(import.meta.url)) {
  const [action, ...args] = process.argv.slice(2);
  if (!['freeze', 'verify'].includes(action) || (args.length && (args.length !== 2 || args[0] !== '--root'))) {
    throw new Error('Usage: node versions/2026/tools/reference.mjs freeze|verify [--root REPOSITORY]');
  }
  const root = resolve(args[1] ?? repository);
  const report = action === 'freeze' ? await freeze(root) : await verifyReference(root, JSON.parse(await readFile(manifestPath, 'utf8')));
  console.log(JSON.stringify(report, null, 2));
}
