import{readFile,writeFile}from'node:fs/promises';import{createHash}from'node:crypto';
import{hull,area}from'../app/contact-geometry.ts';import{BOAT_MODEL_SCALE}from'../app/world-objects.ts';
const source=await readFile(new URL('../app/generated/starter-samples.json',import.meta.url)),atlas=JSON.parse(source),boats={};
const cats=new Set([10,11,17,23]);
for(const[id,packet]of Object.entries(atlas.boats)){
 const polygons=[];for(let at=packet.boats[1];at<packet.boats[2];){const op=packet.records[at],part=packet.records[at+1],n=packet.records[at+6];if(op===1&&part===1){const points=packet.records.slice(at+7,at+7+n).map(i=>({x:packet.positions[i*3]/2048*BOAT_MODEL_SCALE,y:packet.positions[i*3+2]/2048*BOAT_MODEL_SCALE})),shape=hull(points);if(shape.length>2&&area(shape)>.01)polygons.push(shape);}at+=7+n+(op===3?2:0);}
 let parts;if(cats.has(Number(id))){const left=polygons.filter(p=>p.every(v=>v.x<0)).flat(),right=polygons.filter(p=>p.every(v=>v.x>0)).flat(),bridges=polygons.filter(p=>p.some(v=>v.x<0)&&p.some(v=>v.x>0));parts=[hull(left),hull(right),...bridges];}else parts=[hull(polygons.flat())];
 if(parts.some(p=>p.length<3)||!parts.length)throw Error('Missing rigid hull '+id);
 // A small rounded reserve covers the native heel-dependent lateral shift.
 // It is measured against live packets, not a boat-centre collision radius.
 const reserve=.35/Math.cos(Math.PI/16);
 boats[id]=parts.map(points=>({kind:'polygon',points:hull(points.flatMap(p=>Array.from({length:16},(_,i)=>({x:p.x+Math.cos(i*Math.PI/8)*reserve,y:p.y+Math.sin(i*Math.PI/8)*reserve}))))}));
}
const result={format:1,sourceSha256:createHash('sha256').update(source).digest('hex'),scale:BOAT_MODEL_SCALE,heelReserve:.35,scope:'Native rigid hull polygon faces with a 0.35-unit rounded heel reserve; compound catamaran hulls and connecting platform. Sails, crew, wakes and labels excluded.',boats};
await writeFile(new URL('../app/generated/contact-shapes.json',import.meta.url),JSON.stringify(result));console.log(JSON.stringify({boats:Object.keys(boats).length,bytes:JSON.stringify(result).length}));
