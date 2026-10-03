import { readdir } from 'node:fs/promises';
import { spawn } from 'node:child_process';
import { fileURLToPath } from 'node:url';

const root=fileURLToPath(new URL('../',import.meta.url));
const files=(await readdir(new URL('../versions/2010-en/tests/',import.meta.url)))
  .filter(name=>name.endsWith('.test.js')).sort().map(name=>`versions/2010-en/tests/${name}`);
const child=spawn(process.execPath,['--test','--test-concurrency=1',...process.argv.slice(2),...files],{cwd:root,stdio:'inherit'});
child.on('error',error=>{console.error(error);process.exitCode=1;});
child.on('exit',(code,signal)=>{process.exitCode=code??1;if(signal)console.error(`2010 tests terminated by ${signal}`);});
