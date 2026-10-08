import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';import {resolve} from 'node:path';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});
const browser=await openBrowser('http://127.0.0.1:8771/tools/optimist-study.html',{headless:true,gpu:true,requestTimeoutMs:60000});
try{
 await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1000,deviceScaleFactor:1,mobile:false});
 await browser.waitFor('globalThis.studyReady===true',60000);
 await browser.evaluate('optimistStudy.renderer.setAnimationLoop(null)');
 const dimensions=await browser.evaluate(`(()=>{
  const {spec,model}=optimistStudy,{tack,throat,peak,clew}=spec.sail;
  const d=(a,b)=>Math.hypot(a[0]-b[0],a[1]-b[1]);
  const polygon=[tack,throat,peak,clew],area=Math.abs(polygon.reduce((s,a,i)=>{const b=polygon[(i+1)%4];return s+a[0]*b[1]-a[1]*b[0]},0)/2);
  const measurements={length:spec.length,beam:spec.beam,mast:spec.mastLength,luff:d(tack,throat),head:d(throat,peak),leech:d(peak,clew),diagonal:d(throat,clew),area};
  if(measurements.length!==2.36||measurements.beam!==1.12||measurements.mast!==2.26||measurements.luff>1.73||measurements.head>1.24||measurements.leech>2.8||measurements.diagonal<2.45||measurements.diagonal>2.58||Math.abs(area-3.3)>.05)throw Error('Class proportion envelope '+JSON.stringify(measurements));
  // Inspect actual emitted hull: the gunwale vertices must reach measured
  // stations. Rudder/tiller are intentionally outside the hull envelope.
  const p=model.hull.geometry.getAttribute('position');
  for(const [x,y,z] of [[.56,.32,0],[-.56,.32,0],[.38,.37,-1.18],[.47,.34,1.18]]){let found=false;for(let i=0;i<p.count;i++)if(Math.hypot(p.getX(i)-x,p.getY(i)-y,p.getZ(i)-z)<1e-5)found=true;if(!found)throw Error('Missing measured gunwale station');}
  return measurements;
 })()`);
 const rows=[];
 for(const [label,pose]of [['neutral',{trim:12,heel:0,luff:0,time:0,penalty:false}],['opposite-tack',{trim:-30,heel:-12,luff:0,time:0,penalty:false}],['luff',{trim:0,heel:0,luff:1,time:.4,penalty:false}],['penalty',{trim:12,heel:0,luff:0,time:0,penalty:true}]]){
  await browser.evaluate(`(()=>{const pose=${JSON.stringify(pose)};optimistStudy.model.update(pose);for(const [key,value]of Object.entries(pose)){const input=document.getElementById(key);if(input){if(input.type==='checkbox')input.checked=!!value;else input.value=value;}const output=document.getElementById(key+'-value');if(output)output.value=value+'°';}
   const {model,spec}=optimistStudy,p=model.rig.geometry.getAttribute('position'),r=pose.trim*Math.PI/180;
   for(const [w,h]of Object.values(spec.sail)){const expected=[Math.sin(r)*w,h+spec.tackHeight,Math.cos(r)*w+spec.mastZ];let found=false;for(let i=0;i<p.count;i++)if(Math.hypot(p.getX(i)-expected[0],p.getY(i)-expected[1],p.getZ(i)-expected[2])<1e-5)found=true;if(!found)throw Error('Sail corner lost under pose');}
   const c=model.rig.geometry.getAttribute('color');if(pose.penalty&&c.getX(0)>.05)throw Error('Penalty sail not dark');
  })()`);
  for(const view of label==='neutral'?['quarter','side','bow','stern','top','N','NE','E','SE','S','SW','W','NW']:['quarter']){
   const bearing=['N','NE','E','SE','S','SW','W','NW'].indexOf(view)*45;
   await browser.evaluate(bearing>=0?`optimistStudy.setBearing(${bearing})`:`optimistStudy.setView('${view}')`);await browser.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
   const counts=await browser.evaluate(`(()=>{const m=optimistStudy.model;const meshes=[m.hull,m.rig,m.sailor,m.window];for(const mesh of meshes)if(!Array.from(mesh.geometry.getAttribute('position').array).every(Number.isFinite))throw Error('Non-finite geometry');return meshes.map(mesh=>mesh.geometry.getAttribute('position').count/3)})()`);
   await writeFile(resolve(output,`${label}-${view}.png`),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
   rows.push({label,view,triangles:counts});
  }
 }
 await writeFile(resolve(output,'verification.json'),JSON.stringify({dimensions,rows,scope:'Isolated study: class dimension bounds, actual gunwale stations, finite geometry across poses and Chrome screenshots. No claim of live physics integration.'},null,2));console.log(JSON.stringify({dimensions,rows}));
}finally{await browser.close();}
