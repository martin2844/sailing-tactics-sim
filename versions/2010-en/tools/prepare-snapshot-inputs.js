import { readFile,writeFile } from 'node:fs/promises';
import { fileURLToPath } from 'node:url';
import { createHash } from 'node:crypto';

const edition=new URL('../',import.meta.url);
const source=await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe',edition));
const sourceSha256=createHash('sha256').update(source).digest('hex');
const recovered=JSON.parse(await readFile(new URL('analysis/race-snapshot-maps.json',edition),'utf8'));
if (sourceSha256!==recovered.sourceSha256) throw new Error('Original snapshot source differs');
const word=(address,value)=>{const bytes=Buffer.alloc(4);bytes.writeUInt32LE(value>>>0);return {address,bytes:bytes.toString('hex')};};
function profile(seed) {
  let state=seed>>>0;
  const next=()=>{state^=state<<13;state^=state>>>17;state^=state<<5;return state>>>0;};
  const regions=new Map();
  for (const table of [recovered.save,recovered.restore]) {
    for (const row of table.arrays) for (const address of [row.source,row.destination]) regions.set(address,Math.max(regions.get(address)??0,30*row.stride));
    for (const row of table.scalars) for (const address of [row.source,row.destination]) regions.set(address,Math.max(regions.get(address)??0,4));
  }
  for (const address of [0x5116e4,0x535624,0x4fe63c]) regions.set(address,30*4);
  // Native history resets are large. The first/middle/last old words and their
  // neighbors make off-by-one/partial clear mistakes visible in full-state SHA.
  for (const address of [0x5135a0,0x525ab8]) for (const index of [-1,0,1,250,501,7765,15529,15530,15531]) regions.set(address+index*4,4);
  const patches=[];
  for (const [address,bytes] of regions) {
    const data=Buffer.alloc(bytes);for(let offset=0;offset<bytes;offset+=4)data.writeUInt32LE(next(),offset);
    patches.push({address,bytes:data.toString('hex')});
  }
  return {name:`opaque-word-pattern-${seed}`,patches};
}
const profiles=[profile(1),profile(0x12345678),profile(0xdeadbeef),profile(0x80000000),{name:'retained-state',patches:[]}];
const cases=[];
for (const kind of [9,10]) for (const count of [-2147483648,-1,0,1,2,3,7,15,30]) for (let index=0;index<4;index++) {
  const stage=[-2147483648,-1,0,2147483647][index];
  cases.push({kind,identifier:0,arguments:[],profile:index,seed:0x12345678,label:`${kind===9?'save':'restore'}-${count}-pattern${index}`,
    patches:[word(0x4da194,count),word(0x4da1cc,stage),word(0x523648,stage)]});
}
for (let index=0;index<4;index++) {
  cases.push({kind:9,identifier:0,arguments:[],profile:index,seed:index+1,label:`retained-save-${index}`,patches:[word(0x4da194,30),word(0x4da1cc,index)]});
  cases.push({kind:10,identifier:0,arguments:[],profile:4,continue:true,label:`retained-restore-${index}`,patches:[word(0x4f8cd0,999),word(0x4da1cc,99),word(0x4f6c18,0x7ff80001)]});
  cases.push({kind:9,identifier:0,arguments:[],profile:4,continue:true,label:`retained-resave-${index}`,patches:[]});
}
const manifest={format:1,sourceSha256,scope:'Complete original 2010 save/restore, word-copy state plus two 15531-word clears; finite bounded fleet counts with nonpositive signed edges and opaque integer/F64-bit patterns.',profiles,cases};
const destination=process.argv[2]??fileURLToPath(new URL('analysis/snapshot-capture-inputs.json',edition));
await writeFile(destination,JSON.stringify(manifest,null,2)+'\n');console.log(`Prepared ${cases.length} bounded original snapshot calls`);
