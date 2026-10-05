import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const out=resolve(process.argv[2]??'');if(process.argv.length!==3)throw new Error('Usage: native-visual-eval.mjs NEW_DIRECTORY');await mkdir(out);const runs=[];
for(const fleet of [5,15]){
 const b=await openBrowser(`http://127.0.0.1:8770/?manual&fleet=${fleet}`,{headless:true,gpu:true,requestTimeoutMs:60000});
 try{
  await b.call('Emulation.setDeviceMetricsOverride',{width:1280,height:1050,deviceScaleFactor:1,mobile:false});await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);if(await b.evaluate('tact2026.error'))throw new Error(await b.evaluate('tact2026.error'));
  const comparisons=[];
  for(let index=0;index<3;index++){
   if(index){await b.evaluate(`tact2026.engine.send('command',${index===1?32842:32841})`);await b.evaluate('tact2026.engine.request("step",8)');}
   const result=await b.evaluate(`(async()=>{
    const drawing=await tact2026.engine.request('model'),current=tact2026.latest.nativeVisuals;
    const {createCanvasGdi}=await import('/legacy/src/render/gdi.js');
    const reference=new OffscreenCanvas(drawing.width,drawing.height),ctx=reference.getContext('2d',{willReadFrequently:true}),dc=createCanvasGdi(ctx,{recordEvents:false});
    ctx.save();ctx.beginPath();ctx.rect(0,0,drawing.width,drawing.height);ctx.clip();
    const counts={};
    for(const boat of drawing.boats)for(const p of boat.primitives){counts[p.op]=(counts[p.op]??0)+1;dc.pen=p.pen;dc.brush=p.brush;
     if(p.op==='polygon')dc.polygon(p.points);else if(p.op==='lineTo'){dc.position=p.from;dc.lineTo(p.x,p.y);}else if(p.op==='ellipse')dc.ellipse(p.left,p.top,p.right,p.bottom);else if(p.op==='setPixel')dc.setPixel(p.x,p.y,p.color);else throw new Error('Unreviewed primitive '+p.op);
    }ctx.restore();
    const layer=tact2026.scene.nativeBoats;layer.draw(1,drawing.width,drawing.height);
    const actual=layer.canvas.getContext('2d').getImageData(0,0,drawing.width,drawing.height).data,expected=ctx.getImageData(0,0,drawing.width,drawing.height).data;
    let differentBytes=0,visiblePixels=0;for(let i=0;i<actual.length;i++){if(actual[i]!==expected[i])differentBytes++;if(i%4===3&&expected[i])visiblePixels++;}
    const hash=async a=>[...new Uint8Array(await crypto.subtle.digest('SHA-256',a))].map(v=>v.toString(16).padStart(2,'0')).join('');
    return {sequence:tact2026.latest.sequence,width:drawing.width,height:drawing.height,boats:drawing.boats.map(v=>v.id),counts,differentBytes,visiblePixels,actualSha256:await hash(actual),referenceSha256:await hash(expected),packetBytes:current.geometry.byteLength+current.styles.byteLength+current.boats.byteLength,snapshotBytes:tact2026.snapshotBytes.at(-1)};
   })()`);
   if(result.differentBytes||result.visiblePixels<1000)throw new Error('Native boat replay differs: '+JSON.stringify(result));comparisons.push(result);
  }
  await writeFile(resolve(out,`boats-${fleet}.png`),Buffer.from((await b.call('Page.captureScreenshot',{format:'png'})).data,'base64'));
  runs.push({fleet,comparisons});
 }catch(error){await writeFile(resolve(out,'failure.txt'),error.stack);throw error;}finally{await b.close();}
}
await writeFile(resolve(out,'verification.json'),JSON.stringify({passed:true,scope:'Original observed boat vector primitives vs original GDI sink, exact RGBA at alpha 1; original painter projection, not rebuilt 3D geometry',runs},null,2));console.log(JSON.stringify(runs));
