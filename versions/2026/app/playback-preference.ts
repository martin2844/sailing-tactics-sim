import {defaultPlayback,validatePlayback,type PlaybackChoice} from './engine/time/playback';
const key='tact2026.playback';
export function loadPlaybackPreference():PlaybackChoice {
 try{const value=localStorage.getItem(key);const choice=value===null?defaultPlayback:validatePlayback(JSON.parse(value));return choice.mode==='clock'?{...choice}:{...defaultPlayback};}
 catch{return {...defaultPlayback};}
}
export function savePlaybackPreference(value:PlaybackChoice):void {
 const choice=validatePlayback(value);try{localStorage.setItem(key,JSON.stringify(choice));}catch{}
}
