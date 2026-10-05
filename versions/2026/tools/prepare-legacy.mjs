// Copy the pinned runtime without transpilation. Generated files never enter Git.
import {readFile,mkdir,writeFile,rm} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {fileURLToPath} from 'node:url';
const root=new URL('../../../',import.meta.url),out=new URL('../public/legacy/',import.meta.url);
const pin=JSON.parse(await readFile(new URL('../analysis/baseline/reference.json',import.meta.url)));
const data=['original-memory.json','original-constants.bin','original-initial-state.bin','original-english-data.bin','trig-tables.json','x87-trig.json','x87-stored-trig.json','initial-shoreline-stack.json'].map(f=>'versions/2010-en/assets/data/'+f);
const required=new Set([...data,'assets/data/system-font.json','assets/images/system-font-glyphs.png']);
const rows=pin.files.filter(f=>(f.path.startsWith('src/')||f.path.startsWith('versions/2010-en/src/'))&&f.path.endsWith('.js')||required.has(f.path));
for(const path of required)if(!rows.some(f=>f.path===path))throw new Error('Unpinned required asset '+path);
// Validate every input before replacing a previously usable generated tree.
const files=await Promise.all(rows.map(async f=>{const bytes=await readFile(new URL(f.path,root));if(bytes.length!==f.bytes||createHash('sha256').update(bytes).digest('hex')!==f.sha256)throw new Error('Frozen input differs: '+f.path);return {f,bytes};}));
await rm(out,{recursive:true,force:true});
for(const {f,bytes}of files){const target=new URL(f.path,out);await mkdir(fileURLToPath(new URL('./',target)),{recursive:true});await writeFile(target,bytes);}
await writeFile(new URL('manifest.json',out),JSON.stringify({reference:pin.reference.commit,files:rows},null,2));
console.log(`Prepared ${rows.length} byte-exact legacy modules/assets`);
