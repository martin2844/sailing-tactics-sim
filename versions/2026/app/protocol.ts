export interface BoatView {id:number;x:number;y:number;heading:number;speed:number;leg:number;finished:number}
export interface SceneSnapshot {generation:number;sequence:number;time:number;clock:number;pace:number;windDirection:number;windStrength:number;boats:BoatView[];marks:{x:number;y:number}[];results:boolean;workMs:number;minimumDelayMs:number;sentAt:number}
export interface Boundary {frame:number;time:number;clock:number;rngState:number;memorySha256:string;shore:{previousX:number;previousTreeY:number;completedCalls:number}}
export const commands={port:32842,starboard:32841,tack:32846,close:32843,reach:32849,run:32848,jibe:32847} as const;
