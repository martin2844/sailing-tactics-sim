import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const out=resolve(process.argv[2]??''),mode=process.argv[3]??'after';
if(process.argv.length<3||!['before','after'].includes(mode))throw new Error('Usage: boat-surface-eval.mjs NEW_DIRECTORY [before|after]');await mkdir(out);
async function probe(kind){
 const fixture=await tact2026.engine.request('modelcase',kind),packet=fixture.packet;
 tact2026.scene.receiveModels({generation:tact2026.latest.generation,sequence:tact2026.latest.sequence,packet});
 const model=tact2026.scene.models.get(1);model.interpolate(1);
 for(const [id,boat]of tact2026.scene.models)boat.group.visible=id===1;
 const positions=model.geometry.getAttribute('position'),colors=model.geometry.getAttribute('color');
 const contours=[];
 for(let at=0;at<packet.records.length;){const op=packet.records[at++],part=packet.records[at++],fill=packet.colors[packet.records[at++]],stroke=packet.records[at++],flags=packet.records[at++],radius=packet.records[at++],count=packet.records[at++],points=Array.from(packet.records.slice(at,at+count),i=>Array.from(packet.positions.slice(i*3,i*3+3),v=>v/2048));at+=count+(op===3?2:0);if(op===1&&(part===1||part===4)&&fill===0x3f3f3f&&count===4)contours.push(points);}
 if(contours.length!==1)throw new Error('Missing native cockpit contour');const q=contours[0],rays=[];
 // Independent vertical ray/triangle intersection against the actual mesh,
 // classified by its uploaded source colors. No renderer diagnostics required.
 for(const u of [.2,.5,.8])for(const v of [.2,.5,.8]){
  const weights=[(1-u)*(1-v),u*(1-v),u*v,(1-u)*v],x=q.reduce((sum,p,i)=>sum+p[0]*weights[i],0),z=q.reduce((sum,p,i)=>sum+p[2]*weights[i],0),hits=[];
  for(let i=0;i<positions.count;i+=3){const ax=positions.getX(i),az=positions.getZ(i),bx=positions.getX(i+1),bz=positions.getZ(i+1),cx=positions.getX(i+2),cz=positions.getZ(i+2),den=(bz-cz)*(ax-cx)+(cx-bx)*(az-cz);if(Math.abs(den)<1e-9)continue;
    const a=((bz-cz)*(x-cx)+(cx-bx)*(z-cz))/den,b=((cz-az)*(x-cx)+(ax-cx)*(z-cz))/den,c=1-a-b;if(Math.min(a,b,c)<-1e-6)continue;
    const rgb=[colors.getX(i),colors.getY(i),colors.getZ(i)],y=a*positions.getY(i)+b*positions.getY(i+1)+c*positions.getY(i+2);
    const deck=rgb[0]>.99&&rgb[1]>.99&&rgb[2]>.2&&rgb[2]<.23,floor=rgb.every(value=>value>.048&&value<.051);if(deck||floor)hits.push({face:i/3,y,deck,floor});
  }rays.push({x,z,hits});
 }
 tact2026.scene.camera.position.set(22,38,-22);tact2026.scene.controls.target.set(0,2,0);tact2026.scene.controls.update();
 return {kind,rays,deckIntersections:rays.reduce((sum,r)=>sum+r.hits.filter(h=>h.deck).length,0),floorCoveredRays:rays.filter(r=>r.hits.some(h=>h.floor)).length,triangles:positions.count/3};
}
const browser=await openBrowser('http://127.0.0.1:8770/?manual',{headless:true,gpu:true,requestTimeoutMs:60000});
try{
 await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});await browser.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 const before=await browser.evaluate('tact2026.engine.request("boundary")'),cases=[];
 for(const kind of ['normal','trim','oppositeTack','luff']){
  const result=await browser.evaluate('('+probe.toString()+')('+JSON.stringify(kind)+')');
  if(mode==='after'&&(result.deckIntersections!==0||result.floorCoveredRays!==9))throw new Error('Cockpit still overlaps deck: '+JSON.stringify(result));
  if(mode==='before'&&result.deckIntersections===0)throw new Error('Original cockpit overlap was not reproduced');
  await browser.evaluate('new Promise(resolve=>requestAnimationFrame(()=>requestAnimationFrame(resolve)))');
  await writeFile(resolve(out,kind+'.png'),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));cases.push(result);
 }
 const after=await browser.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw new Error('Mesh inspection changed authoritative state');
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,mode,scope:'Actual mesh ray intersections inside native cockpit footprint at four rig states; expected overlap before, no deck surface across the opening after; screenshots and unchanged native state',cases,before,after},null,2));console.log(JSON.stringify(cases.map(c=>({kind:c.kind,deck:c.deckIntersections,floor:c.floorCoveredRays}))));
}catch(error){await writeFile(resolve(out,'failure.txt'),error.stack);throw error;}finally{await browser.close();}
