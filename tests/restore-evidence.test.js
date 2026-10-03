import test from 'node:test';
import assert from 'node:assert/strict';
import { createHash } from 'node:crypto';
import { mkdtemp,mkdir,writeFile,readFile,rm,readdir,symlink } from 'node:fs/promises';
import { join } from 'node:path';
import { tmpdir } from 'node:os';
import { gzipSync } from 'node:zlib';
import { restoreEvidence } from '../tools/restore-evidence.js';

const digest=bytes=>createHash('sha256').update(bytes).digest('hex');
async function fixture(t){
  const root=await mkdtemp(join(tmpdir(),'tact-evidence-test-'));t.after(()=>rm(root,{recursive:true,force:true}));
  const bytes=Buffer.from(' { "recorded": [1, 2, 3], "exactWhitespace": true }\n'),compressed=gzipSync(bytes);
  const row={path:'tests/fixtures/original-test.json',archive:'evidence/archives/test.json.gz',
    bytes:bytes.length,sha256:digest(bytes),compressedBytes:compressed.length,compressedSha256:digest(compressed),profiles:['all','workbench']};
  await mkdir(join(root,'evidence/archives'),{recursive:true});await writeFile(join(root,row.archive),compressed);
  const save=async rows=>writeFile(join(root,'evidence/manifest.json'),JSON.stringify({format:1,files:rows}));
  await save([row]);return{root,bytes,compressed,row,save};
}
test('compressed evidence restores byte-identical canonical files and verifies existing files without requiring inflation',async t=>{
  const f=await fixture(t);assert.deepEqual(await restoreEvidence({root:f.root}),{profile:'all',selected:1,restored:1,skipped:0,bytes:f.bytes.length});
  assert.deepEqual(await readFile(join(f.root,f.row.path)),f.bytes);
  await rm(join(f.root,f.row.archive));
  assert.deepEqual(await restoreEvidence({root:f.root}),{profile:'all',selected:1,restored:0,skipped:1,bytes:f.bytes.length});
});
test('workbench profile restores only its declared canonical data',async t=>{
  const f=await fixture(t),other={...f.row,path:'analysis/all-only.json',archive:'evidence/archives/all-only.json.gz',profiles:['all']};
  await writeFile(join(f.root,other.archive),f.compressed);await f.save([f.row,other]);
  assert.equal((await restoreEvidence({root:f.root,profile:'workbench'})).selected,1);
  await assert.rejects(readFile(join(f.root,other.path)),{code:'ENOENT'});
  assert.equal((await restoreEvidence({root:f.root})).restored,1);
});
test('a mismatched existing canonical file is preserved instead of replaced',async t=>{
  const f=await fixture(t);await mkdir(join(f.root,'tests/fixtures'),{recursive:true});
  const other=Buffer.from(f.bytes);other[1]^=1;await writeFile(join(f.root,f.row.path),other);
  await assert.rejects(restoreEvidence({root:f.root}),/refusing replacement/);
  assert.deepEqual(await readFile(join(f.root,f.row.path)),other);
});
for(const kind of ['missing','corrupt','compressedHash','expandedHash','expandedCount'])test(`invalid ${kind} evidence leaves no canonical or temporary file`,async t=>{
  const f=await fixture(t);
  if(kind==='missing')await rm(join(f.root,f.row.archive));
  if(kind==='corrupt'){const broken=Buffer.from(f.compressed);broken[broken.length-5]^=1;await writeFile(join(f.root,f.row.archive),broken);f.row.compressedSha256=digest(broken);}
  if(kind==='compressedHash')f.row.compressedSha256='0'.repeat(64);
  if(kind==='expandedHash')f.row.sha256='0'.repeat(64);
  if(kind==='expandedCount')f.row.bytes--;
  await f.save([f.row]);await assert.rejects(restoreEvidence({root:f.root}));
  assert.deepEqual(await readdir(join(f.root,'tests/fixtures')),[]);
});
test('manifest paths cannot escape the declared archive/output directories',async t=>{
  const f=await fixture(t);
  for(const change of [{path:'tests/fixtures/../../outside'},{path:'src/runtime/overwrite.js'},{archive:'evidence/../outside.gz'},{path:'/absolute.json'},{path:'tests\\fixtures\\outside.json'}]){
    await f.save([{...f.row,...change}]);await assert.rejects(restoreEvidence({root:f.root}),/outside its declared scope/);
  }
});
test('restoration rejects symlink output parents instead of writing outside the clone',async t=>{
  const f=await fixture(t),outside=await mkdtemp(join(tmpdir(),'tact-evidence-outside-'));t.after(()=>rm(outside,{recursive:true,force:true}));
  await symlink(outside,join(f.root,'tests'));await assert.rejects(restoreEvidence({root:f.root}),/real directory/);
  assert.deepEqual(await readdir(outside),[]);
});
test('concurrent restoration publishes one complete canonical file without overwriting',async t=>{
  const f=await fixture(t);const results=await Promise.all([restoreEvidence({root:f.root}),restoreEvidence({root:f.root})]);
  assert.equal(results.reduce((sum,row)=>sum+row.restored,0),1);
  assert.deepEqual(await readFile(join(f.root,f.row.path)),f.bytes);
  assert.deepEqual(await readdir(join(f.root,'tests/fixtures')),['original-test.json']);
});
