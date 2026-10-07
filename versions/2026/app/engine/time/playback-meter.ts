/** Observes achieved game seconds per wall second without changing deadlines,
 * numerical state or the selected pace. Holds and rate changes rebase samples. */
export class PlaybackRateMeter {
 private anchor?:{wall:number;game:number};
 private actualRate?:number;
 private limited=false;
 reset(now:number,gameTime:number):void {
  this.anchor={wall:now,game:gameTime};this.actualRate=undefined;this.limited=false;
 }
 sample(now:number,gameTime:number,target:number):void {
  if(!this.anchor||gameTime<this.anchor.game||now<this.anchor.wall){this.reset(now,gameTime);return;}
  const elapsed=now-this.anchor.wall;
  if(elapsed<2000)return;
  if(gameTime===this.anchor.game){this.reset(now,gameTime);return;}
  const measured=(gameTime-this.anchor.game)*1000/elapsed;
  this.actualRate=this.actualRate===undefined?measured:(this.actualRate+measured)/2;
  if(this.actualRate<target*.85)this.limited=true;
  else if(this.actualRate>=target*.95)this.limited=false;
  this.anchor={wall:now,game:gameTime};
 }
 state():{actualRate?:number;limited?:boolean} {
  return this.actualRate===undefined?{}:{actualRate:this.actualRate,limited:this.limited};
 }
}
