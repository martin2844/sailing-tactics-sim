/** Modern finishing rule, measured in the original simulation's seconds.
 * Native rank/score stores remain the source for finishes and championships. */
export class RaceWindow {
 firstFinish?:number;readonly finishes=new Map<number,number>();readonly dnfs=new Set<number>();
 private previousClock?:number;closedByCutoff=false;
 reset(){this.firstFinish=undefined;this.finishes.clear();this.dnfs.clear();this.previousClock=undefined;this.closedByCutoff=false;}
 update(memory:{readI32:(a:number)=>number;writeI32:(a:number,v:number)=>void}){
  const i=(a:number)=>memory.readI32(a),w=(a:number,v:number)=>memory.writeI32(a,v),clock=i(0x4f8cd0),count=i(0x4da194);
  if(this.previousClock!==undefined&&clock<this.previousClock)this.reset();
  this.previousClock=clock;
  if(clock<0||i(0x5363b0)!==2)return false;
  for(let id=1;id<=count;id++){
   const rank=i(0x4fe638+id*4);
   if(rank>0&&rank<=count&&!this.finishes.has(id)){this.finishes.set(id,clock);this.firstFinish??=clock;}
  }
  if(i(0x5363f4)!==0||this.firstFinish===undefined||clock<this.firstFinish+1200)return false;
  for(let id=1;id<=count;id++)if(i(0x4fe638+id*4)===0){
   // Native human finishes retain the pace used by the results/next-race
   // routines. The modern DNF transition must retain it as well.
   if(id<=i(0x4da140)){w(0x522f20,i(0x4da174));w(0x5362f0,i(0x4da178));}
   this.dnfs.add(id);w(0x4fe638+id*4,count+1);w(0x4f8538+id*4,i(0x4da1e4)+1);
   w(0x5116e0+id*4,11);w(id===1?0x534d64:0x4f4350+id*4,30000);
  }
  this.closedByCutoff=true;w(0x5363f4,1);w(0x5363fc,i(0x5363fc)+1);
  return true;
 }
 state(clock:number){return {firstFinish:this.firstFinish,deadline:this.firstFinish===undefined?undefined:this.firstFinish+1200,remaining:this.firstFinish===undefined?undefined:Math.max(0,this.firstFinish+1200-clock),closedByCutoff:this.closedByCutoff};}
}
