import * as THREE from 'three';
import {triangulateSail} from '../app/sail-triangulation.ts';
import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const out=resolve(process.argv[2]);await mkdir(out);const rows=[];
const b=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true,requestTimeoutMs:60000});
function coverage(points,faces){
 const across=points.at(-1).clone().sub(points[0]).normalize(),head=points.reduce((a,b)=>a.y>b.y?a:b).clone().sub(points[0]);head.addScaledVector(across,-head.dot(across)).normalize();
 const plane=points.map(p=>new THREE.Vector2(p.clone().sub(points[0]).dot(across),p.clone().sub(points[0]).dot(head)));
 const polygon=Math.abs(THREE.ShapeUtils.area(plane)),filled=faces.reduce((sum,f)=>sum+Math.abs(THREE.ShapeUtils.area(f.map(i=>plane[i]))),0);
 return {polygon,filled,error:Math.abs(polygon-filled)};
}
async function capture(kind){
 const fixture=await tact2026.engine.request('modelcase',kind),packet=fixture.packet;
 tact2026.scene.receiveModels({generation:tact2026.latest.generation,sequence:tact2026.latest.sequence,packet});
 const model=tact2026.scene.models.get(1);model.interpolate(1);
 let main;
 for(let at=packet.boats[1];at<packet.boats[2];){
  const op=packet.records[at++],part=packet.records[at++],fill=packet.colors[packet.records[at++]];at++;
  const flags=packet.records[at++];at++;const count=packet.records[at++];
  const points=Array.from(packet.records.slice(at,at+count),i=>Array.from(packet.positions.slice(i*3,i*3+3),v=>v/2048));at+=count+(op===3?2:0);
  if(op===1&&part===5)main={points,fill,flags};
 }
 if(!main)throw Error('Native main missing');
 const position=model.geometry.getAttribute('position'),faces=[];
 const index=vertex=>main.points.findIndex(p=>p.every((n,k)=>Math.abs(n-position.array[vertex*3+k])<1e-6));
 for(let i=0;i<position.count;i+=3){const f=[index(i),index(i+1),index(i+2)];if(f.every(v=>v>=0))faces.push(f);}
 return {kind,...main,faces,geometryVertices:position.count};
}
async function view(degrees){
 const scene=tact2026.scene,old=tact2026.latest;
 if(!scene.sailSurfaceUpdate){
  scene.sailSurfaceUpdate=scene.course.update.bind(scene.course);
  scene.course.update=(...args)=>{scene.sailSurfaceUpdate(...args);for(const child of scene.course.group.children)child.visible=false;for(const l of[scene.course.start,scene.course.finish,...scene.course.guides])l.group.visible=false;};
 }
 scene.labels.canvas.hidden=true;
 const state={...old,boats:old.boats.map((b,i)=>i?b:{...b,x:0,y:0,heading:0,windFrom:70})};
 scene.receive(state);scene.setPaused(true);scene.controls.dispatchEvent({type:'start'});
 for(const[id,m]of scene.models)m.group.visible=id===1;
 const a=degrees*Math.PI/180;scene.camera.position.set(60*Math.sin(a),28,60*Math.cos(a));scene.controls.target.set(0,15,0);scene.controls.update();
}
// Controlled legacy-surface reproduction: keep the native contour, rods and
// the rest of the actual mesh; replace only its filled main-sail triangles.
async function legacySurface(points,faces){
 const model=tact2026.scene.models.get(1),source=model.geometry,p=source.getAttribute('position'),c=source.getAttribute('color'),positions=[],colors=[];
 const index=v=>points.findIndex(p0=>p0.every((n,k)=>Math.abs(n-p.array[v*3+k])<1e-6));
 let fill;
 for(let i=0;i<p.count;i+=3){
  if([index(i),index(i+1),index(i+2)].every(v=>v>=0)){fill=Array.from(c.array.slice(i*3,i*3+3));continue;}
  positions.push(...p.array.slice(i*3,i*3+9));colors.push(...c.array.slice(i*3,i*3+9));
 }
 for(const face of faces)for(const vertex of face){positions.push(...points[vertex]);colors.push(...fill);}
 const geometry=new source.constructor();geometry.setAttribute('position',new p.constructor(Float32Array.from(positions),3));geometry.setAttribute('color',new c.constructor(Float32Array.from(colors),3));geometry.computeVertexNormals();
 model.mesh.geometry=geometry;globalThis.sailLegacyGeometry=geometry;
}
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 for(const boat of [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27]){
  await b.evaluate(`document.getElementById('race-boat').value='${boat}';document.getElementById('race-wind').dispatchEvent(new Event('change'));`);
  await b.waitFor(`tact2026.ready&&tact2026.latest.configuration.selector===${boat}||tact2026.error`,60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));
  const before=await b.evaluate('tact2026.engine.request("boundary")');
  for(const kind of boat===1?['normal','trim','luff','luffNext','oppositeTack','penalty']:boat===12?['normal','trim','luff','oppositeTack','penalty','spinnaker']:['normal']){
   const row=await b.evaluate('('+capture.toString()+')('+JSON.stringify(kind)+')'),points=row.points.map(p=>new THREE.Vector3(...p));
   const oldPlane=points.map(p=>new THREE.Vector2(p.x*Math.cos(-.6108735491753208)+p.z*Math.sin(-.6108735491753208),p.y-.3*(-p.x*Math.sin(-.6108735491753208)+p.z*Math.cos(-.6108735491753208))));
   const oldFaces=THREE.ShapeUtils.triangulateShape(oldPlane,[]);row.legacy={faces:oldFaces,coverage:coverage(points,oldFaces)};row.coverage=coverage(points,row.faces);
   if(!(row.flags&2)&&(row.faces.length!==points.length-2||row.coverage.error>1e-6))throw Error('Actual main still has gaps/overlap: '+JSON.stringify({boat,...row}));
   const orientations=[];
   if(boat===1)for(let angle=0;angle<360;angle+=5){const rotated=points.map(p=>p.clone().applyAxisAngle(new THREE.Vector3(0,1,0),angle*Math.PI/180)),faces=triangulateSail(rotated),c=coverage(rotated,faces);if(faces.length!==points.length-2||c.error>1e-6)throw Error('Orientation coverage '+kind+' '+angle);orientations.push({angle,faces:faces.length,coverage:c});}
   if(kind==='penalty'&&row.fill!==0)throw Error('Native black penalty sail lost');
   if(boat===1){
    await b.evaluate('document.getElementById("starter").hidden=true');
    for(const angle of [45,135,225,315]){
     await b.evaluate('('+view.toString()+')('+angle+')');await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
     await writeFile(resolve(out,kind+'-'+angle+'.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
    }
    if(kind==='luff'){
     if(oldFaces.length>=points.length-2||row.legacy.coverage.filled/row.legacy.coverage.polygon>.2)throw Error('Missing-panel legacy defect was not reproduced');
     await b.evaluate('('+view.toString()+')(135)');await b.evaluate('('+legacySurface.toString()+')('+JSON.stringify(row.points)+','+JSON.stringify(oldFaces)+')');await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
     await writeFile(resolve(out,'luff-legacy-135.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
     await b.evaluate('tact2026.scene.models.get(1).mesh.geometry=tact2026.scene.models.get(1).geometry;sailLegacyGeometry.dispose();delete globalThis.sailLegacyGeometry');
    }
   }
   rows.push({boat,...row,orientations});
  }
  const after=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Surface evaluation changed master');
  console.log(JSON.stringify({boat,passed:true,cases:rows.filter(r=>r.boat===boat).length}));
 }
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Actual main-mesh fill coverage on all 27 native classes in default states, six original private rig cases each for Optimist/Keelboat, 432 Optimist geometry orientation checks and 24 Chrome camera views; legacy luff surface is a controlled reproduction using the old triangulation on the same native contour. Whole native boundary unchanged per class. Not all natural race/rig combinations.',rows},null,2));
}catch(e){await writeFile(resolve(out,'failure.json'),JSON.stringify({error:e.stack,rows},null,2));throw e;}finally{await b.close();}
