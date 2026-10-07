import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});
const browser=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true,requestTimeoutMs:60000});
const windows=[];
try{
 await browser.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});
 await browser.waitFor('globalThis.tact2026?.ready',60000);
 await browser.evaluate(`for(const [id,value]of [['race-fleet','30'],['race-boat','12'],['race-speed','clock:32'],['race-mode','championship']]){const el=document.getElementById(id);el.value=value;el.dispatchEvent(new Event('change'));}document.getElementById('race-form').requestSubmit()`);
 await browser.waitFor('tact2026.ready&&document.getElementById("starter").hidden&&tact2026.latest.boats.length===30&&!tact2026.paused',60000);
 // Capture actual rendered wall-time throughput from prestart through results.
 for(let n=0;n<36;n++){
  const window=await browser.evaluate(`(async()=>{const start=performance.now(),time=tact2026.latest.time;await new Promise(r=>setTimeout(r,5000));const s=tact2026.latest;return{wall:(performance.now()-start)/1000,time,end:s.time,clock:s.clock,pace:s.pace,selected:s.playback.selected,active:s.playback.active,actual:s.playback.actualRate,contacts:s.contacts,raceWindow:s.raceWindow,results:s.resultsReady,boats:s.boats.map(b=>({id:b.id,leg:b.leg,finished:b.finished,dnf:b.dnf,grounded:b.grounded})),error:tact2026.error}})()`);
  if(window.error)throw Error(window.error);
  const actual=(window.end-window.time)/window.wall;windows.push({...window,measuredRate:actual});
  if(window.pace!==15||window.selected.rate!==32||window.active.rate!==32)throw Error('Fast-forward selection/preset changed');
  if(!window.results&&Math.abs(actual/32-1)>.05)throw Error('Sustained32× outside5% '+JSON.stringify(window));
  console.log(JSON.stringify({n,clock:window.clock,actual,arrivals:window.boats.filter(b=>b.finished&&!b.dnf).length,results:window.results}));
  await writeFile(resolve(output,'progress.json'),JSON.stringify({windows},null,2));
  if(window.results)break;
 }
 const final=windows.at(-1);
 if(!final.results||!final.boats.some(b=>b.finished&&!b.dnf)||!final.boats.every(b=>b.finished||b.dnf))throw Error('Fleet did not resolve into results');
 const next=await browser.evaluate('tact2026.engine.request("next-race")');
 await browser.waitFor('!tact2026.latest.resultsReady&&tact2026.latest.clock<0&&tact2026.latest.pace===15');
 await browser.evaluate('tact2026.engine.send("toggle-pace")');await browser.waitFor('tact2026.latest.pace===6&&tact2026.latest.playback.active.rate===1&&tact2026.latest.configuration.speed===15');
 await browser.evaluate('tact2026.engine.send("toggle-pace")');await browser.waitFor('tact2026.latest.pace===15&&tact2026.latest.playback.active.rate===32');
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,windows,next,scope:'Rendered Chrome30-Keelboat championship at32×: prestart, race, contacts, natural AI arrivals, DNF/results and next race. Every unfinished5s window stays within5%; final window may stop early. Space temporarily selects native6 without losing selected15.'},null,2));
}finally{await browser.close()}
