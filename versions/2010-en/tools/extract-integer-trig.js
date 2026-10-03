import { readFile,writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';

const fixture=JSON.parse(await readFile(new URL('../tests/fixtures/original-boat-options.json',import.meta.url),'utf8'));
const baseline=Buffer.from(fixture.mutableBaseline,'hex');
const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const sha=bytes=>createHash('sha256').update(bytes).digest('hex');
if(sha(source)!==fixture.provenance.sha256||sha(baseline)!==fixture.provenance.mutableBaselineSha256
  ||fixture.provenance.loadedOriginalTextUnchanged!==true)throw new TypeError('Original native baseline provenance differs');
const extract=address=>Array.from({length:362},(_,index)=>baseline.readInt32LE(address-fixture.mutableBlock.address+index*4));
const result={provenance:{...fixture.provenance,
  note:'Integer tables from the original 0x41e040 executed by the native oracle before its mutable baseline handshake; no browser trigonometry substitution.'},
  generator:0x41e040,sineAddress:0x4f85c8,cosineAddress:0x4f1740,
  sine:extract(0x4f85c8),cosine:extract(0x4f1740)};
await writeFile(new URL('../assets/data/trig-tables.json',import.meta.url),JSON.stringify(result,null,2)+'\n');
console.log('Extracted 362 native sine/cosine integer entries with original baseline provenance.');
