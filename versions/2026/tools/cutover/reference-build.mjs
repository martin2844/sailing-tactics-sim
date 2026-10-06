import {execFile} from 'node:child_process';
import {promisify} from 'node:util';
import {mkdtemp, rm, symlink} from 'node:fs/promises';
import {tmpdir} from 'node:os';
import {join} from 'node:path';
import {fileURLToPath} from 'node:url';

const execute = promisify(execFile);
const repository = fileURLToPath(new URL('../../../../', import.meta.url));

/** Builds the declared commit outside the shared working tree and cleans up
 * only the temporary checkout created here. Never accepts the current HEAD as
 * a substitute for a missing or changed reference.
 */
export async function withReferenceBuild(commit, callback) {
  if (!/^[0-9a-f]{7,40}$/.test(commit)) throw new Error('Invalid cutover reference commit');
  const revision = (await execute('git', ['rev-parse', '--verify', commit + '^{commit}'], {cwd: repository})).stdout.trim();
  const directory = await mkdtemp(join(tmpdir(), 'tact-cutover-reference-'));
  const checkout = join(directory, 'checkout');
  let registered = false;
  try {
    await execute('git', ['worktree', 'add', '--detach', checkout, revision], {cwd: repository, maxBuffer: 1024 * 1024});
    registered = true;
    const app = join(checkout, 'versions/2026');
    await symlink(join(repository, 'versions/2026/node_modules'), join(app, 'node_modules'), 'dir');
    await execute('npm', ['run', 'build'], {cwd: app, timeout: 120000, maxBuffer: 2 * 1024 * 1024});
    return await callback({revision, dist: join(app, 'dist')});
  } finally {
    if (registered) await execute('git', ['worktree', 'remove', '--force', checkout], {cwd: repository});
    await rm(directory, {recursive: true, force: true});
  }
}
