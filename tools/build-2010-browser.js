import { cp,mkdir,readdir,readFile,writeFile,rm,lstat } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { dirname,resolve,relative,sep } from 'node:path';
import { fileURLToPath } from 'node:url';

const root=fileURLToPath(new URL('../',import.meta.url));
const edition='versions/2010-en',destination=resolve(root,'dist-2010');
const target='Posey2010-English-native-JavaScript';
const originalSha256='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
const copied=new Set();

async function copyFile(path){
  if(copied.has(path))return;
  const source=resolve(root,path);
  if(!source.startsWith(resolve(root)+sep) || (await lstat(source)).isSymbolicLink())throw new Error(`Invalid player input ${path}`);
  await mkdir(dirname(resolve(destination,path)),{recursive:true});
  await cp(source,resolve(destination,path));copied.add(path);
}

// Follow the actual static module graph, including literal dynamic imports.
// This includes shared numerical/GDI code and no executable or proof fixtures.
async function copyModule(path){
  if(copied.has(path))return;
  if(!path.endsWith('.js') || !/^(src\/|versions\/2010-en\/src\/)/.test(path))throw new Error(`Module is outside the player graph: ${path}`);
  const source=await readFile(resolve(root,path),'utf8');
  await copyFile(path);
  const imports=/\b(?:from\s*|import\s*\(\s*|import\s*)(['"])([^'"\n]+)\1/g;
  for(const match of source.matchAll(imports)){
    const specifier=match[2];
    if(!specifier.startsWith('.'))throw new Error(`Player import must be local: ${specifier}`);
    await copyModule(relative(root,resolve(root,dirname(path),specifier)));
  }
}

async function copyTree(path){
  for(const row of await readdir(resolve(root,path),{withFileTypes:true})){
    const child=`${path}/${row.name}`;
    if(row.isDirectory())await copyTree(child);
    else if(row.isFile())await copyFile(child);
    else throw new Error(`Nonregular player input ${child}`);
  }
}

await mkdir(destination,{recursive:true});
if((await readdir(destination)).length){
  const marker=JSON.parse(await readFile(resolve(destination,'port-manifest.json'),'utf8'));
  if(marker.target!==target)throw new Error('Existing dist-2010 is not this generated browser export');
  await rm(destination,{recursive:true});await mkdir(destination);
}
await copyModule(`${edition}/src/play.js`);
for(const path of [`${edition}/assets/images`,`${edition}/assets/audio`,`${edition}/assets/ui`,'assets/font-source','LICENSES'])await copyTree(path);
for(const path of ['src/play.css','assets/data/system-font.json','assets/images/system-font-glyphs.png','THIRD-PARTY-NOTICES.md',
  `${edition}/assets/manifest.json`,`${edition}/assets/data/original-memory.json`,
  `${edition}/assets/data/original-constants.bin`,`${edition}/assets/data/original-initial-state.bin`,
  `${edition}/assets/data/original-english-data.bin`,`${edition}/assets/data/trig-tables.json`,
  `${edition}/assets/data/x87-trig.json`,`${edition}/assets/data/x87-stored-trig.json`,
  `${edition}/assets/data/initial-shoreline-stack.json`])await copyFile(path);
let html=(await readFile(resolve(root,edition,'play.html'),'utf8')).replace('<a href="../../index.html">Preservation workbench</a>','');
await mkdir(resolve(destination,edition),{recursive:true});
await writeFile(resolve(destination,edition,'play.html'),html);
html=html.replaceAll('href="../../src/play.css"','href="src/play.css"')
  .replaceAll('src="src/play.js"',`src="${edition}/src/play.js"`)
  .replaceAll('href="assets/',`href="${edition}/assets/`).replaceAll('src="assets/',`src="${edition}/assets/`);
await writeFile(resolve(destination,'index.html'),html);await writeFile(resolve(destination,'play.html'),html);
const server=(await readFile(resolve(root,'tools/serve.js'),'utf8'))
  .replace("resolve(dirname(fileURLToPath(import.meta.url)), '..')","resolve(dirname(fileURLToPath(import.meta.url)))")
  .replace('Tact browser workbench:','Posey 2010 browser simulator:');
await writeFile(resolve(destination,'serve.mjs'),server);
await writeFile(resolve(destination,'README.txt'),
  'Posey Sailing Tactics Simulator 2010 English — native JavaScript browser port\n\n'+
  'Run: node serve.mjs\nOpen: http://127.0.0.1:8765\n\n'+
  'Or upload this folder to a static HTTPS host. The player uses native JavaScript\n'+
  'and original data/assets. No Wine, Windows executable or instruction emulator\n'+
  'is needed. Press Space to begin; use the original menus for controls and help.\n'+
  'Sound can be enabled in the footer. Preferences are saved in this browser.\n\n'+
  'Smoother drawing is enabled by default; simulation math remains original.\n'+
  'For exact drawing math comparisons, open index.html?graphics=exact.\n\n'+
  'The full preservation repository contains recovered source and native\n'+
  'comparison evidence. This export contains only the browser player.\n');
const files=[];
async function collect(directory){
  for(const row of await readdir(directory,{withFileTypes:true})){
    const path=resolve(directory,row.name);
    if(row.isDirectory())await collect(path);
    else{const bytes=await readFile(path);files.push({path:relative(destination,path),bytes:bytes.length,sha256:createHash('sha256').update(bytes).digest('hex')});}
  }
}
await collect(destination);files.sort((a,b)=>a.path.localeCompare(b.path));
if(files.some(row=>/\.exe$|tests\/fixtures|decompiled\/|analysis\//.test(row.path)))throw new Error('Evidence/executable reached player export');
await writeFile(resolve(destination,'port-manifest.json'),JSON.stringify({target,originalSha256,files,totalBytes:files.reduce((sum,row)=>sum+row.bytes,0)},null,2)+'\n');
console.log(`${files.length} player files, ${(files.reduce((sum,row)=>sum+row.bytes,0)/1048576).toFixed(2)} MiB: ${destination}`);
