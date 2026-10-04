import assert from 'node:assert/strict';
import {writeFile,mkdir} from 'node:fs/promises';
import {openBrowser} from './browser-session.js';

const url=process.env.TACT_2010_URL??`${process.env.TACT_URL??'http://127.0.0.1:8765'}/versions/2010-en/play.html`;
const reportName=process.env.TACT_2010_FULL_REPORT??'full-version-browser-check.json';
if(!/^[a-z0-9][a-z0-9-]*\.json$/.test(reportName))throw new Error('Full-version report must be a simple JSON filename');
const report={url,checkedAt:new Date().toISOString(),passed:false,checks:[],performance:[],preparedInput:{preciseTime:261.5,clock:261,scope:'Declared finite input beyond the original 260 integer clock gate after actual original initialization; mode is never written.'}};
const browser=await openBrowser(url);
const inspect=()=>browser.evaluate(`({mode:tact.state.memory.readI32(0x4da16c),app:tact.state.memory.readI32(0x5363b0),frames:tact.state.frames,error:tact.state.error,
  fleet:tact.state.memory.readI32(0x4da194),selector:tact.state.memory.readI32(0x4da144),time:tact.state.memory.readF64(0x5359f0),clock:tact.state.memory.readI32(0x4f8cd0),
  demoScreen:tact.state.memory.readI32(0x5363f4),sessionCount:tact.state.memory.readI32(0x536420),notice:tact.state.memory.readI32(0x53648c),
  paused:tact.state.memory.readI32(0x536444),chart:tact.state.memory.readI32(0x5233a8),forecast:tact.state.memory.readI32(0x5363f0),current:tact.state.memory.readI32(0x536434),tide:tact.state.memory.readI32(0x536438),otherOverlay:tact.state.memory.readI32(0x53644c)})`);
