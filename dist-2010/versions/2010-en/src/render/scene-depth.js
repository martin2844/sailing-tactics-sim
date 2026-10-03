import {i32,add32,imul32} from '../../../../src/runtime/c-types.js';
import {registerOriginalDrawing} from './dependencies.js';

export const SCENE_DEPTH_ROUTINES=Object.freeze({sortSceneDepths:0x43f9f0,selectNearestSceneObject:0x43fa60});
export function selectNearestSceneObject(memory,rank,count,limit){
  rank=i32(rank);count=i32(count);limit=i32(limit);
  for(let object=1;object<=count;object=add32(object,1)){
    const depth=memory.readI32(add32(0x4fc160,imul32(object,4)));
    if(depth<limit){memory.writeI32(add32(0x4f4778,imul32(rank,4)),object);limit=depth;}
  }
}
export function sortSceneDepths(memory,mode){
  mode=i32(mode);let count=memory.readI32(0x4da194);
  if(mode===0)count=add32(count,memory.readI32(0x4da1e8)===1?7:5);
  for(let rank=1;rank<=count;rank=add32(rank,1)){
    selectNearestSceneObject(memory,rank,count,19000);
    const object=memory.readI32(add32(0x4f4778,imul32(rank,4)));
    memory.writeI32(add32(0x4fc160,imul32(object,4)),20000);
  }
}
registerOriginalDrawing(0x43f9f0,(memory,_dc,_rng,_options,...args)=>sortSceneDepths(memory,...args));
