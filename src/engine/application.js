import { i32 } from '../runtime/c-types.js';
import { updateSpeedDivisor } from './integer-core.js';
import { initializeWindRandomTable } from './wind-initialization.js';
import { initializeGdiObjects } from '../render/gdi-objects.js';

// Ordered p_tac archive fields read by the original 0x402180 constructor.
// Repeated fields are intentional and preserved in their original positions.
export const PREFERENCE_FIELDS=Object.freeze([
  0x491194,0x491144,0x49116c,0x49118c,0x491190,0x4ac9c0,0x4ac9a4,0x49114c,0x491154,0x491140,
  0x4ac948,0x491180,0x4a5a4c,0x4ac9a8,0x4ac960,0x4ac954,0x491158,0x49114c,0x4ac9d8,0x4ac978,
  0x4ac990,0x4ac998,0x4aae24,0x4aae28,0x4ac9bc,0x4ac92c,0x4ac944,0x4ac9c8,0x4ac95c,0x4911a0,
  0x4911cc,0x4ac9c8,0x4ac928,0x4ac9c0,0x4ab164,0x4ab168,0x4911d0,
  ...Array.from({length:30},(_,index)=>0x4a6bc4+index*16),
  ...Array.from({length:30},(_,index)=>0x4a6bc8+index*16),
  ...Array.from({length:30},(_,index)=>0x4a461c+index*4),
]);

/** Constructor game state, original defaults/archive reads and graphics setup.
 * MFC window ownership is provided by the browser host. The time seed and
 * GetSystemMetrics(SM_CYSCREEN) value are explicit inputs rather than constants.
 */
export function initializeApplication(memory,rng,{preferences=null,timeSeed,screenHeight,integerTrig}={}){
  if(!integerTrig||integerTrig.sine.length!==362||integerTrig.cosine.length!==362)throw new TypeError('Original integer trigonometric tables are required');
  if(!Number.isInteger(timeSeed)||!Number.isInteger(screenHeight))throw new TypeError('Original startup needs explicit time and screen-height inputs');
  const r=address=>memory.readI32(address),w=(address,value)=>memory.writeI32(address,value);
  if(preferences===null){
    for(const [address,value] of [[0x491144,12],[0x491188,6],[0x4ac908,0],[0x4ac900,0],[0x491194,1],[0x49116c,8]])w(address,value);
  }else{
    if(!(preferences instanceof Uint8Array)||preferences.length!==PREFERENCE_FIELDS.length*4)throw new RangeError('Original preference archive has an invalid size');
    const view=new DataView(preferences.buffer,preferences.byteOffset,preferences.byteLength);
    PREFERENCE_FIELDS.forEach((address,index)=>w(address,view.getInt32(index*4,true)));
  }
  if(r(0x4911d0)>1||r(0x4911d0)<0)w(0x4911d0,0);
  for(const address of [0x4ab164,0x4ab168])if(r(address)<0||r(address)>2)w(address,1);
  if(r(0x4911cc)<1||r(0x4911cc)>10)w(0x4911cc,5);
  if(r(0x49118c)===2&&r(0x4911cc)>5)w(0x4911cc,5);
  if(r(0x4ac944)>2)w(0x4ac944,0);
  const courses=new Map([[1,[1,0,0]],[2,[1,0,1]],[3,[0,0,0]],[4,[0,0,1]],[5,[0,1,1]]]);
  const flags=courses.get(r(0x491180));
  if(flags)[0x491160,0x4ac940,0x4ac950].forEach((address,index)=>w(address,flags[index]));
  if(r(0x491194)===8){for(const address of [0x4ac940,0x4ac950,0x4ac954])w(address,0);w(0x491180,1);}
  if(r(0x491194)===7){for(const address of [0x491160,0x4ac940,0x4ac950,0x4ac954])w(address,0);if(r(0x491180)<3||r(0x491180)>4)w(0x491180,3);}
  if(r(0x491188)<7||r(0x491188)>8)w(0x49114c,-1);
  updateSpeedDivisor(memory);w(0x491178,r(0x49116c));w(0x491174,r(0x491170));
  w(0x4a763c,i32(screenHeight));
  integerTrig.sine.forEach((value,index)=>w(0x4a54a0+index*4,value));
  integerTrig.cosine.forEach((value,index)=>w(0x4a3450+index*4,value));
  rng.srand(timeSeed);initializeWindRandomTable(memory,rng);
  return initializeGdiObjects(memory);
}

/** Serialize the preserved archive order for browser-local preference storage. */
export function serializePreferences(memory){
  const bytes=new Uint8Array(PREFERENCE_FIELDS.length*4),view=new DataView(bytes.buffer);
  PREFERENCE_FIELDS.forEach((address,index)=>view.setInt32(index*4,memory.readI32(address),true));
  return bytes;
}
