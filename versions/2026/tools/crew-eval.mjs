import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
if(process.argv.length!==3)throw new Error('Usage: crew-eval.mjs NEW_DIRECTORY');
const out=resolve(process.argv[2]);await mkdir(out);
async function inspect(kind){
 const fixture=await tact2026.engine.request('modelcase',kind),packet=fixture.packet;
 tact2026.scene.receiveModels({generation:tact2026.latest.generation,sequence:tact2026.latest.sequence,packet});
 const model=tact2026.scene.models.get(1);model.interpolate(1);model.group.updateMatrixWorld(true);
 for(const [id,boat]of tact2026.scene.models)boat.group.visible=id===1;
 const groups=[];let group=[];
 for(let at=0;at<packet.records.length;){const op=packet.records[at++],part=packet.records[at++];at+=4;const count=packet.records[at++],points=Array.from(packet.records.slice(at,at+count),i=>Array.from(packet.positions.slice(i*3,i*3+3),v=>v/2048));at+=count+(op===3?2:0);if(part===2){group.push({op,points});if(op===3){groups.push(group);group=[];}}}
 if(groups.length!==3)throw new Error('Missing native crew');
 const add=(a,b)=>a.map((v,i)=>v+b[i]),sub=(a,b)=>a.map((v,i)=>v-b[i]),scale=(a,n)=>a.map(v=>v*n),dot=(a,b)=>a.reduce((s,v,i)=>s+v*b[i],0),cross=(a,b)=>[a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]];
 const p=model.geometry.getAttribute('position'),colors=model.geometry.getAttribute('color'),vertex=i=>[p.getX(i),p.getY(i),p.getZ(i)];
 const bodies=groups.map((g,index)=>{
  const [hipA,shoulderA]=g[0].points,shoulderB=g[1].points[1],hipB=g[2].points[1],center=scale(add(add(hipA,shoulderA),add(shoulderB,hipB)),.25);
  let n=cross(sub(shoulderB,shoulderA),sub(add(shoulderA,shoulderB),add(hipA,hipB)));n=scale(n,1/Math.sqrt(dot(n,n)));
  const origin=sub(center,n),distances=[];
  // Moller–Trumbore against the actual uploaded triangles. Thin native outline
  // rods cannot cover the torso's center; a closed solid must have two walls.
  for(let i=0;i<p.count;i+=3){const a=vertex(i),edge1=sub(vertex(i+1),a),edge2=sub(vertex(i+2),a),h=cross(n,edge2),det=dot(edge1,h);if(Math.abs(det)<1e-8)continue;
   const s=sub(origin,a),u=dot(s,h)/det;if(u<0||u>1)continue;const q=cross(s,edge1),v=dot(n,q)/det;if(v<0||u+v>1)continue;
   const t=dot(edge2,q)/det;if(Math.abs(t-1)<.075&&!distances.some(d=>Math.abs(d-t)<1e-5))distances.push(t);
  }
  distances.sort((a,b)=>a-b);if(distances.length!==2||Math.abs(distances[0]-.945)>.003||Math.abs(distances[1]-1.055)>.003)throw new Error('Crew torso not solid: '+JSON.stringify({kind,index,distances}));
  return {index,distances,nativeHead:g.at(-1).points[0],nativeFeet:[g[3].points[1],g[4].points[1]]};
 });
 const palettes=new Set();for(let i=0;i<colors.count;i++)palettes.add([colors.getX(i),colors.getY(i),colors.getZ(i)].map(v=>v.toFixed(4)).join(','));
 const matrix=model.group.matrixWorld.elements,local=scale(groups[1].at(-1).points[0],1),world=[0,1,2].map(i=>matrix[i]*local[0]+matrix[i+4]*local[1]+matrix[i+8]*local[2]+matrix[i+12]);
 const scene=tact2026.scene;scene.controls.minDistance=4;scene.controls.target.set(...world);scene.camera.position.set(world[0]-5,world[1]+5,world[2]-6);scene.controls.update();
 return {kind,bodies,triangles:p.count/3,palettes:[...palettes]};
}
const browser=await openBrowser('http://127.0.0.1:8770/?manual',{headless:true,gpu:true,requestTimeoutMs:60000});
try{
 await browser.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});await browser.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 const before=await browser.evaluate('tact2026.engine.request("boundary")'),cases=[];
 for(const kind of ['normal','luff','oppositeTack','spinnaker']){
  const result=await browser.evaluate('('+inspect.toString()+')('+JSON.stringify(kind)+')');cases.push(result);
  await browser.evaluate('new Promise(resolve=>requestAnimationFrame(()=>requestAnimationFrame(resolve)))');await writeFile(resolve(out,kind+'.png'),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 }
 const after=await browser.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw new Error('Crew diagnostics changed authoritative state');
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Solid native-anchor torso coverage, three crew and close-camera screenshots at four native rig fixtures; authoritative state unchanged',cases,before,after},null,2));console.log(JSON.stringify(cases.map(c=>({kind:c.kind,solidBodies:c.bodies.length,triangles:c.triangles}))));
}catch(error){await writeFile(resolve(out,'failure.txt'),error.stack);throw error;}finally{await browser.close();}
