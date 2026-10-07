import{openBrowser}from'../../../tools/browser-session.js';import{mkdir,writeFile}from'node:fs/promises';import{resolve}from'node:path';
const out=resolve(process.argv[2]);await mkdir(out);const course=Number(process.env.TACT_ISLAND_COURSE??3),windDirection=process.env.TACT_ISLAND_WIND_DIRECTION??'auto';const log=[],b=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true,requestTimeoutMs:60000});
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 if(process.env.TACT_ISLAND_CHAMP==='1')await b.evaluate('document.getElementById("race-mode").value="championship"');
 await b.evaluate(`document.getElementById("race-area").value="32801";document.getElementById("race-boat").value="1";document.getElementById("race-fleet").value="5";document.getElementById("race-course").value="${course}";document.getElementById("race-wind-direction").value="${windDirection}";document.getElementById("race-wind").value="2";document.getElementById("race-wind").dispatchEvent(new Event("change"))`);await b.waitFor('tact2026.ready&&document.getElementById("boat-preview").dataset.boat==="1"||tact2026.error',60000);
 await b.evaluate('document.getElementById("race-form").requestSubmit()');await b.waitFor('tact2026.ready&&document.getElementById("starter").hidden&&!tact2026.paused||tact2026.error',60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));await b.evaluate('tact2026.engine.send("pause",true)');await b.waitFor('tact2026.paused');
 await b.evaluate('(()=>{for(let n=0;n<6;n++)tact2026.engine.send("key",33);return tact2026.engine.request("boundary");})()');
 const initial=await b.evaluate('({boundary:tact2026.initial,pace:tact2026.latest.pace,course:tact2026.latest.course})');
 for(let batch=0;batch<120;batch++){
  await b.evaluate('tact2026.engine.request("step",200)');const s=await b.evaluate('({clock:tact2026.latest.clock,sequence:tact2026.latest.sequence,boats:tact2026.latest.boats,results:tact2026.latest.resultsReady,window:tact2026.latest.raceWindow,error:tact2026.error})');if(s.error)throw Error(s.error);log.push(s);
  await writeFile(resolve(out,'progress.json'),JSON.stringify({initial,log},null,2));console.log(JSON.stringify({batch,clock:s.clock,legs:s.boats.map(b=>b.leg),finishes:s.boats.map(b=>b.finished),depths:s.boats.map(b=>Math.round(b.depth)),results:s.results}));
  if(s.results)break;
 }
 const last=log.at(-1),arrivals=last.boats.filter(b=>b.id>1&&b.finished>0&&!b.dnf);if(!last.results||arrivals.length<2)throw Error('AI did not navigate island and complete a race');
 if(!last.boats[0].dnf||!last.window.closedByCutoff||last.clock<last.window.deadline)throw Error('Natural leader did not start/close the DNF window');
 await writeFile(resolve(out,'finish.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 let nextRace;
 if(process.env.TACT_ISLAND_CHAMP==='1'){
  const before=await b.evaluate('tact2026.engine.request("boundary")'),standings=await b.evaluate('({races:tact2026.event.races,standings:tact2026.event.standings})');await b.evaluate('tact2026.nextRace()');await b.waitFor('tact2026.ready&&tact2026.event.activeRace===2||tact2026.error',60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));
  if(!await b.evaluate('!document.getElementById("starter").hidden&&document.getElementById("boat-preview").dataset.state==="ready"&&!document.getElementById("start-race").disabled'))throw Error('Next-race starter/preview not ready');const after=await b.evaluate('tact2026.engine.request("step",20)');if(after.frame<=before.frame||after.rngState===initial.boundary.rngState||await b.evaluate('tact2026.latest.raceWindow.deadline!==undefined||tact2026.latest.boats.some(b=>b.dnf||b.finished)'))throw Error('DNF championship transition did not reset the race');nextRace={before,after,standings};
 }
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,initial,log,nextRace,scope:'Independent2026 numerical steps, unsteered human, five Optimists on moderate-wind island; original Page Up pace controls, actual AI sailing/arrivals and game-clock cutoff. Optional natural DNF championship-to-next-race transition. No position/leg/finish fixtures. Diagnostic batch pacing, not a performance series.'},null,2));
}catch(e){await writeFile(resolve(out,'failure.json'),JSON.stringify({error:e.stack,log,state:await b.evaluate('({error:tact2026.error,state:tact2026.latest})').catch(String)},null,2));throw e;}finally{await b.close();}
