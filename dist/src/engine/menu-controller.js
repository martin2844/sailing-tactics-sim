// Generated from original menu message maps and recovered C by tools/translate_menu_handlers.py.
// Supported statements are checked strictly; captured original instructions remain the oracle.
import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { Float80 } from '../runtime/float80.js';
import { updateSpeedDivisor } from './integer-core.js';

const commandHandlers = new Map([
  // 0x0044f760: Start          spacebar
  [32771, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8f8, i32(1));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x0044f790: Another Race             &N
  [32777, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8f8, i32(0));
    w(0x4ac93c, i32(0));
    w(0x4ac97c, i32(0));
    w(0x4ac980, i32(0));
    if (Number(i32(2) < r(0x4ac944))) {
    w(0x4ac944, i32(0));
    }
    w(0x4a5b80, r(0x4a4168));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044f7e0: No Header / Lift Info
  [32776, (memory, options, r, w, f, invalidate) => {
    w(0x4ac978, add32(r(0x4ac978), i32(1)));
    if (Number(i32(1) < r(0x4ac978))) {
    w(0x4ac978, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x0044f850: 505
  [32783, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(6));
    w(0x491188, i32(3));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044f950: America's Cup
  [32792, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(0xf));
    w(0x491188, i32(8));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044f9d0: Board
  [32881, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(3));
    w(0x491188, i32(1));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044fa50: JY15
  [32784, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(5));
    w(0x491188, i32(2));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044fad0: Keelboat
  [32789, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(0xc));
    w(0x491188, i32(6));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044fb50: Laser
  [32782, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(2));
    w(0x491188, i32(1));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044fbd0: Lightning
  [32788, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(9));
    w(0x491188, i32(5));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044fc50: Offshore Racer
  [32791, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(0xe));
    w(0x491188, i32(7));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044fcc0: Optimist
  [32781, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(1));
    w(0x491188, i32(1));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044fd40: Skiff
  [32786, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(7));
    w(0x491188, i32(3));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044fdc0: Spinnaker Catamaran
  [32794, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(0xb));
    w(0x491188, i32(10));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044fe40: Sport Boat
  [32790, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(0xd));
    w(0x491188, i32(7));
    w(0x4ac908, i32(1));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044fed0: Thistle
  [32787, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(8));
    w(0x491188, i32(4));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x0044ff50: Tornado Catamaran
  [32793, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(10));
    w(0x491188, i32(9));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x004500a0: 10
  [32807, (memory, options, r, w, f, invalidate) => {
    w(0x49118c, i32(10));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450120: 15
  [32808, (memory, options, r, w, f, invalidate) => {
    w(0x49118c, i32(0xf));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004501a0: 20
  [32809, (memory, options, r, w, f, invalidate) => {
    w(0x49118c, i32(0x14));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450220: 25
  [32810, (memory, options, r, w, f, invalidate) => {
    w(0x49118c, i32(0x19));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004502a0: 2  Match Racing
  [32805, (memory, options, r, w, f, invalidate) => {
    w(0x49118c, i32(2));
    if (Number(i32(5) < r(0x4911cc))) {
    w(0x4911cc, i32(5));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450320: 30
  [32811, (memory, options, r, w, f, invalidate) => {
    w(0x49118c, i32(0x1e));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004503a0: 5
  [32806, (memory, options, r, w, f, invalidate) => {
    w(0x49118c, i32(5));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450420: No Series Scoring.
  [32824, (memory, options, r, w, f, invalidate) => {
    w(0x4ac960, add32(r(0x4ac960), i32(1)));
    if (Number(i32(1) < r(0x4ac960))) {
    w(0x4ac960, i32(0));
    }
    return;
  }],
  // 0x00450480: One Player
  [32778, (memory, options, r, w, f, invalidate) => {
    w(0x491140, i32(1));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004504f0: Gold Cup
  [32820, (memory, options, r, w, f, invalidate) => {
    w(0x491160, i32(0));
    w(0x4ac940, i32(1));
    w(0x4ac950, i32(1));
    w(0x491180, i32(5));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004505a0: Triangle
  [32818, (memory, options, r, w, f, invalidate) => {
    w(0x491180, i32(3));
    w(0x491160, i32(0));
    w(0x4ac940, i32(0));
    w(0x4ac950, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450630: Triangle Twice Around
  [32819, (memory, options, r, w, f, invalidate) => {
    w(0x4ac950, i32(1));
    w(0x491160, i32(0));
    w(0x4ac940, i32(0));
    w(0x491180, i32(4));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004506d0: Windward / Leeward
  [32816, (memory, options, r, w, f, invalidate) => {
    w(0x491160, i32(1));
    w(0x4ac940, i32(0));
    w(0x4ac950, i32(0));
    w(0x491180, i32(1));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450770: Windward / Leeward Twice Around
  [32817, (memory, options, r, w, f, invalidate) => {
    w(0x491160, i32(1));
    w(0x4ac940, i32(0));
    w(0x4ac950, i32(1));
    w(0x491180, i32(2));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450820: Distance Race - Along Shore
  [32802, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(8));
    w(0x4ac940, i32(0));
    w(0x4ac950, i32(0));
    w(0x4ac954, i32(0));
    w(0x4a5a4c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004508c0: Round Lake
  [32799, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(5));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450930: River Mouth North
  [32803, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(9));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004509a0: River Mouth South
  [32804, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(10));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450a10: Round the Island
  [32801, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(7));
    w(0x491160, i32(0));
    w(0x4ac940, i32(0));
    w(0x4ac954, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450a90: Shoreline to the East
  [32796, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(2));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450b00: Shoreline to the North
  [32795, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(1));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450b70: Shoreline to the South
  [32797, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(3));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450be0: Shoreline to the West
  [32798, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(4));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450c50: Sound
  [32800, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(6));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450cc0: Short Course
  [32821, (memory, options, r, w, f, invalidate) => {
    w(0x4ac954, add32(r(0x4ac954), i32(1)));
    if (Number(i32(1) < r(0x4ac954))) {
    w(0x4ac954, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450d40: Tidal Currents
  [32815, (memory, options, r, w, f, invalidate) => {
    w(0x491158, add32(r(0x491158), i32(1)));
    if (Number(i32(1) < r(0x491158))) {
    w(0x491158, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450e80: Wheel Steering
  [32822, (memory, options, r, w, f, invalidate) => {
    w(0x49114c, sub32(0, r(0x49114c)));
    invalidate(i32(0));
    return;
  }],
  // 0x00450ef0: Light
  [32812, (memory, options, r, w, f, invalidate) => {
    w(0x491154, i32(1));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450f60: Moderate
  [32813, (memory, options, r, w, f, invalidate) => {
    w(0x491154, i32(2));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00450fd0: Strong
  [32814, (memory, options, r, w, f, invalidate) => {
    w(0x491154, i32(3));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00451040: 1
  [32882, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(1));
    w(0x4ac8fc, i32(0));
    return;
  }],
  // 0x004510a0: 10
  [32891, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(10));
    return;
  }],
  // 0x004510f0: 11
  [32892, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(0xb));
    return;
  }],
  // 0x00451140: 12
  [32893, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(0xc));
    return;
  }],
  // 0x00451190: 13
  [32894, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(0xd));
    return;
  }],
  // 0x004511e0: 14
  [32895, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(0xe));
    return;
  }],
  // 0x00451230: 15
  [32896, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(0xf));
    return;
  }],
  // 0x00451280: 2
  [32883, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(2));
    return;
  }],
  // 0x004512d0: 3
  [32884, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(3));
    return;
  }],
  // 0x00451320: 4
  [32885, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(4));
    return;
  }],
  // 0x00451370: 5
  [32886, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(5));
    return;
  }],
  // 0x004513c0: 6
  [32887, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(6));
    return;
  }],
  // 0x00451410: 7
  [32888, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(7));
    return;
  }],
  // 0x00451460: 8
  [32889, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(8));
    return;
  }],
  // 0x004514b0: 9
  [32890, (memory, options, r, w, f, invalidate) => {
    w(0x491190, i32(9));
    return;
  }],
  // 0x0044f8d0: Snipe
  [32897, (memory, options, r, w, f, invalidate) => {
    w(0x491144, i32(4));
    w(0x491188, i32(2));
    w(0x4ac908, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    return;
  }],
  // 0x00451500: Close in View             &1
  [32825, (memory, options, r, w, f, invalidate) => {
    w(0x4a4e8c, i32(1));
    w(0x4aae24, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00451570: High Viewpoint           &3
  [32827, (memory, options, r, w, f, invalidate) => {
    w(0x4a4e8c, i32(3));
    w(0x4aae24, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004515e0: Wide View                  &2
  [32826, (memory, options, r, w, f, invalidate) => {
    w(0x4a4e8c, i32(2));
    w(0x4aae24, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00451650: Look Ahead      up arrow
  [32828, (memory, options, r, w, f, invalidate) => {
    w(0x4a460c, i32(0));
    w(0x4a9444, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00451670: Look Astern      down arrow
  [32831, (memory, options, r, w, f, invalidate) => {
    w(0x4a460c, i32(0xb4));
    w(0x4a9444, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004516a0: Look Left          left arrow
  [32830, (memory, options, r, w, f, invalidate) => {
    w(0x4a460c, add32(r(0x4a460c), i32(0x1e)));
    w(0x4a9444, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004516d0: Look Right        right arrow
  [32829, (memory, options, r, w, f, invalidate) => {
    w(0x4a460c, add32(r(0x4a460c), sub32(0, i32(0x1e))));
    w(0x4a9444, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00451700: Weather Forecast      &W
  [32907, (memory, options, r, w, f, invalidate) => {
    w(0x4ac938, add32(r(0x4ac938), i32(1)));
    if (Number(i32(1) < r(0x4ac938))) {
    w(0x4ac938, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(1));
    w(0x4ac94c, i32(0));
    w(0x4aa980, i32(0));
    w(0x4ac980, i32(0));
    w(0x4a60a8, i32(1));
    return;
  }],
  // 0x00451750: Marks to Starboard
  [32908, (memory, options, r, w, f, invalidate) => {
    w(0x4ac9a8, add32(r(0x4ac9a8), i32(1)));
    if (Number(i32(1) < r(0x4ac9a8))) {
    w(0x4ac9a8, i32(0));
    }
    return;
  }],
  // 0x00452610: Race Course           &R
  [32905, (memory, options, r, w, f, invalidate) => {
    let bVar1;
    let hWnd;
    w(0x4aa980, add32(r(0x4aa980), i32(1)));
    bVar1 = Number(r(0x4aa980) != i32(1));
    if (Number(i32(1) < r(0x4aa980))) {
    w(0x4aa980, i32(0));
    }
    if (bVar1) {
    hWnd = options.windowHandle ?? 0;
    }
    else {
    hWnd = options.windowHandle ?? 0;
    }
    w(0x4ac8fc, Number(!(bVar1)));
    invalidate(i32(0));
    w(0x4ac94c, i32(0));
    w(0x4ac970, i32(0));
    w(0x4ac974, i32(0));
    w(0x4ac938, i32(0));
    return;
  }],
  // 0x004526b0: Automatic Sheet (max speed)     &A
  [32850, (memory, options, r, w, f, invalidate) => {
    w(0x4a85d4, i32(0xffffffff));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452720: Max Luff                                      &S
  [32851, (memory, options, r, w, f, invalidate) => {
    w(0x4a85d4, i32(0x5a));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004528f0: 10 to Port               <  or Left Click
  [32842, (memory, options, r, w, f, invalidate) => {
    memory.writeF64(0x4a78e8, f(0x4a78e8).subtract(f(0x484d58)).toNumber());
    w(0x4a8914, i32(0));
    w(0x4a496c, i32(0));
    w(0x4a684c, i32(0));
    w(0x4a4dfc, i32(0));
    w(0x4abf9c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452930: 10 to Starboard      >  or Right Click
  [32841, (memory, options, r, w, f, invalidate) => {
    memory.writeF64(0x4a78e8, f(0x4a78e8).subtract(f(0x484d60)).toNumber());
    w(0x4a8914, i32(0));
    w(0x4a496c, i32(0));
    w(0x4a684c, i32(0));
    w(0x4a4dfc, i32(0));
    w(0x4abf9c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452970: Closehauled       &C
  [32843, (memory, options, r, w, f, invalidate) => {
    w(0x4a4dfc, i32(0xffffffff));
    w(0x4ac1ec, i32(0));
    w(0x4a8914, i32(0));
    w(0x4a496c, i32(0));
    w(0x4a684c, i32(0));
    w(0x4abf9c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452a00: Reach        &H
  [32849, (memory, options, r, w, f, invalidate) => {
    w(0x4a684c, add32(Number(i32(0x5a) < r(0x4a7bcc)), i32(2)));
    w(0x4a8914, i32(0));
    w(0x4a496c, i32(0));
    w(0x4a4dfc, i32(0));
    w(0x4abf9c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452a40: Foot                     +
  [32845, (memory, options, r, w, f, invalidate) => {
    w(0x4ac1ec, i32(5));
    w(0x4a8914, i32(1));
    w(0x4a496c, i32(0));
    w(0x4a684c, i32(0));
    w(0x4a4dfc, i32(0));
    w(0x4abf9c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452ad0: Jibe                        &J
  [32847, (memory, options, r, w, f, invalidate) => {
    w(0x4abf9c, i32(1));
    w(0x4a8914, i32(0));
    w(0x4a496c, i32(0));
    w(0x4a684c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    w(0x4a4dfc, i32(0));
    return;
  }],
  // 0x00452b10: Pinch                   -
  [32844, (memory, options, r, w, f, invalidate) => {
    w(0x4ac1ec, i32(0xfffffffb));
    w(0x4a8914, i32(1));
    w(0x4a496c, i32(0));
    w(0x4a684c, i32(0));
    w(0x4a4dfc, i32(0));
    w(0x4abf9c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452ba0: Tack           &T
  [32846, (memory, options, r, w, f, invalidate) => {
    w(0x4a4dfc, i32(1));
    w(0x4a46ac, i32(1));
    w(0x4a41f4, r(0x4a5b80));
    w(0x4abf9c, i32(0));
    w(0x4a8914, i32(0));
    w(0x4a496c, i32(0));
    w(0x4a684c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452c10: Run  Downwind     &D
  [32848, (memory, options, r, w, f, invalidate) => {
    w(0x4a684c, i32(1));
    w(0x4a8914, i32(0));
    w(0x4a496c, i32(0));
    w(0x4a4dfc, i32(0));
    w(0x4abf9c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452c90: &1   slowest
  [32872, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(1));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452cf0: &2
  [32873, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(2));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452d50: &3
  [32874, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(3));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452db0: &4
  [32875, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(4));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452e10: &5
  [32876, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(5));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452e70: &6
  [32877, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(6));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452ed0: &7
  [32878, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(7));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452f30: &8
  [32879, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(8));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452f90: &9
  [32880, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(9));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00452ff0: 1&0 
  [32909, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(10));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004532e0: Look to Leeward        &7
  [32833, (memory, options, r, w, f, invalidate) => {
    w(0x4a9444, i32(0xffffffff));
    w(0x4a460c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453350: Look to Windward      &5
  [32832, (memory, options, r, w, f, invalidate) => {
    w(0x4a9444, i32(1));
    w(0x4a460c, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004533c0: Sheet In 20%                   &I
  [32852, (memory, options, r, w, f, invalidate) => {
    w(0x4a85d4, add32(r(0x4a85d4), sub32(0, i32(0x14))));
    if (Number(r(0x4a85d4) < i32(0))) {
    w(0x4a85d4, sub32(0, i32(1)));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453400: Sheet Out 20%                &O
  [32853, (memory, options, r, w, f, invalidate) => {
    w(0x4a85d4, add32(r(0x4a85d4), i32(0x14)));
    if (Number(i32(0x5a) < r(0x4a85d4))) {
    w(0x4a85d4, i32(0x5a));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453440: #1 Genoa
  [32859, (memory, options, r, w, f, invalidate) => {
    w(0x4a4efc, i32(1));
    w(0x4a4388, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004534d0: #2 Genoa
  [32860, (memory, options, r, w, f, invalidate) => {
    w(0x4a4efc, i32(2));
    w(0x4a4388, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453570: #3 Blade
  [32861, (memory, options, r, w, f, invalidate) => {
    w(0x4a4efc, i32(3));
    w(0x4a4388, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453610: Baggy                 F3
  [32856, (memory, options, r, w, f, invalidate) => {
    w(0x4a776c, i32(3));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453670: Flat                     F1
  [32854, (memory, options, r, w, f, invalidate) => {
    w(0x4a776c, i32(1));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004536d0: Medium              F2
  [32855, (memory, options, r, w, f, invalidate) => {
    w(0x4a776c, i32(2));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453730: Spin Down           P
  [32858, (memory, options, r, w, f, invalidate) => {
    w(0x4a4388, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453790: Spin Up (wing)     &P
  [32857, (memory, options, r, w, f, invalidate) => {
    w(0x4a4388, add32(r(0x4a4388), i32(1)));
    if (Number(i32(1) < r(0x4a4388))) {
    w(0x4a4388, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453800: Freeze                       F
  [32910, (memory, options, r, w, f, invalidate) => {
    w(0x4ac968, add32(r(0x4ac968), i32(1)));
    if (Number(i32(1) < r(0x4ac968))) {
    w(0x4ac968, i32(0));
    }
    if (Number(r(0x4ac968) == i32(0))) {
    w(0x4ac8fc, r(0x4ac968));
    invalidate(i32(0));
    return;
    }
    w(0x4ac8fc, i32(1));
    return;
  }],
  // 0x00453880: Wind Chart             [
  [32902, (memory, options, r, w, f, invalidate) => {
    w(0x4ac970, add32(r(0x4ac970), i32(1)));
    if (Number(i32(1) < r(0x4ac970))) {
    w(0x4ac970, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    w(0x4ac974, i32(0));
    w(0x4aa980, i32(0));
    w(0x4ac938, i32(0));
    w(0x4ac94c, i32(0));
    w(0x4ac980, i32(0));
    return;
  }],
  // 0x00453910: Tide Chart               ]    
  [32903, (memory, options, r, w, f, invalidate) => {
    w(0x4ac974, add32(r(0x4ac974), i32(1)));
    if (Number(i32(1) < r(0x4ac974))) {
    w(0x4ac974, i32(0));
    }
    w(0x4ac970, i32(0));
    w(0x4aa980, i32(0));
    w(0x4ac938, i32(0));
    w(0x4ac94c, i32(0));
    w(0x4ac980, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004539a0: Tide @ +1 hour      +
  [32904, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(0));
    w(0x4ac94c, add32(r(0x4ac94c), i32(1)));
    invalidate(i32(0));
    return;
  }],
  // 0x00453a00: Change Viewpoint      &V
  [32912, (memory, options, r, w, f, invalidate) => {
    w(0x4a4e8c, add32(r(0x4a4e8c), i32(1)));
    if (Number(i32(3) < r(0x4a4e8c))) {
    w(0x4a4e8c, i32(1));
    }
    w(0x4aae24, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453a60: Look at Other Boat     &9
  [32834, (memory, options, r, w, f, invalidate) => {
    w(0x4a9444, i32(100));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453ae0: Hide Sails                   &U
  [32913, (memory, options, r, w, f, invalidate) => {
    w(0x4a40c4, add32(r(0x4a40c4), i32(1)));
    if (Number(i32(1) < r(0x4a40c4))) {
    w(0x4a40c4, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453b50: Bow Up Orientation
  [32914, (memory, options, r, w, f, invalidate) => {
    w(0x4ab164, i32(1));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453bc0: Wind Up Orientation
  [32916, (memory, options, r, w, f, invalidate) => {
    w(0x4ab164, i32(2));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453c30: Show Tracks          ~
  [32919, (memory, options, r, w, f, invalidate) => {
    w(0x4ac958, add32(r(0x4ac958), i32(1)));
    if (Number(i32(1) < r(0x4ac958))) {
    w(0x4ac958, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453ca0: Show laylines, Equal Line
  [32918, (memory, options, r, w, f, invalidate) => {
    w(0x49117c, add32(r(0x49117c), i32(1)));
    if (Number(i32(1) < r(0x49117c))) {
    w(0x49117c, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453d10: Same Orientation as Sailing View
  [32915, (memory, options, r, w, f, invalidate) => {
    w(0x4ab164, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453d70: Simulator Operation
  [32862, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(0));
    w(0x4ac980, i32(1));
    w(0x4ac984, i32(1));
    invalidate(i32(0));
    return;
  }],
  // 0x00453de0: What You See (Sailing Views)
  [32924, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(0));
    w(0x4ac980, i32(2));
    w(0x4ac984, i32(2));
    invalidate(i32(0));
    return;
  }],
  // 0x00453e70: View Control
  [32864, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(0));
    w(0x4ac980, i32(3));
    w(0x4ac984, i32(3));
    invalidate(i32(0));
    return;
  }],
  // 0x00453ee0: Steering
  [32865, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(0));
    w(0x4ac980, i32(4));
    w(0x4ac984, i32(4));
    invalidate(i32(0));
    return;
  }],
  // 0x00453f50: Sail Control
  [32866, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(0));
    w(0x4ac980, i32(5));
    w(0x4ac984, i32(5));
    invalidate(i32(0));
    return;
  }],
  // 0x00453fc0: Automatic View           &0
  [32835, (memory, options, r, w, f, invalidate) => {
    w(0x4aae24, add32(r(0x4aae24), i32(1)));
    if (Number(i32(1) < r(0x4aae24))) {
    w(0x4aae24, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00454030: Key Command Summary      &?
  [32925, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(0));
    w(0x4ac980, i32(6));
    w(0x4ac984, i32(6));
    invalidate(i32(0));
    return;
  }],
  // 0x004540a0: Night Race
  [32927, (memory, options, r, w, f, invalidate) => {
    let bVar1;
    w(0x4ac990, add32(r(0x4ac990), i32(1)));
    bVar1 = Number(r(0x4ac990) == i32(1));
    if (Number(i32(1) < r(0x4ac990))) {
    w(0x4ac990, i32(0));
    }
    if (bVar1) {
    w(0x4ac98c, i32(1));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00454130: Introduction
  [32928, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x65));
    w(0x4ac984, i32(0x65));
    invalidate(i32(0));
    return;
  }],
  // 0x004541a0: Same Tack
  [32929, (memory, options, r, w, f, invalidate) => {
    w(0x4ac980, i32(0x67));
    w(0x4ac984, i32(0x67));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    w(0x4ac8fc, i32(1));
    return;
  }],
  // 0x00454230: Opposite Tacks
  [32931, (memory, options, r, w, f, invalidate) => {
    w(0x4ac980, i32(0x66));
    w(0x4ac984, i32(0x66));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    w(0x4ac8fc, i32(1));
    return;
  }],
  // 0x004542b0: Overtaking
  [32930, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x68));
    w(0x4ac984, i32(0x68));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454340: Marks and Obstructions
  [32932, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x69));
    w(0x4ac984, i32(0x69));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x004543d0: Rounding a Windward Mark
  [32933, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x6a));
    w(0x4ac984, i32(0x6a));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454460: Tacking for Obstructions
  [32934, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x6b));
    w(0x4ac984, i32(0x6b));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x004544f0: Same Tack Before Starting
  [32935, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x6c));
    w(0x4ac984, i32(0x6c));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454580: Room at a Starting Mark
  [32936, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x6d));
    w(0x4ac984, i32(0x6d));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454610: Miscellaneous
  [32937, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x6e));
    w(0x4ac984, i32(0x6e));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x004546a0: Coach               &Y
  [32923, (memory, options, r, w, f, invalidate) => {
    if (Number(r(0x4ac984) != i32(300))) {
    w(0x4ac980, i32(300));
    w(0x4ac984, i32(300));
    w(0x4ac938, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
    }
    w(0x4ac980, i32(0));
    w(0x4ac984, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00454740: Southern Hemisphere
  [32938, (memory, options, r, w, f, invalidate) => {
    w(0x4ac998, add32(r(0x4ac998), i32(1)));
    if (Number(i32(1) < r(0x4ac998))) {
    w(0x4ac998, i32(0));
    }
    return;
  }],
  // 0x004547a0: Show Race Results
  [32939, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(400));
    w(0x4ac984, i32(400));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454830: Introduction
  [32940, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x1f5));
    w(0x4ac984, i32(0x1f5));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x004548b0: Wind Shift Effects - Concepts
  [32941, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x1f6));
    w(0x4ac984, i32(0x1f6));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454930: Lifts
  [32942, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x1f7));
    w(0x4ac984, i32(0x1f7));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x004549c0: Headers
  [32943, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x1f8));
    w(0x4ac984, i32(0x1f8));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454a50: Death by Layline
  [32955, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x1f9));
    w(0x4ac984, i32(0x1f9));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454ae0: Strategy for Oscillating Winds
  [32944, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x1fa));
    w(0x4ac984, i32(0x1fa));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454b70: Strategy for One Side Favored
  [32945, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x1fb));
    w(0x4ac984, i32(0x1fb));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454c00: Downwind Strategy
  [32954, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x1fc));
    w(0x4ac984, i32(0x1fc));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454c90: Wind Prediction - 1
  [32946, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x1fd));
    w(0x4ac984, i32(0x1fd));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454d20: Wind Prediction - 2
  [32947, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x1fe));
    w(0x4ac984, i32(0x1fe));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454db0: Currents
  [32948, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x1ff));
    w(0x4ac984, i32(0x1ff));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454e40: Wind Interference from Other Boats
  [32949, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x200));
    w(0x4ac984, i32(0x200));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454ed0: Starting
  [32950, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x201));
    w(0x4ac984, i32(0x201));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454f60: Mark Rounding
  [32951, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x202));
    w(0x4ac984, i32(0x202));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00454ff0: Glossary
  [32926, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x259));
    w(0x4ac984, i32(0x259));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00455080: Bibliography
  [32956, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(1));
    w(0x4ac980, i32(0x2bd));
    w(0x4ac984, i32(0x2bd));
    invalidate(i32(0));
    w(0x4a6774, i32(0));
    return;
  }],
  // 0x00455110: Zoom  In Tactical        &Z
  [32898, (memory, options, r, w, f, invalidate) => {
    w(0x4a8664, idiv32(r(0x4a8664), i32(2)));
    if (Number(r(0x4a8664) < i32(2))) {
    w(0x4a8664, i32(2));
    }
    return;
  }],
  // 0x00455130: Zoom Out Tactical       &X
  [32899, (memory, options, r, w, f, invalidate) => {
    w(0x4a8664, imul32(r(0x4a8664), i32(2)));
    w(0x4a775c, add32((sub32(Number(r(0x4a4958) < i32(2)), i32(1)) & i32(0xffffffc0)), i32(0x80)));
    if (Number(r(0x4a775c) < r(0x4a8664))) {
    w(0x4a8664, r(0x4a775c));
    }
    return;
  }],
  // 0x00455170: Change Shape    &E
  [32911, (memory, options, r, w, f, invalidate) => {
    w(0x4a776c, add32(r(0x4a776c), i32(1)));
    if (Number(i32(3) < r(0x4a776c))) {
    w(0x4a776c, i32(1));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004551d0: New Features
  [32868, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(0));
    w(0x4ac980, i32(7));
    w(0x4ac984, i32(7));
    invalidate(i32(0));
    return;
  }],
  // 0x00455240: Tips for First Use
  [32869, (memory, options, r, w, f, invalidate) => {
    w(0x4ac8fc, i32(0));
    w(0x4ac980, i32(8));
    w(0x4ac984, i32(8));
    invalidate(i32(0));
    return;
  }],
  // 0x004552b0: Colored Mainsails
  [32957, (memory, options, r, w, f, invalidate) => {
    w(0x4ac9bc, add32(r(0x4ac9bc), i32(1)));
    if (Number(i32(1) < r(0x4ac9bc))) {
    w(0x4ac9bc, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455330: New Series
  [32960, (memory, options, r, w, f, invalidate) => {
    w(0x4ac944, i32(0));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455390: Monochrome
  [32958, (memory, options, r, w, f, invalidate) => {
    w(0x4ac92c, add32(r(0x4ac92c), i32(1)));
    if (Number(i32(1) < r(0x4ac92c))) {
    w(0x4ac92c, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455400: Bay
  [32961, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(0xb));
    return;
  }],
  // 0x00455450: No Strategic View       &4
  [32962, (memory, options, r, w, f, invalidate) => {
    w(0x4ac9c8, add32(r(0x4ac9c8), i32(1)));
    if (Number(i32(1) < r(0x4ac9c8))) {
    w(0x4ac9c8, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004554d0: Warning of Right of Way Boat
  [32963, (memory, options, r, w, f, invalidate) => {
    w(0x4911a0, add32(r(0x4911a0), i32(1)));
    if (Number(i32(1) < r(0x4911a0))) {
    w(0x4911a0, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455550: Distance Race - Around Island
  [32964, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(8));
    w(0x4ac940, i32(0));
    w(0x4ac950, i32(0));
    w(0x4ac954, i32(0));
    w(0x4a5a4c, i32(1));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004555f0: Show True Wind
  [32965, (memory, options, r, w, f, invalidate) => {
    w(0x4ac9d8, add32(r(0x4ac9d8), i32(1)));
    if (Number(i32(1) < r(0x4ac9d8))) {
    w(0x4ac9d8, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455650: No Sounds
  [32966, (memory, options, r, w, f, invalidate) => {
    w(0x4ac9c0, add32(r(0x4ac9c0), i32(1)));
    if (Number(i32(1) < r(0x4ac9c0))) {
    w(0x4ac9c0, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004556b0: Show Button Explanations
  [32967, (memory, options, r, w, f, invalidate) => {
    w(0x4911a4, add32(r(0x4911a4), i32(1)));
    if (Number(i32(1) < r(0x4911a4))) {
    w(0x4911a4, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455750: Replay Leg          backspace
  [32968, (memory, options, r, w, f, invalidate) => {
    w(0x4ac9ec, add32(r(0x4ac9ec), i32(1)));
    if (Number(i32(1) < r(0x4ac9ec))) {
    w(0x4ac9ec, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453050: 11
  [32969, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(0xb));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004530b0: 12
  [32970, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(0xc));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453110: 13
  [32971, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(0xd));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453170: 14
  [32972, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(0xe));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004531d0: 15      fastest 
  [32973, (memory, options, r, w, f, invalidate) => {
    w(0x49116c, i32(0xf));
    updateSpeedDivisor(memory);
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453230: Faster             page up
  [32974, (memory, options, r, w, f, invalidate) => {
    if (Number(r(0x49116c) < i32(0xf))) {
    w(0x49116c, add32(r(0x49116c), i32(1)));
    }
    updateSpeedDivisor(memory);
    w(0x491178, r(0x49116c));
    w(0x491174, r(0x491170));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00453290: Slower            page dn
  [32975, (memory, options, r, w, f, invalidate) => {
    if (Number(i32(1) < r(0x49116c))) {
    w(0x49116c, add32(r(0x49116c), sub32(0, i32(1))));
    }
    updateSpeedDivisor(memory);
    w(0x491178, r(0x49116c));
    w(0x491174, r(0x491170));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004557d0: Banana Lakes
  [32976, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(0xc));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455840: Five Finger Lakes
  [32977, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(0xd));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004558b0: Branching Rivers
  [32978, (memory, options, r, w, f, invalidate) => {
    w(0x491194, i32(0xe));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455920: 10 Min Pre-start
  [32979, (memory, options, r, w, f, invalidate) => {
    w(0x4911cc, i32(10));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x004559a0: 5 Min Pre-start
  [32980, (memory, options, r, w, f, invalidate) => {
    w(0x4911cc, i32(5));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455a10: Perfect Start at Pin
  [32981, (memory, options, r, w, f, invalidate) => {
    w(0x4911cc, i32(2));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455a90: Perfect Start at C. Boat
  [32982, (memory, options, r, w, f, invalidate) => {
    w(0x4911cc, i32(1));
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455b10: Simplify Graphics
  [32983, (memory, options, r, w, f, invalidate) => {
    w(0x4ac928, add32(r(0x4ac928), i32(1)));
    if (Number(i32(1) < r(0x4ac928))) {
    w(0x4ac928, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
  // 0x00455b70: Slow Simulator on Warning        backslash
  [32984, (memory, options, r, w, f, invalidate) => {
    w(0x4911d0, add32(r(0x4911d0), i32(1)));
    if (Number(i32(1) < r(0x4911d0))) {
    w(0x4911d0, i32(0));
    }
    w(0x4ac8fc, i32(0));
    invalidate(i32(0));
    return;
  }],
]);

const updateHandlers = new Map([
  // 0x00401340: Hide Menu Item Help
  [59393, (r, enable, check) => {
    return;
  }],
  // 0x00450080: Start          spacebar
  [32771, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    return;
  }],
  // 0x00453a40: Another Race             &N
  [32777, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    return;
  }],
  // 0x0044f810: No Header / Lift Info
  [32776, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac978) == i32(1)));
    return;
  }],
  // 0x0044f880: 505
  [32783, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(6)));
    return;
  }],
  // 0x0044f980: America's Cup
  [32792, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(0xf)));
    return;
  }],
  // 0x0044fa00: Board
  [32881, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(3)));
    return;
  }],
  // 0x0044fa80: JY15
  [32784, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(5)));
    return;
  }],
  // 0x0044fb00: Keelboat
  [32789, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(0xc)));
    return;
  }],
  // 0x0044fb80: Laser
  [32782, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(2)));
    return;
  }],
  // 0x0044fc00: Lightning
  [32788, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(9)));
    return;
  }],
  // 0x0044fc80: Offshore Racer
  [32791, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491144) == i32(0xe)));
    return;
  }],
  // 0x0044fcf0: Optimist
  [32781, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(1)));
    return;
  }],
  // 0x0044fd70: Skiff
  [32786, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(7)));
    return;
  }],
  // 0x0044fdf0: Spinnaker Catamaran
  [32794, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(0xb)));
    return;
  }],
  // 0x0044fe80: Sport Boat
  [32790, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(0xd)));
    return;
  }],
  // 0x0044ff00: Thistle
  [32787, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(8)));
    return;
  }],
  // 0x0044ff80: Tornado Catamaran
  [32793, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(10)));
    return;
  }],
  // 0x00450040: Design
  [32823, (r, enable, check) => {
    if (Number(Boolean(Number(Boolean(Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(i32(5) < r(0x491188))))) && Boolean(Number(r(0x491188) < i32(8))))) && Boolean(Number(r(0x4ac908) == i32(0))))) {
    enable(i32(1));
    return;
    }
    enable(i32(0));
    return;
  }],
  // 0x004500d0: 10
  [32807, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x49118c) == i32(10)));
    return;
  }],
  // 0x00450150: 15
  [32808, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x49118c) == i32(0xf)));
    return;
  }],
  // 0x004501d0: 20
  [32809, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x49118c) == i32(0x14)));
    return;
  }],
  // 0x00450250: 25
  [32810, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x49118c) == i32(0x19)));
    return;
  }],
  // 0x004502e0: 2  Match Racing
  [32805, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x49118c) == i32(2)));
    return;
  }],
  // 0x00450350: 30
  [32811, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x49118c) == i32(0x1e)));
    return;
  }],
  // 0x004503d0: 5
  [32806, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x49118c) == i32(5)));
    return;
  }],
  // 0x00450440: No Series Scoring.
  [32824, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x4ac960) == i32(1)));
    return;
  }],
  // 0x004504b0: One Player
  [32778, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491140) == i32(1)));
    return;
  }],
  // 0x00450530: Gold Cup
  [32820, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x491194) != i32(8))))) && Boolean(Number(r(0x491194) != i32(7))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    if (Number(Boolean(Number(Boolean(Number(r(0x491180) == i32(5))) && Boolean(Number(r(0x491194) != i32(8))))) && Boolean(Number(r(0x491194) != i32(7))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x004505d0: Triangle
  [32818, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x491194) != i32(8))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    if (Number(Boolean(Number(r(0x491180) == i32(3))) && Boolean(Number(r(0x491194) != i32(8))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x00450670: Triangle Twice Around
  [32819, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x491194) != i32(8))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    if (Number(Boolean(Number(r(0x491180) == i32(4))) && Boolean(Number(r(0x491194) != i32(8))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x00450700: Windward / Leeward
  [32816, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x491194) != i32(8))))) && Boolean(Number(r(0x491194) != i32(7))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    if (Number(Boolean(Number(Boolean(Number(r(0x491180) == i32(1))) && Boolean(Number(r(0x491194) != i32(8))))) && Boolean(Number(r(0x491194) != i32(7))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x004507b0: Windward / Leeward Twice Around
  [32817, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x491194) != i32(8))))) && Boolean(Number(r(0x491194) != i32(7))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    if (Number(Boolean(Number(Boolean(Number(r(0x491180) == i32(2))) && Boolean(Number(r(0x491194) != i32(8))))) && Boolean(Number(r(0x491194) != i32(7))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x00450860: Distance Race - Along Shore
  [32802, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x491188) == i32(7))))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    if (Number(Boolean(Number(r(0x491194) == i32(8))) && Boolean(Number(r(0x4a5a4c) == i32(0))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x004508f0: Round Lake
  [32799, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(5)));
    return;
  }],
  // 0x00450960: River Mouth North
  [32803, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(9)));
    return;
  }],
  // 0x004509d0: River Mouth South
  [32804, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(10)));
    return;
  }],
  // 0x00450a40: Round the Island
  [32801, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491194) == i32(7)));
    return;
  }],
  // 0x00450ac0: Shoreline to the East
  [32796, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(2)));
    return;
  }],
  // 0x00450b30: Shoreline to the North
  [32795, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(1)));
    return;
  }],
  // 0x00450ba0: Shoreline to the South
  [32797, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(3)));
    return;
  }],
  // 0x00450c10: Shoreline to the West
  [32798, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(4)));
    return;
  }],
  // 0x00450c80: Sound
  [32800, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(6)));
    return;
  }],
  // 0x00450cf0: Short Course
  [32821, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x491194) != i32(7))))) && Boolean(Number(r(0x491194) != i32(8))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x4ac954) == i32(1)));
    return;
  }],
  // 0x00450d70: Tidal Currents
  [32815, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491158) == i32(1)));
    return;
  }],
  // 0x00450e30: Two Players
  [32779, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491140) == i32(2)));
    return;
  }],
  // 0x00450ea0: Wheel Steering
  [32822, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x491188) == i32(7))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x49114c) == i32(1)));
    return;
  }],
  // 0x00450f20: Light
  [32812, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491154) == i32(1)));
    return;
  }],
  // 0x00450f90: Moderate
  [32813, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491154) == i32(2)));
    return;
  }],
  // 0x00451000: Strong
  [32814, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491154) == i32(3)));
    return;
  }],
  // 0x00451060: 1
  [32882, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(1)));
    return;
  }],
  // 0x004510b0: 10
  [32891, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(10)));
    return;
  }],
  // 0x00451100: 11
  [32892, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(0xb)));
    return;
  }],
  // 0x00451150: 12
  [32893, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(0xc)));
    return;
  }],
  // 0x004511a0: 13
  [32894, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(0xd)));
    return;
  }],
  // 0x004511f0: 14
  [32895, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(0xe)));
    return;
  }],
  // 0x00451240: 15
  [32896, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(0xf)));
    return;
  }],
  // 0x00451290: 2
  [32883, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(2)));
    return;
  }],
  // 0x004512e0: 3
  [32884, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(3)));
    return;
  }],
  // 0x00451380: 5
  [32886, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(5)));
    return;
  }],
  // 0x00451330: 4
  [32885, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(4)));
    return;
  }],
  // 0x004513d0: 6
  [32887, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(6)));
    return;
  }],
  // 0x00451420: 7
  [32888, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(7)));
    return;
  }],
  // 0x00451470: 8
  [32889, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(8)));
    return;
  }],
  // 0x004514c0: 9
  [32890, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491190) == i32(9)));
    return;
  }],
  // 0x0044f900: Snipe
  [32897, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x491144) == i32(4)));
    return;
  }],
  // 0x00451530: Close in View             &1
  [32825, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4a4e8c) == i32(1)));
    return;
  }],
  // 0x004515a0: High Viewpoint           &3
  [32827, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4a4e8c) == i32(3)));
    return;
  }],
  // 0x00451610: Wide View                  &2
  [32826, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4a4e8c) == i32(2)));
    return;
  }],
  // 0x00401340: Look Ahead      up arrow
  [32828, (r, enable, check) => {
    return;
  }],
  // 0x00401340: Look Astern      down arrow
  [32831, (r, enable, check) => {
    return;
  }],
  // 0x00401340: Look Left          left arrow
  [32830, (r, enable, check) => {
    return;
  }],
  // 0x00401340: Look Right        right arrow
  [32829, (r, enable, check) => {
    return;
  }],
  // 0x00452bf0: Weather Forecast      &W
  [32907, (r, enable, check) => {
    enable(Number(i32(1) < r(0x4ac8f8)));
    return;
  }],
  // 0x00451770: Marks to Starboard
  [32908, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x491194) != i32(7))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x4ac9a8) == i32(1)));
    return;
  }],
  // 0x004526e0: Automatic Sheet (max speed)     &A
  [32850, (r, enable, check) => {
    enable(Number(i32(1) < r(0x4ac8f8)));
    check(Number(r(0x4a85d4) == sub32(0, i32(1))));
    return;
  }],
  // 0x00452750: Max Luff                                      &S
  [32851, (r, enable, check) => {
    enable(Number(i32(1) < r(0x4ac8f8)));
    check(Number(r(0x4a85d4) == i32(0x5a)));
    return;
  }],
  // 0x00452bf0: 10 to Port               <  or Left Click
  [32842, (r, enable, check) => {
    enable(Number(i32(1) < r(0x4ac8f8)));
    return;
  }],
  // 0x00452bf0: 10 to Starboard      >  or Right Click
  [32841, (r, enable, check) => {
    enable(Number(i32(1) < r(0x4ac8f8)));
    return;
  }],
  // 0x004529b0: Closehauled       &C
  [32843, (r, enable, check) => {
    enable(Number(i32(1) < r(0x4ac8f8)));
    if (Number(Boolean(Number(r(0x4a8914) == i32(1))) && Boolean(Number(r(0x4ac1ec) < i32(0xb))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x00452bf0: Reach        &H
  [32849, (r, enable, check) => {
    enable(Number(i32(1) < r(0x4ac8f8)));
    return;
  }],
  // 0x00452a80: Foot                     +
  [32845, (r, enable, check) => {
    let uVar2;
    uVar2 = i32(1);
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(2))) || Boolean(Number(r(0x4a8914) < i32(1))))) {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x4ac1ec) == i32(5)));
    return;
  }],
  // 0x00452bf0: Jibe                        &J
  [32847, (r, enable, check) => {
    enable(Number(i32(1) < r(0x4ac8f8)));
    return;
  }],
  // 0x00452b50: Pinch                   -
  [32844, (r, enable, check) => {
    let uVar2;
    uVar2 = i32(1);
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(2))) || Boolean(Number(r(0x4a8914) < i32(1))))) {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x4ac1ec) == sub32(0, i32(5))));
    return;
  }],
  // 0x00452bf0: Tack           &T
  [32846, (r, enable, check) => {
    enable(Number(i32(1) < r(0x4ac8f8)));
    return;
  }],
  // 0x00452c50: Run  Downwind     &D
  [32848, (r, enable, check) => {
    enable(Number(i32(1) < r(0x4ac8f8)));
    check(Number(r(0x4a684c) == i32(1)));
    return;
  }],
  // 0x00452cc0: &1   slowest
  [32872, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(1)));
    return;
  }],
  // 0x00452d20: &2
  [32873, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(2)));
    return;
  }],
  // 0x00452d80: &3
  [32874, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(3)));
    return;
  }],
  // 0x00452de0: &4
  [32875, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(4)));
    return;
  }],
  // 0x00452e40: &5
  [32876, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(5)));
    return;
  }],
  // 0x00452ea0: &6
  [32877, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(6)));
    return;
  }],
  // 0x00452f00: &7
  [32878, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(7)));
    return;
  }],
  // 0x00452f60: &8
  [32879, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(8)));
    return;
  }],
  // 0x00452fc0: &9
  [32880, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(9)));
    return;
  }],
  // 0x00453020: 1&0 
  [32909, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(10)));
    return;
  }],
  // 0x00453310: Look to Leeward        &7
  [32833, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4a9444) == sub32(0, i32(1))));
    return;
  }],
  // 0x00453380: Look to Windward      &5
  [32832, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4a9444) == i32(1)));
    return;
  }],
  // 0x00453a40: Sheet In 20%                   &I
  [32852, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    return;
  }],
  // 0x00401340: Sheet Out 20%                &O
  [32853, (r, enable, check) => {
    return;
  }],
  // 0x00453470: #1 Genoa
  [32859, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x491188) < i32(7))) || Boolean(Number(i32(8) < r(0x491188))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    if (Number(Boolean(Number(Boolean(Number(r(0x4a4efc) == i32(1))) && Boolean(Number(i32(6) < r(0x491188))))) && Boolean(Number(r(0x491188) < i32(9))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x00453500: #2 Genoa
  [32860, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(r(0x491188) < i32(7))) || Boolean(Number(i32(8) < r(0x491188))))) || Boolean(Number(r(0x491140) != i32(1))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    if (Number(Boolean(Number(Boolean(Number(r(0x4a4efc) == i32(2))) && Boolean(Number(i32(6) < r(0x491188))))) && Boolean(Number(r(0x491188) < i32(9))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x004535a0: #3 Blade
  [32861, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(r(0x491188) < i32(7))) || Boolean(Number(i32(8) < r(0x491188))))) || Boolean(Number(r(0x491140) != i32(1))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    if (Number(Boolean(Number(Boolean(Number(r(0x4a4efc) == i32(3))) && Boolean(Number(i32(6) < r(0x491188))))) && Boolean(Number(Boolean(Number(r(0x491188) < i32(9))) && Boolean(Number(r(0x491140) == i32(1))))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x00453640: Baggy                 F3
  [32856, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x4a776c) == i32(3)));
    return;
  }],
  // 0x004536a0: Flat                     F1
  [32854, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x4a776c) == i32(1)));
    return;
  }],
  // 0x00453700: Medium              F2
  [32855, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x4a776c) == i32(2)));
    return;
  }],
  // 0x00453750: Spin Down           P
  [32858, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x491188) < i32(2))) || Boolean(Number(r(0x491188) == i32(9))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4a4388) == i32(0)));
    return;
  }],
  // 0x004537c0: Spin Up (wing)     &P
  [32857, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x491188) < i32(2))) || Boolean(Number(r(0x491188) == i32(9))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4a4388) == i32(1)));
    return;
  }],
  // 0x00453840: Freeze                       F
  [32910, (r, enable, check) => {
    enable(Number(i32(1) < r(0x4ac8f8)));
    check(Number(r(0x4ac968) == i32(1)));
    return;
  }],
  // 0x004538d0: Wind Chart             [
  [32902, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4ac970) == i32(1)));
    return;
  }],
  // 0x00453960: Tide Chart               ]    
  [32903, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4ac974) == i32(1)));
    return;
  }],
  // 0x004539d0: Tide @ +1 hour      +
  [32904, (r, enable, check) => {
    let uVar1;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(1))) || Boolean(((uVar1 = i32(1)), Number(r(0x4ac974) != i32(1)))))) {
    uVar1 = i32(0);
    }
    enable(uVar1);
    return;
  }],
  // 0x00453a40: Change Viewpoint      &V
  [32912, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    return;
  }],
  // 0x00453a90: Look at Other Boat     &9
  [32834, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x491140) == i32(2))) || Boolean(Number(r(0x49118c) == i32(2))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x4a9444) == i32(100)));
    return;
  }],
  // 0x00453b10: Hide Sails                   &U
  [32913, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4a40c4) == i32(1)));
    return;
  }],
  // 0x00453b80: Bow Up Orientation
  [32914, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4ab164) == i32(1)));
    return;
  }],
  // 0x00453bf0: Wind Up Orientation
  [32916, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4ab164) == i32(2)));
    return;
  }],
  // 0x00453c60: Show Tracks          ~
  [32919, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4ac958) == i32(1)));
    return;
  }],
  // 0x00453cd0: Show laylines, Equal Line
  [32918, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x49117c) == i32(1)));
    return;
  }],
  // 0x00452670: Race Course           &R
  [32905, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4aa980) == i32(1)));
    return;
  }],
  // 0x00453d30: Same Orientation as Sailing View
  [32915, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    check(Number(r(0x4ab164) == i32(0)));
    return;
  }],
  // 0x00453da0: Simulator Operation
  [32862, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac980) == i32(1)));
    return;
  }],
  // 0x00453e10: What You See (Sailing Views)
  [32924, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(Boolean(Number(r(0x4ac8f8) < i32(2))) || Boolean(Number(r(0x4aa980) != i32(0))))) || Boolean(Number(r(0x4ac974) != i32(0))))) || Boolean(Number(r(0x4ac938) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(2)));
    return;
  }],
  // 0x00453ea0: View Control
  [32864, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac980) == i32(3)));
    return;
  }],
  // 0x00453f10: Steering
  [32865, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac980) == i32(4)));
    return;
  }],
  // 0x00453f80: Sail Control
  [32866, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac980) == i32(5)));
    return;
  }],
  // 0x00453ff0: Automatic View           &0
  [32835, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4aae24) == i32(1)));
    return;
  }],
  // 0x00454060: Key Command Summary      &?
  [32925, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac980) == i32(6)));
    return;
  }],
  // 0x004540e0: Night Race
  [32927, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x491188) == i32(7))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x4ac990) == i32(1)));
    return;
  }],
  // 0x00454160: Introduction
  [32928, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac980) == i32(0x65)));
    return;
  }],
  // 0x004541e0: Same Tack
  [32929, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x67)));
    return;
  }],
  // 0x00454270: Opposite Tacks
  [32931, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac980) == i32(0x66)));
    return;
  }],
  // 0x004542f0: Overtaking
  [32930, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x68)));
    return;
  }],
  // 0x00454380: Marks and Obstructions
  [32932, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x69)));
    return;
  }],
  // 0x00454410: Rounding a Windward Mark
  [32933, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x6a)));
    return;
  }],
  // 0x004544a0: Tacking for Obstructions
  [32934, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x6b)));
    return;
  }],
  // 0x00454530: Same Tack Before Starting
  [32935, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x6c)));
    return;
  }],
  // 0x004545c0: Room at a Starting Mark
  [32936, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x6d)));
    return;
  }],
  // 0x00454650: Miscellaneous
  [32937, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x6e)));
    return;
  }],
  // 0x004546f0: Coach               &Y
  [32923, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(r(0x4ac8f8) < i32(2))) || Boolean(((uVar2 = i32(1)), Number(r(0x491140) != i32(1)))))) || Boolean(Number(i32(10) < r(0x491190))))) {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(300)));
    return;
  }],
  // 0x00454760: Southern Hemisphere
  [32938, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x4ac998) == i32(1)));
    return;
  }],
  // 0x004547e0: Show Race Results
  [32939, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x4ac944) < i32(1))))) || Boolean(Number(r(0x4ac960) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(400)));
    return;
  }],
  // 0x00454870: Introduction
  [32940, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac980) == i32(0x1f5)));
    return;
  }],
  // 0x004548f0: Wind Shift Effects - Concepts
  [32941, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac980) == i32(0x1f6)));
    return;
  }],
  // 0x00454970: Lifts
  [32942, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x1f7)));
    return;
  }],
  // 0x00454a00: Headers
  [32943, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x1f8)));
    return;
  }],
  // 0x00454a90: Death by Layline
  [32955, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x1f9)));
    return;
  }],
  // 0x00454b20: Strategy for Oscillating Winds
  [32944, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x1fa)));
    return;
  }],
  // 0x00454bb0: Strategy for One Side Favored
  [32945, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x1fb)));
    return;
  }],
  // 0x00454c40: Downwind Strategy
  [32954, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x1fc)));
    return;
  }],
  // 0x00454cd0: Wind Prediction - 1
  [32946, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x1fd)));
    return;
  }],
  // 0x00454d60: Wind Prediction - 2
  [32947, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x1fe)));
    return;
  }],
  // 0x00454df0: Currents
  [32948, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x1ff)));
    return;
  }],
  // 0x00454e80: Wind Interference from Other Boats
  [32949, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x200)));
    return;
  }],
  // 0x00454f10: Starting
  [32950, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x201)));
    return;
  }],
  // 0x00454fa0: Mark Rounding
  [32951, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x202)));
    return;
  }],
  // 0x00455030: Glossary
  [32926, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x259)));
    return;
  }],
  // 0x004550c0: Bibliography
  [32956, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491164) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac980) == i32(0x2bd)));
    return;
  }],
  // 0x00453a40: Zoom  In Tactical        &Z
  [32898, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    return;
  }],
  // 0x00453a40: Zoom Out Tactical       &X
  [32899, (r, enable, check) => {
    enable(Number(i32(0) < r(0x4ac8f8)));
    return;
  }],
  // 0x004551b0: Change Shape    &E
  [32911, (r, enable, check) => {
    enable(Number(r(0x4ac904) == i32(0)));
    return;
  }],
  // 0x00455200: New Features
  [32868, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac980) == i32(7)));
    return;
  }],
  // 0x00455270: Tips for First Use
  [32869, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac980) == i32(8)));
    return;
  }],
  // 0x004552e0: Colored Mainsails
  [32957, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x4ac92c) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac9bc) == i32(1)));
    return;
  }],
  // 0x00455350: New Series
  [32960, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x4ac944) == i32(0)));
    return;
  }],
  // 0x004553c0: Monochrome
  [32958, (r, enable, check) => {
    enable(Number(sub32(0, i32(1)) < r(0x4ac8f8)));
    check(Number(r(0x4ac92c) == i32(1)));
    return;
  }],
  // 0x00455410: Bay
  [32961, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(0xb)));
    return;
  }],
  // 0x00455480: No Strategic View       &4
  [32962, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x491140) != i32(1))))) || Boolean(Number(r(0x4ac9b4) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac9c8) == i32(1)));
    return;
  }],
  // 0x00455500: Warning of Right of Way Boat
  [32963, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) < i32(0))) || Boolean(Number(r(0x4ac92c) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4911a0) == i32(1)));
    return;
  }],
  // 0x00455590: Distance Race - Around Island
  [32964, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(r(0x491188) == i32(7))))) && Boolean(Number(r(0x4ac9ac) == i32(0))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    if (Number(Boolean(Number(r(0x491194) == i32(8))) && Boolean(Number(r(0x4a5a4c) == i32(1))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x00455620: Show True Wind
  [32965, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x4ac9d8) == i32(1)));
    return;
  }],
  // 0x00455680: No Sounds
  [32966, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x4ac9c0) == i32(1)));
    return;
  }],
  // 0x004556e0: Show Button Explanations
  [32967, (r, enable, check) => {
    enable(Number(r(0x491140) == i32(1)));
    if (Number(Boolean(Number(r(0x4911a4) == i32(1))) && Boolean(Number(r(0x491140) == i32(1))))) {
    check(i32(1));
    return;
    }
    check(i32(0));
    return;
  }],
  // 0x00455780: Replay Leg          backspace
  [32968, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4911c0) < i32(0))) || Boolean(Number(r(0x4ac93c) != i32(0))))) {
    uVar2 = i32(0);
    }
    else {
    uVar2 = i32(1);
    }
    enable(uVar2);
    check(Number(r(0x4ac9ec) == i32(1)));
    return;
  }],
  // 0x00453080: 11
  [32969, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(0xb)));
    return;
  }],
  // 0x004530e0: 12
  [32970, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(0xc)));
    return;
  }],
  // 0x00453140: 13
  [32971, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(0xd)));
    return;
  }],
  // 0x004531a0: 14
  [32972, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(0xe)));
    return;
  }],
  // 0x00453200: 15      fastest 
  [32973, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x49116c) == i32(0xf)));
    return;
  }],
  // 0x00453280: Faster             page up
  [32974, (r, enable, check) => {
    enable(i32(1));
    return;
  }],
  // 0x00453280: Slower            page dn
  [32975, (r, enable, check) => {
    enable(i32(1));
    return;
  }],
  // 0x00455800: Banana Lakes
  [32976, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(0xc)));
    return;
  }],
  // 0x00455870: Five Finger Lakes
  [32977, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(0xd)));
    return;
  }],
  // 0x004558e0: Branching Rivers
  [32978, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x491194) == i32(0xe)));
    return;
  }],
  // 0x00455950: 10 Min Pre-start
  [32979, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) && Boolean(Number(i32(2) < r(0x49118c))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x4911cc) == i32(10)));
    return;
  }],
  // 0x004559d0: 5 Min Pre-start
  [32980, (r, enable, check) => {
    enable(Number(r(0x4ac8f8) == i32(0)));
    check(Number(r(0x4911cc) == i32(5)));
    return;
  }],
  // 0x00455a40: Perfect Start at Pin
  [32981, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) || Boolean(Number(Boolean(Number(r(0x4a5b80) == r(0x4a4168))) && Boolean(Number(r(0x4911cc) < i32(3))))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x4911cc) == i32(2)));
    return;
  }],
  // 0x00455ac0: Perfect Start at C. Boat
  [32982, (r, enable, check) => {
    let uVar2;
    if (Number(Boolean(Number(r(0x4ac8f8) == i32(0))) || Boolean(Number(Boolean(Number(r(0x4a5b80) == r(0x4a4168))) && Boolean(Number(r(0x4911cc) < i32(3))))))) {
    uVar2 = i32(1);
    }
    else {
    uVar2 = i32(0);
    }
    enable(uVar2);
    check(Number(r(0x4911cc) == i32(1)));
    return;
  }],
  // 0x00455b40: Simplify Graphics
  [32983, (r, enable, check) => {
    enable(i32(1));
    check(Number(r(0x4ac928) == i32(1)));
    return;
  }],
  // 0x00455ba0: Slow Simulator on Warning        backslash
  [32984, (r, enable, check) => {
    enable(Number(r(0x4911a0) == i32(1)));
    check(Number(r(0x4911d0) == i32(1)));
    return;
  }],
]);

