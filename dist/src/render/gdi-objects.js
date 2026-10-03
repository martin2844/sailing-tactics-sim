import { idiv32 } from '../runtime/c-types.js';

// All 64 CreatePen/CreateSolidBrush definitions from original initialization 0x402180.
const DEFINITIONS = Object.freeze([
  { handleAddress: 0x4aa644, kind: 'pen', style: 0, width: width => idiv32(width, 200), color: 0x7f7900 },
  { handleAddress: 0x4aa954, kind: 'pen', style: 0, width: width => idiv32(width, 200), color: 0x7f6e00 },
  { handleAddress: 0x4a622c, kind: 'pen', style: 0, width: width => idiv32(width, 150), color: 0x7f7900 },
  { handleAddress: 0x4a442c, kind: 'pen', style: 0, width: width => idiv32(width, 150), color: 0x7f6e00 },
  { handleAddress: 0x4ac30c, kind: 'pen', style: 0, width: width => 2, color: 0xffff00 },
  { handleAddress: 0x4abf04, kind: 'pen', style: 0, width: width => idiv32(width, 80), color: 0x00ff00 },
  { handleAddress: 0x4a89bc, kind: 'pen', style: 0, width: width => idiv32(width, 130), color: 0x00ff00 },
  { handleAddress: 0x4a6794, kind: 'pen', style: 0, width: width => idiv32(width, 80), color: 0x0000ff },
  { handleAddress: 0x4ab15c, kind: 'pen', style: 0, width: width => idiv32(width, 130), color: 0x0000ff },
  { handleAddress: 0x4a8a44, kind: 'pen', style: 0, width: width => idiv32(width, 80), color: 0x7f7f7f },
  { handleAddress: 0x4abdbc, kind: 'pen', style: 0, width: width => idiv32(width, 130), color: 0x7f7f7f },
  { handleAddress: 0x4a3a04, kind: 'pen', style: 0, width: width => idiv32(width, 80), color: 0x000000 },
  { handleAddress: 0x4a403c, kind: 'pen', style: 0, width: width => idiv32(width, 130), color: 0x000000 },
  { handleAddress: 0x4ab9e4, kind: 'pen', style: 0, width: width => idiv32(width, 80), color: 0xff0000 },
  { handleAddress: 0x4abbfc, kind: 'pen', style: 0, width: width => idiv32(width, 130), color: 0xff0000 },
  { handleAddress: 0x4a46a4, kind: 'pen', style: 0, width: width => idiv32(width, 130), color: 0xffffff },
  { handleAddress: 0x4a4dec, kind: 'pen', style: 0, width: width => 2, color: 0x000000 },
  { handleAddress: 0x4aa634, kind: 'pen', style: 0, width: width => 2, color: 0x7f7f7f },
  { handleAddress: 0x4a71bc, kind: 'pen', style: 0, width: width => 1, color: 0x7f7f7f },
  { handleAddress: 0x4a676c, kind: 'pen', style: 0, width: width => 2, color: 0x0000ff },
  { handleAddress: 0x4a7054, kind: 'pen', style: 0, width: width => 2, color: 0x00007f },
  { handleAddress: 0x4a705c, kind: 'pen', style: 0, width: width => 1, color: 0x00007f },
  { handleAddress: 0x4a3f9c, kind: 'pen', style: 0, width: width => 2, color: 0x7fffff },
  { handleAddress: 0x4aa7ec, kind: 'pen', style: 0, width: width => 2, color: 0x00007f },
  { handleAddress: 0x4a39fc, kind: 'pen', style: 0, width: width => 2, color: 0x00ff00 },
  { handleAddress: 0x4a4374, kind: 'pen', style: 0, width: width => 3, color: 0xff0000 },
  { handleAddress: 0x4ab9cc, kind: 'pen', style: 0, width: width => 2, color: 0x7f0000 },
  { handleAddress: 0x4aa704, kind: 'pen', style: 0, width: width => 1, color: 0x7f0000 },
  { handleAddress: 0x4a3a2c, kind: 'pen', style: 0, width: width => 2, color: 0x007f00 },
  { handleAddress: 0x4ac84c, kind: 'pen', style: 0, width: width => 1, color: 0x007f00 },
  { handleAddress: 0x4abbf4, kind: 'pen', style: 0, width: width => 2, color: 0xff00ff },
  { handleAddress: 0x4aa7d4, kind: 'pen', style: 0, width: width => 2, color: 0x7f007f },
  { handleAddress: 0x4a4ee4, kind: 'pen', style: 0, width: width => 2, color: 0xffffff },
  { handleAddress: 0x4a3c0c, kind: 'pen', style: 0, width: width => 1, color: 0x00ff00 },
  { handleAddress: 0x4ac854, kind: 'pen', style: 0, width: width => 1, color: 0x0000ff },
  { handleAddress: 0x4a67ac, kind: 'pen', style: 0, width: width => 2, color: 0x00ffff },
  { handleAddress: 0x4aa974, kind: 'pen', style: 0, width: width => 1, color: 0xff00ff },
  { handleAddress: 0x4a494c, kind: 'pen', style: 0, width: width => 1, color: 0x7f007f },
  { handleAddress: 0x4a469c, kind: 'brush', color: 0xffff7f },
  { handleAddress: 0x4a5afc, kind: 'brush', color: 0xffff7f },
  { handleAddress: 0x4a8e04, kind: 'brush', color: 0xff7f00 },
  { handleAddress: 0x4a6dac, kind: 'brush', color: 0x7f7f00 },
  { handleAddress: 0x4a8654, kind: 'brush', color: 0xfa7f00 },
  { handleAddress: 0x4ac1cc, kind: 'brush', color: 0x7f7900 },
  { handleAddress: 0x4aa82c, kind: 'brush', color: 0x7f7e00 },
  { handleAddress: 0x4a5b8c, kind: 'brush', color: 0xe60000 },
  { handleAddress: 0x4a3a14, kind: 'brush', color: 0x0000ff },
  { handleAddress: 0x4ab194, kind: 'brush', color: 0x007f7f },
  { handleAddress: 0x4a6484, kind: 'brush', color: 0x00007f },
  { handleAddress: 0x4a621c, kind: 'brush', color: 0x007f00 },
  { handleAddress: 0x4ac8ec, kind: 'brush', color: 0x003f00 },
  { handleAddress: 0x4aa98c, kind: 'brush', color: 0x00ff00 },
  { handleAddress: 0x4aa714, kind: 'brush', color: 0xff0000 },
  { handleAddress: 0x4a71b4, kind: 'brush', color: 0x7f0000 },
  { handleAddress: 0x4a6234, kind: 'brush', color: 0x00ffff },
  { handleAddress: 0x4ab17c, kind: 'brush', color: 0x007f7f },
  { handleAddress: 0x4a7f24, kind: 'brush', color: 0xff00ff },
  { handleAddress: 0x4a487c, kind: 'brush', color: 0x7f007f },
  { handleAddress: 0x4a4f7c, kind: 'brush', color: 0x7fffff },
  { handleAddress: 0x4a70e4, kind: 'brush', color: 0x7f7f7f },
  { handleAddress: 0x4aa7f4, kind: 'brush', color: 0x3f3f3f },
  { handleAddress: 0x4a7bc4, kind: 'brush', color: 0x303030 },
  { handleAddress: 0x4ac8f4, kind: 'brush', color: 0x202020 },
  { handleAddress: 0x4a3efc, kind: 'brush', color: 0xbfbfbf },
]);

/**
 * Install deterministic browser resource handles for the original graphics
 * definitions. This translates the graphics definitions, not all of 0x402180.
 * Native Windows handles are replaced by their original handle-slot address.
 */
export function initializeGdiObjects(memory) {
  const width = memory.readI32(0x4a763c);
  const objects = new Map();
  for (const definition of DEFINITIONS) {
    const handle = definition.handleAddress;
    const object = { kind: definition.kind, color: definition.color };
    if (object.kind === 'pen') { object.style = definition.style; object.width = definition.width(width); }
    objects.set(handle, Object.freeze(object));
    memory.writeU32(definition.handleAddress, handle);
  }
  return objects;
}

export const ORIGINAL_GDI_DEFINITIONS = DEFINITIONS;
