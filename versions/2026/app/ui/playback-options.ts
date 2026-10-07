/** Setup and sailing use the same ordered multiplier choices. */
import {playbackRates} from '../engine/time/playback';
export function playbackOptions():string {
 return playbackRates.map(rate=>`<option value="clock:${rate}">${rate}×</option>`).join('');
}
