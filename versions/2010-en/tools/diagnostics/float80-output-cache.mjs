// Read-only diagnostic import; never loaded by the browser production graph.
import {Float80} from '../../../../src/runtime/float80.js';
import {writeFileSync} from 'node:fs';
const original=Float80.prototype.toNumber;const cache=new WeakMap();let hits=0,misses=0;
Float80.prototype.toNumber=function(){if(cache.has(this)){hits++;return cache.get(this);}misses++;const value=original.call(this);cache.set(this,value);return value;};
process.on('exit',()=>writeFileSync(process.env.TACT_DIAGNOSTIC_STATS ?? '/tmp/tact-float80-to-number-cache-stats.json',JSON.stringify({kind:'Diagnostic-only immutable Float80.toNumber identity WeakMap; original method on misses',hits,misses},null,2)+'\n'));
