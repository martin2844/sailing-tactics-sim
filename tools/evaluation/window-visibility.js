import {execFile} from 'node:child_process';
import {promisify} from 'node:util';
import {setTimeout as pause} from 'node:timers/promises';

const executeFile=promisify(execFile);

/** Chrome's DOM visibility does not reveal a hidden Wayland workspace. */
export async function evaluationWindowVisibility(launch,{focus=false,environment=process.env,execute=executeFile}={}){
  if(!environment.HYPRLAND_INSTANCE_SIGNATURE)return {supported:false,scope:'No Hyprland compositor visibility check available'};
  if(!Number.isSafeInteger(launch?.processId)||launch.processId<1)throw new Error('Owned browser PID is missing');
  const query=async name=>JSON.parse((await execute('hyprctl',['-j',name],{timeout:2000,maxBuffer:1024*1024})).stdout);
  const inspect=async()=>{
    const clients=await query('clients');
    const owned=clients.filter(row=>row.pid===launch.processId&&row.mapped!==false&&/^0x[0-9a-f]+$/i.test(row.address));
    if(owned.length!==1)throw new Error('Expected exactly one owned browser compositor window');
    const client=owned[0],monitors=await query('monitors');
    const monitor=monitors.find(row=>row.id===client.monitor);
    const visible=client.hidden===false&&client.mapped===true&&monitor?.dpmsStatus===true&&monitor.disabled===false
      &&(client.workspace.id===monitor.activeWorkspace?.id||client.workspace.id===monitor.specialWorkspace?.id);
    return {supported:true,visible,pid:client.pid,address:client.address,workspace:client.workspace.id,
      monitor:client.monitor,activeWorkspace:monitor?.activeWorkspace?.id,dpms:monitor?.dpmsStatus};
  };
  const initial=await inspect();
  if(initial.visible)return initial;
  if(!focus)throw new Error('Owned evaluation window is not on a visible powered display workspace');
  // Recheck ownership immediately before the only desktop mutation.
  const checked=await inspect();
  if(checked.address!==initial.address)throw new Error('Owned evaluation window changed before focus');
  const expression=`hl.dsp.focus({window="address:${checked.address}"})`;
  await execute('hyprctl',['dispatch',expression],{timeout:2000,maxBuffer:1024*1024});
  for(let attempt=0;attempt<20;attempt++){
    const current=await inspect();
    if(current.address!==initial.address)throw new Error('Owned evaluation window changed after focus');
    if(current.visible)return {...current,initial,focusAction:expression};
    await pause(100);
  }
  throw new Error('Owned evaluation window remained invisible after focus');
}
