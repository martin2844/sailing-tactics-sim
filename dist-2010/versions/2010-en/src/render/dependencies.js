import { Float80 } from '../../../../src/runtime/float80.js';
import { initializeBoatOptions } from '../engine/boat-options.js';
import { scaledRandom, wrapDegreesOnce, updateSpeedDivisor } from '../engine/application.js';
import {initializeConfiguration} from '../engine/configuration.js';
import {bearingFromVector} from '../engine/wind.js';
import {signedDegrees,targetRelativeBearing} from '../engine/ai-geometry.js';
import {updateWaveMotion} from '../engine/wave-motion.js';
import {initializeSailGeometry} from './sail-geometry.js';
import {clampedPointDistance,nearestWaypointDistance} from '../engine/waypoints.js';
import {sampleVenueCurrent} from '../engine/current.js';
import {sampleVenueMetric} from '../engine/spatial-metrics.js';
import {readPointer,localPointer,cStringHeaderLength} from './typed-c.js';

// Fixed edition-local JavaScript functions. This dispatch never reads executable
// bytes and never substitutes drawing from another edition.
const drawing = new Map();
export function registerOriginalDrawing(address, routine, hasDc = true, dcIndex = hasDc ? 0 : null) {
  if (!Number.isInteger(address) || address < 0x401000 || address >= 0x49b930 || typeof routine !== 'function') {
    throw new TypeError('Invalid preserved 2010 JavaScript drawing routine');
  }
  if (drawing.has(address) && drawing.get(address).routine !== routine) throw new Error('Duplicate 2010 drawing routine');
  if(hasDc&&(!Number.isInteger(dcIndex)||dcIndex<0||dcIndex>32))throw new TypeError('Invalid reviewed CDC parameter index');
  drawing.set(address, {routine,hasDc,dcIndex});
}

export function callDrawingDependency(memory, dc, address, args, rng, options = {}) {
  if (address === 0x49b970) return (args[0] instanceof Float80 ? args[0] : Float80.fromNumber(args[0])).truncI64();
  if (address === 0x420c00) return initializeBoatOptions(memory);
  if (address === 0x41bc20) return wrapDegreesOnce(args[0]);
  if (address === 0x41e000) return scaledRandom(args[0], rng);
  if (address === 0x464940) return updateSpeedDivisor(memory);
  if (address === 0x42c060) return initializeConfiguration(memory,rng,options);
  if (address === 0x4432b0) return updateWaveMotion(memory,{...options,rng});
  if (address === 0x430260) return sampleVenueCurrent(memory,...args,options);
  if (address === 0x47d5f0) return sampleVenueMetric(memory,...args,options);
  if (address === 0x4662d0) return clampedPointDistance(memory,...args.map(value=>value instanceof Float80?value.toNumber():value));
  if (address === 0x466230) return nearestWaypointDistance(memory,
    args[0] instanceof Float80?args[0].toNumber():args[0],
    args[1] instanceof Float80?args[1].toNumber():args[1],args[2]);
  if (address === 0x41bfb0) return initializeSailGeometry(memory,
    args[0] instanceof Float80?args[0].toNumber():args[0],args[1],args[2],args[3],args[4],
    args[5] instanceof Float80?args[5].toNumber():args[5],options);
  if (address === 0x427ee0) return bearingFromVector(memory,...args,options);
  if (address === 0x41e3a0) return signedDegrees(args[0]);
  if (address === 0x43ec20) return targetRelativeBearing(memory,
    args[0] instanceof Float80?args[0].toNumber():args[0],
    args[1] instanceof Float80?args[1].toNumber():args[1],args[2],args[3]);
  if (address === 0x4710d0) return readPointer(memory,args[0],4);
  if (address === 0x4710c0) {
    const data=readPointer(memory,args[0],4);
    // The game observes only CStringData.nDataLength at header+4. Allocator
    // identity and unobserved ref/allocated-size fields remain unspecified.
    // Sparse slots retain the strict unknown-read behavior if later consumed.
    return localPointer([undefined,cStringHeaderLength(memory,data),undefined]);
  }
  const entry = drawing.get(address);
  if (entry) return entry.routine(memory, dc, rng, options,
    ...(entry.hasDc && args[entry.dcIndex] === dc ? args.filter((_arg,index)=>index!==entry.dcIndex) : args));
  const callback = options.drawingDependencies?.[address];
  if (typeof callback === 'function') return callback(memory, dc, args, rng, options);
  throw new Error(`Preserved 2010 drawing dependency 0x${address.toString(16)} is not implemented`);
}
