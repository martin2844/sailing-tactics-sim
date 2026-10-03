import './tutorial-controls.js';
import './scene-depth.js';
import './tutorial-pages.js';
import './screen-helper-functions.js';
import {createDrawingHost} from './host.js';
import {
  originalDrawStartScreen, originalDrawResultsScreen, originalDrawForecastScreen,
  originalDrawAdvice, originalDrawPauseScreen, originalDrawDemoScreen,
  originalDrawJibeAdvice, originalDrawTackAdvice,
} from './render-functions.js';

export function drawStartScreen(memory,dc,rng,options={}){
  return originalDrawStartScreen(memory,dc,rng,createDrawingHost(options));
}
export function drawResultsScreen(memory,dc,rng,options={}){
  return originalDrawResultsScreen(memory,dc,rng,createDrawingHost(options));
}
export function drawForecastScreen(memory,dc,rng,options={}){
  return originalDrawForecastScreen(memory,dc,rng,createDrawingHost(options));
}
export function drawPauseScreen(memory,dc,rng,options={}){
  return originalDrawPauseScreen(memory,dc,rng,createDrawingHost(options));
}
export function drawDemoScreen(memory,dc,rng,options={}){
  return originalDrawDemoScreen(memory,dc,rng,createDrawingHost(options));
}
export function drawAdvice(memory,dc,left,top,right,bottom,boat,mode,options={}){
  return originalDrawAdvice(memory,dc,options.rng,createDrawingHost(options),left,top,right,bottom,boat,mode);
}
export function drawJibeAdvice(memory,dc,top,left,lineHeight,options={}){
  return originalDrawJibeAdvice(memory,dc,options.rng,createDrawingHost(options),top,left,lineHeight);
}
export function drawTackAdvice(memory,dc,top,left,lineHeight,options={}){
  return originalDrawTackAdvice(memory,dc,options.rng,createDrawingHost(options),top,left,lineHeight);
}
