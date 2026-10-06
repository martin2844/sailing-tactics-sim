import type {PreciseValue} from '../waypoints/respawn';
interface ProfileMemory {
  readI32(address: number): number;
  readF64(address: number): number;
  writeI32(address: number, value: number): void;
  writeU32(address: number, value: number): void;
  writeF64(address: number, value: number): void;
}
interface ProfileNumerics {
  integer(value: number): PreciseValue;
  number(value: number): PreciseValue;
}
export interface CanonicalHostProfile {
  width: number;
  height: number;
  bitsPixel: number;
  applicationInstance: number;
}
export interface CanonicalDimensions {width: number; height: number; bitsPixel: number}
export const canonicalHostProfile: Readonly<CanonicalHostProfile> = {width: 1024, height: 768, bitsPixel: 24, applicationInstance: 1};

/** Compatibility calibration is an explicit engine input, independent of the
 * actual browser viewport or graphics backend. Numerical spills stay exact.
 */
export function configureCanonicalProfile(memory: ProfileMemory, numeric: ProfileNumerics, profile: CanonicalHostProfile): CanonicalDimensions {
  let width = profile.width | 0, height = profile.height | 0;
  memory.writeI32(0x52362c, profile.bitsPixel | 0);
  memory.writeU32(0x5359c8, profile.applicationInstance >>> 0);
  memory.writeI32(0x4f4084, width);
  if (width > 1280) { width = 1280; memory.writeI32(0x4f4084, width); }
  memory.writeI32(0x4fe624, width);
  memory.writeI32(0x4f3ff0, height);
  if (height > 768) { height = 768; memory.writeI32(0x4f3ff0, height); }
  const clientHeight = (width < 801 ? height - 30 : height - Math.trunc(height / 17)) | 0;
  memory.writeI32(0x4fe2a8, clientHeight);
  memory.writeF64(0x50f6e0, numeric.integer(height).multiply(numeric.number(memory.readF64(0x4cc3d8))).toNumber());
  memory.writeF64(0x5259d0, numeric.integer(memory.readI32(0x4f4084)).multiply(numeric.number(memory.readF64(0x4cc3e0))).toNumber());
  return {width, height: clientHeight, bitsPixel: memory.readI32(0x52362c)};
}
