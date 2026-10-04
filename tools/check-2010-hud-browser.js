import assert from 'node:assert/strict';
import {writeFile} from 'node:fs/promises';
import {openBrowser} from './browser-session.js';

// Physical canvas input followed by a real paint: the menu/controller tests
// alone never exercised the HUD's tooltip or click-consumption branches.
const base=process.env.TACT_2010_URL??`${process.env.TACT_URL??'http://127.0.0.1:8765'}/versions/2010-en/play.html`;
const results=[];
const scenarios=[{width:1280,height:1050,graphics:'smooth'},
  {width:640,height:720,graphics:'smooth'},{width:1280,height:1050,graphics:'exact'}];
for(const scenario of scenarios){
  const url=new URL(base);url.searchParams.set('graphics',scenario.graphics);
  const browser=await openBrowser(url.href),checks=[];
  let activeControl=null;
  const healthy=async()=>assert.equal(await browser.evaluate('tact.state.error'),null,
    await browser.evaluate('document.getElementById("error").textContent'));
  const read=address=>browser.evaluate(`tact.state.memory.readI32(${address})`);
  const frames=()=>browser.evaluate('tact.state.frames');
  const rendered=async before=>{
    await browser.waitFor(`tact.state.frames>${before+1}||tact.state.error`,60000);
    await healthy();
  };
  const space=async()=>{
    await browser.evaluate('document.getElementById("race").focus()');
    for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{
      type,code:'Space',key:' ',windowsVirtualKeyCode:32,nativeVirtualKeyCode:32});
  };
  const command=async id=>{
    assert.equal(await browser.evaluate(`(()=>{const b=document.querySelector('[data-command="${id}"]');
      if(!b||b.disabled)return false;b.click();return true;})()`),true,`command ${id} enabled`);
    await healthy();
  };
  try{
    await browser.call('Emulation.setDeviceMetricsOverride',{width:scenario.width,height:scenario.height,deviceScaleFactor:1,mobile:false});
    await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);
    await healthy();await browser.waitFor('tact.state.frames>0||tact.state.error',60000);await healthy();
    // Observe rendered button geometry; do not patch state or call handlers.
    await browser.evaluate(`import(new URL('./render/gdi.js',document.querySelector('script[type="module"]').src)).then(({GdiTrace})=>{
      const original=GdiTrace.prototype.emit;
      globalThis.hudProbe={frame:-1,rects:[],buttons:{},texts:[],steeringWrites:[],inputWrites:[]};
      // Beat/tack requests are consumed by the next physics step. Observe the
      // request without replacing the step or changing its timing/state.
      const write=tact.state.memory.writeI32;
      tact.state.memory.writeI32=function(address,value){
        if(address===0x4f7094){hudProbe.steeringWrites.push(value);if(hudProbe.steeringWrites.length>100)hudProbe.steeringWrites.shift();}
        if([0x5233a4,0x4fe75c,0x4da174].includes(address)){hudProbe.inputWrites.push([address,value]);if(hudProbe.inputWrites.length>100)hudProbe.inputWrites.shift();}
        return write.call(this,address,value);
      };
      GdiTrace.prototype.emit=function(event){
        const p=hudProbe;
        if(p.frame!==tact.state.frames){p.frame=tact.state.frames;p.rects=[];p.buttons={};p.texts=[];}
        if(event.op==='roundRect')p.rects.push(event);
        if(event.op==='textOut'){
          p.texts.push(event.text);
          // Native text sits one pixel above the inset rounded border.
          const r=p.rects.findLast(r=>event.x>=r.left&&event.x<r.right&&event.y>=r.top-1&&event.y<r.bottom);
          if(r)p.buttons[event.text.trim()]={...r};
        }
        return original.call(this,event);
      };
    })`);
    await space();
    await browser.waitFor('tact.state.memory.readI32(0x5363b0)>0||tact.state.memory.readI32(0x53648c)===1||tact.state.error',60000);
    await healthy();
    if(await read(0x5363b0)===0)await space();
    await browser.waitFor('tact.state.memory.readI32(0x5363b0)===2||tact.state.error',60000);await healthy();
    const overlays=[0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c];
    if((await Promise.all(overlays.map(read))).some(Boolean))await space();
    if(await read(0x4da1b0)!==1)await command(32967);
    if(await read(0x4da1dc)!==0)await command(32984);
    await rendered(await frames());
    const point=async label=>{
      const result=await browser.evaluate(`(()=>{
        const r=hudProbe.buttons[${JSON.stringify(label)}],c=document.getElementById('race'),b=c.getBoundingClientRect();
        return r?{x:b.x+(r.left+r.right)/2*b.width/c.width,y:b.y+(r.top+r.bottom)/2*b.height/c.height}:null;
      })()`);
      assert.ok(result,`rendered HUD button ${label}: ${JSON.stringify(await browser.evaluate('hudProbe.buttons'))}`);return result;
    };
    const hover=async label=>{
      activeControl=label;
      const p=await point(label);
      await browser.call('Input.dispatchMouseEvent',{type:'mouseMoved',...p});
      await rendered(await frames());return p;
    };
    const click=async label=>{
      const p=await hover(label);
      await browser.evaluate('hudProbe.steeringWrites=[];hudProbe.inputWrites=[]');
      await browser.call('Input.dispatchMouseEvent',{type:'mousePressed',button:'left',buttons:1,clickCount:1,...p});
      await browser.call('Input.dispatchMouseEvent',{type:'mouseReleased',button:'left',buttons:0,clickCount:1,...p});
      await rendered(await frames());
    };
    const speed=await read(0x4da174);
    await hover('faster');
    const tooltip=await browser.evaluate('hudProbe.texts');
    assert.ok(tooltip.some(text=>text.startsWith('Simulator runs 1 unit faster')),`faster tooltip drawn: ${JSON.stringify(tooltip)}`);
    await click('faster');assert.equal(await read(0x4da174),Math.min(15,speed+1),JSON.stringify(await browser.evaluate('hudProbe.inputWrites')));
    await click('slower');assert.equal(await read(0x4da174),speed);
    checks.push({name:'help hover and speed button actions',before:speed,after:await read(0x4da174)});
    const actions=[['beat',0x4f7094,()=>-1],['tack',0x4f7094,()=>1],
      ['reach',0x4fbbac,null],['run',0x4fbbac,()=>1],['sheet',0x500384,null],
      ['shape',0x4fe77c,value=>value%3+1],
      ['left',0x4f49a4,value=>value+30],['right',0x4f49a4,value=>value-30],
      ['astern',0x4f49a4,()=>180],['ahead',0x4f49a4,()=>0],
      ['upwind',0x512d64,()=>1],['dnwind',0x512d64,()=>-1],
      ['hide sail',0x4f41f4,()=>1],['show sail',0x4f41f4,()=>0],
      ['down',null,null],['up',null,null],['view',0x4f71c4,value=>value%3+1]];
    for(const [label,address,expected] of actions){
      const before=address===null?null:await read(address);
      await click(label);
      const after=address===null?null:await read(address);
      if(address===0x4f7094){
        const writes=await browser.evaluate('hudProbe.steeringWrites');
        assert.ok(writes.includes(expected(before)),`${label} steering request: ${JSON.stringify({writes,point:await point(label),hover:[await read(0x5364a0),await read(0x5364a4)],click:[await read(0x4fe75c),await read(0x5233a4)]})}`);
      }
      else if(expected)assert.equal(after,expected(before),`${label} action`);
      else if(address!==null)assert.notEqual(after,before,`${label} changes its control state`);
      checks.push({name:`physical HUD hover and click: ${label}`,before,after,
        assertion:address===null?'painting continues':'control state',passed:true});
    }
    const before=await frames();await rendered(before+20);
    results.push({...scenario,url:url.href,checks,frames:await frames(),passed:true});
    console.log(`HUD ${scenario.graphics} ${scenario.width}x${scenario.height}: ${checks.length} checks passed`);
  }catch(error){
    results.push({...scenario,url:url.href,checks,activeControl,passed:false,error:error.stack});throw error;
  }finally{
    await browser.close();
    if(process.env.TACT_HUD_REPORT)await writeFile(process.env.TACT_HUD_REPORT,JSON.stringify({format:1,results},null,2)+'\n');
  }
}
