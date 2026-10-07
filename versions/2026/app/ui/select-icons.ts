import {areaChoices} from '../native-catalog';
import {iconSvg,type IconName} from './icons';
const courseIcons:IconName[]=['windward','windwardTwice','triangle','triangleTwice','gold','downwind','downwindTwice'];
const catamarans=new Set([10,11,17,23]);
const keelboats=new Set([12,13,14,15,16,18,19,20,21,22,24,25]);
const classIcons:Partial<Record<number,IconName>>={1:'optimist',2:'laser',4:'snipe',5:'jy15',6:'fiveOhFive',8:'thistle',9:'lightning',11:'tornado',16:'star',17:'aClass',24:'ideal18',25:'etchells',26:'eScow',27:'flyingScot'};
interface SelectionIcon {name:IconName;direction?:number}
function selectionIcon(select:HTMLSelectElement,optionValue=select.value):SelectionIcon {
 const value=Number(optionValue);
 switch(select.id){
  case 'race-mode':return {name:optionValue==='championship'?'trophy':'flag'};
  case 'race-boat':return {name:classIcons[value]??(value===3?'board':catamarans.has(value)?'catamaran':keelboats.has(value)?'keelboat':'dinghy')};
  case 'race-area':{
   const area=areaChoices.find(area=>area.command===value);
   return {name:[32801,32964,33017,33018].includes(value)?'island':area?.venue===0&&[9,10,14].includes(area.area)?'river':area?.area===5||[12,13,103].includes(area?.area||area?.venue||0)?'lake':'pin'};
  }
  case 'race-fleet':case 'fleet':return {name:'fleet'};
  case 'race-wind':return {name:value===1?'breeze':value===3?'gust':'wind'};
  case 'race-wind-direction':return {name:'compass',...(optionValue==='auto'?{}:{direction:value})};
  case 'race-course':return {name:courseIcons[value-1]??'windward'};
  case 'series-length':return {name:'series'};
  case 'race-speed':case 'pace':return {name:optionValue.startsWith('clock:')?'clock':'speed'};
  default:return {name:'speed'};
 }
}

/** Chrome's native customizable picker renders each option's SVG. Select values,
 * labels, validation and keyboard/pointer interaction remain browser-owned.
 * Other engines retain the existing text picker and closed-control decoration. */
export function decorateSelects(root:HTMLElement){
 const richOptions=CSS.supports('appearance','base-select');
 const records=Array.from(root.querySelectorAll<HTMLSelectElement>('#race-form select,#fleet,#pace')).map(select=>{
  const wrapper=document.createElement('span');wrapper.className='select-control';
  const icon=document.createElement('span');icon.className='select-icon';icon.setAttribute('aria-hidden','true');
  const arrow=document.createElement('span');arrow.className='select-chevron';arrow.setAttribute('aria-hidden','true');arrow.innerHTML=iconSvg('chevron');
  select.before(wrapper);wrapper.append(icon,select,arrow);
  if(richOptions){
   select.classList.add('icon-picker');
   const button=document.createElement('button');button.type='button';
   button.append(document.createElement('selectedcontent'));select.prepend(button);
   for(const option of select.options){
    const label=document.createElement('span');label.className='option-label';label.textContent=option.textContent;
    const choice=selectionIcon(select,option.value),symbol=document.createElement('span');
    symbol.className='option-icon';symbol.dataset.icon=choice.name;symbol.setAttribute('aria-hidden','true');symbol.innerHTML=iconSvg(choice.name,choice.direction);
    option.replaceChildren(symbol,label);
   }
  }
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
