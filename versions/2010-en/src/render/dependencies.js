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
import {fpDrawingEnabled,fpArgument,fpFormalF64} from './float-values.js';

// Fixed edition-local JavaScript functions. This dispatch never reads executable
// bytes and never substitutes drawing from another edition.
const drawing = new Map();
const numberDrawing = new Map();
export function registerOriginalDrawing(address, routine, hasDc = true, dcIndex = hasDc ? 0 : null) {
  if (!Number.isInteger(address) || address < 0x401000 || address >= 0x49b930 || typeof routine !== 'function') {
    throw new TypeError('Invalid preserved 2010 JavaScript drawing routine');
  }
  if (drawing.has(address) && drawing.get(address).routine !== routine) throw new Error('Duplicate 2010 drawing routine');
  if(hasDc&&(!Number.isInteger(dcIndex)||dcIndex<0||dcIndex>32))throw new TypeError('Invalid reviewed CDC parameter index');
  drawing.set(address, {routine,hasDc,dcIndex});
}

export function registerOriginalNumberDrawing(address,routine,floatingParameters){
  if(!drawing.has(address)||typeof routine!=='function'||!Array.isArray(floatingParameters)
    ||floatingParameters.some(index=>!Number.isInteger(index)||index<0||index>32)
    ||new Set(floatingParameters).size!==floatingParameters.length)throw new TypeError('Invalid reviewed numeric drawing routine');
  if(numberDrawing.has(address))throw new Error('Duplicate numeric drawing routine');
  const entry=drawing.get(address),parameters=floatingParameters.slice();
  const bindings=parameters.map(parameter=>parameter-Number(entry.hasDc&&parameter>entry.dcIndex));
  numberDrawing.set(address,{routine,floatingParameters:parameters,entry,bindings,floatingSlots:new Set(bindings)});
}

/** A fused private window may bypass only its unchanged registered callee. */
export function originalNumberDrawingIsCurrent(address){
  const numeric=numberDrawing.get(address);
  return !!numeric&&numeric.entry===drawing.get(address);
}

/** Private typed calls keep stored F64 images between two reviewed functions. */
export function callNumberDrawingDependency(memory,dc,address,args,floatingArguments,rng,options={}){
  return callNumberDrawingDependencyImpl(memory,dc,address,args,floatingArguments,rng,options,false);
}
// The compiler supplies a fresh argument literal that belongs to this call.
// Reusing that literal avoids another per-point array on the numeric route.
export function callNumberDrawingDependencyOwned(memory,dc,address,args,floatingArguments,rng,options={}){
  return callNumberDrawingDependencyImpl(memory,dc,address,args,floatingArguments,rng,options,true);
}
const hasFloatingArgument=(indices,index)=>typeof indices==='number'
  ?index>=0&&index<32&&((indices>>>index)&1)!==0:indices.includes(index);
function callNumberDrawingDependencyImpl(memory,dc,address,args,floatingArguments,rng,options,owned){
  const numeric=numberDrawing.get(address),entry=drawing.get(address);
  if(numeric&&numeric.entry===entry&&fpDrawingEnabled(options)){
    const removed=entry.hasDc&&args[entry.dcIndex]===dc;
    const values=owned?args:removed?args.filter((_arg,index)=>index!==entry.dcIndex):args.slice();
    if(owned&&removed){
      for(let index=entry.dcIndex;index+1<values.length;index++)values[index]=values[index+1];
      values.length--;
    }
    const bindings=numeric.bindings,floatingSlots=numeric.floatingSlots;
    for(let index=0;index<values.length;index++){
      const callerIndex=removed&&index>=entry.dcIndex?index+1:index;
      if(!floatingSlots.has(index)&&hasFloatingArgument(floatingArguments,callerIndex))values[index]=fpArgument(values[index]);
    }
    for(const index of bindings){
      // Reproduce the original generated binder even when a recovered caller
      // leaves its CDC-shaped placeholder in the supplied argument list.
      const callerIndex=removed&&index>=entry.dcIndex?index+1:index;
      const floating=hasFloatingArgument(floatingArguments,callerIndex),value=values[index];
      values[index]=fpFormalF64(floating&&value!==undefined&&typeof value!=='number'&&!(value instanceof Float80)?fpArgument(value):value,floating);
    }
    return numeric.routine(memory,dc,rng,options,true,...values);
  }
  const boxed=args.map((value,index)=>hasFloatingArgument(floatingArguments,index)?fpArgument(value):value);
  return callDrawingDependency(memory,dc,address,boxed,rng,options);
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
