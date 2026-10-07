/** Tact's authored icon family: a24-unit grid,1.2-unit rounded strokes,
 * currentColor and no fonts, filters, external references or random geometry. */
const mast='<path d="M12 3v13"/>';
const sail='<path d="M10 5 5 14h5ZM14 5v9h5Z"/>';
const windOne='<path d="M3 10h13a3 3 0 1 0-3-3M3 14h7"/>';
const windTwo='<path d="M3 9h12a3 3 0 1 0-3-3M3 13h16a2 2 0 1 1-2 2M3 17h7"/>';
const courseMarks='<circle cx="12" cy="4" r="1.5" fill="currentColor" stroke="none"/><circle cx="12" cy="20" r="1.5" fill="currentColor" stroke="none"/>';
const windwardRoute=courseMarks+'<path d="M9 6 6 10l3-1v8M15 18l3-4-3 1V7"/>';
const triangleRoute='<circle cx="12" cy="4" r="1.5" fill="currentColor" stroke="none"/><circle cx="4" cy="19" r="1.5" fill="currentColor" stroke="none"/><circle cx="20" cy="19" r="1.5" fill="currentColor" stroke="none"/><path d="m10 7-5 9m3 3h9m1-3-5-9"/>';
const secondLap='<path d="M18 3a2 2 0 0 1 4 0c0 2-4 2-4 4h4"/>';
const compassRing='<circle cx="12" cy="12" r="8"/><path d="M12 2v2m10 8h-2m-8 10v-2M2 12h2"/>';
const compassNeedle='<path d="m12 6 3 9-3-1-3 1Z" fill="currentColor" stroke="none"/>';

