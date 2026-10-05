import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
if(process.argv.length!==3)throw Error('Usage: course-eval.mjs NEW_DIRECTORY');
const out=resolve(process.argv[2]);await mkdir(out);const b=await openBrowser('http://127.0.0.1:8770/?manual',{headless:true,gpu:true});
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});await b.waitFor('globalThis.tact2026?.ready',60000);
 const before=await b.evaluate('tact2026.engine.request("boundary")');
 const inspect=()=>b.evaluate(`(()=>{const s=tact2026.scene,c=s.course,v=tact2026.latest.course,p=tact2026.latest.boats[0];return {course:v,origin:c.group.position.toArray(),marks:c.marks.map(m=>({position:m.position.toArray(),visible:m.visible})),committee:c.committee.position.toArray(),pin:c.pin.position.toArray(),start:[c.start.value.a.x,0,c.start.value.a.y,c.start.value.b.x,0,c.start.value.b.y],finish:[c.finish.value.a.x,0,c.finish.value.a.y,c.finish.value.b.x,0,c.finish.value.b.y],startVisible:c.start.group.visible,finishVisible:c.finish.group.visible,laylines:c.guides.filter(l=>l.group.visible).map(l=>({visible:l.group.visible,value:l.value})),player:p,calls:s.samples.at(-1).calls};})()`);
 await b.evaluate('tact2026.camera("overview")');await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');const actual=await inspect(),v=actual.course;
 for(let i=0;i<3;i++)if(actual.marks[i].position[0]!==v.marks[i].x||actual.marks[i].position[2]!==v.marks[i].y)throw Error('Mark does not use native coordinates');
 if(actual.origin[0]!==-actual.player.x||actual.origin[2]!==-actual.player.y||actual.committee[0]!==v.committee.x||actual.pin[2]!==v.finish.b.y)throw Error('Rebase/committee/pin mismatch');
 if(actual.start[0]!==v.start.a.x||actual.start[2]!==v.start.a.y||actual.start[3]!==v.start.b.x||actual.start[5]!==v.start.b.y)throw Error('Start line mismatch');
 await writeFile(resolve(out,'overview.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 const cameraBoundary=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(cameraBoundary))throw Error('Course presentation/camera mutated native state');
 for(const type of ['keyDown','keyUp'])await b.call('Input.dispatchKeyEvent',{type,key:'l',code:'KeyL',windowsVirtualKeyCode:76});await b.waitFor('tact2026.latest.course.showLaylines',10000);await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');const laylines=await inspect();if(laylines.laylines.length)throw Error('Native prestart must not show mark rays');
 if(laylines.course.headingReference===actual.course.headingReference)throw Error('L did not change the native heading reference');
 await writeFile(resolve(out,'laylines.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 for(const type of ['keyDown','keyUp'])await b.call('Input.dispatchKeyEvent',{type,key:'l',code:'KeyL',windowsVirtualKeyCode:76});await b.waitFor('!tact2026.latest.course.showLaylines',10000);
 const after=await b.evaluate('tact2026.engine.request("boundary")');for(const key of ['frame','time','clock','rngState','shore'])if(JSON.stringify(before[key])!==JSON.stringify(after[key]))throw Error('L advanced native state');
 const fixture=await b.evaluate(`(()=>{const c=tact2026.scene.course,source=tact2026.latest.course,v={...source,finish:{a:{x:50,y:20},b:{x:180,y:100}}};c.update(v,tact2026.latest.boats[0],{x:0,y:0},10);return {start:c.start.group.visible,finish:c.finish.group.visible,positions:[c.finish.value.a.x,0,c.finish.value.a.y,c.finish.value.b.x,0,c.finish.value.b.y]};})()`);
 if(!fixture.start||!fixture.finish||fixture.positions[0]!==50||fixture.positions[5]!==100)throw Error('Distinct finish hid start or used stale endpoints');
 await b.evaluate(`(()=>{const s=tact2026.scene,p=tact2026.latest.boats[0],c=tact2026.latest.course;s.camera.position.set(c.committee.x-p.x+32,26,c.committee.y-p.y+40);s.controls.target.set(c.committee.x-p.x,3,c.committee.y-p.y);s.controls.update()})()`);await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');await writeFile(resolve(out,'committee.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,actual,laylines,fixture,before,cameraBoundary,after,scope:'Real paused native course, full boundary unchanged by presentation; trusted L changes native keyboard state without advancing paints/RNG/shore; changed finish is isolated presentation fixture'},null,2));console.log(JSON.stringify({passed:true,course:v,calls:actual.calls}));
}catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e;}finally{await b.close()}