/** Run the exact recovered numeric command; GUI dialogs remain explicit host requests. */
export function handleMenuCommand(memory, command, options = {}) {
  command = i32(command);
  const invalidate = erase => options.invalidateRect?.({windowHandle: options.windowHandle ?? 0, rectangle: null, erase});
  const dialog = (resourceId, originalAddress) => {
    if (!options.dialogHandler) throw new RangeError('This original command requires its modal dialog host');
    return options.dialogHandler({resourceId, originalAddress});
  };
  const afterDialog = (result, tail) => result && typeof result.then === 'function' ? Promise.resolve(result).then(tail) : tail();
  if (command === 57664) return afterDialog(dialog(100, 0x401760), () => true);
  if (command === 32823) return afterDialog(dialog(132, 0x44ffd0), () => { memory.writeI32(0x4ac8fc,0); invalidate(1); return true; });
  if (command === 32779) return afterDialog(dialog(131, 0x450db0), () => { memory.writeI32(0x4ac8fc,0); invalidate(0); memory.writeI32(0x491140,2); return true; });
  if (command === 57665) { options.closeWindow?.({message:0x10,wParam:0,lParam:0}); return true; }
  if (command === 59393) { options.toggleMenuItemHelp?.(); return true; }
  const handler = commandHandlers.get(command);
  if (!handler) return false;
  handler(memory, options, address => memory.readI32(address), (address,value) => memory.writeI32(address,value),
    address => Float80.fromNumber(memory.readF64(address)), invalidate);
  return true;
}

