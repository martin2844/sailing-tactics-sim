import {createGuideExtractor} from './native-guides';
/** Finite private fixtures checked against the full, unchanged original chart
 * and its real GDI guide emissions, including all otherwise unrelated artwork. */
export function evaluateGuideCases(context:any){
 const {memory,rng,options,objects,ModelMemory,ModelRng,TraceDc,originalGuideChart}=context;
 const cases=[
  {name:'prestart',clock:-1,angle:40,target:0},
  {name:'upwind',clock:20,angle:40,target:0},
  {name:'reach',clock:20,angle:80,target:1},
  {name:'triangle-third-mark',clock:20,angle:40,target:2},
  {name:'downwind',clock:20,angle:150,target:3},
  {name:'finish-port',clock:20,angle:150,target:3,finish:true,side:0},
  {name:'finish-starboard',clock:20,angle:150,target:3,finish:true,side:1},
  {name:'gate',clock:20,angle:150,target:3,gate:true},
  {name:'recall',clock:20,angle:40,target:0,recall:true},
  {name:'results',clock:20,angle:40,target:0,results:true},
  {name:'mark-lines-off',clock:20,angle:40,target:0,off:true},
  {name:'north-wrap-359',clock:20,angle:40,target:0,wind:359},
  {name:'north-wrap-1',clock:20,angle:40,target:0,wind:1},
  {name:'bow-oriented-chart',clock:20,angle:40,target:0,orientation:1},
  {name:'camera-oriented-chart',clock:20,angle:40,target:0,orientation:0},
 ];
 const rows=[];
 for(const fixture of cases){
  const m=new ModelMemory(memory.size,memory.base);m.bytes.set(memory.bytes);
  const owner=m.readI32(0x4da140),random=new ModelRng();random.state=rng.state;
  m.writeI32(0x4f8cd0,fixture.clock);m.writeI32(0x4fecc8+owner*4,fixture.angle);
  m.writeI32(0x4fbf10+owner*4,fixture.target);m.writeI32(0x4da184,fixture.off?0:1);
  m.writeI32(0x5363f4,fixture.results?1:0);m.writeI32(0x525a78+owner*4,fixture.orientation??2);
  if(fixture.wind!==undefined)m.writeI32(0x522b90+owner*4,fixture.wind);
  m.writeI32(0x4f8538+owner*4,fixture.finish?m.readI32(0x4da1e4):1);
  m.writeI32(0x53527c,fixture.finish?1:0);m.writeI32(0x53646c,fixture.side??0);
  m.writeI32(0x4da1e8,fixture.gate?1:0);m.writeI32(0x4f452c,fixture.gate?1:0);
  m.writeI32(0x5116e0+owner*4,fixture.recall?2:0);
  m.writeI32(0x4fe638+owner*4,0);
  // Give the gate actual, distinct native chart object coordinates.
  if(fixture.gate)for(let side=0;side<2;side++){
   const point=m.readI32(0x4da194)+6+side;
   m.writeF64(0x4f8398+point*8,side?90:-90);m.writeF64(0x4fb068+point*8,1000);
  }
  const candidate=createGuideExtractor({...context,memory:m,rng:random})();
  const original:any[]=[];
  const dc=new TraceDc({objects:new Map(objects),recordEvents:false,sink:(event:any,dc:any)=>{
   if(event.op!=='lineTo'||!new Error().stack?.includes('originalDrawing00444890'))return;
   const from={...dc.position},dx=event.x-from.x,dy=event.y-from.y;
   const orientation=m.readI32(0x525a78+owner*4),basis=m.readI32((orientation===2?0x522b90:orientation===1?0x535740:0x4fbb90)+owner*4);
   const bearing=(Math.atan2(dx,-dy)*180/Math.PI+basis+720)%360;
   original.push({from,to:{x:event.x,y:event.y},bearing});
  }});
  originalGuideChart(m,dc,random,{...options,numberRendering:true,smoothGraphics:true,rng:random},512,384,.05,0,0,1,owner,-1e8,-1e8,1e8,1e8);
  // Native may emit the same guide twice through two eligible call sites.
  const unique=original.filter((g,i)=>!original.slice(0,i).some(h=>h.from.x===g.from.x&&h.from.y===g.from.y&&Math.abs(h.bearing-g.bearing)<.02));
  const orientation=m.readI32(0x525a78+owner*4),basis=m.readI32((orientation===2?0x522b90:orientation===1?0x535740:0x4fbb90)+owner*4);
  const bx=m.readF64(0x4f6af8+owner*8),by=m.readF64(0x4f6c10+owner*8),a=basis*Math.PI/180;
  const unmatched=unique.slice();
  for(const ray of candidate){
   const x=512+.05*((ray.x-bx)*Math.cos(a)+(ray.y-by)*Math.sin(a));
   const y=384+.05*((ray.y-by)*Math.cos(a)-(ray.x-bx)*Math.sin(a));
   const index=unmatched.findIndex(g=>Math.abs(g.from.x-x)<1.1&&Math.abs(g.from.y-y)<1.1&&Math.abs(((g.bearing-ray.bearing+540)%360)-180)<.02);
   if(index<0)throw Error('Guide oracle anchor/bearing mismatch: '+fixture.name+' '+JSON.stringify({ray,x,y,original}));
   unmatched.splice(index,1);
  }
  if(unmatched.length||candidate.length!==unique.length)throw Error('Guide oracle count mismatch: '+fixture.name+' '+JSON.stringify({candidate,original}));
  rows.push({fixture,candidate,original,matched:true});
 }
 return rows;
}
