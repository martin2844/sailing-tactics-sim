import {areaChoices} from '../native-catalog';
import {iconSvg,type IconName} from './icons';
const courseIcons:IconName[]=['windward','windwardTwice','triangle','triangleTwice','gold','downwind','downwindTwice'];
const catamarans=new Set([10,11,17,23]);
const keelboats=new Set([12,13,14,15,16,18,19,20,21,22,24,25]);
interface SelectionIcon {name:IconName;direction?:number}
function selectionIcon(select:HTMLSelectElement):SelectionIcon {
 const value=Number(select.value);
 switch(select.id){
  case 'race-mode':return {name:select.value==='championship'?'trophy':'flag'};
  case 'race-boat':return {name:value===3?'board':catamarans.has(value)?'catamaran':keelboats.has(value)?'keelboat':'dinghy'};
  case 'race-area':{
   const area=areaChoices.find(area=>area.command===value);
   return {name:[32801,32964,33017,33018].includes(value)?'island':area?.venue===0&&[9,10,14].includes(area.area)?'river':area?.area===5||[12,13,103].includes(area?.area||area?.venue||0)?'lake':'pin'};
  }
  case 'race-fleet':case 'fleet':return {name:'fleet'};
  case 'race-wind':return {name:value===1?'breeze':value===3?'gust':'wind'};
  case 'race-wind-direction':return {name:'compass',...(select.value==='auto'?{}:{direction:value})};
  case 'race-course':return {name:courseIcons[value-1]??'windward'};
  case 'series-length':return {name:'series'};
  default:return {name:'speed'};
 }
}

/** Native selects retain labels, focus, keyboard selection and validation.
 * Decorative SVGs never receive input. Programmatic coerced choices can be
 * refreshed explicitly, without rebuilding controls or listening to the engine. */
export function decorateSelects(root:HTMLElement){
 const records=Array.from(root.querySelectorAll<HTMLSelectElement>('#race-form select,#fleet,#pace')).map(select=>{
  const wrapper=document.createElement('span');wrapper.className='select-control';
  const icon=document.createElement('span');icon.className='select-icon';icon.setAttribute('aria-hidden','true');
  const arrow=document.createElement('span');arrow.className='select-chevron';arrow.setAttribute('aria-hidden','true');arrow.innerHTML=iconSvg('chevron');
  select.before(wrapper);wrapper.append(icon,select,arrow);
  return {select,icon,key:''};
 });
 function update(){
  for(const record of records){
   const choice=selectionIcon(record.select),key=choice.name+':'+(choice.direction??'auto');
   if(record.key===key)continue;record.key=key;
   record.icon.dataset.icon=choice.name;record.icon.innerHTML=iconSvg(choice.name,choice.direction);
  }
 }
 for(const {select}of records)select.addEventListener('change',()=>queueMicrotask(update));
 update();return {update};
}
