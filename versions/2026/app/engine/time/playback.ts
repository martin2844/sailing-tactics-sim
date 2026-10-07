import {defaultSimulatorSpeed,speedCommand,speedForCommand,validateSimulatorSpeed} from '../speed.ts';

export const playbackRates=[1,2,4,8] as const;
export type PlaybackRate=typeof playbackRates[number];
export type PlaybackChoice={mode:'clock';rate:PlaybackRate}|{mode:'legacy';level:number};
export interface PlaybackState {selected:PlaybackChoice;active:PlaybackChoice}
/** Keep the recovered level6 numerical timestep/maneuvers; clock mode changes
 * host deadlines. Numerical steps are neither divided nor skipped. */
export const clockNativeSpeed=6;
export const defaultPlayback:PlaybackChoice={mode:'clock',rate:1};

export function validatePlayback(value:unknown):PlaybackChoice {
 if(!value||typeof value!=='object')throw new TypeError('Invalid playback setting');
 const choice=value as {mode?:unknown;rate?:unknown;level?:unknown};
 if(choice.mode==='clock'&&playbackRates.includes(choice.rate as PlaybackRate))return {mode:'clock',rate:choice.rate as PlaybackRate};
 if(choice.mode==='legacy')return {mode:'legacy',level:validateSimulatorSpeed(choice.level)};
 throw new RangeError('Unsupported playback setting');
}
export function playbackValue(choice:PlaybackChoice,footer=false):string {
 return choice.mode==='clock'?'clock:'+choice.rate:String(footer?speedCommand(choice.level):choice.level);
}
export function parsePlaybackValue(value:string,footer=false):PlaybackChoice {
 if(value.startsWith('clock:'))return validatePlayback({mode:'clock',rate:Number(value.slice(6))});
 return validatePlayback({mode:'legacy',level:footer?speedForCommand(Number(value)):Number(value)});
}
export function playbackLabel(choice:PlaybackChoice):string {
 return choice.mode==='clock'?choice.rate+'×':'OG level '+choice.level;
}
export function nativePlaybackSpeed(choice:PlaybackChoice):number {
 return choice.mode==='clock'?clockNativeSpeed:choice.level;
}

/** Worker deadlines are separate from authoritative numerical state. Target
 * rates do not depend on renderer callbacks; large stalls discard wall-time
 * debt rather than creating a burst through a paused/tab-hidden interval. */
export class PlaybackPacer {
 private selected:PlaybackChoice={mode:'legacy',level:defaultSimulatorSpeed};
 private precision=false;
 private anchor?:{wall:number;game:number};
 private previousGame?:number;
 get mode(){return this.selected.mode;}
 configure(value:unknown,now:number,gameTime:number):void {
  this.selected=validatePlayback(value);this.precision=false;this.reset(now,gameTime);
 }
 reset(now:number,gameTime:number):void {
  this.anchor={wall:now,game:gameTime};this.previousGame=gameTime;
 }
 beginRace(now:number,gameTime:number):void {this.precision=false;this.reset(now,gameTime);}
 state(nativeSelected:number,nativeActive:number):PlaybackState {
  if(this.selected.mode==='legacy')return {selected:{mode:'legacy',level:nativeSelected},active:{mode:'legacy',level:nativeActive}};
  return {selected:{...this.selected},active:{mode:'clock',rate:this.precision?1:this.selected.rate}};
 }
 togglePrecision(now:number,gameTime:number):void {
  if(this.selected.mode!=='clock')return;
  this.precision=this.selected.rate!==1&&!this.precision;this.reset(now,gameTime);
 }
 slowForWarning(now:number,gameTime:number):void {
  if(this.selected.mode==='clock'&&!this.precision&&this.selected.rate!==1){this.precision=true;this.reset(now,gameTime);}
 }
 adjustRate(direction:1|-1,now:number,gameTime:number):void {
  if(this.selected.mode!=='clock')return;
  const current=this.precision?1:this.selected.rate;
  const index=Math.max(0,Math.min(playbackRates.length-1,playbackRates.indexOf(current)+direction));
  this.configure({mode:'clock',rate:playbackRates[index]},now,gameTime);
 }
 delay(now:number,gameTime:number,nativeDelay:number,workMs:number):number {
  if(this.selected.mode==='legacy')return Math.max(0,nativeDelay-workMs);
  if(!this.anchor||this.previousGame===undefined||gameTime<this.previousGame)this.reset(now,gameTime);
  if(gameTime===this.previousGame){this.reset(now,gameTime);return 80;}
  this.previousGame=gameTime;
  const rate=this.precision?1:this.selected.rate;
  const remaining=this.anchor!.wall+(gameTime-this.anchor!.game)*1000/rate-now;
  // Timer jitter can catch up. A long stall slows elapsed gameplay instead
  // of running an unbounded backlog or silently skipping numerical steps.
  if(remaining< -250){this.reset(now,gameTime);return 0;}
  return Math.max(0,remaining);
 }
}
