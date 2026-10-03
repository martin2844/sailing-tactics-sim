import { add32 } from '../runtime/index.js';
import { Float80 } from '../runtime/float80.js';
import { updateGlobalWind } from './wind.js';
import { respawnWindPatch } from './wind-initialization.js';
import { updateBoatWindAndAI } from './ai.js';
import { updatePlayer1Steering, updatePlayer2Steering } from './steering.js';
import { updateBoatDynamics } from './boat-dynamics.js';
import { integratePositions } from './integration.js';
import { distanceToBoat } from './movement-helpers.js';
import { saveRaceState, restoreRaceState } from './snapshots.js';

/** Numerical prefix of 0x404020; rendering follows before finishFrame. */
export function advanceFrame(memory, rng, options = {}) {
  options = { ...options, rng };
  if (memory.readI32(0x4ac9ec) === 2) {
    options.beep?.();memory.writeI32(0x4ac8fc,1);memory.writeI32(0x4ac9ec,0);memory.writeI32(0x4ac968,1);
  }
  if (memory.readI32(0x4ac9ec) === 1) { restoreRaceState(memory);memory.writeI32(0x4ac9ec,2); }
  if (options.cursor) { memory.writeI32(0x4a4f80,options.cursor.x);memory.writeI32(0x4a5ba0,options.cursor.y); }
  updateGlobalWind(memory,rng,options);
  for(let patch=1;patch<=5;patch++)if(memory.readI32(0x4aaa20+patch*4)<memory.readI32(0x4a5b80))respawnWindPatch(memory,patch,rng,options);
  for(let boat=1;boat<=memory.readI32(0x49118c);boat++)updateBoatWindAndAI(memory,boat,rng,options);
  updatePlayer1Steering(memory,options);
  if(memory.readI32(0x491140)===2)updatePlayer2Steering(memory,options);
  for(let boat=1;boat<=memory.readI32(0x49118c);boat++)updateBoatDynamics(memory,boat,rng,options);
  if(memory.readI32(0x4ac980)===0)integratePositions(memory,rng,options);
  if(memory.readI32(0x4a76c8)===memory.readI32(0x4a4168)) { saveRaceState(memory);memory.writeI32(0x4911c0,0); }
  if(memory.readI32(0x4a5b80)>0 && memory.readI32(0x4a76c8)<1) { saveRaceState(memory);memory.writeI32(0x4911c0,1); }
  const repeated=[2,4,5].includes(memory.readI32(0x491180));
  const marks=[[0x4aa294,0x4aa388],[0x4aa38c,0x4aa588],[0x4aa288,0x4aa384]];
  for(let stage=1;stage<=(repeated?6:3);stage++) {
    if(memory.readI32(0x4911c0)!==stage)continue;
    const [x,y]=marks[(stage-1)%3];
    if(distanceToBoat(memory,1,memory.readI32(x),memory.readI32(y)).compare(Float80.fromNumber(memory.readF64(0x484cc0)))<0)memory.writeI32(0x4ac9fc,memory.readI32(0x4a5b80));
    if(add32(memory.readI32(0x4ac9fc),5)<memory.readI32(0x4a5b80)&&memory.readI32(0x4ac9fc)>0) {
      saveRaceState(memory);memory.writeI32(0x4911c0,stage+1);memory.writeI32(0x4ac9fc,0);
    }
  }
}

/** Last two original frame stores occur after every drawing routine. */
export function finishFrame(memory) { memory.writeI32(0x4a4e7c,0);memory.writeI32(0x4a4e80,0); }

/** Original minimum paint duration; fast speed levels are hardware-limited. */
export function minimumFrameDuration(memory) {
  const level=memory.readI32(0x49116c);
  if(level>=7)return 0;
  const duration=level===6?30:level===5?60:80;
  return duration+(memory.readI32(0x4ac9a4)===1?100:0);
}
