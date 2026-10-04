/** Diagnostic scheduler gate. It retains actual scheduled paint callbacks. */
export function deterministicPaintSetupInstrumentation(){
  return `
    globalThis.paintSetupGate=(()=>{
      let holding=true;
      const queue=[],history=[];
      return {
        get holding(){return holding;},
        get queued(){return queue.length;},
        history,
        accept(callback){if(holding)queue.push(callback);else callback();},
        step(label){
          if(!holding||queue.length!==1)throw new Error('Setup requires exactly one held original paint');
          history.push({kind:'paint',label});queue.shift()();
        },
        release(){
          if(!holding||queue.length!==1)throw new Error('Setup release requires exactly one held original paint');
          holding=false;queue.shift()();
        },
      };
    })();
  `;
}

/** Read only; hashes the complete original image while the scheduler is held. */
export function deterministicSetupSnapshotExpression(addresses){
  return `(async()=>{
    const s=tact.state,m=s.memory,bytes=m.bytes.slice();
    const digest=await crypto.subtle.digest('SHA-256',bytes);
    return {frame:s.frames,rngState:s.rng.state,memoryBase:m.base,memorySize:m.size,
      memorySha256:[...new Uint8Array(digest)].map(v=>v.toString(16).padStart(2,'0')).join(''),
      time:m.readF64(${addresses.time}),clock:m.readI32(${addresses.clock}),
      speed:m.readI32(${addresses.speed}),divisor:m.readI32(${addresses.divisor}),
      ${Number.isInteger(addresses.autoSlow)?`autoSlow:m.readI32(${addresses.autoSlow}),`:''}
      racing:m.readI32(${addresses.racing}),mode:m.readI32(${addresses.mode}),
      overlays:${JSON.stringify(addresses.overlays)}.map(address=>({address,value:m.readI32(address)})),
      queued:paintSetupGate.queued,holding:paintSetupGate.holding,error:s.error};
  })()`;
}

/** Copy the final measured image and its metadata synchronously in that paint. */
export function deterministicFinalPaintSnapshotInstrumentation(addresses){
  return `
    if(globalThis.paintMeasurementFinalFrame===globalThis.tact?.state.frames){
      const finalState=tact.state,finalMemory=finalState.memory;
      const finalBytes=finalMemory.bytes.slice();
      const finalSnapshot={frame:finalState.frames,rngState:finalState.rng.state,
        memoryBase:finalMemory.base,memorySize:finalMemory.size,
        time:finalMemory.readF64(${addresses.time}),clock:finalMemory.readI32(${addresses.clock}),
        speed:finalMemory.readI32(${addresses.speed}),divisor:finalMemory.readI32(${addresses.divisor}),
        ${Number.isInteger(addresses.autoSlow)?`autoSlow:finalMemory.readI32(${addresses.autoSlow}),`:''}
        racing:finalMemory.readI32(${addresses.racing}),mode:finalMemory.readI32(${addresses.mode}),
        error:finalState.error};
      globalThis.paintMeasurementFinalSnapshot=crypto.subtle.digest('SHA-256',finalBytes).then(digest=>({
        ...finalSnapshot,
        memorySha256:[...new Uint8Array(digest)].map(v=>v.toString(16).padStart(2,'0')).join(''),
      }));
    }
  `;
}

export function assertDeterministicSetupMatches(candidate,reference){
  for(const key of ['frame','rngState','memoryBase','memorySize','memorySha256']){
    if(candidate.entry[key]!==reference.entry[key])throw new Error(`Deterministic measurement entry differs: ${key}`);
  }
  if(JSON.stringify(candidate.history)!==JSON.stringify(reference.history)){
    throw new Error('Deterministic setup command/paint history differs');
  }
}

/** Diagnostic-only original menu setting, with one actual paint after toggling. */
export async function disableOriginalAutomaticSlowdown(readSetting,command,paint){
  const before=await readSetting();
  if(before===0)return {before,after:0,intervention:null};
  if(before!==1&&before!==2)throw new Error(`Original automatic slowdown has unsupported state ${before}`);
  await command(32984);
  if(await readSetting()!==0)throw new Error('Original menu32984 did not disable automatic slowdown');
  await paint('menu32984 disable automatic slowdown');
  const after=await readSetting();
  if(after!==0)throw new Error('Original automatic slowdown setting changed during its setup paint');
  return {before,after,intervention:{command:32984,label:'Slow Simulator if Foul Likely',paintCount:1}};
}

