import assert from 'node:assert/strict';
import {readFile,writeFile,mkdir} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {resolve} from 'node:path';
import {openBrowser} from '../browser-session.js';

const output=process.env.TACT_FONT_REPORT??'versions/2010-en/analysis/browser-performance/software-font-atlas.json';
const browser=await openBrowser(`${process.env.TACT_URL??'http://127.0.0.1:8765'}/tools/browser-fixture.html`,{headless:false,gpu:true,width:1280,height:1051});
try{
  const result=await browser.evaluate(`(async()=>{
    const [{fetchGdiBitmapFont},{createCanvasGdi,colorRefCss},fixture]=await Promise.all([
      import('/src/render/bitmap-font.js'),import('/src/render/gdi.js'),fetch('/tests/fixtures/native-system-text.json').then(r=>r.json()),
    ]);
    const fonts=await Promise.all([fetchGdiBitmapFont(),fetchGdiBitmapFont({softwareAtlas:true})]);
    const canvas=document.createElement('canvas');canvas.width=fixture.width;canvas.height=fixture.height;
    const context=canvas.getContext('2d',{willReadFrequently:true}),failures=[];
    const digest=async bytes=>Array.from(new Uint8Array(await crypto.subtle.digest('SHA-256',bytes)),v=>v.toString(16).padStart(2,'0')).join('');
    for(const [index,row]of fixture.cases.entries())for(const [mode,bitmapFont]of fonts.entries()){
      context.reset();context.fillStyle=colorRefCss(fixture.clearColor);context.fillRect(0,0,canvas.width,canvas.height);
      const dc=createCanvasGdi(context,{bitmapFont});dc.setTextColor(row.textColor);dc.setBkColor(row.backgroundColor);dc.setBkMode(row.backgroundMode);dc.textOut(row.x,row.y,row.text);
      const actual=await digest(context.getImageData(0,0,canvas.width,canvas.height).data);
      if(actual!==row.expectedRgbaSha256)failures.push({index,softwareAtlas:mode===1,actual,expected:row.expectedRgbaSha256});
    }
    return {cases:fixture.cases.length,comparisons:fixture.cases.length*2,failures};
  })()`);
  assert.deepEqual(result.failures,[],'Font atlas backend changed native reference pixels');
  const pins={};
  for(const path of ['src/render/bitmap-font.js','versions/2010-en/src/play.js','tests/fixtures/native-system-text.json'])
    pins[path]=createHash('sha256').update(await readFile(path)).digest('hex');
  const report={at:new Date().toISOString(),scope:'Headed GPU browser: original and software font atlases each compared against all native whole-string RGBA captures. Correctness only, excluded from performance comparisons.',launch:browser.metadata,pins,...result};
  await mkdir(resolve(output,'..'),{recursive:true});await writeFile(output,JSON.stringify(report,null,2)+'\n');
  console.log(`${result.comparisons} headed GPU font comparisons match native pixels.`);
}finally{await browser.close();}
