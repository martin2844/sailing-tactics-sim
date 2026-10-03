import { readFile, writeFile } from 'node:fs/promises';
import { fileURLToPath } from 'node:url';
import { createHash } from 'node:crypto';

const edition=new URL('../',import.meta.url);
const source=await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe',edition));
const sha=createHash('sha256').update(source).digest('hex');
if (sha!=='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787') throw new Error('Original English source differs');
const metadata=JSON.parse(await readFile(new URL('analysis/message-map-candidates.json',edition),'utf8'));
if (metadata.source_sha256!==sha) throw new Error('Original message-map source differs');
const map=metadata.tables.reduce((a,b)=>a.entries.length>b.entries.length?a:b);
const intPatch=(address,value)=>{const bytes=Buffer.alloc(4);bytes.writeUInt32LE(value>>>0);return {address,bytes:bytes.toString('hex')};};
const doublePatch=(address,value)=>{const bytes=Buffer.alloc(8);bytes.writeDoubleLE(value);return {address,bytes:bytes.toString('hex')};};
const common={
  0x4da140:1,0x4da144:12,0x4da16c:0,0x4da174:7,0x4da178:256,0x4da17c:256,0x4da180:7,
  0x4da188:1,0x4da18c:10,0x4da190:6,0x4da194:15,0x4da198:7,0x4da1a8:0,0x4da1ac:0,
  0x4da1d8:1,0x4da200:1,0x4f42b8:-150,0x4f8cd0:100,0x4faf7c:200,0x4fe624:1024,
  0x4fe2a8:720,0x4fe770:64,0x4f71c4:1,0x4f71c8:2,0x50f6d4:8,0x50f6d8:4,
  0x500384:45,0x500388:30,0x4f7ee4:2,0x4fe77c:2,0x4fe780:1,0x4feccc:80,0x4fecd0:100,
  0x5363b0:2,0x5363b4:0,0x536400:0,0x536420:0,0x536424:1,0x53642c:0,0x536434:0,
  0x536438:0,0x536444:0,0x536448:0,0x53644c:0,0x53646c:1,0x536478:0,0x536480:1,
  0x536484:0,0x53648c:0,0x5364ac:0,0x5364b0:0,0x5364c8:0,0x5364fc:0,0x536534:0,
  0x5233a8:0,0x535748:90,0x5359d0:100,0x4fb9b4:0,0x525a7c:0,0x525a80:0,
};
const definitions=[
  ['setup',{0x5363b0:0,0x4f8cd0:-150}],
  ['race',{}],
  ['two-players',{0x4da140:2,0x4da1ac:1,0x4da190:8}],
  ['full-chart',{0x5233a8:1}],
  ['wind-chart',{0x536434:1}],
  ['tide-chart',{0x536438:1}],
  ['tutorial',{0x536444:101,0x536448:101,0x5363b4:1}],
  ['original-demo-setup',{0x5363b0:0,0x4da16c:1,0x536420:6,0x4f8cd0:-150}],
];
const profiles=definitions.map(([name,values])=>({name,patches:[
  ...Object.entries({...common,...values}).map(([address,value])=>intPatch(+address,value)),
  doublePatch(0x4fe938,0.125),doublePatch(0x4da230,0),
]}));
const cases=[];
const add=(kind,identifier,args,profile,label,patches=[])=>cases.push({kind,identifier,arguments:args,profile,label,seed:0x12345678,patches});
for (let profile=0;profile<profiles.length;profile++) {
  for (let key=0;key<256;key++) add(1,0,[key,1,0],profile,`key-${key}`);
  for (const entry of map.entries) {
    if (entry.nMessage!==0x111) continue;
    if (entry.nCode===0 && ![32823,32779].includes(entry.nID)) add(2,entry.nID,[],profile,`command-${entry.nID}`);
    if (entry.nCode===0xffffffff) add(3,entry.nID,[],profile,`update-${entry.nID}`);
  }
  const positions=[[0,0],[1,1],[100,201],[100,199],[100,219],[100,220],[341,205],[342,205],[500,400],[-1,-1],[2147483647,-2147483648]];
  for (const [x,y] of positions) {
    for (const kind of [4,5,6]) add(kind,0,[0,x,y],profile,`mouse-${kind}-${x}-${y}`);
  }
  for (const delta of [-32768,-240,-121,-120,-119,-1,0,1,119,120,121,240,32767,65535,65536]) add(7,0,[3,delta,321,-123],profile,`wheel-${delta}`);
}
for (const table of metadata.tables) {
  const resource=table.sourceVA==='004c8008' ? 132 : table.sourceVA==='004c83e8' ? 131 : 0;
  if (resource) for (const entry of table.entries) for (const profile of [0,1,2,7]) add(8,(resource<<16)|entry.nID,[],profile,`radio-${resource}-${entry.nID}`);
}
for (const value of [-2147483648,-2147483647,-6,-1,0,1,85,89,90,91,2147483646,2147483647]) {
  for (const key of [0x1b,0xc0,0x47,0x73,0x34,0x35,0x36,0x37,0x39]) add(1,0,[key,2,0x1234],1,`integer-edge-${value}-${key}`,[intPatch(0x500384,value),intPatch(0x4fe77c,value),intPatch(0x512d64,value)]);
  for (const delta of [-120,120]) add(7,0,[0,delta,10,20],1,`wheel-edge-${value}-${delta}`,[intPatch(0x500384,value)]);
}
for (const value of [-Number.MAX_VALUE,-1e100,-Math.PI,-0,Number.MIN_VALUE,0.1,Math.PI,1e100,Number.MAX_VALUE]) {
  for (const key of [0xbc,0xde,0xbe,0x0d]) add(1,0,[key,1,0],1,`camera-angle-${value}-${key}`,[doublePatch(0x4fe938,value)]);
  add(2,33033,[],1,`sail-colour-${value}`,[doublePatch(0x4da230,value)]);
}
const manifest={format:1,sourceSha256:sha,
  scope:'Fixed original keyboard/menu/update/mouse/radio handlers. Real original MFC Default/TLS lookup; owned OS callbacks. Two actual modal-window entry handlers excluded.',
  profiles,cases};
const destination=process.argv[2] ?? fileURLToPath(new URL('analysis/controller-capture-inputs.json',edition));
await writeFile(destination,JSON.stringify(manifest,null,2)+'\n');
console.log(`Prepared ${cases.length} bounded original controller calls in ${profiles.length} explicit profiles`);
