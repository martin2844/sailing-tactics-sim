import {boatChoices,areaChoices,fleetChoices,offshoreBoats,gateCourses} from './native-catalog';
/** Default values retain the audited preset's exact native menu paints. */
export interface RaceSettings {course:number;wind:1|2|3;windDirection?:number;scoring?:'single'|'series';boat?:number;area?:number;short?:boolean;gate?:boolean}
export const defaultRaceSettings:RaceSettings={course:1,wind:2};
export const courseChoices=[{value:1,label:'Windward / leeward',command:32816},{value:2,label:'Windward / leeward twice',command:32817},{value:3,label:'Triangle',command:32818},{value:4,label:'Triangle twice',command:32819},{value:5,label:'Gold Cup',command:32820},{value:6,label:'Downwind finish W/L',command:32992},{value:7,label:'Downwind finish W/L twice',command:32993}];
export const windChoices=[{value:1,label:'Light',command:32812},{value:2,label:'Moderate',command:32813},{value:3,label:'Strong',command:32814}] as const;
export const windDirectionChoices=['N','NE','E','SE','S','SW','W','NW'].map((label,index)=>({label,value:index*45}));
export function validateRaceSettings(value:unknown):RaceSettings {
 if(value===undefined)return {...defaultRaceSettings};if(!value||typeof value!=='object')throw Error('Invalid race settings');const v=value as RaceSettings;
 if(!courseChoices.some(c=>c.value===v.course)||!windChoices.some(c=>c.value===v.wind))throw Error('Unsupported course or wind setting');
 if(v.windDirection!==undefined&&!windDirectionChoices.some(d=>d.value===v.windDirection))throw Error('Unsupported wind direction');
 if(v.scoring!==undefined&&!['single','series'].includes(v.scoring))throw Error('Unsupported scoring');
 if(v.boat!==undefined&&!boatChoices.some(b=>b.value===v.boat)||v.area!==undefined&&!areaChoices.some(a=>a.command===v.area))throw Error('Unsupported boat or area');
 if(v.short!==undefined&&typeof v.short!=='boolean'||v.gate!==undefined&&typeof v.gate!=='boolean')throw Error('Invalid course options');
 const area=areaChoices.find(a=>a.command===v.area);if(area?.area===8&&!offshoreBoats.has(v.boat??12))throw Error('Distance courses require offshore boats');
 if(v.area===33018&&(v.boat??12)!==14)throw Error('Around Block Island requires the native offshore racer');
 if(v.gate&&(!gateCourses.has(v.course)||[32801,32802,32964,33018].includes(v.area??0)))throw Error('Gate not supported by this course');
 return {course:v.course,wind:v.wind,...(v.windDirection!==undefined?{windDirection:v.windDirection}:{}),...(v.scoring?{scoring:v.scoring}:{}),...(v.boat!==undefined?{boat:v.boat}:{}),...(v.area!==undefined?{area:v.area}:{}),...(v.short!==undefined?{short:v.short}:{}),...(v.gate!==undefined?{gate:v.gate}:{})};
}
export function raceSetupCommands(commands:number[],settings:RaceSettings,fleet?:number){
 const result=commands.map(id=>id===32816?courseChoices.find(c=>c.value===settings.course)!.command:id===32789?boatChoices.find(b=>b.value===(settings.boat??12))!.command:id===32799?areaChoices.find(a=>a.command===(settings.area??32799))!.command:[32806,32808].includes(id)&&fleet!==undefined?fleetChoices.find(f=>f.value===fleet)!.command:id);
 // Model yacht's native command chooses a lake and fleet. Re-selecting the
 // requested area afterwards is an original menu operation, not a memory edit.
 if(settings.boat===20){result.push(settings.area??32799);if(fleet!==undefined)result.push(fleetChoices.find(f=>f.value===fleet)!.command);}
 // Setup paints apply boat compatibility immediately. A distance selection
 // made before the offshore class would otherwise revert to North shore.
 if([32802,32964].includes(settings.area??0)&&settings.boat!==20)result.push(settings.area!);
 if(settings.wind!==2)result.push(windChoices.find(c=>c.value===settings.wind)!.command);
 if(settings.scoring==='single')result.push(32824);
 if(settings.short)result.push(32821);
 return result;
}
export function isAuditedPreset(settings:RaceSettings,fleet:number){return [5,15].includes(fleet)&&settings.course===1&&settings.wind===2&&settings.windDirection===undefined&&settings.scoring===undefined&&(settings.boat??12)===12&&(settings.area??32799)===32799&&!settings.short&&settings.gate===undefined;}
