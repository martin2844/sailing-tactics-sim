import{openBrowser}from'../../../tools/browser-session.js';
import{mkdir,writeFile}from'node:fs/promises';import{resolve}from'node:path';
import{navigationTarget}from'../app/navigation.ts';
const out=resolve(process.argv[2]);await mkdir(out);const b=await openBrowser('http://127.0.0.1:8770/?manual&fleet=5',{headless:true,gpu:true,requestTimeoutMs:60000});
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));
 const initial=await b.evaluate('tact2026.engine.request("boundary")'),boundaries=[];
 while(await b.evaluate('tact2026.latest.clock<5')){
  if(boundaries.length>=10)throw Error('Original countdown did not progress');
  boundaries.push(await b.evaluate('tact2026.engine.request("step",200)'));
 }
 await b.waitFor('tact2026.scene.modelSequence>=tact2026.latest.sequence||tact2026.error',60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));
 await b.evaluate('tact2026.camera("overview")');await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
 const race=await b.evaluate('({clock:tact2026.latest.clock,sequence:tact2026.latest.sequence,course:tact2026.latest.course,player:tact2026.latest.boats[0],mode:tact2026.latest.configuration.mode,guideMeshes:tact2026.scene.course.guides.filter(l=>l.group.visible).length,activeGuides:tact2026.scene.course.guides.filter(l=>l.group.visible&&l.pixelWidth===1.8).length,labels:tact2026.scene.labels.placed,hud:{label:document.getElementById("target-label").textContent,bearing:document.getElementById("target-bearing").textContent}})');
 if(race.clock<0||race.mode!==0||!race.course.guides.length||race.guideMeshes!==race.course.guides.length)throw Error('Live non-demo native guides missing after countdown');
 const navigation=navigationTarget(race.course,race.player,race.clock);
 if(navigation.label!=='Mark 1'||race.hud.label!==navigation.label||race.hud.bearing!==Math.round(navigation.bearing)%360+'°'||race.course.navigationTarget.point!==3||race.activeGuides!==2)throw Error('Original physical target/active guides missing: '+JSON.stringify(race));
 if(Math.hypot(race.course.target.x-race.course.navigationTarget.x,race.course.target.y-race.course.navigationTarget.y)<50)throw Error('Fixture must exercise offset native AI approach waypoint');
 await writeFile(resolve(out,'race-overview.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 const before=await b.evaluate('tact2026.engine.request("boundary")');await b.evaluate('tact2026.camera("chase")');await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');const after=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Race camera changed master');
 await writeFile(resolve(out,'race-follow.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Actual original countdown and early race on five boats through real paints, no injected clock/progression; live native guide count, physical HUD target despite offset AI waypoint, two amber approaches, non-demo and paused camera isolation. Not a completed race or cadence benchmark.',initial,boundaries,race,before,after},null,2));console.log(JSON.stringify({passed:true,paints:race.sequence-initial.frame,clock:race.clock,guides:race.course.guides.length}));
}catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e;}finally{await b.close();}
