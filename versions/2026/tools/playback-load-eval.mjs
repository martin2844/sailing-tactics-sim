import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';import {resolve} from 'node:path';import {setTimeout as delay} from 'node:timers/promises';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});const b=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true,requestTimeoutMs:60000});
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});await b.waitFor('globalThis.tact2026?.ready',60000);
 await b.evaluate('document.getElementById("race-fleet").value="30";document.getElementById("race-speed").value="clock:32";document.getElementById("race-fleet").dispatchEvent(new Event("change"));document.getElementById("race-form").requestSubmit()');
 await b.waitFor('tact2026.ready&&document.getElementById("starter").hidden&&tact2026.latest.boats.length===30&&tact2026.latest.playback.selected.rate===32',60000);
 await delay(4500);const live=await b.evaluate('({time:tact2026.latest.time,playback:tact2026.latest.playback,pace:tact2026.latest.pace,numericWorkMs:tact2026.latest.workMs,snapshotWorkMs:tact2026.latest.snapshotWorkMs,status:document.getElementById("pace-state").textContent,frame:tact2026.latest.sequence})');
 if(live.playback.active.rate!==32||live.playback.selected.rate!==32||live.pace!==15||!Number.isFinite(live.playback.actualRate))throw Error('Selected rate or measurement lost under load '+JSON.stringify(live));
 if(live.playback.limited&&!live.status.includes('actual'))throw Error('Hardware-limited pace is invisible '+JSON.stringify(live));
 await b.evaluate('tact2026.engine.send("pause",true)');await b.waitFor('tact2026.paused');const before=await b.evaluate('tact2026.engine.request("boundary")');await delay(400);const after=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Pause under load advanced the numerical state');
 const receipt={passed:true,live,before,after,scope:'Chrome30-Keelboat workload at requested32×. Achieved rate is observed, not promised. The selected rate/native timestep remain unchanged; sustained processing limits are disclosed in the HUD, and pause retains the exact whole-state/RNG boundary.'};await writeFile(resolve(output,'verification.json'),JSON.stringify(receipt,null,2));console.log(JSON.stringify({passed:true,live}));
}catch(error){await writeFile(resolve(output,'failure.json'),JSON.stringify({error:error.stack},null,2));throw error;}finally{await b.close()}