/** Apply real original commands/input handlers between exact paint boundaries. */
export async function runDeterministicPaintSetup(browser,{addresses,commands,key,afterFastForward,fastForwardClock,noAutoSlow=false}){
  const history=[];
  const liveExpression=`(()=>{const s=tact.state,m=s.memory;return {
    frame:s.frames,clock:m.readI32(${addresses.clock}),time:m.readF64(${addresses.time}),
    racing:m.readI32(${addresses.racing}),mode:m.readI32(${addresses.mode}),notice:m.readI32(${addresses.notice}),
    speed:m.readI32(${addresses.speed}),error:s.error,
    overlays:${JSON.stringify(addresses.overlays)}.map(a=>m.readI32(a))};})()`;
  const live=()=>browser.evaluate(liveExpression);
  const healthy=async()=>{const state=await live();if(state.error)throw new Error(state.error);return state;};
  const waitHeld=async()=>{
    await browser.waitFor('paintSetupGate.queued===1||tact.state.error',60000);
    if(await browser.evaluate('paintSetupGate.queued!==1||!paintSetupGate.holding'))throw new Error('Setup lost its original pending paint');
    await healthy();
  };
  const step=async label=>{
    await waitHeld();await browser.evaluate(`paintSetupGate.step(${JSON.stringify(label)})`);
    const state=await healthy();history.push({kind:'paint',label,...state});return state;
  };
  const command=async id=>{
    await browser.evaluate(`tact.command(${id})`);
    await browser.evaluate('tact.requestPaint()');
    const state=await healthy();history.push({kind:'command',id,...state});return state;
  };
  const space=async label=>{
    await key('Space',' ',32);const state=await healthy();history.push({kind:'key',code:'Space',label,...state});return state;
  };
  await waitHeld();
  const initial=await browser.evaluate(deterministicSetupSnapshotExpression(addresses));
  await step('initial start screen');
  for(const id of commands){await command(id);await step(`menu${id}`);}
  let state=await space('begin');
  if(state.racing===0&&state.mode>0&&state.notice===1)state=await space('acknowledge demo notice');
  for(let attempts=0;state.racing!==2&&attempts<4;attempts++)state=await step('initialize race');
  if(state.racing!==2)throw new Error('Original start handler did not initialize the race');
  if(state.overlays.some(value=>value!==0)){
    await space('dismiss original overlay');state=await step('first unobstructed race paint');
  }
  const autoSlow=noAutoSlow?await disableOriginalAutomaticSlowdown(
    ()=>browser.evaluate(`tact.state.memory.readI32(${addresses.autoSlow})`),command,step):null;
  if(autoSlow)state=await healthy();
  if(afterFastForward){
    state=await command(32973);
    for(let attempts=0;state.clock<fastForwardClock&&attempts<2000;attempts++){
      if(state.speed!==15){
        const error=new Error(`Original fast-forward changed speed to ${state.speed} at clock ${state.clock}`);
        Object.defineProperty(error,'setupHistory',{value:history});throw error;
      }
      state=await step('original speed15 advance');
    }
    if(state.clock<fastForwardClock)throw new Error('Original fast-forward did not reach the requested clock');
    await command(32909);
  }
  await waitHeld();
  const entry=await browser.evaluate(deterministicSetupSnapshotExpression(addresses));
  if(entry.error||entry.racing!==2||entry.overlays.some(row=>row.value!==0)||entry.speed!==10){
    throw new Error('Original deterministic setup did not retain unobstructed speed10 play');
  }
  return {format:1,scope:'Actual original callbacks, menu commands and key handlers; setup retains one scheduled paint between controls. No game memory, RNG or timestep writes. The measurement releases the normal continuous scheduler.',initial,entry,history,
    ...(noAutoSlow?{nativeAutomaticSlowdown: {...autoSlow,requestedOff:true}}:{})};
}