/** Exact original CCmdUI Enable/SetCheck requests; untouched properties remain unspecified. */
export function menuCommandState(memory, command, previous = {}) {
  const state = {...previous};
  const events = [];
  updateHandlers.get(i32(command))?.(address => memory.readI32(address),
    value => {state.enabled=Boolean(value);events.push({op:'enable',value:i32(value)});},
    value => {state.checked=i32(value);events.push({op:'check',value:i32(value)});});
  return {...state,events};
}

export const MENU_COMMAND_ROUTINES = Object.freeze({"57664":4200288,"32771":4519776,"32777":4519824,"32776":4519904,"32783":4520016,"32792":4520272,"32881":4520400,"32784":4520528,"32789":4520656,"32782":4520784,"32788":4520912,"32791":4521040,"32781":4521152,"32786":4521280,"32794":4521408,"32790":4521536,"32787":4521680,"32793":4521808,"32823":4521936,"32807":4522144,"32808":4522272,"32809":4522400,"32810":4522528,"32805":4522656,"32811":4522784,"32806":4522912,"32824":4523040,"32778":4523136,"32820":4523248,"32818":4523424,"32819":4523568,"32816":4523728,"32817":4523888,"32802":4524064,"32799":4524224,"32803":4524336,"32804":4524448,"32801":4524560,"32796":4524688,"32795":4524800,"32797":4524912,"32798":4525024,"32800":4525136,"32821":4525248,"32815":4525376,"32779":4525488,"32822":4525696,"32812":4525808,"32813":4525920,"32814":4526032,"32882":4526144,"32891":4526240,"32892":4526320,"32893":4526400,"32894":4526480,"32895":4526560,"32896":4526640,"32883":4526720,"32884":4526800,"32885":4526880,"32886":4526960,"32887":4527040,"32888":4527120,"32889":4527200,"32890":4527280,"32897":4520144,"32825":4527360,"32827":4527472,"32826":4527584,"32828":4527696,"32831":4527728,"32830":4527776,"32829":4527824,"32907":4527872,"32908":4527952,"32905":4531728,"32850":4531888,"32851":4532000,"32842":4532464,"32841":4532528,"32843":4532592,"32849":4532736,"32845":4532800,"32847":4532944,"32844":4533008,"32846":4533152,"32848":4533264,"32872":4533392,"32873":4533488,"32874":4533584,"32875":4533680,"32876":4533776,"32877":4533872,"32878":4533968,"32879":4534064,"32880":4534160,"32909":4534256,"32833":4535008,"32832":4535120,"32852":4535232,"32853":4535296,"32859":4535360,"32860":4535504,"32861":4535664,"32856":4535824,"32854":4535920,"32855":4536016,"32858":4536112,"32857":4536208,"32910":4536320,"32902":4536448,"32903":4536592,"32904":4536736,"32912":4536832,"32834":4536928,"32913":4537056,"32914":4537168,"32916":4537280,"32919":4537392,"32918":4537504,"32915":4537616,"32862":4537712,"32924":4537824,"32864":4537968,"32865":4538080,"32866":4538192,"32835":4538304,"32925":4538416,"32927":4538528,"32928":4538672,"32929":4538784,"32931":4538928,"32930":4539056,"32932":4539200,"32933":4539344,"32934":4539488,"32935":4539632,"32936":4539776,"32937":4539920,"32923":4540064,"32938":4540224,"32939":4540320,"32940":4540464,"32941":4540592,"32942":4540720,"32943":4540864,"32955":4541008,"32944":4541152,"32945":4541296,"32954":4541440,"32946":4541584,"32947":4541728,"32948":4541872,"32949":4542016,"32950":4542160,"32951":4542304,"32926":4542448,"32956":4542592,"32898":4542736,"32899":4542768,"32911":4542832,"32868":4542928,"32869":4543040,"32957":4543152,"32960":4543280,"32958":4543376,"32961":4543488,"32962":4543568,"32963":4543696,"32964":4543824,"32965":4543984,"32966":4544080,"32967":4544176,"32968":4544336,"32969":4534352,"32970":4534448,"32971":4534544,"32972":4534640,"32973":4534736,"32974":4534832,"32975":4534928,"32976":4544464,"32977":4544576,"32978":4544688,"32979":4544800,"32980":4544928,"32981":4545040,"32982":4545168,"32983":4545296,"32984":4545392,"59393":4685455,"57665":4646960});
export const MENU_UPDATE_ROUTINES = Object.freeze({"59393":4199232,"32771":4522112,"32777":4536896,"32776":4519952,"32783":4520064,"32792":4520320,"32881":4520448,"32784":4520576,"32789":4520704,"32782":4520832,"32788":4520960,"32791":4521088,"32781":4521200,"32786":4521328,"32794":4521456,"32790":4521600,"32787":4521728,"32793":4521856,"32823":4522048,"32807":4522192,"32808":4522320,"32809":4522448,"32810":4522576,"32805":4522720,"32811":4522832,"32806":4522960,"32824":4523072,"32778":4523184,"32820":4523312,"32818":4523472,"32819":4523632,"32816":4523776,"32817":4523952,"32802":4524128,"32799":4524272,"32803":4524384,"32804":4524496,"32801":4524608,"32796":4524736,"32795":4524848,"32797":4524960,"32798":4525072,"32800":4525184,"32821":4525296,"32815":4525424,"32779":4525616,"32822":4525728,"32812":4525856,"32813":4525968,"32814":4526080,"32882":4526176,"32891":4526256,"32892":4526336,"32893":4526416,"32894":4526496,"32895":4526576,"32896":4526656,"32883":4526736,"32884":4526816,"32886":4526976,"32885":4526896,"32887":4527056,"32888":4527136,"32889":4527216,"32890":4527296,"32897":4520192,"32825":4527408,"32827":4527520,"32826":4527632,"32828":4199232,"32831":4199232,"32830":4199232,"32829":4199232,"32907":4533232,"32908":4527984,"32850":4531936,"32851":4532048,"32842":4533232,"32841":4533232,"32843":4532656,"32849":4533232,"32845":4532864,"32847":4533232,"32844":4533072,"32846":4533232,"32848":4533328,"32872":4533440,"32873":4533536,"32874":4533632,"32875":4533728,"32876":4533824,"32877":4533920,"32878":4534016,"32879":4534112,"32880":4534208,"32909":4534304,"32833":4535056,"32832":4535168,"32852":4536896,"32853":4199232,"32859":4535408,"32860":4535552,"32861":4535712,"32856":4535872,"32854":4535968,"32855":4536064,"32858":4536144,"32857":4536256,"32910":4536384,"32902":4536528,"32903":4536672,"32904":4536784,"32912":4536896,"32834":4536976,"32913":4537104,"32914":4537216,"32916":4537328,"32919":4537440,"32918":4537552,"32905":4531824,"32915":4537648,"32862":4537760,"32924":4537872,"32864":4538016,"32865":4538128,"32866":4538240,"32835":4538352,"32925":4538464,"32927":4538592,"32928":4538720,"32929":4538848,"32931":4538992,"32930":4539120,"32932":4539264,"32933":4539408,"32934":4539552,"32935":4539696,"32936":4539840,"32937":4539984,"32923":4540144,"32938":4540256,"32939":4540384,"32940":4540528,"32941":4540656,"32942":4540784,"32943":4540928,"32955":4541072,"32944":4541216,"32945":4541360,"32954":4541504,"32946":4541648,"32947":4541792,"32948":4541936,"32949":4542080,"32950":4542224,"32951":4542368,"32926":4542512,"32956":4542656,"32898":4536896,"32899":4536896,"32911":4542896,"32868":4542976,"32869":4543088,"32957":4543200,"32960":4543312,"32958":4543424,"32961":4543504,"32962":4543616,"32963":4543744,"32964":4543888,"32965":4544032,"32966":4544128,"32967":4544224,"32968":4544384,"32969":4534400,"32970":4534496,"32971":4534592,"32972":4534688,"32973":4534784,"32974":4534912,"32975":4534912,"32976":4544512,"32977":4544624,"32978":4544736,"32979":4544848,"32980":4544976,"32981":4545088,"32982":4545216,"32983":4545344,"32984":4545440});
