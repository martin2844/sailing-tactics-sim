import test from 'node:test';
import assert from 'node:assert/strict';
import {evaluationWindowVisibility} from '../tools/evaluation/window-visibility.js';

const launch={processId:123},environment={HYPRLAND_INSTANCE_SIGNATURE:'fixture'};
function fixture({visible=true,duplicate=false,changes=false}={}){
  const calls=[];let focused=false,clientReads=0;
  const execute=async(_command,args)=>{
    calls.push(args);
    if(args[0]==='dispatch'){focused=true;return {stdout:'ok'};}
    if(args[1]==='clients'){
      clientReads++;
      const client={pid:123,address:changes&&clientReads>1?'0xdef':'0xabc',monitor:0,
        workspace:{id:3},hidden:false,mapped:true};
      return {stdout:JSON.stringify(duplicate?[client,{...client,address:'0xdef'}]:[client])};
    }
    return {stdout:JSON.stringify([{id:0,dpmsStatus:true,disabled:false,activeWorkspace:{id:visible||focused?3:1},specialWorkspace:{id:0}}])};
  };
  return {execute,calls};
}
test('visible owned windows need no compositor mutation',async()=>{
  const f=fixture();assert.equal((await evaluationWindowVisibility(launch,{environment,execute:f.execute,focus:true})).visible,true);
  assert.equal(f.calls.some(args=>args[0]==='dispatch'),false);
});
test('hidden workspace focus targets only the validated owned address and verifies visibility',async()=>{
  const f=fixture({visible:false});const r=await evaluationWindowVisibility(launch,{environment,execute:f.execute,focus:true});
  assert.equal(r.visible,true);assert.equal(r.initial.visible,false);
  assert.deepEqual(f.calls.filter(args=>args[0]==='dispatch'),[['dispatch','hl.dsp.focus({window="address:0xabc"})']]);
});
test('post-measurement visibility check fails rather than repairing the measured environment',async()=>{
  const f=fixture({visible:false});await assert.rejects(evaluationWindowVisibility(launch,{environment,execute:f.execute}),/not on a visible/);
  assert.equal(f.calls.some(args=>args[0]==='dispatch'),false);
});
test('ambiguous or changed owned windows refuse desktop mutations',async()=>{
  for(const options of [{duplicate:true},{visible:false,changes:true}]){
    const f=fixture(options);await assert.rejects(evaluationWindowVisibility(launch,{environment,execute:f.execute,focus:true}),/owned|Owned/);
    assert.equal(f.calls.some(args=>args[0]==='dispatch'),false);
  }
});
test('other compositors are explicitly unverified and never invoked',async()=>{
  assert.equal((await evaluationWindowVisibility(launch,{environment:{},execute:()=>{throw new Error('unexpected');}})).supported,false);
});
