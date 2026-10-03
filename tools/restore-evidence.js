import { createHash,randomUUID } from 'node:crypto';
import { createReadStream,createWriteStream } from 'node:fs';
import { lstat,mkdir,readFile,realpath,link,unlink } from 'node:fs/promises';
import { dirname,resolve,posix } from 'node:path';
import { Transform } from 'node:stream';
import { pipeline } from 'node:stream/promises';
import { fileURLToPath } from 'node:url';
import { createGunzip } from 'node:zlib';

const projectRoot=fileURLToPath(new URL('../',import.meta.url));
const pathValue=value=>value instanceof URL?fileURLToPath(value):resolve(value);
const fail=message=>{throw new Error(message);};
function relativePath(value,prefixes){
  if(typeof value!=='string'||!value||value.includes('\\')||value.includes('\0')||value.includes(':')||value.startsWith('/')||posix.normalize(value)!==value||value.split('/').some(part=>part==='.'||part==='..'||!part)||!prefixes.some(prefix=>value.startsWith(prefix))){
    fail(`Evidence path is outside its declared scope: ${value}`);
  }
  return value;
}
function manifestRows(manifest){
  if(manifest?.format!==1||!Array.isArray(manifest.files))fail('Unsupported evidence manifest format');
  const paths=new Set(),archives=new Set();
  return manifest.files.map(row=>{
    relativePath(row?.path,['tests/fixtures/','analysis/']);
    relativePath(row?.archive,['evidence/']);
    for(const field of ['bytes','compressedBytes'])if(!Number.isSafeInteger(row[field])||row[field]<0)fail(`Invalid ${field} for ${row.path}`);
    for(const field of ['sha256','compressedSha256'])if(typeof row[field]!=='string'||!/^[0-9a-f]{64}$/.test(row[field]))fail(`Invalid ${field} for ${row.path}`);
    if(!Array.isArray(row.profiles)||!row.profiles.includes('all')||row.profiles.some(profile=>!['all','workbench'].includes(profile))||new Set(row.profiles).size!==row.profiles.length)fail(`Invalid profiles for ${row.path}`);
    if(paths.has(row.path)||archives.has(row.archive))fail(`Duplicate evidence target/archive: ${row.path}`);
    paths.add(row.path);archives.add(row.archive);return row;
  });
}
async function safeParent(root,relative,{create=false}={}){
  const parts=relative.split('/');parts.pop();let current=root;
  for(const part of parts){
    current=resolve(current,part);let stat;
    try{stat=await lstat(current);}catch(error){
      if(error.code!=='ENOENT'||!create)throw error;
      try{await mkdir(current);}catch(cause){if(cause.code!=='EEXIST')throw cause;}
      stat=await lstat(current);
    }
    if(stat.isSymbolicLink()||!stat.isDirectory())fail(`Evidence parent must be a real directory: ${current}`);
  }
}
async function fileStat(path){
  try{const stat=await lstat(path);if(!stat.isFile()||stat.isSymbolicLink())fail(`Evidence must be a regular file: ${path}`);return stat;}
  catch(error){if(error.code==='ENOENT')return null;throw error;}
}
class ByteDigest extends Transform{
  constructor(expectedBytes,label){super();this.count=0;this.expectedBytes=expectedBytes;this.label=label;this.hash=createHash('sha256');}
  _transform(chunk,_encoding,callback){
    this.count+=chunk.length;
    if(this.count>this.expectedBytes){callback(new Error(`${this.label}: byte count exceeds manifest`));return;}
    this.hash.update(chunk);callback(null,chunk);
  }
  verify(expectedHash){
    if(this.count!==this.expectedBytes)fail(`${this.label}: byte count differs from manifest`);
    if(this.hash.digest('hex')!==expectedHash)fail(`${this.label}: SHA256 differs from manifest`);
  }
}
async function verifyExisting(path,row){
  const stat=await fileStat(path);if(!stat)return false;
  if(stat.size!==row.bytes)fail(`Existing canonical evidence differs from manifest; refusing replacement: ${row.path}`);
  const hash=createHash('sha256');let count=0;
  for await(const chunk of createReadStream(path)){count+=chunk.length;hash.update(chunk);}
  if(count!==row.bytes||hash.digest('hex')!==row.sha256)fail(`Existing canonical evidence differs from manifest; refusing replacement: ${row.path}`);
  return true;
}

/** Restore canonical bytes, never changing a valid or mismatched existing file.
 * Both compressed and expanded byte counts/SHA256 are checked while streaming.
 * The exclusive hard link publishes a fully verified temporary file atomically;
 * unlike Node rename(), it cannot replace a concurrently created destination.
 */
export async function restoreEvidence({root=projectRoot,manifestPath='evidence/manifest.json',profile='all'}={}){
  if(!['all','workbench'].includes(profile))fail(`Unknown evidence profile: ${profile}`);
  root=await realpath(pathValue(root));relativePath(manifestPath,['evidence/']);
  await safeParent(root,manifestPath);const manifestFile=resolve(root,manifestPath);
  if(!await fileStat(manifestFile))fail(`Missing evidence manifest: ${manifestPath}`);
  const rows=manifestRows(JSON.parse(await readFile(manifestFile,'utf8'))).filter(row=>row.profiles.includes(profile));
  const result={profile,selected:rows.length,restored:0,skipped:0,bytes:0};
  for(const row of rows){
    await safeParent(root,row.path,{create:true});const target=resolve(root,row.path);
    if(await verifyExisting(target,row)){result.skipped++;result.bytes+=row.bytes;continue;}
    await safeParent(root,row.archive);const archive=resolve(root,row.archive),stat=await fileStat(archive);
    if(!stat)fail(`Missing evidence archive: ${row.archive}`);
    if(stat.size!==row.compressedBytes)fail(`${row.archive}: compressed byte count differs from manifest`);
    const temporary=target+`.restore-${process.pid}-${randomUUID()}.tmp`;
    const compressed=new ByteDigest(row.compressedBytes,row.archive),expanded=new ByteDigest(row.bytes,row.path);
    try{
      await pipeline(createReadStream(archive),compressed,createGunzip(),expanded,createWriteStream(temporary,{flags:'wx',mode:0o644}));
      compressed.verify(row.compressedSha256);expanded.verify(row.sha256);
      try{await link(temporary,target);result.restored++;}
      catch(error){if(error.code!=='EEXIST')throw error;await verifyExisting(target,row);result.skipped++;}
      result.bytes+=row.bytes;
    }finally{await unlink(temporary).catch(error=>{if(error.code!=='ENOENT')throw error;});}
  }
  return result;
}

if(process.argv[1]&&resolve(process.argv[1])===fileURLToPath(import.meta.url)){
  try{
    const arguments_=process.argv.slice(2);
    if(arguments_.some(value=>value!=='--workbench')||arguments_.length>1)fail('Usage: node tools/restore-evidence.js [--workbench]');
    const result=await restoreEvidence({profile:arguments_.includes('--workbench')?'workbench':'all'});
    console.log(`Evidence: ${result.restored} restored, ${result.skipped} existing files verified (${result.profile}, ${result.bytes} bytes).`);
  }catch(error){console.error(error.message);process.exitCode=1;}
}
