import assert from 'node:assert/strict';

/** Measure a trusted click to the changed canvas frame seen at an rAF callback.
 * This is an application response proxy, not physical display latency. It runs
 * after throughput measurement so the geometry observer cannot affect FPS.
 */
export async function measureInputResponse(browser,{edition}){
  const camera=edition==='2010'?0x4f49a4:0x4a460c;
  await browser.evaluate(`import(new URL('./render/gdi.js',document.querySelector('script[type="module"]').src)).then(({GdiTrace})=>{
    const original=GdiTrace.prototype.emit;
    const probe=globalThis.evaluationInput={frame:-1,rects:[],buttons:{},pending:null,results:[],active:true};
    GdiTrace.prototype.emit=function(event){
      if(probe.frame!==tact.state.frames){
        probe.frame=tact.state.frames;probe.cameraAtPaintStart=tact.state.memory.readI32(${camera});
        probe.rects=[];probe.buttons={};
      }
      if(event.op==='roundRect')probe.rects.push(event);
      if(event.op==='textOut'&&['left','right','ahead','astern'].includes(event.text.trim())){
        const r=probe.rects.findLast(r=>event.x>=r.left&&event.x<r.right&&event.y>=r.top-1&&event.y<r.bottom);
        if(r)probe.buttons[event.text.trim()]={...r};
      }
      return original.call(this,event);
    };
    const canvas=document.getElementById('race');
    const onInput=event=>{
      if(!probe.pending||probe.pending.started!==undefined)return;
      Object.assign(probe.pending,{started:event.timeStamp,handled:performance.now(),frameAtInput:tact.state.frames,trusted:event.isTrusted});
    };
    canvas.addEventListener('pointerdown',onInput,true);
    const observe=()=>{
      if(!probe.active)return;
      const p=probe.pending,s=tact.state;
      // HUD consumes clicks after scene drawing; wait until a subsequent paint
      // actually began with the selected camera before declaring it visible.
      if(p?.started!==undefined&&s.frames>p.frameAtInput&&probe.frame===s.frames-1
        &&probe.cameraAtPaintStart===p.expected&&s.memory.readI32(${camera})===p.expected){
        probe.results.push({...p,latencyMs:performance.now()-p.started,completedFrame:s.frames,
          cameraAtPaintStart:probe.cameraAtPaintStart,actual:s.memory.readI32(${camera})});
        probe.pending=null;
      }
      requestAnimationFrame(observe);
    };
    requestAnimationFrame(observe);
    globalThis.restoreEvaluationInput=()=>{probe.active=false;GdiTrace.prototype.emit=original;canvas.removeEventListener('pointerdown',onInput,true);};
  })`);
  try{
    await browser.waitFor('evaluationInput.buttons.left&&evaluationInput.buttons.right&&evaluationInput.buttons.ahead&&evaluationInput.buttons.astern||tact.state.error',20000);
    // Each action must change direction: ahead follows astern on every cycle.
    for(let cycle=0;cycle<3;cycle++)for(const [label,value]of [['left',30],['right',-30],['astern',180],['ahead',0]]){
      const action=await browser.evaluate(`(()=>{
        if(tact.state.error)throw new Error(tact.state.error);
        const r=evaluationInput.buttons[${JSON.stringify(label)}],c=document.getElementById('race'),b=c.getBoundingClientRect();
        const before=tact.state.memory.readI32(${camera});
        const expected=${['left','right'].includes(label)?`before+${value}`:value};
        if(before===expected)throw new Error('Input test requires a changed camera direction');
        evaluationInput.pending={label:${JSON.stringify(label)},before,expected};
        return{x:b.x+(r.left+r.right)/2*b.width/c.width,y:b.y+(r.top+r.bottom)/2*b.height/c.height,count:evaluationInput.results.length};
      })()`);
      await browser.call('Input.dispatchMouseEvent',{type:'mouseMoved',x:action.x,y:action.y});
      await browser.call('Input.dispatchMouseEvent',{type:'mousePressed',button:'left',buttons:1,clickCount:1,x:action.x,y:action.y});
      await browser.call('Input.dispatchMouseEvent',{type:'mouseReleased',button:'left',buttons:0,clickCount:1,x:action.x,y:action.y});
      await browser.waitFor(`evaluationInput.results.length>${action.count}||tact.state.error`,15000);
      assert.equal(await browser.evaluate('tact.state.error'),null);
    }
    const samples=await browser.evaluate('evaluationInput.results');
    assert.equal(samples.length,12);
    assert.ok(samples.every(row=>row.trusted&&row.completedFrame>row.frameAtInput&&row.actual===row.expected&&row.cameraAtPaintStart===row.expected));
    const values=samples.map(row=>row.latencyMs).sort((a,b)=>a-b);
    const percentile=p=>values[Math.max(0,Math.ceil(values.length*p)-1)];
    return {kind:'trusted pointer event to changed completed canvas frame observed at rAF',
      physicalPresentationMeasured:false,count:values.length,mean:values.reduce((a,b)=>a+b,0)/values.length,
      p50:percentile(.5),p95:percentile(.95),p99:percentile(.99),max:values.at(-1),samples};
  }finally{await browser.evaluate('restoreEvaluationInput()').catch(()=>{});}
}
