import './screens.js';
import {createDrawingHost} from './host.js';
import {originalDrawSailingHud,originalDrawCompactHud} from './drawing-functions.js';

export function drawSailingHud(memory,dc,left,top,right,bottom,boat,options={}){
  return originalDrawSailingHud(memory,dc,options.rng,createDrawingHost(options),left,top,right,bottom,boat);
}
export function drawCompactHud(memory,dc,left,top,right,bottom,boat,options={}){
  return originalDrawCompactHud(memory,dc,options.rng,createDrawingHost(options),left,top,right,bottom,boat);
}
