// Read-only diagnostic import; never loaded by the browser production graph.
import { Float80 } from '../../../../src/runtime/float80.js';
import { writeFileSync } from 'node:fs';
const original = Float80.fromNumber;
const cache = new Map(), negativeZero = Symbol('IEEE negative zero');
const limit = 4096;
let hits = 0, misses = 0, evictions = 0;
Float80.fromNumber = function (value) {
  const key = Object.is(value, -0) ? negativeZero : value;
  if (cache.has(key)) { hits++; return cache.get(key); }
  misses++;
  const result = original.call(this, value);
  if (cache.size >= limit) { cache.delete(cache.keys().next().value); evictions++; }
  cache.set(key, result);
  return result;
};
process.on('exit', () => writeFileSync(process.env.TACT_DIAGNOSTIC_STATS ?? '/tmp/tact-float80-cache-stats.json', JSON.stringify({kind:'Diagnostic-only bounded immutable Float80.fromNumber cache; original method on misses',limit,hits,misses,evictions,size:cache.size},null,2)+'\n'));
