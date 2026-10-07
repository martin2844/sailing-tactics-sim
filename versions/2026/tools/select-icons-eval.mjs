import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
import {gzipSync} from 'node:zlib';
import {iconBodies,iconSvg} from '../app/ui/icons.ts';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});
const icons=Object.keys(iconBodies).map(name=>({name,bytes:Buffer.byteLength(iconSvg(name))}));
const svgSet=Object.keys(iconBodies).map(name=>iconSvg(name)).join('');
for(const name of Object.keys(iconBodies))if(iconSvg(name)!==iconSvg(name))throw Error('Nondeterministic icon');
const browser=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true,requestTimeoutMs:60000}),checks=[];
async function select(id,value,expected){
 await browser.evaluate(`(()=>{const s=document.getElementById('${id}');s.value='${value}';s.dispatchEvent(new Event('change'));})()`);
 await browser.waitFor(`document.getElementById('${id}').parentElement.querySelector('.select-icon').dataset.icon==='${expected}'`);
 checks.push({id,value,icon:expected});
}
async function shot(name){await writeFile(resolve(output,name+'.png'),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));}
try{
 await browser.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});
 await browser.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);if(await browser.evaluate('tact2026.error'))throw Error(await browser.evaluate('tact2026.error'));
 await browser.waitFor('document.getElementById("boat-preview").dataset.state==="ready"');
 const before=await browser.evaluate('tact2026.engine.request("boundary")');
 const wrappers=await browser.evaluate(`Array.from(document.querySelectorAll('.select-control')).map(w=>({id:w.querySelector('select').id,count:w.querySelectorAll('select').length,decorative:Array.from(w.querySelectorAll('svg')).every(s=>s.getAttribute('aria-hidden')==='true'&&s.getAttribute('focusable')==='false'),viewboxes:Array.from(w.querySelectorAll('svg')).map(s=>s.getAttribute('viewBox'))}))`);
 if(wrappers.length!==11||wrappers.some(w=>w.count!==1||!w.decorative||w.viewboxes.some(box=>box!=='0 0 24 24')))throw Error('Select structure changed');
 await shot('starter-default');
 for(const [value,icon]of [[1,'dinghy'],[3,'board'],[11,'catamaran'],[12,'keelboat']])await select('race-boat',value,icon);
 for(const [value,icon]of [[32799,'lake'],[32801,'island'],[32803,'river'],[33016,'pin']])await select('race-area',value,icon);
 for(const [index,icon]of ['windward','windwardTwice','triangle','triangleTwice','gold','downwind','downwindTwice'].entries())await select('race-course',index+1,icon);
 for(const [value,icon]of [[1,'breeze'],[2,'wind'],[3,'gust']])await select('race-wind',value,icon);
 for(const value of ['auto',0,45,90,135,180,225,270,315]){
  await select('race-wind-direction',value,'compass');
  await browser.waitFor(`(()=>{const g=document.querySelector('#race-wind-direction').parentElement.querySelector('.select-icon g');return ${value==='auto'?'!g':`g?.getAttribute('transform')==='rotate(${value} 12 12)'`};})()`);
 }
 await select('race-mode','championship','trophy');await select('series-length',5,'series');await shot('starter-championship');
 await select('race-mode','race','flag');await select('race-area',32799,'lake');await select('race-course',1,'windward');await select('race-wind',2,'wind');await select('race-wind-direction','auto','compass');
 // Real browser keyboard selection is still handled by the native select.
 await browser.evaluate(`document.getElementById('race-wind').focus()`);
 for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code:'ArrowDown',key:'ArrowDown',windowsVirtualKeyCode:40});
 await browser.waitFor('document.getElementById("race-wind").value==="3"&&document.querySelector("#race-wind").parentElement.querySelector(".select-icon").dataset.icon==="gust"');
 checks.push({name:'Trusted ArrowDown changes native select and its icon'});await select('race-wind',2,'wind');
 const after=await browser.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Decorated setup changed authoritative state');
 const layouts=[];
 for(const [width,height]of [[1440,1050],[1280,900],[768,1024],[390,844]]){
  await browser.call('Emulation.setDeviceMetricsOverride',{width,height,deviceScaleFactor:1,mobile:false});
  const layout=await browser.evaluate(`(()=>{const rect=document.getElementById('race-form').getBoundingClientRect(),selects=Array.from(document.querySelectorAll('#race-form .select-control')).filter(w=>w.getClientRects().length).map(w=>{const s=w.querySelector('select'),r=s.getBoundingClientRect(),icon=w.querySelector('.select-icon').getBoundingClientRect(),arrow=w.querySelector('.select-chevron').getBoundingClientRect(),style=getComputedStyle(s);return{id:s.id,width:r.width,left:r.x,right:r.right,content:r.width-parseFloat(style.paddingLeft)-parseFloat(style.paddingRight),iconRight:icon.right,arrowLeft:arrow.x};});return{width:innerWidth,scrollWidth:document.documentElement.scrollWidth,form:{top:rect.y,left:rect.x,right:rect.right},selects};})()`);
  if(layout.scrollWidth>width||layout.form.left<0||layout.form.right>width||layout.form.top<0||layout.selects.some(s=>s.content<38||s.iconRight>=s.arrowLeft))throw Error('Icon/control overlap '+JSON.stringify(layout));layouts.push(layout);await shot('starter-'+width);
 }
 await browser.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});
 const start=await browser.evaluate(`(()=>{const r=document.getElementById('start-race').getBoundingClientRect();return{x:r.x+r.width/2,y:r.y+r.height/2};})()`);
 for(const type of ['mousePressed','mouseReleased'])await browser.call('Input.dispatchMouseEvent',{type,...start,button:'left',clickCount:1});
 await browser.waitFor('document.getElementById("starter").hidden&&!tact2026.paused&&tact2026.ready',60000);
 await browser.evaluate(`(()=>{const s=document.getElementById('pace');s.focus();s.value='32876';s.dispatchEvent(new Event('change'));})()`);
 await browser.waitFor('tact2026.latest.configuration.speed===5&&document.activeElement.id==="scene"');
 for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code:'Space',key:' ',windowsVirtualKeyCode:32});
 await browser.waitFor('tact2026.latest.pace===1');
 for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code:'Space',key:' ',windowsVirtualKeyCode:32});
 await browser.waitFor('tact2026.latest.pace===5');
 for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code:'KeyF',key:'f',windowsVirtualKeyCode:70});
 await browser.waitFor('tact2026.paused');checks.push({name:'Trusted race start, decorated live pace, sailing focus and Space1/5 toggle still work'});
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,icons,rawSvgBytes:Buffer.byteLength(svgSet),gzipSvgBytes:gzipSync(svgSet).length,checks,wrappers,layouts,before,after,scope:'Actual Chrome setup selectors: deterministic authored SVG family, dynamic boat/venue/wind/course/event/compass icons, native keyboard selection, decorative accessibility, responsive bounds and exact authoritative state held through setup changes; trusted race start and live pace/focus/Space regression. Narrow layouts inspected in desktop Chrome, not Pixel acceptance.'},null,2));
 console.log(JSON.stringify({passed:true,checks:checks.length,icons:icons.length,rawSvgBytes:Buffer.byteLength(svgSet),gzipSvgBytes:gzipSync(svgSet).length}));
}catch(error){await shot('failure');await writeFile(resolve(output,'failure.json'),JSON.stringify({error:error.stack,checks},null,2));throw error;}finally{await browser.close();}
