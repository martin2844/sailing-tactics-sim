import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';

const target = new URL('../../src/engine/ai-functions.js', import.meta.url).href;
const before = new URL('../../analysis/source-review-history/ai-functions-pre-board-fix.js', import.meta.url);
export async function load(url, context, nextLoad) {
  if (url !== target) return nextLoad(url, context);
  const source = await readFile(before);
  if (createHash('sha256').update(source).digest('hex') !== 'a8270c25cb6bdcca931e487c722dc166b150893c186c3d1a09f3e2f893e53618') {
    throw new Error('Preserved pre-fix AI source differs');
  }
  return { format: 'module', source: source.toString('utf8'), shortCircuit: true };
}
