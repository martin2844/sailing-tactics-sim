/** These are original menu choices, applied by the native controller before
 * race initialization. The default retains the audited preset's exact paints. */
export interface RaceSettings {course:1|3|5;wind:1|2|3}
export const defaultRaceSettings:RaceSettings={course:1,wind:2};
export const courseChoices=[{value:1,label:'Windward / leeward',command:32816},{value:3,label:'Triangle',command:32818},{value:5,label:'Gold Cup',command:32820}] as const;
export const windChoices=[{value:1,label:'Light',command:32812},{value:2,label:'Moderate',command:32813},{value:3,label:'Strong',command:32814}] as const;
export function validateRaceSettings(value:unknown):RaceSettings {
 if(value===undefined)return {...defaultRaceSettings};
 if(!value||typeof value!=='object')throw new Error('Invalid race settings');
 const v=value as RaceSettings;
 if(!courseChoices.some(c=>c.value===v.course)||!windChoices.some(c=>c.value===v.wind))throw new Error('Unsupported course or wind setting');
 return {course:v.course,wind:v.wind};
}
export function raceSetupCommands(commands:number[],settings:RaceSettings){
 const result=commands.map(id=>id===32816?courseChoices.find(c=>c.value===settings.course)!.command:id);
 // Moderate is already the original default; an extra default paint would
 // change the captured initial state and its RNG sequence.
 if(settings.wind!==2)result.push(windChoices.find(c=>c.value===settings.wind)!.command);
 return result;
}
