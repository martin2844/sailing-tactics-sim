import { cp,mkdir,readdir,readFile,writeFile,rm } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { dirname,resolve,relative } from 'node:path';
import { fileURLToPath } from 'node:url';

const root=resolve(dirname(fileURLToPath(import.meta.url)),'..'),destination=resolve(root,'dist');
await mkdir(destination,{recursive:true});
const existing=await readdir(destination);
if(existing.length){
  const marker=JSON.parse(await readFile(resolve(destination,'port-manifest.json'),'utf8'));
  if(marker.target!=='Posey2002-native-JavaScript')throw new Error('Existing dist folder is not this generated browser export');
  await rm(destination,{recursive:true});await mkdir(destination);
}
for(const directory of ['src/engine','src/render','src/runtime','assets/images','assets/audio','assets/ui','assets/font-source','assets/data/pc53','LICENSES']){
  await cp(resolve(root,directory),resolve(destination,directory),{recursive:true});
}
for(const file of ['src/play.js','src/play.css','assets/manifest.json','assets/data/original-memory.json','assets/data/original-constants.bin','assets/data/original-initial-state.bin','assets/data/system-font.json','THIRD-PARTY-NOTICES.md']){
  await mkdir(dirname(resolve(destination,file)),{recursive:true});await cp(resolve(root,file),resolve(destination,file));
}
const html=(await readFile(resolve(root,'play.html'),'utf8')).replace('<a href="index.html">Preservation workbench</a>','');
await writeFile(resolve(destination,'index.html'),html);await writeFile(resolve(destination,'play.html'),html);
const server=(await readFile(resolve(root,'tools/serve.js'),'utf8'))
  .replace("resolve(dirname(fileURLToPath(import.meta.url)), '..')","resolve(dirname(fileURLToPath(import.meta.url)))")
  .replace('Tact browser workbench:','Posey 2002 browser simulator:');
await writeFile(resolve(destination,'serve.mjs'),server);
await writeFile(resolve(destination,'README.txt'),'Posey Sailing Tactics Simulator 2002 Demo — native JavaScript browser port\n\nRun: node serve.mjs\nOpen: http://127.0.0.1:8765\n\nOr upload this folder to any static HTTPS host. No build system, Wine,\nWindows executable or instruction emulator is needed to play.\n\nPress Space to continue through the original start screens. Use the\noriginal menus or press ? for controls. Sound can be enabled in the footer.\nThe original demo notices and limits are preserved.\n\nNative execution comparisons and recovered source are retained in the\nfull preservation workspace; this export contains only the player.\n');
const files=[];
async function collect(directory){
  for(const entry of await readdir(directory,{withFileTypes:true})){
    const path=resolve(directory,entry.name);if(entry.isDirectory())await collect(path);
    else{const bytes=await readFile(path);files.push({path:relative(destination,path),bytes:bytes.length,sha256:createHash('sha256').update(bytes).digest('hex')});}
  }
}
await collect(destination);files.sort((a,b)=>a.path.localeCompare(b.path));
const manifest={target:'Posey2002-native-JavaScript',originalSha256:'881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea',builtAt:new Date().toISOString(),files,totalBytes:files.reduce((sum,row)=>sum+row.bytes,0)};
await writeFile(resolve(destination,'port-manifest.json'),JSON.stringify(manifest,null,2)+'\n');
console.log(`${files.length} player files, ${(manifest.totalBytes/1048576).toFixed(2)} MiB: ${destination}`);
