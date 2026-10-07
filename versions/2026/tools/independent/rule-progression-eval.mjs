// Controlled-position review probes. These exercise the actual independent
// runtime's numerical AI/dynamics/integration; they do not model naturally
// sailed routes, continuous swept crossings, or browser hull contacts.
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {makeRuntime} from './fixtures.mjs';
import {signedStartDistance} from '../../public/legacy/versions/2010-en/src/engine/ai-geometry.js';

const report={scope:'Controlled physical positions drive actual numerical routines; not naturally sailed routes or browser contacts.',ocs:[],courses:[],gates:[]};

function startProbe(clock,placement){
 const {memory:m,engine:e}=makeRuntime(),r=a=>m.readI32(a);
 const x=(r(0x536410)+r(0x4fe094))/2,y=(r(0x536414)+r(0x4fe2a0))/2;
 const wx=r(0x5229d4),wy=r(0x522ac8),d=Math.hypot(wx-x,wy-y),toward={x:(wx-x)/d,y:(wy-y)/d};
 const along={x:r(0x4fe094)-r(0x536410),y:r(0x4fe2a0)-r(0x536414)},span=Math.hypot(along.x,along.y);
 let point;
 if(placement==='early-side')point={x:x+30*toward.x,y:y+30*toward.y};
 else if(placement==='behind')point={x:x-30*toward.x,y:y-30*toward.y};
 else if(placement==='far-behind')point={x:x-3000*toward.x,y:y-3000*toward.y};
 else if(placement==='outside-span')point={x:x+3000*along.x/span,y:y+3000*along.y/span};
 else throw Error('Unknown placement');
 m.writeF64(0x5359f0,clock);m.writeI32(0x4f8cd0,clock);m.writeI32(0x5364e8,0);
 m.writeF64(0x4f6b00,point.x);m.writeF64(0x4f6c18,point.y);
 m.writeI32(0x4f853c,0);m.writeI32(0x5116e4,0);m.writeI32(0x4da1d8,3);
 const signed=signedStartDistance(m,1).toNumber();
 if(placement==='early-side')assert(signed<0);else assert(signed>0);
 e.step();
 const value={clock,placement,signed,status:r(0x5116e4),leg:r(0x4f853c),position:{x:m.readF64(0x4f6b00),y:m.readF64(0x4f6c18)}};
 const expected=placement==='early-side'&&clock>-3&&clock<1;
 assert.equal(value.status===2,expected,JSON.stringify(value));
 if(expected)assert.equal(value.leg,0,JSON.stringify(value));
 report.ocs.push(value);
}
for(const clock of[-3,-2,-1,0,1,51])startProbe(clock,'early-side');
for(const clock of[-2,0,1])for(const placement of['behind','far-behind','outside-span'])startProbe(clock,placement);

function progressProbe(command,fleet,gate){
 const {memory:m,engine:e}=makeRuntime({setupCommands:[32799,command,32789,fleet===20?32809:32806,32909],gate});
 const r=a=>m.readI32(a),seen=[];
 m.writeF64(0x5359f0,1000);m.writeI32(0x4f8cd0,1000);m.writeI32(0x5364e8,0);
 for(let n=0;n<24;n++){
  const leg=r(0x4f853c),target={x:r(0x4f4d7c),y:r(0x4fc354)};
  // Deliberately place the boat at its current numerical waypoint. This tests
  // transition ownership/flags, not navigation skill or rounding geometry.
  m.writeF64(0x4f6b00,target.x);m.writeF64(0x4f6c18,target.y);
  m.writeI32(0x4fdfec,0);m.writeF64(0x4fe188,0);
  e.step();seen.push({from:leg,to:r(0x4f853c),passed:r(0x4fe2b4),rank:r(0x4fe63c),target});
  if(r(0x4fe63c))break;
 }
 const course=r(0x4da188),value={course,fleet,gate:r(0x4da1e8),finalLeg:r(0x4da1e4),seen};
 assert.equal(r(0x4fe63c),1,JSON.stringify(value));
 assert(r(0x4f853c)>r(0x4da1e4),JSON.stringify(value));
 assert.equal(Boolean(value.gate),gate,JSON.stringify(value));
 if([2,4,5,7].includes(course))assert(seen.some(v=>v.from===7&&v.to===1&&v.passed===1),JSON.stringify(value));
 (gate?report.gates:report.courses).push(value);
}
for(const command of[32816,32817,32818,32819,32820,32992,32993])progressProbe(command,5,false);
for(const command of[32816,32817,32820,32993])progressProbe(command,20,true);
if(process.argv[2]){const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});await writeFile(resolve(output,'progression.json'),JSON.stringify({passed:true,...report},null,2));}
console.log(JSON.stringify({passed:true,ocs:report.ocs.length,courses:report.courses.length,gates:report.gates.length}));
