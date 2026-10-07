import {RandomStreams} from './random/streams.ts';
import {updateWorldState,type WorldStatePort} from './world-state.ts';
import {createWorldStatePort} from './compatibility/world-state-port.ts';
import {respawnWaypoint} from './waypoints/respawn.ts';
import {createWaypointPort} from './compatibility/waypoint-port.ts';
import {updateWaveMotion} from './environment/wave-motion.ts';
import {createWaveMotionPort} from './compatibility/wave-motion-port.ts';
import {updateFoulSlowdown} from './rules/foul-slowdown.ts';
import {createFoulSlowdownState} from './compatibility/foul-slowdown-state.ts';
import {configureCanonicalProfile,canonicalHostProfile} from './compatibility/host-profile.ts';
import {executeSimulationStep} from './simulation-step.ts';
import {RaceWindow,type RaceWindowCheckpoint} from '../race-window.ts';
import {finalizeResults} from './results.ts';
import {updateSailingTelemetry} from './telemetry.ts';
import type {RandomState} from './random/streams.ts';
import type {EngineMemory,EngineOptions,NumericalEngine} from './ports.ts';

export interface RuntimeConfiguration {
  seed: number;
  setupCommands: readonly number[];
  postSetupCommands: readonly number[];
  gate?: boolean;
  integerTrig: unknown;
  trig: unknown;
  options?: Record<string, unknown>;
}

/** The authoritative runtime owns clocks, RNG and world phases. It has no
 * dependency on browser globals, Canvas/GDI, drawing callbacks or a renderer.
 */
export interface EngineCheckpoint {
  image: Uint8Array;
  random: RandomState;
  raceWindow: RaceWindowCheckpoint;
  ticks: number;
  resultsApplied: boolean;
}
const panelFlags = [0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c];

export class EngineRuntime {
  readonly random: RandomStreams;
  readonly options: EngineOptions;
  readonly raceWindow = new RaceWindow();
  objects = new Map<number, unknown>();
  frame = 0;
  private ticks = 0;
  private resultsApplied = false;
  private saveRequested = false;
  private replay?: EngineCheckpoint;
  minimumDuration = 0;
  private readonly world: WorldStatePort;
  private readonly memory: EngineMemory;
  private readonly numeric: NumericalEngine;

  constructor(memory: EngineMemory, numeric: NumericalEngine, configuration: RuntimeConfiguration) {
    this.memory = memory; this.numeric = numeric;
    this.random = new RandomStreams(configuration.seed);
    this.options = {
      ...numeric.bindings(), ...configuration.options,
      rng: this.random.gameplay, trig: configuration.trig,
      finishWindowEnabled: true,
      getTickCount: () => this.ticks++ >>> 0,
      getCursorPos: () => ({x: 0, y: 0}),
      invalidateRect: () => {},
      playSound: configuration.options?.playSound ?? (() => 1),
      messageBeep: configuration.options?.messageBeep ?? (() => {}),
      beep: configuration.options?.beep ?? (() => {}),
      // Save at the end of the whole authoritative step, after world phases.
      saveRaceState: () => { this.saveRequested = true; },
      restoreRaceState: () => { throw new Error('Replay is owned by EngineRuntime'); },
      respawnPhysicalWave: (image: EngineMemory, index: number) => {
        if (image !== this.memory) throw new Error('Physical waves require the owning runtime');
        this.spawnWave(index);
      },
    };
    this.objects = numeric.initializeApplication(memory, this.random.gameplay, {
      preferences: null, timeSeed: configuration.seed, screenHeight: 768, integerTrig: configuration.integerTrig,
    });
    configureCanonicalProfile(memory, numeric, canonicalHostProfile);
    for (const command of configuration.setupCommands) numeric.command(memory, command, this.options);
    if (configuration.gate !== undefined && Boolean(memory.readI32(0x4da1e8)) !== configuration.gate) numeric.command(memory,32994,this.options);
    numeric.initializeBoatOptions(memory, this.options);
    numeric.initializeRace(memory, this.random.gameplay, this.options);
    memory.writeI32(0x5363b0, 2); memory.writeI32(0x536444, 0); memory.writeI32(0x5233a8, 0);
    memory.writeI32(0x53642c, 0); memory.writeI32(0x4da1dc, 0); memory.writeI32(0x4da1f4, 397);
    for (const command of configuration.postSetupCommands) numeric.command(memory, command, this.options);
    for (let index = 0; index <= memory.readI32(0x4da1f4); index++) this.spawnWave(index);
    this.world = createWorldStatePort(memory, {
      camera: () => {}, // Camera state is presentation only under the v1 contract.
      respawnWave: index => this.spawnWave(index),
      waveMotion: () => updateWaveMotion(createWaveMotionPort(memory, {
        number: numeric.number, integer: numeric.integer,
        sine: value => numeric.sinCos(value).sine,
        nearest: (x,y) => numeric.nearest(memory,x,y,-1),
      })),
      slowdown: boat => updateFoulSlowdown(createFoulSlowdownState(memory,boat)),
    });
    updateWorldState(this.world);
    this.replay = this.checkpoint();
  }

