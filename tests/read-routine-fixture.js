import { createReadStream } from 'node:fs';
import { createInterface } from 'node:readline';

/** Read checked-in, indented capture groups without exceeding V8's string limit.
 * Parsing and comparing each real group retains the canonical fixture bytes;
 * the loader never rewrites or substitutes recorded outputs. */
export async function readRoutineFixture(path, wantedNames) {
  const wanted = new Set(wantedNames), fixture = { routines: {} }, header = [];
  const stream = createReadStream(path, { encoding: 'utf8', highWaterMark: 1024 * 1024 });
  const lines = createInterface({ input: stream, crlfDelay: Infinity });
  let inRoutines = false, groupName, groupLines;
  try {
    for await (const line of lines) {
      if (!inRoutines) {
        if (line === '  "routines": {') {
          Object.assign(fixture, JSON.parse(header.join('\n').replace(/,\s*$/, '') + '\n}'));
          fixture.routines = {}; inRoutines = true;
        } else header.push(line);
        continue;
      }
      if (!groupName) {
        const match = /^    "([^"]+)": \{$/.exec(line);
        if (match) { groupName = match[1]; groupLines = wanted.has(groupName) ? [line] : undefined; }
        continue;
      }
      if (groupLines) groupLines.push(line);
      if (/^    },?$/.test(line)) {
        if (groupLines) {
          const text = groupLines.join('\n').replace(/,\s*$/, '');
          fixture.routines[groupName] = JSON.parse('{' + text + '}')[groupName];
          wanted.delete(groupName);
        }
        groupName = undefined; groupLines = undefined;
        if (!wanted.size) break;
      }
    }
  } finally { lines.close(); stream.destroy(); }
  if (!inRoutines || wanted.size) throw new Error(`Missing original fixture groups: ${[...wanted].join(', ')}`);
  return fixture;
}
