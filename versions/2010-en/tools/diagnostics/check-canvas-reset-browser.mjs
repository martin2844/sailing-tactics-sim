import assert from 'node:assert/strict';
import {readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {openBrowser} from '../../../../tools/browser-session.js';

const browser=await openBrowser(`${process.env.TACT_URL??'http://127.0.0.1:8765'}/versions/2010-en/play.html`);
try{
  await browser.waitFor('globalThis.tact?.state.ready||globalThis.tact?.state.error',60000);
  assert.equal(await browser.evaluate('tact.state.error'),null);
  const key=async()=>{
    for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code:'Space',key:' ',windowsVirtualKeyCode:32,nativeVirtualKeyCode:32});
  };
  await key();await browser.waitFor('tact.state.memory.readI32(0x5363b0)===2||tact.state.error',60000);
  if(await browser.evaluate('[0x536444,0x5363f0,0x5233a8,0x536434,0x536438,0x53644c].some(a=>tact.state.memory.readI32(a)!==0)'))await key();
  const before=await browser.evaluate('tact.state.frames');
  await browser.waitFor(`tact.state.frames>${before+2}||tact.state.error`,60000);
  assert.equal(await browser.evaluate('tact.state.error'),null);
  const result=await browser.evaluate(`(async()=>{
    tact.state.closed=true;
    const {resetBitmapSurface}=await import('/versions/2010-en/src/runtime/canvas-surface.js');
    const digest=async bytes=>Array.from(new Uint8Array(await crypto.subtle.digest('SHA-256',bytes)),n=>n.toString(16).padStart(2,'0')).join('');
    const raster=context=>context.getImageData(0,0,context.canvas.width,context.canvas.height).data;
    const dirty=context=>{
      context.fillStyle='#4f8eaf';context.fillRect(0,0,128,96);
      context.save();context.translate(17,11);context.rotate(.2);
      context.beginPath();context.rect(0,0,3,4);context.clip();
      context.globalAlpha=.3;context.globalCompositeOperation='xor';
      context.lineWidth=7;context.setLineDash([2,3]);context.shadowBlur=9;
      context.shadowColor='#ff0000';context.filter='blur(1px)';
      context.font='bold 24px serif';context.textAlign='right';context.textBaseline='top';
    };
    const properties=context=>({transform:Array.from(context.getTransform().toFloat64Array()),
      alpha:context.globalAlpha,composite:context.globalCompositeOperation,dash:context.getLineDash(),
      lineWidth:context.lineWidth,shadowBlur:context.shadowBlur,shadowColor:context.shadowColor,
      filter:context.filter,font:context.font,textAlign:context.textAlign,textBaseline:context.textBaseline});
    const cases=[];
    for(const fallback of [false,true])for(const [width,height]of [[128,96],[71,53],[128,96]]){
      const pair=[document.createElement('canvas'),document.createElement('canvas')];
      for(const canvas of pair){canvas.width=128;canvas.height=96;}
      const contexts=pair.map(canvas=>canvas.getContext('2d',{willReadFrequently:true}));
      if(fallback)Object.defineProperty(contexts[1],'reset',{value:undefined});
      contexts.forEach(dirty);
      pair[0].width=width;pair[0].height=height;contexts[0].font='13px Arial';
      resetBitmapSurface(pair[1],contexts[1],width,height);
      const expectedProperties=properties(contexts[0]),actualProperties=properties(contexts[1]);
      const cleared=await Promise.all(contexts.map(context=>digest(raster(context))));
      for(const context of contexts){
        context.restore();context.fill(); // No saved state or current path survives.
        context.fillStyle='#31c45a';context.fillRect(0,0,width,height);
        context.strokeStyle='#ffffff';context.beginPath();context.moveTo(0,0);context.lineTo(width,height);context.stroke();
        context.fillStyle='#aa2070';context.fillText('Sailing tactics',9,27);
      }
      const painted=await Promise.all(contexts.map(context=>digest(raster(context))));
      cases.push({fallback,width,height,expectedProperties,actualProperties,cleared,painted});
    }
    const display=[document.createElement('canvas'),document.createElement('canvas')];
    for(const canvas of display){canvas.width=tact.dimensions.width;canvas.height=document.getElementById('race').height;}
    const displayContexts=[display[0].getContext('2d',{willReadFrequently:true}),display[1].getContext('2d')];
    for(const context of displayContexts)context.drawImage(document.getElementById('race'),0,0);
    const displayHashes=await Promise.all(displayContexts.map(context=>digest(raster(context))));
    return {cases,displayHashes,visibleContextAttributes:document.getElementById('race').getContext('2d').getContextAttributes(),
      frameCount:tact.state.frames,simulationClock:tact.state.memory.readF64(0x5359c0),error:tact.state.error};
  })()`);
  for(const row of result.cases){
    assert.deepEqual(row.actualProperties,row.expectedProperties);
    assert.equal(row.cleared[1],row.cleared[0]);assert.equal(row.painted[1],row.painted[0]);
  }
  assert.equal(result.displayHashes[1],result.displayHashes[0]);
  assert.equal(result.visibleContextAttributes.willReadFrequently,false);
  assert.equal(result.error,null);
  const paths=['versions/2010-en/src/play.js','versions/2010-en/src/runtime/canvas-surface.js'];
  const sourcePins=await Promise.all(paths.map(async path=>({path,sha256:createHash('sha256').update(await readFile(path)).digest('hex')})));
  await writeFile('versions/2010-en/analysis/browser-performance/canvas-reset-review.json',JSON.stringify({checkedAt:new Date().toISOString(),scope:'Six actual-browser raster/state reset comparisons including compatibility fallback and size changes; production race startup and exact visible-blit comparison. This is correctness evidence, not a throughput benchmark.',sourcePins,...result},null,2)+'\n');
  console.log('Six real canvas reset/state/raster cases, visible blit and actual race startup passed.');
}finally{await browser.close();}