  step(): void {
    const memory = this.memory;
    if (memory.readI32(0x5363f4) !== 0) { this.applyResults(); return; }
    this.minimumDuration = 80;
    if (memory.readI32(0x53642c) !== 0 || memory.readI32(0x5363b0) !== 2
      || panelFlags.some(address => memory.readI32(address) !== 0)) return;
    const cycle = (memory.readI32(0x5364e8) + 1) | 0;
    memory.writeI32(0x5364e8, cycle > 60 ? 1 : cycle);
    this.minimumDuration = executeSimulationStep({
      advance: () => this.numeric.advanceFrame(memory,this.random.gameplay,this.options),
      updateWorldState: () => { updateWorldState(this.world); updateSailingTelemetry(memory,this.numeric); },
      pace: () => memory.readI32(0x4da174),
      clearFrameWarnings: () => { memory.writeI32(0x4f7124,0); memory.writeI32(0x4f7128,0); },
    });
    this.frame++;
    this.raceWindow.update(memory);
    if (memory.readI32(0x5363f4) !== 0) this.applyResults();
    if (this.saveRequested) { this.saveRequested = false; this.replay = this.checkpoint(); }
  }

  command(command: number): void { this.numeric.command(this.memory,command,this.options); }
  key(key: number): void {
    if (key === 8) {
      if (this.replay) this.restore(this.replay);
      this.memory.writeI32(0x53642c,1);
      this.memory.writeI32(0x5364ac,0);
      return;
    }
    this.numeric.key(this.memory,key,this.options);
  }

  checkpoint(): EngineCheckpoint {
    return {image:this.memory.bytes.slice(),random:this.random.snapshot(),raceWindow:this.raceWindow.checkpoint(),
      ticks:this.ticks,resultsApplied:this.resultsApplied};
  }

  restore(checkpoint: EngineCheckpoint): void {
    if (checkpoint.image.length !== this.memory.bytes.length) throw new RangeError('Invalid engine checkpoint size');
    this.random.restore(checkpoint.random);
    this.memory.bytes.set(checkpoint.image);
    this.raceWindow.restore(checkpoint.raceWindow);
    this.ticks=checkpoint.ticks;this.resultsApplied=checkpoint.resultsApplied;this.saveRequested=false;
  }

  nextRace(): void {
    const m=this.memory;
    if (!this.resultsApplied) throw new Error('Next race requires completed results');
    const pace=m.readI32(0x522f20),divisor=m.readI32(0x5362f0);
    this.numeric.key(m,78,this.options);
    if (pace>0&&divisor>0) { m.writeI32(0x4da174,pace);m.writeI32(0x4da178,divisor); }
    this.numeric.initializeBoatOptions(m,this.options);
    this.numeric.initializeRace(m,this.random.gameplay,this.options);
    m.writeI32(0x5363b0,2);m.writeI32(0x53642c,0);m.writeI32(0x5364ac,0);
    for(const address of [...panelFlags,0x536448,0x5363b4])m.writeI32(address,0);
    m.writeI32(0x4da1f4,397);
    for(let index=0;index<=397;index++)this.spawnWave(index);
    this.raceWindow.reset();this.resultsApplied=false;this.saveRequested=false;
    updateWorldState(this.world);
    this.replay=this.checkpoint();
  }
  private spawnWave(index: number): void {
    const m=this.memory,n=this.numeric;
    const port=createWaypointPort(m, {
      number:n.number,integer:n.integer,sinCos:n.sinCos,
      random:span=>n.scaledRandom(span,this.random.waves),
      nearest:(x,y,excluded)=>n.nearest(m,x,y,excluded),
    });
    port.heading=boat=>m.readI32(0x535740+boat*4);
    respawnWaypoint(port,index);
  }

  private applyResults(): void {
    if (this.resultsApplied) return;
    this.resultsApplied = true;
    finalizeResults(this.memory);
  }
}
