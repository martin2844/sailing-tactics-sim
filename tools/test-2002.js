import { readdir } from 'node:fs/promises';
import { spawn } from 'node:child_process';
import { fileURLToPath } from 'node:url';
const root=fileURLToPath(new URL('../',import.meta.url));
const files=(await readdir(new URL('../tests/',import.meta.url)))
  .filter(name=>name.endsWith('.test.js')&&!/^(2008|2010)-/.test(name)).sort().map(name=>`tests/${name}`);
const processHandle=spawn(process.execPath,['--test',...process.argv.slice(2),...files],{cwd:root,stdio:'inherit'});
processHandle.on('error',error=>{console.error(error);process.exitCode=1;});
processHandle.on('exit',(code,signal)=>{process.exitCode=code??1;if(signal)console.error(`2002 tests terminated by ${signal}`);});
