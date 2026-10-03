import {drawScene,drawBoat} from './scene.js';
import {drawChart} from './chart.js';
import {drawSailingHud,drawCompactHud} from './hud.js';
import {drawStartScreen,drawResultsScreen,drawForecastScreen,drawPauseScreen,drawDemoScreen,drawAdvice,drawJibeAdvice,drawTackAdvice} from './screens.js';
import {createShoreStack} from './shore-stack.js';
export {drawScene,drawBoat,drawChart,drawSailingHud,drawCompactHud,drawStartScreen,drawResultsScreen,drawForecastScreen,drawPauseScreen,drawDemoScreen,drawAdvice,drawJibeAdvice,drawTackAdvice};

const contracts={drawScene:[drawScene,7],drawBoat:[drawBoat,8],drawChart:[drawChart,8],
  drawSailingHud:[drawSailingHud,7],drawCompactHud:[drawCompactHud,7],
  drawAdvice:[drawAdvice,8],drawJibeAdvice:[drawJibeAdvice,5],drawTackAdvice:[drawTackAdvice,5],
  drawStartScreen:[drawStartScreen,3],drawResultsScreen:[drawResultsScreen,3],
  drawForecastScreen:[drawForecastScreen,3],drawPauseScreen:[drawPauseScreen,3],drawDemoScreen:[drawDemoScreen,3]};

/** Actual edition drawing children; no old-edition or placeholder callbacks. */
export function createOriginalRenderer(sharedOptions={}){
  const shoreStack=sharedOptions.shoreStack??(sharedOptions.initialShoreStack?createShoreStack(sharedOptions.initialShoreStack):undefined);
  sharedOptions={...sharedOptions,...(shoreStack?{shoreStack}:{})};
  return Object.freeze({...Object.fromEntries(Object.entries(contracts).map(([name,[routine,index]])=>[
    name,(...args)=>routine(...args.slice(0,index),{...sharedOptions,...args[index]}),
  ])),...(shoreStack?{shoreStack}:{})});
}
