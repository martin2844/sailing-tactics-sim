import{openBrowser}from'../../../tools/browser-session.js';import{mkdir,writeFile}from'node:fs/promises';import{resolve}from'node:path';
const out=resolve(process.argv[2]);await mkdir(out);const b=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true,requestTimeoutMs:60000});const log=[];const wrap=a=>((a+540)%360)-180;
try{
 await b.waitFor('globalThis.tact2026?.ready',60000);await b.evaluate('document.getElementById("race-mode").value="championship";document.getElementById("race-mode").dispatchEvent(new Event("change"))');await b.waitFor('tact2026.ready&&tact2026.latest.seriesScoring',60000);
 const initial=await b.evaluate('tact2026.initial');
 for(let race=1;race<=3;race++){
  await b.evaluate('document.getElementById("race-form").requestSubmit();tact2026.engine.send("pause",true)');await b.waitFor('tact2026.paused',10000);
  let tackSide=1,lastLeg=-1,done=false;
  for(let batch=0;batch<1600;batch++){
   const s=await b.evaluate('tact2026.latest');if(s.resultsReady){done=true;log.push({race,completed:s.completedRaces,boats:s.boats,event:await b.evaluate('({races:tact2026.event.races,standings:tact2026.event.standings,complete:tact2026.event.complete})')});break;}
   if(s.frozen)throw Error('Race transition left the native simulator frozen');
   const p=s.boats[0],w=p.windFrom*Math.PI/180,target=s.clock< -8?{x:(s.course.start.a.x+s.course.start.b.x)/2-Math.sin(w)*90,y:(s.course.start.a.y+s.course.start.b.y)/2+Math.cos(w)*90}:s.course.target,dx=target.x-p.x,dy=target.y-p.y,bearing=(Math.atan2(dx,-dy)*180/Math.PI+360)%360,relative=wrap(bearing-p.windFrom),close=Math.max(42,s.course.closeAngle+3);let desired=bearing;
   if(Math.abs(relative)<close){if(batch===0)tackSide=Math.sign(wrap(p.heading-p.windFrom))||1;if(Math.abs(relative)>close-5&&Math.sign(relative)!==tackSide){tackSide=Math.sign(relative);}desired=p.windFrom+tackSide*close;}
   const delta=wrap(desired-p.heading),id=delta>0?32841:32842,n=Math.min(100,Math.round(Math.abs(delta)/10));
   await b.evaluate(`(()=>{for(let n=0;n<${n};n++)tact2026.engine.send('command',${id});return tact2026.engine.request('step',${p.finished?120:40})})()`);
   if(p.leg!==lastLeg||batch%100===0){const item={race,batch,clock:s.clock,leg:p.leg,position:[p.x,p.y],speed:p.speed,heading:p.heading,bearing,desired,status:p.status,finished:p.finished,otherFinished:s.boats.filter(b=>b.finished).length};log.push(item);console.log(JSON.stringify(item));lastLeg=p.leg;await writeFile(resolve(out,'progress.json'),JSON.stringify(log,null,2));}
  }
  if(!done)throw Error('Natural sailing driver did not complete race');
  await writeFile(resolve(out,`race-${race}.png`),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
  if(race<3){const before=await b.evaluate('tact2026.engine.request("boundary")');await b.evaluate('tact2026.nextRace()');await b.waitFor(`tact2026.ready&&tact2026.event.activeRace===${race+1}&&tact2026.latest.boats[0].finished===0`,60000);const after=await b.evaluate('tact2026.engine.request("boundary")');if(after.frame<=before.frame||after.rngState===initial.rngState)throw Error('Next race reset engine');log.push({race,nextTransition:{before,after}});}
 }
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,log,scope:'Natural original physics and original helm commands; no game memory fixtures'},null,2));
}catch(e){await writeFile(resolve(out,'failure.json'),JSON.stringify({error:e.stack,log,state:await b.evaluate('({error:tact2026.error,state:tact2026.latest})').catch(String)},null,2));throw e}finally{await b.close()}