export const iconBodies={
 flag:'<path d="M5 21V3c4-3 9 3 14 0v10c-5 3-10-3-14 0"/><path d="M7 4v7c4-1 7 2 10 1V5c-4 1-7-2-10-1Z" fill="currentColor" stroke="none"/>',
 trophy:'<path d="M7 3h10v6a5 5 0 0 1-10 0ZM7 5H3v3a4 4 0 0 0 4 4m10-7h4v3a4 4 0 0 1-4 4M12 14v5m-4 2h8m-8 0v-2h8v2"/>',
 dinghy:mast+sail+'<path d="m3 17 3 4h12l3-4Z"/>',
 keelboat:mast+sail+'<path d="m2 17 4 3h12l4-3ZM10 20l2 3 2-3"/>',
 catamaran:mast+sail+'<path d="M4 17h16M4 16v5h3v-5m10 0v5h3v-5"/>',
 board:'<path d="M11 3v13M13 4v11h7ZM5 17h12l-3 4H3Z"/>',
 // Class insignias are compact monochrome redraws. Reference provenance is
 // recorded in docs/ui-icons.md; generic classes retain their hull silhouette.
 optimist:'<circle cx="12" cy="9" r="6"/><path d="M12 9v12m-3 0h6"/>',
 laser:'<circle cx="12" cy="12" r="3"/><path d="M12 2v5m0 10v5M2 12h5m10 0h5M5 5l4 4m6 6 4 4M5 19l4-4m6-6 4-4"/>',
 snipe:'<path d="M2 11h5c1-2 3-2 4 0l2 1-1-3c4-1 7-3 10-4l-6 8 6 1-6 2c-5 3-7-1-9-3H2Z" fill="currentColor" stroke="none"/>',
 fiveOhFive:'<path d="M7 5H3v6h2a3 3 0 0 1 0 6H3m6-9a3 3 0 0 1 6 0v6a3 3 0 0 1-6 0Zm12-3h-4v6h2a3 3 0 0 1 0 6h-2"/>',
 thistle:'<path d="m8 9-2-5q6-4 12 0l-2 5M7 10h10c3 4 0 7-5 7s-8-3-5-7ZM12 17c0 2 0 4 3 5"/>',
 lightning:'<path d="M13 2 4 13h7l-1 9 10-13h-7Z" fill="currentColor" stroke="none"/>',
 tornado:'<path d="M5 3h17l-2 4h-5l-5 10H6l5-10H3ZM5 19h10l-1 2H4Z" fill="currentColor" stroke="none"/>',
 star:'<path d="m12 2 3 7 7 1-5 5 1 7-6-3-6 3 1-7-5-5 7-1Z"/>',
 aClass:'<path d="m4 17 8-15 8 15M7 11h10M4 19h16M4 22h16"/>',
 etchells:'<path d="M3 21 12 2l-2 15-3 4ZM12 6h10l-1 3h-6l-.5 3H20l-.5 3h-6L13 18h6l-.5 3H9Z" fill="currentColor" stroke="none"/>',
 ideal18:'<circle cx="9" cy="11" r="6.5"/><circle cx="15" cy="11" r="6.5"/><path d="M2 13h20"/>',
 flyingScot:'<path d="M4 20V4h9M4 11h7m10-6c-2-2-7-1-7 2 0 5 8 3 8 8 0 4-6 6-9 3"/>',
 jy15:'<path d="M3 3h5v6c0 4-5 4-5 1m8-7 3 4 3-4m-3 4v5m-7 4 2-2v8m11-8h-6v4h3c4 0 4 5 0 5h-3"/>',
 eScow:'<path d="M18 3H6v15h12M6 10h10M4 22h16"/>',
 fleet:'<circle cx="12" cy="7" r="3"/><circle cx="4.5" cy="9" r="2"/><circle cx="19.5" cy="9" r="2"/><path d="M7 20v-3a5 5 0 0 1 10 0v3ZM2 19v-4a3 3 0 0 1 3-2m17 6v-4a3 3 0 0 0-3-2"/>',
 pin:'<path d="M19 10c0 5-7 11-7 11S5 15 5 10a7 7 0 0 1 14 0Z"/><circle cx="12" cy="10" r="2.5"/>',
 lake:'<path d="M7 3 3 8l1 8 5 5 9-2 3-6-3-8ZM7 11c2-2 3 2 5 0s3 2 5 0m-10 5c2-2 3 2 5 0s3 2 5 0"/>',
 island:'<path d="M9 14V5m0 3L5 6m4 1 4-2M5 16l2-3h10l2 3M2 19c3-3 4 3 7 0s4 3 7 0 4 3 6 0"/>',
 river:'<path d="M6 3c8 5-8 13 0 18M17 3c8 5-8 13 0 18M2 8h3m14 8h3"/>',
 breeze:windOne,
 wind:windTwo,
 gust:windTwo+'<path d="M13 19h5a2 2 0 1 1-2 2"/>',
 compass:compassRing+compassNeedle,
 speed:'<path d="M5 19a9 9 0 1 1 14 0M12 4v2M5 8l2 1m12-1-2 1M4 15h2m14 0h-2m-6 0 4-5"/><circle cx="12" cy="15" r="1.5" fill="currentColor" stroke="none"/>',
 clock:'<circle cx="12" cy="12" r="9"/><path d="M12 6v6l4 3"/>',
 windward:windwardRoute,
 windwardTwice:windwardRoute+secondLap,
 triangle:triangleRoute,
 triangleTwice:triangleRoute+secondLap,
 gold:triangleRoute+'<path d="M12 8v8m-2-3 2 3 2-3"/>',
 downwind:windwardRoute+'<path d="M8 22h8"/>',
 downwindTwice:windwardRoute+'<path d="M8 22h8"/>'+secondLap,
 series:'<path d="M6 8h12v13H6ZM9 4h12v13M12 1h11v13M9 12h6m-6 4h6"/>',
 chevron:'<path d="m7 10 5 5 5-5"/>',
} as const;
export type IconName=keyof typeof iconBodies;

/** A fixed template keeps geometry/styling identical wherever an icon is used.
 * Compass rotation indicates the selected wind source; its ring stays north-up. */
export function iconSvg(name:IconName,direction?:number):string {
 const body=name==='compass'&&direction!==undefined
  ?compassRing+`<g transform="rotate(${direction} 12 12)">${compassNeedle}</g>`:iconBodies[name];
 return `<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.2" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true" focusable="false">${body}</svg>`;
}
