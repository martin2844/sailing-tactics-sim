export const defaultSimulatorSpeed=10;
export const simulatorSpeeds=Array.from({length:15},(_,index)=>{
 const level=index+1;
 return {level,command:level<10?32871+level:level===10?32909:32958+level};
});
export function validateSimulatorSpeed(value:unknown):number {
 if(!Number.isInteger(value)||Number(value)<1||Number(value)>15)throw new RangeError('Simulator speed must be1..15');
 return Number(value);
}
export const speedForCommand=(command:number)=>simulatorSpeeds.find(speed=>speed.command===command)?.level;
export const speedCommand=(level:number)=>simulatorSpeeds[validateSimulatorSpeed(level)-1].command;
