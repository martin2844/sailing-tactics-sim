import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';import {resolve} from 'node:path';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});
const browser=await openBrowser('http://127.0.0.1:8770/?manual&fleet=5',{headless:true,gpu:true,requestTimeoutMs:60000});const cases=[];
async function inspect(kind){
 const fixture=await tact2026.engine.request('modelcase',kind),scene=tact2026.scene;
 scene.receiveModels({generation:tact2026.latest.generation,sequence:tact2026.latest.sequence,packet:fixture.packet});
 const model=scene.models.get(1),boat=tact2026.latest.boats[0],position=model.geometry.getAttribute('position'),color=model.geometry.getAttribute('color'),Vector=scene.camera.position.constructor;
 const ray=(origin,direction)=>{
  let first=Infinity,rgb;
  for(let i=0;i<position.count;i+=3){
   const a=new Vector().fromBufferAttribute(position,i),b=new Vector().fromBufferAttribute(position,i+1),c=new Vector().fromBufferAttribute(position,i+2),ab=b.sub(a),ac=c.sub(a),p=new Vector().crossVectors(direction,ac),det=ab.dot(p);
   if(Math.abs(det)<1e-10)continue;const inverse=1/det,t=origin.clone().sub(a),u=t.dot(p)*inverse;if(u<0||u>1)continue;
   const q=new Vector().crossVectors(t,ab),v=direction.dot(q)*inverse;if(v<0||u+v>1)continue;const distance=ac.dot(q)*inverse;
   if(distance>=0&&distance<first){first=distance;rgb=[color.getX(i),color.getY(i),color.getZ(i)];}
  }return {distance:first,rgb,black:rgb?.every(v=>v<.001)??false};
 };
 const anchors=model.sailAttachments;if(!anchors.length)throw Error('No sail detail attachments '+kind);
 // Detail materials are now pale seams and metal spars. Compare the first
 // visible surface to the actual emitted detail palette, not hard-coded black.
 const detailColors=anchors.map(a=>[color.getX(a.vertex),color.getY(a.vertex),color.getZ(a.vertex)]);
 const hitsDetail=hit=>hit.rgb&&detailColors.some(rgb=>rgb.every((v,i)=>Math.abs(v-hit.rgb[i])<1e-5));
 const groups=new Map();for(const a of anchors){const key=a.faceBase+':'+a.weights.map(v=>v.toFixed(6)).join(',');if(!groups.has(key))groups.set(key,a);}
 // Each rod's two anchor centres share a face. Sample their midpoint, rather
 // than an edge endpoint where both neighbouring panels meet.
 const samples=[];for(let i=0;i<anchors.length;i+=30){const segment=anchors.slice(i,i+30),first=segment[0],other=segment.find(a=>a.weights.some((w,j)=>Math.abs(w-first.weights[j])>1e-5));if(!other)continue;samples.push({first,other});}
 const checks=[];
 for(const alpha of [0,.5,1])for(const time of [0,.4,.8]){
  // Directly exercise the actual loaded/headwind deformation and attachment
  // pass. Rig fixtures are presentation only, on the private packet's mesh.
  model.interpolate(alpha,{...boat,heading:boat.windFrom,luff:85},time);
  for(const {first,other}of samples){
   const points=[0,1,2].map(i=>new Vector().fromBufferAttribute(position,first.faceBase+i));
   const centre=new Vector();for(let i=0;i<3;i++)centre.addScaledVector(points[i],(first.weights[i]+other.weights[i])/2);
   const normal=new Vector().crossVectors(points[1].clone().sub(points[0]),points[2].clone().sub(points[0])).normalize();if(normal.lengthSq()<.5)continue;
   for(const side of [-1,1]){const hit=ray(centre.clone().addScaledVector(normal,side*.5),normal.clone().multiplyScalar(-side));if(!hitsDetail(hit))throw Error('Batten hidden behind cloth '+JSON.stringify({kind,alpha,time,side,hit,centre:centre.toArray(),points:points.map(p=>p.toArray()),first,other}));checks.push({alpha,time,side,distance:hit.distance});}
  }
 }
 model.interpolate(1);let detachedControl;
 if(kind==='normal'){
  const sample=samples[0],points=[0,1,2].map(i=>new Vector().fromBufferAttribute(position,sample.first.faceBase+i)),normal=new Vector().crossVectors(points[1].clone().sub(points[0]),points[2].clone().sub(points[0])).normalize(),centre=new Vector();for(let i=0;i<3;i++)centre.addScaledVector(points[i],(sample.first.weights[i]+sample.other.weights[i])/2);
  const original=Float32Array.from(position.array);for(const attachment of anchors){const i=attachment.vertex;position.setXYZ(i,position.getX(i)+normal.x*.1,position.getY(i)+normal.y*.1,position.getZ(i)+normal.z*.1);}
  detachedControl=ray(centre.clone().addScaledVector(normal,-.5),normal);position.array.set(original);position.needsUpdate=true;
  if(hitsDetail(detachedControl))throw Error('Visibility probe did not reject detached strokes');
 }
 return {kind,attachmentVertices:anchors.length,segments:samples.length,checks:checks.length,detachedControl};
}
async function camera(angle){
 const scene=tact2026.scene,state={...tact2026.latest,boats:tact2026.latest.boats.map((b,i)=>i?b:{...b,x:0,y:0,heading:0,windFrom:60})};scene.receive(state);scene.previous=state;scene.setPaused(true);scene.controls.dispatchEvent({type:'start'});
 for(const[id,m]of scene.models)m.group.visible=id===1;scene.labels.canvas.hidden=true;
 if(!scene.detailCourseUpdate){scene.detailCourseUpdate=scene.course.update.bind(scene.course);scene.course.update=(...args)=>{scene.detailCourseUpdate(...args);for(const child of scene.course.group.children)child.visible=false;for(const g of scene.course.guides)g.group.visible=false;scene.course.start.group.visible=false;scene.course.finish.group.visible=false;};}
 const radians=angle*Math.PI/180;scene.camera.position.set(54*Math.sin(radians),25,54*Math.cos(radians));scene.controls.target.set(0,15,0);scene.controls.update();
}
try{
 await browser.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});await browser.waitFor('globalThis.tact2026?.ready',60000);
 await browser.evaluate('document.getElementById("race-boat").value="1";document.getElementById("race-wind").dispatchEvent(new Event("change"))');await browser.waitFor('tact2026.ready&&tact2026.latest.configuration.selector===1',60000);
 const before=await browser.evaluate('tact2026.engine.request("boundary")');
 for(const kind of ['normal','trim','luff','luffNext','oppositeTack','penalty']){
  const result=await browser.evaluate('('+inspect.toString()+')('+JSON.stringify(kind)+')');cases.push(result);
  for(const angle of [45,135,225,315]){await browser.evaluate('('+camera.toString()+')('+angle+')');await browser.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');await writeFile(resolve(output,kind+'-'+angle+'.png'),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));}
 }
 const after=await browser.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Surface work changed master');
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,cases,before,after,scope:'Actual Optimist mesh from six private original rig states; independent two-sided first-hit ray/triangle tests across9 interpolation/headwind states per segment, detached-stroke negative control,24 Chrome camera screenshots and exact authoritative-state retention. No disabled depth testing or camera-facing overlays.'},null,2));console.log(JSON.stringify({passed:true,cases}));
}catch(error){await writeFile(resolve(output,'failure.json'),JSON.stringify({error:error.stack,cases},null,2));throw error;}finally{await browser.close();}
