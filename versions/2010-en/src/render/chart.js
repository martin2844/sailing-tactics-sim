import './screens.js';
import {createDrawingHost} from './host.js';
import {originalDrawChart} from './drawing-functions.js';

export function drawChart(memory,dc,left,top,right,bottom,boat,mode,options={}){
  return originalDrawChart(memory,dc,options.rng,createDrawingHost(options),left,top,right,bottom,boat,mode);
}
