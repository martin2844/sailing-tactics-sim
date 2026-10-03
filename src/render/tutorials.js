import { idiv32 } from '../runtime/c-types.js';
import * as basics from './tutorial-basics.js';
import * as pages from './tutorial-pages.js';

export const PAUSE_SCREEN_ROUTINE = 0x41bb40;
const order = [1,2,3,4,5,6,7,8,101,102,103,104,105,106,107,108,109,110,300,
  501,502,503,504,505,506,507,508,509,510,511,512,513,514,601,602,603,604,701,400];

/** Complete original pause/tutorial dispatcher, including its ordered selector reads. */
export function drawPauseScreen(memory, dc, rng, options = {}) {
  dc.selectStockObject(7); dc.selectStockObject(0); dc.setBkColor(0xffffff);
  const selector = memory.readI32(0x4ac980), height = memory.readI32(0x4a72d0);
  dc.rectangle(0, 0, memory.readI32(0x4a763c), selector === 2 || selector === 300 ? idiv32(height, 3) : height);
  for (const value of order) if (memory.readI32(0x4ac980) === value) {
    if (value <= 8) basics[`drawTutorial${value}`](memory, dc, options);
    else pages[`drawTutorial${value}`](memory, dc, rng, options);
  }
}
