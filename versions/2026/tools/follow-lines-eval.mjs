import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const out=resolve(process.argv[2]);await mkdir(out);const b=await openBrowser('http://127.0.0.1:8770/?manual',{headless:true,gpu:true});
try{
 await b.waitFor('globalThis.tact2026?.ready',60000);const before=await b.evaluate('tact2026.engine.request("boundary")');
 const fixture=await b.evaluate(`(()=>{const s=tact2026.scene,v=tact2026.latest,rows=[];s.setPaused(true);for(const heading of [0,90,180,270,359,1]){s.receive({...v,boats:v.boats.map((b,i)=>i?b:{...b,heading})});s.setCamera('chase');s.render(performance.now()+rows.length*100);rows.push({heading,position:s.camera.position.toArray()});}s.receive(v);return rows})()`);
 for(const r of fixture){const a=r.heading*Math.PI/180;if(Math.abs(r.position[0]+Math.sin(a)*170)>1e-5||Math.abs(r.position[2]-Math.cos(a)*170)>1e-5)throw Error('Camera not behind boat');}
 const after=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Camera changed physics');
 const initial=await b.evaluate('tact2026.latest.course.showMarkLines');await b.evaluate('tact2026.engine.send("command",32918)');await b.waitFor(`tact2026.latest.course.showMarkLines!==${initial}`,10000);
 if(initial){await b.evaluate('tact2026.engine.send("command",32918)');await b.waitFor('tact2026.latest.course.showMarkLines',10000);}
 await b.evaluate('tact2026.camera("overview");new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
 const lines=await b.evaluate(`(()=>{const c=tact2026.scene.course,v=tact2026.latest;return {course:v.course,wind:v.boats[0].windFrom,lines:c.markLines.map(pair=>pair.map(l=>({visible:l.visible,positions:Array.from(l.geometry.attributes.position.array)})))}})()`);
 for(let m=0;m<3;m++)for(let side=0;side<2;side++){const l=lines.lines[m][side],p=lines.course.marks[m],spread=m===0?lines.course.closeAngle:180-lines.course.downwindAngle,a=(lines.wind+(side===0?-spread:spread))*Math.PI/180;if(Math.abs(l.positions[0]-p.x)>.001||Math.abs(l.positions[2]-p.y)>.001)throw Error('Mark line origin');const angle=Math.atan2(-(l.positions[3]-p.x),l.positions[5]-p.y);if(Math.abs(Math.sin(angle-a))>1e-4)throw Error('Mark line bearing');}
 await writeFile(resolve(out,'overview.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 await b.evaluate('tact2026.camera("chase");tact2026.engine.send("command",32846);tact2026.engine.request("step",8)');
 await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');const tack=await b.evaluate('({heading:tact2026.latest.boats[0].heading,camera:tact2026.scene.camera.position.toArray()})');
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,fixture,before,after,lines,tack,scope:'Paused heading fixtures, native mark option and real native tack paints; no claim of exact legacy raster layline projection'},null,2));console.log(JSON.stringify({passed:true,tack}));
}catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e}finally{await b.close()}
