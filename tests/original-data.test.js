import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/memory.js';
import { loadOriginalData } from '../src/runtime/original-data.js';

test('browser data-only image preserves every original constant and initial state byte',async()=>{
  const base=new URL('../assets/data/',import.meta.url);
  const manifest=JSON.parse(await readFile(new URL('original-memory.json',base),'utf8'));
  const segments=new Map(await Promise.all(manifest.segments.map(async row=>[row.file,new Uint8Array(await readFile(new URL(row.file,base)))])));
  const data=loadOriginalData(manifest,segments),original=loadPE32(await readFile(new URL('../original/Tact02Demo.exe',import.meta.url)));
  for(const row of manifest.segments){
    assert.equal(createHash('sha256').update(segments.get(row.file)).digest('hex'),row.sha256);
    assert.deepEqual(data.readBytes(row.address,row.size),original.readBytes(row.address,row.size));
  }
  assert.ok(data.readBytes(0x401000,0x80800).every(value=>value===0),'No original executable instruction section is mapped');
});
