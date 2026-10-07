import test from 'node:test';import assert from 'node:assert/strict';
import {makeRuntime} from './fixtures.mjs';
import {originalUpdateCollisionAvoidance} from '../../public/legacy/versions/2010-en/src/engine/ai-functions.js';
import {withX87ControlWord} from '../../public/legacy/src/runtime/float80.js';
const pair=config=>[makeRuntime({...config,options:{optimizedNumerics:false}}),makeRuntime(config)];
function same(a,b,label){assert.deepEqual(b.memory.bytes,a.memory.bytes,label);assert.deepEqual(b.engine.random.snapshot(),a.engine.random.snapshot(),label);}

test('avoidance screening matches every memory byte/RNG through radius, wrap and grace boundaries',()=>{
 for(const fleet of[2,5,30])for(const humans of[1,2])for(const clock of[-1,0,4,5,2147483647])for(const delta of[[0,0],[0,8],[8,4],[9,0],[6,6],[7,6],[1000,500],[-2147483648,0],[-2147483648,-2147483648]]){
  const [a,b]=pair({speed:6,setupCommands:[32799,32816,32789,fleet===2?32805:fleet===5?32806:32811,32909]});
  for(const {memory:m}of[a,b]){
   m.writeI32(0x4da140,humans);m.writeI32(0x4f8cd0,clock);
   for(let id=1;id<=fleet;id++){m.writeI32(0x513480+id*4,id===1?0:delta[0]);m.writeI32(0x513510+id*4,id===1?0:delta[1]);m.writeI32(0x4fe9d0+id*4,0);m.writeI32(0x535740+id*4,720);}
  }
  for(let id=1;id<=fleet;id++){originalUpdateCollisionAvoidance(a.memory,a.engine.random.gameplay,a.engine.options,id);originalUpdateCollisionAvoidance(b.memory,b.engine.random.gameplay,b.engine.options,id);}
  same(a,b,JSON.stringify({fleet,humans,clock,delta}));
 }
});
test('unsupported precision and declared retained stacks take the original avoidance path',()=>{
 for(const word of[0x027f,0x037f])for(const stack of[undefined,{4428032:[{offset:0,bytes:'00000000'}]}])withX87ControlWord(word,()=>{
  const [a,b]=pair({speed:6});for(const item of[a,b])if(stack)item.engine.options.retainedDrawingStack=stack;
  for(let id=1;id<=5;id++){originalUpdateCollisionAvoidance(a.memory,a.engine.random.gameplay,a.engine.options,id);originalUpdateCollisionAvoidance(b.memory,b.engine.random.gameplay,b.engine.options,id);}same(a,b,JSON.stringify({word,stack}));
 });
});
test('full fixed-step sailing trajectories remain exact with accelerated avoidance across hulls and fleets',()=>{
 for(const boat of[32781,32789,32794])for(const fleet of[5,15,30]){
  const [a,b]=pair({speed:6,setupCommands:[32799,32816,boat,fleet===5?32806:fleet===15?32808:32811,32909]});
  for(let n=0;n<350;n++){
   if(n===30||n===160){a.engine.key(84);b.engine.key(84)}
   if(n===220){a.engine.key(68);b.engine.key(68)}
   a.engine.step();b.engine.step();if(n%50===49)same(a,b,JSON.stringify({boat,fleet,n}));
  }
 }
});