const healthy=async()=>assert.equal(await browser.evaluate('tact.state.error'),null);
const key=async(code,key,keyCode)=>{
  await browser.evaluate('document.getElementById("race").focus()');
  await browser.call('Input.dispatchKeyEvent',{type:'keyDown',code,key,windowsVirtualKeyCode:keyCode,nativeVirtualKeyCode:keyCode});
  await browser.call('Input.dispatchKeyEvent',{type:'keyUp',code,key,windowsVirtualKeyCode:keyCode,nativeVirtualKeyCode:keyCode});
};
try{
  await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);await healthy();
  await browser.waitFor('tact.state.frames>0||tact.state.error',60000);await healthy();
  const initial=await inspect();assert.equal(initial.mode,0);assert.equal(initial.app,0);assert.equal(initial.demoScreen,0);
  report.checks.push({name:'Unmodified supplied full-mode data survives the real constructor',state:initial});
  const fleets=await browser.evaluate(`(async()=>{const rows=[];for(const [id,fleet]of [[32805,2],[32806,5],[32807,10],[32808,15],[32809,20],[32810,25],[32811,30]]){
    const button=document.querySelector('[data-command="'+id+'"]');if(!button||button.disabled)throw Error('Unavailable fleet '+id);
    await tact.command(id);rows.push({id,expected:fleet,actual:tact.state.memory.readI32(0x4da194),mode:tact.state.memory.readI32(0x4da16c)});
  }await tact.command(32805);return rows;})()`);
  for(const row of fleets){assert.equal(row.actual,row.expected);assert.equal(row.mode,0);}report.checks.push({name:'All original fleet choices through 30 boats are available',fleets});
  assert.equal(await browser.evaluate('document.querySelector(\'[data-command="32929"]\').disabled'),false);
  report.checks.push({name:'Original full-mode Same Tack tutorial remains available'});
  await key('Space',' ',32);await browser.waitFor('tact.state.memory.readI32(0x5363b0)===2||tact.state.error',60000);await healthy();
  const started=await inspect();assert.equal(started.mode,0);assert.equal(started.notice,0);
  if(started.paused||started.chart||started.forecast||started.current||started.tide||started.otherOverlay)await key('Space',' ',32);
  await browser.waitFor('!tact.state.memory.readI32(0x536444)&&!tact.state.memory.readI32(0x5233a8)&&!tact.state.memory.readI32(0x5363f0)||tact.state.error',60000);await healthy();
  report.checks.push({name:'Original Space starts without the demo notice',state:await inspect()});
  await browser.evaluate(`(async()=>{
    const play=document.querySelector('script[type="module"]').src;
    const {GdiTrace}=await import(new URL('./render/gdi.js',play));
    const counts={events:0,eventMs:0,getPixel:0,getPixelMs:0,textCalls:0,glyphs:0};globalThis.fullModeGdiCounts=counts;
    const emit=GdiTrace.prototype.emit;GdiTrace.prototype.emit=function(event){counts.events++;if(event.op==='textOut'){counts.textCalls++;counts.glyphs+=Array.from(event.text).length;}const start=performance.now();const value=emit.call(this,event);counts.eventMs+=performance.now()-start;return value;};
    const read=CanvasRenderingContext2D.prototype.getImageData;CanvasRenderingContext2D.prototype.getImageData=function(...args){counts.getPixel++;const start=performance.now();const value=read.apply(this,args);counts.getPixelMs+=performance.now()-start;return value;};
    // Observational counters wrap the existing calls; no drawing or game result changes.
    tact.state.memory.writeF64(0x5359f0,261.5);tact.state.memory.writeI32(0x4f8cd0,261);
    })()`);
  for(let frame=0;frame<2;frame++){
    const sample=await browser.evaluate(`(()=>{for(const key of Object.keys(fullModeGdiCounts))fullModeGdiCounts[key]=0;
      const before={frames:tact.state.frames,time:tact.state.memory.readF64(0x5359f0),clock:tact.state.memory.readI32(0x4f8cd0)};
      const begin=performance.now();tact.paint();return{before,elapsedMs:performance.now()-begin,counts:{...fullModeGdiCounts},after:{frames:tact.state.frames,time:tact.state.memory.readF64(0x5359f0),clock:tact.state.memory.readI32(0x4f8cd0)}};})()`);
    report.performance.push(sample);
    await healthy();const current=await inspect();assert.equal(current.mode,0);assert.equal(current.demoScreen,0);assert.ok(current.time>sample.before.time);assert.ok(current.clock>260);
  }
  report.checks.push({name:'Full mode remains active across two real paints beyond the original 260 clock gate',state:await inspect()});
  const beforeReload=await inspect();await browser.call('Page.reload');
  await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);await healthy();await browser.waitFor('tact.state.frames>0||tact.state.error',60000);await healthy();
  const reloaded=await inspect();assert.equal(reloaded.mode,0);assert.equal(reloaded.demoScreen,0);assert.equal(reloaded.sessionCount,beforeReload.sessionCount);assert.equal(reloaded.fleet,2);assert.equal(reloaded.selector,beforeReload.selector);
  assert.equal(await browser.evaluate('JSON.parse(localStorage.getItem("tact-2010-en-preferences")).length'),636);
  report.checks.push({name:'Saving and reloading 636 preference bytes preserves full mode without incrementing demo sessions',state:reloaded});
  const requests=browser.events.filter(x=>x.method==='Network.requestWillBeSent').map(x=>x.params.request.url);
  assert.deepEqual(requests.filter(x=>/\/tests\/fixtures\/|\.exe(?:$|\?)/.test(x)),[]);
  report.checks.push({name:'Browser runs native JavaScript and data with no EXE/proof requests',requests:requests.length});
  report.passed=true;
}catch(error){report.failure=error.stack??String(error);throw error;}
finally{
  const directory=new URL('../versions/2010-en/analysis/',import.meta.url);await mkdir(directory,{recursive:true});
  await writeFile(new URL(reportName,directory),JSON.stringify(report,null,2)+'\n');await browser.close();
}
console.log(`${report.checks.length} full-version browser checks passed.`);
