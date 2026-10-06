// Analysis only: call original collision routines on disposable images.
import assert from 'node:assert/strict';
import{readFile,mkdir,writeFile}from'node:fs/promises';import{resolve}from'node:path';
import{loadOriginalData}from'../../2010-en/src/runtime/original-data.js';
import{AddressSpaceMemory}from'../../../src/runtime/memory.js';
import{PoseyRng}from'../../../src/engine/integer-core.js';
import{setX87ControlWord}from'../../../src/runtime/float80.js';
import{createCapturedTrig}from'../../2010-en/src/engine/native-trig.js';
import{initializeBoatOptions}from'../../2010-en/src/engine/boat-options.js';
import{checkNearRaceMarks,updateInterference}from'../../2010-en/src/engine/penalties.js';
const out=resolve(process.argv[2]);await mkdir(out,{recursive:true});
const data=new URL('../../2010-en/assets/data/',import.meta.url),json=async(path)=>JSON.parse(await readFile(new URL(path,data),'utf8'));
const manifest=await json('original-memory.json'),segments=new Map(await Promise.all(manifest.segments.map(async row=>[row.file,new Uint8Array(await readFile(new URL(row.file,data)))])));
const original=loadOriginalData(manifest,segments);setX87ControlWord(0x027f);
const trig=createCapturedTrig(await json('x87-trig.json'),await json('x87-stored-trig.json'));
const options={trig,playSound:()=>1};
const markFields={committee:[0x536410,0x536414],pin:[0x4fe094,0x4fe2a0],windward:[0x5229d4,0x522ac8],reach:[0x522acc,0x522ae0],leeward:[0x5229c8,0x522ac4],gateLeft:[0x4f4a68,0x4f6d34],gateRight:[0x523248,0x52359c]};
function image({boat=12,width=1024,clock=1000,leg=1}={}){
 const m=new AddressSpaceMemory(original.size,original.base);m.bytes.set(original.bytes);
 m.writeI32(0x4da144,boat);initializeBoatOptions(m);
 for(const[a,v]of[[0x4fe624,width],[0x4da194,5],[0x4da140,1],[0x4f8cd0,clock],[0x525a9c,1500],[0x53527c,0],[0x4da19c,5],[0x4da1e4,9],[0x4f452c,0],[0x536484,1]])m.writeI32(a,v);
 for(const[ax,ay]of Object.values(markFields)){m.writeI32(ax,10000+ax%1000);m.writeI32(ay,10000+ay%1000);}
 for(let b=1;b<=5;b++){
  m.writeF64(0x4f6af8+b*8,b===1?1000:10000+b*100);m.writeF64(0x4f6c10+b*8,b===1?1000:10000+b*100);
  for(const[a,v]of[[0x522ff0,b===1?-1:1],[0x535740,0],[0x522b90,90],[0x535890,90],[0x4fb380,15],[0x4fecc8,90],[0x4fae60,0],[0x4f8538,leg],[0x4fe638,0],[0x535620,0],[0x5116e0,0]])m.writeI32(a+b*4,v);
 }return m;
}
function boatProbe({dx,dy=0,heading=0,otherHeading=0,boat=12,width=1024,cooldown=0,finished=false}){
 const m=image({boat,width});m.writeF64(0x4f6af8+16,1000+dx);m.writeF64(0x4f6c10+16,1000+dy);
 m.writeI32(0x535740+4,heading);m.writeI32(0x535740+8,otherHeading);m.writeI32(0x535620+8,cooldown);m.writeI32(0x4fe638+4,Number(finished));
 updateInterference(m,1,new PoseyRng(123),options);
 return {dx,dy,heading,otherHeading,boat,width,cooldown,finished,status:m.readI32(0x5116e0+4),position:{x:m.readF64(0x4f6af8+8),y:m.readF64(0x4f6c10+8)}};
}
function markProbe(kind,dx,dy=0,clock=1000,leg=1,width=1024){
 const m=image({clock,leg,width});const[ax,ay]=markFields[kind];m.writeI32(ax,1000);m.writeI32(ay,1000);
 m.writeF64(0x4f6af8+8,1000+dx);m.writeF64(0x4f6c10+8,1000+dy);
 return {kind,dx,dy,clock,leg,width,near:checkNearRaceMarks(m,(width<901?1:0)+1,1)};
}
const boats=[boatProbe({dx:4}),boatProbe({dx:5}),boatProbe({dx:6,otherHeading:90}),boatProbe({dx:7,otherHeading:90}),boatProbe({dx:6,boat:11}),boatProbe({dx:7,boat:11}),boatProbe({dx:10}),boatProbe({dx:0,dy:-20,otherHeading:180}),boatProbe({dx:4,cooldown:980}),boatProbe({dx:4,finished:true}),boatProbe({dx:2.6,dy:2.6}),boatProbe({dx:4.8,dy:.2}),boatProbe({dx:5,width:800})];
assert.deepEqual(boats.map(v=>v.status),[4,0,4,0,4,0,0,0,0,0,4,4,4]);
const marks=[markProbe('windward',1),markProbe('windward',2),markProbe('windward',1,1),markProbe('windward',1.9),markProbe('windward',-1.1),markProbe('windward',10),markProbe('pin',4,0,0),markProbe('pin',5,0,0),markProbe('committee',0,0,0),markProbe('committee',2,0,0),markProbe('committee',0,0,11),markProbe('committee',0,0,1000,9),markProbe('committee',0,-18,0),markProbe('gateLeft',0),markProbe('gateRight',0),markProbe('leeward',0,0,0),markProbe('leeward',0,0,30),markProbe('windward',2,0,1000,1,800)];
assert.deepEqual(marks.map(v=>v.near),[1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,1,1]);
const atlas=JSON.parse(await readFile(new URL('../app/generated/starter-samples.json',import.meta.url),'utf8'));
function hull(p){const vertices=[];for(let at=p.boats[1];at<p.boats[2];){const op=p.records[at],part=p.records[at+1],count=p.records[at+6];if(part===1)for(let n=0;n<count;n++){const i=p.records[at+7+n];vertices.push({x:p.positions[i*3]/2048*4,y:p.positions[i*3+2]/2048*4});}at+=7+count+(op===3?2:0);}return vertices;}
function convex(points){const sorted=[...new Map(points.map(p=>[p.x+','+p.y,p])).values()].sort((a,b)=>a.x-b.x||a.y-b.y);const cross=(o,a,b)=>(a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);const lower=[],upper=[];for(const p of sorted){while(lower.length>=2&&cross(lower.at(-2),lower.at(-1),p)<=0)lower.pop();lower.push(p);}for(const p of sorted.toReversed()){while(upper.length>=2&&cross(upper.at(-2),upper.at(-1),p)<=0)upper.pop();upper.push(p);}lower.pop();upper.pop();return lower.concat(upper);}
const silhouettes=Object.fromEntries(Object.entries(atlas.boats).map(([id,p])=>[id,convex(hull(p))]));
const sizes=Object.entries(atlas.boats).map(([id,p])=>{const v=hull(p),x=v.map(p=>p.x),z=v.map(p=>p.y),minX=Math.min(...x),maxX=Math.max(...x),minZ=Math.min(...z),maxZ=Math.max(...z);return {id:Number(id),minX,maxX,minZ,maxZ,beam:maxX-minX,length:maxZ-minZ};});
const polygon=(points,tx=0,ty=0,rotate=false,fill='#b7d7e2')=>`<polygon points="${points.map(p=>(tx+(rotate?-p.x:p.x))+','+(ty+(rotate?-p.y:p.y))).join(' ')}" fill="${fill}" stroke="#315c73" stroke-width=".12"/>`;
const diamond=(x,y,r)=>`<polygon points="${x},${y-r} ${x+r},${y} ${x},${y+r} ${x-r},${y}" fill="#c9363630" stroke="#c93636" stroke-width=".16" stroke-dasharray=".45 .25"/>`;
const point=(x,y)=>`<circle cx="${x}" cy="${y}" r=".3" fill="#123f58"/>`;
const keel=silhouettes[12],committee=[{x:-3,y:7},{x:3,y:7},{x:3,y:-4},{x:0,y:-8},{x:-3,y:-4}];
const cards=[['Boat vs boat', 'Visible bows overlap at 20 units; OG contact threshold is 5.',polygon(keel)+polygon(keel,0,-20,true,'#ded2b5')+diamond(0,0,5)+point(0,0)+point(0,-20)],['Boat vs buoy','Bow overlaps a buoy 10 units away; OG checks the boat point.',polygon(keel)+`<circle cx="0" cy="-10" r="2.3" fill="#e9a544" stroke="#95651d" stroke-width=".12"/>`+diamond(0,-10,1)+point(0,0)],['Committee boat','Hulls overlap at 18 units; the committee test is only 1 unit.',polygon(committee,0,0,false,'#ded2b5')+polygon(keel,0,-18,true)+diamond(0,0,1)+point(0,0)+point(0,-18)],['Gate buoy','Gate centres have no direct mark-touch test.',polygon(keel)+`<circle cx="0" cy="-10" r="2.3" fill="#e9a544" stroke="#95651d" stroke-width=".12"/>`+point(0,0)]];
const svg=`<svg xmlns="http://www.w3.org/2000/svg" width="1200" height="660" viewBox="0 0 1200 660"><style>text{font-family:Arial,sans-serif;fill:#123f58}.title{font-size:24px;font-weight:bold}.note{font-size:13px}.card{font-size:17px;font-weight:bold}</style><rect width="1200" height="660" fill="#fbfaf6"/><text x="30" y="38" class="title">2026 visible hulls versus the original contact checks</text><text x="30" y="62" class="note">Blue dots: stored boat positions. Red: nominal OG Manhattan contact regions. One unit = one simulation coordinate unit.</text>${cards.map(([title,note,shape],i)=>`<rect x="${20+i*295}" y="85" width="280" height="525" rx="8" fill="#e6eff2" stroke="#c4d5dc"/><text x="${35+i*295}" y="112" class="card">${title}</text><svg x="${35+i*295}" y="135" width="250" height="405" viewBox="-12 -34 24 44">${shape}</svg><foreignObject x="${35+i*295}" y="545" width="250" height="50"><div xmlns="http://www.w3.org/1999/xhtml" style="font:14px Arial;color:#123f58;line-height:1.4">${note}</div></foreignObject>`).join('')}<text x="30" y="638" class="note">Flat hull envelopes from cached native geometry × current renderer scale. Quantization, heel, rule eligibility and cooldown add further differences.</text></svg>`;
await writeFile(resolve(out,'hitboxes.svg'),svg);
await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Analysis only; real preserved collision and mark-nearness routines on private images, all 27 cached hull envelopes in current rendered world scale. No app behavior changed; not naturally sailed impacts.',boats,marks,sizes,visualBuoyRadius:2.3,visualCommittee:{length:15,beam:6},boatMeshScale:4},null,2));
console.log(JSON.stringify({passed:true,boatCases:boats.length,markCases:marks.length,boatEnvelopes:sizes.length}));
