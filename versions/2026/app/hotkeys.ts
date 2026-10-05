// Windows virtual-key values used by the preserved 2010 key handler.
const virtualKeys:Record<string,number>={Space:32,Enter:13,Escape:27,Backspace:8,CapsLock:20,PageUp:33,PageDown:34,Home:36,End:35,
 ArrowLeft:37,ArrowUp:38,ArrowRight:39,ArrowDown:40,Numpad5:12,Backslash:220,IntlBackslash:220,Semicolon:186,Slash:191,
 BracketLeft:219,BracketRight:221,Backquote:192,Comma:188,Period:190,Equal:187,Minus:189,Quote:222,NumpadAdd:187,NumpadSubtract:189,NumpadDecimal:190,NumpadDivide:191};
const letters=new Set('ABCDE F GHIJ LMNOP RSTUVWXYZ'.replaceAll(' ','').split(''));
export function nativeVirtualKey(event:Pick<KeyboardEvent,'code'|'key'>):number|undefined{
 if(event.code.startsWith('Numpad')){
   if(/^[0-9]$/.test(event.key))return event.key.charCodeAt(0);
   if(event.key in virtualKeys)return virtualKeys[event.key];
 }
 if(event.code in virtualKeys)return virtualKeys[event.code];
 if(/^Key[A-Z]$/.test(event.code)&&letters.has(event.code[3]))return event.code.charCodeAt(3);
 if(/^Digit[0-9]$/.test(event.code))return event.code.charCodeAt(5);
 if(/^F(?:[1-5]|12)$/.test(event.code))return 111+Number(event.code.slice(1));
 return undefined;
}
export const nativeCameraKeys=new Set([37,38,39,40,36,12,53,55,57,48,49,50,51,86]);
export const commonKeys=[['Tack','T',84],['Jibe','J',74],['Spinnaker','P',80],['Close hauled','C',67],['Run','D',68],['Sheet in','I',73],['Sheet out','O',79],['Laylines','L',76],['Freeze','F',70],['All keys','?',191]] as const;
export const shortcutGroups=[
 ['Steer','Comma / Quote: port · Period / Enter: starboard · C: close hauled · T: tack · H: reach · J: jibe · D: run · − / +: pinch / foot'],
 ['Sheet','A: automatic · S: maximum luff · I / O: in / out 20% · Esc / Backquote: in / out 5%'],
 ['Sails','F1 / F2 / F3: flat / medium / baggy · E: cycle shape · P: spinnaker · G: cycle headsail · U: hide sails'],
 ['Look','Arrows: ahead / left / right / astern · 1 / 2 / 3, V: viewpoint · 5: windward · 7 / Home: leeward · 9: other boat · 0: automatic view'],
 ['Pace','Page Up / Down: faster / slower · Space: original slow/resume or dismiss a panel · F: freeze · Backslash: automatic foul slowdown · Pause: suspend/resume this app'],
 ['Views','Z / X: tactical zoom · F4 / F5: bow / wind orientation · W: forecast · R: course · [ / ]: wind / current chart · + / −: chart time · ;: tracks · L: laylines'],
 ['Session','N: race setup, then Space to start · Backspace: original leg replay · ?: original key summary · Y: coach · B, P, L, M, S and digits: original context-sensitive setup controls'],
] as const;
