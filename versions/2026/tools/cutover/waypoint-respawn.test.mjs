import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../../src/runtime/memory.js';
import {PoseyRng, scaledRandom} from '../../../../src/engine/integer-core.js';
import {Float80, withX87ControlWord} from '../../../../src/runtime/float80.js';
import {sinCosX87} from '../../../../src/runtime/transcendentals.js';
import {nearestWaypointDistance} from '../../../2010-en/src/engine/waypoints.js';
import {callDrawingDependency, callNumberDrawingDependencyOwned} from '../../../2010-en/src/render/dependencies.js';
import '../../../2010-en/src/render/drawing-functions.js';
import {respawnWaypoint} from '../../app/engine/waypoints/respawn.ts';
import {createWaypointPort} from '../../app/engine/compatibility/waypoint-port.ts';
const executable = await readFile(new URL('../../../2010-en/runtime/Tactics2010EnglishPreserved.exe', import.meta.url));

function image(players, heading, index) {
  const m = loadPE32(executable);
  m.writeI32(0x4da140, players);m.writeI32(0x4da1f4, 3);
  for (let boat=0;boat<=4;boat++) {
    m.writeI32(0x4fbb90+boat*4, heading);
    m.writeF64(0x4f6af8+boat*8, 200+boat*7);
    m.writeF64(0x4f6c10+boat*8, 300-boat*11);
  }
  for (let n=0;n<=3;n++) {
    m.writeF64(0x4f7220+n*8, -5000);m.writeF64(0x4ff038+n*8,-5000);
  }
  return m;
}
function numeric(memory,rng,forceAttempts) {
  let calls=0;
  return {port:createWaypointPort(memory,{
    number:Float80.fromNumber,integer:Float80.fromInteger,sinCos:sinCosX87,
    random:span=>scaledRandom(span,rng),
    nearest:(x,y,index)=>forceAttempts===undefined?nearestWaypointDistance(memory,x,y,index):Float80.fromNumber(++calls<forceAttempts?0:1000),
  })};
}

test('domain respawn matches both actual recovered drawing routes, entire image and RNG',()=>withX87ControlWord(0x027f,()=>{
  for(const players of[1,2,3])for(const index of[0,1,2,3])for(const heading of[-179,-91,-45,-1,0,1,17,45,89,91,137,179,270,359])for(const numericRoute of[false,true]){
    const a=image(players,heading,index),b=image(players,heading,index),ra=new PoseyRng(0x12345678),rb=new PoseyRng(0x12345678);
    if(numericRoute)callNumberDrawingDependencyOwned(a,undefined,0x465ff0,[index],0,ra,{numberRendering:true,smoothGraphics:false});
    else callDrawingDependency(a,undefined,0x465ff0,[index],ra,{numberRendering:false,smoothGraphics:false});
    respawnWaypoint(numeric(b,rb).port,index);
    assert.deepEqual(b.bytes,a.bytes,`players=${players},index=${index},heading=${heading},numeric=${numericRoute}`);
    assert.equal(rb.state,ra.state);
  }
}));

test('crowding retries retain bounded two/four/six draws and ordered F64 stores',()=>withX87ControlWord(0x027f,()=>{
  for(const attempts of[1,2,3]){
    const m=image(1,17,0),rng=new PoseyRng(44),writes=[],randoms=[];
    const write=m.writeF64;m.writeF64=function(a,v){writes.push(a);return write.call(this,a,v);};
    const rand=rng.rand;rng.rand=function(){randoms.push(writes.length);return rand.call(this);};
    respawnWaypoint(numeric(m,rng,attempts).port,0);
    assert.equal(randoms.length,attempts*2);
    assert.deepEqual(writes,Array.from({length:attempts},()=>[0x4f7220,0x4ff038]).flat());
    assert.deepEqual(randoms,Array.from({length:attempts*2},(_,i)=>i));
  }
}));

test('real crowded neighbors exercise all retries identically to the recovered routines',()=>withX87ControlWord(0x027f,()=>{
  for(const attempts of[1,2,3])for(const route of[false,true]){
    const first=image(1,17,0),second=image(1,17,0);
    respawnWaypoint(numeric(first,new PoseyRng(44),1).port,0);
    respawnWaypoint(numeric(second,new PoseyRng(44),2).port,0);
    const a=image(1,17,0),b=image(1,17,0);
    for(const m of[a,b]){
      if(attempts>=2){m.writeF64(0x4f7228,first.readF64(0x4f7220));m.writeF64(0x4ff040,first.readF64(0x4ff038));}
      if(attempts>=3){m.writeF64(0x4f7230,second.readF64(0x4f7220));m.writeF64(0x4ff048,second.readF64(0x4ff038));}
    }
    const ra=new PoseyRng(44),rb=new PoseyRng(44),expected=new PoseyRng(44);
    if(route)callNumberDrawingDependencyOwned(a,undefined,0x465ff0,[0],0,ra,{numberRendering:true,smoothGraphics:false});
    else callDrawingDependency(a,undefined,0x465ff0,[0],ra,{numberRendering:false,smoothGraphics:false});
    respawnWaypoint(numeric(b,rb).port,0);
    for(let n=0;n<attempts*2;n++)expected.rand();
    assert.deepEqual(a.bytes,b.bytes);assert.equal(ra.state,rb.state);assert.equal(rb.state,expected.state);
  }
}));
