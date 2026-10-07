import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const out=resolve(process.argv[2]??'');
if(process.argv.length!==3)throw new Error('Usage: native-model-eval.mjs NEW_DIRECTORY');
await mkdir(out);
async function captureCase(kind){
 const v=await tact2026.engine.request('modelcase',kind),p=v.packet;
 const [a,b,c]=v.projections.map(v=>v.primitives);
 const points=p=>p.points??(p.op==='lineTo'?[p.from,{x:p.x,y:p.y}]:p.op==='ellipse'?[{x:p.left,y:p.top},{x:p.right,y:p.bottom}]:[]);
 let maxAffineErrorPixels=0,maxPolygonScaleErrorPixels=0,horizontalChanges=0;
 for(let i=0;i<a.length;i++){
  if(a[i].op!==b[i].op||a[i].op!==c[i].op)throw new Error('Projection topology differs');
  const aa=points(a[i]),bb=points(b[i]),cc=points(c[i]);
  for(let j=0;j<aa.length;j++){maxAffineErrorPixels=Math.max(maxAffineErrorPixels,Math.abs(aa[j].y-2*bb[j].y+cc[j].y));if(aa[j].x!==bb[j].x||aa[j].x!==cc[j].x)horizontalChanges++;}
  if(a[i].op==='polygon'){const native=points(v.unscaled.primitives[i]);for(let j=0;j<aa.length;j++)maxPolygonScaleErrorPixels=Math.max(maxPolygonScaleErrorPixels,Math.abs((aa[j].x-512)/8-(native[j].x-512)),Math.abs((aa[j].y-65536)/8-(native[j].y-65536)));}
 }
 const hash=async array=>[...new Uint8Array(await crypto.subtle.digest('SHA-256',array))].map(v=>v.toString(16).padStart(2,'0')).join('');
 const main=a.find(v=>v.op==='polygon'&&v.part===0x41ce80);
 const mastBoomLines=a.filter(v=>v.part===0x41fe70&&v.op==='lineTo'&&v.pen.color===0);
 if(mastBoomLines.length!==9)throw new Error('Native mast/boom fixture topology changed');
 // Five successive mast segments precede the articulated boom in 0x41fe70.
 const boom=mastBoomLines[5];
 const records=[];
 for(let at=0;at<p.records.length;){
  const start=at,op=p.records[at++],part=p.records[at++],fill=p.colors[p.records[at++]],stroke=p.colors[p.records[at++]],flags=p.records[at++],radius=p.records[at++],count=p.records[at++];
  at+=count+(op===3?2:0);records.push({op,part,fill,stroke,flags,radius,count,start});
 }
 const mainRecord=records.find(r=>r.op===1&&r.part===5&&r.count===9);
 if(!main||mainRecord.fill!==main.brush.color)throw new Error('Native main colour lost');
 if(maxAffineErrorPixels>4||maxPolygonScaleErrorPixels>2||horizontalChanges)throw new Error('Recovered native geometry differs beyond reviewed rounding tolerance');
 if(records.filter(r=>r.op===3&&r.part===2).length!==3)throw new Error('Native three-person crew lost');
 tact2026.scene.receiveModels({generation:tact2026.latest.generation,sequence:tact2026.latest.sequence,packet:p});
 for(const [id,model]of tact2026.scene.models)model.group.visible=id===1;
 tact2026.scene.camera.position.set(58,36,52);tact2026.scene.controls.target.set(0,17,0);tact2026.scene.controls.update();
 return {kind:v.kind,primitiveCount:a.length,mainVertices:main.points.length,mainColour:main.brush.color,boom:{from:boom.from,to:{x:boom.x,y:boom.y}},crewHeads:3,maxAffineErrorPixels,maxPolygonScaleErrorPixels,horizontalChanges,positionsSha256:await hash(p.positions),recordsSha256:await hash(p.records),modelBytes:p.positions.byteLength+p.records.byteLength+p.colors.byteLength+p.boats.byteLength,records};
}
async function compareTransport(){
 const before=await tact2026.engine.request('boundary'),a=tact2026.scene.modelPacket,b=await tact2026.engine.request('geometry');
 const matches=['positions','records','colors','boats'].every(k=>a[k].length===b[k].length&&a[k].every((v,i)=>v===b[k][i]));
 const after=await tact2026.engine.request('boundary');
 return {sequence:tact2026.latest.sequence,matches,unchanged:JSON.stringify(before)===JSON.stringify(after),boatCount:a.boats.length/3,modelBytes:a.positions.byteLength+a.records.byteLength+a.colors.byteLength+a.boats.byteLength};
}
const b=await openBrowser('http://127.0.0.1:8770/?manual',{headless:true,gpu:true,requestTimeoutMs:60000});
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});
 await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 if(await b.evaluate('tact2026.error'))throw new Error(await b.evaluate('tact2026.error'));
 const before=await b.evaluate('tact2026.engine.request("boundary")'),results=[];
 for(const kind of ['normal','penalty','trim','luff','luffNext',...Array.from({length:7},(_,i)=>'luffNext'+(i+2)),'oppositeTack','spinnaker']){
  const v=await b.evaluate('('+captureCase.toString()+')('+JSON.stringify(kind)+')');
  await b.evaluate('new Promise(resolve=>requestAnimationFrame(()=>requestAnimationFrame(resolve)))');
  await writeFile(resolve(out,kind+'.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
  results.push(v);
 }
 if(results.find(v=>v.kind==='penalty').mainColour!==0||results.find(v=>v.kind==='normal').mainColour!==0xffffff)throw new Error('Penalty sail fixture did not switch white to black');
 for(const kind of ['trim','luff','oppositeTack','spinnaker'])if(results.find(v=>v.kind===kind).positionsSha256===results[0].positionsSha256)throw new Error('Rig state did not alter 3D geometry: '+kind);
 for(const kind of ['trim','oppositeTack'])if(JSON.stringify(results.find(v=>v.kind===kind).boom)===JSON.stringify(results[0].boom))throw new Error('Native boom did not move: '+kind);
 if(new Set(results.filter(v=>v.kind.startsWith('luff')).map(v=>v.positionsSha256)).size<2)throw new Error('Native luff flutter did not change vertices');
 await b.evaluate('('+captureCase.toString()+')("normal")');
 await b.evaluate('tact2026.scene.camera.position.set(72,46,-74);tact2026.scene.controls.target.set(0,17,0);tact2026.scene.controls.update();new Promise(resolve=>requestAnimationFrame(()=>requestAnimationFrame(resolve)))');
 await writeFile(resolve(out,'crew-side.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 const after=await b.evaluate('tact2026.engine.request("boundary")');
 if(JSON.stringify(before)!==JSON.stringify(after))throw new Error('Isolated rig cases mutated authoritative state');
 const cameraBefore=await b.evaluate('tact2026.scene.camera.position.toArray()');
 const point=await b.evaluate('(()=>{const r=document.getElementById("scene").getBoundingClientRect();return {x:r.x+r.width*.6,y:r.y+r.height*.55};})()');
 await b.call('Input.dispatchMouseEvent',{type:'mouseMoved',...point});
 await b.call('Input.dispatchMouseEvent',{type:'mousePressed',button:'left',buttons:1,clickCount:1,...point});
 await b.call('Input.dispatchMouseEvent',{type:'mouseMoved',button:'left',buttons:1,x:point.x+160,y:point.y+55});
 await b.call('Input.dispatchMouseEvent',{type:'mouseReleased',button:'left',buttons:0,clickCount:1,x:point.x+160,y:point.y+55});
 const cameraAfter=await b.evaluate('tact2026.scene.camera.position.toArray()'),orbitBoundary=await b.evaluate('tact2026.engine.request("boundary")');
 if(JSON.stringify(cameraBefore)===JSON.stringify(cameraAfter)||JSON.stringify(before)!==JSON.stringify(orbitBoundary))throw new Error('Free-camera isolation failed');
 await writeFile(resolve(out,'orbit.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 const paired=[];
 for(const fleet of [5,15]){
  await b.evaluate('(()=>{const s=document.getElementById("fleet");s.value="'+fleet+'";s.dispatchEvent(new Event("change"));})()');
  await b.waitFor('tact2026.ready||tact2026.error',60000);
  for(let n=0;n<3;n++){
   if(n){await b.evaluate("tact2026.engine.send('command',"+(n===1?32842:32846)+")");await b.evaluate('tact2026.engine.request("step",8)');}
   await b.waitFor('tact2026.scene.modelSequence===tact2026.latest.sequence||tact2026.error',60000);
   const result=await b.evaluate('('+compareTransport.toString()+')()');
   if(!result.matches||!result.unchanged||result.boatCount!==fleet)throw new Error('Private state transport differs: '+JSON.stringify(result));
   paired.push({fleet,...result});
  }
 }
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Native-derived 3D geometry, source palette and isolated rig fixtures; not exact 2D raster identity or complete MVP',results,paired,before,after,freeOrbit:{cameraBefore,cameraAfter,boundary:orbitBoundary}},null,2));
 console.log(JSON.stringify({rigCases:results.length,paired:paired.length,mainColours:results.map(v=>[v.kind,v.mainColour]),freeOrbit:true}));
}catch(error){await writeFile(resolve(out,'failure.txt'),error.stack);throw error;}finally{await b.close();}
