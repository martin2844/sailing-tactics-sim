import assert from 'node:assert/strict';
import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { execFileSync } from 'node:child_process';

const root = new URL('../../../../', import.meta.url);
const path = 'versions/2010-en/src/render/typed-c.js';
const location = new URL(path, root);
const current = await import(location);
const source = await readFile(location, 'utf8');
const previous = execFileSync('git', ['show', `15fd6ac:${path}`], { cwd: root, encoding: 'utf8' });
const original = await import('data:text/javascript;base64,' + Buffer.from(previous.replace(
  /from (['"])([^'"]+)\1/g,
  (_match, _quote, relative) => 'from ' + JSON.stringify(new URL(relative, location).href),
)).toString('base64'));

const cases = [
  ['cI32', [-0]], ['cI32', [0xffffffff]], ['cI32', [-1, true]],
  ['cI32', [NaN]], ['cI32', [.5]], ['cI32', [undefined]],
  ['cAdd', [3, 4]], ['cAdd', [NaN, 1]], ['cAdd', [NaN, undefined]],
  ['cAdd', [0x7fffffff, 1]], ['cSub', [3, 4]], ['cSub', [NaN, 1]],
  ['cSub', [1, undefined]], ['cSub', [-0x80000000, 1]],
  ['cMul', [3, 4]], ['cMul', [NaN, 1]],
  ['cTruth', [NaN]], ['cTruth', [-0]], ['cTruth', [undefined]],
];
const patterns = [[false], [true], [false, true], [true, false, true], [true, true, false]];
const descriptor = Object.getOwnPropertyDescriptor(Number.prototype, 'events');
let checks = 0;

function outcome(module, name, args, pattern, throwAt) {
  const events = [];
  Object.defineProperty(Number.prototype, 'events', {
    configurable: true,
    get() {
      events.push(Number(this));
      if (events.length === throwAt) throw new Error('events getter failed');
      return pattern[(events.length - 1) % pattern.length];
    },
  });
  let result;
  try { result = { value: module[name](...args) }; }
  catch (error) { result = { name: error.name, message: error.message }; }
  return { result, events };
}

try {
  for (const [name, args] of cases) for (const pattern of patterns) for (const throwAt of [0, 1, 2, 3]) {
    assert.deepEqual(outcome(current, name, args, pattern, throwAt),
      outcome(original, name, args, pattern, throwAt), `${name}/${args}/${pattern}/${throwAt}`);
    checks++;
  }
} finally {
  if (descriptor) Object.defineProperty(Number.prototype, 'events', descriptor);
  else delete Number.prototype.events;
}

const report = {
  checkedAt: new Date().toISOString(),
  source: { path, sha256: createHash('sha256').update(source).digest('hex') },
  reference: '15fd6ac primitive integer dispatch',
  checks,
  result: 'PASS: outputs, exceptions and inherited events getter access order match the original dispatch',
};
await writeFile(new URL('../../analysis/browser-performance/integer-dispatch-review.json', import.meta.url),
  JSON.stringify(report, null, 2) + '\n');
console.log(JSON.stringify(report));
