export interface WorkPhase {calls:number;totalMs:number;maxMs:number}
export interface WorkProfile {steps:number;totalMs:number;phases:Record<string,WorkPhase>}
/** Opt-in cost attribution on the real worker. Wrappers retain arguments,
 * receiver, return/throw behavior and are removed even after a failed step. */
export function profileNumericalWork(options:Record<string,unknown>,advance:()=>void,steps:number):WorkProfile {
 if(!Number.isInteger(steps)||steps<1||steps>200)throw new RangeError('Work profiling requires1..200 steps');
 const phases:Record<string,WorkPhase>={},restore:Array<()=>void>=[];
 try{
  const previousObserver=options.aiWorkObserver;
  const hadObserver=Object.hasOwn(options,'aiWorkObserver');
  options.aiWorkObserver=(name:string,advance:()=>unknown)=>{
   const phase=phases[name]??={calls:0,totalMs:0,maxMs:0},start=performance.now();
   try{return advance();}finally{const elapsed=performance.now()-start;phase.calls++;phase.totalMs+=elapsed;phase.maxMs=Math.max(phase.maxMs,elapsed);}
  };
  restore.push(()=>{if(!hadObserver)delete options.aiWorkObserver;else options.aiWorkObserver=previousObserver;});
  for(const name of ['updateGlobalWind','updateBoatWindAndAI','updatePlayer1Steering','updatePlayer2Steering','updateBoatDynamics','integratePositions']){
   const original=options[name];if(typeof original!=='function')continue;
   const phase=phases[name]={calls:0,totalMs:0,maxMs:0};
   options[name]=function(this:unknown,...args:unknown[]){
    const start=performance.now();try{return Reflect.apply(original,this,args);}
    finally{const elapsed=performance.now()-start;phase.calls++;phase.totalMs+=elapsed;phase.maxMs=Math.max(phase.maxMs,elapsed);}
   };
   restore.push(()=>{options[name]=original;});
  }
  const start=performance.now();for(let n=0;n<steps;n++)advance();
  return {steps,totalMs:performance.now()-start,phases};
 }finally{for(const reset of restore.reverse())reset();}
}
