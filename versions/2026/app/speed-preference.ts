import {defaultSimulatorSpeed,validateSimulatorSpeed} from './engine/speed';
const key='tact2026.simulatorSpeed';
export function loadSpeedPreference():number {
 try{const value=localStorage.getItem(key);return value===null?defaultSimulatorSpeed:validateSimulatorSpeed(Number(value));}
 catch{return defaultSimulatorSpeed;}
}
export function saveSpeedPreference(speed:number):void {
 validateSimulatorSpeed(speed);try{localStorage.setItem(key,String(speed));}catch{}
}
