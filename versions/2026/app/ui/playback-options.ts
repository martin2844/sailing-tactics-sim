import {playbackRates,playbackValue} from '../engine/time/playback';
import {simulatorSpeeds} from '../engine/speed';
export function playbackOptions(footer=false):string {
 const modern=playbackRates.map(rate=>`<option value="clock:${rate}">${rate}×${rate===1?' · Real time':''}</option>`).join('');
 const legacy=simulatorSpeeds.map(({level})=>`<option value="${playbackValue({mode:'legacy',level},footer)}">OG level ${level}</option>`).join('');
 return `<optgroup label="Clock speed">${modern}</optgroup><optgroup label="Original pacing">${legacy}</optgroup>`;
}
