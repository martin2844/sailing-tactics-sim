/** Elapsed cosmetic time, independent of simulation speed and packet cadence.
 * Pause/resume rebases sampling, so hidden tabs and held panels add no debt. */
export class AnimationClock {
 private seconds=0;
 private sampled?:number;
 private paused=true;
 setPaused(value:boolean):void {if(value!==this.paused){this.paused=value;this.sampled=undefined;}}
 reset():void {this.seconds=0;this.sampled=undefined;}
 sample(now:number):number {
  if(!Number.isFinite(now))throw new RangeError('Animation time must be finite');
  if(this.sampled!==undefined&&!this.paused)this.seconds+=Math.max(0,now-this.sampled)/1000;
  this.sampled=now;return this.seconds;
 }
}
