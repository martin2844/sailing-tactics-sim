import {mkdir,writeFile,readFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {referenceSession,closeReferenceServer} from './reference-session.mjs';
const output=resolve(process.argv[2]??'');if(process.argv.length!==3)throw new Error('Usage: node timing-audit.mjs NEW_DIRECTORY');await mkdir(output);
const report={format:1,scope:'Declared unit-tick native host; fixed cursor/hover/keys, original menus and full paints. Continuous samples measure existing host throughput, not future GPU renderer performance.',runs:[]};
try{
  for(const [level,id]of [[1,32872],[5,32876],[10,32909]]){
    const session=await referenceSession({fleet:15,before:'globalThis.timingProbe?.begin()',record:'globalThis.timingProbe?.end(start)'});
    try{
      await session.browser.evaluate(`(()=>{
        const s=tact.state,m=s.memory,rows=[],get=s.options.getTickCount;let ticks=0,first=null,last=null;
        s.options.getTickCount=()=>{const v=get();if(first===null)first=v;last=v;ticks++;return v;};
        globalThis.timingProbe={rows,begin(){ticks=0;first=last=null;},end(start){rows.push({frame:s.frames,start,duration:performance.now()-start,tickReads:ticks,firstTick:first,lastTick:last,minimumHostDelay:Math.max(0,ticks-1),requestedDelay:s.delay,pace:m.readI32(0x4da174),divisor:m.readI32(0x4da178),time:m.readF64(0x5359f0),dt:m.readF64(0x523378),autoSlow:m.readI32(0x4da1dc),error:s.error});}};
      })()`);
      await session.command(id);await session.step('select native level '+level);
      const entry=await session.snapshot();
      const start=await session.browser.evaluate('timingProbe.rows.length=0;tact.state.frames');
      await session.held();await session.browser.evaluate('paintSetupGate.release()');
      await session.browser.waitFor(`tact.state.frames>=${start+36}||tact.state.error`,60000);
      // Re-hold at the next actual paint boundary; no modal or native memory write.
      const rows=await session.browser.evaluate('timingProbe.rows.slice(0,36)');
      if(rows.length!==36||rows.some(r=>r.error||r.pace!==level))throw new Error('Native pace run changed or failed');
      const first=rows[0],last=rows.at(-1),wall=(last.start-first.start)/1000,sim=last.time-first.time;
      report.runs.push({level,entry,rows,wallSeconds:wall,simulationSeconds:sim,observedSimulationSecondsPerWallSecond:sim/wall,modules:await session.modules()});
    }finally{await session.close();}
  }
  const session=await referenceSession({fleet:15});
  try{
    const states=[];
    for(const [label,action]of [['off',async()=>{}],['enabled',()=>session.command(32984)],['space slows',()=>session.key('Space',' ',32)],['space resumes with grace',()=>session.key('Space',' ',32)],['off again',()=>session.command(32984)]]){await action();states.push({label,snapshot:await session.snapshot()});}
    report.slowdown={states,scope:'Real original toggle and Space handlers; 0 off, 1 armed, Space pace toggle, 2 grace. Natural foul trigger remains covered by source contract; no foul flags injected.'};
  }finally{await session.close();}
  report.passed=report.runs.every(r=>r.rows.every(x=>x.tickReads>=1&&x.lastTick-x.firstTick===x.tickReads-1&&x.requestedDelay>=x.minimumHostDelay&&x.divisor===({1:2919,5:577,10:76})[r.level]))&&report.slowdown.states.map(s=>s.snapshot.autoSlow).join(',')==='0,1,1,2,0';
  if(!report.passed)process.exitCode=1;
}catch(error){report.failure=String(error.stack??error);process.exitCode=1;}
finally{await closeReferenceServer();await writeFile(resolve(output,'report.json'),JSON.stringify(report,null,2)+'\n');await writeFile(resolve(output,'collector.mjs.txt'),await readFile(new URL(import.meta.url)));}
console.log(JSON.stringify({passed:report.passed,failure:report.failure,runs:report.runs.map(r=>({level:r.level,dt:r.rows[0].dt,minimumDelay:r.rows[0].minimumHostDelay,observedSimRate:r.observedSimulationSecondsPerWallSecond})),slowdown:report.slowdown?.states.map(s=>({label:s.label,pace:s.snapshot.speed,automatic:s.snapshot.autoSlow}))},null,2));
