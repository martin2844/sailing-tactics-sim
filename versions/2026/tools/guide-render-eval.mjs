import * as THREE from 'three';
import {ScreenCourseLine,clipCourseSegment} from '../app/screen-course-line.ts';
import {navigationTarget,relativeBearing} from '../app/navigation.ts';
import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';import {resolve} from 'node:path';
const out=resolve(process.argv[2]);await mkdir(out);const geometry=[];
const testCourse={marks:[{x:0,y:-500},{x:500,y:0},{x:50,y:0}],start:{a:{x:0,y:0},b:{x:100,y:0}},finish:{a:{x:0,y:0},b:{x:100,y:0}},target:{x:50,y:0}};
const testBoat={x:0,y:100,heading:359,status:0,finished:0};
const navigation=[
 {name:'interpolated prestart endpoint',course:{...testCourse,target:{x:20,y:0}},boat:testBoat,clock:-1,label:'Start line'},
 {name:'recall to interpolated start',course:{...testCourse,target:{x:20,y:0}},boat:{...testBoat,status:2},clock:20,label:'Return to start'},
 {name:'native third mark reused as finish',course:testCourse,boat:testBoat,clock:20,label:'Finish'},
 {name:'finished native boat',course:testCourse,boat:{...testBoat,finished:1},clock:20,label:'Finished'},
 {name:'offset AI approach uses physical mark',course:{...testCourse,target:{x:60,y:-450},navigationTarget:{x:0,y:-500,point:3,finish:false}},boat:testBoat,clock:20,label:'Mark 1'},
 {name:'coincident native marks retain selected identity',course:{...testCourse,marks:[{x:0,y:-500},{x:0,y:-500},{x:0,y:-500}],navigationTarget:{x:0,y:-500,point:4,finish:false}},boat:testBoat,clock:20,label:'Mark 2'},
 {name:'native finish override precedes coincident mark',course:{...testCourse,navigationTarget:{x:50,y:0,point:5,finish:true}},boat:testBoat,clock:20,label:'Finish'},
 {name:'recall uses native return waypoint before HUD mark',course:{...testCourse,target:{x:20,y:0},navigationTarget:{x:0,y:-500,point:3,finish:false}},boat:{...testBoat,status:2},clock:20,label:'Return to start',bearing:(Math.atan2(20,100)*180/Math.PI+360)%360},
];
for(const row of navigation){row.actual=navigationTarget(row.course,row.boat,row.clock);if(row.actual.label!==row.label||row.bearing!==undefined&&Math.abs(row.bearing-row.actual.bearing)>1e-8)throw Error('Target identity/bearing: '+row.name);}
const line=new ScreenCourseLine();
try{
 for(const depth of [35,70,500,5000,50000])for(const size of [[1280,880],[640,360],[2560,1760]]){
  const [width,height]=size,camera=new THREE.PerspectiveCamera(45,width/height,1,70000);camera.position.set(0,0,depth);camera.lookAt(0,0,0);camera.updateMatrixWorld();
  line.set({a:{x:-depth*.2,y:0},b:{x:depth*.2,y:0}},0,'#efbd52',1.8);line.project(camera,{x:0,y:0},width,height);
  for(const [layer,mesh]of line.layers.entries()){
   const p=mesh.geometry.getAttribute('position');if(mesh.geometry.drawRange.count!==6)throw Error('Visible segment lost');
   const a=new THREE.Vector3().fromBufferAttribute(p,0).project(camera),b=new THREE.Vector3().fromBufferAttribute(p,1).project(camera);
   const pixels=Math.hypot((a.x-b.x)*width/2,(a.y-b.y)*height/2),expected=1.8+(layer?0:1.5);
   if(Math.abs(pixels-expected)>.02)throw Error('Projected line width changed: '+JSON.stringify({depth,size,layer,pixels,expected}));
   geometry.push({depth,size,layer,pixels,expected});
  }
 }
 const clipCases=[
  {name:'both behind near',a:[0,0,-2,1],b:[.1,0,-3,1],visible:false},
  {name:'near crossing',a:[0,0,-2,1],b:[.5,0,0,1],visible:true},
  {name:'viewport crossing',a:[-3,0,0,1],b:[3,0,0,1],visible:true},
  {name:'outside right',a:[2,0,0,1],b:[3,1,0,1],visible:false},
  {name:'far crossing',a:[0,0,3,1],b:[0,.1,0,1],visible:true},
  {name:'eye-plane crossing',a:[0,0,-2,-1],b:[.2,.1,.5,1],visible:true},
 ];
 for(const row of clipCases){const result=clipCourseSegment(new THREE.Vector4(...row.a),new THREE.Vector4(...row.b));if(!!result!==row.visible)throw Error('Clip visibility: '+row.name);if(result?.some(v=>v.toArray().some(n=>!Number.isFinite(n)||Math.abs(n)>1.000001)))throw Error('Clip bounds: '+row.name);row.result=result?.map(v=>v.toArray());}
 const camera=new THREE.PerspectiveCamera(45,1280/880,1,70000);camera.position.set(0,20,100);camera.lookAt(0,0,0);camera.updateMatrixWorld();
 line.set({a:{x:-10000,y:0},b:{x:10000,y:0}},.7,'#ffffff',2.2,10);line.project(camera,{x:0,y:0},1280,880);const dashCounts=line.layers.map(m=>m.geometry.drawRange.count);if(dashCounts.some(n=>n<=6||n>256*6))throw Error('Dash budget or clipping');
 await writeFile(resolve(out,'geometry.json'),JSON.stringify({passed:true,geometry,clipCases,dashCounts,navigation,headingWrap:[relativeBearing(1,359),relativeBearing(359,1)]},null,2));
}finally{line.dispose();}
const b=await openBrowser('http://127.0.0.1:8770/?manual&fleet=5',{headless:true,gpu:true,requestTimeoutMs:60000});
try{
 await b.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);if(await b.evaluate('tact2026.error'))throw Error(await b.evaluate('tact2026.error'));
 const before=await b.evaluate('tact2026.engine.request("boundary")'),native=await b.evaluate('tact2026.engine.request("guidecase")'),original=await b.evaluate('tact2026.latest');
 await b.waitFor('document.getElementById("target-label").textContent==="Start line"');
 const expected=navigationTarget(original.course,original.boats[0],original.clock),hud=await b.evaluate('({label:document.getElementById("target-label").textContent,bearing:document.getElementById("target-bearing").textContent,arrow:document.getElementById("target-arrow").style.transform})');if(hud.bearing!==Math.round(expected.bearing)%360+'°')throw Error('Native-target HUD bearing');
 const hiddenArrows=await b.evaluate('(()=>{return ["target-arrow","current-arrow"].map(id=>{const e=document.getElementById(id),old=e.hidden;e.hidden=true;const display=getComputedStyle(e).display;e.hidden=old;return {id,display};});})()');if(hiddenArrows.some(r=>r.display!=='none'))throw Error('Finished/zero-current arrow cannot be hidden');
 const rows=[];
 // These source-checked guides are isolated presentation fixtures. They do not
 // fake completed race progression or modify the authoritative memory image.
 for(const name of ['upwind','reach','triangle-third-mark','downwind','finish-port','gate','recall','north-wrap-359','north-wrap-1']){
  const item=native.cases.find(c=>c.fixture.name===name);
  await b.evaluate(`(()=>{const s=tact2026.scene,v=tact2026.latest,entry=${JSON.stringify(item)},c={...v.course,guides:entry.candidate,navigationTarget:undefined};if(entry.fixture.target===0&&!entry.fixture.recall)c.target=c.marks[0];if(entry.fixture.gate){c.gate=[{x:-90,y:1000},{x:90,y:1000}];c.target={x:0,y:1000};}s.receive({...v,clock:20,course:c,boats:v.boats.map((boat,i)=>i?boat:{...boat,status:entry.fixture.recall?2:0,finished:0})});s.setCamera('overview');})()`);
  await b.evaluate('new Promise(r=>requestAnimationFrame(()=>requestAnimationFrame(r)))');
  const state=await b.evaluate(`(()=>{const s=tact2026.scene,c=s.course;return {labels:s.labels.placed,lines:c.guides.filter(l=>l.group.visible).map(l=>({value:l.value,pixelWidth:l.pixelWidth,layers:l.layers.map(m=>({depthTest:m.material.depthTest,count:m.geometry.drawRange.count,finite:Array.from(m.geometry.getAttribute('position').array.slice(0,m.geometry.drawRange.count*3)).every(Number.isFinite)}))})),calls:s.samples.at(-1).calls}})()`);
  if(state.lines.length!==item.candidate.length||state.lines.some(l=>l.layers.some(m=>!m.depthTest||!m.finite)))throw Error('Guide presentation lost native selection or depth/finite geometry: '+JSON.stringify({name,state,expected:item.candidate.length}));rows.push({name,...state});
  if(['upwind','finish-port','gate','recall'].includes(name))await writeFile(resolve(out,name+'.png'),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
 }
 await b.evaluate('tact2026.scene.receive(tact2026.latest);tact2026.camera("chase")');
 const after=await b.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Guide/indicator presentation changed master state');
 await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Independent projected-width/near/far/viewport geometry checks; nine source-checked guide presentation fixtures; native target HUD bearing and hidden-arrow styling; whole native boundary unchanged. Fixtures are not completed races.',hud,hiddenArrows,rows,before,after},null,2));console.log(JSON.stringify({passed:true,geometryCases:geometry.length,renderCases:rows.length}));
}catch(e){await writeFile(resolve(out,'failure.txt'),e.stack);throw e;}finally{await b.close();}
