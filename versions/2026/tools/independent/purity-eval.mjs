import {openBrowser} from '../../../../tools/browser-session.js';
import {mkdir,writeFile} from 'node:fs/promises';
import {resolve} from 'node:path';
const output=resolve(process.argv[2]);await mkdir(output);
const browser=await openBrowser('http://127.0.0.1:8770/?manual',{headless:true,gpu:true,requestTimeoutMs:60000});
const checks=[];
try {
 await browser.waitFor('globalThis.tact2026?.ready||globalThis.tact2026?.error',60000);
 for(const settings of[{boat:12,area:32799,course:1,wind:2},{boat:1,area:32801,course:3,wind:2,windDirection:270},{boat:11,area:32799,course:1,wind:3}]) {
  const result=await browser.evaluate(`(async()=>{
   const clients=[],boundaries=[];
   try{
    for(let n=0;n<2;n++)await new Promise((resolve,reject)=>{
     const client=new tact2026.engine.constructor(9211,5,true,{ready:resolve,snapshot:()=>{},models:()=>{},paused:()=>{},error:reject},${JSON.stringify(settings)});clients.push(client);
    });
    for(let batch=0;batch<20;batch++){
     if([2,5,8,11].includes(batch))for(const client of clients)client.send('key',[84,73,74,79][[2,5,8,11].indexOf(batch)]);
     // The observed run receives private charts, coach, guide and rig work;
     // both runs receive exactly the same ordered sailing inputs and steps.
     const kind=['forecast','wind','current','coach'][batch%4];
     const information=await clients[1].request('information',{kind});if(information.error)throw Error(information.error);
     await clients[1].request('geometry');await clients[1].request('guidecase');
     const [a,b]=await Promise.all(clients.map(c=>c.request('step',100)));
     if(JSON.stringify(a)!==JSON.stringify(b))throw Error('Observation changed future authoritative state at '+batch+' '+JSON.stringify({a,b}));
     boundaries.push(a);
    }
    for(const client of clients){client.send('key',8);client.send('key',70);}
    const [a,b]=await Promise.all(clients.map(c=>c.request('step',20)));
    if(JSON.stringify(a)!==JSON.stringify(b))throw Error('Observation changed replay');
    return {boundaries,replay:a};
   }finally{for(const client of clients)client.dispose();}
  })()`);
  checks.push({settings,...result});console.log(JSON.stringify({passed:true,settings,boundaries:result.boundaries.length}));
 }
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,checks,scope:'Actual paired independent Chrome workers;2000steps and ordered tack/jibe/sheet inputs perconfiguration; extra private forecast/wind/current/coach/guide/model work on one run only, followed by public leg replay. Whole image, gameplay/wave RNG, virtual-string hash, clock, transport frame and retained presentation context match at every boundary. RoundLakeKeelboat, IslandOptimist and strongTornado; bounded continuations rather than completed races.'},null,2));
}catch(error){await writeFile(resolve(output,'failure.json'),JSON.stringify({error:error.stack,checks},null,2));throw error;}finally{await browser.close();}
