/** Optional observation of completed canvas frames at browser rendering opportunities. */
export function presentationMeasurementInstrumentation(timeAddress){
  return `
    globalThis.presentationMeasurements=[];
    let presentationActive=false;
    const observePresentation=timestamp=>{
      if(!presentationActive)return;
      const state=globalThis.tact?.state;
      presentationMeasurements.push({timestamp,sampledAt:performance.now(),frame:state?.frames,
        time:state?.memory?.readF64(${timeAddress})});
      requestAnimationFrame(observePresentation);
    };
    globalThis.startPresentationMeasurements=()=>{
      presentationMeasurements=[];presentationActive=true;requestAnimationFrame(observePresentation);
    };
    globalThis.stopPresentationMeasurements=()=>{presentationActive=false;};
  `;
}

export function summarizePresentation(rows,firstFrame,lastFrame){
  const selected=rows.filter(row=>Number.isInteger(row.frame)&&row.frame>=firstFrame&&row.frame<=lastFrame);
  const unique=[];let repeated=0,largestFrameJump=0;
  for(const row of selected){
    const previous=unique.at(-1);
    if(previous?.frame===row.frame){repeated++;continue;}
    if(previous)largestFrameJump=Math.max(largestFrameJump,row.frame-previous.frame);
    unique.push(row);
  }
  const visible=unique.filter(row=>row.frame>firstFrame);
  const intervals=visible.slice(1).map((row,index)=>row.sampledAt-visible[index].sampledAt);
  const sorted=[...intervals].sort((a,b)=>a-b);
  const uniqueFrames=new Set(visible.map(row=>row.frame)).size;
  const elapsed=visible.length>1?(visible.at(-1).sampledAt-visible[0].sampledAt)/1000:0;
  return {
    scope:'Completed-frame ids sampled by requestAnimationFrame at browser rendering opportunities. This observes canvas availability and main-thread cadence; it does not prove physical monitor/compositor presentation.',
    firstFrame,lastFrame,renderedUpdates:lastFrame-firstFrame,renderingOpportunities:selected.length,
    distinctCompletedFramesSampled:uniqueFrames,repeatedFrameOpportunities:repeated,
    renderedUpdatesWithoutSample:Math.max(0,lastFrame-firstFrame-uniqueFrames),largestFrameJump,
    sampledContentFramesPerSecond:elapsed?(visible.length-1)/elapsed:null,
    contentInterval:{meanMs:intervals.length?intervals.reduce((a,b)=>a+b,0)/intervals.length:null,
      medianMs:sorted.length?sorted[Math.floor(sorted.length/2)]:null,maxMs:sorted.at(-1)??null},
    finalFence:rows.find(row=>row.frame>=lastFrame)??null,samples:selected,
  };
}
