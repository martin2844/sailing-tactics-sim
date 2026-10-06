import {openBrowser} from '../../../tools/browser-session.js';
import {mkdir,readFile,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const out=resolve(process.argv[2]);await mkdir(out,{recursive:true});
const menu=JSON.parse(await readFile('../2010-en/assets/ui/menus.json','utf8'));
const inventory=[];function collect(items,path=[]){for(const row of items){if(row.items)collect(row.items,[...path,row.text.replaceAll('&','')]);else if(row.command_id)inventory.push({group:path.join(' / '),id:row.command_id,label:row.text.replaceAll('&','')});}}collect(menu[0].items);
await writeFile(resolve(out,'original-menu-inventory.json'),JSON.stringify(inventory,null,2));
const b=await openBrowser('http://127.0.0.1:8770/?manual&fleet=5',{headless:true,gpu:true,requestTimeoutMs:60000});
try{
 await b.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 const result=await b.evaluate(`(async()=>{
 let client,last;try{
 await new Promise((resolve,reject)=>{client=new tact2026.engine.constructor(7913,5,true,{ready:resolve,snapshot:v=>last=v,models:()=>{},paused:()=>{},error:reject},{boat:12,area:32799,course:1,wind:2});});
 // Diagnostics return the whole original address-space image.
 const raw=await client.request('image');const base=0x400000;
 const decode=(bytes,address)=>new DataView(new Uint8Array(bytes).buffer).getInt32(address-base,true);
 const initial={clock:last.clock,tracks:decode(raw,0x53641c),extraFleetInfo:decode(raw,0x536488),slowdown:decode(raw,0x4da1dc)};
 client.send('key',186);const toggled=await client.request('image');
 await client.request('step',200);const sailed=await client.request('image');const flags=Array.from({length:11},(_,i)=>decode(sailed,0x4fb210+i*4));
 const held=await client.request('boundary'),coach=await client.request('information',{kind:'coach'}),after=await client.request('boundary');
 if(JSON.stringify(held)!==JSON.stringify(after))throw Error('Coach inspection mutated game');
 client.send('key',8);await client.request('step',1);const replay=await client.request('boundary');
 return {initial,tracksAfterSemicolon:decode(toggled,0x53641c),extraFleetInfoAfterSemicolon:decode(toggled,0x536488),postPaintCoachFlags:flags,coachText:coach.paragraphs,privateInspectionHeld:true,sailed:held,replayBoundary:replay,snapshotFields:Object.keys(last),boatFields:Object.keys(last.boats[0]),scope:'Diagnostic worker keys verify the backend flag/replay route, not trusted UI input or full feature parity.'};
 }finally{client?.dispose();}
})()`);
 await writeFile(resolve(out,'runtime-probe.json'),JSON.stringify(result,null,2));console.log(JSON.stringify({menuCommands:inventory.length,result}));
}finally{await b.close();}
