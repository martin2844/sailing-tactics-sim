import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';

const output=resolve(process.argv[2]??'');
if(process.argv.length!==3)throw Error('Usage: boat-redesign-capture.mjs NEW_DIRECTORY');
await mkdir(output,{recursive:true});
const browser=await openBrowser('http://127.0.0.1:8771/tools/boat-redesign-gallery.html',{headless:true,gpu:true,requestTimeoutMs:60000});
const views=[['N',0],['NE',45],['E',90],['SE',135],['S',180],['SW',225],['W',270],['NW',315]];
const boats=[['optimist',1],['laser',2],['keelboat',12]];
const rows=[];
try{
 await browser.call('Emulation.setDeviceMetricsOverride',{width:720,height:560,deviceScaleFactor:1,mobile:false});
 await browser.waitFor('globalThis.galleryReady===true',60000);
 for(const [name,id] of boats)for(const [view,bearing] of views){
  const row=await browser.evaluate(`renderBoat(${id},${bearing})`);
  const image=await browser.call('Page.captureScreenshot',{format:'png',captureBeyondViewport:false});
  const filename=`${name}-${view}.png`;
  await writeFile(resolve(output,filename),Buffer.from(image.data,'base64'));
  rows.push({name,view,filename,...row});
 }
 await writeFile(resolve(output,'manifest.json'),JSON.stringify({coordinateSystem:'Model-space compass: N from -Z, E from +X; camera elevation 34 degrees. Same saved original boat samples and same shared mesh as live app.',views:rows},null,2));
 console.log(JSON.stringify({output,views:rows.length,boats:boats.map(([name])=>name)}));
}finally{await browser.close();}
