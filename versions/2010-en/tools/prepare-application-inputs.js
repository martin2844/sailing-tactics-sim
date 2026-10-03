import { readFile,writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { fileURLToPath } from 'node:url';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { PREFERENCE_FIELDS,PREFERENCE_BYTES } from '../src/engine/application.js';

const edition=new URL('../',import.meta.url);
const source=await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe',edition));
const sha=createHash('sha256').update(source).digest('hex');
if(sha!=='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787')throw new Error('Exact English image differs');
const memory=loadPE32(source),cases=[];
const intBytes=value=>{const data=Buffer.alloc(4);data.writeUInt32LE(value>>>0);return data;};
const patch=(address,value)=>({address,bytes:intBytes(value).toString('hex')});
// This generates inputs only. Expected bytes/callbacks come from original code.
function archive(overrides={},pattern=0,tailBits='000000000000f03f') {
  const bytes=Buffer.alloc(PREFERENCE_BYTES);let offset=0;
  for(let index=0;index<PREFERENCE_FIELDS.length;index++) {
    const field=PREFERENCE_FIELDS[index];
    if(field.type==='F64') Buffer.from(tailBits,'hex').copy(bytes,offset);
    else {
      const value=overrides[field.address]??(pattern?((Math.imul(index+1,0x9e3779b9)^pattern)|0):memory.readI32(field.address));
      intBytes(value).copy(bytes,offset);
    }
    offset+=field.bytes;
  }
  return bytes.toString('hex');
}
const normal={0x4da19c:1,0x4da144:12,0x4da174:7,0x4da194:15,0x4da198:7,0x4da188:1,
 0x4da140:1,0x4da1d8:5,0x4da1dc:1,0x4da1e8:1,0x525a7c:1,0x525a80:2,0x536420:0};
function add(label,preferences=null,overrides={}) {
  const index=cases.length;
  cases.push({label,timeSeed:index%2?1600000000:1700000000,screenHeight:[0,480,768,1080,2160][index%5],preferences,
    patches:[patch(0x4da16c,overrides.edition??0),patch(0x536420,overrides.session??0),patch(0x4da178,overrides.previousDivisor??256)]});
}
add('missing archive original defaults');
add('missing archive original demo defaults',null,{edition:1,session:11});
for(let course=1;course<=8;course++)for(const weather of [1,3,5,7]) {
  add(`archive course${course} weather${weather}`,archive({...normal,0x4da19c:course,0x4da188:weather}));
}
for(const level of [-2147483648,-1,0,1,15,16,2147483647]) {
  add(`speed level${level} retained signed divisor`,archive({...normal,0x4da174:level}),{previousDivisor:-1234567});
}
for(const value of [-2147483648,-1,0,1,2,10,11,2147483647]) {
  add(`sanitization boundary${value}`,archive({...normal,0x4da1d8:value,0x4da1dc:value,0x525a7c:value,0x525a80:value,0x5363fc:value}));
}
for(const session of [-2147483648,-1,0,11,12,2147483647]) {
  add(`original demo save session${session}`,archive({...normal,0x536420:session}),{edition:1,session});
}
for(const [pattern,bits] of [[0x12345678,'0000000000000080'],[0x7f000001,'0100000000000000'],[0xffffffff,'000000000000f87f']]) {
  add(`opaque archive words${pattern>>>0} F64bits${bits}`,archive({0x4da188:7,0x4da19c:8,0x4da174:8,0x4da194:30},pattern,bits));
}
const manifest={format:1,sourceSha256:sha,
  scope:'Original full constructor402440 and destructor/archive writer4036a0 with actual CFile/CArchive and private p.tac, native arithmetic027f, fixed original UTC time and screen-height inputs. No browser-derived expected outputs.',cases};
const target=process.argv[2]??fileURLToPath(new URL('analysis/application-capture-inputs.json',edition));
await writeFile(target,JSON.stringify(manifest,null,2)+'\n');
console.log(`Prepared ${cases.length} bounded original constructor/archive profiles`);
