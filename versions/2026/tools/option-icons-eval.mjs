import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});
const browser=await openBrowser('http://127.0.0.1:8770/',{headless:true,gpu:true,requestTimeoutMs:60000}),checks=[];
async function key(code,value,vk){const text=code==='Enter'?'\r':value.length===1?value:undefined;for(const type of ['keyDown','keyUp'])await browser.call('Input.dispatchKeyEvent',{type,code,key:value,windowsVirtualKeyCode:vk,...(type==='keyDown'&&text?{text}:{})});}
async function click(selector){const point=await browser.evaluate(`(()=>{const e=document.querySelector(${JSON.stringify(selector)});e.scrollIntoView({block:'nearest'});const r=e.getBoundingClientRect();return{x:r.x+r.width/2,y:r.y+r.height/2};})()`);for(const type of ['mousePressed','mouseReleased'])await browser.call('Input.dispatchMouseEvent',{type,...point,button:'left',clickCount:1});}
async function shot(name){await writeFile(resolve(output,name+'.png'),Buffer.from((await browser.call('Page.captureScreenshot',{format:'png'})).data,'base64'));}
try{
 await browser.call('Emulation.setDeviceMetricsOverride',{width:1440,height:1050,deviceScaleFactor:1,mobile:false});
 await browser.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);if(await browser.evaluate('tact2026.error'))throw Error(await browser.evaluate('tact2026.error'));
 const before=await browser.evaluate('tact2026.engine.request("boundary")');
 if(!await browser.evaluate('CSS.supports("appearance","base-select")'))throw Error('Chrome customizable picker unsupported');
 await browser.evaluate(`(()=>{const s=document.getElementById('race-boat');s.value='1';s.dispatchEvent(new Event('change'));})()`);
 await click('#race-boat');await browser.waitFor('document.getElementById("race-boat").matches(":open")');await shot('boat-classes');
 const classes=await browser.evaluate(`Array.from(document.getElementById('race-boat').options).map(o=>({value:o.value,label:o.label,text:o.textContent,icon:o.querySelector('.option-icon').dataset.icon,stroke:o.querySelector('svg').getAttribute('stroke-width')}))`);
 const expected={1:'optimist',2:'laser',4:'snipe',5:'jy15',6:'fiveOhFive',8:'thistle',9:'lightning',11:'tornado',16:'star',17:'aClass',24:'ideal18',25:'etchells',26:'eScow',27:'flyingScot'};
 if(classes.length!==27||classes.some(c=>c.text!==c.label||c.stroke!=='1.2'||expected[c.value]&&c.icon!==expected[c.value]))throw Error('Boat values/labels/emblems changed');
 checks.push({name:'Every boat option has a thin SVG;14 identifiable classes use dedicated marks',classes});
 await click('#race-boat option[value="2"]');await browser.waitFor('document.getElementById("race-boat").value==="2"&&!document.getElementById("race-boat").matches(":open")&&document.getElementById("boat-preview").dataset.boat==="2"');
 if(!await browser.evaluate('document.querySelector("#race-boat").parentElement.querySelector(".select-icon").dataset.icon==="laser"'))throw Error('Closed class icon stale');checks.push({name:'Trusted option click updates chosen class, preview and closed logo'});
 await browser.evaluate(`(()=>{const s=document.getElementById('race-mode');s.value='championship';s.dispatchEvent(new Event('change'));})()`);
 for(const id of ['race-mode','race-area','race-fleet','race-speed','race-wind','race-wind-direction','race-course','series-length']){
  await click('#'+id);await browser.waitFor(`document.getElementById('${id}').matches(':open')`);
  const state=await browser.evaluate(`(()=>{const s=document.getElementById('${id}'),p=getComputedStyle(s,'::picker(select)');return{appearance:p.appearance,options:Array.from(s.options).map(o=>({value:o.value,label:o.label,text:o.textContent,icon:!!o.querySelector('svg'),disabled:o.disabled,rect:o.querySelector('svg').getBoundingClientRect().toJSON()}))};})()`);
  if(state.appearance!=='base-select'||state.options.some(o=>!o.icon||o.text!==o.label||o.rect.width!==22))throw Error('Open option icons missing '+id);
  await shot(id);await key('Escape','Escape',27);await browser.waitFor(`!document.getElementById('${id}').matches(':open')`);checks.push({id,state});
 }
 await browser.evaluate(`document.getElementById('race-boat').focus()`);await key('Enter','Enter',13);await browser.waitFor('document.getElementById("race-boat").matches(":open")');await key('KeyO','o',79);await key('Enter','Enter',13);await browser.waitFor('document.getElementById("race-boat").value==="14"&&!document.getElementById("race-boat").matches(":open")');
 checks.push({name:'Native typeahead and Enter select Offshore racer; no O sail-trim input leaked'});
 await browser.evaluate(`(()=>{const s=document.getElementById('race-area');s.value='33018';s.dispatchEvent(new Event('change'));})()`);
 await browser.waitFor('document.getElementById("race-course").value==="3"');await click('#race-course');await browser.waitFor('document.getElementById("race-course").matches(":open")');
 const disabled=await browser.evaluate('Array.from(document.getElementById("race-course").options).filter(o=>o.disabled).map(o=>o.value)');if(disabled.length!==6)throw Error('Native disabled course compatibility lost');await key('Escape','Escape',27);checks.push({name:'Course compatibility still disables6 options on Block Island',disabled});
 const after=await browser.evaluate('tact2026.engine.request("boundary")');if(JSON.stringify(before)!==JSON.stringify(after))throw Error('Picker interaction changed master');
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,checks,before,after,scope:'Actual Chrome152 native customizable open pickers; all27 class option labels/values/SVGs,14 dedicated class glyphs, all setup fields, trusted pointer selection, Escape, keyboard typeahead/Enter, compatibility-disabled courses and exact held authoritative state. Popup screenshots captured for visual inspection.'},null,2));console.log(JSON.stringify({passed:true,checks:checks.length}));
}catch(error){await shot('failure');await writeFile(resolve(output,'failure.json'),JSON.stringify({error:error.stack,checks,state:await browser.evaluate('({boat:document.getElementById("race-boat").value,open:document.getElementById("race-boat").matches(":open"),focus:document.activeElement.outerHTML.slice(0,500)})')},null,2));throw error;}finally{await browser.close();}
