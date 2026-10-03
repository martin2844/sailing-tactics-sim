import { AddressSpaceMemory } from './memory.js';

export const ORIGINAL_SOURCE_SHA256='881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea';

/** Map data-only preservation assets. This loader has no instruction interpreter. */
export function loadOriginalData(manifest,segments){
  if(manifest.sourceSha256!==ORIGINAL_SOURCE_SHA256)throw new Error('Original data source hash differs');
  if(manifest.imageBase!==0x400000||manifest.imageSize!==0x111000||manifest.segments.length!==2)throw new Error('Original data image layout differs');
  const memory=new AddressSpaceMemory(manifest.imageSize,manifest.imageBase);
  for(const row of manifest.segments){
    if(!['.rdata','.data'].includes(row.section))throw new Error('Only original data sections are accepted');
    const bytes=segments.get(row.file);
    if(!(bytes instanceof Uint8Array)||bytes.byteLength!==row.size)throw new Error(`Invalid original data segment ${row.file}`);
    memory.writeBytes(row.address,bytes);
  }
  return memory;
}

/** Fetch and hash-check both immutable inputs before constructing a fresh race. */
export async function fetchOriginalData({fetch:fetcher=globalThis.fetch,crypto=globalThis.crypto}={}){
  const base=new URL('../../assets/data/',import.meta.url);
  const get=async file=>{const response=await fetcher(new URL(file,base));if(!response.ok)throw new Error(`Could not load ${file}: ${response.status}`);return response;};
  const manifest=await (await get('original-memory.json')).json();
  const entries=await Promise.all(manifest.segments.map(async row=>{
    const bytes=new Uint8Array(await (await get(row.file)).arrayBuffer());
    const digest=new Uint8Array(await crypto.subtle.digest('SHA-256',bytes));
    const hash=Array.from(digest,byte=>byte.toString(16).padStart(2,'0')).join('');
    if(hash!==row.sha256)throw new Error(`Original data integrity check failed for ${row.file}`);
    return [row.file,bytes];
  }));
  return loadOriginalData(manifest,new Map(entries));
}
