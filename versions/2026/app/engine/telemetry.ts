import type {EngineMemory,NumericalEngine} from './ports.ts';
import {updateNavigationState} from './compatibility/navigation-state.ts';
const signedAngle = (angle: number) => {
  let value = angle % 360;
  if (value > 180) value -= 360;
  if (value < -180) value += 360;
  return value;
};

/** Coach sample counters and warning decisions previously accumulated by HUD
 * cases324–345. Sampling now happens once per successful simulation step. */
export function updateSailingTelemetry(memory: EngineMemory, numeric: NumericalEngine): void {
  const r = (address: number) => memory.readI32(address);
  if (r(0x4f8cd0) <= 0) return;
  const increment = (address: number) => memory.writeI32(address, (r(address) + 1) | 0);
  const shift = signedAngle(r(0x522b94) - r(0x4f7f94));
  const favorable = Math.imul(shift, r(0x522ff4)) >= 0;
  const upwind = r(0x4feccc) < 55;
  if (upwind) {
    if (favorable) increment(0x4f6d2c);
    increment(0x534e94);
  }
  increment(0x534ea4);
  if (r(0x4fe8ac) > 0) { memory.writeI32(0x4fb220, 1); increment(0x4fe768); }
  const point=updateNavigationState(memory,numeric,1),kind=r(0x4fbf14);
  const finalLeg=r(0x4f853c)===r(0x4da1e4);
  const finish=finalLeg&&(r(0x53527c)===0&&kind===0||r(0x53527c)===1&&kind>1&&r(0x4da194)<15);
  const x=finish?Math.trunc(((r(0x536410)+r(0x4fe094))|0)/2):memory.readF64(0x4f8398+point*8);
  const y=finish?Math.trunc(((r(0x536414)+r(0x4fe2a0))|0)/2):memory.readF64(0x4fb068+point*8);
  const bearingValue=numeric.bearing(memory,x,y,1);
  const bearing=signedAngle((bearingValue.multiply(numeric.number(memory.readF64(0x4cc3e8))).truncI32()-r(0x535744))|0);
  memory.writeI32(0x535ff4,bearing);
  const distance = Math.trunc(memory.readF64(0x4fbb88)), absolute = Math.abs(bearing), downwind = r(0x4fae64);
  if (upwind && absolute > 45 && Math.abs(shift) > 10 && distance > 300) memory.writeI32(0x4fb234,1);
  if (upwind && absolute > 75 && distance > Math.trunc(r(0x525a9c)/3)) memory.writeI32(0x4fb234,2);
  if (upwind && absolute > 90 && r(0x4f853c)>0 && r(0x4f8cd0)>10) memory.writeI32(0x4fb234,3);
  if (!favorable && r(0x4feccc)>=170-downwind) {
    if (distance>300 && absolute>downwind) memory.writeI32(0x4fb234,-1);
    if (distance>700 && absolute>Math.trunc(downwind*9/5)) memory.writeI32(0x4fb234,-2);
    if (distance>700 && absolute>downwind*2) memory.writeI32(0x4fb234,-3);
  }
}
