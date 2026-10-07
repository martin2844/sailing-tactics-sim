import type {WaveMemory} from './compatibility/wave-motion-port';
import type {WaveValue} from './environment/wave-motion';
import type {RandomStream} from './random/streams';
export interface EngineMemory extends WaveMemory {
  readonly base: number;
  readonly size: number;
  readonly bytes: Uint8Array;
  writeU32(address: number, value: number): void;
}
export interface EngineOptions extends Record<string, unknown> {
  rng: RandomStream;
  getTickCount(): number;
  getCursorPos(): {x: number; y: number};
}
export interface StringCell {address: number; text: string}
export interface CollisionNumerics {
 supported():boolean;
 reference(memory:EngineMemory,random:RandomStream,options:EngineOptions,boat:number):void;
 avoid(memory:EngineMemory,random:RandomStream,options:EngineOptions,distance:number,other:number,boat:number,tack:number):void;
 warn(memory:EngineMemory,random:RandomStream,options:EngineOptions,distance:number,other:number,boat:number):void;
 distance(dx:number,dy:number):number;
}
export interface NumericalEngine {
  collision?:CollisionNumerics;
  captureStrings(memory: EngineMemory): StringCell[];
  restoreStrings(memory: EngineMemory, cells: readonly StringCell[]): void;
  initializeApplication(memory: EngineMemory, random: RandomStream, options: Record<string, unknown>): Map<number, unknown>;
  initializeBoatOptions(memory: EngineMemory, options: EngineOptions): void;
  initializeRace(memory: EngineMemory, random: RandomStream, options: EngineOptions): void;
  advanceFrame(memory: EngineMemory, random: RandomStream, options: EngineOptions): number;
  command(memory: EngineMemory, command: number, options: EngineOptions): unknown;
  key(memory: EngineMemory, key: number, options: EngineOptions): void;
  bindings(): Record<string, unknown>;
  number(value: number): WaveValue;
  integer(value: number): WaveValue;
  sinCos(value: WaveValue): {sine: WaveValue; cosine: WaveValue};
  scaledRandom(span: number, random: RandomStream): number;
  bearing(memory: EngineMemory, x: number, y: number, boat: number): WaveValue;
  distance(memory: EngineMemory, boat: number, x: number, y: number): WaveValue;
  nearest(memory: EngineMemory, x: number, y: number, excluded: number): WaveValue;
}
