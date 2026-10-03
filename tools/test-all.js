import { spawn } from 'node:child_process';
import { fileURLToPath } from 'node:url';
import { restoreEvidence } from './restore-evidence.js';

const root=new URL('../',import.meta.url);
await restoreEvidence({root});
await restoreEvidence({root:new URL('versions/2010-en/',root)});
for(const edition of ['2002','2010']){
  const code=await new Promise((resolve,reject)=>{
    const child=spawn(process.execPath,[`tools/test-${edition}.js`,...process.argv.slice(2)],{
      cwd:fileURLToPath(root),stdio:'inherit',
    });
    child.once('error',reject);
    child.once('exit',code=>resolve(code??1));
  });
  if(code){process.exitCode=code;break;}
}
