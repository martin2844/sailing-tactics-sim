import {readFile,writeFile,mkdir} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {TUTORIAL_PAGE_ROUTINES} from '../src/render/tutorial-pages.js';

const root=new URL('../',import.meta.url);
const sourceSha256=createHash('sha256').update(await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe',root))).digest('hex');
if(sourceSha256!=='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787')throw new Error('Preserved English target differs');
const output=new URL('analysis/tutorial-inputs/',root);await mkdir(output,{recursive:true});
for(let page=1;page<=8;page++){
  const cases=[];
  for(const width of [640,699,700,899,900,901,1000,1001,1024,1280,1680]){
    for(const height of [480,724])for(const suppressColors of [0,1])cases.push({
      group:'original-width-and-color-boundaries',arguments:[0],seed:2000+cases.length,
      inputs:{width,height,suppressColors},
    });
  }
  const manifest={sourceSha256,routine:{name:`tutorial-${page}`,address:TUTORIAL_PAGE_ROUTINES[`drawTutorial${page}`],argumentTypes:['CDC'],returnType:'void'},
    integerInputs:{width:0x4fe624,height:0x4fe2a8,suppressColors:0x5363e4},integerOutputs:{},cases};
  await writeFile(new URL(`tutorial-${page}.json`,output),JSON.stringify(manifest,null,2)+'\n');
}
console.log('Prepared 352 finite basic tutorial calls across eight original English routines');
