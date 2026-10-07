import {openBrowser} from '../../../tools/browser-session.js';import {mkdir,writeFile} from 'node:fs/promises';import {resolve} from 'node:path';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});
const browser=await openBrowser('http://127.0.0.1:8770/?manual&fleet=5',{headless:true,gpu:true,requestTimeoutMs:60000});
try{
 await browser.waitFor('globalThis.tact2026?.ready',60000);await browser.evaluate('document.getElementById("race-boat").value="1";document.getElementById("race-wind").dispatchEvent(new Event("change"))');await browser.waitFor('tact2026.ready&&tact2026.latest.configuration.selector===1',60000);
 const before=await browser.evaluate('tact2026.engine.request("boundary")');
 const result=await browser.evaluate(`(()=>{
  const scene=tact2026.scene,Vector=scene.camera.position.constructor,state={...tact2026.latest,boats:tact2026.latest.boats.map((b,i)=>i?b:{...b,x:0,y:0,heading:0,windFrom:60})};scene.receive(state);scene.previous=state;scene.setPaused(true);scene.controls.dispatchEvent({type:'start'});scene.camera.position.set(36,46,60);scene.controls.target.set(0,8,0);scene.controls.update();
  for(const[id,m]of scene.models)m.group.visible=id===1;scene.labels.canvas.hidden=true;
  const original=scene.course.update.bind(scene.course),line=scene.course.start,rows=[];let selectedY,drawTime=performance.now();
  scene.course.update=(...args)=>{original(...args);for(const child of scene.course.group.children)child.visible=false;for(const g of scene.course.guides)g.group.visible=false;scene.course.finish.group.visible=false;line.group.visible=true;if(selectedY===undefined)selectedY=line.y;line.set({a:{x:-30,y:0},b:{x:30,y:0}},selectedY,'#f6f9f4',2.2);};
  function read(visible){scene.models.get(1).group.visible=visible;scene.render(drawTime+=100);const p=new Vector(-2,selectedY,0).project(scene.camera),gl=scene.gl,bytes=new Uint8Array(36);gl.readPixels(Math.floor((p.x+1)*gl.drawingBufferWidth/2)-1,Math.floor((p.y+1)*gl.drawingBufferHeight/2)-1,3,3,gl.RGBA,gl.UNSIGNED_BYTE,bytes);return Array.from({length:9},(_,i)=>Array.from(bytes.slice(i*4,i*4+4)));}
  scene.render(drawTime+=100);const actual=selectedY;
  for(const y of [actual,.8]){selectedY=y;const baseline=read(false),covered=read(true);let sample=0;for(let i=1;i<9;i++)if(baseline[i].slice(0,3).reduce((a,b)=>a+b,0)>baseline[sample].slice(0,3).reduce((a,b)=>a+b,0))sample=i;const lineOnly=baseline[sample],withBoat=covered[sample];rows.push({y,lineOnly,withBoat,sample,occluded:lineOnly.some((v,i)=>Math.abs(v-withBoat[i])>8)});}
  selectedY=actual;scene.models.get(1).group.visible=true;scene.render(drawTime+=100);return {rows,actual};
 })()`);
 if(result.actual>-2||!result.rows[0].occluded||result.rows[1].occluded)throw Error('Line height/occlusion '+JSON.stringify(result));
 await writeFile(resolve(output,'water-lines.png'),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 const after=await browser.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Line fixture changed authoritative state');
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,result,before,after,scope:'Actual Chrome/WebGL2 framebuffer pixel under the Optimist hull: current water-level line is occluded by the boat; controlled old+.8 height paints over the deck. Real depth-tested course-line meshes and unchanged authoritative state.'},null,2));console.log(JSON.stringify({passed:true,result}));
}catch(error){await writeFile(resolve(output,'failure.txt'),error.stack);throw error;}finally{await browser.close();}
