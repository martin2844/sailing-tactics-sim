import { initializeBoatOptions } from './boat-options.js';
import { initializeRace,initializeBoats } from './initialization.js';
import { initializeCourse } from './course.js';
import { projectPoint } from './spatial-metrics.js';
import { respawnWindPatch } from './wind-initialization.js';
import { updateGlobalWind } from './wind.js';
import { updatePlayer1Steering,updatePlayer2Steering } from './steering.js';
import { integratePositions } from './integration.js';
import { distanceToBoat } from './movement.js';
import { saveRaceState,restoreRaceState } from './snapshots.js';
import { updateBoatWindAndAI } from './ai.js';
import { updateBoatDynamics } from './boat-dynamics.js';

/** Edition-local callbacks shared by paint, controllers and original children. */
export function createEngineBindings(){
  return {initializeBoatOptions,initializeRace,initializeBoats,initializeCourse,projectPoint,
    respawnWindPatch,updateGlobalWind,updatePlayer1Steering,updatePlayer2Steering,
    integratePositions,distanceToBoat,saveRaceState,restoreRaceState,
    updateBoatWindAndAI,updateBoatDynamics};
}
