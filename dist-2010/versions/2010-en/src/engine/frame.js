import { add32, u32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { saveRaceState,restoreRaceState } from './snapshots.js';
import { updateGlobalWind } from './wind.js';

export const FRAME_ROUTINES = Object.freeze({
  drawSimulationFrame:0x4049f0, updateGlobalWind:0x427540, respawnWindPatch:0x42b0b0,
  updateBoatWindAndAI:0x434f70, updatePlayer1Steering:0x43df50, updatePlayer2Steering:0x43e510,
  updateBoatDynamics:0x43a030, integratePositions:0x43cf60, distanceToBoat:0x439e80,
  restoreRaceState:0x464180, saveRaceState:0x4645a0,
});

export function frameDependency(options,name) {
  const callback=options[name] ?? options.engine?.[name] ?? ({saveRaceState,restoreRaceState,updateGlobalWind})[name];
  if (typeof callback!=='function') throw new TypeError(`Original 2010 frame requires ${name} (0x${FRAME_ROUTINES[name]?.toString(16) ?? 'unknown'})`);
  return callback;
}

/** Numerical prefix of the complete 0x4049f0; all children are edition-local. */
export function advanceFrame(memory,rng,options={}) {
  options={...options,rng};
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  if (r(0x5364ac)===2) {
    options.messageBeep?.(0);
    w(0x5363b4,1);w(0x5364ac,0);w(0x53642c,1);
  }
  if (r(0x5364ac)===1) {
    frameDependency(options,'restoreRaceState')(memory,options);
    w(0x5364ac,2);
  }
  const started=typeof options.getTickCount==='function' ? u32(options.getTickCount()) : u32(options.tickStart ?? 0);
  const cursor=typeof options.getCursorPos==='function' ? options.getCursorPos() : options.cursor;
  if (!cursor || !Number.isInteger(cursor.x) || !Number.isInteger(cursor.y)) throw new TypeError('Original 2010 frame requires explicit cursor coordinates');
  w(0x4f8ee4,cursor.y);w(0x4f7f78,cursor.x);
  frameDependency(options,'updateGlobalWind')(memory,rng,options);
  for (let patch=1;patch<=5;patch++) {
    if (r(0x523630+patch*4)<r(0x4f8cd0)) frameDependency(options,'respawnWindPatch')(memory,patch,rng,options);
  }
  for (let boat=1;boat<=r(0x4da194);boat++) frameDependency(options,'updateBoatWindAndAI')(memory,boat,rng,options);
  frameDependency(options,'updatePlayer1Steering')(memory,options);
  if (r(0x4da140)===2) frameDependency(options,'updatePlayer2Steering')(memory,options);
  for (let boat=1;boat<=r(0x4da194);boat++) frameDependency(options,'updateBoatDynamics')(memory,boat,rng,options);
  if (r(0x536444)===0) frameDependency(options,'integratePositions')(memory,rng,options);
  if (r(0x4fe6c8)===r(0x4f42b8)) { frameDependency(options,'saveRaceState')(memory,options);w(0x4da1cc,0); }
  if (r(0x4f8cd0)>0 && r(0x4fe6c8)<1) { frameDependency(options,'saveRaceState')(memory,options);w(0x4da1cc,1); }
  const threshold=Float80.fromInteger(r(0x4da1e8)===1 ? 110 : 60);
  const marks=[[0x5229d4,0x522ac8],[0x522acc,0x522ae0],[0x5229c8,0x522ac4]];
  const stageRange=(first,last)=>{
    for (let stage=first;stage<=last;stage++) {
      if (r(0x4da1cc)===stage) {
        const [x,y]=marks[(stage-1)%3];
        const distance=frameDependency(options,'distanceToBoat')(memory,1,r(x),r(y),options);
        if (!(distance instanceof Float80)) throw new TypeError('Original 2010 distance must retain its extended x87 return');
        if (distance.compare(threshold)<0) w(0x536538,r(0x4f8cd0));
      }
      if (r(0x4da1cc)===stage && add32(r(0x536538),5)<r(0x4f8cd0) && r(0x536538)>0) {
        frameDependency(options,'saveRaceState')(memory,options);w(0x4da1cc,stage+1);w(0x536538,0);
      }
    }
  };
  stageRange(1,3);
  if ([2,4,5,6,7].includes(r(0x4da188))) stageRange(4,6);
  if (r(0x4da1e8)===1) {
    w(0x4f452c,1);
    if (r(0x4da188)===5) w(0x4f452c,Number(r(0x4da1cc)>4));
    if ([6,3,4].includes(r(0x4da188))) w(0x4f452c,0);
    if (r(0x4da188)===7) {
      if ((r(0x4f853c)<2 || r(0x4f853c)>7) && r(0x4fe2b4)===0 && r(0x536408)===1) w(0x4f452c,0);
      if (r(0x4f853c)>1 && r(0x4fe2b4)>0) w(0x4f452c,0);
    }
    if (r(0x4fe63c)<1) return started;
  }
  w(0x4f452c,0);
  return started;
}

/** These two stores follow all rendering and the original timing loop. */
export function finishFrame(memory) {
  memory.writeI32(0x4f7124,0);memory.writeI32(0x4f7128,0);
}

export function minimumFrameDuration(memory) {
  const level=memory.readI32(0x4da174);
  return level>=7 ? 0 : level===6 ? 30 : level===5 ? 60 : 80;
}
