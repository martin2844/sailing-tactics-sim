import assert from 'node:assert/strict';
import { readFile,mkdir,writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { openBrowser } from './browser-session.js';
const fixture=JSON.parse(await readFile(new URL('../tests/fixtures/native-system-text.json',import.meta.url),'utf8'));
const source=await readFile(new URL('./capture_system_text.c',import.meta.url));
assert.equal(createHash('sha256').update(source).digest('hex'),fixture.provenance.probeSha256);
const browser=await openBrowser(`${process.env.TACT_URL??'http://127.0.0.1:8765'}/tools/browser-fixture.html`);
try{
  const result=await browser.evaluate(`(async()=>{
    const [{fetchGdiBitmapFont},{createCanvasGdi,colorRefCss},fixture]=await Promise.all([
      import('/src/render/bitmap-font.js'),import('/src/render/gdi.js'),fetch('/tests/fixtures/native-system-text.json').then(response=>response.json()),
    ]);
    const bitmapFont=await fetchGdiBitmapFont(),canvas=document.createElement('canvas');canvas.width=fixture.width;canvas.height=fixture.height;
    const context=canvas.getContext('2d',{willReadFrequently:true}),failures=[];
    for(const [index,row]of fixture.cases.entries()){
      context.fillStyle=colorRefCss(fixture.clearColor);context.fillRect(0,0,canvas.width,canvas.height);
      const dc=createCanvasGdi(context,{bitmapFont});dc.setTextColor(row.textColor);dc.setBkColor(row.backgroundColor);dc.setBkMode(row.backgroundMode);dc.textOut(row.x,row.y,row.text);
      const pixels=context.getImageData(0,0,canvas.width,canvas.height).data;
      const hash=Array.from(new Uint8Array(await crypto.subtle.digest('SHA-256',pixels)),value=>value.toString(16).padStart(2,'0')).join('');
      if(hash!==row.expectedRgbaSha256)failures.push({index,actual:hash,expected:row.expectedRgbaSha256});
      if(index===0)globalThis.fontCheckImage=canvas.toDataURL('image/png');
    }
    return{cases:fixture.cases.length,failures};
  })()`);
  await mkdir(new URL('../analysis/browser-check/',import.meta.url),{recursive:true});
  const png=await browser.evaluate('fontCheckImage');
  await writeFile(new URL('../analysis/browser-check/system-font.png',import.meta.url),Buffer.from(png.split(',')[1],'base64'));
  await writeFile(new URL('../analysis/browser-check/system-font-reference.json',import.meta.url),JSON.stringify(result,null,2)+'\n');
  assert.deepEqual(result.failures,[]);console.log(`${result.cases} native whole-string text rasters exactly match browser RGBA pixels.`);
}finally{await browser.close();}
