import type {BoatView} from './protocol';
const storageKey='tact2026.boatName';
let custom='';try{custom=cleanName(localStorage.getItem(storageKey)??'');}catch{}
export function cleanName(value:string){return value.replace(/[\u0000-\u001f\u007f]/g,'').trim().slice(0,32);}
export function setBoatName(value:string){custom=cleanName(value);try{custom?localStorage.setItem(storageKey,custom):localStorage.removeItem(storageKey);}catch{}return custom;}
export const getBoatName=()=>custom;
export const boatName=(boat:Pick<BoatView,'id'|'name'>)=>boat.id===1&&custom?custom:boat.name||`Boat ${boat.id}`;
