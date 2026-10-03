import { spawn } from 'node:child_process';
import { mkdtemp,rm } from 'node:fs/promises';
import { tmpdir } from 'node:os';
import { join } from 'node:path';
import { setTimeout as pause } from 'node:timers/promises';

/** Local Chrome session for native JS rendering and input comparisons. */
export async function openBrowser(url){
  const profile=await mkdtemp(join(tmpdir(),'tact-browser-'));
  const chrome=spawn(process.env.TACT_CHROME??'/etc/profiles/per-user/martin/bin/google-chrome',[
    '--headless=new','--disable-gpu','--no-sandbox','--remote-debugging-port=0','--no-first-run',`--user-data-dir=${profile}`,'about:blank',
  ],{stdio:['ignore','ignore','pipe']});
  let stderr='',socket;
  try{
    const endpoint=await new Promise((resolve,reject)=>{
      const timeout=setTimeout(()=>reject(new Error('Chrome did not start DevTools')),20000);
      chrome.once('error',reject);chrome.once('exit',code=>reject(new Error(`Chrome exited ${code}: ${stderr.slice(-500)}`)));
      chrome.stderr.on('data',chunk=>{stderr+=chunk;const match=stderr.match(/DevTools listening on (ws:\/\/\S+)/);if(match){clearTimeout(timeout);resolve(match[1]);}});
    });
    const host=new URL(endpoint).host,pages=await(await fetch(`http://${host}/json/list`)).json(),page=pages.find(row=>row.type==='page');
    socket=new WebSocket(page.webSocketDebuggerUrl);
    await new Promise((resolve,reject)=>{socket.addEventListener('open',resolve,{once:true});socket.addEventListener('error',reject,{once:true});});
    let id=0;const pending=new Map(),events=[];
    socket.addEventListener('message',event=>{
      const message=JSON.parse(event.data);if(message.method)events.push(message);
      if(message.id){const job=pending.get(message.id);pending.delete(message.id);if(message.error)job?.reject(new Error(JSON.stringify(message.error)));else job?.resolve(message.result);}
    });
    const call=(method,params={})=>new Promise((resolve,reject)=>{const current=++id;pending.set(current,{resolve,reject});socket.send(JSON.stringify({id:current,method,params}));});
    const evaluate=async(expression,{awaitPromise=true}={})=>{const result=await call('Runtime.evaluate',{expression,returnByValue:true,awaitPromise});if(result.exceptionDetails)throw new Error(JSON.stringify(result.exceptionDetails));return result.result.value;};
    const waitFor=async(expression,timeout=20000)=>{const end=Date.now()+timeout;while(Date.now()<end){if(await evaluate(expression))return;await pause(100);}throw new Error(`Browser condition timed out: ${expression}`);};
    const close=async()=>{socket.close();chrome.kill();await new Promise(resolve=>{chrome.once('exit',resolve);setTimeout(resolve,3000);});await rm(profile,{recursive:true,force:true}).catch(()=>{});};
    await call('Runtime.enable');await call('Page.enable');await call('Network.enable');
    await call('Page.navigate',{url});
    await waitFor(`location.href===${JSON.stringify(url)}&&document.readyState!=='loading'`);
    return{call,evaluate,waitFor,events,close};
  }catch(error){socket?.close();chrome.kill();await rm(profile,{recursive:true,force:true}).catch(()=>{});throw error;}
}
