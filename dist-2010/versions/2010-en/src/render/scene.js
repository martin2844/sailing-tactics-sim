import './screens.js';
import {createDrawingHost} from './host.js';
import {originalDrawScene,originalDrawBoat} from './drawing-functions.js';

export function drawScene(memory,dc,left,top,right,bottom,boat,options={}){
  return originalDrawScene(memory,dc,options.rng,createDrawingHost(options),left,top,right,bottom,boat);
}
export function drawBoat(memory,dc,x,y,boat,viewer,bottom,top,options={}){
  return originalDrawBoat(memory,dc,options.rng,createDrawingHost(options),x,y,boat,viewer,bottom,top);
}
