import { restoreEvidence } from './restore-evidence.js';

if(process.argv.length>2)throw new Error('Usage: node tools/restore-2010-evidence.js');
const result=await restoreEvidence({root:new URL('../versions/2010-en/',import.meta.url)});
console.log(`2010 evidence: ${result.restored} restored, ${result.skipped} verified (${result.bytes} bytes).`);
