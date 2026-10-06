import {test} from 'node:test';import assert from 'node:assert/strict';
import {RaceWindow} from '../app/race-window.ts';
function race(){const values=new Map([[0x4da194,5],[0x5363b0,2],[0x4da1e4,8]]);return {readI32:(a:number)=>values.get(a)??0,writeI32:(a:number,v:number)=>{values.set(a,v);}};}
test('twenty game minutes start with the first real finisher, preserve places and DNF the remainder',()=>{
 const m=race(),window=new RaceWindow();m.writeI32(0x4f8cd0,300);m.writeI32(0x4fe63c,6);window.update(m);assert.equal(window.firstFinish,undefined,'retirement is not an arrival');
 m.writeI32(0x4f8cd0,600);m.writeI32(0x4fe638+3*4,1);window.update(m);assert.equal(window.state(600).remaining,1200);
 m.writeI32(0x4f8cd0,900);m.writeI32(0x4fe638+2*4,2);window.update(m);assert.equal(window.state(900).deadline,1800);
 m.writeI32(0x4f8cd0,1799);assert.equal(window.update(m),false);assert.equal(m.readI32(0x5363f4),0);
 m.writeI32(0x4f8cd0,1800);assert.equal(window.update(m),true);assert.deepEqual([...window.dnfs],[4,5]);assert.equal(m.readI32(0x4fe638+3*4),1);assert.equal(m.readI32(0x4fe638+2*4),2);assert.equal(m.readI32(0x4fe63c),6,'retirement is retained');assert.equal(m.readI32(0x5363fc),1);window.update(m);assert.equal(m.readI32(0x5363fc),1);
});
test('pause does not consume game time, and a new race/replay clears deadline and DNFs',()=>{
 const m=race(),window=new RaceWindow();m.writeI32(0x4f8cd0,0);m.writeI32(0x4fe638+2*4,1);window.update(m);for(let n=0;n<100;n++)window.update(m);assert.equal(window.state(0).remaining,1200);
 m.writeI32(0x4f8cd0,1200);window.update(m);assert.equal(window.closedByCutoff,true);
 m.writeI32(0x4f8cd0,-170);m.writeI32(0x5363f4,0);for(let b=1;b<=5;b++)m.writeI32(0x4fe638+b*4,0);window.update(m);assert.equal(window.firstFinish,undefined);assert.equal(window.dnfs.size,0);assert.equal(window.closedByCutoff,false);
});
test('a naturally completed fleet is never completed or scored twice',()=>{
 const m=race(),window=new RaceWindow();m.writeI32(0x4f8cd0,400);for(let b=1;b<=5;b++)m.writeI32(0x4fe638+b*4,b);m.writeI32(0x5363f4,1);m.writeI32(0x5363fc,1);window.update(m);m.writeI32(0x4f8cd0,1700);window.update(m);assert.equal(window.dnfs.size,0);assert.equal(m.readI32(0x5363fc),1);
});
test('a human DNF retains the native pace for results and the next race',()=>{
 const m=race(),window=new RaceWindow();m.writeI32(0x4da140,1);m.writeI32(0x4da174,16);m.writeI32(0x4da178,31);m.writeI32(0x4f8cd0,600);m.writeI32(0x4fe638+2*4,1);window.update(m);m.writeI32(0x4f8cd0,1800);window.update(m);assert.equal(m.readI32(0x522f20),16);assert.equal(m.readI32(0x5362f0),31);
});
